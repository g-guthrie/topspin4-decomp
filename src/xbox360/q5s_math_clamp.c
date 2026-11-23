/*
 * 0x88269420: clamps both floats of a pair into [0, hi] in place. Caller: 0x886D89E8.
 *
 * Codegen: each clamp is two `fcmpu; mfcr; rlwinm; rlwinm; or; lfsx {+1,-1}; fsel` table selects, from
 * `__fself(c - kZero, x, y)` with a NAMED file-static zero (target loads it from 0x8814B440). The clamp helper
 * must take the float by pointer and store through it: with a by-value helper the second load is hoisted above
 * the first store.
 */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float c, float x, float y) { return c >= 0.0f ? x : y; }
#endif

static const float q5s_clamp_zero = 0.0f;

typedef struct Q5sFloatPair { float a, b; } Q5sFloatPair;

/* c >= 0 ? x : y, both arms evaluated */
static __inline float q5s_clamp_sel(float c, float x, float y) { return __fself(c - q5s_clamp_zero, x, y); }

static __inline void q5s_clamp_0_hi(float *v, float hi)
{
    float t = q5s_clamp_sel(*v, *v, q5s_clamp_zero);
    *v = q5s_clamp_sel(t - hi, hi, t);
}

void ts4_clamp_pair_0_hi_88269420(Q5sFloatPair *v, float hi)
{
    q5s_clamp_0_hi(&v->a, hi);
    q5s_clamp_0_hi(&v->b, hi);
}
