
#include <d_portability.h>
#include <d_instruction.h>
#include <d_opcode.h>
#include <d_utils.h>

#include <user/register.h>

#include <user.h>

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
			if (AVL_OPSZ_IS_BYTE(flags))
				found = gpr8[index];
			else
				found = gpr16[index];
			break ;

		case OT_Y:
			//if (flags & (OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK))
			if (AVL_GET_OPERAND_SZ(flags) >= AVL_OPSZ_QWORD)
				found = gpr64[index];
			else
				found = gpr32[index];
			break ;

		case OT_Z:
			if (AVL_OPSZ_IS_WORD(flags))
				found = gpr16[index];
			else if (!AVL_OPSZ_IS_BYTE(flags))
				found = gpr32[index];
			break ;

		default:
		{
			if (AVL_OPSZ_IS_BYTE(flags))
				found = gpr8[index];
			else if (AVL_OPSZ_IS_WORD(flags))
				found = gpr16[index];
			else if (AVL_OPSZ_IS_DWORD(flags))
				found = gpr32[index];
			else/* if (prefix & OS_QWORD_MASK)*/
				found = gpr64[index];
		}
	}

	return found;
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
			if (AVL_OPSZ_IS_BYTE(flags))
				found = AVL_OP_MEM8;
			else
				found = AVL_OP_MEM16;
			break ;

		case OT_Y:
			//if (flags & (OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK))
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
			///TODO: Handle OT_P (and maybe more)

			///TODO: switch case for optimization
			if (AVL_OPSZ_IS_BYTE(flags))
				found = AVL_OP_MEM8;
			else if (AVL_OPSZ_IS_WORD(flags))
				found = AVL_OP_MEM16;
			else if (AVL_OPSZ_IS_DWORD(flags))
				found = AVL_OP_MEM32;
			else if (AVL_OPSZ_IS_QWORD(flags))
				found = AVL_OP_MEM64;
			else if (AVL_OPSZ_IS_DQWORD(flags))
				found = AVL_OP_MEM128;
			else if (AVL_OPSZ_IS_QQWORD(flags))
				found = AVL_OP_MEM256;
			else if (AVL_OPSZ_IS_DQQWORD(flags))
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

static reg_t	get_vector(uqword index, ubyte ot, udword flags)
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

		case OT_DQQ:
			found = get_zmm_register(index);
			break ;

		default:
		{
			if (AVL_OPSZ_IS_DQWORD(flags))
                found = get_xmm_register(index);
            else if (AVL_OPSZ_IS_QQWORD(flags))
                found = get_ymm_register(index);
            else if (AVL_OPSZ_IS_DQQWORD(flags))
                found = get_zmm_register(index);
		}
	}

	return found;
}

#define IS_AMBIGIOUS(x) ((x) >= OR_8 && (x) <= OR_512)

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
	/*|| ((x) == PSUBQ && !(p & AVL_MP_0x66_MASK))*/ \
	/*|| ((x) == PMULUDQ && !(p & AVL_MP_0x66_MASK))*/\
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
	|| ((x) == VCMPSS /*&& !((p) & AVL_RP_REXW_MASK)*/) \
	|| (x) == VCOMISS \
	|| (x) == VUCOMISS \
	|| (x) == VCVTSS2SI \
	|| (x) == VCVTTSS2SI \
	/*|| (x) == VCVTPS2PD*/ \
	|| (x) == VCVTSS2SD \
	|| (x) == VROUNDSS \
	|| (x) == VPGATHERDD \
	|| (x) == VPGATHERQD \
)

#define IS_VEX_AMH_EXCEPTION(x) ( \
	(((x)->i_opcode[2] == 0x10 || (x)->i_opcode [2]== 0x11) && ((x)->i_mnemonic == VMOVSS || (x)->i_mnemonic == VMOVSD) && AVL_GET_MODRM_MOD((x)->i_mod_rm) != 0b11) \
)

#define IS_EVEX_AMH_EXCEPTION(x) ( \
	(x)->i_mnemonic == VPGATHERDD \
	|| (x)->i_mnemonic == VPGATHERDQ \
	|| (x)->i_mnemonic == VPGATHERQD \
	|| (x)->i_mnemonic == VPGATHERQQ \
)

static void resolve_operand_v2(AVL_instruction_t* const inst, reg_t* const dest, ubyte am, ubyte ot, ubyte* const skip)
{
	DEBUG("[DEBUG] RESOLVE OPERAND: AM: %d OT: %d\n", am, ot);

    if (am == AM_ZERO)
		return ;

    /* ModR/M 'reg' field is extended by 1 bit by REX.R prefix or by VEX.~R.
        ModR/M 'rm' field is extended by 1 bit by REX.B prefix or by VEX.~B. */

    const ubyte modrm_mod = AVL_GET_MODRM_MOD(inst->i_mod_rm);
    const ubyte modrm_reg = AVL_GET_MODRM_REG(inst);
    ubyte modrm_rm = AVL_GET_MODRM_RM(inst);

    ubyte vex_vvvv;

    if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
        vex_vvvv = EVEX_VVVVV_EXTENDTED_GET(inst->i_vp);
    else
        vex_vvvv = (inst->i_vp[2] == 0 ? ~VEXXOP2_VVVV_GET(inst->i_vp) : ~VEXXOP_VVVV_GET(inst->i_vp)) & 0xF;

    DEBUG("MODRM BYTE: 0x%02X\n", inst->i_mod_rm);
    DEBUG("MODRM REG: %d\n", modrm_reg);
    DEBUG("MODRM RM: %d\n", modrm_rm);
    DEBUG("VEX VVVV is: %d\n", vex_vvvv);

    /// ABOVE SEEMS HANDLED IN 'MODRM_REG_EXTENDED_GET'
    // if (0 /* 3 bytes VEX opcode */)
    //     modrm_rm |= (((inst->prefix & RP_REXB_MASK)) << 3) | (~VEXXOP_B_GET(inst->vexxop) << 3);

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
				udword p = inst->i_flags;

				if ((inst->i_mnemonic == VCVTSI2SS || inst->i_mnemonic == MOVD || inst->i_mnemonic == VMOVD || inst->i_mnemonic == VCVTSI2SD || inst->i_mnemonic == VPINSRD || inst->i_mnemonic == VPEXTRD) && !AVL_HAS_REXW_PFX(p))
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);	
					// p |= OS_DWORD_MASK;
					AVL_SET_OPSZ(p, AVL_OPSZ_DWORD);
				}
				else if (AVL_HAS_OP_EVEX_PFX(p))
				{
					if (inst->i_mnemonic == VCVTUSI2SD || inst->i_mnemonic == VCVTUSI2SS)
					{
						// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						// p |= p & AVL_RP_REXW_MASK ? OS_QWORD_MASK : OS_DWORD_MASK;

						AVL_SET_OPSZ(p, AVL_HAS_REXW_PFX(p) ? AVL_OPSZ_QWORD : AVL_OPSZ_DWORD);
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
				udword p = inst->i_flags;

				if ((inst->i_mnemonic == VCVTSS2SI || inst->i_mnemonic == VCVTTSS2SI || inst->i_mnemonic == VPEXTRW || inst->i_mnemonic == VCVTSD2SI || inst->i_mnemonic == VCVTTSD2SI || inst->i_mnemonic == VMOVMSKPS || inst->i_mnemonic == VMOVMSKPD) && !(p & AVL_RP_REXW_MASK))
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					// p |= OS_DWORD_MASK;

					AVL_SET_OPSZ(p, AVL_OPSZ_DWORD);
				}

				*dest = get_general_purpose_register(modrm_reg, ot, p);
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
				udword p = inst->i_flags;

				if (inst->i_mnemonic == PINSRW)
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					// p |= OS_WORD_MASK;

					AVL_SET_OPSZ(p, AVL_OPSZ_WORD);
				}

				else if (inst->i_vp[0] && (inst->i_mnemonic == VMOVLPS || inst->i_mnemonic == VMOVHPS || inst->i_mnemonic == VMOVLPD || inst->i_mnemonic == VMOVHPD))
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					// p |= OS_QWORD_MASK;

					AVL_SET_OPSZ(p, AVL_OPSZ_QWORD);
				}

				else if (inst->i_vp[0] && (inst->i_mnemonic == VLDMXCSR || inst->i_mnemonic == VSTMXCSR))
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					// p |= OS_DWORD_MASK;

					AVL_SET_OPSZ(p, AVL_OPSZ_DWORD);
				}

				else if (AVL_HAS_OP_EVEX_PFX(inst->i_flags))
				{
					if (!EVEX_L_GET(inst->i_vp) && !EVEX_L2_GET(inst->i_vp) && inst->i_mnemonic == VSCATTERQPS)
					{
						// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						// p |= OS_QWORD_MASK;

						AVL_SET_OPSZ(p, AVL_OPSZ_QWORD);
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
					*dest = get_memory(ot, inst->i_flags);
				break ;

			case AM_R:
			{
				udword p = inst->i_flags;

				if (inst->i_mnemonic == PINSRW)
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					// p |= OS_WORD_MASK;

					AVL_SET_OPSZ(p, AVL_OPSZ_WORD);
				}
				else if (inst->i_mnemonic == VPINSRW && !AVL_HAS_REXW_PFX(p))
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					// p |= OS_DWORD_MASK;

					AVL_SET_OPSZ(p, AVL_OPSZ_DWORD);
				}

				*dest = get_general_purpose_register(modrm_rm, ot, p);
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
				udword p = inst->i_flags;

				if ((inst->i_mnemonic == VCVTPD2PS || inst->i_mnemonic == VCVTPD2DQ || inst->i_mnemonic == VCVTTPD2DQ
				|| inst->i_mnemonic == VPGATHERQD) && AVL_OPSZ_IS_QQWORD(p))
				{
					// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
					// p |= OS_DQWORD_MASK;

					AVL_SET_OPSZ(p, AVL_OPSZ_DQWORD);
				}
				else if (AVL_HAS_OP_EVEX_PFX(p))
				{
					if (EVEX_L_GET(inst->i_vp) && (inst->i_mnemonic == VCVTPD2UDQ || inst->i_mnemonic == VCVTTPD2UDQ || inst->i_mnemonic == VCVTUQQ2PS
					|| inst->i_mnemonic == VPSCATTERQD || inst->i_mnemonic == VSCATTERQPS || inst->i_mnemonic == VCVTQQ2PS))
					{
						// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						// p |= OS_DQWORD_MASK;

						AVL_SET_OPSZ(p, AVL_OPSZ_DQWORD);
					}
					else if (EVEX_L2_GET(inst->i_vp) && (inst->i_mnemonic == VCVTPD2PS || inst->i_mnemonic == VCVTPD2DQ || inst->i_mnemonic == VCVTTPD2DQ
					|| inst->i_mnemonic == VCVTPD2UDQ || inst->i_mnemonic == VCVTTPD2UDQ || inst->i_mnemonic == VCVTUQQ2PS || inst->i_mnemonic == VPSCATTERQD
					|| inst->i_mnemonic == VSCATTERQPS || inst->i_mnemonic == VCVTQQ2PS))
					{
						// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
						// p |= OS_QQWORD_MASK;

						AVL_SET_OPSZ(p, AVL_OPSZ_QQWORD);
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
					udword p = inst->i_flags;

					if (!AVL_HAS_OP_EVEX_PFX(p))
					{
						if ((inst->i_mnemonic == VCVTPS2PD || inst->i_mnemonic == VCVTDQ2PD || inst->i_mnemonic == VCVTPH2PS
						|| inst->i_mnemonic == VCVTPS2PH || inst->i_mnemonic == VPSLLW || inst->i_mnemonic == VPSLLD
						|| inst->i_mnemonic == VPSLLQ || inst->i_mnemonic == VPSRLW || inst->i_mnemonic == VPSRLD
						|| inst->i_mnemonic == VPSRLQ || inst->i_mnemonic == VPSRAW || inst->i_mnemonic == VPSRAD
						|| inst->i_mnemonic == VBROADCASTSS || inst->i_mnemonic == VBROADCASTSD) && AVL_OPSZ_IS_QQWORD(p))
						{
							// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							// p |= OS_DQWORD_MASK;

							AVL_SET_OPSZ(p, AVL_OPSZ_DQWORD);
						}
					}
					else
					{
						if (AVL_OPSZ_IS_QQWORD(p) && (inst->i_mnemonic == VCVTPS2PD || inst->i_mnemonic == VCVTPH2PS || inst->i_mnemonic == VCVTPS2PH
						|| inst->i_mnemonic == VCVTUDQ2PD || inst->i_mnemonic == VCVTPS2UQQ || inst->i_mnemonic == VCVTTPS2QQ
						|| inst->i_mnemonic == VCVTTPS2UQQ || inst->i_mnemonic == VPMOVSDW || inst->i_mnemonic == VPMOVUSDW
						|| inst->i_mnemonic == VPMOVQD || inst->i_mnemonic == VPMOVSQD || inst->i_mnemonic == VPMOVUSQD
						|| inst->i_mnemonic == VPMOVWB || inst->i_mnemonic == VPMOVSWB || inst->i_mnemonic == VPMOVUSWB
						|| inst->i_mnemonic == VCVTDQ2PD))
						{
							// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							// p |= OS_DQWORD_MASK;

							AVL_SET_OPSZ(p, AVL_OPSZ_DQWORD);
						}

						if (inst->i_mnemonic == VBROADCASTSD || inst->i_mnemonic == VBROADCASTF32X2 || inst->i_mnemonic == VBROADCASTSS)
						{
							// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							// p |= OS_DQWORD_MASK;

							AVL_SET_OPSZ(p, AVL_OPSZ_DQWORD);
						}

						// EVEX_L2_GET(inst->vexxop) == p & OS_DQQWORD_MASK
						if (EVEX_L2_GET(inst->i_vp) && (inst->i_mnemonic == VCVTPS2PD || inst->i_mnemonic == VCVTPH2PS || inst->i_mnemonic == VCVTPS2PH
						|| inst->i_mnemonic == VCVTUDQ2PD || inst->i_mnemonic == VCVTPS2UQQ || inst->i_mnemonic == VCVTTPS2QQ || inst->i_mnemonic == VCVTTPS2UQQ
						|| inst->i_mnemonic == VPMOVSDW || inst->i_mnemonic == VPMOVUSDW || inst->i_mnemonic == VPMOVQD || inst->i_mnemonic == VPMOVSQD || inst->i_mnemonic == VPMOVUSQD
						|| inst->i_mnemonic == VPMOVWB || inst->i_mnemonic == VPMOVSWB || inst->i_mnemonic == VPMOVUSWB || inst->i_mnemonic == VCVTDQ2PD))
						{
							// p &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK);
							// p |= OS_QQWORD_MASK;

							AVL_SET_OPSZ(p, AVL_OPSZ_QQWORD);
						}
					}

					*dest = get_vector(modrm_rm, ot, p);
				}
				else
				{

					*dest = get_memory(ot, inst->i_flags);

					if (inst->i_vp[0] == 0)
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
						if (EVEX_L2_GET(inst->i_vp) && (inst->i_mnemonic == VCVTPS2PD || inst->i_mnemonic == VCVTUDQ2PD
						|| inst->i_mnemonic == VCVTDQ2PD || inst->i_mnemonic == VCVTPH2PS || inst->i_mnemonic == VCVTPS2UQQ
						|| inst->i_mnemonic == VCVTTPS2QQ || inst->i_mnemonic == VCVTTPS2UQQ))
							*dest = AVL_OP_MEM256;
						else if (EVEX_L_GET(inst->i_vp) && (inst->i_mnemonic == VCVTUDQ2PD || inst->i_mnemonic == VCVTDQ2PD
						|| inst->i_mnemonic == VCVTPH2PS || inst->i_mnemonic == VCVTPS2UQQ || inst->i_mnemonic == VCVTTPS2QQ
						|| inst->i_mnemonic == VCVTTPS2UQQ))	
							*dest = AVL_OP_MEM128;
						else if (EVEX_L2_GET(inst->i_vp) && (inst->i_mnemonic == VCVTPS2PD))
							*dest = AVL_OP_MEM128;
						else if (inst->i_mnemonic == VBROADCASTF32X4 || inst->i_mnemonic == VBROADCASTF64X2
						|| inst->i_mnemonic == VINSERTF32X4 || inst->i_mnemonic == VINSERTF64X2)
							*dest = AVL_OP_MEM128;
						else if (inst->i_mnemonic == VBROADCASTF32X8 || inst->i_mnemonic == VBROADCASTF64X4
						|| inst->i_mnemonic == VINSERTF32X8 || inst->i_mnemonic == VINSERTF64X4)
							*dest = AVL_OP_MEM256;
						else if ((inst->i_mnemonic == VCVTPH2PS || inst->i_mnemonic == VCVTUDQ2PD || inst->i_mnemonic == VCVTPS2UQQ
						|| inst->i_mnemonic == VCVTTPS2QQ  || inst->i_mnemonic == VCVTTPS2UQQ || inst->i_mnemonic == VCVTPS2PD
						|| inst->i_mnemonic == VCVTDQ2PD || inst->i_mnemonic == VMOVDDUP)
						&& !EVEX_L_GET(inst->i_vp) && !EVEX_L2_GET(inst->i_vp))
							*dest = AVL_OP_MEM64;
						else if ((inst->i_mnemonic == VCVTSD2USI || inst->i_mnemonic == VCVTTSD2USI || inst->i_mnemonic == VGETEXPSD
						|| inst->i_mnemonic == VGETMANTSD || inst->i_mnemonic == VRANGESD || inst->i_mnemonic == VRCP14SD
						|| inst->i_mnemonic == VREDUCESD || inst->i_mnemonic == VRNDSCALESD || inst->i_mnemonic == VRSQRT14SD
						|| inst->i_mnemonic == VSCALEFSD || inst->i_mnemonic == VADDSD || inst->i_mnemonic == VMULSD
						|| inst->i_mnemonic == VDIVSD || inst->i_mnemonic == VSQRTSD || inst->i_mnemonic == VMAXSD
						|| inst->i_mnemonic == VMINSD || inst->i_mnemonic == VCMPSD || inst->i_mnemonic == VCVTSD2SS
						|| inst->i_mnemonic == VFIXUPIMMSD || inst->i_mnemonic == VFPCLASSSD))
							*dest = AVL_OP_MEM64;
						else if ((inst->i_mnemonic == VCVTSS2USI || inst->i_mnemonic == VCVTTSS2USI || inst->i_mnemonic == VGETEXPSS
						|| inst->i_mnemonic == VGETMANTSS || inst->i_mnemonic == VRANGESS || inst->i_mnemonic == VRCP14SS
						|| inst->i_mnemonic == VREDUCESS || inst->i_mnemonic == VRNDSCALESS || inst->i_mnemonic == VRSQRT14SS
						|| inst->i_mnemonic == VSCALEFSS || inst->i_mnemonic == VADDSS || inst->i_mnemonic == VMULSS
						|| inst->i_mnemonic == VDIVSS || inst->i_mnemonic == VSQRTSS || inst->i_mnemonic == VMAXSS || inst->i_mnemonic == VMINSS
						|| inst->i_mnemonic == VCVTSS2SD || inst->i_mnemonic == VFIXUPIMMSS || inst->i_mnemonic == VFPCLASSSS))
							*dest = AVL_OP_MEM32;
				
						else if (inst->i_mnemonic == VPMOVDB || inst->i_mnemonic == VPMOVSDB || inst->i_mnemonic == VPMOVUSDB
						|| inst->i_mnemonic == VPMOVQW || inst->i_mnemonic == VPMOVSQW || inst->i_mnemonic == VPMOVUSQW)
						{
							if (EVEX_L2_GET(inst->i_vp))
								*dest = AVL_OP_MEM128;
							else if (EVEX_L_GET(inst->i_vp))
								*dest = AVL_OP_MEM64;
							else
								*dest = AVL_OP_MEM32;
						}
						else if (inst->i_mnemonic == VPMOVDW || inst->i_mnemonic == VPMOVSDW || inst->i_mnemonic == VPMOVUSDW
						|| inst->i_mnemonic == VPMOVQD || inst->i_mnemonic == VPMOVSQD || inst->i_mnemonic == VPMOVUSQD
						|| inst->i_mnemonic == VPMOVWB || inst->i_mnemonic == VPMOVSWB || inst->i_mnemonic == VPMOVUSWB)
						{
							if (EVEX_L2_GET(inst->i_vp))
								*dest = AVL_OP_MEM256;
							else if (EVEX_L_GET(inst->i_vp))
								*dest = AVL_OP_MEM128;
							else
								*dest = AVL_OP_MEM64;
						}
						else if (inst->i_mnemonic == VPMOVQB || inst->i_mnemonic == VPMOVSQB || inst->i_mnemonic == VPMOVUSQB)
						{
							if (EVEX_L2_GET(inst->i_vp))
								*dest = AVL_OP_MEM64;
							else if (EVEX_L_GET(inst->i_vp))
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
						else if (0 /* 16 bit exception */)
							*dest = AVL_OP_MEM16;
						else if (0 /* 32 - 64 exception */)
							*dest = AVL_HAS_REXW_PFX(inst->i_flags) ? AVL_OP_MEM64 : AVL_OP_MEM32;
						else if (inst->i_mnemonic == VGATHERDPS)
							*dest = AVL_HAS_REXW_PFX(inst->i_flags) ? AVL_OP_MEM64 : AVL_OP_MEM32;
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
					if (AVL_OPSZ_IS_WORD(inst->i_flags))
						*dest = gpr16[am - DR_RAX];
					else
						*dest = gpr32[am - DR_RAX];
					break ;

				case OR_64:
					// fall throught
				case DRS_64:
					if (AVL_OPSZ_IS_WORD(inst->i_flags))
						*dest = gpr16[am - DR_RAX];
					else if (AVL_OPSZ_IS_DWORD(inst->i_flags))
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

    DEBUG("REG IS: %d\n", *dest);
}

void	resolve_operands_v2(AVL_instruction_t* const dest, opfield_t instruction)
{
    ubyte skip;
    ubyte attr_index = 0x0;

    reg_t* const	regs[] = { &dest->i_reg1, &dest->i_reg2, &dest->i_reg3 };
    const byte		ams[] = {instruction.am1, instruction.am2, instruction.am3, instruction.am4 };
    const byte		ots[] = {instruction.ot1, instruction.ot2, instruction.ot3, instruction.ot4 };

    for (uqword i = 0 ; i < ARRLEN(regs) ; i++)
    {
		skip = 0x0;
        resolve_operand_v2(dest, regs[i], ams[attr_index], ots[attr_index], &skip);

        /* Addressing Mode H ((E)VEX.VVVV) is ignored for instructions with no (E)VEX prefix. */
        if (ams[attr_index] == AM_H && !((AVL_HAS_OP_EVEX_PFX(dest->i_flags) /*&& !IS_EVEX_AMH_EXCEPTION(dest)*/)|| (dest->i_vp[0] && !IS_VEX_AMH_EXCEPTION(dest))))
            i--;

        attr_index += skip + 0x1;
    }

	if (instruction.am4 == AM_L)
	{
		DEBUG("AM_L imm: %lX\n", (dest->i_imm >> 0x4) & 0xF);
		dest->i_imm = get_vector((dest->i_imm >> 0x4) & 0xF, instruction.ot4, dest->i_flags);
		DEBUG("FINAL IMM VALUE (am_l): %ld\n", dest->i_imm);
	}
}
