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
static void ai_react(Ts4Core *c, int i);
static void fatigue_shot(Ts4Core *c, int i);
static void fatigue_point(Ts4Core *c);

/* ================================================================================================ */
/* fatigue: the decoded graphs (FatigueConst, FatigueIngame, 80ce1a10, ErrorMissFatiguePenalty, Vivacity, IsTired,  */
/* 9c8607a7; brain slots Volley, InputFiltering, daf2ecbd) run on the PlayerState image. How CurrentVigor (S+0xF54) */
/* is integrated is not decoded: fatigue.* tunables drive a port-policy integrator.                                 */
/* ================================================================================================ */
static void fatigue_graphs(Ts4Core *c, int i)
{
    static const char *names[] = {"FatigueConst", "FatigueIngame", "ErrorMissFatiguePenalty", "Vivacity", "IsTired",
                                  "InputFiltering", "Volley", "RushSpeedCoef", "VolleySpeedCoef"};
    static const uint32_t hashes[] = {0x80CE1A10u, 0x9C8607A7u, 0xDAF2ECBDu};
    uint32_t k;
    if (!ts4_bound(c)) return;
    for (k = 0; k < sizeof names / sizeof names[0]; k++) ts4_bgraph_h(c, ts4_crc32(names[k]), i);
    for (k = 0; k < 3; k++) ts4_bgraph_h(c, hashes[k], i);
}

/* S+0xF64 (#80ce1a10 OUT 1) is only labelled "VigorMax?" by the gameplay work and comes out near 0.69 for an
 * average profile, so it is not used as a cap: vigor stays in [0,1] (port policy). */
static float vigor_max(const Ts4SimPlayer *p) { (void)p; return 1.0f; }

static void fatigue_tick(Ts4Core *c, int i, float dist_cm)
{
    Ts4SimPlayer *p = &c->pl[i];
    p->run_dist_cm += dist_cm;
    if (!ts4_bound(c) || !TUN_HAS(c, FATIGUE_DRAIN)) return;
    PS_SET(p, 0xF54, clampf(PS_GET(p, 0xF54) - TUN(c, FATIGUE_DRAIN) * dist_cm * 0.01f * (1.0f - 0.5f * PS_GET(p, 0x668)),
                            0.0f, vigor_max(p)));
}

static void fatigue_shot(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    float pf;
    p->run_dist_cm = 0.0f;
    if (!ts4_bound(c) || !TUN_HAS(c, FATIGUE_SHOT)) return;
    pf = clampf(PS_GET(p, 0x778), 0.0f, 1.0f);
    PS_SET(p, 0xF24, PS_GET(p, 0xF24) + pf);                      /* SumPowerfulFactor */
    PS_SET(p, 0xF54, clampf(PS_GET(p, 0xF54) - TUN(c, FATIGUE_SHOT) * pf, 0.0f, vigor_max(p)));
}

static void fatigue_point(Ts4Core *c)
{
    int i;
    for (i = 0; i < 2; i++) {
        Ts4SimPlayer *p = &c->pl[i];
        if (!ts4_bound(c)) continue;
        if (TUN_HAS(c, FATIGUE_RECOVER)) {
            float r = PS_GET(p, 0xF58) > 0.0f ? PS_GET(p, 0xF58) : 1.0f;
            PS_SET(p, 0xF54, clampf(PS_GET(p, 0xF54) + TUN(c, FATIGUE_RECOVER) * r, 0.0f, vigor_max(p)));
        }
        fatigue_graphs(c, i);
    }
}

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
    p->charging = 0;
    p->charge_committed = 0;
    p->toss_tick = -1;
    p->serve_release_tick = -1;
    p->react_tick = 0;
    p->ai_stroke = 0;
    p->inside_out = 0;
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
    fatigue_point(c);
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
/* skill held by player i (SKIL list index of the skill whose crc32 is h) */
static int has_skill(const Ts4Core *c, int i, uint32_t h)
{
    uint32_t k, n;
    if (!c->ext.skil) return 0;
    n = ts4_le32(c->ext.skil);
    for (k = 0; k < n && k < 32; k++)
        if (ts4_le32(c->ext.skil + 4 + 4 * k) == h) return (c->extra[i].skill_mask >> k) & 1u;
    return 0;
}
#define SKILL_INSTANT_ROCKET 0x82E4BF1Au
#define SKILL_POISONED_SLICES 0x55568E39u

static int32_t lead_ticks(const Ts4Core *c)
{
    return TUN_HAS(c, SHOT_SWING_LEAD) ? (int32_t)TUN(c, SHOT_SWING_LEAD) : (int32_t)TUN(c, SWING_CONTACT_DELAY);
}

/* power of a charge of `frames` (G2b): curve16 cfg+0x8FC of frames / D; InstantRocket uses the alternative curve */
static float charge_power(const Ts4Core *c, int i, uint32_t frames)
{
    uint32_t ty, n;
    const uint8_t *k = 0;
    if (has_skill(c, i, SKILL_INSTANT_ROCKET)) k = ts4_curve_find(c, ts4_crc32("shot.power_alt"), &ty, &n);
    if (!k) k = ts4_curve_find(c, ts4_crc32("shot.power"), &ty, &n);
    if (k && ty == 0 && TUN_HAS(c, SHOT_POWER_DIV) && TUN(c, SHOT_POWER_DIV) > 0.0f)
        return ts4_curve16_le(k, n, (float)frames / TUN(c, SHOT_POWER_DIV));
    return clampf((float)frames / TUN(c, SHOT_CHARGE_TICKS), 0.0f, 1.0f);   /* earlier policy */
}

/* tier flags: the Finesse/Medium/Powerful graphs on ReceiverState #82526c5c.Value (S+0xE00), read as > 0.5 (G2b) */
static void tiers(Ts4Core *c, int i, float power, uint32_t *medium, uint32_t *powerful)
{
    Ts4SimPlayer *p = &c->pl[i];
    if (ts4_bound(c) && ts4_gfind(c, ts4_crc32("Medium")) >= 0 && ts4_gfind(c, ts4_crc32("Powerful")) >= 0) {
        PS_SET(p, 0xE00, power);
        ts4_bgraph_h(c, ts4_crc32("Finesse"), i);
        ts4_bgraph_h(c, ts4_crc32("Medium"), i);
        ts4_bgraph_h(c, ts4_crc32("Powerful"), i);
        *powerful = PS_GET(p, 0x3DC) > 0.5f;
        *medium = !*powerful && PS_GET(p, 0x3D8) > 0.5f;
        return;
    }
    *powerful = power > TUN(c, SHOT_TIER_POWERFUL);
    *medium = !*powerful && power > TUN(c, SHOT_TIER_MEDIUM);
}

static void make_request(Ts4Core *c, int i, uint32_t buttons, float power, uint32_t type_id, int serve, Ts4ShotRequest *rq)
{
    Ts4SimPlayer *p = &c->pl[i];
    memset(rq, 0, sizeof *rq);
    rq->classic_serve = serve ? 1u : 0u;
    rq->topspin = (buttons & TS4_BTN_TOPSPIN) != 0;
    rq->slice = (buttons & TS4_BTN_SLICE) != 0;
    rq->lob = (buttons & TS4_BTN_LOB) != 0;
    rq->risk = (buttons & TS4_BTN_RISK) != 0;
    if (serve && TUN_HAS(c, SERVE_POWERFUL)) {          /* serve tiers from PressAndHold (G2b) */
        rq->powerful = power > TUN(c, SERVE_POWERFUL);
        rq->medium = !(power < TUN(c, SERVE_MEDIUM)) && !rq->powerful;
    } else {
        tiers(c, i, power, &rq->medium, &rq->powerful);
    }
    if (!serve) {
        rq->baseline = type_id == GP_ID_BASELINE;
        rq->smash = type_id == GP_ID_SMASH;
        /* Wood: armed by the Wood evaluation graph (S+0x3EC), fires when |ManualShotTiming| >= 0.1 (G2b) */
        if (ts4_bound(c) && TUN_HAS(c, WOOD_TIMING) && ts4_bgraph_h(c, ts4_crc32("Wood"), i)) {
            float t = PS_GET(p, 0x544);
            rq->wood = PS_GET(p, 0x3EC) > 0.5f && (t >= TUN(c, WOOD_TIMING) || t <= -TUN(c, WOOD_TIMING));
        }
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
    c->pl[shooter].charging = 0;
    fatigue_shot(c, shooter);
    ai_react(c, shooter ^ 1);
    c->phase = TS4_PHASE_RALLY;
    c->phase_tick = 0;
    ts4_ev(c, TS4_EV_HIT, shooter, plan->row, (int32_t)plan->outcome, plan->in.from);
    predict(c);
}

/* shooter-local frame (own baseline at x < 0): LocalPosition S+0x8E0/0x8E8, LocalOpponentPosition S+0x910/0x918 */
static void write_shot_fields(Ts4Core *c, int i, const float contact[3], float power)
{
    Ts4SimPlayer *p = &c->pl[i], *o = &c->pl[i ^ 1];
    float m = -own_sign(c, i), bv[3] = {0.0f, 0.0f, 0.0f};
    int k;
    if (!ts4_bound(c)) return;
    PS_SET(p, 0xE00, power);
    PS_SET(p, 0x8E0, contact[0] * m); PS_SET(p, 0x8E8, contact[2] * m);
    PS_SET(p, 0x910, o->pos[0] * m); PS_SET(p, 0x918, o->pos[2] * m);
    if (c->ball_live) ts4_ball_world_vel(&c->ball, bv);
    PS_SET(p, 0x770, sqrtf(bv[0] * bv[0] + bv[1] * bv[1] + bv[2] * bv[2]) * 0.036f);   /* #1407106c km/h (I) */
    PS_SET(p, 0x7A0, p->run_dist_cm);                                                 /* #03d2be3d run cm (I) */
    PS_SET(p, 0x7D0, (c->last_hitter == (i ^ 1) && (c->pl[i ^ 1].swing_buttons & TS4_BTN_SLICE) &&
                      has_skill(c, i ^ 1, SKILL_POISONED_SLICES)) ? 1.0f : 0.0f);      /* PoisonedSlices, receiver */
    PS_SET(p, 0x6BC, TUN_HAS(c, SHOTDEF_POW_MIN) ? TUN(c, SHOTDEF_POW_MIN) : 0.0f);
    PS_SET(p, 0x6C0, TUN_HAS(c, SHOTDEF_POW_MAX) ? TUN(c, SHOTDEF_POW_MAX) : 1.0f);
    for (k = 0; k < 2; k++) {
        PS_SET(p, 0x6C4 + 8 * (uint32_t)k, TUN_HAS(c, SHOTDEF_AIM_MIN) ? TUN(c, SHOTDEF_AIM_MIN) : 0.0f);
        PS_SET(p, 0x6C8 + 8 * (uint32_t)k, TUN_HAS(c, SHOTDEF_AIM_MAX) ? TUN(c, SHOTDEF_AIM_MAX) : 1.0f);
    }
    PS_SET(p, 0x6D4, TUN_HAS(c, SHOTDEF_ERR_MIN) ? TUN(c, SHOTDEF_ERR_MIN) : 0.0f);
    PS_SET(p, 0x6D8, TUN_HAS(c, SHOTDEF_ERR_MAX) ? TUN(c, SHOTDEF_ERR_MAX) : 1.0f);
    ts4_fset(c->match_img, 0x334, (float)c->rally_shots);                              /* #8beb922e rally length */
    ts4_ball_img_sync(c);
    ts4_fset(c->ball_img, 0x340, contact[0]); ts4_fset(c->ball_img, 0x344, contact[1]); ts4_fset(c->ball_img, 0x348, contact[2]);
}

/* ManualShotTiming (S+0x544): AI = the difficulty's TimingExpression graph (g40); human = commit lead (policy) */
static void shot_timing(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    const uint8_t *rec = ts4_ai_record(c, c->extra[i].ai_style, c->extra[i].ai_level);
    float t = 0.0f;
    if (!ts4_bound(c)) return;
    if (!p->setup.human && rec && ts4_bgraph_h(c, ts4_le32(rec + TS4_AI_G40), i)) {
        ts4_bgraph_h(c, ts4_le32(rec + TS4_AI_G44), i);   /* FinalEfficiency */
        return;
    }
    if (TUN_HAS(c, TIMING_IDEAL) && TUN(c, TIMING_SCALE) > 0.0f)
        t = clampf((TUN(c, TIMING_IDEAL) - (float)p->charge_commit_lead) / TUN(c, TIMING_SCALE), -1.0f, 1.0f);
    PS_SET(p, 0x544, t);
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
    c->rally_shots = 0;
    write_shot_fields(c, i, contact, power);
    PS_SET(p, 0x670, power);                         /* PressAndHold */
    make_request(c, i, buttons, power, 0, 1, &rq);
    c->hit_is_return = 0;
    if (ts4_shot_plan(c, p, &rq, contact, own_sign(c, i), aim_fwd, aim_side, power, 1, c->serve_target_z_sign, &plan) != TS4_OK) {
        end_point(c, RULES_END_SERVE, i ^ 1, TS4_REASON_FAULT);
        return;
    }
    ts4_ev(c, TS4_EV_SERVE, i, (int32_t)c->serve_second, 0, 0);
    p->swing_state = 2;
    p->swing_end_tick = (int32_t)c->tick + (int32_t)TUN(c, SWING_RECOVERY);
    p->toss_tick = -1;
    c->rally_shots = 1;
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
    write_shot_fields(c, i, bp, p->swing_power);
    shot_timing(c, i);
    make_request(c, i, p->swing_buttons, p->swing_power, type, 0, &rq);
    c->hit_is_return = c->rally_shots == 1;
    if (ts4_shot_plan(c, p, &rq, bp, own_sign(c, i), p->swing_aim_x, p->swing_aim_z, p->swing_power, 0, 0.0f, &plan) != TS4_OK) {
        ts4_ev(c, TS4_EV_WHIFF, i, 1, 0, 0);
        return;
    }
    c->rally_shots++;
    launch_plan(c, i, &plan, 0);
}

/* first predicted sample at or after tick t0 that the player can reach (receiver side, after the serve bounce) */
static int32_t find_contact(const Ts4Core *c, int i, int32_t t0, float fx, float fz)
{
    const Ts4SimPlayer *p = &c->pl[i];
    GpWindowParams wp;
    uint32_t k;
    float reach;
    window_params(c, p, &wp);
    reach = wp.reach_radius + TUN(c, SWING_SLACK_CM);
    for (k = 0; k < c->pred_n; k++) {
        const Ts4PredSample *sm = &c->pred[k];
        float dx, dz;
        if (sm->tick < t0) continue;
        if (c->serve_flight && sm->bounce == 0) continue;
        if (sm->pos[0] * own_sign(c, i) <= TUN(c, REACH_NET_MARGIN)) continue;
        if (classify(&wp, sm->pos, sm->bounce) == wp.id_none) continue;
        dx = sm->pos[0] - fx; dz = sm->pos[2] - fz;
        if (sqrtf(dx * dx + dz * dz) <= reach) return sm->tick;
    }
    return -1;
}

/* the swing animation starts `lead` ticks before contact (G2b: planner and row choice 12 frames before contact) */
static void start_swing(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    GpWindowParams wp;
    float bp[3] = {0.0f, 0.0f, 0.0f};
    uint32_t type = GP_ID_BASELINE, k;
    float rs = right_sign(c, i);
    window_params(c, p, &wp);
    for (k = 0; k < c->pred_n; k++)
        if (c->pred[k].tick == p->swing_contact_tick) { bp[0] = c->pred[k].pos[0]; bp[1] = c->pred[k].pos[1]; bp[2] = c->pred[k].pos[2];
                                                          type = classify(&wp, bp, c->pred[k].bounce); break; }
    p->swing_state = 1;
    p->swing_buttons = p->charge_buttons;
    p->swing_power = p->charge_power;
    p->vars[TS4_V_SWING_SPEED_COEF] = 1.0f;
    if (ts4_bound(c)) ts4_bgraph_h(c, ts4_crc32("SwingSpeedCoef"), i);
    else ts4_role_run(c, TS4_R_SWING_SPEED_COEF, p->vars);
    {
        int fh = ((bp[2] * rs) >= (p->pos[2] * rs)) != (p->setup.left_handed != 0);
        ts4_anim_swing(c, i, p->swing_buttons, type == GP_ID_VOLLEY, type == GP_ID_SMASH, fh, c->rally_shots == 1,
                       p->swing_contact_tick - (int32_t)c->tick);
    }
}

/* shot button pressed during a rally: latch and start the charge counter (fn_88698538), choose the contact */
static void on_press(Ts4Core *c, int i, uint32_t buttons)
{
    Ts4SimPlayer *p = &c->pl[i];
    int32_t lead = lead_ticks(c), hit;
    if (c->phase != TS4_PHASE_RALLY || p->swing_state != 0 || p->charging || !c->ball_live || c->last_hitter == i) return;
    if (!p->setup.human && p->commit_valid) hit = p->commit_tick;
    else {
        float t = (float)lead * TICK_DT;
        hit = find_contact(c, i, (int32_t)c->tick + lead, p->pos[0] + p->vel[0] * t, p->pos[2] + p->vel[2] * t);
        if (hit < 0) hit = (int32_t)c->tick + lead;
    }
    p->charging = 1;
    p->charge_frames = 0;
    p->charge_committed = 0;
    p->charge_buttons = buttons;
    p->swing_contact_tick = hit;
}

/* per tick while charging: count, commit on release or when contact - now <= lead (fn ts4_charge_update) */
static void charge_update(Ts4Core *c, int i, int released, uint32_t buttons_now)
{
    Ts4SimPlayer *p = &c->pl[i];
    int32_t lead = lead_ticks(c), to_contact = p->swing_contact_tick - (int32_t)c->tick;
    if (!p->charging) return;
    if (!p->charge_committed) {
        p->charge_frames++;
        p->charge_buttons |= buttons_now & (SHOT_BUTTONS | TS4_BTN_RISK);
        if (released || to_contact <= lead) {
            float sx = clampf(p->in.stick_x, -1.0f, 1.0f), sz = clampf(p->in.stick_z, -1.0f, 1.0f);
            float mag = sqrtf(sx * sx + sz * sz);
            p->charge_committed = 1;
            p->charge_commit_lead = to_contact;
            p->charge_power = charge_power(c, i, p->charge_frames);
            p->swing_aim_x = sx;
            p->swing_aim_z = sz;
            ts4s_aim_from_stick(sz, sx, p->setup.left_handed != 0, &p->aim_angle, &p->aim_depth);
            /* LT forced side commit -> InsideOutRequested (S+0x5DC) */
            p->inside_out = TUN_HAS(c, LT_COMMIT_POWER) &&
                            ts4s_lt_forced_commit((p->charge_buttons & TS4_BTN_RISK) != 0, mag, atan2f(sx, sz), 0,
                                                  p->setup.left_handed != 0, TUN(c, LT_COMMIT_POWER), TUN(c, LT_COMMIT_ANGLE));
            if (ts4_bound(c)) { PS_SET(p, 0x5DC, p->inside_out ? 1.0f : 0.0f); PS_SET(p, 0x7C8, p->inside_out ? 1.0f : 0.0f); }
        }
    }
    if (p->charge_committed && to_contact <= lead) {
        p->charging = 0;
        start_swing(c, i);
    }
}

/* serve (G2b): input ignored for serve.input_delay ticks; press = toss; release = swing; automatic toss after
 * serve.auto ticks; contact countdown + lead after the toss; power = release fraction of the countdown;
 * timing (S+0x66C) = serve timing curve of frames release -> contact */
static void serve_input(Ts4Core *c, int i, int pressed, int released, uint32_t buttons)
{
    Ts4SimPlayer *p = &c->pl[i];
    int32_t cd = TUN_HAS(c, SERVE_COUNTDOWN) ? (int32_t)TUN(c, SERVE_COUNTDOWN) : 0;
    int32_t lead = TUN_HAS(c, SERVE_LEAD) ? (int32_t)TUN(c, SERVE_LEAD) : 0, contact;
    if (i != c->server || p->swing_state != 0) return;
    if (!cd) {                                       /* earlier policy: release serves at once */
        if (released) do_serve(c, i, p->held_buttons, clampf((float)p->held_ticks / TUN(c, SHOT_CHARGE_TICKS), 0.0f, 1.0f),
                               clampf(p->in.stick_x, -1.0f, 1.0f), clampf(p->in.stick_z, -1.0f, 1.0f));
        return;
    }
    if (p->toss_tick < 0) {
        int auto_toss = TUN_HAS(c, SERVE_AUTO) && c->phase_tick >= (uint32_t)TUN(c, SERVE_AUTO);
        if (TUN_HAS(c, SERVE_INPUT_DELAY) && c->phase_tick < (uint32_t)TUN(c, SERVE_INPUT_DELAY)) return;
        if (pressed || auto_toss) {
            p->toss_tick = (int32_t)c->tick;
            p->serve_release_tick = -1;
            p->charge_buttons = auto_toss && !pressed ? TS4_BTN_FLAT : buttons;
        }
        return;
    }
    contact = p->toss_tick + cd + lead;
    if (released && p->serve_release_tick < 0) p->serve_release_tick = (int32_t)c->tick;
    if ((int32_t)c->tick >= contact) {
        int rel = p->serve_release_tick >= 0;
        float power = ts4s_serve_power(p->serve_release_tick, p->toss_tick, cd, rel), timing = 1.0f;
        uint32_t ty, n;
        const uint8_t *k = ts4_curve_find(c, ts4_crc32("serve.timing"), &ty, &n);
        if (rel && k && ty == 0) timing = ts4_curve16_le(k, n, (float)(contact - p->serve_release_tick));
        if (ts4_bound(c)) PS_SET(p, 0x66C, timing);
        do_serve(c, i, p->charge_buttons, power, clampf(p->in.stick_x, -1.0f, 1.0f), clampf(p->in.stick_z, -1.0f, 1.0f));
    }
}

/* ================================================================================================ */
/* AI: candidate evaluation and virtual input (gp2 + movement-and-ai.md: the AI uses the same pipeline)   */
/* ================================================================================================ */
/* run a weighted behaviour list of an AI record: each entry's score graph writes AI+0x1A0 (#91329eea); the entry
 * with the best score * weight wins (the Default entry when none is positive, port policy for the tie rule) and
 * its mix graph writes the Shot/Serve/Repositioning/Positioning components. Returns 1 when a mix graph ran. */
static int ai_run_list(Ts4Core *c, int i, const uint8_t *rec, uint32_t list)
{
    Ts4SimPlayer *p = &c->pl[i];
    uint32_t n = ts4_le32(rec + TS4_AI_LCOUNT + 4 * list), off = ts4_le32(rec + TS4_AI_LOFF + 4 * list), k;
    int32_t best = -1, dflt = -1;
    float best_v = 0.0f;
    for (k = 0; k < n; k++) {
        const uint8_t *e = c->ext.aidf + off + 20 * k;
        float v;
        ts4_fset(p->ai, 0x1A0, 0.0f);
        if (!ts4_bgraph_h(c, ts4_le32(e), i)) continue;
        v = ts4_fget(p->ai, 0x1A0) * ts4_lef32(e + 8);
        if (ts4_lef32(e + 12) != 0.0f && dflt < 0) dflt = (int32_t)k;
        if (v > best_v) { best_v = v; best = (int32_t)k; }
    }
    if (best < 0) best = dflt >= 0 ? dflt : (n ? 0 : -1);
    if (best < 0) return 0;
    return ts4_bgraph_h(c, ts4_le32(c->ext.aidf + off + 20 * (uint32_t)best + 4), i);
}

/* AI shot choice from ShotComponents (AI+0x23C..): stroke = largest of Slice/TopSpin/Flat/Lob (DropShot -> Slice +
 * Risk), PressAndHold = charge, AimingSide/Length = stick (argmax: port policy for reading the mix) */
static void ai_plan_shot(Ts4Core *c, int i, const uint8_t *rec)
{
    Ts4SimPlayer *p = &c->pl[i];
    static const uint32_t btn[4] = {TS4_BTN_SLICE, TS4_BTN_TOPSPIN, TS4_BTN_FLAT, TS4_BTN_LOB};
    float v, best = -1.0f, sl, sc, sr, ls, lc, ll;
    uint32_t k;
    if (!ai_run_list(c, i, rec, c->rally_shots == 1 ? 1u : 0u)) return;   /* l0c return, l00 rally */
    for (k = 0; k < 4; k++) {
        v = ts4_fget(p->ai, 0x23C + 4 * k);
        if (v > best) { best = v; p->ai_stroke = btn[k]; }
    }
    if (ts4_fget(p->ai, 0x24C) > best) p->ai_stroke = TS4_BTN_SLICE | TS4_BTN_RISK;
    p->ai_power = clampf(ts4_fget(p->ai, 0x254), 0.0f, 1.0f);
    sl = ts4_fget(p->ai, 0x25C); sc = ts4_fget(p->ai, 0x260); sr = ts4_fget(p->ai, 0x264);
    ls = ts4_fget(p->ai, 0x268); lc = ts4_fget(p->ai, 0x26C); ll = ts4_fget(p->ai, 0x270);
    p->ai_aim_side = (sl > sc && sl > sr) ? -1.0f : ((sr > sc && sr > sl) ? 1.0f : 0.0f);
    p->ai_aim_len = (ls > lc && ls > ll) ? -1.0f : ((ll > lc && ll > ls) ? 1.0f : 0.0f);
    ts4_bgraph_h(c, ts4_le32(rec + TS4_AI_G54), i);   /* SwingReactionTime (AI+0x1C0) */
    ts4_bgraph_h(c, ts4_le32(rec + TS4_AI_G50), i);   /* EvaluationOutputs #4abbb588 */
}

/* the opponent hit: positioning list -> PositioningComponents #79b99b60 (AI+0x1DC) = reaction delay (G4b) */
static void ai_react(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    const uint8_t *rec;
    p->react_tick = (int32_t)c->tick;
    p->ai_stroke = 0;
    if (p->setup.human || !ts4_bound(c)) return;
    rec = ts4_ai_record(c, c->extra[i].ai_style, c->extra[i].ai_level);
    if (!rec) return;
    if (ai_run_list(c, i, rec, 4)) {
        float d = ts4_fget(p->ai, 0x1DC) * (TUN_HAS(c, AI_REACTION_SCALE) ? TUN(c, AI_REACTION_SCALE) : 1.0f);
        if (d > 0.0f && d < 600.0f) p->react_tick = (int32_t)c->tick + (int32_t)d;
    }
    ai_run_list(c, i, rec, 3);   /* repositioning components (RepositioningComponents) */
}

static void ai_commit(Ts4Core *c, int i)
{
    Ts4SimPlayer *p = &c->pl[i];
    GpWindowParams wp;
    GpMoveMode mode;
    uint32_t k, n = 0;
    int best = -1, pass;
    float margin = TUN(c, REACH_NET_MARGIN), osign = own_sign(c, i), min_rs = 1e30f;
    const uint8_t *rec = 0;
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
    if (ts4_bound(c)) rec = ts4_ai_record(c, c->extra[i].ai_style, c->extra[i].ai_level);
    for (k = 0; k < (uint32_t)c->win.count; k++)
        if (c->win.reach_speed[k] >= 0.0f && c->win.reach_speed[k] < min_rs) min_rs = c->win.reach_speed[k];
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
                if (rec) {   /* hit-point score graphs of the AI record (brain +0x158 / +0x19C) -> #3237ffac.Score */
                    PS_SET(p, 0xB90, c->win.pos[idx][1]);       /* BallHeight */
                    PS_SET(p, 0xB94, 0.0f);                     /* InputNotation: the AI feeds nothing */
                    PS_SET(p, 0xB9C, reach_speed);              /* ReachabilitySpeed */
                    PS_SET(p, 0xBA4, min_rs);                   /* MinReachabilitySpeed */
                    PS_SET(p, 0xBA8, -1.0f);
                    if (ts4_bgraph_h(c, ts4_le32(rec + (volley ? TS4_AI_G4C : TS4_AI_G48)), i)) {
                        c->sel.score[idx] = PS_GET(p, 0xBA8);
                        continue;
                    }
                }
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
        if (rec) ai_plan_shot(c, i, rec);
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
    int32_t delay = lead_ticks(c);
    int32_t hold = (int32_t)(TUN(c, FLOW_AI_POWER) * TUN(c, SHOT_CHARGE_TICKS));
    const uint8_t *rec = ts4_bound(c) ? ts4_ai_record(c, c->extra[i].ai_style, c->extra[i].ai_level) : 0;
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
            if (p->ai_stroke && TUN_HAS(c, SHOT_POWER_DIV))   /* PressAndHold -> frames on the 0..1.25 s power ramp */
                hold = (int32_t)(p->ai_power * 1.25f * TUN(c, SHOT_POWER_DIV));
            if (dt >= delay + 1 && dt <= delay + 1 + hold) {
                in.buttons |= p->ai_stroke ? p->ai_stroke : ((type == GP_ID_BASELINE) ? TS4_BTN_TOPSPIN : TS4_BTN_FLAT);
            }
            if (dt == delay) {                             /* release tick: the stick is the aim */
                const Ts4SimPlayer *o = &c->pl[i ^ 1];
                float away = ((o->pos[2] * right_sign(c, i)) > (p->pos[2] * right_sign(c, i))) ? -1.0f : 1.0f;
                in.stick_x = p->ai_stroke ? p->ai_aim_len : 0.0f;
                in.stick_z = p->ai_stroke ? (p->ai_aim_side != 0.0f ? p->ai_aim_side : away) : away;
                p->in = in;
                return;
            }
        } else {
            p->planner.state = MV_WAIT;
        }
    }
    if (!incoming) p->planner.state = MV_WAIT;
    if (rec && ts4_lef32(rec + TS4_AI_SPEED) > 0.0f && speed > 100.0f * ts4_lef32(rec + TS4_AI_SPEED))
        speed = 100.0f * ts4_lef32(rec + TS4_AI_SPEED);   /* run_speed_limit of the difficulty (m/s) */
    if (incoming && (int32_t)c->tick < p->react_tick) { in.stick_x = in.stick_z = 0.0f; p->in = in; return; }
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

    /* shot buttons (G2b): press latches the charge counter, release or the auto commit 12 ticks before contact
     * commits the shot; serve: press = toss, release = swing */
    if (down) {
        p->held_buttons |= down;
        p->held_ticks++;
    }
    if (c->phase == TS4_PHASE_SERVE) {
        serve_input(c, i, down && !was, !down && was, down | (in->buttons & TS4_BTN_RISK));
    } else {
        if (down && !was) on_press(c, i, down | (in->buttons & TS4_BTN_RISK));
        charge_update(c, i, !down && was, in->buttons);
    }
    if (!down) { p->held_ticks = 0; p->held_buttons = 0; }
    p->prev_buttons = in->buttons;

    /* locomotion: stick = direction, regime = speed (Rush with the sprint button, Jog above half stick, else walk) */
    mx = clampf(in->stick_x, -1.0f, 1.0f) * (-osign);
    mz = clampf(in->stick_z, -1.0f, 1.0f) * rsign;
    mag = sqrtf(mx * mx + mz * mz);
    if (mag > 1.0f) { mx /= mag; mz /= mag; mag = 1.0f; }
    speed = (in->buttons & TS4_BTN_SPRINT) ? TUN(c, MOVE_SPEED_RUSH) : (mag >= 0.5f ? TUN(c, MOVE_SPEED_JOG) : TUN(c, MOVE_SPEED_WALK));
    if (in->buttons & TS4_BTN_SPRINT) {
        if (ts4_bound(c)) {   /* RushSpeedCoef graph (Profile.Speed, CurrentVigor) -> S+0x398 */
            if (ts4_bgraph_h(c, ts4_crc32("RushSpeedCoef"), i) && PS_GET(p, 0x398) > 0.0f) speed *= PS_GET(p, 0x398);
        } else {
            p->vars[TS4_V_RUSH_SPEED_COEF] = 1.0f;
            if (ts4_role_run(c, TS4_R_RUSH_SPEED_COEF, p->vars) && p->vars[TS4_V_RUSH_SPEED_COEF] > 0.0f) speed *= p->vars[TS4_V_RUSH_SPEED_COEF];
        }
    }
    if (TUN_HAS(c, SPEED_OVERRIDE_EPS)) {   /* speed override S+0xDE8: changes only beyond 0.4 m/s (lo_override_update) */
        float prop = speed * 0.01f;
        if (absf(prop - p->speed_override) > TUN(c, SPEED_OVERRIDE_EPS) || mag == 0.0f) p->speed_override = prop;
        speed = p->speed_override * 100.0f;
        if (ts4_bound(c)) PS_SET(p, 0xDE8, p->speed_override);
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
    fatigue_tick(c, i, sqrtf(vx * vx + vz * vz) * TICK_DT);
    p->pos[0] = clampf(p->pos[0] * osign, 10.0f, half_len + 500.0f) * osign;     /* stay on the own half of the net */
    p->pos[2] = clampf(p->pos[2], -(w + 400.0f), w + 400.0f);
    if (vx * vx + vz * vz > 1.0f) p->heading = atan2f(vz, vx);
    else p->heading = atan2f(0.0f, -osign);
    if (!p->setup.human) { /* planner state already updated in ai_think */ }
    else p->planner.state = (in->buttons & TS4_BTN_SPRINT) ? MV_RUSH : (mag >= 0.5f ? MV_JOG : (mag > 0.0f ? MV_APPROACH : MV_HOLD));

    /* swing state machine */
    if (p->swing_state == 1 && (int32_t)c->tick >= p->swing_contact_tick) perform_hit(c, i);
    else if (p->swing_state == 2 && (int32_t)c->tick >= p->swing_end_tick) p->swing_state = 0;
    ts4_anim_tick(c, i);
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
        p->toss_tick = -1;
        ts4_anim_reset(c, i);
    }
    ts4_images_init(c);   /* State.bin defaults of every bound field (SINI) */
    c->rally_shots = 0;
    for (i = 0; i < 2; i++) {
        Ts4SimPlayer *p = &c->pl[i];
        for (k = 0; k < TS4_STAT_COUNT; k++) PS_SET(p, 0x620 + 4 * (uint32_t)k, cfg->players[i].stats[k]);   /* raw ratings */
        if (ts4_bound(c)) {
            ts4_bgraph_h(c, ts4_crc32("DefaultAttributes"), i);   /* raw ratings -> Profile S+0x64C..0x668 (G4b) */
            fatigue_graphs(c, i);
        }
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
    if (c->pl[player].setup.human) {
        Ts4Input v = *in;
        if (TUN_HAS(c, STICK_DEAD_ZONE)) {   /* radial dead zone, rescaled (InputMapper, G2b) */
            float dz = TUN(c, STICK_DEAD_ZONE), m = sqrtf(v.stick_x * v.stick_x + v.stick_z * v.stick_z);
            if (m <= dz) v.stick_x = v.stick_z = 0.0f;
            else { float o = ((m > 1.0f ? 1.0f : m) - dz) / (1.0f - dz); v.stick_x *= o / m; v.stick_z *= o / m; }
        }
        c->pl[player].in = v;
    }
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
            float total = (float)lead_ticks(c);
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
