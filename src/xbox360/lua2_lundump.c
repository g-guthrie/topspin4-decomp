/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* lundump.c: load pre-compiled chunks; this build discards line info and counts references. */
#include "lua2.h"

typedef struct ZIO ZIO;
extern int ex3_luaZ_fill_8880C040(ZIO *z);
extern u32 ex3_luaZ_read_8880C0C8(ZIO *z, void *b, u32 n);
extern char *fn_8880BFB0(lua_State *L, Mbuffer *buff, u32 n); /* luaZ_openspace */
LUA2_DEFINE_RUNERROR
extern TString *lua2_luaS_newlstr_888131A0(lua_State *L, const char *str, u32 l);
extern TString *lua2_luaS_newlwstr_88812FC8(lua_State *L, const unsigned short *str, u32 l);
extern Proto *ts4_if_get_u32_off14_8881C630(lua_State *L); /* luaF_newproto */

extern char lbl_880E2CEC[]; /* "unexpected end of file in %s" */
extern char lbl_880E2D0C[]; /* "bad integer in %s" */
extern char lbl_880E2D20[]; /* "bad nupvalues in %s: read %d; expected %d" */
extern char lbl_880E2D4C[]; /* "bad constant type (%d) in %s" */
extern char lbl_880E2D6C[]; /* "bad signature in %s" */
extern char lbl_880E2D80[]; /* "virtual machine mismatch in %s: size of %s is %d but read %d" */
extern char lbl_880E2DC0[]; /* "%s too new: read version %d.%d; expected at most %d.%d" */
extern char lbl_880E2DF8[]; /* "%s too old: ..." */
extern char lbl_880E252C[]; /* LUA_SIGNATURE "\033Lua" */
extern char lbl_880E2E30[]; /* "int" */
extern char lbl_880E2E34[]; /* "size_t" */
extern char lbl_880E2E3C[]; /* "Instruction" */
extern char lbl_880E2E48[]; /* "OP" */
extern char lbl_880E2E4C[]; /* "A" */
extern char lbl_880E2E50[]; /* "B" */
extern char lbl_880E25A8[]; /* "C" */
extern char lbl_880E2CDC[]; /* "number" */
extern char lbl_880E2E54[]; /* "unknown number format in %s" */
extern int lbl_88C6A108;    /* int 1: first byte gives the endianness */

struct ZIO {
    u32 n;
    const char *p;
};

typedef struct LoadState {
    lua_State *L;
    ZIO *Z;
    Mbuffer *b;
    int swap;
    const char *name;
} LoadState;

#define EOZ (-1)
#define zgetc(z) (((z)->n--) > 0 ? (int)((unsigned char)(*(z)->p++)) : ex3_luaZ_fill_8880C040(z))

LUA2_FORCEINLINE void *luaM_newvector_inl(lua_State *L, u32 n)
{
    return fn_889CE718(L, 0, 0, n);
}

/* luaM_realloc with a zero new size, as LTCG expanded it. */
LUA2_FORCEINLINE void luaM_free_inl(lua_State *L, void *block, u32 osize)
{
    global_State *g = G(L);
    g->frealloc(g->ud, block, osize, 0, 0, L->inrealloc);
    g->nblocks += 0 - osize;
}

/* unexpectedEOZ */
LUA2_NORETURN void lua2_unexpectedEOZ_88810048(LoadState *S)
{
    lua3_luaG_runerror_8881FB60(S->L, lbl_880E2CEC, S->name);
}

/* ezgetc */
LUA2_FORCEINLINE int ezgetc_inl(LoadState *S)
{
    int c = zgetc(S->Z);
    if (c == EOZ) lua2_unexpectedEOZ_88810048(S);
    return c;
}

LUA2_NOINLINE int lua2_ezgetc_888100B8(LoadState *S)
{
    return ezgetc_inl(S);
}

/* ezread */
LUA2_FORCEINLINE void ezread_inl(LoadState *S, void *b, int n)
{
    int r = ex3_luaZ_read_8880C0C8(S->Z, b, n);
    if (r != 0) lua2_unexpectedEOZ_88810048(S);
}

LUA2_NOINLINE void lua2_ezread_88810068(LoadState *S, void *b, int n)
{
    ezread_inl(S, b, n);
}

/* LoadBlock: read size bytes, reversed when the chunk has the other byte order. */
LUA2_FORCEINLINE void LoadBlock_inl(LoadState *S, void *b, u32 size)
{
    if (S->swap) {
        char *p = (char *)b + size - 1;
        int n = size;
        while (n--) *p-- = (char)lua2_ezgetc_888100B8(S);
    } else
        ezread_inl(S, b, size);
}

LUA2_NOINLINE void lua2_LoadBlock_888102D8(LoadState *S, void *b, u32 size)
{
    LoadBlock_inl(S, b, size);
}

/* LoadVector for 4-byte elements. */
LUA2_NOINLINE void lua2_LoadVector_88810250(LoadState *S, void *b, int m)
{
    if (S->swap) {
        char *q = (char *)b;
        while (m--) {
            char *p = q + 4 - 1;
            int n = 4;
            while (n--) *p-- = (char)lua2_ezgetc_888100B8(S);
            q += 4;
        }
    } else
        ezread_inl(S, b, m * 4);
}

/* LoadInt */

/* LoadInt with the block read left out of line. */
LUA2_FORCEINLINE int LoadInt_c(LoadState *S)
{
    int x;
    lua2_LoadBlock_888102D8(S, &x, sizeof(x));
    if (x < 0) lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D0C, S->name);
    return x;
}

LUA2_NOINLINE int lua2_LoadInt_888103B0(LoadState *S)
{
    return LoadInt_c(S);
}

/* LoadSize */
LUA2_FORCEINLINE u32 LoadSize_c(LoadState *S)
{
    u32 x;
    lua2_LoadBlock_888102D8(S, &x, sizeof(x));
    return x;
}

/* LoadNumber */
LUA2_FORCEINLINE double LoadNumber_c(LoadState *S)
{
    double x;
    lua2_LoadBlock_888102D8(S, &x, sizeof(x));
    return x;
}

LUA2_NOINLINE double lua2_LoadNumber_88810350(LoadState *S)
{
    return LoadNumber_c(S);
}

#define LoadByte(S) ((lu_byte)lua2_ezgetc_888100B8(S))

/* LoadWString: wide strings are stored as 16-bit units. */
LUA2_NOINLINE TString *lua2_LoadWString_888107F0(LoadState *S)
{
    u32 size = LoadSize_c(S);
    if (size == 0)
        return 0;
    else {
        unsigned short *s = (unsigned short *)fn_8880BFB0(S->L, S->b, size * 2);
        ezread_inl(S, s, size * 2);
        if (S->swap) {
            unsigned short *p = s;
            unsigned short *e = s + size;
            while (p != e) {
                *p = (unsigned short)((*p << 8) | (*p >> 8));
                p++;
            }
        }
        return lua2_luaS_newlwstr_88812FC8(S->L, s, size - 1);
    }
}

/* LoadString */
LUA2_NOINLINE TString *lua2_LoadString_888108C0(LoadState *S)
{
    u32 size = LoadSize_c(S);
    if (size == 0)
        return 0;
    else {
        char *s = fn_8880BFB0(S->L, S->b, size);
        ezread_inl(S, s, size);
        return lua2_luaS_newlstr_888131A0(S->L, s, size - 1);
    }
}

/* LoadCode */
LUA2_NOINLINE void lua2_LoadCode_88810780(LoadState *S, Proto *f)
{
    int size = LoadInt_c(S);
    f->code = (Instruction *)luaM_newvector_inl(S->L, size * sizeof(Instruction));
    f->sizecode = size;
    lua2_LoadVector_88810250(S, f->code, size);
}

/* LoadLines: line info is read and thrown away. */
LUA2_NOINLINE void lua2_LoadLines_888106C8(LoadState *S, Proto *f)
{
    int size = LoadInt_c(S);
    f->lineinfo = (int *)luaM_newvector_inl(S->L, size * sizeof(int));
    f->sizelineinfo = size;
    lua2_LoadVector_88810250(S, f->lineinfo, size);
    luaM_free_inl(S->L, f->lineinfo, f->sizelineinfo * sizeof(int));
    f->lineinfo = 0;
}


/* LoadUpvalues */
LUA2_NOINLINE void lua2_LoadUpvalues_88810C80(LoadState *S, Proto *f)
{
    int i, n;
    n = LoadInt_c(S);
    if (n != 0 && n != f->nups)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D20, S->name, n, f->nups);
    f->upvalues = (TString **)luaM_newvector_inl(S->L, n * sizeof(TString *));
    f->sizeupvalues = n;
    for (i = 0; i < n; i++) {
        f->upvalues[i] = lua2_LoadString_888108C0(S);
        f->upvalues[i]->h.refs++;
    }
}

Proto *lua2_LoadFunction_88810F00(LoadState *S, TString *p);
extern void fn_88810D48(LoadState *S, Proto *f); /* LoadLocals (not matched yet) */
extern void fn_88810948(LoadState *S, Proto *f); /* LoadConstants (not matched yet) */



/* LoadFunction */
LUA2_NOINLINE Proto *lua2_LoadFunction_88810F00(LoadState *S, TString *p)
{
    Proto *f = ts4_if_get_u32_off14_8881C630(S->L);
    f->source = lua2_LoadString_888108C0(S);
    if (f->source == 0) f->source = p;
    f->source->h.refs++;
    f->lineDefined = LoadInt_c(S);
    f->nups = LoadByte(S);
    f->numparams = LoadByte(S);
    f->is_vararg = LoadByte(S);
    f->maxstacksize = LoadByte(S);
    lua2_LoadLines_888106C8(S, f);
    fn_88810D48(S, f);
    lua2_LoadUpvalues_88810C80(S, f);
    fn_88810948(S, f);
    lua2_LoadCode_88810780(S, f);
    {
        TString *src = f->source;
        if (--src->h.refs == 0) fn_88818C88(S->L, &src->h);
    }
    return f;
}

/* LoadSignature */
LUA2_NOINLINE void lua2_LoadSignature_88810188(LoadState *S)
{
    const char *s = lbl_880E252C;
    do {
        if (ezgetc_inl(S) != *s) break;
    } while (*++s != 0);
    if (*s != 0) lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D6C, S->name);
}

/* TestSize */
LUA2_FORCEINLINE void TestSize_inl(LoadState *S, int s, const char *what)
{
    int r = LoadByte(S);
    if (r != s) lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D80, S->name, what, s, r);
}

LUA2_NOINLINE void lua2_TestSize_88810138(LoadState *S, int s, const char *what)
{
    TestSize_inl(S, s, what);
}

#define TESTSIZE(s, w) TestSize_inl(S, s, w)
#define V(v) v / 16, v % 16

LUA2_FORCEINLINE int luaU_endianness_inl(void)
{
    return *(signed char *)&lbl_88C6A108;
}

/* LoadHeader */
LUA2_NOINLINE void lua2_LoadHeader_88810408(LoadState *S)
{
    int version;
    double x;
    lua2_LoadSignature_88810188(S);
    version = LoadByte(S);
    if (version > 0x50)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2DC0, S->name, V(version), V(0x50));
    if (version < 0x50)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2DF8, S->name, V(version), V(0x50));
    S->swap = (luaU_endianness_inl() != LoadByte(S));
    TESTSIZE(4, lbl_880E2E30);
    TESTSIZE(4, lbl_880E2E34);
    TESTSIZE(4, lbl_880E2E3C);
    TESTSIZE(6, lbl_880E2E48);
    TESTSIZE(8, lbl_880E2E4C);
    TESTSIZE(9, lbl_880E2E50);
    TESTSIZE(9, lbl_880E25A8);
    TESTSIZE(8, lbl_880E2CDC);
    x = LoadNumber_c(S);
    if ((long)x != 31415926L)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2E54, S->name);
}
