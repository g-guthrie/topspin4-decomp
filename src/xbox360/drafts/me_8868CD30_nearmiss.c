/* NEAR MISS 0x8868CD30: 45 off (size 0xe0 vs 0xe8): target loads the flattened direction into a register before the anchor copy and builds the origin in place in its stack slot; 8 variants (ordering, inline flatten/normalize helpers). */
#include "vx1_vector.h"
extern float lbl_8814B440; /* 0.0f */
typedef struct Obj Obj;
void ts4_heading_vector_xz_88679900(Obj *self, const float *angle, __vector4 *out, float len);
typedef struct Tun { char p[0x8e0]; __vector4 anchor; } Tun;
typedef struct World { char p[0x74]; Tun *tun; } World;
struct Obj { void *vt; World *world; };
typedef struct Ray { __vector4 origin; __vector4 dir; } Ray;

/* 0x8868CD30: ground ray from the tuning anchor (y,w zeroed) along the heading for angle, direction normalised. */
void ts4_heading_ray_8868CD30(Obj *self, void *unused, const float *angle, Ray *out, float len)
{
    __vector4 d, a, o, h, lsq, e, half;
    __vector4 *dir;
    ts4_heading_vector_xz_88679900(self, angle, &h, len);
    d.v[0] = h.v[0];
    d.v[1] = lbl_8814B440;
    d.v[2] = h.v[2];
    d.v[3] = lbl_8814B440;
    a = self->world->tun->anchor;
    o.v[0] = a.v[0];
    o.v[1] = lbl_8814B440;
    o.v[2] = a.v[2];
    o.v[3] = lbl_8814B440;
    out->origin = o;
    dir = &out->dir;
    *dir = d;
    half = __vcfsx(__vspltisw(1), 1);
    lsq = __vmsum3fp(d, d);
    e = __vrsqrtefp(lsq);
    e = __vmaddfp(e, __vnmsubfp(__vmulfp(lsq, half), __vmulfp(e, e), half), e);
    *dir = __vsel(__vmulfp(d, e), lsq, __vcmpeqfp(lsq, __vspltisw(0)));
}
