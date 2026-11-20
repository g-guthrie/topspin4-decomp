/* Derived from Lua 5.0.2 lapi.c (MIT); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex (wide strings, per-type metatables). */
#include "d3d_lua.h"

typedef Ts4LuaValue TValue;
typedef Ts4LuaState lua_State;

extern Ts4LuaObject *lua2_luaS_newlwstr_88812FC8(lua_State *L, const unsigned short *str, u32 l);

/* lua_pushlwstring */
void cx19_lua_pushlwstring_88834B28(lua_State *L, const unsigned short *s, u32 len)
{
    TValue old;
    TValue *top = L->top;
    old = *top;
    top->u.gc = lua2_luaS_newlwstr_88812FC8(L, s, len);
    top->tt = 9;
    top->u.gc->refs++;
    TS4_RELEASE(L, &old);
    TS4_INCR_TOP(L);
}
