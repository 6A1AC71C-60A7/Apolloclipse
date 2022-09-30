INCDIR	=	includes
SRCDIR	=	srcs

HDRS	=\
$(addprefix includes/,\
	$(addprefix dev/,\
		d_error.h\
		d_instruction.h\
		d_lookup_tables.h\
		d_opcode.h\
		d_portability.h\
		d_types.h\
		d_utils.h\
		tests.h\
	)\
	$(addprefix user/,\
		AVL_mnemonic.h\
		AVL_prefix.h\
		AVL_register.h\
		AVL_types.h\
	)\
	AVL_disassembler.h\
)
SRCS	=\
$(addprefix srcs/,\
	get_instruction_by_extension.c\
	instruction.c\
	lib.c\
	main.c\
	resolve_operands.c\
	suffix.c\
	operand_size.c\
	prefix.c\
	$(addprefix tests/,\
		fprint_instruction.c\
	)\
)
