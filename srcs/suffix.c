#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

#include <user.h>

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
		|| (x) == AM_KR \
		|| (x) == AM_KRM \
		|| (x) == AM_KM \
	) \
)

__always_inline
ubyte	has_modrm(opfield_t opfield)
{
	return HAS_MODRM(opfield.am1) || HAS_MODRM(opfield.am2) || HAS_MODRM(opfield.am3) || HAS_MODRM(opfield.am4);
}

__always_inline
ubyte	get_modrm(AVL_instruction_t* const inst, const ubyte** iraw)
{
	///TODO: Redo define 'IS_ESCAPE_FX87'
	/* If is x87 instruction, the modR/M is already parsed */
	if (inst->i_vp[0] || inst->i_opcode[0] || !IS_ESCAPE_FX87(inst->i_opcode[2]))
		inst->i_mod_rm = *((*iraw)++);

	/* BYTE bits: { 0, 0, MOD[1], MOD[0], RM[3], RM[2], RM[1], RM[0] }
		(RM[3] is extended from REX.B/VEX.~B/XOP.~B */
	const ubyte rm =  AVL_GET_MODRM_RM(inst);
	const ubyte index = (AVL_GET_MODRM_MOD(inst->i_mod_rm) << 0x4) | rm;

	DEBUG("DEBUG: MODRM INDEX IS %d\n", index);

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
		(INDEX[4] is extended from REX.X/VEX.~X/XOP.~X
		 BASE[4] is extended from REX.B/VEX.~B/XOP.~B) */
	const uword lt_index = ((uword)base | ((uword)index << 4) | ((uword)mod << 0x8)) & (uword)0b0000001111111111;

	return lt_sib_encoded[lt_index];
}

__always_inline
void		get_displacement(udword* const dest, const ubyte** iraw, uqword nbits)
{
	DEBUG("GET DISPLACEMENT OF %lld BITS\n", (long long int)nbits);

	if (nbits == 0x8)
		*dest = *((*iraw)++);
	else
		*dest = *((*(udword**)iraw)++);
}




__always_inline
ubyte	has_immediate(opfield_t opfield)
{
	return HAS_IMMEDIATE(opfield.am1) || HAS_IMMEDIATE(opfield.am2) || HAS_IMMEDIATE(opfield.am3) || HAS_IMMEDIATE(opfield.am4);
}

#define IS_OT_UNRANGED(x) ((x) != OT_C && (x) != OT_V && (x) != OT_Y  && (x) != (OT_Z))

__always_inline
static ubyte	get_immediate_operand_type(opfield_t opfield)
{
	ubyte ot = 0;

	if (HAS_IMMEDIATE(opfield.am1))
		ot = opfield.ot1;
	else if (HAS_IMMEDIATE(opfield.am2))
		ot = opfield.ot2;
	else if (HAS_IMMEDIATE(opfield.am3))
		ot = opfield.ot3;
	else if (HAS_IMMEDIATE(opfield.am4))
		ot = opfield.ot4;

	return ot;
}

__always_inline
void		get_immediate(opfield_t opfield, AVL_instruction_t* const dest, const ubyte** iraw)
{
	const ubyte ot = get_immediate_operand_type(opfield);

	///TODO: Not 100% sure but i think if is AM_L the immediate value is always 8-bits.

	dest->i_flags |= AVL_OP_IMM_MASK;

	DEBUG("[DEBUG][OT OF IMMEDIATE]: %d (**iraw='%X')\n", ot, **iraw);

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
						//else if ((dest->i_flags & (OS_BYTE_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK)) == 0)
						else if (!AVL_OPSZ_IS_BYTE(dest->i_flags) && !AVL_OPSZ_IS_DQWORD(dest->i_flags) && !AVL_OPSZ_IS_QQWORD(dest->i_flags))
							dest->i_imm = *((*(udword**)iraw)++);
						break ;
					default:
						dest->i_imm = *((*iraw)++);

				}
			}
		}
	}

	if (dest->i_mnemonic == ENTER)
		dest->i_imm |= (*((*iraw)++) << 0x10);

	DEBUG("IMMEDIATE IS: %lX\n", dest->i_imm);
}
