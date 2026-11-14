/* Swing_DLL.xex 0x8882A258-0x8882A36C, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d9q_lua.h"

extern const double g_ts4_script_constants[];
extern const char lbl_880C1320[];

/* string.sub(s, i [, j]) */
int ts4_str_sub_8882A258(lua_State *L)
{
    int l;
    const char *s;
    int start, end, pos;
    { u32 ll; s = lib3_luaL_checklstring_8882EB20(L, 1, &ll); l = ll; }
    pos = (int)ts4_lua_opt_number_default_8882EA98(L, 2);
    start = (pos >= 0) ? pos : pos + l + 1;
    end = (int)(ts9_isnoneornil(L, 3) ? g_ts4_script_constants[294] : ts4_lua_opt_number_default_8882EA98(L, 3));
    if (end < 0) end += l + 1;
    if (start < 1) start = 1;
    if (end > l) end = l;
    if (start <= end)
        ts4_lua_pushlstring_88823FC0(L, s + start - 1, end - start + 1);
    else
        ts4_lua_pushlstring_88823FC0(L, lbl_880C1320, 0);
    return 1;
}
