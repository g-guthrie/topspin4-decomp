/* CW35 part e: number-argument script handlers, double kept across a call. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
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

extern void *lbl_88D45A60;
extern u32 ts4_loop_get_u32_lbl_88D45B1C_88868008(void);
extern u32 fn_887ADEB8(u32 a, int b, u32 c);
extern void ts4_if_set_u32_off314_887993C8(void *g, u32 v);

u32 ts4_script_set_off314_887AE318(Ctx *c)
{
    double d = arg_number(arg_at(c->args, 0));
    ts4_loop_get_u32_lbl_88D45B1C_88868008();
    ts4_if_set_u32_off314_887993C8(lbl_88D45A60, fn_887ADEB8(0, (int)d, 1));
    return 0;
}
