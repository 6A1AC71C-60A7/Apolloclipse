
#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

// 1) Check for REX | [{66, f2, f3}], 0f
// 2) If multiple REX, {66, f2, f3} or 0f skip and ignore
// 3) If ((1)) check for opcode
// 4) Else check for prefixes
// 4.1) If multiple REPEATED prefixes, skip and ignore
// 5) Check for VEX
// 6) If VEX take another path (reused fcnt btw)
// 7) Else check for opcode
// 8) If opcode spefied (opcode): check modrm
// 7) If specified (modrm): check for SIB
// 8) If specified (modrm or SIB): check displacement.
// 9) If specified (opcode) : check immediate

// VEX PATH:
// 1) Check VEX
// 2) Check opcode
// 3) Check modrm
// 4) If specified (modrm): check for SIB
// 5) If specified (modrm or SIB): check displacement.
// 6) If specified (opcode) : check immediate

///NOTE: GPM stands for "Gereral Purpose Multiple"

#define IS_GPM_ESCAPE(x) ((x) == 0x0F)
#define IS_GPM_ESCAPE2_0x38(x) ((x) == 0x38)
#define IS_GPM_ESCAPE2_0x3A(x) ((x) == 0x3A)
#define IS_GPM_ESCAPE2(x) (IS_GPM_ESCAPE2_0x38(x) || IS_GPM_ESCAPE2_0x3A(x))
#define IS_REXBYTE(x) (((x) & 0b11110000) == 0b01000000)
#define IS_VEX_PREFIX(x) ((x) == AVL_CONST_VEX2_PREFIX || (x) == AVL_CONST_VEX3_PREFIX)
#define IS_EVEX_PREFIX(x) ((x) == AVL_CONST_EVEX_PREFIX)
#define IS_OPMAP_INDEXING(x) ((x) == AMB)

#define IS_EVEX_COLISION_0x0F(x, p) ( \
	(!((p) & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) && (x) == 0x79) \
	|| (!((p) & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) && (x) == 0x5B) \
	|| (!((p) & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) && (x) == 0x78) \
)

#define HAS_ATTR_MODRM 0x1
#define HAS_ATTR_SIB (HAS_ATTR_MODRM << 1)
#define HAS_ATTR_MODRMDISP_8 (HAS_ATTR_SIB << 1)
#define HAS_ATTR_MODRMDISP_32 (HAS_ATTR_MODRMDISP_8 << 1)
#define HAS_ATTR_SIBDISP_8 (HAS_ATTR_MODRMDISP_32 << 1)
#define HAS_ATTR_SIBDISP_32 (HAS_ATTR_SIBDISP_8 << 1)
#define HAS_ATTR_IMMEDIATE (HAS_ATTR_SIBDISP_32 << 1)
#define HAS_ATTR_DISP(x) ( \
	(x) & HAS_ATTR_MODRMDISP_8 \
	|| (x) & HAS_ATTR_MODRMDISP_32 \
	|| (x) & HAS_ATTR_SIBDISP_8 \
	|| (x) & HAS_ATTR_SIBDISP_32 \
)
#define GET_DISP_LENGHT(x) ( \
	(x) & HAS_ATTR_MODRMDISP_8 || (x) & HAS_ATTR_SIBDISP_8 ? 0x8 : 0x20 \
)

#define HAS_GROUP_EXTENTION(x) ((x == S_1A))

#define IS_K_INSTRUCTION_0F(map, row, inst) ( \
	map == lt_two_byte_opmap \
	&& (row == 0x4 || row == 0x9) \
	&& AVL_HAS_OP_VEX_PFX(inst) \
)

#define IS_OVERWRITING_EVEX_0F(map, inst) ( \
	map == lt_two_byte_opmap \
	&& AVL_HAS_OP_EVEX_PFX((inst)->i_flags) \
	&& IS_EVEX_COLISION_0x0F((inst)->i_opcode[2], (inst)->i_flags) \
)

__always_inline
static void skip_duplicated(const ubyte** target, ubyte mask)
{
	for (const ubyte* pdup = *target ; (*pdup & mask) == (**target & mask) ; (*target)++)
		;
}

__always_inline
static const opfield_t* get_map_vex(ubyte* const vex, ubyte isevex)
{
	/* If instruction is 2 bytes vex prefix, the map is always
		as it was prefixed with 0x0F */
	if (!isevex && *vex == AVL_CONST_VEX2_PREFIX)
		return lt_two_byte_opmap;

	const ubyte			mmmmm = isevex ? ((AVL_evex_t*)vex)->evx_opmap : ((AVL_vex_t*)vex)->vx_opmap;
	const opfield_t*	map;

	switch (mmmmm)
	{
		case 0b01:
			map = lt_two_byte_opmap;
			break ;

		case 0b10:
			map = lt_three_byte_0x38_opmap;
			break ;

		case 0b11:
			map = lt_three_byte_0x3A_opmap;
			break ;
	}

	return map;
}

__always_inline
static const opfield_t*	get_map_legacy(AVL_instruction_t* const inst)
{
	const opfield_t* map;

	if (INST_ISPREFIXED(inst))
	{
		map = lt_two_byte_opmap;

		if (INST_ISPREF_0F38(inst))
			map = lt_three_byte_0x38_opmap;
		else if (INST_ISPREF_0F3A(inst))
			map = lt_three_byte_0x3A_opmap;
	}
	else
		map = lt_one_byte_opmap;

	return map;
}

__always_inline
static opfield_t	handle_x87_instructions(AVL_instruction_t* const inst, const ubyte** iraw)
{
	const opfield_t*	map;
	uqword				map_index;
	opfield_t			found;

	inst->i_mod_rm = *((*iraw)++);

	/* Documentation's map starts at 0xC0 (fields from 0x0 to 0xC0 are zeroed), so I've stripped those fields */
	map_index = inst->i_mod_rm > 0xBF ? GET_MAP_INDEX(inst->i_mod_rm) - 0XC0 : AVL_GET_MODRM_REG(inst);

	switch (inst->i_opcode[2])
	{
		case 0xD8:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xD8_outside_modrm_opmap : lt_escape_0xD8_within_modrm_opmap;
			break ;

		case 0xD9:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xD9_outside_modrm_opmap : lt_escape_0xD9_within_modrm_opmap;
			break ;

		case 0xDA:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xDA_outside_modrm_opmap : lt_escape_0xDA_within_modrm_opmap;
			break ;

		case 0xDB:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xDB_outside_modrm_opmap : lt_escape_0xDB_within_modrm_opmap;
			break ;

		case 0xDC:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xDC_outside_modrm_opmap : lt_escape_0xDC_within_modrm_opmap;
			break ;

		case 0xDD:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xDD_outside_modrm_opmap : lt_escape_0xDD_within_modrm_opmap;
			break ;

		case 0xDE:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xDE_outside_modrm_opmap : lt_escape_0xDE_within_modrm_opmap;
			break ;

		case 0xDF:
			map = inst->i_mod_rm > 0xBF ? lt_escape_0xDF_outside_modrm_opmap : lt_escape_0xDF_within_modrm_opmap;
			break ;
	}

	found = map[map_index];
	inst->i_mnemonic = found.mnemonic;

	return found;
}

__always_inline
static void handle_overwriting_evex_instructions_0F(opfield_t* const found, ubyte opcode, udword prefix)
{
	if (!AVL_HAS_MP_0xF2_PFX(prefix))
	{
		if (opcode == 0x79)
			*found = (opfield_t){ .mnemonic = VCVTPD2UDQ, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
		else if (opcode == 0x5B)
			*found = (opfield_t){ .mnemonic = VCVTDQ2PS, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
		else if (opcode == 0x78)
			*found = (opfield_t){ .mnemonic = VCVTTPD2UDQ, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };

		if (!AVL_HAS_REXW_PFX(prefix))
		{
			if (found->mnemonic == VCVTPD2UDQ)
				found->mnemonic = VCVTPS2UDQ;
			else if (found->mnemonic == VCVTTPD2UDQ)
				found->mnemonic = VCVTTPS2UDQ;
		}
		else if (found->mnemonic == VCVTDQ2PS)
			found->mnemonic = VCVTQQ2PS;
	}
}

__always_inline
static void handle_k_instructions_0x0F(opfield_t* const found, ubyte opcode)
{
	switch (opcode)
	{
		case 0x41:
			*found = (opfield_t){ .mnemonic = KAND, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x42:
			*found = (opfield_t){ .mnemonic = KANDN, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x44:
			*found = (opfield_t){ .mnemonic = KNOT, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x45:
			*found = (opfield_t){ .mnemonic = KOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x46:
			*found = (opfield_t){ .mnemonic = KXNOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x47:
			*found = (opfield_t){ .mnemonic = KXOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x4A:
			*found = (opfield_t){ .mnemonic = KADD, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x4B:
			///TODO: This operand size resolution is very UNIQUE
			*found = (opfield_t){ .mnemonic = KUNPCK, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x90:
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x91:
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_M, .ot1 = OT_ALL, .am2 = AM_KR, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x92:
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_R, .ot2 = OT_Y, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x93:
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_G, .ot1 = OT_Y, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x98:	
			*found = (opfield_t){ .mnemonic = KORTEST, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x99:
			*found = (opfield_t){ .mnemonic = KTEST, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;
	}
}

///WTF: If i copy paste this to another file it doesn't work anymore ...
///TODO: Change arguments and add an AVL_instruction_t instead
__always_inline
static void redirect_indexing_opfield(AVL_instruction_t* const inst, const opfield_t* map, opfield_t* const found, ubyte* const is_k_inst)
{
	const mnemonic_t oldmn = found->mnemonic;
	uqword scale = 0;

	if (map == lt_two_byte_opmap)
	{
		const ubyte row = GET_ROW(inst->i_opcode[2]);
	
		if (AVL_HAS_MP_0x66_PFX(inst->i_flags) && !(row >= 0x9 && row <= 0xB))
			scale = 1;
		if (AVL_HAS_MP_0xF3_PFX(inst->i_flags))
			scale = 2;
		if (AVL_HAS_MP_0xF2_PFX(inst->i_flags))
			scale = 3;

		/* Prefix dependent instructions are aligned by 0x76 bytes */
		*found = lt_two_byte_ambigious_opmap[found->mnemonic + (0x76 * scale)];

		// Just overwrite for the moment

		if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
		{
			switch (found->mnemonic)
			{
				case VCMPSD:
					// fall through
				case VCMPPD:
					// fall through
				case VCMPSS:
					// fall through
				case VCMPPS:
					// fall through
				case VPCMPEQB:
					// fall through
				case VPCMPEQW:
					// fall through
				case VPCMPEQD:
					found->am1 = AM_KR;
					break ;

				case VPAND:
					found->mnemonic = VPANDD;
					break ;

				case VPANDN:
					found->mnemonic = VPANDND;
					break ;

				case VPOR:
					found->mnemonic = VPORD;
					break ;

				case VPXOR:
					found->mnemonic = VPXORD;
					break ;
			}

			if (AVL_HAS_REXW_PFX(inst->i_flags))
			{
				switch (found->mnemonic)
				{
					case VPSRAD:
						found->mnemonic = VPSRAQ;
						break ;

					case VCVTDQ2PD:
						found->mnemonic = VCVTQQ2PD;
						break ;

					case VCVTUDQ2PD:
						found->mnemonic = VCVTUQQ2PD;
					break ;

					case VCVTUDQ2PS:
						found->mnemonic = VCVTUQQ2PS;
						break ;
				}
			}
			else
			{
				switch (found->mnemonic)
				{
					case VCVTPD2UQQ:
						found->mnemonic = VCVTPS2UQQ;
						break ;

					case VCVTTPD2QQ:
						found->mnemonic = VCVTTPS2QQ;
						break ;

					case VCVTTPD2UQQ:
						found->mnemonic = VCVTTPS2UQQ;
						break ;

					case VCVTSS2USI:
						// fall through
					case VCVTSD2USI:
						// fall through
					case VCVTTSS2USI:
						// fall through
					case VCVTTSD2USI:
						// fall through
						found->ot1 = OT_D;
						break ;
				}
			}
		}
	}
	else if (map == lt_three_byte_0x38_opmap)
	{
		if (inst->i_flags & (AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK))
		{
			if (TESTRANGE(inst->i_opcode[2], 0xF0, 0xF8))
				handle_rare_prefixes_0x38_opmap(found, inst->i_opcode[2], inst->i_flags);
			else if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
				handle_evex_addons_0x38_opmap(found, inst->i_opcode[2], inst->i_flags);
		}
		else
		{
			if (AVL_HAS_MP_0x66_PFX(inst->i_flags))
			{
				scale = 1;
				if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
				{
					switch (inst->i_opcode[2])
					{
						
						///TODO: no_overwrite solution is trash

						case 0x10:
							*found = (opfield_t){ .mnemonic = VPSRLVW,	.am1 = AM_V,	.ot1 = OT_X,	.am2 = AM_H,	.ot2 = OT_X,	.am3 = AM_W,	.ot3 = OT_X,	.am4 = 0,	.ot4 = 0,	.symbol = S_V };
							break ;

						case 0x14:
							*found = (opfield_t){ .mnemonic = VPRORVD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							if (AVL_HAS_REXW_PFX(inst->i_flags))
								found->mnemonic = VPRORVQ;
							break ;

						case 0x15:
							*found = (opfield_t){ .mnemonic = VPROLVD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							break ;

						case 0x2C:
							*found = (opfield_t){ .mnemonic = VSCALEFPD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							break ;

						case 0x2D:
							*found = (opfield_t){ .mnemonic = VSCALEFSD, .am1 = AM_V, .ot1 = OT_DQ, .am2 = AM_H, .ot2 = OT_DQ, .am3 = AM_W, .ot3 = OT_DQ, .am4 = 0, .ot4 = 0, .symbol = 0 };
							break ;
					}
				}
			}
			if (found->mnemonic == oldmn)
				*found = lt_three_byte_0x38_opmap[GET_MAP_INDEX(inst->i_opcode[2]) + (0x100 * scale)];

			if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
			{
				switch (found->mnemonic)
				{	
					case VPCMPGTQ:
						// fall through
					case VPCMPEQQ:
						found->am1 = AM_KR;
						break ;

					case VBROADCASTF128:
						found->mnemonic = AVL_HAS_REXW_PFX(inst->i_flags) ? VBROADCASTF64X2 : VBROADCASTF32X4;
						if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
							found->ot1 = OT_DQQ;
						break ;

					case VBROADCASTSD:
						if (!AVL_HAS_REXW_PFX(inst->i_flags))
							found->mnemonic = VBROADCASTF32X2;
						if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
							found->ot1 = OT_DQQ;
						break ;

					case VBROADCASTF32X8:
						if (AVL_HAS_REXW_PFX(inst->i_flags))
							found->mnemonic = VBROADCASTF64X4;
						if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
							found->ot1 = OT_DQQ;
						break ;

					case VGATHERQPS:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VGATHERQPD;
						else if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
						{
							found->ot1 = OT_QQ;
							found->ot2 = OT_QQ;
						}
						else if (((AVL_evex_t*)inst->i_vp)->evx_vlen)
						{
							found->ot1 = OT_DQ;
							found->ot2 = OT_DQ;
						}
						else
							found->ot2 = OT_Q;
						// fall through
					case VGATHERDPS:
						// because strange swtich witout break "found->mnemonic == VGATHERDPS"
						if (AVL_HAS_REXW_PFX(inst->i_flags) && found->mnemonic == VGATHERDPS)	
							found->mnemonic = VGATHERDPD;
						// fall through
					case VGATHERQPD:
						///TODO: This is AM_H exception (can be handled diferently)
						found->am3 = 0;
						break ;

					case VPGATHERDD:
						if (inst->i_flags & AVL_RP_REXW_MASK)	
							found->mnemonic = VPGATHERDQ;
						///TODO: This is AM_H exception (can be handled diferently)
						found->am3 = 0;
						break ;

					case VPGATHERQD:
						if (inst->i_flags & AVL_RP_REXW_MASK)	
							found->mnemonic = VPGATHERQQ;
						else
						{
							if (!((AVL_evex_t*)inst->i_vp)->evx_vlen && !((AVL_evex_t*)inst->i_vp)->evx_vlen2)
								found->ot2 = OT_Q;
							else
							{
								found->ot1 = OT_QQ;
								found->ot2 = OT_QQ;
							}
						}
						///TODO: This is AM_H exception (can be handled diferently)
						found->am3 = 0;
						break ;
				}

				if (AVL_HAS_REXW_PFX(inst->i_flags))
				{
					switch (found->mnemonic)
					{
						case VPSCATTERDD:
							found->mnemonic = VPSCATTERDQ;
							break ;

						case VPSCATTERQD:
							found->mnemonic = VPSCATTERQQ;
							break ;

						case VPBLENDMB:
							found->mnemonic = VPBLENDMW;
							break ;

						case VPBLENDMD:
							found->mnemonic = VPBLENDMQ;
							break ;

						case VPBROADCASTD:
							found->mnemonic = VPBROADCASTQ;
							found->ot2 = OT_Q;
							break ;

						case VPCOMPRESSD:
							found->mnemonic = VPCOMPRESSQ;
							break ;
						
						case VPCONFLICTD:
							found->mnemonic = VPCONFLICTQ;
							break ;

						case VPERMI2B:
							found->mnemonic = VPERMI2W;
							break ;

						case VPERMI2D:
							found->mnemonic = VPERMI2Q;
							break ;

						case VPERMT2B:
							found->mnemonic = VPERMT2W;
							break ;

						case VPERMT2D:
							found->mnemonic = VPERMT2Q;
							break ;

						case VPEXPANDD:
							found->mnemonic = VPEXPANDQ;
							break ;
						
						case VPLZCNTD:
							found->mnemonic = VPLZCNTQ;
							break ;

						case VPROLVD:
							found->mnemonic = VPROLVQ;
							break ;

						case VPTESTMB:
							found->mnemonic = VPTESTMW;
							break ;

						case VPTESTMD:
							found->mnemonic = VPTESTMQ;
							break ;

						case VPMAXSD:
							found->mnemonic = VPMAXSQ;
							break ;

						case VPMULLD:
							found->mnemonic = VPMULLQ;
							break ;

						case VPMINUD:
							found->mnemonic = VPMINUQ;
							break ;

						case VPMINSD:
							found->mnemonic = VPMINSQ;
							break ;

						case VPMAXUD:
							found->mnemonic = VPMAXUQ;
							break ;

						case VPERMB:
							found->mnemonic = VPERMW;
							break ;

						case VPERMPS:
							found->mnemonic = VPERMPD;
							break ;

						case VPERMD:
							found->mnemonic = VPERMQ;
							break ;
					}
				}
				else
				{
					switch (found->mnemonic)
					{
						case VSCATTERDPD:
							found->mnemonic = VSCATTERDPS;
							break ;

						case VSCATTERQPD:
							found->mnemonic = VSCATTERQPS;
							break ;

						case VGETEXPPD:
							found->mnemonic = VGETEXPPS;
							break ;

						case VGETEXPSD:
							found->mnemonic = VGETEXPSS;
							break ;

						case VPERMI2PD:
							found->mnemonic = VPERMI2PS;
						break ;

						case VPERMT2PD:
							found->mnemonic = VPERMT2PS;
							break ;
						
						case VRCP14PD:
							found->mnemonic = VRCP14PS;
							break ;

						case VRCP14SD:
							found->mnemonic = VRCP14SS;
							break ;

						case VRSQRT14PD:
							found->mnemonic = VRSQRT14PS;
							break ;

						case VRSQRT14SD:
							found->mnemonic = VRSQRT14SS;
							break ;

						case VSCALEFPD:
							found->mnemonic = VSCALEFPS;
							break ;

						case VSCALEFSD:
							found->mnemonic = VSCALEFSS;
							break ;

						case VBLENDMPD:
							found->mnemonic = VBLENDMPS;
							break ;

						case VEXPANDPD:
							found->mnemonic = VEXPANDPS;
							break ;
					}
				}
			}
		}
	}
	else if (map == lt_three_byte_0x3A_opmap)
	{
		if (inst->i_opcode[2] == 0x0F && AVL_HAS_MP_0x66_PFX(inst->i_flags))
			found->mnemonic = AMB_VPALIGNR_INDEX;
		*found = lt_tree_byte_0x3A_ambigious_opmap[found->mnemonic];

		if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
		{
			switch (inst->i_opcode[2])
			{
				case 0x8:
					*found = (opfield_t){ .mnemonic = VRNDSCALEPS, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0x9:
					*found = (opfield_t){ .mnemonic = VRNDSCALEPD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0xA:
					*found = (opfield_t){ .mnemonic = VRNDSCALESS, .am1 = AM_V, .ot1 = OT_DQ, .am2 = AM_W, .ot2 = OT_DQ, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0xB:
					*found = (opfield_t){ .mnemonic = VRNDSCALESD, .am1 = AM_V, .ot1 = OT_DQ, .am2 = AM_W, .ot2 = OT_DQ, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0x10:
					*found = (opfield_t){ .mnemonic = VPSRLVW, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = S_V };
					break ;

				case 0x18:
					found->mnemonic = (inst->i_flags & AVL_RP_REXW_MASK) ? VINSERTF64X2 : VINSERTF32X4;
					if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
					{
						found->ot1 = OT_DQQ;
						found->ot2 = OT_DQQ;
					}
					break ;

				case 0x1A:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VINSERTF64X4;
					found->ot1 = OT_DQQ;
					found->ot2 = OT_DQQ;
					break ;

				case 0x42:
					found->mnemonic = VDBPSADBW;
					break ;
			}
			if (AVL_HAS_REXW_PFX(inst->i_flags))
			{
				switch (inst->i_opcode[2])
				{
					case 0x03:
						found->mnemonic = VALIGNQ;
						break ;

					case 0x1E:
						found->mnemonic = VPCMPUQ;
						break ;

					case 0x1F:
						found->mnemonic = VPCMPQ;
						break ;

					case 0x23:
						found->mnemonic = VSHUFF64X2;
						break ;

					case 0x25:
						found->mnemonic = VPTERNLOGQ;
						break ;
					
					case 0x3E:
						found->mnemonic = VPCMPUW;
						break ;

					case 0x3F:
						found->mnemonic = VPCMPW;
						break ;

					case 0x43:
						found->mnemonic = VSHUFI64X2;
						break ;
				}
			}
			else
			{
				switch (inst->i_opcode[2])
				{
					case 0x26:
						found->mnemonic = VGETMANTPS;
						break ;
					
					case 0x27:
							found->mnemonic = VGETMANTSS;
						break ;
					
					case 0x50:
						found->mnemonic = VRANGEPS;
						break ;

					case 0x51:
						found->mnemonic = VRANGESS;
						break ;

					case 0x54:
						found->mnemonic = VFIXUPIMMPS;
						break ;
					
					case 0x55:
						found->mnemonic = VFIXUPIMMSS;
						break ;

					case 0x56:
						found->mnemonic = VREDUCEPS;
						break ;

					case 0x57:
						found->mnemonic = VREDUCESS;
						break ;

					case 0x66:
						found->mnemonic = VFPCLASSPS;
						break ;

					case 0x67:
						found->mnemonic = VFPCLASSSS;
						break ;
				}
			}
		}
		else if (found->mnemonic == KSHIFTL || found->mnemonic == KSHIFTR)
			*is_k_inst = 0x1;
	}
	else
	{
		/// ERROR:
	}
}

__always_inline
static void		handle_ambigious_arguments(opfield_t* const found, const opfield_t* map, AVL_instruction_t* const inst)
{
	const ubyte opcode = inst->i_opcode[2];

	///TODO: Preform (move) the ambigiousness handling in group extensions here ?
	/// MMM parse is a lot more complex, i don't think so (seems not worth)

	if (map == lt_one_byte_opmap && opcode == 0x90)
	{
		if ((inst->i_flags & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) == 0
		&& inst->i_flags & (AVL_RP_REXB_MASK | AVL_RP_REXW_MASK))
			*found = (opfield_t){ .mnemonic = XCHG,	.am1 = DR_R8,	.ot1 = DRS_64,	.am2 = DR_RAX,	.ot2 = DRS_64,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
		else if (AVL_HAS_MP_0xF3_PFX(inst->i_flags))
			found->mnemonic = PAUSE;
	}
	else if (map == lt_three_byte_0x38_opmap)
	{
		if (AVL_HAS_MP_0x66_PFX(inst->i_flags) && AVL_GET_MODRM_MOD(inst->i_mod_rm) != 0b11)
		{
			if (TESTRANGE(opcode, 0x20, 0x25) || TESTRANGE(opcode, 0x30, 0x35))
				found->am2 = AM_M;

			switch (opcode)
			{
				case 0x20:
					found->ot2 = OT_Q;
					break ;

				case 0x21:
					found->ot2 = OT_D;
					break ;

				case 0x22:
					found->ot2 = OT_W;
					break ;

				case 0x23:
					found->ot2 = OT_Q;
					break ;

				case 0x24:
					found->ot2 = OT_D;
					break ;

				case 0x25:
					found->ot2 = OT_Q;
					break ;

				case 0x30:
					found->ot2 = OT_Q;
					break ;

				case 0x31:
					found->ot2 = OT_D;
					break ;

				case 0x32:
					found->ot2 = OT_W;
					break ;

				case 0x33:
					found->ot2 = OT_Q;
					break ;

				case 0x34:
					found->ot2 = OT_D;
					break ;

				case 0x35:
					found->ot2 = OT_Q;
					break ;
			}
		}
	}
	else if (map == lt_three_byte_0x3A_opmap)
	{
		if (AVL_HAS_MP_0x66_PFX(inst->i_flags) && AVL_GET_MODRM_MOD(inst->i_mod_rm) != 0b11)
		{
			switch (opcode)
			{
				case 0x14:
					found->am1 = AM_M;
					found->ot1 = OT_B;
					break ;

				case 0x15:
					found->am1 = AM_M;
					found->ot1 = OT_W;
					break ;

				case 0x20:
					found->am3 = AM_M;
					found->ot3 = OT_B;
					break ;

				case 0x21:
					found->am3 = AM_M;
					found->ot3 = OT_D;
					break ;
			}
		}

		if (AVL_HAS_REXW_PFX(inst->i_flags))
		{
			if (opcode == 0x22)
				found->mnemonic = VPINSRQ;
			else if (opcode == 0x16)
				found->mnemonic = VPEXTRQ;
		}
	}
	else if (map == lt_two_byte_opmap)
	{
		if (AVL_GET_MODRM_MOD(inst->i_mod_rm) != 0b11)
		{
			if (AVL_HAS_MP_0x66_PFX(inst->i_flags))
			{
				if (opcode == 0xC4)
				{
					if (inst->i_mnemonic == PINSRW)
					{
						found->am2 = AM_M;
						found->ot2 = OT_W;
					}
					else if (inst->i_mnemonic == VPINSRW)
					{
						found->am3 = AM_M;
						found->ot3 = OT_W;
					}
				}
			}
			else if ((inst->i_flags & (AVL_MP_0x66_MASK | AVL_MP_0xF3_MASK | AVL_MP_0xF2_MASK)) == 0)
			{
				switch (opcode)
				{
					case 0x12:
						found->mnemonic = VMOVLPS;
						found->am3 = AM_M;
						break ;

					case 0x16:
						found->mnemonic = VMOVHPS;
						found->am3 = AM_M;
						break ;

					case 0xC4:
						found->am2 = AM_M;
						found->ot2 = OT_W;
						break ;

					case 0x77:
						if (inst->i_vp[0])
						{
							if (AVL_ISVEX3_PFX(inst) ? ((AVL_vex_t*)inst->i_vp)->vx_vlen : ((AVL_vex2_t*)inst->i_vp)->vx2_vlen)
								found->mnemonic = VZEROALL;
							else
								found->mnemonic = VZEROUPPER;
						}
						break ;
				}
			}
		}
		else
		{
			if (opcode == 0x6E || opcode == 0x7E)
			{
				if (AVL_HAS_REXW_PFX(inst->i_flags))
				{
					if (inst->i_mnemonic == MOVD)
						found->mnemonic = MOVQ;
					else if (inst->i_mnemonic == VMOVD)
						found->mnemonic = VMOVQ;
				}
			}
			else if (TESTRANGE(opcode, 0x74, 0x76) && AVL_HAS_MP_0x66_PFX(inst->i_flags)
			&& AVL_HAS_OP_EVEX_PFX(inst->i_flags))
				found->am1 = AM_KR;
		}
	}

	inst->i_mnemonic = found->mnemonic;
}

__always_inline
static void get_prefix_data(AVL_instruction_t* const dest, const ubyte** iraw)
{
	if (IS_EVEX_PREFIX(**iraw))
		get_evex_prefixes(dest, iraw);
	else if (IS_VEX_PREFIX(**iraw))
		get_vex_prefixes(dest, iraw);
	else
	{
		get_legacy_prefixes(&dest->i_flags, iraw);

		///TODO: Useful error check but for instructions which have have 2 prefixes fails
		/// They're always exceptions ... (0f 38 F0)
		/// Opcode values isn't parsed yet so is difucult to know whether or not is an exception ...
		if (0 && (/*st = */err_handle_legacy_prefixes(&dest->i_flags)) != SUCCESS)
		{} // error

		if (IS_REXBYTE(**iraw))
		{
			get_rex_prefix(&dest->i_flags, iraw);
			skip_duplicated(iraw, 0xF0);
		}

		if (IS_GPM_ESCAPE(**iraw))
		{
			dest->i_opcode[0] = *((*iraw)++);

			if (IS_GPM_ESCAPE2(**iraw))
				dest->i_opcode[1] = *((*iraw)++);
		}
	}		
}

__always_inline
static const opfield_t* get_map(AVL_instruction_t* const inst)
{
	const opfield_t* map;

	if (!AVL_HAS_OP_VEX_PFX(inst))
		map = get_map_legacy(inst);
	else
		map = get_map_vex(inst->i_vp, AVL_HAS_OP_EVEX_PFX(inst->i_flags));

	return map;
}

__always_inline
static opfield_t get_opfield(AVL_instruction_t* const inst, const opfield_t* map, const ubyte** iraw, ubyte* const is_k_inst)
{
	const ubyte row = GET_ROW(inst->i_opcode[2]);
	opfield_t found = {};

	if (IS_K_INSTRUCTION_0F(map, row, inst))
	{
		*is_k_inst = 0x1;
		handle_k_instructions_0x0F(&found, inst->i_opcode[2]);
	}
	else if (IS_OVERWRITING_EVEX_0F(map, inst))
		handle_overwriting_evex_instructions_0F(&found, inst->i_opcode[2], inst->i_flags);
	else if (found.mnemonic == 0)
		found = map[GET_MAP_INDEX(inst->i_opcode[2])];

	if (HAS_GROUP_EXTENTION(found.symbol))
	{
		found = get_instruction_by_extension_one_and_two_b_opmap(found.mnemonic, found, **iraw, inst->i_flags);
		if (found.am1 == 0 || OPERAND_HAS_IMMEDIATE(found.am1))
			(*iraw)++;
	}
	else if (IS_OPMAP_INDEXING(found.am1) || map == lt_three_byte_0x38_opmap)
		redirect_indexing_opfield(inst, map, &found, is_k_inst);

	return found;
}

__always_inline
static void	get_suffix_data(AVL_instruction_t* const dest, opfield_t found, const ubyte** iraw)
{
	ubyte opattr = INST_HAS_MODRM(found) ? HAS_ATTR_MODRM : 0x0;

	if (opattr & HAS_ATTR_MODRM)
		opattr |= get_modrm(dest, iraw);
	if (opattr & HAS_ATTR_SIB)
		opattr |= get_sib(dest, iraw);
	if (HAS_ATTR_DISP(opattr))
		get_displacement(&dest->i_disp, iraw, GET_DISP_LENGHT(opattr));
}

static err_t	get_instruction(AVL_instruction_t* const dest, const ubyte** iraw)
{
	err_t				st = SUCCESS;
	const ubyte* const	istart = *iraw;
	const opfield_t*	map;
	opfield_t 			found = {};
	ubyte				is_k_inst = 0;

	///TODO: In some documentation i found that these are the 'SIMD prefixes'
	///READ: https://xem.github.io/minix86/manual/intel-x86-and-64-manual-vol2/o_b5573232dd8f1481-74.html
	/// And take more notes

	get_prefix_data(dest, iraw);

	dest->i_opcode[2] = *((*iraw)++);

	if (IS_ESCAPE_FX87(dest))
		found = handle_x87_instructions(dest, iraw);
	else
	{
		map = get_map(dest);
		found = get_opfield(dest, map, iraw, &is_k_inst);
	}

	dest->i_mnemonic = found.mnemonic;

	get_suffix_data(dest, found, iraw);
	handle_ambigious_arguments(&found, map, dest);
	get_operand_size(dest, &found, is_k_inst);

	if (OPFIELD_HAS_IMMEDIATE(found))
		get_immediate(dest, found, iraw);

	resolve_operands(dest, found);

	dest->i_size = *iraw - istart;

	return st;
}

void	get_instructions(AVL_instruction_t* const dest, uqword destlen, const ubyte** iraw)
{
	for (uqword i = 0 ; i < destlen ; i++)
		get_instruction(&dest[i], iraw);
}







/// SUPORTED:
/// LEGACYPREFIX::= [ 0xF0 | 0xF2 | 0xF3] [0x64 | 0x65 | 0x2E | 0x3E ] [ 0x66 ] [ 0x67 ]
/// REXPREFIX::= 0b{0100}{W:1}{R:1}{X:1}{B:1}
/// VEXPREFIX::= 
/// PREFIX::=  ([LEGACYPREFIX] [REXPREFIX]) | ([LEGACYPREFIX] [VEXPREFIX])
/// OPCODEPREFIX::= (0x66 | 0xF2 | 0xF3) 0x0F [ 0x38 | 0x3A ]) | 0x0F [ 0x38 | 0x3A ]
/// OPCODE::= [OPCODEPREFIX] 0bXXXXXXXX
/// MODRM::= 0b{MOD:2}{REG:3}{RM:3}
/// SIB::= 0b{SCALE:2}{INDEX:3}{BASE:3}
/// DISPLACEMENT::= 8 | 32 bits
/// IMMEDIATE::= 8 | 16 | 32 | 64 bits
/// INSTRUCTION::= [PREFIX] OPCODE [MODRM] [SIB] [DISP] [IMM]
