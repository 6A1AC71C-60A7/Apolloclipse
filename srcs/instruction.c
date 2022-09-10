
#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>


// 1) Check for REX | [{66, f2, f3}], 0f
// 2) If multiple REX, {66, f2, f3} or 0f skip and ignore
// 3) If ((1)) check for opcode
// 4) Else check for prefixes
// 4.1) If multiple REPEATED prefixes, skip and ignore
// 5) Check for VEX
// 6) If VEX take another path (reused fcnt btw)
// 7) Else check for opcode
// 8) If opcode spefied (opcode): check modrm
// 7) If specified (modrm): check for SIB
// 8) If specified (modrm or SIB): check displacement.
// 9) If specified (opcode) : check immediate

// VEX PATH:
// 1) Check VEX
// 2) Check opcode
// 3) Check modrm
// 4) If specified (modrm): check for SIB
// 5) If specified (modrm or SIB): check displacement.
// 6) If specified (opcode) : check immediate

///NOTE: GPM stands for "Gereral Purpose Multiple"

#define IS_GPM_MANDATORY_PREFIX(x) ( \
	/*(x) == 0x66*/ \
	/*|| */ (x) == 0xF2 \
	|| (x) == 0xF3 \
)

#define IS_GPM_ESCAPE(x) ((x) == 0x0F)
#define IS_GPM_ESCAPE2_0x38(x) ((x) == 0x38)
#define IS_GPM_ESCAPE2_0x3A(x) ((x) == 0x3A)
#define IS_GPM_ESCAPE2(x) (IS_GPM_ESCAPE2_0x38(x) || IS_GPM_ESCAPE2_0x3A(x))
#define IS_REXBYTE(x) (((x) & 0b11110000) == 0b01000000)
#define VEX2BYTES_PREFIX 0xC5
#define VEX3BYTES_PREFIX 0xC4
#define IS_VEX_PREFIX(x) ((x) == VEX2BYTES_PREFIX || (x) == VEX3BYTES_PREFIX)
#define EVEXBYTES_PREFIX 0x62
#define IS_EVEX_PREFIX(x) ((x) == EVEXBYTES_PREFIX)
#define GET_MAP_INDEX(x) (((x) & 0x0F) + ((((x) & 0xF0) >> 0x4) * 0x10))
#define IS_OPMAP_INDEXING(x) ((x) == AMB)
#define IS_ESCAPE_FX87(x) ((x) >= 0xD8 && (x) <= 0xDF)

__always_inline
static void skip_duplicated(const ubyte** target, ubyte mask)
{
	for (const ubyte* pdup = *target ; (*pdup & mask) == (**target & mask) ; )
		(*target)++;
}

__always_inline
static void get_rex_prefix(udword* const dest, const ubyte** iraw)
{
	for (udword count = 0; count <= 3 ; count++)
	{
		if (**iraw & (1 << count))
			*dest |= RP_REXB_MASK << count;
	}
}

__always_inline
static void		get_legacy_prefixes(udword* const dest, const ubyte** iraw)
{
	udword	prefix_it;

#ifndef LP_STOP_IF_REPEATED
	udword	found;
#else
	udword	old;
#endif

	do
	{

#ifndef LP_STOP_IF_REPEATED
		found = 0;
#else
		old = *dest;
#endif
		prefix_it = 0;
		while (prefix_it < ARRLEN(lt_legacy_prefixes))
		{
			if (lt_legacy_prefixes[prefix_it] == **iraw)
			{
				*dest |= LP_LOCK_MASK << prefix_it;
				DEBUG("[DEBUG] FOUND PREFIX: %02X\n", **iraw);
#ifndef LP_STOP_IF_REPEATED
				found = 1;
				(*iraw)++;
				break ;
#endif
			}
			prefix_it++;
		}
#ifdef LP_STOP_IF_REPEATED
		(*iraw)++;
#endif
	}
#ifndef LP_STOP_IF_REPEATED
	while (found);
#else
	while (old != *dest);
#endif

	///TODO: FIRST OF ALL TO FIX THIS REMOVE THE F2 AND F3 PREFIXES LIKE IS HAS BEEN DONE WITH 66 AND 67
	DEBUG("[DEBUG][END] (**iraw)=[%02X] (%d) (%d)\n", **iraw, *dest & MP_0x66_MASK, *dest & MP_0xF2_MASK);

}

__always_inline
static err_t	err_handle_legacy_prefixes(const udword* const dest)
{
	err_t err = SUCCESS;
	ubyte matches;
	uword dest_shift;

	matches = 0;
	if (*dest & 0b00000111)
	{
		if (*dest & 0b00000001)
			matches++;
		if (*dest & 0b00000010)
			matches++;
		if (*dest & 0b00000100)
			matches++;
		
		if (matches > 1)
		{
			err = EINVOPCODE;
			goto end;
		}
	}

	matches = 0;
	dest_shift = *dest >> 3;
	if (dest_shift & 0xff)
	{
		for (udword i = 0 ; i <= 0b00001000 ; i++)
		{
			if (*dest & (1U << i))
				matches++;
		}

		if (matches > 1)
			err = EINVOPCODE;
	}

end:
	return err;
}

#define TEST_VEX_REX(rex, vexxop) ( \
	VEXXOP_##rex##_GET(vexxop) \
)

__always_inline
static void get_vex_prefixes(instruction_t* const inst, const ubyte** iraw)
{
	ubyte opp;

	udword* prefix = (udword*)inst->prefix;

	*(uword*)inst->vexxop = *((*(uword**)iraw)++);

	if (inst->vexxop[0] != 0xC5)
	{
		inst->vexxop[2] = *((*iraw)++);
		*prefix |= !TEST_VEX_REX(R, inst->vexxop) ? RP_REXR_MASK : 0x0;
		*prefix |= !TEST_VEX_REX(X, inst->vexxop) ? RP_REXX_MASK : 0x0;
		*prefix |= !TEST_VEX_REX(B, inst->vexxop) ? RP_REXB_MASK : 0x0;
		*prefix |= TEST_VEX_REX(WE, inst->vexxop) ? RP_REXW_MASK : 0x0;
		opp = VEXXOP_PP_GET(inst->vexxop);
	}
	else
	{
		*prefix |= !TEST_VEX_REX(R, inst->vexxop) ? RP_REXR_MASK : 0x0;
		opp = VEXXOP2_PP_GET(inst->vexxop);
	}

	switch (opp)
	{
		case 0x1:
			*prefix |= MP_0x66_MASK;
			break ;
		case 0x2:
			*prefix |= MP_0xF3_MASK;
			break ;
		case 0x3:
			*prefix |= MP_0xF2_MASK;
			break ;
	}

		/// debug
	DEBUG("OPP IS: %d\n", opp);
	if (*prefix & RP_REXR_MASK)
		DEBUG("-> VEX: HAS REX.R\n");
	if (*prefix & RP_REXB_MASK)
		DEBUG("-> VEX: HAS REX.B\n");
	if (*prefix & RP_REXX_MASK)
		DEBUG("-> VEX: HAS REX.X\n");
	if (*prefix & RP_REXW_MASK)
		DEBUG("-> VEX: HAS REX.W\n");
}

__always_inline
static void get_evex_prefixes(instruction_t* const inst, const ubyte** iraw)
{
	udword* prefix = (udword*)inst->prefix;

	(*iraw)++;
	*prefix |= OP_EVEX_MASK;

	*(uword*)inst->vexxop = *((*(uword**)iraw)++);
	inst->vexxop[2] = *((*iraw)++);

	*prefix |= !EVEX_R_GET(inst->vexxop) || !EVEX_R2_GET(inst->vexxop) ? RP_REXR_MASK : 0x0;
	*prefix |= !EVEX_X_GET(inst->vexxop) ? RP_REXX_MASK : 0x0;
	*prefix |= !EVEX_B_GET(inst->vexxop) ? RP_REXB_MASK : 0x0;
	*prefix |= EVEX_W_GET(inst->vexxop) ? RP_REXW_MASK : 0x0;

	switch (EVEX_P_GET(inst->vexxop))
	{
		case 0x1:
			*prefix |= MP_0x66_MASK;
			break ;
		case 0x2:
			*prefix |= MP_0xF3_MASK;
			break ;
		case 0x3:
			*prefix |= MP_0xF2_MASK;
			break ;
	}

	if (*prefix & RP_REXR_MASK)
		DEBUG("-> VEX: HAS REX.R\n");
	if (*prefix & RP_REXB_MASK)
		DEBUG("-> VEX: HAS REX.B\n");
	if (*prefix & RP_REXX_MASK)
		DEBUG("-> VEX: HAS REX.X\n");
	if (*prefix & RP_REXW_MASK)
		DEBUG("-> VEX: HAS REX.W\n");
}

__always_inline
static const opfield_t* get_map_vex(ubyte* const vex, ubyte isevex)
{
	/* If instruction is 2 bytes vec prefix, the map is always
		as it was prefixed with 0x0F */

	if (isevex == 0 && vex[2] == 0)
	{
		DEBUG("VEX: MAP 2BYTE\n");
		return lt_two_byte_opmap;
	}

	const ubyte mmmmm = isevex ? EVEX_MAP_GET(vex) : VEXXOP_MAP_SELECT_GET(vex);
	const opfield_t* map;

	DEBUG("VEX MAP SELECT FIELD IS: %d\n", mmmmm);

	switch (mmmmm)
	{
		case 0b01:
			DEBUG("VEX: MAP 2BYTE\n");
			map = lt_two_byte_opmap;
			break ;

		case 0b10:
			DEBUG("VEX: MAP 3BYTE (8)\n");
			map = lt_three_byte_0x38_opmap;
			break ;

		case 0b11:
			DEBUG("VEX: MAP 3BYTE (A)\n");
			map = lt_three_byte_0x3A_opmap;
			break ;
	}

	return map;
}

__always_inline
static const opfield_t*	get_map_legacy(instruction_t* const inst)
{
	const opfield_t* map;

	if (IS_GPM_ESCAPE(inst->opcode[0]))
	{
		map = lt_two_byte_opmap;
		if (IS_GPM_ESCAPE2_0x38(inst->opcode[1]))
		{
			DEBUG("DEBUG: IS 0x38 OPCODE MAP\n");
			map = lt_three_byte_0x38_opmap;
		}
		else if (IS_GPM_ESCAPE2_0x3A(inst->opcode[1]))
		{
			DEBUG("DEBUG: IS 0x3A OPCODE MAP\n");
			map = lt_three_byte_0x3A_opmap;
		}
		else
			DEBUG("DEBUG: IS TWO OPCODE MAP\n");
	}
	else
	{
		DEBUG("DEBUG: IS ONE OPCODE MAP\n");
		map = lt_one_byte_opmap;
	}

	return map;
}

static void		get_immediate(opfield_t opfield, instruction_t* const dest, const ubyte** iraw);

__always_inline
static opfield_t	handle_x87_instructions(instruction_t* const inst, const ubyte** iraw)
{
	const opfield_t*	map;
	uqword				map_index;
	opfield_t			found;

	inst->mod_rm = *((*iraw)++);

	DEBUG("DEBUG x87: MODRM IS 0x%02X\n", inst->mod_rm);

	/* Documentation's map starts at 0xC0 (fields from 0x0 to 0x0 are zeroed), so I've stripped those in mine */
	map_index = inst->mod_rm > 0xBF ? GET_MAP_INDEX(inst->mod_rm) - 0XC0 : MODRM_REG_GET(inst->mod_rm);

	switch (inst->opcode[2])
	{
		case 0xD8:
			map = inst->mod_rm > 0xBF ? lt_escape_0xD8_outside_modrm_opmap : lt_escape_0xD8_within_modrm_opmap;
			break ;

		case 0xD9:
			map = inst->mod_rm > 0xBF ? lt_escape_0xD9_outside_modrm_opmap : lt_escape_0xD9_within_modrm_opmap;
			break ;

		case 0xDA:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDA_outside_modrm_opmap : lt_escape_0xDA_within_modrm_opmap;
			break ;

		case 0xDB:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDB_outside_modrm_opmap : lt_escape_0xDB_within_modrm_opmap;
			break ;

		case 0xDC:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDC_outside_modrm_opmap : lt_escape_0xDC_within_modrm_opmap;
			break ;

		case 0xDD:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDD_outside_modrm_opmap : lt_escape_0xDD_within_modrm_opmap;
			break ;

		case 0xDE:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDE_outside_modrm_opmap : lt_escape_0xDE_within_modrm_opmap;
			break ;

		case 0xDF:
			map = inst->mod_rm > 0xBF ? lt_escape_0xDF_outside_modrm_opmap : lt_escape_0xDF_within_modrm_opmap;
			break ;
	}

	DEBUG("DEBUG x87: MAP INDEX: %"PRId64"\n", map_index);

	DEBUG("DEBUG x87: IS BIG MAP: %d\n", map == lt_escape_0xD9_outside_modrm_opmap);

	found = map[map_index];

	inst->mnemonic = found.mnemonic;

	DEBUG("DEBUG x87: MNEMONIC IS: %d\n", inst->mnemonic);

	return found;
}

__always_inline
static void handle_evex_addons_0x38_opmap(opfield_t* const found, ubyte opcode, udword prefix)
{
	if (prefix & MP_0xF3_MASK)
	{
		if (opcode == 0x3A)
			*found = (opfield_t){ .mnemonic = VPBROADCASTMW2D, .am1 = AM_V, .ot1 = AM_X, .am2 = AM_KRM,	.ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
		// else if (opcode == 0x2A)
		// 	*found = (opfield_t){ .mnemonic = VPBROADCASTMB2Q, .am1 = AM_V,	.ot1 = AM_X, .am2 = AM_KRM, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
		else
		{
			static const opfield_t arr[] = {
				{ .mnemonic = VPMOVUSWB,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSDB,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSQB,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSDW,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVUSQW,	.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
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
				{ .mnemonic = VPMOVSDB,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSQB,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSDW,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVSQW,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
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
				{ .mnemonic = VPMOVDB,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVQB,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVDW,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVQW,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVQD,		.am1 = AM_W,	.ot1 = OT_X,	.am2 = AM_V,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ /* 36 */ },
				{ /* 37 */ },
				{ .mnemonic = VPMOVM2D,		.am1 = AM_V,	.ot1 = OT_X,	.am2 = AM_KRM,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				{ .mnemonic = VPMOVD2M,		.am1 = AM_KR,	.ot1 = OT_X,	.am2 = AM_W,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },				
			};

			if (opcode >= 10 && opcode <= (ARRLEN(arr) + 0x10))
				*found = arr[opcode - 0x10];
		}
	}
}

__always_inline
static void handle_evex_addons_0x0F_opmap(opfield_t* const found, ubyte opcode, udword prefix)
{
	if (prefix & MP_0x66_MASK)
	{
		if (opcode == 0x72)
			*found = (opfield_t){ .mnemonic = VPROLD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
	}
	else if (prefix & MP_0xF3_MASK)
	{
		if (opcode == 0xE6)
			*found = (opfield_t){ .mnemonic = VCVTQQ2PD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
	}
	else if (!(prefix & MP_0xF2_MASK))
	{
		if (opcode == 0x79)
			*found = (opfield_t){ .mnemonic = VCVTPD2UDQ, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
		else if (opcode == 0x5B)
			*found = (opfield_t){ .mnemonic = VCVTQQ2PS, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
		else if (opcode == 0x78)
			*found = (opfield_t){ .mnemonic = VCVTTPD2UDQ, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
	}
}

__always_inline
static void handle_rare_prefixes_0x38_opmap(opfield_t* const found, ubyte opcode, udword prefix)
{
	const ubyte index = opcode & 0x0F;

	if (index == 4)
		goto ret;
	else if (index == 3)
		*found = (opfield_t){ .mnemonic = MODRM_EXT_GRP_17,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_1A };
	else if (prefix & MP_0x66_MASK && prefix & MP_0xF2_MASK)
	{
		if (index == 0)
			*found = (opfield_t){ .mnemonic = CRC32,	.am1 = AM_G,	.ot1 = OT_D,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
		else if (index == 1)
			*found = (opfield_t){ .mnemonic = CRC32,	.am1 = AM_G,	.ot1 = OT_D,	.am2 = AM_E,	.ot2 = OT_W,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
	}
	else if (prefix & MP_0xF2_MASK)
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

		*found = arr[index];
	}
	else if (prefix & MP_0xF3_MASK)
	{
		switch (index)
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
ret:
	return ;
}

__always_inline
static void handle_ambigious_instructions_0x0F_opmap(opfield_t* const found, ubyte opcode)
{
	switch (opcode)
	{
		case 0x41:
			// kand {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KAND, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x42:
			// kandn {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KANDN, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x44:
			// knot {k1: MODRM.REG, k2: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KNOT, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x45:
			// kor {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x46:
			// kxnor {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KXNOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x47:
			// kxor {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KXOR, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x4A:
			// kadd {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KADD, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x4B:
			// kunpck {k1: MODRM.REG, k2: VEX.VVVV, k3: MODRM.RM}{OP= 16:0x66,W0 ; 32:0x66:W1 ; 64:W1}
			///TODO: This operand size resolution is very UNIQUE
			*found = (opfield_t){ .mnemonic = KUNPCK, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KV, .ot2 = OT_ALL, .am3 = AM_KRM, .ot3 = OT_ALL, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x90:
			// kmov {k1: MODRM.REG, k2: if(MODRM.MOD==0b11)MODRM.RM else ADDR}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x91:
			// kmov {k1: ADDR, k2: MODRM.REG}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_M, .ot1 = OT_ALL, .am2 = AM_KR, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x92:
			// kmov {k1: MODRM.REG, k2: ADDR}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_R, .ot2 = OT_Y, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x93:
			// kmov {k1: ADDR, k2: MODRM.REG}{OP= 8:0x66,W0 ; 16:W0 ; 32:0x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KMOV, .am1 = AM_G, .ot1 = OT_Y, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x98:	
			// kortest {k1: MODRM.REG, k2: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KORTEST, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;

		case 0x99:
			// ktest {k1: MODRM.REG, k2: MODRM.RM}{OP= 8:0x66,W0 ; 16:W0 ; 320x66:W1 ; 64:W1}
			*found = (opfield_t){ .mnemonic = KTEST, .am1 = AM_KR, .ot1 = OT_ALL, .am2 = AM_KRM, .ot2 = OT_ALL, .am3 = 0, .ot3 = 0, .am4 = 0, .ot4 = 0, .symbol = 0 };
			break ;
	}
}

#define IS_EVEX_COLISION_0x0F(x, p) ( \
	(!((p) & (MP_0x66_MASK | MP_0xF2_MASK | MP_0xF3_MASK)) && (x) == 0x79) \
	|| ((p) & MP_0xF3_MASK && (x) == 0xE6) \
	|| (!((p) & (MP_0x66_MASK | MP_0xF2_MASK | MP_0xF3_MASK)) && (x) == 0x5B) \
	|| (!((p) & (MP_0x66_MASK | MP_0xF2_MASK | MP_0xF3_MASK)) && (x) == 0x78) \
	|| ((p) & MP_0x66_MASK && (x) == 0x72) \
)

__always_inline
static void redirect_indexing_opfield(const opfield_t* map, opfield_t* const found, udword prefix, ubyte opcode)
{
	uqword scale = 0;

	if (map == lt_two_byte_opmap)
	{
		const ubyte line = (opcode & 0xF0) >> 4;
	
		DEBUG("DEBUG: LINE: %d, HAS 0x66: %d\n", line, prefix & MP_0x66_MASK);

		if (prefix & MP_0x66_MASK && !(line >= 0x9 && line <= 0xB))
			scale = 1;
		if (prefix & MP_0xF3_MASK)
			scale = 2;
		if (prefix & MP_0xF2_MASK)
			scale = 3;

		DEBUG("--> INDEX IS %"PRId64"\n", found->mnemonic + (0x76 * scale));

		/* Prefix dependent instructions are aligned by 0x76 bytes */
		*found = lt_two_byte_ambigious_opmap[found->mnemonic + (0x76 * scale)];
	}
	else if (map == lt_three_byte_0x38_opmap)
	{
		if (prefix & (MP_0xF2_MASK | MP_0xF3_MASK))
		{
			if (opcode >= 0xF0 && opcode < 0xF8)
				handle_rare_prefixes_0x38_opmap(found, opcode, prefix);
			else if (prefix & OP_EVEX_MASK)
				handle_evex_addons_0x38_opmap(found, opcode, prefix);
		}
		else
		{
			if (prefix & MP_0x66_MASK)
			{
				scale = 1;
				if (prefix & OP_EVEX_MASK)
				{
					switch (opcode)
					{
						case 0x14:
							*found = (opfield_t){ .mnemonic = VPRORVD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							break ;

						case 0x15:
							*found = (opfield_t){ .mnemonic = VPROLVD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							break ;

						case 0x2C:
							*found = (opfield_t){ .mnemonic = VSCALEFPD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = 0 };
							break ;

						case 0x2D:
							*found = (opfield_t){ .mnemonic = VSCALEFSD, .am1 = AM_V, .ot1 = OT_DQ, .am2 = AM_H, .ot2 = OT_DQ, .am3 = AM_W, .ot3 = OT_DQ, .am4 = 0, .ot4 = 0, .symbol = 0 };
							break ;
					}
				}
			}
			if (found->am1 == 0 || found->am1 == AMB)
				*found = lt_three_byte_0x38_opmap[GET_MAP_INDEX(opcode) + (0x100 * scale)];
		}
	}
	else if (map == lt_three_byte_0x3A_opmap)
	{
		///TODO: Most of these instructions have prefixes,
		/// Most of them are not checked because there's only
		/// one ambigious instruction. I have to check them validation.

		if (opcode == 0x0F && prefix & MP_0x66_MASK)
			found->mnemonic = AMB_VPALIGNR_INDEX;
		*found = lt_tree_byte_0x3A_ambigious_opmap[found->mnemonic];

		///TODO: Handle ambigiousness otherway (create a single function)
		/// Temporary solution (cause i doesn't know the amount and all  kinds of ambigiousness)

		if (prefix & OP_EVEX_MASK)
		{
			switch (opcode)
			{
				case 0x8:
					*found = (opfield_t){ .mnemonic = VRNDSCALEPS, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0x9:
					*found = (opfield_t){ .mnemonic = VRNDSCALEPD, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_W, .ot2 = OT_X, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0xA:
					*found = (opfield_t){ .mnemonic = VRNDSCALESS, .am1 = AM_V, .ot1 = OT_DQ, .am2 = AM_W, .ot2 = OT_DQ, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0xB:
					*found = (opfield_t){ .mnemonic = VRNDSCALESD, .am1 = AM_V, .ot1 = OT_DQ, .am2 = AM_W, .ot2 = OT_DQ, .am3 = AM_I, .ot3 = OT_B, .am4 = 0, .ot4 = 0, .symbol = 0 };
					break ;

				case 0x10:
					*found = (opfield_t){ .mnemonic = VPSRLVW, .am1 = AM_V, .ot1 = OT_X, .am2 = AM_H, .ot2 = OT_X, .am3 = AM_W, .ot3 = OT_X, .am4 = 0, .ot4 = 0, .symbol = S_V };
					break ;
			}
		}
	}
	else
	{
		/// ERROR:
	}
}

#define HAS_ATTR_MODRM 0x1
#define HAS_ATTR_SIB (HAS_ATTR_MODRM << 1)
#define HAS_ATTR_MODRMDISP_8 (HAS_ATTR_SIB << 1)
#define HAS_ATTR_MODRMDISP_32 (HAS_ATTR_MODRMDISP_8 << 1)
#define HAS_ATTR_SIBDISP_8 (HAS_ATTR_MODRMDISP_32 << 1)
#define HAS_ATTR_SIBDISP_32 (HAS_ATTR_SIBDISP_8 << 1)
#define HAS_ATTR_IMMEDIATE (HAS_ATTR_SIBDISP_32 << 1)
#define HAS_ATTR_DISP(x) ( \
	(x) & HAS_ATTR_MODRMDISP_8 \
	|| (x) & HAS_ATTR_MODRMDISP_32 \
	|| (x) & HAS_ATTR_SIBDISP_8 \
	|| (x) & HAS_ATTR_SIBDISP_32 \
)
#define GET_DISP_LENGHT(x) ( \
	(x) & HAS_ATTR_MODRMDISP_8 || (x) & HAS_ATTR_SIBDISP_8 ? 0x8 : 0x20 \
)

#define HAS_MODRM(x) ( \
	(x) != 0 && ( \
		(x) == AM_C \
		|| (x) == AM_D \
		|| (x) == AM_E \
		|| (x) == AM_G \
		|| (x) == AM_M \
		|| (x) == AM_N \
		|| (x) == AM_P \
		|| (x) == AM_Q \
		|| (x) == AM_R \
		|| (x) == AM_S \
		|| (x) == AM_U \
		|| (x) == AM_V \
		|| (x) == AM_W \
		|| (x) == AM_KR \
		|| (x) == AM_KRM \
		|| (x) == AM_KM \
	) \
)

__always_inline
static ubyte	has_modrm(opfield_t opfield)
{
	return HAS_MODRM(opfield.am1) || HAS_MODRM(opfield.am2) || HAS_MODRM(opfield.am3) || HAS_MODRM(opfield.am4);
}

__always_inline
static ubyte	get_opcode_attributes(mnemonic_t* const mnemonic, opfield_t opfield)
{
	*mnemonic = opfield.mnemonic;

	ubyte opattr = 0;

	if (has_modrm(opfield))
		opattr |= HAS_ATTR_MODRM;

	return opattr;
}

//#define IS_RM_EXTENDED(rex_b, vexxop) ((rex_b) || (((vexxop)[0] == 0xC4 || (vexxop)[0] == 0x8F) && VEXXOP_B_GET(vexxop)))

__always_inline
static ubyte	get_modrm(instruction_t* const inst, const ubyte** iraw)
{
	///TODO: Redo define 'IS_ESCAPE_FX87'
	/* If is x87 instruction, the modR/M is already parsed */
	if (inst->vexxop[0] || inst->opcode[0] || !IS_ESCAPE_FX87(inst->opcode[2]))
		inst->mod_rm = *((*iraw)++);

	/* BYTE bits: { 0, 0, MOD[1], MOD[0], RM[3], RM[2], RM[1], RM[0] }
		(RM[3] is extended from REX.B/VEX.~B/XOP.~B */
	const ubyte rm =  MODRM_RM_EXTENDED_GET(inst);
	const ubyte index = (MODRM_MOD_GET(inst->mod_rm) << 0x4) | rm;

	DEBUG("DEBUG: MODRM INDEX IS %d\n", index);

	return lt_modrm_encoded[index];
}

__always_inline
static ubyte	get_sib(instruction_t* const inst, const ubyte** iraw)
{
	inst->sib = *((*iraw)++);

	const ubyte mod = MODRM_MOD_GET(inst->mod_rm);
	const ubyte index = SIB_INDEX_EXTENDED_GET(inst);
	const ubyte base = SIB_BASE_EXTENDED_GET(inst);

	/* WORD: bits: { 0, 0, 0, 0, 0, 0, MOD[1], MOD[0], INDEX[3], INDEX[2], INDEX[1], INDEX[0], BASE[3], BASE[2], BASE[1], BASE[0] }
		(INDEX[4] is extended from REX.X/VEX.~X/XOP.~X
		 BASE[4] is extended from REX.B/VEX.~B/XOP.~B) */
	const uword lt_index = ((uword)base | ((uword)index << 4) | ((uword)mod << 0x8)) & (uword)0b0000001111111111;

	return lt_sib_encoded[lt_index];
}

__always_inline
static void		get_displacement(udword* const dest, const ubyte** iraw, uqword nbits)
{
	DEBUG("GET DISPLACEMENT OF %lld BITS\n", (long long int)nbits);

	if (nbits == 0x8)
		*dest = *((*iraw)++);
	else
		*dest = *((*(udword**)iraw)++);
}

__always_inline
static void		handle_ambigious_arguments(opfield_t* const found, const opfield_t* map, instruction_t* const inst)
{
	const ubyte opcode = inst->opcode[2];
	const udword prefix = *(udword*)inst->prefix;

	///TODO: Preform (move) the ambigiousness handling in group extensions here ?
	/// MMM parse is a lot more complex, i don't think so (seems not worth)

	if (map == lt_one_byte_opmap)
	{
		if (opcode == 0x90)
		{
			if ((prefix & (MP_0x66_MASK | MP_0xF2_MASK | MP_0xF3_MASK)) == 0
			&& prefix & (RP_REXB_MASK | RP_REXW_MASK))
				*found = (opfield_t){ .mnemonic = XCHG,	.am1 = DR_R8,	.ot1 = DRS_64,	.am2 = DR_RAX,	.ot2 = DRS_64,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			else if (prefix & MP_0xF3_MASK)
				found->mnemonic = PAUSE;
		}	
	}
	else if (map == lt_three_byte_0x38_opmap)
	{
		if (prefix & MP_0x66_MASK && MODRM_MOD_GET(inst->mod_rm) != 0b11)
		{
			switch (opcode)
			{
				case 0x20:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x21:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x22:
					found->am2 = AM_M;
					found->ot2 = OT_W;
					break ;

				case 0x23:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x24:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x25:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x30:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x31:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x32:
					found->am2 = AM_M;
					found->ot2 = OT_W;
					break ;

				case 0x33:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;

				case 0x34:
					found->am2 = AM_M;
					found->ot2 = OT_D;
					break ;

				case 0x35:
					found->am2 = AM_M;
					found->ot2 = OT_Q;
					break ;
			}
		}
	}
	else if (map == lt_three_byte_0x3A_opmap)
	{
		if (prefix & MP_0x66_MASK && MODRM_MOD_GET(inst->mod_rm) != 0b11)
		{
			switch (opcode)
			{
				case 0x14:
					found->am1 = AM_M;
					found->ot1 = OT_B;
					break ;

				case 0x15:
					found->am1 = AM_M;
					found->ot1 = OT_W;
					break ;

				case 0x20:
					found->am3 = AM_M;
					found->ot3 = OT_B;
					break ;

				case 0x21:
					found->am3 = AM_M;
					found->ot2 = OT_D;
					break ;
			}
		}
	}
	else if (map == lt_two_byte_opmap)
	{
		if (MODRM_MOD_GET(inst->mod_rm) != 0b11)
		{
			if (prefix & MP_0x66_MASK)
			{
				if (opcode == 0xC4)
				{
					found->am2 = AM_M;
					found->ot2 = OT_W;
				}
			}
			else if ((prefix & (MP_0x66_MASK | MP_0xF3_MASK | MP_0xF2_MASK)) == 0)
			{
				switch (opcode)
				{
					case 0x12:
						found->mnemonic = VMOVHLPS;
						found->am3 = AM_U;
						break ;

					case 0x16:
						found->mnemonic = VMOVLHPS;
						found->am3 = AM_U;
						break ;

					case 0xC4:
						found->am3 = AM_M;
						found->ot3 = OT_W;
						break ;

					case 0x77:
						if (inst->vexxop[0])
						{
							if (MODRM_RM_EXTENDED_GET(inst) == 0)
								found->mnemonic = VZEROUPPER;
							else
								found->mnemonic = VZEROALL;
						}
				}
			}
		}
	}

	inst->mnemonic = found->mnemonic;
}

#define ISDFT64_CALL(x) (!(x)->opcode[0] && (x)->opcode[2] == 0xFF && (x)->mnemonic == CALL)
#define ISDFT64_JMP(x) (!(x)->opcode[0] && (x)->opcode[2] == 0xFF && (x)->mnemonic == JMP)
#define ISDFT64_LGTD(x) ((x)->mnemonic == LGDT)
#define ISDFT64_LIDT(x) ((x)->mnemonic == LIDT)
#define ISDFT64_LLTD(x) ((x)->mnemonic == LLDT)
#define ISDFT64_POP(x) (!(x)->opcode[0] && (((x)->opcode[2] >= 0x58 && (x)->opcode[2] <= 0x5F) || (x)->opcode[2] == 0x8F))
#define ISDFT64_PUSH(x) ((!(x)->opcode[0] && ((x)->opcode[2] == 0x50 || (x)->opcode[2] == 0x6A || (x)->opcode[2] == 0x68)))
#define ISDFT64_PREFETCHW(x) ((x)->mnemonic == PREFETCHW)
#define ISDFT64_MOVCRDR(x) ((x)->opcode[0] && !(x)->opcode[1] && (x)->opcode[2] >= 0x20 && (x)->opcode[2] <= 0x23)

static ubyte	is_mnemonic_default_64_bits(instruction_t* const inst)
{

	///TODO: Only CALL near JMP near and RET near ?!?!
	///TODO: Mnemonic must have specific operands to be in this list ?
	///TODO: Jcc, jrCXZ, LOOPcc, MOVcr, MOVdr, 

	///TODO: SELECT BY OPCODE
	return ISDFT64_CALL(inst) || ISDFT64_JMP(inst) || ISDFT64_LGTD(inst) || ISDFT64_LIDT(inst) || ISDFT64_LLTD(inst) || ISDFT64_POP(inst) || ISDFT64_PUSH(inst) || ISDFT64_PREFETCHW(inst) || ISDFT64_MOVCRDR(inst); /* mnemonic == CALL || mnemonic == ENTER || mnemonic == JMP || mnemonic == LEAVE
	|| mnemonic == LGDT || mnemonic == LIDT || mnemonic == LLDT || mnemonic == LOOP
	|| mnemonic == LTR || mnemonic == POP || mnemonic == POPF || mnemonic == PUSH
	|| mnemonic == PUSHF || mnemonic == RET; */
}

#define IS_ONE_BYTE_OPCODE_MAP(x) (*(uword*)(x) == 0x0)
#define IS_TWO_BYTE_OPCODE_MAP(x) (*(uword*)(x) == 0xF)
#define IS_WORD_OVERWRITABLE_TWOBYTES_OPMAP(x) (((x) >= 0x9 && (x) <= 0xC) || (x) == 0x0 || (x) == 0x4)
#define OS_RESET(x) ((x) &= ~(OS_BYTE_MASK | OS_WORD_MASK | OS_DWORD_MASK | OS_QWORD_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK | OS_DQQWORD_MASK))
#define IS_DEFAULT_REGISTER(x) ((x) >= 32)
#define IS_TWO_BYTE_NONVEX_SIMD(x) (((x) >= 0x1 && (x) <= 0x2) || ((x) >= 0x5 && (x) <= 0x7) || (x) >= 0xC)

#define IS_EXCEPTION_NONVEX_NONSIMD(x) ((x) == 0xC0 || (x) == 0xC1 || (x) == 0xC3 || (x) == 0xC7)
#define GET_ROW(x) (((x) >> 0x4) & 0xF)
#define GET_COLUMN(x) ((x) & 0xF)
#define IS_TWO_BYTE_NONVEX_SIMD_V2(x) !IS_EXCEPTION_NONVEX_NONSIMD(x) && ((GET_ROW(x) == 0x1 && GET_COLUMN(x) < 0x8) || GET_ROW(x) == 0x2 || (GET_ROW(x) >= 0x5 && GET_ROW(x) <= 0x7) || (GET_ROW(x) == 0xC && GET_COLUMN(x) < 0x8) || GET_ROW(x) > 0xC)

#define IS_0x38_NONVEX_SIMD(x) (/*!(GET_ROW(x) == 0x8 && GET_COLUMN(x) <= 0x8) && */ GET_ROW(x) != 0xF)

__always_inline
static void		get_operand_size(instruction_t* const dest, opfield_t* const found)
{
	(void)found;

	///TODO: REDO THIS WITHOUT TRIPLE RETURN 
	if (*(udword*)dest->prefix & OP_EVEX_MASK)
	{
		if (EVEX_L2_GET(dest->vexxop))
			*(udword*)dest->prefix |= OS_DQQWORD_MASK;
		else if (EVEX_L_GET(dest->vexxop))
			*(udword*)dest->prefix |= OS_QQWORD_MASK;
		else
			*(udword*)dest->prefix |= OS_DQWORD_MASK;
		return ;
	}
	else if (dest->vexxop[0])
	{
		const ubyte is256os = dest->vexxop[2] ? VEXXOP_L_GET(dest->vexxop) : VEXXOP2_L_GET(dest->vexxop);
		*(udword*)dest->prefix |= is256os ? OS_QQWORD_MASK : OS_DQWORD_MASK;
		return ;

		///TODO: if (IS_K*()) { handle k mnemonics operand size }
		/// SIZE RESOLUTION FOR THESE MUST BE PERFORMED OTHERWAY

		///TODO: SOME VEX TAKE GP REGISTERS AS ARGUMENTS,

		///TODO: For the future: if is EVEX the size also could be 512bits
	}
	else if ((dest->opcode[0] && !dest->opcode[1] && 
		/* IS_TWO_BYTE_NONVEX_SIMD((dest->opcode[2] >> 4) & 0xF)) */
		IS_TWO_BYTE_NONVEX_SIMD_V2(dest->opcode[2]))
		 || 
		 /*(dest->opcode[1] == 0x38 && ((((dest->opcode[2] >> 4) & 0xF) == 0x8 && (dest->opcode[2] & 0xF) >= 0x8) || ((dest->opcode[2] >> 4) & 0xF) < 0xF )) */
		(dest->opcode[1] == 0x38 && IS_0x38_NONVEX_SIMD(dest->opcode[2])))
	{
		DEBUG("[DEBUG] COND1: %d COND2: %d\n", (dest->opcode[0] && !dest->opcode[1]
			 && /* IS_TWO_BYTE_NONVEX_SIMD((dest->opcode[2] >> 4) & 0xF)) */
			IS_TWO_BYTE_NONVEX_SIMD_V2(dest->opcode[2]))
			, (dest->opcode[1] == 0x38 && IS_0x38_NONVEX_SIMD(dest->opcode[2])));
		*(udword*)dest->prefix |= OS_DQWORD_MASK;
		return ;
	}

	/* Operand size of first operand dictates the operand size of
		the whole instruction */

	udword* const prefix = (udword*)dest->prefix;
	//ubyte isreg = 0x0;

	/* Set to default operand size */

	if (is_mnemonic_default_64_bits(dest))
		*prefix |= OS_QWORD_MASK;
	// else if (IS_DEFAULT_REGISTER(found.am1))
	// {
	// 	isreg = 0x1;
	// 	if (found.ot1 == DRS_8 || found.ot1 == OR_8)
	// 		*prefix |= OS_BYTE_MASK;
	// 	else if (found.ot1 == DRS_16 || found.ot1 == OR_16)
	// 		*prefix |= OS_WORD_MASK;
	// 	///TODO: SEEMS NEXT ONE NEVER HAPPENS
	// 	else if (found.ot1 == DRS_128 || found.ot1 == OR_128)
	// 		*prefix |= OS_DQWORD_MASK;
	// 	///TODO: SEEMS NEXT ONE NEVER HAPPENS
	// 	else if (found.ot1 == DRS_256 || found.ot1 == OR_256)
	// 		*prefix |= OS_QQWORD_MASK;
	// 	else
	// 		*prefix |= OS_DWORD_MASK;
	// }
	else
		*prefix |= OS_DWORD_MASK;

	/* Overwrite with prefixes */

	// if (*prefix & OS_DWORD_MASK)
	// {
		if (*prefix & MP_0x66_MASK && !(dest->opcode[1] == 0x38 && ((dest->opcode[2] >> 4) & 0xF) == 0xF))
		{
			OS_RESET(*prefix);
			*prefix |= OS_WORD_MASK;
		}
		else if (*prefix & RP_REXW_MASK)
		{
			OS_RESET(*prefix);
			*prefix |= OS_QWORD_MASK;
		// }
	}

	// if (isreg == 0x0)
	// {
	// 	switch (found.ot1)
	// 	{
	// 		case OT_B:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_BYTE_MASK;
	// 			break ;

	// 		case OT_W:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_WORD_MASK;
	// 			break ;

	// 		case OT_D:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_DWORD_MASK;
	// 			break ;

	// 		case OT_Q:
	// 			OS_RESET(*prefix);
	// 			*prefix |= OS_QWORD_MASK;
	// 			break ;
	// 	}
	// }

	/* Exception in which the operand size must be WORD but
		is DWORD when the documentation is followed ... 
		OPERATION: mov WORD [], segment_register
		[ ONLY WHEN IS ADDRESSING ] */
	if (!dest->opcode[0] && dest->opcode[2] == 0x8C && (dest->mod_rm & 0b11000000) != 0b11000000)
	{
		OS_RESET(*prefix);
		*prefix |= OS_WORD_MASK;
	}
	/* More exceptions ... */
	else if (dest->mnemonic == CMPXCHG8B && *prefix & RP_REXW_MASK)
	{
		dest->mnemonic = CMPXCHG16B;
		OS_RESET(*prefix);
		*prefix |= OS_DQWORD_MASK;
		found->ot1 = OT_DQ;
	}
	else if (dest->mnemonic == UMONITOR && !(*prefix & LP_ADDRSZ_MASK))
	{
		OS_RESET(*prefix);
		*prefix |= OS_QWORD_MASK;
	}

	const char* __size;
	if (*prefix & OS_BYTE_MASK)
		__size = "BYTE";
	else if (*prefix & OS_WORD_MASK)
		__size = "WORD";
	else if (*prefix & OS_DWORD_MASK)
		__size = "DWORD";
	else if (*prefix & OS_QWORD_MASK)
		__size = "QWORD";
	else if (*prefix & OS_DQWORD_MASK)
		__size = "DQWORD";
	DEBUG("---------> Operand size is %s\n", __size);
}

#define HAS_IMMEDIATE(x) ( \
	(x) != 0 && (x) >= AM_I && (x) <= AM_L \
)

__always_inline
static ubyte	has_immediate(opfield_t opfield)
{
	return HAS_IMMEDIATE(opfield.am1) || HAS_IMMEDIATE(opfield.am2) || HAS_IMMEDIATE(opfield.am3) || HAS_IMMEDIATE(opfield.am4);
}

#define IS_OT_UNRANGED(x) ((x) != OT_C && (x) != OT_V && (x) != OT_Y  && (x) != (OT_Z))

__always_inline
static ubyte	get_immediate_operand_type(opfield_t opfield)
{
	ubyte ot = 0;

	if (HAS_IMMEDIATE(opfield.am1))
		ot = opfield.ot1;
	else if (HAS_IMMEDIATE(opfield.am2))
		ot = opfield.ot2;
	else if (HAS_IMMEDIATE(opfield.am3))
		ot = opfield.ot3;
	else if (HAS_IMMEDIATE(opfield.am4))
		ot = opfield.ot4;

	return ot;
}

__always_inline
static void		get_immediate(opfield_t opfield, instruction_t* const dest, const ubyte** iraw)
{
	const ubyte ot = get_immediate_operand_type(opfield);

	///TODO: Not 100% sure but i think if is AM_L the immediate value is always 8-bits.

	*(udword*)dest->prefix |= OP_IMMEDIATE_MASK;

	DEBUG("[DEBUG][OT OF IMMEDIATE]: %d\n", ot);

	switch (ot)
	{
		case OT_B:
			dest->immediate = *((*iraw)++);
			break ;

		case OT_W:
			dest->immediate = *((*(uword**)iraw)++);
			break ;

		case OT_D:
			dest->immediate = *((*(udword**)iraw)++);
			break ;

		case OT_Q:
			dest->immediate = *((*(uqword**)iraw)++);
			break ;

		default:
		{
			const udword prefix = *(udword*)dest->prefix;

			if (prefix & RP_REXW_MASK && IS_OT_UNRANGED(ot))
				dest->immediate = *((*(uqword**)iraw)++);
			else
			{
				switch (ot)
				{
					case OT_C:
						if ((prefix & OS_BYTE_MASK) != 0)
							dest->immediate = *((*(uword**)iraw)++);
						else
							dest->immediate = *((*iraw)++);
						break ;

					case OT_V:
							if (prefix & OS_WORD_MASK)
								dest->immediate = *((*(uword**)iraw)++);
							else if (prefix & OS_DWORD_MASK)
								dest->immediate = *((*(udword**)iraw)++);
							else if (prefix & OS_QWORD_MASK)
								dest->immediate = *((*(uqword**)iraw)++);
						break ;

					case OT_Y:
						if (prefix & OS_QWORD_MASK)
							dest->immediate = *((*(udword**)iraw)++);
						else
							dest->immediate = *((*(uqword**)iraw)++);
						break ;

					case OT_Z:
						if (prefix & OS_WORD_MASK)
							dest->immediate = *((*(uword**)iraw)++);
						else if ((prefix & (OS_BYTE_MASK | OS_DQWORD_MASK | OS_QQWORD_MASK)) == 0)
							dest->immediate = *((*(udword**)iraw)++);
						break ;
				}
			}
		}
	}

	if (dest->mnemonic == ENTER)
		dest->immediate |= (*((*iraw)++) << 0x10);
}

#define HAS_GROUP_EXTENTION(x) ((x == S_1A))

err_t	get_instruction_V2(instruction_t* const dest, const ubyte** iraw)
{
	err_t		st = SUCCESS;

	ubyte		isvex = 0x0;
	ubyte		skip_pref = 0x0;
	ubyte		isescape;
	ubyte		isrex;
	ubyte		opattr;

	const ubyte* const istart = *iraw;

	DEBUG("DEBUG: FIRST BYTE IS: %02X\n", **iraw);

opcode_check:

	///TODO: In some documentation i found that these are the 'SIMD prefixes'
	///READ: https://xem.github.io/minix86/manual/intel-x86-and-64-manual-vol2/o_b5573232dd8f1481-74.html
	/// And take more notes
	///TODO: IF OPCODE MAP 0X66 IS ONE BYTE OPCODE MAP 0X66 MEANS 16 BYTES OPERAND SIZE ...
	/// https://stackoverflow.com/questions/68289333/is-there-a-default-operand-size-in-the-x86-64-amd64-architecture
	
	// while (skip_pref == 0 && IS_GPM_MANDATORY_PREFIX(**iraw))
	// {
	// 	switch (**iraw)
	// 	{
	// 		// case 0x66:
	// 		// 	*(udword*)dest->prefix |= MP_0x66_MASK;
	// 		// 	break ;

	// 		// case 0x67:
	// 		// 	*(udword*)dest->prefix |= MP_0x67_MASK;
	// 		// 	break ;

	// 		///TODO: 0xF2 and 0xF3 are already parsed like is done with
	// 		/// 0x66 and 0x67 but i don't know if i'm fcking up
	// 		/// something by removing them form here.
	// 		/// Maybe thay need to be checked before REX ...
	// 		/// TODO: I must fix this, not have ambigious/repeated shit
	// 		///SOLUTION: Check legacy prefixes (legacy_prefixes) before REX

	// 		// case 0xF2:
	// 		// 	*(udword*)dest->prefix |= MP_0xF2_MASK;
	// 		// 	break ;

	// 		// case 0XF3:
	// 		// 	*(udword*)dest->prefix |= MP_0xF3_MASK;
	// 		// 	break ;
	// 	}
	// 	skip_duplicated(iraw, 0xFF);
	// }

	DEBUG("::::: BEFORE: %02X\n", **iraw);

	if ((isvex | isescape) == 0 && (isrex = IS_REXBYTE(**iraw)))
	{
		DEBUG("---> HAS REX BYTE <---\n");
		get_rex_prefix((udword*)dest->prefix, iraw);
		skip_duplicated(iraw, 0xF0);
	}

	DEBUG("::::: AFTER: %02X\n", **iraw);

	if (dest->opcode[0] == 0 && (isescape = IS_GPM_ESCAPE(**iraw)))
	{
		dest->opcode[0] = **iraw;
		(*iraw)++;

		if (IS_GPM_ESCAPE2(**iraw))
		{
			dest->opcode[1] = **iraw;
			(*iraw)++;
		}
	}

	///TODO: This is not an error for: mov WORD PTR [rsp + 880000], 42
	// else if (*(udword*)dest->prefix & (MP_0x66_MASK | MP_0xF2_MASK | MP_0xF3_MASK))
	// {
	// 	st = EINVOPCODE;
	// 	goto error;
	// }

	if (skip_pref)
		goto skip_prefix_check;

	if ((isescape & isrex) == 0x0 && !dest->opcode[0])
	{
		if ((isvex = IS_EVEX_PREFIX(**iraw)))
		{
			get_evex_prefixes(dest, iraw);
			DEBUG("DEBUG: EVEX: [62][%02X][%02X][%02X]\n", dest->vexxop[0], dest->vexxop[1], dest->vexxop[2]);
		}
		else if ((isvex = IS_VEX_PREFIX(**iraw)))
		{
			get_vex_prefixes(dest, iraw);
			DEBUG("DEBUG: VEX: [%02X][%02X][%02X]\n", dest->vexxop[0], dest->vexxop[1], dest->vexxop[2]);
		}
		else if (*(uword*)dest->opcode == 0x0)
		{
			get_legacy_prefixes((udword*)dest->prefix, iraw);

			///TODO: Useful error check but for instructions which have have 2 prefixes fails
			/// They're always exceptions ... (0f 38 F0)
			/// Opcode values isn't parsed yet so is difucult to know whether or not is an exception ...
			if (0 && (st = err_handle_legacy_prefixes((udword*)dest->prefix)) != SUCCESS)
				goto error;

			DEBUG("[DEBUG] PREFIX AFTER: %d\n", *(udword*)dest->prefix & MP_0xF2_MASK);
			DEBUG("[DEBUG] VALUE (**iraw) AFTER: %02X\n", **iraw);
		}		
	}

	if (isvex == 0x0)
	{
		skip_pref = 0x1;
		goto opcode_check;
	}

skip_prefix_check:

	dest->opcode[2] = *((*iraw)++);

	DEBUG("DEBUG: OPCODE IS [%02X][%02X][%02X]\n", dest->opcode[0], dest->opcode[1], dest->opcode[2]);

	opfield_t 			found = {};
	const opfield_t*	map = 0;

	if (dest->vexxop[0] == 0 && dest->opcode[0] == 0 && IS_ESCAPE_FX87(dest->opcode[2]))
		found = handle_x87_instructions(dest, iraw);
	else
	{
		map = !dest->vexxop[0] ? get_map_legacy(dest) : get_map_vex(dest->vexxop, (*(udword*)dest->prefix & OP_EVEX_MASK) != 0);

		///TODO: Improve syntax using more defines for conditions

		const ubyte line = (dest->opcode[2] & 0xF0) >> 4;
	
		/* This is because AVX-512 K instructions use the same opcode than other
			opcodes (within 0x0F opcode map) but a diferent prefix (VEX) */
		if (map == lt_two_byte_opmap && (line == 0x4 || line == 0x9) && dest->vexxop[0])
			handle_ambigious_instructions_0x0F_opmap(&found, dest->opcode[2]);
		/* This is because AVX-512 EVEX instructions use the same opcode than other
			opcodes without EVEX prefix (within 0x0F opcode map) */
		else if (map == lt_two_byte_opmap && *(udword*)dest->prefix & OP_EVEX_MASK && IS_EVEX_COLISION_0x0F(dest->opcode[2], *(udword*)dest->prefix))
			handle_evex_addons_0x0F_opmap(&found, dest->opcode[2], *(udword*)dest->prefix);
		else if (found.mnemonic == 0)
			found = map[GET_MAP_INDEX(dest->opcode[2])];

		DEBUG("DEBUG: MAP INDEX: %d\n", GET_MAP_INDEX(dest->opcode[2]));
		//DEBUG("DEBUG: MNEMONIC: %d\n", found.mnemonic);
		DEBUG("2 ADDR MODE: [%d] [%d]\n", found.am1, found.am2);
		DEBUG("2 OPERAND TYPE: [%d %d]\n", found.ot1, found.ot2);

		if (HAS_GROUP_EXTENTION(found.symbol))
		{
			DEBUG("HAS EXTENSION\n");
			found = get_instruction_by_extension_one_and_two_b_opmap(found.mnemonic, **iraw, *(udword*)dest->prefix, found);

			if (found.am1 == 0 || HAS_IMMEDIATE(found.am1))
				(*iraw)++;
		}

		if (IS_OPMAP_INDEXING(found.am1) || map == lt_three_byte_0x38_opmap)
		{
			DEBUG("IS INDEXING: %x\n", dest->opcode[2]);
			redirect_indexing_opfield(map, &found, *(udword*)dest->prefix, dest->opcode[2]);
		}
	}

	DEBUG("DEBUG: MNEMONIC: %d\n", found.mnemonic);

	opattr = get_opcode_attributes(&dest->mnemonic, found);

	if (opattr & HAS_ATTR_MODRM)
		opattr |= get_modrm(dest, iraw);
	DEBUG("OPATTR IS (no sib): %d\n", opattr);
	if (opattr & HAS_ATTR_SIB)
		opattr |= get_sib(dest, iraw);
	DEBUG("OPATTR IS (sib): %d\n", opattr);
	if (HAS_ATTR_DISP(opattr))
		get_displacement(&dest->displacement, iraw, GET_DISP_LENGHT(opattr));

	handle_ambigious_arguments(&found, map, dest);
	get_operand_size(dest, &found);

	if (has_immediate(found))
		get_immediate(found, dest, iraw);
	else
		DEBUG("DEBUG: HAS NOT IMMEDIATE\n");

	//resolve_operands(dest, found);
	resolve_operands_v2(dest, found);

	dest->size = *iraw - istart;

error:
	DEBUG("IRAW AT THE END: %02X\n", **iraw);

	return st;
}

void	get_instructions(instruction_t* const dest, uqword destlen, const ubyte** iraw)
{
	for (uqword i = 0 ; i < destlen ; i++)
		get_instruction_V2(&dest[i], iraw);
}







/// SUPORTED:
/// LEGACYPREFIX::= [ 0xF0 | 0xF2 | 0xF3] [0x64 | 0x65 | 0x2E | 0x3E ] [ 0x66 ] [ 0x67 ]
/// REXPREFIX::= 0b{0100}{W:1}{R:1}{X:1}{B:1}
/// VEXPREFIX::= 
/// PREFIX::=  ([LEGACYPREFIX] [REXPREFIX]) | ([LEGACYPREFIX] [VEXPREFIX])
/// OPCODEPREFIX::= (0x66 | 0xF2 | 0xF3) 0x0F [ 0x38 | 0x3A ]) | 0x0F [ 0x38 | 0x3A ]
/// OPCODE::= [OPCODEPREFIX] 0bXXXXXXXX
/// MODRM::= 0b{MOD:2}{REG:3}{RM:3}
/// SIB::= 0b{SCALE:2}{INDEX:3}{BASE:3}
/// DISPLACEMENT::= 8 | 32 bits
/// IMMEDIATE::= 8 | 16 | 32 | 64 bits
/// INSTRUCTION::= [PREFIX] OPCODE [MODRM] [SIB] [DISP] [IMM]
