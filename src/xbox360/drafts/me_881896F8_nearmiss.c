/* NEAR MISS fn_881896F8 line intersection in x/z: 62 off (same size 0x13C, same 4 relocs), LTCG + pp1_pool_primer.c, /Oc.
 * Was 77. The ld/std copy of a->d comes from a line struct whose members are two __int64 halves (a double pair works
 * too); float[4] copies with four lwz/stw. Remaining: the target keeps a->p in one register (vor copy + vmaddfp128
 * accumulate), stores diff to two stack slots, and in the parallel path loads a->p once and stores *out after the compare. */
/* Swing_DLL.xex 0x881896F8: intersect two lines in the ground plane (x, z). Each line is a point and a direction.
   Parallel lines: out = a's point, returns whether the two points are equal. Otherwise out = a.p + a.d * t and
   returns 1 with the parameters t (along a) and u (along b). */
typedef unsigned char ts4_u8;
typedef unsigned char ts4_bool;
#include "../ts4_vector.h"
#ifdef _MSC_VER
#pragma intrinsic(__vsubfp, __vmaddfp, __vspltw, __vpermwi)
void __vcmpeqfpR(__vector4 a, __vector4 b, unsigned int *cr);
#pragma intrinsic(__vcmpeqfpR)
#endif

extern const float g_ts4_event_value;   /* 0.0f */
struct Ts4V4 { __int64 lo; __int64 hi; };
struct Ts4Line { struct Ts4V4 p; struct Ts4V4 d; };
#define LV(x) (*(const __vector4 *)&(x))

static __inline float li_cross2(__vector4 a, __vector4 b) { return b.v[2] * a.v[0] - b.v[0] * a.v[2]; }
static __inline float li_cross2r(__vector4 b, __vector4 a) { return b.v[2] * a.v[0] - a.v[2] * b.v[0]; }
static __inline ts4_bool li_equal3(__vector4 v, __vector4 w)
{
    unsigned int cr;
    __vcmpeqfpR(__vpermwi(v, 24), __vpermwi(w, 24), &cr);
    return (ts4_bool)((cr >> 7) & 1);
}

ts4_bool ts4_line_intersect_xz_881896F8(const struct Ts4Line *a, const struct Ts4Line *b, __vector4 *out, float *t, float *u)
{
    float denom = li_cross2r(LV(b->d), LV(a->d));
    if (denom != g_ts4_event_value) {
        struct Ts4V4 da = a->d;
        __vector4 ap = LV(a->p);
        __vector4 diff = __vsubfp(ap, LV(b->p));
        float inv = 1.0f / denom;
        float tt = li_cross2(LV(b->d), diff) * inv;
        float uu = li_cross2(LV(da), diff) * inv;
        *t = tt;
        *u = uu;
        *out = __vmaddfp(LV(da), __vspltw(__lvlx(&tt, 0), 0), ap);
        return 1;
    }
    *out = LV(a->p);
    return li_equal3(LV(a->p), LV(b->p));
}
