/* 0x88837FB0: pushes the script object o onto its Lua stack (ts4_call_seq_u32_off18_88837CB0, which fills a {script, top} ref) and returns luaL_getn of it, restoring the stack top. */
/* Matched on /Oc (agAF). The ref helper returns through a hidden out pointer, written as an explicit LuaRef *out argument. */
#include "d3d_lua.h"
typedef Ts4LuaState lua_State;
typedef struct Script { lua_State *L; } Script;
typedef struct Obj { char p[0x18]; Script *script; } Obj;
typedef struct LuaRef { Script *script; int top; } LuaRef;
extern LuaRef *ts4_call_seq_u32_off18_88837CB0(LuaRef *out, Obj *o);
extern int lib3_luaL_getn_8882DF10(lua_State *L, int idx);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
int fn_88837FB0(Obj *o)
{
    lua_State *L = o->script->L;
    int top = ts4_lua_gettop(L);
    int n;
    LuaRef ref;
    ts4_call_seq_u32_off18_88837CB0(&ref, o);
    n = lib3_luaL_getn_8882DF10(o->script->L, -1);
    lua3_lua_settop_888246A8(L, top);
    return n;
}
