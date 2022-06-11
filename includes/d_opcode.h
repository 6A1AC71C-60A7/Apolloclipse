
#pragma once

#include <d_types.h>

typedef enum
{
	AM_ZERO,	// RESERVED.
	AM_A,		// Direct address: the instruction has no ModR/M byte; the address of the operand is encoded in the instruction.
				//			No base register, index register, or scaling factor can be applied (for example, far JMP (EA)).
	AM_B,		// The VEX.vvvv field of the VEX prefix selects a general purpose register.
	AM_C,		// The reg field of the ModR/M byte selects a control register (for example, MOV (0F20, 0F22)).
	AM_D,		// The reg field of the ModR/M byte selects a debug register (for example, MOV (0F21,0F23)).
	AM_E,		// A ModR/M byte follows the opcode and specifies the operand. The operand is either a general-purpose
				//			register or a memory address. If it is a memory address, the address is computed from a segment register
				//			and any of the following values: a base register, an index register, a scaling factor, a displacement.
	AM_F,		// EFLAGS/RFLAGS Register.
	AM_G,		// The reg field of the ModR/M byte selects a general register (for example, AX (000)).
	AM_H,		// The VEX.vvvv field of the VEX prefix selects a 128-bit XMM register or a 256-bit YMM register, determined
				//			by operand type. For legacy SSE encodings this operand does not exist, changing the instruction to destructive form.
	AM_I,		// Immediate data: the operand value is encoded in subsequent bytes of the instruction.
	AM_J,		// The instruction contains a relative offset to be added to the instruction pointer register (for example, JMP (0E9), LOOP).
	AM_L,		// The upper 4 bits of the 8-bit immediate selects a 128-bit XMM register or a 256-bit YMM register, determined
				//			by operand type. (the MSB is ignored in 32-bit mode)
	AM_M,		// The ModR/M byte may refer only to memory (for example, BOUND, LES, LDS, LSS, LFS, LGS, CMPXCHG8B).
	AM_N,		// The R/M field of the ModR/M byte selects a packed-quadword, MMX technology register.
	AM_O,		// The instruction has no ModR/M byte. The offset of the operand is coded as a word or double word
				//			(depending on address size attribute) in the instruction. No base register, index register, or scaling factor
				//			can be applied (for example, MOV (A0–A3)).
	AM_P,		// The reg field of the ModR/M byte selects a packed quadword MMX technology register.
	AM_Q,		// A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology
				//			register or a memory address. If it is a memory address, the address is computed from a segment register
				//			and any of the following values: a base register, an index register, a scaling factor, and a displacement.
	AM_R,		// The R/M field of the ModR/M byte may refer only to a general register (for example, MOV (0F20-0F23)).
	AM_S,		// The reg field of the ModR/M byte selects a segment register (for example, MOV (8C,8E)).
	AM_U,		// The R/M field of the ModR/M byte selects a 128-bit XMM register or a 256-bit YMM register, determined by operand type.
	AM_V,		// The reg field of the ModR/M byte selects a 128-bit XMM register or a 256-bit YMM register, determined by operand type.
	AM_W,		// A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register,
				//			a 256-bit YMM register (determined by operand type), or a memory address. If it is a memory address, the
				//			address is computed from a segment register and any of the following values: a base register, an index
				//			register, a scaling factor, and a displacement.
	AM_X,		// Memory addressed by the DS:rSI register pair (for example, MOVS, CMPS, OUTS, or LODS).
	AM_Y,		// Memory addressed by the ES:rDI register pair (for example, MOVS, CMPS, INS, STOS, or SCAS).
	AMB			// The opcode held by this field is prefix-dependent. The mnemonic field holds the index to another
				// 			look up table in which the prefix resolution should be performed.

} op_addressing_method_t;

typedef enum
{
	OT_ZERO,	// RESERVED.
	OT_A,		// Two one-word operands in memory or two double-word operands in memory, depending on operand-size
				//			attribute (used only by the BOUND instruction).
	OT_B,		// Byte, regardless of operand-size attribute.
	OT_C,		// Byte or word, depending on operand-size attribute.
	OT_D,		// Doubleword, regardless of operand-size attribute.
	OT_DQ,		// Double-quadword, regardless of operand-size attribute.
	OT_P,		// 32-bit, 48-bit, or 80-bit pointer, depending on operand-size attribute.
	OT_PD,		// 128-bit or 256-bit packed double-precision floating-point data.
	OT_PI,		// Quadword MMX technology register (for example: mm0).
	OT_PS,		// 128-bit or 256-bit packed single-precision floating-point data.
	OT_Q,		// Quadword, regardless of operand-size attribute.
	OT_QQ,		// Quad-Quadword (256-bits), regardless of operand-size attribute.
	OT_S,		// 6-byte or 10-byte pseudo-descriptor.
	OT_SD,		// Scalar element of a 128-bit double-precision floating data.
	OT_SS,		// Scalar element of a 128-bit single-precision floating data.
	OT_SI,		// Doubleword integer register (for example: eax).
	OT_V,		// Word, doubleword or quadword (in 64-bit mode), depending on operand-size attribute.
	OT_W,		// Word, regardless of operand-size attribute.
	OT_X,		// dq or qq based on the operand-size attribute.
	OT_Y,		// Doubleword or quadword (in 64-bit mode), depending on operand-size attribute.
	OT_Z,		// Word for 16-bit operand-size or doubleword for 32 or 64-bit operand-size.

	OT_EXT,		// Reference to a 80-bit Double-Extented floating point data.
	OT_BCD,		// Reference to a 4-bit packed-BCD data.
	
} op_operand_type_t;

typedef enum
{
	// from 32 to max 63, if not enought use ot and extend the lenght

	DR_RAX = 32,// Use otX field bits of RAX register.
	DR_RCX,		// Use the otX field bytes of RCX register.
	DR_RDX,		// Use the otX field bytes of RDX register.
	DR_RBX,		// Use the otX field bytes of RBX register.
	DR_RSP,		// Use the otX field bytes of RSP register.
	DR_RBP,		// Use the otX field bytes of RBP register.
	DR_RSI,		// Use the otX field bytes of RSI register.
	DR_RDI,		// Use the otX field bytes of RDI register.
	DR_R8,		// Use the otX field bytes of R8 register.
	DR_R9,		// Use the otX field bytes of R9 register.
	DR_R10,		// Use the otX field bytes of R10 register.
	DR_R11,		// Use the otX field bytes of R11 register.
	DR_R12,		// Use the otX field bytes of R12 register.
	DR_R13,		// Use the otX field bytes of R13 register.
	DR_R14,		// Use the otX field bytes of R14 register.
	DR_R15,		// Use the otX field bytes of R15 register.
	DR_AH,		// Force use AH bytes of RAX register.
	DR_CH,		// Force use CH bytes of RCX register.
	DR_DH,		// Force use DH bytes of RDX register.
	DR_BH,		// Force use BH bytes of RBX register.

} op_default_reg_t;

/* Some Alias of op_default_reg_t members */

#define DR_ST0 DR_RAX
#define DR_ST1 DR_RCX
#define DR_ST2 DR_RDX
#define DR_ST3 DR_RBX
#define DR_ST4 DR_RSP
#define DR_ST5 DR_RBP
#define DR_ST6 DR_RSI
#define DR_ST7 DR_RDI
#define DR_MMX0 DR_RAX
#define DR_MMX1 DR_RCX
#define DR_MMX2 DR_RDX
#define DR_MMX3 DR_RBX
#define DR_MMX4 DR_RSP
#define DR_MMX5 DR_RBP
#define DR_MMX6 DR_RSI
#define DR_MMX7 DR_RDI
#define DR_MMX0d DR_R8
#define DR_MMX1d DR_R9
#define DR_MM12d DR_R10
#define DR_MMX3d DR_R11
#define DR_MMX4d DR_R12
#define DR_MMX5d DR_R13
#define DR_MMX6d DR_R14
#define DR_MMX7d DR_R15
#define DR_XMM0 DR_RAX
#define DR_XMM1 DR_RCX
#define DR_XMM2 DR_RDX
#define DR_XMM3 DR_RBX
#define DR_XMM4 DR_RSP
#define DR_XMM5 DR_RBP
#define DR_XMM6 DR_RSI
#define DR_XMM7 DR_RDI
#define DR_XMM8 DR_R8
#define DR_XMM9 DR_R9
#define DR_XMM10 DR_R10
#define DR_XMM11 DR_R11
#define DR_XMM12 DR_R12
#define DR_XMM13 DR_R13
#define DR_XMM14 DR_R14
#define DR_XMM15 DR_R15
#define DR_YMM0 DR_RAX
#define DR_YMM1 DR_RCX
#define DR_YMM2 DR_RDX
#define DR_YMM3 DR_RBX
#define DR_YMM4 DR_RSP
#define DR_YMM5 DR_RBP
#define DR_YMM6 DR_RSI
#define DR_YMM7 DR_RDI
#define DR_YMM8 DR_R8
#define DR_YMM9 DR_R9
#define DR_YMM10 DR_R10
#define DR_YMM11 DR_R11
#define DR_YMM12 DR_R12
#define DR_YMM13 DR_R13
#define DR_YMM14 DR_R14
#define DR_YMM15 DR_R15
#define DR_ES DR_RAX
#define DR_CS DR_RCX
#define DR_SS DR_RDX
#define DR_DS DR_RBX
#define DR_FS DR_RSP
#define DR_GS DR_RBP
#define DR_ESd DR_R8
#define DR_CSd DR_R9
#define DR_SSd DR_R10
#define DR_DSd DR_R11
#define DR_FDd DR_R12
#define DR_GSd DR_R13
#define DR_CRO DR_RAX
#define DR_CR1 DR_RCX
#define DR_CR2 DR_RDX
#define DR_CR3 DR_RBX
#define DR_CR4 DR_RSP
#define DR_CR5 DR_RBP
#define DR_CR6 DR_RSI
#define DR_CR7 DR_RDI
#define DR_CR8 DR_R8
#define DR_CR9 DR_R9
#define DR_CR10 DR_R10
#define DR_CR11 DR_R11
#define DR_CR12 DR_R12
#define DR_CR13 DR_R13
#define DR_CR14 DR_R14
#define DR_CR15 DR_R15
#define DR_DR0 DR_RAX
#define DR_DR1 DR_RCX
#define DR_DR2 DR_RDX
#define DR_DR3 DR_RBX
#define DR_DR4 DR_RSP
#define DR_DR5 DR_RBP
#define DR_DR6 DR_RSI
#define DR_DR7 DR_RDI
#define DR_DR8 DR_R8
#define DR_DR9 DR_R9
#define DR_DR10 DR_R10
#define DR_DR11 DR_R11
#define DR_DR12 DR_R12
#define DR_DR13 DR_R13
#define DR_DR14 DR_R14
#define DR_DR15 DR_R15

typedef enum
{
	DRS_8,		
	DRS_16,		// Only 16-bits of the selected register can be used.
	DRS_32,		// Only 32-bits of the selected register can be used.
	DRS_64,		// Only 64-bits of the selected register can be used.
	DRS_128,	// Only 128-bits of the selected register can be used.
	DRS_256,	// Only 256-bits of the selected register can be used.
	DRS_512,	// Only 512-bits of the selected register can be used.
	OR_8,		// Optional 8-bits register next option register is on next amX field.
	OR_16,		// Optional 8-bits register next option register is on next amX field.
	OR_32,		// Optional 8-bits register next option register is on next amX field.
	OR_64,		// Optional 8-bits register next option register is on next amX field.
	OR_128,		// Optional 8-bits register next option register is on next amX field.
	OR_256,		// Optional 8-bits register next option register is on next amX field.
	OR_512,		// Optional 8-bits register next option register is on next amX field.
	DRS_SEC,	// A section register.
	DRS_87		// A floating point register.

} op_default_regsz_t;

typedef enum
{
	S_1A,		// Bits 5, 4, and 3 of ModR/M byte used as an opcode extension.
	S_1B,		// Use the 0F0B opcode (UD2 instruction), the 0FB9H opcode (UD1 instruction), or the 0FFFH opcode (UD0 instruction) when deliberately trying to generate an invalid opcode exception (#UD).
	S_1C,		// Some instructions use the same two-byte opcode. If the instruction has variations, or the opcode represents
				//		different instructions, the ModR/M byte will be used to differentiate the instruction.
	S_I64,		// The instruction is invalid or not encodable in 64-bit mode. 40 through 4F (single-byte INC and DEC) are REX prefix
				//		combinations when in 64-bit mode (use FE/FF Grp 4 and 5 for INC and DEC).
	S_O64,		// Instruction is only available when in 64-bit mode.
	S_D64,		// When in 64-bit mode, instruction defaults to 64-bit operand size and cannot encode 32-bit operand size.
	S_F64,		// The operand size is forced to a 64-bit operand size when in 64-bit mode (prefixes that change operand size are ignored for this instruction in 64-bit mode).
	S_V,		// VEX form only exists. There is no legacy SSE form of the instruction. For Integer GPR instructions it means VEX prefix required.
	S_V1		// VEX128 & SSE forms only exist (no VEX256), when can’t be inferred from the data size.

} op_symbol_t;

typedef struct
{
	uqword mnemonic:11;
	uqword am1:6;
	uqword ot1:6;
	uqword am2:6;
	uqword ot2:6;
	uqword am3:6;
	uqword ot3:6;
	uqword am4:6;
	uqword ot4:6;
	uqword symbol:4;
	uqword zero:1;
} opfield_t;
