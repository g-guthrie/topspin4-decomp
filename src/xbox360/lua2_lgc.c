/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* lgc.c: LuaPlus collector (doubly linked object lists, reference counts, a host mark hook). */
#include "lua2.h"
#ifdef _MSC_VER
void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
#else
#define _ReadWriteBarrier() ((void)0)
#endif

#define LUA2_TPROTO 10
#define LUA2_TUPVAL 11

/* GCState with LuaPlus' extra thread pointer for the host mark hook. */
typedef struct GCState {
    GCheader *tmark; /* list of marked objects to be traversed */
    GCheader *wk;    /* list of traversed key-weak tables (to be cleared) */
    GCheader *wv;    /* list of traversed value-weak tables */
    GCheader *wkv;   /* list of traversed key-value weak tables */
    global_State *g;
    lua_State *L;    /* thread handed to the host mark hook */
} GCState;

/* global_State+0x184: host callback that marks objects the application holds. */
#define gchook(g) (*(void (**)(GCState *))&(g)->field184)

#define unmark(x) ((x)->marked &= (lu_byte)~1)
#define ismarked(x) ((x)->marked & ((1 << 4) | 1))
#define stringmark(s) ((s)->h.marked |= 1)
#define isfinalized(u) (!((u)->h.marked & 2))
#define markfinalized(u) ((u)->h.marked &= (lu_byte)~2)

#define KEYWEAKBIT 1
#define VALUEWEAKBIT 2
#define KEYWEAK (1 << KEYWEAKBIT)
#define VALUEWEAK (1 << VALUEWEAKBIT)

#define gcvalue(o) ((o)->value.gc)
/* setnilvalue without releasing the old value (it is already dead) */
#define setnilvalue_nr(obj) \
    { \
        TValue *o_ = (obj); \
        o_->tt = LUA2_TNIL; \
        o_->value.p = 0; \
    }
#define ttisstring(o) (ttype(o) == LUA2_TSTRING || ttype(o) == LUA2_TWSTRING)
#define sizenode(t) (1 << ((t)->lsizenode))
#define gnode(t, i) (&(t)->node[i])
#define sizeudata(l) (0x18 + (l))
#define sizestring(l) (sizeof(TString) + (l) + 1)
#define sizewstring(l) (sizeof(TString) + ((l) + 1) * 2)
#define sizeCclosure(n) ((int)sizeof(CClosure) + (int)(sizeof(TValue) * ((n) - 1)))
#define sizeLclosure(n) ((int)sizeof(LClosure) + (int)(sizeof(UpVal *) * ((n) - 1)))

#define TM_GC 2
#define TM_MODE 3
#define BASIC_CI_SIZE 8
#define BASIC_STACK_SIZE 40
#define EXTRA_STACK 5
#define MINSTRTABSIZE 32
#define LUA_MINBUFFER 32

extern const TValue *lua2_luaT_gettm_88811168(Table *events, int event, TString *ename);    /* luaT_gettm */
extern void lua2_luaH_free_888115F8(lua_State *L, Table *t);                               /* luaH_free */
extern void lua2_luaS_resize_88812CF8(lua_State *L, int newsize);                            /* luaS_resize */
extern void lua2_freestack_88813598(lua_State *L, lua_State *L1);                          /* freestack */
extern void lua2_luaF_freeproto_8881C2F8(lua_State *L, Proto *f);                               /* luaF_freeproto */
extern void lua2_luaF_close_8881C3C0(lua_State *L, StkId level);                            /* luaF_close */
extern void lua2_luaD_reallocCI_8881D170(lua_State *L, int newsize);                            /* luaD_reallocCI */
extern void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nresults);               /* luaD_call */
extern char *fn_88563500(const char *s, int c);                                /* strchr */

/* luaH_getstr (ltable.c): local copy, so luaC_separateudata keeps values in volatile registers across it. */
LUA2_LOCAL const TValue *ts4_loop_get_u8_offd_888114E0(Table *t, TString *key)
{
    Node *n = &t->node[key->hash & ((1 << t->lsizenode) - 1)];
    do {
        if (n->i_key.tt == LUA2_TSTRING && tsvalue(&n->i_key) == key) return &n->i_val;
        n = n->next;
    } while (n);
    return &lbl_880C9748;
}

#define gfasttm(g, et, e) (((et)->flags & (1u << (e))) ? 0 : lua2_luaT_gettm_88811168(et, e, (g)->tmname[e]))

#define markobject(st, o) \
    { \
        if (iscollectable(o) && !ismarked(gcvalue(o))) lua2_reallymarkobject_8881ADF8(st, gcvalue(o)); \
    }
#define condmarkobject(st, o, c) \
    { \
        if (iscollectable(o) && !ismarked(gcvalue(o)) && (c)) lua2_reallymarkobject_8881ADF8(st, gcvalue(o)); \
    }
#define markvalue(st, t) \
    { \
        if (!ismarked(&(t)->h)) lua2_reallymarkobject_8881ADF8(st, &(t)->h); \
    }

/* luaC_link: put a new object at the head of the root list */
LUA2_NOINLINE void lua2_luaC_link_8881AB58(lua_State *L, GCheader *o, lu_byte tt)
{
    o->prev = (GCheader *)&G(L)->rootgc;
    o->next = G(L)->rootgc;
    G(L)->rootgc = o;
    if (o->next) o->next->prev = o;
    o->tt = tt;
    o->marked = 0;
}

/* checkSizes */
LUA2_NOINLINE void lua2_checkSizes_8881AB98(lua_State *L, u32 deadmem)
{
    /* check size of string hash */
    if (G(L)->strt.nuse < (int)(G(L)->strt.size / 4) && G(L)->strt.size > MINSTRTABSIZE * 2)
        lua2_luaS_resize_88812CF8(L, G(L)->strt.size / 2); /* table is too big */
    /* check size of buffer */
    if (G(L)->buff.buffsize > LUA_MINBUFFER * 2) { /* buffer too big? */
        u32 newsize = G(L)->buff.buffsize / 2;
        G(L)->buff.buffer = (char *)fn_889CE718(L, G(L)->buff.buffer, G(L)->buff.buffsize, newsize);
        G(L)->buff.buffsize = newsize;
    }
    G(L)->GCthreshold = 2 * G(L)->nblocks - deadmem; /* new threshold */
}

/* Drop the references a dead table holds, so a cycle of unmarked tables can be freed. */
LUA2_NOINLINE void lua2_unreftable_8881AC40(Table *h)
{
    int i;
    if (h->metatable) h->metatable->h.refs--;
    i = h->sizearray;
    while (i--) {
        if (iscollectable(&h->array[i])) gcvalue(&h->array[i])->refs--;
    }
    i = sizenode(h);
    while (i--) {
        Node *n = gnode(h, i);
        if (ttype(&n->i_val) != LUA2_TNIL) {
            if (iscollectable(&n->i_key)) gcvalue(&n->i_key)->refs--;
            if (iscollectable(&n->i_val)) gcvalue(&n->i_val)->refs--;
        }
    }
}

/* valismarked: strings are always kept */
LUA2_FORCEINLINE int valismarked_inl(const TValue *o)
{
    if (ttisstring(o)) stringmark((TString *)gcvalue(o));
    return !iscollectable(o) || (gcvalue(o)->marked & 1);
}

LUA2_FORCEINLINE int iscleared_inl(const TValue *o)
{
    if (ttisstring(o)) stringmark((TString *)gcvalue(o));
    return iscollectable(o) && !(gcvalue(o)->marked & 1);
}

LUA2_NOINLINE int lua2_valismarked_8881AD20(const TValue *o)
{
    return valismarked_inl(o);
}

/* removekey */
LUA2_NOINLINE void lua2_removekey_8881AD70(lua_State *L, Node *n)
{
    setnilvalue(L, &n->i_val); /* remove corresponding value ... */
    if (iscollectable(&n->i_key)) n->i_key.tt = -1; /* dead key; remove it */
}

/* reallymarkobject */
LUA2_NOINLINE void lua2_reallymarkobject_8881ADF8(GCState *st, GCheader *o)
{
    o->marked |= 1; /* mark object */
    switch (o->tt) {
    case LUA2_TUSERDATA:
        markvalue(st, ((Udata *)o)->metatable);
        break;
    case LUA2_TFUNCTION:
        ((Closure *)o)->c.gclist = st->tmark;
        st->tmark = o;
        break;
    case LUA2_TTABLE:
        ((Table *)o)->gclist = st->tmark;
        st->tmark = o;
        break;
    case LUA2_TTHREAD:
        ((lua_State *)o)->gclist = st->tmark;
        st->tmark = o;
        break;
    case LUA2_TPROTO:
        ((Proto *)o)->gclist = st->tmark;
        st->tmark = o;
        break;
    }
}

LUA2_FORCEINLINE void reallymarkobject_inl(GCState *st, GCheader *o)
{
    o->marked |= 1; /* mark object */
    switch (o->tt) {
    case LUA2_TUSERDATA:
        markvalue(st, ((Udata *)o)->metatable);
        break;
    case LUA2_TFUNCTION:
        ((Closure *)o)->c.gclist = st->tmark;
        st->tmark = o;
        break;
    case LUA2_TTABLE:
        ((Table *)o)->gclist = st->tmark;
        st->tmark = o;
        break;
    case LUA2_TTHREAD:
        ((lua_State *)o)->gclist = st->tmark;
        st->tmark = o;
        break;
    case LUA2_TPROTO:
        ((Proto *)o)->gclist = st->tmark;
        st->tmark = o;
        break;
    }
}

/* do1gcTM: the stack slot below the call keeps the udata alive */
LUA2_NOINLINE void lua2_do1gcTM_8881AEB0(lua_State *L, Udata *udata)
{
    const TValue *tm;
    L->top++;
    tm = gfasttm(G(L), udata->metatable, TM_GC);
    if (tm != 0) {
        L->top += 2;
        setobj(L, L->top - 2, tm);
        setgcvalue(L, L->top - 1, udata, LUA2_TUSERDATA);
        lua2_luaD_call_8881E258(L, L->top - 2, 0);
    }
    L->top--;
}

LUA2_FORCEINLINE void freeobj_inl(lua_State *L, GCheader *o)
{
    switch (o->tt) {
    case LUA2_TPROTO:
        lua2_luaF_freeproto_8881C2F8(L, (Proto *)o);
        break;
    case LUA2_TFUNCTION: {
        Closure *c = (Closure *)o;
        u32 size = (c->c.isC) ? sizeCclosure(c->c.nupvalues) : sizeLclosure(c->l.nupvalues);
        fn_889CE718(L, c, size, 0);
        break;
    }
    case LUA2_TUPVAL:
        fn_889CE718(L, o, sizeof(UpVal), 0);
        break;
    case LUA2_TTABLE:
        lua2_luaH_free_888115F8(L, (Table *)o);
        break;
    case LUA2_TTHREAD: {
        lua_State *L1 = (lua_State *)o;
        lua2_luaF_close_8881C3C0(L1, L1->stack);
        lua2_freestack_88813598(L, L1);
        fn_889CE718(L, L1, sizeof(lua_State), 0);
        break;
    }
    case LUA2_TSTRING:
        fn_889CE718(L, o, sizestring(((TString *)o)->len), 0);
        break;
    case LUA2_TWSTRING:
        fn_889CE718(L, o, sizewstring(((TString *)o)->len), 0);
        break;
    case LUA2_TUSERDATA:
        fn_889CE718(L, o, sizeudata(((Udata *)o)->len), 0);
        break;
    }
}

/* freeobj */
LUA2_NOINLINE void lua2_freeobj_8881B000(lua_State *L, GCheader *o)
{
    freeobj_inl(L, o);
}

/* cleartablevalues */
LUA2_NOINLINE void lua2_cleartablevalues_8881B108(lua_State *L, GCheader *l)
{
    while (l) {
        Table *h = (Table *)l;
        int i = h->sizearray;
        while (i--) {
            TValue *o = &h->array[i];
            if (iscleared_inl(o)) /* value was collected? */
                setnilvalue_nr(o);  /* remove value */
        }
        i = sizenode(h);
        while (i--) {
            Node *n = gnode(h, i);
            if (iscleared_inl(&n->i_val)) /* value was collected? */
                lua2_removekey_8881AD70(L, n); /* remove entry from table */
        }
        l = h->gclist;
    }
}

/* cleartablekeys */
LUA2_NOINLINE void lua2_cleartablekeys_8881B230(lua_State *L, GCheader *l)
{
    while (l) {
        Table *h = (Table *)l;
        int i = sizenode(h);
        while (i--) {
            Node *n = gnode(h, i);
            if (!valismarked_inl(&n->i_key)) /* key was collected? */
                lua2_removekey_8881AD70(L, n); /* remove entry from table */
        }
        l = h->gclist;
    }
}

/* traverseclosure */
LUA2_NOINLINE void lua2_traverseclosure_8881B2E0(GCState *st, Closure *cl)
{
    if (cl->c.isC) {
        int i;
        for (i = 0; i < cl->c.nupvalues; i++) /* mark its upvalues */
            markobject(st, &cl->c.upvalue[i]);
    } else {
        int i;
        markvalue(st, hvalue(&cl->l.g));
        markvalue(st, cl->l.p);
        for (i = 0; i < cl->l.nupvalues; i++) { /* mark its upvalues */
            UpVal *u = cl->l.upvals[i];
            if (!u->h.marked) {
                markobject(st, &u->value);
                u->h.marked = 1;
            }
        }
    }
}

/* traverseproto */
LUA2_NOINLINE void lua2_traverseproto_8881B418(GCState *st, Proto *f)
{
    int i;
    for (i = 0; i < f->sizek; i++) { /* mark literal strings */
        if (ttisstring(f->k + i)) stringmark(tsvalue(f->k + i));
    }
    for (i = 0; i < f->sizeupvalues; i++) /* mark upvalue names */
        stringmark(f->upvalues[i]);
    for (i = 0; i < f->sizep; i++) /* mark nested protos */
        markvalue(st, f->p[i]);
    for (i = 0; i < f->sizelocvars; i++) /* mark local-variable names */
        stringmark(f->locvars[i].varname);
}

/* traversetable */
LUA2_NOINLINE void lua2_traversetable_8881B558(GCState *st, Table *h)
{
    int i;
    int weakkey = 0;
    int weakvalue = 0;
    const TValue *mode;
    markvalue(st, h->metatable);
    mode = gfasttm(st->g, h->metatable, TM_MODE);
    if (mode && ttype(mode) == LUA2_TSTRING) { /* is there a weak mode? */
        weakkey = (fn_88563500(getstr(tsvalue(mode)), 'k') != 0);
        weakvalue = (fn_88563500(getstr(tsvalue(mode)), 'v') != 0);
        if (weakkey || weakvalue) { /* is really weak? */
            GCheader **weaklist;
            h->h.marked &= ~(KEYWEAK | VALUEWEAK); /* clear bits */
            h->h.marked |= (lu_byte)((weakkey << KEYWEAKBIT) | (weakvalue << VALUEWEAKBIT));
            weaklist = (weakkey && weakvalue) ? &st->wkv : (weakkey) ? &st->wk : &st->wv;
            h->gclist = *weaklist; /* must be cleared after GC, ... */
            *weaklist = &h->h;
        }
    }
    if (!weakvalue) {
        i = h->sizearray;
        while (i--)
            markobject(st, &h->array[i]);
    }
    i = sizenode(h);
    while (i--) {
        Node *n = gnode(h, i);
        if (ttype(&n->i_val) != LUA2_TNIL) {
            condmarkobject(st, &n->i_key, !weakkey);
            condmarkobject(st, &n->i_val, !weakvalue);
        }
    }
}

/* luaC_separateudata: move `dead' udata that need finalization to list `tmudata' */
u32 lua2_luaC_separateudata_8881B770(lua_State *L)
{
    u32 deadmem = 0;
    GCheader **p = &G(L)->rootudata;
    GCheader *curr;
    GCheader *collected = 0; /* to collect udata with gc event */
    GCheader **lastcollected = &collected;
    while ((curr = *p) != 0) {
        if (ismarked(curr) || isfinalized((Udata *)curr))
            p = &curr->next; /* don't bother with them */
        else {
            Table *mt = ((Udata *)curr)->metatable;
            const TValue *tm;
            if (mt->flags & (1u << TM_GC))
                tm = 0;
            else {
                tm = ts4_loop_get_u8_offd_888114E0(mt, G(L)->tmname[TM_GC]);
                _ReadWriteBarrier();
                if (ttype(tm) == LUA2_TNIL) {
                    mt->flags |= (lu_byte)(1u << TM_GC);
                    tm = 0;
                }
            }
            if (tm == 0) {
                markfinalized((Udata *)curr); /* don't need finalization */
                p = &curr->next;
            } else { /* must call its gc method */
                deadmem += sizeudata(((Udata *)curr)->len);
                *p = curr->next;
                curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
                curr->next = 0; /* link `curr' at the end of `collected' list */
                *lastcollected = curr;
                lastcollected = &curr->next;
            }
        }
    }
    /* insert collected udata with gc event into `tmudata' list */
    *lastcollected = G(L)->tmudata;
    G(L)->tmudata = collected;
    return deadmem;
}

/* marktmu */
LUA2_NOINLINE void lua2_marktmu_8881B888(GCState *st)
{
    GCheader *u;
    for (u = st->g->tmudata; u; u = u->next) {
        unmark(u); /* may be marked, if left from previous GC */
        reallymarkobject_inl(st, u);
    }
}

/* luaC_callGCTM */
void lua2_luaC_callGCTM_8881B950(lua_State *L)
{
    lu_byte oldah = L->allowhook;
    L->allowhook = 0; /* stop debug hooks during GC tag methods */
    L->top++;         /* reserve space to keep udata while runs its gc method */
    while (G(L)->tmudata != 0) {
        GCheader *o = G(L)->tmudata;
        Udata *udata = (Udata *)o;
        G(L)->tmudata = o->next; /* remove udata from `tmudata' */
        o->prev = (GCheader *)&G(L)->rootudata; /* return it to `root' list */
        o->next = G(L)->rootudata;
        G(L)->rootudata = o;
        if (o->next) o->next->prev = o;
        setgcvalue(L, L->top - 1, udata, LUA2_TUSERDATA); /* keep a reference to it */
        unmark(o);
        markfinalized(udata);
        lua2_do1gcTM_8881AEB0(L, udata);
    }
    L->top--;
    L->allowhook = oldah; /* restore hooks */
}

LUA2_FORCEINLINE int sweeplist_inl(lua_State *L, GCheader **p, int limit)
{
    GCheader *curr;
    int count = 0; /* number of collected items */
    while ((curr = *p) != 0) {
        if (curr->marked > limit) {
            unmark(curr);
            p = &curr->next;
        } else {
            count++;
            if (curr->prev) curr->prev->next = curr->next;
            if (curr->next) curr->next->prev = (GCheader *)p;
            *p = curr->next;
            lua2_freeobj_8881B000(L, curr);
        }
    }
    return count;
}

/* sweeplist */
LUA2_NOINLINE int lua2_sweeplist_8881BA78(lua_State *L, GCheader **p, int limit)
{
    GCheader *curr;
    int count = 0; /* number of collected items */
    while ((curr = *p) != 0) {
        if (curr->marked > limit) {
            unmark(curr);
            p = &curr->next;
        } else {
            count++;
            if (curr->prev) curr->prev->next = curr->next;
            if (curr->next) curr->next->prev = (GCheader *)p;
            *p = curr->next;
            freeobj_inl(L, curr);
        }
    }
    return count;
}

/* checkstacksizes */
LUA2_NOINLINE void lua2_checkstacksizes_8881BBD8(lua_State *L, StkId max)
{
    int used = L->ci - L->base_ci; /* number of `ci' in use */
    if (4 * used < L->size_ci && 2 * BASIC_CI_SIZE < L->size_ci)
        lua2_luaD_reallocCI_8881D170(L, L->size_ci / 2); /* still big enough... */
    used = max - L->stack;              /* part of stack in use */
    if (4 * used < L->stacksize && 2 * (BASIC_STACK_SIZE + EXTRA_STACK) < L->stacksize)
        lua2_luaD_reallocstack_8881D478(L, L->stacksize / 2); /* still big enough... */
}

/* sweepstrings */
LUA2_NOINLINE void lua2_sweepstrings_8881BC78(lua_State *L, int all)
{
    int i;
    for (i = 0; i < G(L)->strt.size; i++) /* for each list */
        G(L)->strt.nuse -= sweeplist_inl(L, &G(L)->strt.hash[i], all);
}

/* traversestack */
LUA2_NOINLINE void lua2_traversestack_8881BD50(GCState *st, lua_State *L1)
{
    StkId o, lim;
    CallInfo *ci;
    markobject(st, &L1->_gt);
    lim = L1->top;
    for (ci = L1->base_ci; ci <= L1->ci; ci++) {
        if (lim < ci->top) lim = ci->top;
    }
    for (o = L1->stack; o < L1->top; o++)
        markobject(st, o);
    for (; o <= lim; o++) {
        o->tt = LUA2_TNIL;
        o->value.p = 0;
    }
    lua2_checkstacksizes_8881BBD8(L1, lim);
}

/* markroot */
void lua2_markroot_8881BE58(GCState *st, lua_State *L)
{
    global_State *g = st->g;
    int i;
    markobject(st, &G(L)->defaultmeta);
    for (i = 0; i < 11; i++)
        markobject(st, &G(L)->mt[i]);
    markobject(st, &G(L)->l_registry);
    lua2_traversestack_8881BD50(st, g->mainthread);
    if (L != g->mainthread) /* another thread is running? */
        markvalue(st, L);   /* cannot collect it */
    if (gchook(G(L))) {
        st->L = g->mainthread;
        gchook(G(L))(st);
    }
}

/* luaC_sweep */
void lua2_luaC_sweep_8881BF80(lua_State *L, int all)
{
    if (all)
        all = 256; /* larger than any mark */
    else {
        GCheader *o;
        for (o = G(L)->rootgc; o; o = o->next)
            if (o->marked == 0 && o->tt == LUA2_TTABLE) lua2_unreftable_8881AC40((Table *)o);
    }
    lua2_sweeplist_8881BA78(L, &G(L)->rootudata, all);
    lua2_sweepstrings_8881BC78(L, all);
    lua2_sweeplist_8881BA78(L, &G(L)->rootgc, all);
}

/* propagatemarks */
void lua2_propagatemarks_8881C030(GCState *st)
{
    while (st->tmark) { /* traverse marked objects */
        switch (st->tmark->tt) {
        case LUA2_TTABLE: {
            Table *h = (Table *)st->tmark;
            st->tmark = h->gclist;
            lua2_traversetable_8881B558(st, h);
            break;
        }
        case LUA2_TFUNCTION: {
            Closure *cl = (Closure *)st->tmark;
            st->tmark = cl->c.gclist;
            lua2_traverseclosure_8881B2E0(st, cl);
            break;
        }
        case LUA2_TTHREAD: {
            lua_State *th = (lua_State *)st->tmark;
            st->tmark = th->gclist;
            lua2_traversestack_8881BD50(st, th);
            if (gchook(G(th))) {
                st->L = th;
                gchook(G(th))(st);
            }
            break;
        }
        case LUA2_TPROTO: {
            Proto *p = (Proto *)st->tmark;
            st->tmark = p->gclist;
            lua2_traverseproto_8881B418(st, p);
            break;
        }
        }
    }
}
