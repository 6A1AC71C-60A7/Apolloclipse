
#include <tests.h>
#include <d_opcode.h>
#include <d_register.h>

#include <fcntl.h>
#include <unistd.h>

#define INST_NB 4000//2000
#define BUFFSIZE 0x6000
#define FILENAME "srcs/tests/samples/avx512.txt"

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

///TODO: AMBIGIOUS: xchg r8, rax and be NOP and also be pause ...
/// ok is pause if is prefixed with 0xf3: "\xF3\x90"
/// for the nop or xchg i have to reverse

///TODO: UMONITOR takes a register which is used as an address (but type is reg), default operand type
///         is currently dword but this is 32 bits addressing (0x67), need to make it qword by default.
///         Test and see 

///TODO: x87 let the possibility to add 3 newer kinds of operand size:
/// 14/28 byte data (OT_DS)
/// 98/108 byte data (OT_DSS)
/// 80-bits byte data (OT_P)
/// The operand size is not handle yet and i don't know yet if is imperative to do
/// or just an addon (i don't know whether or not)
/// After all the user can resolve the operand size looking at prefixes ...

///SAMPLES: MISSING: PMULL, PMULH, PMADD, PCMPGTPB,
/// SSE4: PMOVSXBW, PMOVZXBW, PMOVSXBD, PMOVZXBD, PMOVSXWD, PMOVZXWD, PMOVSXBQ, PMOVZXBQ, PMOVSXWQ, PMOVZXWQ, PMOVSXDQ, PMOVZXDQ

////TODO: THERE IS SOMETHING STRANGE WITH 'AM_H', for SEE encodings this operand
/// do not exist. The instruction is changed to destructive form.
/// I have problems with vmovss (which seems to have 2 args in objdump but 3 args in a the opcode table ...)

///TODO: AMBIGIOUS SHIT IS RESOLVED BY MODRM.MOD
/// OP2B[16] CAN BE EITHER VMOVHPS (MOD != 0B11) OR VMOVLHPS (MOD == 0B11)
/// OP2B[12] CAN BE EITHER VMOVLPS (MOD != 0B11) OR VMOVHLPS (MOD == 0B11)
/// OP2B[c4] : PINSRW AND VPINSRW CAN HAVE EITHER MEMORY OR REGISTER IN SECOND ARGUMENT (DEPENDS OF MOD)
/// A LOT MORE IN OP3B3A
/// WHY INTEL HAS DONE THIS SHIT ?

///TODO: emms, zeroupper and zeroall are the same opcode but called diferently
/// it seems zeroall must have a VEX prefix per exemple (OPCODE IS 0X77)
/// VXEROALL: "\XC5\XFC\X77"
/// VZEROUPPER: "\XC5\XF8\X77"

///TODO: mxx instructions which are the same overload than their VEX implementation are only present with a 'v' as first character
/// MATBE should add them to the mnemonic or a flag in instruction_t

///TODO: vgatherdps xmm1, [xmm1], xmm2 (DEREFERENCE TO XMM NOT HANDLED YET)

///TODO: pinsrq pextrq missing

///TODO: FOR FMA: If VEX.W size is 64 bits, which means double are used and mnemonic must end by 'd' instead of 's'
///ALSO: VEX.W is not handled yet in operand size resolution


///TESTED:
/// - BASIC
/// - x87
/// - MMX
/// - SSE
/// - SSE2
/// - SSE3
/// - SSE4
/// - AVX
/// - AVX2
/// - FMA
/// - AES
/// - VMX

///TODO: EVEX HAS DIFERENT DISPLACEMENT TO PARSE

///TODO: EXTEND VIDX with EVEX.V2 (check in wikipedia EVEX)

///ERRORS: AVX512:
/// - vpand* is all vpand mnemonic
/// - vpor* is all vpor mnemonic
/// - vpxor* is all vpxor mnemonic
///ERROR: vpsllw/d/q / vpsrlw/d/q / vpsraw/d/q
/// - vpmaxsd == vpmaxsq (there is not vpmaxsq mnemonic)
/// - vmovdqa* is all vmovdqa
/// - vmovdqu* is all vmovdqu
///ERROR: vpslldq, vpsrldq
///ERROR: vpabsd
/// - vpmulld == vpmullq
/// - vpminud == vpminuq
/// - vpminsd == vpminsq
/// - vpmaxud == vpmaxuq
/// - vpmaxsd == vpmaxsq
/// - vpinsrd == vpinsrq
/// - vpextrd == vpextrq
/// - vbroadcastsd == vbroadcastf32x2
/// - vbroadcastf32x4 and vbroadcastf64x2 are resolved as 'vbroadcastf128'
/// SAME for vinsertf32x4 / vinsertf64x2 / vinsertf32x8 / vinsertf64x4
/// ERROR: vpermw
/// vpermpd == vpermps
/// ERROR: vpermq
/// vpsllvd == vpsllvq
/// ERROR: vpsravw
/// vpsravd == vpsravq
/// 100% SURE BAD MNEMONIC: vpsrlvw is pblendvb
/// vpsrlvd == vpsrlvq
///INSTRUCTIONS: WITH K* AVX512 are not handled yet (UNTIL K INSTRUCTIONS ALL SEEM +|- OK)

///MISSING INSTRUCTIONS IN AVX512 ARE IN OPCODE MAP 2 BYTES
/// IF PREFIX IS VEX IS ONE INSTRUCTION (WHICH IS MISSING)
/// ELSE IS THE CURRENT INSTRUCTION (LINE 3, 4, 9)
/// - KADDB/W/D/Q : 0F 4A
/// - KANDB/W/D/Q : 0F 41
/// - KANDNB/W/D/Q : 0F 42
/// - KMOVB/W/D/Q : 0F 90
/// - KMOVB/W/D/Q : 0F 91 (DIFF ARGS THAN PREVIOUS)
/// - KMOVB/W/D/Q : 0F 92 (SAME)
/// - KMOWB/W/D/Q : 0F 93 (SAME)
/// - KNOTB/W/D/Q : 0F 44
/// - KORB/W/D/Q : 0F 45
/// - KORTESTB/W/D/Q : 0F 98
/// - KSHIFTLB/W/D/Q : 0F 32/33
/// - KSHITFRB/W/D/Q : 0F 30/31
/// - KTESTB/W/D/Q : 0F 99
/// - KUNPCKBW/WD/DQ : 0F 4B
/// - KXNORB/W/D/Q : 0F 46
/// - KXORB/W/D/Q : OF 47

///SEEMS THAT THE SAME PATTERN IS USED FOR INSTRUCTIONS THAT ARE EVEX AND NOT VEX 
/// FOR ALL THE INSTRUCTIONS THAT ARE EXCLUSIVELLY FOR AVX512 (IN TEST AFTER THE K* INCIDENT)

/// TODO: Instructions having k registers as argument are not handled yet (AVX512)
/// Seems than opcode map's instruction (field) stills the same ?!?!



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
    const ubyte iraw[] = "\x62\xD1\x0D\x49\xE9\x24\x24";
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
