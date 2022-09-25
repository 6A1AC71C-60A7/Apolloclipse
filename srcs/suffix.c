#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

#include <user.h>

#define IS_OT_UNRANGED(x) ( \
	(x) != OT_C \
	&& (x) != OT_V \
	&& (x) != OT_Y  \
	&& (x) != (OT_Z) \
)

__always_inline
ubyte	get_modrm(AVL_instruction_t* const inst, const ubyte** iraw)
{
	if (AVL_HAS_OP_VEX_PFX(inst) || INST_ISPREFIXED(inst) || !IS_ESCAPE_FX87(inst))
		inst->i_mod_rm = *((*iraw)++);

	/* BYTE bits: { 0, 0, MOD[1], MOD[0], RM[3], RM[2], RM[1], RM[0] }
		(RM[3] is extended from REX.B / VEX.~B / EVEX.~B */
	const ubyte rm =  AVL_GET_MODRM_RM(inst);
	const ubyte index = (AVL_GET_MODRM_MOD(inst->i_mod_rm) << 0x4) | rm;

	return lt_modrm_encoded[index];
}

__always_inline
ubyte	get_sib(AVL_instruction_t* const inst, const ubyte** iraw)
{
	inst->i_sib = *((*iraw)++);

	const ubyte mod = AVL_GET_MODRM_MOD(inst->i_mod_rm);
	const ubyte index = AVL_GET_SIB_INDEX(inst);
	const ubyte base = AVL_GET_SIB_BASE(inst);

	/* WORD: bits: { 0, 0, 0, 0, 0, 0, MOD[1], MOD[0], INDEX[3], INDEX[2], INDEX[1], INDEX[0], BASE[3], BASE[2], BASE[1], BASE[0] }
		(INDEX[4] is extended from REX.X / VEX.~X / EVEX.~X
		 BASE[4] is extended from REX.B / VEX.~B / EVEX.~B) */
	const uword lt_index = ((uword)base | ((uword)index << 4) | ((uword)mod << 0x8)) & (uword)0b0000001111111111;

	return lt_sib_encoded[lt_index];
}

__always_inline
void	get_displacement(udword* const dest, const ubyte** iraw, uqword nbits)
{
	if (nbits == 0x8)
		*dest = *((*iraw)++);
	else
		*dest = *((*(udword**)iraw)++);
}

__always_inline
static ubyte	get_immediate_operand_type(opfield_t opfield)
{
	ubyte ot = 0;

	if (OPERAND_HAS_IMMEDIATE(opfield.am1))
		ot = opfield.ot1;
	else if (OPERAND_HAS_IMMEDIATE(opfield.am2))
		ot = opfield.ot2;
	else if (OPERAND_HAS_IMMEDIATE(opfield.am3))
		ot = opfield.ot3;
	else if (OPERAND_HAS_IMMEDIATE(opfield.am4))
		ot = opfield.ot4;

	return ot;
}

__always_inline
void		get_immediate(AVL_instruction_t* const dest, opfield_t opfield, const ubyte** iraw)
{
	const ubyte ot = get_immediate_operand_type(opfield);

	dest->i_flags |= AVL_OP_IMM_MASK;

	switch (ot)
	{
		case OT_B:
			dest->i_imm = *((*iraw)++);
			break ;

		case OT_W:
			dest->i_imm = *((*(uword**)iraw)++);
			break ;

		case OT_D:
			dest->i_imm = *((*(udword**)iraw)++);
			break ;

		case OT_Q:
			dest->i_imm = *((*(uqword**)iraw)++);
			break ;

		default:
		{
			if (AVL_HAS_REXW_PFX(dest->i_flags) && IS_OT_UNRANGED(ot))
				dest->i_imm = *((*(uqword**)iraw)++);
			else
			{
				switch (ot)
				{
					case OT_C:
						if ((AVL_OPSZ_IS_BYTE(dest->i_flags)) != 0)
							dest->i_imm = *((*(uword**)iraw)++);
						else
							dest->i_imm = *((*iraw)++);
						break ;

					case OT_V:
							if (AVL_OPSZ_IS_WORD(dest->i_flags))
								dest->i_imm = *((*(uword**)iraw)++);
							else if (AVL_OPSZ_IS_DWORD(dest->i_flags))
								dest->i_imm = *((*(udword**)iraw)++);
							else if (AVL_OPSZ_IS_QWORD(dest->i_flags))
								dest->i_imm = *((*(uqword**)iraw)++);
						break ;

					case OT_Y:
						if (AVL_OPSZ_IS_QWORD(dest->i_flags))
							dest->i_imm = *((*(udword**)iraw)++);
						else
							dest->i_imm = *((*(uqword**)iraw)++);
						break ;

					case OT_Z:
						if (AVL_OPSZ_IS_WORD(dest->i_flags))
							dest->i_imm = *((*(uword**)iraw)++);
						else if (!AVL_OPSZ_IS_BYTE(dest->i_flags) && !AVL_OPSZ_IS_DQWORD(dest->i_flags) && !AVL_OPSZ_IS_QQWORD(dest->i_flags))
							dest->i_imm = *((*(udword**)iraw)++);
						break ;

					default:
						dest->i_imm = *((*iraw)++);

				}
			}
		}
	}

	/* Enter is an exception and has 2 immediates values ([0:15],[16:31]) encoded */
	if (dest->i_mnemonic == ENTER)
		dest->i_imm |= (uqword)(*((*iraw)++) << 0x10);
}
