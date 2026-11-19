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


typedef struct Name8 { u8 b[8]; } Name8;
typedef struct Item { u32 r0; int id; u8 r8[0x68]; Name8 name; } Item;
typedef struct ItemList { u8 r[4]; Item **first; Item **last; } ItemList;
typedef struct Reg { u8 r[0x1c]; ItemList *items; } Reg;
typedef struct Rel { int rel; } Rel;
typedef struct Blk { u8 r[0x1c]; Rel names; } Blk;
typedef struct Tgt { u8 r[0x188]; Blk *blk; } Tgt;
extern Tgt *g_ts4_online_context;
extern Reg *g_ts4_online_state;
/* 0x8877FAD0: script handler: copy the 8-byte name of the item whose id is arg 0 into the target block's name slot. */
u32 ts4_script_set_item_name_8877FAD0(Ctx *c)
{
    int id = (int)arg_number(arg_at(c->args, 0));
    Tgt *t = g_ts4_online_context;
    if (t) {
        ItemList *l = g_ts4_online_state->items;
        Item **end = l->last;
        Item **e;
        for (e = l->first; e != end; e++) {
            if (id == (*e)->id) {
                Rel *r = &t->blk->names;
                *(Name8 *)((u8 *)r + r->rel) = (*e)->name;
                return 0;
            }
        }
    }
    return 0;
}
