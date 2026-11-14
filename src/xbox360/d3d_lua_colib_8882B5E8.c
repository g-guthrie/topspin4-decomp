/* Swing_DLL.xex 0x8882B5E8-0x8882C09C, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d3d_lua.h"

typedef Ts4LuaValue TValue;
typedef Ts4LuaState lua_State;

/* Closure header: the C-function flag is a byte at +0xC. */
typedef struct Ts4LuaClosure {
    char header[0xC];
    u8 isC;
} Ts4LuaClosure;

extern char lbl_880E20E0[];
extern char lbl_880E20F4[];
extern char lbl_880E210C[];
extern char lbl_880E2114[];
extern char lbl_880E211C[];
extern TS4_NORETURN int fn_8882E6B8(lua_State *L, int narg, const char *extramsg);
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len);
extern void ts4_lua_pushboolean_88823D48(lua_State *L, int b);
extern void ts4_lua_insert_88824438(lua_State *L, int idx);
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void fn_88824958(lua_State *from, lua_State *to, int n);
extern lua_State *ts4_lua_newthread_88824850(lua_State *L);
extern int fn_8882B768(lua_State *L, lua_State *co, int narg);

/* lua_tothread for a positive index. */
TS4_FORCEINLINE lua_State *lua_tothread_(lua_State *L, int idx)
{
    TValue *o = L->base + (idx - 1);
    if (o >= L->top) o = 0;
    return (o == 0 || o->tt != 8) ? 0 : (lua_State *)o->u.p;
}

/* lua_iscfunction for a positive index. */
TS4_FORCEINLINE int lua_iscfunction_(lua_State *L, int idx)
{
    TValue *o = L->base + (idx - 1);
    if (o >= L->top) o = 0;
    return (o == 0) ? 0 : (o->tt == 6 && ((Ts4LuaClosure *)o->u.p)->isC);
}

/* luaB_costatus */
int ts4_lua_b_costatus_8882B5E8(lua_State *L)
{
    TValue *o = L->base;
    lua_State *co;
    if (o >= L->top) o = 0;
    co = (o == 0 || o->tt != 8) ? 0 : (lua_State *)o->u.p;
    if (!co) fn_8882E6B8(L, 1, lbl_880E20E0);
    if (L == co) ts4_lua_pushlstring_88823FC0(L, lbl_880E210C, 7);
    else {
        if (co->ci == co->base_ci && ts4_lua_gettop(co) == 0)
            ts4_lua_pushlstring_88823FC0(L, lbl_880E2114, 4);
        else
            ts4_lua_pushlstring_88823FC0(L, lbl_880E211C, 9);
    }
    return 1;
}

/* luaB_cocreate */
int ts4_lua_b_cocreate_8882B6A8(lua_State *L)
{
    lua_State *NL = ts4_lua_newthread_88824850(L);
    if (!(ts4_lua_type(L, 1) == 6 && !lua_iscfunction_(L, 1))) fn_8882E6B8(L, 1, lbl_880E20F4);
    ts4_lua_pushvalue_88824248(L, 1);
    fn_88824958(L, NL, 1);
    return 1;
}

/* luaB_coresume */
int ts4_lua_b_coresume_8882BFD0(lua_State *L)
{
    lua_State *co = lua_tothread_(L, 1);
    int r;
    if (!co) fn_8882E6B8(L, 1, lbl_880E20E0);
    r = fn_8882B768(L, co, ts4_lua_gettop(L) - 1);
    if (r < 0) {
        ts4_lua_pushboolean_88823D48(L, 0);
        ts4_lua_insert_88824438(L, -2);
        return 2;
    }
    else {
        ts4_lua_pushboolean_88823D48(L, 1);
        ts4_lua_insert_88824438(L, -(r + 1));
        return r + 1;
    }
}
