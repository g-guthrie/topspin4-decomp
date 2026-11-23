/*
 * Q5: line (point + unit direction) set-up used by the move planner 0x886B8468 (Swing_DLL.xex 0x8826AC10, 0x54).
 *
 * out->point = *point; out->dir = normalised *dir (3-component, XMVector3Normalize: estimate plus one Newton
 * step, a zero-length vector is returned as its zero squared length).
 */
#include "vx1_vector.h"

typedef struct Q5Line {
    __vector4 point;                  /* +0x00 */
    __vector4 dir;                    /* +0x10 unit direction */
} Q5Line;

/* XMVector3Normalize as the library writes it: H is reused for the splat, 0.5 and the Newton term. */
static __inline __vector4 q5_normalize3(__vector4 v)
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

/* 0x8826AC10 */
void ts4_line_init_normalized_8826AC10(Q5Line *out, const __vector4 *point, const __vector4 *dir)
{
    out->point = *point;
    out->dir = *dir;
    {
        /* normalised in place through its own pointer: this keeps the first (dead) store of *dir and the
           `addi r11,r3,0x10` of the target; `out->dir = q5_normalize3(out->dir)` folds both away */
        __vector4 *d = &out->dir;
        *d = q5_normalize3(*d);
    }
}

/* 0x88189888: the line through two points, out->point = *from, out->dir = normalised (*to - *from) */
void ts4_line_init_two_points_88189888(Q5Line *out, const __vector4 *from, const __vector4 *to)
{
    out->point = *from;
    out->dir = __vsubfp(*to, *from);
    {
        __vector4 *d = &out->dir;
        *d = q5_normalize3(*d);
    }
}
