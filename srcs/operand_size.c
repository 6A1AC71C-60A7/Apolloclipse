#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

#include <user.h>

#define IS_EXCEPTION_NONVEX_NONSIMD(x) ((x) == 0xC0 || (x) == 0xC1 || (x) == 0xC3 || (x) == 0xC7)
#define GET_ROW(x) (((x) >> 0x4) & 0xF)
#define GET_COLUMN(x) ((x) & 0xF)
#define IS_TWO_BYTE_NONVEX_SIMD_V2(x) !IS_EXCEPTION_NONVEX_NONSIMD(x) && ((GET_ROW(x) == 0x1 && GET_COLUMN(x) < 0x8) || GET_ROW(x) == 0x2 || (GET_ROW(x) >= 0x5 && GET_ROW(x) <= 0x7) || (GET_ROW(x) == 0xC && GET_COLUMN(x) < 0x8) || GET_ROW(x) > 0xC)

#define IS_0x38_NONVEX_SIMD(x) (/*!(GET_ROW(x) == 0x8 && GET_COLUMN(x) <= 0x8) && */ GET_ROW(x) != 0xF)
#define IS_0x3A_NONVEX_SIMD(x, p) (!((x) == 0x0F && !((p) & AVL_MP_0x66_MASK)) && !((x) == 0xF0 && (p) & AVL_MP_0xF2_MASK))



#define ISDFT64_CALL(x) (!(x)->i_opcode[0] && (x)->i_opcode[2] == 0xFF && (x)->i_mnemonic == CALL)
#define ISDFT64_JMP(x) (!(x)->i_opcode[0] && (x)->i_opcode[2] == 0xFF && (x)->i_mnemonic == JMP)
#define ISDFT64_LGTD(x) ((x)->i_mnemonic == LGDT)
#define ISDFT64_LIDT(x) ((x)->i_mnemonic == LIDT)
#define ISDFT64_LLTD(x) ((x)->i_mnemonic == LLDT)
#define ISDFT64_POP(x) (!(x)->i_opcode[0] && (((x)->i_opcode[2] >= 0x58 && (x)->i_opcode[2] <= 0x5F) || (x)->i_opcode[2] == 0x8F))
#define ISDFT64_PUSH(x) ((!(x)->i_opcode[0] && ((x)->i_opcode[2] == 0x50 || (x)->i_opcode[2] == 0x6A || (x)->i_opcode[2] == 0x68)))
#define ISDFT64_PREFETCHW(x) ((x)->i_mnemonic == PREFETCHW)
#define ISDFT64_MOVCRDR(x) ((x)->i_opcode[0] && !(x)->i_opcode[1] && (x)->i_opcode[2] >= 0x20 && (x)->i_opcode[2] <= 0x23)

static ubyte	is_mnemonic_default_64_bits(AVL_instruction_t* const inst)
{

	///TODO: Only CALL near JMP near and RET near ?!?!
	///TODO: Mnemonic must have specific operands to be in this list ?
	///TODO: Jcc, jrCXZ, LOOPcc, MOVcr, MOVdr, 

	///TODO: SELECT BY OPCODE
	return ISDFT64_CALL(inst) || ISDFT64_JMP(inst) || ISDFT64_LGTD(inst) || ISDFT64_LIDT(inst) || ISDFT64_LLTD(inst) || ISDFT64_POP(inst) || ISDFT64_PUSH(inst) || ISDFT64_PREFETCHW(inst) || ISDFT64_MOVCRDR(inst); /* mnemonic == CALL || mnemonic == ENTER || mnemonic == JMP || mnemonic == LEAVE
	|| mnemonic == LGDT || mnemonic == LIDT || mnemonic == LLDT || mnemonic == LOOP
	|| mnemonic == LTR || mnemonic == POP || mnemonic == POPF || mnemonic == PUSH
	|| mnemonic == PUSHF || mnemonic == RET; */
}

__always_inline
void		get_operand_size(AVL_instruction_t* const dest, opfield_t* const found)
{
	(void)found;

	///TODO: REDO THIS WITHOUT TRIPLE RETURN 
	if (AVL_HAS_OP_EVEX_PFX(dest->i_flags))
	{
		if (((AVL_evex_t*)dest->i_vp)->evx_vlen2)
		{
			AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DQQWORD);
		}
		else if (((AVL_evex_t*)dest->i_vp)->evx_vlen)
		{
			AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_QQWORD);
		}
		else
		{
			AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DQWORD);
		}
		return ;
	}
	else if (dest->i_vp[0])
	{
		const ubyte is256os = dest->i_vp[2] ? ((AVL_vex_t*)dest->i_vp)->vx_vlen : ((AVL_vex2_t*)dest->i_vp)->vx2_vlen;
		//dest->i_flags |= is256os ? OS_QQWORD_MASK : OS_DQWORD_MASK;
		AVL_SET_OPSZ(dest->i_flags, is256os ? AVL_OPSZ_QQWORD : AVL_OPSZ_DQWORD);
		return ;

		///TODO: if (IS_K*()) { handle k mnemonics operand size }
		/// SIZE RESOLUTION FOR THESE MUST BE PERFORMED OTHERWAY

		///TODO: SOME VEX TAKE GP REGISTERS AS ARGUMENTS,

		///TODO: For the future: if is EVEX the size also could be 512bits
	}
	else if ((dest->i_opcode[0] && !dest->i_opcode[1] && 
		/* IS_TWO_BYTE_NONVEX_SIMD((dest->opcode[2] >> 4) & 0xF)) */
		IS_TWO_BYTE_NONVEX_SIMD_V2(dest->i_opcode[2]))
		 || 
		 /*(dest->opcode[1] == 0x38 && ((((dest->opcode[2] >> 4) & 0xF) == 0x8 && (dest->opcode[2] & 0xF) >= 0x8) || ((dest->opcode[2] >> 4) & 0xF) < 0xF )) */
		(dest->i_opcode[1] == 0x38 && IS_0x38_NONVEX_SIMD(dest->i_opcode[2]))
		|| (dest->i_opcode[1] == 0x3A && IS_0x3A_NONVEX_SIMD(dest->i_opcode[2], dest->i_flags)))
	{
		DEBUG("[DEBUG] COND1: %d COND2: %d\n", (dest->i_opcode[0] && !dest->i_opcode[1]
			 && /* IS_TWO_BYTE_NONVEX_SIMD((dest->opcode[2] >> 4) & 0xF)) */
			IS_TWO_BYTE_NONVEX_SIMD_V2(dest->i_opcode[2]))
			, (dest->i_opcode[1] == 0x38 && IS_0x38_NONVEX_SIMD(dest->i_opcode[2])));

		//dest->i_flags |= OS_DQWORD_MASK;
		AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DQWORD);

		// if (dest->vexxop[0] == 0)
		// {
		// 	if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_64(dest->mnemonic))
		// 	{
		// 		OS_RESET(*(udword*)dest->prefix);
		// 		*(udword*)dest->prefix |= OS_QWORD_MASK;
		// 	}
		// 	else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_32(dest->mnemonic))
		// 	{
		// 		OS_RESET(*(udword*)dest->prefix);
		// 		*(udword*)dest->prefix |= OS_DWORD_MASK;
		// 	}
		// 	else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_16(dest->mnemonic))
		// 	{
		// 		OS_RESET(*(udword*)dest->prefix);
		// 		*(udword*)dest->prefix |= OS_WORD_MASK;
		// 	}
		// 	else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_8(dest->mnemonic))
		// 	{
		// 		OS_RESET(*(udword*)dest->prefix);
		// 		*(udword*)dest->prefix |= OS_BYTE_MASK;
		// 	}
		// 	else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_3264(dest->mnemonic))
		// 	{
		// 		OS_RESET(*(udword*)dest->prefix);
		// 		*(udword*)dest->prefix |= *(udword*)dest->prefix & AVL_RP_REXW_MASK ? OS_QWORD_MASK : OS_DWORD_MASK;
		// 	}
		// }
		// else
		// {
		// 	if (0 /* 64 bit exception */)
		// 		*(udword*)dest->prefix |= OS_QWORD_MASK;
		// 	else if (0 /* 32 bit exception */)
		// 		*(udword*)dest->prefix |= OS_DWORD_MASK;
		// 	else if (0 /* 16 bit exception */)
		// 		*(udword*)dest->prefix |= OS_WORD_MASK;
		// 	else if (0 /* 32 - 64 exception */)
		// 		*(udword*)dest->prefix |= *(udword*)dest->prefix & AVL_RP_REXW_MASK ? OS_QWORD_MASK : OS_DWORD_MASK;
		// }

		return ;
	}

	/* Operand size of first operand dictates the operand size of
		the whole instruction */

	//ubyte isreg = 0x0;

	/* Set to default operand size */

	if (is_mnemonic_default_64_bits(dest))
	{
		//dest->i_flags |= OS_QWORD_MASK;
		AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_QWORD);
	}
		
	// else if (IS_DEFAULT_REGISTER(found.am1))
	// {
	// 	isreg = 0x1;
	// 	if (found.ot1 == DRS_8 || found.ot1 == OR_8)
	// 		*prefix |= OS_BYTE_MASK;
	// 	else if (found.ot1 == DRS_16 || found.ot1 == OR_16)
	// 		*prefix |= OS_WORD_MASK;
	// 	///TODO: SEEMS NEXT ONE NEVER HAPPENS
	// 	else if (found.ot1 == DRS_128 || found.ot1 == OR_128)
	// 		*prefix |= OS_DQWORD_MASK;
	// 	///TODO: SEEMS NEXT ONE NEVER HAPPENS
	// 	else if (found.ot1 == DRS_256 || found.ot1 == OR_256)
	// 		*prefix |= OS_QQWORD_MASK;
	// 	else
	// 		*prefix |= OS_DWORD_MASK;
	// }
	else
	{
		//dest->i_flags |= OS_DWORD_MASK;
		AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DWORD);
	}

	/* Overwrite with prefixes */

	// if (*prefix & OS_DWORD_MASK)
	// {
		if (dest->i_flags & AVL_MP_0x66_MASK && !(dest->i_opcode[1] == 0x38 && ((dest->i_opcode[2] >> 4) & 0xF) == 0xF))
		{
			// OS_RESET(dest->i_flags);
			// dest->i_flags |= OS_WORD_MASK;
			AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_WORD);
		}
		else if (AVL_HAS_REXW_PFX(dest->i_flags))
		{
			// OS_RESET(dest->i_flags);
			// dest->i_flags |= OS_QWORD_MASK;
			AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_QWORD);
		// }
	}

	// if (isreg == 0x0)
	// {
	// 	switch (found.ot1)
	// 	{
	// 		case OT_B:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_BYTE_MASK;
	// 			break ;

	// 		case OT_W:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_WORD_MASK;
	// 			break ;

	// 		case OT_D:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_DWORD_MASK;
	// 			break ;

	// 		case OT_Q:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_QWORD_MASK;
	// 			break ;
	// 	}
	// }

	/* Exception in which the operand size must be WORD but
		is DWORD when the documentation is followed ... 
		OPERATION: mov WORD [], segment_register
		[ ONLY WHEN IS ADDRESSING ] */
	if (!dest->i_opcode[0] && dest->i_opcode[2] == 0x8C && (dest->i_mod_rm & 0b11000000) != 0b11000000)
	{
		// OS_RESET(dest->i_flags);
		// dest->i_flags |= OS_WORD_MASK;
		AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_WORD);
	}
	/* More exceptions ... */
	else if (dest->i_mnemonic == CMPXCHG8B && AVL_HAS_REXW_PFX(dest->i_flags))
	{
		dest->i_mnemonic = CMPXCHG16B;
		// OS_RESET(dest->i_flags);
		// dest->i_flags |= OS_DQWORD_MASK;
		AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_DQWORD);
		found->ot1 = OT_DQ;
	}
	else if (dest->i_mnemonic == UMONITOR && !AVL_HAS_LP_ADDRSZ_PFX(dest->i_flags))
	{
		// OS_RESET(dest->i_flags);
		// dest->i_flags |= OS_QWORD_MASK;
		AVL_SET_OPSZ(dest->i_flags, AVL_OPSZ_QWORD);
	}

	const char* __size;
	if (AVL_OPSZ_IS_BYTE(dest->i_flags))
		__size = "BYTE";
	else if (AVL_OPSZ_IS_WORD(dest->i_flags))
		__size = "WORD";
	else if (AVL_OPSZ_IS_DWORD(dest->i_flags))
		__size = "DWORD";
	else if (AVL_OPSZ_IS_QWORD(dest->i_flags))
		__size = "QWORD";
	else if (AVL_OPSZ_IS_DQWORD(dest->i_flags))
		__size = "DQWORD";
	DEBUG("---------> Operand size is %s\n", __size);
}
