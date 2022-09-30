# AVL Tokenizer/Disassembler/Assembler

X86-64 bilateral instruction tokenizer implemented in C. Supports the following processor extensions: `AES`, `AVX`, `AVX2`, `AVX512`, `FMA`, `MMX`, `SSE`, `SSE2`, `SSE3`, `SSE4`, `x87(FPU)`, `VMX`. In order to ease testing, a diassembler which transforms tokens into compilable assembly (for NASM compiler) has been implemented. 

---

## *Index*
### [*I) Usage*](##Usage.link)
#### &emsp; [*- I.I) Install*](##Usage.Install.link)
#### &emsp; [*- I.II) Run*](##Usage.Run.link)
### [*II) Documentation*](##Documentation.link)
#### &emsp; [*- II.I) Overview*](##Documentation.Overview.link)
#### &emsp; [*- II.II) Token*](##Documentation.Token.link)
#### &emsp; &emsp; [*- II.II.I) Flags*](##Documentation.Token.Flags.link)
#### &emsp; &emsp; [*- II.II.II) Opcode*](##Documentation.Token.Opcode.link)
#### &emsp; &emsp; [*- II.II.III) VEX/EVEX*](##Documentation.Token.VEXEVEX.link)
#### &emsp; &emsp; [*- II.II.IV) Operands*](##Documentation.Token.Operands.link)
#### &emsp; [*- II.III) Library*](##Documentation.Library.link)
#### &emsp; [*- II.IV) Miscellaneous*](##Documentation.Miscellaneous.link)
### [*III) Disassembler*](##Disassembler.link)
### [*IV) Testing*](##Testing.link)

---

## <a name="#Usage.link">I) Usage</a>
### <a name="#Usage.Install.link">I.I) Install</a>

### <a name="#Usage.Run.link">I.II) Run</a>

## <a name="#Documentation.link">II) Documentation</a>
### <a name="#Documentation.Overview.link">II.I) Overview</a>

The library perform bilateral conversion (machine code <=> tokens) between x64-86 machine code instructions and tokens (`AVL_instruction_t` (see [token](##Documentation.Token.link))).

### <a name="#Documentation.Token.link">II.II) Token</a>

The token (`AVL_instruction_t`) contains all the avalavaile information of the x86-64 processor instruction that represents, in 32-bytes of data.

The `AVL_instruction_t` prototype is:
```c
typedef struct
{
    uint32_t        i_flags;
    AVL_mnemonic_t  i_mnemonic;
    uint8_t         i_opcode[3];
    uint8_t         i_vp[3];
    uint8_t         i_mod_rm;
    uint8_t         i_sib;
    uint32_t        i_disp;
    uint8_t         i_size;
    AVL_reg_t       i_reg1;
    AVL_reg_t       i_reg2;
    AVL_reg_t       i_reg3;
    uint64_t        i_imm;
} AVL_instruction_t;
```

- The field `i_flags` has its own subsection [here](##Documentation.Token.Flags.link).

- The field `i_mnemonic` is an enum in which each value represents an unique mnemonic (e.g. `MOV`, `VPCMUB`, `VPTERNLOGQ`, ...). The value of `0` is reserved, a `i_mnemonic` with a value `== 0` represents an invalid instruction. The enum `AVL_mnemonic_t` can be found at the root of the tokenizer on the file `includes/user/AVL_mnemonic.h`. 

- The field `i_opcode` holds the map and the index used. It has its own subsection [here](##Documentation.Token.Opcode.link).

- The field `i_vp` contains the raw data of the `VEX` prefixes (2 or 3 bytes) or the 3 last bytes of the `EVEX` prefix. It has its own subsection [here](##Documentation.Token.VEXEVEX.link).

- The field `i_mod_rm` contains the raw data of the `ModR/M` byte of the instruction.

- The field `i_sib` contains the raw data of the `SIB` byte of the instruction. Addressing is not resolved by the tokenizer (see [operands](##Documentation.Token.Operands.link)), however you can easily resolve addressing using the `ModR/M`, the `SIB` and the `displacement`. A complete exemple is provided in the code source of the [disassembler](##Disassembler.link). The use of the `SIB` byte is defined by the `ModR/M`.

- The field `i_disp` contains the raw data of the `displacement` used in addressing (e.g. `mov rax, [rdi + 0x69420]`). The displacement size can be either 8 or 32 bits, it's defined by the `ModR/M` or the `SIB` byte.

- The field `i_size` holds the size of the instruction (prefixes, opcode, suffixes plus immediate data). The size of a x86 instruction is from 1 to 16 bytes.

- The fields `i_reg1`, `i_reg2`, `i_reg3` represent the [operands](##Documentation.Token.Operands.link) used by the instruction. An operand can be either a register or memory. Further information such as the state of the instruction (readonly, read&write or writeonly) durring the instruction excution can he found [here](##Documentation.Token.Flags.link).

- The field `i_imm` contains the raw `immediate data` of the instruction. Some instructions **encode** an aditional operand like the (`ModR/M.rm`, `ModR/M.reg`, ...) in the first 4-bits of the `immediate data` (e.g. `VBLENDVPS`).

### <a name="#Documentation.Token.Flags.link">II.II.I) Flags</a>

The flags (`AVL_instruction_t.i_flags`) encode several information about the instruction such as `prefixes`, `suffixes (immediate data`), `operand size`, `operand modifiers` and `CPU flags`.

| BYTES/BITS   | 0b001 | 0b010 | 0b011 | 0b100 | 0b101 | 0b110 | 0b111 | 0b1000|
|--------------|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|:-----:|
| 1            |lp_lock|lp_rpx |lp_rpnx|lp_fs  |lp_gs  |lp_nbr |lp_br  |lp_opsz|
| 2            |lp_adsz|REX.B  |REX.X  |REX.R  |REX.W  |has_imm|is_evex|is_mdrm|
| 3            |om1_r  |om1_w  |om2_r  |om2_w  |om3_r  |om3_w  |fl_car | fl_par|
| 4            |fl_adj |fl_zero|fl_sign|fl_ovfw|OP_SZ  |OP_SZ  |OP_SZ  |reserved|

- `lp_lock`: The instruction has the `LOCK` legacy prefix (execute certain read-modify-write instructions atomically).\
  The `AVL_HAS_LP_LOCK_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_rpx`: Either the instruction has the `REPNE/Z` legacy prefix (repeat string handling) or the `0xF2` prefix for indexing within opcodes tables is used.\
  The `AVL_HAS_LP_REPNX_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_prnx`: Either the instruction has the `REPE/Z` legacy prefix (repeat string handling) or the `0xF3` prefix for indexing within opcode tables is used.\
  The `AVL_HAS_LP_REPX_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_fs`: The instruction has the `FS segment overwrite` legacy prefix (use the FS segment instead of the stack while addressing).\
 The `AVL_HAS_LP_FS_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_gs`: The intruction has the `GS segment overwrite` legacy prefix (use the GS segment instead of the stack while addressing).\
 The `AVL_HAS_LP_GS_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_nbr`: The instruction has the `branch not taken` legacy prefix (which is used to lessen the impact of branch misprediction (>= Pentium 4)). Weak hint.\
  The `AVL_HAS_LP_NOBRANCH_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_br`: The instruction has the `branch taken` legacy prefix (which is used to lessen the impact of branch misprediction (>= Pentium 4)). Strong hint.\
  The `AVL_HAS_LP_BRANCH_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_opsz`: Either the instruction has its operand size overwriten or the `0x66` prefix for indexing within opcode tables is used.\
  The `AVL_HAS_LP_OPSZ_PFX(flags)` macro enables to retrieve its value conditionally.
- `lp_adsz`: The instruction overwrites addressing size to 32-bits.\
  The `AVL_HAS_LP_ADDRSZ_PFX(flags)` macro enables to retrieve its value conditionally.
- `REX.B`: The instruction has the `REX` prefix with the bit `B`. The value is used as extension for the `ModR/M.rm` or the `SIB.base` field.\
  The `AVL_HAS_REXB_PFX(flags)` macro enables to retrieve its value conditionally.
- `REX.X`: The instruction has the `REX` prefix with the bit `X`. The value is used as extension for the `SIB.index` field.\
  The `AVL_HAS_REXX_PFX(flags)` macro enables to retrieve its value conditionally.
- `REX.R`: The instruction has the `REX` prefix with the bit `R`. The vale is used as extension of the `ModR/M.reg` field.\
  The `AVL_HAS_REXR_PFX(flags)` macro enables to retrieve its value conditionally.
- `REX.W`: The instruction has the `REX` prefix with the bit `W`. Overwrites the operand size.\
  The `AVL_HAS_REXW_PFX(flags)` macro enables to retrieve its value conditionally.
- `has_imm`: The instruction has an `immediate value` on the field `AVL_instruction_t.i_imm`.\
  The `AVL_HAS_OP_IMM_PFX(flags)` macro enables to retrieve its value conditionally.
- `has_evex`: The instruction has the `EVEX` prefix. The `AVL_instruction_t.i_vp` field holds the 3 last bytes of the `EVEX` prefix.\
  The `AVL_HAS_OP_EVEX_PFX(flags)` macro enables to retrieve its value conditionally.
- `is_mdrm`: The instruction has a `ModR/M` byte prefix. The `AVL_instruction_t.i_mod_rm` holds its value.\
  The `AVL_HAS_OP_MODRM_PFX(flags)` macro enables to retrieve its value conditionally.
- `om1_r`: The instruction, while execution, reads the operand held by `AVL_instruction_t.i_reg1`.\
 The `AVL_OM1_IS_READ(flags)` macro enables to retrieve its value conditionally.
- `om1_w`: The instruction, while execution, might modify the operand held by `AVL_instruction_t.i_reg1`.\
 The `AVL_OM1_IS_WRITE(flags)` macro enables to retrieve its value conditionally.
- `om2_r`: The instruction, while execution, reads the operand held by `AVL_instruction_t.i_reg2`.\
 The `AVL_OM2_IS_READ(flags)` macro enables to retrieve its value conditionally.
- `om2_w`: The instruction, while execution, might modify the operand held by `AVL_instruction_t.i_reg2`.\
 The `AVL_OM2_IS_WRITE(flags)` macro enables to retrieve its value conditionally.
- `om3_r`: The instruction, while execution, reads the operand held by `AVL_instruction_t.i_reg3`.\
 The `AVL_OM3_IS_READ(flags)` macro enables to retrieve its value conditionally.
- `om3_w`: The instruction, while execution, might modify the operand held by `AVL_instruction_t.i_reg3`.\
 The `AVL_OM3_IS_WRITE(flags)` macro enables to retrieve its value conditionally.
- `fl_car`: The instruction, on execution, might modify the `carry flag` status.\
  The `AVL_HAS_AF_CARRY(flags)` macro enables to retrieve its value conditionally.
- `fl_par`: The instruction, on execution, might modify the `parity flag` status.\
  The `AVL_HAS_AF_PARITY(flags)` macro enables to retrieve its value conditionally.
- `fl_adj`: The instruction, on execution, might modify the `adjust flag` status.\
  The `AVL_HAS_AF_ADJUST(flags)` macro enables to retrieve its value conditionally.
- `fl_zero`: The instruction, on execution, might modify the `zero flags` status.\
  The `AVL_HAS_AF_ZERO(flags)` macro enables to retrieve its value conditionally.
- `fl_sign`: The instruction, on execution, might modify the `sign flags` status.\
  The `AVL_HAS_AF_SIGN(flags)` macro enables to retrieve its value conditionally.
- `fl_ovfw`: The instruction, on execution, might modify the `overflow flags` status.\
  The `AVL_HAS_AF_OVERFLOW(flags)` macro enables to retrieve its value conditionally.
- `OP_SZ`: Unlike previous flags, these are not 1-bit flags. The `operand size` is encoded in 3-bits. The operand size can be either: `AVL_OPSZ_BYTE` (1-byte), `AVL_OPSZ_WORD` (2-bytes), `AVL_OPSZ_DWORD` (4-bytes), `AVL_OPSZ_QWORD` (8-bytes), `AVL_OPSZ_DQWORD` (16-bytes), `AVL_OPSZ_QQWORD` (32-bytes) or `AVL_OPSZ_DQQWORD` (64-bytes).\
  The `AVL_GET_OPERAND_SZ(flags)` macro enables to retrieve the operand size.\
  Futhermore, the following macros enable type check conditionally the value of the operand size: `AVL_OPSZ_IS_BYTE(flags)`, `AVL_OPSZ_IS_WORD(flags)`, `AVL_OPSZ_IS_DWORD(flags)`, `AVL_OPSZ_IS_QWORD(flags)`, `AVL_OPSZ_IS_DQWORD(flags)`, `AVL_OPSZ_IS_QQWORD(flags)`, `AVL_OPSZ_IS_DQQWORD(flags)`.

### <a name="#Documentation.Token.Opcode.link">II.II.II) Opcode</a>

The opcode (`ALV_instruction_t.i_opcode`) is composed of 3 bytes of data. The first 2 bytes holds the opcode map index and the index within the map is held by the last one.\

The 2 first byte can be either:
- `[0x00][0x00]` for unprefixed opcode map.
- `[0x0F][0x00]` for two byte opcode map.
- `[0x0F][0x38]` for three byte 0x38 opcode map.
- `[0x0F][0x3A]` for three byte 0x3A opcode map.

If the map is unprefixed and its index within is in range of `0xD8 >= INDEX <= 0xDF`, the instructions are escaped to `x87 opcode maps`.

### <a name="#Documentation.Token.VEXEVEX.link">II.II.III) VEX/EVEX</a>

If the instruction has a `VEX` prefix, its raw data can found on `AVL_instruction_t.i_vp` (3-bytes) field.\
If the instruction has an `EVEX` prefix, the raw data of its 3 last bytes can be also found on `AVL_instruction_t.i_vp` field.

Furthermore, to easily access to `VEX`/`EVEX` elements some types has been implemented.
The `i_vp` field is polyphormic, it can be casted either in `AVL_vex_t`, `AVL_vex2_t` or `AVL_evex_t` depenting of the nature of the instruction. I recomend to use this sequence to determine which one use:
```c
#include <AVL_disassembler.h>

AVL_instruction* inst;

/* ... */

if (AVL_OP_EVEX_MASK(inst->i_flags))
  // has EVEX prefix
else if (AVL_ISVEX3_PFX(inst))
  // has VEX 3 bytes prefix
else if (AVL_ISVEX2_PFX(inst))
  // has VEX 2 bytes prefix
```

The prototypes of the `VEX/EVEX` prexixes types:
```c
/// Vector EXtension (VEX) 3-bytes prefix.
typedef struct
{
	union
	{
		struct
		{
			uint8_t	vx_header;		// Mandatory VEX 3-bytes prefix, always 0xC4.
			uint8_t	vx_opmap:5;		// Opcode Map Prefix(es).
			uint8_t vx_rexb:1;		// VEX REX.B bit.
			uint8_t vx_rexx:1;		// VEX REX.X bit.
			uint8_t vx_rexr:1;		// VEX REX.R bit.
			uint8_t vx_prefix:2;    // Instruction prefix.
			uint8_t vx_vlen:1;		// Vector Operand Size, either 128-bits or 256-bits.
			uint8_t vx_vvvv:4;		// Addtional Instruction Argument.
			uint8_t vx_rexw:1;		// VEX REX.W bit.
		};
		uint8_t v_rawdat[3];
	};
} AVL_vex_t;

/// Vextor EXtension (VEX) 2-bytes prefix.
typedef struct
{
	union
	{
		struct
		{
			uint8_t	vx2_header;		// Mandatory VEX 2-bytes prefix, always 0xC5.
			uint8_t	vx2_prefix:2;   // Instruction prefix.
			uint8_t	vx2_vlen:1;		// Vector Operand Size, either 128-bits or 256-bits.
			uint8_t	vx2_vvvv:4;		// Addtional Instruction Argument.
			uint8_t	vx2_rexr:1;		// VEX REX.R bit.
		};
		uint8_t vx2_rawdat[3];
	};
} AVL_vex2_t;

/// Enhanced Vector EXtension (EVEX) prefix.
typedef struct
{
	union
	{
		struct
		{
			uint8_t	evx_opmap:2;    // Opcode Map Prefix(es).
			uint8_t __evx_ZeRo:2;   // Reserved, always 0b00.
			uint8_t	evx_rexr2:1;    // Extends EVEX REX.X extensions.
			uint8_t	evx_rexb:1;     // EVEX REX.B bit.
			uint8_t	evx_rexx:1;     // EVEX REX.X bit.
			uint8_t	evx_rexr:1;     // EVEX REX.R bit.
			uint8_t	evx_prefix:2;   // Instruction prefix.
			uint8_t	__evx_ZeRo:1;   // Reserved, always 0b1.
			uint8_t	evx_vvvv:4;     // Addtional Instruction Argument.
			uint8_t	evx_rexw:1;     // EVEX REX.W bit.
			uint8_t	evx_mask:3;     // Operand Mask Register.
			uint8_t	evx_v:1;        // Expands EVEX.VVVV.
			uint8_t	evx_brcst:1;    // Source Broadcast, Rounding Control or Supress Exceptions.
			uint8_t	evx_vlen:1;     // If == 1, operand size is 256-bits, else 128-bits.
			uint8_t	evx_vlen2:1;    // If == 1, operand size is 512-bits (overwrite EVEX.L (evx_vlen)).
			uint8_t	evx_zero:1;     // Specify merging mode (merge or zero).
		};
		uint8_t evx_rawdat[3];
	};
} AVL_evex_t;

```

### <a name="#Documentation.Token.Operands.link">II.II.IV) Operands</a>

The operands are represented by the 3 fields `i_reg[X]` of the `AVL_intruction_t` type.
An operand can be either a register or memory.
This is a brief of the avalaible operands, the full list can be found on `includes/user/AVL_register.h`:
- Memory: `AVL_OP_MEM8` to `AVL_OP_MEM512`.
- General Purpose Registers: `AVL_OP_AL` to `AVL_OP_R15`.
- Segment Registers: `AVL_OP_ES` to `AVL_OP_GS`.
- Control Registers: `AVL_OP_CR0` to `AVL_OP_CR15`.
- Debug Registers: `AVL_OP_DR0` to `AVL_OP_DR15`.
- Stack (FPU) "Registers": `AVL_OP_STO` to `AVL_OP_ST7`.
- MMX Registers: `AVL_OP_MMX0` to `AVL_OP_MMX0`.
- XMM Registers: `AVL_OP_XMM0` to `AVL_OP_XMM31`.
- YMM Registers: `AVL_OP_YMM0` to `AVL_OP_YMM31`.
- ZMM Registers: `AVL_OP_ZMM0` to `AVL_OP_ZMM31`.
- K Registers: `AVL_OP_K0` to `AVL_OP_K7`.

Also, information about the state of each operand on excution is avalaible through the macros:
- `AVL_OM[X]_IS_READ`: On excution, the operand `i_reg[X]` is read.
- `AVL_OM[X]_IS_WRITE`: On excution, the operand `i_reg[X]` is written,

### <a name="#Documentation.Library.link">II.III) Library</a>

Some utils has been in implemented in order enable to "play with the instructions":

```c
void AVL_disassemble_instructions(AVL_instruction_t* dest, uint64_t destlen, const uint8_t** text);
```
Tokenizes into `dest` an amount of `destlen` instructions from a pointer to x86-64 machine code address (`*text`). Note that the address pointed by `text` is, each call, incremented by pointing to the begining of the next instruction.


```c
void				AVL_assemble_instructions(uint8_t* dest, AVL_instruction_t src[], uint64_t amount);
```
Convert `amount` of tokens (`src`) into x86-64 machine code, the result is written into `dest` address.

```c
uint64_t			AVL_inst_iszeroed(AVL_instruction_t* const target);
```
Performs a zeroed check to the token pointed by `target`. If all the pointed data is equal to 0, return non zero.

```c
uint64_t			AVL_inst_getlen(AVL_instruction_t insts[], uint64_t limit);
```
Return the lenght of the firts sequence of non zeroed tokens in `insts` with an upper bound of `limit` iterations.

```c
AVL_instruction_t* AVL_inst_find(AVL_instruction_t insts[], AVL_mnemonic_t key, uint64_t insts_len);
```
Search for a `key` matching with the mnemonic of the tokens within array `insts` with an upper bound of `insts_len` tokens.

```c
typedef uint64_t (*const AVL_condition_t)(AVL_instruction_t* const);

AVL_instruction_t* AVL_inst_findif(AVL_instruction_t insts[], uint64_t insts_len, AVL_condition_t cond);
```
Search for a matching condition `cond` within the `insts` with an upper bound of `insts_len` tokens.

```c
void				AVL_inst_insert(AVL_instruction_t* const dest, uint64_t destlen, AVL_instruction_t* const src, uint64_t srclen);
```
Insert `srclen` tokens `src` after `dest` address which is followed by at least `destlen` tokens.

```c
void				AVL_inst_erase(AVL_instruction_t* const target, uint64_t amount, uint64_t targetlen);
```
Erase `amount` of tokens at `target` address which is followed by at least `targetlen` tokens.

```c
void				AVL_inst_swap(AVL_instruction_t* const l, AVL_instruction_t* const r);
```
Swap the data between `l` and `r`.

### <a name="#Documentation.Miscellaneous.link">II.IV) Miscellaneous</a>

- The `AVL_HAS_OP_VEX_PFX(inst)` macro enables to conditionally check if the instruction has a `VEX` prefix. Note: this macro should be always preceded of `AVL_HAS_OP_EVEX_PFX(flags)` check, since both `EVEX` and `VEX` fill the `i_vp` field, this macro return true in both cases.\
Another solution could be the `(AVL_ISVEX2_PFX(inst) || AVL_ISVEX3_PFX(inst)) != 0` expression which is not true when the instruction has an `EVEX` prefix.

- The macros `AVL_ISVEX2_PFX(inst)` and `AVL_ISVEX3_PFX(inst)`, respectively, conditionally check if the instruction has a 2 or 3 bytes `VEX` prefix.

- The `AVL_GET_EVEX_VVVV(evex)` macro enables to get the extended value of the  `EVEX.VVVV` field.

- The `AVL_GET_MODRM_MOD(modrm)` macro enables to get the value of the `ModR/M.mod` field.

- The `AVL_GET_MODRM_RM(inst)` macro enables to get the extended value of the `ModR/M.rm` field.

- The `AVL_GET_MODRM_REG(inst)` macro enables to get the extended value of the `ModR/M.reg` field.

- The `AVL_GET_SIB_SCALE(sib)` macro enables to get the value of the `SIB.scale` field.

- The `AVL_GET_SIB_BASE(inst)` macro enables to get the extended value of the `SIB.base` field.

- The `AVL_GET_SIB_INDEX(inst)` macro enables to get the extended value of the `SIB.index` field.

Some instructions such as `Jcc`, `JMP`, `CALL` and `RET` modify the `rip` pointer with diferent bounds which are specified by their spetializations, this macros enable to identify these bounds:
- `AVL_IS_JCC_SHORT(inst)`: Is `short` conditional jump.
- `AVL_IS_JCC_LONG(inst)`: Is `long` conditional jump.
- `AVL_IS_JMP_SHORT(inst)`: Is `short` jump.
- `AVL_IS_JMP_NEAR(inst)`: Is `near` jump.
- `AVL_IS_JMP_FAR(inst)`: Is `far` jump.
- `AVL_IS_CALL_NEAR(inst)`: Is `near` call.
- `AVL_IS_CALL_FAR(inst)`: Is `far` call.
- `AVL_IS_RET_NEAR(inst)`: Is `near` return.
- `AVL_IS_RET_FAR(inst)`: Is `far` return.

---

## <a name="#Disassembler.link">III) Disassembler</a>

In order to perform tests, a function for disassemble tokens in `NASM` syntax has been implemented. With "`NASM` syntax" i mean that every instruction can be displayed in compilable assembly code. It might be an exemple about how to use the tokens, the file is: `srcs/tests/fprint_instruction.c`. The prototype of the disassembler is:
```c
// file: includes/dev/tests.h
void    fprint_instruction(FILE* where, AVL_instruction_t* const target);
```
The current main takes a file as argument (the file must be filled with x64-86 machine code) and disassemble the instruction in `NASM` compilable format to `stdout`.

Here is a sample of firts lines of the code generated by the disassembler while disassembling `srcs/tests/samples/avx512.S` (`${TESTDIR}/avx512.log.S` after running [automated testing](##Testing.link)):
```asm
vpaddb xmm31 {k1}, xmm30, xmm29
vpaddb xmm4 {k1} {z}, xmm14, xmm1
vpaddb xmm4 {k1}, xmm14, [r12]
vpaddb xmm4 {k1} {z}, xmm14, [r12]
```

Here some of non-processor-extension also generated by the disassembler (form `${TESTDIR}/basic.log.S` after nunning [automated testing](##Testing.link)):
```asm
imul r8b
imul BYTE [r8]
imul r8w
imul WORD [r8]
imul r8d
imul DWORD [r8]
imul r8
imul QWORD [r8]
imul r8w, r9w
imul r8w, WORD [r9]
imul r8d, r9d
imul r8d, DWORD [r9]
imul r8, r9
imul r8, QWORD [r9]
imul r8w, r9w, 0x8
imul r8w, WORD [r9], 0x8
imul r8d, r9d, 0x8
imul r8d, DWORD [r9], 0x8
imul r8, r9, 0x8
imul r8, QWORD [r9], 0x8
imul r8w, r9w, 0x6969
imul r8w, WORD [r9], 0x6969
imul r8d, r9d, 0x69696969
imul r8d, DWORD [r9], 0x69696969
imul r8, r9, 0x69696969
imul r8, QWORD [r9], 0x69696969
```

Yesss, looks like fresh compilable assembly code ... :)

---

## <a name="#Testing.link">IV) Testing</a>

The tests are performed through the script `tester.sh`. All the instructions (and all their spetializations) of the default plus processor extensions previouly listed are tested. The files containing the all the instructions can be found on the `srcs/tests/samples/` directory.

The script, for each test file, firstly compiles the file, then extracts the `.text` section into a temporary file which is used as disassembler input. The diassembler will output compilable `NASM` assembly which is compiled using the `NASM` compiler. Finally checks the diff between the object file which is result of the compilation of the disassembler output and the object file compiled at the begin (through objdump).

All the log files are preserved. Take a look of the script if you wanna see theses files.

### NOTE: Automated testing for the assembler has also to be implemented! 
---
