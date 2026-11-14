/* Derived from Lua 5.0.2 lobject.c (MIT); see THIRD_PARTY_NOTICES.md */
/* lobject.c plus the LuaPlus release helpers that drop the references an object holds before it is freed. */
#include "lua3.h"
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
extern char *strcpy(char *d, const char *s);
extern char *strcat(char *d, const char *s);
extern void *memcpy(void *d, const void *s, unsigned int n);
#pragma intrinsic(strlen, strcpy, strcat, memcpy)
#else
#include <string.h>
#endif

#define LUA_IDSIZE 60

extern char *ts4_copy_bytes(char *d, const char *s, unsigned int n); /* strncpy */
extern unsigned int fn_88567988(const char *s, const char *set);     /* strcspn */
extern char *fn_88564EF0(char *d, const char *s, unsigned int n);    /* strncat */
extern double ts4_tailcall_fn_88567A38_88567B98(const char *s, char **endptr); /* strtod */
extern const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void);          /* __pctype_func */
extern TString *lua2_luaS_newlstr_888131A0(lua_State *L, const char *str, u32 l);
extern char lbl_880E27EC[]; /* "..." */
extern char lbl_880C13B8[]; /* "\n" */
extern char lbl_880E29CC[]; /* "[string \"" */
extern char lbl_880D35C4[]; /* "\"]" */

#define RELEASE_GC(L, gc) \
    if (--(gc)->refs == 0) fn_88818C88((L), (gc))

/* Unlink a string from its string-table hash chain (doubly linked in this build). */
void lua3_luaS_unlink_88817998(lua_State *L, TString *ts)
{
    if (ts->h.prev)
        ts->h.prev->next = ts->h.next;
    else
        G(L)->strt.hash[ts->hash & (G(L)->strt.size - 1)] = ts->h.next;
    if (ts->h.next) ts->h.next->prev = ts->h.prev;
    G(L)->strt.nuse--;
}

/* Release the globals table and every stack slot of a dying thread (the live part, then up to the highest ci->top). */
void lua3_release_thread_88817A28(lua_State *L, lua_State *L1)
{
    StkId o, lim;
    CallInfo *ci;
    TValue *gt = &L1->_gt;
    LUA2_RELEASE(L, gt);
    lim = L1->top;
    for (ci = L1->base_ci; ci <= L1->ci; ci++)
        if (lim < ci->top) lim = ci->top;
    for (o = L1->stack; o < L1->top; o++) LUA2_RELEASE(L1, o);
    for (; o <= lim; o++) setnilvalue(L, o);
}

/* NEAR MISS (not built): release_proto 0x88817B78. The target re-tests the constant's tag after a
   no-op `clrrwi r10,r10,0` (see codegen-idioms.md PARTIAL: clrrwi); MSVC folds this form instead. */
#if 0
/* Release the constants, upvalue names, nested prototypes and local names of a prototype. */
void lua3_release_proto_88817B78(lua_State *L, Proto *f)
{
    int i;
    for (i = 0; i < f->sizek; i++) {
        TValue *o = &f->k[i];
        if (ttype(o) == LUA2_TSTRING) LUA2_RELEASE(L, o);
    }
    for (i = 0; i < f->sizeupvalues; i++) {
        GCheader *gc = &f->upvalues[i]->h;
        RELEASE_GC(L, gc);
    }
    for (i = 0; i < f->sizep; i++) {
        GCheader *gc = &f->p[i]->h;
        RELEASE_GC(L, gc);
    }
    for (i = 0; i < f->sizelocvars; i++) {
        GCheader *gc = &f->locvars[i].varname->h;
        RELEASE_GC(L, gc);
    }
}
#endif

/* Release the array part, every used node (key and value) and the metatable of a table. */
void lua3_release_table_88817D00(lua_State *L, Table *h)
{
    int i = h->sizearray;
    while (i--) {
        TValue *o = &h->array[i];
        LUA2_RELEASE(L, o);
    }
    {
    u32 j = 1u << h->lsizenode;
    while ((int)j--) {
        Node *n = &h->node[j];
        TValue *v = &n->i_val;
        if (ttype(v) != LUA2_TNIL) {
            TValue *k = &n->i_key;
            LUA2_RELEASE(L, k);
            LUA2_RELEASE(L, v);
        }
    }
    }
    {
        GCheader *mt = &h->metatable->h;
        RELEASE_GC(L, mt);
    }
}

/* Release the upvalues of a C closure, or the globals, prototype and upvalues of a Lua closure. */
void lua3_release_closure_88817E50(lua_State *L, Closure *cl)
{
    int i;
    if (cl->c.isC) {
        for (i = 0; i < cl->c.nupvalues; i++) {
            TValue *o = &cl->c.upvalue[i];
            LUA2_RELEASE(L, o);
        }
    } else {
        GCheader *gc = cl->l.g.value.gc;
        RELEASE_GC(L, gc);
        gc = &cl->l.p->h;
        RELEASE_GC(L, gc);
        for (i = 0; i < cl->l.nupvalues; i++) {
            gc = &cl->l.upvals[i]->h;
            RELEASE_GC(L, gc);
        }
    }
}

/* luaO_chunkid, with bufflen fixed at LUA_IDSIZE */
void lua3_luaO_chunkid_88817F88(char *out, const char *source)
{
    int bufflen = LUA_IDSIZE;
    if (*source == '=') {
        ts4_copy_bytes(out, source + 1, bufflen); /* remove first char */
        out[bufflen - 1] = '\0'; /* ensures null termination */
    } else { /* out = "source", or "...source" */
        if (*source == '@') {
            int l;
            source++; /* skip the `@' */
            bufflen -= sizeof(" `...' ");
            l = strlen(source);
            strcpy(out, "");
            if (l > bufflen) {
                source += (l - bufflen); /* get last part of file name */
                strcat(out, lbl_880E27EC);
            }
            strcat(out, source);
        } else { /* out = [string "string"] */
            int len = fn_88567988(source, lbl_880C13B8); /* stop at first newline */
            bufflen -= sizeof(" [string \"...\"] ");
            if (len > bufflen) len = bufflen;
            memcpy(out, lbl_880E29CC, sizeof("[string \"")); /* the literal lives at lbl_880E29CC */
            if (source[len] != '\0') { /* must truncate? */
                fn_88564EF0(out, source, len);
                strcat(out, lbl_880E27EC);
            } else
                strcat(out, source);
            strcat(out, lbl_880D35C4);
        }
    }
}

#define lisspace(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[(c)] & 8)

/* luaO_str2d */
int lua3_luaO_str2d_88818190(const char *s, double *result)
{
    char *endptr;
    double res = ts4_tailcall_fn_88567A38_88567B98(s, &endptr);
    if (endptr == s) return 0; /* no conversion */
    while (lisspace((unsigned char)(*endptr))) endptr++;
    if (*endptr != '\0') return 0; /* invalid trailing characters? */
    *result = res;
    return 1;
}

/* NEAR MISS (not built): wcstod 0x88818390. The target hoists the pool constants out of the loops
   (they were literals merged into g_ts4_script_constants by LTCG) but still re-reads *s after each
   __pctype_func call; extern-array loads are reloaded per iteration, and __declspec(noalias) on
   __pctype_func fixes the hoisting but lets MSVC reuse *s. */
#if 0
extern const double g_ts4_script_constants[]; /* shared double pool, indexed in 8-byte units */
extern double fn_88563A38(double x, double y); /* pow */
#define K_ZERO g_ts4_script_constants[0x58 / 8]
#define K_ONE g_ts4_script_constants[0x78 / 8]
#define K_SIXTEEN g_ts4_script_constants[0x18 / 8]
#define K_SIXTEENTH g_ts4_script_constants[0x168 / 8]
#define K_TWO g_ts4_script_constants[0x170 / 8]
#define K_TEN g_ts4_script_constants[0x88 / 8]
#define K_TENTH g_ts4_script_constants[0x178 / 8]
#define wisdigit(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[(c)] & 4)
#define wisxdigit(c) (ts4_get_u32_lbl_88C311F4_88567FC8()[(c)] & 0x80)

LUA2_FORCEINLINE int hexval(int c)
{
    if (wisdigit(c)) return c - '0';
    if (c >= 'a' && c <= 'z') c -= 0x20;
    return c - ('A' - 10);
}

/* wcstod for the unicode lexer: decimal with an optional exponent, or C99 hexadecimal ("0x1.8p3"). */
double lua3_wcstod_88818390(const u16 *s, u16 **endptr)
{
    double ipart = K_ZERO, fpart, scale = K_ONE, base, r;
    int neg = 0, expneg = 0;
    u32 ex = 0;
    fpart = ipart;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        s += 2;
        while (wisxdigit(*s)) {
            ipart = ipart * K_SIXTEEN + hexval(*s);
            s++;
        }
        if (*s == '.') {
            s++;
            while (wisxdigit(*s)) {
                scale *= K_SIXTEENTH;
                fpart += hexval(*s) * scale;
                s++;
            }
        }
        if (*s == 'p' || *s == 'P') {
            u16 c = *++s;
            if (c == '+' || c == '-') {
                expneg = (c == '-');
                s++;
            }
            while (wisdigit(*s)) {
                ex = ex * 10 + *s - '0';
                s++;
            }
        }
        base = K_TWO;
    } else {
        u16 c = *s;
        base = K_TEN;
        neg = (c == '-');
        if (c == '+' || c == '-') s++;
        while (wisdigit(*s)) {
            ipart = ipart * base + (*s - '0');
            s++;
        }
        if (*s == '.') {
            s++;
            while (wisdigit(*s)) {
                scale *= K_TENTH;
                fpart += (*s - '0') * scale;
                s++;
            }
        }
        if (*s == 'e' || *s == 'E') {
            c = *++s;
            expneg = (c == '-');
            if (c == '+' || c == '-') s++;
            while (wisdigit(*s)) {
                ex = ex * 10 + *s - '0';
                s++;
            }
        }
    }
    r = fpart + ipart;
    if (ex != 0) {
        if (expneg) r /= fn_88563A38(base, (double)ex);
        else r = fn_88563A38(base, (double)ex) * r;
    }
    if (neg) r = -r;
    if (endptr) *endptr = (u16 *)s;
    return r;
}
#endif
extern double fn_88818390(const u16 *s, u16 **endptr); /* wcstod */

/* luaO_str2d for wide strings */
int lua3_luaO_wstr2d_88818768(const u16 *s, double *result)
{
    u16 *endptr;
    const u16 *e;
    double res = fn_88818390(s, &endptr);
    e = endptr;
    if (e == s) return 0; /* no conversion */
    {
        u16 c = *e;
        while (c < 0x100) { /* skip trailing ASCII-range spaces */
            c = *e;
            if (!lisspace((unsigned char)c)) break;
            c = *++e;
        }
        if (c != 0) return 0; /* invalid trailing characters? */
    }
    *result = res;
    return 1;
}

/* pushstr */
LUA2_NOINLINE void lua3_pushstr_88818800(lua_State *L, const char *str)
{
    setgcvalue(L, L->top, lua2_luaS_newlstr_888131A0(L, str, strlen(str)), LUA2_TSTRING);
    luaD_checkstack(L, 1);
    L->top++;
}

#ifdef _MSC_VER
/* Xbox 360 va_arg: every argument takes an 8-byte aligned slot; an int sits in its low word. */
#define va_arg_int(ap) (*(int *)(((ap) = (va_list)((((u32)(ap) + 7) & ~7u) + 8)) - 4))
#define va_arg_ptr(ap) (*(char **)(((ap) = (va_list)((((u32)(ap) + 7) & ~7u) + 8)) - 4))
#define va_arg_dbl(ap) (*(double *)(((ap) = (va_list)((((u32)(ap) + 7) & ~7u) + 8)) - 8))
#else
#define va_arg_int(ap) va_arg(ap, int)
#define va_arg_ptr(ap) va_arg(ap, char *)
#define va_arg_dbl(ap) va_arg(ap, double)
#endif

extern char *fn_88563500(const char *s, int c); /* strchr */
extern void fn_8880FA80(lua_State *L, int total, int last); /* luaV_concat */
extern char lbl_880C1320[]; /* "" */
extern char lbl_880E29C8[]; /* "%" */

#define setnvalue(L, obj, x) \
    { \
        TValue *o1 = (obj); \
        LUA2_RELEASE((L), o1); \
        o1->tt = LUA2_TNUMBER; \
        o1->value.n = (x); \
    }

/* luaO_pushvfstring; the pieces are popped with reference-counted nil stores. */
const char *lua3_luaO_pushvfstring_888188F8(lua_State *L, const char *fmt, va_list argp)
{
    int n = 1;
    lua3_pushstr_88818800(L, lbl_880C1320);
    for (;;) {
        const char *e = fn_88563500(fmt, '%');
        if (e == 0) break;
        setgcvalue(L, L->top, lua2_luaS_newlstr_888131A0(L, fmt, e - fmt), LUA2_TSTRING);
        luaD_checkstack(L, 1);
        L->top++;
        switch (*(e + 1)) {
        case 's':
            lua3_pushstr_88818800(L, va_arg_ptr(argp));
            break;
        case 'c': {
            char buff[2];
            buff[0] = (char)va_arg_int(argp);
            buff[1] = '\0';
            lua3_pushstr_88818800(L, buff);
            break;
        }
        case 'd':
            setnvalue(L, L->top, (double)va_arg_int(argp));
            luaD_checkstack(L, 1);
            L->top++;
            break;
        case 'f':
            setnvalue(L, L->top, va_arg_dbl(argp));
            luaD_checkstack(L, 1);
            L->top++;
            break;
        case '%':
            lua3_pushstr_88818800(L, lbl_880E29C8);
            break;
        default:
            break;
        }
        n += 2;
        fmt = e + 2;
    }
    lua3_pushstr_88818800(L, fmt);
    fn_8880FA80(L, n + 1, (int)(L->top - L->base) - 1);
    {
        StkId lim = L->top;
        StkId o;
        for (o = lim - n; o < lim;) setnilvalue(L, o++);
        L->top -= n;
    }
    return getstr(tsvalue(L->top - 1));
}
