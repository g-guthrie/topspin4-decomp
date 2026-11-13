/* Reference implementation of the movement planner decoded from
 * fn_886B8468 / fn_886BD690 / fn_88699FC0 / fn_88688948.  See
 * docs/gameplay/movement-and-ai.md for evidence and confidence levels. */
#include "movement.h"

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
