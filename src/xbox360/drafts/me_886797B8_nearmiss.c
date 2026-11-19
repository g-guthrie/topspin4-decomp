/* NEAR MISS 0x886797B8: 2 off (LTCG): target reuses the zero result in r3 (mr r11,r3) for the two selects; we emit li r11,0. 8 + 6 res-copy variants (if/else from res, ?: orientations, float temps) all stay at 2.  ME sweep (+4): inline near_parallel(d, res), >= cast, ==res, init-1-then-if: all worse (27). */
#include "vx1_vector.h"
extern double fabs(double);
#pragma intrinsic(fabs)
extern const float g_ts4_event_value; /* 0.0f */

typedef struct Ray { Vx1Vec origin; Vx1Vec dir; } Ray;

static __inline unsigned char equal3(__vector4 v, __vector4 w)
{
    unsigned int cr;
    __vcmpeqfpR(__vpermwi(v, 24), __vpermwi(w, 24), &cr);
    return (cr & 0x80) == 0x80;
}

static __inline __vector4 normalize3(__vector4 v)
{
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 lsq = __vmsum3fp(v, v);
    __vector4 e = __vrsqrtefp(lsq);
    e = __vmaddfp(e, __vnmsubfp(__vmulfp(lsq, half), __vmulfp(e, e), half), e);
    return __vsel(__vmulfp(v, e), lsq, __vcmpeqfp(lsq, __vspltisw(0)));
}

static __inline __vector4 cross3(__vector4 a, __vector4 b)
{
    return __vnmsubfp(__vpermwi(a, 135), __vpermwi(b, 99), __vmulfp(__vpermwi(a, 99), __vpermwi(b, 135)));
}

/* 0x886797B8: true when the step turns to the left of the ray direction (cross(dir, step).y < 0);
   false for a zero direction, a zero step, or a step (anti)parallel to the direction. */
unsigned char ts4_ray_step_turns_left_886797B8(const Ray *ray, __vector4 step)
{
    __vector4 zero = __vspltisw(0);
    __vector4 dir = ray->dir.v;
    unsigned char res = 0;
    unsigned char degenerate;
    if (equal3(dir, zero) == 1 || equal3(step, zero) == 1) {
        degenerate = 1;
    } else {
        Vx1Vec d = ray->dir;
        __vector4 dot = __vmsum3fp(normalize3(d.v), normalize3(step));
        degenerate = !((float)fabs(dot.v[0]) < 0.99999f) ? 1 : res;
    }
    if (!degenerate) {
        __vector4 cr = cross3(dir, step);
        res = cr.v[1] < g_ts4_event_value ? 1 : res;
    }
    return res;
}
