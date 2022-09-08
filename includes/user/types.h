
#pragma once

#include "./prefix.h"

#include <stdint.h>

typedef uint8_t		__AVL_SET_PREF(reg_t);

///TODO: Replce by the good one
typedef enum TMP_MNEMONIC
{
	MEMBER,
} __AVL_SET_PREF(TMP_MNEMONIC_t);

/// Vector EXtension (VEX) 3-bytes prefix.
typedef struct
{
	union
	{
		struct
		{
			uint8_t	__AVL_SET_VEX3_PREF(header);		// Mandatory VEX 3-bytes prefix, always 0xC4.
			uint8_t	__AVL_SET_VEX3_PREF(opmap):5;		// Opcode Map Prefix(es).
			uint8_t __AVL_SET_VEX3_PREF(rexb):1;		// VEX REX.B bit.
			uint8_t __AVL_SET_VEX3_PREF(rexx):1;		// VEX REX.X bit.
			uint8_t __AVL_SET_VEX3_PREF(rexr):1;		// VEX REX.R bit.
			uint8_t __AVL_SET_VEX3_PREF(prefix):2;		// Instruction prefix.
			uint8_t __AVL_SET_VEX3_PREF(vlen):1;		// Vector Operand Size, either 128-bits or 256-bits.
			uint8_t __AVL_SET_VEX3_PREF(vvvv):4;		// Addtional Instruction Argument.
			uint8_t __AVL_SET_VEX3_PREF(rexw):1;		// VEX REX.W bit.
		};
		uint8_t __AVL_SET_VEX3_PREF(rawdat)[3];
	};

} __AVL_SET_PREF(vex_t);

/// Vextor EXtension (VEX) 2-bytes prefix.
typedef struct
{
	union
	{
		struct
		{
			uint8_t	__AVL_SET_VEX2_PREF(header);		// Mandatory VEX 2-bytes prefix, always 0xC5.
			uint8_t	__AVL_SET_VEX2_PREF(prefix):2;		// Instruction prefix.
			uint8_t	__AVL_SET_VEX2_PREF(vlen):1;		// Vector Operand Size, either 128-bits or 256-bits.
			uint8_t	__AVL_SET_VEX2_PREF(vvvv):4;		// Addtional Instruction Argument.
			uint8_t	__AVL_SET_VEX2_PREF(rexr):1;		// VEX REX.R bit.
		};
		uint8_t __AVL_SET_VEX2_PREF(rawdat)[3];
	};
} __AVL_SET_PREF(vex2_t);

/// Enhanced Vector EXtension (EVEX) prefix.
typedef struct
{
	union
	{
		struct
		{
			uint8_t	__AVL_SET_EVEX_PREF(opmap):2;		// Opcode Map Prefix(es).
			uint8_t __AVL_SET_EVEX_RSVPREF(ZeRo):2;		// Reserved, always 0b00.
			uint8_t	__AVL_SET_EVEX_PREF(rexr2):1;		// Extends EVEX REX.X extensions.
			uint8_t	__AVL_SET_EVEX_PREF(rexb):1;		// EVEX REX.B bit.
			uint8_t	__AVL_SET_EVEX_PREF(rexx):1;		// EVEX REX.X bit.
			uint8_t	__AVL_SET_EVEX_PREF(rexr):1;		// EVEX REX.R bit.
			uint8_t	__AVL_SET_EVEX_PREF(prefix):2;		// Instruction prefix.
			uint8_t	__AVL_SET_EVEX_RSVPREF(OnE):1;		// Reserved, always 0b1.
			uint8_t	__AVL_SET_EVEX_PREF(vvvv):4;		// Addtional Instruction Argument.
			uint8_t	__AVL_SET_EVEX_PREF(rexw):1;		// EVEX REX.W bit.
			uint8_t	__AVL_SET_EVEX_PREF(mask):3;		// Operand Mask Register.
			uint8_t	__AVL_SET_EVEX_PREF(v):1;			// Expands EVEX.VVVV.
			uint8_t	__AVL_SET_EVEX_PREF(brcst):1;		// Source Broadcast, Rounding Control or Supress Exceptions.
			uint8_t	__AVL_SET_EVEX_PREF(vlen):1;		// If == 1, operand size is 256-bits, else 128-bits.
			uint8_t	__AVL_SET_EVEX_PREF(vlen2):1;		// If == 1, operand size is 512-bits (overwrite EVEX.L (__AVL_SET_EVEX_PREF(vlen)).
			uint8_t	__AVL_SET_EVEX_PREF(zero):1;		// Specify merging mode (merge or zero).
		};
		uint8_t __AVL_SET_EVEX_PREF(rawdat)[3];
	};
} __AVL_SET_PREF(evex_t);


typedef struct
{
	uint32_t __AVL_SET_INST_PREF(flags);		/* Bitwise flags representing:
													- Legacy Prefixes
													- REX prefix
													- Instruction prefix (66h, 67h, F2h, F3h)
													- Operand size
													- Precence of Immediate
													- Presence of EVEX prefix */

	AVL_TMP_MNEMONIC_t	__AVL_SET_INST_PREF(mnemonic);	/* Represents the mnemonic of the instruction,
													the mnemomic values are sorted by procesor extension */

	uint8_t	 __AVL_SET_INST_PREF(opcode[3]);	/* Represents the opcode (map + index), the first byte
													can only be 0Fh or 0h, the second byte can be
													either 38h, 3Ah or 0h.
													[00h][00h][INDEX] -> One byte opcode map
													[0Fh][00h][INDEX] -> Two bytes opcode map
													[0Fh][38h][INDEX] -> Three bytes opcode map 38h
													[0Fh][3Ah][INDEX] -> Three bytes opcode map 3Ah
													If the 2 first bytes are zeroed, the instruction doesn't
													have a (E)VEX prefix and the index is in range {D8h, DFh},
													then the opcode map is x87 (FPU). */

	uint8_t	 __AVL_SET_INST_PREF(vp[3]);		/* A copy of either the 2-bytes VEX prefix, the 3-bytes VEX prefix
													or the EVEX prefix. For the EVEX prefix (which size is 4-bytes)
													the first byte is stripped and bit in the flags is set. */

	uint8_t	 __AVL_SET_INST_PREF(mod_rm);		/* A copy of the modR/M */

	uint8_t	__AVL_SET_INST_PREF(sib);			/* A copy of the SIB byte if present. The presence of the SIB byte
													is defined by the modR/M byte */

	uint32_t __AVL_SET_INST_PREF(disp);			/* Stores the addressing displacement if present. The presence of the
													displacement is defined by the modR/M or the SIB byte. */
		
	uint8_t __AVL_SET_INST_PREF(size);			/* The size of the instruction in bytes */

	AVL_reg_t __AVL_SET_INST_PREF(reg1);		/* Represents the first operand if present. If not present,
													its value == 0 */

	AVL_reg_t __AVL_SET_INST_PREF(reg2);		/* Represents the first operand if present. If not present,
													its value == 0 */

	AVL_reg_t __AVL_SET_INST_PREF(reg3);		/* Represents the first operand if present. If not present,
													its value == 0 */

	uint64_t __AVL_SET_INST_PREF(imm);			/* Stores the immediate value of present. The presence of an
													immediate value is defined by the flags. Its size is defined
													by the instruction (can be known with instruction size) */
} __AVL_SET_PREF(instruction_t);
