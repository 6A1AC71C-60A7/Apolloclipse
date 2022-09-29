
#pragma once

#include <dev/d_error.h>
#include <dev/d_lookup_tables.h>
#include <AVL_disassembler.h>

#define OPERAND_HAS_IMMEDIATE(am) ( \
	(am) != 0 && (am) >= AM_I && (am) <= AM_L \
)

#define OPFIELD_HAS_IMMEDIATE(opfield) ( \
	OPERAND_HAS_IMMEDIATE(opfield.am1) \
	|| OPERAND_HAS_IMMEDIATE(opfield.am2) \
	|| OPERAND_HAS_IMMEDIATE(opfield.am3) \
	|| OPERAND_HAS_IMMEDIATE(opfield.am4) \
)

#define IS_ESCAPE_FX87(x) ( \
	!AVL_HAS_OP_VEX_PFX(x) \
	&& !INST_ISPREFIXED(x) \
	&& TESTRANGE((x)->i_opcode[2], 0xD8, 0xDF) \
)

#define GET_MAP_INDEX(x) (((x) & 0x0F) + ((((x) & 0xF0) >> 0x4) * 0x10))

#define OPFIELD_HAS_MODRM(x) ( \
	(x) != AM_ZERO && ( \
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
		|| (x) == AM_KR \
		|| (x) == AM_KRM \
		|| (x) == AM_KM \
	) \
)

#define INST_HAS_MODRM(x) ( \
	OPFIELD_HAS_MODRM(x.am1) \
	|| OPFIELD_HAS_MODRM(x.am2) \
	|| OPFIELD_HAS_MODRM(x.am3) \
	|| OPFIELD_HAS_MODRM(x.am4) \
)

/*
** Instruction resolution
*/

opfield_t		get_instruction_by_extension_one_and_two_b_opmap(ubyte group, opfield_t found, ubyte modrm, udword prefix);
extern void		resolve_operands(AVL_instruction_t* const dest, opfield_t instruction);

/*
** Prefix parse
*/

extern void		get_legacy_prefixes(udword* const dest, const ubyte** iraw);
extern err_t	err_handle_legacy_prefixes(const udword* const dest);
extern void		get_vex_prefixes(AVL_instruction_t* const inst, const ubyte** iraw);
extern void		get_rex_prefix(udword* const dest, const ubyte** iraw);
extern void		get_evex_prefixes(AVL_instruction_t* const inst, const ubyte** iraw);

/*
** Suffix parse
*/

extern ubyte	get_modrm(AVL_instruction_t* const inst, const ubyte** iraw);
extern ubyte	get_sib(AVL_instruction_t* const inst, const ubyte** iraw);
extern void		get_displacement(udword* const dest, const ubyte** iraw, uqword nbits);
extern void		get_immediate(AVL_instruction_t* const dest, opfield_t opfield, const ubyte** iraw);
extern void		get_operand_size(AVL_instruction_t* const dest, opfield_t* const found, ubyte is_k_inst);
