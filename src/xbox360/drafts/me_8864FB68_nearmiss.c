/* me_8864FB68 near-miss: best 47 off (plain /Oc), tried baseline + 15 spellings, all 47 off except one at 66.
   0x8864FB68: true when two spheres touch or overlap (|a.center - b.center| <= a.radius + b.radius). Sibling of
   ts4_sphere_contains_point_8864FC70 (matched with the same helpers).
   Residue: target hoists the four radius loads (lwz a->radius, lwz b->radius, lfs, lfs) to the top, interleaved with the
   center-pointer loads and before the stvewx stores into d, then the fadds sits before vsubfp. Ours keeps the loads at
   their use point (after the second len3 chain, right before fadds, fcmpu). Source order of the sum does not change it:
   the scheduler decides. Variants tried: sum first, sum in initialiser, ra/rb locals (both orders), block locals, pointer
   locals, one-decl locals, accumulate, helper returning sum (inline and __declspec(noinline)), helper loads, sum before
   d, ternary return. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
typedef struct F3 { float x, y, z; } F3;
typedef struct Sphere { char p[0x10]; F3 *center; float *radius; } Sphere;
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

unsigned char fn_8864FB68(Sphere *a, Sphere *b)
{
    float r;
    F3 d;
    r = *b->radius + *a->radius;
    d = sub3(a->center, b->center);
    return len3(&d) <= r;
}
