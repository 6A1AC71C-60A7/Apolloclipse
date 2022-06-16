
#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

__always_inline
static const ubyte* get_legacy_map(ubyte dest[3], const ubyte** instruction_raw, uqword* const map_len)
{
    const ubyte* map = lt_opcode_defaut_map;
    *map_len = ARRLEN(lt_opcode_defaut_map);

    if (**instruction_raw == 0x0F)
    {
        dest[0] = 0x0F;
        (*instruction_raw)++;
        map = lt_opcode_0x0F_map;
        *map_len = ARRLEN(lt_opcode_0x0F_map);

        if (**instruction_raw == 0x38)
        {
            dest[1] = 0x38;
            (*instruction_raw)++;
            map = lt_opcode_0x0F38_map;
            *map_len = ARRLEN(lt_opcode_0x0F38_map);

        }
        else if (**instruction_raw == 0x3A)
        {
            dest[1] = 0x3A;
            (*instruction_raw)++;
            map = lt_opcode_0x0F3A_map;
            *map_len = ARRLEN(lt_opcode_0x0F3A_map);
        }
    }

    return map;
}

__always_inline
static udword map_find(const ubyte* map, uqword map_len, udword tofind)
{
    for (uqword i = 0 ; i < map_len ; i++)
    {
        if (map[i] == tofind)
            return tofind;
    }
    return 0;
}

__always_inline
static err_t	get_instruction_legacy_opcode(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t			st = EINVOPCODE;
    const ubyte*	map;
    uqword			map_len;

	map = get_legacy_map(inst->opcode, instruction_raw, &map_len);
	if (map_find(map, map_len, **instruction_raw) == **instruction_raw)
	{
		inst->opcode[2] = **instruction_raw;
		(*instruction_raw)++;
		st = SUCCESS;
	}
	return st;
}

__always_inline
static const ubyte*	get_vexxop_map(ubyte key, uqword* const map_len)
{
	///TODO:
	(void)key; (void)map_len;
	return 0;
}

__always_inline
static err_t   get_instruction_vexxop_opcode(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t			st = EINVOPCODE;
    const ubyte		map_key = VEXXOP_MAP_SELECT_GET(inst->vexxop);
	uqword			map_len;
    const ubyte*	map = get_vexxop_map(map_key, &map_len);

	if (map && map_find(map, map_len, **instruction_raw) == **instruction_raw)
	{
		inst->opcode[2] = **instruction_raw;
		(*instruction_raw)++;
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

__always_inline
static err_t	get_instruction_3dnow_opcode(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t st = EINVOPCODE;

	if (map_find(lt_opcode_3dnow_map, ARRLEN(lt_opcode_3dnow_map), **instruction_raw) == **instruction_raw)
	{
		inst->opcode[2] = **instruction_raw;
		(*instruction_raw)++;
		st = SUCCESS;
	}
	return st;
}

__always_inline
static void		get_immediate(instruction_t* const inst, const ubyte** instruction_raw, uqword nbytes)
{
	(void)inst; (void)instruction_raw, (void)nbytes;
	//register ubyte* imm = (ubyte*)inst->operand_l;

	//for (uqword i = 0 ; i < nbytes ; i++)
		//imm[i] = *((*instruction_raw)++);
}

__always_inline
static err_t	get_instruction_opcode(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t st = SUCCESS;

	if (get_3dnow_prefixes(inst, instruction_raw) == SUCCESS)
	{
		handle_modrm(inst, instruction_raw);
		get_instruction_3dnow_opcode(inst, instruction_raw);
	}
	else if (inst->vexxop[0])
	{
		st = get_instruction_vexxop_opcode(inst, instruction_raw);
		///TODO: His also should have modR/M and immediates ...
	}
	else
	{
		st = get_instruction_legacy_opcode(inst, instruction_raw);
		///TODO: CHECK WHICH FORMATS CAN APPEND AN OPCODE
		///DO: The opcodes maps (opcode, mnemonic, ismodrm, isimmediate, ...)
		if (0 /* Is modR/M instruction*/)
			handle_modrm(inst, instruction_raw);
		else if (0 /* Is immediate instruction*/)
			get_immediate(inst, instruction_raw, 0 /* Immediate size */);
		else if (0 /* What else ? */) {;}
			
	}

	return st;
}

/**
 * @brief Parse a whole instruction
 * 
 * @param inst Where the parsed instruction is located on return.
 * @param instruction_raw A pointer to a pointer (which is modified) to the data to parse.
 */
err_t	get_instruction(instruction_t* const inst, const ubyte** instruction_raw)
{
	err_t st;
	const ubyte* const old = *instruction_raw;

	st = get_instruction_prefixes(inst, instruction_raw);
	///TODO: Do something with st here
	st = get_instruction_opcode(inst, instruction_raw);
	inst->size = *instruction_raw - old;

	///TODO: operand_l and operand_r fields are  not completelly parsed yet
	///TDOO: mnemonic field is also not parsed yet

	return st;
}
