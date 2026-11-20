/* Swing_DLL.xex 0x88836xxx script object rebinding and value assignment, hand-matched. */
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

extern void fn_881B19A0(Cx49LuaObject *o);

/* Move o onto another state's object list (no-op when it is already there). */
TS4_FORCEINLINE void cx49_rebind(Cx49LuaObject *o, Cx49LuaGlue *g)
{
    if (g != o->glue) {
        fn_881B19A0(o);
        o->glue = g;
        o->next = g->last;
        g->last = o;
        o->next->prev = o;
        o->prev = (Cx49LuaObject *)&g->last;
    }
}

/* Rebind to g and take a copy of *val. */
void cx49_luaobj_assign_value_88836BC0(Cx49LuaObject *o, Cx49LuaGlue *g, Ts4LuaValue *val)
{
    Ts4LuaState *L;
    Ts4LuaValue *dst;
    cx49_rebind(o, g);
    L = o->glue->L;
    dst = &o->v;
    TS4_ADDREF(val);
    TS4_RELEASE(L, dst);
    dst->tt = val->tt;
    dst->u = val->u;
}

/* Rebind to g and hold the integer n. */
void cx49_luaobj_assign_int_88836EB8(Cx49LuaObject *o, Cx49LuaGlue *g, int n)
{
    Ts4LuaState *L;
    Ts4LuaValue *dst;
    cx49_rebind(o, g);
    dst = &o->v;
    L = o->glue->L;
    TS4_RELEASE(L, dst);
    dst->u.n = (double)n;
    dst->tt = 3;
}

/* Rebind to g and hold nil. */
void cx49_luaobj_assign_nil_88836F68(Cx49LuaObject *o, Cx49LuaGlue *g)
{
    Ts4LuaState *L;
    Ts4LuaValue *dst;
    cx49_rebind(o, g);
    dst = &o->v;
    L = o->glue->L;
    TS4_RELEASE(L, dst);
    dst->tt = 0;
    dst->u.p = 0;
}
