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
	d_register.h\
	d_types.h\
	d_utils.h\
	tests.h\
)
SRCS	=\
$(addprefix srcs/,\
	get_instruction_by_extension.c\
	get_instruction.c\
	get_instruction_prefixes.c\
	handle_modrm.c\
	instruction.c\
	main.c\
	resolve_operands.c\
	$(addprefix tests/,\
		test_instruction.c\
		fprint_instruction.c\
	)\
)
