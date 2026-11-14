/* Swing_DLL.xex Lua object layouts shared by the d6q units. */
/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef D6Q_LUA_H
#define D6Q_LUA_H

#include "d4b_lua_error.h"

/* Error-recovery record: setjmp buffer at +0x10, status code at +0x550. */
typedef struct Ts5LongJmp {
    char pad[0x10];
    char b[0x540];
    volatile int status;
} Ts5LongJmp;

/* Thread state seen by the error-raising paths: global state at +0x14, handler record at +0x60. */
typedef struct Ts5StateErr {
    char pad0[0x14];
    struct Ts5GlobalPanic *l_G;
    char pad18[0x48];
    Ts5LongJmp *errorJmp;
} Ts5StateErr;

typedef struct Ts5GlobalPanic {
    char pad[0x30];
    int (*panic)(Ts5StateErr *L);
} Ts5GlobalPanic;

extern TS4_NORETURN void fn_88569D30(void *buf, int val);
extern TS4_NORETURN void ts4_tailcall_fn_88564208_885643D0(int code);

/* luaD_throw body: jump to the recovery point, or panic. */
#define TS5_THROW(L, code) \
    if ((L)->errorJmp) { \
        (L)->errorJmp->status = (code); \
        fn_88569D30((L)->errorJmp->b, 1); \
    } \
    (L)->l_G->panic(L); \
    ts4_tailcall_fn_88564208_885643D0(1)

typedef Ts4LuaState lua_State;
typedef Ts4LuaValue TValue;

typedef struct Ts5Node {
    TValue key;
    TValue val;
    struct Ts5Node *next;
    int pad;
} Ts5Node;

/* Table: array at +0x14, node vector at +0x18, log2 node count at +0xD, array size at +0x24. */
typedef struct Ts5Table {
    char pad0[0xD];
    unsigned char lsizenode;
    char pad0e[6];
    TValue *array;
    Ts5Node *node;
    char pad1c[8];
    int sizearray;
} Ts5Table;

/* Collectable header: list links at +0/+4, type at +8, mark bits at +9, reference count at +0xA. */
typedef struct Ts5GCObject {
    struct Ts5GCObject *next;
    struct Ts5GCObject *prev;
    u8 tt;
    u8 marked;
    u16 refs;
} Ts5GCObject;

/* Global state: root of the collectable list at +0x14. */
typedef struct Ts5Global {
    char pad0[0x14];
    Ts5GCObject root;
} Ts5Global;

/* Field access by byte offset for object kinds that are only partly modelled. */
#define TS5_AT(T, o, off) (*(T *)((char *)(o) + (off)))

/* Call record: base at +0, saved top at +4, state flags at +8, tail-call count at +0x14. */
typedef struct Ts5CI {
    TValue *base;
    TValue *top;
    int state;
    char padC[8];
    int tailcalls;
} Ts5CI;

extern void *fn_889CE718(lua_State *L, void *block, unsigned int osize, unsigned int nsize);

#endif
