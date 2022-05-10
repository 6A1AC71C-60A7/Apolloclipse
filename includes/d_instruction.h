
#include <d_types.h>

/* Legacy prefixes masks */
#define LP_LOCK_MASK (udword)(0x1)
#define LP_REPNX_MASK (udword)(LP_LOCK_MASK << 1)
#define LP_REPX_MASK (udword)(LP_REPNX_MASK << 1)
#define LP_CS_MASK (udword)(LP_REPX_MASK << 1)
#define LP_SS_MASK (udword)(LP_CS_MASK << 1)
#define LP_DS_MASK (udword)(LP_SS_MASK << 1)
#define LP_ES_MASK (udword)(LP_DS_MASK << 1)
#define LP_FS_MASK (udword)(LP_ES_MASK << 1)
#define LP_GS_MASK (udword)(LP_FS_MASK << 1)
#define LP_NOBRANCH_MASK (udword)(LP_GS_MASK << 1)
#define LP_BRANCH_MASK (udword)(LP_NOBRANCH_MASK << 1)
#define LP_OPSZ_MASK (udword)(LP_BRANCH_MASK << 1)
#define LP_ADDRSZ_MASK (udword)(LP_OPSZ_MASK << 1)

/* Mandatory prefixes masks */
#define MP_0x66_MASK (udword)(LP_ADDRSZ_MASK << 1)
#define MP_0xF2_MASK (udword)(MP_0x66_MASK << 1)
#define MP_0xF3_MASK (udword)(MP_0xF2_MASK << 1)

/* REX prefixes masks */
#define RP_REXW_MASK (udword)(MP_0xF3_MASK << 1)
#define RP_REXR_MASK (udword)(RP_REXW_MASK << 1)
#define RP_REXE_MASK (udword)(RP_REXR_MASK << 1)
#define RP_REXB_MASK (udword)(RP_REXE_MASK << 1)

/* Operand kind get */
#define GET_OP1_TYPE(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2 + 0x4) >> 0x4) & 0b00000011)
#define GET_OP1_TYPE(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2 + 0x4) >> 0x6) & 0b00000011)

/* Operands kinds */
#define FL_OP1_IMM 0x0
#define FL_OP1_MEM 0x1
#define FL_OP1_REG 0x2
#define FL_OP1_UNUSED 0x3 // free to use for something
#define FL_OP2_IMM 0x0
#define FL_OP2_MEM 0x2
#define FL_OP2_REG 0x2
#define FL_OP2_UNUSED 0x3 // free to use for something

/* VEX/XOP members values */
#define VEXXOP_PREFIX_GET(x) (ubyte)(*(ubyte*)&(x))
#define VEXXOP_R_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte)) & 0b00000001)
#define VEXXOP_X_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) + 0x1) & 0b00000010)
#define VEXXOP_B_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) + 0x3) & 0b00000100)
#define VEXXOP_MAP_SELECT_GET(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte)) >> 0x3) & 0b00011111)
#define VEXXOP_WE_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) * 2) & 0b00000001)
#define VEXXOP_VVVV_GET(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2) >> 0x1) & 0b00001111)
#define VEXXOP_L_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) * 2 + 0x5) & 0b00100000)
#define VEXXOP_PP_GET(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2) >> 0x7) & 0b00000011)

typedef enum
{
    NOP // We could sort the mnemonics in a specific order in a way to make ranges (groups)
} mnemonic_t;

typedef struct
{
	ubyte prefix[4];
	ubyte opcode[3];
	mnemonic_t mnemonic;
	ubyte vexxop[3];
	ubyte mod_rm;
	ubyte sib;
	uqword displacement;
	uqword operand_r;
	uqword operand_l;
} instuction_t;
