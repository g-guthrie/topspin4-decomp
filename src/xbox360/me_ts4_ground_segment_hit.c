#include "vx1_vector.h"
extern float lbl_8814B440; /* 0.0f */
typedef struct Seg { __vector4 a; __vector4 b; } Seg;
typedef struct Shape Shape;
unsigned char fn_8826CB30(Shape *s, const Seg *seg, __vector4 *hit, float *t);

static __inline __vector4 v_flatten_xz(__vector4 v)
{
    __vector4 r;
    r.v[0] = v.v[0];
    r.v[1] = lbl_8814B440;
    r.v[2] = v.v[2];
    r.v[3] = lbl_8814B440;
    return r;
}

/* 0x886937F0: intersect the ground projection (y = 0) of segment a->b with the shape; on a hit at t >= 0 write the point. */
int ts4_ground_segment_hit_886937F0(__vector4 a, __vector4 b, Shape *s, __vector4 *out)
{
    Seg seg;
    __vector4 hit;
    float t;
    int found = 0;
    __vector4 fb = v_flatten_xz(b);
    __vector4 fa = v_flatten_xz(a);
    seg.a = fa;
    seg.b = fb;
    t = lbl_8814B440;
    if (fn_8826CB30(s, &seg, &hit, &t)) {
        float tt = t;
        if (!(*(unsigned short *)&tt & 0x8000)) {
            *out = hit;
            found = 1;
        }
    }
    return found;
}
