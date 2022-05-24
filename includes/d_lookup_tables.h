
#pragma once

#include <d_opcode.h>

static const ubyte lt_legacy_prefixes[] = {
    0xF0, 0xF2, 0xF3, 0x64, 0x65, 0x2E, 0x3E, 0x66, 0x67
};

#define DREF_RM (0x1)
#define DREF_SIB (DREF_RM << 1)
#define DISP_8 (DREF_SIB << 1)
#define DISP_32 (DISP_8 << 1)
#define VAL_RM (DISP_32 << 1)

static const ubyte lt_modrm_encoded[] = {
	DREF_RM, DREF_RM, DREF_RM, DREF_RM, DREF_SIB, DREF_SIB | DISP_32, DREF_RM, DREF_RM, DREF_RM, DREF_RM, DREF_RM, DREF_RM, DREF_SIB, DREF_SIB | DISP_32, DREF_RM, DREF_RM, // mod == 0b00
	DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8,	DREF_SIB | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_SIB | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, DREF_RM | DISP_8, // mod == 0b01
	DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_SIB | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_SIB | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32, DREF_RM | DISP_32,  // mod == 0b10
	VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM, VAL_RM // mod == 0b11
};

#define SBASE (0x1)
#define SINDEX (SBASE << 1)
#define SDISP_8 (SINDEX << 1)
#define SDISP_32 (SDISP_8 << 1)
#define SSCALE (SDISP_32 << 1)

static const ubyte lt_sib_encoded[] = {
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b0000
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b0001
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX |  SSCALE, // mod == 0b00 ; SIB.index == 0b0010
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b0011
	SBASE, SBASE, SBASE, SBASE, SBASE, SDISP_32, SBASE, SBASE, SBASE, SBASE, SBASE, SBASE, SBASE, DISP_32, SBASE, SBASE, // mod == 0b00 ; SIB.index == 0100
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b0101
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b0111
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1000
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1001
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1010
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1011
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1100
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1101
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1110
	SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | DISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE, SBASE | SINDEX | SSCALE, // mod == 0b00 ; SIB.index == 0b1111
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b0000
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b0001
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b0010
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b0011
	SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, SBASE | DISP_8, // mod == 0b01 ; SIB.index == 0b0100
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b0101
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b0110
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b0111
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1000
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1001
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1010
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1011
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1100
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1101
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1110
	SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, SBASE | SINDEX | SSCALE | SDISP_8, // mod == 0b01 ; SIB.index == 0b1111
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b0000
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b0001
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b0010
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b0011
	SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, SBASE | DISP_32, // mod = b010 ; SIB.index == 0b0100
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b0101
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b0110
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b0111
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1000
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1001
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1010
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1011
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1100
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1101
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1010
	SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, SBASE | SINDEX | SSCALE | SDISP_32, // mod == 0b10 ; SIB.index == 0b1111
};

static const ubyte lt_opcode_defaut_map[] = {

};

static const ubyte lt_opcode_0x0F_map[] = {

};

static const ubyte lt_opcode_0x0F38_map[] = {

};

static const ubyte lt_opcode_0x0F3A_map[] = {

};

static const ubyte lt_opcode_3dnow_map[] = {

};

///TODO: JUMPS, RET, CALLS MAY HAVE DIFERENT DISPLACEMNT DISTANCES
/// IDK IF I'VE COMMENTED IT WELL IN THE TODO'S OVER THE MAPS



static const opfield_t lt_one_byte_opmap[] = {

	{ .mnemonic = ADD,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADD,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADD,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADD,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADD,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADD,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUSH,		.am1 = DR_ES,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = POP,		.am1 = DR_ES,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },

	{ .mnemonic = OR,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OR,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OR,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OR,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OR,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OR,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUSH,		.am1 = DR_CS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = ADC,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADC,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADC,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADC,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADC,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = ADC,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUSH,		.am1 = DR_SS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = POP,		.am1 = DR_ES,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },

	{ .mnemonic = SBB,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SBB,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SBB,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SBB,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SBB,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SBB,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUSH,		.am1 = DR_DS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = POP,		.am1 = DR_DS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },

	{ .mnemonic = AND,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = AND,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = AND,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = AND,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = AND,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = AND,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = DAA,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },

	{ .mnemonic = SUB,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SUB,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SUB,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SUB,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SUB,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SUB,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = DAS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },

	{ .mnemonic = XOR,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XOR,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XOR,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XOR,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XOR,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XOR,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = AAA,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = CMP,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMP,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMP,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMP,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMP,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMP,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = AAS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },

	{ .mnemonic = INC,		.am1 = DR_RAX,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = DR_RCX,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = DR_RDX,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = DR_RBX,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = DR_RSP,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = DR_RBP,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = DR_RSI,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = DR_RDI,	.ot1 = DRS_32,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = DEC,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = DEC,		.am1 = DR_RCX,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = DEC,		.am1 = DR_RDX,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = DEC,		.am1 = DR_RBX,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = DEC,		.am1 = DR_RSP,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = DEC,		.am1 = DR_RBP,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = DEC,		.am1 = DR_RSI,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = DEC,		.am1 = DR_RDI,	.ot1 = DRS_64,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },

	{ .mnemonic = PUSH,		.am1 = DR_RAX,	.ot1 = OR_64,	.am2 = DR_R8,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = PUSH,		.am1 = DR_RCX,	.ot1 = OR_64,	.am2 = DR_R8,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = PUSH,		.am1 = DR_RDX,	.ot1 = OR_64,	.am2 = DR_R9,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = PUSH,		.am1 = DR_RBX,	.ot1 = OR_64,	.am2 = DR_R10,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = PUSH,		.am1 = DR_RSP,	.ot1 = OR_64,	.am2 = DR_R12,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = PUSH,		.am1 = DR_RBP,	.ot1 = OR_64,	.am2 = DR_R13,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = PUSH,		.am1 = DR_RSI,	.ot1 = OR_64,	.am2 = DR_R14,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = PUSH,		.am1 = DR_RDI,	.ot1 = OR_64,	.am2 = DR_R15,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },

	{ .mnemonic = POP,		.am1 = DR_RAX,	.ot1 = OR_64,	.am2 = DR_R8,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_RCX,	.ot1 = OR_64,	.am2 = DR_R9,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_RDX,	.ot1 = OR_64,	.am2 = DR_R10,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_RBX,	.ot1 = OR_64,	.am2 = DR_R11,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_RSP,	.ot1 = OR_64,	.am2 = DR_R12,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_RBP,	.ot1 = OR_64,	.am2 = DR_R13,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_RSI,	.ot1 = OR_64,	.am2 = DR_R14,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_RDI,	.ot1 = OR_64,	.am2 = DR_R15,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },

	{ .mnemonic = PUSHA,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = POPA,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = BOUND,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_M,	.ot2 = OT_A,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO:
	{ .mnemonic = 0/*TODO: NOT PRESENT: MOVSXD*/,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_O64 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },


	{ .mnemonic = PUSH,		.am1 = AM_I,	.ot1 = OT_Z,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = IMUL,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = AM_I,	.ot3 = OT_Z,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUSH,		.am1 = AM_I,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = IMUL,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INSB,		.am1 = AM_Y,	.ot1 = OT_B,	.am2 = DR_RDX,	.ot2 = DRS_16,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INS,		.am1 = AM_Y,	.ot1 = OT_Z,	.am2 = DR_RDX,	.ot2 = DRS_16,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OUTSB,	.am1 = DR_RDX,	.ot1 = DRS_16,	.am2 = AM_X,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OUTS,		.am1 = DR_RDX,	.ot1 = DRS_16,	.am2 = AM_X,	.ot2 = OT_X,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = JO,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNO,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JB,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNB,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JZ,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNZ,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JBE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNBE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },

	///TODO: NO OPERAND ?
	{ .mnemonic = JS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JL,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNL,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JLE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNLE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },

	///TODO: WTF are the following 4 ?
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_1A },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_1A },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_1A },
	{ .mnemonic = TEST,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = TEST,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = MOV,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_G,	.ot1 = OT_B,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_S,	.ot2 = OT_W,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LEA,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_M,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_S,	.ot1 = OT_W,	.am2 = AM_E,	.ot2 = OT_W,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: HAS GROUP
	{ .mnemonic = POP,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },

	///TODO: NEXT ONE HAS MULTIPLE MNEMONICS
	/// BYTE LELT IN OPFIELD_T COUND BE 'ISAMBIGIOUS'
	{ .mnemonic = XCHG,		.am1 = DR_R8,	.ot1 = DRS_64,	.am2 = DR_RAX,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = DR_RCX,	.ot1 = OR_64,	.am2 = DR_R9,	.ot2 = DRS_64,	.am3 = DR_RAX,	.ot3 = DRS_64,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = DR_RDX,	.ot1 = OR_64,	.am2 = DR_R10,	.ot2 = DRS_64,	.am3 = DR_RAX,	.ot3 = DRS_64,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = DR_RBX,	.ot1 = OR_64,	.am2 = DR_R11,	.ot2 = DRS_64,	.am3 = DR_RAX,	.ot3 = DRS_64,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = DR_RSP,	.ot1 = OR_64,	.am2 = DR_R12,	.ot2 = DRS_64,	.am3 = DR_RAX,	.ot3 = DRS_64,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = DR_RBP,	.ot1 = OR_64,	.am2 = DR_R13,	.ot2 = DRS_64,	.am3 = DR_RAX,	.ot3 = DRS_64,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = DR_RSI,	.ot1 = OR_64,	.am2 = DR_R14,	.ot2 = DRS_64,	.am3 = DR_RAX,	.ot3 = DRS_64,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XCHG,		.am1 = DR_RDI,	.ot1 = OR_64,	.am2 = DR_R15,	.ot2 = DRS_64,	.am3 = DR_RAX,	.ot3 = DRS_64,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = CBW,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CWD,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CALL,		.am1 = AM_A,	.ot1 = OT_P,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = FWAIT,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUSHF,	.am1 = AM_F,	.ot1 = OT_V,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POPF,		.am1 = AM_F,	.ot1 = OT_V,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = SAHF,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LAHF,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = MOV,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_O,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_O,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_O,	.ot1 = OT_B,	.am2 = DR_RAX,	.ot2 = DRS_8,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_O,	.ot1 = OT_V,	.am2 = DR_RAX,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVSB,	.am1 = AM_Y,	.ot1 = OT_B,	.am2 = AM_X,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVS,		.am1 = AM_Y,	.ot1 = OT_V,	.am2 = AM_X,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMPSB,	.am1 = AM_X,	.ot1 = OT_B,	.am2 = AM_Y,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMPS,		.am1 = AM_X,	.ot1 = OT_V,	.am2 = AM_Y,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = TEST,		.am1 = DR_RDX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = TEST,		.am1 = DR_RDX,	.ot1 = DRS_64,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = STOSB,	.am1 = AM_Y,	.ot1 = OT_B,	.am2 = DR_RAX,	.ot2 = DRS_8,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = STOS,		.am1 = AM_Y,	.ot1 = OT_V,	.am2 = DR_RAX,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LODSB,	.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_X,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LODS,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_X,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SCASB,	.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_Y,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SCAS,		.am1 = DR_RAX,	.ot1 = DRS_64,	.am2 = AM_Y,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = MOV,		.am1 = DR_RAX,	.ot1 = OR_8,	.am2 = DR_R8,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RCX,	.ot1 = OR_8,	.am2 = DR_R9,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RDX,	.ot1 = OR_8,	.am2 = DR_R10,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RBX,	.ot1 = OR_8,	.am2 = DR_R11,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_AH,	.ot1 = OR_8,	.am2 = DR_R12,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_CH,	.ot1 = OR_8,	.am2 = DR_R13,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_DH,	.ot1 = OR_8,	.am2 = DR_R14,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_BH,	.ot1 = OR_8,	.am2 = DR_R15,	.ot2 = DRS_8,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = MOV,		.am1 = DR_RAX,	.ot1 = OR_64,	.am2 = DR_R8,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RCX,	.ot1 = OR_64,	.am2 = DR_R9,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RDX,	.ot1 = OR_64,	.am2 = DR_R10,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RBX,	.ot1 = OR_64,	.am2 = DR_R11,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RSP,	.ot1 = OR_64,	.am2 = DR_R12,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RBP,	.ot1 = OR_64,	.am2 = DR_R13,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RSI,	.ot1 = OR_64,	.am2 = DR_R14,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = DR_RDI,	.ot1 = OR_64,	.am2 = DR_R15,	.ot2 = AM_I,	.am3 = OT_V,	.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	///TODO: WTF NEXT 2
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: THIS IS RET NEAR / RET FAR ISN'T SPECIFIED YET IN MNEMONICS
	{ .mnemonic = RET,		.am1 = AM_I,	.ot1 = OT_W,	.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = RET,		.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = LES,		.am1 = AM_G,	.ot1 = OT_Z,	.am2 = AM_M,	.ot2 = OT_P,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = LDS,		.am1 = AM_G,	.ot1 = OT_Z,	.am2 = AM_M,	.ot2 = OT_P,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	///TOOD: CHECK GROUP NEXT 2 {6, C}
	{ .mnemonic = MOV,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_I,	.ot2 = OT_Z,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = ENTER,	.am1 = AM_I,	.ot1 = OT_W,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LEAVE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = DRS_64 },
	///TODO: IS ACTUALLY RET FAR
	{ .mnemonic = RET,		.am1 = AM_I,	.ot1 = OT_W,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: IS ACTUALLU RET FAR
	{ .mnemonic = RET,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: IS INT3 (ONLY NEXT ONE)
	{ .mnemonic = INT,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INT,		.am1 = AM_I,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INTO,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = IRET,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	///TODO: WTF NEXT 4
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = AAM,		.am1 = AM_I,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = AAD,		.am1 = AM_I,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XLAT,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = LOOPNE,	.am1 = AM_J,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = LOOPE,	.am1 = AM_J,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = LOOP,		.am1 = AM_J,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JCXZ,		.am1 = AM_J,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = IN,		.am1 = DR_RAX,	.ot1 = DRS_8,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = IN,		.am1 = DR_RAX,	.ot1 = DRS_32,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OUT,		.am1 = AM_I,	.ot1 = OT_B,	.am2 = DR_RAX,	.ot2 = DRS_8,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OUT,		.am1 = AM_I,	.ot1 = OT_B,	.am2 = DR_RAX,	.ot2 = DRS_32,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	/// TODO: IS NEAR CALL IN DOC
	{ .mnemonic = CALL,		.am1 = AM_J,	.ot1 = OT_Z,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	/// TODO: JUMP NEAR
	{ .mnemonic = JMP,		.am1 = AM_J,	.ot1 = OT_Z,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	/// TODO: JUMP FAR
	{ .mnemonic = JMP,		.am1 = AM_A,	.ot1 = OT_P,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_I64 },
	/// TODO: JUMP SHORT
	{ .mnemonic = JMP,		.am1 = AM_J,	.ot1 = OT_B,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = IN,		.am1 = DR_RAX,	.ot1 = DRS_16,	.am2 = DR_RDX,	.ot2 = DRS_16,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = IN,		.am1 = DR_RAX,	.ot1 = DRS_32,	.am2 = DR_RDX,	.ot2 = DRS_32,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OUT,		.am1 = DR_RDX,	.ot1 = DRS_16,	.am2 = DR_RAX,	.ot2 = DRS_16,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = OUT,		.am1 = DR_RDX,	.ot1 = DRS_32,	.am2 = DR_RAX,	.ot2 = DRS_32,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: IN DOC MNEMONIC IS 'INT1' INSTEAD OF 'INT'
	{ .mnemonic = INT,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XACQUIRE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XRELEASE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = HLT,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMC,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: WFT NEXT 2
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = CLC,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = STC,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CLI,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = STI,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CLD,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = STD,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: HAS GROUP AND IS AMBIGIOUS (ALSO COULD BE DEC)
	{ .mnemonic = INC,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = INC,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
};

///TODO: COPY PASTE FOR PREFIX SPETIALIZATION
///OR: CREATE ANOTHER TABLE
static const opfield_t lt_two_byte_no_prep_opmap[] = {
	/// TODO: GROUPS (NEXT 2)
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LAR,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_W,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LSL,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_W,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SYSCALL,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_O64 },
	{ .mnemonic = CLTS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SYSRET,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_O64 },

	{ .mnemonic = INVD,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = WBINVD,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: WHAT DOES "/1" MEAN ?
	{ .mnemonic = PREFETCHW,.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	/// TODO: VMOVUPS & CO ARE NOT PRESENT (NEXT 8 MNEMONICS)
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_W,	.ot1 = OT_PS,	.am2 = AM_V,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: NEXT ONE IS AMBIGIOUS
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_Q,	.am2 = AM_H,	.ot2 = OT_Q,	.am3 = AM_M,	.ot3 = OT_Q,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_M,	.ot1 = OT_Q,	.am2 = AM_V,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_X,	.am2 = AM_H,	.ot2 = OT_X,	.am3 = AM_W,	.ot3 = OT_X,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_X,	.am2 = AM_H,	.ot2 = OT_X,	.am3 = AM_W,	.ot3 = OT_X,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: NEXT ONE IS AMBIGIOUS
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_DQ,	.am2 = AM_H,	.ot2 = OT_Q,	.am3 = AM_M,	.ot3 = OT_Q,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_M,	.ot1 = OT_Q,	.am2 = AM_V,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	///TODO: NEXT ONE HAS GROUP
	{ .mnemonic = PREFETCHh,.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NOP OR RESERVED ?
	{ .mnemonic = NOP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BNDLDX,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BNDSTX,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NEXT 3 NOP OR RESERVED ?
	{ .mnemonic = NOP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = NOP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = NOP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: WHAT FOES "/0" MEAN ?
	{ .mnemonic = NOP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = MOV,		.am1 = AM_R,	.ot1 = OT_D,	.am2 = AM_C,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_R,	.ot1 = OT_D,	.am2 = AM_D,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_C,	.ot1 = OT_D,	.am2 = AM_R,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOV,		.am1 = AM_D,	.ot1 = OT_D,	.am2 = AM_R,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	///TOOD: 2 FIRST MNEMONIC ARE NOT PRESENT (VMOVAPS)
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_W,	.ot1 = OT_PS,	.am2 = AM_V,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CVTPI2PS,	.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_Q,	.ot2 = OT_PI,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NEXT ONE MNEMONIC NOT PRESENT
	{ .mnemonic = 0,		.am1 = AM_M,	.ot1 = OT_PS,	.am2 = AM_V,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CVTTPS2PI,.am1 = AM_P,	.ot1 = OT_PI,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CVTPS2PI,	.am1 = AM_P,	.ot1 = OT_PI,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NEXT 2 MNMONICS ARE NOT PRESENT
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_SS,	.am2 = AM_W,	.ot2 = OT_SS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_SS,	.am2 = AM_W,	.ot2 = OT_SS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = WRMSR,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = RDTSC,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = RDMSR,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = RDPMC,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SYSENTER,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SYSEXIT,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: IS JUST GETSEC
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = CMOVO,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVNO,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVB,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVAE,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVE,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVNE,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVBE,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVA,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = CMOVS,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVNS,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVP,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVPO,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVNGE,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVNL,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVLE,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMOVNLE,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	/// TODO: MNEMONICS ARE NOT PRESENT IN NEXT 8
	{ .mnemonic = 0,		.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_U,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	/// TODO: MNEMONICS ARE NOT PRESENT IN NEXT 8
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PD,	.am2 = AM_W,	.ot2 = OT_PS,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_W,	.ot2 = OT_DQ,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PUNPCKLBW,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUNPCKLWD,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUNPCKLDQ,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PACKSSWB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PCMPGTB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PCMPGTW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PCMPGTD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PACKUSWB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PUNPCKHBW,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUNPCKHWD,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PUNPCKHDQ,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PACKSSDW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: NEXT ONE CAN ALSO BE MOVQ
	{ .mnemonic = MOVD,		.am1 = AM_P,	.ot1 = OT_D,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVQ,		.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PSHUFW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: NEXT 3 ARE GROUPS
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PCMPEQB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PCMPEQW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PCMPEQD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = EMMS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = VMREAD,	.am1 = AM_E,	.ot1 = OT_Y,	.am2 = AM_G,	.ot2 = AM_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = VMWRITE,	.am1 = AM_Y,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = AM_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: MOVD CAN ALSO BE MOVQ
	{ .mnemonic = MOVD,		.am1 = AM_E,	.ot1 = OT_Y,	.am2 = AM_P,	.ot2 = OT_D,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVQ,		.am1 = AM_Q,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	///TODO: THOSE ARE LONG DISPLACEMENT JUMPS
	/// NOT OPERAND ?!?!?
	/// next 16
	{ .mnemonic = JO,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNO,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JB,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JAE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JNE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JBE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },
	{ .mnemonic = JA,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_F64 },

	{ .mnemonic = JS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = JNS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = JP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = JNP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = JL,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = JNL,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = JLE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = JNLE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = SETO,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETNO,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETB,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETAE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETE,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETNE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETBE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETA,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = SETS,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETNS,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETP,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETNP,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETL,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETNL,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETLE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SETNLE,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PUSH,		.am1 = DR_FS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_FS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = CPUID,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BT,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SHLD,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SHLD,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = DR_RCX,	.ot2 = DRS_8,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PUSH,		.am1 = DR_GS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = POP,		.am1 = DR_GS,	.ot1 = DRS_SEC,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = S_D64 },
	{ .mnemonic = RSM,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BTS,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: NEXT 2 ONES MNEMONICS (SHRD) NOT PRESENT
	{ .mnemonic = 0,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = DR_RCX,	.ot3 = DRS_8,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: GROUP NEXT ONE
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = IMUL,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = CMPXCHG,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = CMPXCHG,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LSS,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_M,	.ot2 = OT_P,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BTR,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LFS,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_M,	.ot2 = OT_P,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = LGS,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_M,	.ot2 = OT_P,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVZX,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVZX,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_W,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	/// TODO: NEXT ONE JMPE RESERVED FOR EMULATOR ON IPF
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NEXT 2 ARE GROUPS
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BTC,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSF,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSR,		.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVSX,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVSX,	.am1 = AM_G,	.ot1 = OT_V,	.am2 = AM_E,	.ot2 = OT_W,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = XADD,		.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_G,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = XADD,		.am1 = AM_E,	.ot1 = OT_V,	.am2 = AM_G,	.ot2 = OT_V,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NEXT ONE MNEMONIC (VCMPPS) NOT PRESENT.
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = AM_I,	.ot4 = OT_B,	.symbol = 0 },
	{ .mnemonic = MOVNTI,	.am1 = AM_M,	.ot1 = OT_Y,	.am2 = AM_G,	.ot2 =OT_Y,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NEXT ONE IS AN SPETIAL CASE HAS OPTIONAL ATTRIBUTES (Ry/Mw) ...
	{ .mnemonic = PINSRW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_R,	.ot2 = OT_Y,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PEXTRW,	.am1 = AM_G,	.ot1 = OT_D,	.am2 = AM_N,	.ot2 = OT_Q,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	/// TODO: NEXT ONE (VSHUFPS) NOT PRESENT.
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_PS,	.am2 = AM_H,	.ot2 = OT_PS,	.am3 = AM_W,	.ot3 = OT_PS,	.am4 = AM_I,	.ot4 = OT_B,	.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	///NOTE: IGNORE 32 BITS (CAUSE 64 ARE HANDLED)
	{ .mnemonic = BSWAP,	.am1 = DR_RAX,	.ot1 = OR_64,	.am2 = DR_R8,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSWAP,	.am1 = DR_RCX,	.ot1 = OR_64,	.am2 = DR_R9,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSWAP,	.am1 = DR_RDX,	.ot1 = OR_64,	.am2 = DR_R10,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSWAP,	.am1 = DR_RBX,	.ot1 = OR_64,	.am2 = DR_R11,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSWAP,	.am1 = DR_RSP,	.ot1 = OR_64,	.am2 = DR_R12,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSWAP,	.am1 = DR_RBP,	.ot1 = OR_64,	.am2 = DR_R13,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSWAP,	.am1 = DR_RSI,	.ot1 = OR_64,	.am2 = DR_R14,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = BSWAP,	.am1 = DR_RDI,	.ot1 = OR_64,	.am2 = DR_R15,	.ot2 = DRS_64,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSRLW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSRLD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSRLQ,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDQ,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMULLW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMOVMSKB,	.am1 = AM_Q,	.ot1 = OT_D,	.am2 = AM_N,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PSUBUSB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSUBUSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMINUB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PAND,		.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDUSB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDUSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMAXUB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PANDN,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PAVGB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSRAW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSRAD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PAVGW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMULHUW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMULHW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVNTQ,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_P,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PSUBSB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSUBSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMINSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = POR,		.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDSB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMAXSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PXOR,		.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSLLW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSLLD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSLLQ,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMULUDQ,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMADDWD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSADBW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MASKMOVDQU,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = PSUBB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSUBW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSUBD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSUBQ,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PADDD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///MMMOK: SO, WHERE IS PADDQ ?!?!?!!?
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
};

static const opfield_t lt_tree_byte_0x38_no_prep_opmap[] = {
	{ .mnemonic = PSHUFB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PHADDW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PHADDD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PHADDSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMADDUBSW,.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PHSUBW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PHSUBD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PHSUBSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = PSIGNB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSIGNW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PSIGND,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PMULHRSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PABSB,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PABSW,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = PABSD,	.am1 = AM_P,	.ot1 = OT_Q,	.am2 = AM_Q,	.ot2 = OT_Q,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	//A
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	//B
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	//C
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = SHA1NEXTE,.am1 = AM_V,	.ot1 = OT_DQ,	.am2 = AM_W,	.ot2 = OT_DQ,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SHA1MSG1,	.am1 = AM_V,	.ot1 = OT_DQ,	.am2 = AM_W,	.ot2 = OT_DQ,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SHA1MSG2,	.am1 = AM_V,	.ot1 = OT_DQ,	.am2 = AM_W,	.ot2 = OT_DQ,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: MNEMONIC SHA256MDS2 NOT PRESENT NEXT ONE
	{ .mnemonic = 0,		.am1 = AM_V,	.ot1 = OT_DQ,	.am2 = AM_W,	.ot2 = OT_DQ,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SHA256MSG1,.am1 = AM_V,	.ot1 = OT_DQ,	.am2 = AM_W,	.ot2 = OT_DQ,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = SHA256MSG2,.am1 = AM_V,	.ot1 = OT_DQ,	.am2 = AM_W,	.ot2 = OT_DQ,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	//E
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	//F
	{ .mnemonic = MOVBE,	.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_M,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = MOVBE,	.am1 = AM_M,	.ot1 = OT_Y,	.am2 = AM_G,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: EXPONENT 'V' SYNTAX IN NEXT ONE
	{ .mnemonic = ANDN,		.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_B,	.ot2 = OT_Y,	.am3 = AM_E,	.ot3 = OT_Y,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: NEXT ONE GROUP
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: EXPONENT 'V' SYNTAX IN NEXT ONE
	{ .mnemonic = BZHI,		.am1 = AM_G,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = AM_B,	.ot3 = OT_Y,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = OT_Y,	.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: EXPONENT 'V' SYNTAX IN NEXT ONE
	{ .mnemonic = BEXTR,	.am1 = AM_G,	.ot1 = 0,		.am2 = AM_E,	.ot2 = OT_Y,	.am3 = AM_B,	.ot3 = OT_Y,	.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

};


static const opfield_t lt_tree_byte_0x38_no_prep_ambigious_opmap[] = {
	/// TODO: MNEMONIC
 	{ .mnemonic = 0 /* vmovups */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* vmovups */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* vmovlps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* vmovlps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* vunpcklps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* vunpckhps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	///TODO: IS V1 X2 NEXT
	{ .mnemonic = 0 /* vmovhps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* vmovhps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0/* bndldx */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* bndstx */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vmovaps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vmovaps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* cvtpi2ps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vmovntps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* cvttps2pi */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* cvtps2pi */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0/* vucomiss */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vcomiss */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vmovmskps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vsqrtps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vrsqrtps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vrcpps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vandps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vandnps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0/* vorps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vxorps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vaddps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vmulps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vcvtps2pd */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vcvtdq2ps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vsubps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vminps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0/* vdivps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* vmaxps */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* punpcklbw */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* punpcklwd */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* punpckldq */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* packsswb */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* pcmpgtb */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* pcmpgtw */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0/* pcmpgtd */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* packuswb */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* punpckhbw */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* punpckhwd */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* punpckhdq */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* packssdw */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0/* movd */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* movq */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* movq */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* pshufw */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* pcmpeqb */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* pcmpeqw */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* pcmpeqd */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* emm */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0/* VMREAD */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* VMWRITE */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* movd */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0/* movq */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0 /* JMPE */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* BSF */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0 /* BSR */,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },

	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
	{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,		.ot4 = 0,		.symbol = 0 },
};

static const opfield_t lt_tree_byte_0x3A_no_prep_opmap[] = {
	/// JUST HOLD ONE NON ZERO ELEMENT ...
};
