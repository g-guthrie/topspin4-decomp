/* Derived from Lua 5.0.2 ltablib.c (MIT); see THIRD_PARTY_NOTICES.md */
/* Family LB1: ltablib.c table.sort helpers (sort_comp and auxsort). */
#include "lua3.h"

extern void ts4_lua_rawgeti_888239E0(lua_State *L, int idx, int n);
extern void ts4_lua_rawseti_88823320(lua_State *L, int idx, int n);
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nresults);
extern int lib3_lua_lessthan_888224D8(lua_State *L, int index1, int index2);
extern LUA3_NORETURN int lib3_luaL_error_8882E5F0(lua_State *L, const char *fmt, ...);
extern const char lbl_880E2508[]; /* "invalid order function for sorting" */

/* lua_pop(L, n) */
#define lua_pop(L, n) lua3_lua_settop_888246A8(L, -(n)-1)

/* Compare the stack values a and b with the sort function in argument 2 (or the < operator), Swing_DLL.xex 0x889CE860 */
/* luaA_indexAcceptable for idx > 0 */
LUA2_FORCEINLINE StkId lb1_index_acceptable(lua_State *L, int idx)
{
    StkId o = L->base + (idx - 1);
    if (o >= L->top) return 0;
    return o;
}

LUA2_FORCEINLINE int lb1_lua_type(lua_State *L, int idx)
{
    StkId o = lb1_index_acceptable(L, idx);
    return (o == 0) ? -1 : ttype(o);
}

LUA2_FORCEINLINE int lb1_lua_toboolean(lua_State *L, int idx)
{
    StkId o = L->top + idx;
    return (o != 0) && !(ttype(o) == LUA2_TNIL || (ttype(o) == LUA2_TBOOLEAN && o->value.b == 0));
}

LUA2_NOINLINE int lb1_lua_sort_comp_889CE860(lua_State *L, int a, int b)
{
    if (lb1_lua_type(L, 2) != LUA2_TNIL) {
        int res;
        ts4_lua_pushvalue_88824248(L, 2);
        ts4_lua_pushvalue_88824248(L, a - 1);
        ts4_lua_pushvalue_88824248(L, b - 2);
        lua2_luaD_call_8881E258(L, L->top - 3, 1);
        res = lb1_lua_toboolean(L, -1);
        lua_pop(L, 1);
        return res;
    }
    return lib3_lua_lessthan_888224D8(L, a, b);
}

#define set2(L, i, j) \
    do {              \
        ts4_lua_rawseti_88823320(L, 1, i); \
        ts4_lua_rawseti_88823320(L, 1, j); \
    } while (0)

/* Quicksort of t[l..u] (ltablib.c auxsort), Swing_DLL.xex 0x889CE9E0. NOT MATCHED: only the stack frame is 0x10 bytes smaller than the original. */
LUA2_LOCAL void lb1_lua_auxsort_889CE9E0(lua_State *L, int l, int u)
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
        lb1_lua_auxsort_889CE9E0(L, j, i);
    }
}
