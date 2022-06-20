
#pragma once

#include <d_instruction.h>

void test_instruction(const ubyte *instruction_raw, instruction_t* answer);

void    fprint_info(FILE* where, instruction_t* target);
void    fprint_instruction(FILE* where, instruction_t* const target);
