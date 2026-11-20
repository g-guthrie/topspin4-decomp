/* Derived from Lua 5.0.2 ltablib.c (MIT); see THIRD_PARTY_NOTICES.md */
#include "cx19_lua.h"

/* luaB_getn */
int cx19_tab_getn_889CEFF8(lua_State *L)
{
    CX19_CHECKTABLE(L, 1);
    ts4_lua_pushnumber_888240B8(L, (lua_Number)lib3_luaL_getn_8882DF10(L, 1));
    return 1;
}

/* luaB_setn */
int cx19_tab_setn_889CEF70(lua_State *L)
{
    CX19_CHECKTABLE(L, 1);
    lib3_luaL_setn_8882E008(L, (int)ts4_lua_opt_number_default_8882EA98(L, 2));
    return 0;
}

/* luaB_foreach */
int cx19_tab_foreach_889CF088(lua_State *L)
{
    CX19_CHECKTABLE(L, 1);
    CX19_CHECKFUNC(L, 2);
    ts4_lua_pushnil_88824188(L);
    for (;;) {
        if (ts4_lua_next_first_88824B68(L) == 0) return 0;
        ts4_lua_pushvalue_88824248(L, 2);
        ts4_lua_pushvalue_88824248(L, -3);
        ts4_lua_pushvalue_88824248(L, -3);
        lua_call(L, 2, 1);
        CX19_RET1_IF_NOTNIL(L)
        lua_pop(L, 2);
    }
}

/* luaB_foreachi */
int cx19_tab_foreachi_889CF1C8(lua_State *L)
{
    int i;
    int n;
    CX19_CHECKTABLE(L, 1);
    n = lib3_luaL_getn_8882DF10(L, 1);
    CX19_CHECKFUNC(L, 2);
    for (i = 1; i <= n; i++) {
        ts4_lua_pushvalue_88824248(L, 2);
        ts4_lua_pushnumber_888240B8(L, (lua_Number)i);
        ts4_lua_rawgeti_888239E0(L, 1, i);
        lua_call(L, 2, 1);
        CX19_RET1_IF_NOTNIL(L)
        lua_pop(L, 1);
    }
    return 0;
}

/* luaB_tinsert */
int cx19_tab_tinsert_889CEE68(lua_State *L)
{
    int v = ts4_lua_gettop(L);
    int n;
    int pos;
    CX19_CHECKTABLE(L, 1);
    n = lib3_luaL_getn_8882DF10(L, 1) + 1;
    if (v == 2)
        pos = n;
    else {
        pos = (int)ts4_lua_opt_number_default_8882EA98(L, 2);
        if (pos > n) n = pos;
        v = 3;
    }
    lib3_luaL_setn_8882E008(L, n);
    while (--n >= pos) {
        ts4_lua_rawgeti_888239E0(L, 1, n);
        ts4_lua_rawseti_88823320(L, 1, n + 1);
    }
    ts4_lua_pushvalue_88824248(L, v);
    ts4_lua_rawseti_88823320(L, 1, pos);
    return 0;
}

/* luaB_tremove */
int cx19_tab_tremove_889CF4D0(lua_State *L)
{
    int n;
    int pos;
    CX19_CHECKTABLE(L, 1);
    n = lib3_luaL_getn_8882DF10(L, 1);
    pos = (int)(ts4_lua_type(L, 2) <= 0 ? (lua_Number)n : ts4_lua_opt_number_default_8882EA98(L, 2));
    if (n <= 0) return 0;
    lib3_luaL_setn_8882E008(L, n - 1);
    ts4_lua_rawgeti_888239E0(L, 1, pos);
    for (; pos < n; pos++) {
        ts4_lua_rawgeti_888239E0(L, 1, pos + 1);
        ts4_lua_rawseti_88823320(L, 1, pos);
    }
    ts4_lua_pushnil_88824188(L);
    ts4_lua_rawseti_88823320(L, 1, n);
    return 1;
}

/* luaB_sort */
int cx19_tab_sort_889CED40(lua_State *L)
{
    int n;
    CX19_CHECKTABLE(L, 1);
    n = lib3_luaL_getn_8882DF10(L, 1);
    if (!lib3_lua_checkstack_88822028(L, 40)) lib3_luaL_error_8882E5F0(L, lbl_880E1C84, lbl_880C1320);
    if (ts4_lua_type(L, 2) > 0) CX19_CHECKFUNC(L, 2);
    lua3_lua_settop_888246A8(L, 2);
    lt1_lua_auxsort_889CE9E0(L, 1, n);
    return 0;
}
