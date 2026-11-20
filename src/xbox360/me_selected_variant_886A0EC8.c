/* 0x886A0EC8 (hand match): the variant for the owner's current selection. Looks up the group whose
 * key matches the selection's group key, then the variant inside it whose key matches the
 * selection's variant key; each lookup falls back to the first element when nothing matches. */
typedef struct Rel { int offset; int count; } Rel;
typedef struct Variant { char p[0x3c]; unsigned int key; char p2[0x5c - 0x40]; } Variant;
typedef struct Group { Rel variants; char p[4]; unsigned int key; } Group;
typedef struct Data { char p[0xf0]; Rel groups; } Data;
typedef struct Holder { char p[0x6c]; Data *data; } Holder;
typedef struct Src { char p[0x1c]; Holder *holder; } Src;
typedef struct Selection { char p[4]; unsigned int variant_key; unsigned int group_key; } Selection;
typedef struct Ctx { char p[0x48]; Src *src; char p2[0x7c - 0x4c]; Selection *selection; } Ctx;
typedef struct Obj { char p[8]; Ctx *ctx; } Obj;
static __forceinline Group *group_find(Rel *t, Selection *sel)
{
    Group *r = 0;
    int i;
    for (i = 0; i < t->count; i++) {
        Group *e = (Group *)((char *)t + (i * 16 + t->offset));
        if (e->key == sel->group_key) {
            r = e;
            break;
        }
    }
    return r;
}
static __forceinline Variant *variant_find(Rel *t, Selection *sel)
{
    Variant *r = 0;
    int i;
    for (i = 0; i < t->count; i++) {
        Variant *e = (Variant *)((char *)t + (i * 92 + t->offset));
        if (e->key == sel->variant_key) {
            r = e;
            break;
        }
    }
    return r;
}
static __forceinline Group *group_first_b(Rel *t) { Group *r = 0; int off = t->offset; if (off != -1) r = (Group *)((char *)t + off); return r; }
static __forceinline Group *group_first(Rel *t, Group *r) { if (r == 0) r = group_first_b(t); return r; }
static __forceinline Variant *variant_first_b(Rel *t) { Variant *r = 0; int off = t->offset; if (off != -1) r = (Variant *)((char *)t + off); return r; }
static __forceinline Variant *variant_first(Rel *t, Variant *r) { if (r == 0) r = variant_first_b(t); return r; }
Variant *ts4_selected_variant_886A0EC8(Obj *o)
{
    Src *src = o->ctx->src;
    Selection *sel = o->ctx->selection;
    Rel *t = &src->holder->data->groups;
    Group *g = group_first(t, group_find(t, sel));
    Rel *v = &g->variants;
    sel = o->ctx->selection;
    return variant_first(v, variant_find(v, sel));
}
