
#pragma once

typedef enum
{
	/////////////////////
	// GENERAL PURPOSE //
	/////////////////////

	/* 1) Data transfer */

	MOV = 0x1,		// Move data between general-purpose registers; move data between memory and general-purpose or segment registers; move immediates to general-purpose registers.
	CMOVE,			// Conditional move if equal.
	CMOVZ,			// Conditional move if zero.
	CMOVNE,			// Conditional move if not equal.
	CMOVNZ,			// Conditional move if not zero.
	CMOVA,			// Conditional move if above.
	CMOVNBE,		// Conditional move if not below or equal.
	CMOVAE,			// Conditional move if above or equal.
	CMOVNB,			// Conditional move if not below.
	CMOVB,			// Conditional move if below.
	CMOVNAE,		// Conditional move if not above or equal.
	CMOVBE,			// Conditional move if below or equal.
	CMOVNA,			// Conditional move if not above.
	CMOVG,			// Conditional move if greater
	CMOVNLE,		// Conditional move if not less or equal.
	CMOVGE,			// Conditional move if greater or equal.
	CMOVNL,			// Conditional move if not less.
	CMOVL,			// Conditional move if less.
	CMOVNGE,		// Conditional move if not greater or equal.
	CMOVLE,			// Conditional move if less or equal.
	CMOVNG,			// Conditional move if not greater.
	CMOVC,			// Conditional move if carry.
	CMOVNC,			// Conditional move if not carry.
	CMOVO,			// Conditional move if overflow.
	CMOVNO,			// Conditional move if not overflow.
	CMOVS,			// Conditional move if sign (negative).
	CMOVNS,			// Conditional move if not sign (non-negative).
	CMOVP,			// Conditional move if parity.
	CMOVPE,			// Conditional move if parity even.
	CMOVNP,			// Conditional move if not parity.
	CMOVPO,			// Conditional move if parity odd.
	XCHG,			// Exchange.
	BSWAP,			// Byte swap.
	XADD,			// Exchange and add.
	CMPXCHG,		// Compare and exchange.
	CMPXCHG8B,		// Compare and exchange 8 bytes
	PUSH,			// Push onto stack.
	POP,			// Pop off of stack.
	PUSHA,			// Push general-purpose registers onto stack.
	PUSHAD,			// Push general-purpose registers onto stack.
	POPA,			// Pop general-purpose registers from stack.
	POPD,			// Pop general-purpose registers from stack.
	CWD,			// Convert word to doubleword.
	CDQ,			// Convert doubleword to quadword.
	CBW,			// Convert byte to word.
	CWDE,			// Convert word to doubleword in EAX register.
	MOVSX,			// Move and sign extend.
	MOVZX,			// Move and zero extend.

	/* 2) Binary arithmetic */

	ADCX,			// Unsigned integer add with carry.
	ADOX,			// Unsigned integer add with overflow.
	ADD,			// Integer add.
	ADC,			// Add with carry.
	SUB,			// Subtract.
	SBB,			// Subtract with borrow.
	IMUL,			// Signed multiply.
	MUL,			// Unsigned multiply.
	IDIV,			// Signed divide.
	DIV,			// Unsigned divide.
	INC,			// Increment.
	DEC,			// Decrement.
	NEG,			// Negate.
	CMP,			// Compare.

	/* 3) Decimal arithmetic */

	DAA,			// Decimal adjust after addition.
	DAS,			// Decimal adjust after subtraction.
	AAA,			// ASCII adjust after addition.
	AAS,			// ASCII adjust after subtraction.
	AAM,			// ASCII adjust after multiplication.
	AAD,			// ASCII adjust before division.

	/* 4) Logical */

	AND,			// Perform bitwise logical AND.
	OR,				// Perform bitwise logical OR.
	XOR,			// Perform bitwise logical exclusive OR.
	NOT,			// Perform bitwise logical NOT.

	/* 5) Shift and Rotate */

	SHLD,			// Shift left double.
	ROR,			// Rotate right.
	ROL,			// Rotate left.
	RCR,			// Rotate through carry right.
	RCL,			// Rotate through carry left.

	/* 6) Bit and Byte */

	BT,				// Bit test.
	BTS,			// Bit test and set.
	BTR,			// Bit test and reset.
	BTC,			// Bit test and complement.
	BSF,			// Bit scan forward.
	BSR,			// Bit scan reverse.
	SETE,			// Set byte if equal.
	SETZ,			// Set byte if zero.
	SETNE,			// Set byte if not equal.
	SETNZ,			// Set byte if not zero.
	SETA,			// Set byte if above.
	SETNBE,			// Set byte if not below or equal.
	SETAE,			// Set byte if above or equal.
	SETNB,			// Set byte if not below.
	SETNC,			// Set byte if not carry.
	SETB,			// Set byte if below.
	SETNAE,			// Set byte if not above or equal.
	SETC,			// Set byte if carry.
	SETBE,			// Set byte if below or equal.
	SETNA,			// Set byte if not above.
	SETG,			// Set byte if greater.
	SETNLE,			// Set byte if not less or equal.
	SETGE,			// Set byte if greater or equal.
	SETNL,			// Set byte if not less.
	SETL,			// Set byte if less.
	SETNGE,			// Set byte if not greater or equal.
	SETLE,			// Set byte if less or equal.
	SETNG,			// Set byte if not greater.
	SETS,			// Set byte if sign (negative).
	SETNS,			// Set byte if not sign (non-negative).
	SETO,			// Set byte if overflow.
	SETNO,			// Set byte if not overflow.
	SETPE,			// Set byte if parity even.
	SETP,			// Set byte if parity.
	SETPO,			// Set byte if parity odd.
	SETNP,			// Set byte if not parity.
	TEST,			// Logical compare.
	CRC32,			// Provides hardware acceleration to calculate cyclic redundancy checks for fast and efficient implementation of data integrity protocols
	POPCNT,			// This instruction calculates of number of bits set to 1 in the second operand (source) and returns the count in the first operand (a destination register).

	/* 7) Control Transfer */

	JMP,			// Jump.
	JE,				// Jump if equal.
	JZ,				// Jump if zero.
	JNE,			// Jump if not equal.
	JNZ,			// Jump if not zero.
	JA,				// Jump if above.
	JNBE,			// Jump if not below or equal.
	JAE,			// Jump if above or equal.
	JNB,			// Jump if not below.
	JB,				// Jump if below.
	JNAE,			// Jump if not above or equal
	JBE,			// Jump if below or equal.
	JNA,			// Jump if not above.
	JG,				// Jump if greater.
	JNLE,			// Jump if not less or equal.
	JGE,			// Jump if greater or equal.
	JNL,			// Jump if not less.
	JL,				// Jump if less.
	JNGE,			// Jump if not greater or equal.
	JLE,			// Jump if less or equal.
	JNG,			// Jump if not greater.
	JC,				// Jump if carry.
	JNC,			// Jump if not carry.
	JO,				// Jump if overflow.
	JNO,			// Jump if not overflow.
	JS,				// Jump if sign (negative).
	JNS,			// Jump if not sign (non-negative).
	JPO,			// Jump if parity odd.
	JNP,			// Jump if not parity.
	JPE,			// Jump if parity even.
	JP,				// Jump if parity.
	JCXZ,			// Jump register CX zero.
	JECXZ,			// Jump register ECX zero.
	LOOP,			// Loop with ECX counter.
	LOOPZ,			// Loop with ECX and zero/
	LOOPE,			// Loop with ECX and equal.
	LOOPNZ,			// Loop with ECX and not zero.
	LOOPNE,			// Loop with ECX and not equal.
	CALL,			// Call procedure.
	RET,			// Return.
	IRET,			// Return from interrupt.
	INT,			// Software interrupt.
	INTO,			// Interrupt on overflow.
	BOUND,			// Detect value out of range.

	/* 8) String */

	MOVS,			// Move string.
	MOVSB,			// Move byte string.
	MOVSW,			// Move word string.
	MOVSD,			// Move doubleword string.
	CMPS,			// Compare string.
	CMPSB,			// Compare byte string.
	CMPDW,			// Compare word string.
	CMPSD,			// Compare doubleword string.
	SCAS,			// Scan string.
	SCASB,			// Scan byte string.
	SCASW,			// Scan word string
	SCASD,			// Scan doubleword string.
	LODS,			// Load string.
	LODSB,			// Load byte string.
	LODSW,			// Load word string.
	LODSD,			// Load doubleword string.
	STOS,			// Store string.
	STOSB,			// Store byte string.
	STOSW,			// Store word string.
	STOSD,			// Store doubleword string.
	REP,			// Repeat while ECX not zero.
	REPE,			// Repeat while equal.
	REPZ,			// Repeat while zero.
	REPNE,			// Repeat while not equal
	REPNZ,			// Repeat while not zero.

	/* 9) I/O */

	IN,				// Read from a port.
	OUT,			// Write to a port.
	INS,			// Input string from port.
	INSB,			// Input byte string from port.
	INSW,			// Input word string from port.
	ISND,			// Input doubleword string from port.
	OUTS,			// Output string to port.
	OUTSB,			// Output byte string to port.
	OUTSW,			// Output word string to port.
	OUTSD,			// /Output doubleword string to port.

	/* 10) Enter and leave */

	ENTER,			// High-level procedure entry.
	LEAVE,			// High-level procedure exit.

	/* 11) Flag Control (EFLAG) */

	STC,			// Set carry flag.
	CLC,			// Clear the carry flag.
	CMC,			// Complement the carry flag.
	CLD,			// Clear the direction flag.
	STD,			// Set direction flag.
	LAHF,			// Load flags into AH register.
	SAHF,			// Store AH register into flags.
	PUSHF,			// Push EFLAGS onto stack.
	PUSHFD,			// Push EFLAGS onto stack.
	POPF,			// Pop EFLAGS from stack.
	POPFD,			// Pop EFLAGS from stack.
	STI,			// Set interrupt flag.
	CLI,			// Clear the interrupt flag.

	/* 12) Segment Register */

	LDS,			// Load far pointer using DS.
	LES,			// Load far pointer using ES.
	LFS,			// Load far pointer using FS.
	LGS,			// Load far pointer using GS.
	LSS,			// Load far pointer using SS.

	/* 13) Misvellaneous */

	LEA,			// Load effective address.
	NOP,			// No operation.
	UD,				// Undefined instruction.
	XLAT,			// Table lookup translation.
	XLATB,			// Table lookup translation.
	CPUID,			// Processor identification.
	MOVBE,			// Move data after swapping data bytes.
	PREFETCHW,		// Prefetch data into cache in anticipation of write.
	PREFETCHWT1,	// Prefetch hint T1 with intent to write.
	CLFLUSH,		// Flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy.
	CLFLUSHOPT,		// Flushes and invalidates a memory operand and its associated cache line from all levels of the processor’s cache hierarchy with optimized memory system throughput.

	/* 14) User Mode Extended Sate Safe/Restore */

	XSAVE,			// Save processor extended states to memory.
	XSAVEC,			// Save processor extended states with compaction to memory.
	XSAVEOPT,		// Save processor extended states to memory, optimized.
	XRSTOR,			// Restore processor extended states from memory.
	XGETBV,			// Reads the state of an extended control register.

	/* 15) Random Number Generation */

	RDRAND,			// Retrieves a random number generated from hardware.
	RDSEED,			// Retrieves a random number generated from hardware.

	/* 16) BMI1, BMI2 */

	ANDN,			// Bitwise AND of first source with inverted 2nd source operands.
	BEXTR,			// Contiguous bitwise extract.
	BLSI,			// Extract lowest set bit.
	BLSMSK,			// Set all lower bits below first set bit to 1.
	BLSR,			// Reset lowest set bit.
	BZHI,			// Zero high bits starting from specified bit position.
	LZCNT,			// Count the number leading zero bits.
	MULX,			// Unsigned multiply without affecting arithmetic flags.
	PDED,			// Parallel deposit of bits using a mask.
	PEXT,			// Parallel extraction of bits using a mask.
	RORX,			// Rotate right without affecting arithmetic flags.
	SARX,			// Shift arithmetic right.
	SHLX,			// Shift logic left.
	SHRX,			// Shift logic right.
	TZCNT,			// Count the number trailing zero bits.

	/////////////
	// x87 FPU //
	/////////////

	/* 1) Data transfer */

	FLD,			// Load floating-point value.
	TST,			// Store floating-point value.
	FSTP,			// Store floating-point value and pop.
	FILD,			// Load integer.
	FIST,			// Store integer.
	FISTP,			// Store integer and pop.
	FBLD,			// Load BCD.
	FBSTP,			// Store BCD and pop.
	FXCH,			// Exchange registers.
	FCMOVE,			// Floating-point conditional move if equal.
	FCMOVNE,		// Floating-point conditional move if not equal.
	FCMOVB,			// Floating-point conditional move if below.
	FCMOVBE,		// Floating-point conditional move if below or equal.
	FCMOVNB,		// Floating-point conditional move if not below.
	FCMOVNBE,		// Floating-point conditional move if not below or equal.
	FCMOVU,			// Floating-point conditional move if unordered.
	FCMOVNU,		// Floating-point conditional move if not unordered.

	/* 2) Basic Arithmetic */

	FADD,			// Add floating-point.
	FADDP,			// Add floating-point and pop.
	FIADD,			// Add integer.
	FSUB,			// Subtract floating-point.
	FSUBP,			// Subtract floating-point and pop.
	FISUB,			// Subtract integer.
	FSUBR,			// Subtract floating-point reverse.
	FSUBRP,			// Subtract floating-point reverse and pop.
	FISUBR,			// Subtract integer reverse.
	FMUL,			// Multiply floating-point.
	FMULP,			// Multiply floating-point and pop.
	FIMUL,			// Multiply integer.
	FDIV,			// Divide floating-point.
	FDIVP,			// Divide floating-point and pop.
	FIDIV,			// Divide integer.
	FDIVR,			// Divide floating-point reverse.
	FDIVRP,			// Divide floating-point reverse and pop.
	FIDIVR,			// Divide integer reverse.
	FPREM,			// Partial remainder.
	FPREM1,			// IEEE Partial remainder.
	FABS,			// Absolute value.
	FCHS,			// Change sign.
	FRDINT,			// Round to integer.
	FSCALE,			// Scale by power of two.
	FSQRT,			// Square root.
	FXTRACT,		// Extract exponent and significand.

	/* 3) Comparison */

	FCOM,			// Compare floating-point.
	FCOMP,			// Compare floating-point and pop.
	FCOMPP,			// Compare floating-point and pop twice.
	FUCOM,			// Unordered compare floating-point.
	FUCOMP,			// Unordered compare floating-point and pop.
	FUCOMPP,		// Unordered compare floating-point and pop twice.
	FICOM,			// Compare integer.
	FICOMP,			// Compare integer and pop.
	FCOMI,			// Compare floating-point and set EFLAGS.
	FUCOMI,			// Unordered compare floating-point and set EFLAGS.
	FCOMIP,			// Compare floating-point, set EFLAGS, and pop.
	FUCOMIP,		// Unordered compare floating-point, set EFLAGS, and pop.
	FTST,			// Test floating-point (compare with 0.0).
	FXAM,			// Examine floating-point.

	/* 4) Transcendental */

	FSIN,			// Sine.
	FCOS,			// Cosine.
	FSINCOS,		// Sine and cosine.
	FPTAN,			// Partial tangent.
	FPATAN,			// Partial arctangent.
	F2XM1,			// 2^x − 1
	FYL2X,			// y∗log2x
	FYL2XP1,		// y∗log2(x+1)

	/* 5) Load Constants */

	FLD1,			// Load +1.0
	FLDZ,			// Load +0.0
	FLDPI,			// Load π
	FLDL2E,			// Load log 2^e
	FLDLN2,			// Load log e^2
	FLDL2T,			// Load log 2^10
	FLDLG2,			// Load log 10^2

	/* 6) Control */

	FINCSTP,		// Increment FPU register stack pointer.
	FDECSTP,		// Decrement FPU register stack pointer.
	FFREE,			// Free floating-point register.
	FINIT,			// Initialize FPU after checking error conditions.
	FNINIT,			// Initialize FPU without checking error conditions.
	FCLEX,			// Clear floating-point exception flags after checking for error conditions.
	FNCLEX,			// Clear floating-point exception flags without checking for error conditions.
	FSTCW,			// Store FPU control word after checking error conditions.
	FNSTCW,			// Store FPU control word without checking error conditions.
	FLDCW,			// Load FPU control word.
	FSTENV,			// Store FPU environment after checking error conditions.
	FNSTENV,		// Store FPU environment without checking error conditions.
	FLDENV,			// Load FPU environment.
	FSAVE,			// Save FPU state after checking error conditions.
	FNSAVE,			// Save FPU state without checking error conditions.
	FRSTOR,			// Restore FPU state.
	FSTSW,			// Store FPU status word after checking error conditions.
	FNSTSW,			// Store FPU status word without checking error conditions.
	WAIT,			// Wait for FPU.
	FWAIT,			// Wait for FPU.
	FNOP,			// FPU no operation.

	/////////
	// MMX //
	/////////

	/* 1) Data transfer */

	MOVD,			// Move doubleword.
	MOVQ,			// Move quadword.

	/* 2) Conversion */

	PACKSSWB,		// Pack words into bytes with signed saturation.
	PACKSSDW,		// Pack doublewords into words with signed saturation.
	PACKUSWB,		// Pack words into bytes with unsigned saturation.
	PUNPCKHBW,		// Unpack high-order bytes.
	PUNPCKHWD,		// Unpack high-order words.
	PUNPCKHDQ,		// Unpack high-order doublewords.
	PUNPCKLBW,		// Unpack low-order bytes.
	PUNPCKLWD,		// Unpack low-order words.
	PUNPCKLDQ,		// Unpack low-order doublewords.

	/* 3) Packed arithmetic */

	PADDB,			// Add packed byte integers.
	PADDW,			// Add packed word integers.
	PADDD,			// Add packed doubleword integers.
	PADDSB,			// Add packed signed byte integers with signed saturation.
	PADDSW,			// Add packed signed word integers with signed saturation.
	PADDUSB,		// Add packed unsigned byte integers with unsigned saturation.
	PADDUSW,		// Add packed unsigned word integers with unsigned saturation.
	PSUBB,			// Subtract packed byte integers.
	PSUBW,			// Subtract packed word integers.
	PSUBD,			// Subtract packed doubleword integers.
	PSUBSB,			// Subtract packed signed byte integers with signed saturation.
	PSUBSW,			// Subtract packed signed word integers with signed saturation.
	PSUBUSB,		// Subtract packed unsigned byte integers with unsigned saturation.
	PSUBUSW,		// Subtract packed unsigned word integers with unsigned saturation.
	PMULHW,			// Multiply packed signed word integers and store high result.
	PMULLW,			// Multiply packed signed word integers and store low result.
	PMADDWD,		// Multiply and add packed word integers.

	/* 4) Comparison */

	PCMPEQB,		// Compare packed bytes for equal.
	PCMPEQW,		// Compare packed words for equal.
	PCMPEQD,		// Compare packed doublewords for equal.
	PCMPGTB,		// Compare packed signed byte integers for greater than.
	PCMPGTW,		// Compare packed signed word integers for greater than.
	PCMPGTD,		// Compare packed signed doubleword integers for greater than.

	/* 5) Logical */

	PAND,			// Bitwise logical AND.
	PANDN,			// Bitwise logical AND NOT.
	POR,			// Bitwise logical OR.
	PXOR,			// Bitwise logical exclusive OR.

	/* 6) Shift and rotate */

	PSLLW,			// Shift packed words left logical.
	PSLLD,			// Shift packed doublewords left logical.
	PSLLQ,			// Shift packed quadword left logical.
	PSRLW,			// Shift packed words right logical.
	PSRLD,			// Shift packed doublewords right logical.
	PSRLQ,			// Shift packed quadword right logical.
	PSRAW,			// Shift packed words right arithmetic.
	PSRAD,			// Shift packed doublewords right arithmetic.

	/* 7) State management */

	EMMS,			// Empty MMX state.

	/////////
	// SSE //
	/////////

	/* 1) Data transfer */

	MOVAPS,			// Move four aligned packed single-precision floating-point values between XMM registers or between and XMM register and memory.
	MOVUPS,			// Move four unaligned packed single-precision floating-point values between XMM registers or between and XMM register and memory.
	MOVHPS,			// Move four unaligned packed single-precision floating-point values between XMM registers or between and XMM register and memory.
	MOVHLPS,		// Move two packed single-precision floating-point values from the high quadword of an XMM register to the low quadword of another XMM register.
	MOVLPS,			// Move two packed single-precision floating-point values to an from the low quadword of an XMM register and memory.
	MOVLHPS,		// Move two packed single-precision floating-point values from the low quadword of an XMM register to the high quadword of another XMM register.
	MOVMSKPS,		// Extract sign mask from four packed single-precision floating-point values.
	MOVSS,			// Move scalar single-precision floating-point value between XMM registers or between an XMM register and memory.

	/* 2) Packed arithmetic */

	ADDPS,			// Add packed single-precision floating-point values.
	ADDSS,			// Add scalar single-precision floating-point values.
	SUBPS,			// Subtract packed single-precision floating-point values.
	SUBSS,			// Subtract scalar single-precision floating-point values.
	MULPS,			// Multiply packed single-precision floating-point values.
	MULSS,			// Multiply scalar single-precision floating-point values.
	DIVPS,			// Divide packed single-precision floating-point values.
	DIVSS,			// Divide scalar single-precision floating-point values.
	RCPPS,			// Compute reciprocals of packed single-precision floating-point values.
	RCPSS,			// Compute reciprocal of scalar single-precision floating-point values.
	SQRTPS,			// Compute square roots of packed single-precision floating-point values.
	SQRTSS,			// Compute square root of scalar single-precision floating-point values.
	RSQRTPS,		// Compute reciprocals of square roots of packed single-precision floating-point values.
	RSQRTSS,		// Compute reciprocal of square root of scalar single-precision floating-point values.
	MAXPS,			// Return maximum packed single-precision floating-point values.
	MAXSS,			// Return maximum scalar single-precision floating-point values.
	MINPS,			// Return minimum packed single-precision floating-point values.
	MINSS,			// Return minimum scalar single-precision floating-point values.

	/* 3) Comparison */

	CMPPS,			// Compare packed single-precision floating-point values.
	CMPSS,			// Compare scalar single-precision floating-point values.
	COMISS,			// Perform ordered comparison of scalar single-precision floating-point values and set flags in EFLAGS register.
	UCOMISS,		// Perform unordered comparison of scalar single-precision floating-point values and set flags in EFLAGS register.

	/* 4) Logical */

	ANDPS,			// Perform bitwise logical AND of packed single-precision floating-point values.
	ANDNPS,			// Perform bitwise logical AND NOT of packed single-precision floating-point values.
	ORPS,			// Perform bitwise logical OR of packed single-precision floating-point values.
	XORPS,			// Perform bitwise logical XOR of packed single-precision floating-point values.

	/* 5) Shuffle and unpack */

	SHUFPS,			// Shuffles values in packed single-precision floating-point operands.
	UNPCKHPS,		// Unpacks and interleaves the two high-order values from two single-precision floating-point operands.
	UNPCKLPS,		// Unpacks and interleaves the two low-order values from two single-precision floating-point operands.

	/* 6) Conversion */

	CVTPI2PS,		// Convert packed doubleword integers to packed single-precision floating-point values.
	CVTSI2SS,		// Convert doubleword integer to scalar single-precision floating-point value.
	CVTPS2PI,		// Convert packed single-precision floating-point values to packed doubleword integers.
	CVTTPS2PI,		// Convert with truncation packed single-precision floating-point values to packed doubleword integers.
	CVTSS2SI,		// Convert a scalar single-precision floating-point value to a doubleword integer.
	CVTTSS2SI,		// Convert with truncation a scalar single-precision floating-point value to a scalar doubleword integer.

	/* 7) MXCSR state management */

	LDMXCSR,		// Load MXCSR register.
	STMXCSR,		// Save MXCSR register state.

	/* 8) 64-bit SIMD integer */

	PAVGB,			// Compute average of packed unsigned byte integers.
	PAVGW,			// Compute average of packed unsigned word integers.
	PEXTRWSSE,		// Extract word.
	PINSRW,			// Insert word.
	PMAXUB,			// Maximum of packed unsigned byte integers.
	PMAXSW,			// Maximum of packed signed word integers.
	PMINUB,			// Minimum of packed unsigned byte integers.
	PMINSW,			// Minimum of packed signed word integers.
	PMOVMSKB,		// Move byte mask.
	PMULHUW,		// Multiply packed unsigned integers and store high result.
	PSADBW,			// Compute sum of absolute differences.
	PSHUFW,			// Shuffle packed integer word in MMX register.

	/* 9) Cacheability control, prefetch, and ordering */

	MASKMOVQ,		// Non-temporal store of selected bytes from an MMX register into memory.
	MOVNTQ,			// Non-temporal store of quadword from an MMX register into memory.
	MOVNTPS,		// Non-temporal store of four packed single-precision floating-point values from an XMM register into memory.
	PREFETCHh,		// Load 32 or more of bytes from memory to a selected level of the processor’s cache hierarchy.
	SFENCE,			// Serializes store operations.

	//////////
	// SSE2 //
	//////////

	/* 1) Data movement */

	MOVAPD,			// Move two aligned packed double-precision floating-point values between XMM registers or between and XMM register and memory.
	MOVUPD,			// Move two unaligned packed double-precision floating-point values between XMM registers or between and XMM register and memory.
	MOVHPD,			// Move high packed double-precision floating-point value to an from the high quadword of an XMM register and memory.
	MOVLPD,			// Move low packed single-precision floating-point value to an from the low quadword of an XMM register and memory.
	MOVMSKPD,		// Extract sign mask from two packed double-precision floating-point values.
	MOVSDXMM,		// Move scalar double-precision floating-point value between XMM registers or between an XMM register and memory.

	/* 2) Packed arithmetic */

	ADDPD,			// Add packed double-precision floating-point values.
	ADDSD,			// Add scalar double precision floating-point values.
	SUBPD,			// Subtract packed double-precision floating-point values.
	SUBSD,			// Subtract scalar double-precision floating-point values.
	MULPD,			// Multiply packed double-precision floating-point values.
	MULSD,			// Multiply scalar double-precision floating-point values.
	DIVPD,			// Divide packed double-precision floating-point values.
	DIVSD,			// Divide scalar double-precision floating-point values.
	SQRTPD,			// Compute packed square roots of packed double-precision floating-point values.
	SQRTSD,			// Compute scalar square root of scalar double-precision floating-point values.
	MAXPD,			// Return maximum packed double-precision floating-point values.
	MAXSD,			// Return maximum scalar double-precision floating-point values.
	MINPD,			// Return minimum packed double-precision floating-point values.
	MINSD,			// Return minimum scalar double-precision floating-point values.

	/* 3) Logical */

	ANDPD,			// Perform bitwise logical AND of packed double-precision floating-point values.
	ANDNPD,			// Perform bitwise logical AND NOT of packed double-precision floating-point values.
	ORPD,			// Perform bitwise logical OR of packed double-precision floating-point values.
	XORPD,			// Perform bitwise logical XOR of packed double-precision floating-point values.

	/* 4) Compare */

	CMPPD,			// Compare packed double-precision floating-point values.
	CMPSDF,			// Compare scalar double-precision floating-point values.
	COMISD,			// Perform ordered comparison of scalar double-precision floating-point values and set flags in EFLAGS register.
	UCOMISD,		// Perform unordered comparison of scalar double-precision floating-point values and set flags in EFLAGS register.

	/* 5) Shuffle and unpack */

	SHUFPD,			// Shuffles values in packed double-precision floating-point operands.
	UNPCKHPD,		// Unpacks and interleaves the high values from two packed double-precision floating-point operands.
	UNPCKLPD,		// Unpacks and interleaves the low values from two packed double-precision floating-point operands.

	/* 6) Conversion */

	CVTPD2PI,		// Convert packed double-precision floating-point values to packed doubleword integers.
	CVTTPD2PI,		// Convert with truncation packed double-precision floating-point values to packed double-word integers.
	CVTPI2PD,		// Convert packed doubleword integers to packed double-precision floating-point values.
	CVTPD2DQ,		// Convert packed double-precision floating-point values to packed doubleword integers.
	CVTTPD2DQ,		// Convert with truncation packed double-precision floating-point values to packed double-word integers.
	CVTDQ2PD,		// Convert packed doubleword integers to packed double-precision floating-point values.
	CVTPS2PD,		// Convert packed single-precision floating-point values to packed double-precision floating-point values.
	CVTPD2PS,		// Convert packed double-precision floating-point values to packed single-precision floating-point values.
	CVTSS2SD,		// Convert scalar single-precision floating-point values to scalar double-precision floating-point values.
	CVTSD2SS,		// Convert scalar double-precision floating-point values to scalar single-precision floating-point values.
	CVTSD2SI,		// Convert scalar double-precision floating-point values to a doubleword integer.
	CVTTSD2SI,		// Convert with truncation scalar double-precision floating-point values to scalar doubleword integers.
	CVTSI2SD,		// Convert doubleword integer to scalar double-precision floating-point value.

	/* 7) Packed single-precision floating-point */

	CVTDQ2PS,		// Convert packed doubleword integers to packed single-precision floating-point values.
	CVTPS2DQ,		// Convert packed single-precision floating-point values to packed doubleword integers.
	CVTTPS2DQ,		// Convert with truncation packed single-precision floating-point values to packed double-word integers.

	/* 8) 128-bit SIMD integer */

	MOVDQA,			// Move aligned double quadword.
	MOVDQU,			// Move unaligned double quadword.
	MOVQ2DQ,		// Move quadword integer from MMX to XMM registers.
	MOVDQ2Q,		// Move quadword integer from XMM to MMX registers.
	PMULUDQ,		// Multiply packed unsigned doubleword integers.
	PADDQ,			// Add packed quadword integers.
	PSUBQ,			// Subtract packed quadword integers.
	PSHUFLW,		// Shuffle packed low words.
	PSHUFHW,		// Shuffle packed high words.
	PSHUFD,			// Shuffle packed doublewords.
	PSLLDQ,			// Shift double quadword left logical.
	PSRLDQ,			// Shift double quadword right logical.
	PUNPCKHQDQ,		// Unpack high quadwords.
	PUNPCKLQDQ,		// Unpack low quadwords.

	/* 9) Cacheability control and ordering */

	LFENCE,			// Serializes load operations.
	MFENCE,			// Serializes load and store operations.
	PAUSE,			// Improves the performance of “spin-wait loops”.
	MASKMOVDQU,		// Non-temporal store of selected bytes from an XMM register into memory.
	MOVNTPD,		// Non-temporal store of two packed double-precision floating-point values from an XMM register into memory.
	MOVNTDQ,		// Non-temporal store of double quadword from an XMM register into memory.
	MOVNTI,			// Non-temporal store of a doubleword from a general-purpose register into memory.

	//////////
	// SSE3 //
	//////////

	/* 1) x87-FP integer conversion */

	FISTTP,			// Behaves like the FISTP instruction but uses truncation, irrespective of the rounding mode specified in the floating-point control word (FCW).

	/* 2) Specialized 128-bit unaligned data load */

	LDDQU,			// Special 128-bit unaligned load designed to avoid cache line splits.

	/* 3) SIMD floating-point packed ADD/SUB */

	ADDSUBPS,		// Performs single-precision addition on the second and fourth pairs of 32-bit data elements
					//		within the operands; single-precision subtraction on the first and third pairs.
	ADDSUBPD,		// Performs double-precision addition on the second pair of quadwords, and double-precision
					//		subtraction on the first pair.

	/* 4) SIMD floating-point horizontal ADD/SUB */

	HADDPS,			// Performs a single-precision addition on contiguous data elements. The first data element
					//		of the result is obtained by adding the first and second elements of the first operand; the
					//		second element by adding the third and fourth elements of the first operand; the third by
					//		adding the first and second elements of the second operand; and the fourth by adding the
					//		third and fourth elements of the second operand.
	HSUBPS,			// Performs a single-precision subtraction on contiguous data elements. The first data
					//		element of the result is obtained by subtracting the second element of the first operand
					//		from the first element of the first operand; the second element by subtracting the fourth
					//		element of the first operand from the third element of the first operand; the third by
					//		subtracting the second element of the second operand from the first element of the second
					//		operand; and the fourth by subtracting the fourth element of the second operand from the
					//		third element of the second operand.
	HADDPD,			// Performs a double-precision addition on contiguous data elements. The first data element
					//		of the result is obtained by adding the first and second elements of the first operand; the
					//		second element by adding the first and second elements of the second operand.
	HSUBPD,			// Performs a double-precision subtraction on contiguous data elements. The first data
					//		element of the result is obtained by subtracting the second element of the first operand
					//		from the first element of the first operand; the second element by subtracting the second
					//		element of the second operand from the first element of the second operand.

	/* 5) SIMD floating-point LOAD/MOVE/DUPLICATE */

	MOVSHDUP,		// Loads/moves 128 bits; duplicating the second and fourth 32-bit data elements.
	MOVSLDUP,		// Loads/moves 128 bits; duplicating the first and third 32-bit data elements.
	MOVDDUP,		// Loads/moves 64 bits (bits[63:0] if the source is a register) and returns the same 64 bits in
					//		both the lower and upper halves of the 128-bit result register; duplicates the 64 bits from the source.

	/* 6) Agent synchronization */

	MONITOR,		// Sets up an address range used to monitor write-back stores.
	MWAIT,			// Enables a logical processor to enter into an optimized state while waiting for a write-back store to the address range set up by the MONITOR instruction.

	/* 7) Horizontal addition/substraction */

	PHADDW,			// Adds two adjacent, signed 16-bit integers horizontally from the source and destination operands and packs the signed 16-bit results to the destination operand.
	PHADDSW,		// Adds two adjacent, signed 16-bit integers horizontally from the source and destination operands and packs the signed, saturated 16-bit results to the destination operand.
	PHADDD,			// Adds two adjacent, signed 32-bit integers horizontally from the source and destination operands and packs the signed 32-bit results to the destination operand.
	PHSUBW,			// Performs horizontal subtraction on each adjacent pair of 16-bit signed integers by
					//		subtracting the most significant word from the least significant word of each pair in the
					//		source and destination operands. The signed 16-bit results are packed and written to the destination operand.
	PHSUBSW,		// Performs horizontal subtraction on each adjacent pair of 16-bit signed integers by
					//		subtracting the most significant word from the least significant word of each pair in the
					//		source and destination operands. The signed, saturated 16-bit results are packed and written to the destination operand.
	PHSUBD,			// Performs horizontal subtraction on each adjacent pair of 32-bit signed integers by
					//		subtracting the most significant doubleword from the least significant double word of each
					//		pair in the source and destination operands. The signed 32-bit results are packed and written to the destination operand.

	/* 8) Packed absolute values */

	PABSB,			// Computes the absolute value of each signed byte data element.
	PABSW,			// Computes the absolute value of each signed 16-bit data element.
	PABSD,			// Computes the absolute value of each signed 32-bit data element.

	/* 9) Multiply and packed signed and unsigned bytes */

	PMADDUBSW,		// Multiplies each unsigned byte value with the corresponding signed byte value to produce
					//		an intermediate, 16-bit signed integer. Each adjacent pair of 16-bit signed values are
					//		added horizontally. The signed, saturated 16-bit results are packed to the destination operand.

	/* 10) Packed multiply high with rounds and scale */

	PMULHRSW,		// Multiplies vertically each signed 16-bit integer from the destination operand with the corre-
					//		sponding signed 16-bit integer of the source operand, producing intermediate, signed 32-
					//		bit integers. Each intermediate 32-bit integer is truncated to the 18 most significant bits.
					//		Rounding is always performed by adding 1 to the least significant bit of the 18-bit interme-
					//		diate result. The final result is obtained by selecting the 16 bits immediately to the right of
					//		the most significant bit of each 18-bit intermediate result and packed to the destination operand.

	/* 11) Packed shuffle bytes */

	PSHUFB,			// Permutes each byte in place, according to a shuffle control mask. The least significant
					//		three or four bits of each shuffle control byte of the control mask form the shuffle index.
					//		The shuffle mask is unaffected. If the most significant bit (bit 7) of a shuffle control byte is
					//		set, the constant zero is written in the result byte.

	/* 12) Packed sign */

	PSIGNB,			// Negates each signed integer element of the destination operand if the sign of the corresponding data element in the source operand is less than zero.
	PSIGNW,			// Negates each signed integer element of the destination operand if the sign of the corresponding data element in the source operand is less than zero.
	PSIGND,			// Negates each signed integer element of the destination operand if the sign of the corresponding data element in the source operand is less than zero.

	/* 13) Packed align right */

	PALIGNR,		// Source operand is appended after the destination operand forming an intermediate value
					//		of twice the width of an operand. The result is extracted from the intermediate value into
					//		the destination operand by selecting the 128 bit or 64 bit value that are right-aligned to the
					//		byte offset specified by the immediate value.

	//////////
	// SSE4 //
	//////////

	/* 1) Dword multiply */

	PMULLD,			// Returns four lower 32-bits of the 64-bit results of signed 32-bit integer multiplies.
	PMULDQ,			// Returns two 64-bit signed result of signed 32-bit integer multiplies.

	/* 2) Floating-point dot product */

	DPPD,			// Perform double-precision dot product for up to 2 elements and broadcast.
	DPPS,			// Perform single-precision dot products for up to 4 elements and broadcast.

	/* 3) Streaming load hint */

	MOVNTDQA,		// Provides a non-temporal hint that can cause adjacent 16-byte items within an aligned 64-
					//		byte region (a streaming line) to be fetched and held in a small set of temporary buffers
					//		(“streaming load buffers”). Subsequent streaming loads to other aligned 16-byte items in
					// the same streaming line may be supplied from the streaming load buffer and can improve throughput.

	/* 4) Packed blending */

	BLENDPD,		// Conditionally copies specified double-precision floating-point data elements in the source
					//		operand to the corresponding data elements in the destination, using an immediate byte control.
	BLENDPS,		// Conditionally copies specified single-precision floating-point data elements in the source
					//		operand to the corresponding data elements in the destination, using an immediate byte control.
	BLENDVPD,		// Conditionally copies specified double-precision floating-point data elements in the source
					//		operand to the corresponding data elements in the destination, using an implied mask.
	BLENDVPS,		// Conditionally copies specified single-precision floating-point data elements in the source
					//		operand to the corresponding data elements in the destination, using an implied mask.
	PBLENDVB,		//  Conditionally copies specified byte elements in the source operand to the corresponding
					//		elements in the destination, using an implied mask.
	PBLENDW,		// Conditionally copies specified word elements in the source operand to the corresponding
					//		elements in the destination, using an immediate byte control.

	/* 5) Packed integer MIN/MAX */

	PMINUW,			// Compare packed unsigned word integers.
	PMINUD,			// Compare packed unsigned dword integers.
	PMINSB,			// Compare packed signed byte integers.
	PMINSD,			// Compare packed signed dword integers.
	PMAXUW,			// Compare packed unsigned word integers.
	PMAXUD,			// Compare packed unsigned dword integers.
	PMAXSB,			// Compare packed signed byte integers.
	PMAXSD,			// Compare packed signed dword integers.

	/* 6) Floating point round with selectable rounding mode */

	ROUNDPS,		// Round packed single precision floating-point values into integer values and return rounded floating-point values.
	ROUNDPD,		// Round packed double precision floating-point values into integer values and return rounded floating-point values.
	ROUNDSS,		// Round the low packed single precision floating-point value into an integer value and return a rounded floating-point value.
	ROUNDSD,		// Round the low packed double precision floating-point value into an integer value and return a rounded floating-point value.

	/* 7) Insertion and extractions from XMM registers */

	EXTRACTPS,		// Extracts a single-precision floating-point value from a specified offset in an XMM register
					//		and stores the result to memory or a general-purpose register.
	INSERTPS,		// Inserts a single-precision floating-point value from either a 32-bit memory location or
					//		selected from a specified offset in an XMM register to a specified offset in the destination
					//		XMM register. In addition, INSERTPS allows zeroing out selected data elements in the destination, using a mask.
	PINSRB,			// Insert a byte value from a register or memory into an XMM register.
	PINSRD,			// Insert a dword value from 32-bit register or memory into an XMM register.
	PINSRQ,			// Insert a qword value from 64-bit register or memory into an XMM register.
	PEXTRB,			// Extract a byte from an XMM register and insert the value into a general-purpose register or memory.
	PEXTRW,			// Extract a word from an XMM register and insert the value into a general-purpose register or memory.
	PEXTRD,			// Extract a dword from an XMM register and insert the value into a general-purpose register or memory.
	PEXTRQ,			// Extract a qword from an XMM register and insert the value into a general-purpose register or memory.

	/* 8) Packed integer format conversion */

	PMOVSXBW,		// Sign extend the lower 8-bit integer of each packed word element into packed signed word integers.
	PMOVZXBW,		// Zero extend the lower 8-bit integer of each packed word element into packed signed word integers.
	PMOVSXBD,		// Sign extend the lower 8-bit integer of each packed dword element into packed signed dword integers.
	PMOVZXBD,		// Zero extend the lower 8-bit integer of each packed dword element into packed signed dword integers.
	PMOVSXWD,		// Sign extend the lower 16-bit integer of each packed dword element into packed signed dword integers.
	PMOVZXWD,		// Zero extend the lower 16-bit integer of each packed dword element into packed signed dword integers.
	PMOVSXBQ,		// Sign extend the lower 8-bit integer of each packed qword element into packed signed qword integers.
	PMOVZXBQ,		// Zero extend the lower 8-bit integer of each packed qword element into packed signed qword integers.
	PMOVSXWQ,		// Sign extend the lower 16-bit integer of each packed qword element into packed signed qword integers.
	PMOVZXWQ,		//  Zero extend the lower 16-bit integer of each packed qword element into packed signed qword integers.
	PMOVSXDQ,		// Sign extend the lower 32-bit integer of each packed qword element into packed signed qword integers.
	PMOVZXDQ,		// Zero extend the lower 32-bit integer of each packed qword element into packed signed qword integers.

	/* 9) Improved sums of absolute differences (SAD) for 4-byte blocks */

	MPSADBW,		// Performs eight 4-byte wide Sum of Absolute Differences operations to produce eight word integers.

	/* 10) Horizontal search */

	PHMINPOSUW,		// Finds the value and location of the minimum unsigned word from one of 8 horizontally
					//		packed unsigned words. The resulting value and location (offset within the source) are
					//		packed into the low dword of the destination XMM register.

	/* 11) Packed test */

	PTEST,			// Performs a logical AND between the destination with this mask and sets the ZF flag if the
					//		result is zero. The CF flag (zero for TEST) is set if the inverted mask AND’d with the destination is all zeroes.

	/* 12) Packed qword equality comparisons */

	PCMPEQQ,		// 128-bit packed qword equality test.

	/* 13) Dword packing with unsigned saturation */

	PACKUSDW,		// PACKUSDW packs dword to word with unsigned saturation.

	/* 14) String and text processing */

	PCMPESTRI,		// Packed compare explicit-length strings, return index in ECX/RCX.
	PCMPESTRM,		// Packed compare explicit-length strings, return mask in XMM0.
	PCMPISTRI,		// Packed compare implicit-length strings, return index in ECX/RCX.
	PCMPISTRM,		// Packed compare implicit-length strings, return mask in XMM0.

	/* 15) Packed comparison SIMD integer */

	PCMPGTQ,		// Performs logical compare of greater-than on packed integer quadwords.

	//////////////////////////
	// AES-NI AND PCLMULQDQ //
	//////////////////////////

	AESDEC,			// Perform an AES decryption round using an 128-bit state and a round key.
	AESDECLAST,		// Perform the last AES decryption round using an 128-bit state and a round key.
	AESENC,			// Perform an AES encryption round using an 128-bit state and a round key.
	AESENCLAST,		// Perform the last AES encryption round using an 128-bit state and a round key.
	AESIMC,			// Perform an inverse mix column transformation primitive.
	AESKEYGENASSIST,// Assist the creation of round keys with a key expansion schedule.
	PCLMULQDQ,		// Perform carryless multiplication of two 64-bit numbers.

	//////////////////////////////////////
	// ADVANCED VECTOR EXTENSIONS (AVX) //
	//////////////////////////////////////

	VBROADCASTF128,	// Broadcast 128-bit floating-point values in mem to low and high 128-bits in ymm1.
	VBROADCASTSD,	// Broadcast double-precision floating-point element in mem to four locations in ymm1.
	VBROADCASTSS,	// Broadcast single-precision floating-point element in mem to eight locations in ymm1.
	VEXTRACTF128,	// Extracts 128-bits of packed floating-point values from ymm2 and store results in xmm1/mem.
	VINSERTF128,	// Insert 128-bits of packed floating-point values from xmm3/mem and the remaining values from ymm2 into ymm1.
	VMASKMOVPS,		// Load packed single-precision values from mem using mask in ymm2 and store in ymm1./Store packed single-precision values from ymm2 mask in ymm1.
	VMASKMOVPD,		// Load packed double-precision values from mem using mask in ymm2 and store in ymm1./Store packed double-precision values from ymm2 using mask in ymm1.
	VPERMILPD,		// Permute Double-Precision Floating-Point values in ymm2 using controls from xmm3/mem and store result in ymm1.
	VPERMILPS,		// Permute Single-Precision Floating-Point values in ymm2 using controls from ymm3/mem	and store result in ymm1.
	VPERM2F128,		// Permute 128-bit floating-point fields in ymm2 and ymm3/mem using controls from imm8	and store result in ymm1.
	VTESTPS,		// Set ZF if ymm2/mem AND ymm1 result is all 0s in packed single-precision sign bits. Set CF
					//		if ymm2/mem AND NOT ymm1 result is all 0s in packed single-precision sign bits.
	VTESTPD,		// Set ZF if ymm2/mem AND ymm1 result is all 0s in packed double-precision sign bits. Set
					//		CF if ymm2/mem AND NOT ymm1 result is all 0s in packed double-precision sign bits.
	VZEROALL,		// Zero all YMM registers.
	VZEROUPPER,		// Zero upper 128 bits of all YMM registers.

	//////////////////////////////////////
	// 16-BIT FLOATING-POINT CONVERSION //
	//////////////////////////////////////

	VCVTPH2PS,		// Convert eight/four data element containing 16-bit floating-point data into eight/four single-precision floating-point data.
	VCVTPS2PH,		// Convert eight/four data element containing single-precision floating-point data into eight/four 16-bit floating-point data

	//////////////////////////////
	// FUSED-MULTIPLY ADD (FMA) //
	//////////////////////////////

	VFMADD132PD,	// Fused Multiply-Add of Packed Double-Precision Floating-Point Values.
	VFMADD213PD,	// Fused Multiply-Add of Packed Double-Precision Floating-Point Values.
	VFMADD231PD,	// Fused Multiply-Add of Packed Double-Precision Floating-Point Values.
	VFMADD132PS,	// Fused Multiply-Add of Packed Single-Precision Floating-Point Values.
	VFMADD213PS,	// Fused Multiply-Add of Packed Single-Precision Floating-Point Values.
	VFMADD231PS,	// Fused Multiply-Add of Packed Single-Precision Floating-Point Values.
	VFMADD132SD,	// Fused Multiply-Add of Scalar Double-Precision Floating-Point Values.
	VFMADD213SD,	// Fused Multiply-Add of Scalar Double-Precision Floating-Point Values.
	VFMADD231SD,	// Fused Multiply-Add of Scalar Double-Precision Floating-Point Values.
	VFMADD132SS,	// Fused Multiply-Add of Scalar Single-Precision Floating-Point Values.
	VFMADD213SS,	// Fused Multiply-Add of Scalar Single-Precision Floating-Point Values.
	VFMADD231SS,	// Fused Multiply-Add of Scalar Single-Precision Floating-Point Values.
	VFMADDSUB132PD,	// Fused Multiply-Alternating Add/Subtract of Packed Double-Precision Floating-Point Values.
	VFMADDSUB213PD,	// Fused Multiply-Alternating Add/Subtract of Packed Double-Precision Floating-Point Values.
	VFMADDSUB231PD,	// Fused Multiply-Alternating Add/Subtract of Packed Double-Precision Floating-Point Values.
	VFMADDSUB132PS,	// Fused Multiply-Alternating Add/Subtract of Packed Single-Precision Floating-Point Values.
	VFMADDSUB213PS,	// Fused Multiply-Alternating Add/Subtract of Packed Single-Precision Floating-Point Values.
	VFMADDSUB231PS,	// Fused Multiply-Alternating Add/Subtract of Packed Single-Precision Floating-Point Values.
	VFMSUBADD132PD,	// Fused Multiply-Alternating Subtract/Add of Packed Double-Precision Floating-Point Values.
	VFMSUBADD213PD,	// Fused Multiply-Alternating Subtract/Add of Packed Double-Precision Floating-Point Values.
	VFMSUBADD231PD,	// Fused Multiply-Alternating Subtract/Add of Packed Double-Precision Floating-Point Values.
	VFMSUBADD132PS,	// Fused Multiply-Alternating Subtract/Add of Packed Single-Precision Floating-Point Values.
	VFMSUBADD213PS,	// Fused Multiply-Alternating Subtract/Add of Packed Single-Precision Floating-Point Values.
	VFMSUBADD231PS,	// Fused Multiply-Alternating Subtract/Add of Packed Single-Precision Floating-Point Values.
	VFMSUB132PD,	// Fused Multiply-Subtract of Packed Double-Precision Floating-Point Values.
	VFMSUB213PD,	// Fused Multiply-Subtract of Packed Double-Precision Floating-Point Values.
	VFMSUB231PD,	// Fused Multiply-Subtract of Packed Double-Precision Floating-Point Values.
	VFMSUB132PS,	// Fused Multiply-Subtract of Packed Single-Precision Floating-Point Values.
	VFMSUB213PS,	// Fused Multiply-Subtract of Packed Single-Precision Floating-Point Values.
	VFMSUB231PS,	// Fused Multiply-Subtract of Packed Single-Precision Floating-Point Values.
	VFMSUB132SD,	// Fused Multiply-Subtract of Scalar Double-Precision Floating-Point Values.
	VFMSUB213SD,	// Fused Multiply-Subtract of Scalar Double-Precision Floating-Point Values.
	VFMSUB231SD,	// Fused Multiply-Subtract of Scalar Double-Precision Floating-Point Values.
	VFMSUB132SS,	// Fused Multiply-Subtract of Scalar Single-Precision Floating-Point Values.
	VFMSUB213SS,	// Fused Multiply-Subtract of Scalar Single-Precision Floating-Point Values.
	VFMSUB231SS,	// Fused Multiply-Subtract of Scalar Single-Precision Floating-Point Values.
	VFNMADD132PD,	// Fused Negative Multiply-Add of Packed Double-Precision Floating-Point Values.
	VFNMADD213PD,	// Fused Negative Multiply-Add of Packed Double-Precision Floating-Point Values.
	VFNMADD231PD,	// Fused Negative Multiply-Add of Packed Double-Precision Floating-Point Values.
	VFNMADD132PS,	// Fused Negative Multiply-Add of Packed Single-Precision Floating-Point Values.
	VFNMADD213PS,	// Fused Negative Multiply-Add of Packed Single-Precision Floating-Point Values.
	VFNMADD231PS,	// Fused Negative Multiply-Add of Packed Single-Precision Floating-Point Values.
	VFNMADD132SD,	// Fused Negative Multiply-Add of Scalar Double-Precision Floating-Point Values.
	VFNMADD213SD,	// Fused Negative Multiply-Add of Scalar Double-Precision Floating-Point Values.
	VFNMADD231SD,	// Fused Negative Multiply-Add of Scalar Double-Precision Floating-Point Values.
	VFNMADD132SS,	// Fused Negative Multiply-Add of Scalar Single-Precision Floating-Point Values.
	VFNMADD213SS,	// Fused Negative Multiply-Add of Scalar Single-Precision Floating-Point Values.
	VFNMADD231SS,	// Fused Negative Multiply-Add of Scalar Single-Precision Floating-Point Values.
	VFNMSUB132PD,	// Fused Negative Multiply-Subtract of Packed Double-Precision Floating-Point Values.
	VFNMSUB213PD,	// Fused Negative Multiply-Subtract of Packed Double-Precision Floating-Point Values.
	VFNMSUB231PD,	// Fused Negative Multiply-Subtract of Packed Double-Precision Floating-Point Values.
	VFNMSUB132PS,	// Fused Negative Multiply-Subtract of Packed Single-Precision Floating-Point Values.
	VFNMSUB213PS,	// Fused Negative Multiply-Subtract of Packed Single-Precision Floating-Point Values.
	VFNMSUB231PS,	// Fused Negative Multiply-Subtract of Packed Single-Precision Floating-Point Values.
	VFNMSUB132SD,	// Fused Negative Multiply-Subtract of Scalar Double-Precision Floating-Point Values.
	VFNMSUB213SD,	// Fused Negative Multiply-Subtract of Scalar Double-Precision Floating-Point Values.
	VFNMSUB231SD,	// Fused Negative Multiply-Subtract of Scalar Double-Precision Floating-Point Values.
	VFNMSUB132SS,	// Fused Negative Multiply-Subtract of Scalar Single-Precision Floating-Point Values.
	VFNMSUB213SS,	// Fused Negative Multiply-Subtract of Scalar Single-Precision Floating-Point Values.
	VFNMSUB231SS,	// Fused Negative Multiply-Subtract of Scalar Single-Precision Floating-Point Values.

	/////////////////////////////////////////
	// ADVANCED VECTOR EXTENSIONS 2 (AVX2) //
	/////////////////////////////////////////

	VPERMD,			// Permute doublewords in ymm3/m256 using indexes in ymm2 and store the result in ymm1.
	VPERMPD,		// Permute double-precision FP elements in ymm2/m256 using indexes in imm8 and store the result in ymm1.
	VPERMPS,		// Permute single-precision FP elements in ymm3/m256 using indexes in ymm2 and store the result in ymm1
	VPERMQ,			// Permute quadwords in ymm2/m256 using indexes in imm8 and store the result in ymm1.
	VPSLLVD,		// Shift doublewords in xmm2 left by amount specified in the corresponding element of
					//		xmm3/m128 or ymm3/m256 while shifting in 0s.
	VPSLLVQ,		// Shift quadwords in xmm2 left by amount specified in the corresponding element of
					//		xmm3/m128 or ymm3/m256 while shifting in 0s.
	VPSRAVD,		// Shift doublewords in xmm2 right by amount specified in the corresponding element of
					//		xmm3/m128 while shifting in the sign bits.
	VPSRLVD,		// Shift doublewords in xmm2 right by amount specified in the corresponding element of
					//		xmm3/m128 or ymm3/m256 while shifting in 0s.
	VPSRLVQ,		// Shift quadwords in xmm2 right by amount specified in the corresponding element of
					//		xmm3/m128 or ymm3/m256 while shifting in 0s.
	VGATHERDD,		// Using dword indices specified in vm32x/y, gather dword values from memory conditioned on
					//		mask specified by x/ymm2. Conditionally gathered elements are merged into x/ymm1.
	VGATHERQD,		// Using qword indices specified in vm64x/y, gather dword values from memory conditioned on
					//		mask specified by x/ymm2. Conditionally gathered elements are merged into x/ymm1.
	VGATHERDPD,		// Using dword indices specified in vm32x, gather double-precision FP values from memory
					//		conditioned on mask specified by x/ymm2. Conditionally gathered elements are merged into x/ymm1.
	VGATHERQPD,		// Using qword indices specified in vm64x, gather double-precision FP values from memory
					//		conditioned on mask specified by x/ymm2. Conditionally gathered elements are merged into x/ymm1.
	VGATHERDPS,		// Using dword indices specified in vm32x, gather single-precision FP values from memory
					//		conditioned on mask specified by xmm2. Conditionally gathered elements are merged into xmm1.
	VGATHERQPS,		// Using qword indices specified in vm64x/y, gather single-precision FP values from memory
					//		conditioned on mask specified by x/ymm2. Conditionally gathered elements are merged into x/ymm1.
	VGATHERDQ,		// Using dword indices specified in vm32x, gather qword values from memory conditioned on
					//		mask specified by x/ymm2. Conditionally gathered elements are merged into x/ymm1.
	VGATHERQQ,		// Using qword indices specified in vm64x/y, gather qword values from memory conditioned on
					//		mask specified by x/ymm2. Conditionally gathered elements are merged into x/ymm1.

	////////////////////////////////////////////////////
	// TRANSACTIONAL SYNCHRONIZATION EXTENSIONS (TSX) //
	////////////////////////////////////////////////////

	XABORT,			// Abort an RTM transaction execution.
	XACQUIRE,		// Prefix hint to the beginning of an HLE transaction region.
	XRELEASE,		// Prefix hint to the end of an HLE transaction region.
	XBEGIN,			// Transaction begin of an RTM transaction region.
	XEND,			// Transaction end of an RTM transaction region.
	XTEST,			// Test if executing in a transactional region.

	////////////////////
	// SHA EXTENSIONS //
	////////////////////

	SHA1MSG1,		// Perform an intermediate calculation for the next four SHA1 message dwords from the previous message dwords.
	SHA1MSG2,		// Perform the final calculation for the next four SHA1 message dwords from the intermediate message dwords.
	SHA1NEXTE,		// Calculate SHA1 state E after four rounds.
	SHA1RNDS4,		// Perform four rounds of SHA1 operations.
	SHA256MSG1,		// Perform an intermediate calculation for the next four SHA256 message dwords.
	SHA256MSG2,		// Perform the final calculation for the next four SHA256 message dwords.
	SHA256RNDS2,	// Perform two rounds of SHA256 operations.

	//////////////////////////////////////////////
	// ADVANCED VECTOR EXTENSIONS 512 (AVX-512) //
	//////////////////////////////////////////////

	VALIGND,		// Perform dword alignment of two concatenated source vectors.
	VALIGNQ,		// Perform qword alignment of two concatenated source vectors.
	VBLENDMPD,		// Replace the VBLENDVPD instruction (using opmask as select control).
	VBLENDMPS,		// Replace the VBLENDVPS instruction (using opmask as select control).
	VCOMPRESSPD,	// Compress packed DP elements of a vector.
	VCOMPRESSPS,	// Compress packed SP elements of a vector.
	VCVTPD2UDQ,		// Convert packed DP FP elements of a vector to packed unsigned 32-bit integers.
	VCVTPS2UDQ, 	// Convert packed SP FP elements of a vector to packed unsigned 32-bit integers.
	VCVTQQ2PD,		// Convert packed signed 64-bit integers to packed DP FP elements.
	VCVTQQ2PS,		// Convert packed signed 64-bit integers to packed SP FP elements.
	VCVTSD2USI,		// Convert the low DP FP element of a vector to an unsigned integer.
	VCVTSS2USI,		// Convert the low SP FP element of a vector to an unsigned integer.
	VCVTUDQ2PD,		// Convert packed unsigned 32-bit integers to packed DP FP elements.
	VCVTUDQ2PS,		// Convert packed unsigned 32-bit integers to packed SP FP elements.
	VCVTUSI2USD,	// Convert an unsigned integer to the low DP FP element and merge to a vector.
	VCVTUSI2USS,	// Convert an unsigned integer to the low SP FP element and merge to a vector.
	VEXPANDPD,		// Expand packed DP elements of a vector.
	VEXPANDPS,		// Expand packed SP elements of a vector.
	VEXTRACTF32X4,	// Extract a vector from a full-length vector with 32-bit granular update.
	VEXTRACTF64X4,	// Extract a vector from a full-length vector with 64-bit granular update.
	VEXTRACTI32X4,	// Extract a vector from a full-length vector with 32-bit granular update.
	VEXTRACTI64X4,	// Extract a vector from a full-length vector with 64-bit granular update.
	VFIXUPIMMPD,	// Perform fix-up to special values in DP FP vectors.
	VFIXUPIMMPS,	// Perform fix-up to special values in SP FP vectors.
	VFIXUPIMMSD,	// Perform fix-up to special values of the low DP FP element.
	VFIXUPIMMSS,	// Perform fix-up to special values of the low SP FP element.
	VGETEXPPD,		// Convert the exponent of DP FP elements of a vector into FP values.
	VGETEXPPS,		// Convert the exponent of SP FP elements of a vector into FP values.
	VGETEXPSD,		// Convert the exponent of the low DP FP element in a vector into FP value.
	VGETEXPSS,		// Convert the exponent of the low SP FP element in a vector into FP value.
	VGETMANTPD,		// Convert the mantissa of DP FP elements of a vector into FP values.
	VGETMANTPS,		// Convert the mantissa of SP FP elements of a vector into FP values.
	VGETMANTSD,		// Convert the mantissa of the low DP FP element of a vector into FP value.
	VGETMANTSS,		// Convert the mantissa of the low SP FP element of a vector into FP value.
	VINSERTF32X4,	// Insert a 128-bit vector into a full-length vector with 32-bit granular update.
	VINSERTF64X4,	// Insert a 256-bit vector into a full-length vector with 64-bit granular update.
	VMOVDQA32,		// VMOVDQA with 32-bit granular conditional update.
	VMOVDQA64,		// VMOVDQA with 64-bit granular conditional update.
	VMOVDQU32,		// VMOVDQU with 32-bit granular conditional update.
	VMOVDQU64,		// VMOVDQU with 64-bit granular conditional update.
	VPBLENDMD,		// Blend dword elements using opmask as select control.
	VPBLENDMQ,		// Blend qword elements using opmask as select control.
	VPBROADCASTD,	// Broadcast from general-purpose register to vector register.
	VPBROADCASTQ,	// Broadcast from general-purpose register to vector register.
	VPCMPD,			// Compare packed signed dwords using specified primitive.
	VPCMUP,			// Compare packed unsigned dwords using specified primitive.
	VPCMPQ,			// Compare packed signed quadwords using specified primitive.
	VPCMUQ,			// Compare packed unsigned quadwords using specified primitive.
	VPCOMPRESSQ,	// Compress packed 64-bit elements of a vector.
	VPCOMPRESSD,	// Compress packed 32-bit elements of a vector.
	VPERMI2D,		// Full permute of two tables of dword elements overwriting the index vector.
	VPERMI2Q,		// Full permute of two tables of qword elements overwriting the index vector.
	VPERMI2PD,		// Full permute of two tables of DP elements overwriting the index vector.
	VPERMI2PS,		// Full permute of two tables of SP elements overwriting the index vector.
	VPERMT2D,		// Full permute of two tables of dword elements overwriting one source table.
	VPERMT2Q,		// Full permute of two tables of qword elements overwriting one source table.
	VPERMT2PD,		// Full permute of two tables of DP elements overwriting one source table.
	VPERMT2PS,		// Full permute of two tables of SP elements overwriting one source table.
	VPEXPANDD,		// Expand packed dword elements of a vector.
	VPEXPANDQ,		// Expand packed qword elements of a vector.
	VPMAXSQ,		// Compute maximum of packed signed 64-bit integer elements.
	VPMAXUD,		// Compute maximum of packed unsigned 32-bit integer elements.
	VPMAXUQ,		// Compute maximum of packed unsigned 64-bit integer elements.
	VPMINSQ,		// Compute minimum of packed signed 64-bit integer elements.
	VPMINUD,		// Compute minimum of packed unsigned 32-bit integer elements.
	VPMINUQ,		// Compute minimum of packed unsigned 64-bit integer elements.
	VPMOVSQB,		// Down convert qword elements in a vector to byte elements using truncation saturation.
	VPMOVUSQB, 		// Down convert qword elements in a vector to byte elements using truncation unsigned saturation.
	VPMOVSQW,		// Down convert qword elements in a vectorto word elements using truncation saturation.
	VPMOVUSQW,		// Down convert qword elements in a vectorto word elements using truncation unsigned saturation.
	VPMOVSQD,		// Down convert qword elements in a vector to dword elements using truncation saturation.
	VPMOVUSQD, 		// Down convert qword elements in a vector to dword elements using truncation unsigned saturation.
	VPMOVSDB,		// Down convert dword elements in a vector to byte elements using truncation saturation.
	VPMOVUSDB,		// Down convert dword elements in a vector to byte elements using truncation unsigned saturation.
	VPMOVSDW,		// Down convert dword elements in a vector to word elements using truncation saturation.
	VPMOVUSDW,  	// Down convert dword elements in a vector to word elements using truncation unsigned saturation.
	VPROLD,			// Rotate dword element left by a constant shift count with conditional update.
	VPROLQ,			// Rotate qword element left by a constant shift count with conditional update.
	VPROLVD,		// Rotate dword element left by shift counts specified in a vector with conditional update.
	VPROLVQ,		// Rotate qword element left by shift counts specified in a vector with conditional update.
	VPRORD,			// Rotate dword element right by a constant shift count with conditional update.
	VPRORQ,			// Rotate qword element right by a constant shift count with conditional update.
	VPRORRD,		// Rotate dword element right by shift counts specified in a vector with conditional update.
	VPRORRQ,		// Rotate qword element right by shift counts specified in a vector with conditional update.
	VPSCATTERDD,	// Scatter dword elements in a vector to memory using dword indices.
	VPSCATTERDQ,	// Scatter qword elements in a vector to memory using dword indices.
	VPSCATTERQD,	// Scatter dword elements in a vector to memory using qword indices.
	VPSCATTERQQ,	// Scatter qword elements in a vector to memory using qword indices.
	VPSRAQ,			// Shift qwords right by a constant shift count and shifting in sign bits.
	VPSRAVQ,		// Shift qwords right by shift counts in a vector and shifting in sign bits.
	VPTESTNMD,		// Perform bitwise NAND of dword elements of two vectors and write results to opmask.
	VPTESTNMQ,		// Perform bitwise NAND of qword elements of two vectors and write results to opmask.
	VPTERLOGD,		// Perform bitwise ternary logic operation of three vectors with 32-bit granular conditional update.
	VPTERLOGQ,		// Perform bitwise ternary logic operation of three vectors with 64-bit granular conditional update.
	VPTESTMD,		// Perform bitwise AND of dword elements of two vectors and write results to opmask.
	VPTESTMQ,		// Perform bitwise AND of qword elements of two vectors and write results to opmask.
	VRCP14PD,		// Compute approximate reciprocals of packed DP FP elements of a vector.
	VRCP14PS,		// Compute approximate reciprocals of packed SP FP elements of a vector.
	VRCP14SD,		// Compute the approximate reciprocal of the low DP FP element of a vector.
	VRCP14SS,		// Compute the approximate reciprocal of the low SP FP element of a vector.
	VRNDSCALEPD,	// Round packed DP FP elements of a vector to specified number of fraction bits.
	VRNDSCALEPS,	// Round packed SP FP elements of a vector to specified number of fraction bits.
	VRNDSCALESD,	// Round the low DP FP element of a vector to specified number of fraction bits.
	VRNDSCALESS,	// Round the low SP FP element of a vector to specified number of fraction bits.
	VRSQRT14PD,		// Compute approximate reciprocals of square roots of packed DP FP elements of a vector.
	VRSQRT14PS,		// Compute approximate reciprocals of square roots of packed SP FP elements of a vector.
	VRSQRT14SD,		// Compute the approximate reciprocal of square root of the low DP FP element of a vector.
	VRSQRT14SS,		// Compute the approximate reciprocal of square root of the low SP FP element of a vector.
	VSCALEPD,		// Multiply packed DP FP elements of a vector by powers of two with exponents specified in a second vector.
	VSCALEPS,		// Multiply packed SP FP elements of a vector by powers of two with exponents specified in a second vector.
	VSCALESD,		// Multiply the low DP FP element of a vector by powers of two with exponent specified in the corresponding element of a second vector.
	VSCALESS,		// Multiply the low SP FP element of a vector by powers of two with exponent specified in the corresponding element of a second vector.
	VSCATTERDD,		// Scatter SP FP elements in a vector to memory using dword indices.
	VSCATTERDQ,		// Scatter DP FP elements in a vector to memory using dword indices.
	VSCATTERQD,		// Scatter SP FP elements in a vector to memory using qword indices.
	VSCATTERQQ,		// Scatter DP FP elements in a vector to memory using qword indices.
	VSHUFF32X4,		// Shuffle 128-bit lanes of a vector with 32-bit granular conditional update.
	VSHUFF64X4,		// Shuffle 128-bit lanes of a vector with 64-bit granular conditional update.
	VSHUFI32X4,		// Shuffle 128-bit lanes of a vector with 32-bit granular conditional update.
	VSHUFI64X4,		// Shuffle 128-bit lanes of a vector with 64-bit granular conditional update.
	VCVTPD2QQ,		// Convert packed DP FP elements of a vector to packed signed 64-bit integers.
	VCVTPD2UQQ,		// Convert packed DP FP elements of a vector to packed unsigned 64-bit integers.
	VCVTPS2QQ,		// Convert packed SP FP elements of a vector to packed signed 64-bit integers.
	VCVTPS2UQQ,		// Convert packed SP FP elements of a vector to packed unsigned 64-bit integers.
	VCVTUQQ2PD,		// Convert packed unsigned 64-bit integers to packed DP FP elements.
	VCVTUQQ2PS,		// Convert packed unsigned 64-bit integers to packed SP FP elements.
	VEXTRACTF64X2,	// Extract a vector from a full-length vector with 64-bit granular update.
	VEXTRACTI64X2,	// Extract a vector from a full-length vector with 64-bit granular update.
	VFPCLASSPD,		// Test packed DP FP elements in a vector by numeric/special-value category.
	VFPCLASSPS,		// Test packed SP FP elements in a vector by numeric/special-value category.
	VFPCLASSSD,		// Test the low DP FP element by numeric-value category.
	VFPCLASSSS,		// Test the low SP FP element by special-value category.
	VINSERTF64X2,	// Insert a 128-bit vector into a full-length vector with 64-bit granular update.
	VINSERTI64X2,	// Insert a 128-bit vector into a full-length vector with 64-bit granular update.
	VPMOVM2D,		// Convert opmask register to vector register in 32-bit granularity.
	VPMOVM2Q,		// Convert opmask register to vector register in 64-bit granularity.
	VPMOVB2D,		// Convert a vector register in 32-bit granularity to an opmask register.
	VPMOVQ2M,		// Convert a vector register in 64-bit granularity to an opmask register.
	VPMULLQ,		// Multiply packed signed 64-bit integer elements of two vectors and store low 64-bit signed result.
	VRANGEPD,		// Perform RANGE operation on each pair of DP FP elements of two vectors using specified range primitive in imm8.
	VRANGEPS,		// Perform RANGE operation on each pair of SP FP elements of two vectors using specified range primitive in imm8.
	VRANGESD,		// Perform RANGE operation on the pair of low DP FP element of two vectors using specified range primitive in imm8.
	VRANGESS,		// Perform RANGE operation on the pair of low SP FP element of two vectors using specified range primitive in imm8.
	VREDUCEPD,		// Perform Reduction operation on packed DP FP elements of a vector using specified reduction primitive in imm8.
	VREDUCEPS,		// Perform Reduction operation on packed SP FP elements of a vector using specified reduction primitive in imm8.
	VREDUCESD,		// Perform Reduction operation on the low DP FP element of a vector using specified reduction primitive in imm8.
	VREDUCESS,		// Perform Reduction operation on the low SP FP element of a vector using specified reduction primitive in imm8.
	VDBPSADBW,		// Double block packed Sum-Absolute-Differences on unsigned bytes.
	VMOVDQU8,		// VMOVDQU with 8-bit granular conditional update.
	VMOVDQU16,		// VMOVDQU with 16-bit granular conditional update.
	VPBLENDMB,		// Replaces the VPBLENDVB instruction (using opmask as select control).
	VPBLENDMW,		// Blend word elements using opmask as select control.
	VPBROADCASTB,	// Broadcast from general-purpose register to vector register.
	VPBROADCASTW,	// Broadcast from general-purpose register to vector register.
	VPCMPB,			// Compare packed signed bytes using specified primitive.
	VPCMUB,			// Compare packed unsigned bytes using specified primitive.
	VPCMPW,			// Compare packed signed words using specified primitive.
	VPCMUW,			// Compare packed unsigned words using specified primitive.
	VPERMW,			// Permute packed word elements.
	VPERMI2B,		// Full permute from two tables of byte elements overwriting the index vector.
	VPERMI2W,		// Full permute from two tables of word elements overwriting the index vector.
	VPMOVM2B,		// Convert opmask register to vector register in 8-bit granularity.
	VPMOVM2W,		// Convert opmask register to vector register in 16-bit granularity.
	VPMOVB2M,		// Convert a vector register in 8-bit granularity to an opmask register.
	VPMOVW2M,		// Convert a vector register in 16-bit granularity to an opmask register.
	VPMOVSWB,		// Down convert word elements in a vector to byte elements using truncation saturation.
	VPMOVUSWB,  	// Down convert word elements in a vector to byte elements using truncation unsigned saturation.
	VPSLLVW,		// Shift word elements in a vector left by shift counts in a vector.
	VPSRAVW,		// Shift words right by shift counts in a vector and shifting in sign bits.
	VPSRLVW,		// Shift word elements in a vector right by shift counts in a vector.
	VPTESTNMB,		// Perform bitwise NAND of byte elements of two vectors and write results to opmask.
	VPTESTNMW,		// Perform bitwise NAND of word elements of two vectors and write results to opmask.
	VPTESTMB,		// Perform bitwise AND of byte elements of two vectors and write results to opmask.
	VPTESTMW,		// Perform bitwise AND of word elements of two vectors and write results to opmask.
	VPBROADCASTM,	// Broadcast from opmask register to vector register.
	VPCONFLICTD,	// Detect conflicts within a vector of packed 32-bit integers.
	VPCONFLICTQ,	// Detect conflicts within a vector of packed 64-bit integers.
	VPLZCNTD,		// Count the number of leading zero bits of packed dword elements.
	VPLZCNTQ,		// Count the number of leading zero bits of packed qword elements.
	KADD,			// Add two 8/16/32/64-bit opmasks.
	KAND,			// Logical AND two 8/16/32/64-bit opmasks.
	KANDN,			// Logical AND NOT two 8/16/32/64-bit opmasks.
	KMOV,			// Move from or move to opmask register of 8/16/32/64-bit data.
	KNOT,			// Bitwise NOT of two 8/16/32/64-bit opmasks.
	KOR,			// Logical OR two 8/16/32/64-bit opmasks.
	KORTEST,		// Update EFLAGS according to the result of bitwise OR of two 8/16/32/64-bit opmasks.
	KSHIFTL,		// Shift left 8/16/32/64-bit opmask by specified count.
	KSHIFTR,		// Shift right 8/16/32/64-bit opmask by specified count.
	KTEST,			// Update EFLAGS according to the result of bitwise TEST of two 8/16/32/64-bit opmasks.
	KUNPCK,			// Unpack and interleave two 8/16/32-bit opmasks into 16/32/64-bit mask.
	KXNOR,			// Bitwise logical XNOR of two 8/16/32/64-bit opmasks.
	KXOR,			// Logical XOR of two 8/16/32/64-bit opmasks.
	VEXP2PD,		// Compute approximate base-2 exponential of packed DP FP elements of a vector.
	VEXP2PS,		// Compute approximate base-2 exponential of packed SP FP elements of a vector.
	VEXP2SD,		// Compute approximate base-2 exponential of the low DP FP element of a vector.
	VEXP2SS,		// Compute approximate base-2 exponential of the low SP FP element of a vector.
	VRCP28PD,		// Compute approximate reciprocals to 28 bits of packed DP FP elements of a vector.
	VRCP28PS,		// Compute approximate reciprocals to 28 bits of packed SP FP elements of a vector.
	VRCP28SD,		// Compute the approximate reciprocal to 28 bits of the low DP FP element of a vector.
	VRCP28SS,		// Compute the approximate reciprocal to 28 bits of the low SP FP element of a vector.
	VRSQRT28PD,		// Compute approximate reciprocals of square roots to 28 bits of packed DP FP elements of a vector.
	VRSQRT28PS,		// Compute approximate reciprocals of square roots to 28 bits of packed SP FP elements of a vector.
	VRSQRT28SD,		// Compute the approximate reciprocal of square root to 28 bits of the low DP FP element of a vector.
	VRSQRT28SS,		// Compute the approximate reciprocal of square root to 28 bits of the low SP FP element of a vector.
	VGATHERPF0DPD,	// Sparse prefetch of packed DP FP vector with T0 hint using dword indices.
	VGATHERPF0DPS,	// Sparse prefetch of packed SP FP vector with T0 hint using dword indices.
	VGATHERPF0QPD,	// Sparse prefetch of packed DP FP vector with T0 hint using qword indices.
	VGATHERPF0QPS,	// Sparse prefetch of packed SP FP vector with T0 hint using qword indices.
	VGATHERPF1DPD,	// Sparse prefetch of packed SP FP vector with T1 hint using dword indices.
	VGATHERPF1DPS,	// Sparse prefetch of packed DP FP vector with T1 hint using dword indices.
	VGATHERPF1QPD,	// Sparse prefetch of packed DP FP vector with T1 hint using qword indices.
	VGATHERPF1QPS,	// Sparse prefetch of packed SP FP vector with T1 hint using qword indices.
	VSCATTERPF0DPD,	// Sparse prefetch of packed DP FP vector with T0 hint to write using dword indices.
	VSCATTERPF0DPS,	// Sparse prefetch of packed SP FP vector with T0 hint to write using dword indices.
	VSCATTERPF0QPD,	// Sparse prefetch of packed DP FP vector with T0 hint to write using qword indices.
	VSCATTERPF0QPS,	// Sparse prefetch of packed SP FP vector with T0 hint to write using qword indices.
	VSCATTERPF1DPD,	// Sparse prefetch of packed DP FP vector with T1 hint to write using dword indices.
	VSCATTERPF1DPS,	// Sparse prefetch of packed SP FP vector with T1 hint to write using dword indices.
	VSCATTERPF1QPD,	// Sparse prefetch of packed DP FP vector with T1 hint to write using qword indices.
	VSCATTERPF1QPS,	// Sparse prefetch of packed SP FP vector with T1 hint to write using qword indices.

	/////////////
	// SYSTEM  //
	/////////////

	CLAC,			// Clear AC Flag in EFLAGS register.
	STAC,			// Set AC Flag in EFLAGS register.
	LGDT,			// Load global descriptor table (GDT) register.
	SGDT,			// Store global descriptor table (GDT) register.
	LLDT,			// Load local descriptor table (LDT) register.
	SLDT,			// Store local descriptor table (LDT) register.
	LTR,			// Load task register.
	STR,			// Store task register.
	LIDT,			// Load interrupt descriptor table (IDT) register.
	SIDT,			// Store interrupt descriptor table (IDT) register.
	LMSW,			// Load machine status word.
	SMSW,			// Store machine status word.
	CLTS,			// Clear the task-switched flag.
	ARPL,			// Adjust requested privilege level.
	LAR,			// Load access rights.
	LSL,			// Load segment limit.
	VERR,			// Verify segment for reading.
	VERW,			// Verify segment for writing.
	INVD,			// Invalidate cache, no writeback.
	WBINVD,			// Invalidate cache, with writeback.
	INVLPG,			// Invalidate TLB Entry.
	INVPCID,		// Invalidate Process-Context Identifier.
	LOCK,			// Perform atomic access to memory (can be applied to a number of general purpose instructions that provide memory source/destination access).
	HLT,			// Halt processor.
	RSM,			// Return from system management mode (SMM).
	RDMSR,			// Read model-specific register.
	WRMSR,			// Write model-specific register.
	RDPMC,			// Read performance monitoring counters.
	RDTSC,			// Read time stamp counter.
	RDTSCP,			// Read time stamp counter and processor ID.
	SYSENTER,		// Fast System Call, transfers to a flat protected mode kernel at CPL = 0.
	SYSEXIT,		// Fast System Call, transfers to a flat protected mode kernel at CPL = 3.
	XSAVES,			// Save processor supervisor-mode extended states to memory.
	XRSTORS,		// Restore processor supervisor-mode extended states from memory.
	XSETBV,			// Writes the state of an extended control register.
	RDFSBASE,		// Reads from FS base address at any privilege level.
	RDGSBASE,		// Reads from GS base address at any privilege level.
	WRFSBASE,		// Writes to FS base address at any privilege level.
	WRGSBASE,		// Writes to GS base address at any privilege level.
	
	/////////////////
	// 64-BIT MODE //
	/////////////////

	CDQE,			// Convert doubleword to quadword.
	CMPSQ,			// Compare string operands.
	CMPXCHG16B,		// Compare RDX:RAX with m128.
	LODSQ,			// Load qword at address (R)SI into RAX.
	MOVSQ,			// Move qword from address (R)SI to (R)DI.
	STOSQ,			// Store RAX at address RDI.
	SWAPGS,			// Exchanges current GS base register value with value in MSR address C0000102H.
	SYSCALL,		// Fast call to privilege level 0 system procedures.
	SYSRET,			// Return from fast systemcall.

	////////////////////////////////
	// VIRTUAL MACHINE EXTENSIONS //
	////////////////////////////////

	VMPTRLD,		// Takes a single 64-bit source operand in memory. It makes the referenced VMCS active and current.
	VMPTRST,		// Takes a single 64-bit destination operand that is in memory. Current-VMCS pointer is stored into the destination operand.
	VMCLEAR,		// Takes a single 64-bit operand in memory. The instruction sets the launch state of the VMCS
					//		referenced by the operand to “clear”, renders that VMCS inactive, and ensures that data
					//		for the VMCS have been written to the VMCS-data area in the referenced VMCS region.
	VMREAD,			// Reads a component from the VMCS (the encoding of that field is given in a register operand) and stores it into a destination operand.
	VMWRITE,		// Writes a component to the VMCS (the encoding of that field is given in a register operand) from a source operand.
	VMLAUNCH,		// Launches a virtual machine managed by the VMCS. A VM entry occurs, transferring control to the VM.
	VMRESUME,		// Resumes a virtual machine managed by the VMCS. A VM entry occurs, transferring control to the VM.
	VMXOFF,			// Causes the processor to leave VMX operation.
	VMXON,			// Takes a single 64-bit source operand in memory. It causes a logical processor to enter VMX
					//		root operation and to use the memory referenced by the operand to support VMX operation.
	INVEPT,			//  Invalidate cached Extended Page Table (EPT) mappings in the processor to synchronize
					//		address translation in virtual machines with memory-resident EPT pages.
	INVVPID,		// Invalidate cached mappings of address translation based on the Virtual Processor ID (VPID).
	VMCALL,			// Allows a guest in VMX non-root operation to call the VMM for service. A VM exit occurs, transferring control to the VMM.
	VMFUNC,			// This instruction allows software in VMX non-root operation to invoke a VM function, which
					// 		is processor functionality enabled and configured by software in VMX root operation. No VM exit occurs.

	///////////////////////////
	// SAFER MODE EXTENSIONS //
	///////////////////////////

	GETSEC_CAPABILITIES,	// Returns the available leaf functions of the GETSEC instruction.
	GETSEC_ENTERACCS,		// Loads an authenticated code chipset module and enters authenticated code execution mode.
	GETSEC_EXITAC,			// Exits authenticated code execution mode.
	GETSEC_SENTER,			// Establishes a Measured Launched Environment (MLE) which has its dynamic root of trust
							//		anchored to a chipset supporting Intel Trusted Execution Technology.
	GETSEC_SEXIT,			// Exits the MLE.
	GETSEC_PARAMETERS,		// Returns SMX related parameter information.
	GETSEC_SMCRTL,			// SMX mode control.
	GETSEC_WAKEUP,			// Wakes up sleeping logical processors inside an MLE.

	//////////////////////////////////
	// MEMORY PROTECTION EXTENSIONS //
	//////////////////////////////////

	BNDMK,			// Create a LowerBound and a UpperBound in a register.
	BNDCL,			// Check the address of a memory reference against a LowerBound.
	BNDCU,			// Check the address of a memory reference against an UpperBound in 1’s compliment form.
	BNDCN,			// Check the address of a memory reference against an UpperBound not in 1’s compliment form.
	BNDMOV,			// Copy or load from memory of the LowerBound and UpperBound to a register./Store to memory of the LowerBound and UpperBound from a register.
	BNDLDX,			// Load bounds using address translation.
	BNDSTX,			// Store bounds using address translation.

	////////////////////////////////
	// SOFTWARE GUARDS EXTENSIONS //
	////////////////////////////////

	ENCLS_EADD,		// Add a page.
	ENCLS_EBLOCK,	// Block an EPC page.
	ENCLS_ECREATE,	// Create an enclave.
	ENCLS_EDBGRD,	// Read data by debugger.
	ENCLS_EDBGWR,	// Write data by debugger.
	ENCLS_EEXTEND,	// Extend EPC page measurement.
	ENCLS_EINIT,	// Initialize an enclave.
	ENCLS_ELDB,		// Load an EPC page as blocked.
	ENCLS_ELDU,		// Load an EPC page as unblocked.
	ENCLS_EPA,		// Add version array.
	ENCLS_EREMOVE,	// Remove a page from EPC.
	ENCLS_ETRACK,	// Activate EBLOCK checks.
	ENCLS_EWB,		// Write back/invalidate an EPC page.
	ENCLS_EENTER,	// Enter an Enclave.
	ENCLS_EEXIT,	// Exit an Enclave.
	ENCLS_EGETKEY,	// Create a cryptographic key.
	ENCLS_EREPORT,	// Create a cryptographic report.
	ENCLS_ERESUME,	// Re-enter an Enclave.

	/////////////////////////////
	// SHADOW STACK MANAGEMENT //
	/////////////////////////////

	CLRSSBSY,		// Clear busy bit in a supervisor shadow stack token.
	INCSSP,			// Increment the shadow stack pointer (SSP).
	RDSSP,			// Read shadow stack point (SSP).
	RSTORSSP,		// Restore a shadow stack pointer (SSP).
	SAVEPREVSSP,	// Save previous shadow stack pointer (SSP).
	SETSSBSY,		// Set busy bit in a supervisor shadow stack token.
	WRSS,			// Write to a shadow stack.
	WRUSS,			// Write to a user mode shadow stack.
	
	//////////////////////////////////
	// CONTROL TRANSFER TERMINATING //
	//////////////////////////////////

	ENDBR32,		// Terminate an Indirect Branch in 32-bit and Compatibility Mode.
	ENDBR64,		// Terminate an Indirect Branch in 64-bit Mode.

	///TODO: SORT NEXT 

	VCVTDQ2PD,		// TODO: UNDOCUMENTED DESPRITION: VARIES PER SIZE SPETIALIZATION
	VCVTDQ2PS,		// TODO: UNDOCUMENTED DESPRITION: VARIES PER SIZE SPETIALIZATION
	VCVTPD2DQ,		// TODO: UNDOCUMENTED DESPRITION: VARIES PER SIZE SPETIALIZATION
	VCVTPD2PS,
	VCVTPS2DQ,
	VCVTPS2PD,
	VCVTSD2SI,
	VCVTSD2SS,
	VCVTSI2SD,
	VCVTSI2SS,
	VCVTSS2SD,
	VCVTSS2SI,
	VCVTTPD2DQ,
	VCVTTPS2DQ,
	VCVTTSD2SI,
	VCVTTSS2SI,
	VDIVPD,
	VDIVPS,
	VDIVSD,
	VDPPD,
	VDPPS,
	ENCODEKEY256,	//  Wrap a 256-bit AES key from XMM1:XMM0 into a key handle and store it in XMM0-3.
	VEXTRACTPS,
	FRNDINT,		// Round ST(0) to an integer.
	FXRSTOR,		// Restore the x87 FPU, MMX, XMM, and MXCSR register state from m512byte.
	FXRSTOR64, 		// Restore the x87 FPU, MMX, XMM, and MXCSR register state from m512byte.
	FXSAVE,			// Save the x87 FPU, MMX, XMM, and MXCSR register state to m512byte.
	FXSAVE64,		// Save the x87 FPU, MMX, XMM, and MXCSR register state to m512byte.
	GF2P8AFFINEINVQB,	//  Computes inverse affine transformation in the finite field GF(2^8).
	VGF2P8AFFINEINVQB,	// Computes inverse affine transformation in the finite field GF(2^8).
	GF2P8AFFINEQB,	// Computes affine transformation in the finite field GF(2^8).
	VGF2P8AFFINEQB, // Computes affine transformation in the finite field GF(2^8).
	GF2P8MULB,		// Multiplies elements in the finite field GF(2^8). 
	VGF2P8MULB,		// Multiplies elements in the finite field GF(2^8).
	VHADDPD,		// Horizontal add packed double-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	VHADDPS,		// Horizontal add packed single-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	VHSUBPD,		// Horizontal subtract packed double-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	VHSUBPS,		// Horizontal subtract packed single-precision floating-point values from (y/x)mm2 and (y/x)mm3/mem.
	VINSERTPS,		//  Insert a single-precision floating-point value selected by imm8 from xmm3/m32 and merge with values in
					//			xmm2 at the specified destination element specified by imm8 and write out the result and zero out
					//			destination elements in xmm1 as indicated in imm8.
	INT3,			// Generate breakpoint trap.
	INT1,			// Generate debug trap.
	IRETD,			// Interrupt return (32-bit operand size).
	IRETQ,			// Interrupt return (64-bit operand size).

	/*
	KANDW,			// Bitwise AND 16 bits masks k2 and k3 and place result in k1.
	KANDB,			// Bitwise AND 8 bits masks k2 and k3 and place result in k1. 
	KANDQ,			// Bitwise AND 64 bits masks k2 and k3 and place result in k1.
	KANDD,			// Bitwise AND 32 bits masks k2 and k3 and place result in k1.
	KMOVW,			// 
	KMOVB,			// 
	KMOVQ,			// 
	KMOVD,			// 
	*/

	VLDDQU,			// Load unaligned packed integer values from mem to (y/x)mm1.
	VLDMXCSR,		//  Load MXCSR register from m32.
	LOADIWKEY,		//  Load internal wrapping key from xmm1, xmm2, and XMM0.
	VMASKMOVDQU,	// Selectively write bytes from xmm1 to memory location using the byte mask in xmm2. The default memory location is specified by DS:DI/EDI/RDI.
	VMAXPD,			// 
	VMAXPS,			//
	VMAXSD,			// Return the maximum scalar double-precision floating-point value between xmm3/m64 and xmm2.
	VMAXSS,			// Return the maximum scalar single-precision floating-point value between xmm3/m32 and xmm2.
	VMINPD,			// 
	VMINPS,			//
	VMINSD,			// Return the minimum scalar double-precision floatingpoint value between xmm3/m64 and xmm2.
	VMINSS,			//  Return the minimum scalar single-precision floatingpoint value between xmm3/m32 and xmm2.
	VMOVAPD,		// 
	VMOVAPS,		//
	VMOVD,			//
	VMOVQ,			// 
	VMOVDDUP,		// 
	MOVDIRI,		// Move doubleword from (r32 to m32 / r64 to m64) using direct store.
	MOVDIR64B,		// Move 64-bytes as direct-store with guaranteed 64-byte write atomicity from the source memory operand
					//		address to destination memory address specified as offset to ES segment in the register operand.
	VMOVDQU,		// 
	VMOVHPD,		//
	VMOVHPS,		//
	VMOVLHPS,		// Merge two packed single-precision floating-point values from low quadword of xmm3 and low quadword of xmm2.
	VMOVLPD,		// 
	VMOVLPS,		//
	VMOVMSKPD,		// Extract (2/4)-bit sign mask from (x/y)mm2 and store in reg. The upper bits of r32 or r64 are zeroed.
	VMOVMSKPS,		// Extract (4/8)-bit sign mask from (x/y)mm2 and store in reg. The upper bits of r32 or r64 are zeroed.
	VMOVNTDQA,		// 
	VMOVNTDQ,		// 
	VMOVNTPD,		//
	VMOVNTPS,		// 
	VMOVSD,			// 
	VMOVSHDUP,		// 
	VMOVSLDUP,		// 
	VMOVSS,			// 
	MOVSXD,			//
	VMOVUPD,		// 
	VMOVUPS,		// 
	VMPSADBW,		// 
	VMULPD,			//
	VMULPS,			// 
	VMULSD,			//
	VMULSS,			// Multiply the low single-precision floating-point value in xmm3/m32 by the low single-precision floating-point value in xmm2.
	VORPD,			//
	VORPS,			//
	VPABSB,			// Compute the absolute value of bytes in (x/y)mm2/m(128/256) and store UNSIGNED result in (x/y)mm1.
	VPABSW,			// 
	VPABSD,			//
	VPACKSSWB,		//
	VPACKSSDW,		//
	VPACKUSDW,		//
	VPACKUSWB,		//
	VPADDB,			//
	VPADDW,			//
	VPADDD,			//
	VPADDQ,			//
	VPADDSB,		//
	VPADDSW,		//
	VPALIGNR,		//
	VPAND,			//
	VPANDD,			//
	VPANDQ,			//
	VPANDN,			//
	VPANDND,		//
	VPANDNQ,		//
	VPAVGB,			//
	VPAVGW,			//
	VPCLMULQDQ,		//
	VPCMPEQB,		//
	VPCMPEQW,		//
	VPCMPEQD,		//
	VPCMPEQQ,		//
	VPCMPESTRI,		// Perform a packed comparison of string data with explicit lengths, generating an index, and storing the result in ECX.
	VPCMPESTRM,		//
	VPCMPGTB,		//
	VPCMPGTW,		//
	VPCMPGTD,		//
	VPCMPGTQ,		//
	VPCMPISTRI,		//
	VPCMPISTRM,		//
	PCONFIG,		// This instruction is used to execute functions for configuring platform features.
	PDEP,			// Parallel deposit of bits from r(32/64)b using mask in r/m(32/64), result is written to r(32/64)a.
	VPEXTRB,		// Extract a byte integer value from xmm2 at the source byte offset specified by imm8 into reg or m8. The upper bits of r64/r32 is filled with zeros.
	VPEXTRD,		// Extract a dword integer value from xmm2 at the source dword offset specified by imm8 into r32/m32.
	VPEXTRQ,		//  Extract a qword integer value from xmm2 at the source dword offset specified by imm8 into r64/m64.
	VPEXTRW,		// 
	VPHADDW,		// Add 16-bit integers horizontally, pack to (x/y)mm1.
	VPHADDD,		// Add 32-bit integers horizontally, pack to (x/y)mm1.
	VPHADDSW,		//  Add 16-bit signed integers horizontally, pack saturated integers to (x/y)mm1.
	VPHSUBW,		// 
	VPHSUBD,		// 
	VPINSRB,		//
	VPINSRD,		//
	VPINSRQ,		//
	VPINSRW,		//  Insert the word from r32/m16 at the offset indicated by imm8 into the value from xmm2 and store result in xmm1.
	VPMADDUBSW,		//
	VPMADDWD,		//
	VPMAXSB,		//
	VPMAXSW,		//
	VPMAXSD,		//
	VPMAXUB,		//
	VPMAXUW,		//
	VPMINSB,		//
	VPMINSW,		//
	VPMINSD,		//
	VPMINUB,		//
	VPMINUW,		//
	VPMOVMSKB,		//
	VPMOVZXBW,		// 
	VPMOVZXBD,		//
	VPMOVZXBQ,		//
	VPMOVZXWD,		//
	VPMOVZXWQ,		//
	VPMOVZXDQ,		//
	VPMULDQ,		//
	VPMULHRSW,		//
	VPMULHUW,		//
	VPMULHW,		//
	VPMULLD,		//
	VPMULLW,		//
	VPMULUDQ,		//
	VPSADBW,		//
	VPSHUFB,		//
	VPSHUFD,		//
	VPSHUFHW,		//
	VPSHUFLW,		//
	VPSLLDQ,		//
	VPSLLW,			//
	VPSLLD,			//
	VPSLLQ,			//
	VPSRAW,			//
	VPSRAD,			//
	VPSRLDQ,		//
	VPSRLW,			//
	VPSRLQ,			//
	VPSRLD,			//
	VPSUBB,			//
	VPSUBW,			//
	VPSUBD,			//
	VPSUBQ,			//
	VPSUBSB,		//
	VPSUBSW,		//
	VPSUBUSB,		//
	VPSUBUSW,		//
	PTWRITE,		//
	VRCPPS,			//
	RDPID,			//
	RDPKRU,			//
	RDSSPD,			//
	RDSSPQ,			//
	VROUNDPS,		//
	VROUNDSD,		//
	VROUNDSS,		//
	VRSQRTPS,		// Computes the approximate reciprocals of the square roots of packed single-precision values in xmm2/mem and stores the results in xmm1.
	SERIALIZE,		//  Serialize instruction fetch and execution.
	VSHUFPD,		//
	VSHUFPS,		//
	VSQRTPS,		//
	VSQRTSD,		//
	VSQRTSS,		//
	VSTMXCSR,		//
	VSUBPD,			//
	VSUBPS,			//
	VSUBSD,			//
	VSUBSS,			//
	VUNPCKHPD,		//
	VUNPCKHPS,		//
	VUNPCKLPD,		//
	VUNPCKLPS,		//
	VBROADCASTF32X2,	//
	VBROADCASTF32X4,	//
	VBROADCASTF64X2,	//
	VBROADCASTF32X8,	//
	VBROADCASTF64X4,	//
	VCVTNE2PS2BF16,		//
	VCVTNEPS2BF16,		//
	VCVTTPD2UDQ,	//
	VCVTTPD2UQQ,	//
	VCVTTPS2UDQ,	//
	VCVTTPS2QQ,		//
	VCVTTPS2UQQ,	//
	VCVTTSD2USI,	//
	VCVTTSS2USI,	//
	VCVTUSI2SD,		//
	VCVTUSI2SS,		//
	VDPBF16PS,		//
	VEXTRACTF32X8,	//
	VEXTRACTI128,	//
	VEXTRACTI32X8,	//
	VINSERTF32X8,	//
	VINSERTI128,	//
	VINSERTI32X4,	//
	VINSERTI32X8,	//
	VINSERTI64X4,	//
	VP2INTERSECTD,	//
	VP2INTERSECTQ,	//
	VPBLENDD,		// Select dwords from (x/y)mm2 and (x/y)mm3/m(128/256) from mask specified in imm8 and store the values into (x/y)mm1.
	VBROADCASTI32x2,	//
	VBROADCASTI128,		//
	VBROADCASTI32X4,	//
	VBROADCASTI64X2,	//
	VBROADCASTI32X8,	//
	VBROADCASTI64X4,	//
	VPBROADCASTMB2Q,	//
	VPBROADCASTMW2D,	//
	VPCMPUB,		//
	VPCMPUD,		//
	VPCMPUQ,		//
	VPCMPUW,		//
	VPCOMPRESSB,	//
	VPCOMPRESSW,	//
	VPDPWSSDS,		//
	VPERM2I128,		// Permute 128-bit integer data in ymm2 and ymm3/mem using controls from imm8 and store result in ymm1.
	VPERMB,			//
	VPERMT2B,		//
	VPERMT2W,		//
	VPEXPANDB,		//
	VPEXPANDW,		//
	VPGATHERDD,		//
	VPGATHERQD,		//
	VPGATHERDQ,		//
	VPGATHERQQ,		//
	VPMADD52HUQ,	//
	VPMADD52LUQ,	//
	VPMASKMOVD,		//
	VPMASKMOVQ,		//
	VPMOVD2M,		//
	VPMOVDB,		//
	VPMOVDW,		//
	VPMOVQB,		//
	VPMOVQD,		//
	VPMOVQW,		//
	VPMOVWB,		//
	VPMULTISHIFTQB,	//
	VPOPCNTB,		//
	VPOPCNTW,		//
	VPOPCNTD,		//
	VPOPCNTQ,		//
	VPRORVD,		//
	VPRORVQ,		//
	VPSHLDW,		//
	VPSHLDD,		//
	VPSHLDQ,		//
	VPSHLDVW,		//
	VPSHLDVD,		//
	VPSHLDVQ,		//
	VPSHRDW,		//
	VPSHRDD,		//
	VPSHRDQ,		//
	VPSHRDVW,		//
	VPSHRDVD,		//
	VPSHRDVQ,		//
	VPSHUFBITQMB,	//
	VPTERNLOGD,		//
	VPTERNLOGQ,		//
	VSCALEFPD,		//
	VSCALEFSD,		//
	VSCALEFPS,		//
	VSCALEFSS,		//
	VSCATTERDPS,	//
	VSCATTERDPD,	//
	VSCATTERQPS,	//
	VSCATTERQPD,	//
	VSHUFF64X2,		//
	VSHUFI64X2,		//
	WBNOINVD,		//
	WRPKRU,			//
	WRSSD,			//
	WRSSQ,			//
	VXORPD,			//
	VXORPS,			//
	XRSTORS64,		//
	XSAVE64,		// Save state components specified by EDX:EAX to mem.
	XSAVEC64,		//
	XSAVES64,		//

	SHL, //
	SHR, //
	SAR, //
	SHRD, //

	PREFETCHTNTA,
	PREFETCHT0,
	PREFETCHT1,
	PREFETCHT2,

	UMONITOR,

	SAVEC,
	SAVES,

} mnemonic_t;

#define NM_GENERAL_PURPOSE_MAX TZCNT
#define NM_X87_FPU_MAX FNOP
#define NM_MMX_MAX EMMS
#define NM_SSE_MAX SFENCE
#define NM_SSE2_MAX MOVNTI
#define NM_SSE3_MAX PALIGNR
#define NM_SSE4_MAX PCMPGTQ
#define NM_AES_NI_MAX PCLMULQDQ
#define NM_AVX_MAX VZEROUPPER
#define NM_16BIT_FLCONV_MAX VCVTPS2PH
#define NM_FMA_MAX VFNMSUB231SS
#define NM_AVX2_MAX VGATHERQQ
#define NM_TSX_MAX XTEST
#define NM_SHA_MAX SHA256RNDS2
#define NM_AVX512_MAX VSCATTERPF1QPS
#define NM_SYSTEM_MAX WRGSBASE
#define NM_64BIT_MODE_MAX SYSRET
#define NM_VM_MAX VMFUNC
#define NM_SAFER_MODE_MAX GETSEC_WAKEUP
#define NM_MEM_PROT_MAX BNDSTX
#define NM_SOFT_GUARDS_MAX ENCLS_ERESUME
#define NM_SHADOW_STACK_MAX WRUSS
#define NM_CTT_MAX ENDBR64

#define MN_ISGENERAL_PURPOSE(x) ((x) <= NM_GENERAL_PURPOSE_MAX)
#define MN_ISX87_FPU(x) ((x) <= NM_X87_FPU_MAX && (x) > NM_GENERAL_PURPOSE_MAX)
#define MN_ISMMX(x) ((x) <= NM_MMX_MAX && (x) > NM_X87_FPU_MAX)
#define MN_ISSSE(x) ((x) <= NM_SSE_MAX && (x) > NM_MMX_MAX)
#define MN_ISSSE2(x) ((x) <= NM_SSE2_MAX && (x) > NM_SSE_MAX)
#define MN_ISSSE3(x) ((x) <= NM_SSE3_MAX && (x) > NM_SSE2_MAX)
#define MN_ISSSE4(x) ((x) <= NM_SSE4_MAX && (x) > NM_SSE3_MAX)
#define NM_ISAES_NI(x) ((x) <= NM_AES_NI_MAX && (x) > NM_SSE4_MAX)
#define NM_ISAVX(x) ((x) <= NM_AVX_MAX && (x) > NM_AES_NI_MAX)
#define NM_IS16BIT_FLCONV(x) ((x) <= NM_16BIT_FLCONV_MAX && (x) > NM_AVX_MAX)
#define NM_ISFMA(x) ((x) <= NM_FMA_MAX && (x) > NM_16BIT_FLCONV_MAX)
#define NM_ISAVX2(x) ((x) <= NM_AVX2_MAX && (x) > NM_FMA_MAX)
#define NM_ISTSX(x) ((x) <= NM_TSX_MAX && (x) > NM_AVX2_MAX)
#define NM_ISSHA(x) ((x) <= NM_SHA_MAX && (x) > NM_TSX_MAX)
#define NM_AVX512(x) ((x) <= NM_AVX512_MAX && (x) > NM_SHA_MAX)
#define NM_ISSYSTEM(x) ((x) <= NM_SYSTEM_MAX && (x) > NM_AVX512_MAX)
#define NM_IS64BIT_MODE(x) ((x) <= NM_64BIT_MODE_MAX && (x) > NM_SYSTEM_MAX)
#define NM_ISVM(x) ((x) <= NM_VM_MAX && (x) > NM_64BIT_MODE_MAX)
#define NM_ISSAFER_MODE(x) ((x) <= NM_SAFER_MODE_MAX && (x) > NM_VM_MAX)
#define NM_ISMEM_PROT(x) ((x) <= NM_MEM_PROT_MAX && (x) > NM_SAFER_MODE_MAX)
#define NM_ISSOFT_GUARDS(x) ((x) <= NM_SOFT_GUARDS_MAX && (x) > NM_MEM_PROT_MAX)
#define NM_ISSHADOW_STACK(x) ((x) <= NM_SHADOW_STACK_MAX && (x) > NM_SOFT_GUARDS_MAX)
#define NM_CTT(x) ((x) <= NM_CTT_MAX && (x) > NM_SHADOW_STACK_MAX)
