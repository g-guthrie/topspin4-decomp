/* Derived from Lua 5.0.2 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef CX19_LUA_H
#define CX19_LUA_H
#include "d3d_lua.h"

typedef Ts4LuaState lua_State;
typedef Ts4LuaValue TValue;
typedef double lua_Number;

extern const char *lbl_880C9684[];
TS4_NORETURN extern void lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern int lib3_luaL_getn_8882DF10(lua_State *L, int t);
extern void lib3_luaL_setn_8882E008(lua_State *L, int n);
extern double ts4_lua_opt_number_default_8882EA98(lua_State *L, int narg);
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);

/* luaL_checktype(L, n, LUA_TTABLE) with lua_type inlined */
#define CX19_CHECKTABLE(L, n) \
    if (ts4_lua_type((L), (n)) != 5) lib3_luaL_typerror_8882E950((L), (n), lbl_880C9684[5])


extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern int ts4_lua_next_first_88824B68(lua_State *L);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern void lua2_luaD_call_8881E258(lua_State *L, TValue *func, int nresults);
extern void ts4_lua_rawgeti_888239E0(lua_State *L, int idx, int n);
extern void ts4_lua_rawseti_88823320(lua_State *L, int idx, int n);

#define CX19_CHECKFUNC(L, n) \
    if (ts4_lua_type((L), (n)) != 6) lib3_luaL_typerror_8882E950((L), (n), lbl_880C9684[6])
#define lua_pop(L, n) lua3_lua_settop_888246A8((L), -(n)-1)
#define lua_call(L, na, nr) lua2_luaD_call_8881E258((L), (L)->top - ((na) + 1), (nr))

/* if (!lua_isnil(L, -1)) return 1; an invalid slot is not nil */
#define CX19_RET1_IF_NOTNIL(L) \
    { \
        TValue *o_ = (L)->top - 1; \
        if (o_ == 0 || o_->tt != 0) return 1; \
    }


typedef struct Cx19Buffer {
    char *p;
    int lvl;
    int wide;
    lua_State *L;
    char buffer[0x200];
} Cx19Buffer;

extern int lib3_lua_checkstack_88822028(lua_State *L, int size);
extern const char *lib3_luaL_optlstring_8882EBF0(lua_State *L, int narg, const char *def, unsigned int *len);
extern void lib3_luaL_addvalue_8882E3E8(Cx19Buffer *B);
extern void lib3_luaL_addlstring_8882E828(Cx19Buffer *B, const char *s, unsigned int l);
extern int lib3_emptybuffer_8882DE88(Cx19Buffer *B);
extern void ts4_lua_concat_88822DB0(lua_State *L, int n);
TS4_NORETURN extern void lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *extramsg);
extern char lbl_880C1320[];
extern char lbl_880E1C84[];
extern char lbl_880E24EC[];
extern const double g_ts4_script_constants[];
extern void lt1_lua_auxsort_889CE9E0(lua_State *L, int l, int u);


/* luaL_error body visible in the unit: the caller's frame depends on it (see lt1_lua_auxsort.c). */
#ifdef _MSC_VER
typedef char *cx19_va_list;
void __cdecl __va_start(cx19_va_list *ap, ...);
#define CX19_VA_START(ap, v) __va_start(&ap, v)
#define CX19_INLINE static __inline
#else
typedef char *cx19_va_list;
#define CX19_VA_START(ap, v) ((ap) = (char *)0, (void)(v))
#define CX19_INLINE static inline
#endif
extern void lib3_luaL_where_8882E2D0(lua_State *L, int level);
extern const char *lua3_luaO_pushvfstring_888188F8(lua_State *L, const char *fmt, cx19_va_list argp);
extern void fn_8880FA80(lua_State *L, int total, int last);
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L);
TS4_NORETURN extern int lua3_luaG_errormsg_8881F900(lua_State *L);
#define CX19_CHECK_GC(L) \
    if (((Ts4LuaGlobal *)(L)->l_G)->nblocks >= ((Ts4LuaGlobal *)(L)->l_G)->GCthreshold) \
        ts4_call_seq_fn_8881C130_8881C200(L)
CX19_INLINE int lib3_luaL_error_8882E5F0(lua_State *L, const char *fmt, ...)
{
    cx19_va_list argp;
    CX19_VA_START(argp, fmt);
    lib3_luaL_where_8882E2D0(L, 1);
    CX19_CHECK_GC(L);
    lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    CX19_CHECK_GC(L);
    fn_8880FA80(L, 2, (int)(L->top - L->base) - 1);
    L->top--;
    return lua3_luaG_errormsg_8881F900(L);
}

#endif
