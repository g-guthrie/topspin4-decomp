/* Derived from Lua 5.0.2 (MIT license, Copyright (C) 1994-2004 Tecgraf, PUC-Rio); see THIRD_PARTY_NOTICES.md. */
/* Altered to match Swing_DLL.xex: reference-counted objects, wide strings, per-type metatables. */
#ifndef LUA2_H
#define LUA2_H
#ifdef _MSC_VER
typedef char *va_list;
void __cdecl __va_start(va_list *ap, ...);
#define va_start(ap, v) (__va_start(&(ap), (v)))
#define va_end(ap) ((ap) = (va_list)0)
#else
#include <stdarg.h>
#endif

typedef unsigned char lu_byte;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned int Instruction;
struct lua_State;
/* ldo.c: previous, jmp_buf at +0x10, status at +0x550. */
struct lua_longjmp {
    struct lua_longjmp *previous;
    char pad4[0x10 - 0x4];
    char b[0x550 - 0x10];
    volatile int status;
};

#ifdef _MSC_VER
#define LUA2_NOINLINE __declspec(noinline)
/* Same-TU copy of an out-of-line function defined elsewhere: the original (LTCG) build knew its register use. */
#define LUA2_LOCAL static __declspec(noinline)
#define LUA2_FORCEINLINE static __forceinline
#define LUA2_NORETURN __declspec(noreturn)
#else
#define LUA2_NOINLINE
#define LUA2_LOCAL static __attribute__((noinline, unused))
#define LUA2_FORCEINLINE static inline
#define LUA2_NORETURN
#endif

/* Type tags; 9 is the wide string, everything >= 4 is collectable and counted. */
#define LUA2_TNIL 0
#define LUA2_TBOOLEAN 1
#define LUA2_TLIGHTUSERDATA 2
#define LUA2_TNUMBER 3
#define LUA2_TSTRING 4
#define LUA2_TTABLE 5
#define LUA2_TFUNCTION 6
#define LUA2_TUSERDATA 7
#define LUA2_TTHREAD 8
#define LUA2_TWSTRING 9

/* Common header: doubly linked (next, prev), tt, marked, then a 16-bit reference count at +0xA. */
typedef struct GCheader {
    struct GCheader *next;
    struct GCheader *prev;
    lu_byte tt;
    lu_byte marked;
    u16 refs;
} GCheader;

typedef struct TValue {
    int tt;
    int pad;
    union {
        double n;
        void *p;
        int b;
        GCheader *gc;
    } value;
} TValue;
typedef TValue *StkId;

typedef struct TString {
    GCheader h;
    lu_byte reserved;
    u32 hash;
    u32 len;
} TString;
#define getstr(ts) ((char *)((ts) + 1))

typedef struct Node {
    TValue i_key;
    TValue i_val;
    struct Node *next;
} Node;

typedef struct Table {
    GCheader h;
    lu_byte flags;
    lu_byte lsizenode;
    struct Table *metatable;
    TValue *array;
    Node *node;
    Node *firstfree;
    GCheader *gclist;
    int sizearray;
} Table;

typedef struct Udata {
    GCheader h;
    Table *metatable;
    u32 len;
} Udata;

typedef struct LocVar {
    TString *varname;
    int startpc;
    int endpc;
} LocVar;

typedef struct Proto {
    GCheader h;
    TValue *k;
    Instruction *code;
    struct Proto **p;
    int *lineinfo;
    LocVar *locvars;
    TString **upvalues;
    TString *source;
    int sizeupvalues;
    int sizek;
    int sizecode;
    int sizelineinfo;
    int sizep;
    int sizelocvars;
    int lineDefined;
    GCheader *gclist;
    lu_byte nups;
    lu_byte numparams;
    lu_byte is_vararg;
    lu_byte maxstacksize;
} Proto;

typedef struct UpVal {
    GCheader h;
    TValue *v;
    TValue value;
} UpVal;

typedef struct CClosure {
    GCheader h;
    lu_byte isC;
    lu_byte nupvalues;
    GCheader *gclist;
    int (*f)(struct lua_State *L);
    TValue upvalue[1];
} CClosure;

typedef struct LClosure {
    GCheader h;
    lu_byte isC;
    lu_byte nupvalues;
    GCheader *gclist;
    Proto *p;
    TValue g;
    UpVal *upvals[1];
} LClosure;

typedef union Closure {
    CClosure c;
    LClosure l;
} Closure;

typedef struct CallInfo {
    StkId base;
    StkId top;
    int state;
    const Instruction *savedpc;
    const Instruction **pc;
    int tailcalls;
} CallInfo;

typedef struct global_State global_State;

typedef struct lua_State {
    GCheader h;
    StkId top;
    StkId base;
    global_State *l_G;
    CallInfo *ci;
    StkId stack_last;
    StkId stack;
    int stacksize;
    CallInfo *end_ci;
    CallInfo *base_ci;
    u16 size_ci;
    u16 nCcalls;
    lu_byte hookmask;
    lu_byte allowhook;
    lu_byte hookinit;
    int basehookcount;
    int hookcount;
    void (*hook)(struct lua_State *L, void *ar);
    TValue _gt;
    GCheader *openupval;
    GCheader *gclist;
    struct lua_longjmp *errorJmp;
    int errfunc;
    int inrealloc; /* set to 1 around buffer reallocation */
    void *stateUserData; /* LuaPlus per-state pointer (set by 0x888134C0) */
} lua_State;

typedef struct stringtable {
    GCheader **hash;
    int nuse;
    int size;
} stringtable;

typedef struct Mbuffer {
    char *buffer;
    u32 buffsize;
} Mbuffer;

struct global_State {
    stringtable strt;
    void *(*frealloc)(void *ud, void *block, u32 osize, u32 nsize, int flags, int inrealloc);
    void *ud;
    GCheader *rootgc;    /* list of collectable objects */
    GCheader *rootudata; /* list of userdata */
    GCheader *tmudata;   /* userdata to be finalized */
    Mbuffer buff;
    u32 GCthreshold;
    u32 nblocks;
    int (*panic)(struct lua_State *L);
    char pad34[0x38 - 0x34];
    TValue l_registry;
    TValue defaultmeta; /* LuaPlus: metatable of the per-type metatables */
    struct lua_State *mainthread;
    char pad5c[0x60 - 0x5C];
    Node dummynode;
    TString *tmname[0x10];
    TValue mt[11];
    void (*callback178)(void); /* set to 0x888134E8 by f_luaopen */
    int field17c;
    int field180;
    int field184;
};

#define G(L) ((L)->l_G)
#define ttype(o) ((o)->tt)
#define iscollectable(o) (ttype(o) >= LUA2_TSTRING)
#define hvalue(o) ((Table *)(o)->value.gc)
#define uvalue(o) ((Udata *)(o)->value.gc)
#define tsvalue(o) ((TString *)(o)->value.gc)
#define nvalue(o) ((o)->value.n)
#define bvalue(o) ((o)->value.b)
#define clvalue(o) ((Closure *)(o)->value.gc)
#define ci_func(ci) (clvalue((ci)->base - 1))
#define pcRel(pc, p) ((int)((pc) - (p)->code) - 1)
#define getline(f, pc) (((f)->lineinfo) ? (f)->lineinfo[pc] : 0)
#define l_isfalse(o) (ttype(o) == LUA2_TNIL || (ttype(o) == LUA2_TBOOLEAN && bvalue(o) == 0))

/* Shared out-of-line helpers. */
extern void *fn_889CE718(lua_State *L, void *block, u32 oldsize, u32 size); /* luaM_realloc */
extern const TValue lbl_880C9748; /* luaO_nilobject */

extern void fn_88818C88(lua_State *L, GCheader *o);

#define LUA2_ADDREF(o) \
    if (iscollectable(o)) (o)->value.gc->refs++
#define LUA2_RELEASE(L, o) \
    if (iscollectable(o)) { \
        if (--(o)->value.gc->refs == 0) fn_88818C88((L), (o)->value.gc); \
    }

/* setobj: reference-counted copy (the new value is referenced before the old one is released). */
#define setobj(L, obj1, obj2) \
    { \
        const TValue *o2 = (obj2); \
        TValue *o1 = (obj1); \
        LUA2_ADDREF(o2); \
        LUA2_RELEASE((L), o1); \
        o1->tt = o2->tt; \
        o1->value = o2->value; \
    }

#define setnilvalue(L, obj) \
    { \
        TValue *o1 = (obj); \
        LUA2_RELEASE((L), o1); \
        o1->tt = LUA2_TNIL; \
        o1->value.p = 0; \
    }

/* Store a collectable: remember the old value, write, reference, then release the old value. */
#define setgcvalue(L, obj, x, t) \
    { \
        TValue *o_ = (obj); \
        TValue old_ = *o_; \
        o_->value.gc = (GCheader *)(x); \
        o_->tt = (t); \
        o_->value.gc->refs++; \
        if (old_.tt >= LUA2_TSTRING) { \
            if (--old_.value.gc->refs == 0) fn_88818C88((L), old_.value.gc); \
        } \
    }

extern void lua2_luaD_reallocstack_8881D478(lua_State *L, int newsize); /* luaD_reallocstack */

/* luaD_checkstack with luaD_growstack expanded. */
#define luaD_checkstack(L, n) \
    if ((char *)(L)->stack_last - (char *)(L)->top <= (n) * (int)sizeof(TValue)) { \
        if ((n) <= (L)->stacksize) \
            lua2_luaD_reallocstack_8881D478((L), 2 * (L)->stacksize); \
        else \
            lua2_luaD_reallocstack_8881D478((L), (L)->stacksize + (n) + 5); \
    }

#define savestack(L, p) ((char *)(p) - (char *)(L)->stack)
#define restorestack(L, n) ((TValue *)((char *)(L)->stack + (n)))

/* luaG_runerror (0x8881FB60). A caller only gets the original frame layout when the variadic
   callee's body is visible in its translation unit, so files that raise errors define this copy. */
extern const char *lua3_luaO_pushvfstring_888188F8(lua_State *L, const char *fmt, va_list argp); /* luaO_pushvfstring */
extern void lua3_addinfo_8881FAD0(lua_State *L, const char *msg);                      /* addinfo */
extern void lua3_luaG_errormsg_8881F900(lua_State *L); /* luaG_errormsg */
#define LUA2_DEFINE_RUNERROR LUA2_DEFINE_RUNERROR_(LUA2_NORETURN)
/* Same copy for files whose callers still expect it to return. */
#define LUA2_DEFINE_RUNERROR_RET LUA2_DEFINE_RUNERROR_(LUA2_EMPTY)
#define LUA2_EMPTY
#define LUA2_DEFINE_RUNERROR_(attr) \
    LUA2_LOCAL attr void lua3_luaG_runerror_8881FB60(lua_State *L, const char *fmt, ...) \
    { \
        const char *msg; \
        va_list argp; \
        va_start(argp, fmt); \
        msg = lua3_luaO_pushvfstring_888188F8(L, fmt, argp); \
        va_end(argp); \
        lua3_addinfo_8881FAD0(L, msg); \
        lua3_luaG_errormsg_8881F900(L); \
    }

#endif
