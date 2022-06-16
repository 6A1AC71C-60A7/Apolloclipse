
#include <d_portability.h>
#include <d_instruction.h>
#include <d_error.h>

__always_inline
static void test_instruction_prefixes(const ubyte *instruction_raw, instruction_t* const data)
{
    DEBUG(" *** START: TEST PREFIX ***\n");

    if (get_instruction_prefixes(data, &instruction_raw) != SUCCESS)
        DEBUG("WARNING: bad format legacy prefixes\n");
    
    udword* p = (udword*)data->prefix;
    udword y = 0;
    for (udword i = 1 ; i <= RP_REXW_MASK ; i <<= 1)
        DEBUG("[%u] -> [%x]\n", y++, *p & i);
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

void test_instruction(const ubyte *instruction_raw, instruction_t* answer)
{
    instruction_t inst = {};
    test_instruction_prefixes(instruction_raw, &inst);

    if (answer)
        DEBUG("CONCLUSION: %s\n", d_memcmp(&inst, answer, sizeof(instruction_t)) == 0 ? "PASS" : "FAIL");
}

void fprint_instruction(instruction_t* target, FILE* where)
{
    const udword prefix = *(udword*)target->prefix;
    fprintf(where, "PREFIXES:\n - LOCK: %d\n - REPNX: %d\n - REPX: %d\n"
        " - FS: %d\n - GS: %d\n - NOBRANCH: %d\n - BRANCH: %d\n - OPERAND SZ: %d\n"
        " - ADDRESS SZ: %d\n - REX.B: %d\n - REX.X: %d\n - REX.R: %d\n - REX.W: %d\n- - -\n",
        prefix & LP_LOCK_MASK, prefix & LP_LOCK_MASK, prefix & LP_REPX_MASK, 
        prefix & LP_FS_MASK, prefix & LP_GS_MASK, prefix & LP_NOBRANCH_MASK, prefix & LP_BRANCH_MASK,
        prefix & LP_OPSZ_MASK, prefix & LP_ADDRSZ_MASK, prefix & RP_REXB_MASK, prefix & RP_REXX_MASK, 
        prefix & RP_REXR_MASK, prefix & RP_REXW_MASK);

    fprintf(where, "MNEMONIC: [%d]\n- - -\n", target->mnemonic);

    fprintf(where, "OPCODE: [%X][%X][%X]\n- - -\n", target->opcode[0], target->opcode[1], target->opcode[2]);

    ///TODO: VEX 

    fprintf(where, "MODRM:\n - MOD: %d\n - REG: %d\n - RM: %d\n- - -\n",
    MODRM_MOD_GET(target->mod_rm), MODRM_REG_GET(target->mod_rm), MODRM_RM_GET(target->mod_rm));

    fprintf(where, "SIB:\n - BASE: %d\n - INDEX: %d\n - SCALE: %d\n- - -\n",
    SIB_BASE_GET(target->sib), SIB_INDEX_GET(target->sib), SIB_SCALE_GET(target->sib));

    fprintf(where, "DISPLACEMENT: %d\n- - -\n", target->displacement);

    fprintf(where, "SIZE: %d\n- - -\n", target->size);

    ///TODO: RESOLVE REGS

    fprintf(where, "IMMEDIATE: %llX\n- - -\n", target->immediate);
}
