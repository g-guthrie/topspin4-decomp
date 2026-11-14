/* Derived from Lua 5.0.2 lbaselib.c (MIT); see THIRD_PARTY_NOTICES.md */
/* lbaselib.c: error, ipairs and function environments (lapi calls inlined by LTCG). */
#include "lua3.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
extern int strcmp(const char *a, const char *b);
#pragma intrinsic(strlen, strcmp)
#else
#include <string.h>
#endif

#define LUA_GLOBALSINDEX (-10001)
#ifdef _MSC_VER
#define LUA3_UNREACHABLE() __assume(0)
#else
#define LUA3_UNREACHABLE() __builtin_unreachable()
#endif

extern double ts4_lua_opt_number_default_8882EA98(lua_State *L, int narg); /* luaL_checknumber */
extern LUA3_NORETURN void lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);
extern LUA3_NORETURN void lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *extramsg);
extern void lib3_luaL_where_8882E2D0(lua_State *L, int level);
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len);
extern void ts4_lua_rawget_88823AE8(lua_State *L, int idx);
extern void ts4_lua_rawgeti_888239E0(lua_State *L, int idx, int n);
extern void ts4_lua_replace_88824340(lua_State *L, int idx);
extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern int lib3_lua_isnumber_88822650(lua_State *L, int idx);
extern int lib3_has_fenv_8882B4F8(lua_State *L);
extern void lua3_lua_settop_888246A8(lua_State *L, int idx);
extern int lua3_lua_setfenv_88823068(lua_State *L); /* lua_setfenv(L, -2) */
extern int lua3_lua_getstack_8881EED0(lua_State *L, int level, lua_Debug *ar);
extern int lua3_lua_getinfo_8881FF18(lua_State *L, const char *what, lua_Debug *ar);
extern void fn_8880FA80(lua_State *L, int total, int last); /* luaV_concat */
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L); /* luaC_collectgarbage */
extern const char *lbl_880C9684[]; /* luaT_typenames */
extern const double g_ts4_script_constants[]; /* [11] = 0.0, [15] = 1.0 */
extern char lbl_880E1C98[]; /* "value expected" */
extern char lbl_880E1E9C[]; /* "level must be non-negative" */
extern char lbl_880E1EB8[]; /* "invalid level" */
extern char lbl_880E1EC8[]; /* "f" */
extern char lbl_880E1ECC[]; /* "no function environment for tail call at level %d" */
extern char lbl_880E1F08[]; /* "`setfenv' cannot change a protected environment" */
extern char lbl_880E1F38[]; /* "`setfenv' cannot change environment of given function" */
extern char lbl_880E1F78[]; /* "ipairs" */

LUA2_FORCEINLINE void lua_concat_(lua_State *L, int n)
{
    if (G(L)->nblocks >= G(L)->GCthreshold) ts4_call_seq_fn_8881C130_8881C200(L);
    fn_8880FA80(L, n, (int)(L->top - L->base) - 1);
    L->top -= (n - 1);
}

/* Same-TU copy of luaL_error: the callers' frames depend on its variadic body being visible. */
LUA2_LOCAL LUA3_NORETURN void lib3_luaL_error_8882E5F0(lua_State *L, const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    lib3_luaL_where_8882E2D0(L, 1);
    if (G(L)->nblocks >= G(L)->GCthreshold) ts4_call_seq_fn_8881C130_8881C200(L);
    lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    va_end(argp);
    lua_concat_(L, 2);
    lua3_luaG_errormsg_8881F900(L);
    LUA3_UNREACHABLE();
}

LUA2_FORCEINLINE StkId index_acceptable(lua_State *L, int idx)
{
    if (idx > 0) {
        StkId o = L->base + (idx - 1);
        if (o >= L->top) return 0;
        return o;
    }
    return L->top + idx;
}

LUA2_FORCEINLINE int lua_type_(lua_State *L, int idx)
{
    StkId o = index_acceptable(L, idx);
    return (o == 0) ? -1 : ttype(o);
}

LUA2_FORCEINLINE int lua_isstring_(lua_State *L, int idx)
{
    int t = lua_type_(L, idx);
    return t == LUA2_TSTRING || t == LUA2_TNUMBER || t == LUA2_TWSTRING;
}

/* luaL_optint(L, narg, 1) */
LUA2_FORCEINLINE int optint_1(lua_State *L, int narg)
{
    return (int)(lua_type_(L, narg) <= LUA2_TNIL ? g_ts4_script_constants[15]
                                                  : ts4_lua_opt_number_default_8882EA98(L, narg));
}

LUA2_FORCEINLINE void checktype_table(lua_State *L, int narg)
{
    if (lua_type_(L, narg) != LUA2_TTABLE) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[LUA2_TTABLE]);
}

/* luaB_error */
int lua3_luaB_error_8882D480(lua_State *L)
{
    int level = optint_1(L, 2);
    if (lua_type_(L, 1) == -1) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1C98);
    if (!lua_isstring_(L, 1) || level == 0)
        ts4_lua_pushvalue_88824248(L, 1);
    else {
        lib3_luaL_where_8882E2D0(L, level);
        ts4_lua_pushvalue_88824248(L, 1);
        lua_concat_(L, 2);
    }
    lua3_luaG_errormsg_8881F900(L); /* lua_error */
    LUA3_UNREACHABLE();
}

/* getfunc */
void lua3_getfunc_8882D360(lua_State *L)
{
    if (lua_type_(L, 1) == LUA2_TFUNCTION)
        ts4_lua_pushvalue_88824248(L, 1);
    else {
        lua_Debug ar;
        int level = optint_1(L, 1);
        if (!(level >= 0)) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1E9C);
        if (lua3_lua_getstack_8881EED0(L, level, &ar) == 0) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1EB8);
        lua3_lua_getinfo_8881FF18(L, lbl_880E1EC8, &ar);
        if (lua_type_(L, -1) == LUA2_TNIL) lib3_luaL_error_8882E5F0(L, lbl_880E1ECC, level);
    }
}

/* luaB_setfenv */
int lua3_luaB_setfenv_8882D8D0(lua_State *L)
{
    checktype_table(L, 2);
    lua3_getfunc_8882D360(L);
    if (lib3_has_fenv_8882B4F8(L)) lib3_luaL_error_8882E5F0(L, lbl_880E1F08);
    lua3_lua_settop_888246A8(L, -3);
    ts4_lua_pushvalue_88824248(L, 2);
    if (lib3_lua_isnumber_88822650(L, 1) && ts4_lua_tonumber_88822420(L, 1) == g_ts4_script_constants[11])
        ts4_lua_replace_88824340(L, LUA_GLOBALSINDEX);
    else if (lua3_lua_setfenv_88823068(L) == 0)
        lib3_luaL_error_8882E5F0(L, lbl_880E1F38);
    return 0;
}

#if 0 /* near miss: the step's fadd takes its operands in the other order (f0, f1) */
/* luaB_ipairs */
int lua3_luaB_ipairs_8882CC08(lua_State *L)
{
    double n = ts4_lua_tonumber_88822420(L, 2);
    double zero;
    checktype_table(L, 1);
    zero = g_ts4_script_constants[11];
    if (n == zero && lua_type_(L, 2) == -1) { /* `for' start? */
        ts4_lua_pushlstring_88823FC0(L, lbl_880E1F78, 6);
        ts4_lua_rawget_88823AE8(L, LUA_GLOBALSINDEX); /* return generator, */
        ts4_lua_pushvalue_88824248(L, 1);              /* state, */
        ts4_lua_pushnumber_888240B8(L, zero); /* and initial value */
        return 3;
    } else { /* `for' step */
        n = g_ts4_script_constants[15] + n;
        ts4_lua_pushnumber_888240B8(L, n);
        ts4_lua_rawgeti_888239E0(L, 1, (int)n);
        return (lua_type_(L, -1) == LUA2_TNIL) ? 0 : 2;
    }
}
#endif

extern void ts4_if_call_seq_fn_88822738_8882E8A0(lua_State *L, int narg); /* luaL_checkany */
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern const u16 *fn_888348A0(lua_State *L, int idx);              /* lua_towstring */
extern const char *lib3_lua_tostring_88822888(lua_State *L, int idx);
extern u32 ts4_tailcall_fn_88564828_88564B08(const char *s, char **endptr, int base); /* strtoul */
extern const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void);                /* __pctype_func */
extern char lbl_880E1E40[]; /* "base out of range" */
#define lisspace(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[(c)] & 8)

/* luaL_optint(L, narg, 10) */
LUA2_FORCEINLINE int optint_10(lua_State *L, int narg)
{
    return (int)(lua_type_(L, narg) <= LUA2_TNIL ? g_ts4_script_constants[17]
                                                  : ts4_lua_opt_number_default_8882EA98(L, narg));
}

LUA2_FORCEINLINE u32 wcslen_(const u16 *s)
{
    const u16 *e = s;
    while (*e) e++;
    return (u32)(e - s);
}

/* luaL_checklwstring(L, narg, NULL) */
LUA2_FORCEINLINE const u16 *checkwstring_(lua_State *L, int narg)
{
    const u16 *s = fn_888348A0(L, narg);
    if (!s) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[LUA2_TWSTRING]);
    return s;
}

/* luaB_tonumber, extended to wide strings (narrowed to bytes before strtoul) */
int lua3_luaB_tonumber_8882D5C8(lua_State *L)
{
    int base = optint_10(L, 2);
    if (base == 10) { /* standard conversion */
        ts4_if_call_seq_fn_88822738_8882E8A0(L, 1);
        if (lib3_lua_isnumber_88822650(L, 1)) {
            ts4_lua_pushnumber_888240B8(L, ts4_lua_tonumber_88822420(L, 1));
            return 1;
        }
    } else if (lua_type_(L, 1) == LUA2_TWSTRING) {
        const u16 *s1 = checkwstring_(L, 1);
        char buf[100];
        char *s2;
        u32 n;
        if (!(2 <= base && base <= 36)) lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1E40);
        if (wcslen_(s1) > 99) {
            ts4_lua_pushnil_88824188(L);
            return 1;
        }
        {
            char *d = buf;
            const u16 *p = s1;
            while (*p) *d++ = (char)*p++;
            *d = '\0';
        }
        n = ts4_tailcall_fn_88564828_88564B08(buf, &s2, base);
        if (buf != s2) { /* at least one valid digit? */
            while (lisspace((unsigned char)(*s2))) s2++; /* skip trailing spaces */
            if (*s2 == '\0') { /* no invalid trailing characters? */
                ts4_lua_pushnumber_888240B8(L, (double)n);
                return 1;
            }
        }
    } else {
        const char *s1 = lib3_lua_tostring_88822888(L, 1);
        char *s2;
        u32 n;
        if (!s1) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[LUA2_TSTRING]);
        if (!(2 <= base && base <= 36)) lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1E40);
        n = ts4_tailcall_fn_88564828_88564B08(s1, &s2, base);
        if (s1 != s2) { /* at least one valid digit? */
            while (lisspace((unsigned char)(*s2))) s2++; /* skip trailing spaces */
            if (*s2 == '\0') { /* no invalid trailing characters? */
                ts4_lua_pushnumber_888240B8(L, (double)n);
                return 1;
            }
        }
    }
    ts4_lua_pushnil_88824188(L); /* else not a number */
    return 1;
}

/* luaL_Buffer: write pointer, level count, wide flag, owner state, storage. */
typedef struct Buffer {
    char *p;
    int lvl;
    int wide;
    lua_State *L;
    char buffer[0x200];
} Buffer;

extern int lib3_luaL_callmeta_8882E560(lua_State *L); /* luaL_callmeta(L, 1, "__tostring") */
extern const void *lib3_lua_topointer_1_888227A8(lua_State *L);
extern void *lib3_lua_touserdata_88822230(lua_State *L, int idx);
extern int ts4_lua_toboolean_88822398(lua_State *L, int idx);
extern u32 lib3_lua_strlen_888222F0(lua_State *L, int idx);
extern int fn_885635D0(char *buffer, const char *format, ...); /* sprintf */
extern int lib3_emptybuffer_8882DE88(Buffer *B);
extern void lib3_adjuststack_8882DBA8(Buffer *B);
extern void ts4_lua_concat_88822DB0(lua_State *L, int n);
extern char g_ts4_true_string[]; /* "true" */
extern char lbl_880D1B30[];      /* "false" */
extern char lbl_880C1320[];      /* "" */
extern char lbl_880E1FB8[];      /* "table: %p" */
extern char lbl_880E1FC4[];      /* "function: %p" */
extern char lbl_880E1FD4[];      /* "userdata: %p" */
extern char lbl_880E1FE4[];      /* "thread: %p" */
extern char lbl_880E1FF0[];      /* "nil" */

LUA2_FORCEINLINE void pushstring_(lua_State *L, const char *s)
{
    if (s == 0)
        ts4_lua_pushnil_88824188(L);
    else
        ts4_lua_pushlstring_88823FC0(L, s, strlen(s));
}

LUA2_FORCEINLINE lua_State *tothread_(lua_State *L, int idx)
{
    StkId o = index_acceptable(L, idx);
    return (o == 0 || ttype(o) != LUA2_TTHREAD) ? 0 : (lua_State *)o->value.gc;
}

/* luaB_tostring; wide strings are narrowed byte by byte */
int lua3_luaB_tostring_8882C1A0(lua_State *L)
{
    char buff[128];
    if (lua_type_(L, 1) == -1) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1C98);
    if (lib3_luaL_callmeta_8882E560(L)) /* is there a metafield? */
        return 1;                       /* use its value */
    switch (lua_type_(L, 1)) {
    case LUA2_TNUMBER:
        pushstring_(L, lib3_lua_tostring_88822888(L, 1));
        return 1;
    case LUA2_TSTRING:
        ts4_lua_pushvalue_88824248(L, 1);
        return 1;
    case LUA2_TWSTRING: {
        const u16 *s = fn_888348A0(L, 1);
        u32 len = lib3_lua_strlen_888222F0(L, 1);
        u32 i;
        Buffer b;
        if (len == 0) {
            ts4_lua_pushlstring_88823FC0(L, lbl_880C1320, 0);
            return 1;
        }
        b.L = L;
        b.p = b.buffer;
        b.wide = 0;
        b.lvl = 0;
        for (i = 0; i < len; i++) {
            if (b.p >= b.buffer + 0x200 && lib3_emptybuffer_8882DE88(&b)) lib3_adjuststack_8882DBA8(&b);
            *b.p++ = (char)s[i];
        }
        lib3_emptybuffer_8882DE88(&b);
        ts4_lua_concat_88822DB0(b.L, b.lvl);
        return 1;
    }
    case LUA2_TBOOLEAN:
        pushstring_(L, ts4_lua_toboolean_88822398(L, 1) ? g_ts4_true_string : lbl_880D1B30);
        return 1;
    case LUA2_TTABLE:
        fn_885635D0(buff, lbl_880E1FB8, lib3_lua_topointer_1_888227A8(L));
        break;
    case LUA2_TFUNCTION:
        fn_885635D0(buff, lbl_880E1FC4, lib3_lua_topointer_1_888227A8(L));
        break;
    case LUA2_TUSERDATA:
    case LUA2_TLIGHTUSERDATA:
        fn_885635D0(buff, lbl_880E1FD4, lib3_lua_touserdata_88822230(L, 1));
        break;
    case LUA2_TTHREAD:
        fn_885635D0(buff, lbl_880E1FE4, (void *)tothread_(L, 1));
        break;
    case LUA2_TNIL:
        ts4_lua_pushlstring_88823FC0(L, lbl_880E1FF0, 3);
        return 1;
    }
    pushstring_(L, buff);
    return 1;
}

typedef struct LoadS {
    const char *s;
    u32 size;
} LoadS;

extern int lib3_lua_load_buffer_88824CF8(lua_State *L, LoadS *ls, const char *chunkname); /* lua_load(L, getS, ls, name) */
extern void ts4_lua_insert_88824438(lua_State *L, int idx);

/* Same-TU copy of luaL_checklstring: callers rely on LTCG knowing it does not retain len. */
LUA2_LOCAL const char *lib3_luaL_checklstring_8882EB20(lua_State *L, int narg, u32 *len)
{
    const char *s = lib3_lua_tostring_88822888(L, narg);
    if (!s) lib3_luaL_typerror_8882E950(L, narg, lbl_880C9684[LUA2_TSTRING]);
    if (len) *len = lib3_lua_strlen_888222F0(L, narg);
    return s;
}

LUA2_FORCEINLINE int load_aux(lua_State *L, int status)
{
    if (status == 0) /* OK? */
        return 1;
    else {
        ts4_lua_pushnil_88824188(L);
        ts4_lua_insert_88824438(L, -2); /* put before error message */
        return 2;                       /* return nil plus error message */
    }
}

LUA2_FORCEINLINE int loadbuffer_(lua_State *L, const char *buff, u32 size, const char *name)
{
    LoadS ls;
    ls.s = buff;
    ls.size = size;
    return lib3_lua_load_buffer_88824CF8(L, &ls, name);
}

/* luaB_loadstring */
int lua3_luaB_loadstring_8882DA28(lua_State *L)
{
    u32 l;
    const char *s = lib3_luaL_checklstring_8882EB20(L, 1, &l);
    const char *chunkname = lua_type_(L, 2) <= LUA2_TNIL ? s : lib3_luaL_checklstring_8882EB20(L, 2, 0);
    return load_aux(L, loadbuffer_(L, s, l, chunkname));
}

extern void fn_88834B28(lua_State *L, const u16 *s, u32 l); /* lua_pushlwstring */
extern const u16 lbl_880DFC68[];                           /* L"" */
extern char lbl_880E1FF4[];                                /* "%.40s: %p" */
extern char lbl_880E17A4[];                                /* "no value" */
extern char lbl_880E2000[];                                /* "userdata" */

LUA2_FORCEINLINE const char *luaL_typename_(lua_State *L, int i)
{
    int t = lua_type_(L, i);
    return t == -1 ? lbl_880E17A4 : lbl_880C9684[t];
}
#define wputchar(B, c) \
    do { \
        if ((B)->p + 1 >= (B)->buffer + 0x200 && lib3_emptybuffer_8882DE88(B)) lib3_adjuststack_8882DBA8(B); \
        *(u16 *)(B)->p = (u16)(c); \
        (B)->p += 2; \
    } while (0)

LUA2_FORCEINLINE void pushwstring_(lua_State *L, const u16 *s)
{
    if (s == 0)
        ts4_lua_pushnil_88824188(L);
    else
        fn_88834B28(L, s, wcslen_(s));
}

/* luaB_towstring (LuaPlus) */
int lua3_luaB_towstring_8882B998(lua_State *L)
{
    char buff[64];
    Buffer b;
    Buffer wb;
    switch (lua_type_(L, 1)) {
    case LUA2_TNUMBER:
        pushwstring_(L, fn_888348A0(L, 1));
        return 1;
    case LUA2_TSTRING: {
        const char *s = lib3_lua_tostring_88822888(L, 1);
        u32 len = lib3_lua_strlen_888222F0(L, 1);
        u32 i;
        if (len == 0) {
            fn_88834B28(L, lbl_880DFC68, 0);
            return 1;
        }
        b.L = L;
        b.p = b.buffer;
        b.wide = 1;
        b.lvl = 0;
        for (i = 0; i < len; i++) wputchar(&b, (unsigned char)s[i]);
        lib3_emptybuffer_8882DE88(&b);
        ts4_lua_concat_88822DB0(b.L, b.lvl);
        return 1;
    }
    case LUA2_TWSTRING:
        ts4_lua_pushvalue_88824248(L, 1);
        return 1;
    case LUA2_TTABLE:
        fn_885635D0(buff, lbl_880E1FF4, luaL_typename_(L, 1), lib3_lua_topointer_1_888227A8(L));
        break;
    case LUA2_TFUNCTION:
        fn_885635D0(buff, lbl_880E1FC4, lib3_lua_topointer_1_888227A8(L));
        break;
    case LUA2_TUSERDATA: {
        const char *tn = luaL_typename_(L, 1);
        if (strcmp(tn, lbl_880E2000) == 0)
            fn_885635D0(buff, lbl_880E1FD4, lib3_lua_touserdata_88822230(L, 1));
        else
            fn_885635D0(buff, lbl_880E1FF4, tn, lib3_lua_touserdata_88822230(L, 1));
        break;
    }
    case LUA2_TNIL:
        ts4_lua_pushlstring_88823FC0(L, lbl_880E1FF0, 3);
        return 1;
    case LUA2_TTHREAD:
        fn_885635D0(buff, lbl_880E1FE4, (void *)tothread_(L, 1));
        break;
    default:
        lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1C98);
    }
    {
        const u16 *s = fn_888348A0(L, 1);
        u32 len = lib3_lua_strlen_888222F0(L, 1);
        u32 i;
        wb.L = L;
        wb.p = wb.buffer;
        wb.wide = 1;
        wb.lvl = 0;
        for (i = 0; i < len; i++) wputchar(&wb, s[i]);
        lib3_emptybuffer_8882DE88(&wb);
        ts4_lua_concat_88822DB0(wb.L, wb.lvl);
    }
    return 1;
}

#if 0 /* NEAR MISS: 2 instructions (r4/r5 argument setup order before luaL_openlib) */
typedef struct luaL_reg {
    const char *name;
    int (*func)(lua_State *L);
} luaL_reg;

extern void lib3_base_open_8882BDA0(lua_State *L);
extern void lib3_luaL_openlib_8882E0D8(lua_State *L, const char *libname, const luaL_reg *l); /* nup folded */
extern void ts4_lua_newtable_888238D8(lua_State *L);
extern void ts4_lua_settable_88823580(lua_State *L, int idx);
extern void fn_88834A38(lua_State *L, int t); /* push the per-type metatable of type t */
extern char lbl_880E2150[];                 /* "coroutine" */
/* registry type-name table ("_nil" ... "_wstring"); co_funcs (6 entries) sits directly before it */
extern const char *const lbl_880C9C70[10];
#define co_funcs (&((const luaL_reg *)lbl_880C9C70)[-6])
extern char lbl_880E2054[];                 /* "_LOADED" */

#define LUA_REGISTRYINDEX (-10000)

LUA2_FORCEINLINE void openlib_(lua_State *L, const char *libname, const luaL_reg *l)
{
    lib3_luaL_openlib_8882E0D8(L, libname, l);
}

/* luaopen_base; LuaPlus also registers the per-type metatables under "_nil" ... "_wstring" */
int lua3_luaopen_base_8882C888(lua_State *L)
{
    int i;
    const char *const *names = lbl_880C9C70;
    lib3_base_open_8882BDA0(L);
    openlib_(L, lbl_880E2150, (const luaL_reg *)names - 6);
    ts4_lua_newtable_888238D8(L);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E2054, 7);
    ts4_lua_insert_88824438(L, -2);
    ts4_lua_settable_88823580(L, LUA_GLOBALSINDEX);
    ts4_lua_pushvalue_88824248(L, LUA_REGISTRYINDEX);
    for (i = 1; i < 10; i++) {
        pushstring_(L, names[i]);
        fn_88834A38(L, i);
        ts4_lua_settable_88823580(L, -3);
    }
    lua3_lua_settop_888246A8(L, -2);
    return 0;
}
#endif
