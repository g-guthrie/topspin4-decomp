/* Derived from Lua 5.0.2 lmathlib.c (MIT); see THIRD_PARTY_NOTICES.md */
#include "cx19_lua.h"

extern double fn_88569838(double x, int exp); /* ldexp */

/* math_max */
int cx19_math_max_889CF8C0(lua_State *L)
{
    int n = ts4_lua_gettop(L);
    lua_Number dmax = ts4_lua_opt_number_default_8882EA98(L, 1);
    int i;
    for (i = 2; i <= n; i++) {
        lua_Number d = ts4_lua_opt_number_default_8882EA98(L, i);
        if (d > dmax) dmax = d;
    }
    ts4_lua_pushnumber_888240B8(L, dmax);
    return 1;
}

/* math_min */
int cx19_math_min_889CF940(lua_State *L)
{
    int n = ts4_lua_gettop(L);
    lua_Number dmin = ts4_lua_opt_number_default_8882EA98(L, 1);
    int i;
    for (i = 2; i <= n; i++) {
        lua_Number d = ts4_lua_opt_number_default_8882EA98(L, i);
        if (d < dmin) dmin = d;
    }
    ts4_lua_pushnumber_888240B8(L, dmin);
    return 1;
}

/* math_ldexp */
int cx19_math_ldexp_889CF9C0(lua_State *L)
{
    ts4_lua_pushnumber_888240B8(L, fn_88569838(ts4_lua_opt_number_default_8882EA98(L, 1), (int)ts4_lua_opt_number_default_8882EA98(L, 2)));
    return 1;
}

extern void lib3_luaL_openlib_8882E0D8(lua_State *L, const char *libname, const void *l);
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, unsigned int len);
extern void ts4_lua_settable_88823580(lua_State *L, int idx);
extern void lib3_lua_pushcclosure_88823E00(lua_State *L, int (*fn)(lua_State *), int n);
extern int ts4_binary_889CFBD8(lua_State *L); /* math_pow */
extern const char lbl_880E238C[]; /* "math" */
extern const char lbl_880E2394[]; /* "pi" */
extern const char lbl_880E2398[]; /* "__pow" */
extern const char lbl_880C9A60[]; /* mathlib luaL_reg table */
extern const double lbl_880D0E70; /* PI */

/* luaopen_math */
int cx19_luaopen_math_889CFF78(lua_State *L)
{
    lib3_luaL_openlib_8882E0D8(L, lbl_880E238C, lbl_880C9A60);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E2394, 2);
    ts4_lua_pushnumber_888240B8(L, lbl_880D0E70);
    ts4_lua_settable_88823580(L, -3);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E2398, 5);
    lib3_lua_pushcclosure_88823E00(L, ts4_binary_889CFBD8, 0);
    ts4_lua_settable_88823580(L, -10001);
    return 1;
}
