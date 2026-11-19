/* NEAR MISS 0x8869BEF0: 45 off (LTCG, ctx flags(/Ob1):src/xbox360/w6b_e.c): target keeps the zero splat in volatile v53 across the 8868ED00 call (LTCG register knowledge); we spill to v127. 4 variants incl. --include. */
#include "vx1_vector.h"
extern float g_ts4_event_value; /* 0.0f */
double fn_88564BF8(float y, float x);   /* atan2 */
typedef struct W6eObj78 Sampler;
void ts4_accumulate_samples_8868ED00(Sampler *self, __vector4 *out, int n);

typedef struct Aim { void *vt; int pad[3]; Sampler *sampler; __vector4 *target; } Aim;

static __inline __vector4 v3_length_est(__vector4 v)
{
    __vector4 lsq = __vmsum3fp(v, v);
    return __vsel(__vmulfp(lsq, __vrsqrtefp(lsq)), lsq, __vcmpeqfp(lsq, __vspltisw(0)));
}

static __inline __vector4 v3_length(__vector4 v)
{
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 lsq = __vmsum3fp(v, v);
    __vector4 e = __vrsqrtefp(lsq);
    e = __vmaddfp(e, __vnmsubfp(__vmulfp(lsq, half), __vmulfp(e, e), half), e);
    return __vsel(__vmulfp(lsq, e), lsq, __vcmpeqfp(lsq, __vspltisw(0)));
}

/* 0x8869BEF0: report the aim direction's length, then set out = {-heading, 1} when the averaged target is over 30 units away in the ground plane, else {0, 0}. */
void ts4_aim_heading_8869BEF0(Aim *self, float *out, float *len, __vector4 dir)
{
    __vector4 t;
    t = v3_length_est(dir);
    *len = t.v[0];
    ts4_accumulate_samples_8868ED00(self->sampler, &t, 30);
    t = vx1_set_y(__vsubfp(*self->target, t), g_ts4_event_value);
    out[0] = g_ts4_event_value;
    out[1] = g_ts4_event_value;
    t = v3_length(t);
    if (t.v[0] > 30.0f) {
        out[1] = 1.0f;
        out[0] = -(float)fn_88564BF8(dir.v[2], dir.v[0]);
    }
}
