/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex (reference-counted values). lapi.c helpers. */
#ifdef _MSC_VER
/* PowerPC MSVC variadic arguments live in 8-byte home slots after the last named one. */
typedef char *va_list;
void __cdecl __va_start(va_list *ap, ...);
#define va_start(ap, v) (__va_start(&(ap), (v)))
#define va_end(ap) ((ap) = (va_list)0)
#else
#include <stdarg.h>
#endif
#include "d3d_lua.h"

typedef Ts4LuaValue TValue;
typedef Ts4LuaState lua_State;

extern TValue *lib3_lua_negindex_88821F98(lua_State *L, int idx);

#ifdef _MSC_VER
#define LIB3_NOINLINE __declspec(noinline)
#else
#define LIB3_NOINLINE
#endif

/* Closure header: C-function flag at +0xC. */
typedef struct Lib3Closure {
    char pad[0xC];
    u8 isC;
} Lib3Closure;
extern TValue *ts4_if_call_seq_u32_off0_88812188(void *t, TValue *key);
extern TValue *lua2_luaV_index_8880D540(lua_State *L, TValue *t, TValue *key, int loop);
extern TValue *lua2_luaV_getnotable_8880CBC8(lua_State *L, TValue *t, TValue *key, int loop);

/* luaV_gettable: primitive table get, then the __index paths (luaV_index / luaV_getnotable). */
TS4_FORCEINLINE TValue *lib3_gettable(lua_State *L, TValue *t, TValue *key)
{
    if (t->tt == 5) {
        TValue *v = ts4_if_call_seq_u32_off0_88812188(t->u.p, key);
        if (v->tt != 0) return v;
        return lua2_luaV_index_8880D540(L, t, key, 1);
    }
    return lua2_luaV_getnotable_8880CBC8(L, t, key, 1);
}

/* lua_gettable(L, LUA_GLOBALSINDEX): replace the key on top with globals[key]. */
void lib3_lua_getglobal_top_88823BA8(lua_State *L)
{
    TValue *t = lib3_lua_negindex_88821F98(L, -10001);
    TValue *v = lib3_gettable(L, t, L->top - 1);
    TS4_SETOBJ(L, L->top - 1, v);
}

extern void *lua2_luaF_newCclosure_8881C768(lua_State *L, int nelems);
extern void lua2_luaD_call_8881E258(lua_State *L, TValue *func, int nresults);

/* incr_top (ldo.h): luaD_checkstack(L, 1); L->top++ (no ci->top check). */
#define LIB3_INCR_TOP(L) \
    { \
        if ((char *)(L)->stack_last - (char *)(L)->top <= 16) { \
            if (1 <= (L)->stacksize) \
                lua2_luaD_reallocstack_8881D478((L), 2 * (L)->stacksize); \
            else \
                lua2_luaD_reallocstack_8881D478((L), (L)->stacksize + 1 + 5); \
        } \
        (L)->top++; \
    }

/* C closure: function pointer at +0x14. */
typedef struct Lib3CClosure {
    Ts4LuaObject hdr;
    char pad[0x14 - sizeof(Ts4LuaObject)];
    void *f;
} Lib3CClosure;

/* lua_cpcall argument block. */
typedef struct Lib3CCallS {
    void *func;
    void *ud;
} Lib3CCallS;

/* f_Ccall: push a new C closure for c->func and the light userdata c->ud, then call it. */
void lib3_lua_f_Ccall_88822F08(lua_State *L, Lib3CCallS *c)
{
    Lib3CClosure *cl = lua2_luaF_newCclosure_8881C768(L, 0);
    TValue old;
    TValue *top;
    cl->f = c->func;
    top = L->top;
    old = *top;
    top->u.p = cl;
    top->tt = 6;
    cl->hdr.refs++;
    TS4_RELEASE(L, &old);
    LIB3_INCR_TOP(L);
    {
        TValue *o = L->top;
        TS4_RELEASE(L, o);
        o->tt = 2;
        o->u.p = c->ud;
    }
    LIB3_INCR_TOP(L);
    lua2_luaD_call_8881E258(L, L->top - 2, 0);
}


extern int ts4_lua_v_lessthan_8880C738(lua_State *L, TValue *l, TValue *r);
extern int lib3_luaO_rawequalObj_88818240(TValue *t1, TValue *t2);

/* luaA_indexAcceptable: NULL when a positive index is past the top. */
TS4_FORCEINLINE TValue *lib3_acceptable(lua_State *L, int idx)
{
    if (idx > 0) {
        TValue *o = L->base + (idx - 1);
        if (o >= L->top) return 0;
        else return o;
    }
    return lib3_lua_negindex_88821F98(L, idx);
}

/* lua_lessthan */
int lib3_lua_lessthan_888224D8(lua_State *L, int index1, int index2)
{
    TValue *o1 = lib3_acceptable(L, index1);
    TValue *o2 = lib3_acceptable(L, index2);
    return (o1 == 0 || o2 == 0) ? 0 : ts4_lua_v_lessthan_8880C738(L, o1, o2);
}

/* lua_rawequal(L, 1, 2) */
int lib3_lua_rawequal_1_2_88822590(lua_State *L)
{
    TValue *o1 = lib3_acceptable(L, 1);
    TValue *o2 = lib3_acceptable(L, 2);
    return (o1 == 0 || o2 == 0) ? 0 : lib3_luaO_rawequalObj_88818240(o1, o2);
}

/* lua_isuserdata */
int lib3_lua_isuserdata_888225D0(lua_State *L, int idx)
{
    TValue *o = lib3_acceptable(L, idx);
    return (o != 0 && (o->tt == 7 || o->tt == 2));
}

extern TValue *ts4_lua_v_tonumber_8880CAF0(lua_State *L, TValue *obj, TValue *n);
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L);

/* lua_isnumber */
int lib3_lua_isnumber_88822650(lua_State *L, int idx)
{
    TValue n;
    TValue *o = lib3_acceptable(L, idx);
    n.tt = 0;
    n.u.gc = 0;
    return (o != 0 && (o->tt == 3 || (o = ts4_lua_v_tonumber_8880CAF0(L, o, &n)) != 0));
}

/* lua_iscfunction(L, 1) */
int lib3_lua_iscfunction_1_888226F8(lua_State *L)
{
    TValue *o = lib3_acceptable(L, 1);
    return (o == 0) ? 0 : (o->tt == 6 && ((Lib3Closure *)o->u.p)->isC);
}

/* lua_type */
LIB3_NOINLINE int lib3_lua_type_88822738(lua_State *L, int idx)
{
    TValue *o = lib3_acceptable(L, idx);
    return (o == 0) ? -1 : o->tt;
}

void *lib3_lua_touserdata_88822230(lua_State *L, int idx);

/* lua_topointer(L, 1) */
const void *lib3_lua_topointer_1_888227A8(lua_State *L)
{
    TValue *o = lib3_acceptable(L, 1);
    if (o == 0) return 0;
    else {
        switch (o->tt) {
        case 5: return o->u.p;
        case 6: return o->u.p;
        case 8: return o->u.p;
        case 7:
        case 2:
            return lib3_lua_touserdata_88822230(L, 1);
        default: return 0;
        }
    }
}

/* lua_isstring: strings, numbers and wide strings (type 9). */
int lib3_lua_isstring_88822808(lua_State *L, int idx)
{
    int t = lib3_lua_type_88822738(L, idx);
    return (t == 4 || t == 3 || t == 9);
}

/* lua_setgcthreshold (threshold in Kbytes) followed by checkGC. */
void lib3_lua_setgcthreshold_88822848(lua_State *L, u32 newthreshold)
{
    if (newthreshold > (0xFFFFFFFFu >> 10))
        ((Ts4LuaGlobal *)L->l_G)->GCthreshold = 0xFFFFFFFFu;
    else
        ((Ts4LuaGlobal *)L->l_G)->GCthreshold = newthreshold << 10;
    if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
}

extern int ts4_lua_v_tostring_8880C9F8(lua_State *L, TValue *obj);

/* lua_tostring: string contents follow the 0x18-byte TString header. */
const char *lib3_lua_tostring_88822888(lua_State *L, int idx)
{
    TValue *o = lib3_acceptable(L, idx);
    if (o == 0) return 0;
    else if (o->tt == 4) return (const char *)o->u.p + 0x18;
    else {
        const char *s;
        s = (ts4_lua_v_tostring_8880C9F8(L, o) ? (const char *)o->u.p + 0x18 : 0);
        if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
            ts4_call_seq_fn_8881C130_8881C200(L);
        return s;
    }
}

/* lua_call */
void lib3_lua_call_88822970(lua_State *L, int nargs, int nresults)
{
    lua2_luaD_call_8881E258(L, L->top - (nargs + 1), nresults);
}

extern const char *lua3_luaO_pushvfstring_888188F8(lua_State *L, const char *fmt, va_list argp);


extern const char *ts4_if_get_u32_off10_88822128(lua_State *L, int n, TValue **val);

/* lua_setupvalue(L, 1, n): pop a value into upvalue n of the function at index 1. */

/* lua_getupvalue(L, 1, n): push upvalue n of the function at index 1. */

/* luaA_index: positive indices are not range-checked. */
TS4_FORCEINLINE TValue *lib3_index(lua_State *L, int idx)
{
    if (idx > 0) return L->base + (idx - 1);
    return lib3_lua_negindex_88821F98(L, idx);
}

/* Table: metatable at +0x10. Full userdata: metatable at +0xC. */
typedef struct Lib3Table {
    Ts4LuaObject hdr;
    char pad[0x10 - sizeof(Ts4LuaObject)];
    struct Lib3Table *metatable;
} Lib3Table;

typedef struct Lib3Udata {
    Ts4LuaObject hdr;
    Lib3Table *metatable;
} Lib3Udata;

/* lua_setmetatable: pop a table (nil means the default metatable at G+0x48) into obj. */
int lib3_lua_setmetatable_888231A0(lua_State *L, int objindex)
{
    TValue *obj, *mt;
    int res = 1;
    obj = lib3_index(L, objindex);
    mt = (L->top - 1)->tt != 0 ? L->top - 1 : (TValue *)((char *)L->l_G + 0x48);
    switch (obj->tt) {
    case 5: {
        TS4_ADDREF(mt);
        {
            Lib3Table *old = ((Lib3Table *)obj->u.p)->metatable;
            if (--old->hdr.refs == 0) fn_88818C88(L, &old->hdr);
        }
        ((Lib3Table *)obj->u.p)->metatable = mt->u.p;
        break;
    }
    case 7: {
        TS4_ADDREF(mt);
        {
            Lib3Table *old = ((Lib3Udata *)obj->u.p)->metatable;
            if (--old->hdr.refs == 0) fn_88818C88(L, &old->hdr);
        }
        ((Lib3Udata *)obj->u.p)->metatable = mt->u.p;
        break;
    }
    default: {
        res = 0;
        break;
    }
    }
    L->top--;
    TS4_SETNIL(L, L->top);
    return res;
}

/* C closure with its upvalues: function at +0x14, upvalue array at +0x18. */
typedef struct Lib3CClosureUp {
    Ts4LuaObject hdr;
    char pad[0x14 - sizeof(Ts4LuaObject)];
    void *f;
    TValue upvalue[1];
} Lib3CClosureUp;

/* lua_pushcclosure: move the n top values into a new C closure's upvalues and push it. */
void lib3_lua_pushcclosure_88823E00(lua_State *L, void *fn, int n)
{
    Lib3CClosureUp *cl;
    if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
    cl = lua2_luaF_newCclosure_8881C768(L, n);
    cl->f = fn;
    L->top -= n;
    while (n--) {
        TValue *o1 = &cl->upvalue[n];
        TValue *o2 = L->top + n;
        o1->tt = o2->tt;
        o1->u = o2->u;
        TS4_ADDREF(o1);
        TS4_SETNIL(L, L->top + n);
    }
    {
        TValue old;
        TValue *top = L->top;
        old = *top;
        top->u.p = cl;
        top->tt = 6;
        cl->hdr.refs++;
        TS4_RELEASE(L, &old);
    }
    TS4_INCR_TOP(L);
}

/* lua_settop: values dropped off the top are released. */

/* lua_xmove: move n values from the top of one thread's stack to another. */
void lib3_lua_xmove_88824958(lua_State *from, lua_State *to, int n)
{
    int i;
    from->top -= n;
    for (i = 0; i < n; i++) {
        TS4_SETOBJ(from, to->top, from->top + i);
        TS4_INCR_TOP(to);
        TS4_SETNIL(from, from->top + i);
    }
}

/* Protected-call descriptor passed to luaD_pcall. */
typedef struct Lib3CallS {
    TValue *func;
    int nresults;
} Lib3CallS;

extern int lua3_luaD_pcall_8881E748(lua_State *L, Lib3CallS *c, int oldtop, int ef);

/* lua_pcall: stack positions are passed as byte offsets from L->stack. */
int lib3_lua_pcall_88824C48(lua_State *L, int nargs, int nresults, int errfunc)
{
    Lib3CallS c;
    int func;
    func = (errfunc == 0) ? 0 : (int)((char *)lib3_index(L, errfunc) - (char *)L->stack);
    c.func = L->top - (nargs + 1);
    c.nresults = nresults;
    return lua3_luaD_pcall_8881E748(L, &c, (int)((char *)c.func - (char *)L->stack), func);
}

#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#else
#include <string.h>
#endif
extern void ts4_lua_pushnil_88824188(lua_State *L);
extern void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len);

/* lua_pushstring */
void lib3_lua_pushstring_88824CC8(lua_State *L, const char *s)
{
    if (s == 0)
        ts4_lua_pushnil_88824188(L);
    else
        ts4_lua_pushlstring_88823FC0(L, s, strlen(s));
}

/* ZIO input stream (lzio.h) with one extra trailing word. */
typedef struct Lib3Zio {
    u32 n;
    const char *p;
    const char *(*reader)(lua_State *L, void *ud, u32 *size);
    void *data;
    const char *name;
    int extra;
} Lib3Zio;

extern const char *ts4_if_get_u32_off4_8882DB60(lua_State *L, void *ud, u32 *size);
extern char lbl_880E1C40[];
extern int ex3_luaZ_lookahead_8880C238(Lib3Zio *z);
extern int lua3_luaD_protectedparser_8881EAF8(lua_State *L, Lib3Zio *z, int bin);

/* lua_load specialised for the luaL_loadbuffer string reader (getS). */
int lib3_lua_load_buffer_88824CF8(lua_State *L, void *data, const char *chunkname)
{
    const char *(*reader)(lua_State *, void *, u32 *) = ts4_if_get_u32_off4_8882DB60;
    Lib3Zio z;
    int c;
    if (!chunkname) chunkname = lbl_880E1C40;
    z.reader = reader;
    z.data = data;
    z.name = chunkname;
    z.n = 0;
    z.p = 0;
    z.extra = 0;
    c = ex3_luaZ_lookahead_8880C238(&z);
    return lua3_luaD_protectedparser_8881EAF8(L, &z, (c == 0x1b));
}

extern TValue *fn_88811930(void *t, int key);

/* C closure upvalue count at +0xD, upvalues at +0x18. */
typedef struct Lib3CClosureHdr {
    char pad[0xD];
    u8 nupvalues;
    char pad2[0xA];
    TValue upvalue[1];
} Lib3CClosureHdr;

/* negindex: stack-relative, registry (G+0x38), globals (L+0x48), C upvalues, and indices
   below -40000 that read integer keys of the table at G+0x40. */
LIB3_NOINLINE TValue *lib3_lua_negindex_88821F98(lua_State *L, int idx)
{
    if (idx > -10000)
        return L->top + idx;
    else if (idx < -40000)
        return fn_88811930(*(void **)((char *)L->l_G + 0x40), -40000 - idx);
    else switch (idx) {
        case -10000: return (TValue *)((char *)L->l_G + 0x38);
        case -10001: return (TValue *)((char *)L + 0x48);
        default: {
            Lib3CClosureHdr *func = (L->base - 1)->u.p;
            idx = -10001 - idx;
            return (idx <= func->nupvalues) ? &func->upvalue[idx - 1] : 0;
        }
    }
}

/* lua_checkstack */
int lib3_lua_checkstack_88822028(lua_State *L, int size)
{
    int res;
    if ((L->top - L->base + size) > 2048)
        res = 0;
    else {
        if ((char *)L->stack_last - (char *)L->top <= size * (int)sizeof(TValue)) {
            if (size <= L->stacksize)
                lua2_luaD_reallocstack_8881D478(L, 2 * L->stacksize);
            else
                lua2_luaD_reallocstack_8881D478(L, L->stacksize + size + 5);
        }
        if (L->ci->top < L->top + size)
            L->ci->top = L->top + size;
        res = 1;
    }
    return res;
}

/* luaA_indexAcceptable */
TValue *lib3_lua_index_acceptable_888220D8(lua_State *L, int idx)
{
    if (idx > 0) {
        TValue *o = L->base + (idx - 1);
        if (o >= L->top) return 0;
        else return o;
    }
    return lib3_lua_negindex_88821F98(L, idx);
}

/* lua_tothread */
lua_State *lib3_lua_tothread_888221B8(lua_State *L, int idx)
{
    TValue *o = lib3_acceptable(L, idx);
    return (o == 0 || o->tt != 8) ? 0 : (lua_State *)o->u.p;
}

/* Full userdata: flag word at +0x10 (bit 0: payload is a boxed pointer), payload at +0x18. */
typedef struct Lib3UdataBox {
    char pad[0x10];
    u32 flags;
    u32 pad14;
    void *box;
} Lib3UdataBox;

/* lua_touserdata */
LIB3_NOINLINE void *lib3_lua_touserdata_88822230(lua_State *L, int idx)
{
    TValue *o = lib3_acceptable(L, idx);
    if (o == 0) return 0;
    switch (o->tt) {
    case 7: {
        Lib3UdataBox *u = o->u.p;
        if (u->flags & 1) return u->box;
        return &u->box;
    }
    case 2: return o->u.p;
    default: return 0;
    }
}

/* String header: length at +0x14. */
typedef struct Lib3TString {
    char pad[0x14];
    u32 len;
} Lib3TString;

/* lua_strlen: also accepts wide strings (type 9). */
u32 lib3_lua_strlen_888222F0(lua_State *L, int idx)
{
    TValue *o = lib3_acceptable(L, idx);
    if (o == 0) return 0;
    else if (o->tt == 4) return ((Lib3TString *)o->u.p)->len;
    else if (o->tt == 9) return ((Lib3TString *)o->u.p)->len;
    else {
        u32 l;
        l = (ts4_lua_v_tostring_8880C9F8(L, o) ? ((Lib3TString *)o->u.p)->len : 0);
        return l;
    }
}
