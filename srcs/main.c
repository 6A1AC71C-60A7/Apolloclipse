
#include <tests.h>
#include <d_opcode.h>
#include <d_register.h>

#include <fcntl.h>
#include <unistd.h>

#define INST_NB 1260
#define BUFFSIZE 0x2000
#define FILENAME "srcs/tests/instructions.txt"

#define TEST_FILE
//#undef TEST_FILE

///TODO: WHILE CONVERTING BACK TO ASM, 2 BYTES VEX OPCODES MAY ALWAYS ALSO BE ENCODED AS 3 BYTES
/// IS USEFUL FOR CODE ALIGNEMENT (JUST NEED TO FOLLOW THE RULE FOR 2 BYTE VEX PREFIX)

///TODO: HANDLE JUMPS PARSING : JCC : Jb (SHORT), Jz (LONG), CALL : NEAR -> Ev, FAR -> Ep, JMP : NEAR -> EV, FAR -> Mp , RET : NEAR -> { Lw, NONE ATTR }, FAR -> {Lw, NONE ATTR}
/// ALSO: JMP NEAR IS ALSO 0XE9, 0XEA, 0XB (MORE OPCODES)
/// ALSO: CALL NEAR IS E8 (MORE OPCODES) 
/// RET COMPARISON MUST BE DONE USING OPCOFES, JUMP & CALL MIGHT BE DONE WITH OPCODE TOO AND JCC MUST BE DONE WITH ATTR

///TODO: Handle 0x67 address size overwrite (makes it 32 bits, otherwise is 64-bits)
/// Check Intel doc before handle this

///TODO: AM_O is also an immediate ?

///TODO: CALL INSTRUCTION ADDRESS RESOLUTION IS DIFERENT FROM OBJDUMP

///TODO: TEST BWSAP BETTER (AMB REGS) IN TWO BYTE OPCODE MAP

///TODO: CASES WHERE OPERAND SIZE IS EXCEPTIONALLY DIFERENT ON OPERANDS ARE NOT
/// HANDLED
/// EXEMPLE: crc eax, cl -> has 32 bit operand size even if cl is 8 bits
/// Cases like that are exeptional and is better to handle them after the diassembler output buy opcode value
/// IN, lsl rax, rdx, lsl rax, [rdx], movsx, movzx, out, ...

///TODO: EXEPTION: ENTER opcode has 2 immediates ...

///TODO: Handle registers pairs as operands: INS, OUTS, MOVS, SCAS, STOS,  ...

///TODO: AMBIGIOUS: xchg r8, rax and be NOP and also be pause ... WTF

///TODO: UMONITOR takes a register which is used as an address (but type is reg), default operand type
///         is currently dword but this is 32 bits addressing (0x67), need to make it qword by default.
///         Test and see 


int main(int ac, const char* av[])
{
    err_t st = SUCCESS;

    (void)ac; (void)av;

    instruction_t dest[INST_NB] = {};

#ifdef TEST_FILE
    ubyte iraw[BUFFSIZE] = {};

    int fd = open(FILENAME, O_RDONLY);

    read(fd, iraw, BUFFSIZE);
#else
    const ubyte iraw[] = "\x0F\xC7\x28\x48\x0F\xC7\x28\x0F\xC7\x20\x48\x0F\xC7\x20\x0F\xC7\x18\x48\x0F\xC7\x18";
#endif

    const ubyte* prt = iraw;

    get_instructions(dest, INST_NB, &prt);

    //fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");
    for (uqword i = 0 ; i < INST_NB ; i++)
    {
        //fprint_info(stdout, &dest[i]);
        fprint_instruction(stdout, &dest[i]);
    }
    //fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");

    return st;
}
