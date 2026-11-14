/* Reference implementation of the movement planner decoded from
 * fn_886B8468 / fn_886BD690 / fn_88699FC0 / fn_88688948.  See
 * docs/gameplay/movement-and-ai.md for evidence and confidence levels. */
#include "movement.h"

#include <math.h>

const char *mv_state_name(int s)
{
    static const char *const n[MV_STATE_COUNT] = {
        "Wait", "AnticipateA", "AnticipateB", "SwingReady", "Swing",
        "Approach", "ApproachNear", "Turn", "Stop", "Replan", "AltA", "AltB",
        "AltSwing", "Hold", "BallWindow", "Choose", "Volley", "ReadyA",
        "ReadyB", "Reach", "Rush", "JogJogPrepared", "JogPrepared"};
    return (s >= 0 && s < MV_STATE_COUNT) ? n[s] : "?";
}

/* fn_88688948: usable iff farther than the mode minimum and the margin
 * table value for (distance, slack) reaches the threshold. */
int mv_mode_valid(const struct mv_cfg *cfg, const struct mv_mode_cfg *mode,
                  float dist, float slack, mv_table_fn tab, void *user)
{
    if (dist * dist <= mode->min_distance * mode->min_distance)
        return 0;
    return tab(mode, dist, slack, user) >= cfg->validity_threshold;
}

/* fn_88699FC0 (verified order: Rush, JogJogPrepared(+0x284),
 * JogPrepared(+0x298)). */
int mv_select_move_state(const struct mv_cfg *cfg, int profile_is_238_248,
                         int profile_is_1f8, int sample_is_volley,
                         float rush_player_value, float dist, float slack,
                         mv_table_fn tab, void *user, int *out_flags_cleared)
{
    if (out_flags_cleared)
        *out_flags_cleared = 0;
    if (profile_is_238_248)
        return MV_ALT_B;
    if (profile_is_1f8)
        return MV_SWING_READY;
    if (sample_is_volley)
        return MV_VOLLEY;
    if (rush_player_value > cfg->rush_guard &&
        mv_mode_valid(cfg, &cfg->rush, dist, slack, tab, user)) {
        if (out_flags_cleared)
            *out_flags_cleared = 1;
        return MV_RUSH;
    }
    if (mv_mode_valid(cfg, &cfg->jogjog, dist, slack, tab, user)) {
        if (out_flags_cleared)
            *out_flags_cleared = 1;
        return MV_JOGJOG;
    }
    if (mv_mode_valid(cfg, &cfg->jog, dist, slack, tab, user)) {
        if (out_flags_cleared)
            *out_flags_cleared = 1;
        return MV_JOG;
    }
    return MV_APPROACH;
}

static int go_hold(struct mv_planner *p)
{
    /* the game copies the current command (+0x130/+0x134) to +0x288/+0x28c */
    p->last_cmd_valid = 1;
    return MV_HOLD;
}

static int go_replan(struct mv_planner *p, const struct mv_world *w, int from)
{
    p->saved_state = from;
    p->saved_candidate = w->candidate_index;
    return MV_REPLAN;
}

static int anticipate(struct mv_planner *p, const struct mv_world *w, int cur)
{
    int sel = w->sel_from_anticipate;
    if (sel != cur)
        return sel;
    if (w->human || !w->rally_active || !w->sets_valid)
        goto stay;
    if (w->shot_window_a)
        return MV_READY_B;
    if (w->ball_window && !w->prepared_or_rushjog)
        return MV_READY_A;
    return go_hold(p);
stay:
    return cur;
}

int mv_next_state(struct mv_planner *p, const struct mv_cfg *cfg,
                  const struct mv_world *w, struct mv_out *out)
{
    int cur = p->state;
    int r;

    if (out) {
        out->speed_override_set = 0;
        out->speed_override = 0.0f;
        out->request_search_profile = 0;
    }
    /* prologue: pending interrupt turns into Turn (7) or Stop (8) */
    if (p->pending_interrupt) {
        p->pending_interrupt = 0;
        if (w->interrupt_to_turn) {
            p->saved_state = cur;
            cur = w->interrupt_dir_positive ? MV_STOP : MV_TURN;
        }
    }
    switch (cur) {
    case MV_WAIT:
        if ((float)w->frames_since_opp_hit >= cfg->reaction_frames ||
            w->opp_mode_is_2)
            return MV_ANTICIPATE_A;
        return cur;
    case MV_ANTICIPATE_A:
        if (w->pending_candidate)
            return MV_BALL_WINDOW;
        r = anticipate(p, w, cur);
        if (r != cur)
            return r;
        /* stay unless the hold window ran out: then go to phase B */
        if (((float)w->frames_since_opp_hit <= w->hold_frames ||
             w->hold_window_ok) &&
            (w->hold_window_ok || !w->reaction_started))
            return cur;
        return MV_ANTICIPATE_B;
    case MV_ANTICIPATE_B:
        r = anticipate(p, w, cur);
        return r;
    case MV_SWING_READY:
        if (w->zone_swing_start) {
            p->pending_interrupt = 1;
            return MV_SWING;
        }
        return cur;
    case MV_SWING:
        r = w->replan;
        if (r == 1)
            return go_replan(p, w, MV_SWING);
        if (w->rally_active && r == -1)
            return go_hold(p);
        return cur;
    case MV_APPROACH:
    case MV_APPROACH_NEAR:
        if (w->can_start_swing) {
            p->swing_flag = 0;
            return MV_SWING_READY;
        }
        if (cur == MV_APPROACH && w->zone_near) {
            p->pending_interrupt = 1;
            return MV_APPROACH_NEAR;
        }
        if (w->can_reach)
            return MV_REACH;
        if (w->replan == 1 && cur == MV_APPROACH_NEAR)
            return go_replan(p, w, cur);
        if (w->rally_active && w->replan == -1)
            return go_hold(p);
        if (out)
            out->request_search_profile = 0x208;
        return cur;
    case MV_TURN:
        /* holds the heading for a counted number of frames, then resumes */
        return p->saved_state;
    case MV_STOP:
        if (p->frames_in_state >= 4)
            return p->saved_state;
        return cur;
    case MV_REPLAN:
        if (w->candidate_stable_window)
            return cur;
        return p->saved_state;
    case MV_ALT_A:
    case MV_ALT_B:
        if (out) {
            out->speed_override_set = 1;
            out->speed_override = 1.0f;
        }
        if (w->zone_hold) {
            p->pending_interrupt = 1;
            return MV_ALT_SWING;
        }
        return cur;
    case MV_ALT_SWING:
        if (w->alt_swing_ok)
            return MV_RUSH;
        r = w->replan;
        if (r == 1)
            return go_replan(p, w, cur);
        if (w->rally_active && r == -1)
            return go_hold(p);
        if (out) {
            out->speed_override_set = 1;
            out->speed_override = 1.0f;
        }
        return cur;
    case MV_HOLD:
        return cur; /* re-applies the stored command every frame */
    case MV_BALL_WINDOW:
        if (w->replan == 0 || w->replan == 1)
            return go_replan(p, w, cur);
        return cur;
    case MV_CHOOSE:
    case MV_VOLLEY:
        r = w->replan;
        if (r == 1)
            return go_replan(p, w, cur);
        if (w->rally_active && r == -1)
            return go_hold(p);
        return cur;
    case MV_READY_A:
    case MV_READY_B:
        if (w->slack_distance < 20.0f && p->frames_in_state > 1)
            return MV_HOLD;
        return cur;
    case MV_REACH:
        if (p->frames_in_state > 10)
            return go_replan(p, w, MV_REACH);
        return cur;
    case MV_RUSH:
    case MV_JOGJOG:
    case MV_JOG:
        if (w->can_start_swing) {
            p->swing_flag = 0;
            return MV_SWING_READY;
        }
        if (w->can_reach)
            return MV_REACH;
        if (cur == MV_JOGJOG && w->rush_ok_flag && w->jog_far_ok)
            return MV_JOG;
        if (cur == MV_RUSH && w->rush_ok_flag &&
            (w->slack_distance > w->slack_hi ||
             (w->slack_distance > w->slack_lo && w->jog_far_ok)))
            return MV_JOG;
        r = w->replan;
        if (r == 1)
            return MV_APPROACH_NEAR;
        if (w->rally_active && r == -1)
            return go_hold(p);
        return cur;
    default:
        return cur;
    }
}

int mv_update(struct mv_planner *p, const struct mv_cfg *cfg,
              const struct mv_world *w, struct mv_out *out)
{
    int hops;
    for (hops = 0; hops < cfg->max_hops; hops++) {
        int next = mv_next_state(p, cfg, w, out);
        if (next == p->state)
            break;
        p->prev_state = p->state;
        p->state = next;
        p->frames_in_state = 0;
    }
    p->frames_in_state++;
    return p->state;
}

int mv_ball_window(float player_x, float frames_to_contact, float path_offset)
{
    return fabsf(player_x) < 810.0f &&
           (frames_to_contact > 40.0f || fabsf(path_offset) > 400.0f);
}

int mv_shot_window(float player_x_local, int side_tag, float zone_distance)
{
    return player_x_local + 800.0f < 0.0f && (side_tag || zone_distance < 50.0f);
}

int mv_alt_swing_ok(int human, float stick_angle, float stick_power, int frames_left,
                    int blocked)
{
    int stick_ok = !human || (fabsf(stick_angle) > 1.5f && 0.2f - stick_power < 0.0f);
    return !blocked && frames_left < 10 && stick_ok;
}

/* ---- GE2: planner geometry and repositioning (movement-and-ai.md A.4c, repositioning.md) ---- */

static float cross2(struct mv_v2 a, struct mv_v2 b) { return a.x * b.z - a.z * b.x; }
static float dot2(struct mv_v2 a, struct mv_v2 b) { return a.x * b.x + a.z * b.z; }
static struct mv_v2 sub2(struct mv_v2 a, struct mv_v2 b) { struct mv_v2 r = {a.x - b.x, a.z - b.z}; return r; }
static struct mv_v2 norm2(struct mv_v2 a)
{
    float l = sqrtf(dot2(a, a));
    struct mv_v2 r = a;
    if (l != 0.0f) { r.x /= l; r.z /= l; }   /* vsel keeps a zero vector */
    return r;
}

int mv_line_intersect(struct mv_v2 p1, struct mv_v2 d1, struct mv_v2 p2, struct mv_v2 d2,
                      struct mv_v2 *point, float *t1, float *t2)
{
    float den = cross2(d1, d2);
    struct mv_v2 w;
    if (den == 0.0f) {
        *point = p1;
        return 0;
    }
    w = sub2(p2, p1);
    *t1 = cross2(w, d2) / den;
    *t2 = cross2(w, d1) / den;
    point->x = p1.x + *t1 * d1.x;
    point->z = p1.z + *t1 * d1.z;
    return 1;
}

int mv_replan_check(struct mv_v2 a, struct mv_v2 q, struct mv_v2 pos, struct mv_v2 pred,
                    int frames_left)
{
    float d1 = dot2(sub2(q, a), sub2(pred, pos));   /* already moving from a toward q */
    struct mv_v2 u = norm2(sub2(a, q)), n = {-u.z, u.x};
    struct mv_v2 c = sub2(pred, q);
    float along = dot2(c, u), lateral = dot2(c, n);
    int near = fabsf(lateral) - 40.0f < 0.0f;
    int ok = d1 > 0.0f ? (along < 0.0f && along > -30.0f) : (along < 30.0f && along > -20.0f);
    if (!(near && ok))
        return 0;
    return frames_left <= 10 ? 1 : -1;
}

float mv_run_angle(struct mv_v2 q, struct mv_v2 pos, struct mv_v2 velocity_ms)
{
    struct mv_v2 e = sub2(sub2(q, pos), velocity_ms);   /* cm minus m/s, as in the code */
    return fabsf(atan2f(e.z, e.x));
}

float mv_mode_slack(int frames_left, float prep, float lead)
{
    return (float)frames_left - prep - lead;
}

void mv_mover_step(float *sum, float *mean, float sample, float tau)
{
    *sum = *sum - *mean + sample;
    *mean = *sum / tau;
}

int mv_volley_or_bounce(int first_type_is_baseline, int last_type_is_baseline)
{
    return !first_type_is_baseline && last_type_is_baseline;
}

float mv_human_reach_input(float reach_speed, float best_speed, float margin)
{
    return reach_speed - (best_speed + margin) < 0.0f ? best_speed : 100.0f;
}

int mv_inside_out(struct mv_v2 p, struct mv_v2 b0, struct mv_v2 b1, int far)
{
    struct mv_v2 dir = norm2(sub2(b1, b0)), zdir = {0.0f, 1.0f}, pt;
    float t1 = 0.0f, t2 = 0.0f, qz;
    int s1, s2;
    mv_line_intersect(b0, dir, p, zdir, &pt, &t1, &t2);
    qz = p.z + t2;                    /* crossing of the line x = p.x */
    s1 = (far ? -qz : qz) < p.z;      /* mirrored by the own court tag, compared in world */
    mv_line_intersect(b0, dir, b0, zdir, &pt, &t1, &t2);   /* degenerate: t2 = 0 */
    qz = b0.z + t2;
    s2 = (far ? -qz : qz) < b0.z;
    return s1 != s2;
}

static float clampf(float v, float lo, float hi) { return v < lo ? lo : v > hi ? hi : v; }

void rp_singles_points(float opp_hit_z, struct mv_v2 *net, struct mv_v2 *baseline)
{
    float z = clampf(opp_hit_z, -600.0f, 600.0f);
    net->x = 300.0f;  net->z = z / 6.0f;          /* curve1: +-600 -> +-100 */
    baseline->x = 1300.0f; baseline->z = -z / 12.0f;  /* curve2: +-600 -> -+50 */
}

int rp_human_mode(float pos_x, float pos_z, float move_power, float stick_minus_target_rad,
                  float dist_to_net_point, int rb, int play_mode_1, int event_frames_valid,
                  int event_frames_left, int old_mode)
{
    int mode = 0, inbox, aimed, far;
    if (move_power < 0.1f || pos_x > -500.0f)
        return 0;
    inbox = pos_x < -700.0f && pos_z < 400.0f && pos_x > -1100.0f && pos_z > -400.0f;
    aimed = fabsf(stick_minus_target_rad) < 40.0f * 0.0174532924f;
    far = dist_to_net_point * dist_to_net_point > 175.0f * 175.0f;
    if (aimed && far && ((inbox && !play_mode_1) || rb))
        mode = 2;
    if (mode != old_mode && mode == 2 && event_frames_valid &&
        (unsigned)event_frames_left < 20u)
        mode = old_mode;
    return mode;
}

int rp_ai_singles_mode(float r, float volley, float baseline, int old_mode)
{
    int mode = old_mode;
    if (r > 0.0f && r < volley)
        mode = 2;
    if (volley < r && r < volley + baseline)
        mode = 1;
    return mode;
}

int rp_doubles_nearest(float d160, float d170, float d180, float d190, int old_mode)
{
    int mode = old_mode;
    if (d160 < d170 && d160 < d190 && d160 < d180) mode = 4;
    if (d170 < d160 && d170 < d190 && d170 < d180) mode = 6;
    if (d180 < d170 && d180 < d190 && d180 < d160) mode = 3;
    if (d190 < d170 && d190 < d160 && d190 < d180) mode = 5;
    return mode;
}

int rp_doubles_ai_swap(int mode, float partner_local_z, float own_local_x)
{
    int back = own_local_x < -900.0f;
    if (partner_local_z > 0.0f) {
        if (mode == 3) return 5;
        if (mode == 4) return 6;
        if (mode == 0) return back ? 5 : 6;
    } else {
        if (mode == 5) return 3;
        if (mode == 6) return 4;
        if (mode == 0) return back ? 3 : 4;
    }
    return mode;
}

int rp_ai_stop(float c2b4b4baa, float stop_moving, float c2ac5965a, float opp_frames)
{
    return (c2b4b4baa < 0.5f || stop_moving > 0.5f) && opp_frames < c2ac5965a;
}

int rp_ai_post_swing_hold(int n, int swing_running, int *stamp, int now)
{
    if (n <= 0)
        return 0;
    if (!swing_running && *stamp == -1)
        *stamp = now;
    if (*stamp == -1)
        return 1;
    if (*stamp <= 0)
        return 0;
    return now - *stamp <= n;
}
