/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* lfunc.c: closures, prototypes and upvalues; LuaPlus links them into doubly linked lists. */
#include "lua2.h"
#ifdef _MSC_VER
void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
#else
#define _ReadWriteBarrier() ((void)0)
#endif

#define LUA2_TUPVAL 11

#define sizeCclosure(n) ((int)sizeof(CClosure) + (int)(sizeof(TValue) * ((n) - 1)))
#define sizeLclosure(n) ((int)sizeof(LClosure) + (int)(sizeof(UpVal *) * ((n) - 1)))

/* luaC_link (lgc.c), expanded by LTCG */
LUA2_FORCEINLINE void luaC_link_inl(lua_State *L, GCheader *o, lu_byte tt)
{
    o->prev = (GCheader *)&G(L)->rootgc;
    o->next = G(L)->rootgc;
    G(L)->rootgc = o;
    if (o->next) o->next->prev = o;
    o->tt = tt;
    o->marked = 0;
}

/* the same link with the stores as luaF_close schedules them */
LUA2_FORCEINLINE void luaC_link_inl2(lua_State *L, GCheader *o, lu_byte tt)
{
    o->prev = (GCheader *)&G(L)->rootgc;
    o->next = G(L)->rootgc;
    G(L)->rootgc = o;
    if (o->next) o->next->prev = o;
    o->marked = 0;
    o->tt = tt;
}

/* luaF_getlocalname */
const char *lua2_luaF_getlocalname_8881C258(const Proto *f, int local_number, int pc)
{
    int i;
    for (i = 0; i < f->sizelocvars && f->locvars[i].startpc <= pc; i++) {
        if (pc < f->locvars[i].endpc) { /* is variable active? */
            local_number--;
            if (local_number == 0) return getstr(f->locvars[i].varname);
        }
    }
    return 0; /* not found */
}

/* luaF_freeclosure */
void lua2_luaF_freeclosure_8881C2C8(lua_State *L, Closure *c)
{
    int size = (c->c.isC) ? sizeCclosure(c->c.nupvalues) : sizeLclosure(c->l.nupvalues);
    fn_889CE718(L, c, size, 0);
}

/* luaF_freeproto: line information is not kept by this build */
void lua2_luaF_freeproto_8881C2F8(lua_State *L, Proto *f)
{
    fn_889CE718(L, f->code, f->sizecode * sizeof(Instruction), 0);
    fn_889CE718(L, f->p, f->sizep * sizeof(Proto *), 0);
    fn_889CE718(L, f->k, f->sizek * sizeof(TValue), 0);
    fn_889CE718(L, f->locvars, f->sizelocvars * sizeof(LocVar), 0);
    fn_889CE718(L, f->upvalues, f->sizeupvalues * sizeof(TString *), 0);
    fn_889CE718(L, f, sizeof(Proto), 0);
}

/* luaF_close */
void lua2_luaF_close_8881C3C0(lua_State *L, StkId level)
{
    UpVal *p;
    while ((p = (UpVal *)L->openupval) != 0 && p->v >= level) {
        setobj(L, &p->value, p->v); /* save current value */
        p->v = &p->value;           /* now current value lives here */
        L->openupval = p->h.next;   /* remove from `open' list */
        luaC_link_inl2(L, &p->h, LUA2_TUPVAL);
    }
}

/* luaF_findupval */
UpVal *lua2_luaF_findupval_8881C4B8(lua_State *L, StkId level)
{
    GCheader **pp = &L->openupval;
    UpVal *p;
    UpVal *v;
    while ((p = (UpVal *)*pp) != 0 && p->v >= level) {
        if (p->v == level) return p;
        pp = &p->h.next;
    }
    v = (UpVal *)fn_889CE718(L, 0, 0, sizeof(UpVal)); /* not found: create a new one */
    v->h.tt = LUA2_TUPVAL;
    v->h.marked = 1; /* open upvalues should not be collected */
    v->v = level;    /* current value lives in the stack */
    v->h.next = *pp; /* chain it in the proper position */
    if (v->h.next) {
        v->h.prev = v->h.next->prev;
        v->h.next->prev = &v->h;
    } else
        v->h.prev = 0;
    v->value.tt = LUA2_TNIL;
    v->value.value.p = 0;
    v->h.refs = 0;
    *pp = &v->h;
    return v;
}

/* luaF_newLclosure */
Closure *lua2_luaF_newLclosure_8881C580(lua_State *L, int nelems, TValue *e)
{
    Closure *c = (Closure *)fn_889CE718(L, 0, 0, sizeLclosure(nelems));
    c->l.h.refs = 0;
    luaC_link_inl(L, &c->l.h, LUA2_TFUNCTION);
    c->l.isC = 0;
    {
        TValue *g = &c->l.g;
        *g = *e;
        _ReadWriteBarrier(); /* the binary re-reads g->tt after the copy */
        LUA2_ADDREF(g);
    }
    c->l.nupvalues = (lu_byte)nelems;
    return c;
}

/* luaF_newCclosure */
Closure *lua2_luaF_newCclosure_8881C768(lua_State *L, int nelems)
{
    Closure *c = (Closure *)fn_889CE718(L, 0, 0, sizeCclosure(nelems));
    c->c.h.refs = 0;
    luaC_link_inl(L, &c->c.h, LUA2_TFUNCTION);
    c->c.isC = 1;
    c->c.nupvalues = (lu_byte)nelems;
    return c;
}
