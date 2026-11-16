/* 0x886D1490: recomputes a layer's tick window. The span length is the clip-time window scaled by
 * the clip's time ratio - 1; the base tick is the parent layer's warped time (0 without a parent); the
 * end and length ticks follow from it, and the parent's limit is set to base + length. */
typedef struct ClipDesc { char p[0x14]; float time_ratio; } ClipDesc;
typedef struct ClipRef { char p[8]; ClipDesc *desc; } ClipRef;
typedef struct Layer {
    char p0[4]; ClipRef *inner;          /* +0x04 */
    char p1[0xc - 8]; float parent_time; /* +0x0c */
    char p2[0x14 - 0x10]; float t_ref;   /* +0x14 */
    float t_end;                         /* +0x18 */
    char p3[0x24 - 0x1c]; float base;    /* +0x24 */
    float limit;                         /* +0x28 */
    float length;                        /* +0x2c */
    char p4[0x34 - 0x30]; struct Layer *parent; /* +0x34 */
    float w_start; float w_end;          /* +0x38, +0x3c */
    float span;                          /* +0x40 */
} Layer;
extern float g_ts4_script_constants[];
extern float lbl_8814B440;
float ts4_layer_time_warp_886D1408(Layer *l, float t);
static __inline void set_span(Layer *l, float one) { l->span = (l->w_end - l->w_start) * (l->inner->desc->time_ratio - one); }
static __inline float ratio_m1(Layer *l, float one) { return l->inner->desc->time_ratio - one; }
void ts4_layer_recompute_tick_window(Layer *l)
{
    float one = g_ts4_script_constants[0];
    Layer *parent;
    { float *w = &l->w_start; w[2] = (w[1] - w[0]) * ratio_m1(l, one); }
    parent = l->parent;
    if (parent != 0) l->base = ts4_layer_time_warp_886D1408(parent, l->parent_time);
    else l->base = lbl_8814B440;
    {
        float d = l->w_end - l->t_ref;
        float k = l->inner->desc->time_ratio - one;
        l->limit = d * k + l->base;
    }
    {
        float d = l->t_end - l->t_ref;
        float k = l->inner->desc->time_ratio - one;
        l->length = d * k;
    }
    if (parent != 0) parent->limit = l->length + l->base;
}
