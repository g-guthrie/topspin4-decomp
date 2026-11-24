/* CW18 LTCG route, context: src/xbox360/hs3_i.c (callee 0x88843650), include ts4_reltbl_record_da554856_mode_88843650. Built with /Oc. */
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Cx18LuaCtx { u32 pad[0x6c / 4]; u32 **state; } Cx18LuaCtx;
typedef struct Cx18LuaArg { Cx18LuaCtx *ctx; } Cx18LuaArg;
extern void *lbl_88D459E8;
extern double ts4_lua_tonumber_88822420(u32 *obj, u32 idx);
extern void *ts4_reltbl_record_da554856_mode_88843650(void *game, u8 mode);
extern void fn_88863D00(void *game, int value, int flag);
/* 0x88864A78: script callback; record mode 0 on the reltbl entry, then hand the argument-1 integer on with flag 1 */
u32 ts4_script_cb_88864A78(void *unused, Cx18LuaArg *a)
{
    u32 **s = a->ctx->state;
    int value = (int)ts4_lua_tonumber_88822420(*s, 1);
    void *r;
    (void)unused;
    r = ts4_reltbl_record_da554856_mode_88843650(lbl_88D459E8, 0);
    fn_88863D00(r, value, 1);
    return 0;
}
