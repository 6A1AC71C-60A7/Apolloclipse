
#include <tests.h>
#include <d_opcode.h>

///TODO: WHILE CONVERTING BACK TO ASM, 2 BYTES VEX OPCODES MAY ALWAYS ALSO BE ENCODED AS 3 BYTES
/// IS USEFUL FOR CODE ALIGNEMENT (JUST NEED TO FOLLOW THE RULE FOR 2 BYTE VEX PREFIX)

///TODO: HANDLE JUMPS PARSING : JCC : Jb (SHORT), Jz (LONG), CALL : NEAR -> Ev, FAR -> Ep, JMP : NEAR -> EV, FAR -> Mp , RET : NEAR -> { Lw, NONE ATTR }, FAR -> {Lw, NONE ATTR}
/// ALSO: JMP NEAR IS ALSO 0XE9, 0XEA, 0XB (MORE OPCODES)
/// ALSO: CALL NEAR IS E8 (MORE OPCODES) 
/// RET COMPARISON MUST BE DONE USING OPCOFES, JUMP & CALL MIGHT BE DONE WITH OPCODE TOO AND JCC MUST BE DONE WITH ATTR

///TODO: REGS RESOLUTION:
/// - up to 1 reg could be an address ---> 0b10000001
/// - up to 3 regs could be empty/unused ---> 0b10000000
/// - regs can be from : 64, 128, 256, 512 bits operations (this could be resolved other way (e.g: lookiing at opcode field))
/// - reg value can be defined by the instruction addressing mode or the modR/M OR VEX.vvvv ---> 0b00000000 to 0b00001111

int main(int ac, const char* av[])
{
    err_t st = SUCCESS;

    (void)ac; (void)av;

   // printf("%lu\n", sizeof(instruction_t));

   // ubyte t_isnt[] = {0xF0, 0xF2, 0xF3, 0x64, 0x65, 0x2E, 0x3E, 0x66, 0x67, 0b01001111};
   // test_instruction(t_isnt,  0);

    instruction_t dest[1];
    //const ubyte iraw[] = "\x48\x89\xF8";
    const ubyte iraw[] = "\x48\xC7\xC4\x2A\x00\x00\x00";

    const ubyte* prt = iraw;

    get_instructions(dest, sizeof(dest) / sizeof(*dest), &prt);

    fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");
    for (uqword i = 0 ; i < sizeof(dest) / sizeof(*dest) ; i++)
        fprint_instruction(&dest[i], stdout);
    fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");

    return st;


}
