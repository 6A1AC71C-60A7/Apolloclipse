
#include <d_portability.h>
#include <d_instruction.h>
#include <d_register.h>
#include <d_opcode.h>

static reg_t	get_general_purpose_register(uqword index)
{
	static const reg_t regs[] = {
		D_REG_RAX, D_REG_RCX, D_REG_RDX, D_REG_RBX,
		D_REG_RSP, D_REG_RBP, D_REG_RSI, D_REG_RDI,
		D_REG_R8,  D_REG_R9,  D_REG_R10, D_REG_R11,
		D_REG_R12, D_REG_R13, D_REG_R14, D_REG_R15
	};

	return regs[index];
}

// static reg_t get_x87_register(uqword index)
// {
//     static const reg_t regs[] = {
//         D_REG_ST0, D_REG_ST1, D_REG_ST2, D_REG_ST3,
//         D_REG_ST4, D_REG_ST5, D_REG_ST6, D_REG_ST7
//     };

//     return regs[index];
// }

static reg_t get_mmx_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_MMX0, D_REG_MMX1, D_REG_MMX2, D_REG_MMX3,
        D_REG_MMX4, D_REG_MMX5, D_REG_MMX6, D_REG_MMX7,
        D_REG_MMX0B, D_REG_MMX1B, D_REG_MMX2B, D_REG_MMX3B,
        D_REG_MMX4B, D_REG_MMX5B, D_REG_MMX6B, D_REG_MMX7B
    };

    return regs[index];
}

static reg_t get_xmm_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_XMM0, D_REG_XMM1, D_REG_XMM2, D_REG_XMM3,
        D_REG_XMM4, D_REG_XMM5, D_REG_XMM6, D_REG_XMM7,
        D_REG_XMM8, D_REG_XMM9, D_REG_XMM10, D_REG_XMM11,
        D_REG_XMM12, D_REG_XMM13, D_REG_XMM14, D_REG_XMM15
    };

    return regs[index];
}

static reg_t get_ymm_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_YMM0, D_REG_YMM1, D_REG_YMM2, D_REG_YMM3,
        D_REG_YMM4, D_REG_YMM5, D_REG_YMM6, D_REG_YMM7,
        D_REG_YMM8, D_REG_YMM9, D_REG_YMM10, D_REG_YMM11,
        D_REG_YMM12, D_REG_YMM13, D_REG_YMM14, D_REG_YMM15
    };

    return regs[index];
}

static reg_t get_segmemt_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_ES, D_REG_CS, D_REG_SS, D_REG_DS,
        D_REG_FS, D_REG_GS, 0, 0,
        D_REG_ESB, D_REG_CSB, D_REG_SSB, D_REG_DSB,
        D_REG_FSB, D_REG_GSB
    };

    return regs[index];
}

static reg_t get_control_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_CR0, D_REG_CR1, D_REG_CR2, D_REG_CR3,
        D_REG_CR4, D_REG_CR5, D_REG_CR6, D_REG_CR7,
        D_REG_CR8, D_REG_CR9, D_REG_CR10, D_REG_CR11,
        D_REG_CR12, D_REG_CR13, D_REG_CR14, D_REG_CR15
    };

    return regs[index];
}

static reg_t get_debug_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_DR0, D_REG_DR1, D_REG_DR2, D_REG_DR3,
        D_REG_DR4, D_REG_DR5, D_REG_DR6, D_REG_DR7,
        D_REG_DR8, D_REG_DR9, D_REG_DR10, D_REG_DR11,
        D_REG_DR12, D_REG_DR13, D_REG_DR14, D_REG_DR15
    };

    return regs[index];
}

static void revolve_operand(instruction_t* const inst, reg_t* const dest, ubyte am, ubyte ot)
{
    if (am == AM_ZERO)
		return ;

    /* ModR/M 'reg' field is extended by 1 bit by REX.R prefix or by VEX.~R.
        ModR/M 'rm' field is extended by 1 bit by REX.B prefix or by VEX.~B. */

    const ubyte modrm_mod = MODRM_MOD_GET(inst->mod_rm);
    const ubyte modrm_reg = MODRM_REG_GET(inst->mod_rm) | (((*(udword*)inst->prefix & RP_REXR_MASK)) << 3) | (~VEXXOP_R_GET(inst->vexxop) << 3);
    ubyte modrm_rm = MODRM_RM_GET(inst->mod_rm);
    const ubyte vex_vvvv = 0 /* Is 2 byte vex */ ? ~VEXXOP2_VVVV_GET(inst->vexxop) : ~VEXXOP_VVVV_GET(inst->vexxop);

    if (0 /* 3 bytes VEX opcode */)
        modrm_rm |= (((*(udword*)inst->prefix & RP_REXB_MASK)) << 3) | (~VEXXOP_B_GET(inst->vexxop) << 3);

    if (am < DR_RAX)
    {
        switch (am)
        {
            case AM_B:
                *dest = get_general_purpose_register(vex_vvvv);
                break ;

            case AM_C:
                *dest = get_control_register(modrm_reg);
                break ;

            case AM_D:
                *dest = get_debug_register(modrm_reg);
                break ;
            
            case AM_E:
                *dest = modrm_mod == 0b11 ? get_general_purpose_register(modrm_rm) : D_REG_ADDR;
                break ;

            case AM_F:
                *dest = D_REG_RFLAGS;
                break ;

            case AM_G:
                *dest = get_general_purpose_register(modrm_reg);
                break ;

            case AM_H:
                if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                    *dest = get_xmm_register(vex_vvvv);
                else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                    *dest = get_ymm_register(vex_vvvv);
                break ;

            case AM_L:
                if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                    *dest = get_xmm_register(inst->immediate & 0xF);
                else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                    *dest = get_ymm_register(inst->immediate & 0xF);
                break ;

            case AM_M:
                *dest = D_REG_ADDR;
                break ;

            case AM_N:
                *dest = get_mmx_register(modrm_rm);
                break ;

            case AM_O:
                ///TODO: WTF
                break ;

            case AM_P:
                *dest = get_mmx_register(modrm_reg);
                break ;

            case AM_Q:
                ///TODO: NOT TESTED YET IF IS MODRM.RM
                *dest = modrm_mod == 0b11 ? get_mmx_register(modrm_rm) : D_REG_ADDR;
                break ;

            case AM_R:
                *dest = get_general_purpose_register(modrm_rm);
                break ;

            case AM_S:
                *dest = get_segmemt_register(modrm_reg);
                break ;

            case AM_U:
                if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                    *dest = get_xmm_register(modrm_rm);
                else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                    *dest = get_ymm_register(modrm_rm);
                break ;

            case AM_V:
                if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                    *dest = get_xmm_register(modrm_reg);
                else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                    *dest = get_ymm_register(modrm_reg);
                break ;

            case AM_W:
                ///TODO: NOT TESTED YET IF IS MODRM.RM
                if (modrm_mod == 0b11)
                {
                    ///TODO: 
                    if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                        *dest = get_xmm_register(modrm_rm);
                    else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                        *dest = get_ymm_register(modrm_rm);
                }
                else
                    *dest = D_REG_ADDR;
                break ;

            case AM_X:
                ///TODO: Memory addressed by DS:RSI register pairs
                break ;

            case AM_Y:
                ///TODO: Memory addressed by ES:RDI register pairs
                break ;
        }
    }
	else
	{
		if (ot == DRS_87)
			*dest = am - 14;
		else if (am < DR_AH)
		{
			///TODO: For the moment i only handle general purpose registers but i have to hadle all

			*dest = am - 30;
		}
		else
		{
			switch (am)
			{
				case DR_AH:
					*dest = D_REG_AH;
					break ;

				case DR_CH:
					*dest = D_REG_CH;
					break ;

				case DR_DH:
					*dest = D_REG_DH;
					break ;

				case DR_BH:
					*dest = D_REG_BH;
					break ;
			}
		}
	}

    DEBUG("REG IS: %d\n", *dest);
}

__always_inline
void	resolve_operands(instruction_t* const dest, opfield_t instruction)
{
	revolve_operand(dest, &dest->reg1, instruction.am1, instruction.ot1);
	revolve_operand(dest, &dest->reg2, instruction.am2, instruction.ot2);
	revolve_operand(dest, &dest->reg3, instruction.am3, instruction.ot3);
}
