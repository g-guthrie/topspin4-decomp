/* NEAR MISS fn_88672130 push point out of rect margin: 6 off (same size 0x278, same 15 relocs), LTCG + pp1_pool_primer.c, /Oc.
 * Remaining: z (lfs 0x8(r4)) is loaded where the target loads half_x (lfs 0x20(r1), between the two std spills);
 * the target computes |x| - half_x before loading z. Declaring z with its initializer (z = p->v[2]) took it from 11 to 6;
 * by-value inline helpers, a hoisted half_x local, a block and a rect copy all left it unchanged.
 * nearmiss: 6 off; z load is scheduled ahead of half_x load. kZero as a literal 0.0f -> 153 off (body shrinks to 0x170);
 * z assigned after dx or scoped in a block -> 11 off; hoisted half_x local -> 6 (2026-11-24). */
/* Swing_DLL.xex 0x88672130: push a point that is just inside the margin of a rectangle out along its nearer edge. */
typedef unsigned char ts4_u8;
#include "../ts4_vector.h"
#ifdef _MSC_VER
#pragma intrinsic(__vrlimi)
double fabs(double x);
#pragma intrinsic(fabs)
#endif

extern const float g_ts4_script_constants[];
#define CL_K(off) g_ts4_script_constants[(off) / 4]

struct Ts4ClRect { float half_x; float near_z; float far_z; float pad; };

static const float kZero = 0.0f;
static __inline float cl_max(float a, float b) { return (a - b >= kZero) ? a : b; }
static __inline float cl_min(float a, float b) { return (a - b >= kZero) ? b : a; }
static __inline __vector4 cl_set_x(__vector4 v, float f) { return __vrlimi(v, __lvlx(&f, 0), 8, 0); }
static __inline __vector4 cl_set_z(__vector4 v, float f) { return __vrlimi(v, __lvlx(&f, 0), 2, 2); }

void ts4_push_out_of_rect_margin_88672130(__vector4 *out, const __vector4 *p, struct Ts4ClRect r)
{
    __vector4 v = *p;
    float ax = p->v[0];
    float dx, dz, z = p->v[2];
    if (ax < kZero)
        ax = -ax;
    dx = ax - r.half_x;
    if (z >= kZero)
        dz = z - r.far_z;
    else
        dz = r.near_z - z;
    {
        ts4_u8 far_out = (dx > 3.0f || dz > 3.0f) ? 1 : 0;
        if (far_out) {
            *out = v;
            return;
        }
    }
    if ((float)fabs(dx) < (float)fabs(dz)) {
        if (v.v[0] > kZero)
            { *out = cl_set_x(v, cl_min(cl_max(v.v[0], r.half_x + 3.0f), 100000.0f)); return; }
        { *out = cl_set_x(v, cl_min(cl_max(v.v[0], -r.half_x - 3.0f), 100000.0f)); return; }
    }
    if (v.v[2] > kZero)
        { *out = cl_set_z(v, cl_min(cl_max(v.v[2], r.far_z + 3.0f), 100000.0f)); return; }
    *out = cl_set_z(v, cl_min(cl_max(v.v[2], -100000.0f), r.near_z - 3.0f));
}
