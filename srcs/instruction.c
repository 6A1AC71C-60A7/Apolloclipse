
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

#define IS_GPM_MANDATORY_PREFIX(x) ( \
	(x) == 0x66 \
	|| (x) == 0xF2 \
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
#define GET_MAP_INDEX(x) (((x) & 0x0F) + ((((x) & 0xF0) >> 0x4) * 0x10))
#define IS_OPMAP_INDEXING(x) ((x) == AMB)
#define IS_ESCAPE_FX87(x) ((x) >= 0xD8 && (x) <= 0xDF)

__always_inline
static void skip_duplicated(const ubyte** target, ubyte mask)
{
	for (const ubyte* pdup = *target ; (*pdup & mask) == (**target & mask) ; )
		(*target)++;
}

__always_inline
static void get_rex_prefix(udword* const dest, const ubyte** iraw)
{
	for (udword count = 0; count <= 3 ; count++)
	{
		if (**iraw & (1 << count))
			*dest |= RP_REXB_MASK << count;
	}
}

__always_inline
static void		get_legacy_prefixes(udword* const dest, const ubyte** iraw)
{
	udword	prefix_it;

#ifndef LP_STOP_IF_REPEATED
	udword	found;
#else
	udword	old;
#endif

	do
	{

#ifndef LP_STOP_IF_REPEATED
		found = 0;
#else
		old = *dest;
#endif
		prefix_it = 0;
		while (prefix_it < ARRLEN(lt_legacy_prefixes))
		{
			if (lt_legacy_prefixes[prefix_it] == **iraw)
			{
				*dest |= LP_LOCK_MASK << prefix_it;
#ifndef LP_STOP_IF_REPEATED
				found = 1;
				(*iraw)++;
				break ;
#endif
			}
			prefix_it++;
		}
#ifdef LP_STOP_IF_REPEATED
		(*iraw)++;
#endif
	}
#ifndef LP_STOP_IF_REPEATED
	while (found);
#else
	while (old != *dest);
#endif

}

__always_inline
static err_t	err_handle_legacy_prefixes(const udword* const dest)
{
	err_t err = SUCCESS;
	ubyte matches;
	uword dest_shift;

	matches = 0;
	if (*dest & 0b00000111)
	{
		if (*dest & 0b00000001)
			matches++;
		if (*dest & 0b00000010)
			matches++;
		if (*dest & 0b00000100)
			matches++;
		
		if (matches > 1)
		{
			err = EINVOPCODE;
			goto end;
		}
	}

	matches = 0;
	dest_shift = *dest >> 3;
	if (dest_shift & 0xff)
	{
		for (udword i = 0 ; i <= 0b10000000 ; i++)
		{
			if (*dest & (1U << i))
				matches++;
		}

		if (matches > 1)
			err = EINVOPCODE;
	}

end:
	return err;
}

__always_inline
static const opfield_t* get_map_vex(ubyte* const vex)
{
	/* If instruction is 2 bytes vec prefix, the map is always
		as it was prefixed with 0x0F */
	if (vex[2] == 0)
		return lt_two_byte_opmap;

	const ubyte mmmmm = VEXXOP_MAP_SELECT_GET(vex);
	const opfield_t* map;

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
static const opfield_t*	get_map_legacy(instruction_t* const inst)
{
	const opfield_t* map;

	if (IS_GPM_ESCAPE(inst->opcode[0]))
	{
		map = lt_two_byte_opmap;
		if (IS_GPM_ESCAPE2_0x38(inst->opcode[1]))
			map = lt_three_byte_0x38_opmap;
		else if (IS_GPM_ESCAPE2_0x3A(inst->opcode[1]))
			map = lt_three_byte_0x3A_opmap;
	}
	else
	{
		DEBUG("DEBUG: ONE OPCODE MAP\n");
		map = lt_one_byte_opmap;
	}

	return map;
}

static void		get_immediate(opfield_t opfield, instruction_t* const dest, const ubyte** iraw);

__always_inline
static opfield_t	handle_x87_instructions(instruction_t* const inst, const ubyte** iraw)
{
	const opfield_t*	map;
	uqword				map_index;
	opfield_t			found;


	inst->mod_rm = *((*iraw)++);

	/* Documentation map starts at 0x60 (fields from 0x0 to 0x60 are zeroed), so I've stripped those in mine */
	map_index = inst->mod_rm > 0xBF ? GET_MAP_INDEX(inst->mod_rm) - 0X60 : MODRM_REG_GET(inst->mod_rm);

	switch (inst->opcode[0])
	{
		case 0xD8:
			map = inst->mod_rm > 0xBF ? lt_escape_0xD8_outside_modrm_opmap : lt_escape_0xD8_within_modrm_opmap;
			break ;
	
		case 0xD9:
			map = inst->mod_rm > 0xBF ? lt_escape_0xD9_outside_modrm_opmap : lt_escape_0xD9_within_modrm_opmap;
			break ;

		case 0xDA:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDA_outside_modrm_opmap : lt_escape_0xDA_within_modrm_opmap;
			break ;

		case 0xDB:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDB_outside_modrm_opmap : lt_escape_0xDB_within_modrm_opmap;
			break ;

		case 0xDC:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDC_outside_modrm_opmap : lt_escape_0xDC_within_modrm_opmap;
			break ;

		case 0xDD:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDD_outside_modrm_opmap : lt_escape_0xDD_within_modrm_opmap;
			break ;

		case 0xDE:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDE_outside_modrm_opmap : lt_escape_0xDE_within_modrm_opmap;
			break ;

		case 0xDF:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDF_outside_modrm_opmap : lt_escape_0xDF_within_modrm_opmap;
			break ;
	}

	found = map[map_index];

	inst->mnemonic = found.mnemonic;

	return found;
}

__always_inline
static void redirect_indexing_opfield(const opfield_t* map, opfield_t* const found, udword prefix, ubyte opcode)
{
	uqword scale = 1;

	if (map == lt_two_byte_opmap)
	{
		if (prefix & MP_0x66_MASK)
			scale = 2;
		if (prefix & MP_0xF2_MASK)
			scale = 3;
		if (prefix & MP_0xF3_MASK)
			scale = 4;
		*found = lt_two_byte_ambigious_opmap[found->mnemonic * scale];
	}
	else if (map == lt_three_byte_0x38_opmap)
	{
		///TODO: ALL prefixes are not currently handled in the map
		if (prefix & MP_0x66_MASK)
			scale = 2;
		*found = lt_three_byte_0x38_opmap[GET_MAP_INDEX(opcode) * scale];
	}
	else if (map == lt_three_byte_0x3A_opmap)
	{
		///TODO: All the cases are not handled yet too
		*found = lt_tree_byte_0x3A_ambigious_opmap[found->mnemonic];
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

#define HAS_MODRM(x) ( \
	(x) != 0 && ( \
		(x) == AM_C \
		|| (x) == AM_D \
		|| (x) == AM_E \
		|| (x) == AM_G \
		|| (x) == AM_M \
		|| (x) == AM_N \
		|| (x) == AM_P \
		|| (x) == AM_Q \
		|| (x) == AM_R \
		|| (x) == AM_S \
		|| (x) == AM_U \
		|| (x) == AM_V \
		|| (x) == AM_W \
	) \
)

__always_inline
static ubyte	has_modrm(opfield_t opfield)
{
	return HAS_MODRM(opfield.am1) || HAS_MODRM(opfield.am2) || HAS_MODRM(opfield.am3) || HAS_MODRM(opfield.am4);
}

__always_inline
static ubyte	get_opcode_attributes(mnemonic_t* const mnemonic, opfield_t opfield)
{
	*mnemonic = opfield.mnemonic;

	ubyte opattr = 0;

	if (has_modrm(opfield))
		opattr |= HAS_ATTR_MODRM;

	return opattr;
}

#define IS_RM_EXTENDED(rex_b, vexxop) ((rex_b) || (((vexxop)[0] == 0xC4 || (vexxop)[0] == 0x8F) && VEXXOP_B_GET(vexxop)))

__always_inline
static ubyte	get_modrm(instruction_t* const inst, const ubyte** iraw)
{
	inst->mod_rm = *((*iraw)++);

	/* BYTE bits: { 0, 0, MOD[1], MOD[0], RM[3], RM[2], RM[1], RM[0] }
		(RM[3] is extended from REX.B/VEX.~B/XOP.~B */
	const ubyte rm = (IS_RM_EXTENDED(*(udword*)inst->prefix & RP_REXB_MASK,  inst->vexxop) << 0x3) | MODRM_RM_GET(inst->mod_rm);
	const ubyte index = (MODRM_MOD_GET(inst->mod_rm) << 0x4) | rm;

	DEBUG("DEBUG: MODRM INDEX IS %d\n", index);

	return lt_modrm_encoded[index];
}

#define IS_SINDEX_EXTENDED(rex_x, vexxop) ((rex_x) || (((vexxop)[0] == 0xC4 || (vexxop)[0] == 0x8F) && VEXXOP_X_GET(vexxop)))
#define IS_SBASE_EXTENDED(rex_b, vexxop) ((rex_b) || (((vexxop)[0] == 0xC4 || (vexxop)[0] == 0x8F) && VEXXOP_B_GET(vexxop)))

__always_inline
static ubyte	get_sib(instruction_t* const inst, const ubyte** iraw)
{
	inst->sib = *((*iraw)++);

	const ubyte mod = MODRM_MOD_GET(inst->mod_rm);
	const ubyte index = (IS_SINDEX_EXTENDED(*(udword*)inst->prefix & RP_REXX_MASK, inst->vexxop) << 0x3) | SIB_INDEX_GET(inst->sib);
	const ubyte base = (IS_SBASE_EXTENDED(*(udword*)inst->prefix & RP_REXB_MASK, inst->vexxop) << 0x3) | SIB_BASE_GET(inst->sib);

	/* WORD: bits: { 0, 0, 0, 0, 0, 0, MOD[1], MOD[0], INDEX[3], INDEX[2], INDEX[1], INDEX[0], BASE[3], BASE[2], BASE[1], BASE[0] }
		(INDEX[4] is extended from REX.X/VEX.~X/XOP.~X
		 BASE[4] is extended from REX.B/VEX.~B/XOP.~B) */
	const uword lt_index = ((uword)base | ((uword)index << 4) | ((uword)mod << 0x8)) & (uword)0b0000001111111111;

	return lt_sib_encoded[lt_index];
}

__always_inline
static void		get_displacement(udword* const dest, const ubyte** iraw, uqword nbits)
{
	DEBUG("GET DISPLACEMENT OF %lld BITS\n", nbits);

	if (nbits == 0x8)
		*dest = *((*iraw)++);
	else
		*dest = *((*(udword**)iraw)++);
}

__always_inline
static ubyte		find_operand_size_overwrite(udword* const dest, ubyte ot)
{
	const udword old = *dest;

	switch (ot)
	{
		case OT_B:
			*dest |= OS_BYTE_MASK;
			break ;

		case OT_W:
			*dest |= OS_WORD_MASK;
			break ;

		case OT_D:
			*dest |= OS_DWORD_MASK;
			break ;

		case OT_Q:
			*dest |= OS_QWORD_MASK;
			break ;
	}

	return *dest != old;
}

__always_inline
static void		get_operand_size_by_operand_type(udword* const dest, opfield_t found)
{
	ubyte unused __attribute__ ((unused)) = !find_operand_size_overwrite(dest, found.ot1) || !find_operand_size_overwrite(dest, found.ot2)
	|| !find_operand_size_overwrite(dest, found.ot3) || !find_operand_size_overwrite(dest, found.ot4);
}

static ubyte	is_mnemonic_default_64_bits(mnemonic_t mnemonic)
{
	///TODO: Only CALL near JMP near and RET near ?!?!
	///TODO: Mnemonic must have specific operands to be in this list ?
	///TODO: Jcc, jrCXZ, LOOPcc, MOVcr, MOVdr, 
	return mnemonic == CALL || mnemonic == ENTER || mnemonic == JMP || mnemonic == LEAVE
	|| mnemonic == LGDT || mnemonic == LIDT || mnemonic == LLDT || mnemonic == LOOP
	|| mnemonic == LTR || mnemonic == POP || mnemonic == POPF || mnemonic == PUSH
	|| mnemonic == PUSHF || mnemonic == RET;
}

#define IS_ONE_BYTE_OPCODE_MAP(x) (*(uword*)(x) == 0x0)

__always_inline
static void		get_operand_size(instruction_t* const dest, opfield_t found)
{
	///TODO: Handle > 64-bits

	udword* const prefix = (udword*)dest->prefix;

	if (*prefix & RP_REXW_MASK)
		*prefix |= OS_QWORD_MASK;
	else if (*prefix & MP_0x66_MASK && IS_ONE_BYTE_OPCODE_MAP(dest->opcode))
		*prefix |= OS_WORD_MASK;
	else if (is_mnemonic_default_64_bits(dest->mnemonic))
		*prefix |= OS_QWORD_MASK;
	else
		*prefix |= OS_DWORD_MASK;

	/* Previous could be ovewrited by the operand type of the instruction */

	get_operand_size_by_operand_type(prefix, found);		
}

#define HAS_IMMEDIATE(x) ( \
	(x) != 0 && (x) >= AM_I && (x) <= AM_L \
)

__always_inline
static ubyte	has_immediate(opfield_t opfield)
{
	return HAS_IMMEDIATE(opfield.am1) || HAS_IMMEDIATE(opfield.am2) || HAS_IMMEDIATE(opfield.am3) || HAS_IMMEDIATE(opfield.am4);
}

__always_inline
static ubyte	get_immediate_operand_type(opfield_t opfield)
{
	ubyte ot = 0;

	if (HAS_IMMEDIATE(opfield.am1))
		ot = opfield.ot1;
	if (HAS_IMMEDIATE(opfield.am2))
		ot = opfield.ot2;
	if (HAS_IMMEDIATE(opfield.am3))
		ot = opfield.ot3;
	if (HAS_IMMEDIATE(opfield.am4))
		ot = opfield.ot4;

	return ot;
}

__always_inline
static void		get_immediate(opfield_t opfield, instruction_t* const dest, const ubyte** iraw)
{
		const ubyte ot = get_immediate_operand_type(opfield);

	switch (ot)
	{
		case OT_B:
			dest->immediate = *((*iraw)++);
			break ;

		case OT_W:
			dest->immediate = *((*(uword**)iraw)++);
			break ;

		case OT_D:
			dest->immediate = *((*(udword**)iraw)++);
			break ;

		case OT_Q:
			dest->immediate = *((*(uqword**)iraw)++);
			break ;

		default:
		{
			const udword prefix = *(udword*)dest->prefix;

			if (prefix & RP_REXW_MASK)
				dest->immediate = *((*(uqword**)iraw)++);
			else
			{
				switch (ot)
				{
					case OT_C:
						if ((prefix & OS_BYTE_MASK) != 0)
							dest->immediate = *((*(uword**)iraw)++);
						else
							dest->immediate = *((*iraw)++);
						break ;

					case OT_V:
							if (prefix & OS_WORD_MASK)
								dest->immediate = *((*(uword**)iraw)++);
							else if (prefix & OS_DWORD_MASK)
								dest->immediate = *((*(udword**)iraw)++);
							else if (prefix & OS_QWORD_MASK)
								dest->immediate = *((*(uqword**)iraw)++);
						break ;

					case OT_Y:
						if (prefix & OS_QWORD_MASK)
							dest->immediate = *((*(udword**)iraw)++);
						else
							dest->immediate = *((*(uqword**)iraw)++);
						break ;

					case OT_Z:
						if (prefix & OS_WORD_MASK)
							dest->immediate = *((*(uword**)iraw)++);
						else if ((prefix & OS_WORD_MASK) != 0)
							dest->immediate = *((*(udword**)iraw)++);
						break ;
				}
			}
		}
	}
}

#define HAS_GROUP_EXTENTION(x) ((x == S_1A))

err_t	get_instruction_V2(instruction_t* const dest, const ubyte** iraw)
{
	err_t		st = SUCCESS;

	//ubyte		mandatory_prefix = 0x0;
	ubyte		isvex = 0x0;
	ubyte		skip_pref = 0x0;
	ubyte		isescape;
	ubyte		isrex;
	ubyte		opattr;

	const ubyte* const istart = *iraw;

opcode_check:

	///TODO: In some documentation i found that these are the 'SIMD prefixes'
	///READ: https://xem.github.io/minix86/manual/intel-x86-and-64-manual-vol2/o_b5573232dd8f1481-74.html
	/// And take more notes
	///TODO: IF OPCODE MAP 0X66 IS ONE BYTE OPCODE MAP 0X66 MEANS 16 BYTES OPERAND SIZE ...
	/// https://stackoverflow.com/questions/68289333/is-there-a-default-operand-size-in-the-x86-64-amd64-architecture
	if (IS_GPM_MANDATORY_PREFIX(**iraw))
	{
		//mandatory_prefix = **iraw;
		switch (**iraw)
		{
			case 0x66:
				*(udword*)dest->prefix |= MP_0x66_MASK;
				break ;

			case 0xF2:
				*(udword*)dest->prefix |= MP_0xF2_MASK;
				break ;

			case 0XF3:
				*(udword*)dest->prefix |= MP_0xF3_MASK;
				break ;
		}
		skip_duplicated(iraw, 0xFF);
	}

	if ((isescape = IS_GPM_ESCAPE(**iraw)))
	{
		dest->opcode[0] = **iraw;
		(*iraw)++;

		if (IS_GPM_ESCAPE2(**iraw))
		{
			dest->opcode[1] = **iraw;
			(*iraw)++;
		}
	}
	///TODO: This is not an error for: mov WORD PTR [rsp + 880000], 42
	// else if (*(udword*)dest->prefix & (MP_0x66_MASK | MP_0xF2_MASK | MP_0xF3_MASK))
	// {
	// 	st = EINVOPCODE;
	// 	goto error;
	// }

	if ((isrex = IS_REXBYTE(**iraw)))
	{
		get_rex_prefix((udword*)dest->prefix, iraw);
		skip_duplicated(iraw, 0xF0);
	}

	if (skip_pref)
		goto skip_prefix_check;

	if ((isescape & isrex) == 0x0)
	{
		if ((isvex = IS_VEX_PREFIX(**iraw)))
		{
			///TODO:
			// get vex prefix
		}
		else
		{
			get_legacy_prefixes((udword*)dest->prefix, iraw);
			if ((st = err_handle_legacy_prefixes((udword*)dest->prefix)) != SUCCESS)
				goto error;
		}		
	}

	if (isvex == 0x0)
	{
		skip_pref = 0x1;
		goto opcode_check;
	}

skip_prefix_check:

	dest->opcode[2] = *((*iraw)++);

	opfield_t found;

	if (IS_ESCAPE_FX87(dest->opcode[0]))
		///TODO: MAYBE THE PREFIX IS NOT ALWAYS IN THE opcode[0] index
		found = handle_x87_instructions(dest, iraw);
	else
	{
		const opfield_t*	map = !dest->vexxop[0] ? get_map_legacy(dest) : get_map_vex(dest->vexxop);
		
		found = map[GET_MAP_INDEX(dest->opcode[2])];

		DEBUG("DEBUG: MAP INDEX: %d\n", GET_MAP_INDEX(dest->opcode[2]));
		DEBUG("DEBUG: MNEMONIC: %d\n", found.mnemonic);
		DEBUG("2 ADDR MODE: [%d] [%d]\n", found.am1, found.am2);
		DEBUG("2 OPERAND TYPE: [%d %d]\n", found.ot1, found.ot2);

		if (HAS_GROUP_EXTENTION(found.symbol))
		{
			DEBUG("HAS EXTENSION\n");
			found = get_instruction_by_extension_one_and_two_b_opmap(found.mnemonic, *(*iraw + 1), *(udword*)dest->prefix, found);
		}

		if (IS_OPMAP_INDEXING(found.am1) || map == lt_three_byte_0x38_opmap)
		{
			DEBUG("IS INDEXING\n");
			redirect_indexing_opfield(map, &found, *(udword*)dest->prefix, dest->opcode[2]);
		}
	}

	opattr = get_opcode_attributes(&dest->mnemonic, found);


	if (opattr & HAS_ATTR_MODRM)
		opattr |= get_modrm(dest, iraw);
	DEBUG("OPATTR IS (no sib): %d\n", opattr);
	if (opattr & HAS_ATTR_SIB)
		opattr |= get_sib(dest, iraw);
	DEBUG("OPATTR IS (sib): %d\n", opattr);
	DEBUG("BEFORE BUG\n");
	if (HAS_ATTR_DISP(opattr))
		get_displacement(&dest->displacement, iraw, GET_DISP_LENGHT(opattr));
	DEBUG("AFTER BUG\n");

	get_operand_size(dest, found);
	
	if (has_immediate(found))
	{
		DEBUG("HAS IMMEDIATE\n");
		get_immediate(found, dest, iraw);
	}
	else
		DEBUG("DEBUG: HAS NOT IMMEDIATE\n");

	///TODO: SOMEWHERE FILL THE REG1, REG2, REG3 MEMBER

	dest->size = *iraw - istart;

error:
	return st;
}

void	get_instructions(instruction_t* const dest, uqword destlen, const ubyte** iraw)
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
