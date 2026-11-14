/* Swing_DLL.xex Lua object layouts shared by the d7q units. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef D7Q_LUA_H
#define D7Q_LUA_H

#include "d6q_lua.h"

#ifdef _MSC_VER
#define TS7_NOINLINE __declspec(noinline)
#else
#define TS7_NOINLINE
#endif

/* Expression descriptor used by the parser (0x18 bytes). */
typedef struct Ts7Expr {
    int k;
    union {
        struct { int info, aux; } s;
    } u;
    int t;
    int f;
    int pad;
} Ts7Expr;

/* Block record: previous at +0, break lists at +4/+8, active vars at +0xC, upvalue flag +0x10, breakable +0x14. */
typedef struct Ts7Block {
    struct Ts7Block *previous;
    int breaklist;
    int breaklist2;
    int nactvar;
    int upval;
    int isbreakable;
} Ts7Block;

/* Lexer state: current token at +0x10, line at +4, function state at +0x30, thread at +0x34. */
typedef struct Ts7Lex {
    int pad0;
    int linenumber;
    int pad8;
    int padC;
    int t;
    int pad14;
    int pad18;
    int pad1C;
    int pad20;
    int pad24;
    int pad28;
    int pad2C;
    struct Ts7Func *fs;
    lua_State *L;
} Ts7Lex;

typedef struct Ts7Func {
    void *f;
    char pad4[0x10];
    Ts7Block *bl;
    int pc;
    char pad1c[0x18];
    int nactvar;
} Ts7Func;

extern void ts4_luaX_next_88814BB8(Ts7Lex *ls);
extern const char *fn_888194C0(Ts7Lex *ls, int token);
extern const char *fn_888188F8(lua_State *L, const char *fmt, ts4_va_list argp);
extern TS4_NORETURN void fn_888195F0(Ts7Lex *ls, const char *msg);

#endif
