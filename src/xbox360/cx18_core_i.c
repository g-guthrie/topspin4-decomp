/* CW18 part i: script callbacks with two or three arguments (0x88850000-0x88871F08). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Cx18LuaCtx { u32 pad[0x6c / 4]; u32 **state; } Cx18LuaCtx;
typedef struct Cx18LuaArg { Cx18LuaCtx *ctx; } Cx18LuaArg;
extern double ts4_lua_tonumber_88822420(u32 *obj, u32 idx);
extern u32 ts4_lua_toboolean_88822398(u32 *obj, u32 idx);

typedef struct Cx18Cfg { u8 pad0[0xd00]; int modulus; u8 padd04[0xd14 - 0xd04]; u32 f14; u8 padd18[4]; int cur; int mode; } Cx18Cfg;
typedef struct Cx18Cursor { u8 pad0[0x24]; Cx18Cfg *cfg; u8 pad28[0x10]; void *sink38; void *sink3c; } Cx18Cursor;
extern Cx18Cursor *lbl_88D459E8;
extern void *lbl_88D459E0;
extern void fn_88862338(void *sink, u32 a, int mode, int target, int step, u32 d14);
extern void fn_88860B50(void *g, int id, int flag, u32 v);

/* 0x88862998: argument 1 is an id, argument 2 a step; advance the global cursor by it (wrapping at the modulus) and forward */
u32 ts4_script_cb_88862998(void *unused, Cx18LuaArg *a)
{
    u32 **s = a->ctx->state;
    double d1 = ts4_lua_tonumber_88822420(*s, 1);
    u32 *L2 = *s;
    u32 id = (int)d1;
    int step = (int)ts4_lua_tonumber_88822420(L2, 2);
    Cx18Cursor *c = lbl_88D459E8;
    int mod = c->cfg->modulus;
    int target;
    (void)unused;
    if (step == 0) target = c->cfg->cur;
    else target = (c->cfg->cur + mod + step - 1) % mod + 1;
    fn_88862338(c->sink38, id, c->cfg->mode, target, step, c->cfg->f14);
    return 0;
}

/* 0x88862108: argument 1 id, argument 2 a 64-bit-converted word, argument 3 a flag; skipped when the flag is set and the cursor object is not ready */
u32 ts4_script_cb_88862108(void *unused, Cx18LuaArg *a)
{
    u32 **s = a->ctx->state;
    double d1 = ts4_lua_tonumber_88822420(*s, 1);
    u32 *L2 = *s;
    int id = (int)d1;
    double d2 = ts4_lua_tonumber_88822420(L2, 2);
    u32 *L3 = *s;
    u32 v = (u32)d2;
    int flag = ts4_lua_toboolean_88822398(L3, 3) != 0;
    (void)unused;
    if (!(u8)flag || (lbl_88D459E8 != 0 && lbl_88D459E8->cfg != 0)) fn_88860B50(lbl_88D459E0, id, flag, v);
    return 0;
}
