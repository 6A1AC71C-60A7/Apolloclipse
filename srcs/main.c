
#include <tests.h>
#include <d_opcode.h>
#include <d_register.h>

#include <fcntl.h>
#include <unistd.h>

#define INST_NB 1
#define BUFFSIZE 0x1000
#define FILENAME "srcs/tests/instructions.txt"

#define TEST_FILE
#undef TEST_FILE

///TODO: WHILE CONVERTING BACK TO ASM, 2 BYTES VEX OPCODES MAY ALWAYS ALSO BE ENCODED AS 3 BYTES
/// IS USEFUL FOR CODE ALIGNEMENT (JUST NEED TO FOLLOW THE RULE FOR 2 BYTE VEX PREFIX)

///TODO: HANDLE JUMPS PARSING : JCC : Jb (SHORT), Jz (LONG), CALL : NEAR -> Ev, FAR -> Ep, JMP : NEAR -> EV, FAR -> Mp , RET : NEAR -> { Lw, NONE ATTR }, FAR -> {Lw, NONE ATTR}
/// ALSO: JMP NEAR IS ALSO 0XE9, 0XEA, 0XB (MORE OPCODES)
/// ALSO: CALL NEAR IS E8 (MORE OPCODES) 
/// RET COMPARISON MUST BE DONE USING OPCOFES, JUMP & CALL MIGHT BE DONE WITH OPCODE TOO AND JCC MUST BE DONE WITH ATTR

///TODO: Handle 0x67 address size overwrite (makes it 32 bits, otherwise is 64-bits)
/// Check Intel doc before handle this

///TODO: AM_O is also an immediate ?

///STATUS: Current main value does not work
/// Indexing seems ok now, but maybe opcode tables structs are bad aligned
/// TEST MAPS ALIGNEMENT ...

int main(int ac, const char* av[])
{
    err_t st = SUCCESS;

    (void)ac; (void)av;

   // printf("%lu\n", sizeof(instruction_t));


   // ubyte t_isnt[] = {0xF0, 0xF2, 0xF3, 0x64, 0x65, 0x2E, 0x3E, 0x66, 0x67, 0b01001111};
   // test_instruction(t_isnt,  0);

    instruction_t dest[INST_NB] = {};
    //const ubyte iraw[] = "\x48\xC7\xC0\x42\x00\x00\x00";
    // const ubyte iraw[] = "\x14\x69\x66\x83\xD0\x69\x83\xD0\x69\x48\x83\xD0\x69";
    //const ubyte iraw[] = "\xB8\x42\x00\x00\x00";

#ifdef TEST_FILE
    ubyte iraw[BUFFSIZE] = {};

    int fd = open(FILENAME, O_RDONLY);

    read(fd, iraw, BUFFSIZE);
#else
    const ubyte iraw[] =  "\x66\x41\x0F\x38\xF5\xF7";
#endif

    const ubyte* prt = iraw;

    get_instructions(dest, INST_NB, &prt);

    //fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");
    for (uqword i = 0 ; i < INST_NB ; i++)
    {
        //fprint_info(stdout, &dest[i]);
        fprint_instruction(stdout, &dest[i]);
    }
    fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");

    return st;
}
