/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* lstate.c: global and per-thread state; LuaPlus allocator hooks. */
#include "lua2.h"
#ifdef _MSC_VER
void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
#else
#define _ReadWriteBarrier() ((void)0)
#endif

extern void *lbl_88C6A10C; /* default allocator */
extern void *lbl_88D459EC; /* default allocator data */
extern void *ts4_if_call_seq_fn_885651F8_88813510(void *ud, void *block, u32 osize, u32 nsize, int flags, int inrealloc);
extern void fn_88569D30(void *jb, int v);                  /* longjmp */
extern LUA2_NORETURN void ts4_tailcall_fn_88564208_885643D0(int status); /* exit */

extern lua_State *ts4_if_get_u32_off14_88813840(lua_State *L); /* mallocstate */
extern void lua2_luaF_close_8881C3C0(lua_State *L, StkId level);            /* luaF_close */
extern void lua2_luaC_separateudata_8881B770(lua_State *L);                         /* luaC_separateudata */
extern int lua2_luaD_rawrunprotected_8881D300(lua_State *L, void (*f)(lua_State *, void *), void *ud); /* luaD_rawrunprotected */
extern void ts4_forward_88813590(lua_State *L, void *ud);      /* callallgcTM */
extern void fn_88813C38(lua_State *L, void *ud); /* f_luaopen */
extern void fn_88813A68(lua_State *L); /* close_state */

#define BASIC_CI_SIZE 8
#define BASIC_STACK_SIZE 40
#define EXTRA_STACK 5
#define LUA_MINSTACK 20

/* Install the allocator used by lua_open. */
void lua2_lua_setdefaultallocator_88813560(void *f, void *ud)
{
    if (f) lbl_88C6A10C = f;
    else lbl_88C6A10C = (void *)ts4_if_call_seq_fn_885651F8_88813510;
    lbl_88D459EC = ud;
}

LUA2_FORCEINLINE void luaM_free_inl(lua_State *L, void *block, u32 osize)
{
    global_State *g = G(L);
    g->frealloc(g->ud, block, osize, 0, 0, L->inrealloc);
    g->nblocks -= osize;
}

/* luaM_malloc with the out-of-memory path of luaM_realloc. */
LUA2_FORCEINLINE void *luaM_malloc_inl(lua_State *L, u32 size)
{
    global_State *g = G(L);
    void *b = g->frealloc(g->ud, 0, 0, size, 0, L->inrealloc);
    if (b == 0) {
        if (L->errorJmp) {
            L->errorJmp->status = 4;
            fn_88569D30(L->errorJmp->b, 1);
        }
        G(L)->panic(L);
        ts4_tailcall_fn_88564208_885643D0(1);
    }
    g->nblocks += size;
    return b;
}

/* freestack */
void lua2_freestack_88813598(lua_State *L, lua_State *L1)
{
    luaM_free_inl(L, L1->base_ci, L1->size_ci * sizeof(CallInfo));
    luaM_free_inl(L, L1->stack, L1->stacksize * sizeof(TValue));
}

/* stack_init */
void lua2_stack_init_88813638(lua_State *L1, lua_State *L)
{
    TValue *p;
    L1->stack = (TValue *)luaM_malloc_inl(L, (BASIC_STACK_SIZE + EXTRA_STACK) * sizeof(TValue));
    L1->stacksize = BASIC_STACK_SIZE + EXTRA_STACK;
    L1->top = L1->stack;
    L1->stack_last = L1->stack + (L1->stacksize - EXTRA_STACK) - 1;
    for (p = L1->stack; p != L1->stack_last; p++) {
        p->tt = LUA2_TNIL;
        p->value.p = 0;
    }
    L1->ci = L1->base_ci = (CallInfo *)luaM_malloc_inl(L, BASIC_CI_SIZE * sizeof(CallInfo));
    L1->ci->state = 1;
    {
        TValue *o = L1->top++;
        o->tt = LUA2_TNIL;
        o->value.p = 0;
    }
    L1->base = L1->ci->base = L1->top;
    L1->ci->top = L1->top + LUA_MINSTACK;
    L1->size_ci = BASIC_CI_SIZE;
    L1->end_ci = L1->base_ci + BASIC_CI_SIZE;
}

/* luaM_freelem(L, L1) */
void lua2_freestate_888137E8(lua_State *L, lua_State *L1)
{
    luaM_free_inl(L, L1, sizeof(lua_State));
}

LUA2_FORCEINLINE void preinit_state(lua_State *L)
{
    L->stack = 0;
    L->stacksize = 0;
    L->errorJmp = 0;
    L->hook = 0;
    L->hookmask = L->hookinit = 0;
    L->basehookcount = 0;
    L->allowhook = 1;
    L->hookcount = L->basehookcount;
    L->openupval = 0;
    L->size_ci = 0;
    L->nCcalls = 0;
    L->base_ci = L->ci = 0;
    L->errfunc = 0;
    L->stateUserData = 0;
    L->_gt.tt = LUA2_TNIL;
    L->_gt.value.p = 0;
}

/* lua_close */
void lua2_lua_close_88813BA8(lua_State *L)
{
    L = G(L)->mainthread;
    lua2_luaF_close_8881C3C0(L, L->stack);
    lua2_luaC_separateudata_8881B770(L);
    L->errfunc = 0;
    do {
        L->ci = L->base_ci;
        L->base = L->top = L->ci->base;
        L->nCcalls = 0;
    } while (lua2_luaD_rawrunprotected_8881D300(L, ts4_forward_88813590, 0) != 0);
    fn_88813A68(L);
}


/* lua_open */
lua_State *lua2_lua_open_888140E0(void)
{
    lua_State *L;
    lua_State dummyL;
    global_State dummyG;
    dummyL.l_G = &dummyG;
    dummyG.frealloc = (void *(*)(void *, void *, u32, u32, int, int))lbl_88C6A10C;
    dummyG.ud = lbl_88D459EC;
    dummyG.nblocks = sizeof(lua_State) + sizeof(global_State);
    L = ts4_if_get_u32_off14_88813840(&dummyL);
    if (L) {
        L->h.marked = 0;
        L->h.tt = LUA2_TTHREAD;
        L->gclist = 0;
        L->h.next = 0;
        preinit_state(L);
        L->l_G = 0;
        if (lua2_luaD_rawrunprotected_8881D300(L, fn_88813C38, 0) != 0) {
            fn_88813A68(L);
            L = 0;
        }
    }
    return L;
}

/* Reserved-word style token test. */
int lua2_isspecialtoken_888141D8(int c)
{
    switch (c) {
    case 0x105:
    case 0x106:
    case 0x107:
    case 0x115:
    case 0x123:
        return 1;
    default:
        return 0;
    }
}
