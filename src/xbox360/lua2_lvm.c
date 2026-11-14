/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex (reference counting, per-type metatables). lvm.c. */
#include "lua2.h"

#define MAXTAGLOOP 100

extern const TValue *ts4_if_call_seq_u32_off0_88812188(Table *t, const TValue *key); /* luaH_get */
extern const TValue *lua2_luaT_gettm_88811168(Table *events, int event, TString *ename);       /* luaT_gettm */
extern const TValue *lu1_call_orderTM_8880C480(lua_State *L, Table *mt1, Table *mt2); /* get_compTM(.., TM_EQ) */
extern void lua2_luaD_call_8881E258(lua_State *L, StkId func, int nresults);                   /* luaD_call */
extern void fn_8881FB60(lua_State *L, const char *fmt, ...);                       /* luaG_runerror */
extern void fn_8881F6D8(lua_State *L, const TValue *o, const char *opname);         /* luaG_typeerror */
extern char lbl_880E2E80[]; /* "index" */
extern char lbl_880E2E88[]; /* "loop in gettable" */

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

/* luaO_rawequalObj (lobject.c) */
LUA2_LOCAL int lib3_luaO_rawequalObj_88818240(const TValue *t1, const TValue *t2)
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

/* callTMres: call f(p1, p2) leaving the result at L->top. */
void lua2_callTMres_8880F770(lua_State *L, const TValue *f, const TValue *p1, const TValue *p2)
{
    setobj(L, L->top, f);
    setobj(L, L->top + 1, p1);
    setobj(L, L->top + 2, p2);
    luaD_checkstack(L, 3);
    L->top += 3;
    lua2_luaD_call_8881E258(L, L->top - 3, 1);
    L->top--;
}

/* call_orderTM */
int lua2_call_orderTM_8880C360(lua_State *L, const TValue *p1, const TValue *p2, int event)
{
    const TValue *tm1 = luaT_gettmbyobj(L, p1, event);
    const TValue *tm2;
    if (ttype(tm1) == LUA2_TNIL) return -1;
    tm2 = luaT_gettmbyobj(L, p2, event);
    if (!lib3_luaO_rawequalObj_88818240(tm1, tm2)) return -1;
    lua2_callTMres_8880F770(L, tm1, p1, p2);
    return !l_isfalse(L->top);
}

/* luaV_equalval */
int lua2_luaV_equalval_8880C538(lua_State *L, const TValue *t1, const TValue *t2)
{
    const TValue *tm;
    switch (ttype(t1)) {
    case LUA2_TNIL: return 1;
    case LUA2_TNUMBER: return nvalue(t1) == nvalue(t2);
    case LUA2_TBOOLEAN: return bvalue(t1) == bvalue(t2);
    case LUA2_TLIGHTUSERDATA: return t1->value.p == t2->value.p;
    case LUA2_TUSERDATA:
        if (uvalue(t1) == uvalue(t2)) return 1;
        tm = lu1_call_orderTM_8880C480(L, uvalue(t1)->metatable, uvalue(t2)->metatable);
        break;
    case LUA2_TTABLE:
        if (hvalue(t1) == hvalue(t2)) return 1;
        tm = lu1_call_orderTM_8880C480(L, hvalue(t1)->metatable, hvalue(t2)->metatable);
        break;
    default: return t1->value.gc == t2->value.gc;
    }
    if (tm == 0) return 0;
    lua2_callTMres_8880F770(L, tm, t1, t2);
    return !l_isfalse(L->top);
}

const TValue *lua2_luaV_gettable_8880D4B0(lua_State *L, const TValue *t, TValue *key, int loop);

/* luaV_getnotable: without an __index entry the metatable itself is indexed. */
const TValue *lua2_luaV_getnotable_8880CBC8(lua_State *L, const TValue *t, TValue *key, int loop)
{
    const TValue *tm = luaT_gettmbyobj(L, t, 0);
    TValue temp;
    if (ttype(tm) == LUA2_TNIL) {
        Table *mt;
        switch (ttype(t)) {
        case LUA2_TTABLE: mt = hvalue(t)->metatable; break;
        case LUA2_TUSERDATA: mt = uvalue(t)->metatable; break;
        default: mt = hvalue(&G(L)->mt[ttype(t)]); break;
        }
        if (mt == 0) fn_8881F6D8(L, t, lbl_880E2E80);
        temp.tt = LUA2_TNIL;
        temp.value.p = 0;
        setgcvalue(L, &temp, mt, LUA2_TTABLE);
        tm = &temp;
    }
    if (ttype(tm) == LUA2_TFUNCTION) {
        lua2_callTMres_8880F770(L, tm, t, key);
        return L->top;
    }
    return lua2_luaV_gettable_8880D4B0(L, tm, key, loop);
}

/* luaV_index */
const TValue *lua2_luaV_index_8880D540(lua_State *L, const TValue *t, TValue *key, int loop)
{
    Table *mt = hvalue(t)->metatable;
    const TValue *tm = (mt->flags & 1) ? 0 : lua2_luaT_gettm_88811168(mt, 0, G(L)->tmname[0]);
    if (tm == 0) return &lbl_880C9748;
    if (ttype(tm) == LUA2_TFUNCTION) {
        lua2_callTMres_8880F770(L, tm, t, key);
        return L->top;
    }
    return lua2_luaV_gettable_8880D4B0(L, tm, key, loop);
}

/* luaV_gettable */
const TValue *lua2_luaV_gettable_8880D4B0(lua_State *L, const TValue *t, TValue *key, int loop)
{
    if (loop > MAXTAGLOOP) fn_8881FB60(L, lbl_880E2E88);
    if (ttype(t) == LUA2_TTABLE) {
        const TValue *v = ts4_if_call_seq_u32_off0_88812188(hvalue(t), key);
        if (ttype(v) != LUA2_TNIL) return v;
        return lua2_luaV_index_8880D540(L, t, key, loop + 1);
    }
    return lua2_luaV_getnotable_8880CBC8(L, t, key, loop + 1);
}

/* call_binTM */
int lua2_call_binTM_8880F928(lua_State *L, const TValue *p1, const TValue *p2, StkId res, int event)
{
    int result = savestack(L, res);
    const TValue *tm = luaT_gettmbyobj(L, p1, event);
    if (ttype(tm) == LUA2_TNIL) tm = luaT_gettmbyobj(L, p2, event);
    if (ttype(tm) != LUA2_TFUNCTION) return 0;
    lua2_callTMres_8880F770(L, tm, p1, p2);
    res = restorestack(L, result);
    setobj(L, res, L->top);
    return 1;
}

/* callTM: call f(p1, p2, p3) with no results. */
void lua2_callTM_8880C7E0(lua_State *L, const TValue *f, const TValue *p1, const TValue *p2, const TValue *p3)
{
    setobj(L, L->top, f);
    setobj(L, L->top + 1, p1);
    setobj(L, L->top + 2, p2);
    setobj(L, L->top + 3, p3);
    luaD_checkstack(L, 4);
    L->top += 4;
    lua2_luaD_call_8881E258(L, L->top - 4, 0);
}

extern void lua2_luaD_callhook_8881D5A8(lua_State *L, int event, int line); /* luaD_callhook */
extern void ts4_loop_get_u32_off18_8881F450(lua_State *L);   /* luaG_inithooks */

/* traceexec */
void lua2_traceexec_8880CD38(lua_State *L)
{
    lu_byte mask = L->hookmask;
    if (mask & 8) {
        if (L->hookcount == 0) {
            L->hookcount = L->basehookcount;
            lua2_luaD_callhook_8881D5A8(L, 3, -1);
            return;
        }
    }
    if (mask & 4) {
        CallInfo *ci = L->ci;
        Proto *p = ci_func(ci)->l.p;
        int newline = getline(p, pcRel(*ci->pc, p));
        if (!L->hookinit) {
            ts4_loop_get_u32_off18_8881F450(L);
            return;
        }
        if (pcRel(*ci->pc, p) == 0) ci->savedpc = *ci->pc;
        if (*ci->pc <= ci->savedpc || newline != getline(p, pcRel(ci->savedpc, p))) {
            lua2_luaD_callhook_8881D5A8(L, 2, newline);
            ci = L->ci;
        }
        ci->savedpc = *ci->pc;
    }
}

extern TValue *lua2_luaH_set_888122E8(lua_State *L, Table *t, const TValue *key);          /* luaH_set */
extern void *ts4_if_call_seq_u32_off0_88812238(Table *t, const TValue *key);    /* find the key's node */
extern void lua2_removenode_88811FE8(lua_State *L, Table *t, void *n);                         /* remove the node */
extern char lbl_880E2E9C[]; /* "loop in settable" */

/* luaT_gettm, expanded inline (caches a missing method in the flags). */
LUA2_FORCEINLINE const TValue *luaT_gettm_inl(Table *events, int event, TString *ename)
{
    const TValue *tm = ts4_loop_get_u8_offd_888114E0(events, ename);
    if (ttype(tm) == LUA2_TNIL) {
        events->flags |= (lu_byte)(1u << event);
        return 0;
    }
    return tm;
}

/* luaV_settable: storing nil removes the key from the table. */
void lua2_luaV_settable_8880D278(lua_State *L, const TValue *t, TValue *key, StkId val)
{
    const TValue *tm;
    int loop = 0;
    do {
        if (ttype(t) == LUA2_TTABLE) {
            Table *h = hvalue(t);
            TValue *oldval = lua2_luaH_set_888122E8(L, h, key);
            if (ttype(oldval) != LUA2_TNIL ||
                (tm = (h->metatable->flags & 2) ? 0 : luaT_gettm_inl(h->metatable, 1, G(L)->tmname[1])) == 0) {
                setobj(L, oldval, val);
                if (ttype(val) == LUA2_TNIL) {
                    void *n = ts4_if_call_seq_u32_off0_88812238(h, key);
                    if (n) lua2_removenode_88811FE8(L, h, n);
                }
                return;
            }
        } else if (ttype(tm = luaT_gettmbyobj(L, t, 1)) == LUA2_TNIL)
            fn_8881F6D8(L, t, lbl_880E2E80);
        if (ttype(tm) == LUA2_TFUNCTION) {
            lua2_callTM_8880C7E0(L, tm, t, key, val);
            if (ttype(t) == LUA2_TTABLE) {
                if (ttype(lua2_luaH_set_888122E8(L, hvalue(t), key)) == LUA2_TNIL) {
                    void *n = ts4_if_call_seq_u32_off0_88812238(hvalue(t), key);
                    if (n) lua2_removenode_88811FE8(L, hvalue(t), n);
                }
            }
            return;
        }
        t = tm;
    } while (++loop <= MAXTAGLOOP);
    fn_8881FB60(L, lbl_880E2E9C);
}

extern TValue *ts4_lua_v_tonumber_8880CAF0(lua_State *L, const TValue *obj, TValue *n);
extern void fn_8881F848(lua_State *L, const TValue *p1, const TValue *p2); /* luaG_aritherror */
extern char lbl_880E2EC8[]; /* "`__pow' (`^' operator) is not a function" */

#define setnvalue(L, obj, x) \
    { \
        TValue *o_ = (obj); \
        LUA2_RELEASE((L), o_); \
        o_->tt = LUA2_TNUMBER; \
        o_->value.n = (x); \
    }

/* Arith: the number temporaries are counted values and are cleared before use or error. */
void lua2_Arith_8880CEA0(lua_State *L, StkId ra, const TValue *rb, const TValue *rc, int op)
{
    TValue tempb, tempc;
    const TValue *b, *c;
    tempb.tt = LUA2_TNIL;
    tempb.value.p = 0;
    tempc.tt = LUA2_TNIL;
    tempc.value.p = 0;
    if ((b = ts4_lua_v_tonumber_8880CAF0(L, rb, &tempb)) != 0 &&
        (c = ts4_lua_v_tonumber_8880CAF0(L, rc, &tempc)) != 0) {
        setnilvalue(L, &tempb);
        setnilvalue(L, &tempc);
        switch (op) {
        case 5: setnvalue(L, ra, nvalue(b) + nvalue(c)); break;
        case 6: setnvalue(L, ra, nvalue(b) - nvalue(c)); break;
        case 7: setnvalue(L, ra, nvalue(b) * nvalue(c)); break;
        case 8: setnvalue(L, ra, nvalue(b) / nvalue(c)); break;
        case 9: {
            const TValue *f = ts4_loop_get_u8_offd_888114E0(hvalue(&L->_gt), G(L)->tmname[9]);
            int res = savestack(L, ra);
            if (ttype(f) != LUA2_TFUNCTION) fn_8881FB60(L, lbl_880E2EC8);
            lua2_callTMres_8880F770(L, f, b, c);
            ra = restorestack(L, res);
            setobj(L, ra, L->top);
            break;
        }
        default: break;
        }
    } else if (!lua2_call_binTM_8880F928(L, rb, rc, ra, op)) {
        setnilvalue(L, &tempb);
        setnilvalue(L, &tempc);
        fn_8881F848(L, rb, rc);
    }
}

