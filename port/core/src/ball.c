/*
 * ts4core ball module.
 *
 * Wraps the validated reference ball model src/xbox360/drafts/gp4b_ball_model.c (bit-exact against the original
 * machine code for the launch solve, the closed-form arcs and the per-tick step up to the first bounce) by
 * #including it, so there is exactly one copy of that logic. Everything after the first bounce that the
 * validation did not cover is implemented here from docs/gameplay/gp4.md / the gp4_ball_flight.c draft:
 *   - ground bounce response (fn_889C1C80)      mathematical, not bit-exact  [draft]
 *   - solid net hit and net-cord deflection     mathematical, polarity of the height test is M  [draft]
 *
 * To swap in matched code later, replace the #include below with the matched translation units and keep the
 * gp4b_* entry points (see docs/port/architecture.md, "swapping in matched functions").
 */
#include <math.h>
#include <string.h>

#include "ts4_internal.h"

/* The draft is plain C99 and exports the gp4b_* symbols. It is deliberately included, not copied. */
#include "../../../src/xbox360/drafts/gp4b_ball_model.c"

#define TS4_PI 3.14159265358979323846f
#define TS4_TICKS_PER_SECOND 60.0f

void ts4_ball_env(const Ts4Core *c, Ts4BallEnv *e)
{
    e->net_restitution = TUN(c, BALL_NET_RESTITUTION);
    e->cord_a_deg = TUN(c, BALL_CORD_ANGLE_A);
    e->cord_b_deg = TUN(c, BALL_CORD_ANGLE_B);
    e->cord_speed_loss = TUN(c, BALL_CORD_SPEED_LOSS);
    e->cord_spin_loss = TUN(c, BALL_CORD_SPIN_LOSS);
}

int32_t ts4_ball_launch(const Ts4Core *c, Ts4Ball *ball, const Ts4ShotIn *in, uint32_t launch_tick, Gp4bSolve *O)
{
    Gp4bBall *B = &ball->b;
    const uint8_t *row = ts4_template_row(c, in->row);
    uint32_t mode = in->mode;
    int i;
    if (!row) return TS4_ERR_ARG;
    if (mode == TS4_HASH_LET) mode = TS4_HASH_LET_IN;   /* the ball becomes LetIn at launch (gp4b s10.3) */
    memset(ball, 0, sizeof *ball);
    memset(O, 0, sizeof *O);
    B->a4 = TUN(c, BALL_A4);
    B->g = TUN(c, BALL_G);
    B->radius_cm = TUN(c, BALL_RADIUS_CM);
    B->net_height_cm = TUN(c, BALL_NET_HEIGHT_CM);
    B->max_bounces = (uint32_t)TUN(c, BALL_MAX_BOUNCES);
    for (i = 0; i < 3; i++) { B->cmd_from[i] = in->from[i]; B->cmd_to[i] = in->to[i]; }
    B->cmd_to[1] = 0.0f;
    B->cmd_from[3] = B->cmd_to[3] = 0.0f;
    B->blend = in->spin_blend;
    B->shot_f430 = in->f4c;
    B->planned = (uint8_t)(in->planned ? 1 : 0);
    B->speed_kmh = in->speed_kmh;
    B->aim_height = in->aim_height_m;
    B->shot_id = mode;
    B->sidespin_neg = (uint8_t)(in->left_handed ? 1 : 0);
    B->launch_frame = (int32_t)launch_tick;
    gp4b_probe(B, row, O);
    if (!(B->tau > 0.0f) || !(B->tau < 100.0f)) return TS4_ERR_UNSOLVABLE;
    gp4b_to_local(B);
    gp4b_launch(B, row, TS4_TICKS_PER_SECOND);
    B->mode = mode;
    B->enabled = 1;
    memcpy(B->vel, B->v_launch, 16);
    ball->row = row;
    ball->active = 1;
    return TS4_OK;
}

/* ---- small vector helpers ---------------------------------------------------------------------------- */
static void v_cross(const float a[3], const float b[3], float r[3])
{
    r[0] = a[1] * b[2] - a[2] * b[1];
    r[1] = a[2] * b[0] - a[0] * b[2];
    r[2] = a[0] * b[1] - a[1] * b[0];
}
static float v_len(const float v[3]) { return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]); }

/* Rodrigues rotation of v about the axis (normalised here) by angle radians. fn_8864F7B8 equivalent. */
static void rotate_about(float v[3], const float axis_in[3], float angle)
{
    float k[3], kx[3], len = v_len(axis_in), co, si, kd, r[3];
    int i;
    if (!(len > 0.0f)) return;
    for (i = 0; i < 3; i++) k[i] = axis_in[i] / len;
    co = cosf(angle);
    si = sinf(angle);
    v_cross(k, v, kx);
    kd = k[0] * v[0] + k[1] * v[1] + k[2] * v[2];
    for (i = 0; i < 3; i++) r[i] = v[i] * co + kx[i] * si + k[i] * kd * (1.0f - co);
    for (i = 0; i < 3; i++) v[i] = r[i];
}

static float wrap_pi(float a)
{
    while (a > TS4_PI) a -= 2.0f * TS4_PI;
    while (a <= -TS4_PI) a += 2.0f * TS4_PI;
    return a;
}

/* fn_889C1C80 (draft): incoming velocity v (local frame, m/s) -> outgoing velocity, spin decay, arc 2 start. */
static void bounce_response(Gp4bBall *B, const uint8_t *row, float v[4])
{
    const uint8_t *tpl = row + 0x18;
    float axis[3] = {0.0f, 0.0f, 1.0f}, up[3] = {0.0f, 1.0f, 0.0f};
    float theta, sf, w, delta, yaw, decay, len;
    v[1] = -v[1];
    len = v_len(v);
    if (len > 0.0f) {
        float cosang = v[1] / len;
        if (fabsf(cosang) < 0.99999f) v_cross(v, up, axis);
    }
    theta = atan2f(v[1], v[0]);
    if (theta > 1.5707964f) theta = TS4_PI - theta;
    sf = 1.0f - curve16_eval(B->spin_a, tpl + 0x40);
    w = fabsf(B->spin_a * 5.0f);
    delta = wrap_pi(curve16_eval(theta, tpl + 0x58) - theta);
    yaw = curve16_eval(B->spin_b, tpl + 0x64);
    v[0] *= sf; v[1] *= sf; v[2] *= sf;
    rotate_about(v, axis, delta * w);
    rotate_about(v, up, yaw);
    decay = 1.0f - curve16_eval(B->spin_a, tpl + 0x4C);
    B->spin_a *= decay;
    B->spin_b *= decay;
    if (!B->no_sidespin) B->spin_c *= decay; else { B->spin_c = 0.0f; B->spin_b = 0.0f; }
    memcpy(B->arc2_pos, B->pos, 16);
    B->arc2_pos[3] = 0.0f;
    B->arc2_vel[0] = v[0]; B->arc2_vel[1] = v[1]; B->arc2_vel[2] = v[2]; B->arc2_vel[3] = 0.0f;
    gp4b_spin_accel(B, 0);
}

static void start_arc2_at_net(Gp4bBall *B, const float cross[3], const float vel[3])
{
    int i;
    for (i = 0; i < 3; i++) { B->arc2_pos[i] = cross[i]; B->arc2_vel[i] = vel[i]; B->pos[i] = cross[i]; }
    B->arc2_pos[3] = B->arc2_vel[3] = 0.0f;
    B->bounce_count++;
    B->tick_prev = B->tick;
    B->hold_ticks = 0;
    B->flag34 = 1;
}

void ts4_ball_world_pos(const Ts4Ball *ball, float out[3])
{
    const Gp4bBall *B = &ball->b;
    int i;
    for (i = 0; i < 3; i++) out[i] = B->pos[i] * 100.0f + B->origin[i];
}
void ts4_ball_world_vel(const Ts4Ball *ball, float out[3])
{
    int i;
    for (i = 0; i < 3; i++) out[i] = ball->b.vel[i] * 100.0f;
}

int32_t ts4_ball_dead(const Ts4Ball *ball)
{
    const Gp4bBall *B = &ball->b;
    if (B->max_bounces && (uint32_t)B->bounce_count >= B->max_bounces) return 1;
    if (B->pos[0] > 60.0f || B->pos[0] < -60.0f || B->pos[2] > 60.0f || B->pos[2] < -60.0f) return 1;
    if (B->pos[1] < -2.0f) return 1;
    return 0;
}

void ts4_ball_tick(const Ts4Core *c, Ts4Ball *ball, const Ts4BallEnv *env, Ts4BallEvents *ev)
{
    Gp4bBall *B = &ball->b;
    float bv[4], prev[3];
    int i, bounce;
    (void)c;
    ev->bounced = 0;
    ev->net_hit = 0;
    ev->at[0] = ev->at[1] = ev->at[2] = 0.0f;
    B->tick++;
    for (i = 0; i < 3; i++) prev[i] = B->pos[i];
    bounce = gp4b_step_flight(TS4_TICKS_PER_SECOND, K_TICK_DT, B, bv);
    if (bounce) {
        ball->ground_bounces++;
        bounce_response(B, ball->row, bv);
        ts4_ball_world_pos(ball, ev->at);
        ev->bounced = 1;
    }
    /* net plane x = 0 (fn_889C1F70, GP4 s1.4 step 5) */
    if (!ball->net_done && B->flag31 && prev[0] * B->pos[0] < 0.0f) {
        float ax = fabsf(prev[0]), bx = fabsf(B->pos[0]);
        float frac = ax / (ax + bx);
        int same_side_target = (B->P1[0] * B->P0[0]) > 0.0f;
        float cross[3], vel[3];
        int hits = 1;
        for (i = 0; i < 3; i++) {
            cross[i] = prev[i] + (B->pos[i] - prev[i]) * frac;
            vel[i] = (B->pos[i] - prev[i]) * TS4_TICKS_PER_SECOND;
        }
        if (same_side_target) hits = !(cross[1] * 100.0f > B->net_height_cm);
        if (hits) {
            ball->net_done = 1;
            ts4_ball_world_pos(ball, ev->at);
            for (i = 0; i < 3; i++) ev->at[i] = cross[i] * 100.0f + B->origin[i];
            if (B->flag32) {                              /* solid net: spin lost, speed * restitution, x reflected */
                B->spin_a = B->spin_b = B->spin_c = 0.0f;
                B->A[0] = B->A[1] = B->A[2] = B->A[3] = 0.0f;
                for (i = 0; i < 3; i++) vel[i] *= env->net_restitution;
                vel[0] = -vel[0];
                start_arc2_at_net(B, cross, vel);
                ev->net_hit = 1;
            } else if (B->flag33) {                       /* net cord (let): deflect, keep going */
                float h = sqrtf(vel[0] * vel[0] + vel[2] * vel[2]), sp, el, up[3] = {0.0f, 1.0f, 0.0f};
                for (i = 0; i < 3; i++) vel[i] *= (1.0f - env->cord_speed_loss);
                rotate_about(vel, up, (float)ball->cord_sign * env->cord_a_deg * (TS4_PI / 180.0f));
                sp = v_len(vel);
                h = sqrtf(vel[0] * vel[0] + vel[2] * vel[2]);
                el = atan2f(vel[1], h) + env->cord_b_deg * (TS4_PI / 180.0f);
                if (h > 0.0f) { float s = (sp * cosf(el)) / h; vel[0] *= s; vel[2] *= s; }
                vel[1] = sp * sinf(el);
                B->spin_a *= (1.0f - env->cord_spin_loss);
                B->spin_b *= (1.0f - env->cord_spin_loss);
                B->spin_c *= (1.0f - env->cord_spin_loss);
                start_arc2_at_net(B, cross, vel);
                gp4b_spin_accel(B, 0);
                ev->net_hit = 2;
            }
        }
    }
    for (i = 0; i < 3; i++) B->vel[i] = (B->pos[i] - prev[i]) * TS4_TICKS_PER_SECOND;
}

/* ---- public probe / trace -------------------------------------------------------------------------- */
static int32_t shot_in_ok(const Ts4Core *c, const Ts4ShotIn *in)
{
    if (!c || c->magic != TS4_MAGIC || !in || in->struct_size < sizeof(Ts4ShotIn)) return TS4_ERR_ARG;
    if (c->mod_status[TS4_MOD_BALL] == TS4_STATUS_MISSING_DATA) return TS4_ERR_MISSING_DATA;
    if (in->row >= c->tpl_rows) return TS4_ERR_ARG;
    return TS4_OK;
}

int32_t ts4_shot_probe(Ts4Core *c, const Ts4ShotIn *in, Ts4ShotOut *out)
{
    Ts4Ball scratch, *ball = &scratch;     /* never touches the match ball */
    Gp4bSolve O;
    int32_t r;
    int i;
    if (!out || out->struct_size < sizeof(Ts4ShotOut)) return TS4_ERR_ARG;
    r = shot_in_ok(c, in);
    if (r) return r;
    r = ts4_ball_launch(c, ball, in, 0, &O);
    if (r) return r;
    out->tau = ball->b.tau;
    out->bounce_tick = ball->b.bounce_tick;
    out->initial_kmh = O.initial_kmh;
    out->net_height_m = O.net_height;
    out->raised = O.raised;
    out->net_unreachable = O.net_unreachable;
    for (i = 0; i < 3; i++) { out->launch_vel[i] = ball->b.v_launch[i]; out->arrive_vel[i] = ball->b.v_arrive[i]; }
    return TS4_OK;
}

int32_t ts4_shot_trace(Ts4Core *c, const Ts4ShotIn *in, float *out_xyz, uint32_t max_ticks)
{
    Ts4Ball scratch, *ball = &scratch;
    Gp4bSolve O;
    Ts4BallEnv env;
    Ts4BallEvents ev;
    uint32_t n = 0;
    int32_t r;
    if (!out_xyz || !max_ticks) return TS4_ERR_ARG;
    r = shot_in_ok(c, in);
    if (r) return r;
    r = ts4_ball_launch(c, ball, in, 0, &O);
    if (r) return r;
    ball->cord_sign = 1;
    ts4_ball_env(c, &env);
    ts4_ball_world_pos(ball, out_xyz);
    n = 1;
    while (n < max_ticks && ball->ground_bounces < 2 && !ts4_ball_dead(ball)) {
        ts4_ball_tick(c, ball, &env, &ev);
        ts4_ball_world_pos(ball, out_xyz + 3 * n);
        n++;
    }
    return (int32_t)n;
}
