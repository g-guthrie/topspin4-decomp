/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef D3D_LUA_H
#define D3D_LUA_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Reference-counted collectable header: the count is a 16-bit field at +0xA. */
typedef struct Ts4LuaObject {
    char header[0xA];
    u16 refs;
} Ts4LuaObject;

/* Tagged value: tag first, payload at +8. */
typedef struct Ts4LuaValue {
    int tt;
    int pad;
    union {
        double n;
        void *p;
        int b;
        Ts4LuaObject *gc;
    } u;
} Ts4LuaValue;


#ifdef _MSC_VER
#define TS4_FORCEINLINE static __forceinline
#define TS4_NORETURN __declspec(noreturn)
#else
#define TS4_FORCEINLINE static inline
#define TS4_NORETURN
#endif

/* Stack bookkeeping: current call frame limit. */
typedef struct Ts4LuaCallInfo {
    char header[4];
    struct Ts4LuaValue *top;
} Ts4LuaCallInfo;

/* Interpreter thread state: stack top/base, global state, call frame and stack extent. */
typedef struct Ts4LuaState {
    char header[0xC];
    Ts4LuaValue *top;
    Ts4LuaValue *base;
    void *l_G;
    Ts4LuaCallInfo *ci;
    Ts4LuaValue *stack_last;
    Ts4LuaValue *stack;
    int stacksize;
    int pad28;
    void *base_ci;
} Ts4LuaState;

/* Pending protected call: function slot and the result count wanted. */
typedef struct Ts4LuaCall {
    Ts4LuaValue *func;
    int nresults;
} Ts4LuaCall;

/* lua_type for a positive index: -1 when the slot is past the top. */
TS4_FORCEINLINE int ts4_lua_type(Ts4LuaState *L, int idx)
{
    Ts4LuaValue *o = L->base + (idx - 1);
    if (o >= L->top) o = 0;
    return (o == 0) ? -1 : o->tt;
}

TS4_FORCEINLINE int ts4_lua_gettop(Ts4LuaState *L)
{
    return (int)(L->top - L->base);
}


/* Reference-counted copy and stack growth helpers shared by the API wrappers. */
extern void fn_88818C88(void *L, Ts4LuaObject *o);
extern void fn_8881D478(void *L, int n);

#define TS4_ADDREF(o2) \
    if ((o2)->tt >= 4) (o2)->u.gc->refs++

#define TS4_RELEASE(L, o1) \
    if ((o1)->tt >= 4) { \
        if (--(o1)->u.gc->refs == 0) fn_88818C88((L), (o1)->u.gc); \
    }


/* api_incr_top with the stack growth check expanded. */
#define TS4_INCR_TOP(L) \
    { \
        if ((L)->top >= (L)->ci->top) { \
            if ((char *)(L)->stack_last - (char *)(L)->top <= 16) { \
                if (1 <= (L)->stacksize) \
                    fn_8881D478((L), 2 * (L)->stacksize); \
                else \
                    fn_8881D478((L), (L)->stacksize + 1 + 5); \
            } \
        } \
        (L)->top++; \
    }


/* setobjs2s: reference-counted assignment of one tagged value to another. */
#define TS4_SETOBJ(L, obj1, obj2) \
    { \
        Ts4LuaValue *o2 = (obj2); \
        Ts4LuaValue *o1 = (obj1); \
        TS4_ADDREF(o2); \
        TS4_RELEASE((L), o1); \
        o1->tt = o2->tt; \
        o1->u = o2->u; \
    }

/* setnilvalue on a stack slot that may hold a counted object. */
#define TS4_SETNIL(L, obj) \
    { \
        Ts4LuaValue *o1 = (obj); \
        TS4_RELEASE((L), o1); \
        o1->tt = 0; \
        o1->u.p = 0; \
    }


/* Global state: collection counters, metamethod names and the per-type metatable slots. */
typedef struct Ts4LuaGlobal {
    char pad0[0x28];
    u32 GCthreshold;
    u32 nblocks;
    char pad30[0x88 - 0x30];
    void *tmname[0x10];
    Ts4LuaValue mt[0x10];
} Ts4LuaGlobal;

#endif
