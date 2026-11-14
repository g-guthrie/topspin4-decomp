/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* ltable.c: table traversal (luaH_index, luaH_next). */
#include "lua2.h"

LUA2_DEFINE_RUNERROR
extern const TValue *ts4_if_call_seq_u32_off0_88812188(Table *t, const TValue *key); /* luaH_get */
extern char lbl_880E2C14[]; /* "invalid key for `next'" */

#define MAXBITS 24
#define twoto(x) (1 << (x))
#define sizenode(t) (twoto((t)->lsizenode))
#define gnode(t, i) (&(t)->node[i])
#define gkey(n) (&(n)->i_key)
#define gval(n) (&(n)->i_val)

/* arrayindex */
LUA2_LOCAL int ts4_if_get_u32_off0_88811880(const TValue *key)
{
    if (ttype(key) == LUA2_TNUMBER) {
        int k = (int)nvalue(key);
        if ((double)k == nvalue(key) && k >= 1 && !(((k - 1) >> MAXBITS) != 0)) return k;
    }
    return -1;
}

/* luaH_index */
int lua2_luaH_index_888129D0(lua_State *L, Table *t, StkId key)
{
    int i;
    if (ttype(key) == LUA2_TNIL) return -1;
    i = ts4_if_get_u32_off0_88811880(key);
    if (0 <= i && i <= t->sizearray) return i - 1;
    else {
        const TValue *v = ts4_if_call_seq_u32_off0_88812188(t, key);
        if (v == &lbl_880C9748) fn_8881FB60(L, lbl_880E2C14);
        i = (int)(((const lu_byte *)v - (const lu_byte *)gval(gnode(t, 0))) / sizeof(Node));
        return i + t->sizearray;
    }
}
#define setnvalue_rc(L, obj, x) \
    { \
        TValue *o_ = (obj); \
        LUA2_RELEASE((L), o_); \
        o_->value.n = (x); \
        o_->tt = LUA2_TNUMBER; \
    }

/* luaH_next */
int lua2_luaH_next_88812A88(lua_State *L, Table *t, StkId key)
{
    int i = lua2_luaH_index_888129D0(L, t, key);
    for (i++; i < t->sizearray; i++) {
        if (ttype(&t->array[i]) != LUA2_TNIL) {
            setnvalue_rc(L, key, (double)(i + 1));
            setobj(L, key + 1, &t->array[i]);
            return 1;
        }
    }
    for (i -= t->sizearray; i < sizenode(t); i++) {
        if (ttype(gval(gnode(t, i))) != LUA2_TNIL) {
            setobj(L, key, gkey(gnode(t, i)));
            setobj(L, key + 1, gval(gnode(t, i)));
            return 1;
        }
    }
    return 0;
}
