/* Swing_DLL.xex 0x881899D8: piecewise-linear lookup in a self-relative range list. */
struct Ts4Range { float x0; float x1; float y0; float y1; };
struct Ts4RangeList { int offset; int count; };
static const float kZero = 0.0f;
static __inline float ts4_rl_max(float a, float b) { return (a - b >= kZero) ? a : b; }
static __inline float ts4_rl_min(float a, float b) { return (a - b >= kZero) ? b : a; }
static __forceinline const struct Ts4Range *ts4_rl_end(const struct Ts4RangeList *l)
{
    const struct Ts4Range *r = 0;
    if (l->offset != -1)
        r = (const struct Ts4Range *)((const char *)l + (l->count * 16 + l->offset));
    return r;
}
static __forceinline const struct Ts4Range *ts4_rl_begin(const struct Ts4RangeList *l)
{
    const struct Ts4Range *r = 0;
    if (l->offset != -1)
        r = (const struct Ts4Range *)((const char *)l + l->offset);
    return r;
}
float ts4_range_lookup_881899D8(float x, const struct Ts4RangeList *list)
{
    const struct Ts4Range *end = ts4_rl_end(list);
    const struct Ts4Range *e = ts4_rl_begin(list);
    const struct Ts4Range *sel = e;
    float span;
    for (; e != end; e++) {
        if (e->x0 > x)
            break;
        sel = e;
    }
    {
        float dy = sel->y1 - sel->y0;
        float u;
        span = sel->x1 - sel->x0;
        u = ts4_rl_min(ts4_rl_max(x - sel->x0, kZero), span) / span;
        return u * dy + sel->y0;
    }
}
