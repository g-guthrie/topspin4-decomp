/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* ldo.c: stack and call structure; LuaPlus releases references when the stack shrinks. */
#include "lua2.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif

#define LUA_MAXCALLS 4096
#define EXTRA_STACK 5
#define LUA_ERRRUN 1
#define LUA_ERRSYNTAX 3
#define LUA_ERRMEM 4
#define LUA_ERRERR 5

int _setjmp(void *env); /* setjmp */
extern LUA2_NORETURN void fn_88569D30(void *jb, int v);                  /* longjmp */
extern LUA2_NORETURN void ts4_tailcall_fn_88564208_885643D0(int status); /* exit */
extern char lbl_880E26F4[];                                              /* "stack overflow" */
extern char lbl_880E21DC[];                                              /* "call" */
extern void lua3_luaG_typeerror_8881F6D8(lua_State *L, const TValue *o, const char *opname); /* luaG_typeerror */
extern void lua3_luaG_runerror_8881FB60(lua_State *L, const char *fmt, ...); /* luaG_runerror */

extern const TValue *fn_88811930(Table *t, int key);                       /* luaH_getnum */
extern TValue *lua2_newkey_88812790(lua_State *L, Table *t, const TValue *key);     /* newkey */
extern TValue *lua2_luaH_set_888122E8(lua_State *L, Table *t, const TValue *key);     /* luaH_set */
extern Table *ts4_if_call_seq_fn_889CE718_88811AC0(lua_State *L, int narray, int lnhash); /* luaH_new */
extern TString *lua2_luaS_newlstr_888131A0(lua_State *L, const char *str, u32 l);
extern char lbl_880E18AC[]; /* "n" */
extern char lbl_880E2704[]; /* "C stack overflow" */
extern char lbl_880E2760[]; /* "attempt to yield across metamethod/C-call boundary" */
extern char lbl_880E2794[]; /* "cannot yield a C function" */
extern char lbl_880E26C8[]; /* MEMERRMSG "not enough memory" */
extern char lbl_880E26DC[]; /* "error in error handling" */

extern StkId fn_8880D5E0(lua_State *L);                  /* luaV_execute */
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L); /* luaC_collectgarbage */

typedef void (*Pfunc)(lua_State *L, void *ud);

/* luaD_reallocCI */
void lua2_luaD_reallocCI_8881D170(lua_State *L, int newsize)
{
    CallInfo *oldci = L->base_ci;
    L->base_ci = (CallInfo *)fn_889CE718(L, L->base_ci, L->size_ci * sizeof(CallInfo), newsize * sizeof(CallInfo));
    L->size_ci = (u16)newsize;
    L->ci = (L->ci - oldci) + L->base_ci;
    L->end_ci = L->base_ci + L->size_ci;
}

/* correctstack */
LUA2_NOINLINE void lua2_correctstack_8881D1F8(lua_State *L, TValue *oldstack)
{
    CallInfo *ci;
    GCheader *up;
    L->top = (L->top - oldstack) + L->stack;
    for (up = L->openupval; up != 0; up = up->next)
        ((UpVal *)up)->v = (((UpVal *)up)->v - oldstack) + L->stack;
    for (ci = L->base_ci; ci <= L->ci; ci++) {
        ci->top = (ci->top - oldstack) + L->stack;
        ci->base = (ci->base - oldstack) + L->stack;
    }
    L->base = L->ci->base;
}

/* luaD_rawrunprotected */
int lua2_luaD_rawrunprotected_8881D300(lua_State *L, Pfunc f, void *ud)
{
    struct lua_longjmp lj;
    lj.status = 0;
    lj.previous = L->errorJmp; /* chain new error handler */
    L->errorJmp = &lj;
    if (_setjmp(lj.b) == 0) (*f)(L, ud);
    L->errorJmp = lj.previous; /* restore old error handler */
    return lj.status;
}

LUA2_FORCEINLINE LUA2_NORETURN void luaD_throw_inl(lua_State *L, int errcode)
{
    if (L->errorJmp) {
        L->errorJmp->status = errcode;
        fn_88569D30(L->errorJmp->b, 1);
    }
    G(L)->panic(L);
    ts4_tailcall_fn_88564208_885643D0(1);
}

/* luaD_throw */
LUA2_NORETURN void lua2_luaD_throw_8881D390(lua_State *L, int errcode)
{
    luaD_throw_inl(L, errcode);
}

/* luaD_growCI */
void lua2_luaD_growCI_8881D3D8(lua_State *L)
{
    if (L->size_ci > LUA_MAXCALLS) /* overflow while handling overflow? */
        luaD_throw_inl(L, LUA_ERRERR);
    else {
        lua2_luaD_reallocCI_8881D170(L, 2 * L->size_ci);
        if (L->size_ci > LUA_MAXCALLS) lua3_luaG_runerror_8881FB60(L, lbl_880E26F4);
    }
}

/* luaD_reallocstack: references above a shrinking top are released first */
void lua2_luaD_reallocstack_8881D478(lua_State *L, int newsize)
{
    TValue *oldstack = L->stack;
    TValue *o;
    if (newsize < L->stacksize) {
        TValue *top = L->top;
        o = L->stack + newsize;
        while (o < top) setnilvalue(L, o++);
    }
    L->stack = (TValue *)fn_889CE718(L, L->stack, L->stacksize * sizeof(TValue), newsize * sizeof(TValue));
    L->stacksize = newsize;
    L->stack_last = L->stack + newsize - 1 - EXTRA_STACK;
    lua2_correctstack_8881D1F8(L, oldstack);
    {
        TValue *last;
        o = L->top;
        last = L->stack_last;
        while (o < last) {
            TValue *o1 = o++;
            o1->tt = LUA2_TNIL;
            o1->value.p = 0;
        }
    }
}

#define LUA_MINSTACK 20
#define LUA_HOOKRET 1
#define LUA_HOOKTAILRET 4
#define LUA_MASKRET 2
#define CI_C 1

typedef struct lua_Debug {
    int event;
    const char *name;
    const char *namewhat;
    const char *what;
    const char *source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci; /* active function */
} lua_Debug;

typedef void (*lua_Hook)(lua_State *L, lua_Debug *ar);

#define checkstack_ldo(L, n) \
    if ((char *)(L)->stack_last - (char *)(L)->top <= (n) * (int)sizeof(TValue)) { \
        if ((n) <= (L)->stacksize) \
            lua2_luaD_reallocstack_8881D478((L), 2 * (L)->stacksize); \
        else \
            lua2_luaD_reallocstack_8881D478((L), (L)->stacksize + (n) + 5); \
    }

/* luaD_callhook */
LUA2_FORCEINLINE void luaD_callhook_inl(lua_State *L, int event, int line)
{
    lua_Hook hook = (lua_Hook)L->hook;
    if (hook && L->allowhook) {
        int top = savestack(L, L->top);
        int ci_top = savestack(L, L->ci->top);
        lua_Debug ar;
        ar.event = event;
        ar.currentline = line;
        if (event == LUA_HOOKTAILRET)
            ar.i_ci = 0; /* tail call; no debug information about it */
        else
            ar.i_ci = L->ci - L->base_ci;
        checkstack_ldo(L, LUA_MINSTACK); /* ensure minimum stack size */
        L->ci->top = L->top + LUA_MINSTACK;
        L->allowhook = 0; /* cannot call hooks inside a hook */
        (*hook)(L, &ar);
        L->allowhook = 1;
        L->ci->top = restorestack(L, ci_top);
        L->top = restorestack(L, top);
    }
}

void lua2_luaD_callhook_8881D5A8(lua_State *L, int event, int line)
{
    luaD_callhook_inl(L, event, line);
}

/* callrethooks */
LUA2_NOINLINE StkId lua2_callrethooks_8881D698(lua_State *L, StkId firstResult)
{
    int fr = savestack(L, firstResult); /* next call may change stack */
    lua2_luaD_callhook_8881D5A8(L, LUA_HOOKRET, -1);
    if (!(L->ci->state & CI_C)) { /* Lua function? */
        while (L->ci->tailcalls--) /* call hook for eventual tail calls */
            luaD_callhook_inl(L, LUA_HOOKTAILRET, -1);
    }
    return restorestack(L, fr);
}

#define TM_CALL 14

/* luaH_getstr (ltable.c) */
LUA2_LOCAL const TValue *ts4_loop_get_u8_offd_888114E0(Table *t, TString *key)
{
    Node *n = &t->node[key->hash & ((1 << t->lsizenode) - 1)];
    do {
        if (n->i_key.tt == LUA2_TSTRING && tsvalue(&n->i_key) == key) return &n->i_val;
        n = n->next;
    } while (n);
    return &lbl_880C9748;
}

/* luaT_gettmbyobj: tables and userdata use their metatable, other types the global per-type slot. */
LUA2_FORCEINLINE const TValue *luaT_gettmbyobj(lua_State *L, const TValue *o, int event)
{
    TString *ename = G(L)->tmname[event];
    switch (ttype(o)) {
    case LUA2_TTABLE: return ts4_loop_get_u8_offd_888114E0(hvalue(o)->metatable, ename);
    case LUA2_TUSERDATA: return ts4_loop_get_u8_offd_888114E0(uvalue(o)->metatable, ename);
    default: return &G(L)->mt[ttype(o)];
    }
}

/* tryfuncTM */
LUA2_NOINLINE StkId lua2_tryfuncTM_8881D7E0(lua_State *L, StkId func)
{
    const TValue *tm = luaT_gettmbyobj(L, func, TM_CALL);
    StkId p;
    int funcr = savestack(L, func);
    if (ttype(tm) != LUA2_TFUNCTION) lua3_luaG_typeerror_8881F6D8(L, func, lbl_880E21DC);
    /* Open a hole inside the stack at `func' */
    for (p = L->top; p > func; p--) setobj(L, p, p - 1);
    checkstack_ldo(L, 1);
    L->top++;
    func = restorestack(L, funcr); /* previous call may change stack */
    setobj(L, func, tm);           /* tag method is the new function to be called */
    return func;
}

/* luaD_poscall: LuaPlus clears the slots between the old top and the results */
void lua2_luaD_poscall_8881D9A0(lua_State *L, int wanted, StkId firstResult)
{
    StkId res;
    StkId o;
    int state;
    if (L->hookmask & LUA_MASKRET) firstResult = lua2_callrethooks_8881D698(L, firstResult);
    res = L->base - 1; /* res == final position of 1st result */
    L->ci--;
    L->base = L->ci->base; /* restore base */
    /* move results to correct place */
    while (wanted != 0 && firstResult < L->top) {
        setobj(L, res++, firstResult++);
        wanted--;
    }
    while (wanted-- > 0) setnilvalue(L, res++);
    state = L->ci->state;
    L->ci->state = 2;
    for (o = L->top; o < res;) setnilvalue(L, o++);
    for (o = L->top; o >= res;) setnilvalue(L, o--);
    L->ci->state = state;
    L->top = res;
}

/* luaH_setnum (ltable.c), expanded by LTCG */
LUA2_FORCEINLINE TValue *luaH_setnum_inl(lua_State *L, Table *t, int key)
{
    const TValue *p = fn_88811930(t, key);
    if (p != &lbl_880C9748) return (TValue *)p;
    else {
        TValue k;
        k.tt = LUA2_TNUMBER;
        k.value.n = (double)key;
        return lua2_newkey_88812790(L, t, &k);
    }
}

/* copy into a fresh slot: no old value to release */
#define setobj2n(obj1, obj2) \
    { \
        const TValue *o2 = (obj2); \
        TValue *o1 = (obj1); \
        o1->tt = o2->tt; \
        o1->value = o2->value; \
        LUA2_ADDREF(o1); \
    }

/* adjust_varargs: collect the extra arguments into the `arg' table */
LUA2_NOINLINE void lua2_adjust_varargs_8881DBB8(lua_State *L, int nfixargs, StkId base)
{
    int i;
    Table *htab;
    TValue nname;
    int actual = L->top - base; /* actual number of arguments */
    nname.tt = LUA2_TNIL;
    nname.value.p = 0;
    if (actual < nfixargs) {
        int n = nfixargs - actual;
        checkstack_ldo(L, n);
        for (; actual < nfixargs; ++actual) setnilvalue(L, L->top++);
    }
    actual -= nfixargs; /* number of extra arguments */
    htab = ts4_if_call_seq_fn_889CE718_88811AC0(L, actual, 1); /* create `arg' table */
    for (i = 0; i < actual; i++) /* put extra arguments into `arg' table */
        setobj2n(luaH_setnum_inl(L, htab, i + 1), L->top - actual + i);
    /* store counter in field `n' */
    setgcvalue(L, &nname, lua2_luaS_newlstr_888131A0(L, lbl_880E18AC, 1), LUA2_TSTRING);
    {
        TValue *o = lua2_luaH_set_888122E8(L, htab, &nname);
        LUA2_RELEASE(L, o);
        o->tt = LUA2_TNUMBER;
        o->value.n = (double)actual;
    }
    while (actual--) setnilvalue(L, --L->top); /* remove extra elements from the stack */
    setgcvalue(L, L->top, htab, LUA2_TTABLE);
    checkstack_ldo(L, 1);
    L->top++;
    LUA2_RELEASE(L, &nname);
}

#define LUA_HOOKCALL 0
#define LUA_MASKCALL 1
#define CI_SAVEDPC 8
#define CI_YIELD 16
#define LUA_MULTRET (-1)
#define LUA_MAXCCALLS 200
#define GETARG_C(i) ((int)(((i) >> 6) & 0x1FF))

/* luaD_precall */
LUA2_NOINLINE StkId lua2_luaD_precall_8881DF48(lua_State *L, StkId func)
{
    LClosure *cl;
    int funcr = savestack(L, func);
    if (ttype(func) != LUA2_TFUNCTION) /* `func' is not a function? */
        func = lua2_tryfuncTM_8881D7E0(L, func); /* check the `function' tag method */
    if (L->ci + 1 == L->end_ci) lua2_luaD_growCI_8881D3D8(L);
    cl = &clvalue(func)->l;
    if (!cl->isC) { /* Lua function? prepare its call */
        CallInfo *ci;
        Proto *p = cl->p;
        if (p->is_vararg) /* varargs? */
            lua2_adjust_varargs_8881DBB8(L, p->numparams, func + 1);
        checkstack_ldo(L, p->maxstacksize);
        ci = ++L->ci; /* now `enter' new function */
        L->base = L->ci->base = restorestack(L, funcr) + 1;
        ci->top = L->base + p->maxstacksize;
        ci->savedpc = p->code; /* starting point */
        ci->tailcalls = 0;
        ci->state = CI_SAVEDPC;
        while (L->top < ci->top) setnilvalue(L, L->top++);
        L->top = ci->top;
        return 0;
    } else { /* if is a C function, call it */
        CallInfo *ci;
        int n;
        checkstack_ldo(L, LUA_MINSTACK); /* ensure minimum stack size */
        ci = ++L->ci;                    /* now `enter' new function */
        L->base = L->ci->base = restorestack(L, funcr) + 1;
        ci->top = L->top + LUA_MINSTACK;
        ci->state = CI_C; /* a C function */
        if (L->hookmask & LUA_MASKCALL) lua2_luaD_callhook_8881D5A8(L, LUA_HOOKCALL, -1);
        n = (*clvalue(L->base - 1)->c.f)(L); /* do the actual call */
        return L->top - n;
    }
}

/* resume */
LUA2_NOINLINE void lua2_resume_8881E180(lua_State *L, void *ud)
{
    StkId firstResult;
    int nargs = *(int *)ud;
    CallInfo *ci = L->ci;
    if (ci == L->base_ci) /* no activation record? */
        lua2_luaD_precall_8881DF48(L, L->top - (nargs + 1)); /* start coroutine */
    else {                                                   /* inside a yield */
        if (ci->state & CI_C) {                              /* `common' yield? */
            /* finish interrupted execution of `OP_CALL' */
            int nresults = GETARG_C(*((ci - 1)->savedpc - 1)) - 1;
            lua2_luaD_poscall_8881D9A0(L, nresults, L->top - nargs); /* complete it */
            if (nresults >= 0) L->top = L->ci->top;
        } else /* yielded inside a hook: just continue its execution */
            ci->state &= ~CI_YIELD;
    }
    firstResult = fn_8880D5E0(L);
    if (firstResult != 0) /* return from Lua function? */
        lua2_luaD_poscall_8881D9A0(L, LUA_MULTRET, firstResult); /* finalize this coroutine */
}

/* luaD_call */
void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nResults)
{
    StkId firstResult;
    if (++L->nCcalls >= LUA_MAXCCALLS) {
        if (L->nCcalls == LUA_MAXCCALLS)
            lua3_luaG_runerror_8881FB60(L, lbl_880E2704);
        else if (L->nCcalls >= (LUA_MAXCCALLS + (LUA_MAXCCALLS >> 3)))
            luaD_throw_inl(L, LUA_ERRERR); /* error while handing stack error */
    }
    firstResult = lua2_luaD_precall_8881DF48(L, func);
    if (firstResult == 0)                 /* is a Lua function? */
        firstResult = fn_8880D5E0(L);     /* call it */
    lua2_luaD_poscall_8881D9A0(L, nResults, firstResult);
    L->nCcalls--;
    if (G(L)->nblocks >= G(L)->GCthreshold) ts4_call_seq_fn_8881C130_8881C200(L); /* luaC_checkGC */
}

/* LuaPlus: reset the stack to the current function's base and push the message `s'
   (no direct callers in the image). */
int lua2_seterrorstring_8881E488(lua_State *L, const char *s)
{
    L->top = L->ci->base;
    setgcvalue(L, L->top, lua2_luaS_newlstr_888131A0(L, s, strlen(s)), LUA2_TSTRING);
    checkstack_ldo(L, 1);
    L->top++;
    return 1;
}

/* luaD_seterrorobj */
void lua2_luaD_seterrorobj_8881E590(lua_State *L, int errcode, StkId oldtop)
{
    switch (errcode) {
    case LUA_ERRMEM:
        setgcvalue(L, oldtop, lua2_luaS_newlstr_888131A0(L, lbl_880E26C8, 17), LUA2_TSTRING);
        break;
    case LUA_ERRERR:
        setgcvalue(L, oldtop, lua2_luaS_newlstr_888131A0(L, lbl_880E26DC, 23), LUA2_TSTRING);
        break;
    case LUA_ERRSYNTAX:
    case LUA_ERRRUN:
        setobj(L, oldtop, L->top - 1); /* error message on current top */
        break;
    }
    L->top = oldtop + 1;
}
