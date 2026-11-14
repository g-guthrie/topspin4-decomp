#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x8880BFB0-0x8881CCE8, executable version 0.0.0.3. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "d8q_lua.h"

/* Growable scratch buffer. */
typedef struct Ts8Mbuffer {
    char *buffer;
    unsigned int buffsize;
} Ts8Mbuffer;

/* Writer state for precompiled chunks. */
typedef struct Ts8DumpState {
    lua_State *L;
    int (*writer)(lua_State *L, const void *p, unsigned int size, void *u);
    void *data;
    int swap;
    int pad10;
    Ts8Mbuffer buff;
} Ts8DumpState;

/* luaZ_openspace: make sure the scratch buffer holds at least n bytes. */
char *ts4_luaZ_openspace_8880BFB0(lua_State *L, Ts8Mbuffer *buff, unsigned int n)
{
    if (n > buff->buffsize) {
        int saved = TS5_AT(int, L, 0x68);
        if (n < 32) n = 32;
        TS5_AT(int, L, 0x68) = 1;
        buff->buffer = (char *)fn_889CE718(L, buff->buffer, buff->buffsize, n);
        TS5_AT(int, L, 0x68) = saved;
        buff->buffsize = n;
    }
    return buff->buffer;
}

extern char *fn_8880BFB0(lua_State *L, Ts8Mbuffer *buff, unsigned int n);
extern void lua2_DumpBlock_8881C828(const char *b, unsigned int size, Ts8DumpState *D);
extern void lua2_DumpVector_8881C8B8(const char *b, int n, unsigned int size, Ts8DumpState *D);

typedef struct Ts8TString {
    char pad0[0x14];
    unsigned int len;
    char data[1];
} Ts8TString;

#define TS8_STRDATA(s) ((const char *)(s) + 0x18)

/* DumpSize: write one 32-bit count. */
TS4_FORCEINLINE void dump_size(int x, Ts8DumpState *D)
{
    lua2_DumpBlock_8881C828((const char *)&x, 4, D);
}

