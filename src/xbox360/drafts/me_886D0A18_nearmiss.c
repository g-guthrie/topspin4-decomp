/* near miss 0x886D0A18 (ME agent B): 177 off on /Oc (plain and LTCG). Structure and fres recipe right;
 * prologue differs (we save r28-r31 via __savegprlr_28, target std r30/r31 with layer in r30) and the key
 * address folds 0x70+0x10 (target keeps addi base+0x70; try a volatile self-relative offset as in
 * me_two_event_ticks_remaining_886CD1E8.c). Function: picks the last key before the layer's clip time,
 * stores it and the segment value/link pair into the state block. */
typedef struct Key { char p[0x10]; float time; char p2[0x28 - 0x14]; } Key;
typedef struct ClipDesc { char p[0x14]; float time_ratio; char p18[0x20 - 0x18]; short seg; short sub; char p24[0x70 - 0x24]; int keys_rel; unsigned int num_keys; } ClipDesc;
typedef struct LayerInner { char p[8]; ClipDesc *desc; } LayerInner;
typedef struct Layer { char p[4]; LayerInner *inner; char p2[0x14 - 8]; float rate; char p3[0x24 - 0x18]; float base_time; char p4[0x6c - 0x28]; int use_links; } Layer;
typedef struct AnimStack { char p[0x18]; float now; char p1c[0x20 - 0x1c]; struct Ctx *ctx; char p24[0x28 - 0x24]; struct Res *res; char p2c[0x5c - 0x2c]; Layer **layers; } AnimStack;
typedef struct State { char p[0x55]; unsigned char locked; char p56[0x468 - 0x56]; int seg_value; int cur_key; int link_a; int link_b; } State;
typedef struct Ctx { char p[0x14]; State *state; } Ctx;
typedef struct Link { char p[8]; unsigned short id; char pa[0x10 - 0xa]; int a; int b; } Link;
typedef struct Seg { int links_rel; unsigned int num_links; char p8[0xc - 8]; int value; char p10[0x20 - 0x10]; int def_a; int def_b; } Seg;
typedef struct SegTable { int segs_rel; } SegTable;
typedef struct ResData { char p[0x14]; int table_rel; } ResData;
typedef struct Res { char p[0xc]; ResData *data; } Res;
typedef struct Globals { char p[0x27c]; int none; } Globals;
extern Globals *lbl_88D45B1C;
extern float __fres(float);
#pragma intrinsic(__fres)
extern float g_ts4_script_constants[];
int ts4_anim_layer_index_886C66C0(AnimStack *stack);
static __inline SegTable *seg_table(ResData *d) { return (SegTable *)((char *)&d->table_rel + d->table_rel); }
static __inline Seg *seg_at(SegTable *t, int i) { return (Seg *)((char *)t + t->segs_rel + i * sizeof(Seg)); }
static __inline Key *keys(ClipDesc *d) { return (Key *)((char *)&d->keys_rel + d->keys_rel); }
static __inline Link *links(Seg *s) { return (Link *)((char *)s + s->links_rel); }
void fn_886D0A18(AnimStack *self)
{
    int idx = ts4_anim_layer_index_886C66C0(self);
    Layer *l;
    ClipDesc *d;
    float t, one;
    int last;
    unsigned int i;
    int seg, sub;
    Seg *s;
    State *st;
    if (idx == -1)
        return;
    l = self->layers[idx];
    d = l->inner->desc;
    one = g_ts4_script_constants[0];
    {
        float dv = d->time_ratio - one;
        float inv = __fres(dv);
        inv = ((one - inv * dv) + one) * inv;
        t = (self->now - l->base_time) * inv + l->rate;
    }
    last = -1;
    for (i = 0; i < d->num_keys; i++)
        if (keys(d)[i].time < t)
            last = i;
    self->ctx->state->cur_key = last;
    seg = d->seg;
    if (seg == -1)
        return;
    sub = d->sub;
    s = seg_at(seg_table(self->res->data), seg);
    st = self->ctx->state;
    if (!st->locked)
        st->seg_value = s->value;
    if (l->use_links) {
        unsigned char found = 0;
        Seg *s2 = seg_at(seg_table(self->res->data), seg);
        unsigned int j;
        for (j = 0; j < s2->num_links; j++) {
            Link *k = &links(s)[j];
            if (k->id == (unsigned int)sub && k->a != lbl_88D45B1C->none && k->b != lbl_88D45B1C->none) {
                found = 1;
                self->ctx->state->link_a = k->a;
                self->ctx->state->link_b = k->b;
            }
        }
        if (!found) {
            self->ctx->state->link_a = seg_at(seg_table(self->res->data), seg)->def_a;
            self->ctx->state->link_b = seg_at(seg_table(self->res->data), seg)->def_b;
        }
    }
}
