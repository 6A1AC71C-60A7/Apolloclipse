
#include <tests.h>
#include <d_opcode.h>

///TODO: Opcodes maps (opcode, mnemonic, ismodrm, isimmediate, ...)

int main(int ac, const char* av[])
{
    err_t st = SUCCESS;

    (void)ac; (void)av;

    ubyte t_isnt[] = {0xF0, 0xF2, 0xF3, 0x64, 0x65, 0x2E, 0x3E, 0x66, 0x67, 0b01001111};
    test_instruction(t_isnt,  0);

    return st;

}
