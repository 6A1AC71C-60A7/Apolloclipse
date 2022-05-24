
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
