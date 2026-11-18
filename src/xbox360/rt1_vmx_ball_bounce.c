/*
 * RT1: ball bounce response (docs/gameplay/ball-physics.md s6; models
 * src/xbox360/drafts/gp4_ball_flight.c gp4_bounce, gp4b_ball_model.c).
 *
 * v (incoming velocity, local frame, m/s) is reflected (v.y = -v.y); the tilt axis is v x up
 * unless v is zero or (nearly) vertical, else (0, 0, 1); theta = atan2(v.y, v.x) folded to
 * <= pi/2; the template curves give the speed loss and spin decay (of spin_a), the yaw kick (of
 * spin_b) and the outgoing elevation (of theta); v is scaled by 1 - loss, rotated by
 * wrap(out - theta) * |5 spin_a| about the axis and by the yaw kick about up; the spins decay
 * (side spins cleared for no_sidespin balls); arc 2 starts at pos with velocity v and the drift
 * is rebuilt by fn_889C0DC0(ball, 0).
 *
 * Verdict: compiling, unverified. VMX128 (vector compare, two inlined normalises, cross product,
 * splat-scale) means tools/fn_equiv.py reports UNCHECKED (vmx). See work/army/RT1.failed.md.
 */
#include "rt1_types.h"

extern const __vector4 lbl_88001AF0;          /* up (0, 1, 0, 0) */
extern const __vector4 lbl_880FC6B0;          /* fallback axis (0, 0, 1, 0) */
extern const float lbl_880C88DC;              /* pi */
extern const float g_ts4_event_value;              /* 0.0f */
extern const float g_ts4_script_constants[];  /* +0 1.0, +0xE8 pi/2, +0x1E0 5.0, +0x490 0.99999 */
#define RT1_K(off) g_ts4_script_constants[(off) / 4]

double fn_88564BF8(double y, double x);       /* atan2 */
float ts4_range_lookup_881899D8(float x, const struct Rt1RangeList *list);
void fn_8817B608(float *angle);               /* wrap to [-pi, pi) */
void fn_8864F7B8(__vector4 *v, const __vector4 *axis, float angle); /* rotate v about axis */
void fn_889C0DC0(struct Rt1Ball *ball, ts4_bool keep);

#ifdef _MSC_VER
double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

static RT1_INLINE __vector4 rt1_normalize3(__vector4 v, __vector4 half, __vector4 zero)
{
    __vector4 len_sq = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(len_sq);
    __vector4 is_zero = __vcmpeqfp(len_sq, zero);
    __vector4 step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    r = __vmaddfp(r, step, r);
    return __vsel(__vmulfp(v, r), len_sq, is_zero);
}

/* XMVector3Equal: x, y, z all equal (vcmpeqfp. on the xyzx permutation, CR6 "all"). Callers test `!= 1`,
   which keeps the extrwi + cmplwi 1 of the target (LTCG route: 94 off, was 162). */
static RT1_INLINE ts4_bool rt1_equal3(__vector4 v, __vector4 w)
{
    unsigned int cr;
    __vcmpeqfpR(__vpermwi(v, 24), __vpermwi(w, 24), &cr);
    return (cr & 0x80) == 0x80;
}

/* Swing_DLL.xex 0x889C1C80 */
void ts4_ball_bounce_response_889C1C80(struct Rt1Ball *ball, struct Rt1Vec4 *vel)
{
    const struct Rt1BallTemplate *tmpl;
    float *spin;
    __vector4 v, up, axis, zero;
    ts4_bool tilt_about_cross = 0;
    float fzero, theta, spin_a, loss, decay, yaw, weight, delta, keep, scale;

    {
        float y = -vel->y;
        v = *(__vector4 *)vel;
        v = __vrlimi(v, __lvlx(&y, 0), 4, 3);
    }
    zero = __vspltisw(0);
    up = lbl_88001AF0;
    *(__vector4 *)vel = v;
    tmpl = ball->tmpl;
    axis = lbl_880FC6B0;
    spin = ball->spin;

    if (rt1_equal3(v, zero) != 1 && rt1_equal3(up, zero) != 1) {
        __vector4 half = __vcfsx(__vspltisw(1), 1);
        struct Rt1Vec4 copy = *vel;
        __vector4 dot = __vmsum3fp(rt1_normalize3(*(__vector4 *)&copy, half, zero), rt1_normalize3(up, half, zero));
        if (fabs(dot.v[0]) < RT1_K(0x490))
            tilt_about_cross = 1;
    }
    if (tilt_about_cross) {
        /* v x up */
        axis = __vnmsubfp(__vpermwi(v, 135), __vpermwi(up, 99), __vmulfp(__vpermwi(v, 99), __vpermwi(up, 135)));
    }

    theta = (float)fn_88564BF8(vel->y, vel->x);
    if (theta > RT1_K(0xE8))
        theta = lbl_880C88DC - theta;
    spin_a = spin[0];
    loss = ts4_range_lookup_881899D8(spin_a, &tmpl->speed_loss);
    decay = ts4_range_lookup_881899D8(spin_a, &tmpl->spin_decay);
    yaw = ts4_range_lookup_881899D8(spin[1], &tmpl->yaw_kick);
    delta = ts4_range_lookup_881899D8(theta, &tmpl->out_angle) - theta;
    weight = spin_a * RT1_K(0x1E0);
    fzero = g_ts4_event_value;
    weight = (weight < fzero) ? -weight : weight;
    fn_8817B608(&delta);

    scale = RT1_K(0) - loss;
    *(__vector4 *)vel = __vmulfp(*(__vector4 *)vel, __vspltw(__lvlx(&scale, 0), 0));
    fn_8864F7B8((__vector4 *)vel, &axis, delta * weight + theta - theta);
    fn_8864F7B8((__vector4 *)vel, &up, yaw);

    keep = RT1_K(0) - decay;
    spin[0] = keep * spin[0];
    spin[1] = keep * spin[1];
    if (!ball->no_sidespin) {
        spin[2] = keep * spin[2];
    } else {
        spin[2] = fzero;
        spin[1] = fzero;
    }
    ball->arc2_pos = ball->pos;
    ball->arc2_vel = *vel;
    fn_889C0DC0(ball, 0);
}
