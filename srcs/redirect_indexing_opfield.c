
#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

__always_inline
void handle_evex_addons_0x38_opmap(opfield_t* const found, ubyte opcode, udword flags)
{
	if (AVL_HAS_MP_0xF3_PFX(flags))
	{
		if (opcode == 0x3A)
			*found = (opfield_t){ .mnemonic = VPBROADCASTMW2D, .am1 = AM_V, .ot1 = AM_X, .am2 = AM_KRM,	.ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
		else
		{
			static const opfield_t arr[] = {
				{ .mnemonic = VPMOVUSWB,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSDB,	.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSQB,	.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSDW,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSQW,	.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSQD,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ /* 16 */ },
				{ /* 17 */ },
				{ /* 18 */ },
				{ /* 19 */ },
				{ /* 1A */ },
				{ /* 1B */ },
				{ /* 1C */ },
				{ /* 1D */ },
				{ /* 1E */ },
				{ /* 1F */ },
				{ .mnemonic = VPMOVSWB,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSDB,		.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSQB,		.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSDW,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSQW,		.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSQD,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPTESTNMB,	.am1 = AM_KR,	.ot1 = OT_X,	.am2 = AM_H,	.ot2 = OT_X,	.am3 = AM_W,	.ot3 = OT_X,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPTESTNMD,	.am1 = AM_KR,	.ot1 = OT_X,	.am2 = AM_H,	.ot2 = OT_X,	.am3 = AM_W,	.ot3 = OT_X,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVM2B,		.am1 = AM_V,	.ot1 = OT_X,	.am2 = AM_KRM,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVB2M,		.am1 = AM_KR,	.ot1 = OT_X,	.am2 = AM_W,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPBROADCASTMB2Q, .am1 = AM_V,	.ot1 = AM_X,	.am2 = AM_KRM,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ /* 2B */ },
				{ /* 2C */ },
				{ /* 2D */ },
				{ /* 2E */ },
				{ /* 2F */ },
				{ .mnemonic = VPMOVWB,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVDB,		.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVQB,		.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVDW,		.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVQW,		.am1 = AM_W,	.ot1 = OT_DQ,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVQD,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ /* 36 */ },
				{ /* 37 */ },
				{ .mnemonic = VPMOVM2D,		.am1 = AM_V,	.ot1 = OT_X,	.am2 = AM_KRM,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVD2M,		.am1 = AM_KR,	.ot1 = OT_X,	.am2 = AM_W,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },				
			};

			if (TESTRANGE(opcode, 0xA, (ARRLEN(arr) + 0x10)))
				*found = arr[opcode - 0x10];

			if (AVL_HAS_REXW_PFX(flags))
			{
				switch (found->mnemonic)
				{
					case VPMOVM2B:
						found->mnemonic = VPMOVM2W;
						break ;

					case VPMOVM2D:
						found->mnemonic = VPMOVM2Q;
						break ;

					case VPTESTNMB:
						found->mnemonic = VPTESTNMW;
						break ;

					case VPTESTNMD:
						found->mnemonic = VPTESTNMQ;
						break ;

					case VPMOVB2M:
						found->mnemonic = VPMOVW2M;
						break ;

					case VPMOVD2M:
						found->mnemonic = VPMOVQ2M;
						break ;
				}
			}
		}
	}
}

__always_inline
void handle_rare_prefixes_0x38_opmap(opfield_t* const found, ubyte opcode, udword flags)
{
	const ubyte column = GET_COLUMN(opcode);

	if (column == 4)
		return ;
	else if (column == 3)
		*found = (opfield_t){ .mnemonic = MODRM_EXT_GRP_17,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1A };
	else if (AVL_HAS_MP_0x66_PFX(flags) && AVL_HAS_MP_0xF2_PFX(flags))
	{
		if (column == 0)
			*found = (opfield_t){ .mnemonic = CRC32,	.am1 = AM_G,	.ot1 = OT_D,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
		else if (column == 1)
			*found = (opfield_t){ .mnemonic = CRC32,	.am1 = AM_G,	.ot1 = OT_D,	.am2 = AM_E,	.ot2 = OT_W,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
	}
	else if (AVL_HAS_MP_0xF2_PFX(flags))
	{
		static const opfield_t arr[] = {
			{ .mnemonic = CRC32,	.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
			{ .mnemonic = CRC32,	.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
			{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
			{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
			{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
			{ .mnemonic = PDEP,		.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_B,	.ot2 = OT_Y,	.am3 = AM_E,	.ot3 = OT_Y,	.am4 = 0,		.ot4 = 0,		.symbol = S_V },
			{ .mnemonic = MULX,		.am1 = AM_B,	.ot1 = OT_Y,	.am2 = AM_G,	.ot2 = OT_Y,	.am3 = DR_RDX,	.ot3 = DRS_64,	.am4 = AM_E,	.ot4 = OT_Y	,	.symbol = S_V },
			{ .mnemonic = SHRX,		.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = AM_B,	.ot3 = OT_Y,	.am4 = 0,		.ot4 = 0,		.symbol = S_V }
		};

		*found = arr[column];
	}
	else if (AVL_HAS_MP_0xF3_PFX(flags))
	{
		switch (column)
		{
			case 0x5:
				*found = (opfield_t){ .mnemonic = PEXT,	.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_V };
				break ;

			case 0x6:
				*found = (opfield_t){ .mnemonic = ADOX,	.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				break ;

			case 0x7:
				*found = (opfield_t){ .mnemonic = SARX,	.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_B,	.ot2 = OT_Y,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_V };
				break ;
		}
	}
}
