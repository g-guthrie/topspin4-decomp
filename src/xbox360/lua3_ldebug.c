/* Derived from Lua 5.0.2 ldebug.c (MIT); see THIRD_PARTY_NOTICES.md */
/* ldebug.c: debug interface, symbolic execution and runtime errors (LuaPlus opcode numbering). */
#include "lua3.h"

#define LUA_IDSIZE 60
#define MAXSTACK 250
#define NO_REG 255
#define MAXARG_sBx 0x1FFFF
#define LFIELDS_PER_FLUSH 32
#define LUA_ERRRUN 1
#define LUA_ERRERR 5
#define LUA_MULTRET (-1)

/* this build has four extra opcodes after OP_NOT */
enum {
    OP_MOVE = 0, OP_LOADK, OP_LOADBOOL, OP_LOADNIL, OP_GETUPVAL, OP_GETGLOBAL, OP_GETTABLE,
    OP_SETGLOBAL, OP_SETUPVAL, OP_SETTABLE, OP_NEWTABLE, OP_SELF, OP_CONCAT = 23, OP_JMP,
    OP_EQ, OP_LT, OP_LE, OP_TEST, OP_CALL, OP_TAILCALL, OP_RETURN, OP_FORLOOP, OP_TFORLOOP,
    OP_TFORPREP, OP_SETLIST, OP_SETLISTO, OP_CLOSE, OP_CLOSURE
};

enum { iABC, iABx, iAsBx };
#define OpModeBreg 2
#define OpModeBrk 3
#define OpModeCrk 4
#define OpModesetA 5
#define OpModeK 6
#define OpModeT 7

#define GET_OPCODE(i) ((int)((i)&0x3F))
#define GETARG_A(i) ((int)((i) >> 24))
#define GETARG_B(i) ((int)(((i) >> 15) & 0x1FF))
#define GETARG_C(i) ((int)(((i) >> 6) & 0x1FF))
#define GETARG_Bx(i) ((int)(((i) >> 6) & 0x3FFFF))
#define GETARG_sBx(i) (GETARG_Bx(i) - MAXARG_sBx)
#define getOpMode(m) (lbl_880C970C[m] & 3)
#define testOpMode(m, b) (lbl_880C970C[m] & (1 << (b)))

#define isLua(ci) (!((ci)->state & CI_C))
#define svalue(o) getstr(tsvalue(o))

extern const lu_byte lbl_880C970C[];  /* luaP_opmodes */
extern const char *lbl_880C9684[];    /* luaT_typenames */
extern char lbl_880C1320[];           /* "" */
extern char lbl_880E1C18[];           /* "method" */
extern char lbl_880E1C40[];           /* "?" */
extern char lbl_880E25B8[];           /* "tail" */
extern char lbl_880E25C0[];           /* "=(tail call)" */
extern char lbl_880E25D0[];           /* "global" */
extern char lbl_880E25D8[];           /* "value for `lua_getinfo' is not a function" */
extern char lbl_880E2604[];           /* "local" */
extern char lbl_880E260C[];           /* "field" */
extern char lbl_880E2614[];           /* "attempt to %s %s `%s' (a %s value)" */
extern char lbl_880E2638[];           /* "attempt to %s a %s value" */
extern char lbl_880E2660[];           /* "perform arithmetic on" */
extern char lbl_880E2678[];           /* "attempt to compare two %s values" */
extern char lbl_880E269C[];           /* "attempt to compare %s with %s" */
extern char lbl_880E26BC[];           /* "%s:%d: %s" */

extern void ts4_if_get_u32_off8_8881EE28(lua_Debug *ar, StkId func); /* funcinfo */
extern const char *lua2_luaF_getlocalname_8881C258(const Proto *f, int local_number, int pc);
extern void ts4_lua_pushobject_88824AA8(lua_State *L, const TValue *o); /* luaA_pushobject */
extern TValue *ts4_lua_v_tonumber_8880CAF0(lua_State *L, const TValue *obj, TValue *n);
extern void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nResults);
extern void lua3_luaO_chunkid_88817F88(char *out, const char *source); /* luaO_chunkid(out, source, LUA_IDSIZE) */
extern const char *lua3_luaO_pushvfstring_888188F8(lua_State *L, const char *fmt, va_list argp); /* luaO_pushvfstring */

/* same-file copy of luaO_pushfstring: addinfo's frame reflects the visible variadic body */
LUA2_LOCAL const char *ts4_forward_varargs_88818C40(lua_State *L, const char *fmt, ...)
{
    const char *msg;
    va_list argp;
    va_start(argp, fmt);
    msg = lua3_luaO_pushvfstring_888188F8(L, fmt, argp);
    va_end(argp);
    return msg;
}
extern char *fn_88563500(const char *s, int c);                             /* strchr */

void lua3_luaG_errormsg_8881F900(lua_State *L);
LUA2_NOINLINE void lua3_addinfo_8881FAD0(lua_State *L, const char *msg);
void lua3_luaG_runerror_8881FB60(lua_State *L, const char *fmt, ...); /* lua3_ldebug_err.c */
const char *lua3_getobjname_8881F4F8(CallInfo *ci, int stackpos, const char **name);

/* currentline: this build keeps no line information, so every frame reports -1 */
LUA2_FORCEINLINE int currentpc_inl(CallInfo *ci)
{
    if (!isLua(ci)) return -1; /* function is not a Lua function? */
    if (ci->state & CI_HASFRAME) ci->savedpc = *ci->pc; /* use `pc' from there */
    return pcRel(ci->savedpc, ci_func(ci)->l.p);
}

/* same-file copy of currentpc (0x8881EFB8): callers rely on its register use */
LUA2_LOCAL int ts4_if_get_u32_off8_8881EFB8(CallInfo *ci)
{
    return currentpc_inl(ci);
}

LUA2_NOINLINE int lua3_currentline_8881F4A8(CallInfo *ci)
{
    int pc = currentpc_inl(ci);
    if (pc < 0) return -1;
    else return -1;
}

/* luaG_ordererror */
int lua3_luaG_ordererror_8881EBA8(lua_State *L, const TValue *p1, const TValue *p2)
{
    const char *t1 = lbl_880C9684[ttype(p1)];
    const char *t2 = lbl_880C9684[ttype(p2)];
    if (t1[2] == t2[2])
        lua3_luaG_runerror_8881FB60(L, lbl_880E2678, t1);
    else
        lua3_luaG_runerror_8881FB60(L, lbl_880E269C, t1, t2);
    return 0;
}

/* kname: constant name for an RK operand, or "?" */
LUA2_FORCEINLINE const char *kname_inl(Proto *p, int c)
{
    c = c - MAXSTACK;
    if (c >= 0 && ttype(&p->k[c]) == LUA2_TSTRING)
        return svalue(&p->k[c]);
    else
        return lbl_880E1C40;
}

LUA2_NOINLINE const char *lua3_kname_8881EC60(Proto *p, int c)
{
    c = c - MAXSTACK;
    if (c >= 0 && ttype(&p->k[c]) == LUA2_TSTRING)
        return svalue(&p->k[c]);
    else
        return lbl_880E1C40;
}

/* checkopenop: the instruction after an open call must consume all results */
LUA2_NOINLINE int lua3_checkopenop_8881ECD0(const Proto *pt, int pc)
{
    Instruction i = pt->code[pc + 1];
    switch (GET_OPCODE(i)) {
    case OP_CALL:
    case OP_TAILCALL:
    case OP_RETURN: return GETARG_B(i) == 0;
    case OP_SETLISTO: return 1;
    default: return 0; /* invalid instruction after an open call */
    }
}

/* travglobals: name of a global variable holding o */
LUA2_FORCEINLINE int rawequalObj_inl(const TValue *t1, const TValue *t2)
{
    if (ttype(t1) != ttype(t2)) return 0;
    switch (ttype(t1)) {
    case LUA2_TNIL: return 1;
    case LUA2_TNUMBER: return nvalue(t1) == nvalue(t2);
    case LUA2_TBOOLEAN: return bvalue(t1) == bvalue(t2);
    case LUA2_TLIGHTUSERDATA: return t1->value.p == t2->value.p;
    default: return t1->value.gc == t2->value.gc;
    }
}

LUA2_NOINLINE const char *lua3_travglobals_8881ED70(lua_State *L, const TValue *o)
{
    Table *g = hvalue(&L->_gt);
    int i = 1 << g->lsizenode;
    while (i--) {
        Node *n = &g->node[i];
        if (rawequalObj_inl(o, &n->i_val) && ttype(&n->i_key) == LUA2_TSTRING) return svalue(&n->i_key);
    }
    return 0;
}

/* lua_getstack */
int lua3_lua_getstack_8881EED0(lua_State *L, int level, lua_Debug *ar)
{
    int status;
    CallInfo *ci;
    for (ci = L->ci; level > 0 && ci > L->base_ci; ci--) {
        level--;
        if (!(ci->state & CI_C)) /* Lua function? */
            level -= ci->tailcalls; /* skip lost tail calls */
    }
    if (level > 0 || ci == L->base_ci)
        status = 0; /* there is no such level */
    else if (level < 0) { /* level is of a lost tail call */
        status = 1;
        ar->i_ci = 0;
    } else {
        status = 1;
        ar->i_ci = ci - L->base_ci;
    }
    return status;
}

/* lua_sethook */
int lua3_lua_sethook_8881EF78(lua_State *L, lua_Hook func, int mask, int count)
{
    if (func == 0 || mask == 0) { /* turn off hooks? */
        mask = 0;
        func = 0;
    }
    L->hook = (void (*)(struct lua_State *, void *))func;
    L->basehookcount = count;
    L->hookcount = count;
    L->hookmask = (lu_byte)mask;
    L->hookinit = 0;
    return 1;
}

#define check(x) \
    if (!(x)) return 0;
#define checkjump(pt, pc) check(0 <= pc && pc < pt->sizecode)
#define checkreg(pt, reg) check((reg) < (pt)->maxstacksize)
#define checkRK(pt, r) ((r) < (pt)->maxstacksize || ((r) >= MAXSTACK && (r)-MAXSTACK < (pt)->sizek))

LUA2_FORCEINLINE int precheck(const Proto *pt)
{
    check(pt->maxstacksize <= MAXSTACK);
    check(pt->sizelineinfo == pt->sizecode || pt->sizelineinfo == 0);
    check(GET_OPCODE(pt->code[pt->sizecode - 1]) == OP_RETURN);
    return 1;
}

/* luaG_symbexec */
LUA2_NOINLINE Instruction lua3_luaG_symbexec_8881F010(const Proto *pt, int lastpc, int reg)
{
    int pc;
    int last; /* stores position of last instruction that changed `reg' */
    last = pt->sizecode - 1; /* points to final return (a `neutral' instruction) */
    check(precheck(pt));
    for (pc = 0; pc < lastpc; pc++) {
        const Instruction i = pt->code[pc];
        int op = GET_OPCODE(i);
        int a = GETARG_A(i);
        int b = 0;
        int c = 0;
        checkreg(pt, a);
        switch (getOpMode(op)) {
        case iABC: {
            b = GETARG_B(i);
            c = GETARG_C(i);
            if (testOpMode(op, OpModeBreg)) {
                checkreg(pt, b);
            } else if (testOpMode(op, OpModeBrk))
                check(checkRK(pt, b));
            if (testOpMode(op, OpModeCrk)) check(checkRK(pt, c));
            break;
        }
        case iABx: {
            b = GETARG_Bx(i);
            if (testOpMode(op, OpModeK)) check(b < pt->sizek);
            break;
        }
        case iAsBx: {
            b = GETARG_sBx(i);
            break;
        }
        }
        if (testOpMode(op, OpModesetA)) {
            if (a == reg) last = pc; /* change register `a' */
        }
        if (testOpMode(op, OpModeT)) {
            check(pc + 2 < pt->sizecode); /* check skip */
            check(GET_OPCODE(pt->code[pc + 1]) == OP_JMP);
        }
        switch (op) {
        case OP_LOADBOOL: {
            if (c) { /* does it jump? */
                check(pc + 2 < pt->sizecode); /* check its jump */
            }
            break;
        }
        case OP_LOADNIL: {
            if (a <= reg && reg <= b) last = pc; /* set registers from `a' to `b' */
            break;
        }
        case OP_GETUPVAL:
        case OP_SETUPVAL: {
            check(b < pt->nups);
            break;
        }
        case OP_GETGLOBAL:
        case OP_SETGLOBAL: {
            check(ttype(&pt->k[b]) == LUA2_TSTRING);
            break;
        }
        case OP_SELF: {
            checkreg(pt, a + 1);
            if (reg == a + 1) last = pc;
            break;
        }
        case OP_CONCAT: {
            /* `c' is a register, and at least two operands */
            check(c < MAXSTACK && b < c);
            break;
        }
        case OP_TFORLOOP:
            checkreg(pt, a + c + 5);
            if (reg >= a) last = pc; /* affect all registers above base */
            /* go through */
        case OP_FORLOOP:
            checkreg(pt, a + 2);
            /* go through */
        case OP_JMP: {
            int dest = pc + 1 + b;
            check(0 <= dest && dest < pt->sizecode);
            /* not full check and jump is forward and do not skip `lastpc'? */
            if (reg != NO_REG && pc < dest && dest <= lastpc) pc += b; /* do the jump */
            break;
        }
        case OP_CALL:
        case OP_TAILCALL: {
            if (b != 0) {
                checkreg(pt, a + b - 1);
            }
            c--; /* c = num. returns */
            if (c == LUA_MULTRET) {
                check(lua3_checkopenop_8881ECD0(pt, pc));
            } else if (c != 0)
                checkreg(pt, a + c - 1);
            if (reg >= a) last = pc; /* affect all registers above base */
            break;
        }
        case OP_RETURN: {
            b--; /* b = num. returns */
            if (b > 0) checkreg(pt, a + b - 1);
            break;
        }
        case OP_SETLIST: {
            checkreg(pt, a + (b & (LFIELDS_PER_FLUSH - 1)) + 1);
            break;
        }
        case OP_CLOSURE: {
            int nup;
            check(b < pt->sizep);
            nup = pt->p[b]->nups;
            check(pc + nup < pt->sizecode);
            for (; nup > 0; nup--) {
                int op1 = GET_OPCODE(pt->code[pc + nup]);
                check(op1 == OP_GETUPVAL || op1 == OP_MOVE);
            }
            break;
        }
        default: break;
        }
    }
    return pt->code[last];
}

/* getobjname */
LUA2_NOINLINE const char *lua3_getobjname_8881F4F8(CallInfo *ci, int stackpos, const char **name)
{
    if (isLua(ci)) { /* a Lua function? */
        Proto *p = ci_func(ci)->l.p;
        int pc = ts4_if_get_u32_off8_8881EFB8(ci);
        Instruction i;
        *name = lua2_luaF_getlocalname_8881C258(p, stackpos + 1, pc);
        if (*name) /* is a local? */
            return lbl_880E2604;
        i = lua3_luaG_symbexec_8881F010(p, pc, stackpos); /* try symbolic execution */
        switch (GET_OPCODE(i)) {
        case OP_GETGLOBAL: {
            int g = GETARG_Bx(i); /* global index */
            *name = svalue(&p->k[g]);
            return lbl_880E25D0;
        }
        case OP_MOVE: {
            int a = GETARG_A(i);
            int b = GETARG_B(i); /* move from `b' to `a' */
            if (b < a) return lua3_getobjname_8881F4F8(ci, b, name); /* get name for `b' */
            break;
        }
        case OP_GETTABLE: {
            int k = GETARG_C(i); /* key index */
            *name = kname_inl(p, k);
            return lbl_880E260C;
        }
        case OP_SELF: {
            int k = GETARG_C(i); /* key index */
            *name = kname_inl(p, k);
            return lbl_880E1C18;
        }
        default: break;
        }
    }
    return 0; /* no useful name found */
}

/* luaG_typeerror */
void lua3_luaG_typeerror_8881F6D8(lua_State *L, const TValue *o, const char *op)
{
    const char *name = 0;
    const char *t = lbl_880C9684[ttype(o)];
    const char *kind = 0;
    CallInfo *ci = L->ci;
    StkId p;
    for (p = ci->base; p < ci->top; p++)
        if (o == p) {
            kind = lua3_getobjname_8881F4F8(ci, o - L->base, &name);
            break;
        }
    if (kind)
        lua3_luaG_runerror_8881FB60(L, lbl_880E2614, op, kind, name, t);
    else
        lua3_luaG_runerror_8881FB60(L, lbl_880E2638, op, t);
}

/* getfuncname */
LUA2_NOINLINE const char *lua3_getfuncname_8881F798(CallInfo *ci, const char **name)
{
    Instruction i;
    if ((isLua(ci) && ci->tailcalls > 0) || !isLua(ci - 1)) return 0; /* calling function is not Lua (or is unknown) */
    ci--; /* calling function */
    i = ci_func(ci)->l.p->code[ts4_if_get_u32_off8_8881EFB8(ci)];
    if (GET_OPCODE(i) == OP_CALL || GET_OPCODE(i) == OP_TAILCALL)
        return lua3_getobjname_8881F4F8(ci, GETARG_A(i), name);
    else
        return 0; /* no useful name can be found */
}

/* luaG_aritherror */
void lua3_luaG_aritherror_8881F848(lua_State *L, const TValue *p1, const TValue *p2)
{
    TValue temp;
    temp.tt = LUA2_TNIL;
    temp.value.p = 0;
    if (ts4_lua_v_tonumber_8880CAF0(L, p1, &temp) == 0) p2 = p1; /* first operand is wrong */
    setnilvalue(L, &temp);
    lua3_luaG_typeerror_8881F6D8(L, p2, lbl_880E2660);
}

/* addinfo */
LUA2_NOINLINE void lua3_addinfo_8881FAD0(lua_State *L, const char *msg)
{
    CallInfo *ci = L->ci;
    if (isLua(ci)) { /* is Lua code? */
        char buff[LUA_IDSIZE]; /* add file:line information */
        int line = lua3_currentline_8881F4A8(ci);
        lua3_luaO_chunkid_88817F88(buff, getstr((isLua(ci) ? ci_func(ci)->l.p : 0)->source));
        ts4_forward_varargs_88818C40(L, lbl_880E26BC, buff, line, msg);
    }
}

/* getinfo */
LUA2_NOINLINE int lua3_getinfo_8881FBB8(lua_State *L, const char *what, lua_Debug *ar, StkId f, CallInfo *ci)
{
    int status = 1;
    for (; *what; what++) {
        switch (*what) {
        case 'S': {
            ts4_if_get_u32_off8_8881EE28(ar, f);
            break;
        }
        case 'l': {
            ar->currentline = (ci) ? lua3_currentline_8881F4A8(ci) : -1;
            break;
        }
        case 'u': {
            ar->nups = clvalue(f)->c.nupvalues;
            break;
        }
        case 'n': {
            ar->namewhat = (ci) ? lua3_getfuncname_8881F798(ci, &ar->name) : 0;
            if (ar->namewhat == 0) {
                /* try to find a global name */
                if ((ar->name = lua3_travglobals_8881ED70(L, f)) != 0)
                    ar->namewhat = lbl_880E25D0;
                else
                    ar->namewhat = lbl_880C1320; /* not found */
            }
            break;
        }
        case 'f': {
            setobj(L, L->top, f);
            break;
        }
        default: status = 0; /* invalid option */
        }
    }
    return status;
}

/* info_tailcall */
LUA2_NOINLINE void lua3_info_tailcall_8881FD48(lua_State *L, lua_Debug *ar)
{
    ar->name = ar->namewhat = lbl_880C1320;
    ar->what = lbl_880E25B8;
    ar->linedefined = ar->currentline = -1;
    ar->source = lbl_880E25C0;
    lua3_luaO_chunkid_88817F88(ar->short_src, ar->source);
    ar->nups = 0;
    setnilvalue(L, L->top);
}

/* lua_setlocal */
const char *lua3_lua_setlocal_8881FDF0(lua_State *L, const lua_Debug *ar, int n)
{
    const char *name;
    CallInfo *ci;
    Proto *fp;
    name = 0;
    ci = L->base_ci + ar->i_ci;
    fp = isLua(ci) ? ci_func(ci)->l.p : 0;
    L->top--; /* pop new value */
    if (fp) { /* is a Lua function? */
        name = lua2_luaF_getlocalname_8881C258(fp, n, ts4_if_get_u32_off8_8881EFB8(ci));
        if (!name || name[0] == '(') /* `(' starts private locals */
            name = 0;
        else
            setobj(L, ci->base + (n - 1), L->top);
    }
    return name;
}

/* lua_getlocal */
const char *lua3_lua_getlocal_88820020(lua_State *L, const lua_Debug *ar, int n)
{
    const char *name;
    CallInfo *ci;
    Proto *fp;
    name = 0;
    ci = L->base_ci + ar->i_ci;
    fp = isLua(ci) ? ci_func(ci)->l.p : 0;
    if (fp) { /* is a Lua function? */
        name = lua2_luaF_getlocalname_8881C258(fp, n, ts4_if_get_u32_off8_8881EFB8(ci));
        if (name) ts4_lua_pushobject_88824AA8(L, ci->base + (n - 1)); /* push value */
    }
    return name;
}
