
#include <d_opcode.h>

///TODO: SOME ARRAYS ARE TOO SHORT AND MAY SEGFAULT IN CASE OF CORRUPTED MODR/M

opfield_t	get_instruction_by_extension_one_and_two_b_opmap(ubyte group, ubyte modrm, ubyte prefix)
{
	const ubyte mod = (modrm & 0b11000000) >> 6;
	const ubyte reg = (modrm & 0b0111000) >> 3;
	const ubyte rm = (modrm & 0b00000111);
	opfield_t inst = {};

	switch (group)
	{
		case 0x1:
			if (prefix == 0x0)
			{
				static const opfield_t arr[] = {/*todo*/};
				inst = arr[reg];
			}
			break ;

		case 0x1A:
			if (prefix == 0x0)
			{
				if (!reg)
					inst = 0; // pop
			}
			break ;

		case 0x2:
			if (prefix == 0x0)
			{
				static const opfield arr[] = {/* rol, ror, ... */};
				inst = arr[reg];
			}
			break ;

		case 0x3:
			if (prefix == 0x0)
			{
				static const opfield arr[] = {/* test, 0, ... */};
				inst = arr[reg];
			}
			break ;

		case 0x4:
			if (prefix == 0x0)
			{
				static const opfield arr[] = {/* inc, dec */};
				inst = arr[reg];
			}
			break ;

		case 0x5:
			if (prefix == 0x0)
			{
				static const opfield arr[] = {/* inc, dec, ... */};
				inst = arr[reg];
			}
			break ;

		case 0x6:
			if (prefix == 0x0)
			{
				static const opfield arr[] = {/* sldt, str, ... */};
				inst = arr[reg];
			}
			break ;

		case 0x7:
			if (prefix == 0x0)
			{
				if (mod == 0b11)
				{
					switch (reg)
					{
						case 0b000:
							static const opfield_t arr[] = { /* vmcall, vmlaunch, vmresume, vmxof */};
							inst = arr[rm];
							break ;

						case 0b001:
							static const opfield_t arr[] = { /* monitor, mwait, clac, stac, encls*/};
							inst = arr[rm];
							break ;

						case 0b010:
							static const opfield_t arr[] = { /* xgetbv, xsetbv, vmfunc, xend, xtest, enclu */ };
							inst = arr[rm];
							break ;

						case 0b100:
							isnt = 0; // smsw
							break ;

						case 0b110:
							isnt = 0; // lmsw
							break ;

						case 0b111:
							static const opfield_t arr[] = { /* swapgs, rdtscp */};
							inst = arr[rm];
					}
				}
				else
				{
					static const opfield_t arr[] = {/*todo*/};
					inst = arr[reg];
				}
			}
			
			break ;
	
		case 0x8:
			if (prefix == 0x0)
			{
				static const opfield arr[] = {/* bt, bts, ... */};
				inst = arr[reg];
			}
			break ;

		case 0x9:
			if (mod == 0b11)
			{
				if (prefix == 0x0)
				{
					static const opfield_t arr[] = {/* rdrand, rdseed */};
					inst = arr[rm];
				}
				else if (prefix == 0xF3)
					inst = 0; // rdpid
			}
			else
			{
				if (prefix == 0x0)
				{
					if (reg == 0b001)
					{
						///TODO: mmmmmmm RM as index ?!?!?
						static const opfield_t arr[] = {/* CMPXCH8B, CMPXCHG*/};
						inst = arr[rm];
					}
					else if (reg == 0b110)
						inst = 0; // vmptrld
					else if (reg == 0b111)
						isnt = 0; // vmptrst
				}
				else if (prefix == 0x66 && reg == 0b110)
					inst = 0; // vmclear
				else if (prefix == 0xF3 && reg == 0b110)
					inst = 0; // vmxon
			}
			break ;

		case 0x10:
			// UD1
			break ;

		case 0x11:
			if (prefix == 0x0)
			{
				if (mod == 0b11)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/* mov, 0, ... */};
					inst = arr[reg];
				}
				else if (reg == 0b000)
					inst = 0; // mov
			}
			break ;

		case 0x12:
			if (mod == 0b11)
			{
				if (prefix == 0x0)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
				else if (prefix == 0x66)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
			}
			break ;

		case 0x13:
			if (mod == 0b11)
			{
				if (prefix == 0x0)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
				else if (prefix == 0x66)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
			}
			break ;

		case 0x14:
			if (mod == 0b11)
			{
				if (prefix == 0x0)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
				else if (prefix == 0x66)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
			}
			break ;

		case 0x15:
			if (mod == 0b11)
			{
				if (prefix == 0x0)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
				else if (prefix == 0xF3)
				{
					///TODO: can easily crash on corrupted input
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
			}
			else if (prefix == 0x0)
			{
				static const opfield arr[] = {/*  ... */};
				inst = arr[reg];
			}
			break ;

		case 0x16:
			if (prefix == 0x0)
			{
				if (mod == 0b11)
					inst = 0; // nop
				else
				{
					static const opfield arr[] = {/*  ... */};
					inst = arr[reg];
				}
			}
			break ;

		case 0x17:
			if (prefix == 0x0)
			{
				static const opfield arr[] = {/*  ... */};
				inst = arr[reg];
			}
			break ;
	}
}