
#include <tests.h>
#include <d_opcode.h>
#include <d_register.h>

#include <fcntl.h>
#include <unistd.h>

#define INST_NB 4000
#define BUFFSIZE 0x6000
#define FILENAME "srcs/tests/samples/avx.txt"

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

///TODO: ONLY WHEN EVEX PREFIX IS USED: SOME INSTRUCTIONS TAKE K REGISTERS (vpcmpeqb/w/d/q, ...)

///ERRORS: AVX512:
/// - vpmaxsd == vpmaxsq (there is not vpmaxsq mnemonic) [ FIXED AND TRUE ]
/// - vpmulld == vpmullq [ FIXED AND TRUE ]
/// - vpminud == vpminuq [ FIXED AND TRUE ]
/// - vpminsd == vpminsq [ FIXED AND TRUE ]
/// - vpmaxud == vpmaxuq [ FIXED AND TRUE ]
/// - vpmaxsd == vpmaxsq [ FIXED AND TRUE ]
/// - vpinsrd == vpinsrq [ FIXED AND TRUE ]
/// - vpextrd == vpextrq [ FIXED AND TRUE ]
/// - vbroadcastsd == vbroadcastf32x2 [ FIXED AND TRUE BUT DEPENDS ON VEX OR EVEX ]
/// - vbroadcastf32x4 and vbroadcastf64x2 are resolved as 'vbroadcastf128' [ SAME AS BEFORE ]
/// SAME for vinsertf32x4 / vinsertf64x2 / vinsertf32x8 / vinsertf64x4 [ SAB ]
/// vpermpd == vpermps [ TRUE float:W0 ; double:W1 ]
/// vpsllvd == vpsllvq [ TRUE d:W0 ; q:W1 ]
/// vpsravd == vpsravq [ TRUE d:W0 ; q:W1 ]
/// vpsrlvd == vpsrlvq [ TRUE d:W0 ; q:W1 ]

///TODO: AVX512 (EVEX): MISSING:
/// valignd/q : 0x66 -> 0F 3A 03
/// vblendmpd/s : 0x66 -> 0F 38 65
/// vcompresspd : 0x66 -> 0F 38 8A
/// vcvtpd2qq : 0x66 -> 0F 7B
/// vcvtpd2udq : 0F 79
/// vcvtpd2uqq : 0x66 -> 0F 79
/// vcvtqq2pd : 0xF3 -> 0F E6
/// vcvtqq2ps : 0F 5B
/// vcvtsd2usi : 0xF2 -> 0F 79
/// vcvtss2usi : 0xF3 -> 0F 79
/// vcvttpd2qq : 0x66 -> 0F 7A
/// vcvttpd2udq : 0F 78
/// vcvttpd2uqq : 0x66 -> 0F 78
/// vcvtudq2pd : 0xF3 -> 0F 7A
/// vcvtudq2ps : 0xf2 -> 0F 7A
/// vcvtusi2sd : 0F 7B
/// vcvtusi2ss : 0xF3 -> 0F 7B
/// vdbpsadbw : 0x66 -> 0F 3A 42
/// vexpandpd : 0x66 -> 0F 38 88
/// vfixupimmpd : 0x66 -> 0F 3A 54
/// vfixupimmsd : 0x66 -> 0F 3A 55
/// vfpclasspd : 0x66 -> 0F 3A 66
/// vfpclasssd : 0x66 -> 0F 3A 67
/// vgatherdps : 0x66 -> 0F 38 92
/// vgatherqps : 0x66 -> 0F 38 93
/// vgetexppd : 0x66 -> 0F 38 42
/// vgetexpsd : 0x66 -> 0F 38 43
/// vgetmantpd : 0x66 -> 0F 3A 26
/// vgetmantsd : 0x66 -> 0F 3A 27
/// vpblendmb/w : 0x66 -> 0f 38 66
/// vpblendmd/q : 0x66 -> 0f 38 64
/// vpbroadcastb : 0x66 -> 0f 38 7A
/// vpbroadcastw : 0x66 -> 0f 38 7B
/// vpbroadcastd/q : 0x66 -> of 38 7C
///MISSING: vpbroadcastmb2q
///MISSING: vpbroadcastmw2d
/// vpcmpb : 0x66 -> 0f 3a 3f
/// vpcmpub : 0x66 -> 0f 3a 3e
/// vpcmpd/w/q : 0x66 -> 0f 3a 1f
/// vpcmpud/w/q : 0x66 -> 0f 3a 1e
/// vpcompressd/q : 0x66 0f 38 8b
/// vpconflictd/q : 0x66 -> 0f 38 c4
/// vpermb : 0x66 -> 0f 38 8d
/// vpermi2b/w : 0x66 -> 0f 38 75
/// vpermi2/q : 0x66 -> 0f 38 76
/// vpermi2ps/pd : 0x66 -> 0f 38 77
/// vpermt2b/w : 0x66 -> 0f 38 7d
/// vpermt2d/q : 0x66 -> 0f 38 7e
/// vpermt2ps/pd : 0x66 -> 0f 38 7f
/// vpexpandd/q : 0x66 -> 0f 38 89
/// vpgatherdd/q : 0x66 -> 0f 38 90
/// vpgatherqd/q : 0x66 -> 0f 38 91
/// vplzcntd/q : 0x66 -> 0f 38 44
/// vpmadd52huq : 0x66 -> 0f 38 b5
/// vpmadd52luq : 0x66 -> 0f 38 b4
/// vpmovb/w2m : 0xf3 -> 0f 38 29
/// vpmovd/q2m : 0xf3 -> 0f 38 39
/// vpmovdb : 0xf3 -> 0f 38 31
/// vpmovsdb : 0xf3 -> 0f 38 21
/// vpmovusdb : 0xf3 -> 0f 38 11
/// vpmovdw : 0xf3 -> 0f 38 33
/// vpmovsdw : 0xf3 -> 0f 38 23
/// vpmovusdw : 0xf3 -> 0f 38 13
/// vpmovm2b/w : 0xf3 -> of 38 28
/// vpmovm2d/q : 0xf3 -> of 38 38
/// vpmovqb : 0xf3 -> 0f 38 32
/// vpmovsqb : 0xf3 -> 0f 38 22
/// vpmovusqb : 0xf3 -> 0f 38 12
/// vpmovqd : 0xf3 -> 0f 38 35
/// vpmovsqd : 0xf3 -> 0f 38 25
/// vpmovusqd : 0cf3 -> 0f 38 15
/// vpmovqw : 0xf3 -> 0f 38 34
/// vpmovsqw : 0xf3 -> 0f 38 24
/// vpmovusqw : 0xf3 -> 0f 38 14
/// vpmovwb : 0xf3 -> 0f 38 30
/// vpmovswb : 0cf3 -> 0f 38 20
/// vpmovuswb : 0xf3 -> 0f 38 10
/// vpmultishiftqb : 0x66 -> 0f 38 83
/// vprolvd/q : 0x66 -> 0f 38 15
/// vprold/q : 0x66 -> 0f 72
/// vprorvd/q : 0x66 -> 0f 38 14
/// vprord/q : 0x66 -> 0f 72
/// vpscatterdd : 0x66 0f 38 a0
/// vpscatterqd : 0x66 -> 0f 38 a1
/// vpternlogd/q : 0x66 -> 0f 3a 25
/// vptestmb/w : 0x66 -> 0f 38 26
/// vptestmd/q : 0x66 -> 0f 38 27
/// vptestnmb/w : 0xf3 -> 0f 38 26
/// vptestnmd/q : 0xf3 -> 0f 38 27
/// vrangepd/ps : 0x66 -> of 3a 50
/// vrangesd/ss : 0x66 -> 0f 3a 51
/// vrcp14pd/ps : 0x66 -> 0f 38 4c
/// vrcp14sd/ss : 0x66 -> 0f 38 4d
/// vreducepd/ps : 0x66 -> 0f 3a 56
/// vreducesd/ss : 0x66 -> 0f 3a 57
/// vrndscalepd : 0x66 -> 0f 3a 09
/// vrndscaleps : 0x66 -> 0f 3a 08
/// vrndscalesd : 0x66 -> 0f 3a 0B
/// vrndscaless : 0x66 -> 0f 3a 0A
/// vrsqrt14pd/ps : 0x66 -> 0f 38 4e
/// vrsqrt14sd/ss : 0x66 -> 0f 38 4f
/// vscalefpd/ps : 0x66 -> 0f 38 2c
/// vscalefsd/ss : 0x66 -> 0f 38 2d
/// vscatterdps/pd : 0x66 -> 0f 38 a2
/// vscatterqps/pd : 0x66 -> 0f 38 a3
/// vshuff32x4/64x2 : 0x66 -> 0f 3a 23
/// vshufi32x4/64x2 : 0x66 -> 0f 3a 43

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
    const ubyte iraw[] = "\x62\xF2\xED\x89\x10\xCB\x62\xF2\xED\x89\x10\x08";
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
