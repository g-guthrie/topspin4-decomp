/* VX1: point at `dist` from `base` in the ground plane, Swing_DLL.xex 0x8867D9A0.
 *
 * fn_881BD4B8(&a, &b, angle) fills two floats from an angle (sine/cosine pair; which is which is not
 * checked here). The result is {b*dist + base.x, 0, a*dist + base.z, 0}.
 *
 * Vector rules (VX1): a __vector4 local built lane by lane through .v[i] is stored as floats on the
 * stack and copied out with lvx128/stvx128; a __vector4 by-value argument is spilled to its home
 * slot (stvx128 v1 at the caller's r1+0x20) before its lanes are read with lfs. The target returns
 * the output pointer in r3 (`mr r3,r31`), so the function returns it. LTCG route: the plain checker
 * also matches but reports RENAME lbl_8814B440 -> vx1_zero_d9a0 (a static, compared by value only
 * under LTCG). */
#include "vx1_vector.h"

static const float vx1_zero_d9a0 = 0.0f;

void fn_881BD4B8(float *a, float *b, float angle);

__vector4 *ts4_polar_offset_xz_8867D9A0(__vector4 *out, __vector4 base, float dist, float angle)
{
    float a, b;
    __vector4 r;
    fn_881BD4B8(&a, &b, angle);
    r.v[0] = b * dist + base.v[0];
    r.v[1] = vx1_zero_d9a0;
    r.v[2] = a * dist + base.v[2];
    r.v[3] = vx1_zero_d9a0;
    *out = r;
    return out;
}
