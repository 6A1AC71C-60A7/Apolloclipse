
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
	(x) == 0x66 \
	|| (x) == 0xF2 \
	|| (x) == 0xF3 \
)
#define IS_GPM_ESCAPE(x) ((x) == 0x0F)
#define IS_GPM_ESCAPE2(x) ((x) == 0x38 || (x) == 0x3A)
#define IS_REXBYTE(x) (((x) & 0b11110000) == 0b01000000)
#define VEX2BYTES_PREFIX 0xC5
#define VEX3BYTES_PREFIX 0xC4
#define IS_VEX_PREFIX(x) ((x) == VEX2BYTES_PREFIX || (x) == VEX3BYTES_PREFIX)
#define GET_MAP_INDEX(x) ((x) & 0x0F * (((x) & 0xF0) >> 0x4))

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
		for (udword i = 0 ; i <= 0b10000000 ; i++)
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

__always_inline
static opfield_t*	get_map()
{
	///TODO:
	return 0;
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
	(x) == HAS_ATTR_MODRMDISP_8 || (x) == HAS_ATTR_SIBDISP_8 ? 0x8 : 0x20 \
)

__always_inline
static ubyte	get_opcode_attributes(mnemonic_t* const mnemonic, opfield_t opfield)
{
	*mnemonic = opfield.mnemonic;

	///TODO:
	return 0;
}

__always_inline
static ubyte	get_modrm(ubyte* const dest, const ubyte** iraw)
{
	*dest = *((*iraw)++);

	///TODO: Check for disps (already done in test version) & ret
	return 0;
}

__always_inline
static ubyte	get_sib(ubyte* const dest, const ubyte** iraw)
{
	*dest = *((*iraw)++);

	///TODO: Check for disps (already done in test version) & ret
	return 0;
}

__always_inline
static void		get_displacement(udword* const dest, const ubyte** iraw, uqword nbytes)
{
	if (nbytes == 0x8)
		*dest = *((*iraw)++);
	else
		*dest = *((*(udword**)iraw)++);
}

__always_inline
static void		get_immediate(instruction_t* const dest, const ubyte** iraw)
{
	///TODO:
	(void)dest;
	(void)iraw;
}

err_t	get_instruction_V2(instruction_t* const dest, const ubyte** iraw)
{
	err_t		st = SUCCESS;

	ubyte		isvex = 0x0;
	ubyte		ismandatory = 0x0;
	ubyte		skip_pref = 0x0;
	ubyte		isescape;
	ubyte		isrex;
	opfield_t*	map;
	ubyte		opattr;

opcode_check:

	if (IS_GPM_MANDATORY_PREFIX(**iraw))
	{
		ismandatory = 0x1;
		skip_duplicated(iraw, 0xFF);
	}

	if ((isescape = IS_GPM_ESCAPE(**iraw)))
	{
		dest->opcode[0] = **iraw;
		(*iraw)++;

		if (IS_GPM_ESCAPE2(**iraw))
		{
			dest->opcode[1] = **iraw;
			(*iraw)++;
		}
	}
	else if (ismandatory)
	{
		st = EINVOPCODE;
		goto error;
	}

	if ((isrex = IS_REXBYTE(**iraw)))
	{
		get_rex_prefix((udword*)dest->prefix, iraw);
		skip_duplicated(iraw, 0xF0);
	}

	if (skip_pref)
		goto skip_prefix_check;

	if ((isescape & isrex) == 0x0)
	{
		if ((isvex = IS_VEX_PREFIX(**iraw)))
		{
			///TODO:
			// get vex prefix
		}
		else
		{
			get_legacy_prefixes((udword*)dest->prefix, iraw);
			if ((st = err_handle_legacy_prefixes((udword*)dest->prefix)) != SUCCESS)
				goto error;
		}		
	}

	if (isvex == 0x0)
	{
		skip_pref = 0x1;
		goto opcode_check;
	}

skip_prefix_check:

	dest->opcode[2] = *((*iraw)++);

	///TODO:
	map = get_map();

	opattr = get_opcode_attributes(&dest->mnemonic, map[GET_MAP_INDEX(dest->opcode[2])]);

	if (opattr & HAS_ATTR_MODRM)
		opattr |= get_modrm(&dest->mod_rm, iraw);
	if (opattr & HAS_ATTR_SIB)
		opattr |= get_sib(&dest->sib, iraw);
	if (HAS_ATTR_DISP(opattr))
		get_displacement(&dest->displacement, iraw, GET_DISP_LENGHT(opattr));
	if (opattr & HAS_ATTR_IMMEDIATE)
		get_immediate(dest, iraw);

error:
	return st;
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
