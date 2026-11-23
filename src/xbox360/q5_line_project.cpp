/*
 * Q5: projection of a point onto a line, used by the move planner 0x886B8468 (Swing_DLL.xex 0x8826D3A0, 0x64),
 * C++ form.
 *
 * t = dot(p - line.point, line.dir) (line.dir is a unit vector, see src/xbox360/q5_line_init.c);
 * *out = line.point + line.dir * t; *t_out = t.
 *
 * Codegen notes (cl 16.00.10224 PPC, /O2 /Oc): Q5Vec has a user-declared destructor, so the by-value copies are
 * real memory temporaries. The direction is copied first (`ld/ld/std/std` to the stack, read back with lvx),
 * which is why the dot product reads line.dir again; the point + dir * t of q5_extend is fused late into
 * `vor` + `vmaddfp128` and its second read of line.point is merged late (the gap at v55). Copying the direction
 * after the dot product, or writing the result straight to *out, gives an early `vmaddfp` on v0/v12/v13.
 */
#include "vx1_vector.h"

struct Q5Vec {
    __vector4 v;
    Q5Vec() {}
    ~Q5Vec() {}
};

struct Q5Line {
    Q5Vec point;            /* +0x00 */
    Q5Vec dir;              /* +0x10 unit direction */
};

/* *o = *a + d * t */
static inline void q5_advance_to(Q5Vec *o, const Q5Vec *a, __vector4 d, float t)
{
    __vector4 l = __vmulfp(d, __vspltw(__lvlx(&t, 0), 0));
    o->v = a->v;
    o->v = __vaddfp(o->v, l);
}

/* *from + d * t, by value */
static inline Q5Vec q5_extend(const Q5Vec *from, Q5Vec d, float t)
{
    Q5Vec r;
    q5_advance_to(&r, from, d.v, t);
    return r;
}

/* 0x8826D3A0: closest point on the line to p, and its parameter t along the line */
extern "C" void ts4_line_closest_point_8826D3A0(const Q5Vec *p, const Q5Line *line, Q5Vec *out, float *t_out)
{
    Q5Vec dir = line->dir;
    __vector4 s = __vmsum3fp(__vsubfp(p->v, line->point.v), line->dir.v);
    float t = s.v[0];
    Q5Vec r = q5_extend(&line->point, dir, t);
    *t_out = t;
    out->v = r.v;
}
