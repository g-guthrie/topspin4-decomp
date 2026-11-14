#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x88810048-0x88810F00, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d4b_lua_error.h"

typedef Ts4LuaState lua_State;

typedef struct Ts4ZIO {
    unsigned int n;
    const unsigned char *p;
} Ts4ZIO;

/* Loader state for precompiled chunks. */
typedef struct Ts4LoadState {
    lua_State *L;
    Ts4ZIO *Z;
    void *b;
    int swap;
    const char *name;
} Ts4LoadState;

extern int ex3_luaZ_fill_8880C040(Ts4ZIO *z);
extern int ex3_luaZ_read_8880C0C8(Ts4ZIO *z, void *b, unsigned int n);
extern void *fn_889CE718(lua_State *L, void *block, unsigned int osize, unsigned int nsize);
extern void *fn_8880BFB0(lua_State *L, void *buff, unsigned int n);
extern void *fn_888131A0(lua_State *L, const char *s, unsigned int len);
extern void *fn_88812FC8(lua_State *L, const void *s, unsigned int len);
extern const char lbl_880E2CEC[];
extern const char lbl_880E252C[];
extern const char lbl_880E2D6C[];
extern const char lbl_880E2D80[];
extern const char lbl_880E2D0C[];

#ifdef _MSC_VER
#define TS4_NOINLINE __declspec(noinline)
#else
#define TS4_NOINLINE
#endif

#define UNEXPECTED_EOZ(S) lua3_luaG_runerror_8881FB60((S)->L, lbl_880E2CEC, (S)->name)

/* The chunk ended early. */
static TS4_NOINLINE void lua2_unexpectedEOZ_88810048(Ts4LoadState *S)
{
    UNEXPECTED_EOZ(S);
}

/* Read n raw bytes from the stream. */
static TS4_NOINLINE void lua2_ezread_88810068(Ts4LoadState *S, void *b, unsigned int n)
{
    if (ex3_luaZ_read_8880C0C8(S->Z, b, n) != 0)
        UNEXPECTED_EOZ(S);
}

/* Read one byte (zgetc inlined). */
static TS4_NOINLINE int lua2_ezgetc_888100B8(Ts4LoadState *S)
{
    int c = (S->Z->n-- != 0) ? (int)(*S->Z->p++) : ex3_luaZ_fill_8880C040(S->Z);
    if (c == -1) UNEXPECTED_EOZ(S);
    return c;
}

/* Check the chunk signature bytes. */
static void lua2_LoadSignature_88810188(Ts4LoadState *S)
{
    const char *s = lbl_880E252C;
    do {
        int c = (S->Z->n-- != 0) ? (int)(*S->Z->p++) : ex3_luaZ_fill_8880C040(S->Z);
        if (c == -1) UNEXPECTED_EOZ(S);
        if (c != *s) break;
        ++s;
    } while (*s != 0);
    if (*s != 0)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D6C, S->name);
}

/* Load n 32-bit words, byte-swapping when the chunk has foreign endianness. */
static TS4_NOINLINE void lua2_LoadVector_88810250(Ts4LoadState *S, void *b, int n)
{
    if (S->swap) {
        if (n != 0) {
            char *q = (char *)b + 3;
            do {
                int i;
                char *p;
                n--;
                p = q;
                for (i = 0; i < 4; i++) *p-- = (char)lua2_ezgetc_888100B8(S);
                q += 4;
            } while (n != 0);
        }
    } else {
        if (ex3_luaZ_read_8880C0C8(S->Z, b, (unsigned int)n * 4) != 0)
            UNEXPECTED_EOZ(S);
    }
}

/* Load a block of size bytes, reversing byte order when the chunk is foreign-endian. */
static TS4_NOINLINE void lua2_LoadBlock_888102D8(Ts4LoadState *S, void *b, int size)
{
    if (S->swap) {
        char *q = (char *)b + size - 1;
        if (size != 0) {
            int n = (int)(q - (char *)b) + 1;
            char *p = q + 1;
            do { *--p = (char)lua2_ezgetc_888100B8(S); n--; } while (n != 0);
        }
    } else {
        if (ex3_luaZ_read_8880C0C8(S->Z, b, (unsigned int)size) != 0)
            UNEXPECTED_EOZ(S);
    }
}

/* Load a double. */
static TS4_NOINLINE double lua2_LoadNumber_88810350(Ts4LoadState *S)
{
    double x;
    lua2_LoadBlock_888102D8(S, &x, 8);
    return x;
}

/* Load a non-negative size. */
static TS4_NOINLINE int lua2_LoadInt_888103B0(Ts4LoadState *S)
{
    int x;
    lua2_LoadBlock_888102D8(S, &x, 4);
    if (x < 0)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D0C, S->name);
    return x;
}

#ifdef _MSC_VER
#define TS4_FORCEINLINE_FN static __forceinline
#else
#define TS4_FORCEINLINE_FN static inline
#endif

/* Load a non-negative size, inlined into the table loaders. */
TS4_FORCEINLINE_FN int load_size_inline(Ts4LoadState *S)
{
    int x;
    lua2_LoadBlock_888102D8(S, &x, 4);
    if (x < 0)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D0C, S->name);
    return x;
}

/* Load a non-negative size whose result stays in memory. */
TS4_FORCEINLINE_FN int load_size_inline_nocopy(Ts4LoadState *S)
{
    return load_size_inline(S);
}

/* Prototype fields touched by the array loaders. */
typedef struct Ts4Proto {
    char pad0[0x10];
    void *lineinfo;
    char pad14[4];
    void *tmp18;
    char pad1c[0x30 - 0x1c];
    int nlineinfo;
    int ntmp;
} Ts4Proto;

/* Allocator state: reallocation callback at +0xC, its context at +0x10, byte count at +0x2C. */
typedef struct Ts4MemState {
    char pad0[0xC];
    void *(*frealloc)(void *ud, void *ptr, unsigned int osize, unsigned int nsize, int a, int tag);
    void *ud;
    char pad14[0x2C - 0x14];
    unsigned int nblocks;
} Ts4MemState;

/* Load the line-number table. */
static TS4_NOINLINE void lua2_LoadCode_88810780(Ts4LoadState *S, Ts4Proto *f)
{
    int n = load_size_inline(S);
    f->lineinfo = fn_889CE718(S->L, 0, 0, (unsigned int)n * 4);
    f->nlineinfo = n;
    lua2_LoadVector_88810250(S, f->lineinfo, n);
}

/* Load a temporary word table and free it again. */
static TS4_NOINLINE void lua2_LoadLines_888106C8(Ts4LoadState *S, Ts4Proto *f)
{
    Ts4MemState *g;
    int n = load_size_inline(S);
    f->tmp18 = fn_889CE718(S->L, 0, 0, (unsigned int)n * 4);
    f->ntmp = n;
    lua2_LoadVector_88810250(S, f->tmp18, n);
    {
        unsigned int bytes = (unsigned int)f->ntmp * 4;
        g = (Ts4MemState *)((Ts4LuaState *)S->L)->l_G;
        g->frealloc(g->ud, f->tmp18, bytes, 0, 0, *(int *)((char *)S->L + 0x68));
        g->nblocks -= bytes;
        f->tmp18 = 0;
    }
}

/* Load a counted byte string and intern it. */
static TS4_NOINLINE void *lua2_LoadString_888108C0(Ts4LoadState *S)
{
    unsigned int size;
    char *s;
    {
        unsigned int x;
        lua2_LoadBlock_888102D8(S, &x, 4);
        size = x;
    }
    if (size == 0) return 0;
    s = (char *)fn_8880BFB0(S->L, S->b, size);
    if (ex3_luaZ_read_8880C0C8(S->Z, s, size) != 0)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2CEC, S->name);
    return fn_888131A0(S->L, s, size - 1);
}

/* Load a non-negative 32-bit integer with the block loader expanded in place. */
TS4_FORCEINLINE_FN int load_int_inline(Ts4LoadState *S)
{
    int x;
    if (S->swap) {
        char *p = (char *)&x + 4;
        int i = 4;
        do {
            *--p = (char)lua2_ezgetc_888100B8(S);
        } while (--i != 0);
    } else {
        if (ex3_luaZ_read_8880C0C8(S->Z, &x, 4) != 0)
            UNEXPECTED_EOZ(S);
    }
    if (x < 0)
        lua3_luaG_runerror_8881FB60(S->L, lbl_880E2D0C, S->name);
    return x;
}

/* Local-variable debug record. */
typedef struct Ts4LocVar {
    Ts4LuaObject *varname;
    int startpc;
    int endpc;
} Ts4LocVar;

typedef struct Ts4ProtoVars {
    char pad0[0x1c];
    Ts4LocVar *locvars;
    char pad20[0x3c - 0x20];
    int sizelocvars;
} Ts4ProtoVars;

/* Load the local-variable table. */
TS4_NOINLINE void ts4_undump_load_locvars_88810D48(Ts4LoadState *S, Ts4ProtoVars *f)
{
    int i;
    int n = load_size_inline(S);
    f->locvars = (Ts4LocVar *)fn_889CE718(S->L, 0, 0, (unsigned int)n * 12);
    f->sizelocvars = n;
    for (i = 0; i < n; i++) {
        f->locvars[i].varname = (Ts4LuaObject *)lua2_LoadString_888108C0(S);
        f->locvars[i].varname->refs++;
        f->locvars[i].startpc = load_int_inline(S);
        f->locvars[i].endpc = load_int_inline(S);
    }
}

typedef struct Ts4ProtoUpvals Ts4ProtoUpvals;
extern void ts4_undump_load_upvalues_88810C80(Ts4LoadState *S, Ts4ProtoUpvals *f);

extern void *ts4_if_get_u32_off14_8881C630(lua_State *L);
extern void fn_88810948(Ts4LoadState *S, void *f);

typedef struct Ts4ProtoHead {
    char pad0[0x24];
    Ts4LuaObject *source;
    char pad28[0x40 - 0x28];
    int linedefined;
    char pad44[4];
    unsigned char nups;
    unsigned char numparams;
    unsigned char is_vararg;
    unsigned char maxstacksize;
} Ts4ProtoHead;

/* Load one function prototype: header fields, then the code, constants, debug tables. */
static Ts4ProtoHead *lua2_LoadFunction_88810F00(Ts4LoadState *S, Ts4LuaObject *p)
{
    Ts4ProtoHead *f = (Ts4ProtoHead *)ts4_if_get_u32_off14_8881C630(S->L);
    f->source = (Ts4LuaObject *)lua2_LoadString_888108C0(S);
    if (f->source == 0) f->source = p;
    f->source->refs++;
    f->linedefined = load_size_inline_nocopy(S);
    f->nups = (unsigned char)lua2_ezgetc_888100B8(S);
    f->numparams = (unsigned char)lua2_ezgetc_888100B8(S);
    f->is_vararg = (unsigned char)lua2_ezgetc_888100B8(S);
    f->maxstacksize = (unsigned char)lua2_ezgetc_888100B8(S);
    lua2_LoadLines_888106C8(S, (Ts4Proto *)f);
    ts4_undump_load_locvars_88810D48(S, (Ts4ProtoVars *)f);
    ts4_undump_load_upvalues_88810C80(S, (Ts4ProtoUpvals *)f);
    fn_88810948(S, f);
    lua2_LoadCode_88810780(S, (Ts4Proto *)f);
    {
        Ts4LuaObject *o = f->source;
        if (--o->refs == 0) fn_88818C88(S->L, o);
    }
    return f;
}
