/* Derived from Lua 5.0.2 lmem.c (MIT); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "lua2.h"

extern LUA2_NORETURN void fn_88569D30(void *jb, int v);                  /* longjmp */
extern LUA2_NORETURN void ts4_tailcall_fn_88564208_885643D0(int status); /* exit */
extern char lbl_880E29A0[]; /* "memory allocation error: block too big" */

LUA2_DEFINE_RUNERROR

/* luaM_realloc */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void *cx19_luaM_realloc_889CE718(lua_State *L, void *block, u32 oldsize, u32 size)
{
    global_State *g = G(L);
    if (size >= (u32)-3) lua3_luaG_runerror_8881FB60(L, lbl_880E29A0);
    block = g->frealloc(g->ud, block, oldsize, size, 0, L->inrealloc);
    if (block == 0 && size != 0) {
        if (L->errorJmp) {
            L->errorJmp->status = 4;
            fn_88569D30(L->errorJmp->b, 1);
        }
        G(L)->panic(L);
        ts4_tailcall_fn_88564208_885643D0(1);
    }
    g->nblocks = g->nblocks - oldsize + size;
    return block;
}

extern void *cx19_luaM_realloc_889CE718(lua_State *L, void *block, u32 oldsize, u32 size);

#define MINSIZEARRAY 4

/* luaM_growaux */
void *cx19_luaM_growaux_889CE7D8(lua_State *L, void *block, int *size, int size_elems, int limit, const char *errormsg)
{
    void *newblock;
    int newsize = (*size) * 2;
    if (newsize < MINSIZEARRAY)
        newsize = MINSIZEARRAY;
    else if (*size >= limit / 2) {
        if (*size < limit - MINSIZEARRAY)
            newsize = limit;
        else
            lua3_luaG_runerror_8881FB60(L, errormsg);
    }
    newblock = cx19_luaM_realloc_889CE718(L, block, (*size) * size_elems, newsize * size_elems);
    *size = newsize;
    return newblock;
}
