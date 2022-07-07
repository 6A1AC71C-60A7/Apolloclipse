#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

#define IS_RM_EXTENDED_XZCCXCXCXZXCXXC(rex_b, vexxop) ((rex_b) || (((vexxop)[0] == 0xC4 || (vexxop)[0] == 0x8F) && VEXXOP_B_GET(vexxop)))

__always_inline
static ubyte	parse_modRM(instruction_t* const inst, const ubyte** instruction_raw)
{
	inst->mod_rm = *((*instruction_raw)++);

	/*
	**	mod: register addressing or displacement
	**	reg: type of operation
	**	rm: which register is used
	**	https://stackoverflow.com/questions/15511482/x64-instruction-encoding-and-the-modrm-byte
	**	BETTER: https://datacadamia.com/lang/assembly/intel/modrm
	*/

	/* BYTE bits: { 0, 0, MOD[1], MOD[0], RM[3], RM[2], RM[1], RM[0] }
		(RM[3] is extended from REX.B/VEX.~B/XOP.~B */
	const ubyte rm = (IS_RM_EXTENDED_XZCCXCXCXZXCXXC(*(udword*)inst->prefix & RP_REXB_MASK, inst->vexxop) << 0x3) | MODRM_RM_GET(inst->mod_rm);
	const ubyte index = (MODRM_MOD_GET(inst->mod_rm) << 0x4) | rm;

	return lt_modrm_encoded[index];
}

__always_inline
static ubyte	parse_sib(instruction_t* const inst, const ubyte** instruction_raw)
{
	inst->sib = *((*instruction_raw)++);

	const ubyte mod = 0;// MODRM_MOD_GET(inst->mod_rm);
	const ubyte index = 0; // (IS_SINDEX_EXTENDED(*(udword*)inst->prefix & RP_REXX_MASK, inst->vexxop) << 0x3) | SIB_INDEX_GET(inst->sib);
	const ubyte base = 0; //(IS_SBASE_EXTENDED(*(udword*)inst->prefix & RP_REXB_MASK, inst->vexxop) << 0x3) | SIB_BASE_GET(inst->sib);

	/* WORD: bits: { 0, 0, 0, 0, 0, 0, MOD[1], MOD[0], INDEX[3], INDEX[2], INDEX[1], INDEX[0], BASE[3], BASE[2], BASE[1], BASE[0] }
		(INDEX[4] is extended from REX.X/VEX.~X/XOP.~X
		 BASE[4] is extended from REX.B/VEX.~B/XOP.~B) */
	const uword lt_index = ((uword)base | ((uword)index << 4) | ((uword)mod << 0x8)) & (uword)0b0000001111111111;
	return lt_sib_encoded[lt_index];
}

__always_inline
static void		parse_displacement(instruction_t* const inst, const ubyte** instruction_raw, uqword lenght)
{
	register ubyte* disp = (ubyte*)&inst->displacement;

	for (uqword i = 0 ; i < lenght ; i++)
		disp[i] = *((*instruction_raw)++);
}

#define GET_DISPLACEMENT(x) (DISP_8 & (x) ? sizeof(ubyte) : sizeof(udword))

/**
 * @brief Handle modR/M, SIB and displacement bytes
 * 
 * @param inst Where the parsed instruction is located on return.
 * @param instruction_raw A pointer to a pointer (which is modified) to the data to parse.
 */
void	handle_modrm(instruction_t* const inst, const ubyte** instruction_raw)
{
	///NOTE: I assume than there can be only 1 displacement:
	/// Either into modRM or into SIB
	/// This function won't work if both have a displacement

	ubyte sib_disp = 0;
	const ubyte modrm_disp = parse_modRM(inst, instruction_raw);
	uqword disp_lenght = 0;

	if (modrm_disp & DREF_SIB)
		sib_disp = parse_sib(inst, instruction_raw);

	if (modrm_disp & (DISP_8 | DISP_32))
		disp_lenght = GET_DISPLACEMENT(modrm_disp);
	else if (sib_disp & (SDISP_8 | SDISP_32))
		disp_lenght = GET_DISPLACEMENT(sib_disp);

	if (disp_lenght)
		parse_displacement(inst, instruction_raw, disp_lenght);
}
