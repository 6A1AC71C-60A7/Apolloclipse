
#include <d_portability.h>
#include <d_instruction.h>
#include <d_opcode.h>
#include <d_utils.h>

#include <user/register.h>

#include <user.h>

#define IS_AME_NONEVEX_EXCEPTION(x) ( \
	(x) == VCVTSI2SS \
	|| (x) == MOVD \
	|| (x) == VMOVD \
	|| (x) == VCVTSI2SD \
	|| (x) == VPINSRD \
	|| (x) == VPEXTRD \
)

#define IS_AME_EVEX_EXCEPTION(x) ( \
	(x) == VCVTUSI2SD \
	|| (x) == VCVTUSI2SS \
)

#define IS_AMG_EXCEPTION(x) ( \
	(x) == VCVTSS2SI \
	|| (x) == VCVTTSS2SI \
	|| (x) == VPEXTRW \
	|| (x) == VCVTSD2SI \
	|| (x) == VCVTTSD2SI \
	|| (x) == VMOVMSKPS \
	|| (x) == VMOVMSKPD \
)

#define IS_AMM_EVEX128_EXCEPTION(inst) ( \
	!((AVL_evex_t*)(inst)->i_vp)->evx_vlen \
	&& !((AVL_evex_t*)(inst)->i_vp)->evx_vlen2 \
	&& (inst)->i_mnemonic == VSCATTERQPS \
)

#define IS_AMM_VEX64_EXCEPTION(x) ( \
	(x) == VMOVLPS \
	|| (x) == VMOVHPS \
	|| (x) == VMOVLPD \
	|| (x) == VMOVHPD \
)

#define IS_AMM_EXCEPTION(x) ( \
	(x) == PINSRW \
)

#define IS_AMM_VEX32_EXCEPTION(x) ( \
	(x) == VLDMXCSR \
	|| (x) == VSTMXCSR \
)

#define IS_AMR_16_EXCEPTION(x) ( \
	(x) == PINSRW \
)

#define IS_AMR_32_EXCEPTION(x) ( \
	(x) == VPINSRW \
)

 #define IS_AMV_ALWAYS128_EXCEPTION(x) ( \
	(x) == VCVTPD2PS \
	|| (x) == VCVTPD2DQ \
	|| (x) == VCVTTPD2DQ \
	|| (x) == VPGATHERQD \
)

#define IS_AMV_EVEX128_EXCEPTION(x) ( \
	(x) == VCVTPD2UDQ \
	|| (x) == VCVTTPD2UDQ \
	|| (x) == VCVTUQQ2PS \
	|| (x) == VPSCATTERQD \
	|| (x) == VSCATTERQPS \
	|| (x) == VCVTQQ2PS \
)

#define IS_AMV_EVEX256_EXCEPTION(x) ( \
	(x) == VCVTPD2PS \
	|| (x) == VCVTPD2DQ \
	|| (x) == VCVTTPD2DQ \
	|| (x) == VCVTPD2UDQ \
	|| (x) == VCVTTPD2UDQ \
	|| (x) == VCVTUQQ2PS \
	|| (x) == VPSCATTERQD \
	|| (x) == VSCATTERQPS \
	|| (x) == VCVTQQ2PS \
)

#define IS_AMW_REG128_EXCEPTION(x) ( \
	(x) == VCVTPS2PD \
	|| (x) == VCVTDQ2PD \
	|| (x) == VCVTPH2PS \
	|| (x) == VCVTPS2PH \
	|| (x) == VPSLLW \
	|| (x) == VPSLLD \
	|| (x) == VPSLLQ \
	|| (x) == VPSRLW \
	|| (x) == VPSRLD \
	|| (x) == VPSRLQ \
	|| (x) == VPSRAW \
	|| (x) == VPSRAD \
	|| (x) == VBROADCASTSS \
	|| (x) == VBROADCASTSD \
)

#define IS_AMW_REGEVEX_DQQ2QQ_EXCEPTION(x) ( \
	(x) == VCVTPS2PD \
	|| (x) == VCVTPH2PS \
	|| (x) == VCVTPS2PH \
	|| (x) == VCVTUDQ2PD \
	|| (x) == VCVTPS2UQQ \
	|| (x) == VCVTTPS2QQ \
	|| (x) == VCVTTPS2UQQ \
	|| (x) == VPMOVSDW \
	|| (x) == VPMOVUSDW \
	|| (x) == VPMOVQD \
	|| (x) == VPMOVSQD \
	|| (x) == VPMOVUSQD \
	|| (x) == VPMOVWB \
	|| (x) == VPMOVSWB \
	|| (x) == VPMOVUSWB \
	|| (x) == VCVTDQ2PD \
)

#define IS_AMW_REGEVEX_QQ2DQ_EXCEPTION(x) ( \
	(x) == VCVTPS2PD \
	|| (x) == VCVTPH2PS \
	|| (x) == VCVTPS2PH \
	|| (x) == VCVTUDQ2PD \
	|| (x) == VCVTPS2UQQ \
	|| (x) == VCVTTPS2QQ \
	|| (x) == VCVTTPS2UQQ \
	|| (x) == VPMOVSDW \
	|| (x) == VPMOVUSDW \
	|| (x) == VPMOVQD \
	|| (x) == VPMOVSQD \
	|| (x) == VPMOVUSQD \
	|| (x) == VPMOVWB \
	|| (x) == VPMOVSWB \
	|| (x) == VPMOVUSWB \
	|| (x) == VCVTDQ2PD \
)

#define IS_AMW_REGEVEX128_EXCEPTION(x) ( \
	(x) == VBROADCASTSD \
	|| (x) == VBROADCASTF32X2 \
	|| (x) == VBROADCASTSS \
)

#define IS_AMW_MEMEVEX32_EXCEPTION(x) ( \
	(x) == VCVTSS2USI \
	|| (x) == VCVTTSS2USI \
	|| (x) == VGETEXPSS \
	|| (x) == VGETMANTSS \
	|| (x) == VRANGESS \
	|| (x) == VRCP14SS \
	|| (x) == VREDUCESS \
	|| (x) == VRNDSCALESS \
	|| (x) == VRSQRT14SS \
	|| (x) == VSCALEFSS \
	|| (x) == VADDSS \
	|| (x) == VMULSS \
	|| (x) == VDIVSS \
	|| (x) == VSQRTSS \
	|| (x) == VMAXSS \
	|| (x) == VMINSS \
	|| (x) == VCVTSS2SD \
	|| (x) == VFIXUPIMMSS \
	|| (x) == VFPCLASSSS \
)

#define IS_AMW_MEMEVEX64_EXCEPTION(x) ( \
	(x) == VCVTSD2USI \
	|| (x) == VCVTTSD2USI \
	|| (x) == VGETEXPSD \
	|| (x) == VGETMANTSD \
	|| (x) == VRANGESD \
	|| (x) == VRCP14SD \
	|| (x) == VREDUCESD \
	|| (x) == VRNDSCALESD \
	|| (x) == VRSQRT14SD \
	|| (x) == VSCALEFSD \
	|| (x) == VADDSD \
	|| (x) == VMULSD \
	|| (x) == VDIVSD \
	|| (x) == VSQRTSD \
	|| (x) == VMAXSD \
	|| (x) == VMINSD \
	|| (x) == VCMPSD \
	|| (x) == VCVTSD2SS \
	|| (x) == VFIXUPIMMSD \
	|| (x) == VFPCLASSSD \
)

#define IS_AMW_MEMEVEX128_EXCEPTION(x) ( \
	(x) == VBROADCASTF32X4 \
	|| (x) == VBROADCASTF64X2 \
	|| (x) == VINSERTF32X4 \
	|| (x) == VINSERTF64X2 \
)

#define IS_AMW_MEMEVEX256_EXCEPTION(x) ( \
	(x) == VBROADCASTF32X8 \
	|| (x) == VBROADCASTF64X4 \
	|| (x) == VINSERTF32X8 \
	|| (x) == VINSERTF64X4 \
)

#define IS_AMW_MEMEVEX_DQQ2DQ_EXCEPTION(x) ( \
	(x) == VCVTPS2PD \
)

#define IS_AMW_MEMEVEX_DQQ2QQ_EXCEPTION(x) ( \
	(x) == VCVTPS2PD \
	|| (x) == VCVTUDQ2PD \
	|| (x) == VCVTDQ2PD \
	|| (x) == VCVTPH2PS \
	|| (x) == VCVTPS2UQQ \
	|| (x) == VCVTTPS2QQ \
	|| (x) == VCVTTPS2UQQ \
)

#define IS_AMW_MEMEVEX_QQ2DQ_EXCEPTION(x) ( \
	(x) == VCVTUDQ2PD \
	|| (x) == VCVTDQ2PD \
	|| (x) == VCVTPH2PS \
	|| (x) == VCVTPS2UQQ \
	|| (x) == VCVTTPS2QQ \
	|| (x) == VCVTTPS2UQQ \
)

#define IS_AMW_MEMEVEX_DQ2Q_EXCEPTION(x) ( \
	(x) == VCVTPH2PS \
	|| (x) == VCVTUDQ2PD \
	|| (x) == VCVTPS2UQQ \
	|| (x) == VCVTTPS2QQ \
	|| (x) == VCVTTPS2UQQ \
	|| (x) == VCVTPS2PD \
	|| (x) == VCVTDQ2PD \
	|| (x) == VMOVDDUP \
)

#define IS_AMW_MEMEVEX_VPMOVDQ2D_EXCEPTION(x) ( \
	(x) == VPMOVDB \
	|| (x) == VPMOVSDB \
	|| (x) == VPMOVUSDB \
	|| (x) == VPMOVQW \
	|| (x) == VPMOVSQW \
	|| (x) == VPMOVUSQW \
)

#define IS_AMW_MEMEVEX_VPMOVQQ2Q_EXCEPTION(x) ( \
	(x) == VPMOVDW \
	|| (x) == VPMOVSDW \
	|| (x) == VPMOVUSDW \
	|| (x) == VPMOVQD \
	|| (x) == VPMOVSQD \
	|| (x) == VPMOVUSQD \
	|| (x) == VPMOVWB \
	|| (x) == VPMOVSWB \
	|| (x) == VPMOVUSWB \
)

#define IS_AMW_MEMEVEX_VPMOVQ2W_EXCEPTION(x) ( \
	(x) == VPMOVQB \
	|| (x) == VPMOVSQB \
	|| (x) == VPMOVUSQB \
)

#define IS_AMBIGIOUS(x) ( \
	TESTRANGE(x, OR_8, OR_512) \
)

#define IS_OSMEMEXTENTED_EXCEPTION_NONVEC_64(x) ( \
	(x) == MOVQ \
	|| (x) == VMOVSD \
	|| (x) == VADDSD \
	|| (x) == VMULSD \
	|| (x) == VDIVSD \
	|| (x) == VSQRTSD \
	|| (x) == VMAXSD \
	|| (x) == VMINSD \
	|| (x) == VCMPSD \
	|| (x) == VCOMISD \
	|| (x) == VUCOMISD \
	|| (x) == VMOVDDUP \
	|| (x) == VCVTSD2SI \
	|| (x) == VCVTTSD2SI \
	|| (x) == VCVTPS2PD \
	|| (x) == VCVTSD2SS \
	|| (x) == VCVTDQ2PD \
	|| (x) == VROUNDSD \
)


#define IS_OSMEMEXTENTED_EXCEPTION_NONVEC_32(x) ( \
	(x) == MOVD \
	|| (x) == VMOVSS \
	|| (x) == VADDSS \
	|| (x) == VCVTSS2SI  \
	|| (x) == VCVTTSS2SI \
	|| (x) == VLDMXCSR \
	|| (x) == VSTMXCSR \
	|| (x) == VEXTRACTPS \
	|| (x) == VINSERTPS \
	|| (x) == VCVTSS2SD \
	|| (x) == VROUNDSS \
)
#define IS_OSMEMEXTENTED_EXCEPTION_NONVEC_16(x) ( \
	(x) == VPINSRW \
	|| (x) == VPEXTRW \
)

#define IS_OSMEMEXTENTED_EXCEPTION_NONVEC_8(x) ( \
	(x) == VPINSRB \
	|| (x) == VPEXTRB \
)

#define IS_OSMEMEXTENTED_EXCEPTION_NONVEC_3264(x) ( \
	(x) == VCVTSI2SD \
	|| (x) == MOVNTI \
	|| (x) == VPINSRQ \
	|| (x) == VPEXTRQ \
	|| (x) == VCVTSI2SD \
)

#define IS_VOSMEMEXTENTED_EXCEPTION_NONVEC_64(x, p) ( \
	(x) == VMOVSD \
	|| (x) == VADDSD \
	|| (x) == VMULSD \
	|| (x) == VDIVSD \
	|| (x) == VSQRTSD \
	|| (x) == VMAXSD \
	|| (x) == VMINSD \
	|| (x) == VCMPSD \
	|| (x) == VCOMISD \
	|| (x) == VUCOMISD \
	|| (x) == VCVTSD2SS \
	|| ((x) == VCVTDQ2PD && !AVL_OPSZ_IS_QQWORD(p)) \
	|| (x) == VCVTSD2SI \
	|| (x) == VCVTTSD2SI \
	|| (x) == VROUNDSD \
	|| ((x) == VCVTPH2PS && !AVL_OPSZ_IS_QQWORD(p)) \
	|| ((x) == VCVTPS2PH && !AVL_OPSZ_IS_QQWORD(p)) \
	|| ((x) == VCVTPS2PD && !AVL_OPSZ_IS_QQWORD(p)) \
	|| ((x) == VMOVDDUP && !AVL_OPSZ_IS_QQWORD(p)) \
)

#define IS_VOSMEMEXTENTED_EXCEPTION_NONVEC_32(x) ( \
	(x) == VMOVSS \
	|| (x) == VMULSS \
	|| (x) == VDIVSS \
	|| (x) == VRSQRTSS \
	|| (x) == VMAXSS \
	|| (x) == VMINSS \
	|| (x) == VCMPSS \
	|| (x) == VCOMISS \
	|| (x) == VUCOMISS \
	|| (x) == VCVTSS2SI \
	|| (x) == VCVTTSS2SI \
	|| (x) == VCVTSS2SD \
	|| (x) == VROUNDSS \
	|| (x) == VPGATHERDD \
	|| (x) == VPGATHERQD \
)

#define IS_VEX_AMH_EXCEPTION(x) ( \
	(((x)->i_opcode[2] == 0x10 || (x)->i_opcode [2]== 0x11) \
	&& ((x)->i_mnemonic == VMOVSS || (x)->i_mnemonic == VMOVSD) \
	&& AVL_GET_MODRM_MOD((x)->i_mod_rm) != 0b11) \
)

#define IS_EVEX_AMH_EXCEPTION(x) ( \
	(x)->i_mnemonic == VPGATHERDD \
	|| (x)->i_mnemonic == VPGATHERDQ \
	|| (x)->i_mnemonic == VPGATHERQD \
	|| (x)->i_mnemonic == VPGATHERQQ \
)

static const reg_t gpr8[] = {
	AVL_OP_AL,   AVL_OP_BL,   AVL_OP_CL,   AVL_OP_DL,
	AVL_OP_SIL,  AVL_OP_DIL,  AVL_OP_SPL,  AVL_OP_BPL,
	AVL_OP_R8B,  AVL_OP_R9B,  AVL_OP_R10B, AVL_OP_R11B,
	AVL_OP_R12B, AVL_OP_R13B, AVL_OP_R14B, AVL_OP_R15B
};

static const reg_t gpr16[] = {
	AVL_OP_AX,   AVL_OP_BX,   AVL_OP_CX,   AVL_OP_DX,
	AVL_OP_SI,   AVL_OP_DI,   AVL_OP_SP,   AVL_OP_BP,
	AVL_OP_R8W,  AVL_OP_R9W,  AVL_OP_R10W, AVL_OP_R11W,
	AVL_OP_R12W, AVL_OP_R13W, AVL_OP_R14W, AVL_OP_R15W
};

static const reg_t gpr32[] = {
	AVL_OP_EAX,  AVL_OP_EBX,  AVL_OP_ECX,  AVL_OP_EDX,
	AVL_OP_ESI,  AVL_OP_EDI,  AVL_OP_ESP,  AVL_OP_EBP,
	AVL_OP_R8D,  AVL_OP_R9D,  AVL_OP_R10D, AVL_OP_R11D,
	AVL_OP_R12D, AVL_OP_R13D, AVL_OP_R14D, AVL_OP_R15D
};

static const reg_t gpr64[] = {
	AVL_OP_RAX,  AVL_OP_RBX,  AVL_OP_RCX,  AVL_OP_RDX,
	AVL_OP_RSI,  AVL_OP_RDI,  AVL_OP_RSP,  AVL_OP_RBP,
	AVL_OP_R8,   AVL_OP_R9,   AVL_OP_R10,  AVL_OP_R11,
	AVL_OP_R12,  AVL_OP_R13,  AVL_OP_R14,  AVL_OP_R15
};

static reg_t	get_general_purpose_register(uqword index, ubyte ot, udword flags)
{
	const reg_t* grp = 0x0;

	switch (ot)
	{
		case OT_B:
			grp = gpr8;
			break ;

		case OT_W:
			grp = gpr16;
			break ;

		case OT_D:
			grp = gpr32;
			break ;

		case OT_Q:
			grp = gpr64;
			break ;

		case OT_C:
			if (AVL_OPSZ_IS_BYTE(flags))
				grp = gpr8;
			else
				grp = gpr16;
			break ;

		case OT_Y:
			if (AVL_GET_OPERAND_SZ(flags) >= AVL_OPSZ_QWORD)
				grp = gpr64;
			else
				grp = gpr32;
			break ;

		case OT_Z:
			if (AVL_OPSZ_IS_WORD(flags))
				grp = gpr16;
			else if (!AVL_OPSZ_IS_BYTE(flags))
				grp = gpr32;
			break ;

		default:
		{
			if (AVL_OPSZ_IS_BYTE(flags))
				grp = gpr8;
			else if (AVL_OPSZ_IS_WORD(flags))
				grp = gpr16;
			else if (AVL_OPSZ_IS_DWORD(flags))
				grp = gpr32;
			else
				grp = gpr64;
		}
	}

	return grp ? grp[index] : AVL_OP_NONE;
}

static reg_t	get_memory(ubyte ot, udword flags)
{
	reg_t found = AVL_OP_NONE;

	switch (ot)
	{
		case OT_B:
			found = AVL_OP_MEM8;
			break ;

		case OT_W:
			found = AVL_OP_MEM16;
			break ;

		case OT_D:
			found = AVL_OP_MEM32;
			break ;

		case OT_Q:
			found = AVL_OP_MEM64;
			break ;

		case OT_DQ:
			found = AVL_OP_MEM128;
			break ;

		case OT_QQ:
			found = AVL_OP_MEM256;
			break ;

		case OT_DQQ:
			found = AVL_OP_MEM512;
			break ;

		case OT_DS:
		// fall through
		case OT_DSS:
		// fall through
		case OT_EXT:
		// fall through
		case OT_BCD:
		// fall through
		case OT_S:
			found = AVL_OP_MEM80;
			break ;

		case OT_C:
			if (AVL_OPSZ_IS_BYTE(flags))
				found = AVL_OP_MEM8;
			else
				found = AVL_OP_MEM16;
			break ;

		case OT_Y:
			if (AVL_GET_OPERAND_SZ(flags) >= AVL_OPSZ_QWORD)
				found = AVL_OP_MEM64;
			else
				found = AVL_OP_MEM32;
			break ;

		case OT_Z:
			if (AVL_OPSZ_IS_WORD(flags))
				found = AVL_OP_MEM16;
			else if (!AVL_OPSZ_IS_BYTE(flags))
				found = AVL_OP_MEM32;
			break ;

		default:
		{
			static const reg_t memsz[] = {
				AVL_OP_MEM8,
				AVL_OP_MEM16,
				AVL_OP_MEM32,
				AVL_OP_MEM64,
				AVL_OP_MEM128,
				AVL_OP_MEM256,
				AVL_OP_MEM512
			};

			found = memsz[AVL_GET_OPERAND_SZ(flags)];
		}
	}

	return found;
}

static reg_t	get_mmx_register(uqword index)
{
	static const reg_t mmxr[] = {
		AVL_OP_MMX0,  AVL_OP_MMX1,  AVL_OP_MMX2,  AVL_OP_MMX3,
		AVL_OP_MMX4,  AVL_OP_MMX5,  AVL_OP_MMX6,  AVL_OP_MMX7,
		AVL_OP_MMX0B, AVL_OP_MMX1B, AVL_OP_MMX2B, AVL_OP_MMX3B,
		AVL_OP_MMX4B, AVL_OP_MMX5B, AVL_OP_MMX6B, AVL_OP_MMX7B
	};

	return mmxr[index];
}

static reg_t	get_xmm_register(uqword index)
{
	static const reg_t xmmr[] = {
		AVL_OP_XMM0,  AVL_OP_XMM1,  AVL_OP_XMM2,  AVL_OP_XMM3,
		AVL_OP_XMM4,  AVL_OP_XMM5,  AVL_OP_XMM6,  AVL_OP_XMM7,
		AVL_OP_XMM8,  AVL_OP_XMM9,  AVL_OP_XMM10, AVL_OP_XMM11,
		AVL_OP_XMM12, AVL_OP_XMM13, AVL_OP_XMM14, AVL_OP_XMM15,
		AVL_OP_XMM16, AVL_OP_XMM17, AVL_OP_XMM18, AVL_OP_XMM19,
		AVL_OP_XMM20, AVL_OP_XMM21, AVL_OP_XMM22, AVL_OP_XMM23,
		AVL_OP_XMM24, AVL_OP_XMM25, AVL_OP_XMM26, AVL_OP_XMM27,
		AVL_OP_XMM28, AVL_OP_XMM29, AVL_OP_XMM30, AVL_OP_XMM31
	};

	return xmmr[index];
}

static reg_t	get_ymm_register(uqword index)
{
	static const reg_t ymmr[] = {
		AVL_OP_YMM0,  AVL_OP_YMM1,  AVL_OP_YMM2,  AVL_OP_YMM3,
		AVL_OP_YMM4,  AVL_OP_YMM5,  AVL_OP_YMM6,  AVL_OP_YMM7,
		AVL_OP_YMM8,  AVL_OP_YMM9,  AVL_OP_YMM10, AVL_OP_YMM11,
		AVL_OP_YMM12, AVL_OP_YMM13, AVL_OP_YMM14, AVL_OP_YMM15,
		AVL_OP_YMM16, AVL_OP_YMM17, AVL_OP_YMM18, AVL_OP_YMM19,
		AVL_OP_YMM20, AVL_OP_YMM21, AVL_OP_YMM22, AVL_OP_YMM23,
		AVL_OP_YMM24, AVL_OP_YMM25, AVL_OP_YMM26, AVL_OP_YMM27,
		AVL_OP_YMM28, AVL_OP_YMM29, AVL_OP_YMM30, AVL_OP_YMM31
	};

	return ymmr[index];
}

static reg_t	get_zmm_register(uqword index)
{
	static const reg_t zmmr[] = {
		AVL_OP_ZMM0,  AVL_OP_ZMM1,  AVL_OP_ZMM2,  AVL_OP_ZMM3,
		AVL_OP_ZMM4,  AVL_OP_ZMM5,  AVL_OP_ZMM6,  AVL_OP_ZMM7,
		AVL_OP_ZMM8,  AVL_OP_ZMM9,  AVL_OP_ZMM10, AVL_OP_ZMM11,
		AVL_OP_ZMM12, AVL_OP_ZMM13, AVL_OP_ZMM14, AVL_OP_ZMM15,
		AVL_OP_ZMM16, AVL_OP_ZMM17, AVL_OP_ZMM18, AVL_OP_ZMM19,
		AVL_OP_ZMM20, AVL_OP_ZMM21, AVL_OP_ZMM22, AVL_OP_ZMM23,
		AVL_OP_ZMM24, AVL_OP_ZMM25, AVL_OP_ZMM26, AVL_OP_ZMM27,
		AVL_OP_ZMM28, AVL_OP_ZMM29, AVL_OP_ZMM30, AVL_OP_ZMM31
	};

	return zmmr[index];
}

static reg_t	get_segment_register(uqword index)
{
	static const reg_t sgmtr[] = {
		AVL_OP_ES,  AVL_OP_CS,  AVL_OP_SS,  AVL_OP_DS,
		AVL_OP_FS,  AVL_OP_GS,  0, 0,
		AVL_OP_ESB,	AVL_OP_CSB, AVL_OP_SSB, AVL_OP_DSB,
		AVL_OP_FSB, AVL_OP_GSB, 0, 0
	};

	return sgmtr[index];
}

static reg_t	get_control_register(uqword index)
{
	static const reg_t crtlr[] = {
		AVL_OP_CR0,  AVL_OP_CR1,  AVL_OP_CR2,  AVL_OP_CR3,
		AVL_OP_CR4,  AVL_OP_CR5,  AVL_OP_CR6,  AVL_OP_CR7,
		AVL_OP_CR8,  AVL_OP_CR9,  AVL_OP_CR10, AVL_OP_CR11,
		AVL_OP_CR12, AVL_OP_CR13, AVL_OP_CR14, AVL_OP_CR15
	};

	return crtlr[index];
}

static reg_t	get_debug_register(uqword index)
{
	static const reg_t dbgr[] = {
		AVL_OP_DR0,  AVL_OP_DR1,  AVL_OP_DR2,  AVL_OP_DR3,
		AVL_OP_DR4,  AVL_OP_DR5,  AVL_OP_DR6,  AVL_OP_DR7,
		AVL_OP_DR8,  AVL_OP_DR9,  AVL_OP_DR10, AVL_OP_DR11,
		AVL_OP_DR12, AVL_OP_DR13, AVL_OP_DR14, AVL_OP_DR15
	};

	return dbgr[index];
}

static reg_t	get_k_register(uqword index)
{
	static const reg_t kr[] = {
		AVL_OP_K0, AVL_OP_K1, AVL_OP_K2, AVL_OP_K3,
		AVL_OP_K4, AVL_OP_K5, AVL_OP_K6, AVL_OP_K7
	};

	return kr[index];
}

static reg_t	get_vector(uqword index, ubyte ot, udword flags)
{
	reg_t (*get_vec_register)(uqword) = 0;

	switch (ot)
	{
		case OT_DQ:
			get_vec_register = get_xmm_register;
			break ;

		case OT_QQ:
			get_vec_register = get_ymm_register;
			break ;

		case OT_DQQ:
			get_vec_register = get_zmm_register;
			break ;

		default:
		{
			switch (AVL_GET_OPERAND_SZ(flags))
			{
				case AVL_OPSZ_DQWORD:
					get_vec_register = get_xmm_register;
					break ;

				case AVL_OPSZ_QQWORD:
					get_vec_register = get_ymm_register;
					break ;

				case AVL_OPSZ_DQQWORD:
					get_vec_register = get_zmm_register;
					break ;
			}
		}
	}

	return get_vec_register ? get_vec_register(index) : AVL_OP_NONE;
}


__always_inline
static void		handle_ame_exceptions(AVL_instruction_t* const inst, udword* const flags)
{
	if (AVL_HAS_OP_EVEX_PFX(*flags) && IS_AME_EVEX_EXCEPTION(inst->i_mnemonic))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_HAS_REXW_PFX(*flags) ? AVL_OPSZ_QWORD : AVL_OPSZ_DWORD);
	}
	else if (!AVL_HAS_REXW_PFX(*flags) && IS_AME_NONEVEX_EXCEPTION(inst->i_mnemonic))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_OPSZ_DWORD);
	}
}

__always_inline
static void		handle_amg_exceptions(AVL_instruction_t* const inst, udword* const flags)
{
	if (!AVL_HAS_REXW_PFX(*flags) && IS_AMG_EXCEPTION(inst->i_mnemonic))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_OPSZ_DWORD);
	}
}

__always_inline
static void		handle_amm_exceptions(AVL_instruction_t* const inst, udword* const flags)
{
	if (AVL_HAS_OP_EVEX_PFX(*flags) && IS_AMM_EVEX128_EXCEPTION(inst))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_OPSZ_QWORD);
	}
	else if (AVL_HAS_OP_VEX_PFX(inst))
	{
		if (IS_AMM_VEX64_EXCEPTION(inst->i_mnemonic))
		{
			AVL_CLEAR_OPSZ(*flags);
			AVL_SET_OPSZ(*flags, AVL_OPSZ_QWORD);
		}
		else if (IS_AMM_VEX32_EXCEPTION(inst->i_mnemonic))
		{
			AVL_CLEAR_OPSZ(*flags);
			AVL_SET_OPSZ(*flags, AVL_OPSZ_DWORD);
		}
	}
	else if (IS_AMM_EXCEPTION(inst->i_mnemonic))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_OPSZ_WORD);
	}
}

__always_inline
static void		handle_amr_exceptions(AVL_instruction_t* const inst, udword* const flags)
{
	if (IS_AMR_16_EXCEPTION(inst->i_mnemonic))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_OPSZ_WORD);
	}
	else if (!AVL_HAS_REXW_PFX(*flags) && IS_AMR_32_EXCEPTION(inst->i_mnemonic))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_OPSZ_DWORD);
	}
}

__always_inline
static void		handle_amv_exceptions(AVL_instruction_t* const inst, udword* const flags)
{
	if (AVL_OPSZ_IS_QQWORD(*flags) && IS_AMV_ALWAYS128_EXCEPTION(inst->i_mnemonic))
	{
		AVL_CLEAR_OPSZ(*flags);
		AVL_SET_OPSZ(*flags, AVL_OPSZ_DQWORD);
	}
	else if (AVL_HAS_OP_EVEX_PFX(*flags))
	{
		if (((AVL_evex_t*)inst->i_vp)->evx_vlen && IS_AMV_EVEX128_EXCEPTION(inst->i_mnemonic))
		{
			AVL_CLEAR_OPSZ(*flags);
			AVL_SET_OPSZ(*flags, AVL_OPSZ_DQWORD);
		}
		else if (((AVL_evex_t*)inst->i_vp)->evx_vlen2 && IS_AMV_EVEX256_EXCEPTION(inst->i_mnemonic))
		{
			AVL_CLEAR_OPSZ(*flags);
			AVL_SET_OPSZ(*flags, AVL_OPSZ_QQWORD);
		}
	}
}

__always_inline
static void		handle_amw_reg_exceptions(AVL_instruction_t* const inst, udword* const flags)
{
	if (!AVL_HAS_OP_EVEX_PFX(*flags))
	{
		if (AVL_OPSZ_IS_QQWORD(*flags) && IS_AMW_REG128_EXCEPTION(inst->i_mnemonic))
		{
			AVL_CLEAR_OPSZ(*flags);
			AVL_SET_OPSZ(*flags, AVL_OPSZ_DQWORD);
		}
	}
	else
	{
		if (((AVL_evex_t*)inst->i_vp)->evx_vlen2 && IS_AMW_REGEVEX_DQQ2QQ_EXCEPTION(inst->i_mnemonic))
		{
			AVL_CLEAR_OPSZ(*flags);
			AVL_SET_OPSZ(*flags, AVL_OPSZ_QQWORD);
		}
		else if ((((AVL_evex_t*)inst->i_vp)->evx_vlen && IS_AMW_REGEVEX_QQ2DQ_EXCEPTION(inst->i_mnemonic))
		|| IS_AMW_REGEVEX128_EXCEPTION(inst->i_mnemonic))
		{
			AVL_CLEAR_OPSZ(*flags);
			AVL_SET_OPSZ(*flags, AVL_OPSZ_DQWORD);
		}
	}
}

__always_inline
static void		handle_amw_mem_exceptions(AVL_instruction_t* const inst, reg_t* const dest)
{
	if (!AVL_HAS_OP_VEX_PFX(inst))
	{
		if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_64(inst->i_mnemonic))
			*dest = AVL_OP_MEM64;
		else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_32(inst->i_mnemonic))
			*dest = AVL_OP_MEM32;
		else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_16(inst->i_mnemonic))
			*dest = AVL_OP_MEM16;
		else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_8(inst->i_mnemonic))
			*dest = AVL_HAS_REXW_PFX(inst->i_flags) ? AVL_OP_MEM64 : AVL_OP_MEM32;
	}
	else if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
	{
		if (IS_AMW_MEMEVEX32_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM32;
		else if (IS_AMW_MEMEVEX64_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM64;
		else if (IS_AMW_MEMEVEX128_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM128;
		else if (IS_AMW_MEMEVEX256_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM256;
		else if (((AVL_evex_t*)inst->i_vp)->evx_vlen2
		&& IS_AMW_MEMEVEX_DQQ2DQ_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM128;
		else if (((AVL_evex_t*)inst->i_vp)->evx_vlen2
		&& IS_AMW_MEMEVEX_DQQ2QQ_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM256;
		else if (((AVL_evex_t*)inst->i_vp)->evx_vlen
		&& IS_AMW_MEMEVEX_QQ2DQ_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM128;
		else if (!((AVL_evex_t*)inst->i_vp)->evx_vlen && !((AVL_evex_t*)inst->i_vp)->evx_vlen2
		&& IS_AMW_MEMEVEX_DQ2Q_EXCEPTION(inst->i_mnemonic))
			*dest = AVL_OP_MEM64;
		else if (IS_AMW_MEMEVEX_VPMOVQQ2Q_EXCEPTION(inst->i_mnemonic))
		{
			if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
				*dest = AVL_OP_MEM256;
			else if (((AVL_evex_t*)inst->i_vp)->evx_vlen)
				*dest = AVL_OP_MEM128;
			else
				*dest = AVL_OP_MEM64;
		}
		else if (IS_AMW_MEMEVEX_VPMOVDQ2D_EXCEPTION(inst->i_mnemonic))
		{
			if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
				*dest = AVL_OP_MEM128;
			else if (((AVL_evex_t*)inst->i_vp)->evx_vlen)
				*dest = AVL_OP_MEM64;
			else
				*dest = AVL_OP_MEM32;
		}

		else if (IS_AMW_MEMEVEX_VPMOVQ2W_EXCEPTION(inst->i_mnemonic))
		{
			if (((AVL_evex_t*)inst->i_vp)->evx_vlen2)
				*dest = AVL_OP_MEM64;
			else if (((AVL_evex_t*)inst->i_vp)->evx_vlen)
				*dest = AVL_OP_MEM32;
			else
				*dest = AVL_OP_MEM16;
		}
	}
	else
	{
		if (IS_VOSMEMEXTENTED_EXCEPTION_NONVEC_64(inst->i_mnemonic, inst->i_flags))
			*dest = AVL_OP_MEM64;
		else if (IS_VOSMEMEXTENTED_EXCEPTION_NONVEC_32(inst->i_mnemonic))
			*dest = AVL_OP_MEM32;
		else if (inst->i_mnemonic == VGATHERDPS)
			*dest = AVL_HAS_REXW_PFX(inst->i_flags) ? AVL_OP_MEM64 : AVL_OP_MEM32;
	}
}

static void resolve_operand(AVL_instruction_t* const inst, reg_t* const dest, ubyte am, ubyte ot, ubyte* const skip)
{
    if (am == AM_ZERO)
		return ;

    const ubyte	modrm_mod = AVL_GET_MODRM_MOD(inst->i_mod_rm);
    const ubyte	modrm_reg = AVL_GET_MODRM_REG(inst);
    const ubyte	modrm_rm = AVL_GET_MODRM_RM(inst);    
	udword		cflags = inst->i_flags;
	ubyte		vex_vvvv;

	if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
    	vex_vvvv = AVL_GET_EVEX_VVVV(inst->i_vp);
	else
    	vex_vvvv = (AVL_ISVEX2_PFX(inst) ? ~((AVL_vex2_t*)inst->i_vp)->vx2_vvvv : ~((AVL_vex_t*)inst->i_vp)->vx_vvvv) & 0xF;

	if (am < DR_RAX)
	{
		switch (am)
		{
			case AM_B:
				*dest = get_general_purpose_register(vex_vvvv, ot, inst->i_flags);
				break ;

			case AM_C:
				*dest = get_control_register(modrm_reg);
				break ;

			case AM_D:
				*dest = get_debug_register(modrm_reg);
				break ;

			case AM_E:
			{
				handle_ame_exceptions(inst, &cflags);

				if (modrm_mod == 0b11)
					*dest = get_general_purpose_register(modrm_rm, ot, cflags);
				else
					*dest = get_memory(ot, cflags);
				break ;
			}

			case AM_F:
				*dest = AVL_OP_RFLAGS;
				break ;

			case AM_G:
			{
				handle_amg_exceptions(inst, &cflags);
				*dest = get_general_purpose_register(modrm_reg, ot, cflags);
				break ;
			}

			case AM_H:
				*dest = get_vector(vex_vvvv, ot, inst->i_flags);
                break ;

			case AM_L:
				*dest = get_vector(inst->i_imm & 0xF, ot, inst->i_flags);
				break ;

			case AM_M:
			{
				handle_amm_exceptions(inst, &cflags);
				*dest = get_memory(ot, cflags);
				break ;
			}

			case AM_N:
				*dest = get_mmx_register(modrm_rm);
				break ;

			case AM_O:
				///TODO: mov moffs
				break ;

			case AM_P:
				*dest = get_mmx_register(modrm_reg);
				break ;

			case AM_Q:
				if (modrm_mod == 0b11)
					*dest = get_mmx_register(modrm_rm);
				else
					*dest = get_memory(ot, inst->i_flags);
				break ;

			case AM_R:
			{
				handle_amr_exceptions(inst, &cflags);
				*dest = get_general_purpose_register(modrm_rm, ot, cflags);
				break ;
			}

			case AM_S:
				*dest = get_segment_register(modrm_reg);
				break ;

			case AM_U:
				if (modrm_mod == 0b11)
					*dest = get_vector(modrm_rm, ot, inst->i_flags);
				else
					*dest = get_memory(ot, inst->i_flags);
				break ;

			case AM_V:
			{
				handle_amv_exceptions(inst, &cflags);
				*dest = get_vector(modrm_reg, ot, cflags);
				break ;
			}

			///TODO: AM_U and AM_W are the same, there must be an error
			case AM_W:
			{
				if (modrm_mod == 0b11)
				{
					handle_amw_reg_exceptions(inst, &cflags);
					*dest = get_vector(modrm_rm, ot, cflags);
				}
				else
				{
					*dest = get_memory(ot, inst->i_flags);
					handle_amw_mem_exceptions(inst, dest);
				}
				break ;
			}

			case AM_X:
                *dest = AVL_OP_PAIR_DS_RSI;
                break ;

            case AM_Y:
                *dest = AVL_OP_PAIR_ES_RDI;
                break ;

            case AM_KR:
                *dest = get_k_register(modrm_reg & 0x7);
                break ;

            case AM_KRM:
                *dest = get_k_register(modrm_rm & 0x7);
                break ;

            case AM_KV:
                *dest = get_k_register(vex_vvvv & 0x7);
                break ;

            case AM_KM:
				if (modrm_mod == 0b11)
                	*dest = get_k_register(modrm_rm);
				else
					*dest = get_memory(ot, inst->i_flags);
                break ;
		}
	}
	else
	{
		if (ot == DRS_87)
			*dest = am - (DR_RAX - AVL_OP_STO);
		else if (am < DR_AH)
		{
			const reg_t* grp = 0;

			switch (ot)
			{
				case OR_8:
					// fall throught
				case DRS_8:
					grp = gpr8;
					break ;

				case OR_16:
					// fall throught
				case DRS_16:
					grp = gpr16;
					break ;

				case OR_32:
					// fall throught
				case DRS_32:
					if (AVL_OPSZ_IS_WORD(inst->i_flags))
						grp = gpr16;
					else
						grp = gpr32;
					break ;

				case OR_64:
					// fall throught
				case DRS_64:
					if (AVL_OPSZ_IS_WORD(inst->i_flags))
						grp = gpr16;
					else if (AVL_OPSZ_IS_DWORD(inst->i_flags))
						grp = gpr32;
					else
						grp = gpr64;
					break ;

				case DRS_SEC:
					*dest = get_segment_register(am - DR_RAX);
					break ;
			}

			if (grp)
				*dest = grp[am - DR_RAX];

			if (IS_AMBIGIOUS(ot))
			{
				if (AVL_HAS_REXB_PFX(inst->i_flags))
                    *dest += 0x8;
        		*skip = 0x1;
			}
		}
		else
		{
			switch (am)
			{
				case DR_AH:
					*dest = AVL_OP_AH;
					break ;

				case DR_CH:
					*dest = AVL_OP_CH;
					break ;

				case DR_DH:
					*dest = AVL_OP_DH;
					break ;

				case DR_BH:
					*dest = AVL_OP_BH;
					break ;
			}
		}
	}
}

void	resolve_operands(AVL_instruction_t* const dest, opfield_t instruction)
{
	ubyte skip;
	ubyte attr_index = 0x0;

	reg_t* const	regs[] = { &dest->i_reg1, &dest->i_reg2, &dest->i_reg3 };
	const byte		ams[] = {instruction.am1, instruction.am2, instruction.am3, instruction.am4 };
	const byte		ots[] = {instruction.ot1, instruction.ot2, instruction.ot3, instruction.ot4 };

	for (uqword i = 0 ; i < ARRLEN(regs) ; i++)
	{
		skip = 0x0;
		resolve_operand(dest, regs[i], ams[attr_index], ots[attr_index], &skip);

		/* Addressing Mode H ((E)VEX.VVVV) is ignored for instructions with no (E)VEX prefix. */
		if (ams[attr_index] == AM_H
		&& !(AVL_HAS_OP_EVEX_PFX(dest->i_flags) || (AVL_HAS_OP_VEX_PFX(dest) && !IS_VEX_AMH_EXCEPTION(dest))))
			i--;

		attr_index += skip + 0x1;
	}

	if (instruction.am4 == AM_L)
		dest->i_imm = get_vector((dest->i_imm >> 0x4) & 0xF, instruction.ot4, dest->i_flags);
}
