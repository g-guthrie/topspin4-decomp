/* NEAR MISS fn_88671B10 error-can-leave-court reach fan: size 0x664 vs target 0x620 (386 off), 21 relocs (same layout),
 * LTCG + pp1_pool_primer.c, /Oc. Behaviour fully decoded (see body). Remaining: the target keeps more vectors live in
 * registers (v43..v63, saved with __savevmx) where we spill to the stack, the q+dir*r madds use vmaddfp into the q copy
 * (ours vmaddcfp), and the 0x029EAAF4 test is emitted as subis/addi rather than lis/ori/subf. */
/* Swing_DLL.xex 0x88671B10: can an error on this shot leave the court? Tests the reach fan of the player
   (two arc edges at reach and max reach, plus a forward point) against the court target box. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
#include "../ts4_vector.h"
#ifdef _MSC_VER
#pragma intrinsic(__vrlimi, __vmaddfp, __vsubfp, __vmulfp, __vnmsubfp, __vpermwi, __vspltw)
#endif

extern char lbl_880FC690[];          /* forward direction vector */
float fn_8817B3F8(float x);          /* cos-like */
float fn_8817B500(float x);          /* sin-like */
void ts4_if_get_8865E730(__vector4 *v, ts4_u32 side_tag);
struct Ts4CourtBounds { float x_max; float z_min; float z_max; };
struct Ts4RfFlow { ts4_u8 pad_000[0x318]; ts4_u32 state; };
struct Ts4RfMatch { ts4_u8 pad_00[0x30]; struct Ts4RfFlow *flow; };
void ts4_court_bounds_8866E318(struct Ts4RfMatch *m, ts4_u8 serve, struct Ts4CourtBounds *b);

struct Ts4RfCourt { ts4_u8 pad_00[0xB0]; ts4_u32 style; };
struct Ts4RfLink { ts4_u8 pad_00[0x24]; struct Ts4RfCourt *court; };
struct Ts4RfState { ts4_u8 pad_000[0x7DC]; float reach_min; float reach_max; };
struct Ts4RfAnim { ts4_u8 pad_000[0x44C]; float arc_lo; float arc_hi; };
struct Ts4RfPC {
    ts4_u8 pad_00[0x48]; struct Ts4RfMatch *match; struct Ts4RfLink *link;
    ts4_u8 pad_50[0x24]; struct Ts4RfState *state; struct Ts4RfAnim *anim;
};

static const float kZero = 0.0f;
static __inline float rf_max(float a, float b) { return (a - b >= kZero) ? a : b; }
static __inline __vector4 rf_set_y0(__vector4 v) { return __vrlimi(v, __lvlx(&kZero, 0), 4, 3); }
static __inline __vector4 rf_splat(float f) { return __vspltw(__lvlx(&f, 0), 0); }
static __inline __vector4 rf_xz(float x, float z)
{
    __vector4 r;
    r.v[0] = x; r.v[1] = kZero; r.v[2] = z; r.v[3] = kZero;
    return r;
}
static __inline float rf_cross_y(__vector4 a, __vector4 b)
{
    __vector4 c = __vnmsubfp(__vpermwi(a, 135), __vpermwi(b, 99), __vmulfp(__vpermwi(a, 99), __vpermwi(b, 135)));
    return c.v[1];
}
static __inline float rf_dist_sq(const __vector4 *q, const __vector4 *c)
{
    float dx = q->v[0] - c->v[0];
    float dz = q->v[2] - c->v[2];
    return dz * dz + dx * dx;
}
static __inline ts4_u8 rf_inside(const __vector4 *p, const __vector4 *lo, const __vector4 *hi)
{
    return (ts4_u8)(p->v[0] < hi->v[0] && p->v[2] < hi->v[2] && p->v[0] > lo->v[0] && p->v[2] > lo->v[2]);
}

void ts4_error_can_leave_court_88671B10(const __vector4 *pos, struct Ts4RfPC *pc, ts4_u8 *b50, ts4_u8 *b51)
{
    struct Ts4CourtBounds bd;
    struct Ts4RfState *st;
    __vector4 q, dir_lo, dir_hi, c0, c1, c2, c3, p_lo_max, p_lo_reach, p_hi_max, p_hi_reach, p_fwd;
    __vector4 v_max, v_reach;
    float reach, reach_sq, rmax, rmax_sq, a_lo, a_hi, d0, d1, d2, d3;
    ts4_u8 set1, set2, all5;
    ts4_u8 point_end = pc->match->flow->state == 0x029EAAF4;
    if (point_end) {
        *b51 = 1;
        *b50 = 1;
        return;
    }
    st = pc->state;
    reach = st->reach_max;
    reach_sq = reach * reach;
    ts4_court_bounds_8866E318(pc->match, point_end, &bd);
    q = *pos;
    ts4_if_get_8865E730(&q, pc->link->court->style);
    rmax = rf_max(st->reach_max, st->reach_min);
    a_lo = pc->anim->arc_lo * 0.01745329238474369f;
    a_hi = pc->anim->arc_hi * 0.01745329238474369f;
    q = rf_set_y0(q);
    dir_lo = rf_xz(fn_8817B500(a_lo), fn_8817B3F8(a_lo));
    v_max = rf_splat(rmax);
    v_reach = rf_splat(reach);
    p_lo_max = __vmaddfp(dir_lo, v_max, q);
    p_lo_reach = __vmaddfp(dir_lo, v_reach, q);
    dir_hi = rf_xz(fn_8817B500(a_hi), fn_8817B3F8(a_hi));
    c0 = rf_xz(100.0f, bd.z_max);
    c1 = rf_xz(100.0f, bd.z_min);
    c2 = rf_xz(bd.x_max, bd.z_min);
    c3 = rf_xz(bd.x_max, bd.z_max);
    p_hi_max = __vmaddfp(dir_hi, v_max, q);
    p_hi_reach = __vmaddfp(dir_hi, v_reach, q);
    p_fwd = __vmaddfp(*(const __vector4 *)lbl_880FC690, v_max, q);
    rmax_sq = rmax * rmax;
    d0 = rf_dist_sq(&q, &c0);
    d1 = rf_dist_sq(&q, &c1);
    d2 = rf_dist_sq(&q, &c2);
    d3 = rf_dist_sq(&q, &c3);
    {
        ts4_u8 far_edge = (d1 > rmax_sq && d0 > rmax_sq) ? 1 : 0;
        ts4_u8 near_in = (d2 < reach_sq && d3 < reach_sq) ? 1 : 0;
        ts4_u8 lo_side = (rf_cross_y(dir_lo, __vsubfp(c3, q)) > kZero) ? 1 : 0;
        ts4_u8 hi_side = (rf_cross_y(dir_hi, __vsubfp(c2, q)) < kZero) ? 1 : 0;
        if (far_edge || lo_side || hi_side)
            set1 = 1;
        else
            set1 = near_in ? 1 : 0;
    }
    {
        ts4_u8 near_all = (d2 < rmax_sq && d3 < rmax_sq) ? 1 : 0;
        ts4_u8 far_all = (d0 > reach_sq && d1 > reach_sq) ? 1 : 0;
        ts4_u8 lo_side = (rf_cross_y(dir_lo, __vsubfp(c0, q)) < kZero) ? 1 : 0;
        ts4_u8 hi_side = (rf_cross_y(dir_hi, __vsubfp(c1, q)) > kZero) ? 1 : 0;
        set2 = (near_all && far_all && lo_side && hi_side) ? 1 : 0;
    }
    {
        ts4_u8 i0 = rf_inside(&p_lo_max, &c1, &c3);
        ts4_u8 i1 = rf_inside(&p_lo_reach, &c1, &c3);
        ts4_u8 i2 = rf_inside(&p_hi_max, &c1, &c3);
        ts4_u8 i3 = rf_inside(&p_hi_reach, &c1, &c3);
        ts4_u8 i4 = rf_inside(&p_fwd, &c1, &c3);
        all5 = (i0 && i1 && i2 && i3 && i4) ? 1 : 0;
    }
    if (all5) {
        *b51 = 0;
        *b50 = 1;
        return;
    }
    if (set2 || !set1) {
        *b51 = 1;
        *b50 = 1;
        return;
    }
    *b50 = 0;
    *b51 = 1;
}
