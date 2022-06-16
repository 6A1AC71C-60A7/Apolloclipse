
#pragma once

#include <d_instruction.h>

void test_instruction(const ubyte *instruction_raw, instruction_t* answer);

void fprint_instruction(instruction_t* target, FILE* where);
