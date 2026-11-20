/* Swing_DLL.xex Lua stack-index helpers shared by the d9q units. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef D9Q_LUA_H
#define D9Q_LUA_H

#include "d8q_lua.h"

#ifdef _MSC_VER
#define TS9_INLINE static __forceinline
#else
#define TS9_INLINE static inline
#endif

/* Value at a positive stack index, or null when the index is past the top. */
TS9_INLINE TValue *ts9_index(lua_State *L, int n)
{
    TValue *o = L->base + (n - 1);
    return (o < L->top && o != 0) ? o : 0;
}

/* lua_type for a positive index (-1 for none). */
TS9_INLINE int ts9_type(lua_State *L, int n)
{
    TValue *o = L->base + (n - 1);
    return (o < L->top && o != 0) ? o->tt : -1;
}

TS9_INLINE int ts9_isnoneornil(lua_State *L, int n)
{
    TValue *o = L->base + (n - 1);
    return o >= L->top || o == 0 || o->tt <= 0;
}

TS9_INLINE int ts9_toboolean(lua_State *L, int n)
{
    TValue *o = L->base + (n - 1);
    if (!(o < L->top && o != 0)) return 0;
    if (o->tt == 0) return 0;
    return !(o->tt == 1 && o->u.b == 0);
}

extern const char *lib3_luaL_checklstring_8882EB20(lua_State *L, int narg, u32 *len);
extern TS4_NORETURN int lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *msg);
extern TS4_NORETURN int lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern int lib3_lua_type_88822738(lua_State *L, int idx);
extern double ts4_lua_opt_number_default_8882EA98(lua_State *L, int narg);
extern const char *lbl_880C9684[];
extern const char lbl_880E1C98[];

#endif
