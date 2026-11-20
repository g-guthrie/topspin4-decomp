/* NEAR MISS 0x8868CBF0: 60 off (0x130 vs 0x13c), LTCG with context src/xbox360/drafts/me_886797B8_nearmiss.c (callee near-miss, 2 off; removes the v127 save). Left: stack slot order (target temp 0x60, t 0x50, ray 0x70) and the t round trip. 8 variants. */
#include "vx1_vector.h"
extern const float g_ts4_event_value;
#define lbl_8814B440 g_ts4_event_value /* 0.0f */
typedef struct Ray { __vector4 origin; __vector4 dir; } Ray;
unsigned char ts4_ray_step_turns_left_886797B8(const Ray *ray, __vector4 delta);

static __inline __vector4 v_flatten_xz(__vector4 v)
{
    __vector4 r;
    r.v[0] = v.v[0];
    r.v[1] = lbl_8814B440;
    r.v[2] = v.v[2];
    r.v[3] = lbl_8814B440;
    return r;
}

static __inline __vector4 v3_normalize_safe(__vector4 v)
{
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 lsq = __vmsum3fp(v, v);
    __vector4 e = __vrsqrtefp(lsq);
    e = __vmaddfp(e, __vnmsubfp(__vmulfp(lsq, half), __vmulfp(e, e), half), e);
    return __vsel(__vmulfp(v, e), lsq, __vcmpeqfp(lsq, __vspltisw(0)));
}

/* 0x8868CBF0: project the point onto the ground line a->b (y = 0); if the ray test accepts the step, move the point there. */
void ts4_snap_to_ground_line_8868CBF0(__vector4 *pt, __vector4 a, __vector4 b)
{
    __vector4 fb = v_flatten_xz(b);
    __vector4 fa = v_flatten_xz(a);
    __vector4 p = v_flatten_xz(*pt);
    Ray ray;
    float t;
    __vector4 q, dt;
    ray.origin = fa;
    ray.dir = v3_normalize_safe(__vsubfp(fb, fa));
    dt = __vmsum3fp(__vsubfp(p, fa), ray.dir);
    t = dt.v[0];
    q = __vmaddfp(ray.dir, vx1_replicate(t), fa);
    if (ts4_ray_step_turns_left_886797B8(&ray, __vsubfp(q, *pt)))
        *pt = q;
}
