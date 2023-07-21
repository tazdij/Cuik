// our precious x86 assembly ops
//
//           mnemonic       category    fields
X(RET,       "ret",         BYTE,       0xC3)
X(INT3,      "int3",        BYTE,       0xCC)
X(STOSB,     "rep stosb",   BYTE,       0xAA)
X(MOVSB,     "rep movsb",   BYTE,       0xA4)
X(CAST,      NULL,          BYTE,       0x99)
X(SYSCALL,   "syscall",     BYTE_EXT,   0x05)
X(RDTSC,     "rdtsc",       BYTE_EXT,   0x31)

X(NOT,       "not",         UNARY,      .op_i = 0xF7, 0x02)
X(NEG,       "neg",         UNARY,      .op_i = 0xF7, 0x03)
X(MUL,       "mul",         UNARY,      .op_i = 0xF7, 0x04)
X(DIV,       "div",         UNARY,      .op_i = 0xF7, 0x06)
X(IDIV,      "idiv",        UNARY,      .op_i = 0xF7, 0x07)
X(CALL,      "call",        UNARY,      0xE8,   0xFF, 0x02)
X(JMP,       "jmp",         UNARY,      0xE9,   0xFF, 0x04)

// Jcc
X(JO,        "jo",          UNARY_EXT,  0x80)
X(JNO,       "jno",         UNARY_EXT,  0x81)
X(JB,        "jb",          UNARY_EXT,  0x82)
X(JNB,       "jnb",         UNARY_EXT,  0x83)
X(JE,        "je",          UNARY_EXT,  0x84)
X(JNE,       "jne",         UNARY_EXT,  0x85)
X(JBE,       "jbe",         UNARY_EXT,  0x86)
X(JA,        "ja",          UNARY_EXT,  0x87)
X(JS,        "js",          UNARY_EXT,  0x88)
X(JNS,       "jns",         UNARY_EXT,  0x89)
X(JP,        "jp",          UNARY_EXT,  0x8A)
X(JNP,       "jnp",         UNARY_EXT,  0x8B)
X(JL,        "jl",          UNARY_EXT,  0x8C)
X(JGE,       "jge",         UNARY_EXT,  0x8D)
X(JLE,       "jle",         UNARY_EXT,  0x8E)
X(JG,        "jg",          UNARY_EXT,  0x8F)

// SETcc
X(SETO,      "seto",        UNARY_EXT,  0x90)
X(SETNO,     "setno",       UNARY_EXT,  0x91)
X(SETB,      "setb",        UNARY_EXT,  0x92)
X(SETNB,     "setnb",       UNARY_EXT,  0x93)
X(SETE,      "sete",        UNARY_EXT,  0x94)
X(SETNE,     "setne",       UNARY_EXT,  0x95)
X(SETBE,     "setbe",       UNARY_EXT,  0x96)
X(SETA,      "seta",        UNARY_EXT,  0x97)
X(SETS,      "sets",        UNARY_EXT,  0x98)
X(SETNS,     "setns",       UNARY_EXT,  0x99)
X(SETP,      "setp",        UNARY_EXT,  0x9A)
X(SETNP,     "setnp",       UNARY_EXT,  0x9B)
X(SETL,      "setl",        UNARY_EXT,  0x9C)
X(SETGE,     "setge",       UNARY_EXT,  0x9D)
X(SETLE,     "setle",       UNARY_EXT,  0x9E)
X(SETG,      "setg",        UNARY_EXT,  0x9F)

// binary ops but they have an implicit CL on the righthand side
X(SHL,       "shl",         BINOP_CL,   0xD2, 0xC0, 0x04)
X(SHR,       "shr",         BINOP_CL,   0xD2, 0xC0, 0x05)
X(ROL,       "rol",         BINOP_CL,   0xD2, 0xC0, 0x00)
X(ROR,       "ror",         BINOP_CL,   0xD2, 0xC0, 0x01)
X(SAR,       "sar",         BINOP_CL,   0xD2, 0xC0, 0x07)

X(ADD,       "add",         BINOP,      0x00, 0x80, 0x00)
X(OR,        "or",          BINOP,      0x08, 0x80, 0x01)
X(AND,       "and",         BINOP,      0x20, 0x80, 0x04)
X(SUB,       "sub",         BINOP,      0x28, 0x80, 0x05)
X(XOR,       "xor",         BINOP,      0x30, 0x80, 0x06)
X(CMP,       "cmp",         BINOP,      0x38, 0x80, 0x07)
X(MOV,       "mov",         BINOP,      0x88, 0xC6, 0x00)
X(TEST,      "test",        BINOP,      0x84, 0xF6, 0x00)

// misc integer ops
X(MOVABS,    "mov",         BINOP_PLUS, 0xB8)
X(XCHG,      "xchg",        BINOP,      0x86)
X(LEA,       "lea",         BINOP,      0x8D)
X(XADD,      "xadd",        BINOP_EXT,  0xC0)
X(IMUL,      "imul",        BINOP_EXT,  0xAF)
X(MOVSXB,    "movsxb",      BINOP_EXT2, 0xBE)
X(MOVSXW,    "movsxw",      BINOP_EXT2, 0xBF)
X(MOVSXD,    "movsxd",      BINOP,      0x63)
X(MOVZXB,    "movzxb",      BINOP_EXT2, 0xB6)
X(MOVZXW,    "movzxw",      BINOP_EXT2, 0xB7)

// SSE binops
X(FP_MOV,    "mov",         BINOP_SSE,  0x10)
X(FP_ADD,    "add",         BINOP_SSE,  0x58)
X(FP_MUL,    "mul",         BINOP_SSE,  0x59)
X(FP_SUB,    "sub",         BINOP_SSE,  0x5C)
X(FP_DIV,    "div",         BINOP_SSE,  0x5E)
X(FP_CMP,    "cmp",         BINOP_SSE,  0xC2)
X(FP_UCOMI,  "ucomi",       BINOP_SSE,  0x2E)
X(FP_CVT32,  "cvtsi",       BINOP_SSE,  0x2A)
X(FP_CVT64,  "cvtsi",       BINOP_SSE,  0x2A)
X(FP_CVT,    "cvt",         BINOP_SSE,  0x5A)
X(FP_CVTT,   "cvtt",        BINOP_SSE,  0x2C)
X(FP_SQRT,   "sqrt",        BINOP_SSE,  0x51)
X(FP_RSQRT,  "rsqrt",       BINOP_SSE,  0x52)
X(FP_AND,    "and",         BINOP_SSE,  0x54)
X(FP_OR,     "or",          BINOP_SSE,  0x56)
X(FP_XOR,    "xor",         BINOP_SSE,  0x57)
#undef X