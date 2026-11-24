/* Derived from Lua 5.0.2 lapi.c (MIT); see THIRD_PARTY_NOTICES.md */
/* lapi.c functions (LuaPlus reference-counted values). */
#include "lua3.h"

extern TValue *lib3_lua_negindex_88821F98(lua_State *L, int idx); /* luaA_index for idx <= 0 */

/* A TValue copied as four words (the environment copy is not 8-byte typed). */
typedef struct Words4 {
    u32 w[4];
} Words4;

/* lua_setfenv(L, -2): LTCG folded idx. The old environment is released after the new one is referenced. */
int lua3_lua_setfenv_88823068(lua_State *L)
{
    StkId o;
    int res = 0;
    o = lib3_lua_negindex_88821F98(L, -2);
    L->top--;
    if (ttype(o) == LUA2_TFUNCTION && !clvalue(o)->c.isC) {
        Words4 old;
        TValue *g;
        res = 1;
        old = *(Words4 *)&clvalue(o)->l.g;
        *(Words4 *)&clvalue(o)->l.g = *(Words4 *)L->top;
        g = &clvalue(o)->l.g;
        LUA2_ADDREF(g);
        g = (TValue *)&old;
        LUA2_RELEASE(L, g);
    }
    setnilvalue(L, L->top);
    return res;
}

/* Release and clear the stack slots [o, lim). */
LUA2_FORCEINLINE void clear_range(lua_State *L, StkId o, StkId lim)
{
    for (; o < lim;) setnilvalue(L, o++);
}

/* lua_settop: slots dropped from the top are released and cleared. */
void lua3_lua_settop_888246A8(lua_State *L, int idx)
{
    if (idx >= 0) {
        while (L->top < L->base + idx) setnilvalue(L, L->top++);
        clear_range(L, L->base + idx, L->top);
        L->top = L->base + idx;
    } else {
        StkId o = L->top + idx + 1;
        if (o < L->base) o = L->base;
        clear_range(L, o, L->top);
        L->top += idx + 1;
    }
}
