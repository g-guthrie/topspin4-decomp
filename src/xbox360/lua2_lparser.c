/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* lparser.c: LuaPlus parser (continue, numbered break/continue, reference-counted protos). */
#include "lua2_lparser.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
double floor(double x);
#pragma intrinsic(strlen)
void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
#else
#define _ReadWriteBarrier() ((void)0)
#include <string.h>
#include <math.h>
#endif

extern char lbl_880E2868[]; /* "too many %s (limit=%d)" */
extern char lbl_880E2A60[]; /* "items in a constructor" */
extern char lbl_880E2A34[]; /* "upvalues" */
extern char lbl_880E2A24[]; /* "local variables" */
extern char lbl_880E2A40[]; /* "parameters" */
extern char lbl_880E2A4C[]; /* "arg" */
extern char lbl_880E29D8[]; /* "`%s' expected" */
extern char lbl_880E29E8[]; /* "`%s' expected (to close `%s' at line %d)" */
extern char lbl_880E2550[]; /* "function or expression too complex" */
extern char lbl_880E2574[]; /* "constant table overflow" */
extern char lbl_880E2A9C[]; /* "<name> or `...' expected" */
extern char lbl_880E2BA8[]; /* "loop block number must be integer" */
extern char lbl_880E2BCC[]; /* "loop block number out of range" */
extern char lbl_880E2C00[]; /* "no loop to continue" */
extern char lbl_880E2BEC[]; /* "no loop to break" */
extern char lbl_880C1320[]; /* "" */
extern char lbl_880E2A14[]; /* "<name> expected" */
extern char lbl_880E2A78[]; /* "size expected following & (line %d)" */
extern char lbl_880E2AF4[]; /* "function arguments expected" */
extern char lbl_880E2AC0[]; /* "ambiguous syntax (function call x new statement)" */
extern char lbl_880DCDF4[]; /* "syntax error" */
extern char lbl_880E2B24[]; /* "too many syntax levels" */
extern char lbl_880E2B3C[]; /* "`while' condition too complex" */
extern char lbl_880E2B5C[]; /* "(for limit)" */
extern char lbl_880E2B68[]; /* "(for step)" */
extern const char *const lbl_880C9858[]; /* luaX_tokens */
extern double g_ts4_script_constants[];   /* pooled constants; [15] == 1.0 */
extern char lbl_880E2B90[]; /* "`=' or `in' expected" */
extern char lbl_880E2A50[]; /* "<eof> expected" */
extern char lbl_880E2B74[]; /* "(for generator)" */
extern char lbl_880E2B84[]; /* "(for state)" */

struct ConsControl {
    expdesc v;
    expdesc *t;
    int nh;
    int na;
    int tostore;
};

extern TString *lua2_luaS_newlstr_888131A0(lua_State *L, const char *str, u32 l);
extern int ts4_if_call_seq_u32_off30_888147A0(LexState *ls, TString *varname); /* luaI_registerlocalvar */
LUA2_NOINLINE int lua2_subexpr_88816C30(LexState *ls, expdesc *v, int limit);                 /* subexpr */
extern void lua2_chunk_88817818(LexState *ls);                                        /* chunk */
extern void ts4_if_call_seq_u32_off14_88814F80(FuncState *fs);                /* leaveblock */
extern int ts4_call_seq_u32_off20_88820DD0(FuncState *fs);                    /* luaK_jump */
extern void lua2_luaK_concat_888203F0(FuncState *fs, int *l1, int l2);                      /* luaK_concat */

/* luaO_pushfstring: callers only get the original frame when the variadic body is visible. */
LUA2_LOCAL const char *ts4_forward_varargs_88818C40(lua_State *L, const char *fmt, ...)
{
    const char *msg;
    va_list argp;
    va_start(argp, fmt);
    msg = lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    va_end(argp);
    return msg;
}

extern void lua2_luaK_exp2nextreg_888214B0(FuncState *fs, expdesc *e); /* luaK_exp2nextreg */
extern void lua2_luaK_patchlistaux_88820468(FuncState *fs, int list, int vtarget, int reg, int dtarget, int reg2, int dtarget2); /* patchlistaux */

extern void lua2_luaK_setcallreturns_888200C8(FuncState *fs, expdesc *e, int nresults); /* luaK_setcallreturns */
extern void lua2_luaK_nil_88820E30(FuncState *fs, int from, int n);           /* luaK_nil */
extern int lua2_luaK_exp2anyreg_888216D0(FuncState *fs, expdesc *e);                 /* luaK_exp2anyreg */
extern int lua2_luaK_exp2RK_88821878(FuncState *fs, expdesc *e);                                  /* luaK_exp2RK */
extern void lua2_luaK_storevar_88821DC8(FuncState *fs, expdesc *var, expdesc *ex);                    /* luaK_storevar */
extern void ts4_if_call_seq_u32_off10_88815520(LexState *ls, expdesc *e);             /* checkname */
extern void ts4_if_call_seq_fn_88814BB8_88815F80(LexState *ls, expdesc *v);           /* yindex */
extern void ts4_if_call_seq_fn_888145C8_88815860(LexState *ls, expdesc *e, int needself, int line); /* body */
extern void ts4_if_call_seq_u32_off0_88815A40(FuncState *fs, struct ConsControl *cc); /* closelistfield */
extern void ts4_loop_call_seq_fn_88814418_88814950(FuncState *fs, TString *n, expdesc *var, int base); /* singlevaraux */
extern int lua2_luaK_stringK_88820AF0(FuncState *fs, TString *s);                                    /* luaK_stringK */
extern void ts4_call_seq_u32_off30_888164B0(LexState *ls, expdesc *v);                /* luaY_field */
extern void ts4_if_call_seq_u32_off10_888157D8(LexState *ls, expdesc *v);            /* prefixexp */
extern void lua2_luaK_self_88821CC0(FuncState *fs, expdesc *e, expdesc *key);                     /* luaK_self */
extern int lua2_luaK_numberK_88820A68(FuncState *fs, double r);                                     /* luaK_numberK */
extern int lua2_luaK_wstringK_888207C8(FuncState *fs, TString *s);                                    /* luaK_wstringK (LuaPlus) */
extern void lua2_luaK_prefix_88821770(FuncState *fs, int op, expdesc *e);                           /* luaK_prefix */
extern int ts4_key_to_index_88814210(int op);                                         /* getbinopr */
extern void ts4_if_call_seq_fn_888214B0_88821BC8(FuncState *fs, int op, expdesc *v);  /* luaK_infix */
extern void lua2_luaK_posfix_88821928(FuncState *fs, int op, expdesc *e1, expdesc *e2);             /* luaK_posfix */
struct lua2_priority {
    lu_byte left;
    lu_byte right;
};
extern const struct lua2_priority lbl_880C96E8[]; /* priority */
extern void lua2_luaK_goiffalse_88821568(FuncState *fs, expdesc *e);                                  /* luaK_goiffalse */
extern void ts4_if_call_seq_fn_88816C30_88817030(LexState *ls, expdesc *v);           /* cond */
extern void lua2_luaK_goiftrue_88821618(FuncState *fs, expdesc *e);                                   /* luaK_goiftrue */
extern int ts4_parser_dispatch_88817680(LexState *ls);                                /* statement */
extern void lua2_luaX_setinput_88819238(lua_State *L, LexState *ls, void *z, TString *source);        /* luaX_setinput */
extern void ts4_call_seq_u32_off34_888145C8(LexState *ls, FuncState *fs);             /* open_func */
#define SETARG_B(i, b) ((i) = (((i)&MASK0(9, 15)) | (((Instruction)(b) << 15) & MASK1(9, 15))))
#define SET_OPCODE(i, o) ((i) = (((i)&MASK0(6, 0)) | ((Instruction)(o)&MASK1(6, 0))))
#define NO_REG 0xFF
#define LUA_MULTRET (-1)
#define LFIELDS_PER_FLUSH 32
#define MASK1(n, p) ((~((~(Instruction)0) << (n))) << (p))
#define MASK0(n, p) (~MASK1(n, p))
#define SETARG_C(i, b) ((i) = (((i)&MASK0(9, 6)) | (((Instruction)(b) << 6) & MASK1(9, 6))))
#define GETARG_A(i) ((int)((i) >> 24))
#define getcode(fs, e) ((fs)->f->code[(e)->info])
#define MAXARG_sBx (MAXARG_Bx >> 1)

#define luaM_growvector(L, v, nelems, size, t, limit, e) \
    if (((nelems) + 1) > (size)) ((v) = (t *)fn_889CE7D8(L, v, &(size), sizeof(t), limit, e))
#define luaM_reallocvector(L, v, oldn, n, t) \
    ((v) = (t *)fn_889CE718(L, v, (oldn) * (u32)sizeof(t), (n) * (u32)sizeof(t)))

LUA2_FORCEINLINE void luaX_checklimit(LexState *ls, int val, int limit, const char *msg)
{
    if (val > limit) {
        msg = ts4_forward_varargs_88818C40(ls->L, lbl_880E2868, msg, limit);
        lua2_luaX_syntaxerror_888195F0(ls, msg);
    }
}

LUA2_FORCEINLINE void luaK_checkstack(FuncState *fs, int n)
{
    int newstack = fs->freereg + n;
    if (newstack > fs->f->maxstacksize) {
        if (newstack >= MAXSTACK) lua2_luaX_syntaxerror_888195F0(fs->ls, lbl_880E2550);
        fs->f->maxstacksize = (lu_byte)newstack;
    }
}

LUA2_FORCEINLINE void luaK_reserveregs(FuncState *fs, int n)
{
    luaK_checkstack(fs, n);
    fs->freereg += n;
}

LUA2_FORCEINLINE int luaK_codeABC(FuncState *fs, OpCode o, int a, int b, int c)
{
    return lua2_luaK_code_888208A8(fs, CREATE_ABC(o, a, b, c));
}

LUA2_FORCEINLINE int luaK_codeABx(FuncState *fs, OpCode o, int a, unsigned int bc)
{
    return lua2_luaK_code_888208A8(fs, CREATE_ABx(o, a, bc));
}

LUA2_FORCEINLINE void init_exp(expdesc *e, expkind k, int i)
{
    e->f = e->t = NO_JUMP;
    e->k = k;
    e->info = i;
}

LUA2_FORCEINLINE void adjustlocalvars_inl(LexState *ls, int nvars)
{
    FuncState *fs = ls->fs;
    fs->nactvar += nvars;
    for (; nvars; nvars--) getlocvar(fs, fs->nactvar - nvars).startpc = fs->pc;
}

/* searchvar */
LUA2_NOINLINE int lua2_searchvar_88814418(FuncState *fs, TString *n)
{
    int i;
    for (i = fs->nactvar - 1; i >= 0; i--) {
        if (n == getlocvar(fs, i).varname) return i;
    }
    return -1;
}

/* removevars */
LUA2_NOINLINE void lua2_removevars_88814470(LexState *ls, int tolevel)
{
    FuncState *fs = ls->fs;
    while (fs->nactvar > tolevel) getlocvar(fs, --fs->nactvar).endpc = fs->pc;
}

/* adjustlocalvars */
LUA2_NOINLINE void lua2_adjustlocalvars_888144C8(LexState *ls, int nvars)
{
    FuncState *fs = ls->fs;
    fs->nactvar += nvars;
    for (; nvars; nvars--) getlocvar(fs, fs->nactvar - nvars).startpc = fs->pc;
}


/* listfield */
LUA2_NOINLINE void lua2_listfield_88814540(LexState *ls, struct ConsControl *cc)
{
    lua2_subexpr_88816C30(ls, &cc->v, -1);
    luaX_checklimit(ls, cc->na, MAXARG_Bx, lbl_880E2A60);
    cc->na++;
    cc->tostore++;
}

/* newupvalue: the upvalue name gains a reference. */
LUA2_NOINLINE int lua2_newupvalue_88814668(FuncState *fs, TString *name, expdesc *v)
{
    int i;
    Proto *f = fs->f;
    for (i = 0; i < f->nups; i++) {
        if (fs->upvalues[i].k == v->k && fs->upvalues[i].info == v->info) return i;
    }
    luaX_checklimit(fs->ls, f->nups + 1, MAXUPVALUES, lbl_880E2A34);
    luaM_growvector(fs->L, fs->f->upvalues, f->nups, fs->f->sizeupvalues, TString *, MAX_INT, lbl_880C1320);
    fs->f->upvalues[f->nups] = name;
    name->h.refs++;
    fs->upvalues[f->nups] = *v;
    return f->nups++;
}

/* error_expected */
LUA2_NOINLINE LUA2_NORETURN void lua2_error_expected_88814830(LexState *ls, int token)
{
    lua2_luaX_syntaxerror_888195F0(ls, ts4_forward_varargs_88818C40(ls->L, lbl_880E29D8, lua2_luaX_token2str_888194C0(ls, token)));
}

/* new_localvar */
LUA2_NOINLINE void lua2_new_localvar_88814868(LexState *ls, TString *name, int n)
{
    FuncState *fs = ls->fs;
    luaX_checklimit(ls, fs->nactvar + n + 1, MAXVARS, lbl_880E2A24);
    fs->actvar[fs->nactvar + n] = ts4_if_call_seq_u32_off30_888147A0(ls, name);
}

/* new_localvarstr */
LUA2_NOINLINE void lua2_new_localvarstr_888148E0(LexState *ls, const char *name, int n)
{
    lua2_new_localvar_88814868(ls, lua2_luaS_newlstr_888131A0(ls->L, name, strlen(name)), n);
}

/* create_local */
LUA2_NOINLINE void lua2_create_local_88814A70(LexState *ls, const char *name)
{
    lua2_new_localvarstr_888148E0(ls, name, 0);
    adjustlocalvars_inl(ls, 1);
}

/* next */
LUA2_NOINLINE void lua2_next_88814BB8(LexState *ls)
{
    ls->lastline = ls->linenumber;
    if (ls->lookahead.token != TK_EOS) {
        ls->t = ls->lookahead;
        ls->lookahead.token = TK_EOS;
    } else
        ls->t.token = lua2_luaX_lex_8881A6E8(ls, &ls->t.seminfo);
}

struct LHS_assign {
    struct LHS_assign *prev;
    expdesc v;
};

/* check_conflict */
LUA2_NOINLINE void lua2_check_conflict_88814C38(LexState *ls, struct LHS_assign *lh, expdesc *v)
{
    FuncState *fs = ls->fs;
    int extra = fs->freereg;
    int conflict = 0;
    for (; lh; lh = lh->prev) {
        if (lh->v.k == VINDEXED) {
            if (lh->v.info == v->info) {
                conflict = 1;
                lh->v.info = extra;
            }
            if (lh->v.aux == v->info) {
                conflict = 1;
                lh->v.aux = extra;
            }
        }
    }
    if (conflict) {
        lua2_luaK_code_888208A8(fs, CREATE_ABC(OP_MOVE, fs->freereg, v->info, 0));
        luaK_reserveregs(fs, 1);
    }
}

/* close_func: no line table in this build; the constant cache table is released. */
LUA2_NOINLINE void lua2_close_func_88814D20(LexState *ls)
{
    FuncState *fs = ls->fs;
    lua_State *L = ls->L;
    Proto *f = fs->f;
    lua2_removevars_88814470(ls, 0);
    lua2_luaK_code_888208A8(fs, CREATE_ABC(OP_RETURN, 0, 1, 0));
    luaM_reallocvector(L, f->code, f->sizecode, fs->pc, Instruction);
    f->sizecode = fs->pc;
    luaM_reallocvector(L, f->k, f->sizek, fs->nk, TValue);
    f->sizek = fs->nk;
    luaM_reallocvector(L, f->p, f->sizep, fs->np, Proto *);
    f->sizep = fs->np;
    luaM_reallocvector(L, f->locvars, f->sizelocvars, fs->nlocvars, LocVar);
    f->sizelocvars = fs->nlocvars;
    luaM_reallocvector(L, f->upvalues, f->sizeupvalues, f->nups, TString *);
    f->sizeupvalues = f->nups;
    ls->fs = fs->prev;
    {
        GCheader *h = &fs->h->h;
        if (--h->refs == 0) fn_88818C88(L, h);
    }
}

/* pushclosure: the child prototype gains a reference. */
LUA2_NOINLINE void lua2_pushclosure_88814E68(LexState *ls, FuncState *func, expdesc *v)
{
    FuncState *fs = ls->fs;
    Proto *f = fs->f;
    int i;
    luaM_growvector(ls->L, f->p, fs->np, f->sizep, Proto *, MAXARG_Bx, lbl_880E2574);
    f->p[fs->np++] = func->f;
    func->f->h.refs++;
    init_exp(v, VRELOCABLE, luaK_codeABx(fs, OP_CLOSURE, 0, fs->np - 1));
    for (i = 0; i < func->f->nups; i++) {
        OpCode o = (func->upvalues[i].k == VLOCAL) ? OP_MOVE : OP_GETUPVAL;
        luaK_codeABC(fs, o, 0, func->upvalues[i].info, 0);
    }
}

/* code_params */
LUA2_NOINLINE void lua2_code_params_88815008(LexState *ls, int nparams, int dots)
{
    FuncState *fs = ls->fs;
    lua2_adjustlocalvars_888144C8(ls, nparams);
    luaX_checklimit(ls, fs->nactvar, MAXPARAMS, lbl_880E2A40);
    fs->f->numparams = (lu_byte)fs->nactvar;
    fs->f->is_vararg = (lu_byte)dots;
    if (dots) lua2_create_local_88814A70(ls, lbl_880E2A4C);
    luaK_reserveregs(fs, fs->nactvar);
}

/* continuestat: `continue [n]' jumps to the continue list of the n-th enclosing loop. */
LUA2_NOINLINE void lua2_continuestat_88815140(LexState *ls)
{
    FuncState *fs = ls->fs;
    BlockCnt *bl = fs->bl;
    BlockCnt *prevbl = 0;
    int upval = 0;
    int prevupval = 0;
    int level = 1;
    lua2_next_88814BB8(ls);
    if (ls->t.token == TK_NUMBER) {
        double n;
        lua2_next_88814BB8(ls);
        n = ls->t.seminfo.r;
        if (n != floor(n)) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2BA8);
        level = (int)ls->t.seminfo.r;
        if (level < 1 || level > 100) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2BCC);
    }
    while (level > 0) {
        level--;
        prevupval = upval;
        while (bl && !bl->isbreakable) {
            upval |= bl->upval;
            bl = bl->previous;
        }
        if (bl && level > 0) {
            prevbl = bl;
            bl = bl->previous;
        }
    }
    if (!bl) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2C00);
    if (prevupval) lua2_luaK_code_888208A8(fs, CREATE_ABC(OP_CLOSE, prevbl->nactvar, 0, 0));
    lua2_luaK_concat_888203F0(fs, &bl->continuelist, ts4_call_seq_u32_off20_88820DD0(fs));
}

/* breakstat: `break [n]' leaves the n-th enclosing loop. */
LUA2_NOINLINE void lua2_breakstat_88815288(LexState *ls)
{
    FuncState *fs = ls->fs;
    BlockCnt *bl = fs->bl;
    int upval = 0;
    int level = 1;
    lua2_next_88814BB8(ls);
    if (ls->t.token == TK_NUMBER) {
        double n;
        lua2_next_88814BB8(ls);
        n = ls->t.seminfo.r;
        if (n != floor(n)) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2BA8);
        level = (int)ls->t.seminfo.r;
        if (level < 1 || level > 100) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2BCC);
    }
    while (level > 0) {
        level--;
        while (bl && !bl->isbreakable) {
            upval |= bl->upval;
            bl = bl->previous;
        }
        if (bl && level > 0) bl = bl->previous;
    }
    if (!bl) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2BEC);
    if (upval) lua2_luaK_code_888208A8(fs, CREATE_ABC(OP_CLOSE, bl->nactvar, 0, 0));
    lua2_luaK_concat_888203F0(fs, &bl->breaklist, ts4_call_seq_u32_off20_88820DD0(fs));
}

LUA2_FORCEINLINE void enterblock(FuncState *fs, BlockCnt *bl, int isbreakable)
{
    bl->breaklist = NO_JUMP;
    bl->continuelist = NO_JUMP;
    bl->isbreakable = isbreakable;
    bl->nactvar = fs->nactvar;
    bl->upval = 0;
    bl->previous = fs->bl;
    fs->bl = bl;
}

/* block */
LUA2_NOINLINE void lua2_block_888153C0(LexState *ls)
{
    FuncState *fs = ls->fs;
    BlockCnt bl;
    enterblock(fs, &bl, 0);
    lua2_chunk_88817818(ls);
    ts4_if_call_seq_u32_off14_88814F80(fs);
}

LUA2_FORCEINLINE int testnext(LexState *ls, int c)
{
    if (ls->t.token == c) {
        lua2_next_88814BB8(ls);
        return 1;
    }
    return 0;
}

LUA2_FORCEINLINE TString *str_checkname(LexState *ls)
{
    TString *ts;
    if (ls->t.token != TK_NAME) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2A14);
    ts = ls->t.seminfo.ts;
    lua2_next_88814BB8(ls);
    return ts;
}

/* parlist */
LUA2_NOINLINE void lua2_parlist_88815428(LexState *ls)
{
    int nparams = 0;
    int dots = 0;
    if (ls->t.token != ')') {
        do {
            switch (ls->t.token) {
            case TK_DOTS:
                dots = 1;
                lua2_next_88814BB8(ls);
                break;
            case TK_NAME:
                lua2_new_localvar_88814868(ls, str_checkname(ls), nparams++);
                break;
            default:
                lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2A9C);
            }
        } while (!dots && testnext(ls, ','));
    }
    lua2_code_params_88815008(ls, nparams, dots);
}

/* check_match */
LUA2_NOINLINE void lua2_check_match_88815580(LexState *ls, int what, int who, int where)
{
    if (!testnext(ls, what)) {
        if (where == ls->linenumber)
            lua2_luaX_syntaxerror_888195F0(ls, ts4_forward_varargs_88818C40(ls->L, lbl_880E29D8, lua2_luaX_token2str_888194C0(ls, what)));
        else {
            lua2_luaX_syntaxerror_888195F0(ls, ts4_forward_varargs_88818C40(ls->L, lbl_880E29E8, lua2_luaX_token2str_888194C0(ls, what),
                                                         lua2_luaX_token2str_888194C0(ls, who), where));
        }
    }
}

/* check */
LUA2_NOINLINE void lua2_check_88815628(LexState *ls, int c)
{
    if (!testnext(ls, c))
        lua2_luaX_syntaxerror_888195F0(ls, ts4_forward_varargs_88818C40(ls->L, lbl_880E29D8, lua2_luaX_token2str_888194C0(ls, c)));
}

/* luaK_getlabel */
LUA2_FORCEINLINE int luaK_getlabel(FuncState *fs)
{
    fs->lasttarget = fs->pc;
    return fs->pc;
}

/* luaK_patchtohere */
LUA2_FORCEINLINE void luaK_patchtohere(FuncState *fs, int list)
{
    luaK_getlabel(fs);
    lua2_luaK_concat_888203F0(fs, &fs->jpc, list);
}

/* luaK_patchlist */
LUA2_FORCEINLINE void luaK_patchlist(FuncState *fs, int list, int target)
{
    if (target == fs->pc)
        luaK_patchtohere(fs, list);
    else
        lua2_luaK_patchlistaux_88820468(fs, list, target, NO_REG, target, NO_REG, target);
}

LUA2_FORCEINLINE int luaK_codeAsBx(FuncState *fs, OpCode o, int a, int sbx)
{
    return luaK_codeABx(fs, o, a, sbx + MAXARG_sBx);
}

/* forbody: LuaPlus patches pending `continue' jumps to the loop end; no line fix-up. */
LUA2_NOINLINE void lua2_forbody_88815688(LexState *ls, int base, int nvars, int isnum)
{
    BlockCnt bl;
    FuncState *fs = ls->fs;
    int prep, endfor;
    lua2_adjustlocalvars_888144C8(ls, nvars);
    lua2_check_88815628(ls, TK_DO);
    enterblock(fs, &bl, 1);
    prep = luaK_getlabel(fs);
    lua2_block_888153C0(ls);
    luaK_patchtohere(fs, bl.continuelist);
    luaK_patchtohere(fs, prep - 1);
    endfor = (isnum) ? luaK_codeAsBx(fs, OP_FORLOOP, base, NO_JUMP) : luaK_codeABC(fs, OP_TFORLOOP, base, 0, nvars - 3);
    luaK_patchlist(fs, (isnum) ? endfor : ts4_call_seq_u32_off20_88820DD0(fs), prep);
    ts4_if_call_seq_u32_off14_88814F80(fs);
}

/* explist1 */
LUA2_NOINLINE int lua2_explist1_88815900(LexState *ls, expdesc *v)
{
    int n = 1;
    lua2_subexpr_88816C30(ls, v, -1);
    while (testnext(ls, ',')) {
        lua2_luaK_exp2nextreg_888214B0(ls->fs, v);
        lua2_subexpr_88816C30(ls, v, -1);
        n++;
    }
    return n;
}

LUA2_FORCEINLINE void luaK_setcallreturns(FuncState *fs, expdesc *e, int nresults)
{
    if (e->k == VCALL) {
        SETARG_C(getcode(fs, e), nresults + 1);
        if (nresults == 1) {
            e->k = VNONRELOC;
            e->info = GETARG_A(getcode(fs, e));
        }
    }
}

/* lastlistfield */
LUA2_NOINLINE void lua2_lastlistfield_88815968(FuncState *fs, struct ConsControl *cc)
{
    if (cc->tostore == 0) return;
    if (cc->v.k == VCALL) {
        luaK_setcallreturns(fs, &cc->v, LUA_MULTRET);
        luaK_codeABx(fs, OP_SETLISTO, cc->t->info, cc->na - 1);
    } else {
        if (cc->v.k != VVOID) lua2_luaK_exp2nextreg_888214B0(fs, &cc->v);
        luaK_codeABx(fs, OP_SETLIST, cc->t->info, cc->na - 1);
    }
    fs->freereg = cc->t->info + 1;
}

/* adjust_assign */
LUA2_NOINLINE void lua2_adjust_assign_88815AC0(LexState *ls, int nvars, int nexps, expdesc *e)
{
    FuncState *fs = ls->fs;
    int extra = nvars - nexps;
    if (e->k == VCALL) {
        extra++;
        if (extra <= 0)
            extra = 0;
        else
            luaK_reserveregs(fs, extra - 1);
        lua2_luaK_setcallreturns_888200C8(fs, e, extra);
    } else {
        if (e->k != VVOID) lua2_luaK_exp2nextreg_888214B0(fs, e);
        if (extra > 0) {
            int reg = fs->freereg;
            luaK_reserveregs(fs, extra);
            lua2_luaK_nil_88820E30(fs, reg, extra);
        }
    }
}

LUA2_FORCEINLINE int block_follow(int token)
{
    switch (token) {
    case TK_ELSE:
    case TK_ELSEIF:
    case TK_END:
    case TK_UNTIL:
    case TK_EOS:
        return 1;
    default:
        return 0;
    }
}

/* retstat */
LUA2_NOINLINE void lua2_retstat_88815BD8(LexState *ls)
{
    FuncState *fs = ls->fs;
    expdesc e;
    int first, nret;
    lua2_next_88814BB8(ls);
    if (block_follow(ls->t.token) || ls->t.token == ';')
        first = nret = 0;
    else {
        nret = lua2_explist1_88815900(ls, &e);
        if (e.k == VCALL) {
            luaK_setcallreturns(fs, &e, LUA_MULTRET);
            if (nret == 1) SET_OPCODE(getcode(fs, &e), OP_TAILCALL);
            first = fs->nactvar;
            nret = LUA_MULTRET;
        } else {
            if (nret == 1)
                first = lua2_luaK_exp2anyreg_888216D0(fs, &e);
            else {
                lua2_luaK_exp2nextreg_888214B0(fs, &e);
                first = fs->nactvar;
            }
        }
    }
    luaK_codeABC(fs, OP_RETURN, first, nret + 1, 0);
}

LUA2_FORCEINLINE void new_localvar_inl(LexState *ls, TString *name, int n)
{
    FuncState *fs = ls->fs;
    luaX_checklimit(ls, fs->nactvar + n + 1, MAXVARS, lbl_880E2A24);
    fs->actvar[fs->nactvar + n] = ts4_if_call_seq_u32_off30_888147A0(ls, name);
}

/* localstat */
LUA2_NOINLINE void lua2_localstat_88815CF8(LexState *ls)
{
    int nvars = 0;
    int nexps;
    expdesc e;
    do {
        new_localvar_inl(ls, str_checkname(ls), nvars++);
    } while (testnext(ls, ','));
    if (testnext(ls, '='))
        nexps = lua2_explist1_88815900(ls, &e);
    else {
        e.k = VVOID;
        nexps = 0;
    }
    lua2_adjust_assign_88815AC0(ls, nvars, nexps, &e);
    lua2_adjustlocalvars_888144C8(ls, nvars);
}

/* forlist */
LUA2_NOINLINE void lua2_forlist_88815E00(LexState *ls, TString *indexname)
{
    FuncState *fs = ls->fs;
    expdesc e;
    int nvars = 0;
    int base = fs->freereg;
    lua2_new_localvarstr_888148E0(ls, lbl_880E2B74, nvars++);
    lua2_new_localvarstr_888148E0(ls, lbl_880E2B84, nvars++);
    lua2_new_localvar_88814868(ls, indexname, nvars++);
    while (testnext(ls, ','))
        new_localvar_inl(ls, str_checkname(ls), nvars++);
    lua2_check_88815628(ls, TK_IN);
    lua2_adjust_assign_88815AC0(ls, nvars, lua2_explist1_88815900(ls, &e), &e);
    luaK_checkstack(fs, 3);
    luaK_codeAsBx(fs, OP_TFORPREP, base, NO_JUMP);
    lua2_forbody_88815688(ls, base, nvars, 0);
}

/* recfield */
LUA2_NOINLINE void lua2_recfield_88815FF8(LexState *ls, struct ConsControl *cc)
{
    FuncState *fs = ls->fs;
    int reg = ls->fs->freereg;
    expdesc key, val;
    if (ls->t.token == TK_NAME) {
        luaX_checklimit(ls, cc->nh, MAX_INT, lbl_880E2A60);
        cc->nh++;
        ts4_if_call_seq_u32_off10_88815520(ls, &key);
    } else
        ts4_if_call_seq_fn_88814BB8_88815F80(ls, &key);
    lua2_check_88815628(ls, '=');
    lua2_luaK_exp2RK_88821878(fs, &key);
    lua2_subexpr_88816C30(ls, &val, -1);
    luaK_codeABC(fs, OP_SETTABLE, cc->t->info, lua2_luaK_exp2RK_88821878(fs, &key), lua2_luaK_exp2RK_88821878(fs, &val));
    fs->freereg = reg;
}

extern const lu_byte lbl_880C9758[]; /* log_8 */

/* luaO_log2: the constructor keeps volatile registers live across it (LTCG knowledge). */
LUA2_LOCAL int ts4_if_addr_lbl_880C9758_888182A8(unsigned int x)
{
    if (x >= 0x00010000) {
        if (x >= 0x01000000)
            return lbl_880C9758[(x >> 24) - 1] + 24;
        else
            return lbl_880C9758[((x >> 16) & 0xff) - 1] + 16;
    } else {
        if (x >= 0x00000100)
            return lbl_880C9758[((x >> 8) & 0xff) - 1] + 8;
        else if (x)
            return lbl_880C9758[(x & 0xff) - 1];
        return -1;
    }
}

LUA2_FORCEINLINE int luaO_int2fb(unsigned int x)
{
    int m = 0;
    while (x >= (1 << 3)) {
        x = (x + 1) >> 1;
        m++;
    }
    return (m << 3) | (int)x;
}

/* constructor: LuaPlus accepts `{ & nhash & narray ...' size hints. */
LUA2_NOINLINE void lua2_constructor_88816230(LexState *ls, expdesc *t)
{
    FuncState *fs = ls->fs;
    int line = ls->linenumber;
    int ahint = 0, nhint = 0;
    int pc = luaK_codeABC(fs, OP_NEWTABLE, 0, 0, 0);
    struct ConsControl cc;
    cc.na = cc.nh = cc.tostore = 0;
    cc.t = t;
    init_exp(t, VRELOCABLE, pc);
    init_exp(&cc.v, VVOID, 0);
    lua2_luaK_exp2nextreg_888214B0(ls->fs, t);
    lua2_check_88815628(ls, '{');
    if (ls->t.token == '&') {
        lua2_next_88814BB8(ls);
        if (ls->t.token != TK_NUMBER)
            lua2_luaX_syntaxerror_888195F0(ls, ts4_forward_varargs_88818C40(ls->L, lbl_880E2A78, ls->linenumber));
        nhint = (int)ls->t.seminfo.r;
        lua2_next_88814BB8(ls);
        if (ls->t.token == '&') {
            lua2_next_88814BB8(ls);
            if (ls->t.token != TK_NUMBER)
                lua2_luaX_syntaxerror_888195F0(ls, ts4_forward_varargs_88818C40(ls->L, lbl_880E2A78, ls->linenumber));
            ahint = (int)ls->t.seminfo.r;
            lua2_next_88814BB8(ls);
        }
    }
    do {
        testnext(ls, ';');
        if (ls->t.token == '}') break;
        ts4_if_call_seq_u32_off0_88815A40(fs, &cc);
        switch (ls->t.token) {
        case TK_NAME:
            ls->lookahead.token = lua2_luaX_lex_8881A6E8(ls, &ls->lookahead.seminfo);
            if (ls->lookahead.token != '=')
                lua2_listfield_88814540(ls, &cc);
            else
                lua2_recfield_88815FF8(ls, &cc);
            break;
        case '[':
            lua2_recfield_88815FF8(ls, &cc);
            break;
        default:
            lua2_listfield_88814540(ls, &cc);
            break;
        }
    } while (testnext(ls, ',') || testnext(ls, ';'));
    lua2_check_match_88815580(ls, '}', '{', line);
    lua2_lastlistfield_88815968(fs, &cc);
    if (ahint > cc.na) cc.na = ahint;
    if (nhint > cc.nh) cc.nh = nhint;
    if (cc.na > 0) SETARG_B(fs->f->code[pc], luaO_int2fb(cc.na));
    SETARG_C(fs->f->code[pc], ts4_if_addr_lbl_880C9758_888182A8(cc.nh) + 1);
}

LUA2_FORCEINLINE void luaK_indexed(FuncState *fs, expdesc *t, expdesc *k)
{
    t->aux = lua2_luaK_exp2RK_88821878(fs, k);
    t->k = VINDEXED;
}

LUA2_FORCEINLINE void codestring(LexState *ls, expdesc *e, TString *s)
{
    FuncState *fs;
    _ReadWriteBarrier();
    fs = ls->fs;
    _ReadWriteBarrier();
    e->f = e->t = NO_JUMP;
    e->k = VK;
    e->info = lua2_luaK_stringK_88820AF0(fs, s);
}

LUA2_FORCEINLINE void checkname(LexState *ls, expdesc *e)
{
    codestring(ls, e, str_checkname(ls));
}

LUA2_FORCEINLINE void luaY_field_inl(LexState *ls, expdesc *v)
{
    FuncState *fs = ls->fs;
    expdesc key;
    lua2_luaK_exp2anyreg_888216D0(fs, v);
    lua2_next_88814BB8(ls);
    checkname(ls, &key);
    luaK_indexed(fs, v, &key);
}

/* funcname */
LUA2_NOINLINE int lua2_funcname_88816508(LexState *ls, expdesc *v)
{
    int needself = 0;
    ts4_loop_call_seq_fn_88814418_88814950(ls->fs, str_checkname(ls), v, 1);
    while (ls->t.token == '.') luaY_field_inl(ls, v);
    if (ls->t.token == ':') {
        needself = 1;
        ts4_call_seq_u32_off30_888164B0(ls, v);
    }
    return needself;
}

/* funcargs: no line fix-up in this build. */
LUA2_NOINLINE void lua2_funcargs_88816608(LexState *ls, expdesc *f)
{
    FuncState *fs = ls->fs;
    expdesc args;
    int base, nparams;
    int line = ls->linenumber;
    switch (ls->t.token) {
    case '(':
        if (line != ls->lastline) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2AC0);
        lua2_next_88814BB8(ls);
        if (ls->t.token == ')')
            args.k = VVOID;
        else {
            lua2_explist1_88815900(ls, &args);
            luaK_setcallreturns(fs, &args, LUA_MULTRET);
        }
        lua2_check_match_88815580(ls, ')', '(', line);
        break;
    case '{':
        lua2_constructor_88816230(ls, &args);
        break;
    case TK_STRING:
        init_exp(&args, VK, lua2_luaK_stringK_88820AF0(fs, ls->t.seminfo.ts));
        lua2_next_88814BB8(ls);
        break;
    default:
        lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2AF4);
        return;
    }
    base = f->info;
    if (args.k == VCALL)
        nparams = LUA_MULTRET;
    else {
        if (args.k != VVOID) lua2_luaK_exp2nextreg_888214B0(fs, &args);
        nparams = fs->freereg - (base + 1);
    }
    init_exp(f, VCALL, luaK_codeABC(fs, OP_CALL, base, nparams + 1, 2));
    fs->freereg = base + 1;
}

/* funcstat */
LUA2_NOINLINE void lua2_funcstat_88816788(LexState *ls, int line)
{
    int needself;
    expdesc v, b;
    lua2_next_88814BB8(ls);
    needself = lua2_funcname_88816508(ls, &v);
    ts4_if_call_seq_fn_888145C8_88815860(ls, &b, needself, line);
    lua2_luaK_storevar_88821DC8(ls->fs, &v, &b);
}

/* primaryexp */
LUA2_NOINLINE void lua2_primaryexp_888167F0(LexState *ls, expdesc *v)
{
    FuncState *fs = ls->fs;
    ts4_if_call_seq_u32_off10_888157D8(ls, v);
    for (;;) {
        switch (ls->t.token) {
        case '.':
            ts4_call_seq_u32_off30_888164B0(ls, v);
            break;
        case '[': {
            expdesc key;
            lua2_luaK_exp2anyreg_888216D0(fs, v);
            ts4_if_call_seq_fn_88814BB8_88815F80(ls, &key);
            luaK_indexed(fs, v, &key);
            break;
        }
        case ':': {
            expdesc key;
            lua2_next_88814BB8(ls);
            ts4_if_call_seq_u32_off10_88815520(ls, &key);
            lua2_luaK_self_88821CC0(fs, v, &key);
            lua2_funcargs_88816608(ls, v);
            break;
        }
        case '(':
        case TK_STRING:
        case TK_WSTRING:
        case '{':
            lua2_luaK_exp2nextreg_888214B0(fs, v);
            lua2_funcargs_88816608(ls, v);
            break;
        default:
            return;
        }
    }
}

/* assignment */
LUA2_NOINLINE void lua2_assignment_888168E8(LexState *ls, struct LHS_assign *lh, int nvars)
{
    expdesc e;
    if (!(VLOCAL <= lh->v.k && lh->v.k <= VINDEXED)) lua2_luaX_syntaxerror_888195F0(ls, lbl_880DCDF4);
    if (testnext(ls, ',')) {
        struct LHS_assign nv;
        nv.prev = lh;
        lua2_primaryexp_888167F0(ls, &nv.v);
        if (nv.v.k == VLOCAL) lua2_check_conflict_88814C38(ls, lh, &nv.v);
        lua2_assignment_888168E8(ls, &nv, nvars + 1);
    } else {
        int nexps;
        lua2_check_88815628(ls, '=');
        nexps = lua2_explist1_88815900(ls, &e);
        if (nexps != nvars) {
            lua2_adjust_assign_88815AC0(ls, nvars, nexps, &e);
            if (nexps > nvars) ls->fs->freereg -= nexps - nvars;
        } else {
            luaK_setcallreturns(ls->fs, &e, 1);
            lua2_luaK_storevar_88821DC8(ls->fs, &lh->v, &e);
            return;
        }
    }
    init_exp(&e, VNONRELOC, ls->fs->freereg - 1);
    lua2_luaK_storevar_88821DC8(ls->fs, &lh->v, &e);
}

/* simpleexp */
LUA2_NOINLINE void lua2_simpleexp_88816A68(LexState *ls, expdesc *v)
{
    switch (ls->t.token) {
    case TK_NUMBER:
        init_exp(v, VK, lua2_luaK_numberK_88820A68(ls->fs, ls->t.seminfo.r));
        lua2_next_88814BB8(ls);
        break;
    case TK_STRING:
        init_exp(v, VK, lua2_luaK_stringK_88820AF0(ls->fs, ls->t.seminfo.ts));
        lua2_next_88814BB8(ls);
        break;
    case TK_WSTRING:
        init_exp(v, VK, lua2_luaK_wstringK_888207C8(ls->fs, ls->t.seminfo.ts));
        lua2_next_88814BB8(ls);
        break;
    case TK_NIL:
        init_exp(v, VNIL, 0);
        lua2_next_88814BB8(ls);
        break;
    case TK_TRUE:
        init_exp(v, VTRUE, 0);
        lua2_next_88814BB8(ls);
        break;
    case TK_FALSE:
        init_exp(v, VFALSE, 0);
        lua2_next_88814BB8(ls);
        break;
    case '{':
        lua2_constructor_88816230(ls, v);
        break;
    case TK_FUNCTION:
        lua2_next_88814BB8(ls);
        ts4_if_call_seq_fn_888145C8_88815860(ls, v, 0, ls->linenumber);
        break;
    default:
        lua2_primaryexp_888167F0(ls, v);
        break;
    }
}

/* exprstat */
LUA2_NOINLINE void lua2_exprstat_88816BA8(LexState *ls)
{
    FuncState *fs = ls->fs;
    struct LHS_assign v;
    lua2_primaryexp_888167F0(ls, &v.v);
    if (v.v.k == VCALL)
        luaK_setcallreturns(fs, &v.v, 0);
    else {
        v.prev = 0;
        lua2_assignment_888168E8(ls, &v, 1);
    }
}

#define OPR_MINUS 0
#define OPR_NOT 1
#define OPR_NOUNOPR 2
#define OPR_NOBINOPR 18
#define UNARY_PRIORITY 8
#define LUA_MAXPARSERLEVEL 200

LUA2_FORCEINLINE int getunopr(int op)
{
    switch (op) {
    case TK_NOT:
        return OPR_NOT;
    case '-':
        return OPR_MINUS;
    default:
        return OPR_NOUNOPR;
    }
}

/* subexpr */
LUA2_NOINLINE int lua2_subexpr_88816C30(LexState *ls, expdesc *v, int limit)
{
    int op;
    int uop;
    if (++ls->nestlevel > LUA_MAXPARSERLEVEL) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2B24);
    uop = getunopr(ls->t.token);
    if (uop != OPR_NOUNOPR) {
        lua2_next_88814BB8(ls);
        lua2_subexpr_88816C30(ls, v, UNARY_PRIORITY);
        lua2_luaK_prefix_88821770(ls->fs, uop, v);
    } else
        lua2_simpleexp_88816A68(ls, v);
    op = ts4_key_to_index_88814210(ls->t.token);
    while (op != OPR_NOBINOPR && (int)lbl_880C96E8[op].left > limit) {
        expdesc v2;
        int nextop;
        lua2_next_88814BB8(ls);
        ts4_if_call_seq_fn_888214B0_88821BC8(ls->fs, op, v);
        nextop = lua2_subexpr_88816C30(ls, &v2, (int)lbl_880C96E8[op].right);
        lua2_luaK_posfix_88821928(ls->fs, op, v, &v2);
        op = nextop;
    }
    ls->nestlevel--;
    return op;
}

#define MAXEXPWHILE 100
#define EXTRAEXP 5
#define FIRST_RESERVED 257

/* check() for a reserved word: luaX_token2str reduces to the token table. */
LUA2_FORCEINLINE void check_reserved(LexState *ls, int c)
{
    if (!testnext(ls, c))
        lua2_luaX_syntaxerror_888195F0(ls, ts4_forward_varargs_88818C40(ls->L, lbl_880E29D8, lbl_880C9858[c - FIRST_RESERVED]));
}

LUA2_FORCEINLINE void block_inl(LexState *ls)
{
    FuncState *fs = ls->fs;
    BlockCnt bl;
    enterblock(fs, &bl, 0);
    lua2_chunk_88817818(ls);
    ts4_if_call_seq_u32_off14_88814F80(fs);
}

/* whilestat: the condition is moved after the body; `continue' jumps land on it. */
LUA2_NOINLINE void lua2_whilestat_88816DA0(LexState *ls, int line)
{
    Instruction codeexp[MAXEXPWHILE + EXTRAEXP];
    int i;
    int sizeexp;
    FuncState *fs = ls->fs;
    int whileinit, blockinit, expinit;
    expdesc v;
    BlockCnt bl;
    lua2_next_88814BB8(ls);
    whileinit = ts4_call_seq_u32_off20_88820DD0(fs);
    expinit = luaK_getlabel(fs);
    lua2_subexpr_88816C30(ls, &v, -1);
    if (v.k == VK) v.k = VTRUE;
    lua2_luaK_goiffalse_88821568(fs, &v);
    lua2_luaK_concat_888203F0(fs, &v.f, fs->jpc);
    fs->jpc = NO_JUMP;
    sizeexp = fs->pc - expinit;
    if (sizeexp > MAXEXPWHILE) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2B3C);
    for (i = 0; i < sizeexp; i++) codeexp[i] = fs->f->code[expinit + i];
    fs->pc = expinit;
    enterblock(fs, &bl, 1);
    check_reserved(ls, TK_DO);
    blockinit = luaK_getlabel(fs);
    block_inl(ls);
    luaK_patchtohere(fs, whileinit);
    luaK_patchtohere(fs, bl.continuelist);
    if (v.t != NO_JUMP) v.t += fs->pc - expinit;
    if (v.f != NO_JUMP) v.f += fs->pc - expinit;
    for (i = 0; i < sizeexp; i++) lua2_luaK_code_888208A8(fs, codeexp[i]);
    lua2_check_match_88815580(ls, TK_END, TK_WHILE, line);
    ts4_if_call_seq_u32_off14_88814F80(fs);
    luaK_patchlist(fs, v.t, blockinit);
    luaK_patchtohere(fs, v.f);
}

/* exp1, expanded with the caller's expression slot (the original keeps one slot per call). */
LUA2_FORCEINLINE int exp1(LexState *ls, expdesc *e)
{
    int k;
    lua2_subexpr_88816C30(ls, e, -1);
    k = e->k;
    lua2_luaK_exp2nextreg_888214B0(ls->fs, e);
    return k;
}

/* fornum */
LUA2_NOINLINE void lua2_fornum_88817100(LexState *ls, TString *varname)
{
    FuncState *fs = ls->fs;
    int base = fs->freereg;
    expdesc e1, e2, e3;
    lua2_new_localvar_88814868(ls, varname, 0);
    lua2_new_localvarstr_888148E0(ls, lbl_880E2B5C, 1);
    lua2_new_localvarstr_888148E0(ls, lbl_880E2B68, 2);
    lua2_check_88815628(ls, '=');
    exp1(ls, &e1);
    lua2_check_88815628(ls, ',');
    exp1(ls, &e2);
    if (testnext(ls, ','))
        exp1(ls, &e3);
    else {
        luaK_codeABx(fs, OP_LOADK, fs->freereg, lua2_luaK_numberK_88820A68(fs, g_ts4_script_constants[15]));
        luaK_reserveregs(fs, 1);
    }
    luaK_codeABC(fs, OP_SUB, fs->freereg - 3, fs->freereg - 3, fs->freereg - 1);
    ts4_call_seq_u32_off20_88820DD0(fs);
    lua2_forbody_88815688(ls, base, 3, 1);
}

/* repeatstat */
LUA2_NOINLINE void lua2_repeatstat_88817290(LexState *ls, int line)
{
    FuncState *fs = ls->fs;
    int repeat_init = luaK_getlabel(fs);
    expdesc v;
    BlockCnt bl;
    enterblock(fs, &bl, 1);
    lua2_next_88814BB8(ls);
    lua2_block_888153C0(ls);
    luaK_patchtohere(fs, bl.continuelist);
    lua2_check_match_88815580(ls, TK_UNTIL, TK_REPEAT, line);
    ts4_if_call_seq_fn_88816C30_88817030(ls, &v);
    luaK_patchlist(fs, v.f, repeat_init);
    ts4_if_call_seq_u32_off14_88814F80(fs);
}

LUA2_FORCEINLINE int luaK_jump_inl(FuncState *fs)
{
    int jpc = fs->jpc;
    int j;
    fs->jpc = NO_JUMP;
    j = luaK_codeAsBx(fs, OP_JMP, 0, NO_JUMP);
    lua2_luaK_concat_888203F0(fs, &j, jpc);
    return j;
}

LUA2_FORCEINLINE void cond_inl(LexState *ls, expdesc *v)
{
    lua2_subexpr_88816C30(ls, v, -1);
    if (v->k == VNIL) v->k = VFALSE;
    lua2_luaK_goiftrue_88821618(ls->fs, v);
    luaK_patchtohere(ls->fs, v->t);
}

/* forstat */
LUA2_NOINLINE void lua2_forstat_888175A0(LexState *ls, int line)
{
    FuncState *fs = ls->fs;
    TString *varname;
    BlockCnt bl;
    enterblock(fs, &bl, 0);
    lua2_next_88814BB8(ls);
    varname = str_checkname(ls);
    switch (ls->t.token) {
    case '=':
        lua2_fornum_88817100(ls, varname);
        break;
    case ',':
    case TK_IN:
        lua2_forlist_88815E00(ls, varname);
        break;
    default:
        lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2B90);
    }
    lua2_check_match_88815580(ls, TK_END, TK_FOR, line);
    ts4_if_call_seq_u32_off14_88814F80(fs);
}

/* chunk */
LUA2_NOINLINE void lua2_chunk_88817818(LexState *ls)
{
    int islast = 0;
    if (++ls->nestlevel > LUA_MAXPARSERLEVEL) lua2_luaX_syntaxerror_888195F0(ls, lbl_880E2B24);
    while (!islast && !block_follow(ls->t.token)) {
        islast = ts4_parser_dispatch_88817680(ls);
        testnext(ls, ';');
        ls->fs->freereg = ls->fs->nactvar;
    }
    ls->nestlevel--;
}

typedef struct Zio {
    char pad0[0x10];
    const char *name;
} ZIO;

/* luaY_parser */
Proto *lua2_luaY_parser_888178D8(lua_State *L, ZIO *z, Mbuffer *buff)
{
    LexState lexstate;
    FuncState funcstate;
    lexstate.buff = buff;
    lexstate.nestlevel = 0;
    lua2_luaX_setinput_88819238(L, &lexstate, z, lua2_luaS_newlstr_888131A0(L, z->name, strlen(z->name)));
    ts4_call_seq_u32_off34_888145C8(&lexstate, &funcstate);
    lua2_next_88814BB8(&lexstate);
    lua2_chunk_88817818(&lexstate);
    if (lexstate.t.token != TK_EOS) lua2_luaX_syntaxerror_888195F0(&lexstate, lbl_880E2A50);
    lua2_close_func_88814D20(&lexstate);
    return funcstate.f;
}
