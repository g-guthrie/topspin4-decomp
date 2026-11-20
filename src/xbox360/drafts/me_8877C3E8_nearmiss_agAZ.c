/* agAZ near miss, 2 off: lwz 0x2c4/0x2c0 order swapped. /Oc */
typedef unsigned int u32;
typedef unsigned char u8;
#define INL static __forceinline
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
INL Val *arg_at(Args *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}
INL double arg_number(Val *v)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return g_ts4_script_constants[11];
}

typedef struct G { u8 r[0x2c0]; u32 *first; u32 *last; } G;
extern G *lbl_88D45B1C;
extern u32 *fn_88165170(u32 *a, u32 *b, u32 *v);
u8 ts4_script_set_contains_8877C3E8(Ctx *c)
{
    u32 v = (u32)arg_number(arg_at(c->args, 0));
    G *g = lbl_88D45B1C;
    u32 *e = g->last;
    return e != fn_88165170(g->first, e, &v);
}
