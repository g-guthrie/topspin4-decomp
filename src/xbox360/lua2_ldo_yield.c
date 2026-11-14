/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* ldo.c, lua_yield: it sits in its own file because it sees the luaG_runerror body (which sets its
   frame size), while luaD_call and luaD_growCI in lua2_ldo.c must not. */
#include "lua2.h"

#define CI_C 1
#define CI_YIELD 16

extern char lbl_880E2760[]; /* "attempt to yield across metamethod/C-call boundary" */
extern char lbl_880E2794[]; /* "cannot yield a C function" */

LUA2_DEFINE_RUNERROR

/* lua_yield */
int lua2_lua_yield_8881E350(lua_State *L, int nresults)
{
    CallInfo *ci;
    ci = L->ci;
    if (L->nCcalls > 0) lua3_luaG_runerror_8881FB60(L, lbl_880E2760);
    if (ci->state & CI_C) { /* usual yield */
        if ((ci - 1)->state & CI_C) lua3_luaG_runerror_8881FB60(L, lbl_880E2794);
        if (L->top - nresults > L->base) { /* is there garbage in the stack? */
            int i;
            for (i = 0; i < nresults; i++) /* move down results */
                setobj(L, L->base + i, L->top - nresults + i);
            L->top = L->base + nresults;
        }
    } /* else it's an yield inside a hook: nothing to do */
    ci->state |= CI_YIELD;
    return -1;
}
