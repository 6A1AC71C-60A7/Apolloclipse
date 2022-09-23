
#include <d_portability.h>
#include <d_instruction.h>
#include <d_register.h>
#include <d_opcode.h>
#include <d_utils.h>

#include <user/register.h>

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

static reg_t	get_general_purpose_register(uqword index, ubyte ot, udword prefix)
{
	reg_t found = AVL_OP_NONE;

	switch (ot)
	{
		case OT_B:
			found = gpr8[index];
			break ;

		case OT_W:
			found = gpr16[index];
			break ;

		case OT_D:
			found = gpr32[index];
			break ;

		case OT_Q:
			found = gpr64[index];
			break ;

		case OT_C:
			if (prefix & OS_BYTE_MASK)
				found = gpr8[index];
			else
				found = gpr16[index];
			break ;

		case OT_Y:
			if (prefix & (OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK))
				found = gpr64[index];
			else
				found = gpr32[index];
			break ;

		case OT_Z:
			if (prefix & OS_WORD_MASK)
				found = gpr16[index];
			else if (!(prefix & OS_BYTE_MASK))
				found = gpr32[index];
			break ;

		default:
		{
			if (prefix & OS_BYTE_MASK)
				found = gpr8[index];
			else if (prefix & OS_WORD_MASK)
				found = gpr16[index];
			else if (prefix & OS_DWORD_MASK)
				found = gpr32[index];
			else/* if (prefix & OS_QWORD_MASK)*/
				found = gpr64[index];
		}
	}

	return found;
}

static reg_t	get_memory(ubyte ot, udword prefix)
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

		///TODO: Add 512-bits

		// case OT_DQQ:
		// 	found = AVL_OP_MEM512;
		// 	break ;

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
			if (prefix & OS_BYTE_MASK)
				found = AVL_OP_MEM8;
			else
				found = AVL_OP_MEM16;
			break ;

		case OT_Y:
			if (prefix & (OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK))
				found = AVL_OP_MEM64;
			else
				found = AVL_OP_MEM32;
			break ;

		case OT_Z:
			if (prefix & OS_WORD_MASK)
				found = AVL_OP_MEM16;
			else if (!(prefix & OS_BYTE_MASK))
				found = AVL_OP_MEM32;
			break ;

		default:
		{
			///TODO: Handle OT_P (and maybe more)

			if (prefix & OS_BYTE_MASK)
				found = AVL_OP_MEM8;
			else if (prefix & OS_WORD_MASK)
				found = AVL_OP_MEM16;
			else if (prefix & OS_DWORD_MASK)
				found = AVL_OP_MEM32;
			else if (prefix & OS_QWORD_MASK)
				found = AVL_OP_MEM64;
			else if (prefix & OS_DQWORD_MASK)
				found = AVL_OP_MEM128;
			else if (prefix & OS_QQWORD_MASK)
				found = AVL_OP_MEM256;
			else if (prefix & OS_DQQWORD_MASK)
				found = AVL_OP_MEM512;
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

static reg_t	get_vector(uqword index, ubyte ot, udword prefix)
{
	reg_t found = AVL_OP_NONE;

	switch (ot)
	{
		case OT_DQ:
			found = get_xmm_register(index);
			break ;

		case OT_QQ:
			found = get_ymm_register(index);
			break ;

		///TODO: Handle 512-bits too

		case OT_DQQ:
			found = get_zmm_register(index);
			break ;

		default:
		{
			if (prefix & OS_DQWORD_MASK)
                found = get_xmm_register(index);
            else if (prefix & OS_QQWORD_MASK)
                found = get_ymm_register(index);
            else if (prefix & OS_DQQWORD_MASK)
                found = get_zmm_register(index);
		}
	}

	return found;
}

#define IS_AMBIGIOUS(x) ((x) >= OR_8 && (x) <= OR_512)

#define IS_OSMEMEXTENTED_EXCEPTION_NONVEC_64(x, p) ( \
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
	/*|| ((x) == PSUBQ && !(p & MP_0x66_MASK))*/ \
	/*|| ((x) == PMULUDQ && !(p & MP_0x66_MASK))*/\
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
/*	|| (x) == CVTSI2SS \ */ \
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
	|| ((x) == VCVTDQ2PD && !((p) & OS_QQWORD_MASK)) \
	|| (x) == VCVTSD2SI \
	|| (x) == VCVTTSD2SI \
	|| (x) == VROUNDSD \
	|| ((x) == VCVTPH2PS && !((p) & OS_QQWORD_MASK)) \
	|| ((x) == VCVTPS2PH && !((p) & OS_QQWORD_MASK)) \
	|| ((x) == VCVTPS2PD && !((p) & OS_QQWORD_MASK)) \
	|| ((x) == VMOVDDUP && !((p) & OS_QQWORD_MASK)) \
)

#define IS_VOSMEMEXTENTED_EXCEPTION_NONVEC_32(x) ( \
	(x) == VMOVSS \
	|| (x) == VMULSS \
	|| (x) == VDIVSS \
	|| (x) == VRSQRTSS \
	|| (x) == VMAXSS \
	|| (x) == VMINSS \
	|| ((x) == VCMPSS /*&& !((p) & RP_REXW_MASK)*/) \
	|| (x) == VCOMISS \
	|| (x) == VUCOMISS \
	|| (x) == VCVTSS2SI \
	|| (x) == VCVTTSS2SI \
	/*|| (x) == VCVTPS2PD*/ \
	|| (x) == VCVTSS2SD \
	|| (x) == VROUNDSS \
)

#define IS_VEX_AMH_EXCEPTION(x) ( \
	(((x)->opcode[2] == 0x10 || (x)->opcode [2]== 0x11) && ((x)->mnemonic == VMOVSS || (x)->mnemonic == VMOVSD) && MODRM_MOD_GET((x)->mod_rm) != 0b11) \
)

#define IS_EVEX_AMH_EXCEPTION(x) ( \
	(x)->mnemonic == VPGATHERDD \
	|| (x)->mnemonic == VPGATHERDQ \
	|| (x)->mnemonic == VPGATHERQD \
	|| (x)->mnemonic == VPGATHERQQ \
)

static void resolve_operand_v2(instruction_t* const inst, reg_t* const dest, ubyte am, ubyte ot, ubyte* const skip)
{
	DEBUG("[DEBUG] RESOLVE OPERAND: AM: %d OT: %d\n", am, ot);

    if (am == AM_ZERO)
		return ;

    /* ModR/M 'reg' field is extended by 1 bit by REX.R prefix or by VEX.~R.
        ModR/M 'rm' field is extended by 1 bit by REX.B prefix or by VEX.~B. */

    const ubyte modrm_mod = MODRM_MOD_GET(inst->mod_rm);
    const ubyte modrm_reg = MODRM_REG_EXTENDED_GET(inst);
    ubyte modrm_rm = MODRM_RM_EXTENDED_GET(inst);

    ubyte vex_vvvv;

    if (*(udword*)inst->prefix & OP_EVEX_MASK)
        vex_vvvv = EVEX_VVVVV_EXTENDTED_GET(inst->vexxop);
    else
        vex_vvvv = (inst->vexxop[2] == 0 ? ~VEXXOP2_VVVV_GET(inst->vexxop) : ~VEXXOP_VVVV_GET(inst->vexxop)) & 0xF;

    DEBUG("MODRM BYTE: 0x%02X\n", inst->mod_rm);
    DEBUG("MODRM REG: %d\n", modrm_reg);
    DEBUG("MODRM RM: %d\n", modrm_rm);
    DEBUG("VEX VVVV is: %d\n", vex_vvvv);

    /// ABOVE SEEMS HANDLED IN 'MODRM_REG_EXTENDED_GET'
    // if (0 /* 3 bytes VEX opcode */)
    //     modrm_rm |= (((*(udword*)inst->prefix & RP_REXB_MASK)) << 3) | (~VEXXOP_B_GET(inst->vexxop) << 3);

	if (am < DR_RAX)
	{
		switch (am)
		{
			case AM_B:
				*dest = get_general_purpose_register(vex_vvvv, ot, *(udword*)inst->prefix);
				break ;

			case AM_C:
				*dest = get_control_register(modrm_reg);
				break ;

			case AM_D:
				*dest = get_debug_register(modrm_reg);
				break ;

			case AM_E:
			{
				udword p = *(udword*)inst->prefix;

				if ((inst->mnemonic == VCVTSI2SS || inst->mnemonic == MOVD || inst->mnemonic == VMOVD || inst->mnemonic == VCVTSI2SD || inst->mnemonic == VPINSRD || inst->mnemonic == VPEXTRD) && !(p & RP_REXW_MASK))
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);	
					p |= OS_DWORD_MASK;
				}
				else if (p & OP_EVEX_MASK)
				{
					if (inst->mnemonic == VCVTUSI2SD || inst->mnemonic == VCVTUSI2SS)
					{
						p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						p |= p & RP_REXW_MASK ? OS_QWORD_MASK : OS_DWORD_MASK;
					}
				}

				if (modrm_mod == 0b11)
					*dest = get_general_purpose_register(modrm_rm, ot, p);
				else
					*dest = get_memory(ot, p);
				break ;
			}

			case AM_F:
				*dest = AVL_OP_RFLAGS;
				break ;

			case AM_G:
			{
				udword p = *(udword*)inst->prefix;

				if ((inst->mnemonic == VCVTSS2SI || inst->mnemonic == VCVTTSS2SI || inst->mnemonic == VPEXTRW || inst->mnemonic == VCVTSD2SI || inst->mnemonic == VCVTTSD2SI || inst->mnemonic == VMOVMSKPS || inst->mnemonic == VMOVMSKPD) && !(p & RP_REXW_MASK))
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					p |= OS_DWORD_MASK;
				}

				*dest = get_general_purpose_register(modrm_reg, ot, p);
				break ;
			}

			case AM_H:
				*dest = get_vector(vex_vvvv, ot, *(udword*)inst->prefix);
                break ;

			case AM_L:
				*dest = get_vector(inst->immediate & 0xF, ot, *(udword*)inst->prefix);
				break ;

			case AM_M:
			{
				udword p = *(udword*)inst->prefix;

				if (inst->mnemonic == PINSRW)
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					p |= OS_WORD_MASK;
				}

				else if (inst->vexxop[0] && (inst->mnemonic == VMOVLPS || inst->mnemonic == VMOVHPS || inst->mnemonic == VMOVLPD || inst->mnemonic == VMOVHPD))
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					p |= OS_QWORD_MASK;
				}

				else if (inst->vexxop[0] && (inst->mnemonic == VLDMXCSR|| inst->mnemonic == VSTMXCSR))
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					p |= OS_DWORD_MASK;
				}

				else if (*(udword*)inst->prefix & OP_EVEX_MASK)
				{
					if (!EVEX_L_GET(inst->vexxop) && !EVEX_L2_GET(inst->vexxop) && inst->mnemonic == VSCATTERQPS)
					{
						p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						p |= OS_QWORD_MASK;
					}
				}

				*dest = get_memory(ot, p);
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
					*dest = get_memory(ot, *(udword*)inst->prefix);
				break ;

			case AM_R:
			{
				udword p = *(udword*)inst->prefix;

				if (inst->mnemonic == PINSRW)
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					p |= OS_WORD_MASK;
				}
				else if (inst->mnemonic == VPINSRW && !(p & RP_REXW_MASK))
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					p |= OS_DWORD_MASK;
				}

				*dest = get_general_purpose_register(modrm_rm, ot, p);
				break ;
			}

			case AM_S:
				*dest = get_segment_register(modrm_reg);
				break ;

			case AM_U:
				if (modrm_mod == 0b11)
					*dest = get_vector(modrm_rm, ot, *(udword*)inst->prefix);
				else
					*dest = get_memory(ot, *(udword*)inst->prefix);
				break ;

			case AM_V:
			{
				udword p = *(udword*)inst->prefix;

				if ((inst->mnemonic == VCVTPD2PS || inst->mnemonic == VCVTPD2DQ || inst->mnemonic == VCVTTPD2DQ) && p & OS_QQWORD_MASK)
				{
					p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					p |= OS_DQWORD_MASK;
				}
				else if (p & OP_EVEX_MASK)
				{
					if (EVEX_L_GET(inst->vexxop) && (inst->mnemonic == VCVTPD2UDQ || inst->mnemonic == VCVTTPD2UDQ || inst->mnemonic == VCVTUQQ2PS
					|| inst->mnemonic == VPSCATTERQD || inst->mnemonic == VSCATTERQPS || inst->mnemonic == VCVTQQ2PS))
					{
						p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						p |= OS_DQWORD_MASK;
					}
					else if (EVEX_L2_GET(inst->vexxop) && (inst->mnemonic == VCVTPD2PS || inst->mnemonic == VCVTPD2DQ || inst->mnemonic == VCVTTPD2DQ
					|| inst->mnemonic == VCVTPD2UDQ || inst->mnemonic == VCVTTPD2UDQ || inst->mnemonic == VCVTUQQ2PS || inst->mnemonic == VPSCATTERQD
					|| inst->mnemonic == VSCATTERQPS || inst->mnemonic == VCVTQQ2PS))
					{
						p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						p |= OS_QQWORD_MASK;
					}

				}

				*dest = get_vector(modrm_reg, ot, p);
				break ;
			}

			///TODO: AM_U and AM_W are the same, there must be an error
			case AM_W:
			{
				if (modrm_mod == 0b11)
				{
					udword p = *(udword*)inst->prefix;

					if (!(p & OP_EVEX_MASK))
					{
						if ((inst->mnemonic == VCVTPS2PD || inst->mnemonic == VCVTDQ2PD || inst->mnemonic == VCVTPH2PS
						|| inst->mnemonic == VCVTPS2PH || inst->mnemonic == VPSLLW || inst->mnemonic == VPSLLD
						|| inst->mnemonic == VPSLLQ || inst->mnemonic == VPSRLW || inst->mnemonic == VPSRLD
						|| inst->mnemonic == VPSRLQ || inst->mnemonic == VPSRAW || inst->mnemonic == VPSRAD
						|| inst->mnemonic == VBROADCASTSS || inst->mnemonic == VBROADCASTSD) && p & OS_QQWORD_MASK)
						{
							p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							p |= OS_DQWORD_MASK;
						}
					}
					else
					{
						if (p & OS_QQWORD_MASK && (inst->mnemonic == VCVTPS2PD || inst->mnemonic == VCVTPH2PS || inst->mnemonic == VCVTPS2PH
						|| inst->mnemonic == VCVTUDQ2PD || inst->mnemonic == VCVTPS2UQQ || inst->mnemonic == VCVTTPS2QQ
						|| inst->mnemonic == VCVTTPS2UQQ || inst->mnemonic == VPMOVSDW || inst->mnemonic == VPMOVUSDW
						|| inst->mnemonic == VPMOVQD || inst->mnemonic == VPMOVSQD || inst->mnemonic == VPMOVUSQD
						|| inst->mnemonic == VPMOVWB || inst->mnemonic == VPMOVSWB || inst->mnemonic == VPMOVUSWB
						|| inst->mnemonic == VCVTDQ2PD))
						{
							p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							p |= OS_DQWORD_MASK;
						}

						if (inst->mnemonic == VBROADCASTSD || inst->mnemonic == VBROADCASTF32X2 || inst->mnemonic == VBROADCASTSS)
						{
							p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							p |= OS_DQWORD_MASK;
						}

						// EVEX_L2_GET(inst->vexxop) == p & OS_DQQWORD_MASK
						if (EVEX_L2_GET(inst->vexxop) && (inst->mnemonic == VCVTPS2PD || inst->mnemonic == VCVTPH2PS || inst->mnemonic == VCVTPS2PH
						|| inst->mnemonic == VCVTUDQ2PD || inst->mnemonic == VCVTPS2UQQ || inst->mnemonic == VCVTTPS2QQ || inst->mnemonic == VCVTTPS2UQQ
						|| inst->mnemonic == VPMOVSDW || inst->mnemonic == VPMOVUSDW || inst->mnemonic == VPMOVQD || inst->mnemonic == VPMOVSQD || inst->mnemonic == VPMOVUSQD
						|| inst->mnemonic == VPMOVWB || inst->mnemonic == VPMOVSWB || inst->mnemonic == VPMOVUSWB || inst->mnemonic == VCVTDQ2PD))
						{
							p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							p |= OS_QQWORD_MASK;
						}
					}

					*dest = get_vector(modrm_rm, ot, p);
				}
				else
				{

					*dest = get_memory(ot, *(udword*)inst->prefix);

					if (inst->vexxop[0] == 0)
					{
						if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_64(inst->mnemonic, *(udword*)inst->prefix))
							*dest = AVL_OP_MEM64;
						else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_32(inst->mnemonic))
							*dest = AVL_OP_MEM32;
						else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_16(inst->mnemonic))
							*dest = AVL_OP_MEM16;
						else if (IS_OSMEMEXTENTED_EXCEPTION_NONVEC_8(inst->mnemonic))
							*dest = *(udword*)inst->prefix & RP_REXW_MASK ? AVL_OP_MEM64 : AVL_OP_MEM32;
					}
					else if (*(udword*)inst->prefix & OP_EVEX_MASK)
					{
						if (EVEX_L2_GET(inst->vexxop) && (inst->mnemonic == VCVTPS2PD || inst->mnemonic == VCVTUDQ2PD
						|| inst->mnemonic == VCVTDQ2PD || inst->mnemonic == VCVTPH2PS || inst->mnemonic == VCVTPS2UQQ
						|| inst->mnemonic == VCVTTPS2QQ || inst->mnemonic == VCVTTPS2UQQ))
							*dest = AVL_OP_MEM256;
						else if (EVEX_L_GET(inst->vexxop) && (inst->mnemonic == VCVTUDQ2PD || inst->mnemonic == VCVTDQ2PD
						|| inst->mnemonic == VCVTPH2PS || inst->mnemonic == VCVTPS2UQQ || inst->mnemonic == VCVTTPS2QQ
						|| inst->mnemonic == VCVTTPS2UQQ))	
							*dest = AVL_OP_MEM128;
						else if (EVEX_L2_GET(inst->vexxop) && (inst->mnemonic == VCVTPS2PD))
							*dest = AVL_OP_MEM128;
						else if (inst->mnemonic == VBROADCASTF32X4 || inst->mnemonic == VBROADCASTF64X2
						|| inst->mnemonic == VINSERTF32X4 || inst->mnemonic == VINSERTF64X2)
							*dest = AVL_OP_MEM128;
						else if (inst->mnemonic == VBROADCASTF32X8 || inst->mnemonic == VBROADCASTF64X4
						|| inst->mnemonic == VINSERTF32X8 || inst->mnemonic == VINSERTF64X4)
							*dest = AVL_OP_MEM256;
						else if ((inst->mnemonic == VCVTPH2PS || inst->mnemonic == VCVTUDQ2PD || inst->mnemonic == VCVTPS2UQQ
						|| inst->mnemonic == VCVTTPS2QQ  || inst->mnemonic == VCVTTPS2UQQ || inst->mnemonic == VCVTPS2PD
						|| inst->mnemonic == VCVTDQ2PD || inst->mnemonic == VMOVDDUP)
						&& !EVEX_L_GET(inst->vexxop) && !EVEX_L2_GET(inst->vexxop))
							*dest = AVL_OP_MEM64;
						else if ((inst->mnemonic == VCVTSD2USI || inst->mnemonic == VCVTTSD2USI || inst->mnemonic == VGETEXPSD
						|| inst->mnemonic == VGETMANTSD || inst->mnemonic == VRANGESD || inst->mnemonic == VRCP14SD
						|| inst->mnemonic == VREDUCESD || inst->mnemonic == VRNDSCALESD || inst->mnemonic == VRSQRT14SD
						|| inst->mnemonic == VSCALEFSD || inst->mnemonic == VADDSD || inst->mnemonic == VMULSD
						|| inst->mnemonic == VDIVSD || inst->mnemonic == VSQRTSD || inst->mnemonic == VMAXSD
						|| inst->mnemonic == VMINSD || inst->mnemonic == VCMPSD || inst->mnemonic == VCVTSD2SS
						|| inst->mnemonic == VFIXUPIMMSD || inst->mnemonic == VFPCLASSSD))
							*dest = AVL_OP_MEM64;
						else if ((inst->mnemonic == VCVTSS2USI || inst->mnemonic == VCVTTSS2USI || inst->mnemonic == VGETEXPSS
						|| inst->mnemonic == VGETMANTSS || inst->mnemonic == VRANGESS || inst->mnemonic == VRCP14SS
						|| inst->mnemonic == VREDUCESS || inst->mnemonic == VRNDSCALESS || inst->mnemonic == VRSQRT14SS
						|| inst->mnemonic == VSCALEFSS || inst->mnemonic == VADDSS || inst->mnemonic == VMULSS
						|| inst->mnemonic == VDIVSS || inst->mnemonic == VSQRTSS || inst->mnemonic == VMAXSS || inst->mnemonic == VMINSS
						|| inst->mnemonic == VCVTSS2SD || inst->mnemonic == VFIXUPIMMSS || inst->mnemonic == VFPCLASSSS))
							*dest = AVL_OP_MEM32;
				
						else if (inst->mnemonic == VPMOVDB || inst->mnemonic == VPMOVSDB || inst->mnemonic == VPMOVUSDB
						|| inst->mnemonic == VPMOVQW || inst->mnemonic == VPMOVSQW || inst->mnemonic == VPMOVUSQW)
						{
							if (EVEX_L2_GET(inst->vexxop))
								*dest = AVL_OP_MEM128;
							else if (EVEX_L_GET(inst->vexxop))
								*dest = AVL_OP_MEM64;
							else
								*dest = AVL_OP_MEM32;
						}
						else if (inst->mnemonic == VPMOVDW || inst->mnemonic == VPMOVSDW || inst->mnemonic == VPMOVUSDW
						|| inst->mnemonic == VPMOVQD || inst->mnemonic == VPMOVSQD || inst->mnemonic == VPMOVUSQD
						|| inst->mnemonic == VPMOVWB || inst->mnemonic == VPMOVSWB || inst->mnemonic == VPMOVUSWB)
						{
							if (EVEX_L2_GET(inst->vexxop))
								*dest = AVL_OP_MEM256;
							else if (EVEX_L_GET(inst->vexxop))
								*dest = AVL_OP_MEM128;
							else
								*dest = AVL_OP_MEM64;
						}
						else if (inst->mnemonic == VPMOVQB || inst->mnemonic == VPMOVSQB || inst->mnemonic == VPMOVUSQB)
						{
							if (EVEX_L2_GET(inst->vexxop))
								*dest = AVL_OP_MEM64;
							else if (EVEX_L_GET(inst->vexxop))
								*dest = AVL_OP_MEM32;
							else
								*dest = AVL_OP_MEM16;
						}
					}
					else
					{
						if (IS_VOSMEMEXTENTED_EXCEPTION_NONVEC_64(inst->mnemonic, *(udword*)inst->prefix))
							*dest = AVL_OP_MEM64;
						else if (IS_VOSMEMEXTENTED_EXCEPTION_NONVEC_32(inst->mnemonic))
							*dest = AVL_OP_MEM32;
						else if (0 /* 16 bit exception */)
							*dest = AVL_OP_MEM16;
						else if (0 /* 32 - 64 exception */)
							*dest = *(udword*)inst->prefix & RP_REXW_MASK ? AVL_OP_MEM64 : AVL_OP_MEM32;
					}
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
					*dest = get_memory(ot, *(udword*)inst->prefix);
                break ;
		}
	}
	else
	{
		if (ot == DRS_87)
			*dest = am - (DR_RAX - AVL_OP_STO);
		else if (am < DR_AH)
		{
			switch (ot)
			{
				case OR_8:
					// fall throught
				case DRS_8:
					*dest = gpr8[am - DR_RAX];
					break ;

				case OR_16:
					// fall throught
				case DRS_16:
					*dest = gpr16[am - DR_RAX];
					break ;

				case OR_32:
					// fall throught
				case DRS_32:
					if (*(udword*)inst->prefix & OS_WORD_MASK)
						*dest = gpr16[am - DR_RAX];
					else
						*dest = gpr32[am - DR_RAX];
					break ;

				case OR_64:
					// fall throught
				case DRS_64:
					if (*(udword*)inst->prefix & OS_WORD_MASK)
						*dest = gpr16[am - DR_RAX];
					else if (*(udword*)inst->prefix & OS_DWORD_MASK)
						*dest = gpr32[am - DR_RAX];
					else
						*dest = gpr64[am - DR_RAX];
					break ;

				case DRS_SEC:
					*dest = get_segment_register(am - DR_RAX);
					break ;
			}

			if (IS_AMBIGIOUS(ot))
			{
				if (*(udword*)inst->prefix & RP_REXB_MASK)
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

    DEBUG("REG IS: %d\n", *dest);
}

void	resolve_operands_v2(instruction_t* const dest, opfield_t instruction)
{
    ubyte skip;
    ubyte attr_index = 0x0;

    reg_t* const	regs[] = { &dest->reg1, &dest->reg2, &dest->reg3 };
    const byte		ams[] = {instruction.am1, instruction.am2, instruction.am3, instruction.am4 };
    const byte		ots[] = {instruction.ot1, instruction.ot2, instruction.ot3, instruction.ot4 };

    for (uqword i = 0 ; i < ARRLEN(regs) ; i++)
    {
		skip = 0x0;
        resolve_operand_v2(dest, regs[i], ams[attr_index], ots[attr_index], &skip);

        /* Addressing Mode H ((E)VEX.VVVV) is ignored for instructions with no (E)VEX prefix. */
        if (ams[attr_index] == AM_H && !((*(udword*)dest->prefix & OP_EVEX_MASK /*&& !IS_EVEX_AMH_EXCEPTION(dest)*/)|| (dest->vexxop[0] && !IS_VEX_AMH_EXCEPTION(dest))))
            i--;

        attr_index += skip + 0x1;
    }

	if (instruction.am4 == AM_L)
	{
		DEBUG("AM_L imm: %lX\n", (dest->immediate >> 0x4) & 0xF);
		dest->immediate = get_vector((dest->immediate >> 0x4) & 0xF, instruction.ot4, *(udword*)dest->prefix);
		DEBUG("FINAL IMM VALUE (am_l): %ld\n", dest->immediate);
	}
}
