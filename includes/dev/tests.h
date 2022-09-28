
#pragma once

#include <dev/d_instruction.h>

void test_instruction(const ubyte *instruction_raw, AVL_instruction_t* answer);

void    fprint_info(FILE* where, AVL_instruction_t* target);
void    fprint_instruction(FILE* where, AVL_instruction_t* const target);
