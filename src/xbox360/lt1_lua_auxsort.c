/* Derived from Lua 5.0.2 ltablib.c (MIT); see THIRD_PARTY_NOTICES.md */
/* Family LT1: ltablib.c auxsort, verified with the LTCG route (tools/fn_check_ltcg.py, docs/ltcg-route.md).
 * The plain per-object compile gives a 0x90-byte frame; the original's 0xA0 frame appears only when
 * luaL_error's real definition (lib3_lua_auxlib.c) is in the same /LTCG link. */
#include "lua3.h"

extern void ts4_lua_rawgeti_888239E0(lua_State *L, int idx, int n);
extern void ts4_lua_rawseti_88823320(lua_State *L, int idx, int n);
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern LUA3_NORETURN int lib3_luaL_error_8882E5F0(lua_State *L, const char *fmt, ...);
extern int lb1_lua_sort_comp_889CE860(lua_State *L, int a, int b);
extern const char lbl_880E2508[]; /* "invalid order function for sorting" */

#define lua_pop(L, n) lua3_lua_settop_888246A8(L, -(n)-1)

#define set2(L, i, j) \
    do {              \
        ts4_lua_rawseti_88823320(L, 1, i); \
        ts4_lua_rawseti_88823320(L, 1, j); \
    } while (0)

/* Quicksort of t[l..u] (ltablib.c auxsort), Swing_DLL.xex 0x889CE9E0. */
void lt1_lua_auxsort_889CE9E0(lua_State *L, int l, int u)
{
    while (l < u) {
        int i, j;
        ts4_lua_rawgeti_888239E0(L, 1, l);
        ts4_lua_rawgeti_888239E0(L, 1, u);
        if (lb1_lua_sort_comp_889CE860(L, -1, -2))
            set2(L, l, u);
        else
            lua_pop(L, 2);
        if (u - l == 1) break;
        i = (l + u) / 2;
        ts4_lua_rawgeti_888239E0(L, 1, i);
        ts4_lua_rawgeti_888239E0(L, 1, l);
        if (lb1_lua_sort_comp_889CE860(L, -2, -1))
            set2(L, i, l);
        else {
            lua_pop(L, 1);
            ts4_lua_rawgeti_888239E0(L, 1, u);
            if (lb1_lua_sort_comp_889CE860(L, -1, -2))
                set2(L, i, u);
            else
                lua_pop(L, 2);
        }
        if (u - l == 2) break;
        ts4_lua_rawgeti_888239E0(L, 1, i);
        ts4_lua_pushvalue_88824248(L, -1);
        ts4_lua_rawgeti_888239E0(L, 1, u - 1);
        set2(L, i, u - 1);
        i = l;
        j = u - 1;
        for (;;) {
            while (ts4_lua_rawgeti_888239E0(L, 1, ++i), lb1_lua_sort_comp_889CE860(L, -1, -2)) {
                if (i > u) lib3_luaL_error_8882E5F0(L, lbl_880E2508);
                lua_pop(L, 1);
            }
            while (ts4_lua_rawgeti_888239E0(L, 1, --j), lb1_lua_sort_comp_889CE860(L, -3, -1)) {
                if (j < l) lib3_luaL_error_8882E5F0(L, lbl_880E2508);
                lua_pop(L, 1);
            }
            if (j < i) {
                lua_pop(L, 3);
                break;
            }
            set2(L, i, j);
        }
        ts4_lua_rawgeti_888239E0(L, 1, u - 1);
        ts4_lua_rawgeti_888239E0(L, 1, i);
        set2(L, u - 1, i);
        if (i - l < u - i) {
            j = l;
            i = i - 1;
            l = i + 2;
        } else {
            j = i + 1;
            i = u;
            u = j - 2;
        }
        lt1_lua_auxsort_889CE9E0(L, j, i);
    }
}
