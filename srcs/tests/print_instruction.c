

#include <d_instruction.h>
#include <d_register.h>
#include <d_error.h>

static const char* const regs[] = {
    "[ADDR]",
    "RAX",
    "RCX",
    "RDX",
    "RBX",
    "RSP",
    "RBP",
    "RSI",
    "RDI",
    "R8",
    "R9",
    "R10",
    "R11",
    "R12",
    "R13",
    "R14",
    "R15",
    "ST0",
    "ST1",
    "ST2",
    "ST3",
    "ST4",
    "ST5",
    "ST6",
    "ST7",
    "MMX0",
    "MMX1",
    "MMX2",
    "MMX3",
    "MMX4",
    "MMX5",
    "MMX6",
    "MMX7",
    "MMX0B",
    "MMX1B",
    "MMX2B",
    "MMX3B",
    "MMX4B",
    "MMX5B",
    "MMX6B",
    "MMX7B",
    "XMM0",
    "XMM1",
    "XMM2",
    "XMM3",
    "XMM4",
    "XMM5",
    "XMM6",
    "XMM7",
    "XMM8",
    "XMM9",
    "XMM10",
    "XMM11",
    "XMM12",
    "XMM13",
    "XMM14",
    "XMM15",
    "YMM0",
    "YMM1",
    "YMM2",
    "YMM3",
    "YMM4",
    "YMM5",
    "YMM6",
    "YMM7",
    "YMM8",
    "YMM9",
    "YMM10",
    "YMM11",
    "YMM12",
    "YMM13",
    "YMM14",
    "YMM15",
    "ES",
    "CS",
    "SS",
    "DS",
    "FS",
    "GS",
    "ESB",
    "CSB",
    "SSB",
    "DSB",
    "FSB",
    "GSB",
    "CR0",
    "CR1",
    "CR2",
    "CR3",
    "CR4",
    "CR5",
    "CR6",
    "CR7",
    "CR8",
    "CR9",
    "CR10",
    "CR11",
    "CR12",
    "CR13",
    "CR14",
    "CR15",
    "DR0",
    "DR1",
    "DR2",
    "DR3",
    "DR4",
    "DR5",
    "DR6",
    "DR7",
    "DR8",
    "DR9",
    "DR10",
    "DR11",
    "DR12",
    "DR13",
    "DR14",
    "DR15",
    "RFLAGS",
    "AH",
    "CH",
    "DH",
    "BH",
};

static const char* const mnemonics[] = {
    "MOV",	// Move data between general-purpose registers; move data between memory and general-purpose or segment registers; move immediates to general-purpose registers.
	"CMOVE",   // Conditional move if equal.
	"CMOVZ",   // Conditional move if zero.
	"CMOVNE",   // Conditional move if not equal.
	"CMOVNZ",   // Conditional move if not zero.
	"CMOVA",   // Conditional move if above.
	"CMOVNBE",	// Conditional move if not below or equal.
	"CMOVAE",   // Conditional move if above or equal.
	"CMOVNB",   // Conditional move if not below.
	"CMOVB",   // Conditional move if below.
	"CMOVNAE",	// Conditional move if not above or equal.
	"CMOVBE",   // Conditional move if below or equal.
	"CMOVNA",   // Conditional move if not above.
	"CMOVG",   // Conditional move if greater
	"CMOVNLE",	// Conditional move if not less or equal.
	"CMOVGE",   // Conditional move if greater or equal.
	"CMOVNL",   // Conditional move if not less.
	"CMOVL",   // Conditional move if less.
	"CMOVNGE",	// Conditional move if not greater or equal.
	"CMOVLE",   // Conditional move if less or equal.
	"CMOVNG",   // Conditional move if not greater.
	"CMOVC",   // Conditional move if carry.
	"CMOVNC",   // Conditional move if not carry.
	"CMOVO",   // Conditional move if overflow.
	"CMOVNO",   // Conditional move if not overflow.
	"CMOVS",   // Conditional move if sign (negative).
	"CMOVNS",   // Conditional move if not sign (non-negative).
	"CMOVP",   // Conditional move if parity.
	"CMOVPE",   // Conditional move if parity even.
	"CMOVNP",   // Conditional move if not parity.
	"CMOVPO",   // Conditional move if parity odd.
	"XCHG",   // Exchange.
	"BSWAP",   // Byte swap.
	"XADD",   // Exchange and add.
	"CMPXCHG",	// Compare and exchange.
	"CMPXCHG8B",	// Compare and exchange 8 bytes
	"PUSH",   // Push onto stack.
	"POP",   // Pop off of stack.
	"PUSHA",   // Push general-purpose registers onto stack.
	"PUSHAD",   // Push general-purpose registers onto stack.
	"POPA",   // Pop general-purpose registers from stack.
	"POPD",   // Pop general-purpose registers from stack.
	"CWD",   // Convert word to doubleword.
	"CDQ",   // Convert doubleword to quadword.
	"CBW",   // Convert byte to word.
	"CWDE",   // Convert word to doubleword in EAX register.
	"MOVSX",   // Move and sign extend.
	"MOVZX",   // Move and zero extend.

	/* 2) Binary arithmetic */

	"ADCX",   // Unsigned integer add with carry.
	"ADOX",   // Unsigned integer add with overflow.
	"ADD",   // Integer add.
	"ADC",   // Add with carry.
	"SUB",   // Subtract.
	"SBB",   // Subtract with borrow.
	"IMUL",   // Signed multiply.
	"MUL",   // Unsigned multiply.
	"IDIV",   // Signed divide.
	"DIV",   // Unsigned divide.
	"INC",   // Increment.
	"DEC",   // Decrement.
	"NEG",   // Negate.
	"CMP",   // Compare.

	/* 3) Decimal arithmetic */

	"DAA",   // Decimal adjust after addition.
	"DAS",   // Decimal adjust after subtraction.
	"AAA",   // ASCII adjust after addition.
	"AAS",   // ASCII adjust after subtraction.
	"AAM",   // ASCII adjust after multiplication.
	"AAD",   // ASCII adjust before division.

	/* 4) Logical */

	"AND",   // Perform bitwise logical AND.
	"OR",   // Perform bitwise logical OR.
	"XOR",   // Perform bitwise logical exclusive OR.
	"NOT",   // Perform bitwise logical NOT.

	/* 5) Shift and Rotate */

	"SHLD",   // Shift left double.
	"ROR",   // Rotate right.
	"ROL",   // Rotate left.
	"RCR",   // Rotate through carry right.
	"RCL",   // Rotate through carry left.

	/* 6) Bit and Byte */

	"BT",   // Bit test.
	"BTS",   // Bit test and set.
	"BTR",   // Bit test and reset.
	"BTC",   // Bit test and complement.
	"BSF",   // Bit scan forward.
	"BSR",   // Bit scan reverse.
	"SETE",   // Set byte if equal.
	"SETZ",   // Set byte if zero.
	"SETNE",   // Set byte if not equal.
	"SETNZ",   // Set byte if not zero.
	"SETA",   // Set byte if above.
	"SETNBE",   // Set byte if not below or equal.
	"SETAE",   // Set byte if above or equal.
	"SETNB",   // Set byte if not below.
	"SETNC",   // Set byte if not carry.
	"SETB",   // Set byte if below.
	"SETNAE",   // Set byte if not above or equal.
	"SETC",   // Set byte if carry.
	"SETBE",   // Set byte if below or equal.
	"SETNA",   // Set byte if not above.
	"SETG",   // Set byte if greater.
	"SETNLE",   // Set byte if not less or equal.
	"SETGE",   // Set byte if greater or equal.
	"SETNL",   // Set byte if not less.
	"SETL",   // Set byte if less.
	"SETNGE",   // Set byte if not greater or equal.
	"SETLE",   // Set byte if less or equal.
	"SETNG",   // Set byte if not greater.
	"SETS",   // Set byte if sign (negative).
	"SETNS",   // Set byte if not sign (non-negative).
	"SETO",   // Set byte if overflow.
	"SETNO",   // Set byte if not overflow.
	"SETPE",   // Set byte if parity even.
	"SETP",   // Set byte if parity.
	"SETPO",   // Set byte if parity odd.
	"SETNP",   // Set byte if not parity.
	"TEST",   // Logical compare.
	"CRC32",   // Provides hardware acceleration to calculate cyclic redundancy checks for fast and efficient implementation of data integrity protocols
	"POPCNT",   // This instruction calculates of number of bits set to 1 in the second operand (source) and returns the count in the first operand (a destination register).

	/* 7) Control Transfer */

	"JMP",   // Jump.
	"JE",   // Jump if equal.
	"JZ",   // Jump if zero.
	"JNE",   // Jump if not equal.
	"JNZ",   // Jump if not zero.
	"JA",   // Jump if above.
	"JNBE",   // Jump if not below or equal.
	"JAE",   // Jump if above or equal.
	"JNB",   // Jump if not below.
	"JB",   // Jump if below.
	"JNAE",   // Jump if not above or equal
	"JBE",   // Jump if below or equal.
	"JNA",   // Jump if not above.
	"JG",   // Jump if greater.
	"JNLE",   // Jump if not less or equal.
	"JGE",   // Jump if greater or equal.
	"JNL",   // Jump if not less.
	"JL",   // Jump if less.
	"JNGE",   // Jump if not greater or equal.
	"JLE",   // Jump if less or equal.
	"JNG",   // Jump if not greater.
	"JC",   // Jump if carry.
	"JNC",   // Jump if not carry.
	"JO",   // Jump if overflow.
	"JNO",   // Jump if not overflow.
	"JS",   // Jump if sign (negative).
	"JNS",   // Jump if not sign (non-negative).
	"JPO",   // Jump if parity odd.
	"JNP",   // Jump if not parity.
	"JPE",   // Jump if parity even.
	"JP",   // Jump if parity.
	"JCXZ",   // Jump register CX zero.
	"JECXZ",   // Jump register ECX zero.
	"LOOP",   // Loop with ECX counter.
	"LOOPZ",   // Loop with ECX and zero/
	"LOOPE",   // Loop with ECX and equal.
	"LOOPNZ",   // Loop with ECX and not zero.
	"LOOPNE",   // Loop with ECX and not equal.
	"CALL",   // Call procedure.
	"RET",   // Return.
	"IRET",   // Return from interrupt.
	"INT",   // Software interrupt.
	"INTO",   // Interrupt on overflow.
	"BOUND",   // Detect value out of range.

	/* 8) String */

	"MOVS",   // Move string.
	"MOVSB",   // Move byte string.
	"MOVSW",   // Move word string.
	"MOVSD",   // Move doubleword string.
	"CMPS",   // Compare string.
	"CMPSB",   // Compare byte string.
	"CMPDW",   // Compare word string.
	"CMPSD",   // Compare doubleword string.
	"SCAS",   // Scan string.
	"SCASB",   // Scan byte string.
	"SCASW",   // Scan word string
	"SCASD",   // Scan doubleword string.
	"LODS",   // Load string.
	"LODSB",   // Load byte string.
	"LODSW",   // Load word string.
	"LODSD",   // Load doubleword string.
	"STOS",   // Store string.
	"STOSB",   // Store byte string.
	"STOSW",   // Store word string.
	"STOSD",   // Store doubleword string.
	"REP",   // Repeat while ECX not zero.
	"REPE",   // Repeat while equal.
	"REPZ",   // Repeat while zero.
	"REPNE",   // Repeat while not equal
	"REPNZ",   // Repeat while not zero.

	/* 9) I/O */

	"IN",   // Read from a port.
	"OUT",   // Write to a port.
	"INS",   // Input string from port.
	"INSB",   // Input byte string from port.
	"INSW",   // Input word string from port.
	"ISND",   // Input doubleword string from port.
	"OUTS",   // Output string to port.
	"OUTSB",   // Output byte string to port.
	"OUTSW",   // Output word string to port.
	"OUTSD",   // /Output doubleword string to port.

	/* 10) Enter and leave */

	"ENTER",   // High-level procedure entry.
	"LEAVE",   // High-level procedure exit.

	/* 11) Flag Control (EFLAG) */

	"STC",   // Set carry flag.
	"CLC",   // Clear the carry flag.
	"CMC",   // Complement the carry flag.
	"CLD",   // Clear the direction flag.
	"STD",   // Set direction flag.
	"LAHF",   // Load flags into AH register.
	"SAHF",   // Store AH register into flags.
	"PUSHF",   // Push EFLAGS onto stack.
	"PUSHFD",   // Push EFLAGS onto stack.
	"POPF",   // Pop EFLAGS from stack.
	"POPFD",   // Pop EFLAGS from stack.
	"STI",   // Set interrupt flag.
	"CLI",   // Clear the interrupt flag.

	/* 12) Segment Register */

	"LDS",   // Load far pointer using DS.
	"LES",   // Load far pointer using ES.
	"LFS",   // Load far pointer using FS.
	"LGS",   // Load far pointer using GS.
	"LSS",   // Load far pointer using SS.

	/* 13) Misvellaneous */

	"LEA",   // Load effective address.
	"NOP",   // No operation.
	"UD",   	// Undefined instruction.
	"XLAT",   // Table lookup translation.
	"XLATB",   // Table lookup translation.
	"CPUID",   // Processor identification.
	"MOVBE",   // Move data after swapping data bytes.
	"PREFETCHW",	"	"// Prefetch data into cache in anticipation of write.
	"PREFETCHWT1",	// Prefetch hint T1 with intent to write.
	"CLFLUSH",	"	"// Flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy.
	"CLFLUSHOPT",	"	"// Flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy with optimized memory system throughput.

	/* 14) User Mode Extended Sate Safe/Restore */

	"XSAVE",   // Save processor extended states to memory.
	"XSAVEC",   // Save processor extended states with compaction to memory.
	"XSAVEOPT",	"	"// Save processor extended states to memory, optimized.
	"XRSTOR",   // Restore processor extended states from memory.
	"XGETBV",   // Reads the state of an extended control register.

	/* 15) Random Number Generation */

	"RDRAND",   // Retrieves a random number generated from hardware.
	"RDSEED",   // Retrieves a random number generated from hardware.

	/* 16) BMI1", BMI2 */

	"ANDN",   // Bitwise AND of first source with inverted 2nd source operands.
	"BEXTR",   // Contiguous bitwise extract.
	"BLSI",   // Extract lowest set bit.
	"BLSMSK",   // Set all lower bits below first set bit to 1.
	"BLSR",   // Reset lowest set bit.
	"BZHI",   // Zero high bits starting from specified bit position.
	"LZCNT",   // Count the number leading zero bits.
	"MULX",   // Unsigned multiply without affecting arithmetic flags.
	"PDED",   // Parallel deposit of bits using a mask.
	"PEXT",   // Parallel extraction of bits using a mask.
	"RORX",   // Rotate right without affecting arithmetic flags.
	"SARX",   // Shift arithmetic right.
	"SHLX",   // Shift logic left.
	"SHRX",   // Shift logic right.
	"TZCNT",   // Count the number trailing zero bits.
};

void    fprintf_instruction(FILE* where, instruction_t* const target)
{
    fprintf(where, "%s ", mnemonics[target->mnemonic - 1]);

    dword has_operands = 0;
	const udword prefix = *(udword*)target->prefix;

    if (target->reg1)
        has_operands = fprintf(where, "%s", regs[target->reg1 - 1]);
    if (target->reg2)
        has_operands = fprintf(where, ", %s", regs[target->reg2 - 1]);
    if (target->reg3)
        has_operands = fprintf(where, ", %s", regs[target->reg3 - 1]);

    if (prefix & OP_IMMEDIATE_MASK)
    {
        if (has_operands)
            fprintf(where, ", ");
        fprintf(where, "0x%llX", target->immediate);
    }

	if (prefix & OS_BYTE_MASK)
		fprintf(where, " (Operand Size: BYTE)\n");
	else if (prefix & OS_WORD_MASK)
		fprintf(where, " (Operand Size: WORD)\n");
	else if (prefix & OS_DWORD_MASK)
		fprintf(where, " (Operand Size: DWORD)\n");
	else if (prefix & OS_QWORD_MASK)
		fprintf(where, " (Operand Size: QWORD)\n");
	else if (prefix & OS_DQWORD_MASK)
		fprintf(where, " (Operand Size: DQWORD)\n");
	else if (prefix & OS_QQWORD_MASK)
		fprintf(where, " (Operand Size: QQWORD)\n");
	else
		fprintf(where, " (Operand Size: ERROR)\n");
}

