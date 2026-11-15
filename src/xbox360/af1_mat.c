/* AF1: matrix/vector helpers of the gameplay range (rules in docs/agents/near-misses/AF1.md). */
#include "af1_vector.h"
#include "w6b_types.h"

extern const float g_ts4_script_constants[];

/* Matrix plus a fifth row (position), as interpolated by 0x8867D2B0. */
typedef struct Af1Xform {
    Af1Mat m;                   /* +0x00 */
    __vector4 v;                /* +0x40 */
} Af1Xform;

/* Swing_DLL.xex 0x8864E980 */
void ts4_transform_coord_8864E980(const __vector4 *v, const Af1Mat *m, __vector4 *out)
{
    *out = af1_transform_coord(*v, *m);
}

/* Swing_DLL.xex 0x8867D2B0 */
void ts4_xform_lerp_8867D2B0(Af1Xform *out, const Af1Xform *a, const Af1Xform *b, float t)
{
    af1_mat_lerp_rows(out->m.r, a->m.r, b->m.r, t);
    af1_vec_lerp_to(&out->v, &a->v, b->v, t);
}

/* Swing_DLL.xex 0x8864E908 */
void ts4_transform_coord_in_place_8864E908(__vector4 *v, const Af1Mat *m)
{
    *v = af1_transform_coord(*v, *m);
}

/* Unaligned float[3] load: lvlx/lvrx pair merged with vsldoi + vor. */
static __inline __vector4 af1_load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}

/* Swing_DLL.xex 0x8864E9F8 */
void ts4_transform_vec3_in_place_8864E9F8(float *v, const Af1Mat *m)
{
    __vector4 p = af1_load3(v);
    __vector4 r;
    p.v[3] = g_ts4_script_constants[0];
    r = af1_transform_coord(p, *m);
    __stvewx(__vspltw(r, 0), v, 0);
    __stvewx(__vspltw(r, 1), v, 4);
    __stvewx(__vspltw(r, 2), v, 8);
}

/* Swing_DLL.xex 0x8864E7F8 */
void ts4_mat_translation_8864E7F8(Af1Mat *m, float x, float y, float z)
{
    Af1Mat r = af1_mat_translation(x, y, z);
    af1_mat_set(m, &r);
}

/* Swing_DLL.xex 0x8864EFF0 */
void ts4_mat_translation_from_ptr_8864EFF0(Af1Mat *m, const float *p)
{
    Af1Mat r = af1_mat_translation(p[0], p[1], p[2]);
    af1_mat_set(m, &r);
}

/* Swing_DLL.xex 0x8864F050 */
void ts4_mat_translation_from_ptr_8864F050(Af1Mat *m, const float *p)
{
    Af1Mat r = af1_mat_translation(p[0], p[1], p[2]);
    af1_mat_set(m, &r);
}
