/* Swing_DLL.xex 0x88848998-0x88848A20, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4LuaCtx { u32 pad[0x6c / 4]; u32 **state; } Ts4LuaCtx;
typedef struct Ts4LuaArg { Ts4LuaCtx *ctx; } Ts4LuaArg;
typedef struct Ts4Ent { char pad[0x180]; int id; } Ts4Ent;
typedef struct Ts4Mgr { char pad[0x20]; Ts4Ent **first; Ts4Ent **last; } Ts4Mgr;
extern Ts4Mgr *lbl_88D459E0;
extern double ts4_lua_tonumber_88822420(u32 *obj, u32 idx);
extern void ts4_if_get_fn_8883F238_88848698(Ts4Ent *ent, int flag);

u32 ts4_script_cb_88848998(void *unused, Ts4LuaArg *a)
{
    int key;
    u32 *L;
    Ts4Ent *found;
    Ts4Ent **p;
    Ts4Ent **e;
    Ts4Mgr *m;
    u32 **s = a->ctx->state;
    (void)unused;
    L = *s;
    key = (int)ts4_lua_tonumber_88822420(L, 1);
    found = 0;
    m = lbl_88D459E0;
    e = m->last;
    for (p = m->first; p != e; ++p) {
        if ((*p)->id == key) {
            found = *p;
            break;
        }
    }
    ts4_if_get_fn_8883F238_88848698(found, 0);
    return 0;
}
