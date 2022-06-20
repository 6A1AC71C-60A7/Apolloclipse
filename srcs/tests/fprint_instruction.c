
#include <d_portability.h>
#include <d_instruction.h>
#include <d_register.h>
#include <d_error.h>

static const char* const regs[] = {
    "[ADDR]",
    "rax",
    "rcx",
    "rdx",
    "rbx",
    "rsp",
    "rbp",
    "rsi",
    "rdi",
    "r8",
    "r9",
    "r10",
    "r11",
    "r12",
    "r13",
    "r14",
    "r15",
    "st0",
    "st1",
    "st2",
    "st3",
    "st4",
    "st5",
    "st6",
    "st7",
    "mmx0",
    "mmx1",
    "mmx2",
    "mmx3",
    "mmx4",
    "mmx5",
    "mmx6",
    "mmx7",
    "mmx0b",
    "mmx1b",
    "mmx2b",
    "mmx3b",
    "mmx4b",
    "mmx5b",
    "mmx6b",
    "mmx7b",
    "xmm0",
    "xmm1",
    "xmm2",
    "xmm3",
    "xmm4",
    "xmm5",
    "xmm6",
    "xmm7",
    "xmm8",
    "xmm9",
    "xmm10",
    "xmm11",
    "xmm12",
    "xmm13",
    "xmm14",
    "xmm15",
    "ymm0",
    "ymm1",
    "ymm2",
    "ymm3",
    "ymm4",
    "ymm5",
    "ymm6",
    "ymm7",
    "ymm8",
    "ymm9",
    "ymm10",
    "ymm11",
    "ymm12",
    "ymm13",
    "ymm14",
    "ymm15",
    "es",
    "cs",
    "ss",
    "ds",
    "fs",
    "gs",
    "esb",
    "csb",
    "ssb",
    "dsb",
    "fsb",
    "gsb",
    "cr0",
    "cr1",
    "cr2",
    "cr3",
    "cr4",
    "cr5",
    "cr6",
    "cr7",
    "cr8",
    "cr9",
    "cr10",
    "cr11",
    "cr12",
    "cr13",
    "cr14",
    "cr15",
    "dr0",
    "dr1",
    "dr2",
    "dr3",
    "dr4",
    "dr5",
    "dr6",
    "dr7",
    "dr8",
    "dr9",
    "dr10",
    "dr11",
    "dr12",
    "dr13",
    "dr14",
    "dr15",
    "rflags",
    "ah",
    "ch",
    "dh",
    "bh",
};

static const char* const gp_regs_32[] = {
	"eax",
	"ecx",
	"edx",
	"ebx",
	"esp",
	"ebp",
	"esi",
	"edi",
	"r8d",
	"r9d",
	"r10d",
	"r11d",
	"r12d",
	"r13d",
	"r14d",
	"r15d"
};

static const char* const gp_regs_16[] = {
	"ax",
	"cx",
	"dx",
	"bx",
	"sp",
	"bp",
	"si",
	"di",
	"r8w",
	"r9w"
	"r10w",
	"r11w",
	"r12w",
	"r13w",
	"r14w",
	"r15w"
};

static const char* const gp_regs_8[] = {
	"al",
	"cl",
	"dl",
	"bl",
	"spl",
	"bpl",
	"sil",
	"dil",
	"r8b",
	"r9b",
	"r10b",
	"r11b",
	"r12b",
	"r13b",
	"r14b",
	"r15b"
};


static const char* const mnemonics[] = {
    "mov",	// move data between general-purpose registers; move data between memory and general-purpose or segment registers; move immediates to general-purpose registers.
	"cmove",   // conditional move if equal.
	"cmovz",   // conditional move if zero.
	"cmovne",   // conditional move if not equal.
	"cmovnz",   // conditional move if not zero.
	"cmova",   // conditional move if above.
	"cmovnbe",	// conditional move if not below or equal.
	"cmovae",   // conditional move if above or equal.
	"cmovnb",   // conditional move if not below.
	"cmovb",   // conditional move if below.
	"cmovnae",	// conditional move if not above or equal.
	"cmovbe",   // conditional move if below or equal.
	"cmovna",   // conditional move if not above.
	"cmovg",   // conditional move if greater
	"cmovnle",	// conditional move if not less or equal.
	"cmovge",   // conditional move if greater or equal.
	"cmovnl",   // conditional move if not less.
	"cmovl",   // conditional move if less.
	"cmovnge",	// conditional move if not greater or equal.
	"cmovle",   // conditional move if less or equal.
	"cmovng",   // conditional move if not greater.
	"cmovc",   // conditional move if carry.
	"cmovnc",   // conditional move if not carry.
	"cmovo",   // conditional move if overflow.
	"cmovno",   // conditional move if not overflow.
	"cmovs",   // conditional move if sign (negative).
	"cmovns",   // conditional move if not sign (non-negative).
	"cmovp",   // conditional move if parity.
	"cmovpe",   // conditional move if parity even.
	"cmovnp",   // conditional move if not parity.
	"cmovpo",   // conditional move if parity odd.
	"xchg",   // exchange.
	"bswap",   // byte swap.
	"xadd",   // exchange and add.
	"cmpxchg",	// compare and exchange.
	"cmpxchg8b",	// compare and exchange 8 bytes
	"push",   // push onto stack.
	"pop",   // pop off of stack.
	"pusha",   // push general-purpose registers onto stack.
	"pushad",   // push general-purpose registers onto stack.
	"popa",   // pop general-purpose registers from stack.
	"popd",   // pop general-purpose registers from stack.
	"cwd",   // convert word to doubleword.
	"cdq",   // convert doubleword to quadword.
	"cbw",   // convert byte to word.
	"cwde",   // convert word to doubleword in eax register.
	"movsx",   // move and sign extend.
	"movzx",   // move and zero extend.

	/* 2) binary arithmetic */

	"adcx",   // unsigned integer add with carry.
	"adox",   // unsigned integer add with overflow.
	"add",   // integer add.
	"adc",   // add with carry.
	"sub",   // subtract.
	"sbb",   // subtract with borrow.
	"imul",   // signed multiply.
	"mul",   // unsigned multiply.
	"idiv",   // signed divide.
	"div",   // unsigned divide.
	"inc",   // increment.
	"dec",   // decrement.
	"neg",   // negate.
	"cmp",   // compare.

	/* 3) decimal arithmetic */

	"daa",   // decimal adjust after addition.
	"das",   // decimal adjust after subtraction.
	"aaa",   // ascii adjust after addition.
	"aas",   // ascii adjust after subtraction.
	"aam",   // ascii adjust after multiplication.
	"aad",   // ascii adjust before division.

	/* 4) logical */

	"and",   // perform bitwise logical and.
	"or",   // perform bitwise logical or.
	"xor",   // perform bitwise logical exclusive or.
	"not",   // perform bitwise logical not.

	/* 5) shift and rotate */

	"shld",   // shift left double.
	"ror",   // rotate right.
	"rol",   // rotate left.
	"rcr",   // rotate through carry right.
	"rcl",   // rotate through carry left.

	/* 6) bit and byte */

	"bt",   // bit test.
	"bts",   // bit test and set.
	"btr",   // bit test and reset.
	"btc",   // bit test and complement.
	"bsf",   // bit scan forward.
	"bsr",   // bit scan reverse.
	"sete",   // set byte if equal.
	"setz",   // set byte if zero.
	"setne",   // set byte if not equal.
	"setnz",   // set byte if not zero.
	"seta",   // set byte if above.
	"setnbe",   // set byte if not below or equal.
	"setae",   // set byte if above or equal.
	"setnb",   // set byte if not below.
	"setnc",   // set byte if not carry.
	"setb",   // set byte if below.
	"setnae",   // set byte if not above or equal.
	"setc",   // set byte if carry.
	"setbe",   // set byte if below or equal.
	"setna",   // set byte if not above.
	"setg",   // set byte if greater.
	"setnle",   // set byte if not less or equal.
	"setge",   // set byte if greater or equal.
	"setnl",   // set byte if not less.
	"setl",   // set byte if less.
	"setnge",   // set byte if not greater or equal.
	"setle",   // set byte if less or equal.
	"setng",   // set byte if not greater.
	"sets",   // set byte if sign (negative).
	"setns",   // set byte if not sign (non-negative).
	"seto",   // set byte if overflow.
	"setno",   // set byte if not overflow.
	"setpe",   // set byte if parity even.
	"setp",   // set byte if parity.
	"setpo",   // set byte if parity odd.
	"setnp",   // set byte if not parity.
	"test",   // logical compare.
	"crc32",   // provides hardware acceleration to calculate cyclic redundancy checks for fast and efficient implementation of data integrity protocols
	"popcnt",   // this instruction calculates of number of bits set to 1 in the second operand (source) and returns the count in the first operand (a destination register).

	/* 7) control transfer */

	"jmp",   // jump.
	"je",   // jump if equal.
	"jz",   // jump if zero.
	"jne",   // jump if not equal.
	"jnz",   // jump if not zero.
	"ja",   // jump if above.
	"jnbe",   // jump if not below or equal.
	"jae",   // jump if above or equal.
	"jnb",   // jump if not below.
	"jb",   // jump if below.
	"jnae",   // jump if not above or equal
	"jbe",   // jump if below or equal.
	"jna",   // jump if not above.
	"jg",   // jump if greater.
	"jnle",   // jump if not less or equal.
	"jge",   // jump if greater or equal.
	"jnl",   // jump if not less.
	"jl",   // jump if less.
	"jnge",   // jump if not greater or equal.
	"jle",   // jump if less or equal.
	"jng",   // jump if not greater.
	"jc",   // jump if carry.
	"jnc",   // jump if not carry.
	"jo",   // jump if overflow.
	"jno",   // jump if not overflow.
	"js",   // jump if sign (negative).
	"jns",   // jump if not sign (non-negative).
	"jpo",   // jump if parity odd.
	"jnp",   // jump if not parity.
	"jpe",   // jump if parity even.
	"jp",   // jump if parity.
	"jcxz",   // jump register cx zero.
	"jecxz",   // jump register ecx zero.
	"loop",   // loop with ecx counter.
	"loopz",   // loop with ecx and zero/
	"loope",   // loop with ecx and equal.
	"loopnz",   // loop with ecx and not zero.
	"loopne",   // loop with ecx and not equal.
	"call",   // call procedure.
	"ret",   // return.
	"iret",   // return from interrupt.
	"int",   // software interrupt.
	"into",   // interrupt on overflow.
	"bound",   // detect value out of range.

	/* 8) string */

	"movs",   // move string.
	"movsb",   // move byte string.
	"movsw",   // move word string.
	"movsd",   // move doubleword string.
	"cmps",   // compare string.
	"cmpsb",   // compare byte string.
	"cmpdw",   // compare word string.
	"cmpsd",   // compare doubleword string.
	"scas",   // scan string.
	"scasb",   // scan byte string.
	"scasw",   // scan word string
	"scasd",   // scan doubleword string.
	"lods",   // load string.
	"lodsb",   // load byte string.
	"lodsw",   // load word string.
	"lodsd",   // load doubleword string.
	"stos",   // store string.
	"stosb",   // store byte string.
	"stosw",   // store word string.
	"stosd",   // store doubleword string.
	"rep",   // repeat while ecx not zero.
	"repe",   // repeat while equal.
	"repz",   // repeat while zero.
	"repne",   // repeat while not equal
	"repnz",   // repeat while not zero.

	/* 9) i/o */

	"in",   // read from a port.
	"out",   // write to a port.
	"ins",   // input string from port.
	"insb",   // input byte string from port.
	"insw",   // input word string from port.
	"isnd",   // input doubleword string from port.
	"outs",   // output string to port.
	"outsb",   // output byte string to port.
	"outsw",   // output word string to port.
	"outsd",   // /output doubleword string to port.

	/* 10) enter and leave */

	"enter",   // high-level procedure entry.
	"leave",   // high-level procedure exit.

	/* 11) flag control (eflag) */

	"stc",   // set carry flag.
	"clc",   // clear the carry flag.
	"cmc",   // complement the carry flag.
	"cld",   // clear the direction flag.
	"std",   // set direction flag.
	"lahf",   // load flags into ah register.
	"sahf",   // store ah register into flags.
	"pushf",   // push eflags onto stack.
	"pushfd",   // push eflags onto stack.
	"popf",   // pop eflags from stack.
	"popfd",   // pop eflags from stack.
	"sti",   // set interrupt flag.
	"cli",   // clear the interrupt flag.

	/* 12) segment register */

	"lds",   // load far pointer using ds.
	"les",   // load far pointer using es.
	"lfs",   // load far pointer using fs.
	"lgs",   // load far pointer using gs.
	"lss",   // load far pointer using ss.

	/* 13) misvellaneous */

	"lea",   // load effective address.
	"nop",   // no operation.
	"ud",   	// undefined instruction.
	"xlat",   // table lookup translation.
	"xlatb",   // table lookup translation.
	"cpuid",   // processor identification.
	"movbe",   // move data after swapping data bytes.
	"prefetchw",	"	"// prefetch data into cache in anticipation of write.
	"prefetchwt1",	// prefetch hint t1 with intent to write.
	"clflush",	"	"// flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy.
	"clflushopt",	"	"// flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy with optimized memory system throughput.

	/* 14) user mode extended sate safe/restore */

	"xsave",   // save processor extended states to memory.
	"xsavec",   // save processor extended states with compaction to memory.
	"xsaveopt",	"	"// save processor extended states to memory, optimized.
	"xrstor",   // restore processor extended states from memory.
	"xgetbv",   // reads the state of an extended control register.

	/* 15) random number generation */

	"rdrand",   // retrieves a random number generated from hardware.
	"rdseed",   // retrieves a random number generated from hardware.

	/* 16) bmi1", bmi2 */

	"andn",   // bitwise and of first source with inverted 2nd source operands.
	"bextr",   // contiguous bitwise extract.
	"blsi",   // extract lowest set bit.
	"blsmsk",   // set all lower bits below first set bit to 1.
	"blsr",   // reset lowest set bit.
	"bzhi",   // zero high bits starting from specified bit position.
	"lzcnt",   // count the number leading zero bits.
	"mulx",   // unsigned multiply without affecting arithmetic flags.
	"pded",   // parallel deposit of bits using a mask.
	"pext",   // parallel extraction of bits using a mask.
	"rorx",   // rotate right without affecting arithmetic flags.
	"sarx",   // shift arithmetic right.
	"shlx",   // shift logic left.
	"shrx",   // shift logic right.
	"tzcnt",   // count the number trailing zero bits.
};

__always_inline
static void print_mnemonic(FILE* where, instruction_t* const target)
{
	fprintf(where, "%s ", mnemonics[target->mnemonic - 1]);
}

static ubyte print_operand(FILE* where, reg_t reg, udword prefix, ubyte isfirst)
{
	ubyte l = 0x0;

	if (reg)
	{
		if (!(prefix & OS_QWORD_MASK) && reg >= D_REG_RAX && reg <= D_REG_R15)
		{
			if (prefix & OS_BYTE_MASK)
				l = fprintf(where, "%s%s", isfirst ? "" : ", ", gp_regs_8[reg - 2]);
			else if (prefix & OS_WORD_MASK)
				l = fprintf(where, "%s%s", isfirst ? "" : ", ", gp_regs_16[reg - 2]);
			else if (prefix & OS_DWORD_MASK)
				l = fprintf(where, "%s%s", isfirst ? "" : ", ", gp_regs_32[reg - 2]);
		}
		else
			l = fprintf(where, "%s%s", isfirst ? "" : ", ", regs[reg - 1]); 
	}

	return l;
}

__always_inline
static ubyte print_operands(FILE* where, instruction_t* const target)
{
	const udword prefix = *(udword*)target->prefix;

	return print_operand(where, target->reg1, prefix, 1)
	+ print_operand(where, target->reg2, prefix, 0)
	+ print_operand(where, target->reg3, prefix, 0);
}

__always_inline
static void print_immediate(FILE* where, instruction_t* const target, ubyte has_operands)
{
	if (*(udword*)target->prefix & OP_IMMEDIATE_MASK)
    {
        if (has_operands)
            fprintf(where, ", ");
        fprintf(where, "0x%lX", target->immediate);
    }
}

void    fprint_instruction(FILE* where, instruction_t* const target)
{
	dword has_operands;

	print_mnemonic(where, target);
	has_operands = print_operands(where, target);
    print_immediate(where, target, has_operands);
	fprintf(where, "\n");

	// if (prefix & OS_BYTE_MASK)
	// 	fprintf(where, " (Operand Size: BYTE)\n");
	// else if (prefix & OS_WORD_MASK)
	// 	fprintf(where, " (Operand Size: WORD)\n");
	// else if (prefix & OS_DWORD_MASK)
	// 	fprintf(where, " (Operand Size: DWORD)\n");
	// else if (prefix & OS_QWORD_MASK)
	// 	fprintf(where, " (Operand Size: QWORD)\n");
	// else if (prefix & OS_DQWORD_MASK)
	// 	fprintf(where, " (Operand Size: DQWORD)\n");
	// else if (prefix & OS_QQWORD_MASK)
	// 	fprintf(where, " (Operand Size: QQWORD)\n");
	// else
	// 	fprintf(where, " (Operand Size: ERROR)\n");
}
