
#include <dev/d_portability.h>
#include <dev/d_instruction.h>
#include <dev/d_utils.h>

#define IS_EXCEPTION_NONVEX_NONSIMD(x) ( \
	(x) == 0xC0 \
	|| (x) == 0xC1 \
	|| (x) == 0xC3 \
	|| (x) == 0xC7 \
)

#define IS_TWO_BYTE_NONVEX_SIMD(x) \
	!IS_EXCEPTION_NONVEX_NONSIMD(x) \
	&& ( \
		(GET_ROW(x) == 0x1 && GET_COLUMN(x) < 0x8) \
		|| GET_ROW(x) == 0x2 || TESTRANGE(GET_ROW(x), 0x5, 0x7) \
		|| (GET_ROW(x) == 0xC && GET_COLUMN(x) < 0x8) || GET_ROW(x) > 0xC \
)

#define IS_0x38_NONVEX_SIMD(x) (GET_ROW(x) != 0xF)
#define IS_0x3A_NONVEX_SIMD(x, fl) ( \
	!((x) == 0x0F && !((fl) & AVL_MP_0x66_MASK)) \
	&& !((x) == 0xF0 && (fl) & AVL_MP_0xF2_MASK) \
)

#define IS_NONVEX_SIMD(x) ( \
	(INST_ISPREFIXED(x) && INST_ISPREF_0F(x) && IS_TWO_BYTE_NONVEX_SIMD((x)->i_opcode[2])) \
	|| (INST_ISPREF_0F38(x) && IS_0x38_NONVEX_SIMD((x)->i_opcode[2])) \
	|| (INST_ISPREF_0F3A(x) && IS_0x3A_NONVEX_SIMD((x)->i_opcode[2], x->i_flags)) \
)

///TODO: Upgrade using defines for CALL NEAR, JMP NEAR AND RET NEAR

#define ISDFT64_CALL(x) ( \
	!INST_ISPREFIXED(x) \
	&& (x)->i_opcode[2] == 0xFF \
	&& (x)->i_mnemonic == CALL \
)
#define ISDFT64_ENTER(x) ( \
	INST_ISPREFIXED(x) \
	&& (x)->i_opcode[2] == 0xC8 \
)
#define ISDFT64_JCC(x) \
	(TESTRANGE((x)->i_mnemonic, JE, JP) \
)
#define ISDFT64_JRCXZ(x) ( \
	TESTRANGE((x)->i_mnemonic, JCXZ, JECXZ) \
)
#define ISDFT64_JMP(x) ( \
	!INST_ISPREFIXED(x) \
	&& (x)->i_opcode[2] == 0xFF \
	&& (x)->i_mnemonic == JMP \
)
#define ISDFT_LEAVE(x) ( \
	(x)->i_mnemonic == LEAVE \
)
#define ISDFT64_LGTD(x) ( \
	(x)->i_mnemonic == LGDT \
)
#define ISDFT64_LIDT(x) ( \
	(x)->i_mnemonic == LIDT \
)
#define ISDFT64_LLTD(x) ( \
	(x)->i_mnemonic == LLDT \
)
#define ISDFT64_LOOP(x) ( \
	TESTRANGE((x)->i_mnemonic, LOOP, LOOPNE) \
)
#define ISDFT64_LTR(x) ( \
	(x)->i_mnemonic == LTR \
)
#define ISDFT64_MOVCRDR(x) ( \
	INST_ISPREFIXED(x) \
	&& INST_ISPREF_0F(x) \
	&& TESTRANGE((x)->i_opcode[2], 0x20, 0x23) \
)
#define ISDFT64_POP(x) ( \
	!INST_ISPREFIXED(x) \
	&& (TESTRANGE((x)->i_opcode[2], 0x58, 0x5F) || (x)->i_opcode[2] == 0x8F) \
)
#define ISDTF64_POPF(x) ( \
	(x)->i_mnemonic == POPF \
)
#define ISDFT64_PUSH(x) ( \
	!INST_ISPREFIXED(x) \
	&& ((x)->i_opcode[2] == 0x50 || (x)->i_opcode[2] == 0x6A || (x)->i_opcode[2] == 0x68) \
)
#define ISDFT64_PUSHF(x) ( \
	(x)->i_mnemonic == PUSHF \
)
#define ISDFT64_RET(x) ( \
	INST_ISPREFIXED(x) \
	&& TESTRANGE((x)->i_opcode[2], 0xC2, 0xC3) \
	&& (x)->i_mnemonic == RET \
)
#define ISDFT64_PREFETCHW(x) ( \
	(x)->i_mnemonic == PREFETCHW \
)

__always_inline
static ubyte	is_operand_size_default_64bits(AVL_instruction_t* const inst)
{
	return ISDFT64_CALL(inst) \
/** TODO:	|| ISDFT64_ENTER(inst)*/  \
	|| ISDFT64_JCC(inst) \
	|| ISDFT64_JRCXZ(inst) \
	|| ISDFT64_JMP(inst) \
	|| ISDFT_LEAVE(inst) \
	|| ISDFT64_LGTD(inst) \
	|| ISDFT64_LIDT(inst) \
	|| ISDFT64_LLTD(inst) \
	|| ISDFT64_LOOP(inst) \
	|| ISDFT64_LTR(inst) \
	|| ISDFT64_MOVCRDR(inst) \
	|| ISDFT64_POP(inst) \
	|| ISDTF64_POPF(inst) \
	|| ISDFT64_PUSH(inst) \
	|| ISDFT64_PUSHF(inst) \
	|| ISDFT64_RET(inst) \
	|| ISDFT64_PREFETCHW(inst);
}

__always_inline
void	get_operand_size(AVL_instruction_t* const dest, opfield_t* const found, ubyte is_k_inst)
{
	ubyte opsz;

	if (AVL_HAS_OP_EVEX_PFX(dest->i_flags))
	{
		if (((AVL_evex_t*)dest->i_vp)->evx_vlen2)
			opsz = AVL_OPSZ_DQQWORD;
		else if (((AVL_evex_t*)dest->i_vp)->evx_vlen)
			opsz = AVL_OPSZ_QQWORD;
		else
			opsz = AVL_OPSZ_DQWORD;
	}
	else if (AVL_HAS_OP_VEX_PFX(dest))
	{
		if (is_k_inst)
		{
			if (dest->i_opcode[2] == 0x30 || dest->i_opcode[2] == 0x32)
				opsz = AVL_HAS_REXW_PFX(dest->i_flags) ? AVL_OPSZ_WORD : AVL_OPSZ_BYTE;
			else if (dest->i_opcode[2] == 0x31 || dest->i_opcode[2] == 0x33)
				opsz = AVL_HAS_REXW_PFX(dest->i_flags) ? AVL_OPSZ_QWORD : AVL_OPSZ_DWORD;
			else if (TESTRANGE(dest->i_opcode[2], 0x41, 0x47) || TESTRANGE(dest->i_opcode[2], 0x90, 0x99)
			|| TESTRANGE(dest->i_opcode[2], 0x4A, 0x4B)) 
			{		
				if (TESTRANGE(dest->i_opcode[2], 0x41, 0x42) || TESTRANGE(dest->i_opcode[2], 0x44, 0x47)
				|| TESTRANGE(dest->i_opcode[2], 0x90, 0x91) || TESTRANGE(dest->i_opcode[2], 0x98, 0x99)
				|| dest->i_opcode[2] == 0x4A)
				{
					
					if (AVL_HAS_REXW_PFX(dest->i_flags))
					{
						if (AVL_HAS_MP_0x66_PFX(dest->i_flags))
							opsz = AVL_OPSZ_DWORD;
						else
							opsz = AVL_OPSZ_QWORD;
					}
					else
					{
						if (dest->i_flags & AVL_MP_0x66_MASK)
							opsz = AVL_OPSZ_BYTE;
						else
							opsz = AVL_OPSZ_WORD;
					}
				}
				else if (dest->i_opcode[2] == 0x92 || dest->i_opcode[2] == 0x93)
				{
					if (AVL_HAS_MP_0xF2_PFX(dest->i_flags))
					{
						if (AVL_HAS_REXW_PFX(dest->i_flags))
							opsz = AVL_OPSZ_QWORD;
						else
							opsz = AVL_OPSZ_DWORD;
					}
					else
					{
						if (AVL_HAS_MP_0x66_PFX(dest->i_flags))
							opsz = AVL_OPSZ_BYTE;
						else
							opsz = AVL_OPSZ_WORD;
					}

					if (opsz != AVL_OPSZ_QWORD)
					{
						if (dest->i_opcode[2] == 0x92)
							found->ot2 = OT_D;
						else if (dest->i_opcode[2] == 0x93)
							found->ot1 = OT_D;
					}
				}
				else if (dest->i_opcode[2] == 0x4B)
				{
					if (AVL_HAS_REXW_PFX(dest->i_flags))
						opsz = AVL_OPSZ_QWORD;
					else if (AVL_HAS_MP_0x66_PFX(dest->i_flags))
						opsz = AVL_OPSZ_WORD;
					else
						opsz = AVL_OPSZ_DWORD;
				}
			}
			AVL_CLEAR_OPSZ(dest->i_flags);
			AVL_SET_OPSZ(dest->i_flags, opsz);
			return ;
		}
		else
		{
			const ubyte is_qqword = AVL_ISVEX3_PFX(dest) ? ((AVL_vex_t*)dest->i_vp)->vx_vlen : ((AVL_vex2_t*)dest->i_vp)->vx2_vlen;
			opsz = is_qqword ? AVL_OPSZ_QQWORD : AVL_OPSZ_DQWORD;
		}
	}
	else if (IS_NONVEX_SIMD(dest))
		opsz = AVL_OPSZ_DQWORD;
	else
	{
		/* Set to default operand size */
		if (is_operand_size_default_64bits(dest))
			opsz = AVL_OPSZ_QWORD;
		else
			opsz = AVL_OPSZ_DWORD;

		/* Overwrite with 0x66 prefix */
		if (AVL_HAS_LP_OPSZ_PFX(dest->i_flags) && !(INST_ISPREF_0F38(dest) && GET_ROW(dest->i_opcode[2]) == 0xF))
			opsz = AVL_OPSZ_WORD;
		/* Overwrite with REX.W prefix */
		else if (AVL_HAS_REXW_PFX(dest->i_flags))
			opsz = AVL_OPSZ_QWORD;

		/* Handle exceptions */
		if (!INST_ISPREFIXED(dest) && dest->i_opcode[2] == 0x8C && AVL_GET_MODRM_MOD(dest->i_mod_rm) != 0b11)
			opsz = AVL_OPSZ_WORD;
		else if (dest->i_mnemonic == CMPXCHG8B && AVL_HAS_REXW_PFX(dest->i_flags))
		{
			dest->i_mnemonic = CMPXCHG16B;
			found->ot1 = OT_DQ;
			opsz = AVL_OPSZ_DQWORD;
		}
		else if (dest->i_mnemonic == UMONITOR && !AVL_HAS_LP_ADDRSZ_PFX(dest->i_flags))
			opsz = AVL_OPSZ_QWORD;

	}

	AVL_CLEAR_OPSZ(dest->i_flags);
	AVL_SET_OPSZ(dest->i_flags, opsz);
}
