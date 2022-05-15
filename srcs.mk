INCDIR	=	includes
SRCDIR	=	srcs

HDRS	=\
$(addprefix includes/,\
	d_error.h\
	d_instruction.h\
	d_lookup_tables.h\
	d_register.h\
	d_types.h\
	d_utils.h\
	tests.h\
)
SRCS	=\
$(addprefix srcs/,\
	get_instruction_prefixes.c\
	main.c\
	$(addprefix tests/,\
		test_instruction.c\
	)\
)
