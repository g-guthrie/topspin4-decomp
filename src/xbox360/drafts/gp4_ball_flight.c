/*
 * GP4 draft: Top Spin 4 ball flight stepper (the game's OWN ball integrator, no Havok involved).
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 *
 * Reconstructed from machine code (VMX128 + scalar FP). Original functions:
 *   fn_889C2818 step entry                fn_889C1F70 per-tick step (0x704)       fn_889C1C80 ground bounce
 *   fn_889C19F0 / fn_889C1AF8 / fn_889C2678 launch                                 fn_889C0C70 mode -> flags
 *   fn_889C1868 spin-curve blend          fn_889C0DC0 spin acceleration vector     fn_889C1160/fn_889C0FE8 frame change
 *   fn_888AAEA8 / fn_888AAE00 closed-form coefficients                             ts4_bm_ball_arc1_position_888AB558 arc-1 position
 *   ts4_bm_ball_arc2_position_888AD1C8 arc-2 position            ts4_bm_ball_launch_velocity_888AB220 / fn_888AB0E0 arc-1 velocity at start / end
 *   fn_888AAB98 arrival speed^2           fn_888AB8D0 .. shot "kind" solvers (flight time bisection)
 *
 * Status: DRAFT (not compiled into the matching build). Formulas for the position/velocity closed forms were
 * extracted with a symbolic executor over the scalar instructions (reproducible: scratch symex.py in GP4 notes) so
 * they are exact up to float evaluation order; the vector parts (spin accel, bounce rotation, net) were read by hand.
 * Marks:  [H] read directly   [M] consistent but one detail inferred   a trailing "?" marker = uncertain.
 *
 * Coordinate system inside the stepper (after gp4_to_local): x = along the court (net plane is x = 0),
 * y = up (ground y = 0 for the ball bottom), z = across the court; metres, seconds; origin = ball.origin(+0x70).
 * Outside (world frame): centimetres; the stepper converts with lbl_88D46390 = 0.01 and lbl_88D463A0 = 100.
 *
 * PHYSICAL MODEL (per tick, exact closed form, NOT a numerical ODE):
 *     v' = -k (v - W) - g * yhat          k = T / a4   (1/s, "drag rate")
 *     W  = A / T                          A = drift vector ball+0x80 (spin acceleration, see gp4_spin_accel)
 *     g  = ball+0x4D8                     a4 = ball+0x4D4   T = ball+0x08 (= shot template +0x54)
 *  arc 1 (from launch until the first bounce): boundary value problem  p(0)=P0 (from), p(tau)=(P1.x, 0, P1.z) (to, ground),
 *      p(t) = P0 + (P1 - P0 - Weff*tau) * (1 - e^{-k t}) / (1 - e^{-k tau}) + Weff * t       Weff = W - (0, g/k, 0), P1.y = 0
 *  arc 2 (after every bounce / net hit): initial value problem p(0)=arc2_pos, v(0)=arc2_vel
 *      p(t) = p0 + (v0 - Weff) * (1 - e^{-k t}) / k + Weff * t
 *  t = (tick - tick_prev) / 60.
 */
#include <math.h>
#include "../gp4_types.h"

#define BF(b, o) (*(float *)((char *)(b) + (o)))
#define BI(b, o) (*(int *)((char *)(b) + (o)))
#define BU(b, o) (*(gp4_u32 *)((char *)(b) + (o)))
#define BB(b, o) (*(gp4_u8 *)((char *)(b) + (o)))
#define BV(b, o) ((float *)((char *)(b) + (o)))   /* vec4 */

/* pool constants (g_ts4_script_constants, 0x880D0F70): +0x00 = 1.0, +0x20 = 100.0, +0x38 = -1.0, +0xE8 = pi/2,
 * +0x10C = 0.2, +0x1BC = 0.01, +0x1E0 = 5.0, +0x490 = 0.99999, +0x784 = -1.19e-7 (ground epsilon), +0x184 = pi/180 */
static const float POOL_NET_RESTITUTION = 0.2f;      /* pool+0x10C */
static const float POOL_BOUNCE_AXIS_COS = 0.99999f;  /* pool+0x490 */
static const float POOL_SPIN_WEIGHT = 5.0f;          /* pool+0x1E0 */
static const float POOL_GROUND_EPS = -1.1920929e-7f; /* pool+0x784 */
static const float POOL_DEG2RAD = 0.017453292f;      /* pool+0x184 */
static const float POOL_HALF_PI = 1.5707964f;        /* pool+0xE8 */
static const float POOL_PI = 3.1415927f;             /* lbl_880C88DC */

typedef struct Gp4Curve Gp4Curve;
float gp4_curve16_eval(float x, const Gp4Curve *c);  /* fn_881899D8 */
float gp4_curve20_eval(float x, const Gp4Curve *c);  /* fn_8817A688 */
void  gp4_rotate_about_axis(float v[4], const float axis[4], float angle); /* fn_8864F7B8: v = R(axis, angle) v */
float gp4_wrap_angle(float a);                       /* fn_8817B608: wraps into (-pi, pi] */

/* ---- fn_889C1160 / fn_889C0FE8: world (cm, absolute) <-> local (m, relative) [H] ----
 * to_local:  v = (v - origin) * 0.01  for +0x40 (pos), +0x60 (pos_prev), +0x100 (p_from), +0x130 (arc2_pos)
 *            v = v * 0.01             for +0x110 (p_to), +0x140 (arc2_vel)        (no origin shift)
 * to_world:  inverse (v * 100 + origin / v * 100). Guarded by S->local_frame (+0x40) so it is idempotent.
 * (lbl_88D46390 = (0.01,0.01,0.01,0), lbl_88D463A0 = (100,100,100,0), both set up at start by ts4_copy_vec_const_then_call_889D22A8/ts4_copy_vec_const_then_call_889D22D0.)
 * fn_889C0F70 / fn_889C0EF8 apply only the scaling (no origin) to the launch command vectors +0x340 and +0x350,
 * guarded by S->launch_local_frame (+0x41). Note: the launch writes p_from/p_to straight from the scaled command vectors. */
void gp4_to_local(struct Gp4Stepper *S, void *B)      /* fn_889C1160 */
{
    float *origin = BV(B, 0x70);
    static const int shifted[4] = {0x40, 0x60, 0x100, 0x130};
    static const int scaled_only[2] = {0x110, 0x140};
    int i, k;
    if (S->local_frame) return;
    S->local_frame = 1;
    for (k = 0; k < 4; k++)
        for (i = 0; i < 3; i++) BV(B, shifted[k])[i] = (BV(B, shifted[k])[i] - origin[i]) * 0.01f;
    for (k = 0; k < 2; k++)
        for (i = 0; i < 3; i++) BV(B, scaled_only[k])[i] *= 0.01f;
}
/* fn_889C0FE8 does the inverse with *100 and + origin. fn_889C0F70/fn_889C0EF8 do the same for the 0x340/0x350 command vectors. */

/* ---- fn_888AAEA8 [H]: closed-form constants ---- */
void gp4_arc_constants(void *B)
{
    float T = BF(B, 0x08), a4 = BF(B, 0x4D4), g = BF(B, 0x4D8), tau = BF(B, 0x00);
    (void)tau;
    BF(B, 0x154) = 1.0f / a4;
    BF(B, 0x150) = 1.0f / T;
    BF(B, 0x158) = BF(B, 0x154) * T;            /* k = T / a4 */
    BF(B, 0x15C) = g * a4;
    BF(B, 0x160) = BF(B, 0x150) * BF(B, 0x150); /* 1/T^2 */
    BF(B, 0x164) = a4 * a4;
    BF(B, 0x168) = T * T;
    BF(B, 0x16C) = BV(B, 0x100)[0] * T;         /* P0.x * T */
    BF(B, 0x170) = BV(B, 0x110)[0] * T;         /* P1.x * T */
    BF(B, 0x174) = BV(B, 0x100)[1] * T;         /* P0.y * T */
    BF(B, 0x178) = BV(B, 0x100)[2] * T;         /* P0.z * T */
    BF(B, 0x17C) = BV(B, 0x110)[2] * T;         /* P1.z * T */
}

/* ---- fn_888AAE00 [H]: needs tau = ball+0x00 ---- */
void gp4_arc_end_constants(void *B)
{
    float tau = BF(B, 0x00), E = expf(-(BF(B, 0x158) * tau));
    const float *A = BV(B, 0x80);
    BF(B, 0x180) = E;
    BF(B, 0x184) = 1.0f / (E - 1.0f);
    BF(B, 0x188) = tau * A[0];
    BF(B, 0x18C) = tau * A[1];
    BF(B, 0x190) = tau * A[2];
    BF(B, 0x194) = BF(B, 0x15C) * tau;
}

/* ---- ts4_bm_ball_arc1_position_888AB558 [H]: arc-1 position at t = (tick - tick_prev) * dt, written to ball+0x40 ---- */
void gp4_arc1_position(const struct Gp4Generator *G, void *B)
{
    float t = (float)(BI(B, 0x18) - BI(B, 0x1C)) * G->seconds_per_tick;
    float e = expf(-(BF(B, 0x158) * t));
    const float *A = BV(B, 0x80);
    float s = BF(B, 0x150), E = BF(B, 0x180), r = BF(B, 0x184);
    float *pos = BV(B, 0x40);
    pos[0] = (((E * BF(B, 0x16C) + (BF(B, 0x188) - BF(B, 0x170))) - ((BF(B, 0x16C) + BF(B, 0x188)) - BF(B, 0x170)) * e) * r
              + A[0] * t) * s;
    pos[1] = ((BF(B, 0x174) * E + (BF(B, 0x18C) - BF(B, 0x194))) * r) * s
             + (A[1] * (s * t) - ((((BF(B, 0x18C) + BF(B, 0x174)) - BF(B, 0x194)) * r) * s) * e - BF(B, 0x15C) * (s * t));
    pos[2] = (((BF(B, 0x178) * E + (BF(B, 0x190) - BF(B, 0x17C))) - ((BF(B, 0x178) + BF(B, 0x190)) - BF(B, 0x17C)) * e) * r
              + A[2] * t) * s;
    pos[3] = 0.0f;
}

/* ---- ts4_bm_ball_arc2_position_888AD1C8 [H]: arc-2 position (start state ball+0x130 pos, ball+0x140 vel), written to ball+0x40 ---- */
void gp4_arc2_position(const struct Gp4Generator *G, void *B)
{
    float t = (float)(BI(B, 0x18) - BI(B, 0x1C)) * G->seconds_per_tick;
    float e = expf(-(BF(B, 0x158) * t));
    const float *A = BV(B, 0x80), *p0 = BV(B, 0x130), *v0 = BV(B, 0x140);
    float T = BF(B, 0x08), a4 = BF(B, 0x4D4), g = BF(B, 0x4D8);
    float s = BF(B, 0x150), inv_t2 = BF(B, 0x160), T2 = BF(B, 0x168), ga4 = BF(B, 0x15C), a4sq = BF(B, 0x164);
    float *pos = BV(B, 0x40);
    pos[0] = (((v0[0] * T) * a4 + (T2 * p0[0] - A[0] * a4)) - (((v0[0] * T) - A[0]) * e) * a4) * inv_t2 + A[0] * (s * t);
    pos[1] = (a4sq * g + (((v0[1] * T) * a4 + (T2 * p0[1])) - A[1] * a4)) * inv_t2
             + (A[1] * (s * t) - ((((ga4 + (v0[1] * T)) - A[1]) * inv_t2) * e) * a4 - ga4 * (s * t));
    pos[2] = (((v0[2] * T) * a4 + (T2 * p0[2] - A[2] * a4)) - (((v0[2] * T) - A[2]) * e) * a4) * inv_t2 + A[2] * (s * t);
    pos[3] = 0.0f;
}

/* ---- ts4_bm_ball_launch_velocity_888AB220 [H]: arc-1 velocity at t = 0 (stored in ball+0x500 at launch) ---- */
void gp4_arc1_velocity_start(const void *B, float out[4])
{
    const float *A = BV((void *)B, 0x80), *P0 = BV((void *)B, 0x100), *P1 = BV((void *)B, 0x110);
    float T = BF(B, 0x08), tau = BF(B, 0x00), r = BF(B, 0x184), ia4 = BF(B, 0x154), s = BF(B, 0x150);
    out[0] = (((P0[0] - P1[0]) * T + (A[0] * tau)) * r) * ia4 + s * A[0];
    out[1] = ((((A[1] - BF(B, 0x15C)) * tau) + (P0[1] * T)) * r) * ia4 + (A[1] - BF(B, 0x15C)) * s;
    out[2] = (((P0[2] - P1[2]) * T + (A[2] * tau)) * r) * ia4 + s * A[2];
    out[3] = 0.0f;
}

/* ---- fn_888AB0E0 [H]: arc-1 velocity at t = tau (arrival speed, ball+0x510; also the incoming velocity of the first bounce) ---- */
void gp4_arc1_velocity_end(const void *B, float out[4])
{
    const float *A = BV((void *)B, 0x80), *P0 = BV((void *)B, 0x100), *P1 = BV((void *)B, 0x110);
    float T = BF(B, 0x08), tau = BF(B, 0x00), ia4 = BF(B, 0x154), s = BF(B, 0x150);
    float E = expf(-((ia4 * T) * tau));
    float c = (E * ia4) * (1.0f / (E - 1.0f));
    out[0] = ((((P0[0] * T + A[0] * tau) - P1[0] * T) * c)) + A[0] * s;
    out[1] = (A[1] * s - ((((BF(B, 0x15C) * tau - (P0[1] * T + A[1] * tau)) * c)))) - BF(B, 0x15C) * s;
    out[2] = ((((P0[2] * T + A[2] * tau) - P1[2] * T) * c)) + A[2] * s;
    out[3] = 0.0f;
}

/* ---- fn_889C0C70 [H]: ball mode -> net-interaction flags (only while bounce_count == 0; after the first bounce all three = {1,1,0}) ----
 * flag31 = "check the net plane crossing"   flag32 = "net is solid (hit)"   flag33 = "let: net-cord deflection" */
void gp4_mode_flags(void *B, gp4_u32 mode)
{
    gp4_u8 *f31 = &BB(B, 0x31), *f32 = &BB(B, 0x32), *f33 = &BB(B, 0x33);
    if (BI(B, 0x14) != 0) { *f33 = 0; *f32 = 1; *f31 = 1; return; }
    if (mode == GP4_HASH_WOOD || mode == GP4_HASH_NET) { *f33 = 0; *f32 = 1; *f31 = 1; return; }
    if (mode == GP4_HASH_LET_IN || mode == GP4_HASH_LET_OUT) { *f33 = 1; *f32 = 0; *f31 = 1; return; }
    if (mode == GP4_HASH_MODE_LIVE_A || mode == GP4_HASH_MODE_LIVE_B) { *f31 = *f32 = *f33 = 0; return; }
    if (mode == GP4_HASH_OUT || mode == GP4_HASH_MODE_CA68AAEC) {
        /* net only matters when launch and target are on the same side of x = 0 */
        int same_side = (BF(B, 0x110) * BF(B, 0x100)) > 0.0f;
        *f33 = 0;
        if (same_side) { *f32 = 1; *f31 = 1; } else { *f31 = 0; *f32 = 0; }
        return;
    }
    /* other modes: flags unchanged */
}

/* ---- fn_889C1868 [H]: blend three template spin curves into ball+0x90..0x98 ----
 * template row tpl (ball+0x24): +0x18 -> self-relative pair node A {rel,type,rel,type}, +0x24 -> pair B, +0x30 -> pair C (each 0xC apart)
 * each half is either a 1-D curve (type 0xF9F12A60, evaluated at x = ball+0x344) or a plain float.
 *   spin_a(+0x90) = lerp(A0, A1, blend)   spin_c(+0x98) = lerp(B0, B1, blend)   spin_b(+0x94) = lerp(C0, C1, blend)   blend = ball+0x364 */
void gp4_spin_blend(void *B, float blend, float (*half)(const void *B, int pair, int which))
{
    float x = BF(B, 0x344);
    float a0 = half(B, 0, 0), a1 = half(B, 0, 1), b0 = half(B, 1, 0), b1 = half(B, 1, 1), c0 = half(B, 2, 0), c1 = half(B, 2, 1);
    (void)x;
    BF(B, 0x90) = (a1 - a0) * blend + a0;
    BF(B, 0x94) = (c1 - c0) * blend + c0;
    BF(B, 0x98) = (b1 - b0) * blend + b0;
    /* then gp4_spin_accel(B, 1) */
}

static void cross3(const float a[4], const float b[4], float r[4])
{
    r[0] = a[1] * b[2] - a[2] * b[1];
    r[1] = a[2] * b[0] - a[0] * b[2];
    r[2] = a[0] * b[1] - a[1] * b[0];
    r[3] = 0.0f;
}

/* ---- fn_889C0DC0 [H structure, M sign convention]: drift / spin-acceleration vector A = ball+0x80 ----
 * dir = (flag ? p_from - p_to : ball+0x140 velocity), normalised (unchanged if zero; returns early if dir == 0)
 * c1 = dir x up      (horizontal "left" vector (-u.z, 0, u.x))
 * c2 = c1 x dir      (vertical-ish: (-u.x u.y, u.x^2+u.z^2, -u.z u.y))
 * A  = dir * spin_c + c1 * (spin_b * sgn) + c2 * spin_a        sgn = ball+0x368 ? -1 : +1 (handedness / FH-BH side) */
void gp4_spin_accel(void *B, int use_endpoints)
{
    float d[4], u[4], c1[4], c2[4], up[4] = {0.0f, 1.0f, 0.0f, 0.0f}, len2;
    float sgn = BB(B, 0x368) ? -1.0f : 1.0f;
    float *A = BV(B, 0x80);
    int i;
    if (use_endpoints == 1) { for (i = 0; i < 3; i++) d[i] = BV(B, 0x100)[i] - BV(B, 0x110)[i]; }
    else { for (i = 0; i < 3; i++) d[i] = BV(B, 0x140)[i]; }
    d[3] = 0.0f;
    if (d[0] == 0.0f && d[1] == 0.0f && d[2] == 0.0f) return;
    len2 = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
    for (i = 0; i < 3; i++) u[i] = d[i] / sqrtf(len2);
    u[3] = 0.0f;
    cross3(u, up, c1);
    cross3(c1, u, c2);
    for (i = 0; i < 3; i++)
        A[i] = u[i] * BF(B, 0x98) + c1[i] * (BF(B, 0x94) * sgn) + c2[i] * BF(B, 0x90);
    A[3] = 0.0f;
}

/* ---- fn_889C1C80 [H structure]: ground bounce response. v = incoming velocity (local frame, m/s); outgoing velocity written back in v.
 * Template row curves (each a 16-byte-key piecewise linear table, fn_881899D8):
 *   tpl+0x40  speed loss as function of spin_a        (v *= 1 - c40(spin_a))
 *   tpl+0x58  outgoing elevation angle as function of incoming elevation angle theta
 *   tpl+0x64  yaw kick (radians) as function of spin_b
 *   tpl+0x4C  spin decay as function of spin_a        (spin *= 1 - c4C(spin_a))
 */
void gp4_bounce(const struct Gp4Stepper *S, void *B, float v[4], const Gp4Curve *tpl40, const Gp4Curve *tpl4c,
                const Gp4Curve *tpl58, const Gp4Curve *tpl64)
{
    float axis[4] = {0.0f, 0.0f, 1.0f, 0.0f}, up[4] = {0.0f, 1.0f, 0.0f, 0.0f};
    float *spin = BV(B, 0x90);
    float theta, sf, w, delta, decay;
    (void)S;
    v[1] = -v[1];                                           /* reflect the vertical component */
    if (!(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)) {
        float len = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        float cosang = (v[1] / len);                        /* dot(v/|v|, up) */
        if (fabsf(cosang) < POOL_BOUNCE_AXIS_COS) cross3(v, up, axis);   /* axis for the elevation tilt */
    }
    theta = atan2f(v[1], v[0]);                             /* fn_88564BF8(y, x) */
    if (theta > POOL_HALF_PI) theta = POOL_PI - theta;      /* fold: elevation measured away from +x or -x alike */
    sf = 1.0f - gp4_curve16_eval(spin[0], tpl40);
    w = fabsf(spin[0] * POOL_SPIN_WEIGHT);
    delta = gp4_wrap_angle(gp4_curve16_eval(theta, tpl58) - theta);
    {
        float yaw = gp4_curve16_eval(spin[1], tpl64);
        v[0] *= sf; v[1] *= sf; v[2] *= sf;
        gp4_rotate_about_axis(v, axis, delta * w);          /* tilt toward the template's outgoing elevation by weight |5*spin_a| */
        gp4_rotate_about_axis(v, up, yaw);                  /* yaw kick by side spin */
    }
    decay = 1.0f - gp4_curve16_eval(spin[0], tpl4c);
    spin[0] *= decay;
    spin[1] *= decay;
    if (!BB(B, 0x4E1)) spin[2] *= decay; else { spin[2] = 0.0f; spin[1] = 0.0f; }
    /* start of arc 2 */
    BV(B, 0x130)[0] = BV(B, 0x40)[0]; BV(B, 0x130)[1] = BV(B, 0x40)[1]; BV(B, 0x130)[2] = BV(B, 0x40)[2]; BV(B, 0x130)[3] = 0.0f;
    BV(B, 0x140)[0] = v[0]; BV(B, 0x140)[1] = v[1]; BV(B, 0x140)[2] = v[2]; BV(B, 0x140)[3] = 0.0f;
    gp4_spin_accel(B, 0);
}

/* ---- fn_889C1F70 [H]: per-tick step; B is in the LOCAL frame while this runs ----
 * Returns nothing; on exit ball.pos (+0x40) is the new position, ball.velocity_per_second (+0x4F0) = (pos - pos_prev) * 60. */
void gp4_step_tick(struct Gp4Stepper *S, void *B, void (*bounce)(struct Gp4Stepper *, void *, float *),
                   void (*net_cord)(struct Gp4Stepper *, void *))
{
    float *pos = BV(B, 0x40), *prev = BV(B, 0x60);
    gp4_u32 mode = BU(B, 0x2C);
    int is_let = (mode == GP4_HASH_LET_IN || mode == GP4_HASH_LET_OUT);
    int stepped = 0, i;
    gp4_to_local(S, B);
    for (i = 0; i < 4; i++) prev[i] = pos[i];

    if (BI(B, 0x28) > 0) {                         /* serve toss / hold: no physics, carried by hold_delta (+0xA0) */
        BI(B, 0x28) -= 1;
        for (i = 0; i < 4; i++) pos[i] += BV(B, 0xA0)[i];
        if (BI(B, 0x28) == 0 && BI(B, 0x14) > 0) BI(B, 0x1C) = BI(B, 0x18);
    } else {
        int no_bounce_yet = (BI(B, 0x14) == 0);
        int same_side_as_launch = (BF(B, 0x100) >= 0.0f) ? (pos[0] > 0.0f) : (pos[0] < 0.0f);
        /* generator selection */
        if (!is_let) { if (no_bounce_yet) gp4_arc1_position(S->g1, B); else gp4_arc2_position(S->g2, B); }
        else         { if (same_side_as_launch) gp4_arc1_position(S->g1, B); else gp4_arc2_position(S->g2, B); }

        /* bounce detection */
        {
            float dy = pos[1] - prev[1];
            int bounce_now;
            if (no_bounce_yet && !is_let) bounce_now = (BI(B, 0x18) >= BI(B, 0x04));          /* scheduled bounce tick */
            else bounce_now = !(dy > 0.0f) && pos[1] < POOL_GROUND_EPS;                      /* falling and below the ground */
            if (bounce_now) {
                float vin[4];
                if (no_bounce_yet && !is_let) gp4_arc1_velocity_end(B, vin);                 /* analytic arrival velocity */
                else for (i = 0; i < 3; i++) vin[i] = (pos[i] - prev[i]) * S->ticks_per_second;
                vin[3] = 0.0f;
                BI(B, 0x14) += 1;                                                            /* bounce_count++ */
                BI(B, 0x1C) = BI(B, 0x18);                                                   /* restart the arc clock */
                if (no_bounce_yet && !is_let) { for (i = 0; i < 4; i++) pos[i] = BV(B, 0x110)[i]; }  /* snap to the planned landing point */
                else pos[3] = 0.0f;
                if (!(vin[0] == 0.0f && vin[1] == 0.0f && vin[2] == 0.0f)) bounce(S, B, vin);
                stepped = 1;
            }
        }
        /* net plane x = 0 crossing */
        if (prev[0] * pos[0] < 0.0f && BB(B, 0x31)) {
            float frac = fabsf(prev[0]) / (fabsf(prev[0]) + fabsf(pos[0]));
            int same_side_target = (BF(B, 0x100) * BF(B, 0x110)) > 0.0f;
            int hits = 1;
            if (same_side_target) hits = !(pos[1] * 100.0f > BF(B, 0x124));      /* ball below the net top (cm) hits the net */ /* ? exact polarity of the test */
            if (hits) {
                float cross_pt[4], vel[4];
                for (i = 0; i < 3; i++) { cross_pt[i] = prev[i] + (pos[i] - prev[i]) * frac; vel[i] = (pos[i] - prev[i]) * S->ticks_per_second; }
                cross_pt[3] = vel[3] = 0.0f;
                for (i = 0; i < 4; i++) { BV(B, 0x130)[i] = cross_pt[i]; BV(B, 0x140)[i] = vel[i]; pos[i] = cross_pt[i]; }
                BB(B, 0x34) = 1;
                if (BB(B, 0x32) && !S->keep_spin_on_net) {
                    /* solid net: spin lost, velocity *= 0.2 and x reflected, restart arc 2 at the crossing point */
                    BF(B, 0x90) = BF(B, 0x94) = BF(B, 0x98) = 0.0f;
                    gp4_spin_accel(B, 1);
                    for (i = 0; i < 3; i++) BV(B, 0x140)[i] *= POOL_NET_RESTITUTION;
                    BV(B, 0x140)[0] = -BV(B, 0x140)[0];
                    BI(B, 0x14) += 1; BI(B, 0x1C) = BI(B, 0x18); BI(B, 0x28) = 0;
                    for (i = 0; i < 4; i++) BV(B, 0xA0)[i] = 0.0f;
                    stepped = 1;
                } else if (BB(B, 0x33)) {
                    net_cord(S, B);   /* let: direction rotated by +-B+0x494/0x498 degrees, speed *= (1 - B+0x49C), spin *= (1 - B+0x4A0) */
                    stepped = 1;
                }
            }
        }
    }
    if (stepped && BU(B, 0x4DC) <= (gp4_u32)BI(B, 0x14))   /* enough bounces: schedule the "ball dead" event */
        BI(B, 0xD0) = BI(B, 0x20) + BI(B, 0x18) + 1;
    for (i = 0; i < 4; i++) BV(B, 0x4F0)[i] = (pos[i] - prev[i]) * S->ticks_per_second;
    /* fn_889C0FE8: back to the world frame (cm, absolute) */
}

/* ---- fn_889C2818 [H]: stepper entry for one ball ---- */
void gp4_ball_step(struct Gp4Stepper *S, void *B,
                   void (*launch)(struct Gp4Stepper *, void *), void (*step)(struct Gp4Stepper *, void *))
{
    int do_step = 1;
    if (!BB(B, 0x530)) return;                      /* ball.enabled */
    gp4_to_local(S, B);
    if (BB(B, 0x43C)) {                             /* new shot pending */
        launch(S, B);                               /* fn_889C19F0 */
        BB(B, 0x43C) = 0;
        do_step = (BB(B, 0x4E0) == 0);              /* a frozen ball is launched but not advanced this tick */
    }
    if (do_step) step(S, B);                        /* fn_889C1F70 */
    /* fn_889C0FE8(S, B): back to the world frame */
}
