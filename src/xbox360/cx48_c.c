/* CW48 part c: small find loops and format wrappers, plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))


extern void ts4_tailcall_fn_88584548_8857AFE8(int a);
extern void fn_88778BE8(void *self, int code);

/* 0x8877DA88 */
void ts4_set_and_signal_8877DA88(char *self, u32 a, u32 b, u32 c)
{
    *(volatile u32 *)(self + 0xcc) = a;
    *(volatile u32 *)(self + 0xd0) = b;
    *(volatile u32 *)(self + 0xd4) = c;
    W(self, 0xd8) = 0xffffffffu;
    *(volatile u8 *)(self + 0xdc) = 0;
    fn_88778BE8(self, 0xe);
    ts4_tailcall_fn_88584548_8857AFE8(0xa0);
}


extern double ts4_lua_tonumber_88822420(u32 *obj, u32 idx);
extern char *lbl_88D45894;
typedef struct Cx48LuaCtx { u32 pad[0x8 / 4]; u32 **state; u32 idx; } Cx48LuaCtx;
/* 0x8877CE20: script callback, store argument 1 as an integer into the game block's +0x3c record */
u32 ts4_script_set_int_8877CE20(void *unused, Cx48LuaCtx *a)
{
    (void)unused;
    if (lbl_88D45894 != 0) {
        int v = (int)ts4_lua_tonumber_88822420(*a->state, a->idx);
        W(*(char **)(lbl_88D45894 + 0x3c), 0x10) = (u32)v;
    }
    return 0;
}

