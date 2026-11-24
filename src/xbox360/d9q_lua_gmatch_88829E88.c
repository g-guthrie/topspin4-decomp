/* Swing_DLL.xex 0x88829E88-0x88829F30, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d9q_lua.h"

extern const char *lib3_lua_tostring_88822888(lua_State *L, int idx);
extern void lib3_lua_pushcclosure_88823E00(lua_State *L, void *fn, int n);
extern int lib3_gfind_aux_88828338(lua_State *L);
extern const double g_ts4_script_constants[];

/* string.gmatch: keep subject, pattern and a position as upvalues of the iterator. */
int ts4_str_gmatch_88829E88(lua_State *L)
{
    if (lib3_lua_tostring_88822888(L, 1) == 0) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[4]);
    if (lib3_lua_tostring_88822888(L, 2) == 0) lib3_luaL_typerror_8882E950(L, 2, lbl_880C9684[4]);
    lua3_lua_settop_888246A8(L, 2);
    ts4_lua_pushnumber_888240B8(L, g_ts4_script_constants[11]);
    lib3_lua_pushcclosure_88823E00(L, (void *)lib3_gfind_aux_88828338, 3);
    return 1;
}
