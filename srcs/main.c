
///ENGINE: NOTES:
// Add an option to load the static data into the heap whether is possible
//      Per explemple if EPO with jmp before exit (heap is no longer needed)

// NEED DETERMINITICS REVERSIBLE ENGINE
// BE ABLE TO 'ENCRYPT'/'DECRIPT' THE INPUT WITH A KEY
// IT ALSO MUST WORK BY RANGE (E.G. [[1],[10]],[22],[34],... => ONLY WORKS FROM BYTE 1 T0 10 ...)
// IT ALSO MUST HAVE A BLACKLIST FOR REGISTER PERMUTATION (USEFUL FOR THE FUTURE)
//      (EXCEPTIONS ON REGISTERS WHICH WILL BE THE OUTPUT)

#include <dev/tests.h>
#include <dev/d_opcode.h>

#include <user/AVL_register.h>

#include <AVL_disassembler.h>

#include <fcntl.h>
#include <unistd.h>

#define INST_NB 3000
#define BUFFSIZE 0x6000
#define FILENAME "srcs/tests/samples/avx512.txt"

#define TEST_FILE
//#undef TEST_FILE

///ERRORS: (OLD): AVX512:
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

///EVEX: EXCLUSIVE ADDONS:
/// vpmovb/w2m : 0xf3 -> 0f 38 29 [FREE]
/// vpmovd/q2m : 0xf3 -> 0f 38 39 [FREE]
/// vpmovdb : 0xf3 -> 0f 38 31 [FREE]
/// vpmovsdb : 0xf3 -> 0f 38 21 [FREE]
/// vpmovusdb : 0xf3 -> 0f 38 11 [FREE]
/// vpmovdw : 0xf3 -> 0f 38 33 [FREE]
/// vpmovsdw : 0xf3 -> 0f 38 23 [FREE]
/// vpmovusdw : 0xf3 -> 0f 38 13 [FREE]
/// vpmovm2b/w : 0xf3 -> of 38 28 [FREE]
/// vpmovm2d/q : 0xf3 -> of 38 38 [FREE]
/// vpmovqb : 0xf3 -> 0f 38 32 [FREE]
/// vpmovsqb : 0xf3 -> 0f 38 22 [FREE]
/// vpmovusqb : 0xf3 -> 0f 38 12 [FREE]
/// vpmovqd : 0xf3 -> 0f 38 35 [FREE]
/// vpmovsqd : 0xf3 -> 0f 38 25 [FREE]
/// vpmovusqd : 0cf3 -> 0f 38 15 [FREE]
/// vpmovqw : 0xf3 -> 0f 38 34 [FREE]
/// vpmovsqw : 0xf3 -> 0f 38 24 [FREE]
/// vpmovusqw : 0xf3 -> 0f 38 14 [FREE]
/// vpmovwb : 0xf3 -> 0f 38 30 [FREE]
/// vpmovswb : 0cf3 -> 0f 38 20 [FREE]
/// vpmovuswb : 0xf3 -> 0f 38 10 [FREE]
/// vptestnmb/w : 0xf3 -> 0f 38 26 [FREE]
/// vptestnmd/q : 0xf3 -> 0f 38 27 [FREE]
/// vprolvd/q : 0x66 -> 0f 38 15 [COLLISION blendvpd]
/// vprorvd/q : 0x66 -> 0f 38 14 [COLLISION blendvps]
/// vscalefpd/ps : 0x66 -> 0f 38 2c [COLLISION vmaskmovps]
/// vscalefsd/ss : 0x66 -> 0f 38 2d [COLLISION vmaskmovps]

/// vcvtusi2ss : 0xF3 -> 0F 7B [FREE]
/// vblendmpd/s : 0x66 -> 0F 38 65 [FREE]
/// vcompresspd : 0x66 -> 0F 38 8A [FREE]
/// vexpandpd : 0x66 -> 0F 38 88 [FREE]
/// vgatherdps : 0x66 -> 0F 38 92 [ALREADY IN]
/// vgatherqps : 0x66 -> 0F 38 93 [ALREADY IN]
/// vgetexppd : 0x66 -> 0F 38 42 [FREE]
/// vgetexpsd : 0x66 -> 0F 38 43 [FREE]
/// vpblendmb/w : 0x66 -> 0f 38 66 [FREE]
/// vpblendmd/q : 0x66 -> 0f 38 64 [FREE]
/// vpbroadcastb : 0x66 -> 0f 38 7A [FREE]
/// vpbroadcastw : 0x66 -> 0f 38 7B [FREE]
/// vpbroadcastd/q : 0x66 -> of 38 7C [FREE]
/// vpbroadcastmb2q [COLLISION]
/// vpbroadcastmw2d [COLLISION]
/// vpcompressd/q : 0x66 0f 38 8b [FREE]
/// vpconflictd/q : 0x66 -> 0f 38 c4 [FREE] 
/// vpermb : 0x66 -> 0f 38 8d [FREE]
/// vpermi2b/w : 0x66 -> 0f 38 75 [FREE]
/// vpermi2/q : 0x66 -> 0f 38 76 [FREE] 
/// vpermi2ps/pd : 0x66 -> 0f 38 77 [FREE] 
/// vpermt2b/w : 0x66 -> 0f 38 7d [FREE] 
/// vpermt2d/q : 0x66 -> 0f 38 7e [FREE] 
/// vpermt2ps/pd : 0x66 -> 0f 38 7f [FREE] 
/// vpexpandd/q : 0x66 -> 0f 38 89 [FREE] 
/// vpgatherdd/q : 0x66 -> 0f 38 90 [ALREADY IN]
/// vpgatherqd/q : 0x66 -> 0f 38 91 [ALREADY IN]
/// vplzcntd/q : 0x66 -> 0f 38 44 [FREE] 
/// vpmadd52huq : 0x66 -> 0f 38 b5 [FREE] 
/// vpmadd52luq : 0x66 -> 0f 38 b4 [FREE] 
/// vpmultishiftqb : 0x66 -> 0f 38 83 [FREE] 
/// vpscatterdd : 0x66 0f 38 a0 [FREE] 
/// vpscatterqd : 0x66 -> 0f 38 a1 [FREE] 
/// vptestmb/w : 0x66 -> 0f 38 26 [FREE] 
/// vptestmd/q : 0x66 -> 0f 38 27 [FREE] 
/// vrcp14pd/ps : 0x66 -> 0f 38 4c [FREE] 
/// vrcp14sd/ss : 0x66 -> 0f 38 4d [FREE] 
/// vrsqrt14pd/ps : 0x66 -> 0f 38 4e [FREE]  
/// vrsqrt14sd/ss : 0x66 -> 0f 38 4f [FREE] 
/// vscatterdps/pd : 0x66 -> 0f 38 a2 [FREE]
/// vscatterqps/pd : 0x66 -> 0f 38 a3 [FREE] 
/// vprord/q : 0x66 -> 0f 38 72 [FREE] 

/// vdbpsadbw : 0x66 -> 0F 3A 42 [ALREADY IN]
/// vrndscalepd : 0x66 -> 0f 3a 09 [COLLISION vroundpd]
/// vrndscaleps : 0x66 -> 0f 3a 08 [COLLISION vroundps]
/// vrndscalesd : 0x66 -> 0f 3a 0B [COLLISION vroundsd]
/// vrndscaless : 0x66 -> 0f 3a 0A [COLLISION vroundss]
/// valignd/q : 0x66 -> 0F 3A 03 [FREE]
/// vfixupimmpd : 0x66 -> 0F 3A 54 [FREE]
/// vfixupimmsd : 0x66 -> 0F 3A 55 [FREE]
/// vfpclasspd : 0x66 -> 0F 3A 66 [FREE]
/// vfpclasssd : 0x66 -> 0F 3A 67 [FREE]
/// vgetmantpd : 0x66 -> 0F 3A 26 [FREE]
/// vgetmantsd : 0x66 -> 0F 3A 27 [FREE]
/// vpcmpb : 0x66 -> 0f 3a 3f [FREE]
/// vpcmpub : 0x66 -> 0f 3a 3e [FREE]
/// vpcmpd/w/q : 0x66 -> 0f 3a 1f [FREE]
/// vpcmpud/w/q : 0x66 -> 0f 3a 1e [FREE]
/// vpternlogd/q : 0x66 -> 0f 3a 25 [FREE]
/// vrangepd/ps : 0x66 -> of 3a 50 [FREE]
/// vrangesd/ss : 0x66 -> 0f 3a 51 [FREE]
/// vreducepd/ps : 0x66 -> 0f 3a 56 [FREE]
/// vreducesd/ss : 0x66 -> 0f 3a 57 [FREE]
/// vshuff32x4/64x2 : 0x66 -> 0f 3a 23 [FREE]
/// vshufi32x4/64x2 : 0x66 -> 0f 3a 43 [FREE]
/// vinsertf32x8 : 0x66 -> 0f 3a 1a [FREE]

/// vcvtpd2udq : 0F 79 [COLLISION VMWRITE]
/// vcvtqq2pd : 0xF3 -> 0F E6  [COLLISION vcvtdq2pd]
/// vcvtqq2ps : 0F 5B [COLLISION vcvtdq2ps]
/// vcvttpd2udq : 0F 78 [COLLISION VM READ]
/// vprold/q : 0x66 -> 0f 72 [GROUP ?!?!]
/// vcvtpd2qq : 0x66 -> 0F 7B [FREE]
/// vcvtpd2uqq : 0x66 -> 0F 79 [FREE]
/// vcvtsd2usi : 0xF2 -> 0F 79 [FREE]
/// vcvtss2usi : 0xF3 -> 0F 79 [FREE]
/// vcvttpd2qq : 0x66 -> 0F 7A [FREE]
/// vcvttpd2uqq : 0x66 -> 0F 78 [FREE]
/// vcvtudq2pd : 0xF3 -> 0F 7A [FREE]
/// vcvtudq2ps : 0xf2 -> 0F 7A [FREE]
/// vcvtusi2sd : 0xf2 -> 0F 7B [FREE]
/// VCVTTSS2USI

// VCVTUDQ2PS

int is_endof_insts(AVL_instruction_t* const inst)
{
    int amount = 0;

    for (uqword i = 0 ; i < 8 ; i++)
    {
        if (inst->i_mnemonic == ADD && inst->i_opcode[2] == 0 && inst->i_mod_rm == 0)
            amount++;
    }
    return amount == 8;
}

int main(int ac, const char* av[])
{
    err_t st = SUCCESS;

    AVL_instruction_t dest[INST_NB] = {};

#ifdef TEST_FILE
    if (ac != 2)
        return 1;

    ubyte iraw[BUFFSIZE] = {};

    int fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return 1;

    read(fd, iraw, BUFFSIZE);
#else
    (void)av; (void)ac;

    const ubyte iraw[] = "\xc5\xf9\x90\xca";
#endif

    const ubyte* prt = iraw;

    AVL_disassemble_instructions(dest, INST_NB, &prt);

    //fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");
    for (uqword i = 0 ; i < INST_NB ; i++)
    {
        if (i < (uqword)INST_NB - 8 && is_endof_insts(&dest[i]))
            break ;
        //fprint_info(stdout, &dest[i]);
        fprint_instruction(stdout, &dest[i]);
#ifdef TEST_FILE
        if (i < INST_NB - 1 && dest[i].i_mnemonic != dest[i + 1].i_mnemonic)
            fprintf(stdout, "\n");
#endif
    }
    //fprintf(stdout, "*** *** *** *** *** *** *** *** *** *** *** *** ***\n");

    return st;
}
