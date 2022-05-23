
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

/**
 * @brief Get the legacy prefixes from the instruction raw
 * 
 * @param dest Where the prefixes are encoded in bitwise on return.
 * @param instruction_raw  Data to parse.
 * NOTE: Stops when none new prefix has been found if macro LP_STOP_IF_REPEATED is defined.
 */
__always_inline
static void		get_legacy_prefixes(udword* const dest, const ubyte** instruction_raw)
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
			if (lt_legacy_prefixes[prefix_it] == **instruction_raw)
			{
				*dest |= LP_LOCK_MASK << prefix_it;
#ifndef LP_STOP_IF_REPEATED
				found = 1;
				(*instruction_raw)++;
				break ;
#endif
			}
			prefix_it++;
		}
#ifdef LP_STOP_IF_REPEATED
		(*instruction_raw)++;
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

/**
 * @brief Get the rex prefix from the instruction raw
 * 
 * @param dest Where the prefixes are encoded in bitwise on return.
 * @param instruction_raw Data to parse.
 */
__always_inline
static void		get_rex_prefix(udword* const dest, const ubyte** instruction_raw)
{
	if ((**instruction_raw & 0b11110000) == 0b01000000)
	{
		for (udword count = 0; count <= 3 ; count++)
		{
			if (**instruction_raw & (1 << count))
				*dest |= RP_REXB_MASK << count;
		}
		(*instruction_raw)++;
	}	
}

__always_inline
static void		fill_inst_with_vexxop_3bytes(instruction_t* const inst, const ubyte* vexxop)
{
	register udword* prefix = (udword*)inst->prefix;
	const byte opp = VEXXOP_PP_GET(vexxop);

	inst->opcode[0] = VEXXOP_PREFIX_GET(vexxop);
	*prefix |= (VEXXOP_R_GET(vexxop) == ~0x1) ? RP_REXR_MASK : 0x0;
	*prefix |= (VEXXOP_X_GET(vexxop) == ~0x1) ? RP_REXX_MASK : 0x0;
	*prefix |= (VEXXOP_B_GET(vexxop) == ~0x1) ? RP_REXB_MASK : 0x0;
	*prefix |= (VEXXOP_WE_GET(vexxop) == ~0x1) ? RP_REXW_MASK : 0x0;
	///NOTE: The only one not stored is 'l' which is the operand size
	inst->operand_r = VEXXOP_VVVV_GET(vexxop);
	
	switch (opp)
	{
		case 0x1:
			inst->opcode[1] = 0x66;
			break ;
		case 0x2:
			inst->opcode[1] = 0xF3;
			break ;
		case 0x3:
			inst->opcode[1] = 0xF2;
			break ;
		default:
			inst->opcode[1] = 0x0;
	}
}

__always_inline
static void		fill_inst_with_vexxop_2bytes(instruction_t* const inst, const ubyte* vexxop)
{
	register udword* prefix = (udword*)inst->prefix;
	const byte opp = VEXXOP2_PP_GET(vexxop);

	inst->opcode[0] = VEXXOP_PREFIX_GET(vexxop);
	*prefix |= (VEXXOP_R_GET(vexxop) == ~0x1) ? RP_REXR_MASK : 0x0;

	///NOTE: The only one not stored is 'l' which is the operand size
	/// USE: VEXXOP2_L_GET(vexxop)
	inst->operand_r = VEXXOP2_VVVV_GET(vexxop);	

	switch (opp)
	{
		case 0x1:
			inst->opcode[1] = 0x66;
			break ;
		case 0x2:
			inst->opcode[1] = 0xF3;
			break ;
		case 0x3:
			inst->opcode[1] = 0xF2;
			break ;
		default:
			inst->opcode[1] = 0x0;
	}
}

#define IS_VEXXOP(x) (*(x) == 0xC4 || *(x) == 0xC5 || *(x) == 0x8F)

__always_inline
static err_t	get_vexxop_prefixes(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t st = EINVOPCODE;

	if (IS_VEXXOP(*instruction_raw))
	{
		inst->vexxop[0] = (*instruction_raw)[0];
		inst->vexxop[1] = (*instruction_raw)[1];
		if (inst->vexxop[0] != 0xC5)
		{
			inst->vexxop[2] = (*instruction_raw)[2];
			*instruction_raw += 3;
			fill_inst_with_vexxop_3bytes(inst, inst->vexxop);
		}
		else
		{
			*instruction_raw += 2;
			fill_inst_with_vexxop_2bytes(inst, inst->vexxop);
		}

		st = SUCCESS;
	}
	return st;
}

# define IS_3DNOW(x) (*(uword*)(x) == 0x0F0F)

__always_inline
static err_t	get_3dnow_prefixes(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t st = EINVOPCODE;

	if (IS_3DNOW(*instruction_raw))
	{
		inst->opcode[0] = 0x0F;
		inst->opcode[1] = 0x0F;
		*instruction_raw += 2;
		st = SUCCESS;
	}
	return st;
}

/**
 * @brief Get the prefixes from the instruction
 * 
 * @param dest Where the prefixes are encoded in bitwise on return.
 * @param instruction_raw Data to parse.
 * @return SUCCESS (0) if all the found legacy prefixes are from diferent families.
 */
err_t			get_instruction_prefixes(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t st = SUCCESS;

	if (get_vexxop_prefixes(inst, instruction_raw) != SUCCESS)
	{
		get_legacy_prefixes((udword*)inst->prefix, instruction_raw);
		get_rex_prefix((udword*)inst->prefix, instruction_raw);
		st = err_handle_legacy_prefixes((udword*)inst->prefix);
	}
	return st;
}
