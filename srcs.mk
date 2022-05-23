INCDIR	=	includes
SRCDIR	=	srcs

HDRS	=\
$(addprefix includes/,\
	d_error.h\
	d_instruction.h\
	d_lookup_tables.h\
	d_mnemonic.h\
	d_opcode.h\
	d_register.h\
	d_types.h\
	d_utils.h\
	tests.h\
)
SRCS	=\
$(addprefix srcs/,\
	get_instruction.c\
	get_instruction_prefixes.c\
	handle_modrm.c\
	instruction.c\
	main.c\
	$(addprefix tests/,\
		test_instruction.c\
	)\
)
