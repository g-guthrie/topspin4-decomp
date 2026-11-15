/* NEAR MISS draft (not built, not counted): 7 off, vector register numbering only (target keeps v63 for the splat and loads the axis into v61; ours reuses v63). */
#include "vx1_vector.h"
typedef struct Line { __vector4 point; __vector4 dir; } Line;
typedef struct L3 { char p[0xb0]; int fb0; } L3;
typedef struct L2 { char p[0x24]; L3 *f24; } L2;
typedef struct Ctx { char p[0x4c]; L2 *f4c; } Ctx;
typedef struct Self { char p[0x10]; Line line; Ctx *f30; } Self;
extern const __vector4 lbl_880FC6B0;
int fn_881896F8(const Line *a, const Line *b, __vector4 *point, float *t1, float *t2);
/* XMVector3Normalize as the library writes it: H is reused for the splat, 0.5 and the Newton term. */
static __inline __vector4 normalize3(__vector4 v)
{
    __vector4 d, rsq, rcp, rt, res, zero, sel, h;
    d = __vmsum3fp(v, v);
    h = __vspltisw(1);
    zero = __vspltisw(0);
    h = __vcfsx(h, 1);
    rcp = __vrsqrtefp(d);
    rt = __vmulfp(d, h);
    rsq = __vmulfp(rcp, rcp);
    h = __vnmsubfp(rt, rsq, h);
    rcp = __vmaddfp(rcp, h, rcp);
    sel = __vcmpeqfp(d, zero);
    res = __vmulfp(v, rcp);
    return __vsel(res, d, sel);
}
float f(Self *s, __vector4 a)
{
    Line probe;
    __vector4 hit;
    float t1, t2, d;
    probe.point = a;
    { __vector4 ax = lbl_880FC6B0; probe.dir = normalize3(ax); }
    fn_881896F8(&s->line, &probe, &hit, &t1, &t2);
    d = hit.v[2] - a.v[2];
    if (s->f30->f4c->f24->fb0 == (int)0xA2EDA1E7) d = -d;
    return d;
}
