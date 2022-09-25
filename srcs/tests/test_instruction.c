
#include <d_portability.h>
#include <d_instruction.h>
#include <d_error.h>

__always_inline
static void test_instruction_prefixes(const ubyte *instruction_raw, AVL_instruction_t* const data)
{
    DEBUG(" *** START: TEST PREFIX ***\n");

    (void)instruction_raw;

    // if (get_instruction_prefixes(data, &instruction_raw) != SUCCESS)
    //     DEBUG("WARNING: bad format legacy prefixes\n");
    
    udword y = 0;
    for (udword i = 1 ; i <= AVL_RP_REXW_MASK ; i <<= 1)
        DEBUG("[%u] -> [%x]\n", y++, data->i_flags & i);
    DEBUG(" *** END:  TEST PREFIX ***\n");
}

uqword d_memcmp(void* restrict p1, void* restrict p2, uqword size)
{
    ubyte* d1 = (ubyte*)p1;
    ubyte* d2 = (ubyte*)p2;
    uqword i;

    if (d1 && d2)
    {
        i = 0;
        while (d1[i] == d2[i] && i < size)
            i++;
        return d1[i] - d2[i];
    }
    return 1;
}

void test_instruction(const ubyte *instruction_raw, AVL_instruction_t* answer)
{
    AVL_instruction_t inst = {};
    test_instruction_prefixes(instruction_raw, &inst);

    if (answer)
        DEBUG("CONCLUSION: %s\n", d_memcmp(&inst, answer, sizeof(AVL_instruction_t)) == 0 ? "PASS" : "FAIL");
}

void fprint_info(FILE* where, AVL_instruction_t* target)
{
    fprintf(where, "PREFIXES:\n - LOCK: %d\n - REPNX: %d\n - REPX: %d\n"
        " - FS: %d\n - GS: %d\n - NOBRANCH: %d\n - BRANCH: %d\n - OPERAND SZ: %d\n"
        " - ADDRESS SZ: %d\n - REX.B: %d\n - REX.X: %d\n - REX.R: %d\n - REX.W: %d\n - 0x66: %d\n- - -\n",
        target->i_flags & AVL_LP_LOCK_MASK, target->i_flags & AVL_LP_LOCK_MASK, target->i_flags & AVL_LP_REPX_MASK, 
        target->i_flags & AVL_LP_FS_MASK, target->i_flags & AVL_LP_GS_MASK, target->i_flags & AVL_LP_NOBRANCH_MASK, target->i_flags & AVL_LP_BRANCH_MASK,
        target->i_flags & AVL_LP_OPSZ_MASK, target->i_flags & AVL_LP_ADDRSZ_MASK, target->i_flags & AVL_RP_REXB_MASK, target->i_flags & AVL_RP_REXX_MASK, 
        target->i_flags & AVL_RP_REXR_MASK, target->i_flags & AVL_RP_REXW_MASK, target->i_flags & AVL_MP_0x66_MASK);

    fprintf(where, "MNEMONIC: [%d]\n- - -\n", target->i_mnemonic);

    fprintf(where, "OPCODE: [%X][%X][%X]\n- - -\n", target->i_opcode[0], target->i_opcode[1], target->i_opcode[2]);

    ///TODO: VEX 

    fprintf(where, "MODRM:\n - MOD: %d\n - REG: %d\n - RM: %d\n- - -\n",
    AVL_GET_MODRM_MOD(target->i_mod_rm), AVL_GET_MODRM_REG(target), AVL_GET_MODRM_RM(target));

    fprintf(where, "SIB:\n - BASE: %d\n - INDEX: %d\n - SCALE: %d\n- - -\n",
    AVL_GET_SIB_BASE(target), AVL_GET_SIB_INDEX(target), AVL_GET_SIB_SCALE(target->i_sib));

    fprintf(where, "DISPLACEMENT: %d\n- - -\n", target->i_disp);

    fprintf(where, "SIZE: %d\n- - -\n", target->i_size);

    fprintf(where, "IMMEDIATE: %llX\n- - -\n", (long long)target->i_imm);
}
