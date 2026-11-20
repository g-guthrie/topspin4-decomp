/* NEAR MISS 0x88651E18: 66 off (0x114 vs 0x138, LTCG): the abs select stays a branch (target: mfcr/lfsx/fsel against g_ts4_event_value) and the float3 self-copy of d is missing. 8 variants. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
static const float kZero = 0.0f;

typedef struct Vec3 { float x, y, z; } Vec3;

static __inline __vector4 load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}

static __inline Vec3 to_vec3(__vector4 v)
{
    Vec3 r;
    __stvewx(__vspltw(v, 0), &r, 0);
    __stvewx(__vspltw(v, 1), &r, 4);
    __stvewx(__vspltw(v, 2), &r, 8);
    return r;
}

static __inline void store3(void *p, __vector4 v)
{
    __stvewx(__vspltw(v, 0), p, 0);
    __stvewx(__vspltw(v, 1), p, 4);
    __stvewx(__vspltw(v, 2), p, 8);
}

static __inline float absf_sel(float x)
{
    float r = (x >= kZero) ? x : -x;
    return r;
}

typedef struct Obb { char p[0x10]; const Vec3 *center; const Vec3 **axes; char q[8]; const float **extents; } Obb;

/* 0x88651E18: true when point p lies inside the oriented box (|dot(p - c, axis_i)| <= extent_i for i = 0..2). */
int ts4_obb_contains_88651E18(const Obb *b, const Vec3 *p)
{
    Vec3 d = to_vec3(__vsubfp(load3(p), load3(b->center)));
    unsigned int i;
    for (i = 0; i < 3; i++) {
        __vector4 dv = load3(&d);
        __vector4 dot = __vmsum3fp(dv, load3(b->axes[i]));
        if (absf_sel(dot.v[0]) > *b->extents[i])
            return 0;
    }
    return 1;
}
