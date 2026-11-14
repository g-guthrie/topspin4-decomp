/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* ldump.c: save pre-compiled chunks. LuaPlus can write either byte order and dumps wide strings;
   this build writes no line information. */
#include "lua2.h"

#define LUA2_TWSTRING 9

typedef int (*lua_Chunkwriter)(lua_State *L, const void *p, u32 sz, void *ud);

typedef struct DumpState {
    lua_State *L;
    lua_Chunkwriter write;
    void *data;
    int swap;
    char endian;
    Mbuffer b;
} DumpState;

extern char *fn_8880BFB0(lua_State *L, Mbuffer *buff, u32 n); /* luaZ_openspace */
extern int ts4_call_seq_fn_8882E828_88825CD8(lua_State *L, const void *p, u32 sz, void *ud); /* buffer writer */
extern void ts4_call_seq_u32_off30_8881CB90(const Proto *f, DumpState *D);                   /* DumpCode */
extern char lbl_880E252C[];                    /* LUA_SIGNATURE "\033Lua" */
extern int lbl_88C6A108;                       /* int 1: first byte gives the native endianness */
extern const double g_ts4_script_constants[]; /* [94] = TEST_NUMBER 3.14159265358979323846E7 */

/* LuaPlus: byte-swap flag for an endianness character ('<' little, '>' big, '=' native);
   the console is big-endian, so only '<' swaps. */
int lua2_doswap_8881C800(int c)
{
    if (c == '<') return 1;
    else if (c == '>') return 0;
    else if (c == '=') return 0;
    return 0;
}

/* the 5.0.2 `getstr(s) == NULL' test, written so that hosted compilers accept it */
#define isnullptr(p) ((unsigned long)(p) == 0)
#define getwstr(ts) ((const unsigned short *)((ts) + 1))

/* DumpBlock: a swapped dump reverses the bytes through D->b */
LUA2_NOINLINE void lua2_DumpBlock_8881C828(const void *b, u32 size, DumpState *D)
{
    if (D->swap) {
        char *p = fn_8880BFB0(D->L, &D->b, size);
        char *q = p;
        const char *s;
        for (s = (const char *)b + size - 1; s >= (const char *)b; s--) *q++ = *s;
        D->write(D->L, p, size, D->data);
    } else
        D->write(D->L, b, size, D->data);
}

/* DumpVector: a swapped dump reverses each element */
LUA2_NOINLINE void lua2_DumpVector_8881C8B8(const void *b, int n, u32 size, DumpState *D)
{
    if (D->swap) {
        char *p = fn_8880BFB0(D->L, &D->b, n * size);
        char *q = p;
        const char *src = (const char *)b;
        int m = n;
        while (n--) {
            const char *s;
            for (s = src + size - 1; s >= src; s--) *q++ = *s;
            src += size;
        }
        D->write(D->L, p, m * size, D->data);
    } else
        D->write(D->L, b, n * size, D->data);
}

#define DumpLiteral(s, D) D->write(D->L, "" s, sizeof(s) - 1, D->data)

#define DumpByte(y, D) \
    { \
        char x_ = (char)(y); \
        lua2_DumpBlock_8881C828(&x_, sizeof(x_), D); \
    }
#define DumpInt(y, D) \
    { \
        int x_ = (y); \
        lua2_DumpBlock_8881C828(&x_, sizeof(x_), D); \
    }

LUA2_FORCEINLINE void DumpNumber_inl(double x, DumpState *D)
{
    lua2_DumpBlock_8881C828(&x, sizeof(x), D);
}

/* DumpNumber */
LUA2_NOINLINE void lua2_DumpNumber_8881C970(double x, DumpState *D)
{
    lua2_DumpBlock_8881C828(&x, sizeof(x), D);
}

/* DumpHeader */
LUA2_NOINLINE void lua2_DumpHeader_8881CA30(DumpState *D)
{
    int e = (D->endian == '=') ? *(signed char *)&lbl_88C6A108 : (D->endian == '<');
    D->write(D->L, lbl_880E252C, 4, D->data);
    DumpByte(0x50, D);
    DumpByte(e, D);
    DumpByte(sizeof(int), D);
    DumpByte(sizeof(u32), D);
    DumpByte(sizeof(Instruction), D);
    DumpByte(6, D);
    DumpByte(8, D);
    DumpByte(9, D);
    DumpByte(9, D);
    DumpByte(sizeof(double), D);
    DumpNumber_inl(g_ts4_script_constants[94], D);
}

/* DumpWString (LuaPlus) */
LUA2_NOINLINE void lua2_DumpWString_8881CBF0(TString *s, DumpState *D)
{
    if (s == 0 || isnullptr(getwstr(s))) {
        DumpInt(0, D);
    } else {
        u32 size = s->len + 1; /* include trailing '\0' */
        DumpInt(size, D);
        lua2_DumpVector_8881C8B8(getwstr(s), size, 2, D);
    }
}

LUA2_FORCEINLINE void DumpString_inl(TString *s, DumpState *D)
{
    if (s == 0 || isnullptr(getstr(s))) {
        DumpInt(0, D);
    } else {
        u32 size = s->len + 1; /* include trailing '\0' */
        DumpInt(size, D);
        D->write(D->L, getstr(s), size, D->data);
    }
}

/* DumpString */
LUA2_NOINLINE void lua2_DumpString_8881CC68(TString *s, DumpState *D)
{
    DumpString_inl(s, D);
}

/* DumpConstants (0x8881CCE8) is not reconstructed yet: its draft differs in three operand orders. */
extern void fn_8881CCE8(const Proto *f, DumpState *D);

/* DumpUpvalues */
LUA2_NOINLINE void lua2_DumpUpvalues_8881CDF0(const Proto *f, DumpState *D)
{
    int i, n = f->sizeupvalues;
    DumpInt(n, D);
    for (i = 0; i < n; i++) DumpString_inl(f->upvalues[i], D);
}

/* DumpLocals */
LUA2_NOINLINE void lua2_DumpLocals_8881CEB0(const Proto *f, DumpState *D)
{
    int i, n = f->sizelocvars;
    DumpInt(n, D);
    for (i = 0; i < n; i++) {
        DumpString_inl(f->locvars[i].varname, D);
        DumpInt(f->locvars[i].startpc, D);
        DumpInt(f->locvars[i].endpc, D);
    }
}

/* DumpFunction */
LUA2_NOINLINE void lua2_DumpFunction_8881CFA8(const Proto *f, const TString *p, DumpState *D)
{
    lua2_DumpString_8881CC68((f->source == p) ? 0 : f->source, D);
    DumpInt(f->lineDefined, D);
    DumpByte(f->nups, D);
    DumpByte(f->numparams, D);
    DumpByte(f->is_vararg, D);
    DumpByte(f->maxstacksize, D);
    lua2_DumpLocals_8881CEB0(f, D);
    lua2_DumpUpvalues_8881CDF0(f, D);
    fn_8881CCE8(f, D);
    ts4_call_seq_u32_off30_8881CB90(f, D);
}

/* luaU_dump: dump a function into the buffer writer, in the requested byte order */
void lua2_luaU_dump_8881D0A8(lua_State *L, const Proto *Main, void *data, char endian)
{
    DumpState D;
    D.L = L;
    D.write = ts4_call_seq_fn_8882E828_88825CD8;
    D.data = data;
    D.swap = lua2_doswap_8881C800(endian);
    D.endian = endian;
    D.b.buffer = 0;
    D.b.buffsize = 0;
    lua2_DumpHeader_8881CA30(&D);
    lua2_DumpFunction_8881CFA8(Main, 0, &D);
    {
        global_State *g = G(L);
        u32 size = D.b.buffsize;
        g->frealloc(g->ud, D.b.buffer, size, 0, 0, L->inrealloc);
        g->nblocks -= size;
    }
}
