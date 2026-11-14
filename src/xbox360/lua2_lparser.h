/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Parser and code generator state (llex.h, lparser.h, lcode.h), as laid out in Swing_DLL.xex. */
#ifndef LUA2_LPARSER_H
#define LUA2_LPARSER_H
#include "lua2.h"

/* LuaPlus token set: `continue', wide strings and the shift operators. */
enum RESERVED {
    TK_AND = 257, TK_BREAK, TK_CONTINUE, TK_DO, TK_ELSE, TK_ELSEIF, TK_END, TK_FALSE, TK_FOR,
    TK_FUNCTION, TK_IF, TK_IN, TK_LOCAL, TK_NIL, TK_NOT, TK_OR, TK_REPEAT, TK_RETURN, TK_THEN,
    TK_TRUE, TK_UNTIL, TK_WHILE,
    TK_NAME, TK_CONCAT, TK_DOTS, TK_EQ, TK_GE, TK_LE, TK_NE, TK_NUMBER, TK_STRING, TK_WSTRING,
    TK_SHL, TK_SHR, TK_EOS
};

typedef union {
    double r;
    TString *ts;
} SemInfo;

typedef struct Token {
    int token;
    SemInfo seminfo;
} Token;

struct FuncState;
typedef struct LexState {
    int current;
    int linenumber;
    int lastline;
    Token t;
    Token lookahead;
    struct FuncState *fs;
    lua_State *L;
    void *z;
    Mbuffer *buff;
    TString *source;
    int nestlevel;
} LexState;

typedef enum {
    VVOID, VNIL, VTRUE, VFALSE, VK, VLOCAL, VUPVAL, VGLOBAL, VINDEXED, VJMP, VRELOCABLE, VNONRELOC, VCALL
} expkind;

typedef struct expdesc {
    expkind k;
    int info, aux;
    int t;
    int f;
} expdesc;

/* LuaPlus adds the pending `continue' jumps. */
typedef struct BlockCnt {
    struct BlockCnt *previous;
    int breaklist;
    int continuelist;
    int nactvar;
    int upval;
    int isbreakable;
} BlockCnt;

#define MAXUPVALUES 32
#define MAXVARS 200
#define MAXPARAMS 100
#define MAXSTACK 250
#define MAXARG_Bx 0x3FFFF
#define NO_JUMP (-1)
#define MAX_INT (0x7FFFFFFF - 2)

typedef struct FuncState {
    Proto *f;
    Table *h;
    struct FuncState *prev;
    LexState *ls;
    lua_State *L;
    BlockCnt *bl;
    int pc;
    int lasttarget;
    int jpc;
    int freereg;
    int nk;
    int np;
    int nlocvars;
    int nactvar;
    expdesc upvalues[MAXUPVALUES];
    int actvar[MAXVARS];
} FuncState;

#define getlocvar(fs, i) ((fs)->f->locvars[(fs)->actvar[i]])

/* Instruction layout: op 6 bits at 0, C at 6, B at 15, A at 24; Bx at 6. */
#define CREATE_ABC(o, a, b, c) ((Instruction)(o) | ((Instruction)(a) << 24) | ((Instruction)(b) << 15) | ((Instruction)(c) << 6))
#define CREATE_ABx(o, a, bc) ((Instruction)(o) | ((Instruction)(a) << 24) | ((Instruction)(bc) << 6))

/* Opcodes whose numbers were confirmed in the binary (LuaPlus renumbers them). */
typedef enum {
    OP_MOVE = 0,
    OP_LOADK = 1,
    OP_LOADBOOL = 2,
    OP_LOADNIL = 3,
    OP_GETUPVAL = 4,
    OP_GETGLOBAL = 5,
    OP_GETTABLE = 6,
    OP_SETGLOBAL = 7,
    OP_SETUPVAL = 8,
    OP_SETTABLE = 9,
    OP_NEWTABLE = 10,
    OP_SELF = 11,
    OP_ADD = 12,
    OP_SUB = 13,
    OP_UNM = 21,
    OP_NOT = 22,
    OP_CONCAT = 23,
    OP_JMP = 24,
    OP_EQ = 25,
    OP_LT = 26,
    OP_LE = 27,
    OP_TEST = 28,
    OP_CALL = 29,
    OP_TAILCALL = 30,
    OP_RETURN = 31,
    OP_FORLOOP = 32,
    OP_TFORLOOP = 33,
    OP_TFORPREP = 34,
    OP_SETLIST = 35,
    OP_SETLISTO = 36,
    OP_CLOSE = 37,
    OP_CLOSURE = 38
} OpCode;

extern LUA2_NORETURN void lua2_luaX_syntaxerror_888195F0(LexState *ls, const char *msg); /* luaX_syntaxerror */
extern const char *lua2_luaX_token2str_888194C0(LexState *ls, int token);             /* luaX_token2str */
extern int lua2_luaX_lex_8881A6E8(LexState *ls, SemInfo *seminfo);              /* luaX_lex */

extern int lua2_luaK_code_888208A8(FuncState *fs, Instruction i);                /* luaK_code (line taken from ls) */
extern void *fn_889CE7D8(lua_State *L, void *block, int *size, int size_elem, int limit, const char *errormsg); /* luaM_growaux */

#endif
