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


typedef struct Content Content;
typedef struct Ent { void *user; Content *content; } Ent;
typedef struct Pool { u8 r[0x1c]; Ent *first; Ent *last; } Pool;
extern Pool *lbl_88D45B30;
extern u8 ts4_content_has_space_88885228(Content *t);
/* 0x8877A608: script handler: for id 0x14B75F81 in arg 1, does the first free content slot have room? Otherwise 1. */
u8 ts4_script_content_has_space_8877A608(Ctx *c)
{
    u32 id = (u32)arg_number(arg_at(c->args, 1));
    u8 r = 1;
    if (id == 0x14b75f81) {
        Ent *end = lbl_88D45B30->last;
        Ent *e;
        Content *x = 0;
        for (e = lbl_88D45B30->first; end != e; e++) {
            if (!e->user) { x = e->content; break; }
        }
        r = ts4_content_has_space_88885228(x);
    }
    return r;
}
