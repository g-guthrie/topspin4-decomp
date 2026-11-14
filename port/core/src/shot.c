/*
 * ts4core shot module: request -> template row (data decision tree), the In/Out/Net/Let outcome decision
 * (docs/gameplay/gp4b.md s10, drafts/gp8_shot_error_model.c), aiming and the launch plan.
 *
 * Code here: the dice rolls, the decision table, the court-tolerance rules. Data: the tree, the templates,
 * the analyser graphs (through roles), every number (tunables). Not decoded in the game, therefore a port
 * policy marked in docs/port/architecture.md: the aim point (aim tables) and the reach flags b50/b51
 * (fn_88671B10: both treated as open).
 */
#include <math.h>
#include <string.h>

#include "ts4_internal.h"

/* ================================================================================================ */
/* RNG: fn_8861E598 (gp8 draft)                                                                      */
/* ================================================================================================ */
void ts4_rng_seed(Ts4Rng *r, uint32_t seed)
{
    r->s1 = seed ^ 0x9E3779B9u;
    r->s2 = (seed * 2654435761u) | 1u;
    if (!r->s1) r->s1 = 0x1234567u;
    ts4_rng_range(r, 0.0f, 1.0f);   /* warm up */
}

float ts4_rng_range(Ts4Rng *r, float lo, float hi)
{
    uint32_t t = (r->s1 >> 15) ^ r->s1;
    uint32_t s1n = (t << 17) ^ t;
    uint32_t s2n = r->s2 * 0x10DCDu;
    float u;
    r->s1 = s1n;
    r->s2 = s2n;
    u = (float)(uint32_t)(s2n ^ s1n) * 2.3283064365386963e-10f;   /* 2^-32 */
    if (u > 1.0f) u = 1.0f;
    return ts4_fmaf(u, hi - lo, lo);
}

uint32_t ts4_hash_state(uint32_t h, const void *p, uint32_t n)
{
    const uint8_t *b = (const uint8_t *)p;
    uint32_t i;
    for (i = 0; i < n; i++) { h ^= b[i]; h *= 16777619u; }
    return h;
}

/* ================================================================================================ */
/* request tree                                                                                      */
/* ================================================================================================ */
static int cond_value(const Ts4ShotRequest *rq, uint32_t h)
{
    struct { const char *n; uint32_t v; } t[12];
    int i;
    t[0].n = "IsWoodDown"; t[0].v = rq->wood_down;
    t[1].n = "IsWood"; t[1].v = rq->wood;
    t[2].n = "IsClassicServe"; t[2].v = rq->classic_serve;
    t[3].n = "IsAdvancedServe"; t[3].v = rq->advanced_serve;
    t[4].n = "IsSmash"; t[4].v = rq->smash;
    t[5].n = "IsBaseLine"; t[5].v = rq->baseline;
    t[6].n = "IsTopSpin"; t[6].v = rq->topspin;
    t[7].n = "IsSlice"; t[7].v = rq->slice;
    t[8].n = "IsLob"; t[8].v = rq->lob;
    t[9].n = "IsRisk"; t[9].v = rq->risk;
    t[10].n = "IsMedium"; t[10].v = rq->medium;
    t[11].n = "IsPowerful"; t[11].v = rq->powerful;
    for (i = 0; i < 12; i++)
        if (ts4_crc32(t[i].n) == h) return t[i].v != 0;
    return 0;
}

int32_t ts4_tree_select(const Ts4Core *c, const Ts4ShotRequest *rq)
{
    int32_t node = (int32_t)c->tree_root;
    uint32_t depth;
    if (!c->have_tree) return -1;
    for (depth = 0; depth <= TS4_TREE_DEPTH; depth++) {
        const uint8_t *n = c->tree + 12u * (uint32_t)node;
        int32_t next = (int32_t)ts4_le32(n + (cond_value(rq, ts4_le32(n)) ? 4 : 8));
        if (next < 0) return ~next;
        node = next;
    }
    return -1;
}

/* ================================================================================================ */
/* outcome decision and launch plan                                                                  */
/* ================================================================================================ */
typedef struct CourtBounds { float xmax, zlo, zhi; } CourtBounds;

static CourtBounds court_bounds(const Ts4Core *c, int serve, float box_sign)
{
    CourtBounds b;
    float tol = 2.0f * TUN(c, BALL_RADIUS_CM);
    float w = TUN(c, COURT_HALF_WIDTH_S_CM);
    if (serve) {
        b.xmax = TUN(c, COURT_SERVICE_X_CM) + tol;
        if (box_sign > 0.0f) { b.zlo = -tol; b.zhi = w + tol; } else { b.zlo = -w - tol; b.zhi = tol; }
    } else {
        b.xmax = TUN(c, COURT_HALF_LENGTH_CM) + tol;
        b.zlo = -(w + tol);
        b.zhi = w + tol;
    }
    return b;
}

static float clampf(float v, float lo, float hi) { return v < lo ? lo : (v > hi ? hi : v); }

/* gp8_shot_error_decide() of the draft, with b50 = b51 = 1 (fn_88671B10 not decoded). */
static uint32_t decide(const float *vars, int net_let, float roll1, float roll2, float roll3, int outside)
{
    float p = vars[TS4_V_ERROR_PROB] + vars[TS4_V_ERROR_ADDED];
    int C, A, B, F1, F2;
    p = clampf(p, 0.0f, 1.0f);
    C = net_let && (roll3 < vars[TS4_V_LET_PROB]);
    A = roll1 < p;
    B = A && (roll2 < vars[TS4_V_NET_SHARE]);
    F1 = !C && A && B && net_let;
    F2 = !F1 && ((!C && A) || outside);   /* b50 = b51 = 1: error pushes the target out */
    if (C && !F2) return TS4_HASH_LET;
    if (F1) return TS4_HASH_NET;
    if (F2) return TS4_HASH_OUT;
    return TS4_HASH_IN;
}

/* Build the launch for one swing. own_sign = sign of x on the shooter's half (-1 / +1). stick_fwd is toward the
 * opponent's baseline, stick_side toward the shooter's right. box_sign: z sign of the target service box. */
int32_t ts4_shot_plan(Ts4Core *c, Ts4SimPlayer *p, const Ts4ShotRequest *rq, const float contact[3],
                      float own_sign, float stick_fwd, float stick_side, float power, int serve, float box_sign,
                      Ts4ShotPlan *plan)
{
    float *vars = p->vars;
    float opp_sign = -own_sign, right_sign = -own_sign;   /* facing +x (own_sign -1): right is +z */
    float tx, tz, nx, roll1, roll2, roll3, tol;
    CourtBounds cb;
    int outside, net_let;
    int32_t row = ts4_tree_select(c, rq);
    uint32_t outcome;
    Ts4ShotIn *in = &plan->in;
    Gp4bSolve O;
    Ts4Ball tmp;
    int i;
    if (row < 0) return TS4_ERR_ARG;

    memset(plan, 0, sizeof *plan);
    plan->row = row;

    /* ---- per-shot variable refresh, then the graphs that fill them (roles) ---- */
    vars[TS4_V_POWER] = power;
    vars[TS4_V_HIT_HEIGHT_CM] = contact[1];
    vars[TS4_V_ERROR_PROB] = TUN(c, SHOT_ERR_BASE);
    vars[TS4_V_ERROR_ADDED] = TUN(c, SHOT_ERR_ADD);
    vars[TS4_V_LET_PROB] = TUN(c, SHOT_LET_PROB);
    vars[TS4_V_NET_SHARE] = TUN(c, SHOT_NET_SHARE);
    vars[TS4_V_SPIN_BLEND] = TUN(c, SHOT_SPIN_BLEND);
    vars[TS4_V_F4C] = TUN(c, SHOT_F4C);
    {
        int volley = !serve && !rq->baseline && !rq->smash;
        const Ts4SimPlayer *pp = p;
        float fh = pp->vars[TS4_V_STAT_FOREHAND], bh = pp->vars[TS4_V_STAT_BACKHAND];
        GpPlayerStats st;
        st.serve = vars[TS4_V_STAT_SERVE]; st.ret = vars[TS4_V_STAT_RETURN]; st.forehand = fh; st.backhand = bh;
        st.volley = vars[TS4_V_STAT_VOLLEY]; st.power = vars[TS4_V_STAT_POWER]; st.speed = vars[TS4_V_STAT_SPEED];
        st.stamina = vars[TS4_V_STAT_STAMINA];
        {
            /* forehand side: contact on the shooter's right half of the body (left-handers mirror) */
            int fh_side = ((contact[2] * right_sign) >= (p->pos[2] * right_sign)) != (p->setup.left_handed != 0);
            vars[TS4_V_CURRENT_SKILL] = gp_stat_for_stroke(&st, serve ? GP_STROKE_SERVE : (volley ? GP_STROKE_VOLLEY : GP_STROKE_GROUND), fh_side);
        }
        ts4_role_run(c, volley ? TS4_R_TIMING_VOLLEY : TS4_R_TIMING_BASELINE, vars);
    }
    ts4_role_run(c, TS4_R_SHOT_ERROR, vars);

    /* ---- the three rolls (roll3 after the let graph, as in fn_886807C0) ---- */
    roll1 = ts4_rng_range(&c->rng, 0.0f, 1.0f);
    roll2 = ts4_rng_range(&c->rng, 0.0f, 1.0f);
    ts4_role_run(c, TS4_R_LET_PROBABILITY, vars);
    roll3 = ts4_rng_range(&c->rng, 0.0f, 1.0f);

    /* ---- aim point (port policy) ---- */
    if (serve) {
        tx = opp_sign * TUN(c, AIM_SERVE_X_CM);
        tz = box_sign * TUN(c, AIM_SERVE_Z_CM) + stick_side * right_sign * TUN(c, AIM_WIDTH_STICK_CM);
    } else {
        tx = opp_sign * (TUN(c, AIM_DEPTH_CM) + stick_fwd * TUN(c, AIM_DEPTH_STICK_CM));
        tz = stick_side * right_sign * TUN(c, AIM_WIDTH_STICK_CM);
    }
    cb = court_bounds(c, serve, box_sign);
    tol = 2.0f * TUN(c, BALL_RADIUS_CM);
    (void)tol;
    nx = tx * opp_sign;                               /* normalised: > 0 = opponent half */
    outside = (nx > cb.xmax) || (tz < cb.zlo) || (tz > cb.zhi) || (nx < 0.0f);
    net_let = TUN(c, SHOT_NET_LET_ENABLED) != 0.0f;
    outcome = decide(vars, net_let, roll1, roll2, roll3, outside);

    /* ---- landing point per outcome (gp4b s10.3) ---- */
    if (outcome == TS4_HASH_OUT) {
        if (!outside) {                               /* push to just outside the nearest line */
            float dx = cb.xmax - nx, dzh = cb.zhi - tz, dzl = tz - cb.zlo, dz = dzh < dzl ? dzh : dzl;
            float margin = TUN(c, SHOT_OUT_MARGIN_CM);
            if (dx <= dz) nx = cb.xmax + margin;
            else if (dzh <= dzl) tz = cb.zhi + margin;
            else tz = cb.zlo - margin;
        }
    } else {
        nx = clampf(nx, TUN(c, SHOT_MIN_DEPTH_CM), cb.xmax);
        tz = clampf(tz, cb.zlo, cb.zhi);
        if (!serve && outcome == TS4_HASH_IN) {       /* uniform dispersion box of a normal groundstroke */
            float ddx = ts4_rng_range(&c->rng, TUN(c, BALL_DISP_X_LO), TUN(c, BALL_DISP_X_HI));
            float ddz = ts4_rng_range(&c->rng, TUN(c, BALL_DISP_Z_LO), TUN(c, BALL_DISP_Z_HI));
            float wx = nx * opp_sign;
            if (wx < 0.0f) { wx += ddx; tz += ddz; } else { wx -= ddx; tz -= ddz; }
            nx = wx * opp_sign;
        }
    }
    tx = nx * opp_sign;

    in->struct_size = sizeof(Ts4ShotIn);
    in->row = (uint32_t)row;
    for (i = 0; i < 3; i++) in->from[i] = contact[i];
    in->to[0] = tx; in->to[1] = 0.0f; in->to[2] = tz;
    in->spin_blend = vars[TS4_V_SPIN_BLEND];
    in->f4c = vars[TS4_V_F4C];
    in->left_handed = p->setup.left_handed;
    in->mode = (ts4_template_id(c, (uint32_t)row) == TS4_HASH_WOOD) ? TS4_HASH_WOOD : outcome;
    in->planned = 1;
    plan->outcome = outcome;
    plan->target[0] = tx; plan->target[1] = 0.0f; plan->target[2] = tz;

    if (outcome == TS4_HASH_NET || outcome == TS4_HASH_LET) {
        /* commanded-speed probe: initial speed of the planned shot, target pulled in until the arc crosses the
         * net plane at the Net/Let aim height (fn_889C29E8: 10-step bisection) */
        float aim_m = 0.01f * (outcome == TS4_HASH_NET ? TUN(c, SHOT_NET_AIM_CM) : TUN(c, SHOT_LET_AIM_CM));
        float lo = 0.05f, hi = 1.0f, s;
        Ts4ShotIn probe = *in;
        int32_t r = ts4_ball_launch(c, &tmp, in, 0, &O);
        if (r) return r;
        probe.planned = 0;
        probe.speed_kmh = O.initial_kmh;
        probe.aim_height_m = aim_m;
        for (i = 0; i < 10; i++) {
            float sc = 0.5f * (lo + hi);
            probe.to[0] = in->from[0] + (tx - in->from[0]) * sc;
            probe.to[2] = in->from[2] + (tz - in->from[2]) * sc;
            r = ts4_ball_launch(c, &tmp, &probe, 0, &O);
            if (r) break;
            if (O.net_height > aim_m) hi = sc; else lo = sc;
        }
        s = 0.5f * (lo + hi);
        probe.to[0] = in->from[0] + (tx - in->from[0]) * s;
        probe.to[2] = in->from[2] + (tz - in->from[2]) * s;
        *in = probe;
        plan->target[0] = in->to[0]; plan->target[2] = in->to[2];
    }
    return TS4_OK;
}
