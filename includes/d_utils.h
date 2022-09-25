
#pragma once

#include <d_types.h>

#define ARRLEN(x) (sizeof(x) / sizeof(*x))
#define TESTRANGE(x, r1, r2) ((x) >= (r1) && (x) <= (r2))
#define INST_ISPREFIXED(x) (*(uword*)(x)->i_opcode) // use this one before the others
#define INST_ISPREF_0F(x) (!(x)->i_opcode[1])
#define INST_ISPREF_0F38(x) ((x)->i_opcode[1] == 0x38)
#define INST_ISPREF_0F3A(x) ((x)->i_opcode[1] == 0x3A)
#define GET_ROW(x) (((x) >> 0x4) & 0xF)
#define GET_COLUMN(x) ((x) & 0xF)