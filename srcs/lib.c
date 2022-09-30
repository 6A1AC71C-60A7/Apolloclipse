
#include <AVL_disassembler.h>
#include <dev/d_utils.h>
#include <dev/d_instruction.h>

#define __EVEX_PREFIX_B1 0x62
#define __DISP_8 0x1
#define __DISP_32 0x2

#define IS_OT_UNRANGED(x) ( \
	(x) != OT_C \
	&& (x) != OT_V \
	&& (x) != OT_Y  \
	&& (x) != (OT_Z) \
)

void AVL_assemble_instructions(uint8_t* dest, AVL_instruction_t src[], uint64_t amount)
{
	for (uint64_t i = 0 ; i < amount ; i++)
	{
		/* Handle prefixes */
		if (AVL_HAS_OP_EVEX_PFX(src[i].i_flags))
		{
			*(dest++) = __EVEX_PREFIX_B1;
			*((uint16_t*)(dest)++) = *(uint16_t*)src[i].i_vp;
			*(dest++) = src[i].i_vp[2];
		}
		else if (AVL_HAS_OP_VEX_PFX(&src[i]))
		{
			*((uint16_t*)(dest)++) = *(uint16_t*)src[i].i_vp;
			if (AVL_ISVEX3_PFX(&src[i]))
				*(dest++) = src[i].i_vp[2];
		}
		else
		{
			///NOTE: This could be also done with a loop
			///NOTE: Also some VEX instruction might take legacy prefixes
			if (AVL_HAS_LP_LOCK_PFX(src[i].i_flags))
				*(dest++) = 0xF0;
			else if (AVL_HAS_LP_REPNX_PFX(src[i].i_flags))
				*(dest++) = 0xF2;
			else if (AVL_HAS_LP_REPX_PFX(src[i].i_flags))
				*(dest++) = 0xF3;
			else if (AVL_HAS_LP_FS_PFX(src[i].i_flags))
				*(dest++) = 0x64;
			else if (AVL_HAS_LP_GS_PFX(src[i].i_flags))
				*(dest++) = 0x65;
			else if (AVL_HAS_LP_NOBRANCH_PFX(src[i].i_flags))
				*(dest++) = 0x2E;
			else if (AVL_HAS_LP_BRANCH_PFX(src[i].i_flags))
				*(dest++) = 0x3E;
			else if (AVL_HAS_LP_OPSZ_PFX(src[i].i_flags))
				*(dest++) = 0x66;
			else if (AVL_HAS_LP_ADDRSZ_PFX(src[i].i_flags))
				*(dest++) = 0x67;

			if (src[i].i_flags & (AVL_RP_REXB_MASK | AVL_RP_REXX_MASK | AVL_RP_REXR_MASK | AVL_RP_REXW_MASK))
			{
				*(dest++) = 0b01000000;

				if (AVL_HAS_REXB_PFX(src[i].i_flags))
					*dest |= 0b0001;
				else if (AVL_HAS_REXX_PFX(src[i].i_flags))
					*dest |= 0b0010;
				else if (AVL_HAS_REXR_PFX(src[i].i_flags))
					*dest |= 0b0100;
				else if (AVL_HAS_REXW_PFX(src[i].i_flags))
					*dest |= 0b1000;
			}
		}

		/* Handle opcode */
		if (src[i].i_opcode[0])
			*(dest++) = src[i].i_opcode[0];
		if (src[i].i_opcode[1])
			*(dest++) = src[i].i_opcode[1];
		*(dest++) = src[i].i_opcode[2];

		/* Handle suffixes */
		if (AVL_HAS_OP_MODRM_MASK(src[i].i_flags))
		{
			*(dest++) = src[i].i_mod_rm;

			const uint8_t	mod = AVL_GET_MODRM_MOD(src[i].i_mod_rm);
			const uint8_t	rm = AVL_GET_MODRM_RM(&src[i]);
			uint8_t			has_sib = 0;
			uint8_t			has_disp = 0;

			if (mod == 0b00)
			{
				if (rm == 0b0100 || rm == 0b1100)
				{
					has_sib = 1;
					const ubyte base = AVL_GET_SIB_BASE(&src[i]);

					if (base == 0b0101 || base == 0b1101)
						has_disp = __DISP_32;
				}
				else if (rm == 0101 || rm == 0b1101)
					has_disp = __DISP_32;
			}
			else if (mod == 0b01)
			{
				has_disp = DISP_8;
				if (rm == 0b0100 || rm == 0b1100)
					has_sib = 1;
			}
			else if (mod == 0b10)
			{
				has_disp = __DISP_32;
				if (rm == 0b0100 || rm == 0b1100)
					has_sib = 1;	
			}

			if (has_sib)
				*(dest++) = src[i].i_sib;
			if (has_disp == __DISP_8)
				*(dest++) = (uint8_t)src[i].i_disp;
			else if (has_disp == __DISP_32)
				*((uint32_t*)(dest)++) = src[i].i_disp;
		}

		if (AVL_HAS_OP_IMM_PFX(src[i].i_flags))
		{
			if (src[i].i_mnemonic == ENTER)
			{
				*((uint16_t*)(dest)++) = (uint16_t)(src[i].i_imm & 0xFFFF);
				*(dest++) = (uint8_t)(src[i].i_imm >> 0x10) & 0xFF;
			}
			else
			{
				AVL_instruction_t	tmp1 = src[i];
				opfield_t			opfield;
				const ubyte*		modrm = &src[i].i_mod_rm;
				ubyte				tmp2;

				// Only useful to get the opfield, other arguments aren't useful
				resolve_opfield(&tmp1, &opfield, &modrm, &tmp2);

				const ubyte ot = get_immediate_operand_type(opfield);

				switch (ot)
				{
					case OT_B:
						*(dest++) = (uint8_t)src[i].i_imm;
						break ;

					case OT_W:
						*((uint16_t*)(dest)++) = (uint16_t)src[i].i_imm;
						break ;

					case OT_D:
						*((uint32_t*)(dest)++) = (uint32_t)src[i].i_imm;
						break ;

					case OT_Q:
						*((uint64_t*)(dest)++) = (uint64_t)src[i].i_imm;
						break ;

					default:
					{
						if (AVL_HAS_REXW_PFX(src[i].i_flags) && IS_OT_UNRANGED(ot))
							*((uint64_t*)(dest)++) = (uint64_t)src[i].i_imm;
						else
						{
							switch (ot)
							{
								case OT_C:
									if ((AVL_OPSZ_IS_BYTE(src[i].i_flags)) != 0)
										*((uint16_t*)(dest)++) = (uint16_t)src[i].i_imm;
									else
										*(dest++) = (uint8_t)src[i].i_imm;
									break ;

								case OT_V:
										if (AVL_OPSZ_IS_WORD(src[i].i_flags))
											*((uint16_t*)(dest)++) = (uint16_t)src[i].i_imm;
										else if (AVL_OPSZ_IS_DWORD(src[i].i_flags))
											*((uint32_t*)(dest)++) = (uint32_t)src[i].i_imm;
										else if (AVL_OPSZ_IS_QWORD(src[i].i_flags))
											*((uint64_t*)(dest)++) = (uint64_t)src[i].i_imm;
									break ;

								case OT_Y:
									if (AVL_OPSZ_IS_QWORD(src[i].i_flags))
										*((uint32_t*)(dest)++) = (uint32_t)src[i].i_imm;
									else
										*((uint64_t*)(dest)++) = (uint64_t)src[i].i_imm;
									break ;

								case OT_Z:
									if (AVL_OPSZ_IS_WORD(src[i].i_flags))
										*((uint16_t*)(dest)++) = (uint16_t)src[i].i_imm;
									else if (!AVL_OPSZ_IS_BYTE(src[i].i_flags) && !AVL_OPSZ_IS_DQWORD(src[i].i_flags) && !AVL_OPSZ_IS_QQWORD(src[i].i_flags))
										*((uint32_t*)(dest)++) = (uint32_t)src[i].i_imm;
									break ;

								default:
									*(dest++) = (uint8_t)src[i].i_imm;

							}
						}
					}
				}
			}
		}
	}
}

/**
 * @brief Check if a 'AVL_instruction_t' instance is zeroed
 * 
 * @param target A pointer to the AVL_instruction_t to check.
 * @return non 0 if the AVL_instruction_t pointed by @p target is zeroed.
 */
uint64_t AVL_inst_iszeroed(AVL_instruction_t* const target)
{
	const uint64_t* raw = (const uint64_t*)target;

	return (raw[0] + raw[1] + raw[2] + raw[3]) == 0;
}

/**
 * @brief Return the amount of non zeroed AVL_instruction_t entities
 * 
 * @param insts The array where the count is performed.
 * @param limit The upper bound of the array.
 */
uint64_t AVL_inst_getlen(AVL_instruction_t insts[], uint64_t limit)
{
	uint64_t lenght = 0;

	while (lenght < limit)
	{
		if (AVL_inst_iszeroed(&insts[lenght]))
			break ;
		lenght++;
	}

	return lenght;
}

/**
 * @brief Find intruction by mnemonic
 * 
 * @param insts The array where the search is performed.
 * @param key The mnemonic used as key.
 * @param insts_len The limit lenght of the search.
 * @return If match a pointer to the found instance, else a pointer to @p &insts[insts_len - 1]
 */
AVL_instruction_t* AVL_inst_find(AVL_instruction_t insts[], AVL_mnemonic_t key, uint64_t insts_len)
{
	uint64_t i = 0;

	while (i < insts_len)
	{
		if (insts[i].i_mnemonic == key)
			break ;
		i++;
	}

	return &insts[i];
}

/**
 * @brief Find instruction by condiational function
 * 
 * @param insts The array where the search is performed.
 * @param insts_len The limit lenght of the search.
 * @param cond A function pointer (uint64_t (*f)(AVL_instruction_t*)) used as key.
 * @return If match a pointer to the found instance, else a pointer to @p &insts[insts_len - 1]
 */
AVL_instruction_t* AVL_inst_findif(AVL_instruction_t insts[], uint64_t insts_len, AVL_condition_t cond)
{
	uint64_t i = 0;

	while (i < insts_len)
	{
		if (cond(&insts[i]))
			break ;
		i++;
	}

	return &insts[i];
}

/**
 * @brief Insert instructions after @p dest
 * 
 * @param dest A pointer to the element that precedes the insertion.
 * @param destlen The amount of instructions after @p dest pointer.
 * @param src A pointer to the begin of the instructions that will be inserted.
 * @param srclen The amount of instructions that will be inserted
 */
void AVL_inst_insert(AVL_instruction_t* const dest, uint64_t destlen, AVL_instruction_t* const src, uint64_t srclen)
{
	for (int64_t i = destlen ; i >= 0 ; --i)
		dest[i + srclen] = dest[i];

	for (uint64_t i = 0 ; i < srclen ; i++)
		dest[i] = src[i];
}

/**
 * @brief Erase N instructions on @p target
 * 
 * @param target A pointer to the instructions that will be erased.
 * @param amount The amount of instuctions that will be erased.
 * @param targetlen The amount of instructions after @p target pointer.
 */
void AVL_inst_erase(AVL_instruction_t* const target, uint64_t amount, uint64_t targetlen)
{
	for (uint64_t i = 0 ; i < targetlen - amount; i++)
		target[i] = target[i + amount];
}

__always_inline
static void	__swap(uint64_t *x, uint64_t *y) 
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

/**
 * @brief Swaps @p 'l' and @p 'p' pointed data.
 */
void AVL_inst_swap(AVL_instruction_t* const l, AVL_instruction_t* const r)
{
	if (l != r)
	{
		uint64_t* lraw = (uint64_t*)l;
		uint64_t* rraw = (uint64_t*)r;

		__swap(&lraw[0], &rraw[0]);
		__swap(&lraw[1], &rraw[1]);
		__swap(&lraw[2], &rraw[2]);
		__swap(&lraw[3], &rraw[3]);
	}
}
