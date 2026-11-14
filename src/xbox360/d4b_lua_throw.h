/* Swing_DLL.xex Lua thread-state view used by the error and call paths. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef D4B_LUA_THROW_H
#define D4B_LUA_THROW_H

#include "d3d_lua.h"

/* Error-recovery record: setjmp buffer at +0x10, status code at +0x550. */
typedef struct Ts4LuaLongJmp {
    char pad[0x10];
    char b[0x540];
    volatile int status;
} Ts4LuaLongJmp;

typedef struct Ts4LuaStateErr {
    char pad0[0xC];
    Ts4LuaValue *top;
    char pad10[4];
    struct Ts4LuaGlobalPanic *l_G;
    char pad18[4];
    Ts4LuaValue *stack_last;
    Ts4LuaValue *stack;
    int stacksize;
    char pad28[0x30 - 0x28];
    unsigned short size_ci;
    unsigned short nCcalls;
    char pad34[0x60 - 0x34];
    Ts4LuaLongJmp *errorJmp;
    int errfunc;
} Ts4LuaStateErr;

typedef struct Ts4LuaGlobalPanic {
    char pad[0x30];
    int (*panic)(Ts4LuaStateErr *L);
} Ts4LuaGlobalPanic;

extern void fn_88569D30(void *buf, int val);
extern TS4_NORETURN void ts4_tailcall_fn_88564208_885643D0(int code);
extern void ts4_luaD_reallocstack_8881D478(void *L, int n);
extern void ts4_lua_call_8881E258(Ts4LuaStateErr *L, Ts4LuaValue *func, int nresults);

#define TS4_THROW(L, code) \
    if ((L)->errorJmp) { \
        (L)->errorJmp->status = (code); \
        fn_88569D30((L)->errorJmp->b, 1); \
    } \
    (L)->l_G->panic(L); \
    ts4_tailcall_fn_88564208_885643D0(1)

#endif
