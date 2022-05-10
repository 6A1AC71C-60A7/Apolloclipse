#pragma once

#include <stdio.h>

# define ERROR(x...) (fprintf(stderr, x))
# define DEBUG(x...) (fprintf(stderr, x))

typedef enum
{
	SUCCESS,
	SYSCALL,
	INVOPCODE,
} err_t;
