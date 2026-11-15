/* CW35 part p: script handlers on a named object. */
#include "fam4_refstr.h"
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[4]; u32 f4; u8 reserved2[8]; Args *args; } Ctx;
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
typedef struct SubX { u8 pad[0x48]; int f48; } SubX;
typedef struct ObjX { u8 pad[0x28]; SubX *f28; } ObjX;
extern void fn_8818EB10(char **out, void *src);
extern ObjX **fn_881FFA10(void **h, u32 self, char **name, u32 one);
extern void ts4_if_atomic_interlocked_dec_881876D0(void *h);
extern void fn_88799490(SubX *o, u32 a);
extern void ts4_if_call_seq_u32_off70_887961A0(SubX *o, u32 a, u32 b);
extern u32 lbl_88C6CBF4;

u32 ts4_script_toggle_887A8CC8(Ctx *c)
{
    char *name;
    void *h;
    SubX *o;
    fn_8818EB10(&name, arg_at(c->args, 0)->pad);
    o = (*fn_881FFA10(&h, c->f4, &name, 1))->f28;
    if (h) {
        ts4_if_atomic_interlocked_dec_881876D0(h);
        h = 0;
    }
    if (o->f48 == 0) {
        fn_88799490(o, 0);
    } else {
        ts4_if_call_seq_u32_off70_887961A0(o, lbl_88C6CBF4, 1);
    }
    ts4_str_release(name);
    return 0;
}
