/* Swing_DLL.xex 0x88853B40-0x88853BC4, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4LuaCtx { u32 pad[0x6c / 4]; u32 **state; } Ts4LuaCtx;
typedef struct Ts4LuaArg { Ts4LuaCtx *ctx; } Ts4LuaArg;
typedef struct Ts4MgrA { char pad[0x34]; void *target; } Ts4MgrA;
typedef struct Ts4MgrB { char pad[0x27c]; u32 value; } Ts4MgrB;
extern Ts4MgrA *lbl_88D459E8;
extern Ts4MgrB *lbl_88D45B1C;
extern double ts4_lua_tonumber_88822420(u32 *obj, u32 idx);
extern void fn_8884CF80(void *target, u32 key, u32 value, int amount, int flag);

u32 ts4_script_cb_88853B40(void *unused, Ts4LuaArg *a)
{
    u32 key;
    int amount;
    u32 *L;
    u32 **s = a->ctx->state;
    L = *s;
    key = (u32)ts4_lua_tonumber_88822420(L, 1);
    L = *s;
    amount = (int)ts4_lua_tonumber_88822420(L, 2);
    (void)unused;
    fn_8884CF80(lbl_88D459E8->target, key, lbl_88D45B1C->value, amount, 0);
    return 0;
}
