/* Derived from Lua 5.0.2 ldo.c (MIT); see THIRD_PARTY_NOTICES.md */
/* ldo.c tail: protected calls, coroutine resume and the protected parser (LuaPlus variant). */
#include "lua2.h"

#define CI_YIELD 16

typedef void (*Pfunc)(lua_State *L, void *ud);

/* ZIO with the LuaPlus unicode flag at +0x14. */
typedef struct Zio {
    u32 n;
    const char *p;
    void *reader;
    void *data;
    const char *name;
    int unicode;
} ZIO;

struct SParser {
    ZIO *z;
    Mbuffer buff;
    int bin;
};

extern int lua2_luaD_rawrunprotected_8881D300(lua_State *L, Pfunc f, void *ud);
extern void lua2_luaF_close_8881C3C0(lua_State *L, StkId level);
extern void lua2_luaD_seterrorobj_8881E590(lua_State *L, int errcode, StkId oldtop);
extern void ts4_if_get_u32_off24_8881D2B0(lua_State *L);       /* restore_stack_limit */
extern void ts4_get_u32_off4_88822960(lua_State *L, void *ud); /* f_call (lapi.c) */
extern int lua2_seterrorstring_8881E488(lua_State *L, const char *s); /* resume_error */
extern void lua2_resume_8881E180(lua_State *L, void *ud);
extern void ts4_call_seq_fn_8881C130_8881C200(lua_State *L); /* luaC_checkGC body */
extern int ex3_luaZ_lookahead16_8880C1B0(ZIO *z);
extern int ex3_luaZ_fill_8880C040(ZIO *z);
extern Proto *ts4_if_call_seq_u32_off10_88811060(lua_State *L, ZIO *z, Mbuffer *buff); /* luaU_undump */
extern Proto *lua2_luaY_parser_888178D8(lua_State *L, ZIO *z, Mbuffer *buff);
extern Closure *lua2_luaF_newLclosure_8881C580(lua_State *L, int nelems, TValue *e);
extern char lbl_880E2718[]; /* "cannot resume dead coroutine" */
extern char lbl_880E2738[]; /* "cannot resume non-suspended coroutine" */

/* luaD_pcall; LTCG folded the function argument to f_call. Values left above the error object are released. */
int lua3_luaD_pcall_8881E748(lua_State *L, void *u, int old_top, int ef)
{
    int status;
    int old_errfunc = L->errfunc;
    u16 oldnCcalls;
    int old_ci;
    lu_byte old_allowhooks;
    L->errfunc = ef;
    old_ci = (char *)L->ci - (char *)L->base_ci;
    oldnCcalls = L->nCcalls;
    old_allowhooks = L->allowhook;
    status = lua2_luaD_rawrunprotected_8881D300(L, ts4_get_u32_off4_88822960, u);
    if (status != 0) { /* an error occurred? */
        StkId oldtop = restorestack(L, old_top);
        StkId top = L->top;
        StkId o;
        lua2_luaF_close_8881C3C0(L, oldtop); /* close eventual pending closures */
        lua2_luaD_seterrorobj_8881E590(L, status, oldtop);
        for (o = L->top; o < top;) setnilvalue(L, o++);
        L->nCcalls = oldnCcalls;
        L->ci = (CallInfo *)((char *)L->base_ci + old_ci);
        L->base = L->ci->base;
        L->allowhook = old_allowhooks;
        ts4_if_get_u32_off24_8881D2B0(L);
    }
    L->errfunc = old_errfunc;
    return status;
}

/* lua_resume */
int lua3_lua_resume_8881E858(lua_State *L, int nargs)
{
    int status;
    lu_byte old_allowhooks;
    if (L->ci == L->base_ci) {
        if (nargs >= L->top - L->base) return lua2_seterrorstring_8881E488(L, lbl_880E2718);
    } else if (!(L->ci->state & CI_YIELD)) /* not inside a yield? */
        return lua2_seterrorstring_8881E488(L, lbl_880E2738);
    old_allowhooks = L->allowhook;
    status = lua2_luaD_rawrunprotected_8881D300(L, lua2_resume_8881E180, &nargs);
    if (status != 0) { /* error? */
        L->ci = L->base_ci; /* go back to initial level */
        L->base = L->ci->base;
        L->nCcalls = 0;
        lua2_luaF_close_8881C3C0(L, L->base); /* close eventual pending closures */
        lua2_luaD_seterrorobj_8881E590(L, status, L->base);
        L->allowhook = old_allowhooks;
        ts4_if_get_u32_off24_8881D2B0(L);
    }
    return status;
}

#define zgetc(z) (((z)->n--) > 0 ? (*(z)->p++) : ex3_luaZ_fill_8880C040(z))

/* f_parser: a UTF-16 byte-order mark switches the stream to unicode */
void lua3_f_parser_8881E940(lua_State *L, void *ud)
{
    struct SParser *p;
    Proto *tf;
    Closure *cl;
    if (G(L)->nblocks >= G(L)->GCthreshold) ts4_call_seq_fn_8881C130_8881C200(L);
    p = (struct SParser *)ud;
    if (ex3_luaZ_lookahead16_8880C1B0(p->z) == 0xFEFF) {
        zgetc(p->z);
        zgetc(p->z);
        p->z->unicode = 1;
    }
    tf = p->bin ? ts4_if_call_seq_u32_off10_88811060(L, p->z, &p->buff)
                : lua2_luaY_parser_888178D8(L, p->z, &p->buff);
    cl = lua2_luaF_newLclosure_8881C580(L, 0, &L->_gt);
    cl->l.p = tf;
    tf->h.refs++;
    setgcvalue(L, L->top, cl, LUA2_TFUNCTION);
    luaD_checkstack(L, 1);
    L->top++;
}

/* luaD_protectedparser */
int lua3_luaD_protectedparser_8881EAF8(lua_State *L, ZIO *z, int bin)
{
    struct SParser p;
    int status;
    int oldtopr = savestack(L, L->top); /* save current top */
    p.z = z;
    p.bin = bin;
    p.buff.buffer = 0;
    p.buff.buffsize = 0;
    status = lua2_luaD_rawrunprotected_8881D300(L, lua3_f_parser_8881E940, &p);
    {
        global_State *g = G(L);
        u32 osize = p.buff.buffsize;
        char *nb = (char *)g->frealloc(g->ud, p.buff.buffer, osize, 0, 0, L->inrealloc);
        g->nblocks -= osize;
        p.buff.buffer = nb;
        p.buff.buffsize = 0;
    }
    if (status != 0) { /* error? */
        StkId oldtop = restorestack(L, oldtopr);
        lua2_luaD_seterrorobj_8881E590(L, status, oldtop);
    }
    return status;
}
