/* rough draft 0x886D0390 (ME agent B): 144 off (/Oc). Reach weights: resets w[0..3], solves the reach frame
 * (fn_886CFE08), and when the offset is not ~0 sets w[3] = clamp01(1 - |d| / |reached - origin|). Target keeps d in
 * v127 and origin in v126 across the calls (only r29-r31 saved); ours saves three vectors. */
#include "ts4_vector.h"
extern double fabs(double);
#pragma intrinsic(fabs)
#define fabsf(x) ((float)fabs(x))
extern float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef struct Mat { __vector4 r[4]; } Mat;
typedef struct Reach { __vector4 pos; char p10[0x18 - 0x10]; int f18, f19, f20; int f24; float w[4]; } Reach;
typedef struct Trip { int a, b, c; } Trip;
void fn_886CFE08(Reach *r, Mat *m, __vector4 *origin, int *lim, Trip *t);
void fn_88263100(__vector4 *out, Mat *m, __vector4 *pos, __vector4 *dir);
void fn_886D0108(Reach *r, Mat *m, __vector4 *p);
static __inline __vector4 length3(__vector4 v, __vector4 zero, __vector4 half)
{
    __vector4 l = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(l);
    __vector4 z = __vcmpeqfp(l, zero);
    r = __vmaddfp(r, __vnmsubfp(__vmulfp(l, half), __vmulfp(r, r), half), r);
    return __vsel(__vmulfp(l, r), l, z);
}
static __inline float clamp01(float x, float zero, float one)
{
    x = x < zero ? zero : x;
    return x - one > zero ? one : x;
}
void fn_886D0390(Reach *self)
{
    float zero = g_ts4_event_value;
    float *p;
    Mat m;
    __vector4 origin, d, tmp, out, pos;
    int lim;
    Trip t;
    for (p = self->w; p != self->w + 4; p++)
        *p = zero;
    fn_886CFE08(self, &m, &origin, &lim, &t);
    pos = self->pos;
    self->f18 = t.a; self->f19 = t.b; self->f20 = t.c; self->f24 = lim;
    d = __vsubfp(pos, origin);
    tmp = d;
    if (fabsf(tmp.v[0]) < 0.001f && fabsf(tmp.v[1]) < 0.001f && fabsf(tmp.v[2]) < 0.001f) {
        self->w[0] = zero; self->w[1] = zero; self->w[2] = zero; self->w[3] = g_ts4_script_constants[0];
    } else {
        __vector4 zv = __vspltisw(0), half = __vcfsx(__vspltisw(1), 1), a, b;
        float r;
        __vector4 pp = pos;
        fn_88263100(&out, &m, &pp, &tmp);
        fn_886D0108(self, &m, &out);
        a = length3(d, zv, half);
        tmp = a;
        r = tmp.v[0];
        b = length3(__vsubfp(out, origin), zv, half);
        tmp = b;
        self->w[3] = g_ts4_script_constants[0] - r / tmp.v[0];
        self->w[3] = clamp01(self->w[3], zero, g_ts4_script_constants[0]);
    }
}
