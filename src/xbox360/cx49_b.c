/* Swing_DLL.xex 0x88837xxx script object constructors, hand-matched. */
#include "d3d_lua.h"

struct Cx49LuaObject;
typedef struct Cx49LuaGlue {
    Ts4LuaState *L;
    struct Cx49LuaObject *last; /* most recent live script object of this state */
} Cx49LuaGlue;

typedef struct Cx49LuaObject {
    struct Cx49LuaObject *next;
    struct Cx49LuaObject *prev;
    Ts4LuaValue v;
    Cx49LuaGlue *glue;
} Cx49LuaObject;

extern void cx49_luaobj_set_int_888364F8(Cx49LuaObject *o, int key, Ts4LuaValue *val);

extern Ts4LuaObject *ts4_if_call_seq_fn_889CE718_88811AC0(Ts4LuaState *L, int a, int b);
extern void cx49_luaobj_set_named_888368B0(Cx49LuaObject *o, const char *key, Ts4LuaValue *val);

/* Create a script object holding a fresh table and store it under key. */
Cx49LuaObject *cx49_luaobj_new_table_at_88837A68(Cx49LuaObject *out, Cx49LuaObject *obj, int key)
{
    Cx49LuaGlue *g = obj->glue;
    Ts4LuaValue *v = &out->v;
    out->glue = g;
    out->next = g->last;
    g->last = out;
    out->next->prev = out;
    out->prev = (Cx49LuaObject *)&g->last;
    *(volatile int *)&v->tt = 0;
    v->u.p = 0;
    v->tt = 5;
    out->v.u.gc = ts4_if_call_seq_fn_889CE718_88811AC0(obj->glue->L, 0, 0);
    out->v.u.gc->refs++;
    cx49_luaobj_set_int_888364F8(obj, key, &out->v);
    return out;
}

/* The same with a string key. */
Cx49LuaObject *cx49_luaobj_new_table_named_88837B00(Cx49LuaObject *out, Cx49LuaObject *obj, const char *key)
{
    Cx49LuaGlue *g = obj->glue;
    Ts4LuaValue *v = &out->v;
    out->glue = g;
    out->next = g->last;
    g->last = out;
    out->next->prev = out;
    out->prev = (Cx49LuaObject *)&g->last;
    *(volatile int *)&v->tt = 0;
    v->u.p = 0;
    v->tt = 5;
    out->v.u.gc = ts4_if_call_seq_fn_889CE718_88811AC0(obj->glue->L, 0, 0);
    out->v.u.gc->refs++;
    cx49_luaobj_set_named_888368B0(obj, key, &out->v);
    return out;
}

extern Cx49LuaObject *fn_88836710(Cx49LuaObject *o, Ts4LuaValue *key, Ts4LuaValue *val);
extern Ts4LuaObject *lua2_luaS_newlstr_888131A0(void *L, const char *s, u32 len);
extern void fn_88818C88(void *L, Ts4LuaObject *o);
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif

/* t[name] = *val, going through the raw table setter. */
Cx49LuaObject *cx49_luaobj_set_named_raw_888367F8(Cx49LuaObject *o, const char *key, Ts4LuaValue *val)
{
    Ts4LuaState *L = o->glue->L;
    Ts4LuaValue k;
    k.tt = 4;
    k.u.gc = lua2_luaS_newlstr_888131A0(L, key, strlen(key));
    k.u.gc->refs++;
    fn_88836710(o, &k, val);
    TS4_RELEASE(L, &k);
    return o;
}
