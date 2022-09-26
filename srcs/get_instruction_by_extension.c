
#include <d_opcode.h>
#include <d_mnemonic.h>
#include <d_instruction.h>

#define HAS_NOT_MANDATORY_PREFIX(x) (((x) & (AVL_MP_0x66_MASK | AVL_MP_0xF2_MASK | AVL_MP_0xF3_MASK)) == 0)

opfield_t	get_instruction_by_extension_one_and_two_b_opmap(ubyte group, opfield_t found, ubyte modrm, udword flags)
{
	const ubyte mod = AVL_GET_MODRM_MOD(modrm);
	const ubyte reg = __AVL_GET_MODRM_REG_BASE(modrm);
	const ubyte rm = __AVL_GET_MODRM_RM_BASE(modrm);
	opfield_t	inst = {};
	ubyte		overwrite = 0x0;

	switch (group)
	{
		case 0x1:
		{
			static const opfield_t arr[] = {
				{ .mnemonic = ADD,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = OR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = ADC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = SBB,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = AND,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = SUB,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = XOR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = CMP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
			};
			inst = arr[reg];
			overwrite = 0x1;
			break ;
		}

		case 0x1A:

			if (!reg)
					///TODO: SEEMS TO ALSO HAVE S_D64 symbol
				inst = (opfield_t){ .mnemonic = POP,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1A };
			break ;

		case 0x2:
		{
			static const opfield_t arr[] = {
				{ .mnemonic = ROL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = ROR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = RCL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = RCR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = SHL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = SHR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ },
				{ .mnemonic = SAR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
			};
			inst = arr[reg];
			overwrite = 0x1;
			break ;
		}

		case 0x3:
		{
			static const opfield_t arr[] = {
				{ .mnemonic = TEST,	.am1 = 0,	.ot1 = 0,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ },
				{ .mnemonic = NOT,	.am1 = 0,	.ot1 = 0,	.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = NEG,	.am1 = 0,	.ot1 = 0,	.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = MUL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = IMUL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = DIV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = IDIV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
			};
			inst = arr[reg];
			inst.am1 = found.am1;
			inst.ot1 = found.ot1;

			if (inst.ot1 != OT_B && reg == 0b000)
					inst.ot2 = OT_Z;
			break ;
		}

		case 0x4:
		{
			if (reg < 0b010)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = INC,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = DEC,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;
		}

		case 0x5:
			if (reg < 0b111)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = INC,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = DEC,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = CALL,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_F64 },
					{ .mnemonic = CALL,	.am1 = AM_E,	.ot1 = OT_P,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = JMP,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_F64 },
					{ .mnemonic = JMP,	.am1 = AM_M,	.ot1 = OT_P,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = PUSH,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_D64 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x6:
			if (reg < 0b110)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = SLDT,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = STR,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = LLDT,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = LTR,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = VERR,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = VERW,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];

				if (mod != 0b011)
				{
					if (reg == 0b000)
						inst = (opfield_t){ .mnemonic = SLDT,	.am1 = AM_W,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
					else if (reg == 0b001)
						inst = (opfield_t){ .mnemonic = STR,	.am1 = AM_W,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				}
			}
			break ;

		case 0x7:
		{
			if (mod == 0b11)
			{
				switch (reg)
				{
					case 0b000:
					{
						static const opfield_t arr[] = {
							{ },
							{ .mnemonic = VMCALL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = VMLAUNCH,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = VMRESUME,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = VMXOFF,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
						};
						inst = arr[rm];
						break ;
					}
					case 0b001:
					{
						static const opfield_t arr[] = {
							{ .mnemonic = MONITOR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = MWAIT,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = CLAC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = STAC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							///TODO: ENCLS (I'VE BUILT THE OPTION INSTEAD OF THE MNEMONIC)
							{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						};
						inst = arr[rm];
						break ;
					}
					case 0b010:
					{
						static const opfield_t arr[] = {
							{ .mnemonic = XGETBV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = XSETBV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ },
							{ },
							{ .mnemonic = VMFUNC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = XEND,		.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = XTEST,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							///TODO: MNEMONIC ENCLU NOT PRESENT
							{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
						};
						inst = arr[rm];
						break ;
					}
					case 0b100:
						if (mod == 0b011)
							inst = (opfield_t){ .mnemonic = SMSW,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
						else
							inst = (opfield_t){ .mnemonic = SMSW,	.am1 = AM_M,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
						break ;

					case 0b101:
						if (mod == 0b011)
							inst = (opfield_t){ .mnemonic = WRPKRU,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
						break ;

					case 0b110:
						inst = (opfield_t){ .mnemonic = LMSW,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
						break ;

					case 0b111:
						if (rm == 0b000)
							inst = (opfield_t){ .mnemonic = SWAPGS,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_O64 };
						else if (rm == 0b001)
							inst = (opfield_t){ .mnemonic = RDTSCP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				}
			}
			else
			{
				static const opfield_t arr[] = {
					{ .mnemonic = SGDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = SIDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = LGDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = LIDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = SMSW,		.am1 = AM_M,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ },
					{ .mnemonic = LMSW,		.am1 = AM_M,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = INVLPG,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}

			if (reg == 0b100 && mod == 0b011)
					inst = (opfield_t){ .mnemonic = SMSW,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			break ;
		}

		case 0x8:
		{
			static const opfield_t arr[] = {
				{ },
				{ },
				{ },
				{ },
				{ .mnemonic = BT,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = BTS,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = BTR,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = BTC,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
			};
			inst = arr[reg];
			overwrite = 0x1;
			break ;
		}

		case 0x9:
			if (mod == 0b011)
			{
				if (reg == 0b110)
					inst = (opfield_t){ .mnemonic = RDRAND,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				else if (reg == 0b111)
				{
					if (AVL_HAS_MP_0xF3_PFX(flags))
						inst = (opfield_t){ .mnemonic = RDPID,	.am1 = AM_R,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
					else
						inst = (opfield_t){ .mnemonic = RDSEED,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				}
			}
			else
			{
				///TODO: For srstor, xrstors, xsave, xsavec, xsaves:
				/// Create a new operand type (OT) which is just memory from some size
				/// AVL_OP_MEMUNKNOWN per exemple
				/// For the moment OT_S is used just to make work the output (but in the end is not a good solution)

				if (HAS_NOT_MANDATORY_PREFIX(flags))
				{
					static const opfield_t arr[] = {
						{ },
						{ .mnemonic = CMPXCHG8B,	.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = XRSTORS,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = XSAVEC,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = XSAVES,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = VMPTRLD,		.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = VMPTRST,		.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];				
				}
				else if (AVL_HAS_MP_0x66_PFX(flags) && reg == 0b110)
					inst = (opfield_t){ .mnemonic = VMCLEAR,	.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				else if (AVL_HAS_MP_0xF3_PFX(flags) && reg == 0b110)
					inst = (opfield_t){ .mnemonic = VMXON,		.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			}
			break ;

		case 0x10:
			/// TODO: UD1 ( HANDLE IT ? )
			break ;

		case 0x11:
			if (found.ot1 == OT_B)
			{
				if (reg == 0b000)
					inst = (opfield_t){ .mnemonic = MOV,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				else if (reg == 0b111 && rm == 0b000)
					inst = (opfield_t){ .mnemonic = XABORT,	.am1 = AM_I,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			}
			else
			{
				if (reg == 0b000)
					inst = (opfield_t){ .mnemonic = MOV,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				else if (reg == 0b111 && rm == 0b000)
					///NOTE: Have changed OT_Z to OT_D to make it work (differs from Intel's manual)
					inst = (opfield_t){ .mnemonic = XBEGIN,	.am1 = AM_J,	.ot1 = OT_D,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			}
			break ;

		case 0x12:
			if (reg < 0b111)
			{
				if (HAS_NOT_MANDATORY_PREFIX(flags))
				{
					static const opfield_t arr[] = {
						{ },
						{ },
						{ .mnemonic = PSRLW,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = PSRAW,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = PSLLW,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
				else if (AVL_HAS_MP_0x66_PFX(flags))
				{
					static const opfield_t arr[] = {
						{ },
						{ },
						{ .mnemonic = VPSRLW,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = VPSRAW,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = VPSLLW,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			break ;

		case 0x13:
			if (reg < 0b111)
			{
				if (HAS_NOT_MANDATORY_PREFIX(flags))
				{
					static const opfield_t arr[] = {
						{ },
						{ },
						{ .mnemonic = PSRLD,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = PSRAD,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = PSLLD,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
				else if (AVL_HAS_MP_0x66_PFX(flags))
				{
					static const opfield_t arr[] = {
						{ .mnemonic = VPRORD,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = VPROLD,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = VPSRLD,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = VPSRAD,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ },
						{ .mnemonic = VPSLLD,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];

					if (AVL_HAS_REXW_PFX(flags))
					{
						if (inst.mnemonic == VPSRAD)
							inst.mnemonic = VPSRAQ;
						else if (inst.mnemonic == VPROLD)
							inst.mnemonic = VPROLQ;
						else if (inst.mnemonic == VPRORD)
							inst.mnemonic = VPRORQ;
					}
				}
			}
			break ;

		case 0x14:
			if (HAS_NOT_MANDATORY_PREFIX(flags) && reg < 0b111)
			{
				static const opfield_t arr[] = {
					{ },
					{ },
					{ .mnemonic = PSRLQ,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ },
					{ },
					{ },
					{ .mnemonic = PSLLQ,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			else if (AVL_HAS_MP_0x66_PFX(flags))
			{
				static const opfield_t arr[] = {
					{ },
					{ },
					{ .mnemonic = VPSRLQ,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = VPSRLDQ,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ },
					{ },
					{ .mnemonic = VPSLLQ,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = VPSLLDQ,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x15:
			if (mod == 0b11)
			{
				if (HAS_NOT_MANDATORY_PREFIX(flags))
				{
					if (reg == 0b0101)
						inst = (opfield_t){ .mnemonic = LFENCE,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C };
					else if (reg == 0b110)
						inst = (opfield_t){ .mnemonic = MFENCE,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C };
					else if (reg == 0b111)
						inst = (opfield_t){ .mnemonic = SFENCE,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C };
				}
				else if (AVL_HAS_MP_0xF3_PFX(flags))
				{
					static const opfield_t arr[] = {
						{ .mnemonic = RDFSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ .mnemonic = RDGSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ .mnemonic = WRFSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ .mnemonic = WRGSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ },
						{ },
						{ .mnemonic = UMONITOR,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ }
					};
					inst = arr[reg];
				}
			}
			else if (HAS_NOT_MANDATORY_PREFIX(flags))
			{

				///TODO: Temporally fixup of addressing size of fxsacve and fxrsor using OT_S
			
				static const opfield_t arr[] = {
					{ .mnemonic = FXSAVE,	.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
					{ .mnemonic = FXRSTOR,	.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
					{ .mnemonic = VLDMXCSR,	.am1 = AM_M,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
					{ .mnemonic = VSTMXCSR,	.am1 = AM_M,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
					{ .mnemonic = XSAVE,	.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
					{ .mnemonic = XRSTOR,	.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
					{ .mnemonic = XSAVEOPT,	.am1 = AM_M,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
					{ .mnemonic = CLFLUSH,	.am1 = AM_M,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C }
				};
				inst = arr[reg];
			}
			break ;

		case 0x16:
			if (HAS_NOT_MANDATORY_PREFIX(flags))
			{
				if (mod == 0b11)
					inst = (opfield_t){ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				else
				{
					static const opfield_t arr[] = {
						{ .mnemonic = PREFETCHTNTA,	.am1 = AM_M,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ .mnemonic = PREFETCHT0,	.am1 = AM_M,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ .mnemonic = PREFETCHT1,	.am1 = AM_M,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ .mnemonic = PREFETCHT2,	.am1 = AM_M,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1C },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			break ;

		case 0x17:
			if (HAS_NOT_MANDATORY_PREFIX(flags) && reg < 0b100)
			{
				static const opfield_t arr[] = {
					{ },
					{ .mnemonic = BLSR,		.am1 = AM_B,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = S_V },
					{ .mnemonic = BLSMSK,	.am1 = AM_B,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = S_V },
					{ .mnemonic = BLSI,		.am1 = AM_B,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = S_V }
				};
				inst = arr[reg];
			}
			break ;
	}

	if (overwrite)
	{
		const mnemonic_t mn = inst.mnemonic;
		inst = found;
		inst.mnemonic = mn;
	}

	return inst;
}
