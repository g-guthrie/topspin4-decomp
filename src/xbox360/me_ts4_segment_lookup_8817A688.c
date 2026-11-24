/* Swing_DLL.xex 0x8817A688: piecewise-linear lookup in a self-relative list of 20-byte segments. */
/* Picks the last segment whose x0 <= x, clamps x - x0 to [0, x1 - x0] and returns y0 + t * slope. */
struct Ts4Seg20 { float x0; float x1; float y0; float slope; float extra; };
struct Ts4SegList { int offset; int count; };
static const float kZero = 0.0f;
static __inline float ts4_sl_max(float a, float b) { return (a - b >= kZero) ? a : b; }
static __inline float ts4_sl_min(float a, float b) { return (a - b >= kZero) ? b : a; }
static __forceinline const struct Ts4Seg20 *ts4_sl_end(const struct Ts4SegList *l)
{
    const struct Ts4Seg20 *r = 0;
    if (l->offset != -1)
        r = (const struct Ts4Seg20 *)((const char *)l + (l->count * 20 + l->offset));
    return r;
}
static __forceinline const struct Ts4Seg20 *ts4_sl_begin(const struct Ts4SegList *l)
{
    const struct Ts4Seg20 *r = 0;
    if (l->offset != -1)
        r = (const struct Ts4Seg20 *)((const char *)l + l->offset);
    return r;
}
float ts4_segment_lookup_8817A688(float x, const struct Ts4SegList *list)
{
    const struct Ts4Seg20 *end = ts4_sl_end(list);
    const struct Ts4Seg20 *e = ts4_sl_begin(list);
    const struct Ts4Seg20 *sel = e;
    for (; e != end; e++) {
        if (e->x0 > x)
            break;
        sel = e;
    }
    {
        float slope = sel->slope;
        float span = sel->x1 - sel->x0;
        float t = ts4_sl_max(ts4_sl_min(x - sel->x0, span), kZero);
        return t * slope + sel->y0;
    }
}
