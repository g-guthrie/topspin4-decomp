/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex (no file I/O, wide-string buffers). lauxlib.c. */
#ifdef _MSC_VER
typedef char *va_list;
void __cdecl __va_start(va_list *ap, ...);
#define va_start(ap, v) (__va_start(&(ap), (v)))
#define va_end(ap) ((ap) = (va_list)0)
#else
#include <stdarg.h>
#endif
#include "d3d_lua.h"
#ifdef _MSC_VER
#define LIB3_NOINLINE __declspec(noinline)
#else
#define LIB3_NOINLINE
#endif
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
extern int strcmp(const char *a, const char *b);
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(strlen, strcmp, memcmp)
#else
#include <string.h>
#endif

typedef Ts4LuaValue TValue;
typedef Ts4LuaState lua_State;

#define LIB3_BUFFERSIZE 0x200

/* luaL_Buffer as laid out here: write pointer, level count, wide flag, owner state, storage. */
typedef struct Lib3Buffer {
    char *p;
    int lvl;
    int wide;
    lua_State *L;
    char buffer[LIB3_BUFFERSIZE];
} Lib3Buffer;

/* lua_Debug (5.0.2 layout). */
typedef struct Lib3Debug {
    int event;
    const char *name;
    const char *namewhat;
    const char *what;
    const char *source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci;
} Lib3Debug;

extern unsigned int lib3_lua_strlen_888222F0(lua_State *L, int idx);
extern void ts4_lua_concat_88822DB0(lua_State *L, int n);
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, unsigned int l);
extern void fn_88834B28(lua_State *L, const void *s, unsigned int l);
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern void ts4_lua_rawget_88823AE8(lua_State *L, int idx);
extern void ts4_lua_rawgeti_888239E0(lua_State *L, int idx, int n);
extern void ts4_lua_rawset_88823430(lua_State *L, int idx);
extern void ts4_lua_pushnumber_888240B8(lua_State *L, double n);
extern void ts4_lua_pushvalue_88824248(lua_State *L, int idx);
extern void fn_888246A8(lua_State *L, int idx);
extern void ts4_lua_remove_below_top_888245A8(lua_State *L);
extern int fn_8881EED0(lua_State *L, int level, Lib3Debug *ar);
extern int fn_8881FF18(lua_State *L, const char *what, Lib3Debug *ar);
const char *lib3_lua_pushfstring_88822988(lua_State *L, const char *fmt, ...);
extern int lib3_checkint_8882DD08(lua_State *L, int i);
extern void lib3_getsizes_8882DC40(lua_State *L);
#ifdef _MSC_VER
#define LIB3_NOINLINE __declspec(noinline)
#else
#define LIB3_NOINLINE
#endif
LIB3_NOINLINE int lib3_emptybuffer_8882DE88(Lib3Buffer *B);
LIB3_NOINLINE void lib3_adjuststack_8882DBA8(Lib3Buffer *B);
extern char lbl_880E1CB4[];
extern char lbl_880E1CA8[];
extern char lbl_880E1CB0[];
extern char lbl_880E17D0[];
extern char lbl_880D3108[];
extern const double g_ts4_script_constants[];
extern void ts4_lua_newtable_888238D8(lua_State *L);
extern void lib3_lua_setmetatable_888231A0(lua_State *L, int idx);
extern void ts4_lua_rawseti_88823320(lua_State *L, int idx, int n);
extern TValue *ts4_lua_v_tonumber_8880CAF0(lua_State *L, TValue *obj, TValue *n);
extern void lib3_lua_getglobal_top_88823BA8(lua_State *L);
extern void ts4_lua_insert_88824438(lua_State *L, int idx);
extern void fn_8881E258(lua_State *L, TValue *func, int nresults);
extern const char *lib3_lua_tostring_88822888(lua_State *L, int idx);
extern char *ts4_addr_lbl_88C30DA8_88567BC8(void);
extern int fn_88569190(void *stream, const char *fmt, ...);
extern void ts4_lua_settable_88823580(lua_State *L, int idx);
extern void lib3_lua_pushcclosure_88823E00(lua_State *L, void *fn, int n);

typedef struct Lib3Reg {
    const char *name;
    void *func;
} Lib3Reg;
extern char lbl_880E1C78[];
extern char lbl_880E1C7C[];
extern char lbl_880E18AC[];
extern char lbl_880C1320[];


/* luaL_addlstring: append l bytes, flushing the buffer when full. */
void lib3_luaL_addlstring_8882E828(Lib3Buffer *B, const char *s, unsigned int l)
{
    while (l--) {
        if (B->p >= B->buffer + LIB3_BUFFERSIZE) {
            if (lib3_emptybuffer_8882DE88(B)) lib3_adjuststack_8882DBA8(B);
        }
        *B->p++ = *s++;
    }
}

/* Wide variant of luaL_addlstring: append l 16-bit units. */
void lib3_luaL_addlwstring_8882E790(Lib3Buffer *B, const unsigned short *s, unsigned int l)
{
    while (l--) {
        if (B->p + 1 >= B->buffer + LIB3_BUFFERSIZE) {
            if (lib3_emptybuffer_8882DE88(B)) lib3_adjuststack_8882DBA8(B);
        }
        *(unsigned short *)B->p = *s++;
        B->p += 2;
    }
}

/* luaL_addwstring: append a NUL-terminated wide string. */
void lib3_luaL_addwstring_8882E9B8(Lib3Buffer *B, const unsigned short *s)
{
    const unsigned short *e = s;
    while (*e) e++;
    lib3_luaL_addlwstring_8882E790(B, s, e - s);
}

/* adjuststack: concatenate buffer levels on the stack to keep it shallow. */
void lib3_adjuststack_8882DBA8(Lib3Buffer *B)
{
    if (B->lvl > 1) {
        lua_State *L = B->L;
        int toget = 1;
        unsigned int toplen = lib3_lua_strlen_888222F0(L, -1);
        do {
            unsigned int l = lib3_lua_strlen_888222F0(L, -(toget + 1));
            if (B->lvl - toget + 1 >= 10 || toplen > l) {
                toplen += l;
                toget++;
            } else
                break;
        } while (toget < B->lvl);
        ts4_lua_concat_88822DB0(L, toget);
        B->lvl = B->lvl - toget + 1;
    }
}

/* emptybuffer: push the buffered bytes (or wide units) as a string. */
int lib3_emptybuffer_8882DE88(Lib3Buffer *B)
{
    unsigned int l = B->p - B->buffer;
    if (l == 0) return 0;
    if (B->wide)
        fn_88834B28(B->L, B->buffer, l / 2);
    else
        ts4_lua_pushlstring_88823FC0(B->L, B->buffer, l);
    B->p = B->buffer;
    B->lvl++;
    return 1;
}

/* luaL_where: push "chunk:line: " for the function at the given level. */
void lib3_luaL_where_8882E2D0(lua_State *L, int level)
{
    Lib3Debug ar;
    if (fn_8881EED0(L, level, &ar)) {
        fn_8881FF18(L, lbl_880E1C78, &ar);
        if (ar.currentline > 0) {
            lib3_lua_pushfstring_88822988(L, lbl_880E1C7C, ar.short_src, ar.currentline);
            return;
        }
    }
    ts4_lua_pushlstring_88823FC0(L, lbl_880C1320, 0);
}

/* luaL_setn: record n in the "n" field or the weak sizes table. */
void lib3_luaL_setn_8882E008(lua_State *L, int n)
{
    ts4_lua_pushlstring_88823FC0(L, lbl_880E18AC, 1);
    ts4_lua_rawget_88823AE8(L, 1);
    if (lib3_checkint_8882DD08(L, 1) >= 0) {
        ts4_lua_pushlstring_88823FC0(L, lbl_880E18AC, 1);
        ts4_lua_pushnumber_888240B8(L, (double)n);
        ts4_lua_rawset_88823430(L, 1);
    } else {
        lib3_getsizes_8882DC40(L);
        ts4_lua_pushvalue_88824248(L, 1);
        ts4_lua_pushnumber_888240B8(L, (double)n);
        ts4_lua_rawset_88823430(L, -3);
        fn_888246A8(L, -2);
    }
}

/* luaL_getn: "n" field, sizes table, or count of non-nil integer keys. */
int lib3_luaL_getn_8882DF10(lua_State *L, int t)
{
    int n;
    if (t <= 0) t = (int)(L->top - L->base) + t + 1;
    ts4_lua_pushlstring_88823FC0(L, lbl_880E18AC, 1);
    ts4_lua_rawget_88823AE8(L, t);
    if ((n = lib3_checkint_8882DD08(L, 1)) >= 0) return n;
    lib3_getsizes_8882DC40(L);
    ts4_lua_pushvalue_88824248(L, t);
    ts4_lua_rawget_88823AE8(L, -2);
    if ((n = lib3_checkint_8882DD08(L, 2)) >= 0) return n;
    for (n = 1;; n++) {
        TValue *o;
        ts4_lua_rawgeti_888239E0(L, t, n);
        o = L->top - 1;
        if (o != 0 && o->tt == 0) break;
        fn_888246A8(L, -2);
    }
    fn_888246A8(L, -2);
    return n - 1;
}

/* Tail of luaL_getmetafield: metatable already pushed; fetch event from it. */
int lib3_getmetafield_tail_8882E218(lua_State *L, const char *event)
{
    TValue *o;
    if (event == 0)
        ts4_lua_pushnil_88824188(L);
    else {
        ts4_lua_pushlstring_88823FC0(L, event, strlen(event));
    }
    ts4_lua_rawget_88823AE8(L, -2);
    o = L->top - 1;
    if (o != 0 && o->tt == 0) {
        fn_888246A8(L, -3);
        return 0;
    }
    ts4_lua_remove_below_top_888245A8(L);
    return 1;
}

/* getsizes: fetch (or create) the weak-keyed table of array sizes in the registry. */
void lib3_getsizes_8882DC40(lua_State *L)
{
    TValue *o;
    ts4_lua_rawgeti_888239E0(L, -10000, 2);
    o = L->top - 1;
    if (o != 0 && o->tt == 0) {
        fn_888246A8(L, -2);
        ts4_lua_newtable_888238D8(L);
        ts4_lua_pushvalue_88824248(L, -1);
        lib3_lua_setmetatable_888231A0(L, -2);
        ts4_lua_pushlstring_88823FC0(L, lbl_880E1CA8, 6);
        ts4_lua_pushlstring_88823FC0(L, lbl_880E1CB0, 1);
        ts4_lua_rawset_88823430(L, -3);
        ts4_lua_pushvalue_88824248(L, -1);
        ts4_lua_rawseti_88823320(L, -10000, 2);
    }
}

/* lua_tonumber(L, -1) expanded. */
TS4_FORCEINLINE double lib3_tonumber_top(lua_State *L)
{
    TValue n;
    TValue *o;
    n.tt = 0;
    n.u.p = 0;
    o = L->top - 1;
    if (o != 0 && (o->tt == 3 || (o = ts4_lua_v_tonumber_8880CAF0(L, o, &n)) != 0))
        return o->u.n;
    return g_ts4_script_constants[11];
}

/* lua_isnumber(L, -1) expanded. */
TS4_FORCEINLINE int lib3_isnumber_top(lua_State *L)
{
    TValue n;
    TValue *o;
    n.tt = 0;
    n.u.p = 0;
    o = L->top - 1;
    return o != 0 && (o->tt == 3 || ts4_lua_v_tonumber_8880CAF0(L, o, &n) != 0);
}

/* checkint: integer on top (or -1 if not a number), then pop topop values. */
int lib3_checkint_8882DD08(lua_State *L, int topop)
{
    int n = (int)lib3_tonumber_top(L);
    if (n == 0 && !lib3_isnumber_top(L)) n = -1;
    fn_888246A8(L, -topop - 1);
    return n;
}

/* callalert (status != 0 part): hand the message to _ALERT or print it on stderr. */
void lib3_callalert_8882DDD0(lua_State *L)
{
    TValue *o;
    ts4_lua_pushlstring_88823FC0(L, lbl_880E17D0, 6);
    lib3_lua_getglobal_top_88823BA8(L);
    o = L->top - 1;
    if (o != 0 && o->tt == 6) {
        ts4_lua_insert_88824438(L, -2);
        fn_8881E258(L, L->top - 2, 0);
    } else {
        const char *msg = lib3_lua_tostring_88822888(L, -2);
        fn_88569190(ts4_addr_lbl_88C30DA8_88567BC8() + 0x40, lbl_880D3108, msg);
        fn_888246A8(L, -3);
    }
}

extern int fn_8881E748(lua_State *L, Ts4LuaCall *c, int oldtop, int ef);

/* aux_do: run the chunk on top when it parsed, report errors through _ALERT. */
int lib3_aux_do_8882E368(lua_State *L, int status)
{
    if (status == 0) {
        Ts4LuaCall c;
        c.func = L->top - 1;
        c.nresults = -1;
        status = fn_8881E748(L, &c, (int)((char *)c.func - (char *)L->stack), 0);
    }
    if (status != 0) lib3_callalert_8882DDD0(L);
    return status;
}

/* luaL_openlib(L, libname, l, 0). */
void lib3_luaL_openlib_8882E0D8(lua_State *L, const char *libname, const Lib3Reg *l)
{
    if (libname) {
        TValue *o;
        ts4_lua_pushlstring_88823FC0(L, libname, strlen(libname));
        lib3_lua_getglobal_top_88823BA8(L);
        o = L->top - 1;
        if (o != 0 && o->tt == 0) {
            fn_888246A8(L, -2);
            ts4_lua_newtable_888238D8(L);
            ts4_lua_pushlstring_88823FC0(L, libname, strlen(libname));
            ts4_lua_pushvalue_88824248(L, -2);
            ts4_lua_settable_88823580(L, -10001);
        }
        ts4_lua_insert_88824438(L, -1);
    }
    for (; l->name; l++) {
        ts4_lua_pushlstring_88823FC0(L, l->name, strlen(l->name));
        lib3_lua_pushcclosure_88823E00(L, l->func, 0);
        ts4_lua_settable_88823580(L, -3);
    }
    fn_888246A8(L, -1);
}

extern int ts4_lua_v_tostring_8880C9F8(lua_State *L, TValue *obj);

/* lua_strlen(L, -1) expanded (narrow and wide strings share the length slot). */
TS4_FORCEINLINE unsigned int lib3_strlen_top(lua_State *L)
{
    TValue *o = L->top - 1;
    if (o == 0) return 0;
    if (o->tt == 4) return *(unsigned int *)((char *)o->u.p + 0x14);
    if (o->tt == 9) return *(unsigned int *)((char *)o->u.p + 0x14);
    if (ts4_lua_v_tostring_8880C9F8(L, o)) return *(unsigned int *)((char *)o->u.p + 0x14);
    return 0;
}

/* luaL_addvalue: move the value on top into the buffer. */
void lib3_luaL_addvalue_8882E3E8(Lib3Buffer *B)
{
    lua_State *L = B->L;
    unsigned int vl = lib3_strlen_top(L);
    if (vl <= (unsigned int)(LIB3_BUFFERSIZE - (B->p - B->buffer))) {
        memcpy(B->p, lib3_lua_tostring_88822888(L, -1), vl);
        B->p += vl;
        fn_888246A8(L, -2);
    } else {
        if (lib3_emptybuffer_8882DE88(B)) ts4_lua_insert_88824438(L, -2);
        B->lvl++;
        lib3_adjuststack_8882DBA8(B);
    }
}

extern int ts4_lua_getmetatable_88823768(lua_State *L, int idx);
extern char lbl_880E1FAC[];

/* luaL_callmeta(L, 1, event) with the metafield lookup split out. */
TS4_FORCEINLINE int lib3_getmetafield(lua_State *L, int obj, const char *event)
{
    if (!ts4_lua_getmetatable_88823768(L, obj)) return 0;
    return lib3_getmetafield_tail_8882E218(L, event);
}

int lib3_luaL_callmeta_8882E560(lua_State *L)
{
    if (!lib3_getmetafield(L, 1, lbl_880E1FAC))
        return 0;
    ts4_lua_pushvalue_88824248(L, 1);
    fn_8881E258(L, L->top - 2, 1);
    return 1;
}

extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L);
extern const char *fn_888188F8(lua_State *L, const char *fmt, va_list argp);
extern void fn_8880FA80(lua_State *L, int total, int last);
TS4_NORETURN extern void fn_8881F900(lua_State *L);

/* luaC_checkGC */
#define LIB3_CHECKGC(L) \
    if (((Ts4LuaGlobal *)(L)->l_G)->nblocks >= ((Ts4LuaGlobal *)(L)->l_G)->GCthreshold) \
        ts4_call_seq_fn_8881C130_8881C200(L)

int lib3_luaL_error_8882E5F0(lua_State *L, const char *fmt, ...);

/* luaL_error: prefix position, format the message, raise it. */
int lib3_luaL_error_8882E5F0(lua_State *L, const char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);
    lib3_luaL_where_8882E2D0(L, 1);
    LIB3_CHECKGC(L);
    fn_888188F8(L, fmt, argp);
    va_end(argp);
    LIB3_CHECKGC(L);
    fn_8880FA80(L, 2, (int)(L->top - L->base) - 1);
    L->top -= 1;
    fn_8881F900(L);
#ifndef _MSC_VER
    return 0; /* host syntax check only: lua_error does not return */
#endif
}

typedef struct Lib3CallInfo {
    char pad[0x18];
} Lib3CallInfo;

extern char lbl_880E1C18[];
extern char lbl_880E1C20[];
extern char lbl_880E1C40[];
extern char lbl_880E1C44[];

TS4_NORETURN void lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *extramsg);

/* luaL_argerror: name the offending argument (and the method's self) in the message. */
void lib3_luaL_argerror_8882E6B8(lua_State *L, int narg, const char *extramsg)
{
    Lib3Debug ar;
    Lib3CallInfo *ci = (Lib3CallInfo *)L->ci;
    Lib3CallInfo *base_ci = (Lib3CallInfo *)L->base_ci;
    if (ci != base_ci) ar.i_ci = (int)(ci - base_ci);
    fn_8881FF18(L, lbl_880E18AC, &ar);
    if (strcmp(ar.namewhat, lbl_880E1C18) == 0) {
        narg--;
        if (narg == 0)
            lib3_luaL_error_8882E5F0(L, lbl_880E1C20, ar.name, extramsg);
    }
    if (ar.name == 0) ar.name = lbl_880E1C40;
    lib3_luaL_error_8882E5F0(L, lbl_880E1C44, narg, ar.name, extramsg);
}

/* lapi.c: kept in this unit because the original was link-time optimised: callers of a
   variadic function whose body is visible reserve home slots and keep a frame. */
/* lua_pushfstring */
const char *lib3_lua_pushfstring_88822988(lua_State *L, const char *fmt, ...)
{
    const char *ret;
    va_list argp;
    LIB3_CHECKGC(L);
    va_start(argp, fmt);
    ret = fn_888188F8(L, fmt, argp);
    va_end(argp);
    return ret;
}

extern int lib3_lua_checkstack_88822028(lua_State *L, int size);
extern int lib3_lua_type_88822738(lua_State *L, int idx);
extern const char *lbl_880C9684[];
extern char lbl_880E17A4[];
extern char lbl_880E1C64[];
extern char lbl_880E1C84[];

/* luaL_checkstack */
void lib3_luaL_checkstack_8882E8F8(lua_State *L, int space, const char *mesg)
{
    if (!lib3_lua_checkstack_88822028(L, space))
        lib3_luaL_error_8882E5F0(L, lbl_880E1C84, mesg);
}

#define LIB3_TYPENAME(t) ((t) == -1 ? lbl_880E17A4 : lbl_880C9684[t])

TS4_NORETURN void lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname);

/* luaL_typerror */
void lib3_luaL_typerror_8882E950(lua_State *L, int narg, const char *tname)
{
    int t = lib3_lua_type_88822738(L, narg);
    const char *msg = lib3_lua_pushfstring_88822988(L, lbl_880E1C64, tname, LIB3_TYPENAME(t));
    lib3_luaL_argerror_8882E6B8(L, narg, msg);
}

/* ---- lstrlib.c functions that raise errors ----
   Lua 5.0.2 lstrlib.c, kept in this unit next to luaL_error for the reason given above. */
typedef struct Lib3MatchState {
    const char *src_init;
    const char *src_end;
    lua_State *L;
    int level;
    struct {
        const char *init;
        int len;
    } capture[32];
} Lib3MatchState;

extern const char *lib3_match_88825EF0(Lib3MatchState *ms, const char *s, const char *p);
extern char *fn_88563500(const char *s, int c);
extern const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void);
extern char *ts4_copy_bytes(char *dst, const char *src, unsigned int n);
extern char lbl_880E244C[];
extern char lbl_880E1B88[];
extern char lbl_880E1BB8[];

#define LIB3_ISDIGIT(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x4)

/* scanformat: copy one %-specification (flags, width, precision) of string.format into form. */
const char *lib3_scanformat_88825638(lua_State *L, const char *strfrmt, char *form, int *hasprecision)
{
    const char *p = strfrmt;
    while (fn_88563500(lbl_880E244C, *p)) p++;
    if (LIB3_ISDIGIT((unsigned char)*p)) p++;
    if (LIB3_ISDIGIT((unsigned char)*p)) p++;
    if (*p == '.') {
        p++;
        *hasprecision = 1;
        if (LIB3_ISDIGIT((unsigned char)*p)) p++;
        if (LIB3_ISDIGIT((unsigned char)*p)) p++;
    }
    if (LIB3_ISDIGIT((unsigned char)*p))
        lib3_luaL_error_8882E5F0(L, lbl_880E1B88);
    if (p - strfrmt + 2 > 20)
        lib3_luaL_error_8882E5F0(L, lbl_880E1BB8);
    form[0] = '%';
    ts4_copy_bytes(form + 1, strfrmt, p - strfrmt + 1);
    form[p - strfrmt + 2] = 0;
    return p;
}

extern char lbl_880E1B28[];
extern char lbl_880E1B14[];

/* push_onecapture: a position capture pushes its 1-based index, others the substring. */
LIB3_NOINLINE void lib3_push_onecapture_888257A0(Lib3MatchState *ms, int i)
{
    int l = ms->capture[i].len;
    if (l == -1) lib3_luaL_error_8882E5F0(ms->L, lbl_880E1B28);
    if (l == -2)
        ts4_lua_pushnumber_888240B8(ms->L, (double)(ms->capture[i].init - ms->src_init + 1));
    else
        ts4_lua_pushlstring_88823FC0(ms->L, ms->capture[i].init, l);
}

/* start_capture */
const char *lib3_start_capture_88825838(Lib3MatchState *ms, const char *s, const char *p, int what)
{
    const char *res;
    int level = ms->level;
    if (level >= 32) lib3_luaL_error_8882E5F0(ms->L, lbl_880E1B14);
    ms->capture[level].init = s;
    ms->capture[level].len = what;
    ms->level = level + 1;
    if ((res = lib3_match_88825EF0(ms, s, p)) == 0)
        ms->level--;
    return res;
}

extern char lbl_880E1B00[];
extern char lbl_880E1AE0[];
extern char lbl_880E1ABC[];
extern char lbl_880E1AA4[];
extern char lbl_880E1A8C[];

/* matchbalance: %bxy */
const char *lib3_matchbalance_888258B8(Lib3MatchState *ms, const char *s, const char *p)
{
    if (*p == 0 || *(p + 1) == 0)
        lib3_luaL_error_8882E5F0(ms->L, lbl_880E1B00);
    if (*s != *p) return 0;
    else {
        int b = *p;
        int e = *(p + 1);
        int cont = 1;
        while (++s < ms->src_end) {
            if (*s == e) {
                if (--cont == 0) return s + 1;
            }
            else if (*s == b) cont++;
        }
    }
    return 0;
}

/* luaI_classend: end of the single-char class starting at p. */
const char *lib3_classend_88825988(Lib3MatchState *ms, const char *p)
{
    switch (*p++) {
    case '%': {
        if (*p == '\0')
            lib3_luaL_error_8882E5F0(ms->L, lbl_880E1ABC);
        return p + 1;
    }
    case '[': {
        if (*p == '^') p++;
        do {
            if (*p == '\0')
                lib3_luaL_error_8882E5F0(ms->L, lbl_880E1AE0);
            if (*(p++) == '%' && *p != '\0')
                p++;
        } while (*p != ']');
        return p + 1;
    }
    default: {
        return p;
    }
    }
}

/* capture_to_close */
int lib3_capture_to_close_88825A50(Lib3MatchState *ms)
{
    int level = ms->level;
    for (level--; level >= 0; level--)
        if (ms->capture[level].len == -1) return level;
    return lib3_luaL_error_8882E5F0(ms->L, lbl_880E1AA4);
}

/* check_capture */
int lib3_check_capture_88825AB0(Lib3MatchState *ms, int l)
{
    l -= '1';
    if (l < 0 || l >= ms->level || ms->capture[l].len == -1)
        return lib3_luaL_error_8882E5F0(ms->L, lbl_880E1A8C);
    return l;
}

#ifdef _MSC_VER
#define LIB3_UNREACHABLE() __assume(0)
#else
#define LIB3_UNREACHABLE() __builtin_unreachable()
#endif

/* luaL_loadfile replacement: file loading is not supported in this build. */
void lib3_luaL_loadfile_8882E808(lua_State *L, const char *filename)
{
    lib3_luaL_error_8882E5F0(L, lbl_880E1CB4, filename);
    LIB3_UNREACHABLE();
}

/* ---- lbaselib.c functions that raise errors (same unit as luaL_error, see above) ---- */
extern const char *lib3_luaL_checklstring_8882EB20(lua_State *L, int narg, unsigned int *len);
extern char lbl_880E1C98[];
extern char lbl_880E1F80[];
extern char lbl_880D1B40[];
extern char lbl_880E1F94[];

/* luaL_optstring (luaL_optlstring without a length). */
TS4_FORCEINLINE const char *lib3_optstring(lua_State *L, int narg, const char *def)
{
    if (ts4_lua_type(L, narg) <= 0) return def;
    return lib3_luaL_checklstring_8882EB20(L, narg, 0);
}

/* luaB_loadfile: luaL_loadfile always raises here. */
int lib3_luaB_loadfile_8882D1D0(lua_State *L)
{
    lib3_luaL_error_8882E5F0(L, lbl_880E1CB4, lib3_optstring(L, 1, 0));
    LIB3_UNREACHABLE();
}

/* luaB_dofile: luaL_loadfile always raises here. */
int lib3_luaB_dofile_8882D238(lua_State *L)
{
    lib3_luaL_error_8882E5F0(L, lbl_880E1CB4, lib3_optstring(L, 1, 0));
    LIB3_UNREACHABLE();
}

/* lua_toboolean on a positive index. */
TS4_FORCEINLINE int lib3_toboolean(lua_State *L, int idx)
{
    TValue *o = L->base + (idx - 1);
    if (o >= L->top) o = 0;
    return !(o == 0 || o->tt == 0 || (o->tt == 1 && o->u.b == 0));
}

/* luaB_assert */
int lib3_luaB_assert_8882D0E0(lua_State *L)
{
    if (ts4_lua_type(L, 1) == -1) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1C98);
    if (!lib3_toboolean(L, 1)) {
        lib3_luaL_error_8882E5F0(L, lbl_880D1B40, lib3_optstring(L, 2, lbl_880E1F80));
        LIB3_UNREACHABLE();
    }
    fn_888246A8(L, 1);
    return 1;
}

/* luaB_unpack */
int lib3_luaB_unpack_8882CB48(lua_State *L)
{
    int n, i;
    if (ts4_lua_type(L, 1) != 5) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[5]);
    n = lib3_luaL_getn_8882DF10(L, 1);
    if (!lib3_lua_checkstack_88822028(L, n)) lib3_luaL_error_8882E5F0(L, lbl_880E1C84, lbl_880E1F94);
    for (i = 1; i <= n; i++)
        ts4_lua_rawgeti_888239E0(L, 1, i);
    return n;
}

extern void lib3_lua_xmove_88824958(lua_State *from, lua_State *to, int n);
extern int fn_8881E858(lua_State *L, int nargs);
extern char lbl_880E20A4[];
extern char lbl_880E20C4[];

/* auxresume: move the arguments to the coroutine, resume it and fetch its results. */
int lib3_auxresume_8882B768(lua_State *L, lua_State *co, int narg)
{
    int status;
    if (!lib3_lua_checkstack_88822028(co, narg))
        lib3_luaL_error_8882E5F0(L, lbl_880E20A4);
    lib3_lua_xmove_88824958(L, co, narg);
    status = fn_8881E858(co, narg);
    if (status == 0) {
        int nres = (int)(co->top - co->base);
        if (!lib3_lua_checkstack_88822028(L, nres))
            lib3_luaL_error_8882E5F0(L, lbl_880E20C4);
        lib3_lua_xmove_88824958(co, L, nres);
        return nres;
    } else {
        lib3_lua_xmove_88824958(co, L, 1);
        return -1;
    }
}

extern char lbl_880E1E60[];
extern char lbl_880E1E54[];
extern char lbl_880E1E78[];

/* luaB_setmetatable */
int lib3_luaB_setmetatable_8882CFE0(lua_State *L)
{
    int t = ts4_lua_type(L, 2);
    if (ts4_lua_type(L, 1) != 5) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[5]);
    if (!(t == 0 || t == 5)) lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1E60);
    if (lib3_getmetafield(L, 1, lbl_880E1E54))
        lib3_luaL_error_8882E5F0(L, lbl_880E1E78);
    fn_888246A8(L, 2);
    lib3_lua_setmetatable_888231A0(L, 1);
    return 1;
}

/* luaO_rawequalObj (lobject.c); its body is visible to luaB_rawequal in the original. */
int lib3_luaO_rawequalObj_88818240(const TValue *t1, const TValue *t2)
{
    if (t1->tt != t2->tt) return 0;
    switch (t1->tt) {
    case 0:
        return 1;
    case 3:
        return t1->u.n == t2->u.n;
    case 1:
        return t1->u.b == t2->u.b;
    case 2:
        return t1->u.p == t2->u.p;
    default:
        return t1->u.gc == t2->u.gc;
    }
}
extern void ts4_lua_pushboolean_88823D48(lua_State *L, int b);

/* index2adr for a positive index (NULL past the top). */
TS4_FORCEINLINE TValue *lib3_posindex(lua_State *L, int idx)
{
    TValue *o = L->base + (idx - 1);
    if (o >= L->top) return 0;
    return o;
}

/* luaB_rawequal */
int lib3_luaB_rawequal_8882C710(lua_State *L)
{
    TValue *o1, *o2;
    if (ts4_lua_type(L, 1) == -1) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E1C98);
    if (ts4_lua_type(L, 2) == -1) lib3_luaL_argerror_8882E6B8(L, 2, lbl_880E1C98);
    o1 = lib3_posindex(L, 1);
    o2 = lib3_posindex(L, 2);
    ts4_lua_pushboolean_88823D48(L, (o1 == 0 || o2 == 0) ? 0 : lib3_luaO_rawequalObj_88818240(o1, o2));
    return 1;
}

/* ---- lbaselib.c helpers without errors ---- */
extern char *fn_88563500(const char *s, int c);
extern void ts4_lua_getglobals_88823670(lua_State *L);
extern char lbl_880E1F00[];

/* pushnexttemplate: push the next ';'-separated entry of a require path. */
const char *lib3_pushnexttemplate_8882B3B8(lua_State *L, const char *path)
{
    const char *l;
    if (*path == '\0') return 0;
    if (*path == ';') path++;
    l = fn_88563500(path, ';');
    if (l == 0) l = path + strlen(path);
    ts4_lua_pushlstring_88823FC0(L, path, l - path);
    return l;
}

/* luaB_gcinfo: block count and threshold in kilobytes. */
int lib3_luaB_gcinfo_8882B490(lua_State *L)
{
    ts4_lua_pushnumber_888240B8(L, (double)(int)(((Ts4LuaGlobal *)L->l_G)->nblocks >> 10));
    ts4_lua_pushnumber_888240B8(L, (double)(int)(((Ts4LuaGlobal *)L->l_G)->GCthreshold >> 10));
    return 2;
}

/* Push the caller's globals and its "__fenv" entry; true when that entry is not nil. */
int lib3_has_fenv_8882B4F8(lua_State *L)
{
    TValue *o;
    ts4_lua_getglobals_88823670(L);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E1F00, 6);
    ts4_lua_rawget_88823AE8(L, -2);
    o = L->top - 1;
    return (o == 0 ? -1 : o->tt) != 0;
}

extern void ts4_lua_concat_88822DB0(lua_State *L, int n);
extern char lbl_880E2030[];

/* composename: replace each '?' of the template on top with the package name. */
void lib3_composename_8882C0A0(lua_State *L)
{
    const char *path = lib3_lua_tostring_88822888(L, -1);
    const char *wild;
    int n = 1;
    while ((wild = fn_88563500(path, '?')) != 0) {
        if (!lib3_lua_checkstack_88822028(L, 3)) {
            lib3_luaL_error_8882E5F0(L, lbl_880E1C84, lbl_880E2030);
            LIB3_UNREACHABLE();
        }
        ts4_lua_pushlstring_88823FC0(L, path, wild - path);
        ts4_lua_pushvalue_88824248(L, 1);
        path = wild + 1;
        n += 2;
    }
    if (path == 0)
        ts4_lua_pushnil_88824188(L);
    else
        ts4_lua_pushlstring_88823FC0(L, path, strlen(path));
    ts4_lua_concat_88822DB0(L, n);
}

extern const char *ts4_if_call_seq_lbl_880E18EC_8882B568(lua_State *L);
extern char lbl_880E2054[];
extern char lbl_880E205C[];
extern char lbl_880E2078[];

/* lua_toboolean(L, -1) */
TS4_FORCEINLINE int lib3_toboolean_top(lua_State *L)
{
    TValue *o = L->top - 1;
    return !(o == 0 || o->tt == 0 || (o->tt == 1 && o->u.b == 0));
}

/* luaB_require: packages can only come from the _LOADED table in this build. */
int lib3_luaB_require_8882C9D0(lua_State *L)
{
    const char *path;
    if (!lib3_lua_tostring_88822888(L, 1)) lib3_luaL_typerror_8882E950(L, 1, lbl_880C9684[4]);
    fn_888246A8(L, 1);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E2054, 7);
    lib3_lua_getglobal_top_88823BA8(L);
    if (ts4_lua_type(L, 2) != 5) lib3_luaL_error_8882E5F0(L, lbl_880E205C);
    path = ts4_if_call_seq_lbl_880E18EC_8882B568(L);
    ts4_lua_pushvalue_88824248(L, 1);
    ts4_lua_rawget_88823AE8(L, 2);
    if (lib3_toboolean_top(L)) return 1;
    fn_888246A8(L, 3);
    if (lib3_pushnexttemplate_8882B3B8(L, path) != 0) {
        lib3_composename_8882C0A0(L);
        lib3_luaL_error_8882E5F0(L, lbl_880E1CB4, lib3_lua_tostring_88822888(L, -1));
        LIB3_UNREACHABLE();
    }
    lib3_luaL_error_8882E5F0(L, lbl_880E2078, lib3_lua_tostring_88822888(L, 1), ts4_if_call_seq_lbl_880E18EC_8882B568(L));
    LIB3_UNREACHABLE();
}

extern void *ts4_lua_newuserdata_88822CA0(lua_State *L, unsigned int size);
extern char lbl_880E200C[];

/* luaB_newproxy */
int lib3_luaB_newproxy_8882B830(lua_State *L)
{
    fn_888246A8(L, 1);
    ts4_lua_newuserdata_88822CA0(L, 0);
    if (lib3_toboolean(L, 1) == 0)
        return 1;
    else if (ts4_lua_type(L, 1) == 1) {
        ts4_lua_newtable_888238D8(L);
        ts4_lua_pushvalue_88824248(L, -1);
        ts4_lua_pushboolean_88823D48(L, 1);
        ts4_lua_rawset_88823430(L, -10002);
    } else {
        int validproxy = 0;
        if (ts4_lua_getmetatable_88823768(L, 1)) {
            ts4_lua_rawget_88823AE8(L, -10002);
            validproxy = lib3_toboolean_top(L);
            fn_888246A8(L, -2);
        }
        if (!validproxy) lib3_luaL_argerror_8882E6B8(L, 1, lbl_880E200C);
        ts4_lua_getmetatable_88823768(L, 1);
    }
    lib3_lua_setmetatable_888231A0(L, 2);
    return 1;
}

/* C closure: upvalue count at +0xD, upvalues from +0x18. */
typedef struct Lib3CClosure {
    char pad[0xD];
    u8 nupvalues;
    char pad2[0xA];
    TValue upvalue[1];
} Lib3CClosure;

/* lua_isstring(L, -1) */
TS4_FORCEINLINE int lib3_isstring_top(lua_State *L)
{
    TValue *o = L->top - 1;
    int t = (o == 0) ? -1 : o->tt;
    return t == 4 || t == 3 || t == 9;
}

/* lua_tothread(L, lua_upvalueindex(1)) */
TS4_FORCEINLINE lua_State *lib3_tothread_up1(lua_State *L)
{
    TValue *func = L->base - 1;
    TValue *o = (1 <= ((Lib3CClosure *)func->u.p)->nupvalues) ? &((Lib3CClosure *)func->u.p)->upvalue[0] : 0;
    return (o == 0 || o->tt != 8) ? 0 : (lua_State *)o->u.p;
}

/* auxwrap: resume the wrapped coroutine, re-raising its errors with position info. */
int lib3_auxwrap_8882BEC0(lua_State *L)
{
    lua_State *co = lib3_tothread_up1(L);
    int r = lib3_auxresume_8882B768(L, co, ts4_lua_gettop(L));
    if (r < 0) {
        if (lib3_isstring_top(L)) {
            lib3_luaL_where_8882E2D0(L, 1);
            ts4_lua_insert_88824438(L, -2);
            LIB3_CHECKGC(L);
            fn_8880FA80(L, 2, (int)(L->top - L->base) - 1);
            L->top -= 1;
        }
        fn_8881F900(L);
    }
    return r;
}

extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern char lbl_880E1F78[];


extern char lbl_880E2128[];
extern char lbl_880E212C[];
extern char lbl_880E2138[];
extern char lbl_880E2144[];
extern const Lib3Reg lbl_880C9B68[];

/* base_open: register the base library, _VERSION and newproxy (with its weak table). */
void lib3_base_open_8882BDA0(lua_State *L)
{
    ts4_lua_pushlstring_88823FC0(L, lbl_880E2128, 2);
    ts4_lua_pushvalue_88824248(L, -10001);
    lib3_luaL_openlib_8882E0D8(L, 0, lbl_880C9B68);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E212C, 8);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E2138, 9);
    ts4_lua_rawset_88823430(L, -3);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E2144, 8);
    ts4_lua_newtable_888238D8(L);
    ts4_lua_pushvalue_88824248(L, -1);
    lib3_lua_setmetatable_888231A0(L, -2);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E1CA8, 6);
    ts4_lua_pushlstring_88823FC0(L, lbl_880E1CB0, 1);
    ts4_lua_rawset_88823430(L, -3);
    lib3_lua_pushcclosure_88823E00(L, (void *)lib3_luaB_newproxy_8882B830, 1);
    ts4_lua_rawset_88823430(L, -3);
    ts4_lua_rawset_88823430(L, -1);
}

extern void fn_88834A38(lua_State *L, int n);
extern char lbl_880E2150[];
/* Registry type-name strings ("_nil", "_boolean", ...); co_funcs sits 0x30 bytes before them. */
extern const char *lbl_880C9C70[];


extern int ts4_lua_toboolean_88822398(lua_State *L, int idx);
extern const void *lib3_lua_topointer_1_888227A8(lua_State *L);
extern void *lib3_lua_touserdata_88822230(lua_State *L, int idx);
extern int fn_885635D0(char *buf, const char *fmt, ...);
extern char g_ts4_true_string[];
extern char lbl_880D1B30[];
extern char lbl_880E1FB8[];
extern char lbl_880E1FC4[];
extern char lbl_880E1FD4[];
extern char lbl_880E1FE4[];
extern char lbl_880E1FF0[];



/* luaL_checkstack expanded. */
TS4_FORCEINLINE void lib3_checkstack(lua_State *L, int space, const char *mesg)
{
    if (!lib3_lua_checkstack_88822028(L, space))
        lib3_luaL_error_8882E5F0(L, lbl_880E1C84, mesg);
}

/* push_captures (lstrlib.c) */
int lib3_push_captures_88825B08(Lib3MatchState *ms, const char *s, const char *e)
{
    int i;
    lib3_checkstack(ms->L, ms->level, lbl_880E1B14);
    if (ms->level == 0 && s) {
        ts4_lua_pushlstring_88823FC0(ms->L, s, e - s);
        return 1;
    } else {
        for (i = 0; i < ms->level; i++)
            lib3_push_onecapture_888257A0(ms, i);
        return ms->level;
    }
}

/* match_capture (lstrlib.c) with check_capture expanded. */
const char *lib3_match_capture_88825BB0(Lib3MatchState *ms, const char *s, int l)
{
    unsigned int len;
    l -= '1';
    if (l < 0 || l >= ms->level || ms->capture[l].len == -1) {
        lib3_luaL_error_8882E5F0(ms->L, lbl_880E1A8C);
        LIB3_UNREACHABLE();
    }
    len = ms->capture[l].len;
    if ((unsigned int)(ms->src_end - s) >= len && memcmp(ms->capture[l].init, s, len) == 0)
        return s + len;
    else
        return 0;
}

extern char lbl_880E23F0[];
extern char lbl_880E23F4[];
extern char lbl_880E1A7C[];
extern int ts4_if_call_seq_u32_offc_88822A50(lua_State *L, Lib3Buffer *B, int endian);
extern double ts4_lua_opt_number_default_8882EA98(lua_State *L, int narg);

/* str_dump: optional leading endian string, then the function to dump. */
int lib3_str_dump_888284F0(lua_State *L)
{
    Lib3Buffer b;
    const char *mode = lbl_880E23F0;
    int fn = 1;
    TValue *o = (L->base < L->top) ? L->base : 0;
    if (o != 0 && (o->tt == 4 || o->tt == 3 || o->tt == 9)) {
        mode = lib3_lua_tostring_88822888(L, 1);
        fn = 2;
    }
    if (lib3_lua_type_88822738(L, fn) != 6) lib3_luaL_typerror_8882E950(L, fn, lbl_880C9684[6]);
    b.L = L; b.p = b.buffer; b.wide = 0; b.lvl = 0;
    if (!ts4_if_call_seq_u32_offc_88822A50(L, &b, (unsigned char)*mode))
        lib3_luaL_error_8882E5F0(L, lbl_880E23F4);
    lib3_emptybuffer_8882DE88(&b);
    ts4_lua_concat_88822DB0(b.L, b.lvl);
    return 1;
}

/* str_char */
int lib3_str_char_888285E0(lua_State *L)
{
    int n = (int)(L->top - L->base);
    int i;
    Lib3Buffer b;
    b.L = L; b.p = b.buffer; b.wide = 0; b.lvl = 0;
    for (i = 1; i <= n; i++) {
        int c = (int)ts4_lua_opt_number_default_8882EA98(L, i);
        if ((unsigned char)c != c) lib3_luaL_argerror_8882E6B8(L, i, lbl_880E1A7C);
        if (b.p >= b.buffer + LIB3_BUFFERSIZE && lib3_emptybuffer_8882DE88(&b)) lib3_adjuststack_8882DBA8(&b);
        *b.p++ = (char)c;
    }
    lib3_emptybuffer_8882DE88(&b);
    ts4_lua_concat_88822DB0(b.L, b.lvl);
    return 1;
}

extern void ts4_lua_replace_88824340(lua_State *L, int idx);

/* lua_tonumber body on an already resolved slot. */
TS4_FORCEINLINE double lib3_tonumber_obj(lua_State *L, TValue *o)
{
    TValue n;
    n.tt = 0;
    n.u.p = 0;
    if (o != 0 && (o->tt == 3 || (o = ts4_lua_v_tonumber_8880CAF0(L, o, &n)) != 0))
        return o->u.n;
    return g_ts4_script_constants[11];
}

/* gfind_aux */
int lib3_gfind_aux_88828338(lua_State *L)
{
    Lib3MatchState ms;
    const char *s = lib3_lua_tostring_88822888(L, -10002);
    unsigned int ls;
    const char *p;
    const char *src;
    Lib3CClosure *cl = (Lib3CClosure *)(L->base - 1)->u.p;
    TValue *o = (1 <= cl->nupvalues) ? &cl->upvalue[0] : 0;
    if (o == 0) ls = 0;
    else if (o->tt == 4) ls = *(unsigned int *)((char *)o->u.p + 0x14);
    else if (o->tt == 9) ls = *(unsigned int *)((char *)o->u.p + 0x14);
    else if (ts4_lua_v_tostring_8880C9F8(L, o)) ls = *(unsigned int *)((char *)o->u.p + 0x14);
    else ls = 0;
    p = lib3_lua_tostring_88822888(L, -10003);
    ms.L = L;
    ms.src_init = s;
    ms.src_end = s + ls;
    cl = (Lib3CClosure *)(L->base - 1)->u.p;
    o = (3 <= cl->nupvalues) ? &cl->upvalue[2] : 0;
    for (src = s + (unsigned int)lib3_tonumber_obj(L, o);
         src <= ms.src_end; src++) {
        const char *e;
        ms.level = 0;
        if ((e = lib3_match_88825EF0(&ms, src, p)) != 0) {
            int newstart = (int)(e - s);
            if (e == src) newstart++;
            ts4_lua_pushnumber_888240B8(L, (double)newstart);
            ts4_lua_replace_88824340(L, -10004);
            return lib3_push_captures_88825B08(&ms, src, e);
        }
    }
    return 0;
}

/* add_s */
void lib3_add_s_88825D00(Lib3MatchState *ms, Lib3Buffer *b, const char *s, const char *e)
{
    lua_State *L = ms->L;
    TValue *o = L->base + 2;
    if (o < L->top && o != 0 && (o->tt == 4 || o->tt == 3 || o->tt == 9)) {
        const char *news = lib3_lua_tostring_88822888(L, 3);
        unsigned int l = lib3_lua_strlen_888222F0(L, 3);
        unsigned int i;
        for (i = 0; i < l; i++) {
            if (news[i] != '%') {
                if (b->p >= b->buffer + LIB3_BUFFERSIZE && lib3_emptybuffer_8882DE88(b)) lib3_adjuststack_8882DBA8(b);
                *b->p++ = news[i];
            } else {
                i++;
                if (!LIB3_ISDIGIT((unsigned char)news[i])) {
                    if (b->p >= b->buffer + LIB3_BUFFERSIZE && lib3_emptybuffer_8882DE88(b)) lib3_adjuststack_8882DBA8(b);
                    *b->p++ = news[i];
                } else {
                    int level = lib3_check_capture_88825AB0(ms, news[i]);
                    lib3_push_onecapture_888257A0(ms, level);
                    lib3_luaL_addvalue_8882E3E8(b);
                }
            }
        }
    } else {
        int n;
        ts4_lua_pushvalue_88824248(L, 3);
        n = lib3_push_captures_88825B08(ms, s, e);
        fn_8881E258(L, L->top - (n + 1), 1);
        if (lib3_isstring_top(L))
            lib3_luaL_addvalue_8882E3E8(b);
        else
            fn_888246A8(L, -2);
    }
}

extern char lbl_880E2414[];
extern int lib3_matchbracketclass_88825118(int c, const char *p, const char *ec);
extern int ts4_match_class_88824F38(int c, int cl);
extern const char *lib3_min_expand_888253B8(Lib3MatchState *ms, const char *s, const char *p, const char *ep);
extern const char *lib3_max_expand_88825478(Lib3MatchState *ms, const char *s, const char *p, const char *ep);
extern const char *ts4_if_call_seq_fn_88825A50_88825C78(Lib3MatchState *ms, const char *s, const char *p);

/* luaI_singlematch */
TS4_FORCEINLINE int lib3_singlematch(int c, const char *p, const char *ep)
{
    switch (*p) {
    case '.': return 1;
    case '%': return ts4_match_class_88824F38(c, *(p + 1));
    case '[': return lib3_matchbracketclass_88825118(c, p, ep - 1);
    default: return (unsigned char)*p == c;
    }
}

/* match */
const char *lib3_match_88825EF0(Lib3MatchState *ms, const char *s, const char *p)
{
init:
    switch (*p) {
    case '(':
        if (*(p + 1) == ')')
            return lib3_start_capture_88825838(ms, s, p + 2, -2);
        else
            return lib3_start_capture_88825838(ms, s, p + 1, -1);
    case ')':
        return ts4_if_call_seq_fn_88825A50_88825C78(ms, s, p + 1);
    case '%':
        switch (*(p + 1)) {
        case 'b':
            s = lib3_matchbalance_888258B8(ms, s, p + 2);
            if (s == 0) return 0;
            p += 4;
            goto init;
        case 'f': {
            const char *ep;
            char previous;
            p += 2;
            if (*p != '[') {
                lib3_luaL_error_8882E5F0(ms->L, lbl_880E2414);
                return 0;
            }
            ep = lib3_classend_88825988(ms, p);
            previous = (s == ms->src_init) ? '\0' : *(s - 1);
            if (lib3_matchbracketclass_88825118((unsigned char)previous, p, ep - 1) ||
                !lib3_matchbracketclass_88825118((unsigned char)*s, p, ep - 1)) return 0;
            p = ep;
            goto init;
        }
        default:
            if (LIB3_ISDIGIT((unsigned char)*(p + 1))) {
                s = lib3_match_capture_88825BB0(ms, s, *(p + 1));
                if (s == 0) return 0;
                p += 2;
                goto init;
            }
            goto dflt;
        }
    case '\0':
        return s;
    case '$':
        if (*(p + 1) == '\0')
            return (s == ms->src_end) ? s : 0;
        goto dflt;
    default:
    dflt: {
        const char *ep = lib3_classend_88825988(ms, p);
        int m = s < ms->src_end && lib3_singlematch((unsigned char)*s, p, ep);
        switch (*ep) {
        case '?': {
            const char *res;
            if (m && ((res = lib3_match_88825EF0(ms, s + 1, ep + 1)) != 0))
                return res;
            p = ep + 1;
            goto init;
        }
        case '*':
            return lib3_max_expand_88825478(ms, s, p, ep);
        case '+':
            return m ? lib3_max_expand_88825478(ms, s + 1, p, ep) : 0;
        case '-':
            return lib3_min_expand_888253B8(ms, s, p, ep);
        default:
            if (!m) return 0;
            s++;
            p = ep;
            goto init;
        }
    }
    }
}
