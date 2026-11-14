/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* ltm.c: tag-method names and lookup; metatables are reference counted. */
#include "lua2.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
extern int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(memcmp, strlen)
#else
#include <string.h>
#endif

extern TString *lua2_newlstr_88812EE0(lua_State *L, const char *str, u32 l, u32 h); /* newlstr */
extern const char *lbl_880C96AC[]; /* luaT_eventname: "__index" ... "__call" */

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

/* luaT_gettm: a missing method is cached as a flag bit. */
const TValue *lua2_luaT_gettm_88811168(Table *events, int event, TString *ename)
{
    const TValue *tm = ts4_loop_get_u8_offd_888114E0(events, ename);
    if (ttype(tm) == LUA2_TNIL) {
        events->flags |= (lu_byte)(1u << event);
        return 0;
    }
    return tm;
}

/* luaS_newlstr (lstring.c), expanded here by LTCG. */
LUA2_FORCEINLINE TString *luaS_newlstr_inl(lua_State *L, const char *str, u32 l)
{
    GCheader *o;
    u32 h = (u32)l;
    u32 step = (l >> 5) + 1;
    u32 l1;
    for (l1 = l; l1 >= step; l1 -= step)
        h = h ^ ((h << 5) + (h >> 2) + (unsigned char)str[l1 - 1]);
    for (o = G(L)->strt.hash[h & (G(L)->strt.size - 1)]; o != 0; o = o->next) {
        TString *ts = (TString *)o;
        if (o->tt == LUA2_TSTRING && ts->len == l && memcmp(str, getstr(ts), l) == 0)
            return ts;
    }
    return lua2_newlstr_88812EE0(L, str, l, h);
}

/* luaT_init: intern the event names and pin them (fixed bit, one reference). */
void lua2_luaT_init_888111C0(lua_State *L)
{
    int i;
    for (i = 0; i < 15; i++) {
        G(L)->tmname[i] = luaS_newlstr_inl(L, lbl_880C96AC[i], strlen(lbl_880C96AC[i]));
        G(L)->tmname[i]->h.marked |= 0x10;
        G(L)->tmname[i]->h.refs = 1;
    }
}

/* Set the metatable of a table, a userdata or (for other types) the per-type global slot. */
void lua2_setmetatable_88811318(lua_State *L, const TValue *obj, Table *mt)
{
    switch (ttype(obj)) {
    case LUA2_TTABLE:
        if (mt->h.tt >= LUA2_TSTRING) mt->h.refs++;
        if (hvalue(obj)->metatable != 0) {
            Table *old = hvalue(obj)->metatable;
            if (--old->h.refs == 0) fn_88818C88(L, &old->h);
        }
        hvalue(obj)->metatable = mt;
        break;
    case LUA2_TUSERDATA:
        if (mt->h.tt >= LUA2_TSTRING) mt->h.refs++;
        if (uvalue(obj)->metatable != 0) {
            Table *old = uvalue(obj)->metatable;
            if (--old->h.refs == 0) fn_88818C88(L, &old->h);
        }
        uvalue(obj)->metatable = mt;
        break;
    default:
        setgcvalue(L, &G(L)->mt[ttype(obj)], mt, LUA2_TTABLE);
        break;
    }
}
