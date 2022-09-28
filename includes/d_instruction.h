

#pragma once

#include <d_error.h>
#include <d_mnemonic.h>
#include <d_opcode.h>

#include <user/types.h>

#include <user.h>


// /*
// ** Legacy prefixes masks
// */

// /// Certain read-modify-write instructions are executed atomically
// #define LP_LOCK_MASK (udword)(0x1)
// /// Repeat string handling instructions
// #define LP_REPNX_MASK (udword)(LP_LOCK_MASK << 1)
// /// Repeat string handling instructions
// #define LP_REPX_MASK (udword)(LP_REPNX_MASK << 1)
// /// Use references within FS segment instead of the stack
// #define LP_FS_MASK (udword)(LP_REPX_MASK << 1)
// /// Use references within GS segment instead of the stack
// #define LP_GS_MASK (udword)(LP_FS_MASK << 1)
// /// Used to lessen the impact of branch misprediction somewhat, 
// ///		only supported by Intel since the Pentium 4 (weak hint)
// #define LP_NOBRANCH_MASK (udword)(LP_GS_MASK << 1)
// /// Used to lessen the impact of branch misprediction somewhat, 
// ///		only supported by Intel since the Pentium 4 (strong hint)
// #define LP_BRANCH_MASK (udword)(LP_NOBRANCH_MASK << 1)
// /// Operand size
// #define LP_OPSZ_MASK (udword)(LP_BRANCH_MASK << 1)
// /// Address size
// #define LP_ADDRSZ_MASK (udword)(LP_OPSZ_MASK << 1)

// /*
// ** REX prefix masks
// */

// /// This 1-bit value is an extension to the MODRM.rm field or the SIB.base field
// #define RP_REXB_MASK (udword)(LP_ADDRSZ_MASK << 1)
// /// This 1-bit value is an extension to the SIB.index field
// #define RP_REXX_MASK (udword)(RP_REXB_MASK << 1)
// /// This 1-bit value is an extension to the MODRM.reg field
// #define RP_REXR_MASK (udword)(RP_REXX_MASK << 1)
// /// When 1, a 64-bit operand size is used. Otherwise, when 0, the default operand size is used
// #define RP_REXW_MASK (udword)(RP_REXR_MASK << 1)

// /*
// ** Mandatory prefix
// */

// ///TODO: I missed up that 0x66 and 0x67 are already parsed as LP_OPSZ_MASK and LP_ADDRSZ_MASK
// /// Redo all without next 2
// /// TODO: Same for 0xf2 and 0xf3 ...

// #define MP_0x66_MASK /*(udword)(RP_REXW_MASK << 1)*/ LP_OPSZ_MASK
// #define MP_0x67_MASK /*(udword)(MP_0x66_MASK << 1)*/ LP_ADDRSZ_MASK
// #define MP_0xF2_MASK /*(udword)(/ *MP_0x67_MASK* / RP_REXW_MASK << 1)*/ LP_REPNX_MASK
// #define MP_0xF3_MASK /* (udword)(MP_0xF2_MASK << 1) */ LP_REPX_MASK

// /*
// ** Operand size
// */

// #define OS_BYTE_MASK (udword)(RP_REXW_MASK << 1)
// #define OS_WORD_MASK (udword)(OS_BYTE_MASK << 1)
// #define OS_DWORD_MASK (udword)(OS_WORD_MASK << 1)
// #define OS_QWORD_MASK (udword)(OS_DWORD_MASK << 1)
// #define OS_DQWORD_MASK (udword)(OS_QWORD_MASK << 1)
// #define OS_QQWORD_MASK (udword)(OS_DQWORD_MASK << 1)
// #define OS_DQQWORD_MASK (udword)(OS_QQWORD_MASK << 1)

// #define OP_IMMEDIATE_MASK 0 // AVL_OP_IMM_MASK //(udword)(1 << 20)
// #define OP_EVEX_MASK 0 // AVL_OP_EVEX_MASK //(udword)(1 << 21)

/*
** VEX/XOP members values 
*/

// /// Prefix: 0xC4 (3 bytes VEX) | 0xC5 (2 byte VEX) | 0x8F (3 byte XOP)
// #define VEXXOP_PREFIX_GET(x) (ubyte)(*(ubyte*)(x))
// /// This 1-bit value is an 'inverted' extension to the MODRM.reg field (the inverse of REX.R)
// #define VEXXOP_R_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x7) & 0x1)
// /// This 1-bit value is an 'inverted' extension to the SIB.index field (the inverse of REX.X)
// #define VEXXOP_X_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x6) & 0x1)
// /// This 1-bit value is an 'inverted' extension to the MODRM.rm field or the SIB.base field (the inverse of REX.B)
// #define VEXXOP_B_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x5) & 0x1)
// /// Specifies the opcode map to use
// #define VEXXOP_MAP_SELECT_GET(x) (ubyte)(*(ubyte*)((x) + 1) & 0x1F)
// /// For integer instructions: when 1, a 64-bit operand size is used; otherwise, when 0, the default operand size is used (equivalent with REX.W)
// /// For non-integer instructions, this bit is a general opcode extension bit
// #define VEXXOP_WE_GET(x) (ubyte)(((*(ubyte*)((x) + 2)) >> 0x7) & 0x1)
/// An additional operand for the instruction, the value of the XMM or YMM register is 'inverted'
// #define VEXXOP_VVVV_GET(x) (ubyte)(((*(ubyte*)((x) + 2)) >> 0x3) & 0xF)
// #define VEXXOP2_VVVV_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 0x3) & 0xF)

/// When 0, a 128-bit vector lengh is used. Otherwise, when 1, a 256-bit vector length is used
// #define VEXXOP_L_GET(x) (ubyte)(((*(ubyte*)((x) + 2)) >> 2) & 0x1)
// #define VEXXOP2_L_GET(x) (ubyte)(((*(ubyte*)((x) + 1)) >> 2) & 0x1)
/// Specifies an implied mandatory prefix for the opcode:
/// 00 (none) | 01 (0x66) | 10 (0xF3) | 11 (0xF2)
// #define VEXXOP_PP_GET(x) (ubyte)(*(ubyte*)((x) + 2) & 0x3)
// #define VEXXOP2_PP_GET(x) (ubyte)(*(ubyte*)((x) + 1) & 0x3)


/*
** EVEX
*/

///TODO: Document this
///TODO: Invert all here or nothing but not both

// #define EVEX_R_GET(x) (ubyte)((*(ubyte*)(x) >> 0x7) & 0x1)
// #define EVEX_X_GET(x) (ubyte)((*(ubyte*)(x) >> 0x6) & 0x1)
// #define EVEX_B_GET(x) (ubyte)((*(ubyte*)(x) >> 0x5) & 0x1)
// #define EVEX_R2_GET(x) (ubyte)((*(ubyte*)(x) >> 0x4) & 0x1)
// #define EVEX_MAP_GET(x) (ubyte)(*(ubyte*)(x) & 0x3)
// #define EVEX_W_GET(x) (ubyte)((*(ubyte*)((x) + 0x1) >> 0x7) & 0x1)
//#define EVEX_VVVV_GET(x) (ubyte)(~(*(ubyte*)((x) + 0x1) >> 0x3) & 0xF)
//#define EVEX_P_GET(x) (ubyte)((*(ubyte*)((x) + 0x1)) & 0x3)
//#define EVEX_Z_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x7) & 0x1)
// #define EVEX_L2_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x6) & 0x1)
// #define EVEX_L_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x5) & 0x1)
// #define EVEX_BROADCAST_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x4) & 0x1)
// #define EVEX_V2_GET(x) (ubyte)((*(ubyte*)((x) + 0x2) >> 0x3) & 0x1)
// #define EVEX_K_GET(x) (ubyte)((*(ubyte*)((x) + 0x2)) & 0x7)

//#define EVEX_VVVVV_EXTENDTED_GET(x) AVL_GET_EVEX_VVVV(x) //((!EVEX_V2_GET(x) << 0x4) | EVEX_VVVV_GET(x))
//#define EVEX_L_EXTENDED_GET(x) AVL_GET_EVEX_LL(x) // ((EVEX_L2_GET(x) << 1) | EVEX_L_GET(x))

/*
** ModR/M member values
*/

/// Specify (in)direct operand, optionally with displacement. Can be extented by 1 bit. 
// #define MODRM_RM_GET(x) (ubyte)(*(ubyte*)&(x) & 0b00000111)
// /// Opcode extension or register reference
// #define MODRM_REG_GET(x) (ubyte)((*(ubyte*)(&(x)) >> 0x3) & 0b00000111)
/// In general, when this field is 0b11, then register-direct addressing mode is used;
///		otherwise register-indirect addressing mode is used. 
//#define MODRM_MOD_GET(x) AVL_GET_MODRM_MOD(x) // (ubyte)((*(ubyte*)(&(x)) >> 0x6) & 0b00000011)

/*#define MODRM_RM_EXTENDED_GET(inst) AVL_GET_MODRM_RM(inst)  (	\
	((AVL_HAS_REXB_PFX((inst)->i_flags) != 0) << 3) | ((((inst)->i_flags & AVL_OP_EVEX_MASK) && MODRM_MOD_GET((inst)->i_mod_rm) == 0b11 && !EVEX_X_GET((inst)->i_vp)) << 4) | MODRM_RM_GET((inst)->i_mod_rm) \
)*/

/* #define MODRM_REG_EXTENDED_GET(inst) AVL_GET_MODRM_REG(inst) (	\
	((AVL_HAS_REXR_PFX((inst)->i_flags) != 0) << 3) | ((((inst)->i_flags & AVL_OP_EVEX_MASK) && !EVEX_R2_GET((inst)->i_vp)) << 4) | MODRM_REG_GET((inst)->i_mod_rm) \
)*/

/*
** SIB member values
*/

/// The scaling factor of SIB.index
// # define SIB_BASE_GET(x) (ubyte)(*(ubyte*)(&(x)) & 0b00000111)
// /// The index register to use. Can be extented by 1 bit.
// # define SIB_INDEX_GET(x) (ubyte)((*(ubyte*)(&(x)) >> 0x3) & 0b00000111)
/// The base register to use. Can be extented by 1 bit.
//# define SIB_SCALE_GET(x) AVL_GET_SIB_SCALE(x) // (ubyte)((*(ubyte*)(&(x)) >> 0x6) & 0b00000011)

/*#define SIB_BASE_EXTENDED_GET(inst) AVL_GET_SIB_BASE(inst) (	\
	(AVL_HAS_REXB_PFX((inst)->i_flags) != 0) << 3 | SIB_BASE_GET((inst)->i_sib) \
)*/

/*#define SIB_INDEX_EXTENDED_GET(inst) AVL_GET_SIB_INDEX(inst) (	\
	(AVL_HAS_REXX_PFX((inst)->i_flags) != 0) << 3 | SIB_INDEX_GET((inst)->i_sib) \
)*/

// typedef struct
// {
// 	udword		prefix;
// 	mnemonic_t	mnemonic;
// 	ubyte		opcode[3];
// 	ubyte		vexxop[3];
// 	ubyte		mod_rm;
// 	ubyte		sib;
// 	udword		displacement;
// 	ubyte		size;
// 	reg_t		reg1;
// 	reg_t		reg2;
// 	reg_t		reg3;
// 	uqword		immediate;
// } instruction_t;

err_t			get_instruction_prefixes(AVL_instruction_t* const inst, const ubyte** instruction_raw);
void			handle_modrm(AVL_instruction_t* const inst, const ubyte** instruction_raw);
//err_t			get_instruction(AVL_instruction_t* const inst, const ubyte** instruction_raw);
opfield_t		get_instruction_by_extension_one_and_two_b_opmap(ubyte group, opfield_t found, ubyte modrm, udword prefix);
extern void		resolve_operands(AVL_instruction_t* const dest, opfield_t instruction);
extern void		resolve_operands(AVL_instruction_t* const dest, opfield_t instruction);

void			get_instructions(AVL_instruction_t* const dest, uqword destlen, const ubyte** iraw);


extern void		get_legacy_prefixes(udword* const dest, const ubyte** iraw);
extern err_t	err_handle_legacy_prefixes(const udword* const dest);
extern void		get_vex_prefixes(AVL_instruction_t* const inst, const ubyte** iraw);
extern void		get_rex_prefix(udword* const dest, const ubyte** iraw);
extern void		get_evex_prefixes(AVL_instruction_t* const inst, const ubyte** iraw);

extern ubyte	get_modrm(AVL_instruction_t* const inst, const ubyte** iraw);
extern ubyte	get_sib(AVL_instruction_t* const inst, const ubyte** iraw);
extern void		get_displacement(udword* const dest, const ubyte** iraw, uqword nbits);
extern void		get_immediate(AVL_instruction_t* const dest, opfield_t opfield, const ubyte** iraw);

#define OPERAND_HAS_IMMEDIATE(am) ( \
	(am) != 0 && (am) >= AM_I && (am) <= AM_L \
)

#define OPFIELD_HAS_IMMEDIATE(opfield) ( \
	OPERAND_HAS_IMMEDIATE(opfield.am1) \
	|| OPERAND_HAS_IMMEDIATE(opfield.am2) \
	|| OPERAND_HAS_IMMEDIATE(opfield.am3) \
	|| OPERAND_HAS_IMMEDIATE(opfield.am4) \
)

#define IS_ESCAPE_FX87(x) (!AVL_HAS_OP_VEX_PFX(x) && !INST_ISPREFIXED(x) && TESTRANGE((x)->i_opcode[2], 0xD8, 0xDF))

extern void		get_operand_size(AVL_instruction_t* const dest, opfield_t* const found, ubyte is_k_inst);

//extern void		redirect_indexing_opfield(const opfield_t* map, opfield_t* const found, ubyte opcode, ubyte* pvex, AVL_instruction_t* const inst);


#define GET_MAP_INDEX(x) (((x) & 0x0F) + ((((x) & 0xF0) >> 0x4) * 0x10))

///tmp to remove
extern void handle_evex_addons_0x38_opmap(opfield_t* const found, ubyte opcode, udword prefix);
extern void handle_rare_prefixes_0x38_opmap(opfield_t* const found, ubyte opcode, udword prefix);

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

