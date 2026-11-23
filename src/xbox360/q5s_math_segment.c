/*
 * 0x88265890: piecewise-linear lookup over 16-byte segments {in0, in1, out0, out1}. Picks the last segment
 * whose in0 <= x (the first one when x is below all), clamps x - in0 to [0, in1 - in0] and maps it linearly onto
 * [out0, out1]. r3 is not used (member of an object that owns the segment range). Callers: 0x882628A0, 0x886D3AD8.
 *
 * Codegen: the two clamps are `fcmpu; mfcr; rlwinm 27; rlwinm 30; or; lfsx {+1,-1}; fsel` table selects against
 * a zero the target loads from 0x8814B440 (symbols.txt: g_ts4_event_value). That zero is a NAMED file-static
 * `static const float ... = 0.0f` (LTCG trims it from the map, fn_check_ltcg compares it by value as a pool
 * constant). The select helper is `__fself(c - kZero, x, y)`. With `extern const float g_ts4_event_value` instead,
 * the helper gives a bare `fsubs; fsel` and a `?:` gives branches.
 */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float c, float x, float y) { return c >= 0.0f ? x : y; }
#endif

static const float q5s_seg_zero = 0.0f;

typedef struct Q5sSegment { float in0, in1, out0, out1; } Q5sSegment;

/* c >= 0 ? x : y, both arms evaluated */
static __inline float q5s_seg_sel(float c, float x, float y) { return __fself(c - q5s_seg_zero, x, y); }

float ts4_segment_lookup_88265890(void *self, const Q5sSegment *begin, const Q5sSegment *end, float x)
{
    const Q5sSegment *p = begin;
    const Q5sSegment *s = begin;
    float d, span, t;
    (void)self;
    for (; p != end; ++p) {
        if (p->in0 > x)
            break;
        s = p;
    }
    d = x - s->in0;
    span = s->in1 - s->in0;
    t = q5s_seg_sel(d, d, q5s_seg_zero);
    t = q5s_seg_sel(t - span, span, t);
    return t / span * (s->out1 - s->out0) + s->out0;
}
