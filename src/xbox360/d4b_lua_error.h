/* Swing_DLL.xex luaL_error (0x8882E5F0) and luaG_runerror (0x8881FB60). The compiler only
   reproduces the callers' frames when it sees these (noreturn) bodies in the same unit. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef D4B_LUA_ERROR_H
#define D4B_LUA_ERROR_H

#include "d3d_lua.h"

#ifndef TS4_LUA_ERROR_LINKAGE
#ifdef _MSC_VER
#define TS4_LUA_ERROR_LINKAGE static __inline
#else
#define TS4_LUA_ERROR_LINKAGE static inline
#endif
#endif

typedef char *ts4_va_list;
#ifdef _MSC_VER
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#define TS4_VA_START(ap, v) ((ap) = (char *)0, (void)(v))
#endif

extern void fn_8882E2D0(Ts4LuaState *L, int level);
extern const char *fn_888188F8(Ts4LuaState *L, const char *fmt, ts4_va_list argp);
extern void fn_8880FA80(Ts4LuaState *L, int total, int last);
extern void ts4_call_seq_fn_8881C130_8881C200(Ts4LuaState *L);
extern TS4_NORETURN int ts4_lua_errormsg_8881F900(Ts4LuaState *L);
extern void fn_8881FAD0(Ts4LuaState *L, const char *msg);

#define TS4_CHECK_GC(L) \
    if (((Ts4LuaGlobal *)(L)->l_G)->nblocks >= ((Ts4LuaGlobal *)(L)->l_G)->GCthreshold) \
        ts4_call_seq_fn_8881C130_8881C200(L)

#ifndef TS4_SKIP_LUAL_ERROR
/* luaL_error: prefix the position, format the message, concatenate and raise it. */
TS4_LUA_ERROR_LINKAGE int lib3_luaL_error_8882E5F0(Ts4LuaState *L, const char *fmt, ...)
{
    ts4_va_list argp;
    TS4_VA_START(argp, fmt);
    fn_8882E2D0(L, 1);
    TS4_CHECK_GC(L);
    fn_888188F8(L, fmt, argp);
    TS4_CHECK_GC(L);
    fn_8880FA80(L, 2, (int)(L->top - L->base) - 1);
    L->top--;
    return ts4_lua_errormsg_8881F900(L);
}
#endif

#ifndef TS4_SKIP_RUNERROR
/* luaG_runerror: format the message, add position information and raise it. */
TS4_LUA_ERROR_LINKAGE int lua3_luaG_runerror_8881FB60(Ts4LuaState *L, const char *fmt, ...)
{
    ts4_va_list argp;
    TS4_VA_START(argp, fmt);
    fn_8881FAD0(L, fn_888188F8(L, fmt, argp));
    return ts4_lua_errormsg_8881F900(L);
}
#endif

#ifndef TS4_SKIP_PUSHFSTRING
#ifndef TS4_PUSHFSTRING_LINKAGE
#define TS4_PUSHFSTRING_LINKAGE TS4_LUA_ERROR_LINKAGE
#endif
/* lua_pushfstring: format into a new string pushed on the stack. */
TS4_PUSHFSTRING_LINKAGE const char *lib3_lua_pushfstring_88822988(Ts4LuaState *L, const char *fmt, ...)
{
    ts4_va_list argp;
    const char *ret;
    TS4_CHECK_GC(L);
    TS4_VA_START(argp, fmt);
    ret = fn_888188F8(L, fmt, argp);
    return ret;
}
#endif

#endif
