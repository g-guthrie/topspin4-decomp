/*
 * 0x881A40F0: transforms a packed float3 point in place by a 4x4 matrix (XMVector3TransformCoord:
 * x*r0 + y*r1 + z*r2 + r3, divided by w). The point is loaded unaligned (lvlx/lvrx + vsldoi + vor)
 * and written back one lane at a time with stvewx.
 *
 * Codegen: af1_transform_coord with the matrix passed BY VALUE (*m) gives the target's VMX128
 * register numbering; the unaligned load is the explicit lvlx(p,0) | vsldoi(lvrx(p,12),4) form.
 */
#include "af1_vector.h"

#ifdef _MSC_VER
__vector4 __vsldoi(__vector4 a, __vector4 b, int sh);
#pragma intrinsic(__vsldoi)
#else
static __vector4 __vsldoi(__vector4 a, __vector4 b, int sh) { (void)b; (void)sh; return a; }
#endif

typedef struct Q5sXfF3 {
    float x, y, z;
} Q5sXfF3;

void ts4_vec3_transform_coord_inplace_881A40F0(Q5sXfF3 *p, const Af1Mat *m)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    __vector4 v, r;
    hi = __vsldoi(hi, hi, 4);
    v = __vor(lo, hi);
    r = af1_transform_coord(v, *m);
    __stvewx(__vspltw(r, 0), p, 0);
    __stvewx(__vspltw(r, 1), p, 4);
    __stvewx(__vspltw(r, 2), p, 8);
}
