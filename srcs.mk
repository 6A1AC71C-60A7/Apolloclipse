INCDIR	=	includes
SRCDIR	=	srcs

HDRS	=\
$(addprefix includes/,\
	d_error.h\
	d_instruction.h\
	d_lookup_tables.h\
	d_mnemonic.h\
	d_opcode.h\
	d_portability.h\
	d_types.h\
	d_utils.h\
	tests.h\
	$(addprefix user/,\
		prefix.h\
		register.h\
		types.h\
	)\
	user.h\
)
SRCS	=\
$(addprefix srcs/,\
	get_instruction_by_extension.c\
	instruction.c\
	main.c\
	resolve_operands_V2.c\
	$(addprefix tests/,\
		fprint_instruction.c\
		test_instruction.c\
	)\
)
