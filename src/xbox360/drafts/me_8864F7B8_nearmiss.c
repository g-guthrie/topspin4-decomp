/* NEAR MISS fn_8864F7B8 rotate about axis: 14 off (same size), LTCG + pp1_pool_primer.c, /Oc.
 * Remaining: VMX32 register numbering in the TransformCoord chain (open in matching-tips, AF1 notes). */
/* Swing_DLL.xex 0x8864F7B8: rotate *v about *axis by angle (axis-angle quaternion -> matrix -> TransformCoord). */
#include "../af1_vector.h"

struct Ts4Float3 { float x, y, z; };
void fn_8825D450(__vector4 *q, const struct Ts4Float3 *axis, float angle);   /* quaternion from axis-angle */
void fn_8864E310(__vector4 *m, const __vector4 *q);                          /* matrix from quaternion */

void ts4_rotate_about_axis_8864F7B8(__vector4 *v, const __vector4 *axis, float angle)
{
    struct Ts4Float3 a;
    __vector4 q;
    Af1Mat m;
    __vector4 ax = *axis;
    __stvewx(__vspltw(ax, 0), &a, 0);
    __stvewx(__vspltw(ax, 1), &a, 4);
    __stvewx(__vspltw(ax, 2), &a, 8);
    fn_8825D450(&q, &a, angle);
    fn_8864E310(m.r, &q);
    *v = af1_transform_coord(*v, m);
}
