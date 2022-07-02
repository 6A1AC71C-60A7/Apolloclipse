
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
	"r9w",
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
	"prefetchw",	// prefetch data into cache in anticipation of write.
	"prefetchwt1",	// prefetch hint t1 with intent to write.
	"clflush",	// flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy.
	"clflushopt",	// flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy with optimized memory system throughput.

	/* 14) user mode extended sate safe/restore */

	"xsave",   // save processor extended states to memory.
	"xsavec",   // save processor extended states with compaction to memory.
	"xsaveopt",	// save processor extended states to memory, optimized.
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

	"fld",	// load floating-point value.
	"fst",	// store floating-point value.
	"fstp",	// store floating-point value and pop.
	"fild",	// load integer.
	"fist",	// store integer.
	"fistp",	// store integer and pop.
	"fbld",	// load bcd.
	"fbstp",	// store bcd and pop.
	"fxch",	// exchange registers.
	"fcmove",	// floating-point conditional move if equal.
	"fcmovne",// floating-point conditional move if not equal.
	"fcmovb",	// floating-point conditional move if below.
	"fcmovbe",// floating-point conditional move if below or equal.
	"fcmovnb",// floating-point conditional move if not below.
	"fcmovnbe",// floating-point conditional move if not below or equal.
	"fcmovu",	// floating-point conditional move if unordered.
	"fcmovnu",// floating-point conditional move if not unordered.

	/* 2) basic arithmetic */

	"fadd",	// add floating-point.
	"faddp",	// add floating-point and pop.
	"fiadd",	// add integer.
	"fsub",	// subtract floating-point.
	"fsubp",	// subtract floating-point and pop.
	"fisub",	// subtract integer.
	"fsubr",	// subtract floating-point reverse.
	"fsubrp",	// subtract floating-point reverse and pop.
	"fisubr",	// subtract integer reverse.
	"fmul",	// multiply floating-point.
	"fmulp",	// multiply floating-point and pop.
	"fimul",	// multiply integer.
	"fdiv",	// divide floating-point.
	"fdivp",	// divide floating-point and pop.
	"fidiv",	// divide integer.
	"fdivr",	// divide floating-point reverse.
	"fdivrp",	// divide floating-point reverse and pop.
	"fidivr",	// divide integer reverse.
	"fprem",	// partial remainder.
	"fprem1",	// ieee partial remainder.
	"fabs",	// absolute value.
	"fchs",	// change sign.
	"frdint",	// round to integer.
	"fscale",	// scale by power of two.
	"fsqrt",	// square root.
	"fxtract",// extract exponent and significand.

	/* 3) comparison */

	"fcom",	// compare floating-point.
	"fcomp",	// compare floating-point and pop.
	"fcompp",	// compare floating-point and pop twice.
	"fucom",	// unordered compare floating-point.
	"fucomp",	// unordered compare floating-point and pop.
	"fucompp",// unordered compare floating-point and pop twice.
	"ficom",	// compare integer.
	"ficomp",	// compare integer and pop.
	"fcomi",	// compare floating-point and set eflags.
	"fucomi",	// unordered compare floating-point and set eflags.
	"fcomip",	// compare floating-point, set eflags, and pop.
	"fucomip",// unordered compare floating-point, set eflags, and pop.
	"ftst",	// test floating-point (compare with 0.0).
	"fxam",	// examine floating-point.

	/* 4) transcendental */

	"fsin",	// sine.
	"fcos",	// cosine.
	"fsincos",// sine and cosine.
	"fptan",	// partial tangent.
	"fpatan",	// partial arctangent.
	"f2xm1",	// 2^x − 1
	"fyl2x",	// y∗log2x
	"fyl2xp1",// y∗log2(x+1)

	/* 5) load constants */

	"fld1",	// load +1.0
	"fldz",	// load +0.0
	"fldpi",	// load π
	"fldl2e",	// load log 2^e
	"fldln2",	// load log e^2
	"fldl2t",	// load log 2^10
	"fldlg2",	// load log 10^2

	/* 6) control */

	"fincstp",// increment fpu register stack pointer.
	"fdecstp",// decrement fpu register stack pointer.
	"ffree",	// free floating-point register.
	"finit",	// initialize fpu after checking error conditions.
	"fninit",	// initialize fpu without checking error conditions.
	"fclex",	// clear floating-point exception flags after checking for error conditions.
	"fnclex",	// clear floating-point exception flags without checking for error conditions.
	"fstcw",	// store fpu control word after checking error conditions.
	"fnstcw",	// store fpu control word without checking error conditions.
	"fldcw",	// load fpu control word.
	"fstenv",	// store fpu environment after checking error conditions.
	"fnstenv",// store fpu environment without checking error conditions.
	"fldenv",	// load fpu environment.
	"fsave",	// save fpu state after checking error conditions.
	"fnsave",	// save fpu state without checking error conditions.
	"frstor",	// restore fpu state.
	"fstsw",	// store fpu status word after checking error conditions.
	"fnstsw",	// store fpu status word without checking error conditions.
	"wait",	// wait for fpu.
	"fwait",	// wait for fpu.
	"fnop",	// fpu no operation.

	/////////
	// mmx //
	/////////

	/* 1) data transfer */

	"movd",	// move doubleword.
	"movq",	// move quadword.

	/* 2) conversion */

	"packsswb",// pack words into bytes with signed saturation.
	"packssdw",// pack doublewords into words with signed saturation.
	"packuswb",// pack words into bytes with unsigned saturation.
	"punpckhbw",// unpack high-order bytes.
	"punpckhwd",// unpack high-order words.
	"punpckhdq",// unpack high-order doublewords.
	"punpcklbw",// unpack low-order bytes.
	"punpcklwd",// unpack low-order words.
	"punpckldq",// unpack low-order doublewords.

	/* 3) packed arithmetic */

	"paddb",	// add packed byte integers.
	"paddw",	// add packed word integers.
	"paddd",	// add packed doubleword integers.
	"paddsb",	// add packed signed byte integers with signed saturation.
	"paddsw",	// add packed signed word integers with signed saturation.
	"paddusb",// add packed unsigned byte integers with unsigned saturation.
	"paddusw",// add packed unsigned word integers with unsigned saturation.
	"psubb",	// subtract packed byte integers.
	"psubw",	// subtract packed word integers.
	"psubd",	// subtract packed doubleword integers.
	"psubsb",	// subtract packed signed byte integers with signed saturation.
	"psubsw",	// subtract packed signed word integers with signed saturation.
	"psubusb",// subtract packed unsigned byte integers with unsigned saturation.
	"psubusw",// subtract packed unsigned word integers with unsigned saturation.
	"pmulhw",	// multiply packed signed word integers and store high result.
	"pmullw",	// multiply packed signed word integers and store low result.
	"pmaddwd",// multiply and add packed word integers.

	/* 4) comparison */

	"pcmpeqb",// compare packed bytes for equal.
	"pcmpeqw",// compare packed words for equal.
	"pcmpeqd",// compare packed doublewords for equal.
	"pcmpgtb",// compare packed signed byte integers for greater than.
	"pcmpgtw",// compare packed signed word integers for greater than.
	"pcmpgtd",// compare packed signed doubleword integers for greater than.

	/* 5) logical */

	"pand",	// bitwise logical and.
	"pandn",	// bitwise logical and not.
	"por",	// bitwise logical or.
	"pxor",	// bitwise logical exclusive or.

	/* 6) shift and rotate */

	"psllw",	// shift packed words left logical.
	"pslld",	// shift packed doublewords left logical.
	"psllq",	// shift packed quadword left logical.
	"psrlw",	// shift packed words right logical.
	"psrld",	// shift packed doublewords right logical.
	"psrlq",	// shift packed quadword right logical.
	"psraw",	// shift packed words right arithmetic.
	"psrad",	// shift packed doublewords right arithmetic.

	/* 7) state management */

	"emms",	// empty mmx state.

	/////////
	// sse //
	/////////

	/* 1) data transfer */

	"movaps",	// move four aligned packed single-precision floating-point values between xmm registers or between and xmm register and memory.
	"movups",	// move four unaligned packed single-precision floating-point values between xmm registers or between and xmm register and memory.
	"movhps",	// move four unaligned packed single-precision floating-point values between xmm registers or between and xmm register and memory.
	"movhlps",// move two packed single-precision floating-point values from the high quadword of an xmm register to the low quadword of another xmm register.
	"movlps",	// move two packed single-precision floating-point values to an from the low quadword of an xmm register and memory.
	"movlhps",// move two packed single-precision floating-point values from the low quadword of an xmm register to the high quadword of another xmm register.
	"movmskps",// extract sign mask from four packed single-precision floating-point values.
	"movss",	// move scalar single-precision floating-point value between xmm registers or between an xmm register and memory.

	/* 2) packed arithmetic */

	"addps",	// add packed single-precision floating-point values.
	"addss",	// add scalar single-precision floating-point values.
	"subps",	// subtract packed single-precision floating-point values.
	"subss",	// subtract scalar single-precision floating-point values.
	"mulps",	// multiply packed single-precision floating-point values.
	"mulss",	// multiply scalar single-precision floating-point values.
	"divps",	// divide packed single-precision floating-point values.
	"divss",	// divide scalar single-precision floating-point values.
	"rcpps",	// compute reciprocals of packed single-precision floating-point values.
	"rcpss",	// compute reciprocal of scalar single-precision floating-point values.
	"sqrtps",	// compute square roots of packed single-precision floating-point values.
	"sqrtss",	// compute square root of scalar single-precision floating-point values.
	"rsqrtps",// compute reciprocals of square roots of packed single-precision floating-point values.
	"rsqrtss",// compute reciprocal of square root of scalar single-precision floating-point values.
	"maxps",	// return maximum packed single-precision floating-point values.
	"maxss",	// return maximum scalar single-precision floating-point values.
	"minps",	// return minimum packed single-precision floating-point values.
	"minss",	// return minimum scalar single-precision floating-point values.

	/* 3) comparison */

	"cmpps",	// compare packed single-precision floating-point values.
	"cmpss",	// compare scalar single-precision floating-point values.
	"comiss",	// perform ordered comparison of scalar single-precision floating-point values and set flags in eflags register.
	"ucomiss",// perform unordered comparison of scalar single-precision floating-point values and set flags in eflags register.

	/* 4) logical */

	"andps",	// perform bitwise logical and of packed single-precision floating-point values.
	"andnps",	// perform bitwise logical and not of packed single-precision floating-point values.
	"orps",	// perform bitwise logical or of packed single-precision floating-point values.
	"xorps",	// perform bitwise logical xor of packed single-precision floating-point values.

	/* 5) shuffle and unpack */

	"shufps",	// shuffles values in packed single-precision floating-point operands.
	"unpckhps",// unpacks and interleaves the two high-order values from two single-precision floating-point operands.
	"unpcklps",// unpacks and interleaves the two low-order values from two single-precision floating-point operands.

	/* 6) conversion */

	"cvtpi2ps",// convert packed doubleword integers to packed single-precision floating-point values.
	"cvtsi2ss",// convert doubleword integer to scalar single-precision floating-point value.
	"cvtps2pi",// convert packed single-precision floating-point values to packed doubleword integers.
	"cvttps2pi",// convert with truncation packed single-precision floating-point values to packed doubleword integers.
	"cvtss2si",// convert a scalar single-precision floating-point value to a doubleword integer.
	"cvttss2si",// convert with truncation a scalar single-precision floating-point value to a scalar doubleword integer.

	/* 7) mxcsr state management */

	"ldmxcsr",// load mxcsr register.
	"stmxcsr",// save mxcsr register state.

	/* 8) 64-bit simd integer */

	"pavgb",	// compute average of packed unsigned byte integers.
	"pavgw",	// compute average of packed unsigned word integers.
	"pextrwsse",// extract word.
	"pinsrw",	// insert word.
	"pmaxub",	// maximum of packed unsigned byte integers.
	"pmaxsw",	// maximum of packed signed word integers.
	"pminub",	// minimum of packed unsigned byte integers.
	"pminsw",	// minimum of packed signed word integers.
	"pmovmskb",// move byte mask.
	"pmulhuw",// multiply packed unsigned integers and store high result.
	"psadbw",	// compute sum of absolute differences.
	"pshufw",	// shuffle packed integer word in mmx register.

	/* 9) cacheability control, prefetch, and ordering */

	"maskmovq",// non-temporal store of selected bytes from an mmx register into memory.
	"movntq",	// non-temporal store of quadword from an mmx register into memory.
	"movntps",// non-temporal store of four packed single-precision floating-point values from an xmm register into memory.
	"prefetchh",// load 32 or more of bytes from memory to a selected level of the processor’s cache hierarchy.
	"sfence",	// serializes store operations.

	//////////
	// sse2 //
	//////////

	/* 1) data movement */

	"movapd",	// move two aligned packed double-precision floating-point values between xmm registers or between and xmm register and memory.
	"movupd",	// move two unaligned packed double-precision floating-point values between xmm registers or between and xmm register and memory.
	"movhpd",	// move high packed double-precision floating-point value to an from the high quadword of an xmm register and memory.
	"movlpd",	// move low packed single-precision floating-point value to an from the low quadword of an xmm register and memory.
	"movmskpd",// extract sign mask from two packed double-precision floating-point values.
	"movsdxmm",// move scalar double-precision floating-point value between xmm registers or between an xmm register and memory.

	/* 2) packed arithmetic */

	"addpd",	// add packed double-precision floating-point values.
	"addsd",	// add scalar double precision floating-point values.
	"subpd",	// subtract packed double-precision floating-point values.
	"subsd",	// subtract scalar double-precision floating-point values.
	"mulpd",	// multiply packed double-precision floating-point values.
	"mulsd",	// multiply scalar double-precision floating-point values.
	"divpd",	// divide packed double-precision floating-point values.
	"divsd",	// divide scalar double-precision floating-point values.
	"sqrtpd",	// compute packed square roots of packed double-precision floating-point values.
	"sqrtsd",	// compute scalar square root of scalar double-precision floating-point values.
	"maxpd",	// return maximum packed double-precision floating-point values.
	"maxsd",	// return maximum scalar double-precision floating-point values.
	"minpd",	// return minimum packed double-precision floating-point values.
	"minsd",	// return minimum scalar double-precision floating-point values.

	/* 3) logical */

	"andpd",	// perform bitwise logical and of packed double-precision floating-point values.
	"andnpd",	// perform bitwise logical and not of packed double-precision floating-point values.
	"orpd",	// perform bitwise logical or of packed double-precision floating-point values.
	"xorpd",	// perform bitwise logical xor of packed double-precision floating-point values.

	/* 4) compare */

	"cmppd",	// compare packed double-precision floating-point values.
	"cmpsdf",	// compare scalar double-precision floating-point values.
	"comisd",	// perform ordered comparison of scalar double-precision floating-point values and set flags in eflags register.
	"ucomisd",// perform unordered comparison of scalar double-precision floating-point values and set flags in eflags register.

	/* 5) shuffle and unpack */

	"shufpd",	// shuffles values in packed double-precision floating-point operands.
	"unpckhpd",// unpacks and interleaves the high values from two packed double-precision floating-point operands.
	"unpcklpd",// unpacks and interleaves the low values from two packed double-precision floating-point operands.

	/* 6) conversion */

	"cvtpd2pi",// convert packed double-precision floating-point values to packed doubleword integers.
	"cvttpd2pi",// convert with truncation packed double-precision floating-point values to packed double-word integers.
	"cvtpi2pd",// convert packed doubleword integers to packed double-precision floating-point values.
	"cvtpd2dq",// convert packed double-precision floating-point values to packed doubleword integers.
	"cvttpd2dq",// convert with truncation packed double-precision floating-point values to packed double-word integers.
	"cvtdq2pd",// convert packed doubleword integers to packed double-precision floating-point values.
	"cvtps2pd",// convert packed single-precision floating-point values to packed double-precision floating-point values.
	"cvtpd2ps",// convert packed double-precision floating-point values to packed single-precision floating-point values.
	"cvtss2sd",// convert scalar single-precision floating-point values to scalar double-precision floating-point values.
	"cvtsd2ss",// convert scalar double-precision floating-point values to scalar single-precision floating-point values.
	"cvtsd2si",// convert scalar double-precision floating-point values to a doubleword integer.
	"cvttsd2si",// convert with truncation scalar double-precision floating-point values to scalar doubleword integers.
	"cvtsi2sd",// convert doubleword integer to scalar double-precision floating-point value.

	/* 7) packed single-precision floating-point */

	"cvtdq2ps",// convert packed doubleword integers to packed single-precision floating-point values.
	"cvtps2dq",// convert packed single-precision floating-point values to packed doubleword integers.
	"cvttps2dq",// convert with truncation packed single-precision floating-point values to packed double-word integers.

	/* 8) 128-bit simd integer */

	"movdqa",	// move aligned double quadword.
	"movdqu",	// move unaligned double quadword.
	"movq2dq",// move quadword integer from mmx to xmm registers.
	"movdq2q",// move quadword integer from xmm to mmx registers.
	"pmuludq",// multiply packed unsigned doubleword integers.
	"paddq",	// add packed quadword integers.
	"psubq",	// subtract packed quadword integers.
	"pshuflw",// shuffle packed low words.
	"pshufhw",// shuffle packed high words.
	"pshufd",	// shuffle packed doublewords.
	"pslldq",	// shift double quadword left logical.
	"psrldq",	// shift double quadword right logical.
	"punpckhqdq",// unpack high quadwords.
	"punpcklqdq",// unpack low quadwords.

	/* 9) cacheability control and ordering */

	"lfence",	// serializes load operations.
	"mfence",	// serializes load and store operations.
	"pause",	// improves the performance of “spin-wait loops”.
	"maskmovdqu",// non-temporal store of selected bytes from an xmm register into memory.
	"movntpd",// non-temporal store of two packed double-precision floating-point values from an xmm register into memory.
	"movntdq",// non-temporal store of double quadword from an xmm register into memory.
	"movnti",	// non-temporal store of a doubleword from a general-purpose register into memory.

	//////////
	// sse3 //
	//////////

	/* 1) x87-fp integer conversion */

	"fisttp",	// behaves like the fistp instruction but uses truncation, irrespective of the rounding mode specified in the floating-point control word (fcw).

	/* 2) specialized 128-bit unaligned data load */

	"lddqu",	// special 128-bit unaligned load designed to avoid cache line splits.

	/* 3) simd floating-point packed add/sub */

	"addsubps",// performs single-precision addition on the second and fourth pairs of 32-bit data elements"
		//within the operands; single-precision subtraction on the first and third pairs.
	"addsubpd",// performs double-precision addition on the second pair of quadwords, and double-precision"
		//subtraction on the first pair.

	/* 4) simd floating-point horizontal add/sub */

	"haddps",	// performs a single-precision addition on contiguous data elements. the first data element"
		//of the result is obtained by adding the first and second elements of the first operand; the"
		//second element by adding the third and fourth elements of the first operand; the third by"
		//adding the first and second elements of the second operand; and the fourth by adding the"
		//third and fourth elements of the second operand.
	"hsubps",	// performs a single-precision subtraction on contiguous data elements. the first data"
		//element of the result is obtained by subtracting the second element of the first operand"
		//from the first element of the first operand; the second element by subtracting the fourth"
		//element of the first operand from the third element of the first operand; the third by"
		//subtracting the second element of the second operand from the first element of the second"
		//operand; and the fourth by subtracting the fourth element of the second operand from the"
		//third element of the second operand.
	"haddpd",	// performs a double-precision addition on contiguous data elements. the first data element"
		//of the result is obtained by adding the first and second elements of the first operand; the"
		//second element by adding the first and second elements of the second operand.
	"hsubpd",	// performs a double-precision subtraction on contiguous data elements. the first data"
		//element of the result is obtained by subtracting the second element of the first operand"
		//from the first element of the first operand; the second element by subtracting the second"
		//element of the second operand from the first element of the second operand.

	/* 5) simd floating-point load/move/duplicate */

	"movshdup",// loads/moves 128 bits; duplicating the second and fourth 32-bit data elements.
	"movsldup",// loads/moves 128 bits; duplicating the first and third 32-bit data elements.
	"movddup",// loads/moves 64 bits (bits[63:0] if the source is a register) and returns the same 64 bits in"
		//both the lower and upper halves of the 128-bit result register; duplicates the 64 bits from the source.

	/* 6) agent synchronization */

	"monitor",// sets up an address range used to monitor write-back stores.
	"mwait",	// enables a logical processor to enter into an optimized state while waiting for a write-back store to the address range set up by the monitor instruction.

	/* 7) horizontal addition/substraction */

	"phaddw",	// adds two adjacent, signed 16-bit integers horizontally from the source and destination operands and packs the signed 16-bit results to the destination operand.
	"phaddsw",// adds two adjacent, signed 16-bit integers horizontally from the source and destination operands and packs the signed, saturated 16-bit results to the destination operand.
	"phaddd",	// adds two adjacent, signed 32-bit integers horizontally from the source and destination operands and packs the signed 32-bit results to the destination operand.
	"phsubw",	// performs horizontal subtraction on each adjacent pair of 16-bit signed integers by"
		//subtracting the most significant word from the least significant word of each pair in the"
		//source and destination operands. the signed 16-bit results are packed and written to the destination operand.
	"phsubsw",// performs horizontal subtraction on each adjacent pair of 16-bit signed integers by"
		//subtracting the most significant word from the least significant word of each pair in the"
		//source and destination operands. the signed, saturated 16-bit results are packed and written to the destination operand.
	"phsubd",	// performs horizontal subtraction on each adjacent pair of 32-bit signed integers by"
		//subtracting the most significant doubleword from the least significant double word of each"
		//pair in the source and destination operands. the signed 32-bit results are packed and written to the destination operand.

	/* 8) packed absolute values */

	"pabsb",	// computes the absolute value of each signed byte data element.
	"pabsw",	// computes the absolute value of each signed 16-bit data element.
	"pabsd",	// computes the absolute value of each signed 32-bit data element.

	/* 9) multiply and packed signed and unsigned bytes */

	"pmaddubsw",// multiplies each unsigned byte value with the corresponding signed byte value to produce"
		//an intermediate, 16-bit signed integer. each adjacent pair of 16-bit signed values are"
		//added horizontally. the signed, saturated 16-bit results are packed to the destination operand.

	/* 10) packed multiply high with rounds and scale */

	"pmulhrsw",// multiplies vertically each signed 16-bit integer from the destination operand with the corre-"
		//sponding signed 16-bit integer of the source operand, producing intermediate, signed 32-"
		//bit integers. each intermediate 32-bit integer is truncated to the 18 most significant bits."
		//rounding is always performed by adding 1 to the least significant bit of the 18-bit interme-"
		//diate result. the final result is obtained by selecting the 16 bits immediately to the right of"
		//the most significant bit of each 18-bit intermediate result and packed to the destination operand.

	/* 11) packed shuffle bytes */

	"pshufb",	// permutes each byte in place, according to a shuffle control mask. the least significant"
		//three or four bits of each shuffle control byte of the control mask form the shuffle index."
		//the shuffle mask is unaffected. if the most significant bit (bit 7) of a shuffle control byte is"
		//set, the constant zero is written in the result byte.

	/* 12) packed sign */

	"psignb",	// negates each signed integer element of the destination operand if the sign of the corresponding data element in the source operand is less than zero.
	"psignw",	// negates each signed integer element of the destination operand if the sign of the corresponding data element in the source operand is less than zero.
	"psignd",	// negates each signed integer element of the destination operand if the sign of the corresponding data element in the source operand is less than zero.

	/* 13) packed align right */

	"palignr",// source operand is appended after the destination operand forming an intermediate value"
		//of twice the width of an operand. the result is extracted from the intermediate value into"
		//the destination operand by selecting the 128 bit or 64 bit value that are right-aligned to the"
		//byte offset specified by the immediate value.

	//////////
	// sse4 //
	//////////

	/* 1) dword multiply */

	"pmulld",	// returns four lower 32-bits of the 64-bit results of signed 32-bit integer multiplies.
	"pmuldq",	// returns two 64-bit signed result of signed 32-bit integer multiplies.

	/* 2) floating-point dot product */

	"dppd",	// perform double-precision dot product for up to 2 elements and broadcast.
	"dpps",	// perform single-precision dot products for up to 4 elements and broadcast.

	/* 3) streaming load hint */

	"movntdqa",// provides a non-temporal hint that can cause adjacent 16-byte items within an aligned 64-"
		//byte region (a streaming line) to be fetched and held in a small set of temporary buffers"
		//(“streaming load buffers”). subsequent streaming loads to other aligned 16-byte items in"
		// the same streaming line may be supplied from the streaming load buffer and can improve throughput.

	/* 4) packed blending */

	"blendpd",// conditionally copies specified double-precision floating-point data elements in the source"
		//operand to the corresponding data elements in the destination, using an immediate byte control.
	"blendps",// conditionally copies specified single-precision floating-point data elements in the source"
		//operand to the corresponding data elements in the destination, using an immediate byte control.
	"blendvpd",// conditionally copies specified double-precision floating-point data elements in the source"
		//operand to the corresponding data elements in the destination, using an implied mask.
	"blendvps",// conditionally copies specified single-precision floating-point data elements in the source"
		//operand to the corresponding data elements in the destination, using an implied mask.
	"pblendvb",//  conditionally copies specified byte elements in the source operand to the corresponding"
		//elements in the destination, using an implied mask.
	"pblendw",// conditionally copies specified word elements in the source operand to the corresponding"
		//elements in the destination, using an immediate byte control.

	/* 5) packed integer min/max */

	"pminuw",	// compare packed unsigned word integers.
	"pminud",	// compare packed unsigned dword integers.
	"pminsb",	// compare packed signed byte integers.
	"pminsd",	// compare packed signed dword integers.
	"pmaxuw",	// compare packed unsigned word integers.
	"pmaxud",	// compare packed unsigned dword integers.
	"pmaxsb",	// compare packed signed byte integers.
	"pmaxsd",	// compare packed signed dword integers.

	/* 6) floating point round with selectable rounding mode */

	"roundps",// round packed single precision floating-point values into integer values and return rounded floating-point values.
	"roundpd",// round packed double precision floating-point values into integer values and return rounded floating-point values.
	"roundss",// round the low packed single precision floating-point value into an integer value and return a rounded floating-point value.
	"roundsd",// round the low packed double precision floating-point value into an integer value and return a rounded floating-point value.

	/* 7) insertion and extractions from xmm registers */

	"extractps",// extracts a single-precision floating-point value from a specified offset in an xmm register"
		//and stores the result to memory or a general-purpose register.
	"insertps",// inserts a single-precision floating-point value from either a 32-bit memory location or"
		//selected from a specified offset in an xmm register to a specified offset in the destination"
		//xmm register. in addition, insertps allows zeroing out selected data elements in the destination, using a mask.
	"pinsrb",	// insert a byte value from a register or memory into an xmm register.
	"pinsrd",	// insert a dword value from 32-bit register or memory into an xmm register.
	"pinsrq",	// insert a qword value from 64-bit register or memory into an xmm register.
	"pextrb",	// extract a byte from an xmm register and insert the value into a general-purpose register or memory.
	"pextrw",	// extract a word from an xmm register and insert the value into a general-purpose register or memory.
	"pextrd",	// extract a dword from an xmm register and insert the value into a general-purpose register or memory.
	"pextrq",	// extract a qword from an xmm register and insert the value into a general-purpose register or memory.

	/* 8) packed integer format conversion */

	"pmovsxbw",// sign extend the lower 8-bit integer of each packed word element into packed signed word integers.
	"pmovzxbw",// zero extend the lower 8-bit integer of each packed word element into packed signed word integers.
	"pmovsxbd",// sign extend the lower 8-bit integer of each packed dword element into packed signed dword integers.
	"pmovzxbd",// zero extend the lower 8-bit integer of each packed dword element into packed signed dword integers.
	"pmovsxwd",// sign extend the lower 16-bit integer of each packed dword element into packed signed dword integers.
	"pmovzxwd",// zero extend the lower 16-bit integer of each packed dword element into packed signed dword integers.
	"pmovsxbq",// sign extend the lower 8-bit integer of each packed qword element into packed signed qword integers.
	"pmovzxbq",// zero extend the lower 8-bit integer of each packed qword element into packed signed qword integers.
	"pmovsxwq",// sign extend the lower 16-bit integer of each packed qword element into packed signed qword integers.
	"pmovzxwq",//  zero extend the lower 16-bit integer of each packed qword element into packed signed qword integers.
	"pmovsxdq",// sign extend the lower 32-bit integer of each packed qword element into packed signed qword integers.
	"pmovzxdq",// zero extend the lower 32-bit integer of each packed qword element into packed signed qword integers.

	/* 9) improved sums of absolute differences (sad) for 4-byte blocks */

	"mpsadbw",// performs eight 4-byte wide sum of absolute differences operations to produce eight word integers.

	/* 10) horizontal search */

	"phminposuw",// finds the value and location of the minimum unsigned word from one of 8 horizontally"
		//packed unsigned words. the resulting value and location (offset within the source) are"
		//packed into the low dword of the destination xmm register.

	/* 11) packed test */

	"ptest",	// performs a logical and between the destination with this mask and sets the zf flag if the"
		//result is zero. the cf flag (zero for test) is set if the inverted mask and’d with the destination is all zeroes.

	/* 12) packed qword equality comparisons */

	"pcmpeqq",// 128-bit packed qword equality test.

	/* 13) dword packing with unsigned saturation */

	"packusdw",// packusdw packs dword to word with unsigned saturation.

	/* 14) string and text processing */

	"pcmpestri",// packed compare explicit-length strings, return index in ecx/rcx.
	"pcmpestrm",// packed compare explicit-length strings, return mask in xmm0.
	"pcmpistri",// packed compare implicit-length strings, return index in ecx/rcx.
	"pcmpistrm",// packed compare implicit-length strings, return mask in xmm0.

	/* 15) packed comparison simd integer */

	"pcmpgtq",// performs logical compare of greater-than on packed integer quadwords.

	//////////////////////////
	// aes-ni and pclmulqdq //
	//////////////////////////

	"aesdec",	// perform an aes decryption round using an 128-bit state and a round key.
	"aesdeclast",// perform the last aes decryption round using an 128-bit state and a round key.
	"aesenc",	// perform an aes encryption round using an 128-bit state and a round key.
	"aesenclast",// perform the last aes encryption round using an 128-bit state and a round key.
	"aesimc",	// perform an inverse mix column transformation primitive.
	"aeskeygenassist",// assist the creation of round keys with a key expansion schedule.
	"pclmulqdq",// perform carryless multiplication of two 64-bit numbers.

	//////////////////////////////////////
	// advanced vector extensions (avx) //
	//////////////////////////////////////

	"vbroadcastf128",	// broadcast 128-bit floating-point values in mem to low and high 128-bits in ymm1.
	"vbroadcastsd",	// broadcast double-precision floating-point element in mem to four locations in ymm1.
	"vbroadcastss",	// broadcast single-precision floating-point element in mem to eight locations in ymm1.
	"vextractf128",	// extracts 128-bits of packed floating-point values from ymm2 and store results in xmm1/mem.
	"vinsertf128",	// insert 128-bits of packed floating-point values from xmm3/mem and the remaining values from ymm2 into ymm1.
	"vmaskmovps",// load packed single-precision values from mem using mask in ymm2 and store in ymm1./store packed single-precision values from ymm2 mask in ymm1.
	"vmaskmovpd",// load packed double-precision values from mem using mask in ymm2 and store in ymm1./store packed double-precision values from ymm2 using mask in ymm1.
	"vpermilpd",// permute double-precision floating-point values in ymm2 using controls from xmm3/mem and store result in ymm1.
	"vpermilps",// permute single-precision floating-point values in ymm2 using controls from ymm3/mem	and store result in ymm1.
	"vperm2f128",// permute 128-bit floating-point fields in ymm2 and ymm3/mem using controls from imm8	and store result in ymm1.
	"vtestps",// set zf if ymm2/mem and ymm1 result is all 0s in packed single-precision sign bits. set cf"
		//if ymm2/mem and not ymm1 result is all 0s in packed single-precision sign bits.
	"vtestpd",// set zf if ymm2/mem and ymm1 result is all 0s in packed double-precision sign bits. set"
		//cf if ymm2/mem and not ymm1 result is all 0s in packed double-precision sign bits.
	"vzeroall",// zero all ymm registers.
	"vzeroupper",// zero upper 128 bits of all ymm registers.

	//////////////////////////////////////
	// 16-bit floating-point conversion //
	//////////////////////////////////////

	"vcvtph2ps",// convert eight/four data element containing 16-bit floating-point data into eight/four single-precision floating-point data.
	"vcvtps2ph",// convert eight/four data element containing single-precision floating-point data into eight/four 16-bit floating-point data

	//////////////////////////////
	// fused-multiply add (fma) //
	//////////////////////////////

	"vfmadd132pd",	// fused multiply-add of packed double-precision floating-point values.
	"vfmadd213pd",	// fused multiply-add of packed double-precision floating-point values.
	"vfmadd231pd",	// fused multiply-add of packed double-precision floating-point values.
	"vfmadd132ps",	// fused multiply-add of packed single-precision floating-point values.
	"vfmadd213ps",	// fused multiply-add of packed single-precision floating-point values.
	"vfmadd231ps",	// fused multiply-add of packed single-precision floating-point values.
	"vfmadd132sd",	// fused multiply-add of scalar double-precision floating-point values.
	"vfmadd213sd",	// fused multiply-add of scalar double-precision floating-point values.
	"vfmadd231sd",	// fused multiply-add of scalar double-precision floating-point values.
	"vfmadd132ss",	// fused multiply-add of scalar single-precision floating-point values.
	"vfmadd213ss",	// fused multiply-add of scalar single-precision floating-point values.
	"vfmadd231ss",	// fused multiply-add of scalar single-precision floating-point values.
	"vfmaddsub132pd",	// fused multiply-alternating add/subtract of packed double-precision floating-point values.
	"vfmaddsub213pd",	// fused multiply-alternating add/subtract of packed double-precision floating-point values.
	"vfmaddsub231pd",	// fused multiply-alternating add/subtract of packed double-precision floating-point values.
	"vfmaddsub132ps",	// fused multiply-alternating add/subtract of packed single-precision floating-point values.
	"vfmaddsub213ps",	// fused multiply-alternating add/subtract of packed single-precision floating-point values.
	"vfmaddsub231ps",	// fused multiply-alternating add/subtract of packed single-precision floating-point values.
	"vfmsubadd132pd",	// fused multiply-alternating subtract/add of packed double-precision floating-point values.
	"vfmsubadd213pd",	// fused multiply-alternating subtract/add of packed double-precision floating-point values.
	"vfmsubadd231pd",	// fused multiply-alternating subtract/add of packed double-precision floating-point values.
	"vfmsubadd132ps",	// fused multiply-alternating subtract/add of packed single-precision floating-point values.
	"vfmsubadd213ps",	// fused multiply-alternating subtract/add of packed single-precision floating-point values.
	"vfmsubadd231ps",	// fused multiply-alternating subtract/add of packed single-precision floating-point values.
	"vfmsub132pd",	// fused multiply-subtract of packed double-precision floating-point values.
	"vfmsub213pd",	// fused multiply-subtract of packed double-precision floating-point values.
	"vfmsub231pd",	// fused multiply-subtract of packed double-precision floating-point values.
	"vfmsub132ps",	// fused multiply-subtract of packed single-precision floating-point values.
	"vfmsub213ps",	// fused multiply-subtract of packed single-precision floating-point values.
	"vfmsub231ps",	// fused multiply-subtract of packed single-precision floating-point values.
	"vfmsub132sd",	// fused multiply-subtract of scalar double-precision floating-point values.
	"vfmsub213sd",	// fused multiply-subtract of scalar double-precision floating-point values.
	"vfmsub231sd",	// fused multiply-subtract of scalar double-precision floating-point values.
	"vfmsub132ss",	// fused multiply-subtract of scalar single-precision floating-point values.
	"vfmsub213ss",	// fused multiply-subtract of scalar single-precision floating-point values.
	"vfmsub231ss",	// fused multiply-subtract of scalar single-precision floating-point values.
	"vfnmadd132pd",	// fused negative multiply-add of packed double-precision floating-point values.
	"vfnmadd213pd",	// fused negative multiply-add of packed double-precision floating-point values.
	"vfnmadd231pd",	// fused negative multiply-add of packed double-precision floating-point values.
	"vfnmadd132ps",	// fused negative multiply-add of packed single-precision floating-point values.
	"vfnmadd213ps",	// fused negative multiply-add of packed single-precision floating-point values.
	"vfnmadd231ps",	// fused negative multiply-add of packed single-precision floating-point values.
	"vfnmadd132sd",	// fused negative multiply-add of scalar double-precision floating-point values.
	"vfnmadd213sd",	// fused negative multiply-add of scalar double-precision floating-point values.
	"vfnmadd231sd",	// fused negative multiply-add of scalar double-precision floating-point values.
	"vfnmadd132ss",	// fused negative multiply-add of scalar single-precision floating-point values.
	"vfnmadd213ss",	// fused negative multiply-add of scalar single-precision floating-point values.
	"vfnmadd231ss",	// fused negative multiply-add of scalar single-precision floating-point values.
	"vfnmsub132pd",	// fused negative multiply-subtract of packed double-precision floating-point values.
	"vfnmsub213pd",	// fused negative multiply-subtract of packed double-precision floating-point values.
	"vfnmsub231pd",	// fused negative multiply-subtract of packed double-precision floating-point values.
	"vfnmsub132ps",	// fused negative multiply-subtract of packed single-precision floating-point values.
	"vfnmsub213ps",	// fused negative multiply-subtract of packed single-precision floating-point values.
	"vfnmsub231ps",	// fused negative multiply-subtract of packed single-precision floating-point values.
	"vfnmsub132sd",	// fused negative multiply-subtract of scalar double-precision floating-point values.
	"vfnmsub213sd",	// fused negative multiply-subtract of scalar double-precision floating-point values.
	"vfnmsub231sd",	// fused negative multiply-subtract of scalar double-precision floating-point values.
	"vfnmsub132ss",	// fused negative multiply-subtract of scalar single-precision floating-point values.
	"vfnmsub213ss",	// fused negative multiply-subtract of scalar single-precision floating-point values.
	"vfnmsub231ss",	// fused negative multiply-subtract of scalar single-precision floating-point values.

	/////////////////////////////////////////
	// advanced vector extensions 2 (avx2) //
	/////////////////////////////////////////

	"vpermd",	// permute doublewords in ymm3/m256 using indexes in ymm2 and store the result in ymm1.
	"vpermpd",// permute double-precision fp elements in ymm2/m256 using indexes in imm8 and store the result in ymm1.
	"vpermps",// permute single-precision fp elements in ymm3/m256 using indexes in ymm2 and store the result in ymm1
	"vpermq",	// permute quadwords in ymm2/m256 using indexes in imm8 and store the result in ymm1.
	"vpsllvd",// shift doublewords in xmm2 left by amount specified in the corresponding element of"
		//xmm3/m128 or ymm3/m256 while shifting in 0s.
	"vpsllvq",// shift quadwords in xmm2 left by amount specified in the corresponding element of"
		//xmm3/m128 or ymm3/m256 while shifting in 0s.
	"vpsravd",// shift doublewords in xmm2 right by amount specified in the corresponding element of"
		//xmm3/m128 while shifting in the sign bits.
	"vpsrlvd",// shift doublewords in xmm2 right by amount specified in the corresponding element of"
		//xmm3/m128 or ymm3/m256 while shifting in 0s.
	"vpsrlvq",// shift quadwords in xmm2 right by amount specified in the corresponding element of"
		//xmm3/m128 or ymm3/m256 while shifting in 0s.
	"vgatherdd",// using dword indices specified in vm32x/y, gather dword values from memory conditioned on"
		//mask specified by x/ymm2. conditionally gathered elements are merged into x/ymm1.
	"vgatherqd",// using qword indices specified in vm64x/y, gather dword values from memory conditioned on"
		//mask specified by x/ymm2. conditionally gathered elements are merged into x/ymm1.
	"vgatherdpd",// using dword indices specified in vm32x, gather double-precision fp values from memory"
		//conditioned on mask specified by x/ymm2. conditionally gathered elements are merged into x/ymm1.
	"vgatherqpd",// using qword indices specified in vm64x, gather double-precision fp values from memory"
		//conditioned on mask specified by x/ymm2. conditionally gathered elements are merged into x/ymm1.
	"vgatherdps",// using dword indices specified in vm32x, gather single-precision fp values from memory"
		//conditioned on mask specified by xmm2. conditionally gathered elements are merged into xmm1.
	"vgatherqps",// using qword indices specified in vm64x/y, gather single-precision fp values from memory"
		//conditioned on mask specified by x/ymm2. conditionally gathered elements are merged into x/ymm1.
	"vgatherdq",// using dword indices specified in vm32x, gather qword values from memory conditioned on"
		//mask specified by x/ymm2. conditionally gathered elements are merged into x/ymm1.
	"vgatherqq",// using qword indices specified in vm64x/y, gather qword values from memory conditioned on"
		//mask specified by x/ymm2. conditionally gathered elements are merged into x/ymm1.

	////////////////////////////////////////////////////
	// transactional synchronization extensions (tsx) //
	////////////////////////////////////////////////////

	"xabort",	// abort an rtm transaction execution.
	"xacquire",// prefix hint to the beginning of an hle transaction region.
	"xrelease",// prefix hint to the end of an hle transaction region.
	"xbegin",	// transaction begin of an rtm transaction region.
	"xend",	// transaction end of an rtm transaction region.
	"xtest",	// test if executing in a transactional region.

	////////////////////
	// sha extensions //
	////////////////////

	"sha1msg1",// perform an intermediate calculation for the next four sha1 message dwords from the previous message dwords.
	"sha1msg2",// perform the final calculation for the next four sha1 message dwords from the intermediate message dwords.
	"sha1nexte",// calculate sha1 state e after four rounds.
	"sha1rnds4",// perform four rounds of sha1 operations.
	"sha256msg1",// perform an intermediate calculation for the next four sha256 message dwords.
	"sha256msg2",// perform the final calculation for the next four sha256 message dwords.
	"sha256rnds2",	// perform two rounds of sha256 operations.

	//////////////////////////////////////////////
	// advanced vector extensions 512 (avx-512) //
	//////////////////////////////////////////////

	"valignd",// perform dword alignment of two concatenated source vectors.
	"valignq",// perform qword alignment of two concatenated source vectors.
	"vblendmpd",// replace the vblendvpd instruction (using opmask as select control).
	"vblendmps",// replace the vblendvps instruction (using opmask as select control).
	"vcompresspd",	// compress packed dp elements of a vector.
	"vcompressps",	// compress packed sp elements of a vector.
	"vcvtpd2udq",// convert packed dp fp elements of a vector to packed unsigned 32-bit integers.
	"vcvtps2udq", 	// convert packed sp fp elements of a vector to packed unsigned 32-bit integers.
	"vcvtqq2pd",// convert packed signed 64-bit integers to packed dp fp elements.
	"vcvtqq2ps",// convert packed signed 64-bit integers to packed sp fp elements.
	"vcvtsd2usi",// convert the low dp fp element of a vector to an unsigned integer.
	"vcvtss2usi",// convert the low sp fp element of a vector to an unsigned integer.
	"vcvtudq2pd",// convert packed unsigned 32-bit integers to packed dp fp elements.
	"vcvtudq2ps",// convert packed unsigned 32-bit integers to packed sp fp elements.
	"vcvtusi2usd",	// convert an unsigned integer to the low dp fp element and merge to a vector.
	"vcvtusi2uss",	// convert an unsigned integer to the low sp fp element and merge to a vector.
	"vexpandpd",// expand packed dp elements of a vector.
	"vexpandps",// expand packed sp elements of a vector.
	"vextractf32x4",	// extract a vector from a full-length vector with 32-bit granular update.
	"vextractf64x4",	// extract a vector from a full-length vector with 64-bit granular update.
	"vextracti32x4",	// extract a vector from a full-length vector with 32-bit granular update.
	"vextracti64x4",	// extract a vector from a full-length vector with 64-bit granular update.
	"vfixupimmpd",	// perform fix-up to special values in dp fp vectors.
	"vfixupimmps",	// perform fix-up to special values in sp fp vectors.
	"vfixupimmsd",	// perform fix-up to special values of the low dp fp element.
	"vfixupimmss",	// perform fix-up to special values of the low sp fp element.
	"vgetexppd",// convert the exponent of dp fp elements of a vector into fp values.
	"vgetexpps",// convert the exponent of sp fp elements of a vector into fp values.
	"vgetexpsd",// convert the exponent of the low dp fp element in a vector into fp value.
	"vgetexpss",// convert the exponent of the low sp fp element in a vector into fp value.
	"vgetmantpd",// convert the mantissa of dp fp elements of a vector into fp values.
	"vgetmantps",// convert the mantissa of sp fp elements of a vector into fp values.
	"vgetmantsd",// convert the mantissa of the low dp fp element of a vector into fp value.
	"vgetmantss",// convert the mantissa of the low sp fp element of a vector into fp value.
	"vinsertf32x4",	// insert a 128-bit vector into a full-length vector with 32-bit granular update.
	"vinsertf64x4",	// insert a 256-bit vector into a full-length vector with 64-bit granular update.
	"vmovdqa32",// vmovdqa with 32-bit granular conditional update.
	"vmovdqa64",// vmovdqa with 64-bit granular conditional update.
	"vmovdqu32",// vmovdqu with 32-bit granular conditional update.
	"vmovdqu64",// vmovdqu with 64-bit granular conditional update.
	"vpblendmd",// blend dword elements using opmask as select control.
	"vpblendmq",// blend qword elements using opmask as select control.
	"vpbroadcastd",	// broadcast from general-purpose register to vector register.
	"vpbroadcastq",	// broadcast from general-purpose register to vector register.
	"vpcmpd",	// compare packed signed dwords using specified primitive.
	"vpcmup",	// compare packed unsigned dwords using specified primitive.
	"vpcmpq",	// compare packed signed quadwords using specified primitive.
	"vpcmuq",	// compare packed unsigned quadwords using specified primitive.
	"vpcompressq",	// compress packed 64-bit elements of a vector.
	"vpcompressd",	// compress packed 32-bit elements of a vector.
	"vpermi2d",// full permute of two tables of dword elements overwriting the index vector.
	"vpermi2q",// full permute of two tables of qword elements overwriting the index vector.
	"vpermi2pd",// full permute of two tables of dp elements overwriting the index vector.
	"vpermi2ps",// full permute of two tables of sp elements overwriting the index vector.
	"vpermt2d",// full permute of two tables of dword elements overwriting one source table.
	"vpermt2q",// full permute of two tables of qword elements overwriting one source table.
	"vpermt2pd",// full permute of two tables of dp elements overwriting one source table.
	"vpermt2ps",// full permute of two tables of sp elements overwriting one source table.
	"vpexpandd",// expand packed dword elements of a vector.
	"vpexpandq",// expand packed qword elements of a vector.
	"vpmaxsq",// compute maximum of packed signed 64-bit integer elements.
	"vpmaxud",// compute maximum of packed unsigned 32-bit integer elements.
	"vpmaxuq",// compute maximum of packed unsigned 64-bit integer elements.
	"vpminsq",// compute minimum of packed signed 64-bit integer elements.
	"vpminud",// compute minimum of packed unsigned 32-bit integer elements.
	"vpminuq",// compute minimum of packed unsigned 64-bit integer elements.
	"vpmovsqb",// down convert qword elements in a vector to byte elements using truncation saturation.
	"vpmovusqb", // down convert qword elements in a vector to byte elements using truncation unsigned saturation.
	"vpmovsqw",// down convert qword elements in a vectorto word elements using truncation saturation.
	"vpmovusqw",// down convert qword elements in a vectorto word elements using truncation unsigned saturation.
	"vpmovsqd",// down convert qword elements in a vector to dword elements using truncation saturation.
	"vpmovusqd", // down convert qword elements in a vector to dword elements using truncation unsigned saturation.
	"vpmovsdb",// down convert dword elements in a vector to byte elements using truncation saturation.
	"vpmovusdb",// down convert dword elements in a vector to byte elements using truncation unsigned saturation.
	"vpmovsdw",// down convert dword elements in a vector to word elements using truncation saturation.
	"vpmovusdw",  	// down convert dword elements in a vector to word elements using truncation unsigned saturation.
	"vprold",	// rotate dword element left by a constant shift count with conditional update.
	"vprolq",	// rotate qword element left by a constant shift count with conditional update.
	"vprolvd",// rotate dword element left by shift counts specified in a vector with conditional update.
	"vprolvq",// rotate qword element left by shift counts specified in a vector with conditional update.
	"vprord",	// rotate dword element right by a constant shift count with conditional update.
	"vprorq",	// rotate qword element right by a constant shift count with conditional update.
	"vprorrd",// rotate dword element right by shift counts specified in a vector with conditional update.
	"vprorrq",// rotate qword element right by shift counts specified in a vector with conditional update.
	"vpscatterdd",	// scatter dword elements in a vector to memory using dword indices.
	"vpscatterdq",	// scatter qword elements in a vector to memory using dword indices.
	"vpscatterqd",	// scatter dword elements in a vector to memory using qword indices.
	"vpscatterqq",	// scatter qword elements in a vector to memory using qword indices.
	"vpsraq",	// shift qwords right by a constant shift count and shifting in sign bits.
	"vpsravq",// shift qwords right by shift counts in a vector and shifting in sign bits.
	"vptestnmd",// perform bitwise nand of dword elements of two vectors and write results to opmask.
	"vptestnmq",// perform bitwise nand of qword elements of two vectors and write results to opmask.
	"vpterlogd",// perform bitwise ternary logic operation of three vectors with 32-bit granular conditional update.
	"vpterlogq",// perform bitwise ternary logic operation of three vectors with 64-bit granular conditional update.
	"vptestmd",// perform bitwise and of dword elements of two vectors and write results to opmask.
	"vptestmq",// perform bitwise and of qword elements of two vectors and write results to opmask.
	"vrcp14pd",// compute approximate reciprocals of packed dp fp elements of a vector.
	"vrcp14ps",// compute approximate reciprocals of packed sp fp elements of a vector.
	"vrcp14sd",// compute the approximate reciprocal of the low dp fp element of a vector.
	"vrcp14ss",// compute the approximate reciprocal of the low sp fp element of a vector.
	"vrndscalepd",	// round packed dp fp elements of a vector to specified number of fraction bits.
	"vrndscaleps",	// round packed sp fp elements of a vector to specified number of fraction bits.
	"vrndscalesd",	// round the low dp fp element of a vector to specified number of fraction bits.
	"vrndscaless",	// round the low sp fp element of a vector to specified number of fraction bits.
	"vrsqrt14pd",// compute approximate reciprocals of square roots of packed dp fp elements of a vector.
	"vrsqrt14ps",// compute approximate reciprocals of square roots of packed sp fp elements of a vector.
	"vrsqrt14sd",// compute the approximate reciprocal of square root of the low dp fp element of a vector.
	"vrsqrt14ss",// compute the approximate reciprocal of square root of the low sp fp element of a vector.
	"vscalepd",// multiply packed dp fp elements of a vector by powers of two with exponents specified in a second vector.
	"vscaleps",// multiply packed sp fp elements of a vector by powers of two with exponents specified in a second vector.
	"vscalesd",// multiply the low dp fp element of a vector by powers of two with exponent specified in the corresponding element of a second vector.
	"vscaless",// multiply the low sp fp element of a vector by powers of two with exponent specified in the corresponding element of a second vector.
	"vscatterdd",// scatter sp fp elements in a vector to memory using dword indices.
	"vscatterdq",// scatter dp fp elements in a vector to memory using dword indices.
	"vscatterqd",// scatter sp fp elements in a vector to memory using qword indices.
	"vscatterqq",// scatter dp fp elements in a vector to memory using qword indices.
	"vshuff32x4",// shuffle 128-bit lanes of a vector with 32-bit granular conditional update.
	"vshuff64x4",// shuffle 128-bit lanes of a vector with 64-bit granular conditional update.
	"vshufi32x4",// shuffle 128-bit lanes of a vector with 32-bit granular conditional update.
	"vshufi64x4",// shuffle 128-bit lanes of a vector with 64-bit granular conditional update.
	"vcvtpd2qq",// convert packed dp fp elements of a vector to packed signed 64-bit integers.
	"vcvtpd2uqq",// convert packed dp fp elements of a vector to packed unsigned 64-bit integers.
	"vcvtps2qq",// convert packed sp fp elements of a vector to packed signed 64-bit integers.
	"vcvtps2uqq",// convert packed sp fp elements of a vector to packed unsigned 64-bit integers.
	"vcvtuqq2pd",// convert packed unsigned 64-bit integers to packed dp fp elements.
	"vcvtuqq2ps",// convert packed unsigned 64-bit integers to packed sp fp elements.
	"vextractf64x2",	// extract a vector from a full-length vector with 64-bit granular update.
	"vextracti64x2",	// extract a vector from a full-length vector with 64-bit granular update.
	"vfpclasspd",// test packed dp fp elements in a vector by numeric/special-value category.
	"vfpclassps",// test packed sp fp elements in a vector by numeric/special-value category.
	"vfpclasssd",// test the low dp fp element by numeric-value category.
	"vfpclassss",// test the low sp fp element by special-value category.
	"vinsertf64x2",	// insert a 128-bit vector into a full-length vector with 64-bit granular update.
	"vinserti64x2",	// insert a 128-bit vector into a full-length vector with 64-bit granular update.
	"vpmovm2d",// convert opmask register to vector register in 32-bit granularity.
	"vpmovm2q",// convert opmask register to vector register in 64-bit granularity.
	"vpmovb2d",// convert a vector register in 32-bit granularity to an opmask register.
	"vpmovq2m",// convert a vector register in 64-bit granularity to an opmask register.
	"vpmullq",// multiply packed signed 64-bit integer elements of two vectors and store low 64-bit signed result.
	"vrangepd",// perform range operation on each pair of dp fp elements of two vectors using specified range primitive in imm8.
	"vrangeps",// perform range operation on each pair of sp fp elements of two vectors using specified range primitive in imm8.
	"vrangesd",// perform range operation on the pair of low dp fp element of two vectors using specified range primitive in imm8.
	"vrangess",// perform range operation on the pair of low sp fp element of two vectors using specified range primitive in imm8.
	"vreducepd",// perform reduction operation on packed dp fp elements of a vector using specified reduction primitive in imm8.
	"vreduceps",// perform reduction operation on packed sp fp elements of a vector using specified reduction primitive in imm8.
	"vreducesd",// perform reduction operation on the low dp fp element of a vector using specified reduction primitive in imm8.
	"vreducess",// perform reduction operation on the low sp fp element of a vector using specified reduction primitive in imm8.
	"vdbpsadbw",// double block packed sum-absolute-differences on unsigned bytes.
	"vmovdqu8",// vmovdqu with 8-bit granular conditional update.
	"vmovdqu16",// vmovdqu with 16-bit granular conditional update.
	"vpblendmb",// replaces the vpblendvb instruction (using opmask as select control).
	"vpblendmw",// blend word elements using opmask as select control.
	"vpbroadcastb",	// broadcast from general-purpose register to vector register.
	"vpbroadcastw",	// broadcast from general-purpose register to vector register.
	"vpcmpb",	// compare packed signed bytes using specified primitive.
	"vpcmub",	// compare packed unsigned bytes using specified primitive.
	"vpcmpw",	// compare packed signed words using specified primitive.
	"vpcmuw",	// compare packed unsigned words using specified primitive.
	"vpermw",	// permute packed word elements.
	"vpermi2b",// full permute from two tables of byte elements overwriting the index vector.
	"vpermi2w",// full permute from two tables of word elements overwriting the index vector.
	"vpmovm2b",// convert opmask register to vector register in 8-bit granularity.
	"vpmovm2w",// convert opmask register to vector register in 16-bit granularity.
	"vpmovb2m",// convert a vector register in 8-bit granularity to an opmask register.
	"vpmovw2m",// convert a vector register in 16-bit granularity to an opmask register.
	"vpmovswb",// down convert word elements in a vector to byte elements using truncation saturation.
	"vpmovuswb",  	// down convert word elements in a vector to byte elements using truncation unsigned saturation.
	"vpsllvw",// shift word elements in a vector left by shift counts in a vector.
	"vpsravw",// shift words right by shift counts in a vector and shifting in sign bits.
	"vpsrlvw",// shift word elements in a vector right by shift counts in a vector.
	"vptestnmb",// perform bitwise nand of byte elements of two vectors and write results to opmask.
	"vptestnmw",// perform bitwise nand of word elements of two vectors and write results to opmask.
	"vptestmb",// perform bitwise and of byte elements of two vectors and write results to opmask.
	"vptestmw",// perform bitwise and of word elements of two vectors and write results to opmask.
	"vpbroadcastm",	// broadcast from opmask register to vector register.
	"vpconflictd",	// detect conflicts within a vector of packed 32-bit integers.
	"vpconflictq",	// detect conflicts within a vector of packed 64-bit integers.
	"vplzcntd",// count the number of leading zero bits of packed dword elements.
	"vplzcntq",// count the number of leading zero bits of packed qword elements.
	"kadd",	// add two 8/16/32/64-bit opmasks.
	"kand",	// logical and two 8/16/32/64-bit opmasks.
	"kandn",	// logical and not two 8/16/32/64-bit opmasks.
	"kmov",	// move from or move to opmask register of 8/16/32/64-bit data.
	"knot",	// bitwise not of two 8/16/32/64-bit opmasks.
	"kor",	// logical or two 8/16/32/64-bit opmasks.
	"kortest",// update eflags according to the result of bitwise or of two 8/16/32/64-bit opmasks.
	"kshiftl",// shift left 8/16/32/64-bit opmask by specified count.
	"kshiftr",// shift right 8/16/32/64-bit opmask by specified count.
	"ktest",	// update eflags according to the result of bitwise test of two 8/16/32/64-bit opmasks.
	"kunpck",	// unpack and interleave two 8/16/32-bit opmasks into 16/32/64-bit mask.
	"kxnor",	// bitwise logical xnor of two 8/16/32/64-bit opmasks.
	"kxor",	// logical xor of two 8/16/32/64-bit opmasks.
	"vexp2pd",// compute approximate base-2 exponential of packed dp fp elements of a vector.
	"vexp2ps",// compute approximate base-2 exponential of packed sp fp elements of a vector.
	"vexp2sd",// compute approximate base-2 exponential of the low dp fp element of a vector.
	"vexp2ss",// compute approximate base-2 exponential of the low sp fp element of a vector.
	"vrcp28pd",// compute approximate reciprocals to 28 bits of packed dp fp elements of a vector.
	"vrcp28ps",// compute approximate reciprocals to 28 bits of packed sp fp elements of a vector.
	"vrcp28sd",// compute the approximate reciprocal to 28 bits of the low dp fp element of a vector.
	"vrcp28ss",// compute the approximate reciprocal to 28 bits of the low sp fp element of a vector.
	"vrsqrt28pd",// compute approximate reciprocals of square roots to 28 bits of packed dp fp elements of a vector.
	"vrsqrt28ps",// compute approximate reciprocals of square roots to 28 bits of packed sp fp elements of a vector.
	"vrsqrt28sd",// compute the approximate reciprocal of square root to 28 bits of the low dp fp element of a vector.
	"vrsqrt28ss",// compute the approximate reciprocal of square root to 28 bits of the low sp fp element of a vector.
	"vgatherpf0dpd",	// sparse prefetch of packed dp fp vector with t0 hint using dword indices.
	"vgatherpf0dps",	// sparse prefetch of packed sp fp vector with t0 hint using dword indices.
	"vgatherpf0qpd",	// sparse prefetch of packed dp fp vector with t0 hint using qword indices.
	"vgatherpf0qps",	// sparse prefetch of packed sp fp vector with t0 hint using qword indices.
	"vgatherpf1dpd",	// sparse prefetch of packed sp fp vector with t1 hint using dword indices.
	"vgatherpf1dps",	// sparse prefetch of packed dp fp vector with t1 hint using dword indices.
	"vgatherpf1qpd",	// sparse prefetch of packed dp fp vector with t1 hint using qword indices.
	"vgatherpf1qps",	// sparse prefetch of packed sp fp vector with t1 hint using qword indices.
	"vscatterpf0dpd",	// sparse prefetch of packed dp fp vector with t0 hint to write using dword indices.
	"vscatterpf0dps",	// sparse prefetch of packed sp fp vector with t0 hint to write using dword indices.
	"vscatterpf0qpd",	// sparse prefetch of packed dp fp vector with t0 hint to write using qword indices.
	"vscatterpf0qps",	// sparse prefetch of packed sp fp vector with t0 hint to write using qword indices.
	"vscatterpf1dpd",	// sparse prefetch of packed dp fp vector with t1 hint to write using dword indices.
	"vscatterpf1dps",	// sparse prefetch of packed sp fp vector with t1 hint to write using dword indices.
	"vscatterpf1qpd",	// sparse prefetch of packed dp fp vector with t1 hint to write using qword indices.
	"vscatterpf1qps",	// sparse prefetch of packed sp fp vector with t1 hint to write using qword indices.

	/////////////
	// system  //
	/////////////

	"clac",	// clear ac flag in eflags register.
	"stac",	// set ac flag in eflags register.
	"lgdt",	// load global descriptor table (gdt) register.
	"sgdt",	// store global descriptor table (gdt) register.
	"lldt",	// load local descriptor table (ldt) register.
	"sldt",	// store local descriptor table (ldt) register.
	"ltr",	// load task register.
	"str",	// store task register.
	"lidt",	// load interrupt descriptor table (idt) register.
	"sidt",	// store interrupt descriptor table (idt) register.
	"lmsw",	// load machine status word.
	"smsw",	// store machine status word.
	"clts",	// clear the task-switched flag.
	"arpl",	// adjust requested privilege level.
	"lar",	// load access rights.
	"lsl",	// load segment limit.
	"verr",	// verify segment for reading.
	"verw",	// verify segment for writing.
	"invd",	// invalidate cache, no writeback.
	"wbinvd",	// invalidate cache, with writeback.
	"invlpg",	// invalidate tlb entry.
	"invpcid",// invalidate process-context identifier.
	"lock",	// perform atomic access to memory (can be applied to a number of general purpose instructions that provide memory source/destination access).
	"hlt",	// halt processor.
	"rsm",	// return from system management mode (smm).
	"rdmsr",	// read model-specific register.
	"wrmsr",	// write model-specific register.
	"rdpmc",	// read performance monitoring counters.
	"rdtsc",	// read time stamp counter.
	"rdtscp",	// read time stamp counter and processor id.
	"sysenter",// fast system call, transfers to a flat protected mode kernel at cpl = 0.
	"sysexit",// fast system call, transfers to a flat protected mode kernel at cpl = 3.
	"xsaves",	// save processor supervisor-mode extended states to memory.
	"xrstors",// restore processor supervisor-mode extended states from memory.
	"xsetbv",	// writes the state of an extended control register.
	"rdfsbase",// reads from fs base address at any privilege level.
	"rdgsbase",// reads from gs base address at any privilege level.
	"wrfsbase",// writes to fs base address at any privilege level.
	"wrgsbase",// writes to gs base address at any privilege level.
	
	/////////////////
	// 64-bit mode //
	/////////////////

	"cdqe",	// convert doubleword to quadword.
	"cmpsq",	// compare string operands.
	"cmpxchg16b",// compare rdx:rax with m128.
	"lodsq",	// load qword at address (r)si into rax.
	"movsq",	// move qword from address (r)si to (r)di.
	"stosq",	// store rax at address rdi.
	"swapgs",	// exchanges current gs base register value with value in msr address c0000102h.
	"syscall",// fast call to privilege level 0 system procedures.
	"sysret",	// return from fast systemcall.

	////////////////////////////////
	// virtual machine extensions //
	////////////////////////////////

	"vmptrld",// takes a single 64-bit source operand in memory. it makes the referenced vmcs active and current.
	"vmptrst",// takes a single 64-bit destination operand that is in memory. current-vmcs pointer is stored into the destination operand.
	"vmclear",// takes a single 64-bit operand in memory. the instruction sets the launch state of the vmcs"
		//referenced by the operand to “clear”, renders that vmcs inactive, and ensures that data"
		//for the vmcs have been written to the vmcs-data area in the referenced vmcs region.
	"vmread",	// reads a component from the vmcs (the encoding of that field is given in a register operand) and stores it into a destination operand.
	"vmwrite",// writes a component to the vmcs (the encoding of that field is given in a register operand) from a source operand.
	"vmlaunch",// launches a virtual machine managed by the vmcs. a vm entry occurs, transferring control to the vm.
	"vmresume",// resumes a virtual machine managed by the vmcs. a vm entry occurs, transferring control to the vm.
	"vmxoff",	// causes the processor to leave vmx operation.
	"vmxon",	// takes a single 64-bit source operand in memory. it causes a logical processor to enter vmx"
		//root operation and to use the memory referenced by the operand to support vmx operation.
	"invept",	//  invalidate cached extended page table (ept) mappings in the processor to synchronize"
		//address translation in virtual machines with memory-resident ept pages.
	"invvpid",// invalidate cached mappings of address translation based on the virtual processor id (vpid).
	"vmcall",	// allows a guest in vmx non-root operation to call the vmm for service. a vm exit occurs, transferring control to the vmm.
	"vmfunc",	// this instruction allows software in vmx non-root operation to invoke a vm function, which"
		//" is processor functionality enabled and configured by software in vmx root operation. no vm exit occurs.

	///////////////////////////
	// safer mode extensions //
	///////////////////////////

	"getsec_capabilities",	// returns the available leaf functions of the getsec instruction.
	"getsec_enteraccs",// loads an authenticated code chipset module and enters authenticated code execution mode.
	"getsec_exitac",	// exits authenticated code execution mode.
	"getsec_senter",	// establishes a measured launched environment (mle) which has its dynamic root of trust"
			//anchored to a chipset supporting intel trusted execution technology.
	"getsec_sexit",	// exits the mle.
	"getsec_parameters",// returns smx related parameter information.
	"getsec_smcrtl",	// smx mode control.
	"getsec_wakeup",	// wakes up sleeping logical processors inside an mle.

	//////////////////////////////////
	// memory protection extensions //
	//////////////////////////////////

	"bndmk",	// create a lowerbound and a upperbound in a register.
	"bndcl",	// check the address of a memory reference against a lowerbound.
	"bndcu",	// check the address of a memory reference against an upperbound in 1’s compliment form.
	"bndcn",	// check the address of a memory reference against an upperbound not in 1’s compliment form.
	"bndmov",	// copy or load from memory of the lowerbound and upperbound to a register./store to memory of the lowerbound and upperbound from a register.
	"bndldx",	// load bounds using address translation.
	"bndstx",	// store bounds using address translation.

	////////////////////////////////
	// software guards extensions //
	////////////////////////////////

	"encls_eadd",// add a page.
	"encls_eblock",	// block an epc page.
	"encls_ecreate",	// create an enclave.
	"encls_edbgrd",	// read data by debugger.
	"encls_edbgwr",	// write data by debugger.
	"encls_eextend",	// extend epc page measurement.
	"encls_einit",	// initialize an enclave.
	"encls_eldb",// load an epc page as blocked.
	"encls_eldu",// load an epc page as unblocked.
	"encls_epa",// add version array.
	"encls_eremove",	// remove a page from epc.
	"encls_etrack",	// activate eblock checks.
	"encls_ewb",// write back/invalidate an epc page.
	"encls_eenter",	// enter an enclave.
	"encls_eexit",	// exit an enclave.
	"encls_egetkey",	// create a cryptographic key.
	"encls_ereport",	// create a cryptographic report.
	"encls_eresume",	// re-enter an enclave.

	/////////////////////////////
	// shadow stack management //
	/////////////////////////////

	"clrssbsy",// clear busy bit in a supervisor shadow stack token.
	"incssp",	// increment the shadow stack pointer (ssp).
	"rdssp",	// read shadow stack point (ssp).
	"rstorssp",// restore a shadow stack pointer (ssp).
	"saveprevssp",	// save previous shadow stack pointer (ssp).
	"setssbsy",// set busy bit in a supervisor shadow stack token.
	"wrss",	// write to a shadow stack.
	"wruss",	// write to a user mode shadow stack.
	
	//////////////////////////////////
	// control transfer terminating //
	//////////////////////////////////

	"endbr32",// terminate an indirect branch in 32-bit and compatibility mode.
	"endbr64",// terminate an indirect branch in 64-bit mode.

	///todo: sort next 

	"vcvtdq2pd",// todo: undocumented desprition: varies per size spetialization
	"vcvtdq2ps",// todo: undocumented desprition: varies per size spetialization
	"vcvtpd2dq",// todo: undocumented desprition: varies per size spetialization
	"vcvtpd2ps",
	"vcvtps2dq",
	"vcvtps2pd",
	"vcvtsd2si",
	"vcvtsd2ss",
	"vcvtsi2sd",
	"vcvtsi2ss",
	"vcvtss2sd",
	"vcvtss2si",
	"vcvttpd2dq",
	"vcvttps2dq",
	"vcvttsd2si",
	"vcvttss2si",
	"vdivpd",
	"vdivps",
	"vdivsd",
	"vdppd",
	"vdpps",
	"encodekey256",	//  wrap a 256-bit aes key from xmm1:xmm0 into a key handle and store it in xmm0-3.
	"vextractps",
	"frndint",// round st(0) to an integer.
	"fxrstor",// restore the x87 fpu, mmx, xmm, and mxcsr register state from m512byte.
	"fxrstor64", // restore the x87 fpu, mmx, xmm, and mxcsr register state from m512byte.
	"fxsave",	// save the x87 fpu, mmx, xmm, and mxcsr register state to m512byte.
	"fxsave64",// save the x87 fpu, mmx, xmm, and mxcsr register state to m512byte.
	"gf2p8affineinvqb",	//  computes inverse affine transformation in the finite field gf(2^8).
	"vgf2p8affineinvqb",	// computes inverse affine transformation in the finite field gf(2^8).
	"gf2p8affineqb",	// computes affine transformation in the finite field gf(2^8).
	"vgf2p8affineqb", // computes affine transformation in the finite field gf(2^8).
	"gf2p8mulb",// multiplies elements in the finite field gf(2^8). 
	"vgf2p8mulb",// multiplies elements in the finite field gf(2^8).
	"vhaddpd",// horizontal add packed double-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	"vhaddps",// horizontal add packed single-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	"vhsubpd",// horizontal subtract packed double-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	"vhsubps",// horizontal subtract packed single-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	"vinsertps",//  insert a single-precision floating-point value selected by imm8 from xmm3/m32 and merge with values in"
		//	xmm2 at the specified destination element specified by imm8 and write out the result and zero out"
		//	destination elements in xmm1 as indicated in imm8.
	"int3",	// generate breakpoint trap.
	"int1",	// generate debug trap.
	"iretd",	// interrupt return (32-bit operand size).
	"iretq",	// interrupt return (64-bit operand size).

	/*
	"kandw",	// bitwise and 16 bits masks k2 and k3 and place result in k1.
	"kandb",	// bitwise and 8 bits masks k2 and k3 and place result in k1. 
	"kandq",	// bitwise and 64 bits masks k2 and k3 and place result in k1.
	"kandd",	// bitwise and 32 bits masks k2 and k3 and place result in k1.
	"kmovw",	// 
	"kmovb",	// 
	"kmovq",	// 
	"kmovd",	// 
	*/

	"vlddqu",	// load unaligned packed integer values from mem to (y/x)mm1.
	"vldmxcsr",//  load mxcsr register from m32.
	"loadiwkey",//  load internal wrapping key from xmm1, xmm2, and xmm0.
	"vmaskmovdqu",	// selectively write bytes from xmm1 to memory location using the byte mask in xmm2. the default memory location is specified by ds:di/edi/rdi.
	"vmaxpd",	// 
	"vmaxps",	//
	"vmaxsd",	// return the maximum scalar double-precision floating-point value between xmm3/m64 and xmm2.
	"vmaxss",	// return the maximum scalar single-precision floating-point value between xmm3/m32 and xmm2.
	"vminpd",	// 
	"vminps",	//
	"vminsd",	// return the minimum scalar double-precision floatingpoint value between xmm3/m64 and xmm2.
	"vminss",	//  return the minimum scalar single-precision floatingpoint value between xmm3/m32 and xmm2.
	"vmovapd",// 
	"vmovaps",//
	"vmovd",	//
	"vmovq",	// 
	"vmovddup",// 
	"movdiri",// move doubleword from (r32 to m32 / r64 to m64) using direct store.
	"movdir64b",// move 64-bytes as direct-store with guaranteed 64-byte write atomicity from the source memory operand"
		//address to destination memory address specified as offset to es segment in the register operand.
	"vmovdqu",// 
	"vmovhpd",//
	"vmovhps",//
	"vmovlhps",// merge two packed single-precision floating-point values from low quadword of xmm3 and low quadword of xmm2.
	"vmovlpd",// 
	"vmovlps",//
	"vmovmskpd",// extract (2/4)-bit sign mask from (x/y)mm2 and store in reg. the upper bits of r32 or r64 are zeroed.
	"vmovmskps",// extract (4/8)-bit sign mask from (x/y)mm2 and store in reg. the upper bits of r32 or r64 are zeroed.
	"vmovntdqa",// 
	"vmovntdq",// 
	"vmovntpd",//
	"vmovntps",// 
	"vmovsd",	// 
	"vmovshdup",// 
	"vmovsldup",// 
	"vmovss",	// 
	"movsxd",	//
	"vmovupd",// 
	"vmovups",// 
	"vmpsadbw",// 
	"vmulpd",	//
	"vmulps",	// 
	"vmulsd",	//
	"vmulss",	// multiply the low single-precision floating-point value in xmm3/m32 by the low single-precision floating-point value in xmm2.
	"vorpd",	//
	"vorps",	//
	"vpabsb",	// compute the absolute value of bytes in (x/y)mm2/m(128/256) and store unsigned result in (x/y)mm1.
	"vpabsw",	// 
	"vpabsd",	//
	"vpacksswb",//
	"vpackssdw",//
	"vpackusdw",//
	"vpackuswb",//
	"vpaddb",	//
	"vpaddw",	//
	"vpaddd",	//
	"vpaddq",	//
	"vpaddsb",//
	"vpaddsw",//
	"vpalignr",//
	"vpand",	//
	"vpandd",	//
	"vpandq",	//
	"vpandn",	//
	"vpandnd",//
	"vpandnq",//
	"vpavgb",	//
	"vpavgw",	//
	"vpclmulqdq",//
	"vpcmpeqb",//
	"vpcmpeqw",//
	"vpcmpeqd",//
	"vpcmpeqq",//
	"vpcmpestri",// perform a packed comparison of string data with explicit lengths, generating an index, and storing the result in ecx.
	"vpcmpestrm",//
	"vpcmpgtb",//
	"vpcmpgtw",//
	"vpcmpgtd",//
	"vpcmpgtq",//
	"vpcmpistri",//
	"vpcmpistrm",//
	"pconfig",// this instruction is used to execute functions for configuring platform features.
	"pdep",	// parallel deposit of bits from r(32/64)b using mask in r/m(32/64), result is written to r(32/64)a.
	"vpextrb",// extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. the upper bits of r64/r32 is filled with zeros.
	"vpextrd",// extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r32/m32.
	"vpextrq",//  extract a qword integer value from xmm2 at the source dword offset specified by imm8 into r64/m64.
	"vpextrw",// 
	"vphaddw",// add 16-bit integers horizontally, pack to (x/y)mm1.
	"vphaddd",// add 32-bit integers horizontally, pack to (x/y)mm1.
	"vphaddsw",//  add 16-bit signed integers horizontally, pack saturated integers to (x/y)mm1.
	"vphsubw",// 
	"vphsubd",// 
	"vpinsrb",//
	"vpinsrd",//
	"vpinsrq",//
	"vpinsrw",//  insert the word from r32/m16 at the offset indicated by imm8 into the value from xmm2 and store result in xmm1.
	"vpmaddubsw",//
	"vpmaddwd",//
	"vpmaxsb",//
	"vpmaxsw",//
	"vpmaxsd",//
	"vpmaxub",//
	"vpmaxuw",//
	"vpminsb",//
	"vpminsw",//
	"vpminsd",//
	"vpminub",//
	"vpminuw",//
	"vpmovmskb",//
	"vpmovzxbw",// 
	"vpmovzxbd",//
	"vpmovzxbq",//
	"vpmovzxwd",//
	"vpmovzxwq",//
	"vpmovzxdq",//
	"vpmuldq",//
	"vpmulhrsw",//
	"vpmulhuw",//
	"vpmulhw",//
	"vpmulld",//
	"vpmullw",//
	"vpmuludq",//
	"vpsadbw",//
	"vpshufb",//
	"vpshufd",//
	"vpshufhw",//
	"vpshuflw",//
	"vpslldq",//
	"vpsllw",	//
	"vpslld",	//
	"vpsllq",	//
	"vpsraw",	//
	"vpsrad",	//
	"vpsrldq",//
	"vpsrlw",	//
	"vpsrlq",	//
	"vpsrld",	//
	"vpsubb",	//
	"vpsubw",	//
	"vpsubd",	//
	"vpsubq",	//
	"vpsubsb",//
	"vpsubsw",//
	"vpsubusb",//
	"vpsubusw",//
	"ptwrite",//
	"vrcpps",	//
	"rdpid",	//
	"rdpkru",	//
	"rdsspd",	//
	"rdsspq",	//
	"vroundps",//
	"vroundsd",//
	"vroundss",//
	"vrsqrtps",// computes the approximate reciprocals of the square roots of packed single-precision values in xmm2/mem and stores the results in xmm1.
	"serialize",//  serialize instruction fetch and execution.
	"vshufpd",//
	"vshufps",//
	"vsqrtps",//
	"vsqrtsd",//
	"vsqrtss",//
	"vstmxcsr",//
	"vsubpd",	//
	"vsubps",	//
	"vsubsd",	//
	"vsubss",	//
	"vunpckhpd",//
	"vunpckhps",//
	"vunpcklpd",//
	"vunpcklps",//
	"vbroadcastf32x2",	//
	"vbroadcastf32x4",	//
	"vbroadcastf64x2",	//
	"vbroadcastf32x8",	//
	"vbroadcastf64x4",	//
	"vcvtne2ps2bf16",//
	"vcvtneps2bf16",//
	"vcvttpd2udq",	//
	"vcvttpd2uqq",	//
	"vcvttps2udq",	//
	"vcvttps2qq",//
	"vcvttps2uqq",	//
	"vcvttsd2usi",	//
	"vcvttss2usi",	//
	"vcvtusi2sd",//
	"vcvtusi2ss",//
	"vdpbf16ps",//
	"vextractf32x8",	//
	"vextracti128",	//
	"vextracti32x8",	//
	"vinsertf32x8",	//
	"vinserti128",	//
	"vinserti32x4",	//
	"vinserti32x8",	//
	"vinserti64x4",	//
	"vp2intersectd",	//
	"vp2intersectq",	//
	"vpblendd",// select dwords from (x/y)mm2 and (x/y)mm3/m(128/256) from mask specified in imm8 and store the values into (x/y)mm1.
	"vbroadcasti32x2",	//
	"vbroadcasti128",//
	"vbroadcasti32x4",	//
	"vbroadcasti64x2",	//
	"vbroadcasti32x8",	//
	"vbroadcasti64x4",	//
	"vpbroadcastmb2q",	//
	"vpbroadcastmw2d",	//
	"vpcmpub",//
	"vpcmpud",//
	"vpcmpuq",//
	"vpcmpuw",//
	"vpcompressb",	//
	"vpcompressw",	//
	"vpdpwssds",//
	"vperm2i128",// permute 128-bit integer data in ymm2 and ymm3/mem using controls from imm8 and store result in ymm1.
	"vpermb",	//
	"vpermt2b",//
	"vpermt2w",//
	"vpexpandb",//
	"vpexpandw",//
	"vpgatherdd",//
	"vpgatherqd",//
	"vpgatherdq",//
	"vpgatherqq",//
	"vpmadd52huq",	//
	"vpmadd52luq",	//
	"vpmaskmovd",//
	"vpmaskmovq",//
	"vpmovd2m",//
	"vpmovdb",//
	"vpmovdw",//
	"vpmovqb",//
	"vpmovqd",//
	"vpmovqw",//
	"vpmovwb",//
	"vpmultishiftqb",	//
	"vpopcntb",//
	"vpopcntw",//
	"vpopcntd",//
	"vpopcntq",//
	"vprorvd",//
	"vprorvq",//
	"vpshldw",//
	"vpshldd",//
	"vpshldq",//
	"vpshldvw",//
	"vpshldvd",//
	"vpshldvq",//
	"vpshrdw",//
	"vpshrdd",//
	"vpshrdq",//
	"vpshrdvw",//
	"vpshrdvd",//
	"vpshrdvq",//
	"vpshufbitqmb",	//
	"vpternlogd",//
	"vpternlogq",//
	"vscalefpd",//
	"vscalefsd",//
	"vscalefps",//
	"vscalefss",//
	"vscatterdps",	//
	"vscatterdpd",	//
	"vscatterqps",	//
	"vscatterqpd",	//
	"vshuff64x2",//
	"vshufi64x2",//
	"wbnoinvd",//
	"wrpkru",	//
	"wrssd",	//
	"wrssq",	//
	"vxorpd",	//
	"vxorps",	//
	"xrstors64",//
	"xsave64",// save state components specified by edx:eax to mem.
	"xsavec64",//
	"xsaves64",//

	"shl",
	"shr",
	"sar",
	"shrd",

	"prefetchnta",
	"prefetcht0",
	"prefetcht1",
	"prefetcht2",

	"umonitor",

	"savec",
	"saves",
};

__always_inline
static void print_mnemonic(FILE* where, instruction_t* const target)
{
	if (target->mnemonic == 0)
		fprintf(where, "(bad) ");
	else
		fprintf(where, "%s ", mnemonics[target->mnemonic - 1]);
}

static ubyte print_register(FILE* where, reg_t reg, udword prefix)
{
	ubyte l = 0;

	if (!(prefix & OS_QWORD_MASK) && reg >= D_REG_RAX && reg <= D_REG_R15)
	{
		if (prefix & OS_BYTE_MASK)
			l = fprintf(where, "%s", gp_regs_8[reg - 2]);
		else if (prefix & OS_WORD_MASK)
			l = fprintf(where, "%s", gp_regs_16[reg - 2]);
		else if (prefix & OS_DWORD_MASK)
			l = fprintf(where, "%s", gp_regs_32[reg - 2]);
	}
	else
		l = fprintf(where, "%s", regs[reg - 1]);

	return l;
}

static void print_sib(FILE* where, instruction_t* const inst, ubyte hasdisp)
{
	///TODO: WHAT I AM SUPOSED TO DO WITH hasdisp ?!?! (Add twice the displacement ?!?)
	/// I don't think so, i've only parsed 1 displacement
	(void)hasdisp;

	const ubyte mod = MODRM_MOD_GET(inst->mod_rm);
	const ubyte scale = 0x1 << SIB_SCALE_GET(inst->sib);
	const ubyte index = SIB_INDEX_EXTENDED_GET(inst);
	const ubyte base = SIB_BASE_EXTENDED_GET(inst);

	///TODO: For the moment only general purpose registers addressing is handled
	
	switch (mod)
	{
		case 0b00:
		{
			if (base <= 0b0100 || (base >= 0b0110 && base <= 0b1100) || base >= 0b1110)
			{
				if (index == 0b0100)
				{
					/* [BASE] */

					fprintf(where, "[");
					print_register(where, base + 2, *(udword*)inst->prefix);
					fprintf(where, "]");
				}
				else
				{
					/* [BASE + (INDEX * SCALE)] */

					fprintf(where, "[");
					print_register(where, base + 2, *(udword*)inst->prefix);
					fprintf(where, " + (");
					print_register(where, index + 2, *(udword*)inst->prefix);
					fprintf(where, " * %d)]", scale);
				}
			}
			else
			{
				if (index == 0b0100)
				{
					/* [DISP32] */

					fprintf(where, "[%d]", inst->displacement);
				}
				else
				{
					/* [(INDEX * SCALE) + DISP32] */

					fprintf(where, "[(");
					print_register(where, index + 2, *(udword*)inst->prefix);
					fprintf(where, " * %d) + %d]", scale, inst->displacement);
				}
			}
			break ;
		}

		case 0b01:
		{
			if (index == 0b0100)
			{
				/* [BASE + DISP8] */

				fprintf(where, "[");
				print_register(where, base + 2, *(udword*)inst->prefix);
				fprintf(where, " + %"PRIdd"]", inst->displacement);
			}
			else
			{
				/* [BASE + (INDEX * SCALE) + DISP8] */

				fprintf(where, "[");
				print_register(where, base + 2, *(udword*)inst->prefix);
				fprintf(where, " + (");
				print_register(where, index + 2, *(udword*)inst->prefix);
				fprintf(where, " * %d) + %"PRIdd"]", scale, inst->displacement);
			}
			break ;
		}

		case 0b10:
		{
			if (index == 0b0100)
			{
				/* [BASE + DISP32] */

				fprintf(where, "[");
				print_register(where, base + 2, *(udword*)inst->prefix);
				fprintf(where, " + %d]", inst->displacement);
			}
			else
			{
				/* [BASE + (INDEX * SCALE) + DISP32] */

				fprintf(where, "[");
				print_register(where, base + 2, *(udword*)inst->prefix);
				fprintf(where, " + (");
				print_register(where, index + 2, *(udword*)inst->prefix);
				fprintf(where, " * %d) + %d]", scale, inst->displacement);
			}
			break ;
		}
	}
}

__always_inline
static void print_address(FILE* where, instruction_t* const inst, ubyte isfirst)
{
	const ubyte mod = MODRM_MOD_GET(inst->mod_rm);
	const ubyte rm = MODRM_RM_EXTENDED_GET(inst);

	const ubyte* direction = (dword)inst->displacement < 0 ? (ubyte*)"-" : (ubyte*)"+";

	///TODO: For the moment only 64-bits addressing is handled
	///TODO: For the moment only general purpose registers addressing is handled

	if (!isfirst)
		fprintf(where, ", ");

	if (mod == 0b11 || (mod == 0b00 && (rm <= 0b0011 || (rm >= 0b0110 && rm <= 0b1011) || rm >= 0b1110)))
	{
		/* [R/M] */

		fprintf(where, "[");
		print_register(where, rm + 2, *(udword*)inst->prefix);
		fprintf(where, "]");
	}
	else if (mod == 0b00)
	{
		if (rm == 0b0100 || rm == 0b1100)
		{
			/* [SIB] */

			print_sib(where, inst, 0);
		}
		else if (rm == 0101 || rm == 0b1101)
		{
			/* [RIP + DISP32] */

			fprintf(where, "[rip %s %d]", direction, inst->displacement);
		}
	}
	else if (mod == 0b01)
	{
		if (rm == 0b0100 || rm == 0b1100)
		{
			/* [SIB + DIPS8] */

			print_sib(where, inst, 8);
		}
		else
		{
			/* [R/M + DISP8] */

			fprintf(where, "[");
			print_register(where, rm + 2, *(udword*)inst->prefix);
			fprintf(where, " %s %"PRIdd"]", direction, inst->displacement);
		}
	}
	else if (mod == 0b10)
	{
		if (rm == 0b0100 || rm == 0b1100)
		{
			/* [SIB + DISP32] */

			print_sib(where, inst, 32);
		}
		else
		{
			/* [R/M + DISP32] */

			fprintf(where, "[");
			print_register(where, rm + 2, *(udword*)inst->prefix);
			fprintf(where, " %s %d]", direction, inst->displacement);
		}
	}
}

static ubyte print_operand(FILE* where, instruction_t* const inst, reg_t reg, udword prefix, ubyte isfirst)
{
	ubyte l = 0x0;

	if (reg == D_REG_ADDR)
	{
		print_address(where, inst, isfirst);
		l++;
	}
	else if (reg)
	{
		if (!isfirst)
			fprintf(where, ", ");
		l = print_register(where, reg, prefix);
	}

	return l;
}

__always_inline
static ubyte print_operands(FILE* where, instruction_t* const target)
{
	const udword prefix = *(udword*)target->prefix;

	return print_operand(where, target, target->reg1, prefix, 1)
	+ print_operand(where, target, target->reg2, prefix, 0)
	+ print_operand(where, target, target->reg3, prefix, 0);
}

__always_inline
static void print_immediate(FILE* where, instruction_t* const target, ubyte has_operands)
{
	if (*(udword*)target->prefix & OP_IMMEDIATE_MASK)
    {
        if (has_operands)
            fprintf(where, ", ");
        fprintf(where, "0x%"PRIXq"", target->immediate);
    }
}

void    fprint_instruction(FILE* where, instruction_t* const target)
{
	dword has_operands;

	print_mnemonic(where, target);
	has_operands = print_operands(where, target);
    print_immediate(where, target, has_operands);


	if (*(word*)target->opcode == 0x0)
	{
		if (target->opcode[2] == 0xD0 || target->opcode[2] == 0xD1)
			fprintf(where, ", 1");
	}

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
