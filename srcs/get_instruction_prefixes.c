
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>
#include <d_error.h>

/**
 * @brief Get the lagacy prefixes from the instruction raw
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

/**
 * @brief Get the prefixes from the instruction
 * 
 * @param dest Where the prefixes are encoded in bitwise on return.
 * @param instruction_raw Data to parse.
 * @return SUCCESS (0) if all the found legacy prefixes are from diferent families.
 */
err_t			get_instruction_prefixes(udword* const dest, const ubyte** instruction_raw)
{
	get_legacy_prefixes(dest, instruction_raw);
	get_rex_prefix(dest, instruction_raw);
	return err_handle_legacy_prefixes(dest);
}
