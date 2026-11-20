/* W9A: LTCG route, /Oc. Last-match entry search over a bounds-checked object vector. */
typedef unsigned int W9U32;
struct W9Obj;
typedef struct W9Vt { void *pad[0x12]; struct W9Hdr *(*fn48)(struct W9Obj *, int); } W9Vt;
typedef struct W9Obj { W9Vt *vt; } W9Obj;
typedef struct W9Ent { unsigned char pad[0xe0]; int key; unsigned char pad2[0x104 - 0xe4]; } W9Ent;
typedef struct W9Hdr { int rel; int count; } W9Hdr;
typedef struct W9E16 { W9Obj *p; W9U32 w[3]; } W9E16;
typedef struct W9V16 { W9E16 *first; } W9V16;
typedef struct W9S38 { unsigned char pad[0x13c4]; W9V16 *vec; W9U32 count; } W9S38;
typedef struct W9B48 { unsigned char pad[0x38]; W9S38 *s38; } W9B48;
typedef struct W9O8867AB78 { unsigned char pad[0x48]; W9B48 *b48; } W9O8867AB78;

static __inline W9Obj *w9_get(W9S38 *s, W9U32 i)
{
    W9Obj *r = 0;
    if (i < s->count) r = *(W9Obj **)((char *)s->vec->first + i * 16);
    return r;
}

W9Ent *ts4_find_entry_by_key_8867AB78(W9O8867AB78 *o, int key)
{
    W9Ent *r = 0;
    if (key > -1) {
        W9U32 n = o->b48->s38->count;
        W9U32 i;
        for (i = 0; i < n; i++) {
            W9Obj *ob = w9_get(o->b48->s38, i);
            W9Hdr *h = ob->vt->fn48(ob, 0);
            W9Ent *b, *e, *p;
            e = 0;
            if (h->rel != -1)
                e = (W9Ent *)((char *)h + (h->count * 0x104 + h->rel));
            b = 0;
            if (h->rel != -1)
                b = (W9Ent *)((char *)h + h->rel);
            for (p = b; e != p; p++) {
                if (p->key == key) { r = p; break; }
            }
        }
    }
    return r;
}

extern float ts4_layer_inv_time_warp_886D1318(void *l, float t);
typedef struct W9Key { unsigned char pad00[0x10]; float k10; float k14; } W9Key;
typedef struct W9Def {
    unsigned char pad00[0x70];
    int rel;                 /* +0x70 */
    int count;               /* +0x74 */
} W9Def;
typedef struct W9Link { unsigned char pad00[8]; W9Def *def; } W9Link;
typedef struct W9Inst {
    unsigned char pad00[4];
    W9Link *link;
    unsigned char pad08[0x6c - 0x08];
    unsigned *tag;           /* +0x6c */
} W9Inst;
typedef struct W9Own {
    unsigned char pad00[0x5c];
    W9Inst **inst;           /* +0x5c */
} W9Own;
typedef struct W9Holder { unsigned char pad00[0x30]; W9Own own; } W9Holder;
typedef struct W9Base { unsigned char pad00[0x18]; float base; } W9Base;
typedef struct W9Self { unsigned char pad00[0x28]; W9Holder *holder; W9Base *base; } W9Self;
extern int ts4_anim_layer_index_886C66C0(W9Own *o);

unsigned char ts4_layer_warp_in_range_886D21B8(W9Self *self)
{
    W9Holder *hd = self->holder;
    unsigned char r = 0;
    int ix = ts4_anim_layer_index_886C66C0(&hd->own);
    if (ix != -1) {
        W9Inst *in = hd->own.inst[ix];
        if (in->tag != 0) {
            unsigned id = *in->tag;
            int ok = id == 0xb7b2d9fdu || id == 0x2041cb84u || id == 0xb3ff5297u;
            if ((unsigned char)ok) {
                W9Def *d = in->link->def;
                if (d->count != 0) {
                    int *h = &d->rel;
                    W9Key *k = (W9Key *)((char *)h + *h);
                    float t = ts4_layer_inv_time_warp_886D1318(in, self->base->base);
                    int x = t <= k->k14 + k->k10;
                    r = (unsigned char)x;
                }
            }
        }
    }
    return r;
}
