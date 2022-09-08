

#pragma once

#include <d_error.h>
#include <d_mnemonic.h>
#include <d_opcode.h>
#include <d_register.h>


/*
** Legacy prefixes masks
*/

/// Certain read-modify-write instructions are executed atomically
#define LP_LOCK_MASK (udword)(0x1)
/// Repeat string handling instructions
#define LP_REPNX_MASK (udword)(LP_LOCK_MASK << 1)
/// Repeat string handling instructions
#define LP_REPX_MASK (udword)(LP_REPNX_MASK << 1)
/// Use references within FS segment instead of the stack
#define LP_FS_MASK (udword)(LP_REPX_MASK << 1)
/// Use references within GS segment instead of the stack
#define LP_GS_MASK (udword)(LP_FS_MASK << 1)
/// Used to lessen the impact of branch misprediction somewhat, 
///		only supported by Intel since the Pentium 4 (weak hint)
#define LP_NOBRANCH_MASK (udword)(LP_GS_MASK << 1)
/// Used to lessen the impact of branch misprediction somewhat, 
///		only supported by Intel since the Pentium 4 (strong hint)
#define LP_BRANCH_MASK (udword)(LP_NOBRANCH_MASK << 1)
/// Operand size
#define LP_OPSZ_MASK (udword)(LP_BRANCH_MASK << 1)
/// Address size
#define LP_ADDRSZ_MASK (udword)(LP_OPSZ_MASK << 1)

/*
** REX prefix masks
*/

/// This 1-bit value is an extension to the MODRM.rm field or the SIB.base field
#define RP_REXB_MASK (udword)(LP_ADDRSZ_MASK << 1)
/// This 1-bit value is an extension to the SIB.index field
#define RP_REXX_MASK (udword)(RP_REXB_MASK << 1)
/// This 1-bit value is an extension to the MODRM.reg field
#define RP_REXR_MASK (udword)(RP_REXX_MASK << 1)
/// When 1, a 64-bit operand size is used. Otherwise, when 0, the default operand size is used
#define RP_REXW_MASK (udword)(RP_REXR_MASK << 1)

/*
** Mandatory prefix
*/

///TODO: I missed up that 0x66 and 0x67 are already parsed as LP_OPSZ_MASK and LP_ADDRSZ_MASK
/// Redo all without next 2
/// TODO: Same for 0xf2 and 0xf3 ...

#define MP_0x66_MASK /*(udword)(RP_REXW_MASK << 1)*/ LP_OPSZ_MASK
#define MP_0x67_MASK /*(udword)(MP_0x66_MASK << 1)*/ LP_ADDRSZ_MASK
#define MP_0xF2_MASK /*(udword)(/ *MP_0x67_MASK* / RP_REXW_MASK << 1)*/ LP_REPNX_MASK
#define MP_0xF3_MASK /* (udword)(MP_0xF2_MASK << 1) */ LP_REPX_MASK

/*
** Operand size
*/

#define OS_BYTE_MASK (udword)(RP_REXW_MASK << 1)
#define OS_WORD_MASK (udword)(OS_BYTE_MASK << 1)
#define OS_DWORD_MASK (udword)(OS_WORD_MASK << 1)
#define OS_QWORD_MASK (udword)(OS_DWORD_MASK << 1)
#define OS_DQWORD_MASK (udword)(OS_QWORD_MASK << 1)
#define OS_QQWORD_MASK (udword)(OS_DQWORD_MASK << 1)
#define OS_DQQWORD_MASK (udword)(OS_QQWORD_MASK << 1)

#define OP_IMMEDIATE_MASK (udword)(OS_DQQWORD_MASK << 1)
#define OP_EVEX_MASK (udword)(OP_IMMEDIATE_MASK << 1)

/*
** VEX/XOP members values 
*/

/// Prefix: 0xC4 (3 bytes VEX) | 0xC5 (2 byte VEX) | 0x8F (3 byte XOP)
#define VEXXOP_PREFIX_GET(x) (ubyte)(*(ubyte*)(x))
/// This 1-bit value is an 'inverted' extension to the MODRM.reg field (the inverse of REX.R)
#define VEXXOP_R_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x7) & 0x1)
/// This 1-bit value is an 'inverted' extension to the SIB.index field (the inverse of REX.X)
#define VEXXOP_X_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x6) & 0x1)
/// This 1-bit value is an 'inverted' extension to the MODRM.rm field or the SIB.base field (the inverse of REX.B)
#define VEXXOP_B_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x5) & 0x1)
/// Specifies the opcode map to use
#define VEXXOP_MAP_SELECT_GET(x) (ubyte)(*(ubyte*)((x) + 1) & 0b00011111)
/// For integer instructions: when 1, a 64-bit operand size is used; otherwise, when 0, the default operand size is used (equivalent with REX.W)
/// For non-integer instructions, this bit is a general opcode extension bit
#define VEXXOP_WE_GET(x) (ubyte)(((*(ubyte*)((x) + 2)) >> 0x8) & 0x1)
/// An additional operand for the instruction, the value of the XMM or YMM register is 'inverted'
#define VEXXOP_VVVV_GET(x) (ubyte)(((*(ubyte*)((x) + 2)) >> 0x3) & 0xF)
#define VEXXOP2_VVVV_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x3) & 0xF)

/// When 0, a 128-bit vector lengh is used. Otherwise, when 1, a 256-bit vector length is used
#define VEXXOP_L_GET(x) (ubyte)(((*(ubyte*)((x) + 2)) >> 2) & 0x1)
#define VEXXOP2_L_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 2) & 0x1)
/// Specifies an implied mandatory prefix for the opcode:
/// 00 (none) | 01 (0x66) | 10 (0xF3) | 11 (0xF2)
#define VEXXOP_PP_GET(x) (ubyte)(*(ubyte*)((x) + 2) & 0b00000011)
#define VEXXOP2_PP_GET(x) (ubyte)(*(ubyte*)((x) + 1) & 0b00000011)


/*
** EVEX
*/

///TODO: Document this
///TODO: Invert all here or nothing but not both

#define EVEX_R_GET(x) (ubyte)((*(ubyte*)(x) >> 0x7) & 0x1)
#define EVEX_X_GET(x) (ubyte)((*(ubyte*)(x) >> 0x6) & 0x1)
#define EVEX_B_GET(x) (ubyte)((*(ubyte*)(x) >> 0x5) & 0x1)
#define EVEX_R2_GET(x) (ubyte)((*(ubyte*)(x) >> 0x4) & 0x1)
#define EVEX_MAP_GET(x) (ubyte)(*(ubyte*)(x) & 0x3)
#define EVEX_W_GET(x) (ubyte)((*(ubyte*)((x) + 0x1) >> 0x7) & 0x1)
#define EVEX_VVVV_GET(x) (ubyte)(~(*(ubyte*)((x) + 0x1) >> 0x3) & 0xF)
#define EVEX_P_GET(x) (ubyte)((*(ubyte*)((x) + 0x1)) & 0x3)
#define EVEX_Z_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x7) & 0x1)
#define EVEX_L2_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x6) & 0x1)
#define EVEX_L_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x5) & 0x1)
#define EVEX_BROADCAST_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x4) & 0x1)
#define EVEX_V2_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x3) & 0x1)
#define EVEX_K_GET(x) (ubyte)((*(ubyte*)((x) + 0x2)) & 0x7)

#define EVEX_VVVVV_EXTENDTED_GET(x) ((!EVEX_V2_GET(x) << 0x4) | EVEX_VVVV_GET(x))
#define EVEX_L_EXTENDED_GET(x) ((EVEX_L2_GET(x) << 1) | EVEX_L_GET(x))

/*
** ModR/M member values
*/

/// Specify (in)direct operand, optionally with displacement. Can be extented by 1 bit. 
#define MODRM_RM_GET(x) (ubyte)(*(ubyte*)&(x) & 0b00000111)
/// Opcode extension or register reference
#define MODRM_REG_GET(x) (ubyte)((*(ubyte*)(&(x)) >> 0x3) & 0b00000111)
/// In general, when this field is 0b11, then register-direct addressing mode is used;
///		otherwise register-indirect addressing mode is used. 
#define MODRM_MOD_GET(x) (ubyte)((*(ubyte*)(&(x)) >> 0x6) & 0b00000011)

#define MODRM_RM_EXTENDED_GET(inst) (	\
	(((*(udword*)(inst)->prefix & RP_REXB_MASK) != 0) << 3) | (((*(udword*)(inst)->prefix & OP_EVEX_MASK) && MODRM_MOD_GET((inst)->mod_rm) == 0b11 && !EVEX_X_GET((inst)->vexxop)) << 4) | MODRM_RM_GET((inst)->mod_rm) \
)

#define MODRM_REG_EXTENDED_GET(inst) (	\
	(((*(udword*)(inst)->prefix & RP_REXR_MASK) != 0) << 3) | (((*(udword*)(inst)->prefix & OP_EVEX_MASK) && !EVEX_R2_GET((inst)->vexxop)) << 4) | MODRM_REG_GET((inst)->mod_rm) \
)

/*
** SIB member values
*/

/// The scaling factor of SIB.index
# define SIB_BASE_GET(x) (ubyte)(*(ubyte*)(&(x)) & 0b00000111)
/// The index register to use. Can be extented by 1 bit.
# define SIB_INDEX_GET(x) (ubyte)((*(ubyte*)(&(x)) >> 0x3) & 0b00000111)
/// The base register to use. Can be extented by 1 bit.
# define SIB_SCALE_GET(x) (ubyte)((*(ubyte*)(&(x)) >> 0x6) & 0b00000011)

#define SIB_BASE_EXTENDED_GET(inst) (	\
	((*(udword*)(inst)->prefix & RP_REXB_MASK) != 0) << 3 | SIB_BASE_GET((inst)->sib) \
)

#define SIB_INDEX_EXTENDED_GET(inst) (	\
	((*(udword*)(inst)->prefix & RP_REXX_MASK) != 0) << 3 | SIB_INDEX_GET((inst)->sib) \
)

typedef struct
{
	ubyte		prefix[4];
	mnemonic_t	mnemonic;
	ubyte		opcode[3];
	ubyte		vexxop[3];
	ubyte		mod_rm;
	ubyte		sib;
	udword		displacement;
	ubyte		size;
	reg_t		reg1;
	reg_t		reg2;
	reg_t		reg3;
	uqword		immediate;
} instruction_t;

err_t			get_instruction_prefixes(instruction_t* const inst, const ubyte** instruction_raw);
void			handle_modrm(instruction_t* const inst, const ubyte** instruction_raw);
err_t			get_instruction(instruction_t* const inst, const ubyte** instruction_raw);
opfield_t		get_instruction_by_extension_one_and_two_b_opmap(ubyte group, ubyte modrm, udword prefix, opfield_t found);
extern void		resolve_operands(instruction_t* const dest, opfield_t instruction);
extern void		resolve_operands_v2(instruction_t* const dest, opfield_t instruction);

void			get_instructions(instruction_t* const dest, uqword destlen, const ubyte** iraw);
