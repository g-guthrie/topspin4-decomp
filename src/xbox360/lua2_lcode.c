/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* lcode.c: LuaPlus code generator (no line info, wide string constants, reference-counted constants). */
#include "lua2_lparser.h"
#ifdef _MSC_VER
int abs(int x);
#pragma intrinsic(abs)
#else
#include <stdlib.h>
#endif

extern char lbl_880E2534[]; /* "control structure too long" */
extern char lbl_880E2550[]; /* "function or expression too complex" */
extern char lbl_880E2574[]; /* "constant table overflow" */
extern char lbl_880E258C[]; /* "code size overflow" */
extern const lu_byte lbl_880C970C[]; /* luaP_opmodes */
extern const int lbl_880C98E4[];     /* codebinop: {OP_EQ, OP_EQ, OP_LT, OP_LE, OP_LT, OP_LE} */

extern const TValue *ts4_if_call_seq_u32_off0_88812188(Table *t, const TValue *key); /* luaH_get */
extern TValue *lua2_luaH_set_888122E8(lua_State *L, Table *t, const TValue *key);             /* luaH_set */
extern int ts4_call_seq_u32_off20_88820DD0(FuncState *fs);                         /* luaK_jump */
extern void ts4_event_dispatch_888212B8(FuncState *fs, expdesc *e);                /* codenot */
extern int fn_88820948(FuncState *fs);                                              /* nil_constant */

#define MASK1(n, p) ((~((~(Instruction)0) << (n))) << (p))
#define MASK0(n, p) (~MASK1(n, p))
#define GET_OPCODE(i) ((OpCode)((i)&MASK1(6, 0)))
#define GETARG_A(i) ((int)((i) >> 24))
#define SETARG_A(i, u) ((i) = (((i)&MASK0(8, 24)) | (((Instruction)(u) << 24) & MASK1(8, 24))))
#define GETARG_B(i) ((int)(((i) >> 15) & MASK1(9, 0)))
#define SETARG_B(i, b) ((i) = (((i)&MASK0(9, 15)) | (((Instruction)(b) << 15) & MASK1(9, 15))))
#define GETARG_C(i) ((int)(((i) >> 6) & MASK1(9, 0)))
#define SETARG_C(i, b) ((i) = (((i)&MASK0(9, 6)) | (((Instruction)(b) << 6) & MASK1(9, 6))))
#define GETARG_Bx(i) ((int)(((i) >> 6) & MASK1(18, 0)))
#define SETARG_Bx(i, b) ((i) = (((i)&MASK0(18, 6)) | (((Instruction)(b) << 6) & MASK1(18, 6))))
#define MAXARG_sBx (MAXARG_Bx >> 1)
#define GETARG_sBx(i) (GETARG_Bx(i) - MAXARG_sBx)
#define SETARG_sBx(i, b) SETARG_Bx((i), (unsigned int)((b) + MAXARG_sBx))
#define MAXARG_C 0x1FF
#define NO_REG 0xFF
#define OpModeT 7
#define testOpMode(m, b) (lbl_880C970C[m] & (1 << (b)))
#define getcode(fs, e) ((fs)->f->code[(e)->info])
#define hasjumps(e) ((e)->t != (e)->f)

/* Binary operators: LuaPlus adds four arithmetic operators after OPR_POW. */
#define OPR_LASTARITH 8
#define OPR_CONCAT 9
#define OPR_NE 10
#define OPR_GT 14
#define OPR_AND 16
#define OPR_OR 17
#define OPR_MINUS 0

#define luaM_growvector(L, v, nelems, size, t, limit, e) \
    if (((nelems) + 1) > (size)) ((v) = (t *)fn_889CE7D8(L, v, &(size), sizeof(t), limit, e))

LUA2_NOINLINE int lua2_luaK_code_888208A8(FuncState *fs, Instruction i);
LUA2_NOINLINE int lua2_addk_88820600(FuncState *fs, TValue *k, TValue *v);
LUA2_NOINLINE void lua2_luaK_dischargevars_88820C30(FuncState *fs, expdesc *e);
LUA2_NOINLINE void lua2_luaK_exp2nextreg_888214B0(FuncState *fs, expdesc *e);
LUA2_NOINLINE int lua2_luaK_exp2anyreg_888216D0(FuncState *fs, expdesc *e);
LUA2_NOINLINE void lua2_luaK_patchlistaux_88820468(FuncState *fs, int list, int ttarget, int treg, int ftarget, int freg, int dtarget);

LUA2_FORCEINLINE int luaK_codeABC(FuncState *fs, OpCode o, int a, int b, int c)
{
    return lua2_luaK_code_888208A8(fs, CREATE_ABC(o, a, b, c));
}

LUA2_FORCEINLINE int luaK_codeABx(FuncState *fs, OpCode o, int a, unsigned int bc)
{
    return lua2_luaK_code_888208A8(fs, CREATE_ABx(o, a, bc));
}

LUA2_FORCEINLINE int luaK_getlabel(FuncState *fs)
{
    fs->lasttarget = fs->pc;
    return fs->pc;
}

LUA2_FORCEINLINE void setcallreturns_inl(FuncState *fs, expdesc *e, int nresults)
{
    if (e->k == VCALL) {
        SETARG_C(getcode(fs, e), nresults + 1);
        if (nresults == 1) {
            e->k = VNONRELOC;
            e->info = GETARG_A(getcode(fs, e));
        }
    }
}

/* luaK_setcallreturns */
LUA2_NOINLINE void lua2_luaK_setcallreturns_888200C8(FuncState *fs, expdesc *e, int nresults)
{
    setcallreturns_inl(fs, e, nresults);
}

/* getjumpcontrol, specialised by the original build to take the instruction pointer */
LUA2_NOINLINE Instruction *lua2_getjumpcontrol_88820168(Instruction *pi)
{
    if (testOpMode(GET_OPCODE(*(pi - 1)), OpModeT))
        return pi - 1;
    else
        return pi;
}

LUA2_FORCEINLINE Instruction *getjumpcontrol(FuncState *fs, int pc)
{
    Instruction *pi = &fs->f->code[pc];
    if (pc >= 1 && testOpMode(GET_OPCODE(*(pi - 1)), OpModeT))
        return pi - 1;
    else
        return pi;
}

LUA2_FORCEINLINE int getjump_inl(FuncState *fs, int pc)
{
    int offset = GETARG_sBx(fs->f->code[pc]);
    if (offset == NO_JUMP)
        return NO_JUMP;
    else
        return (pc + 1) + offset;
}

/* luaK_getjump */
LUA2_NOINLINE int lua2_luaK_getjump_88820198(FuncState *fs, int pc)
{
    return getjump_inl(fs, pc);
}

/* invertjump */
LUA2_NOINLINE void lua2_invertjump_888201E0(FuncState *fs, expdesc *e)
{
    Instruction *pc = getjumpcontrol(fs, e->info);
    SETARG_A(*pc, !(GETARG_A(*pc)));
}

/* need_value */
LUA2_NOINLINE int lua2_need_value_88820278(FuncState *fs, int list, int cond)
{
    for (; list != NO_JUMP; list = getjump_inl(fs, list)) {
        Instruction i = *getjumpcontrol(fs, list);
        if (GET_OPCODE(i) != OP_TEST || GETARG_C(i) != cond) return 1;
    }
    return 0;
}

LUA2_FORCEINLINE void fixjump_inl(FuncState *fs, int pc, int dest)
{
    Instruction *jmp = &fs->f->code[pc];
    int offset = dest - (pc + 1);
    if (abs(offset) > MAXARG_sBx) lua2_luaX_syntaxerror_888195F0(fs->ls, lbl_880E2534);
    SETARG_sBx(*jmp, offset);
}

/* luaK_fixjump */
LUA2_NOINLINE void lua2_luaK_fixjump_88820350(FuncState *fs, int pc, int dest)
{
    fixjump_inl(fs, pc, dest);
}

/* luaK_checkstack */
LUA2_NOINLINE void lua2_luaK_checkstack_888203A8(FuncState *fs, int n)
{
    int newstack = fs->freereg + n;
    if (newstack > fs->f->maxstacksize) {
        if (newstack >= MAXSTACK) lua2_luaX_syntaxerror_888195F0(fs->ls, lbl_880E2550);
        fs->f->maxstacksize = (lu_byte)newstack;
    }
    fs->freereg += n;
}

LUA2_FORCEINLINE void luaK_reserveregs(FuncState *fs, int n)
{
    int newstack = fs->freereg + n;
    if (newstack > fs->f->maxstacksize) {
        if (newstack >= MAXSTACK) lua2_luaX_syntaxerror_888195F0(fs->ls, lbl_880E2550);
        fs->f->maxstacksize = (lu_byte)newstack;
    }
    fs->freereg += n;
}

/* luaK_concat */
LUA2_NOINLINE void lua2_luaK_concat_888203F0(FuncState *fs, int *l1, int l2)
{
    if (l2 == NO_JUMP) return;
    else if (*l1 == NO_JUMP)
        *l1 = l2;
    else {
        int list = *l1;
        int next;
        while ((next = getjump_inl(fs, list)) != NO_JUMP) /* find last element */
            list = next;
        lua2_luaK_fixjump_88820350(fs, list, l2);
    }
}

LUA2_FORCEINLINE void patchtestreg(Instruction *i, int reg)
{
    if (reg == NO_REG) reg = GETARG_B(*i);
    SETARG_A(*i, reg);
}

/* luaK_patchlistaux */
LUA2_NOINLINE void lua2_luaK_patchlistaux_88820468(FuncState *fs, int list, int ttarget, int treg, int ftarget, int freg, int dtarget)
{
    while (list != NO_JUMP) {
        int next = getjump_inl(fs, list);
        Instruction *i = getjumpcontrol(fs, list);
        if (GET_OPCODE(*i) != OP_TEST) {
            fixjump_inl(fs, list, dtarget);
        } else {
            if (GETARG_C(*i)) {
                patchtestreg(i, treg);
                fixjump_inl(fs, list, ttarget);
            } else {
                patchtestreg(i, freg);
                fixjump_inl(fs, list, ftarget);
            }
        }
        list = next;
    }
}

/* luaK_wstringK */
LUA2_NOINLINE int lua2_luaK_wstringK_888207C8(FuncState *fs, TString *s)
{
    lua_State *L = fs->L;
    TValue o;
    int n;
    o.tt = LUA2_TNIL;
    o.value.p = 0;
    setgcvalue(L, &o, s, LUA2_TWSTRING);
    n = lua2_addk_88820600(fs, &o, &o);
    LUA2_RELEASE(L, &o);
    return n;
}

/* luaK_code */
LUA2_NOINLINE int lua2_luaK_code_888208A8(FuncState *fs, Instruction i)
{
    Proto *f = fs->f;
    lua2_luaK_patchlistaux_88820468(fs, fs->jpc, fs->pc, NO_REG, fs->pc, NO_REG, fs->pc);
    fs->jpc = NO_JUMP;
    luaM_growvector(fs->L, f->code, fs->pc, f->sizecode, Instruction, MAX_INT, lbl_880E258C);
    f->code[fs->pc] = i;
    return fs->pc++;
}

/* addk */
LUA2_NOINLINE int lua2_addk_88820600(FuncState *fs, TValue *k, TValue *v)
{
    const TValue *idx = ts4_if_call_seq_u32_off0_88812188(fs->h, k);
    lua_State *L = fs->L;
    if (ttype(idx) == LUA2_TNUMBER) {
        return (int)nvalue(idx);
    } else {
        Proto *f = fs->f;
        TValue *o1;
        TValue *o2;
        luaM_growvector(L, f->k, fs->nk, f->sizek, TValue, MAXARG_Bx, lbl_880E2574);
        o1 = &f->k[fs->nk];
        o1->tt = v->tt;
        o1->value = v->value;
        LUA2_ADDREF(o1);
        o2 = lua2_luaH_set_888122E8(fs->L, fs->h, k);
        LUA2_RELEASE(L, o2);
        o2->tt = LUA2_TNUMBER;
        o2->value.n = (double)fs->nk;
        return fs->nk++;
    }
}

/* luaK_numberK */
LUA2_NOINLINE int lua2_luaK_numberK_88820A68(FuncState *fs, double r)
{
    lua_State *L = fs->L;
    TValue o;
    int n;
    o.tt = LUA2_TNUMBER;
    o.value.n = r;
    n = lua2_addk_88820600(fs, &o, &o);
    LUA2_RELEASE(L, &o);
    return n;
}

/* luaK_stringK */
LUA2_NOINLINE int lua2_luaK_stringK_88820AF0(FuncState *fs, TString *s)
{
    lua_State *L = fs->L;
    TValue o;
    int n;
    o.tt = LUA2_TNIL;
    o.value.p = 0;
    setgcvalue(L, &o, s, LUA2_TSTRING);
    n = lua2_addk_88820600(fs, &o, &o);
    LUA2_RELEASE(L, &o);
    return n;
}

LUA2_FORCEINLINE void freereg(FuncState *fs, int reg)
{
    if (reg >= fs->nactvar && reg < MAXSTACK) fs->freereg--;
}

LUA2_FORCEINLINE void freeexp(FuncState *fs, expdesc *e)
{
    if (e->k == VNONRELOC) freereg(fs, e->info);
}

/* luaK_dischargevars */
LUA2_NOINLINE void lua2_luaK_dischargevars_88820C30(FuncState *fs, expdesc *e)
{
    switch (e->k) {
    case VLOCAL: {
        e->k = VNONRELOC;
        break;
    }
    case VUPVAL: {
        e->info = luaK_codeABC(fs, OP_GETUPVAL, 0, e->info, 0);
        e->k = VRELOCABLE;
        break;
    }
    case VGLOBAL: {
        e->info = luaK_codeABx(fs, OP_GETGLOBAL, 0, e->info);
        e->k = VRELOCABLE;
        break;
    }
    case VINDEXED: {
        freereg(fs, e->aux);
        freereg(fs, e->info);
        e->info = luaK_codeABC(fs, OP_GETTABLE, 0, e->info, e->aux);
        e->k = VRELOCABLE;
        break;
    }
    case VCALL: {
        setcallreturns_inl(fs, e, 1);
        break;
    }
    default:
        break; /* there is one value available (somewhere) */
    }
}

/* luaK_nil */
LUA2_NOINLINE void lua2_luaK_nil_88820E30(FuncState *fs, int from, int n)
{
    Instruction *previous;
    if (fs->pc > fs->lasttarget && /* no jumps to current position? */
        GET_OPCODE(*(previous = &fs->f->code[fs->pc - 1])) == OP_LOADNIL) {
        int pfrom = GETARG_A(*previous);
        int pto = GETARG_B(*previous);
        if (pfrom <= from && from <= pto + 1) { /* can connect both? */
            if (from + n - 1 > pto) SETARG_B(*previous, from + n - 1);
            return;
        }
    }
    luaK_codeABC(fs, OP_LOADNIL, from, from + n - 1, 0); /* else no optimization */
}

/* discharge2reg */
LUA2_NOINLINE void lua2_discharge2reg_88820EB8(FuncState *fs, expdesc *e, int reg)
{
    lua2_luaK_dischargevars_88820C30(fs, e);
    switch (e->k) {
    case VNIL: {
        lua2_luaK_nil_88820E30(fs, reg, 1);
        break;
    }
    case VFALSE:
    case VTRUE: {
        luaK_codeABC(fs, OP_LOADBOOL, reg, e->k == VTRUE, 0);
        break;
    }
    case VK: {
        luaK_codeABx(fs, OP_LOADK, reg, e->info);
        break;
    }
    case VRELOCABLE: {
        Instruction *pc = &getcode(fs, e);
        SETARG_A(*pc, reg);
        break;
    }
    case VNONRELOC: {
        if (reg != e->info) luaK_codeABC(fs, OP_MOVE, reg, e->info, 0);
        break;
    }
    default: {
        return; /* nothing to do... */
    }
    }
    e->info = reg;
    e->k = VNONRELOC;
}

LUA2_FORCEINLINE int condjump_inl(FuncState *fs, OpCode op, int A, int B, int C)
{
    luaK_codeABC(fs, op, A, B, C);
    return ts4_call_seq_u32_off20_88820DD0(fs);
}

/* condjump */
LUA2_NOINLINE int lua2_condjump_88820FE8(FuncState *fs, OpCode op, int A, int B, int C)
{
    return condjump_inl(fs, op, A, B, C);
}

/* codebinop */
LUA2_NOINLINE void lua2_codebinop_88821038(FuncState *fs, expdesc *res, int op, int o1, int o2)
{
    if (op <= OPR_LASTARITH) {
        OpCode opc = (OpCode)(op + OP_ADD);
        res->info = luaK_codeABC(fs, opc, 0, o1, o2);
        res->k = VRELOCABLE;
    } else { /* test operator */
        int cond = 1;
        if (op >= OPR_GT) { /* `>' or `>='? */
            int temp; /* exchange args and replace by `<' or `<=' */
            temp = o1;
            o1 = o2;
            o2 = temp; /* o1 <==> o2 */
        } else if (op == OPR_NE)
            cond = 0;
        res->info = condjump_inl(fs, (OpCode)lbl_880C98E4[op - OPR_NE], cond, o1, o2);
        res->k = VJMP;
    }
}

LUA2_FORCEINLINE int code_label(FuncState *fs, int A, int b, int jump)
{
    luaK_getlabel(fs); /* those instructions may be jump targets */
    return luaK_codeABC(fs, OP_LOADBOOL, A, b, jump);
}

/* luaK_exp2reg */
LUA2_NOINLINE void lua2_luaK_exp2reg_88821110(FuncState *fs, expdesc *e, int reg)
{
    lua2_discharge2reg_88820EB8(fs, e, reg);
    if (e->k == VJMP) lua2_luaK_concat_888203F0(fs, &e->t, e->info); /* put this jump in `t' list */
    if (hasjumps(e)) {
        int final;          /* position after whole expression */
        int p_f = NO_JUMP; /* position of an eventual LOAD false */
        int p_t = NO_JUMP; /* position of an eventual LOAD true */
        if (lua2_need_value_88820278(fs, e->t, 1) || lua2_need_value_88820278(fs, e->f, 0)) {
            int fj = NO_JUMP; /* first jump (over LOAD ops.) */
            if (e->k != VJMP) fj = ts4_call_seq_u32_off20_88820DD0(fs);
            p_f = code_label(fs, reg, 0, 1);
            p_t = code_label(fs, reg, 1, 0);
            luaK_getlabel(fs);
            lua2_luaK_concat_888203F0(fs, &fs->jpc, fj);
        }
        final = luaK_getlabel(fs);
        lua2_luaK_patchlistaux_88820468(fs, e->f, p_f, NO_REG, final, reg, p_f);
        lua2_luaK_patchlistaux_88820468(fs, e->t, final, reg, p_t, NO_REG, p_t);
    }
    e->f = e->t = NO_JUMP;
    e->info = reg;
    e->k = VNONRELOC;
}

/* discharge2anyreg */
LUA2_NOINLINE void lua2_discharge2anyreg_88821260(FuncState *fs, expdesc *e)
{
    if (e->k != VNONRELOC) {
        luaK_reserveregs(fs, 1);
        lua2_discharge2reg_88820EB8(fs, e, fs->freereg - 1);
    }
}

/* jumponcond */
LUA2_NOINLINE int lua2_jumponcond_888213D8(FuncState *fs, expdesc *e, int cond)
{
    if (e->k == VRELOCABLE) {
        Instruction ie = getcode(fs, e);
        if (GET_OPCODE(ie) == OP_NOT) {
            fs->pc--; /* remove previous OP_NOT */
            return condjump_inl(fs, OP_TEST, NO_REG, GETARG_B(ie), !cond);
        }
        /* else go through */
    }
    lua2_discharge2anyreg_88821260(fs, e);
    freeexp(fs, e);
    return condjump_inl(fs, OP_TEST, NO_REG, e->info, cond);
}

/* luaK_exp2nextreg */
LUA2_NOINLINE void lua2_luaK_exp2nextreg_888214B0(FuncState *fs, expdesc *e)
{
    lua2_luaK_dischargevars_88820C30(fs, e);
    freeexp(fs, e);
    luaK_reserveregs(fs, 1);
    lua2_luaK_exp2reg_88821110(fs, e, fs->freereg - 1);
}

/* luaK_goiffalse */
LUA2_NOINLINE void lua2_luaK_goiffalse_88821568(FuncState *fs, expdesc *e)
{
    int pc; /* pc of last jump */
    lua2_luaK_dischargevars_88820C30(fs, e);
    switch (e->k) {
    case VNIL:
    case VFALSE: {
        pc = NO_JUMP; /* always false; do nothing */
        break;
    }
    case VTRUE: {
        pc = ts4_call_seq_u32_off20_88820DD0(fs); /* always jump */
        break;
    }
    case VJMP: {
        pc = e->info;
        break;
    }
    default: {
        pc = lua2_jumponcond_888213D8(fs, e, 1);
        break;
    }
    }
    lua2_luaK_concat_888203F0(fs, &e->t, pc); /* insert last jump in `t' list */
}

/* luaK_goiftrue */
LUA2_NOINLINE void lua2_luaK_goiftrue_88821618(FuncState *fs, expdesc *e)
{
    int pc; /* pc of last jump */
    lua2_luaK_dischargevars_88820C30(fs, e);
    switch (e->k) {
    case VK:
    case VTRUE: {
        pc = NO_JUMP; /* always true; do nothing */
        break;
    }
    case VFALSE: {
        pc = ts4_call_seq_u32_off20_88820DD0(fs); /* always jump */
        break;
    }
    case VJMP: {
        lua2_invertjump_888201E0(fs, e);
        pc = e->info;
        break;
    }
    default: {
        pc = lua2_jumponcond_888213D8(fs, e, 0);
        break;
    }
    }
    lua2_luaK_concat_888203F0(fs, &e->f, pc); /* insert last jump in `f' list */
}

/* luaK_exp2anyreg */
LUA2_NOINLINE int lua2_luaK_exp2anyreg_888216D0(FuncState *fs, expdesc *e)
{
    lua2_luaK_dischargevars_88820C30(fs, e);
    if (e->k == VNONRELOC) {
        if (!hasjumps(e)) return e->info; /* exp is already in a register */
        if (e->info >= fs->nactvar) {     /* reg. is not a local? */
            lua2_luaK_exp2reg_88821110(fs, e, e->info); /* put value on it */
            return e->info;
        }
    }
    lua2_luaK_exp2nextreg_888214B0(fs, e); /* default */
    return e->info;
}

LUA2_FORCEINLINE void luaK_exp2val(FuncState *fs, expdesc *e)
{
    if (hasjumps(e))
        lua2_luaK_exp2anyreg_888216D0(fs, e);
    else
        lua2_luaK_dischargevars_88820C30(fs, e);
}

/* luaK_prefix */
LUA2_NOINLINE void lua2_luaK_prefix_88821770(FuncState *fs, int op, expdesc *e)
{
    if (op == OPR_MINUS) {
        luaK_exp2val(fs, e);
        if (e->k == VK && ttype(&fs->f->k[e->info]) == LUA2_TNUMBER)
            e->info = lua2_luaK_numberK_88820A68(fs, -nvalue(&fs->f->k[e->info]));
        else {
            lua2_luaK_exp2anyreg_888216D0(fs, e);
            freeexp(fs, e);
            e->info = luaK_codeABC(fs, OP_UNM, 0, e->info, 0);
            e->k = VRELOCABLE;
        }
    } else /* op == NOT */
        ts4_event_dispatch_888212B8(fs, e);
}

/* luaK_exp2RK */
LUA2_NOINLINE int lua2_luaK_exp2RK_88821878(FuncState *fs, expdesc *e)
{
    luaK_exp2val(fs, e);
    switch (e->k) {
    case VNIL: {
        if (fs->nk + MAXSTACK <= MAXARG_C) { /* constant fit in argC? */
            e->info = fn_88820948(fs);
            e->k = VK;
            return e->info + MAXSTACK;
        } else
            break;
    }
    case VK: {
        if (e->info + MAXSTACK <= MAXARG_C) /* constant fit in argC? */
            return e->info + MAXSTACK;
        else
            break;
    }
    default:
        break;
    }
    /* not a constant in the right range: put it in a register */
    return lua2_luaK_exp2anyreg_888216D0(fs, e);
}

/* luaK_posfix */
LUA2_NOINLINE void lua2_luaK_posfix_88821928(FuncState *fs, int op, expdesc *e1, expdesc *e2)
{
    switch (op) {
    case OPR_AND: {
        lua2_luaK_dischargevars_88820C30(fs, e2);
        lua2_luaK_concat_888203F0(fs, &e1->f, e2->f);
        e1->k = e2->k;
        e1->info = e2->info;
        e1->aux = e2->aux;
        e1->t = e2->t;
        break;
    }
    case OPR_OR: {
        lua2_luaK_dischargevars_88820C30(fs, e2);
        lua2_luaK_concat_888203F0(fs, &e1->t, e2->t);
        e1->k = e2->k;
        e1->info = e2->info;
        e1->aux = e2->aux;
        e1->f = e2->f;
        break;
    }
    case OPR_CONCAT: {
        luaK_exp2val(fs, e2);
        if (e2->k == VRELOCABLE && GET_OPCODE(getcode(fs, e2)) == OP_CONCAT) {
            freeexp(fs, e1);
            SETARG_B(getcode(fs, e2), e1->info);
            e1->k = e2->k;
            e1->info = e2->info;
        } else {
            lua2_luaK_exp2nextreg_888214B0(fs, e2);
            freeexp(fs, e2);
            freeexp(fs, e1);
            e1->info = luaK_codeABC(fs, OP_CONCAT, 0, e1->info, e2->info);
            e1->k = VRELOCABLE;
        }
        break;
    }
    default: {
        int o1 = lua2_luaK_exp2RK_88821878(fs, e1);
        int o2 = lua2_luaK_exp2RK_88821878(fs, e2);
        freeexp(fs, e2);
        freeexp(fs, e1);
        lua2_codebinop_88821038(fs, e1, op, o1, o2);
    }
    }
}

/* luaK_self */
LUA2_NOINLINE void lua2_luaK_self_88821CC0(FuncState *fs, expdesc *e, expdesc *key)
{
    int func;
    lua2_luaK_exp2anyreg_888216D0(fs, e);
    freeexp(fs, e);
    func = fs->freereg;
    luaK_reserveregs(fs, 2);
    luaK_codeABC(fs, OP_SELF, func, e->info, lua2_luaK_exp2RK_88821878(fs, key));
    freeexp(fs, key);
    e->info = func;
    e->k = VNONRELOC;
}

/* luaK_storevar */
LUA2_NOINLINE void lua2_luaK_storevar_88821DC8(FuncState *fs, expdesc *var, expdesc *ex)
{
    switch (var->k) {
    case VLOCAL: {
        freeexp(fs, ex);
        lua2_luaK_exp2reg_88821110(fs, ex, var->info);
        return;
    }
    case VUPVAL: {
        int e = lua2_luaK_exp2anyreg_888216D0(fs, ex);
        luaK_codeABC(fs, OP_SETUPVAL, e, var->info, 0);
        break;
    }
    case VGLOBAL: {
        int e = lua2_luaK_exp2anyreg_888216D0(fs, ex);
        luaK_codeABx(fs, OP_SETGLOBAL, e, var->info);
        break;
    }
    case VINDEXED: {
        int e = lua2_luaK_exp2RK_88821878(fs, ex);
        luaK_codeABC(fs, OP_SETTABLE, var->info, var->aux, e);
        break;
    }
    default: {
        break;
    }
    }
    freeexp(fs, ex);
}
