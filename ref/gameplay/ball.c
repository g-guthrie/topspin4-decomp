/*
 * Top Spin 4 (Xbox 360) ball mechanics: portable reference implementation (see ball.h).
 * Spec: docs/gameplay/ball-physics.md. Original routines are named per function.
 */
#include "ball.h"

#include <math.h>
#include <string.h>

#define TAU_LO 0.1f            /* pool+0x2AC */
#define TAU_HI 5.1f            /* pool+0x68C */
#define KMH_PER_MS 3.6f        /* pool+0x2A4 */
#define CM 0.01f               /* pool+0x1BC */
#define X_EPS 1e-3f            /* pool+0x80  */
#define T_EPS 1e-4f            /* pool+0x458 */
#define BOUNCE_EPS 1.1920929e-7f /* pool+0x784 (negated) */
#define NET_SOLID_KEEP 0.2f    /* pool+0x10C */
#define BOUNCE_TILT_GAIN 5.0f  /* pool+0x1E0 */
#define PI_F 3.14159265f

static float clampf(float x, float lo, float hi) { return x < lo ? lo : (x > hi ? hi : x); }
static float dot3(const float a[3], const float b[3]) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
static void cross3(const float a[3], const float b[3], float o[3])
{
    float r[3] = { a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0] };
    memcpy(o, r, sizeof r);
}

/* fn_8817B608: wrap an angle into [-pi, pi) (one step each way) */
static float wrap_pi(float a)
{
    if (a >= PI_F) a -= 2.0f * PI_F;
    if (a < -PI_F) a += 2.0f * PI_F;
    return a;
}

/* fn_8864F7B8: rotate v about axis by angle (right-hand rule; quaternion fn_8825D450 + matrix fn_8864E310) */
static void rotate(float v[3], const float axis[3], float ang)
{
    float l = sqrtf(dot3(axis, axis)), n[3], c, s, d, cr[3];
    int i;
    if (l == 0.0f) return;
    for (i = 0; i < 3; i++) n[i] = axis[i] / l;
    c = cosf(ang); s = sinf(ang); d = dot3(n, v);
    cross3(n, v, cr);
    for (i = 0; i < 3; i++) v[i] = v[i] * c + cr[i] * s + n[i] * d * (1.0f - c);
}

/* ================================================================== template data */

float ball_curve16_eval(const ball_curve16 *c, float x)
{
    const ball_key16 *k;
    int i, sel = 0;
    float span, t;
    if (c->n <= 0) return 0.0f;
    for (i = 0; i < c->n; i++) { if (c->k[i].x0 > x) break; sel = i; }
    k = &c->k[sel];
    span = k->x1 - k->x0;
    t = clampf(x - k->x0, 0.0f, span > 0.0f ? span : 0.0f);
    return k->y0 + (span != 0.0f ? t / span : 0.0f) * (k->y1 - k->y0);
}

float ball_curve20_eval(const ball_curve20 *c, float x, ball_curve_mode mode)
{
    const ball_key20 *k;
    int i, sel = 0;
    float span, slope, t;
    if (c->n <= 0) return 0.0f;
    for (i = 0; i < c->n; i++) { if (c->k[i].x0 > x) break; sel = i; }
    k = &c->k[sel];
    span = k->x1 - k->x0;
    slope = k->slope;
    if (mode == BALL_CURVE_RAMP && span != 0.0f) slope = (k->y1 - k->y0) / span;
    t = x - k->x0;
    if (t > span) t = span;
    if (t < 0.0f) t = 0.0f;
    return k->y0 + t * slope;
}

/* fn_8826D278 */
static float table_eval(const ball_value *v, float a, float b)
{
    int lo = 0, i;
    float v0, v1, d, span;
    if (v->nrows <= 0) return 0.0f;
    for (i = 0; i < v->nrows; i++) { if (a - v->rows[i].a < 0.0f) break; lo = i; }
    if (lo == v->nrows - 1 || a < v->rows[0].a) return ball_curve16_eval(&v->rows[lo].c, b);
    v0 = ball_curve16_eval(&v->rows[lo].c, b);
    v1 = ball_curve16_eval(&v->rows[lo + 1].c, b);
    d = a - v->rows[lo].a;
    span = v->rows[lo + 1].a - v->rows[lo].a;
    if (d <= 0.0f) return v0;
    if (d >= span) return v1;
    return v0 + d / span * (v1 - v0);
}

float ball_value_eval(const ball_value *v, float a, float b, ball_curve_mode m)
{
    switch (v->type) {
    case BALL_VAL_CONST: return v->c;
    case BALL_VAL_CURVE: return ball_curve20_eval(&v->curve, a, m);
    case BALL_VAL_TABLE: return table_eval(v, a, b);
    default: return 0.0f;
    }
}

/* ---- big-endian loader */
static uint32_t be32(const uint8_t *p) { return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3]; }
static int32_t bei32(const uint8_t *p) { return (int32_t)be32(p); }
static float bef(const uint8_t *p) { uint32_t u = be32(p); float f; memcpy(&f, &u, 4); return f; }

static ball_kind kind_of(uint32_t h)
{
    switch (h) {
    case 0x5D90675Bu: return BALL_KIND_DROP_TIME;
    case 0x50B89452u: return BALL_KIND_BOUNCE_SPEED;
    case 0xC1965E5Cu: return BALL_KIND_INITIAL_SPEED;
    case 0x2DB3EB6Fu: return BALL_KIND_AVERAGE_SPEED;
    case 0x879BA860u: return BALL_KIND_APOGEE;
    default: return BALL_KIND_NONE;
    }
}

static int load_c16(const uint8_t *hdr, ball_curve16 *c)
{
    int32_t rel = bei32(hdr), n = bei32(hdr + 4), i;
    c->n = 0;
    if (rel == -1 || n <= 0) return 0;
    if (n > BALL_MAX_KEYS) return -1;
    for (i = 0; i < n; i++) {
        const uint8_t *k = hdr + rel + 16 * i;
        c->k[i].x0 = bef(k); c->k[i].x1 = bef(k + 4); c->k[i].y0 = bef(k + 8); c->k[i].y1 = bef(k + 12);
    }
    c->n = n;
    return 0;
}

static int load_c20(const uint8_t *hdr, ball_curve20 *c)
{
    int32_t rel = bei32(hdr), n = bei32(hdr + 4), i;
    c->n = 0;
    if (rel == -1 || n <= 0) return 0;
    if (n > BALL_MAX_KEYS) return -1;
    for (i = 0; i < n; i++) {
        const uint8_t *k = hdr + rel + 20 * i;
        c->k[i].x0 = bef(k); c->k[i].x1 = bef(k + 4); c->k[i].y0 = bef(k + 8);
        c->k[i].slope = bef(k + 12); c->k[i].y1 = bef(k + 16);
    }
    c->n = n;
    return 0;
}

/* element {i32 rel, u32 type} */
static int load_value(const uint8_t *e, ball_value *v)
{
    const uint8_t *tgt = e + bei32(e);
    uint32_t type = be32(e + 4);
    memset(v, 0, sizeof *v);
    if (type == 0x33799CCEu) { v->type = BALL_VAL_CONST; v->c = bef(tgt); return 0; }
    if (type == 0xF9F12A60u) { v->type = BALL_VAL_CURVE; return load_c20(tgt, &v->curve); }
    if (type == 0x7A330099u) {
        int32_t rel = bei32(tgt), n = bei32(tgt + 4), i;
        v->type = BALL_VAL_TABLE;
        if (rel == -1 || n <= 0) return 0;
        if (n > BALL_MAX_TABLE_ROWS) return -1;
        for (i = 0; i < n; i++) {
            const uint8_t *r = tgt + rel + 16 * i;
            v->rows[i].a = bef(r + 12);
            if (load_c16(r, &v->rows[i].c)) return -1;
        }
        v->nrows = n;
        return 0;
    }
    v->type = BALL_VAL_NONE;
    return 0;
}

static int load_pair(const uint8_t *slot, ball_value pair[2])
{
    const uint8_t *p = slot + bei32(slot);
    if (bei32(slot + 4) < 2) { memset(pair, 0, 2 * sizeof *pair); return 0; }
    return load_value(p, &pair[0]) | load_value(p + 8, &pair[1]);
}

int ball_template_from_be(const uint8_t *row, int has_header, ball_curve_mode mode, ball_template *t)
{
    const uint8_t *tpl = row + 0x18;
    int err = 0;
    memset(t, 0, sizeof *t);
    if (has_header) {
        t->row_type = be32(row);
        t->name_hash = be32(row + 4);
        t->group_hash = be32(row + 8);
        t->base_hash = be32(row + 12);
        t->id = be32(row + 0x88);
    }
    t->kind = kind_of(be32(tpl + 0x08));
    t->kind2 = kind_of(be32(tpl + 0x14));
    err |= load_value(tpl, &t->primary);
    err |= load_value(tpl + 0x0C, &t->secondary);
    err |= load_pair(tpl + 0x18, t->spin_a);
    err |= load_pair(tpl + 0x24, t->spin_c);
    err |= load_pair(tpl + 0x30, t->spin_b);
    t->T = bef(tpl + 0x3C);
    err |= load_c16(tpl + 0x40, &t->bounce_speed_loss);
    err |= load_c16(tpl + 0x4C, &t->bounce_spin_decay);
    err |= load_c16(tpl + 0x58, &t->bounce_out_elev);
    err |= load_c16(tpl + 0x64, &t->bounce_yaw);
    t->curve_mode = mode;
    return err ? -1 : 0;
}

void ball_config_default(ball_config *c)
{
    /* the State.bin default ball block (docs/gameplay/ball-physics.md section 9) */
    c->radius_cm = 4.0f;
    c->a4 = 0.06f;
    c->g = 9.81f;
    c->max_bounces = 5;
    c->disp_dx[0] = -800.0f; c->disp_dx[1] = -400.0f;
    c->disp_dz[0] = -400.0f; c->disp_dz[1] = 400.0f;
    c->skip_launch_step = true;                            /* ball+0x4E0 = 1 in the image */
    c->no_sidespin = true;                                 /* ball+0x4E1 = 1 in the image */
}

static float scale1(float s) { return s == 0.0f ? 1.0f : s; }  /* port-only scales: 0 = identity */

void ball_to_world_cm(const ball_config *cfg, const float l[3], float o[3])
{
    o[0] = l[0] * 100.0f;
    o[1] = l[1] * 100.0f + cfg->radius_cm;
    o[2] = l[2] * 100.0f;
}

/* ================================================================== closed forms */

typedef struct { float k, E, W[3], Weff[3], C[3]; } arc1_k;

/* constants of arc 1 for flight time tau (fn_888AAEA8 + fn_888AAE00) */
static void arc1_consts(const ball_state *b, float tau, float g, float a4, arc1_k *o)
{
    int i;
    o->k = b->T / a4;
    o->E = expf(-o->k * tau);
    for (i = 0; i < 3; i++) { o->W[i] = b->A[i] / b->T; o->Weff[i] = o->W[i]; }
    o->Weff[1] -= g / o->k;
    for (i = 0; i < 3; i++) {
        float p1 = (i == 1) ? 0.0f : b->P1[i];
        o->C[i] = (p1 - b->P0[i] - o->Weff[i] * tau) / (1.0f - o->E);
    }
}

void ball_arc1_position(const ball_state *b, float t, float out[3])
{
    arc1_k c;
    int i;
    arc1_consts(b, b->tau, b->g, b->a4, &c);
    for (i = 0; i < 3; i++) out[i] = b->P0[i] + c.C[i] * (1.0f - expf(-c.k * t)) + c.Weff[i] * t;
}

void ball_arc1_velocity(const ball_state *b, float t, float out[3])
{
    arc1_k c;
    int i;
    arc1_consts(b, b->tau, b->g, b->a4, &c);
    for (i = 0; i < 3; i++) out[i] = c.C[i] * c.k * expf(-c.k * t) + c.Weff[i];
}

void ball_arc2_position(const ball_state *b, float t, float out[3])
{
    float k = b->k, f = (1.0f - expf(-k * t)) / k, Weff[3];
    int i;
    for (i = 0; i < 3; i++) Weff[i] = b->A[i] / b->T;
    Weff[1] -= b->g / k;
    for (i = 0; i < 3; i++) out[i] = b->arc2_pos[i] + (b->arc2_vel[i] - Weff[i]) * f + Weff[i] * t;
}

static float speed2_at(const ball_state *b, float tau, float t)
{
    float v[3];
    arc1_k c;
    int i;
    arc1_consts(b, tau, b->g, b->a4, &c);
    for (i = 0; i < 3; i++) v[i] = c.C[i] * c.k * expf(-c.k * t) + c.Weff[i];
    return dot3(v, v);
}

float ball_speed2_initial(const ball_state *b) { return speed2_at(b, b->tau, 0.0f); }
float ball_speed2_bounce(const ball_state *b) { return speed2_at(b, b->tau, b->tau); }

/* fn_888AACB8: d|v(0)|^2 / dtau */
static float speed2_initial_deriv(const ball_state *b)
{
    arc1_k c;
    float v0[3], dv[3], om;
    int i;
    arc1_consts(b, b->tau, b->g, b->a4, &c);
    om = 1.0f - c.E;
    for (i = 0; i < 3; i++) {
        float D = c.C[i] * om;                                      /* P1 - P0 - Weff tau */
        float dC = (-c.Weff[i] * om - D * c.k * c.E) / (om * om);
        v0[i] = c.C[i] * c.k + c.Weff[i];
        dv[i] = c.k * dC;
    }
    return 2.0f * dot3(v0, dv);
}

/* fn_888AA968: apex height (local m) of arc 1 planned with flight time tau */
float ball_apex_height(const ball_state *b, float tau)
{
    arc1_k c;
    float ts, r;
    arc1_consts(b, tau, b->g, b->a4, &c);
    r = c.C[1] * c.k / -c.Weff[1];          /* e^{k t*} at vy = 0 */
    ts = logf(r) / c.k;
    return b->P0[1] + c.C[1] * (1.0f - expf(-c.k * ts)) + c.Weff[1] * ts;
}

/* fn_888AB308: height at the net plane x = 0 (bisection on x(t), 4 steps per round, <= 375 rounds) */
float ball_net_height(const ball_state *b)
{
    arc1_k c;
    float lo, hi, t = 0.0f, ax = 1.0f, p[3];
    int round = 0, i;
    arc1_consts(b, b->tau, b->g, b->a4, &c);
    lo = b->P0[0] > 0.0f ? 0.0f : b->tau;
    hi = b->P0[0] > 0.0f ? b->tau : 0.0f;
    while (ax > X_EPS) {
        for (i = 0; i < 4; i++) {
            float x;
            t = (hi + lo) * 0.5f;
            x = b->P0[0] + c.C[0] * (1.0f - expf(-c.k * t)) + c.Weff[0] * t;
            if (x >= 0.0f) lo = t; else hi = t;
            ax = fabsf(x);
        }
        if (fabsf(hi - lo) < T_EPS) break;
        if (++round >= 375) break;
    }
    for (i = 0; i < 3; i++) p[i] = b->P0[i] + c.C[i] * (1.0f - expf(-c.k * t)) + c.Weff[i] * t;
    return p[1];
}

/* ================================================================== solvers (fn_888AD0E8 family) */

static float blend_w(const ball_state *b) { return clampf(1.0f - b->sec_weight, 0.0f, 1.0f); }

/* tick quantisation: tau = n / 60, n = floor(tau * 60) by repeated float subtraction in the original */
static void quantise(ball_state *b)
{
    float x = b->tau, acc = 0.0f;
    int n = 0;
    while (x >= BALL_TICK_DT) { x -= BALL_TICK_DT; n++; acc += BALL_TICK_DT; }
    b->tau = acc;
    b->bounce_tick = n;
}

static float net_thr(const ball_state *b, const ball_config *cfg)
{
    return (b->planned ? (cfg->radius_cm + b->net_height_cm) * CM : b->aim_height_m) + CM;
}

static float node(const ball_template *t, const ball_value *v, const ball_state *b)
{
    float dx = b->P1[0] - b->P0[0], dz = b->P1[2] - b->P0[2];
    float d = sqrtf(dx * dx + dz * dz);
    return ball_value_eval(v, d * 100.0f, b->P0[1] * 100.0f, t->curve_mode);
}

typedef float (*metric_fn)(const ball_state *);

/* 20 bisections of tau in [TAU_LO, TAU_HI] for the minimum of the launch speed */
static float tau_of_min_speed(ball_state *b)
{
    float lo = TAU_LO, hi = TAU_HI;
    int i;
    for (i = 0; i < 20; i++) {
        b->tau = (hi + lo) * 0.5f;
        if (speed2_initial_deriv(b) > 0.0f) hi = b->tau; else lo = b->tau;
    }
    return (hi + lo) * 0.5f;
}

static void secondary_stage(ball_state *b, const ball_template *t, const ball_solve *o);

/* fn_888AB8D0: primary kind DropTime */
static void solve_drop_time(ball_state *b, const ball_template *t, const ball_config *cfg, ball_solve *o)
{
    float desired;
    int i;
    o->tau = b->tau = node(t, &t->primary, b);
    if (!b->planned) {
        float tmin = tau_of_min_speed(b), target = b->speed_kmh * b->speed_kmh / 12.96f;
        o->tau_min = b->tau = tmin;
        if (!(ball_speed2_initial(b) > target)) {
            float lo = TAU_LO, hi = tmin;
            for (i = 0; i < 20; i++) {
                b->tau = (hi + lo) * 0.5f;
                if (ball_speed2_initial(b) < target) hi = b->tau; else lo = b->tau;
            }
            o->tau = (hi + lo) * 0.5f;
        } else {
            o->tau = tmin;
        }
    }
    if (b->mode != BALL_MODE_WOOD) {
        float thr = net_thr(b, cfg);
        o->raised = false;
        if (ball_net_height(b) < thr && b->planned) {
            float lo = b->tau, hi = b->tau + 2.0f;
            o->raised = true;
            for (i = 0; i < 20; i++) {
                b->tau = (hi + lo) * 0.5f;
                if (ball_net_height(b) > thr) hi = b->tau; else lo = b->tau;
            }
            o->tau = (hi + lo) * 0.5f;
        }
    }
    desired = o->tau;
    if (t->kind2 == BALL_KIND_DROP_TIME) {
        desired = node(t, &t->secondary, b) + o->tau;
    } else if (t->kind2 == BALL_KIND_APOGEE) {
        float target = ball_apex_height(b, b->tau) + node(t, &t->secondary, b), lo = TAU_LO, hi = TAU_HI;
        for (i = 0; i < 20; i++) {
            float mid = (hi + lo) * 0.5f;
            b->tau = mid;
            if (ball_apex_height(b, mid) > target) hi = mid; else lo = mid;
        }
        desired = (hi + lo) * 0.5f;
    }
    b->tau = b->planned ? o->tau + blend_w(b) * (desired - o->tau) : o->tau;
    o->initial_kmh = sqrtf(ball_speed2_initial(b)) * KMH_PER_MS;
    o->tau_final = b->tau;
    quantise(b);
    o->net_height_m = ball_net_height(b);
}

/* fn_888AC748 (AverageSpeed, metric NULL) / fn_888ACA68 (InitialSpeed) / fn_888ACDA8 (BounceSpeed) */
static void solve_speed(ball_state *b, const ball_template *t, const ball_config *cfg, ball_solve *o, metric_fn m)
{
    float tmin, tgt, target, thr;
    int i;
    b->tau = TAU_LO;
    o->has_min = speed2_initial_deriv(b) < 0.0f;
    if (!o->has_min) return;
    tmin = tau_of_min_speed(b);
    o->tau_min = b->tau = tmin;
    tgt = b->planned ? node(t, &t->primary, b) * scale1(b->port_speed_scale) : b->speed_kmh;
    target = tgt * tgt / 12.96f;
    if (m ? !(m(b) > target) : (target >= 0.0f)) {
        float lo = TAU_LO, hi = tmin;
        for (i = 0; i < 20; i++) {
            b->tau = (hi + lo) * 0.5f;
            if ((m ? m(b) : 0.0f) >= target) lo = b->tau; else hi = b->tau;
        }
        o->tau = (hi + lo) * 0.5f;
    } else {
        o->tau = tmin;
    }
    thr = net_thr(b, cfg);
    b->tau = o->tau;
    if (ball_net_height(b) >= thr || !b->planned) {
        o->raised = false;
        o->tau_raised = o->tau;
    } else {
        float lo = b->tau, hi = tmin, spread = 1.0f, ht;
        int round = 0;
        b->tau = tmin;
        o->net_unreachable = false;
        if (ball_net_height(b) < thr) {        /* even the slowest arc hits the net: search up to +5 s */
            o->net_unreachable = true;
            hi = tmin + 5.0f;
            b->tau = hi;
        }
        ht = ball_net_height(b);
        while (spread > X_EPS) {
            for (i = 0; i < 4; i++) {
                b->tau = (hi + lo) * 0.5f;
                ht = ball_net_height(b);
                if (thr < ht) hi = b->tau; else lo = b->tau;
            }
            if (fabsf(lo - hi) < T_EPS) break;
            spread = fabsf(ht - thr);
            if (++round >= 200) break;
        }
        o->raised = true;
        o->tau_raised = (hi + lo) * 0.5f;
    }
    o->metric_kmh = (m ? sqrtf(m(b)) : 0.0f) * KMH_PER_MS;
    o->net_height_m = ball_net_height(b);
    if (b->planned) {
        secondary_stage(b, t, o);
        o->initial_kmh = sqrtf(ball_speed2_initial(b)) * KMH_PER_MS;
        o->tau_final = b->tau;
    }
}

/* fn_888AC688 -> fn_888AB7B0 / AC100 / AC2B8 / AC4A0 / ABF10 */
static void secondary_stage(ball_state *b, const ball_template *t, const ball_solve *o)
{
    float ta = o->raised ? o->tau_raised : o->tau, tb, w = blend_w(b);
    int i;
    if (t->kind2 == BALL_KIND_DROP_TIME) {               /* tauB = tauA + curve; no has_min test */
        tb = node(t, &t->secondary, b) + ta;
        b->tau = ta + w * (tb - ta);
        quantise(b);
        return;
    }
    if (t->kind2 == BALL_KIND_NONE) return;
    if (!o->has_min) { b->tau = 1.0f; return; }          /* not quantised (original) */
    if (o->net_unreachable) { b->tau = o->tau_raised; return; }
    tb = o->tau_min;
    if (t->kind2 == BALL_KIND_APOGEE) {                  /* apex(tauB) = apex(tauA) + curve */
        float lim = -ball_apex_height(b, ta) - node(t, &t->secondary, b);
        if (!(-ball_apex_height(b, o->tau_min) > lim)) {
            float lo = ta, hi = o->tau_min;
            for (i = 0; i < 20; i++) {
                float mid = (hi + lo) * 0.5f;
                b->tau = mid;
                if (lim > -ball_apex_height(b, mid)) hi = mid; else lo = mid;
            }
            tb = (hi + lo) * 0.5f;
        }
    } else {
        metric_fn m = t->kind2 == BALL_KIND_INITIAL_SPEED ? ball_speed2_initial
                    : t->kind2 == BALL_KIND_BOUNCE_SPEED ? ball_speed2_bounce : NULL;
        float g = node(t, &t->secondary, b), target;
        if (m) {                                         /* curve = speed delta (km/h) from the speed at tauA */
            float m0, m1, d;
            b->tau = ta; m0 = m(b);
            b->tau = o->tau_min; m1 = m(b);
            d = sqrtf(m0 * 12.96f) - g;
            target = d * d / 12.96f;
            if (!(m1 > target)) {
                float lo = ta, hi = o->tau_min;
                for (i = 0; i < 20; i++) {
                    b->tau = (hi + lo) * 0.5f;
                    if (target > m(b)) hi = b->tau; else lo = b->tau;
                }
                tb = (hi + lo) * 0.5f;
            }
        } else {                                         /* AverageSpeed stub: compares with 0 */
            target = g * g / 12.96f;
            if (target >= 0.0f) {
                float lo = ta, hi = o->tau_min;
                for (i = 0; i < 20; i++) {
                    b->tau = (hi + lo) * 0.5f;
                    if (target > 0.0f) hi = b->tau; else lo = b->tau;
                }
                tb = (hi + lo) * 0.5f;
            }
        }
    }
    b->tau = ta + w * (tb - ta);
    quantise(b);
}

void ball_solve_tau(ball_state *b, const ball_template *t, const ball_config *cfg, ball_solve *o)
{
    memset(o, 0, sizeof *o);
    b->g = cfg->g;
    b->a4 = cfg->a4;
    b->k = b->T / cfg->a4;
    switch (t->kind) {
    case BALL_KIND_DROP_TIME: solve_drop_time(b, t, cfg, o); break;
    case BALL_KIND_AVERAGE_SPEED: solve_speed(b, t, cfg, o, NULL); break;
    case BALL_KIND_BOUNCE_SPEED: solve_speed(b, t, cfg, o, ball_speed2_bounce); break;
    case BALL_KIND_INITIAL_SPEED: solve_speed(b, t, cfg, o, ball_speed2_initial); break;
    default: break;                                      /* Apogee as primary: nothing happens */
    }
}

/* ================================================================== spin and drift */

/* fn_889C0DC0 */
void ball_drift_update(ball_state *b, bool from_endpoints)
{
    float d[3], u[3], c1[3], c2[3], l, sgn = b->sidespin_neg ? -1.0f : 1.0f;
    static const float up[3] = { 0.0f, 1.0f, 0.0f };
    int i;
    if (from_endpoints) {
        for (i = 0; i < 3; i++) d[i] = b->P0[i] - b->P1[i];  /* note: points backwards (as decoded) */
    } else {
        d[0] = b->arc2_vel[0]; d[1] = 0.0f; d[2] = b->arc2_vel[2]; /* horizontal outgoing direction */
    }
    l = sqrtf(dot3(d, d));
    if (l == 0.0f) return;
    for (i = 0; i < 3; i++) u[i] = d[i] / l;
    cross3(u, up, c1);                                     /* (-u.z, 0, u.x) */
    cross3(c1, u, c2);
    for (i = 0; i < 3; i++) b->A[i] = u[i] * b->spin_c + c1[i] * (b->spin_b * sgn) + c2[i] * b->spin_a;
}

/* fn_889C1868: spin = lerp(lo(h), hi(h), blend) at launch height h (m) */
void ball_spin_set(ball_state *b, const ball_template *t, float h, float blend)
{
    ball_curve_mode m = t->curve_mode;
    float alo = ball_value_eval(&t->spin_a[0], h, 0, m), ahi = ball_value_eval(&t->spin_a[1], h, 0, m);
    float blo = ball_value_eval(&t->spin_b[0], h, 0, m), bhi = ball_value_eval(&t->spin_b[1], h, 0, m);
    float clo = ball_value_eval(&t->spin_c[0], h, 0, m), chi = ball_value_eval(&t->spin_c[1], h, 0, m);
    b->spin_a = alo + (ahi - alo) * blend;
    b->spin_b = blo + (bhi - blo) * blend;
    b->spin_c = clo + (chi - clo) * blend;
    ball_drift_update(b, true);
}

/* ================================================================== launch */

void ball_mode_flags(ball_state *b, uint32_t mode)
{
    if (b->bounce_count != 0 || mode == BALL_MODE_WOOD || mode == BALL_MODE_NET) {
        b->check_net = b->solid_net = true; b->net_cord = false;
    } else if (mode == BALL_MODE_LET_IN || mode == BALL_MODE_LET_OUT) {
        b->check_net = true; b->solid_net = false; b->net_cord = true;
    } else if (mode == BALL_MODE_LIVE_A || mode == BALL_MODE_LIVE_B) {
        b->check_net = b->solid_net = b->net_cord = false;
    } else if (mode == BALL_MODE_OUT || mode == BALL_MODE_IN) {
        bool same = b->P1[0] * b->P0[0] > 0.0f;            /* target on the hitter's own side */
        b->net_cord = false;
        b->check_net = b->solid_net = same;
    }
}

static void setup_points(ball_state *b, const ball_template *t, const ball_config *cfg, const ball_command *c)
{
    int i;
    for (i = 0; i < 3; i++) { b->P0[i] = c->from_cm[i] * CM; b->P1[i] = c->to_cm[i] * CM; }
    b->P0[1] -= cfg->radius_cm * CM;                       /* centre one radius below the hit height in local y */
    b->T = t->T;
    b->a4 = cfg->a4;
    b->g = cfg->g;
    b->k = t->T / cfg->a4;
    b->sec_weight = c->sec_weight;
    b->spin_blend = c->spin_blend;
    b->sidespin_neg = c->sidespin_neg;
    b->planned = c->planned;
    b->speed_kmh = c->speed_kmh;
    b->aim_height_m = c->aim_height_m;
    b->net_height_cm = c->net_height_cm;
    b->mode = c->mode;
    b->no_sidespin = cfg->no_sidespin;                     /* ball+0x4E1 lives in the ball block */
    b->port_speed_scale = c->port_speed_scale;
    b->port_bounce_loss_scale = c->port_bounce_loss_scale;
    b->port_bounce_decay_scale = c->port_bounce_decay_scale;
    b->port_bounce_tilt_scale = c->port_bounce_tilt_scale;
    ball_spin_set(b, t, c->from_cm[1] * CM, c->spin_blend);
    if (c->port_spin_scale[0] != 0.0f || c->port_spin_scale[1] != 0.0f || c->port_spin_scale[2] != 0.0f) {
        b->spin_a *= scale1(c->port_spin_scale[0]);        /* port-only modifier hook */
        b->spin_b *= scale1(c->port_spin_scale[1]);
        b->spin_c *= scale1(c->port_spin_scale[2]);
        ball_drift_update(b, true);
    }
}

void ball_probe(ball_state *b, const ball_template *t, const ball_config *cfg, const ball_command *c, ball_solve *o)
{
    setup_points(b, t, cfg, c);
    ball_solve_tau(b, t, cfg, o);
}

void ball_launch(ball_state *b, const ball_template *t, const ball_config *cfg, const ball_command *c, int frame)
{
    int i;
    float tau = b->tau;
    int tick = b->bounce_tick;
    setup_points(b, t, cfg, c);
    b->tau = tau;
    b->bounce_tick = tick;
    b->bounce_count = b->tick = b->tick_prev = 0;
    b->launch_frame = frame;
    b->hold = 0;
    b->touched_net = false;
    b->dead_frame = -1;
    b->cord_elev_deg = c->cord[0]; b->cord_yaw_deg = c->cord[1];
    b->cord_speed_loss = c->cord[2]; b->cord_spin_loss = c->cord[3];
    ball_mode_flags(b, c->mode);
    for (i = 0; i < 3; i++) { b->pos[i] = b->prev[i] = b->P0[i]; }
    ball_arc1_velocity(b, 0.0f, b->v_launch);
    ball_arc1_velocity(b, b->tau, b->v_arrive);
    b->land_frame = frame + (int)(BALL_TICKS_PER_SECOND * b->tau);
}

/* ================================================================== bounce, net, step */

void ball_bounce_response(ball_state *b, const ball_template *t, float v[3])
{
    static const float up[3] = { 0.0f, 1.0f, 0.0f };
    float axis[3] = { 0.0f, 0.0f, 1.0f }, theta, sa = b->spin_a, f_loss, f_decay, yaw, tilt, l;
    int i;
    v[1] = -v[1];                                          /* reflect the vertical component */
    l = sqrtf(dot3(v, v));
    if (l > 0.0f && fabsf(v[1] / l) < 0.99999f) cross3(v, up, axis);
    theta = atan2f(v[1], v[0]);                            /* elevation in the x-y plane (z ignored) */
    if (theta > PI_F * 0.5f) theta = PI_F - theta;
    f_loss = ball_curve16_eval(&t->bounce_speed_loss, sa) * scale1(b->port_bounce_loss_scale);
    f_decay = ball_curve16_eval(&t->bounce_spin_decay, sa) * scale1(b->port_bounce_decay_scale);
    yaw = ball_curve16_eval(&t->bounce_yaw, b->spin_b);
    tilt = wrap_pi(ball_curve16_eval(&t->bounce_out_elev, theta) - theta) * fabsf(BOUNCE_TILT_GAIN * sa)
           * scale1(b->port_bounce_tilt_scale);
    for (i = 0; i < 3; i++) v[i] *= 1.0f - f_loss;
    rotate(v, axis, tilt);                                 /* elevation pulled toward the template angle */
    rotate(v, up, yaw);                                    /* sidespin kick (raw spin_b, no hand mirror) */
    b->spin_a *= 1.0f - f_decay;
    b->spin_b *= 1.0f - f_decay;
    if (b->no_sidespin) { b->spin_b = b->spin_c = 0.0f; }
    else b->spin_c *= 1.0f - f_decay;
    memcpy(b->arc2_pos, b->pos, sizeof b->pos);
    memcpy(b->arc2_vel, v, 3 * sizeof(float));
    ball_drift_update(b, false);
}

static void net_cord(ball_state *b)
{
    static const float up[3] = { 0.0f, 1.0f, 0.0f };
    float speed = sqrtf(dot3(b->arc2_vel, b->arc2_vel)), n[3], h[3], hl, ax[3], c, keep_s, keep_r;
    int i;
    b->pos[0] = 0.0f;
    if (speed > 0.0f) for (i = 0; i < 3; i++) n[i] = b->arc2_vel[i] / speed;
    else { n[0] = n[1] = n[2] = 0.0f; }
    h[0] = n[0]; h[1] = 0.0f; h[2] = n[2];
    hl = sqrtf(dot3(h, h));
    c = hl > 0.0f ? dot3(n, h) / hl : 1.0f;
    cross3(n, up, ax);
    /* rotate by the current |elevation| plus the cord angle: a descending ball leaves at +cord_elev */
    rotate(n, ax, acosf(clampf(c, -1.0f, 1.0f)) + b->cord_elev_deg * (PI_F / 180.0f));
    rotate(n, up, b->cord_yaw_deg * (PI_F / 180.0f));
    keep_s = 1.0f - b->cord_speed_loss;
    keep_r = 1.0f - b->cord_spin_loss;
    for (i = 0; i < 3; i++) b->arc2_vel[i] = n[i] * speed * keep_s;
    b->spin_c *= keep_r;
    b->spin_a *= keep_r;
    b->spin_b *= keep_r;
    if (b->no_sidespin) { b->spin_c = b->spin_b = 0.0f; }
    else b->spin_c *= keep_r;                              /* spin_c is scaled twice (original) */
    ball_drift_update(b, false);
    b->hold = 0;
    b->tick_prev = b->tick;
    b->hold_delta[0] = b->hold_delta[1] = b->hold_delta[2] = 0.0f;
}

unsigned ball_step(ball_state *b, const ball_template *t, const ball_config *cfg)
{
    unsigned ev = 0;
    bool is_let = b->mode == BALL_MODE_LET_IN || b->mode == BALL_MODE_LET_OUT;
    float dt;
    int i;
    memcpy(b->prev, b->pos, sizeof b->pos);
    if (b->hold > 0) {                                     /* scripted motion */
        b->hold--;
        for (i = 0; i < 3; i++) b->pos[i] += b->hold_delta[i];
        if (b->hold == 0 && b->bounce_count > 0) b->tick_prev = b->tick;
        goto done;
    }
    {
        bool first = b->bounce_count == 0;
        bool same_side = b->P0[0] >= 0.0f ? b->pos[0] > 0.0f : b->pos[0] < 0.0f;
        bool arc1 = is_let ? same_side : first;
        bool planned_bounce = first && !is_let, bounce;
        dt = (float)(b->tick - b->tick_prev) * BALL_TICK_DT;
        if (arc1) ball_arc1_position(b, dt, b->pos); else ball_arc2_position(b, dt, b->pos);
        if (planned_bounce) bounce = b->tick >= b->bounce_tick;
        else bounce = (b->pos[1] - b->prev[1]) <= 0.0f && b->pos[1] < -BOUNCE_EPS;
        if (bounce) {
            float v[3];
            if (planned_bounce) ball_arc1_velocity(b, b->tau, v);
            else for (i = 0; i < 3; i++) v[i] = (b->pos[i] - b->prev[i]) * BALL_TICKS_PER_SECOND;
            b->bounce_count++;
            b->tick_prev = b->tick;
            if (planned_bounce) memcpy(b->pos, b->P1, sizeof b->P1);   /* snap to the planned landing point */
            else b->pos[1] = 0.0f;
            if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) ball_bounce_response(b, t, v);
            ev |= BALL_EV_BOUNCE;
        }
    }
    /* net plane */
    if (b->prev[0] * b->pos[0] < 0.0f && b->check_net) {
        float ap = fabsf(b->prev[0]), an = fabsf(b->pos[0]), f = ap / (ap + an), cross[3];
        bool same_endpoints = b->P0[0] * b->P1[0] > 0.0f;
        bool hit = !same_endpoints || !(b->pos[1] * 100.0f > b->net_height_cm);
        if (hit) {
            for (i = 0; i < 3; i++) {
                cross[i] = b->prev[i] + (b->pos[i] - b->prev[i]) * f;
                b->arc2_vel[i] = (b->pos[i] - b->prev[i]) * BALL_TICKS_PER_SECOND;
            }
            memcpy(b->arc2_pos, cross, sizeof cross);
            memcpy(b->pos, cross, sizeof cross);
            b->touched_net = true;
            if (b->solid_net && !b->keep_spin_on_net) {
                b->spin_a = b->spin_b = b->spin_c = 0.0f;
                ball_drift_update(b, true);
                for (i = 0; i < 3; i++) b->arc2_vel[i] *= NET_SOLID_KEEP;
                b->arc2_vel[0] = -b->arc2_vel[0];          /* drops back on the hitter's side */
                b->bounce_count++;
                b->hold_delta[0] = b->hold_delta[1] = b->hold_delta[2] = 0.0f;
                b->tick_prev = b->tick;
                b->hold = 0;
                b->pos[0] = 0.0f;
                ev |= BALL_EV_NET_SOLID;
            } else if (b->net_cord) {
                net_cord(b);                               /* no bounce_count increment */
                ev |= BALL_EV_NET_CORD;
            }
        }
    }
    if (ev && cfg->max_bounces <= (unsigned)b->bounce_count) {
        b->dead_frame = b->launch_frame + b->tick + 1;
        ev |= BALL_EV_DEAD;
    }
done:
    for (i = 0; i < 3; i++) b->vel[i] = (b->pos[i] - b->prev[i]) * BALL_TICKS_PER_SECOND;
    return ev;
}

/* ================================================================== prediction */

int ball_predict(const ball_state *src, const ball_template *t, const ball_config *cfg, ball_sample *out, int max)
{
    ball_state b = *src;
    int n = 0, i;
    if (b.mode == BALL_MODE_LET_IN || b.mode == BALL_MODE_LET_OUT) {
        b.mode = b.mode == BALL_MODE_LET_IN ? BALL_MODE_LIVE_A : BALL_MODE_LIVE_B;
        b.check_net = b.solid_net = b.net_cord = false;
    }
    for (i = 0; i < BALL_PREDICT_MAX_TICKS && n < max; i++) {
        b.tick++;
        ball_step(&b, t, cfg);
        out[n].tick = b.tick;
        ball_to_world_cm(cfg, b.pos, out[n].pos_cm);
        memcpy(out[n].vel, b.vel, sizeof b.vel);
        out[n].bounce_count = b.bounce_count;
        n++;
        if (b.bounce_count >= 2 || b.mode == BALL_MODE_NET || b.mode == BALL_MODE_OUT) break;
    }
    return n;
}

/* ================================================================== court, outcome, error */

void ball_court_bounds(bool serve, bool deuce_side, bool doubles, float radius_cm, ball_bounds *o)
{
    float tol = 2.0f * radius_cm;                          /* pool 2.0 * ball+0x4D0 */
    if (serve) {
        o->xmax = 646.0f;                                  /* service line (pool+0x140)        */
        o->zmin = deuce_side ? -4.0f : -415.5f;            /* centre line / singles sideline   */
        o->zmax = deuce_side ? 415.5f : 4.0f;
    } else {
        o->xmax = 1194.5f;                                 /* baseline (pool+0x2C0)            */
        o->zmin = doubles ? -552.5f : -415.5f;
        o->zmax = doubles ? 552.5f : 415.5f;
    }
    o->xmax += tol; o->zmin -= tol; o->zmax += tol;
}

bool ball_target_out(const float p[3], const ball_bounds *bb)
{
    return fabsf(p[0]) > bb->xmax || p[2] > bb->zmax || p[2] < bb->zmin || p[0] < 0.0f;
}

void ball_push_out(float p[3], const ball_bounds *bb)
{
    float dx = fabsf(p[0]) - bb->xmax;
    float dz = p[2] >= 0.0f ? p[2] - bb->zmax : bb->zmin - p[2];
    if (dx > 3.0f || dz > 3.0f) return;                    /* already clearly out */
    if (fabsf(dx) < fabsf(dz)) {                           /* nearest line is the baseline */
        if (p[0] > 0.0f) p[0] = fminf(fmaxf(p[0], bb->xmax + 3.0f), 100000.0f);
        else p[0] = fminf(fmaxf(p[0], -bb->xmax - 3.0f), 100000.0f); /* original: no push on this side */
    } else {
        if (p[2] > 0.0f) p[2] = fminf(fmaxf(p[2], bb->zmax + 3.0f), 100000.0f);
        else p[2] = fminf(fmaxf(p[2], -100000.0f), bb->zmin - 3.0f);
    }
}

uint32_t ball_out_class(const float p[3], const ball_bounds *bb)
{
    const float w = 50.0f, A = 100.0f, B = 100.0f, C = 200.0f;   /* Settings cfg+0x13C..0x148 */
    if (p[0] < bb->xmax + w && p[2] < bb->zmax + w && p[0] > -A && p[2] > bb->zmin - w) return BALL_MODE_OUT;
    if (p[0] < bb->xmax + B + w && p[2] < bb->zmax + B + w && p[0] > -(A + C) && p[2] > bb->zmin - B - w)
        return BALL_MODE_OUT_FAR;
    return BALL_MODE_OUT_VERY_FAR;
}

float ball_rng_range(ball_rng *r, float lo, float hi)
{
    uint32_t t = (r->s1 >> 15) ^ r->s1, v;
    float u;
    r->s2 = r->s2 * 0x10DCDu;
    r->s1 = (t << 17) ^ t;
    v = r->s2 ^ r->s1;
    u = (float)v * 2.3283064e-10f;                         /* 2^-32 */
    if (u > 1.0f) u = 1.0f;
    return lo + u * (hi - lo);
}

uint32_t ball_outcome_decide(const ball_outcome_inputs *in, const float target[3], const ball_bounds *bb, ball_rng *rng)
{
    float P = clampf(in->error + in->error_add, 0.0f, 1.0f);
    float r1 = ball_rng_range(rng, 0.0f, 1.0f), r2 = ball_rng_range(rng, 0.0f, 1.0f), r3 = ball_rng_range(rng, 0.0f, 1.0f);
    bool G = in->net_let_enabled;
    bool C = G && (r3 < in->let_prob || in->force_let);
    bool A = r1 < P || in->force_error || in->force_net;
    bool B = (A && r2 < in->net_share) || in->force_net;
    bool out = ball_target_out(target, bb);
    bool f1 = !C && A && B && G;
    bool f2 = !f1 && (!in->b50 || (!C && in->b51 && A) || out);
    if (f1) return BALL_MODE_NET;
    if (f2) return BALL_MODE_OUT;
    if (!C) return BALL_MODE_IN;
    return BALL_MODE_LET;
}

void ball_target_min_depth(float p[3])
{
    if (p[0] > 0.0f && p[0] < 75.0f) p[0] = 75.0f;                /* pool+0x604, fn_886807C0 +0x874 */
    else if (p[0] < 0.0f && p[0] > -75.0f) p[0] = -75.0f;         /* pool+0x610 (x == 0 is kept)    */
}

void ball_in_target(float p[3], const ball_bounds *bb)
{
    p[0] = clampf(p[0], 75.0f, bb->xmax);                          /* fn_886807C0 +0x398..+0x3E0 */
    p[2] = clampf(p[2], bb->zmin, bb->zmax);                       /* +0x43C..+0x47C             */
    ball_target_min_depth(p);
}

void ball_in_shortfall(float p[3], const float from[3], float shortfall_cm)
{
    float dx = p[0] - from[0], dz = p[2] - from[2], l = sqrtf(dx * dx + dz * dz);
    if (l == 0.0f) return;                                         /* vsel keeps the zero vector */
    p[0] -= dx / l * shortfall_cm;                                 /* fn_886805E0 +0x17C..+0x190 */
    p[2] -= dz / l * shortfall_cm;
}

void ball_wood_target(float out[3], const float from[3], const ball_config *cfg, ball_rng *rng)
{
    float dx = ball_rng_range(rng, cfg->disp_dx[0], cfg->disp_dx[1]);   /* fn_886AE528 +0xA90 */
    float dz = ball_rng_range(rng, cfg->disp_dz[0], cfg->disp_dz[1]);   /* +0xAA4             */
    if (from[0] < 0.0f) { out[0] = from[0] + dx; out[2] = from[2] + dz; }
    else { out[0] = from[0] - dx; out[2] = from[2] - dz; }
    out[1] = 0.0f;
}

static float cross_y(const float d[3], float wx, float wz) { return d[2] * wx - d[0] * wz; }
static bool inside_rect(float x, float z, const ball_bounds *bb)
{
    return x < bb->xmax && z < bb->zmax && x > 100.0f && z > bb->zmin;  /* strict; 100 = pool+0x20 */
}

void ball_reach_flags(const float p[3], const ball_bounds *bb, const ball_reach_inputs *in, bool *b50, bool *b51)
{
    const float D2R = 0.017453292f;                                /* pool+0x184 */
    float R = in->len_a, Rm = in->len_b > in->len_a ? in->len_b : in->len_a;
    float R2 = R * R, Rm2 = Rm * Rm, a1 = in->ang1_deg * D2R, a2 = in->ang2_deg * D2R;
    float d1[3] = { sinf(a1), 0.0f, cosf(a1) }, d2[3] = { sinf(a2), 0.0f, cosf(a2) };
    /* court corners of the receiver half from 1 m past the net: q1 (100, zmax), q2 (100, zmin),
     * q3 (xmax, zmin), q4 (xmax, zmax) */
    float px = p[0], pz = p[2];
    float dq1 = (px - 100.0f) * (px - 100.0f) + (pz - bb->zmax) * (pz - bb->zmax);
    float dq2 = (px - 100.0f) * (px - 100.0f) + (pz - bb->zmin) * (pz - bb->zmin);
    float dq3 = (px - bb->xmax) * (px - bb->xmax) + (pz - bb->zmin) * (pz - bb->zmin);
    float dq4 = (px - bb->xmax) * (px - bb->xmax) + (pz - bb->zmax) * (pz - bb->zmax);
    bool g1, g2, all5;
    if (in->point_end) { *b50 = *b51 = true; return; }             /* fn_88671B10 +0x54 */
    /* group 1 (+0x2F0..+0x3D4): any of four "court not covered" tests */
    g1 = (dq2 > Rm2 && dq1 > Rm2)                                  /* both near corners beyond the long reach */
        || cross_y(d1, bb->xmax - px, bb->zmax - pz) > 0.0f        /* q4 outside ray a1 */
        || cross_y(d2, bb->xmax - px, bb->zmin - pz) < 0.0f        /* q3 outside ray a2 */
        || (dq3 < R2 && dq4 < R2);                                 /* both far corners inside the short reach */
    /* group 2 (+0x3D4..+0x4A4): all four "court spans the fan" tests */
    g2 = (dq3 < Rm2 && dq4 < Rm2) && (dq1 > R2 && dq2 > R2)
        && cross_y(d1, 100.0f - px, bb->zmax - pz) < 0.0f          /* q1 vs ray a1 */
        && cross_y(d2, 100.0f - px, bb->zmin - pz) > 0.0f;         /* q2 vs ray a2 */
    /* five end points of the reach fan (+0x4A4..+0x5A4) */
    all5 = inside_rect(px + d1[0] * Rm, pz + d1[2] * Rm, bb) && inside_rect(px + d1[0] * R, pz + d1[2] * R, bb)
        && inside_rect(px + d2[0] * Rm, pz + d2[2] * Rm, bb) && inside_rect(px + d2[0] * R, pz + d2[2] * R, bb)
        && inside_rect(px + Rm, pz, bb);
    if (all5) { *b50 = true; *b51 = false; }                       /* +0x5F4 */
    else if (g2 || !g1) { *b50 = true; *b51 = true; }              /* +0x5FC..+0x610 */
    else { *b50 = false; *b51 = true; }                            /* +0x614 */
}

uint32_t ball_out_target_nonforced(float p[3], const ball_bounds *bb, ball_rng *rng)
{
    float x0 = p[0], z0 = p[2], best = -1.0f, line[3] = { 0.0f, 0.0f, 0.0f }, d[3], l, r;
    float d0 = (bb->zmin - z0) * (bb->zmin - z0);                  /* to (x0, zmin)   */
    float d1 = (bb->zmax - z0) * (bb->zmax - z0);                  /* to (x0, zmax)   */
    float d2 = (bb->xmax - x0) * (bb->xmax - x0);                  /* to (xmax, z0)   */
    if (d0 < d1 && d0 < d2) { best = d0; line[0] = x0; line[2] = bb->zmin; }
    if (d1 < d0 && d1 < d2) { best = d1; line[0] = x0; line[2] = bb->zmax; }
    if (d2 < d1 && d2 < d0) { best = d2; line[0] = bb->xmax; line[2] = z0; }
    if (best < 0.0f) {
        /* exact tie: the original keeps f11 = -1 (pool+0x38) and a stale vector register (v125), so
         * sqrtf(-1) feeds the roll (NaN target). Port deviation: take the first smallest line. */
        if (d0 <= d1 && d0 <= d2) { best = d0; line[0] = x0; line[2] = bb->zmin; }
        else if (d1 <= d2) { best = d1; line[0] = x0; line[2] = bb->zmax; }
        else { best = d2; line[0] = bb->xmax; line[2] = z0; }
    }
    if (best > 40000.0f) {                                          /* pool+0x614: demote to In */
        p[0] = clampf(p[0], -bb->xmax, bb->xmax);
        p[2] = clampf(p[2], bb->zmin, bb->zmax);
        ball_target_min_depth(p);
        return BALL_MODE_IN;
    }
    r = ball_rng_range(rng, sqrtf(best), 200.0f);                  /* pool+0x364 */
    d[0] = line[0] - x0; d[1] = 0.0f; d[2] = line[2] - z0;
    l = sqrtf(d[0] * d[0] + d[2] * d[2]);
    if (l > 0.0f) { p[0] = x0 + d[0] / l * r; p[2] = z0 + d[2] / l * r; }
    ball_push_out(p, bb);
    ball_target_min_depth(p);
    return BALL_MODE_OUT;
}

bool ball_aim_bracket_lo(const float from[3], const float to[3], float d_cm, float out[3])
{
    float dx = to[0] - from[0], dz = to[2] - from[2], l = sqrtf(dx * dx + dz * dz), s;
    if (dx == 0.0f || l == 0.0f) return false;
    s = -from[0] / dx;                                             /* line meets x = 0 */
    out[0] = dx / l * d_cm;
    out[1] = 0.0f;
    out[2] = from[2] + dz * s + dz / l * d_cm;
    return true;
}

void ball_modifiers_default(ball_modifiers *m)
{
    memset(m, 0, sizeof *m);
    m->sec_weight = 1.0f;          /* primary solver only */
    m->spin_blend = 0.5f;
    m->outcome.b50 = m->outcome.b51 = true;
    m->outcome.net_let_enabled = true;
    m->net_aim_cm = 80.0f; m->let_aim_cm = 90.0f;
    m->port_speed_scale = 1.0f;
    m->port_spin_scale[0] = m->port_spin_scale[1] = m->port_spin_scale[2] = 1.0f;
    m->port_bounce_loss_scale = m->port_bounce_decay_scale = m->port_bounce_tilt_scale = 1.0f;
}

void ball_modifiers_apply_command(const ball_modifiers *m, ball_command *c)
{
    c->sec_weight = m->sec_weight;
    c->spin_blend = m->spin_blend;
    c->port_speed_scale = m->port_speed_scale;
    memcpy(c->port_spin_scale, m->port_spin_scale, sizeof c->port_spin_scale);
    c->port_bounce_loss_scale = m->port_bounce_loss_scale;
    c->port_bounce_decay_scale = m->port_bounce_decay_scale;
    c->port_bounce_tilt_scale = m->port_bounce_tilt_scale;
}
