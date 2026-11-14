/* Self-test for the ball reference model (ref/gameplay/ball.c), synthetic templates only.
 *
 *   cc -std=c11 -Wall -Wextra -Werror ref/gameplay/ball.c ref/gameplay/test_ball.c -lm
 *   cc -std=c11 -Wall -Wextra -Werror -DBALL_CROSSCHECK_DRAFT -Isrc/xbox360 ref/gameplay/ball.c \
 *      ref/gameplay/test_ball.c src/xbox360/drafts/gp4b_ball_model.c -lm     (also compares with the bit-exact draft)
 */
#include "ball.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int failures;
#define CHECK(c) do { if (!(c)) { fprintf(stderr, "%s:%d: FAILED: %s\n", __FILE__, __LINE__, #c); failures++; } } while (0)
#define NEAR(a, b, tol) CHECK(fabsf((float)(a) - (float)(b)) <= (tol))

/* ---------------------------------------------------------------- big-endian template builder */
static uint8_t buf[0x800];
static int top;

static void put32(int off, uint32_t v) { buf[off] = (uint8_t)(v >> 24); buf[off + 1] = (uint8_t)(v >> 16); buf[off + 2] = (uint8_t)(v >> 8); buf[off + 3] = (uint8_t)v; }
static void putf(int off, float f) { uint32_t u; memcpy(&u, &f, 4); put32(off, u); }
static void rel(int field, int target) { put32(field, (uint32_t)(target - field)); }
static int alloc(int n) { int p = top; top += (n + 3) & ~3; return p; }

static int mk_const(float v) { int p = alloc(4); putf(p, v); return p; }
static int mk_curve20(float x0, float x1, float y0, float slope, float y1)
{
    int h = alloc(12 + 20);
    put32(h, 12); put32(h + 4, 1); put32(h + 8, 1);
    putf(h + 12, x0); putf(h + 16, x1); putf(h + 20, y0); putf(h + 24, slope); putf(h + 28, y1);
    return h;
}
static void mk_curve16_at(int hdr, float x0, float x1, float y0, float y1)
{
    int k = alloc(16);
    rel(hdr, k); put32(hdr + 4, 1); put32(hdr + 8, 1);
    putf(k, x0); putf(k + 4, x1); putf(k + 8, y0); putf(k + 12, y1);
}
static void set_value(int field, uint32_t type, int target) { rel(field, target); put32(field + 4, type); }
static void set_pair(int slot, float lo, float hi)
{
    int p = alloc(16), a = mk_const(lo), b = mk_const(hi);
    rel(slot, p); put32(slot + 4, 2); put32(slot + 8, 2);
    set_value(p, 0x33799CCEu, a);
    set_value(p + 8, 0x33799CCEu, b);
}

/* one 0x8C row at offset 0x40 of buf. Returns the row offset. */
static int build_row(uint32_t kind, uint32_t kind2, float primary, float secondary, float T, float spin_a_hi)
{
    int row = 0x40, tpl = row + 0x18;
    memset(buf, 0, sizeof buf);
    top = 0x100;
    put32(row, 0x85B71A2Bu); put32(row + 4, 0x11111111u); put32(row + 0x88, 0x22222222u);
    put32(row + 0x10, 0xFFFFFFFFu); put32(row + 0x14, 0xFFFFFFFFu);
    set_value(tpl, 0xF9F12A60u, mk_curve20(500.0f, 3000.0f, primary, 0.0f, primary + 50.0f));
    put32(tpl + 8, kind);
    set_value(tpl + 0x0C, 0x33799CCEu, mk_const(secondary));
    put32(tpl + 0x14, kind2);
    set_pair(tpl + 0x18, 0.0f, spin_a_hi);    /* spin_a */
    set_pair(tpl + 0x24, 0.0f, 0.0f);         /* spin_c */
    set_pair(tpl + 0x30, 0.0f, 0.0f);         /* spin_b */
    putf(tpl + 0x3C, T);
    mk_curve16_at(tpl + 0x40, -0.4f, 0.4f, 0.10f, 0.30f);   /* speed loss over spin_a       */
    mk_curve16_at(tpl + 0x4C, -0.4f, 0.4f, 0.20f, 0.40f);   /* spin decay                   */
    mk_curve16_at(tpl + 0x58, 0.0f, 1.5f, 0.0f, 1.5f);      /* outgoing elevation: identity */
    mk_curve16_at(tpl + 0x64, -1.0f, 1.0f, 0.0f, 0.0f);     /* no yaw kick                  */
    return row;
}

static ball_command ground_command(void)
{
    ball_command c;
    memset(&c, 0, sizeof c);
    c.from_cm[0] = -1250.0f; c.from_cm[1] = 100.0f; c.from_cm[2] = 150.0f;
    c.to_cm[0] = 1000.0f; c.to_cm[1] = 0.0f; c.to_cm[2] = -250.0f;
    c.net_height_cm = 91.4f;
    c.sec_weight = 1.0f;          /* primary only */
    c.spin_blend = 0.5f;
    c.mode = BALL_MODE_IN;
    c.planned = true;
    return c;
}

static float len3(const float v[3]) { return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]); }

/* ---------------------------------------------------------------- tests */
static void test_curves(void)
{
    ball_curve20 c;
    ball_curve16 d;
    c.n = 1; c.k[0].x0 = 500; c.k[0].x1 = 3000; c.k[0].y0 = 80; c.k[0].slope = 0; c.k[0].y1 = 135;
    NEAR(ball_curve20_eval(&c, 1750, BALL_CURVE_STEP), 80, 0);
    NEAR(ball_curve20_eval(&c, 1750, BALL_CURVE_RAMP), 107.5f, 1e-3f);
    NEAR(ball_curve20_eval(&c, 9000, BALL_CURVE_RAMP), 135, 1e-3f);
    NEAR(ball_curve20_eval(&c, 0, BALL_CURVE_RAMP), 80, 0);
    d.n = 1; d.k[0].x0 = 0; d.k[0].x1 = 2; d.k[0].y0 = 1; d.k[0].y1 = 3;
    NEAR(ball_curve16_eval(&d, 1), 2, 1e-6f);
    NEAR(ball_curve16_eval(&d, 5), 3, 1e-6f);
}

static void test_load(void)
{
    ball_template t;
    int row = build_row(0xC1965E5Cu, 0x879BA860u, 130.0f, 1.0f, 0.05f, -0.3f);
    CHECK(ball_template_from_be(buf + row, 1, BALL_CURVE_STEP, &t) == 0);
    CHECK(t.kind == BALL_KIND_INITIAL_SPEED && t.kind2 == BALL_KIND_APOGEE);
    CHECK(t.row_type == 0x85B71A2Bu && t.id == 0x22222222u);
    NEAR(t.T, 0.05f, 0);
    CHECK(t.primary.type == BALL_VAL_CURVE && t.primary.curve.n == 1);
    NEAR(t.primary.curve.k[0].y1, 180.0f, 0);
    NEAR(ball_value_eval(&t.spin_a[1], 1.0f, 0, BALL_CURVE_STEP), -0.3f, 0);
    NEAR(ball_curve16_eval(&t.bounce_speed_loss, 0.0f), 0.2f, 1e-6f);
}

static void test_launch_and_flight(void)
{
    ball_template t;
    ball_config cfg;
    ball_state b;
    ball_solve o;
    ball_command c = ground_command();
    int row = build_row(0xC1965E5Cu, 0x879BA860u, 130.0f, 1.0f, 0.05f, -0.3f), tick, bounced = 0;
    float p[3], v0;
    ball_config_default(&cfg);
    ball_template_from_be(buf + row, 1, BALL_CURVE_STEP, &t);
    memset(&b, 0, sizeof b);
    ball_probe(&b, &t, &cfg, &c, &o);
    CHECK(o.has_min);
    /* sec_weight 1 -> w = 0: the launch speed is the template's 130 km/h (to tick quantisation) */
    NEAR(o.initial_kmh, 130.0f, 3.0f);
    CHECK(b.bounce_tick == (int)(b.tau * 60.0f + 0.5f));
    CHECK(o.net_height_m > (cfg.radius_cm + c.net_height_cm) * 0.01f);
    ball_launch(&b, &t, &cfg, &c, 1000);
    v0 = len3(b.v_launch) * 3.6f;
    NEAR(v0, 130.0f, 3.0f);
    /* (int)(60 * tau) on a tau built by repeated float addition can be one tick short (original) */
    CHECK(b.land_frame == 1000 + b.bounce_tick || b.land_frame == 999 + b.bounce_tick);
    /* the closed form ends at the target: x, z = P1, y = 0 */
    ball_arc1_position(&b, b.tau, p);
    NEAR(p[0], b.P1[0], 1e-3f); NEAR(p[2], b.P1[2], 1e-3f); NEAR(p[1], 0.0f, 1e-3f);
    for (tick = 1; tick <= 200 && !bounced; tick++) {
        unsigned ev;
        b.tick = tick;
        ev = ball_step(&b, &t, &cfg);
        if (ev & BALL_EV_BOUNCE) {
            bounced = tick;
            NEAR(b.pos[0], b.P1[0], 0); NEAR(b.pos[2], b.P1[2], 0);
            CHECK(b.arc2_vel[1] > 0.0f);              /* reflected upward */
            /* speed loss f(spin_a) = 0.2 + 0.25*spin_a with spin_a = -0.15 at blend 0.5 */
            NEAR(len3(b.arc2_vel) / len3(b.v_arrive), 1.0f - (0.2f + 0.25f * -0.15f), 1e-3f);
            NEAR(b.spin_a, -0.15f * (1.0f - (0.3f + 0.25f * -0.15f)), 1e-5f);
        }
    }
    CHECK(bounced == b.bounce_tick);
    /* topspin (spin_a < 0) pushes the drift vector downward: A.y < 0 before the bounce */
}

static void test_prediction_and_dead(void)
{
    ball_template t;
    ball_config cfg;
    ball_state b;
    ball_solve o;
    ball_sample s[BALL_PREDICT_MAX_TICKS];
    ball_command c = ground_command();
    int row = build_row(0xC1965E5Cu, 0x879BA860u, 130.0f, 1.0f, 0.05f, -0.3f), n;
    ball_config_default(&cfg);
    ball_template_from_be(buf + row, 1, BALL_CURVE_STEP, &t);
    memset(&b, 0, sizeof b);
    ball_probe(&b, &t, &cfg, &c, &o);
    ball_launch(&b, &t, &cfg, &c, 0);
    n = ball_predict(&b, &t, &cfg, s, BALL_PREDICT_MAX_TICKS);
    CHECK(n > b.bounce_tick && n < BALL_PREDICT_MAX_TICKS);
    CHECK(s[n - 1].bounce_count == 2);
    CHECK(s[b.bounce_tick - 1].bounce_count == 1);
    NEAR(s[b.bounce_tick - 1].pos_cm[0], 1000.0f, 0.05f);
    /* with max_bounces = 1 the first bounce kills the ball */
    cfg.max_bounces = 1;
    for (b.tick = 1; b.tick <= b.bounce_tick; b.tick++) ball_step(&b, &t, &cfg);
    CHECK(b.dead_frame == b.bounce_tick + 1);
}

static void test_net_solid_and_cord(void)
{
    ball_template t;
    ball_config cfg;
    ball_state b;
    ball_solve o;
    ball_command c = ground_command();
    int row = build_row(0xC1965E5Cu, 0x879BA860u, 130.0f, 1.0f, 0.05f, -0.3f), tick;
    unsigned all = 0;
    ball_config_default(&cfg);
    ball_template_from_be(buf + row, 1, BALL_CURVE_STEP, &t);
    /* Net: the probe (planned = 0) is aimed so the arc crosses x = 0 low; the stepper reverses it */
    /* the planner probes the In shot first; an unplanned speed probe does not quantise tau and leaves
     * bounce_tick from that earlier probe (original behaviour) */
    memset(&b, 0, sizeof b);
    ball_probe(&b, &t, &cfg, &c, &o);
    c.mode = BALL_MODE_NET; c.planned = false; c.speed_kmh = 120.0f; c.aim_height_m = 0.5f;
    ball_probe(&b, &t, &cfg, &c, &o);
    ball_launch(&b, &t, &cfg, &c, 0);
    CHECK(b.check_net && b.solid_net && !b.net_cord);
    for (tick = 1; tick < 120 && !(all & BALL_EV_NET_SOLID); tick++) { b.tick = tick; all |= ball_step(&b, &t, &cfg); }
    CHECK(all & BALL_EV_NET_SOLID);
    CHECK(b.arc2_vel[0] < 0.0f && b.bounce_count == 1 && b.pos[0] == 0.0f);
    /* Let: the cord deflects the ball, keeps it going forward, no bounce counted */
    c.mode = BALL_MODE_LET_IN;
    c.cord[0] = 20.0f; c.cord[1] = 0.0f; c.cord[2] = 0.5f; c.cord[3] = 0.5f;
    ball_probe(&b, &t, &cfg, &c, &o);
    ball_launch(&b, &t, &cfg, &c, 0);
    CHECK(b.net_cord && !b.solid_net);
    all = 0;
    for (tick = 1; tick < 120 && !(all & BALL_EV_NET_CORD); tick++) { b.tick = tick; all |= ball_step(&b, &t, &cfg); }
    CHECK(all & BALL_EV_NET_CORD);
    CHECK(b.bounce_count == 0 && b.arc2_vel[0] > 0.0f);
    /* after the cord the ball flies on arc 2 and lands on the far side */
    all = 0;
    for (; tick < 400 && !(all & BALL_EV_BOUNCE); tick++) { b.tick = tick; all |= ball_step(&b, &t, &cfg); }
    CHECK((all & BALL_EV_BOUNCE) && b.pos[0] > 0.0f);
}

static void test_drop_time_kind(void)
{
    ball_template t;
    ball_config cfg;
    ball_state b;
    ball_solve o;
    ball_command c = ground_command();
    int row = build_row(0x5D90675Bu, 0x5D90675Bu, 1.5f, 0.3f, 0.045f, -0.2f);
    ball_config_default(&cfg);
    ball_template_from_be(buf + row, 1, BALL_CURVE_STEP, &t);
    memset(&b, 0, sizeof b);
    ball_probe(&b, &t, &cfg, &c, &o);
    CHECK(b.bounce_tick == 90);                      /* 1.5 s, primary only */
    c.sec_weight = 0.0f;                             /* full secondary: +0.3 s */
    memset(&b, 0, sizeof b);
    ball_probe(&b, &t, &cfg, &c, &o);
    CHECK(b.bounce_tick == 108);
    NEAR(b.tau, 1.8f, 1e-4f);
}

static void test_court_and_outcome(void)
{
    ball_bounds bb;
    ball_rng r = { 0x12345678u, 0x9ABCDEF1u };
    ball_outcome_inputs in;
    float p[3] = { 1100.0f, 0.0f, 0.0f }, q[3];
    int i, n_in = 0;
    ball_court_bounds(false, false, false, 4.0f, &bb);
    NEAR(bb.xmax, 1202.5f, 0); NEAR(bb.zmax, 423.5f, 0); NEAR(bb.zmin, -423.5f, 0);
    ball_court_bounds(true, true, false, 4.0f, &bb);
    NEAR(bb.xmax, 654.0f, 0); NEAR(bb.zmin, -12.0f, 0);
    ball_court_bounds(false, false, false, 4.0f, &bb);
    memcpy(q, p, sizeof q);
    ball_push_out(q, &bb);                           /* nearest line is the baseline (102.5 cm away) */
    NEAR(q[0], 1205.5f, 0); NEAR(q[2], 0.0f, 0);
    CHECK(ball_target_out(q, &bb));
    CHECK(ball_out_class(q, &bb) == BALL_MODE_OUT);
    q[0] = 1300.0f; CHECK(ball_out_class(q, &bb) == BALL_MODE_OUT_FAR);
    q[0] = 1500.0f; CHECK(ball_out_class(q, &bb) == BALL_MODE_OUT_VERY_FAR);
    memset(&in, 0, sizeof in);
    in.b50 = in.b51 = true; in.net_let_enabled = true;
    in.error = 0.2f; in.net_share = 0.5f; in.let_prob = 0.0f;
    for (i = 0; i < 10000; i++) n_in += ball_outcome_decide(&in, p, &bb, &r) == BALL_MODE_IN;
    NEAR(n_in / 10000.0f, 0.8f, 0.02f);
    in.force_net = true;
    CHECK(ball_outcome_decide(&in, p, &bb, &r) == BALL_MODE_NET);
    in.force_net = false; in.error = 0.0f; in.b50 = false;
    CHECK(ball_outcome_decide(&in, p, &bb, &r) == BALL_MODE_OUT);
    for (i = 0; i < 1000; i++) { float u = ball_rng_range(&r, 0.0f, 1.0f); CHECK(u >= 0.0f && u <= 1.0f); }
}

static void test_targets_and_reach(void)
{
    ball_bounds bb;
    ball_config cfg;
    ball_rng r = { 0x2468ACE1u, 0x13579BDFu };
    ball_reach_inputs ri;
    float p[3], from[3] = { -1100.0f, 0.0f, 0.0f }, w[3], lo[3];
    bool b50, b51;
    int i;
    ball_config_default(&cfg);
    CHECK(cfg.no_sidespin && cfg.skip_launch_step);
    ball_court_bounds(false, false, false, 4.0f, &bb);
    /* In: x in [75, xmax], z in [zmin, zmax], no random term */
    p[0] = 20.0f; p[1] = 0.0f; p[2] = 900.0f;
    ball_in_target(p, &bb);
    NEAR(p[0], 75.0f, 0); NEAR(p[2], 423.5f, 0);
    p[0] = 1500.0f; p[2] = -10.0f;
    ball_in_target(p, &bb);
    NEAR(p[0], 1202.5f, 0); NEAR(p[2], -10.0f, 0);
    p[0] = -30.0f; ball_target_min_depth(p); NEAR(p[0], -75.0f, 0);
    p[0] = 0.0f; ball_target_min_depth(p); NEAR(p[0], 0.0f, 0);
    /* In length error: pulled back toward the hitter along the shot line */
    p[0] = 1000.0f; p[2] = 0.0f;
    ball_in_shortfall(p, from, 150.0f);
    NEAR(p[0], 850.0f, 1e-3f); NEAR(p[2], 0.0f, 1e-3f);
    /* Wood: 4..8 m behind the hitter, +-4 m across */
    for (i = 0; i < 200; i++) {
        ball_wood_target(w, from, &cfg, &r);
        CHECK(w[0] >= -1900.0f && w[0] <= -1500.0f && w[2] >= -400.0f && w[2] <= 400.0f);
    }
    from[0] = 1100.0f;
    ball_wood_target(w, from, &cfg, &r);
    CHECK(w[0] >= 1500.0f && w[0] <= 1900.0f);
    from[0] = -1100.0f;
    /* reach flags (fn_88671B10) */
    memset(&ri, 0, sizeof ri);
    ri.point_end = true;
    ball_reach_flags(from, &bb, &ri, &b50, &b51);
    CHECK(b50 && b51);
    ri.point_end = false;
    ri.len_a = 1300.0f; ri.len_b = 1500.0f; ri.ang1_deg = 100.0f; ri.ang2_deg = 80.0f;
    ball_reach_flags(from, &bb, &ri, &b50, &b51);      /* the whole fan lands in the court */
    CHECK(b50 && !b51);
    ri.len_a = 1500.0f; ri.len_b = 2600.0f; ri.ang1_deg = 120.0f; ri.ang2_deg = 60.0f;
    ball_reach_flags(from, &bb, &ri, &b50, &b51);      /* fan leaves the court, no group-1 test */
    CHECK(b50 && b51);
    ri.ang1_deg = 60.0f; ri.ang2_deg = 120.0f;
    ball_reach_flags(from, &bb, &ri, &b50, &b51);      /* group-1 ray test fires: forced Out */
    CHECK(!b50 && b51);
    /* non-forced Out: within 2 m of a line -> moved out; farther -> demoted to In */
    p[0] = 1100.0f; p[2] = 0.0f;
    CHECK(ball_out_target_nonforced(p, &bb, &r) == BALL_MODE_OUT);
    CHECK(ball_target_out(p, &bb)); NEAR(p[2], 0.0f, 1e-3f);
    CHECK(p[0] >= 1205.5f - 1e-3f && p[0] <= 1300.0f + 1e-3f);
    p[0] = 600.0f; p[2] = 50.0f;
    CHECK(ball_out_target_nonforced(p, &bb, &r) == BALL_MODE_IN);
    NEAR(p[0], 600.0f, 0);
    /* Net/Let aim bracket: 1 m past the net on the shot line */
    p[0] = 1100.0f; p[2] = 400.0f;
    CHECK(ball_aim_bracket_lo(from, p, 100.0f, lo));
    NEAR(lo[0], 100.0f * 2200.0f / sqrtf(2200.0f * 2200.0f + 400.0f * 400.0f), 1e-2f);
    NEAR(lo[2], 200.0f + 100.0f * 400.0f / sqrtf(2200.0f * 2200.0f + 400.0f * 400.0f), 1e-2f);
}

static void test_modifiers(void)
{
    ball_template t;
    ball_config cfg;
    ball_state b0, b1;
    ball_solve o0, o1;
    ball_modifiers m;
    ball_command c = ground_command();
    int row = build_row(0xC1965E5Cu, 0x879BA860u, 120.0f, 1.0f, 0.045f, -0.2f);
    ball_config_default(&cfg);
    ball_template_from_be(buf + row, 1, BALL_CURVE_STEP, &t);
    ball_modifiers_default(&m);
    m.sec_weight = 1.0f; m.spin_blend = c.spin_blend;
    ball_modifiers_apply_command(&m, &c);
    memset(&b0, 0, sizeof b0);
    ball_probe(&b0, &t, &cfg, &c, &o0);                 /* identity scales = original */
    m.port_speed_scale = 1.2f; m.port_spin_scale[0] = 2.0f;
    ball_modifiers_apply_command(&m, &c);
    memset(&b1, 0, sizeof b1);
    ball_probe(&b1, &t, &cfg, &c, &o1);
    NEAR(b1.spin_a, 2.0f * b0.spin_a, 1e-6f);
    CHECK(o1.initial_kmh > o0.initial_kmh);
    CHECK(b1.bounce_tick < b0.bounce_tick);
}

#ifdef BALL_CROSSCHECK_DRAFT
#include "gp4b_types.h"
void gp4b_probe(Gp4bBall *B, const uint8_t *row, Gp4bSolve *O);
void gp4b_to_local(Gp4bBall *B);
void gp4b_launch(Gp4bBall *B, const uint8_t *row, float tps);
int gp4b_step_flight(float tps, float dt, Gp4bBall *B, float bounce_v[4]);
float gp4b_apex_height(const Gp4bBall *B, float tt);

/* the readable model must reproduce the bit-exact draft (float rounding differences only) */
static void crosscheck(uint32_t kind, uint32_t kind2, float primary, float secondary, float T, float spin, float sec_w,
                       int planned)
{
    static Gp4bBall B;
    Gp4bSolve O;
    ball_template t;
    ball_config cfg;
    ball_state b;
    ball_solve o;
    ball_command c = ground_command();
    float bv[4];
    int row = build_row(kind, kind2, primary, secondary, T, spin), tick;
    ball_config_default(&cfg);
    ball_template_from_be(buf + row, 1, BALL_CURVE_STEP, &t);
    c.sec_weight = sec_w; c.planned = planned != 0; c.speed_kmh = 125.0f; c.aim_height_m = 1.2f;
    memset(&B, 0, sizeof B); memset(&O, 0, sizeof O);
    B.a4 = cfg.a4; B.g = cfg.g; B.radius_cm = cfg.radius_cm; B.net_height_cm = c.net_height_cm;
    memcpy(B.cmd_from, c.from_cm, 12); memcpy(B.cmd_to, c.to_cm, 12);
    B.blend = c.spin_blend; B.planned = (uint8_t)planned; B.shot_id = c.mode; B.shot_f430 = sec_w;
    B.speed_kmh = c.speed_kmh; B.aim_height = c.aim_height_m;
    gp4b_probe(&B, buf + row, &O);
    memset(&b, 0, sizeof b);
    ball_probe(&b, &t, &cfg, &c, &o);
    CHECK(abs((int)B.bounce_tick - b.bounce_tick) <= 1);
    NEAR(O.initial_kmh, o.initial_kmh, 0.05f * (1.0f + fabsf(O.initial_kmh)));
    NEAR(O.tau_min, o.tau_min, 2e-3f);
    if ((int)B.bounce_tick != b.bounce_tick) { printf("tick differs: draft %u ref %d\n", (unsigned)B.bounce_tick, b.bounce_tick); return; }
    /* flight: same positions per tick up to the first bounce */
    gp4b_to_local(&B);
    gp4b_launch(&B, buf + row, 60.0f);
    ball_launch(&b, &t, &cfg, &c, 0);
    NEAR(gp4b_apex_height(&B, B.tau), ball_apex_height(&b, b.tau), 2e-3f);
    for (tick = 1; tick <= b.bounce_tick; tick++) {
        B.tick = tick; b.tick = tick;
        gp4b_step_flight(60.0f, 1.0f / 60.0f, &B, bv);
        ball_step(&b, &t, &cfg);
        NEAR(B.pos[0], b.pos[0], 2e-3f); NEAR(B.pos[1], b.pos[1], 2e-3f); NEAR(B.pos[2], b.pos[2], 2e-3f);
    }
}

static void test_crosscheck(void)
{
    crosscheck(0xC1965E5Cu, 0x879BA860u, 130.0f, 1.0f, 0.05f, -0.3f, 1.0f, 1);
    crosscheck(0xC1965E5Cu, 0x879BA860u, 130.0f, 1.0f, 0.05f, -0.3f, 0.0f, 1);
    crosscheck(0xC1965E5Cu, 0x5D90675Bu, 150.0f, 0.4f, 0.045f, -0.5f, 0.3f, 1);
    crosscheck(0xC1965E5Cu, 0xC1965E5Cu, 140.0f, 40.0f, 0.045f, -0.2f, 0.0f, 1);
    crosscheck(0x50B89452u, 0x50B89452u, 80.0f, 10.0f, 0.045f, -0.2f, 0.5f, 1);
    crosscheck(0x5D90675Bu, 0x879BA860u, 1.4f, 1.0f, 0.045f, -0.2f, 0.0f, 1);
    crosscheck(0x5D90675Bu, 0x5D90675Bu, 1.2f, 0.3f, 0.0525f, 0.1f, 0.5f, 1);
    crosscheck(0x5D90675Bu, 0x5D90675Bu, 1.2f, 0.3f, 0.0525f, 0.1f, 0.5f, 0);
    crosscheck(0xC1965E5Cu, 0x879BA860u, 90.0f, 1.0f, 0.0475f, -0.4f, 1.0f, 0);
    printf("cross-check against the bit-exact draft done\n");
}
#endif

int main(void)
{
    test_curves();
    test_load();
    test_launch_and_flight();
    test_prediction_and_dead();
    test_net_solid_and_cord();
    test_drop_time_kind();
    test_court_and_outcome();
    test_targets_and_reach();
    test_modifiers();
#ifdef BALL_CROSSCHECK_DRAFT
    test_crosscheck();
#endif
    if (failures) { fprintf(stderr, "%d failure(s)\n", failures); return 1; }
    printf("ball reference model: all tests passed\n");
    return 0;
}
