/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* ltable.c: hash tables with an array part; LuaPlus-style node lookups added. */
#include "lua2.h"
#ifdef _MSC_VER
extern void *memcpy(void *d, const void *s, unsigned int n);
#pragma intrinsic(memcpy)
void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
#else
#define _ReadWriteBarrier() ((void)0)
#include <string.h>
#endif

extern void fn_8881FB60(lua_State *L, const char *fmt, ...); /* luaG_runerror */

extern const double g_ts4_script_constants[]; /* [15] = 1.0 */
extern char lbl_880E2C2C[];                   /* "table overflow" */
extern const lu_byte lbl_880C9758[]; /* log_8 */
extern Node *fn_88811D48(const Table *t, const TValue *key); /* luaH_mainposition */
extern const TValue *fn_88811930(Table *t, int key);       /* luaH_getnum */

/* luaO_log2 (lobject.c) */
LUA2_LOCAL int ts4_if_addr_lbl_880C9758_888182A8(unsigned int x)
{
    if (x >= 0x00010000) {
        if (x >= 0x01000000) return lbl_880C9758[((x >> 24) & 0xff) - 1] + 24;
        else return lbl_880C9758[((x >> 16) & 0xff) - 1] + 16;
    } else {
        if (x >= 0x00000100) return lbl_880C9758[((x >> 8) & 0xff) - 1] + 8;
        else if (x) return lbl_880C9758[(x & 0xff) - 1];
        return -1;
    }
}

#define MAXBITS 24
#define twoto(x) (1 << (x))
#define sizenode(t) (twoto((t)->lsizenode))
#define gnode(t, i) (&(t)->node[i])
#define gkey(n) (&(n)->i_key)
#define gval(n) (&(n)->i_val)
#define setnilvalue_raw(obj) \
    { \
        TValue *o_ = (obj); \
        o_->tt = LUA2_TNIL; \
        o_->value.p = 0; \
    }

/* luaH_free */
void lua2_luaH_free_888115F8(lua_State *L, Table *t)
{
    if (t->lsizenode) fn_889CE718(L, t->node, sizenode(t) * sizeof(Node), 0);
    fn_889CE718(L, t->array, t->sizearray * sizeof(TValue), 0);
    fn_889CE718(L, t, sizeof(Table), 0);
}

/* setnodevector */
void lua2_setnodevector_88811688(lua_State *L, Table *t, int lsize)
{
    int i;
    int size = twoto(lsize);
    if (lsize > MAXBITS) fn_8881FB60(L, lbl_880E2C2C);
    if (lsize == 0) {
        t->node = (Node *)((char *)G(L) + 0x60); /* dummynode */
    } else {
        t->node = (Node *)fn_889CE718(L, 0, 0, size * sizeof(Node));
        for (i = 0; i < size; i++) {
            t->node[i].next = 0;
            setnilvalue_raw(gkey(gnode(t, i)));
            setnilvalue_raw(gval(gnode(t, i)));
        }
    }
    t->lsizenode = (lu_byte)lsize;
    t->firstfree = gnode(t, size - 1);
}

/* setarrayvector */
void lua2_setarrayvector_88811768(lua_State *L, Table *t, int size)
{
    int i;
    t->array = (TValue *)fn_889CE718(L, t->array, t->sizearray * sizeof(TValue), size * sizeof(TValue));
    for (i = t->sizearray; i < size; i++) setnilvalue_raw(&t->array[i]);
    t->sizearray = size;
}

/* computesizes */
void lua2_computesizes_888117F0(int nums[], int ntotal, int *narray, int *nhash)
{
    int i;
    int a = nums[0];
    int na = a;
    int n = (na == 0) ? -1 : 0;
    for (i = 1; a < *narray && *narray >= twoto(i - 1); i++) {
        if (nums[i] > 0) {
            a += nums[i];
            if (a >= twoto(i - 1)) {
                n = i;
                na = a;
            }
        }
    }
    *nhash = ntotal - na;
    *narray = (n == -1) ? 0 : twoto(n);
}

/* luaO_rawequalObj, expanded. */
LUA2_FORCEINLINE int rawequal_inl(const TValue *t1, const TValue *t2)
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

/* luaH_getany */
const TValue *lua2_luaH_getany_88811E80(Table *t, const TValue *key)
{
    if (ttype(key) == LUA2_TNIL) return &lbl_880C9748;
    else {
        Node *n = fn_88811D48(t, key);
        do {
            if (rawequal_inl(gkey(n), key)) return gval(n);
            else n = n->next;
        } while (n);
        return &lbl_880C9748;
    }
}

/* Node holding an arbitrary key, or NULL. */
Node *lua2_luaH_getanynode_88811F40(Table *t, const TValue *key)
{
    if (ttype(key) == LUA2_TNIL) return 0;
    else {
        Node *n = fn_88811D48(t, key);
        do {
            if (rawequal_inl(gkey(n), key)) return n;
            else n = n->next;
        } while (n);
        return 0;
    }
}

extern const TValue *ts4_if_call_seq_u32_off0_88812188(Table *t, const TValue *key); /* luaH_get */
extern void ts4_call_seq_fn_88811B98_88812730(lua_State *L, Table *t);              /* rehash */
extern char lbl_880E2C3C[]; /* "table index is nil" */
extern char lbl_880E2C50[]; /* "table index is NaN" */

/* Remove node n from its chain (LuaPlus addition). The barriers keep the original store order. */
#define setnilvalue_vt(L, obj) \
    { \
        TValue *o1 = (obj); \
        LUA2_RELEASE((L), o1); \
        o1->value.p = 0; \
        o1->tt = LUA2_TNIL; \
    }
void lua2_removenode_88811FE8(lua_State *L, Table *t, Node *n)
{
    Node *mp = fn_88811D48(t, gkey(n));
    if (n != mp) {
        Node **pp = &mp->next;
        while (*pp != n) pp = &(*pp)->next;
        *pp = n->next;
        setnilvalue(L, gkey(n));
        _ReadWriteBarrier();
        n->next = 0;
        if (n > t->firstfree) t->firstfree = n;
    } else {
        Node *nx = n->next;
        if (nx) {
            setnilvalue_vt(L, gkey(n));
            _ReadWriteBarrier();
            *mp = *n->next;
            nx->next = 0;
            setnilvalue_raw(gval(nx));
            nx->i_key.value.p = 0;
            nx->i_key.tt = LUA2_TNIL;
            if (nx > t->firstfree) t->firstfree = nx;
        } else {
            setnilvalue_vt(L, gkey(n));
            if (n > t->firstfree) t->firstfree = n;
        }
    }
}

TValue *lua2_newkey_88812790(lua_State *L, Table *t, const TValue *key);

/* luaH_set */
LUA2_NOINLINE TValue *lua2_luaH_set_888122E8(lua_State *L, Table *t, const TValue *key)
{
    const TValue *p = ts4_if_call_seq_u32_off0_88812188(t, key);
    t->flags = 0;
    if (p != &lbl_880C9748) return (TValue *)p;
    else {
        if (ttype(key) == LUA2_TNIL) fn_8881FB60(L, lbl_880E2C3C);
        else if (ttype(key) == LUA2_TNUMBER && nvalue(key) != nvalue(key)) fn_8881FB60(L, lbl_880E2C50);
        return lua2_newkey_88812790(L, t, key);
    }
}

LUA2_NOINLINE TValue *lua2_luaH_setnum_88812968(lua_State *L, Table *t, int key);

/* resize */
void lua2_resize_88812378(lua_State *L, Table *t, int nasize, int nhsize)
{
    int i;
    int oldasize = t->sizearray;
    int oldhsize = t->lsizenode;
    Node *nold;
    Node temp[1];
    if (oldhsize) nold = t->node;
    else {
        temp[0] = *t->node;
        nold = temp;
        setnilvalue(L, gkey((Node *)((char *)G(L) + 0x60)));
        setnilvalue(L, gval((Node *)((char *)G(L) + 0x60)));
    }
    if (nasize > oldasize) lua2_setarrayvector_88811768(L, t, nasize);
    lua2_setnodevector_88811688(L, t, nhsize);
    if (nasize < oldasize) {
        t->sizearray = nasize;
        for (i = nasize; i < oldasize; i++) {
            if (ttype(&t->array[i]) != LUA2_TNIL) {
                setobj(L, lua2_luaH_setnum_88812968(L, t, i + 1), &t->array[i]);
                setnilvalue(L, &t->array[i]);
            }
        }
        t->array = (TValue *)fn_889CE718(L, t->array, oldasize * sizeof(TValue), nasize * sizeof(TValue));
    }
    for (i = twoto(oldhsize) - 1; i >= 0; i--) {
        Node *old = nold + i;
        if (ttype(gval(old)) != LUA2_TNIL) {
            setobj(L, lua2_luaH_set_888122E8(L, t, gkey(old)), gval(old));
        }
    }
    if (oldhsize) {
        for (i = twoto(oldhsize) - 1; i >= 0; i--) {
            Node *old = nold + i;
            if (ttype(gval(old)) != LUA2_TNIL) {
                setnilvalue(L, gkey(old));
                setnilvalue(L, gval(old));
            }
        }
        fn_889CE718(L, nold, twoto(oldhsize) * sizeof(Node), 0);
    }
}

/* newkey */
TValue *lua2_newkey_88812790(lua_State *L, Table *t, const TValue *key)
{
    Node *mp = fn_88811D48(t, key);
    if (ttype(gval(mp)) != LUA2_TNIL) {
        Node *othern = fn_88811D48(t, gkey(mp));
        Node *n = t->firstfree;
        if (othern != mp) {
            Node **pp = &othern->next;
            while (*pp != mp) pp = &(*pp)->next;
            *pp = n;
            *n = *mp;
            mp->next = 0;
            setnilvalue_raw(gval(mp));
            setnilvalue_raw(gkey(mp));
        } else {
            n->next = mp->next;
            mp->next = n;
            mp = n;
        }
    }
    setobj(L, gkey(mp), key);
    for (;;) {
        if (ttype(gkey(t->firstfree)) == LUA2_TNIL) return gval(mp);
        else if (t->firstfree == t->node) break;
        else (t->firstfree)--;
    }
    {
        TValue *v = gval(mp);
        LUA2_RELEASE(L, v);
        v->tt = LUA2_TBOOLEAN;
        v->value.b = 0;
    }
    ts4_call_seq_fn_88811B98_88812730(L, t);
    {
        TValue *v = (TValue *)ts4_if_call_seq_u32_off0_88812188(t, key);
        setnilvalue_raw(v);
        return v;
    }
}

/* luaH_setnum */
LUA2_NOINLINE TValue *lua2_luaH_setnum_88812968(lua_State *L, Table *t, int key)
{
    const TValue *p = fn_88811930(t, key);
    if (p != &lbl_880C9748) return (TValue *)p;
    else {
        TValue k;
        k.value.n = (double)key;
        k.tt = LUA2_TNUMBER;
        return lua2_newkey_88812790(L, t, &k);
    }
}
