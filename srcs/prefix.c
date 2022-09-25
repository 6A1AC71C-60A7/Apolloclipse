#include <d_portability.h>
#include <d_instruction.h>
#include <d_lookup_tables.h>
#include <d_utils.h>

#include <user.h>

__always_inline
void		get_legacy_prefixes(udword* const dest, const ubyte** iraw)
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
				*dest |= AVL_LP_LOCK_MASK << prefix_it;
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
	DEBUG("[DEBUG][END] (**iraw)=[%02X] (%d) (%d)\n", **iraw, *dest & AVL_MP_0x66_MASK, *dest & AVL_MP_0xF2_MASK);

}

__always_inline
err_t	err_handle_legacy_prefixes(const udword* const dest)
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

__always_inline
void get_vex_prefixes(AVL_instruction_t* const inst, const ubyte** iraw)
{
	ubyte opp;

	*(uword*)inst->i_vp = *((*(uword**)iraw)++);

	if (inst->i_vp[0] != 0xC5)
	{
		AVL_vex_t*	vp = (AVL_vex_t*)inst->i_vp;

		inst->i_vp[2] = *((*iraw)++);

		if (!vp->vx_rexr)
			inst->i_flags |= AVL_RP_REXR_MASK;
		if (!vp->vx_rexx)
			inst->i_flags |= AVL_RP_REXX_MASK;
		if (!vp->vx_rexb)
			inst->i_flags |= AVL_RP_REXB_MASK;
		if (vp->vx_rexw)
			inst->i_flags |= AVL_RP_REXW_MASK;

		opp = vp->vx_prefix;
	}
	else
	{
		AVL_vex2_t*	vp2 = (AVL_vex2_t*)inst->i_vp;

		if (!vp2->vx2_rexr)
			inst->i_flags |= AVL_RP_REXR_MASK;

		opp = vp2->vx2_prefix;
	}

	switch (opp)
	{
		case 0x1:
			inst->i_flags |= AVL_MP_0x66_MASK;
			break ;
		case 0x2:
			inst->i_flags |= AVL_MP_0xF3_MASK;
			break ;
		case 0x3:
			inst->i_flags |= AVL_MP_0xF2_MASK;
			break ;
	}

		/// debug
	DEBUG("OPP IS: %d\n", opp);
	if (AVL_HAS_REXR_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.R\n");
	if (AVL_HAS_REXB_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.B\n");
	if (AVL_HAS_REXX_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.X\n");
	if (AVL_HAS_REXW_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.W\n");
}


__always_inline
void get_rex_prefix(udword* const dest, const ubyte** iraw)
{
	for (udword count = 0; count <= 3 ; count++)
	{
		if (**iraw & (1 << count))
			*dest |= AVL_RP_REXB_MASK << count;
	}
}


__always_inline
void get_evex_prefixes(AVL_instruction_t* const inst, const ubyte** iraw)
{
	(*iraw)++;
	inst->i_flags |= AVL_OP_EVEX_MASK;

	AVL_evex_t* evp = (AVL_evex_t*)inst->i_vp;

	*(uword*)inst->i_vp = *((*(uword**)iraw)++);
	inst->i_vp[2] = *((*iraw)++);

	if (!evp->evx_rexr || !evp->evx_rexr2)
		inst->i_flags |= AVL_RP_REXR_MASK;
	if (!evp->evx_rexx)
		inst->i_flags |= AVL_RP_REXX_MASK;
	if (!evp->evx_rexb)
		inst->i_flags |= AVL_RP_REXB_MASK;
	if (evp->evx_rexw)
		inst->i_flags |= AVL_RP_REXW_MASK;

	switch (evp->evx_prefix)
	{
		case 0x1:
			inst->i_flags |= AVL_MP_0x66_MASK;
			break ;
		case 0x2:
			inst->i_flags |= AVL_MP_0xF3_MASK;
			break ;
		case 0x3:
			inst->i_flags |= AVL_MP_0xF2_MASK;
			break ;
	}

	if (AVL_HAS_REXR_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.R\n");
	if (AVL_HAS_REXB_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.B\n");
	if (AVL_HAS_REXX_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.X\n");
	if (AVL_HAS_REXW_PFX(inst->i_flags))
		DEBUG("-> VEX: HAS REX.W\n");
}
