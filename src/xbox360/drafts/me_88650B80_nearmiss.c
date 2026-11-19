/* NEAR MISS 0x88650B80, 4 instructions off on plain /Oc and LTCG (work/army/ME/v.py chk, matching-b133). Model: me_ts4_sphere_contains_point.c (0x8864FC70).
 * Only difference: vector register swap v59/v60 for the two lvlx128 loads (centre vs point) and the matching vor128 operands.
 * Tried: explicit va/vb load order (ab = 9 off), swapped sub3 params, copy3 helper, struct copy (33 off), int padding 0-9. */
/* 0x88650B80: distance from the sphere centre to a point; also copies the centre into *center_out. The difference
   goes through a 3-float stack temporary (stvewx store + struct return copy) before the refined-rsqrt length. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
typedef struct F3 { float x, y, z; } F3;
typedef struct Sphere { char p[0x10]; F3 *center; float *radius; } Sphere;   /* center/radius are shared refs */
static __inline __vector4 load3(const F3 *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}
static __inline F3 sub3(const F3 *a, const F3 *b)
{
    F3 r;
    __vector4 d = __vsubfp(load3(a), load3(b));
    __stvewx(__vspltw(d, 0), &r, 0);
    __stvewx(__vspltw(d, 1), &r, 4);
    __stvewx(__vspltw(d, 2), &r, 8);
    return r;
}
static __inline float len3(const F3 *p)
{
    __vector4 v = load3(p);
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 zero = __vspltisw(0);
    __vector4 len_sq = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(len_sq);
    __vector4 is_zero = __vcmpeqfp(len_sq, zero);
    __vector4 step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    Vx1Vec o;
    r = __vmaddfp(r, step, r);
    o.v = __vsel(__vmulfp(len_sq, r), len_sq, is_zero);
    return o.v.v[0];
}

float ts4_sphere_center_distance_88650B80(Sphere *s, const F3 *p, F3 *center_out)
{
    F3 d;
    const F3 *c = s->center;
    center_out->x = c->x; center_out->y = c->y; center_out->z = c->z;
    d = sub3(p, c);
    return len3(&d);
}
