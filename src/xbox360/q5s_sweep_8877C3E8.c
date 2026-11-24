/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8877C3E8: script native: argument 0 as a number, converted to u32; returns whether the global set
 * (lbl_88D45B1C, range +0x2c0..+0x2c4) contains it (find through 0x88165170).
 * Source: drafts/me_8877C3E8_nearmiss_agAZ.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_8877C3E8.json for route and flags. */
typedef unsigned int u32;
typedef unsigned char u8;
#define INL static __forceinline
typedef struct Ts4ScriptVal { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Ts4ScriptVal;
typedef struct Ts4ScriptArgs { u8 reserved[0x380]; Ts4ScriptVal *items; u32 count; } Ts4ScriptArgs;
typedef struct Ts4ScriptCtx { u8 reserved[0x10]; Ts4ScriptArgs *args; } Ts4ScriptCtx;
extern Ts4ScriptVal *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
INL Ts4ScriptVal *arg_at(Ts4ScriptArgs *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}
INL double arg_number(Ts4ScriptVal *v)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return g_ts4_script_constants[11];
}

typedef struct Ts4ScriptSetHost { u8 r[0x2c0]; u32 *first; u32 *last; } Ts4ScriptSetHost;
extern Ts4ScriptSetHost *lbl_88D45B1C;
extern u32 *fn_88165170(u32 *a, u32 *b, u32 *v);
u8 ts4_script_set_contains_8877C3E8(Ts4ScriptCtx *c)
{
    u32 v = (u32)arg_number(arg_at(c->args, 0));
    Ts4ScriptSetHost *g = lbl_88D45B1C;
    u32 *e = g->last;
    return e != fn_88165170(g->first, e, &v);
}
