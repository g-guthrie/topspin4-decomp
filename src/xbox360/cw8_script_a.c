/* CW8 script argument handlers near 0x881D1D78. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#include "fam4_refstr.h"
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 payload[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Host { u8 pad[0x6c]; void *target; } Host;
typedef struct Env { u8 pad[0x58]; void *registry; } Env;
typedef struct Ctx { Host *host; Env *env; u32 pad8; void *field_c; Args *args; } Ctx;
typedef struct Node { u8 pad[0x6e8]; u8 bit7 : 1; u8 bit6 : 1; u8 bits_lo : 6; } Node;
typedef struct Holder { u32 pad0; u32 pad4; Node *node; } Holder;
extern Holder *fn_881CECD0(void *key);
extern void fn_881C1298(Node *node, u32 one, float f);
extern const float lbl_8814B440;
extern Val *g_ts4_default_script_value;
extern const char g_ts4_true_string[];
extern double g_ts4_script_constants[];
u8 ts4_script_string_equals(void *value, const char *text);
extern u32 ts4_crc32_cstr_seed_88608590(void *a, void *b);
extern void fn_88202810(void *target, void *name, u8 flag, u32 one, u32 hash);
extern void fn_88202DF0(void *target, void *name, int amount);
extern void fn_88202900(void *target);
extern void ts4_loop_call_seq_u32_off10_88202BF8(void *target, u32 v);

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

/* 0x881D1D78: call target op with name (arg0), bool (arg1 == "true") and optional hash (arg2 when type 2) */
u32 ts4_script_call_name_bool_hash_881D1D78(Ctx *c)
{
    void *name = arg_at(c->args, 0)->payload;
    u8 flag = ts4_script_string_equals(arg_at(c->args, 1)->payload, g_ts4_true_string);
    u32 hash = 0;
    if (arg_at(c->args, 2)->type == 2) {
        hash = ts4_crc32_cstr_seed_88608590(0, *(void **)arg_at(c->args, 2)->payload);
    }
    fn_88202810(c->host->target, name, flag, 1, hash);
    return 0;
}

/* 0x881D1E68: call target op with name (arg0) and integer amount (arg1) */
u32 ts4_script_call_name_amount_881D1E68(Ctx *c)
{
    void *name = arg_at(c->args, 0)->payload;
    int amount = (int)arg_number(arg_at(c->args, 1));
    fn_88202DF0(c->host->target, name, amount);
    return 0;
}

/* 0x881D1F28: with a type-2 arg0 call the seq op with its hash, else call the plain op */
u32 ts4_script_call_hash_or_plain_881D1F28(Ctx *c)
{
    if (arg_at(c->args, 0)->type == 2) {
        u32 hash = ts4_crc32_cstr_seed_88608590(0, *(void **)arg_at(c->args, 0)->payload);
        ts4_loop_call_seq_u32_off10_88202BF8(c->host->target, hash);
    } else {
        fn_88202900(c->host->target);
    }
    return 0;
}

/* 0x881D2998: script op on the holder resolved through env->registry: mode 0 calls fn_881C1298, mode 1 sets flag bits from arg1 */
u32 ts4_script_node_mode_881D2998(Ctx *c)
{
    u32 mode = arg_at(c->args, 0)->value.integer;
    int on = arg_at(c->args, 1)->value.integer;
    Node *n = fn_881CECD0(c->env->registry)->node;
    if ((long)n != 0) {
        if (mode >= 1) {
            if (mode == 1) {
                n->bit7 = 1;
                n->bit6 = on != 0;
            }
        } else {
            fn_881C1298(n, 1, lbl_8814B440);
        }
    }
    return 0;
}

/* 0x881D2A70: same as 0x881D2998 with the registry taken from context field 0xC */
u32 ts4_script_node_mode_881D2A70(Ctx *c)
{
    u32 mode = arg_at(c->args, 0)->value.integer;
    Val *v1 = arg_at(c->args, 1);
    void *key = c->field_c;
    int on = v1->value.integer;
    Node *n = fn_881CECD0(key)->node;
    if ((long)n != 0) {
        if (mode >= 1) {
            if (mode == 1) {
                n->bit7 = 1;
                n->bit6 = on != 0;
            }
        } else {
            fn_881C1298(n, 1, lbl_8814B440);
        }
    }
    return 0;
}
