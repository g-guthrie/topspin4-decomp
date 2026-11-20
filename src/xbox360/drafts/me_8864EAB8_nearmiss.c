/* agentA2 (2026-11-18 tips pass): volatile reads of each matrix row (single and pairs), named splats, row-0 local, block result: still 9 off (plain and LTCG); v-register numbering does not move. */
/* me_8864EAB8 near-miss: 9 off (plain and LTCG). Transform a 3-float point by a 4x4 row matrix, divide by w
   (refined vrefp reciprocal with NaN select, XMVector3TransformCoord shape) and store x,y,z with stvewx.
   Only the v0-v13 register numbering of the three row loads/splats/vmaddfp differs (target accumulates in v13 and
   reuses row0's v0 for the result). Tried: named temps, inline xform, hoisted row 0, LTCG. 8 variants. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
void __stvewx(__vector4 v, void *p, int off);
#pragma intrinsic(__stvewx)
typedef struct Mat44 { __vector4 r[4]; } Mat44;
static __inline __vector4 load3(const float *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}
static __inline __vector4 recip(__vector4 v, __vector4 one)
{
    __vector4 r = __vrefp(v);
    __vector4 e = __vnmsubfp(v, r, one);
    __vector4 r0 = r;
    __vector4 eq;
    r = __vmaddfp(r, e, r);
    e = __vnmsubfp(v, r, one);
    eq = __vcmpeqfp(r, r);
    r = __vmaddfp(r, e, r);
    return __vsel(r0, r, eq);
}

void fn_8864EAB8(const float *in, const Mat44 *m, float *out)
{
    __vector4 one = __vupkd3d(__vspltisw(0), 1);
    __vector4 v = load3(in);
    __vector4 t, w;
    t = __vmaddfp(m->r[2], __vspltw(v, 2), m->r[3]);
    t = __vmaddfp(__vspltw(v, 1), m->r[1], t);
    t = __vmaddfp(__vspltw(v, 0), m->r[0], t);
    w = __vspltw(t, 3);
    t = __vmulfp(t, recip(w, __vspltw(one, 3)));
    __stvewx(__vspltw(t, 0), out, 0);
    __stvewx(__vspltw(t, 1), out, 4);
    __stvewx(__vspltw(t, 2), out, 8);
}
