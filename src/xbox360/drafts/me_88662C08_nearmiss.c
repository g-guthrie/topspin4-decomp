/* NEAR MISS fn_88662C08 court-point side-box classifier: 68 off (same size 0x1AC, same frame), LTCG + pp1_pool_primer.c, /Oc.
 * Remaining: scheduling of the box float stores versus the in-place vector swap, and the early *out = 0 / p[0] loads. */
/* Swing_DLL.xex 0x88662C08: classify a court point against two side boxes around a base position. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern const float g_ts4_event_value;
#include "../ts4_vector.h"
extern const float g_ts4_event_value;

struct Ts4ZnDims { ts4_u8 pad_000[0x13C]; float margin; float width; float gap; float depth; };
struct Ts4ZnB { ts4_u8 pad_00[0x6C]; struct Ts4ZnDims *dims; };
struct Ts4ZnA { ts4_u8 pad_00[0x1C]; struct Ts4ZnB *b; };
struct Ts4ZnCtx { ts4_u8 pad_00[0x48]; struct Ts4ZnA *a; };
struct Ts4ZnBox { __vector4 lo; __vector4 hi; };
struct Ts4ZnHash { ts4_u32 h; };

static __inline struct Ts4ZnBox zn_box_unused(float lx, float lz, float hx, float hz)
{
    struct Ts4ZnBox r;
    r.lo.v[0] = lx; r.lo.v[1] = g_ts4_event_value; r.lo.v[2] = lz; r.lo.v[3] = g_ts4_event_value;
    r.hi.v[0] = hx; r.hi.v[1] = g_ts4_event_value; r.hi.v[2] = hz; r.hi.v[3] = g_ts4_event_value;
    return r;
}

static __inline ts4_u8 zn_inside(const struct Ts4ZnBox *b, const float *p)
{
    return (ts4_u8)(p[0] < b->hi.v[0] && p[2] < b->hi.v[2] && p[0] > b->lo.v[0] && p[2] > b->lo.v[2]);
}

void ts4_zone_side_hash_88662C08(ts4_u32 *out, const float *p, const float *base, struct Ts4ZnCtx *ctx)
{
    struct Ts4ZnDims *d = ctx->a->b->dims;
    float s = d->gap + d->margin;
    struct Ts4ZnBox t[2];
    t[0].lo.v[0] = -d->width; t[0].lo.v[1] = g_ts4_event_value; t[0].lo.v[2] = base[1] - d->margin; t[0].lo.v[3] = g_ts4_event_value;
    t[0].hi.v[0] = base[0] + d->margin; t[0].hi.v[1] = g_ts4_event_value; t[0].hi.v[2] = base[2] + d->margin; t[0].hi.v[3] = g_ts4_event_value;
    t[1].lo.v[0] = base[0] + s; t[1].lo.v[1] = g_ts4_event_value; t[1].lo.v[2] = base[2] + s; t[1].lo.v[3] = g_ts4_event_value;
    t[1].hi.v[0] = -d->depth - d->width; t[1].hi.v[1] = g_ts4_event_value; t[1].hi.v[2] = base[1] - s; t[1].hi.v[3] = g_ts4_event_value;
    { __vector4 x0 = t[0].lo, x1 = t[0].hi, x2 = t[1].lo, x3 = t[1].hi; t[1].lo = x0; t[1].hi = x1; t[0].lo = x3; t[0].hi = x2; }

    *out = 0;
    if (zn_inside(&t[1], p)) { *out = 0x81A72B79; return; }
    if (zn_inside(&t[0], p)) { *out = 0x2C59FAEA; return; }
    *out = 0x280AE84D;
}
