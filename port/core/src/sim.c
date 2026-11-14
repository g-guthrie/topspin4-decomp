/*
 * ts4core match simulation: players, swings, point flow, judge, AI virtual input, events, snapshot.
 *
 * Built from the decoded pieces (ball, shot, reach window, movement selector, rules) plus *port policy* where the
 * game's behaviour is not decoded yet. Every such policy is listed in docs/port/architecture.md (table
 * "module status"); none of them contains a game number: all numbers are tunables.
 */
#include <math.h>
#include <string.h>

#include "ts4_internal.h"

#define TICK_DT (1.0f / 60.0f)
#define SHOT_BUTTONS (TS4_BTN_FLAT | TS4_BTN_TOPSPIN | TS4_BTN_SLICE | TS4_BTN_LOB)

/* ================================================================================================ */
/* events                                                                                            */
/* ================================================================================================ */
void ts4_ev(Ts4Core *c, uint32_t type, int32_t a, int32_t b, int32_t cc, const float *xyz)
{
    Ts4Event *e = &c->ring[c->ev_head % TS4_EV_RING];
    e->type = type;
    e->tick = c->tick;
    e->a = a; e->b = b; e->c = cc;
    e->x = xyz ? xyz[0] : 0.0f;
    e->y = xyz ? xyz[1] : 0.0f;
    e->z = xyz ? xyz[2] : 0.0f;
    c->ev_head++;
    if (c->ev_head - c->ev_tail > TS4_EV_RING) c->ev_tail = c->ev_head - TS4_EV_RING;
}

uint32_t ts4_poll_events(Ts4Core *c, Ts4Event *out, uint32_t max)
{
    uint32_t n = 0;
    if (!c || c->magic != TS4_MAGIC || !out) return 0;
    while (n < max && c->ev_tail != c->ev_head) {
        out[n++] = c->ring[c->ev_tail % TS4_EV_RING];
        c->ev_tail++;
    }
    return n;
}

/* ================================================================================================ */
/* geometry helpers                                                                                  */
/* ================================================================================================ */
static float own_sign(const Ts4Core *c, int p) { return ((p ^ (c->rules.ends_swapped ? 1 : 0)) == 0) ? -1.0f : 1.0f; }
static float right_sign(const Ts4Core *c, int p) { return -own_sign(c, p); }
static float clampf(float v, float lo, float hi) { return v < lo ? lo : (v > hi ? hi : v); }
static float absf(float v) { return v < 0.0f ? -v : v; }

/* ================================================================================================ */
/* candidate window parameters from tunables                                                         */
/* ================================================================================================ */
static void window_params(const Ts4Core *c, const Ts4SimPlayer *p, GpWindowParams *w)
{
    memset(w, 0, sizeof *w);
    w->volley_lateral_max = TUN(c, REACH_VOLLEY_X_MAX);
    w->volley_max_bounce = (int)TUN(c, REACH_VOLLEY_BOUNCE);
    w->split_height_volley = TUN(c, REACH_SPLIT_VOLLEY);
    w->split_height_other = TUN(c, REACH_SPLIT_OTHER);
    w->smash_band_volley[0] = TUN(c, REACH_SMASH_LO_V);
    w->smash_band_volley[1] = TUN(c, REACH_SMASH_HI_V);
    w->smash_band_other[0] = TUN(c, REACH_SMASH_LO_O);
    w->smash_band_other[1] = TUN(c, REACH_SMASH_HI_O);
    w->reach_radius = p->setup.left_handed ? TUN(c, REACH_RADIUS_LEFT) : TUN(c, REACH_RADIUS_RIGHT);
    w->prep_frames_volley = TUN(c, REACH_PREP_VOLLEY);
    w->prep_frames_other = TUN(c, REACH_PREP_OTHER);
    w->unit_scale = TUN(c, REACH_UNIT_SCALE);
    w->speed_cap = TUN(c, REACH_SPEED_CAP);
    w->unreachable = TUN(c, REACH_UNREACHABLE);
    w->far_default = TUN(c, REACH_FAR_DEFAULT);
    w->min_time_frames = TUN(c, REACH_MIN_TIME);
    w->id_baseline = GP_ID_BASELINE;
    w->id_volley = GP_ID_VOLLEY;
    w->id_smash = GP_ID_SMASH;
    w->id_none = 0;
}

/* same classification as gp_window_build() for a single point */
static uint32_t classify(const GpWindowParams *p, const float pos[3], int bounce)
{
    float lateral = absf(pos[0]), height = pos[1];
    int vz = bounce <= p->volley_max_bounce && lateral < p->volley_lateral_max;
    float split = vz ? p->split_height_volley : p->split_height_other;
    const float *band = vz ? p->smash_band_volley : p->smash_band_other;
    if (height < split) return vz ? p->id_volley : p->id_baseline;
    return (height > band[0] && height < band[1]) ? p->id_smash : p->id_none;
}

/* ================================================================================================ */
/* ball prediction (the game predicts with its own stepper, gp3 s2)                                  */
/* ================================================================================================ */
static void predict(Ts4Core *c)
{
    Ts4Ball sim = c->ball;
    Ts4BallEnv env;
    Ts4BallEvents ev;
    uint32_t n = 0;
    ts4_ball_env(c, &env);
    while (n < TS4_MAX_PRED && sim.ground_bounces < 2 && !ts4_ball_dead(&sim)) {
        Ts4PredSample *s = &c->pred[n];
        ts4_ball_tick(c, &sim, &env, &ev);
        ts4_ball_world_pos(&sim, s->pos);
        s->tick = (int32_t)c->tick + (int32_t)n + 1;
        s->bounce = (int32_t)sim.ground_bounces;
        n++;
        if (ev.net_hit == 1) break;
    }
    c->pred_n = n;
}

/* ================================================================================================ */
/* movement regime (fn_88699FC0) and the planner state machine                                       */
/* ================================================================================================ */
static float move_table(const struct mv_mode_cfg *mode, float distance, float slack, void *user)
{
    Ts4Core *c = (Ts4Core *)user;
    const char *name = (mode == &c->mvcfg.rush) ? "move.table.rush" : (mode == &c->mvcfg.jogjog) ? "move.table.jogjog" : "move.table.jog";
    uint32_t ty, n;
    const uint8_t *t = ts4_curve_find(c, ts4_crc32(name), &ty, &n);
    if (!t || ty != 2) return -1.0f;
    return ts4_table2d_le(t, n, distance, slack);
}

static void setup_mvcfg(Ts4Core *c)
{
    memset(&c->mvcfg, 0, sizeof c->mvcfg);
    c->mvcfg.reaction_frames = TUN(c, MOVE_REACTION);
    c->mvcfg.validity_threshold = TUN(c, MOVE_VALIDITY);
    c->mvcfg.rush_guard = TUN(c, MOVE_RUSH_GUARD);
    c->mvcfg.rush.min_distance = TUN(c, MOVE_MIN_RUSH);
    c->mvcfg.jogjog.min_distance = TUN(c, MOVE_MIN_JOGJOG);
    c->mvcfg.jog.min_distance = TUN(c, MOVE_MIN_JOG);
    c->mvcfg.max_hops = (int)TUN(c, MOVE_MAX_HOPS);
}

/* ================================================================================================ */
/* point flow                                                                                        */
/* ================================================================================================ */
static void reset_player_point(Ts4SimPlayer *p)
{
    memset(&p->planner, 0, sizeof p->planner);
    p->planner.state = MV_WAIT;
    p->committed = -1;
    p->commit_valid = 0;
    p->swing_state = 0;
    p->held_ticks = 0;
    p->held_buttons = 0;
    p->ai_press = 0;
    p->vel[0] = p->vel[1] = p->vel[2] = 0.0f;
}

static void setup_serve(Ts4Core *c)
{
    int s, r;
    float zs;
    c->server = rules_server(&c->rules);
    s = c->server;
    r = s ^ 1;
    zs = (rules_serve_side(&c->rules) == 0 ? 1.0f : -1.0f) * right_sign(c, s);   /* server's z sign (deuce = right) */
    c->serve_target_z_sign = -zs;
    c->serve_second = c->rules.second_serve ? 1u : 0u;
    reset_player_point(&c->pl[0]);
    reset_player_point(&c->pl[1]);
    c->pl[s].pos[0] = own_sign(c, s) * TUN(c, SERVE_BASELINE_X_CM);
    c->pl[s].pos[2] = zs * TUN(c, SERVE_START_Z_CM);
    c->pl[r].pos[0] = own_sign(c, r) * TUN(c, RECEIVE_BASELINE_X_CM);
    c->pl[r].pos[2] = -zs * TUN(c, SERVE_START_Z_CM);
    c->pl[0].pos[1] = c->pl[1].pos[1] = 0.0f;
    c->pl[0].last_opp_hit_tick = c->pl[1].last_opp_hit_tick = (int32_t)c->tick;
    c->ball_live = 0;
    c->ball.active = 0;
    c->serve_flight = 0;
    c->last_hitter = -1;
    c->pred_n = 0;
    c->phase = TS4_PHASE_SERVE;
    c->phase_tick = 0;
}

static void emit_rule_events(Ts4Core *c, unsigned ev)
{
    if (ev & RULES_EV_FAULT) ts4_ev(c, TS4_EV_FAULT, 0, 0, 0, 0);
    if (ev & RULES_EV_DOUBLE_FAULT) ts4_ev(c, TS4_EV_DOUBLE_FAULT, 0, 0, 0, 0);
    if (ev & RULES_EV_LET) ts4_ev(c, TS4_EV_LET, 0, 0, 0, 0);
    if (ev & RULES_EV_GAME) ts4_ev(c, TS4_EV_GAME, 0, 0, 0, 0);
    if (ev & RULES_EV_SET) ts4_ev(c, TS4_EV_SET, 0, 0, 0, 0);
    if (ev & RULES_EV_MATCH) ts4_ev(c, TS4_EV_MATCH, c->rules.match_winner, 0, 0, 0);
    if (ev & RULES_EV_CHANGE_ENDS) ts4_ev(c, TS4_EV_CHANGE_ENDS, 0, 0, 0, 0);
}

static unsigned end_point(Ts4Core *c, rules_end_kind kind, int winner, int reason)
{
    unsigned ev = rules_end_point(&c->rules, kind, winner);
    emit_rule_events(c, ev);
    ts4_ev(c, TS4_EV_POINT_END, (ev & RULES_EV_POINT) ? c->rules.winner : -1, reason, (int32_t)ev, 0);
    c->ball_live = 0;
    c->ball.active = 0;
    c->serve_flight = 0;
    c->phase = TS4_PHASE_POINT_END;
    c->phase_tick = 0;
    return ev;
}

uint32_t ts4_debug_end_point(Ts4Core *c, uint32_t kind, int32_t winner)
{
    if (!c || c->magic != TS4_MAGIC || !c->started) return 0;
    return end_point(c, kind == 1 ? RULES_END_SERVE : (kind == 2 ? RULES_END_LET : RULES_END_RALLY), winner, TS4_REASON_NONE);
}

/* ================================================================================================ */
/* shots                                                                                             */
/* ================================================================================================ */
static void make_request(const Ts4Core *c, uint32_t buttons, float power, uint32_t type_id, int serve, Ts4ShotRequest *rq)
{
    memset(rq, 0, sizeof *rq);
    rq->classic_serve = serve ? 1u : 0u;
    rq->topspin = (buttons & TS4_BTN_TOPSPIN) != 0;
    rq->slice = (buttons & TS4_BTN_SLICE) != 0;
    rq->lob = (buttons & TS4_BTN_LOB) != 0;
    rq->risk = (buttons & TS4_BTN_RISK) != 0;
    rq->powerful = power > TUN(c, SHOT_TIER_POWERFUL);
    rq->medium = !rq->powerful && power > TUN(c, SHOT_TIER_MEDIUM);
    if (!serve) {
        rq->baseline = type_id == GP_ID_BASELINE;
        rq->smash = type_id == GP_ID_SMASH;
    }
}

static void launch_plan(Ts4Core *c, int shooter, const Ts4ShotPlan *plan, int serve)
{
    Gp4bSolve O;
    int32_t r = ts4_ball_launch(c, &c->ball, &plan->in, c->tick, &O);
    if (r) { /* unsolvable flight: treat as a shot into the net */
        end_point(c, serve ? RULES_END_SERVE : RULES_END_RALLY, shooter ^ 1, TS4_REASON_NET);
        return;
    }
    c->ball.cord_sign = (ts4_rng_range(&c->rng, 0.0f, 1.0f) < 0.5f) ? 1 : -1;
    c->ball_live = 1;
    c->last_hitter = shooter;
    c->last_shot_mode = plan->outcome;
    c->last_shot_row = plan->row;
    c->first_bounce_done = 0;
    c->net_touched = 0;
    c->bounces_side[0] = c->bounces_side[1] = 0;
    c->pl[shooter].template_row = (uint32_t)plan->row;
    c->pl[shooter ^ 1].last_opp_hit_tick = (int32_t)c->tick;
    c->pl[shooter ^ 1].commit_valid = 0;
    c->pl[shooter ^ 1].committed = -1;
    c->phase = TS4_PHASE_RALLY;
    c->phase_tick = 0;
    ts4_ev(c, TS4_EV_HIT, shooter, plan->row, (int32_t)plan->outcome, plan->in.from);
    predict(c);
}

static void do_serve(Ts4Core *c, int i, uint32_t buttons, float power, float aim_fwd, float aim_side)
{
    Ts4SimPlayer *p = &c->pl[i];
    Ts4ShotRequest rq;
    Ts4ShotPlan plan;
    float contact[3];
    contact[0] = p->pos[0];
    contact[1] = TUN(c, SERVE_CONTACT_H_CM);
    contact[2] = p->pos[2];
    make_request(c, buttons, power, 0, 1, &rq);
    if (ts4_shot_plan(c, p, &rq, contact, own_sign(c, i), aim_fwd, aim_side, power, 1, c->serve_target_z_sign, &plan) != TS4_OK) {
        end_point(c, RULES_END_SERVE, i ^ 1, TS4_REASON_FAULT);
        return;
    }
    ts4_ev(c, TS4_EV_SERVE, i, (int32_t)c->serve_second, 0, 0);
    p->swing_state = 2;
    p->swing_end_tick = (int32_t)c->tick + (int32_t)TUN(c, SWING_RECOVERY);
    launch_plan(c, i, &plan, 1);
    if (c->ball_live) c->serve_flight = 1;
}

/* contact: the swing reached its contact tick */
static void perform_hit(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    GpWindowParams wp;
    Ts4ShotRequest rq;
    Ts4ShotPlan plan;
    float bp[3], d, reach;
    uint32_t type;
    window_params(c, p, &wp);
    reach = wp.reach_radius + TUN(c, SWING_SLACK_CM);
    p->swing_state = 2;
    p->swing_end_tick = (int32_t)c->tick + (int32_t)TUN(c, SWING_RECOVERY);
    if (!c->ball_live || c->last_hitter == i || (c->serve_flight && c->ball.ground_bounces == 0)) {
        ts4_ev(c, TS4_EV_WHIFF, i, 0, 0, 0);
        return;
    }
    ts4_ball_world_pos(&c->ball, bp);
    d = sqrtf((bp[0] - p->pos[0]) * (bp[0] - p->pos[0]) + (bp[2] - p->pos[2]) * (bp[2] - p->pos[2]));
    type = classify(&wp, bp, (int)c->ball.ground_bounces);
    if (d > reach || type == wp.id_none) {
        ts4_ev(c, TS4_EV_WHIFF, i, 0, 0, 0);
        return;
    }
    make_request(c, p->swing_buttons, p->swing_power, type, 0, &rq);
    if (ts4_shot_plan(c, p, &rq, bp, own_sign(c, i), p->swing_aim_x, p->swing_aim_z, p->swing_power, 0, 0.0f, &plan) != TS4_OK) {
        ts4_ev(c, TS4_EV_WHIFF, i, 1, 0, 0);
        return;
    }
    launch_plan(c, i, &plan, 0);
}

/* A shot button was released: start the swing, or serve. */
static void on_release(Ts4Core *c, int i, uint32_t buttons, float power, float aim_fwd, float aim_side)
{
    Ts4SimPlayer *p = &c->pl[i];
    if (c->phase == TS4_PHASE_SERVE) {
        if (i == c->server) do_serve(c, i, buttons, power, aim_fwd, aim_side);
        return;
    }
    if (c->phase != TS4_PHASE_RALLY || p->swing_state != 0 || !c->ball_live || c->last_hitter == i) return;
    {
        float vx = p->vel[0], vz = p->vel[2];
        float t_delay = TUN(c, SWING_CONTACT_DELAY);
        float fx = p->pos[0] + vx * (t_delay * TICK_DT), fz = p->pos[2] + vz * (t_delay * TICK_DT);
        GpWindowParams wp;
        uint32_t k;
        float reach;
        int32_t t0 = (int32_t)c->tick + (int32_t)t_delay, hit_tick = t0;
        window_params(c, p, &wp);
        reach = wp.reach_radius + TUN(c, SWING_SLACK_CM);
        for (k = 0; k < c->pred_n; k++) {
            const Ts4PredSample *s = &c->pred[k];
            float dx, dz;
            if (s->tick < t0) continue;
            if (c->serve_flight && s->bounce == 0) continue;
            if (s->pos[0] * own_sign(c, i) <= TUN(c, REACH_NET_MARGIN)) continue;
            if (classify(&wp, s->pos, s->bounce) == wp.id_none) continue;
            dx = s->pos[0] - fx; dz = s->pos[2] - fz;
            if (sqrtf(dx * dx + dz * dz) <= reach) { hit_tick = s->tick; break; }
        }
        p->swing_state = 1;
        p->swing_contact_tick = hit_tick;
        p->swing_buttons = buttons;
        p->swing_power = power;
        p->swing_aim_x = aim_fwd;
        p->swing_aim_z = aim_side;
        p->vars[TS4_V_SWING_SPEED_COEF] = 1.0f;
        ts4_role_run(c, TS4_R_SWING_SPEED_COEF, p->vars);
    }
}

/* ================================================================================================ */
/* AI: candidate evaluation and virtual input (gp2 + movement-and-ai.md: the AI uses the same pipeline)   */
/* ================================================================================================ */
static void ai_commit(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    GpWindowParams wp;
    GpMoveMode mode;
    uint32_t k, n = 0;
    int best = -1, pass;
    float margin = TUN(c, REACH_NET_MARGIN), osign = own_sign(c, i);
    window_params(c, p, &wp);
    p->committed = -1;
    p->commit_valid = 0;
    for (k = 0; k < c->pred_n && n < GP_MAX_SAMPLES; k++) {
        const Ts4PredSample *s = &c->pred[k];
        if (s->pos[0] * osign <= margin) continue;
        if (c->serve_flight && s->bounce == 0) continue;
        c->cand_samples[n].local_x = s->pos[0];
        c->cand_samples[n].local_y = s->pos[1];
        c->cand_samples[n].local_z = s->pos[2];
        c->cand_samples[n].time_frame = s->tick;
        c->cand_samples[n].bounce_index = s->bounce;
        c->cand_pred_index[n] = (int32_t)k;
        c->cand_dist[n] = sqrtf((s->pos[0] - p->pos[0]) * (s->pos[0] - p->pos[0]) + (s->pos[2] - p->pos[2]) * (s->pos[2] - p->pos[2]));
        n++;
    }
    if (!n) return;
    gp_window_build(&c->win, c->cand_samples, c->cand_dist, (int)n, &wp, (int)c->tick, 0.0f);
    for (pass = 0; pass < 2 && best < 0; pass++) {
        uint32_t j;
        mode.allow_volley = 1;
        mode.smash_only = pass;
        mode.speed_limit_other = mode.speed_limit_volley = TUN(c, REACH_SCORE_MAX_SPEED);
        gp_sel_extract_rows(&c->sel, &c->win, &mode, 1, GP_ID_VOLLEY, GP_ID_SMASH);
        for (j = 0; j < (uint32_t)c->win.count; j++) c->sel.score[j] = -1.0f;
        for (j = 0; j < (uint32_t)c->sel.row_count; j++) {
            int idx;
            for (idx = c->sel.rows[j].first; idx <= c->sel.rows[j].last; idx++) {
                float reach_speed = c->win.reach_speed[idx];
                float *v = p->vars;
                int volley = c->win.type_id[idx] == GP_ID_VOLLEY;
                if (reach_speed > TUN(c, REACH_SCORE_MAX_SPEED)) { c->sel.score[idx] = -1.0f; continue; }
                v[TS4_V_REACH_SPEED] = reach_speed;
                v[TS4_V_BALL_DIST_M] = c->cand_dist[idx] * 0.01f;
                v[TS4_V_INPUT_NOTATION] = 0.0f;           /* AI feeds nothing (ai_driver.c) */
                v[TS4_V_HIT_HEIGHT_CM] = c->win.pos[idx][1];
                {
                    float dt = (float)(c->cand_samples[idx].time_frame - c->cand_samples[0].time_frame);
                    v[TS4_V_TICKS_SINCE_FIRST] = dt < 0.0f ? -1000.0f : dt;
                }
                v[TS4_V_SELECTION_SCORE] = -1.0f;
                ts4_role_run(c, TS4_R_SHOT_DIFFICULTY, v);
                if (ts4_role_run(c, volley ? TS4_R_SELECTION_VOLLEY : TS4_R_SELECTION_GROUND, v))
                    c->sel.score[idx] = v[TS4_V_SELECTION_SCORE];
                else
                    c->sel.score[idx] = 1.0f / (1.0f + reach_speed);   /* fallback policy: least effort wins */
            }
        }
        best = gp_select_best(&c->sel, &c->win, 0, 0, -1.0f, GP_ID_VOLLEY);
    }
    if (best >= 0) {
        const Ts4PredSample *s = &c->pred[c->cand_pred_index[best]];
        p->committed = best;
        p->commit_valid = 1;
        p->commit_tick = s->tick;
        p->commit_pos[0] = s->pos[0]; p->commit_pos[1] = s->pos[1]; p->commit_pos[2] = s->pos[2];
    }
}

/* stick toward (tx, tz) in the player's own frame; intensity limited so the player lands on the point */
static void stick_toward(const Ts4Core *c, int i, float tx, float tz, float speed_cms, Ts4Input *in)
{
    const Ts4SimPlayer *p = &c->pl[i];
    float dx = tx - p->pos[0], dz = tz - p->pos[2], d = sqrtf(dx * dx + dz * dz), k;
    if (d < 0.5f) { in->stick_x = in->stick_z = 0.0f; return; }
    k = clampf(d * 60.0f / speed_cms, 0.0f, 1.0f);
    in->stick_x = (dx / d) * k * (-own_sign(c, i));
    in->stick_z = (dz / d) * k * right_sign(c, i);
}

static void ai_think(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    Ts4Input in;
    GpWindowParams wp;
    float tx, tz, speed = TUN(c, MOVE_SPEED_JOG);
    int32_t delay = (int32_t)TUN(c, SWING_CONTACT_DELAY);
    int32_t hold = (int32_t)(TUN(c, FLOW_AI_POWER) * TUN(c, SHOT_CHARGE_TICKS));
    int incoming = c->ball_live && c->last_hitter == (i ^ 1);
    memset(&in, 0, sizeof in);
    window_params(c, p, &wp);
    tx = own_sign(c, i) * TUN(c, RECEIVE_BASELINE_X_CM);
    tz = 0.0f;
    p->ai_buttons = 0;

    if (c->phase == TS4_PHASE_SERVE) {
        if (i == c->server) {
            int32_t t0 = (int32_t)TUN(c, FLOW_AI_SERVE_DELAY);
            int32_t pt = (int32_t)c->phase_tick;
            tx = p->pos[0]; tz = p->pos[2];
            if (pt >= t0 && pt < t0 + hold + 1) in.buttons = c->serve_second ? TS4_BTN_TOPSPIN : TS4_BTN_FLAT;
        }
    } else if (incoming) {
        if (!p->commit_valid) ai_commit(c, i);
        if (p->commit_valid) {
            struct mv_world w;
            int regime, cleared;
            float dist, slack, rush_speed = TUN(c, MOVE_SPEED_RUSH);
            int32_t dt = p->commit_tick - (int32_t)c->tick;
            uint32_t type = classify(&wp, p->commit_pos, 0);
            tx = p->commit_pos[0]; tz = p->commit_pos[2];
            dist = sqrtf((tx - p->pos[0]) * (tx - p->pos[0]) + (tz - p->pos[2]) * (tz - p->pos[2]));
            slack = (float)dt - (type == GP_ID_VOLLEY ? wp.prep_frames_volley : wp.prep_frames_other);
            regime = mv_select_move_state(&c->mvcfg, 0, 0, type == GP_ID_VOLLEY, p->vars[TS4_V_STAT_SPEED], dist, slack,
                                          move_table, c, &cleared);
            if (regime == MV_RUSH) { in.buttons |= TS4_BTN_SPRINT; speed = rush_speed; }
            /* planner state machine, wired as far as the predicates are decoded (movement-and-ai.md) */
            memset(&w, 0, sizeof w);
            w.frame = (int)c->tick;
            w.frames_since_opp_hit = (int)c->tick - p->last_opp_hit_tick;
            w.rally_active = 1;
            w.sets_valid = 1;
            w.sel_from_anticipate = p->planner.state;
            w.pending_candidate = 1;
            w.can_start_swing = dt <= delay + 1 && dist <= wp.reach_radius + TUN(c, SWING_SLACK_CM);
            w.can_reach = !w.can_start_swing && dist <= wp.reach_radius;
            w.candidate_index = p->committed;
            w.slack_distance = dist;
            w.rush_ok_flag = 1;
            {
                struct mv_out out;
                mv_update(&p->planner, &c->mvcfg, &w, &out);
            }
            /* swing: press for `hold` ticks ending one tick before the release that starts the swing */
            if (dt >= delay + 1 && dt <= delay + 1 + hold) {
                in.buttons |= (type == GP_ID_BASELINE) ? TS4_BTN_TOPSPIN : TS4_BTN_FLAT;
            }
            if (dt == delay) {                             /* release tick: the stick is the aim */
                const Ts4SimPlayer *o = &c->pl[i ^ 1];
                float away = ((o->pos[2] * right_sign(c, i)) > (p->pos[2] * right_sign(c, i))) ? -1.0f : 1.0f;
                in.stick_x = 0.0f;
                in.stick_z = away;
                p->in = in;
                return;
            }
        } else {
            p->planner.state = MV_WAIT;
        }
    }
    if (!incoming) p->planner.state = MV_WAIT;
    stick_toward(c, i, tx, tz, speed, &in);
    p->in = in;
}

/* ================================================================================================ */
/* players                                                                                           */
/* ================================================================================================ */
static void player_update(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    const Ts4Input *in = &p->in;
    uint32_t down = in->buttons & SHOT_BUTTONS, was = p->prev_buttons & SHOT_BUTTONS;
    float osign = own_sign(c, i), rsign = right_sign(c, i);
    float mx, mz, mag, speed, dvx, dvz, dv, maxdv, vx, vz;
    float half_len = TUN(c, COURT_HALF_LENGTH_CM), w = TUN(c, COURT_HALF_WIDTH_S_CM);

    /* shot button: hold = charge, release = swing / serve */
    if (down) {
        p->held_buttons |= down;
        p->held_ticks++;
    } else if (was) {
        float power = clampf((float)p->held_ticks / TUN(c, SHOT_CHARGE_TICKS), 0.0f, 1.0f);
        uint32_t buttons = p->held_buttons | (in->buttons & TS4_BTN_RISK) | (p->prev_buttons & TS4_BTN_RISK);
        float aim_fwd = clampf(in->stick_x, -1.0f, 1.0f), aim_side = clampf(in->stick_z, -1.0f, 1.0f);
        p->held_ticks = 0;
        p->held_buttons = 0;
        on_release(c, i, buttons, power, aim_fwd, aim_side);
    }
    p->prev_buttons = in->buttons;

    /* locomotion: stick = direction, regime = speed (Rush with the sprint button, Jog above half stick, else walk) */
    mx = clampf(in->stick_x, -1.0f, 1.0f) * (-osign);
    mz = clampf(in->stick_z, -1.0f, 1.0f) * rsign;
    mag = sqrtf(mx * mx + mz * mz);
    if (mag > 1.0f) { mx /= mag; mz /= mag; mag = 1.0f; }
    speed = (in->buttons & TS4_BTN_SPRINT) ? TUN(c, MOVE_SPEED_RUSH) : (mag >= 0.5f ? TUN(c, MOVE_SPEED_JOG) : TUN(c, MOVE_SPEED_WALK));
    if (in->buttons & TS4_BTN_SPRINT) {
        p->vars[TS4_V_RUSH_SPEED_COEF] = 1.0f;
        if (ts4_role_run(c, TS4_R_RUSH_SPEED_COEF, p->vars) && p->vars[TS4_V_RUSH_SPEED_COEF] > 0.0f) speed *= p->vars[TS4_V_RUSH_SPEED_COEF];
    }
    if (p->swing_state == 1) { mx = mz = 0.0f; }
    dvx = mx * speed - p->vel[0];
    dvz = mz * speed - p->vel[2];
    dv = sqrtf(dvx * dvx + dvz * dvz);
    maxdv = TUN(c, MOVE_ACCEL) * TICK_DT;
    if (dv > maxdv && dv > 0.0f) { dvx *= maxdv / dv; dvz *= maxdv / dv; }
    vx = p->vel[0] + dvx;
    vz = p->vel[2] + dvz;
    p->vel[0] = vx; p->vel[2] = vz;
    p->pos[0] += vx * TICK_DT;
    p->pos[2] += vz * TICK_DT;
    p->pos[0] = clampf(p->pos[0] * osign, 10.0f, half_len + 500.0f) * osign;     /* stay on the own half of the net */
    p->pos[2] = clampf(p->pos[2], -(w + 400.0f), w + 400.0f);
    if (vx * vx + vz * vz > 1.0f) p->heading = atan2f(vz, vx);
    else p->heading = atan2f(0.0f, -osign);
    if (!p->setup.human) { /* planner state already updated in ai_think */ }
    else p->planner.state = (in->buttons & TS4_BTN_SPRINT) ? MV_RUSH : (mag >= 0.5f ? MV_JOG : (mag > 0.0f ? MV_APPROACH : MV_HOLD));

    /* swing state machine */
    if (p->swing_state == 1 && (int32_t)c->tick >= p->swing_contact_tick) perform_hit(c, i);
    else if (p->swing_state == 2 && (int32_t)c->tick >= p->swing_end_tick) p->swing_state = 0;
}

/* ================================================================================================ */
/* judge                                                                                             */
/* ================================================================================================ */
static void judge(Ts4Core *c, const Ts4BallEvents *ev)
{
    int hitter = c->last_hitter, opp = hitter ^ 1;
    float opp_sign = own_sign(c, opp);          /* x sign of the half the shooter aims at */
    float tol = 2.0f * TUN(c, BALL_RADIUS_CM), w = TUN(c, COURT_HALF_WIDTH_S_CM);
    if (ev->net_hit) {
        ts4_ev(c, TS4_EV_NET, ev->net_hit, 0, 0, ev->at);
        if (ev->net_hit == 1) {
            if (c->serve_flight) end_point(c, RULES_END_SERVE, opp, TS4_REASON_FAULT);
            else end_point(c, RULES_END_RALLY, opp, TS4_REASON_NET);
            return;
        }
        c->net_touched = 1;
    }
    if (ev->bounced) {
        int half = ev->at[0] < 0.0f ? 0 : 1;
        ts4_ev(c, TS4_EV_BOUNCE, (int32_t)c->ball.ground_bounces, 0, 0, ev->at);
        c->bounces_side[half]++;
        if (!c->first_bounce_done) {
            float nx = ev->at[0] * opp_sign, z = ev->at[2];
            c->first_bounce_done = 1;
            c->first_bounce[0] = ev->at[0]; c->first_bounce[1] = ev->at[1]; c->first_bounce[2] = ev->at[2];
            if (c->serve_flight) {
                float zs = c->serve_target_z_sign;
                int in_box = nx > 0.0f && nx <= TUN(c, COURT_SERVICE_X_CM) + tol &&
                             (zs > 0.0f ? (z >= -tol && z <= w + tol) : (z <= tol && z >= -w - tol));
                if (!in_box) { end_point(c, RULES_END_SERVE, opp, TS4_REASON_SERVE_OUT_OF_BOX); return; }
                if (c->net_touched) { end_point(c, RULES_END_LET, -1, TS4_REASON_LET); return; }
                c->serve_flight = 0;
            } else {
                int in_court = nx > 0.0f && nx <= TUN(c, COURT_HALF_LENGTH_CM) + tol && absf(z) <= w + tol;
                if (!in_court) { end_point(c, RULES_END_RALLY, opp, TS4_REASON_OUT); return; }
            }
        } else if (c->bounces_side[half] >= 2) {
            end_point(c, RULES_END_RALLY, hitter, half == (opp_sign < 0.0f ? 0 : 1) ? TS4_REASON_NO_RETURN : TS4_REASON_DOUBLE_BOUNCE);
            return;
        }
    }
    if (ts4_ball_dead(&c->ball)) {
        if (!c->first_bounce_done || c->serve_flight) {
            if (c->serve_flight) end_point(c, RULES_END_SERVE, opp, TS4_REASON_FAULT);
            else end_point(c, RULES_END_RALLY, opp, TS4_REASON_OUT);
        } else {
            end_point(c, RULES_END_RALLY, hitter, TS4_REASON_NO_RETURN);
        }
    }
}

static void update_snapshot(Ts4Core *c);

/* ================================================================================================ */
/* match                                                                                             */
/* ================================================================================================ */
int32_t ts4_match_start(Ts4Core *c, const Ts4MatchConfig *cfg)
{
    rules_config rc;
    uint32_t m;
    int i, k;
    if (!c || c->magic != TS4_MAGIC || !cfg || cfg->struct_size < sizeof(Ts4MatchConfig)) return TS4_ERR_ARG;
    for (m = 0; m < TS4_MOD_COUNT; m++)
        if (c->mod_status[m] == TS4_STATUS_MISSING_DATA) return TS4_ERR_MISSING_DATA;
    c->cfg = *cfg;
    ts4_rng_seed(&c->rng, cfg->seed);
    rc.games_per_set = cfg->games_per_set;
    rc.num_sets = cfg->num_sets;
    rc.tiebreak_only_sets = cfg->tiebreak_only_sets != 0;
    rc.final_set_super_tb = cfg->final_set_super_tb != 0;
    rc.short_format = cfg->short_format != 0;
    rc.single_serve = cfg->single_serve != 0;
    rules_init(&c->rules, &rc, cfg->first_server);
    setup_mvcfg(c);
    for (i = 0; i < 2; i++) {
        Ts4SimPlayer *p = &c->pl[i];
        memset(p, 0, sizeof *p);
        p->setup = cfg->players[i];
        for (k = 0; k < TS4_STAT_COUNT; k++) p->vars[TS4_V_STAT_SERVE + k] = cfg->players[i].stats[k];
        ts4_role_run(c, TS4_R_DEFAULT_ATTRIBUTES, p->vars);
        p->committed = -1;
    }
    memset(&c->ball, 0, sizeof c->ball);
    c->tick = 0;
    c->ev_head = c->ev_tail = 0;
    c->started = 1;
    setup_serve(c);
    update_snapshot(c);
    return TS4_OK;
}

int32_t ts4_set_input(Ts4Core *c, uint32_t player, const Ts4Input *in)
{
    if (!c || c->magic != TS4_MAGIC || player > 1 || !in) return TS4_ERR_ARG;
    if (!c->started) return TS4_ERR_NOT_STARTED;
    if (c->pl[player].setup.human) c->pl[player].in = *in;
    return TS4_OK;
}

static void update_snapshot(Ts4Core *c)
{
    Ts4Snapshot *s = &c->snap;
    int i, k;
    s->struct_size = sizeof(Ts4Snapshot);
    s->tick = c->tick;
    s->phase = c->phase;
    s->point_ticks = c->phase_tick;
    if (c->ball_live || c->ball.active) {
        float vel[3];
        ts4_ball_world_pos(&c->ball, s->ball.pos);
        ts4_ball_world_vel(&c->ball, vel);
        for (k = 0; k < 3; k++) s->ball.vel[k] = vel[k];
        s->ball.spin[0] = c->ball.b.spin_a; s->ball.spin[1] = c->ball.b.spin_b; s->ball.spin[2] = c->ball.b.spin_c;
        s->ball.mode = c->ball.b.mode;
        s->ball.bounce_count = c->ball.ground_bounces;
    } else if (c->phase == TS4_PHASE_SERVE) {
        const Ts4SimPlayer *sv = &c->pl[c->server];
        s->ball.pos[0] = sv->pos[0]; s->ball.pos[1] = TUN(c, SERVE_CONTACT_H_CM); s->ball.pos[2] = sv->pos[2];
        for (k = 0; k < 3; k++) s->ball.vel[k] = 0.0f;
        s->ball.bounce_count = 0;
    }
    s->ball.live = c->ball_live;
    s->ball.last_hitter = (uint32_t)c->last_hitter;
    for (i = 0; i < 2; i++) {
        const Ts4SimPlayer *p = &c->pl[i];
        Ts4PlayerView *v = &s->players[i];
        for (k = 0; k < 3; k++) { v->pos[k] = p->pos[k]; v->vel[k] = p->vel[k]; }
        v->heading = p->heading;
        v->move_state = (uint32_t)p->planner.state;
        v->swing_state = p->swing_state;
        v->swing_t = 0.0f;
        if (p->swing_state == 1) {
            float total = TUN(c, SWING_CONTACT_DELAY);
            float left = (float)(p->swing_contact_tick - (int32_t)c->tick);
            v->swing_t = total > 0.0f ? clampf(1.0f - left / total, 0.0f, 1.0f) : 1.0f;
        }
        v->template_row = p->template_row;
        v->flags = (c->server == i ? 1u : 0u) | (p->setup.left_handed ? 2u : 0u) | (p->setup.human ? 4u : 0u);
    }
    {
        Ts4ScoreView *sc = &s->score;
        const rules_state *r = &c->rules;
        for (i = 0; i < 2; i++) {
            for (k = 0; k < 5; k++) sc->games[i][k] = r->p[i].sets[k].games;
            sc->sets_won[i] = r->p[i].sets_won;
            sc->display[i] = rules_display(r, i);
        }
        sc->cur_set = r->cur_set;
        sc->server = rules_server(r);
        sc->serve_side = rules_serve_side(r);
        sc->second_serve = r->second_serve;
        sc->tiebreak = r->tiebreak;
        sc->match_over = r->match_over;
        sc->winner = r->match_winner;
        sc->ends_swapped = r->ends_swapped;
    }
    s->status_flags = c->pred_n ? 1u : 0u;
}

void ts4_step(Ts4Core *c)
{
    int i;
    if (!c || c->magic != TS4_MAGIC || !c->started) return;
    c->tick++;
    c->phase_tick++;

    if (c->phase == TS4_PHASE_RALLY && c->ball_live) {
        Ts4BallEnv env;
        Ts4BallEvents ev;
        ts4_ball_env(c, &env);
        ts4_ball_tick(c, &c->ball, &env, &ev);
        judge(c, &ev);
    }
    if (c->phase != TS4_PHASE_MATCH_OVER) {
        for (i = 0; i < 2; i++) {
            if (!c->pl[i].setup.human) ai_think(c, i);
            player_update(c, i);
        }
    }
    if (c->phase == TS4_PHASE_POINT_END && c->phase_tick >= (uint32_t)TUN(c, FLOW_POINT_END_TICKS)) {
        if (c->rules.match_over) { c->phase = TS4_PHASE_MATCH_OVER; c->phase_tick = 0; }
        else setup_serve(c);
    }
    update_snapshot(c);
}

const Ts4Snapshot *ts4_snapshot(const Ts4Core *c) { return (c && c->magic == TS4_MAGIC) ? &c->snap : (const Ts4Snapshot *)0; }
uint32_t ts4_snapshot_size(void) { return (uint32_t)sizeof(Ts4Snapshot); }

uint32_t ts4_state_hash(const Ts4Core *c)
{
    uint32_t h = 2166136261u;
    if (!c || c->magic != TS4_MAGIC) return 0;
    h = ts4_hash_state(h, &c->tick, sizeof c->tick);
    h = ts4_hash_state(h, &c->phase, sizeof c->phase);
    h = ts4_hash_state(h, &c->phase_tick, sizeof c->phase_tick);
    h = ts4_hash_state(h, &c->rng, sizeof c->rng);
    h = ts4_hash_state(h, &c->rules, sizeof c->rules);
    h = ts4_hash_state(h, &c->ball.b, sizeof c->ball.b);
    h = ts4_hash_state(h, &c->ball.ground_bounces, sizeof c->ball.ground_bounces);
    h = ts4_hash_state(h, c->pl, sizeof c->pl);
    h = ts4_hash_state(h, &c->server, sizeof c->server);
    h = ts4_hash_state(h, &c->last_hitter, sizeof c->last_hitter);
    return h;
}
