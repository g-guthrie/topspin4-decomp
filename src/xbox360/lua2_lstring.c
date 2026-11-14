/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex (doubly linked string chains, wide strings). lstring.c. */
#include "lua2.h"
#ifdef _MSC_VER
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif

/* luaS_resize */
void lua2_luaS_resize_88812CF8(lua_State *L, int newsize)
{
    GCheader **newhash = (GCheader **)fn_889CE718(L, 0, 0, newsize * sizeof(GCheader *));
    stringtable *tb = &G(L)->strt;
    int i;
    for (i = 0; i < newsize; i++) newhash[i] = 0;
    for (i = 0; i < tb->size; i++) {
        GCheader *p = tb->hash[i];
        while (p) {
            GCheader *next = p->next;
            u32 h = ((TString *)p)->hash;
            int h1 = h & (newsize - 1);
            GCheader *x = newhash[h1];
            p->next = x;
            if (x) x->prev = p;
            p->prev = 0;
            newhash[h1] = p;
            p = next;
        }
    }
    fn_889CE718(L, tb->hash, tb->size * sizeof(TString *), 0);
    tb->size = newsize;
    tb->hash = newhash;
}

#define LUA2_CHAIN_STRING(L, ts, h) \
    { \
        stringtable *tb = &G(L)->strt; \
        h = h & (tb->size - 1); \
        ts->h.next = tb->hash[h]; \
        ts->h.refs = 0; \
        if (ts->h.next) ts->h.next->prev = &ts->h; \
        ts->h.prev = 0; \
        tb->hash[h] = &ts->h; \
        tb->nuse++; \
        if (tb->nuse > tb->size && tb->size <= 0x7FFFFFFD / 2) \
            lua2_luaS_resize_88812CF8(L, tb->size * 2); \
    }

/* newlwstr: allocate and chain a wide string. */
TString *lua2_newlwstr_88812DE8(lua_State *L, const unsigned short *str, u32 l, u32 h)
{
    TString *ts = (TString *)fn_889CE718(L, 0, 0, sizeof(TString) + (l + 1) * 2);
    ts->len = l;
    ts->hash = h;
    ts->h.marked = 0;
    ts->h.tt = LUA2_TWSTRING;
    ts->reserved = 0;
    memcpy(ts + 1, str, l * 2);
    ((char *)(ts + 1))[l * 2 + 1] = '\0';
    ((char *)(ts + 1))[l * 2] = '\0';
    LUA2_CHAIN_STRING(L, ts, h);
    return ts;
}

/* newlstr */
TString *lua2_newlstr_88812EE0(lua_State *L, const char *str, u32 l, u32 h)
{
    TString *ts = (TString *)fn_889CE718(L, 0, 0, sizeof(TString) + l + 1);
    ts->len = l;
    ts->hash = h;
    ts->h.marked = 0;
    ts->h.tt = LUA2_TSTRING;
    ts->reserved = 0;
    memcpy(ts + 1, str, l);
    ((char *)(ts + 1))[l] = '\0';
    LUA2_CHAIN_STRING(L, ts, h);
    return ts;
}

/* luaS_newlwstr */
TString *lua2_luaS_newlwstr_88812FC8(lua_State *L, const unsigned short *str, u32 l)
{
    GCheader *o;
    u32 h = (u32)l;
    u32 step = (l >> 5) + 1;
    u32 l1;
    for (l1 = l; l1 >= step; l1 -= step)
        h = h ^ ((h << 5) + (h >> 2) + str[l1 - 1]);
    for (o = G(L)->strt.hash[h & (G(L)->strt.size - 1)]; o != 0; o = o->next) {
        TString *ts = (TString *)o;
        if (o->tt == LUA2_TWSTRING && ts->len == l && memcmp(str, getstr(ts), l * 2) == 0)
            return ts;
    }
    return lua2_newlwstr_88812DE8(L, str, l, h);
}

/* luaS_newlstr */
TString *lua2_luaS_newlstr_888131A0(lua_State *L, const char *str, u32 l)
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
