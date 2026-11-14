/* Swing_DLL.xex 0x88822398-0x88824594, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d3d_lua.h"

typedef Ts4LuaValue TValue;
typedef Ts4LuaState lua_State;

extern TValue *fn_88821F98(lua_State *L, int idx);
extern TValue *fn_888122E8(lua_State *L, void *t, TValue *key);
extern TValue *ts4_if_call_seq_u32_off0_88812188(void *t, TValue *key);
extern Ts4LuaObject *fn_888131A0(lua_State *L, const char *s, u32 len);
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L);
extern TValue *ts4_lua_v_tonumber_8880CAF0(lua_State *L, TValue *obj, TValue *n);
extern void fn_8880FA80(lua_State *L, int total, int last);
extern void fn_8880D278(lua_State *L, TValue *t, TValue *key, TValue *val);
extern void *ts4_if_call_seq_fn_889CE718_88811AC0(lua_State *L, int narray, int nhash);
extern TValue *fn_88811930(void *t, int n);
extern lua_State *fn_88813970(lua_State *L);
extern int fn_88812A88(lua_State *L, void *t, TValue *key);
extern TValue *fn_88812968(lua_State *L, void *t, int n);

/* Closure header: C-function flag at +0xC, environment value at +0x18. */
typedef struct Ts4LuaClosure {
    char pad[0xC];
    u8 isC;
    char pad2[0xB];
    TValue g;
} Ts4LuaClosure;
extern double g_ts4_script_constants[];

/* lua_State API: luaA_indexAcceptable helper (NULL when the slot is past the top). */
TS4_FORCEINLINE TValue *acceptable_(lua_State *L, int idx)
{
    if (idx > 0) {
        TValue *o = L->base + (idx - 1);
        if (o >= L->top) return 0;
        else return o;
    }
    return fn_88821F98(L, idx);
}
extern void *ts4_if_call_seq_fn_889CE718_88813350(lua_State *L, u32 size);

typedef struct Ts4LuaTable {
    char pad[0x10];
    struct Ts4LuaTable *metatable;
} Ts4LuaTable;

typedef struct Ts4LuaUdata {
    char pad[0xC];
    Ts4LuaTable *metatable;
} Ts4LuaUdata;

/* lua_toboolean */
int ts4_lua_toboolean_88822398(lua_State *L, int idx)
{
    TValue *o = acceptable_(L, idx);
    return (o != 0 && !(o->tt == 0 || (o->tt == 1 && o->u.b == 0)));
}

/* lua_tonumber */
double ts4_lua_tonumber_88822420(lua_State *L, int idx)
{
    TValue n;
    TValue *o;
    if (idx > 0) {
        TValue *p = L->base + (idx - 1);
        o = (p < L->top) ? p : 0;
    } else o = fn_88821F98(L, idx);
    n.tt = 0;
    n.u.gc = 0;
    if (o != 0 && (o->tt == 3 || (o = ts4_lua_v_tonumber_8880CAF0(L, o, &n)) != 0))
        return o->u.n;
    return g_ts4_script_constants[11];
}

/* lua_newuserdata */
void *ts4_lua_newuserdata_88822CA0(lua_State *L, u32 size)
{
    TValue old;
    TValue *top;
    void *u;
    if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
    u = ts4_if_call_seq_fn_889CE718_88813350(L, size);
    top = L->top;
    old = *top;
    top->u.p = u;
    top->tt = 7;
    ((Ts4LuaObject *)u)->refs++;
    TS4_RELEASE(L, &old);
    TS4_INCR_TOP(L);
    return (char *)u + 0x18;
}

/* lua_concat */
void ts4_lua_concat_88822DB0(lua_State *L, int n)
{
    if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
    if (n >= 2) {
        fn_8880FA80(L, n, (int)(L->top - L->base) - 1);
        L->top -= (n - 1);
    }
    else if (n == 0) {
        TValue old;
        TValue *top = L->top;
        old = *top;
        top->u.gc = fn_888131A0(L, 0, 0);
        top->tt = 4;
        top->u.gc->refs++;
        TS4_RELEASE(L, &old);
        TS4_INCR_TOP(L);
    }
}

/* lua_rawset */
void ts4_lua_rawset_88823430(lua_State *L, int idx)
{
    TValue *t;
    TValue *slot;
    TValue *top;
    t = (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx);
    top = L->top;
    slot = fn_888122E8(L, t->u.p, top - 2);
    TS4_SETOBJ(L, slot, top - 1);
    L->top -= 2;
    TS4_SETNIL(L, L->top);
    TS4_SETNIL(L, L->top + 1);
}

/* lua_rawget */
void ts4_lua_rawget_88823AE8(lua_State *L, int idx)
{
    TValue *t;
    TValue *o2;
    TValue *o1;
    t = (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx);
    o2 = ts4_if_call_seq_u32_off0_88812188(t->u.p, L->top - 1);
    o1 = L->top - 1;
    if (o2->tt >= 4) o2->u.gc->refs++;
    if (o1->tt >= 4) {
        if (--o1->u.gc->refs == 0) fn_88818C88(L, o1->u.gc);
    }
    o1->tt = o2->tt;
    o1->u = o2->u;
}

/* lua_getmetatable */
int ts4_lua_getmetatable_88823768(lua_State *L, int idx)
{
    TValue *obj;
    Ts4LuaTable *mt;
    TValue old;
    TValue *top;
    if (idx > 0) {
        TValue *o = L->base + (idx - 1);
        obj = (o < L->top) ? o : 0;
    } else obj = fn_88821F98(L, idx);
    switch (obj->tt) {
    case 5: mt = ((Ts4LuaTable *)obj->u.p)->metatable; break;
    case 7: mt = ((Ts4LuaUdata *)obj->u.p)->metatable; break;
    default: mt = (Ts4LuaTable *)((Ts4LuaGlobal *)L->l_G)->mt[obj->tt].u.p;
    }
    if (mt == 0) return 0;
    top = L->top;
    old = *top;
    top->u.p = mt;
    top->tt = 5;
    ((Ts4LuaObject *)mt)->refs++;
    TS4_RELEASE(L, &old);
    TS4_INCR_TOP(L);
    return 1;
}

/* lua_pushboolean */
void ts4_lua_pushboolean_88823D48(lua_State *L, int b)
{
    TValue *o1 = L->top;
    TS4_RELEASE(L, o1);
    o1->tt = 1;
    o1->u.b = (b != 0);
    TS4_INCR_TOP(L);
}

/* lua_pushlstring */
void ts4_lua_pushlstring_88823FC0(lua_State *L, const char *s, u32 len)
{
    TValue old;
    TValue *top;
    if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
    top = L->top;
    old = *top;
    top->u.gc = fn_888131A0(L, s, len);
    top->tt = 4;
    top->u.gc->refs++;
    TS4_RELEASE(L, &old);
    TS4_INCR_TOP(L);
}

/* lua_pushnil */
void ts4_lua_pushnil_88824188(lua_State *L)
{
    TValue *o1 = L->top;
    TS4_RELEASE(L, o1);
    o1->tt = 0;
    o1->u.p = 0;
    TS4_INCR_TOP(L);
}

/* lua_pushvalue */
void ts4_lua_pushvalue_88824248(lua_State *L, int idx)
{
    TValue *o2 = (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx);
    TValue *o1 = L->top;
    TS4_ADDREF(o2);
    TS4_RELEASE(L, o1);
    o1->tt = o2->tt;
    o1->u = o2->u;
    TS4_INCR_TOP(L);
}

/* lua_replace */
void ts4_lua_replace_88824340(lua_State *L, int idx)
{
    TS4_SETOBJ(L, (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx), L->top - 1);
    L->top--;
    TS4_SETNIL(L, L->top);
}

/* lua_insert */
void ts4_lua_insert_88824438(lua_State *L, int idx)
{
    TValue *p;
    TValue *q;
    TValue *t;
    p = (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx);
    for (q = L->top; q > p; q--) {
        TValue *o2 = q - 1;
        TValue *o1 = q;
        TS4_ADDREF(o2);
        TS4_RELEASE(L, o1);
        o1->tt = o2->tt;
        o1->u = o2->u;
    }
    t = L->top;
    TS4_ADDREF(t);
    TS4_RELEASE(L, p);
    p->tt = t->tt;
    p->u = t->u;
    t = L->top;
    TS4_RELEASE(L, t);
    t->tt = 0;
    t->u.p = 0;
}

/* lua_settable */
void ts4_lua_settable_88823580(lua_State *L, int idx)
{
    TValue *t;
    TValue *top;
    t = (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx);
    top = L->top;
    fn_8880D278(L, t, top - 2, top - 1);
    L->top -= 2;
    TS4_SETNIL(L, L->top);
    TS4_SETNIL(L, L->top + 1);
}

/* Push the global table visible to the function on top of the stack. */
void ts4_lua_getglobals_88823670(lua_State *L)
{
    TValue *o = fn_88821F98(L, -1);
    TValue *g;
    TValue *top;
    if (o->tt == 6 && !((Ts4LuaClosure *)o->u.p)->isC)
        g = &((Ts4LuaClosure *)o->u.p)->g;
    else
        g = (TValue *)((char *)L + 0x48);
    top = L->top;
    TS4_ADDREF(g);
    TS4_RELEASE(L, top);
    top->tt = g->tt;
    top->u = g->u;
    TS4_INCR_TOP(L);
}

/* lua_newtable */
void ts4_lua_newtable_888238D8(lua_State *L)
{
    TValue old;
    TValue *top;
    if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
    top = L->top;
    old = *top;
    top->u.p = ts4_if_call_seq_fn_889CE718_88811AC0(L, 0, 0);
    top->tt = 5;
    ((Ts4LuaObject *)top->u.p)->refs++;
    TS4_RELEASE(L, &old);
    TS4_INCR_TOP(L);
}

/* lua_rawgeti */
void ts4_lua_rawgeti_888239E0(lua_State *L, int idx, int n)
{
    TValue *o;
    TValue *r;
    o = (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx);
    r = fn_88811930(o->u.p, n);
    TS4_SETOBJ(L, L->top, r);
    TS4_INCR_TOP(L);
}

/* lua_pushlightuserdata */
void ts4_lua_pushlightuserdata_88823C98(lua_State *L, void *p)
{
    TValue *o1 = L->top;
    TS4_RELEASE(L, o1);
    o1->tt = 2;
    o1->u.p = p;
    TS4_INCR_TOP(L);
}

/* lua_pushnumber */
void ts4_lua_pushnumber_888240B8(lua_State *L, double n)
{
    TValue *o1 = L->top;
    TS4_RELEASE(L, o1);
    o1->tt = 3;
    o1->u.n = n;
    TS4_INCR_TOP(L);
}

/* lua_newthread */
lua_State *ts4_lua_newthread_88824850(lua_State *L)
{
    lua_State *L1;
    TValue old;
    TValue *top;
    if (((Ts4LuaGlobal *)L->l_G)->nblocks >= ((Ts4LuaGlobal *)L->l_G)->GCthreshold)
        ts4_call_seq_fn_8881C130_8881C200(L);
    L1 = fn_88813970(L);
    top = L->top;
    old = *top;
    top->u.p = L1;
    top->tt = 8;
    ((Ts4LuaObject *)L1)->refs++;
    TS4_RELEASE(L, &old);
    TS4_INCR_TOP(L);
    return L1;
}

/* luaA_pushobject: push a copy of a value; the growth check here has no call-frame test. */
void ts4_lua_pushobject_88824AA8(lua_State *L, TValue *o)
{
    TValue *o1 = L->top;
    TS4_ADDREF(o);
    TS4_RELEASE(L, o1);
    o1->tt = o->tt;
    o1->u = o->u;
    if ((char *)L->stack_last - (char *)L->top <= 16) {
        if (1 <= L->stacksize) fn_8881D478(L, 2 * L->stacksize);
        else fn_8881D478(L, L->stacksize + 1 + 5);
    }
    L->top++;
}

/* lua_next on the table in slot 1. */
int ts4_lua_next_first_88824B68(lua_State *L)
{
    int more = fn_88812A88(L, L->base->u.p, L->top - 1);
    if (more) {
        TS4_INCR_TOP(L);
    } else {
        L->top -= 1;
        TS4_SETNIL(L, L->top);
    }
    return more;
}

/* lua_remove(L, -2): drop the value just below the top. */
void ts4_lua_remove_below_top_888245A8(lua_State *L)
{
    TValue *p = fn_88821F98(L, -2);
    while (++p < L->top) {
        TS4_SETOBJ(L, p - 1, p);
    }
    L->top--;
    TS4_SETNIL(L, L->top);
}

/* lua_rawseti */
void ts4_lua_rawseti_88823320(lua_State *L, int idx, int n)
{
    TValue *o;
    TValue *slot;
    TValue *top;
    o = (idx > 0) ? L->base + (idx - 1) : fn_88821F98(L, idx);
    top = L->top;
    slot = fn_88812968(L, o->u.p, n);
    TS4_SETOBJ(L, slot, top - 1);
    L->top--;
    TS4_SETNIL(L, L->top);
}
