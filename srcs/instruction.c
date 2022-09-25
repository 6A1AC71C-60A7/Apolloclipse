
#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

#include <user.h>

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

#define IS_GPM_MANDATORY_PREFIX(x) ( \
	/*(x) == 0x66*/ \
	/*|| */ (x) == 0xF2 \
	|| (x) == 0xF3 \
)

#define IS_GPM_ESCAPE(x) ((x) == 0x0F)
#define IS_GPM_ESCAPE2_0x38(x) ((x) == 0x38)
#define IS_GPM_ESCAPE2_0x3A(x) ((x) == 0x3A)
#define IS_GPM_ESCAPE2(x) (IS_GPM_ESCAPE2_0x38(x) || IS_GPM_ESCAPE2_0x3A(x))
#define IS_REXBYTE(x) (((x) & 0b11110000) == 0b01000000)
#define VEX2BYTES_PREFIX 0xC5
#define VEX3BYTES_PREFIX 0xC4
#define IS_VEX_PREFIX(x) ((x) == VEX2BYTES_PREFIX || (x) == VEX3BYTES_PREFIX)
#define EVEXBYTES_PREFIX 0x62
#define IS_EVEX_PREFIX(x) ((x) == EVEXBYTES_PREFIX)
//#define GET_MAP_INDEX(x) (((x) & 0x0F) + ((((x) & 0xF0) >> 0x4) * 0x10))
#define IS_OPMAP_INDEXING(x) ((x) == AMB)


__always_inline
static void skip_duplicated(const ubyte** target, ubyte mask)
{
	for (const ubyte* pdup = *target ; (*pdup & mask) == (**target & mask) ; (*target)++)
		;
}



__always_inline
static const opfield_t* get_map_vex(ubyte* const vex, ubyte isevex)
{
	/* If instruction is 2 bytes vec prefix, the map is always
		as it was prefixed with 0x0F */

	if (isevex == 0 && vex[2] == 0)
	{
		DEBUG("VEX: MAP 2BYTE\n");
		return lt_two_byte_opmap;
	}

	const ubyte mmmmm = isevex ? ((AVL_evex_t*)vex)->evx_opmap : ((AVL_vex_t*)vex)->vx_opmap;
	const opfield_t* map;

	DEBUG("VEX MAP SELECT FIELD IS: %d\n", mmmmm);

	switch (mmmmm)
	{
		case 0b01:
			DEBUG("VEX: MAP 2BYTE\n");
			map = lt_two_byte_opmap;
			break ;

		case 0b10:
			DEBUG("VEX: MAP 3BYTE (8)\n");
			map = lt_three_byte_0x38_opmap;
			break ;

		case 0b11:
			DEBUG("VEX: MAP 3BYTE (A)\n");
			map = lt_three_byte_0x3A_opmap;
			break ;
	}

	return map;
}

__always_inline
static const opfield_t*	get_map_legacy(AVL_instruction_t* const inst)
{
	const opfield_t* map;

	if (IS_GPM_ESCAPE(inst->i_opcode[0]))
	{
		map = lt_two_byte_opmap;
		if (IS_GPM_ESCAPE2_0x38(inst->i_opcode[1]))
		{
			DEBUG("DEBUG: IS 0x38 OPCODE MAP\n");
			map = lt_three_byte_0x38_opmap;
		}
		else if (IS_GPM_ESCAPE2_0x3A(inst->i_opcode[1]))
		{
			DEBUG("DEBUG: IS 0x3A OPCODE MAP\n");
			map = lt_three_byte_0x3A_opmap;
		}
		else
			DEBUG("DEBUG: IS TWO OPCODE MAP\n");
	}
	else
	{
		DEBUG("DEBUG: IS ONE OPCODE MAP\n");
		map = lt_one_byte_opmap;
	}

	return map;
}

__always_inline
static opfield_t	handle_x87_instructions(AVL_instruction_t* const inst, const ubyte** iraw)
{
	const opfield_t*	map;
	uqword				map_index;
	opfield_t			found;

	inst->i_mod_rm = *((*iraw)++);

	DEBUG("DEBUG x87: MODRM IS 0x%02X\n", inst->i_mod_rm);

	/* Documentation's map starts at 0xC0 (fields from 0x0 to 0x0 are zeroed), so I've stripped those in mine */
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

	DEBUG("DEBUG x87: MAP INDEX: %"PRId64"\n", map_index);

	DEBUG("DEBUG x87: IS BIG MAP: %d\n", map == lt_escape_0xD9_outside_modrm_opmap);

	found = map[map_index];

	inst->i_mnemonic = found.mnemonic;

	DEBUG("DEBUG x87: MNEMONIC IS: %d\n", inst->i_mnemonic);

	return found;
}

__always_inline
static void handle_evex_addons_0x0F_opmap(opfield_t* const found, ubyte opcode, udword prefix)
{
	if (AVL_HAS_MP_0x66_PFX(prefix))
	{
		if (opcode == 0x72)
		{
			// *found = (opfield_t){ .mnemonic = VPROLD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
			// if (prefix & AVL_RP_REXW_MASK)
			// 	found->mnemonic = VPROLQ;
			// ///TODO: HANDLE HERE VPRORLD/Q TOOO !!!
		}
	}
	else if (AVL_HAS_MP_0xF3_PFX(prefix))
	{
		// if (opcode == 0xE6)
		// 	*found = (opfield_t){ .mnemonic = VCVTQQ2PD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
	}
	else if (!AVL_HAS_MP_0xF2_PFX(prefix))
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
			// if (found->mnemonic == VCVTPD2UQQ)
			// 	found->mnemonic = VCVTPS2UQQ;
			// else if (found->mnemonic == VCVTTPD2UQQ)
			// 	found->mnemonic = VCVTTPS2UQQ;
		}
		else
		{
			if (found->mnemonic == VCVTDQ2PS)
				found->mnemonic = VCVTQQ2PS;
		}

		
	}
}


__always_inline
static void handle_ambigious_instructions_0x0F_opmap(opfield_t* const found, ubyte opcode)
{
	switch (opcode)
	{
		case 0x41:
			// kand {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KAND, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x42:
			// kandn {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KANDN, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x44:
			// knot {k1: MODRM.REG, k2: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KNOT, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x45:
			// kor {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x46:
			// kxnor {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KXNOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x47:
			// kxor {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KXOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x4A:
			// kadd {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KADD, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x4B:
			// kunpck {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 16:0x66,W0 ; 32:0x66:W1 ; 64:W1}
			///TODO: This operand size resolution is very UNIQUE
			*found = (opfield_t){ .mnemonic = KUNPCK, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x90:
			// kmov {k1: MODRM.REG, k2: if(MODRM.MOD==0b11)MODRM.RM else ADDR}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x91:
			// kmov {k1: ADDR, k2: MODRM.REG}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_M, .ot1 = OT_ALL, .am2 = AM_KR, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x92:
			// kmov {k1: MODRM.REG, k2: ADDR}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_R, .ot2 = OT_Y, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x93:
			// kmov {k1: ADDR, k2: MODRM.REG}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_G, .ot1 = OT_Y, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x98:	
			// kortest {k1: MODRM.REG, k2: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KORTEST, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x99:
			// ktest {k1: MODRM.REG, k2: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KTEST, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;
	}
}

#define IS_EVEX_COLISION_0x0F(x, p) ( \
	(!((p) & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) && (x) == 0x79) \
	/*|| ((p) & AVL_MP_0xF3_MASK && (x) == 0xE6)*/ \
	|| (!((p) & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) && (x) == 0x5B) \
	|| (!((p) & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) && (x) == 0x78) \
	/*|| ((p) & AVL_MP_0x66_MASK && (x) == 0x72)*/ \
)

///WTF: If i copy paste this to another file it doesn't work anymore ...
///TODO: Change arguments and add an AVL_instruction_t instead
__always_inline
static void redirect_indexing_opfield(const opfield_t* map, opfield_t* const found, ubyte opcode, ubyte* pvex, AVL_instruction_t* const inst)
{
	uqword scale = 0;
	ubyte no_overwrite = 0;

	if (map == lt_two_byte_opmap)
	{
		const ubyte line = (opcode & 0xF0) >> 4;
	
		DEBUG("DEBUG: LINE: %d, HAS 0x66: %d\n", line, inst->i_flags & AVL_MP_0x66_MASK);

		if (AVL_HAS_MP_0x66_PFX(inst->i_flags) && !(line >= 0x9 && line <= 0xB))
			scale = 1;
		if (AVL_HAS_MP_0xF3_PFX(inst->i_flags))
			scale = 2;
		if (AVL_HAS_MP_0xF2_PFX(inst->i_flags))
			scale = 3;

		DEBUG("--> INDEX IS %"PRId64"\n", found->mnemonic + (0x76 * scale));

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

				case VCVTUDQ2PD:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VCVTUQQ2PD;
					break ;

				case VCVTUDQ2PS:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VCVTUQQ2PS;
					break ;

				case VCVTPD2UQQ:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VCVTPS2UQQ;
					break ;

				case VCVTTPD2QQ:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VCVTTPS2QQ;
					break ;

				case VCVTTPD2UQQ:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
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
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->ot1 = OT_D;
					break ;

				case VPSRAD:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VPSRAQ;
					break ;

				case VCVTDQ2PD:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VCVTQQ2PD;
					break ;

			}
		}
	}
	else if (map == lt_three_byte_0x38_opmap)
	{
		if (inst->i_flags & (AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK))
		{
			if (opcode >= 0xF0 && opcode < 0xF8)
				handle_rare_prefixes_0x38_opmap(found, opcode, inst->i_flags);
			else if (inst->i_flags & AVL_OP_EVEX_MASK)
				handle_evex_addons_0x38_opmap(found, opcode, inst->i_flags);
		}
		else
		{
			if (inst->i_flags & AVL_MP_0x66_MASK)
			{
				scale = 1;
				if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
				{
					switch (opcode)
					{
						
						///TODO: no_overwrite solution is trash

						case 0x10:
							*found = (opfield_t){ .mnemonic = VPSRLVW,	.am1 = AM_V,	.ot1 = OT_X,	.am2 = AM_H,	.ot2 = OT_X,	.am3 = AM_W,	.ot3 = OT_X,	.am4 = 0,	.ot4 = 0,	.symbol = S_V };
							no_overwrite = 1;
							break ;

						case 0x14:
							*found = (opfield_t){ .mnemonic = VPRORVD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							if (AVL_HAS_REXW_PFX(inst->i_flags))
								found->mnemonic = VPRORVQ;
							no_overwrite = 1;
							break ;

						case 0x15:
							*found = (opfield_t){ .mnemonic = VPROLVD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							no_overwrite = 1;
							break ;

						// case 0x1A:
						// 	*found = (opfield_t){ .mnemonic = VBROADCASTF32X4,	.am1 = AM_V,	.ot1 = OT_QQ,	.am2 = AM_M,	.ot2 = OT_DQ,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_V };
						// 	if (prefix & AVL_RP_REXW_MASK)
						// 		found->mnemonic = VBROADCASTF64X2;
						// 	no_overwrite = 1;
						// 	break ;

						// case 0x1B:
						// 	*found = (opfield_t){ .mnemonic = VBROADCASTF32X8,	.am1 = AM_V,	.ot1 = OT_QQ,	.am2 = AM_M,	.ot2 = OT_DQ,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
						// 	if (prefix & AVL_RP_REXW_MASK)
						// 		found->mnemonic = VBROADCASTF64X4;
						// 	no_overwrite = 1;
						// 	break ;

						case 0x2C:
							*found = (opfield_t){ .mnemonic = VSCALEFPD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							no_overwrite = 1;
							break ;

						case 0x2D:
							*found = (opfield_t){ .mnemonic = VSCALEFSD, .am1 = AM_V, .ot1 = OT_DQ, .am2 = AM_H, .ot2 = OT_DQ, .am3 = AM_W, .ot3 = OT_DQ, .am4 = 0, .ot4 = 0, .symbol = 0 };
							no_overwrite = 1;
							break ;
					}
				}
			}
			if (!no_overwrite)
				*found = lt_three_byte_0x38_opmap[GET_MAP_INDEX(opcode) + (0x100 * scale)];
			DEBUG("[DEBUG INDEXING MAP 0x0F38] INDEX IS [%ld] (mnemonic='%d')\n", GET_MAP_INDEX(opcode) + (0x100 * scale), found->mnemonic);

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
						if (((AVL_evex_t*)pvex)->evx_vlen2)
							found->ot1 = OT_DQQ;
						// if (AVL_GET_MODRM_MOD(modrm) != 0b11)
						// 	found->ot2 = OT_DQ;
						break ;

					case VBROADCASTSD:
						if (!AVL_HAS_REXW_PFX(inst->i_flags))
							found->mnemonic = VBROADCASTF32X2;
						if (((AVL_evex_t*)pvex)->evx_vlen2)
							found->ot1 = OT_DQQ;
						// if (AVL_GET_MODRM_MOD(modrm) != 0b11)
						// 	found->ot2 = OT_DQ;
						break ;

					case VBROADCASTF32X8:
						if (AVL_HAS_REXW_PFX(inst->i_flags))
							found->mnemonic = VBROADCASTF64X4;
						if (((AVL_evex_t*)pvex)->evx_vlen2)
							found->ot1 = OT_DQQ;
						// if (AVL_GET_MODRM_MOD(modrm) != 0b11)
						// 	found->ot2 = OT_DQ;
						break ;

					case VGATHERQPS:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VGATHERQPD;
						else if (((AVL_evex_t*)pvex)->evx_vlen2)
						{
							found->ot1 = OT_QQ;
							found->ot2 = OT_QQ;
						}
						else if (((AVL_evex_t*)pvex)->evx_vlen)
						{
							found->ot1 = OT_DQ;
							found->ot2 = OT_DQ;
						}
						else
							found->ot2 = OT_Q;
						// fall through
					case VGATHERDPS:
						// because strange swtich witout break "found->mnemonic == VGATHERDPS"
						if (found->mnemonic == VGATHERDPS && inst->i_flags & AVL_RP_REXW_MASK)	
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
							if (!((AVL_evex_t*)pvex)->evx_vlen && !((AVL_evex_t*)pvex)->evx_vlen2)
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

					case VSCATTERDPD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VSCATTERDPS;
						break ;

					case VSCATTERQPD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VSCATTERQPS;
						break ;

					case VPSCATTERDD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPSCATTERDQ;
						break ;

					case VPSCATTERQD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPSCATTERQQ;
						break ;

					case VGETEXPPD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VGETEXPPS;
						break ;

					case VGETEXPSD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VGETEXPSS;
						break ;

					case VPBLENDMB:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPBLENDMW;
						break ;

					case VPBLENDMD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPBLENDMQ;
						break ;

					case VPBROADCASTD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
						{
							found->mnemonic = VPBROADCASTQ;
							found->ot2 = OT_Q;
						}
						break ;

					case VPCOMPRESSD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPCOMPRESSQ;
						break ;
					
					case VPCONFLICTD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPCONFLICTQ;
						break ;

					case VPERMI2B:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPERMI2W;
						break ;

					case VPERMI2D:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPERMI2Q;
						break ;

					case VPERMI2PD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VPERMI2PS;
						break ;

					case VPERMT2B:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPERMT2W;
						break ;

					case VPERMT2D:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPERMT2Q;
						break ;

					case VPERMT2PD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VPERMT2PS;
						break ;

					case VPEXPANDD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPEXPANDQ;
						break ;
					
					case VPLZCNTD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPLZCNTQ;
						break ;

					case VPROLVD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPROLVQ;
						break ;

					case VPTESTMB:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPTESTMW;
						break ;

					case VPTESTMD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPTESTMQ;
						break ;

					case VRCP14PD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VRCP14PS;
						break ;

					case VRCP14SD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VRCP14SS;
						break ;

					case VRSQRT14PD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VRSQRT14PS;
						break ;

					case VRSQRT14SD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VRSQRT14SS;
						break ;

					case VSCALEFPD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VSCALEFPS;
						break ;

					case VSCALEFSD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VSCALEFSS;
						break ;

					case VPMAXSD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPMAXSQ;
						break ;

					case VPMULLD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPMULLQ;
						break ;

					case VPMINUD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPMINUQ;
						break ;

					case VPMINSD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPMINSQ;
						break ;

					case VPMAXUD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPMAXUQ;
						break ;

					case VPERMB:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPERMW;
						break ;

					case VPERMPS:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPERMPD;
						break ;

					case VPERMD:
						if (inst->i_flags & AVL_RP_REXW_MASK)
							found->mnemonic = VPERMQ;
						break ;

					case VBLENDMPD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VBLENDMPS;
						break ;

					case VEXPANDPD:
						if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VEXPANDPS;
						break ;
				}
			}
		}
	}
	else if (map == lt_three_byte_0x3A_opmap)
	{
		///TODO: Most of these instructions have prefixes,
		/// Most of them are not checked because there's only
		/// one ambigious instruction. I have to check them validation.

		if (opcode == 0x0F && AVL_HAS_MP_0x66_PFX(inst->i_flags))
			found->mnemonic = AMB_VPALIGNR_INDEX;
		*found = lt_tree_byte_0x3A_ambigious_opmap[found->mnemonic];

		///TODO: Handle ambigiousness otherway (create a single function)
		/// Temporary solution (cause i doesn't know the amount and all  kinds of ambigiousness)

		if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
		{
			switch (opcode)
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
					if (((AVL_evex_t*)pvex)->evx_vlen2)
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

				case 0x26:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VGETMANTPS;
					break ;
				
				case 0x27:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
							found->mnemonic = VGETMANTSS;
					break ;

				case 0x3E:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VPCMPUW;
					break ;

				case 0x3F:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VPCMPW;
					break ;

				case 0x1E:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VPCMPUQ;
					break ;

				case 0x1F:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VPCMPQ;
					break ;

				case 0x25:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VPTERNLOGQ;
					break ;

				case 0x50:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VRANGEPS;
					break ;

				case 0x51:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VRANGESS;
					break ;

				case 0x56:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VREDUCEPS;
					break ;

				case 0x57:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VREDUCESS;
					break ;

				case 0x23:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VSHUFF64X2;
					break ;

				case 0x43:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VSHUFI64X2;
					break ;

				case 0x54:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VFIXUPIMMPS;
					break ;
				
				case 0x55:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VFIXUPIMMSS;
					break ;

				case 0x66:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VFPCLASSPS;
					break ;

				case 0x67:
					if (!(inst->i_flags & AVL_RP_REXW_MASK))
						found->mnemonic = VFPCLASSSS;
					break ;

				case 0x03:
					if (inst->i_flags & AVL_RP_REXW_MASK)
						found->mnemonic = VALIGNQ;
					break ;

				// case 0x16:
				// 	if (prefix & AVL_RP_REXW_MASK)
				// 		found->mnemonic = VPERMPD;
				// 	break ;
			}
		}
		else if (found->mnemonic == KSHIFTL || found->mnemonic == KSHIFTR)
		{
			///TODO: Need the prefix here as pointer !! (change areguments)

			if (opcode == 0x30 || opcode == 0x32)
			{
				//inst->i_flags |= inst->i_flags & AVL_RP_REXW_MASK ? OS_WORD_MASK : OS_BYTE_MASK;
				AVL_SET_OPSZ(inst->i_flags, AVL_HAS_REXW_PFX(inst->i_flags) ? AVL_OPSZ_WORD : AVL_OPSZ_BYTE);
			}
			else if (opcode == 0x31 || opcode == 0x33)
			{
				//inst->i_flags |= inst->i_flags & AVL_RP_REXW_MASK ? OS_QWORD_MASK : OS_DWORD_MASK;
				AVL_SET_OPSZ(inst->i_flags, AVL_HAS_REXW_PFX(inst->i_flags) ? AVL_OPSZ_QWORD : AVL_OPSZ_DWORD);
			}
		}
	}
	else
	{
		/// ERROR:
	}
}

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


__always_inline
static ubyte	get_opcode_attributes(mnemonic_t* const mnemonic, opfield_t opfield)
{
	*mnemonic = opfield.mnemonic;

	ubyte opattr = 0;

	if (has_modrm(opfield))
		opattr |= HAS_ATTR_MODRM;

	return opattr;
}

//#define IS_RM_EXTENDED(rex_b, vexxop) ((rex_b) || (((vexxop)[0] == 0xC4 || (vexxop)[0] == 0x8F) && VEXXOP_B_GET(vexxop)))







__always_inline
static void		handle_ambigious_arguments(opfield_t* const found, const opfield_t* map, AVL_instruction_t* const inst)
{
	const ubyte opcode = inst->i_opcode[2];

	///TODO: Preform (move) the ambigiousness handling in group extensions here ?
	/// MMM parse is a lot more complex, i don't think so (seems not worth)

	if (map == lt_one_byte_opmap)
	{
		if (opcode == 0x90)
		{
			if ((inst->i_flags & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) == 0
			&& inst->i_flags & (AVL_RP_REXB_MASK | AVL_RP_REXW_MASK))
				*found = (opfield_t){ .mnemonic = XCHG,	.am1 = DR_R8,	.ot1 = DRS_64,	.am2 = DR_RAX,	.ot2 = DRS_64,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			else if (AVL_HAS_MP_0xF3_PFX(inst->i_flags))
				found->mnemonic = PAUSE;
		}
	}
	else if (map == lt_three_byte_0x38_opmap)
	{
		if (AVL_HAS_MP_0x66_PFX(inst->i_flags) && AVL_GET_MODRM_MOD(inst->i_mod_rm) != 0b11)
		{
			switch (opcode)
			{
				case 0x20:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x21:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x22:
					found->am2 = AM_M;
					found->ot2 = OT_W;
					break ;

				case 0x23:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x24:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x25:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x30:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x31:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x32:
					found->am2 = AM_M;
					found->ot2 = OT_W;
					break ;

				case 0x33:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x34:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x35:
					found->am2 = AM_M;
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

		if (opcode == 0x22 && AVL_HAS_REXW_PFX(inst->i_flags))
			found->mnemonic = VPINSRQ;
		else if (opcode == 0x16 && AVL_HAS_REXW_PFX(inst->i_flags))
			found->mnemonic = VPEXTRQ;

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
							if (inst->i_vp[2] ? ((AVL_vex_t*)inst->i_vp)->vx_vlen : ((AVL_vex2_t*)inst->i_vp)->vx2_vlen)
								found->mnemonic = VZEROALL;
							else
								found->mnemonic = VZEROUPPER;
						}
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
			else if (opcode >= 0x74 && opcode <= 0x76 && inst->i_flags & AVL_MP_0x66_MASK)
			{
				if (inst->i_flags & AVL_OP_EVEX_MASK)
					found->am1 = AM_KR;
			}
		}
	}

	inst->i_mnemonic = found->mnemonic;
}

// #define IS_ONE_BYTE_OPCODE_MAP(x) (*(uword*)(x) == 0x0)
// #define IS_TWO_BYTE_OPCODE_MAP(x) (*(uword*)(x) == 0xF)
// #define IS_WORD_OVERWRITABLE_TWOBYTES_OPMAP(x) (((x) >= 0x9 && (x) <= 0xC) || (x) == 0x0 || (x) == 0x4)
// //#define OS_RESET(x) ((x) &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK))
// #define IS_DEFAULT_REGISTER(x) ((x) >= 32)
// #define IS_TWO_BYTE_NONVEX_SIMD(x) (((x) >= 0x1 && (x) <= 0x2) || ((x) >= 0x5 && (x) <= 0x7) || (x) >= 0xC)

#define HAS_GROUP_EXTENTION(x) ((x == S_1A))


err_t	get_instruction_V2(AVL_instruction_t* const dest, const ubyte** iraw)
{
	err_t		st = SUCCESS;

	ubyte		isvex = 0x0;
	ubyte		skip_pref = 0x0;
	ubyte		isescape;
	ubyte		isrex;
	ubyte		opattr;

	const ubyte* const istart = *iraw;

	DEBUG("DEBUG: FIRST BYTE IS: %02X\n", **iraw);

opcode_check:

	///TODO: In some documentation i found that these are the 'SIMD prefixes'
	///READ: https://xem.github.io/minix86/manual/intel-x86-and-64-manual-vol2/o_b5573232dd8f1481-74.html
	/// And take more notes
	///TODO: IF OPCODE MAP 0X66 IS ONE BYTE OPCODE MAP 0X66 MEANS 16 BYTES OPERAND SIZE ...
	/// https://stackoverflow.com/questions/68289333/is-there-a-default-operand-size-in-the-x86-64-amd64-architecture
	
	// while (skip_pref == 0 && IS_GPM_MANDATORY_PREFIX(**iraw))
	// {
	// 	switch (**iraw)
	// 	{
	// 		// case 0x66:
	// 		// 	*(udword*)dest->prefix |= AVL_MP_0x66_MASK;
	// 		// 	break ;

	// 		// case 0x67:
	// 		// 	*(udword*)dest->prefix |= MP_0x67_MASK;
	// 		// 	break ;

	// 		///TODO: 0xF2 and 0xF3 are already parsed like is done with
	// 		/// 0x66 and 0x67 but i don't know if i'm fcking up
	// 		/// something by removing them form here.
	// 		/// Maybe thay need to be checked before REX ...
	// 		/// TODO: I must fix this, not have ambigious/repeated shit
	// 		///SOLUTION: Check legacy prefixes (legacy_prefixes) before REX

	// 		// case 0xF2:
	// 		// 	*(udword*)dest->prefix |= AVL_MP_0xF2_MASK;
	// 		// 	break ;

	// 		// case 0XF3:
	// 		// 	*(udword*)dest->prefix |= AVL_MP_0xF3_MASK;
	// 		// 	break ;
	// 	}
	// 	skip_duplicated(iraw, 0xFF);
	// }

	DEBUG("::::: BEFORE: %02X\n", **iraw);

	if ((isvex | isescape) == 0 && (isrex = IS_REXBYTE(**iraw)))
	{
		DEBUG("---> HAS REX BYTE <---\n");
		get_rex_prefix(&dest->i_flags, iraw);
		skip_duplicated(iraw, 0xF0);
	}

	DEBUG("::::: AFTER: %02X\n", **iraw);

	if (dest->i_opcode[0] == 0 && (isescape = IS_GPM_ESCAPE(**iraw)))
	{
		dest->i_opcode[0] = **iraw;
		(*iraw)++;

		if (IS_GPM_ESCAPE2(**iraw))
		{
			dest->i_opcode[1] = **iraw;
			(*iraw)++;
		}
	}

	///TODO: This is not an error for: mov WORD PTR [rsp + 880000], 42
	// else if (*(udword*)dest->prefix & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK))
	// {
	// 	st = EINVOPCODE;
	// 	goto error;
	// }

	if (skip_pref)
		goto skip_prefix_check;

	if ((isescape & isrex) == 0x0 && !dest->i_opcode[0])
	{
		if ((isvex = IS_EVEX_PREFIX(**iraw)))
		{
			get_evex_prefixes(dest, iraw);
			DEBUG("DEBUG: EVEX: [62][%02X][%02X][%02X]\n", dest->i_vp[0], dest->i_vp[1], dest->i_vp[2]);
		}
		else if ((isvex = IS_VEX_PREFIX(**iraw)))
		{
			get_vex_prefixes(dest, iraw);
			DEBUG("DEBUG: VEX: [%02X][%02X][%02X]\n", dest->i_vp[0], dest->i_vp[1], dest->i_vp[2]);
		}
		else if (*(uword*)dest->i_opcode == 0x0)
		{
			get_legacy_prefixes(&dest->i_flags, iraw);

			///TODO: Useful error check but for instructions which have have 2 prefixes fails
			/// They're always exceptions ... (0f 38 F0)
			/// Opcode values isn't parsed yet so is difucult to know whether or not is an exception ...
			if (0 && (st = err_handle_legacy_prefixes(&dest->i_flags)) != SUCCESS)
				goto error;

			DEBUG("[DEBUG] PREFIX AFTER: %d\n", dest->i_flags & AVL_MP_0xF2_MASK);
			DEBUG("[DEBUG] VALUE (**iraw) AFTER: %02X\n", **iraw);
		}		
	}

	if (isvex == 0x0)
	{
		skip_pref = 0x1;
		goto opcode_check;
	}

skip_prefix_check:

	dest->i_opcode[2] = *((*iraw)++);

	DEBUG("DEBUG: OPCODE IS [%02X][%02X][%02X]\n", dest->i_opcode[0], dest->i_opcode[1], dest->i_opcode[2]);

	opfield_t 			found = {};
	const opfield_t*	map = 0;
	ubyte not_overwrite = 0;

	if (dest->i_vp[0] == 0 && dest->i_opcode[0] == 0 && IS_ESCAPE_FX87(dest->i_opcode[2]))
		found = handle_x87_instructions(dest, iraw);
	else
	{
		map = !dest->i_vp[0] ? get_map_legacy(dest) : get_map_vex(dest->i_vp, (dest->i_flags & AVL_OP_EVEX_MASK) != 0);

		///TODO: Improve syntax using more defines for conditions

		const ubyte line = (dest->i_opcode[2] & 0xF0) >> 4;
	
		/* This is because AVX-512 K instructions use the same opcode than other
			opcodes (within 0x0F opcode map) but a diferent prefix (VEX) */
		if (map == lt_two_byte_opmap && (line == 0x4 || line == 0x9) && dest->i_vp[0])
		{
			handle_ambigious_instructions_0x0F_opmap(&found, dest->i_opcode[2]);
			
			if ((dest->i_opcode[2] >= 0x41 || dest->i_opcode[2] <= 0x47) || (dest->i_opcode[2] >= 0x90 && dest->i_opcode[2] <= 0x99)
			|| dest->i_opcode[2] == 0x4A || dest->i_opcode[2] == 0x4B) 
			{
				not_overwrite = 1;
				//OS_RESET(dest->i_flags);

				///TODO: Refrctor using ranges
				if (dest->i_opcode[2] == 0x90 || dest->i_opcode[2] == 0x91 || dest->i_opcode[2] == 0x4A
				|| dest->i_opcode[2] == 0x41 || dest->i_opcode[2] == 0x42 || dest->i_opcode[2] == 0x44
				|| dest->i_opcode[2] == 0x45 || dest->i_opcode[2] == 0x98
				|| dest->i_opcode[2] == 0x99 || dest->i_opcode[2] == 0x46
				|| dest->i_opcode[2] == 0x47)
				{
					
					if (AVL_HAS_REXW_PFX(dest->i_flags))
					{
						if (AVL_HAS_MP_0x66_PFX(dest->i_flags))
						{
							//dest->i_flags |= OS_DWORD_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DWORD);
						}
						else
						{
							//dest->i_flags |= OS_QWORD_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_QWORD);
						}
					}
					else
					{
						if (dest->i_flags & AVL_MP_0x66_MASK)
						{
							//dest->i_flags |= OS_BYTE_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_BYTE);
						}
						else
						{
							//dest->i_flags |= OS_WORD_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_WORD);
						}
					}
				}
				else if (dest->i_opcode[2] == 0x92 || dest->i_opcode[2] == 0x93)
				{
					if (AVL_HAS_MP_0xF2_PFX(dest->i_flags))
					{
						if (AVL_HAS_REXW_PFX(dest->i_flags))
						{
							//dest->i_flags |= OS_QWORD_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_QWORD);
						}
						else
						{
							//dest->i_flags |= OS_DWORD_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DWORD);
						}
					}
					else
					{
						if (AVL_HAS_MP_0x66_PFX(dest->i_flags))
						{
							//dest->i_flags |= OS_BYTE_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_BYTE);
						}
						else
						{
							//dest->i_flags |= OS_WORD_MASK;
							AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_WORD);
						}
					}
				}
				else if (dest->i_opcode[2] == 0x4B)
				{
					if (AVL_HAS_REXW_PFX(dest->i_flags))
					{
						//dest->i_flags |= OS_QWORD_MASK;
						AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_QWORD);
					}
					else if (AVL_HAS_MP_0x66_PFX(dest->i_flags))
					{
						//dest->i_flags |= OS_WORD_MASK;
						AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_WORD);
					}
					else
					{
						//dest->i_flags |= OS_DWORD_MASK;
						AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DWORD);
					}
				}

				if (dest->i_opcode[2] == 0x92 && !AVL_OPSZ_IS_QWORD(dest->i_flags))
					found.ot2 = OT_D;
				else if (dest->i_opcode[2] == 0x93 && !AVL_OPSZ_IS_QWORD(dest->i_flags))
					found.ot1 = OT_D;
			}
		}
		
		/* This is because AVX-512 EVEX instructions use the same opcode than other
			opcodes without EVEX prefix (within 0x0F opcode map) */
		else if (map == lt_two_byte_opmap && AVL_HAS_OP_EVEX_PFX(dest->i_flags) && IS_EVEX_COLISION_0x0F(dest->i_opcode[2], dest->i_flags))
			handle_evex_addons_0x0F_opmap(&found, dest->i_opcode[2], dest->i_flags);
		else if (found.mnemonic == 0)
			found = map[GET_MAP_INDEX(dest->i_opcode[2])];

		DEBUG("DEBUG: MAP INDEX: %d\n", GET_MAP_INDEX(dest->i_opcode[2]));
		//DEBUG("DEBUG: MNEMONIC: %d\n", found.mnemonic);
		DEBUG("2 ADDR MODE: [%d] [%d]\n", found.am1, found.am2);
		DEBUG("2 OPERAND TYPE: [%d %d]\n", found.ot1, found.ot2);

		if (HAS_GROUP_EXTENTION(found.symbol))
		{
			DEBUG("HAS EXTENSION\n");
			found = get_instruction_by_extension_one_and_two_b_opmap(found.mnemonic, found, **iraw, dest->i_flags);

			if (found.am1 == 0 || HAS_IMMEDIATE(found.am1))
				(*iraw)++;
		}

		if (IS_OPMAP_INDEXING(found.am1) || map == lt_three_byte_0x38_opmap)
		{
			DEBUG("IS INDEXING: %02X\n", dest->i_opcode[2]);
			redirect_indexing_opfield(map, &found, dest->i_opcode[2], dest->i_vp, dest);
		}
	}

	DEBUG("DEBUG: MNEMONIC: %d\n", found.mnemonic);

	opattr = get_opcode_attributes(&dest->i_mnemonic, found);

	if (opattr & HAS_ATTR_MODRM)
		opattr |= get_modrm(dest, iraw);
	DEBUG("OPATTR IS (no sib): %d\n", opattr);
	if (opattr & HAS_ATTR_SIB)
		opattr |= get_sib(dest, iraw);
	DEBUG("OPATTR IS (sib): %d\n", opattr);
	if (HAS_ATTR_DISP(opattr))
		get_displacement(&dest->i_disp, iraw, GET_DISP_LENGHT(opattr));

	handle_ambigious_arguments(&found, map, dest);
	if (!not_overwrite && dest->i_mnemonic != KSHIFTL && dest->i_mnemonic != KSHIFTR)
		get_operand_size(dest, &found);

	if (has_immediate(found))
		get_immediate(found, dest, iraw);
	else
		DEBUG("DEBUG: HAS NOT IMMEDIATE\n");

	//resolve_operands(dest, found);
	resolve_operands_v2(dest, found);

	dest->i_size = *iraw - istart;

error:
	DEBUG("IRAW AT THE END: %02X\n", **iraw);

	return st;
}

void	get_instructions(AVL_instruction_t* const dest, uqword destlen, const ubyte** iraw)
{
	for (uqword i = 0 ; i < destlen ; i++)
		get_instruction_V2(&dest[i], iraw);
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
