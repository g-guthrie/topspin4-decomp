/* agentA2 (2026-11-18 tips pass): volatile reads of out->v[0] / v[2], named call args, named lane values: still 8 off (plain and LTCG); stack-slot sharing residue unchanged. */
/* NEAR MISS (8 off: the two lane-insert temporaries share the sine/cosine stack slots instead
 * of a separate slot at 0x58, which also flips two load orders). Tried struct/explicit temp forms.
 * 0x88679900: ground-plane heading vector: write {len, 0, 0, 0} to out, then
 * rotate it in the XZ plane by the given angle (x' = z*s + x*c, z' = z*c - x*s) using the
 * sine/cosine pair from fn_881BD4B8. The leading object argument is unused. */
#include "vx1_vector.h"
extern float lbl_8814B440;
void fn_881BD4B8(float *a, float *b, float angle);
typedef struct Obj Obj;
void ts4_heading_vector_xz_88679900(Obj *self, const float *angle, __vector4 *out, float len)
{
    float a, b;
    __vector4 v;
    float x, z;
    v.v[0] = len;
    v.v[1] = lbl_8814B440;
    v.v[2] = lbl_8814B440;
    v.v[3] = lbl_8814B440;
    *out = v;
    fn_881BD4B8(&a, &b, *angle);
    x = out->v[0];
    z = out->v[2];
    v = vx1_set_z(vx1_set_x(v, z * a + x * b), z * b - x * a);
    *out = v;
}
