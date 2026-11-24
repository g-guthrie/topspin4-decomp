/* Derived from Lua 5.0.2 ldebug.c (MIT); see THIRD_PARTY_NOTICES.md */
/* ldebug.c error path: luaG_errormsg, luaG_runerror and lua_getinfo, whose callers see both as non-returning. */
/* lua2.h declares luaG_errormsg without noreturn; hide that declaration here. */
#define lua3_luaG_errormsg_8881F900 lua3_luaG_errormsg_hdr_decl
#include "lua3.h"
#undef lua3_luaG_errormsg_8881F900

#define LUA_ERRRUN 1
#define LUA_ERRERR 5

extern char lbl_880E25D8[]; /* "value for `lua_getinfo' is not a function" */
extern void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nResults);
extern const char *lua3_luaO_pushvfstring_888188F8(lua_State *L, const char *fmt, va_list argp); /* luaO_pushvfstring */
extern void lua3_addinfo_8881FAD0(lua_State *L, const char *msg);
extern int lua3_getinfo_8881FBB8(lua_State *L, const char *what, lua_Debug *ar, StkId f, CallInfo *ci);
extern void lua3_info_tailcall_8881FD48(lua_State *L, lua_Debug *ar);
extern char *fn_88563500(const char *s, int c); /* strchr */

LUA2_FORCEINLINE LUA2_NORETURN void luaD_throw_inl(lua_State *L, int errcode)
{
    if (L->errorJmp) {
        L->errorJmp->status = errcode;
        fn_88569D30(L->errorJmp->b, 1);
    }
    G(L)->panic(L);
    ts4_tailcall_fn_88564208_885643D0(1);
}

/* luaG_errormsg */
LUA3_NORETURN void lua3_luaG_errormsg_8881F900(lua_State *L)
{
    if (L->errfunc != 0) { /* is there an error handling function? */
        StkId errfunc = restorestack(L, L->errfunc);
        if (ttype(errfunc) != LUA2_TFUNCTION) luaD_throw_inl(L, LUA_ERRERR);
        setobj(L, L->top, L->top - 1); /* move argument */
        setobj(L, L->top - 1, errfunc); /* push function */
        luaD_checkstack(L, 1);
        L->top++;
        lua2_luaD_call_8881E258(L, L->top - 2, 1); /* call it */
    }
    luaD_throw_inl(L, LUA_ERRRUN);
}

/* luaG_runerror */
void lua3_luaG_runerror_8881FB60(lua_State *L, const char *fmt, ...)
{
    const char *msg;
    va_list argp;
    va_start(argp, fmt);
    msg = lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    va_end(argp);
    lua3_addinfo_8881FAD0(L, msg);
    lua3_luaG_errormsg_8881F900(L);
}

/* lua_getinfo */
int lua3_lua_getinfo_8881FF18(lua_State *L, const char *what, lua_Debug *ar)
{
    int status = 1;
    if (*what == '>') {
        StkId f = L->top - 1;
        if (ttype(f) != LUA2_TFUNCTION) lua3_luaG_runerror_8881FB60(L, lbl_880E25D8);
        status = lua3_getinfo_8881FBB8(L, what + 1, ar, f, 0);
        L->top--; /* pop function */
    } else if (ar->i_ci != 0) { /* no tail call? */
        CallInfo *ci = L->base_ci + ar->i_ci;
        status = lua3_getinfo_8881FBB8(L, what, ar, ci->base - 1, ci);
    } else
        lua3_info_tailcall_8881FD48(L, ar);
    if (fn_88563500(what, 'f')) {
        luaD_checkstack(L, 1);
        L->top++;
    }
    return status;
}

