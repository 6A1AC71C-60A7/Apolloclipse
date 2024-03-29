
#pragma once

#include <user/AVL_types.h>
#include <user/AVL_mnemonic.h>

/*
** Legacy prefixes
*/

/// Certain read-modify-write instructions are executed atomically
#define AVL_LP_LOCK_MASK (uint32_t)(0x1)
/// Repeat string handling instructions
#define AVL_LP_REPNX_MASK (uint32_t)(AVL_LP_LOCK_MASK << 0x1)
/// Repeat string handling instructions
#define AVL_LP_REPX_MASK (uint32_t)(AVL_LP_REPNX_MASK << 0x1)
/// Use references within FS segment instead of the stack
#define AVL_LP_FS_MASK (uint32_t)(AVL_LP_REPX_MASK << 0x1)
/// Use references within GS segment instead of the stack
#define AVL_LP_GS_MASK (uint32_t)(AVL_LP_FS_MASK << 0x1)
/// Used to lessen the impact of branch misprediction somewhat, 
///		only supported by Intel since the Pentium 4 (weak hint)
#define AVL_LP_NOBRANCH_MASK (uint32_t)(AVL_LP_GS_MASK << 0x1)
/// Used to lessen the impact of branch misprediction somewhat, 
///		only supported by Intel since the Pentium 4 (strong hint)
#define AVL_LP_BRANCH_MASK (uint32_t)(AVL_LP_NOBRANCH_MASK << 0x1)
/// Operand size (0x66)
#define AVL_LP_OPSZ_MASK (uint32_t)(AVL_LP_BRANCH_MASK << 0x1)
/// Address size (0x67)
#define AVL_LP_ADDRSZ_MASK (uint32_t)(AVL_LP_OPSZ_MASK << 0x1)

#define AVL_HAS_LP_LOCK_PFX(x) !!((x) & AVL_LP_LOCK_MASK)
#define AVL_HAS_LP_REPNX_PFX(x) !!((x) & AVL_LP_REPNX_MASK)
#define AVL_HAS_LP_REPX_PFX(x) !!((x) & AVL_LP_REPX_MASK)
#define AVL_HAS_LP_FS_PFX(x) !!((x) & AVL_LP_FS_MASK)
#define AVL_HAS_LP_GS_PFX(x) !!((x) & AVL_LP_GS_MASK)
#define AVL_HAS_LP_NOBRANCH_PFX(x) !!((x) & AVL_LP_NOBRANCH_MASK)
#define AVL_HAS_LP_BRANCH_PFX(x) !!((x) & AVL_LP_BRANCH_MASK)
#define AVL_HAS_LP_OPSZ_PFX(x) !!((x) & AVL_LP_OPSZ_MASK)
#define AVL_HAS_LP_ADDRSZ_PFX(x) !!((x) & AVL_LP_ADDRSZ_MASK)

/*
** REX prefix
*/

/// This 1-bit value is an extension to the MODRM.rm field or the SIB.base field
#define AVL_RP_REXB_MASK (uint32_t)(AVL_LP_ADDRSZ_MASK << 0x1)
/// This 1-bit value is an extension to the SIB.index field
#define AVL_RP_REXX_MASK (uint32_t)(AVL_RP_REXB_MASK << 0x1)
/// This 1-bit value is an extension to the MODRM.reg field
#define AVL_RP_REXR_MASK (uint32_t)(AVL_RP_REXX_MASK << 0x1)
/// When 1, a 64-bit operand size is used. Otherwise, when 0, the default operand size is used
#define AVL_RP_REXW_MASK (uint32_t)(AVL_RP_REXR_MASK << 0x1)

#define AVL_HAS_REXB_PFX(x) !!((x) & AVL_RP_REXB_MASK)
#define AVL_HAS_REXX_PFX(x) !!((x) & AVL_RP_REXX_MASK)
#define AVL_HAS_REXR_PFX(x) !!((x) & AVL_RP_REXR_MASK)
#define AVL_HAS_REXW_PFX(x) !!((x) & AVL_RP_REXW_MASK)

/*
** Mandatory prefix (aliases)
*/

#define AVL_MP_0x66_MASK AVL_LP_OPSZ_MASK
#define AVL_MP_0x67_MASK AVL_LP_ADDRSZ_MASK
#define AVL_MP_0xF2_MASK AVL_LP_REPNX_MASK
#define AVL_MP_0xF3_MASK AVL_LP_REPX_MASK

#define AVL_HAS_MP_0x66_PFX(x) !!((x) & AVL_MP_0x66_MASK)
#define AVL_HAS_MP_0x67_PFX(x) !!((x) & AVL_MP_0x67_MASK)
#define AVL_HAS_MP_0xF2_PFX(x) !!((x) & AVL_MP_0xF2_MASK)
#define AVL_HAS_MP_0xF3_PFX(x) !!((x) & AVL_MP_0xF3_MASK)

/*
** Optional prefixes (immediate value and EVEX prefix)
*/

#define AVL_OP_IMM_MASK (uint32_t)(AVL_RP_REXW_MASK << 0x1)
#define AVL_OP_EVEX_MASK (uint32_t)(AVL_OP_IMM_MASK << 0x1)
#define AVL_OP_MODRM_MASK (uint32_t)(AVL_OP_EVEX_MASK << 0x01)

#define AVL_HAS_OP_IMM_PFX(x) !!((x) & AVL_OP_IMM_MASK)
#define AVL_HAS_OP_EVEX_PFX(x) !!((x) & AVL_OP_EVEX_MASK)
#define AVL_HAS_OP_MODRM_MASK(x) !!((x) & AVL_OP_MODRM_MASK)

/*
** Operands modifier hints
*/

#define AVL_OM1_READ (uint32_t)(AVL_OP_MODRM_MASK << 0x1)
#define AVL_OM1_WRITE (uint32_t)(AVL_OM1_READ << 0x1)
#define AVL_OM2_READ (uint32_t)(AVL_OM1_WRITE << 0x1)
#define AVL_OM2_WRITE (uint32_t)(AVL_OM2_READ << 0x1)
#define AVL_OM3_READ (uint32_t)(AVL_OM2_WRITE << 0x1)
#define AVL_OM3_WRITE (uint32_t)(AVL_OM3_READ << 0x1)

#define AVL_OM1_IS_READ(x) !!((x) & AVL_OM1_READ)
#define AVL_OM1_IS_WRITE(x) !!((x) & AVL_OM1_WRITE)
#define AVL_OM2_IS_READ(x) !!((x) & AVL_OM2_READ)
#define AVL_OM2_IS_WRITE(x) !!((x) & AVL_OM2_WRITE)
#define AVL_OM3_IS_READ(x) !!((x) & AVL_OM3_READ)
#define AVL_OM3_IS_WRITE(x) !!((x) & AVL_OM3_WRITE)

/*
** Afected flags
*/

///NOTE: Direction flag is not handled (only 'cld' and 'std' can modify it)

#define AVL_AF_CARRY (uint32_t)(AVL_OM3_WRITE << 0x1)
#define AVL_AF_PARITY (uint32_t)(AVL_AF_CARRY << 0x1)
#define AVL_AF_ADJUST (uint32_t)(AVL_AF_PARITY << 0x1)
#define AVL_AF_ZERO (uint32_t)(AVL_AF_ADJUST << 0x1)
#define AVL_AF_SIGN (uint32_t)(AVL_AF_ZERO << 0x1)
#define AVL_AF_OVERFLOW (uint32_t)(AVL_AF_SIGN << 0x1)

#define AVL_HAS_AF_CARRY(x) !!((x) & AVL_AF_CARRY)
#define AVL_HAS_AF_PARITY(x) !!((x) & AVL_AF_PARITY)
#define AVL_HAS_AF_ADJUST(x) !!((x) & AVL_AF_ADJUST)
#define AVL_HAS_AF_ZERO(x) !!((x) & AVL_AF_ZERO)
#define AVL_HAS_AF_SIGN(x) !!((x) & AVL_AF_SIGN)
#define AVL_HAS_AF_OVERFLOW(x) !!((x) & AVL_AF_OVERFLOW)

/*
** Operand Size
*/

#define AVL_OPSZ_BYTE 0x0
#define AVL_OPSZ_WORD 0x1
#define AVL_OPSZ_DWORD 0x2
#define AVL_OPSZ_QWORD 0x3
#define AVL_OPSZ_DQWORD 0x4
#define AVL_OPSZ_QQWORD 0x5
#define AVL_OPSZ_DQQWORD 0x6
#define AVL_OPSZ_OTHER 0x7 // unused

#define __AVL_OPERAND_SZ_SHIFT_AMOUNT 0x1D
#define AVL_GET_OPERAND_SZ(x) (((x) >> __AVL_OPERAND_SZ_SHIFT_AMOUNT) & 0x7)

#define AVL_OPSZ_IS_BYTE(x) (AVL_GET_OPERAND_SZ(x) == AVL_OPSZ_BYTE)
#define AVL_OPSZ_IS_WORD(x) (AVL_GET_OPERAND_SZ(x) == AVL_OPSZ_WORD)
#define AVL_OPSZ_IS_DWORD(x) (AVL_GET_OPERAND_SZ(x) == AVL_OPSZ_DWORD)
#define AVL_OPSZ_IS_QWORD(x) (AVL_GET_OPERAND_SZ(x) == AVL_OPSZ_QWORD)
#define AVL_OPSZ_IS_DQWORD(x) (AVL_GET_OPERAND_SZ(x) == AVL_OPSZ_DQWORD)
#define AVL_OPSZ_IS_QQWORD(x) (AVL_GET_OPERAND_SZ(x) == AVL_OPSZ_QQWORD)
#define AVL_OPSZ_IS_DQQWORD(x) (AVL_GET_OPERAND_SZ(x) == AVL_OPSZ_DQQWORD)

#define AVL_CLEAR_OPSZ(flags) ((flags) &= ~((1 << __AVL_OPERAND_SZ_SHIFT_AMOUNT) | (1 << (__AVL_OPERAND_SZ_SHIFT_AMOUNT + 1)) | (1 << (__AVL_OPERAND_SZ_SHIFT_AMOUNT + 2))))
#define AVL_SET_OPSZ(flags, opsz) ((flags) |= (((opsz) & 0x7) << __AVL_OPERAND_SZ_SHIFT_AMOUNT))

/*
** Miscellaneous
*/

#define AVL_CONST_VEX2_PREFIX 0xC5
#define AVL_CONST_VEX3_PREFIX 0xC4
#define AVL_CONST_EVEX_PREFIX 0x62

#define AVL_HAS_OP_VEX_PFX(x) !!(*(x)->i_vp) // use this one before the others (also true when EVEX)
#define AVL_ISVEX2_PFX(x) !!(*(x)->i_vp == AVL_CONST_VEX2_PREFIX)
#define AVL_ISVEX3_PFX(x) !!(*(x)->i_vp == AVL_CONST_VEX3_PREFIX)

#define AVL_GET_EVEX_VVVV(evex) (uint8_t)(((!(*(AVL_evex_t*)(evex)).__AVL_SET_EVEX_PREF(v)) << 0x4) | (~(*(AVL_evex_t*)(evex)).__AVL_SET_EVEX_PREF(vvvv) & 0xF))
#define AVL_GET_EVEX_LL(evex) (uint8_t)((((*(AVL_evex_t*)(evex)).__AVL_SET_EVEX_PREF(vlen2)) << 0x1) | ((*(AVL_evex_t*)(evex)).__AVL_SET_EVEX_PREF(vlen)))

#define AVL_GET_MODRM_MOD(modrm) (uint8_t)(((modrm) >> 0x6) & 0x3)

#define __AVL_GET_MODRM_RM_BASE(modrm) (uint8_t)((modrm) & 0x7)
#define __AVL_GET_MODRM_REG_BASE(modrm) (uint8_t)(((modrm) >> 0x3) & 0x7)

#define AVL_GET_MODRM_RM(inst) ( \
    ((AVL_HAS_REXB_PFX((inst)->__AVL_SET_INST_PREF(flags)) != 0) << 0x3) \
    | ((AVL_HAS_OP_EVEX_PFX((inst)->__AVL_SET_INST_PREF(flags)) && AVL_GET_MODRM_MOD((inst)->__AVL_SET_INST_PREF(mod_rm)) == 0b11 && (!(*(AVL_evex_t*)((inst)->__AVL_SET_INST_PREF(vp))).__AVL_SET_EVEX_PREF(rexx))) << 0x4) \
    | __AVL_GET_MODRM_RM_BASE((inst)->__AVL_SET_INST_PREF(mod_rm)) \
)

#define AVL_GET_MODRM_REG(inst) ( \
    ((AVL_HAS_REXR_PFX((inst)->__AVL_SET_INST_PREF(flags)) != 0) << 0x3) \
    | ((AVL_HAS_OP_EVEX_PFX((inst)->__AVL_SET_INST_PREF(flags)) && (!(*(AVL_evex_t*)((inst)->__AVL_SET_INST_PREF(vp))).__AVL_SET_EVEX_PREF(rexr2))) << 0x4) \
    | __AVL_GET_MODRM_REG_BASE((inst)->__AVL_SET_INST_PREF(mod_rm)) \
)

#define AVL_GET_SIB_SCALE(sib) (uint8_t)(((sib) >> 0x6) & 0x3)

#define __AVL_GET_SIB_BASE_BASE(modrm) (uint8_t)((modrm) & 0xF)
#define __AVL_GET_SIB_INDEX_BASE(modrm) (uint8_t)(((modrm) >> 0x3) & 0xF)

#define AVL_GET_SIB_BASE(inst) ( \
    ((AVL_HAS_REXB_PFX((inst)->__AVL_SET_INST_PREF(flags)) != 0) << 0x3) \
    | __AVL_GET_SIB_BASE_BASE((inst)->__AVL_SET_INST_PREF(sib)) \
)

#define AVL_GET_SIB_INDEX(inst) ( \
    ((AVL_HAS_REXX_PFX((inst)->__AVL_SET_INST_PREF(flags)) != 0) << 0x3) \
    | __AVL_GET_SIB_INDEX_BASE((inst)->__AVL_SET_INST_PREF(sib)) \
)

#define AVL_IS_JCC_SHORT(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) >= JE \
    && (inst)->__AVL_SET_INST_PREF(mnemonic) <= JP \
    && ((inst)->__AVL_SET_INST_PREF(opcode[2]) & 0xF0) == 0x70 \
)
#define AVL_IS_JCC_LONG(inst)( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) >= JE \
    && (inst)->__AVL_SET_INST_PREF(mnemonic) <= JP \
    && ((inst)->__AVL_SET_INST_PREF(opcode[2]) & 0xF0) == 0x80 \
)

#define AVL_IS_JMP_SHORT(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) == JMP \
    && (inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xEB \
)
#define AVL_IS_JMP_NEAR(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) == JMP \
    && ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xE9 \
        || ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xFF \
        && AVL_GET_MODRM_REG(inst) == 0b100) \
    ) \
)
#define AVL_IS_JMP_FAR(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) == JMP \
    && ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xEA \
        || ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xFF \
        && AVL_GET_MODRM_REG(inst) == 0b101) \
    ) \
)

#define AVL_IS_CALL_NEAR(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) == CALL \
    && ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xE8 \
        || ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xFF \
        && AVL_GET_MODRM_REG(inst) == 0b010) \
    ) \
)
#define AVL_IS_CALL_FAR(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) == CALL \
    && ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0x9A \
        || ((inst)->__AVL_SET_INST_PREF(opcode[2]) == 0xFF \
        && AVL_GET_MODRM_REG(inst) == 0b011) \
    ) \
)

#define AVL_IS_RET_NEAR(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) == RET \
    && (inst)->__AVL_SET_INST_PREF(opcode[2]) >= 0xC2 \
    && (inst)->__AVL_SET_INST_PREF(opcode[2]) <= 0xC3 \
)
#define AVL_IS_RET_FAR(inst) ( \
    (inst)->__AVL_SET_INST_PREF(mnemonic) == RET \
    && (inst)->__AVL_SET_INST_PREF(opcode[2]) >= 0xCA \
    && (inst)->__AVL_SET_INST_PREF(opcode[2]) <= 0xCB \
)

/*
** Tokenizer library
*/

/**
 * @brief Fetch and disassemble @p destlen instructions from @p *text to @p dest tokens.
 * 
 * @param dest An array of 32-byte tokens elements (AVL_instruction_t).
 * @param destlen The amount instructions to fetch.
 * @param text A pointer to bytecode data.
 * Each call the address pointed by is increased to the begin of the next instruction.
 */
void				AVL_disassemble_instructions(__AVL_SET_PREF(instruction_t)* dest, uint64_t destlen, const uint8_t** text);

/**
 * @brief Assemble tokens to x86-64 machine code.
 * 
 * @param dest Where the machine code will be written.
 * @param src The array of tokens that will be assembled.
 * @param amount The amout of tokens to assemble.
 */
void				AVL_assemble_instructions(uint8_t* dest, __AVL_SET_PREF(instruction_t) src[], uint64_t amount);

uint64_t			AVL_inst_iszeroed(__AVL_SET_PREF(instruction_t)* const target);
uint64_t			AVL_inst_getlen(__AVL_SET_PREF(instruction_t) insts[], uint64_t limit);
__AVL_SET_PREF(instruction_t)*
					AVL_inst_find(__AVL_SET_PREF(instruction_t) insts[], __AVL_SET_PREF(mnemonic_t) key, uint64_t insts_len);
__AVL_SET_PREF(instruction_t)*
					AVL_inst_findif(__AVL_SET_PREF(instruction_t) insts[], uint64_t insts_len, __AVL_SET_PREF(condition_t) cond);
void				AVL_inst_insert(__AVL_SET_PREF(instruction_t)* const dest, uint64_t destlen, __AVL_SET_PREF(instruction_t)* const src, uint64_t srclen);
void				AVL_inst_erase(__AVL_SET_PREF(instruction_t)* const target, uint64_t amount, uint64_t targetlen);
void				AVL_inst_swap(__AVL_SET_PREF(instruction_t)* const l, __AVL_SET_PREF(instruction_t)* const r);
