/* Swing-category rule lists (fn_886AFDF8 and friends).  See swing_category.h. */
#include "swing_category.h"

#include <math.h>

void sc_default_tuning(ScTuning *t)
{
    t->min_speed_reach = 3.5f;
    t->min_speed_bad = 4.5f;
    t->late_timing = 0.1f;
    t->window_hi = 0.1f;
    t->window_lo = -0.3f;
    t->fatality_power = 0.15f;
}

static float min_speed(const ScInputs *in)
{
    /* fsel on the sign of (left - right): the smaller of the two lines */
    return in->min_speed_left - in->min_speed_right >= 0.0f ? in->min_speed_right : in->min_speed_left;
}

static int in_window(const ScInputs *in, const ScTuning *t)
{
    return in->manual_timing > t->window_lo && in->manual_timing < t->window_hi;
}

int sc_condition(uint32_t cond, const ScInputs *in, const ScTuning *t)
{
    switch (cond) {
    case SC_COND_NONE:
        return 1;
    case SC_COND_FATALITY:
        /* not (AI with its net request), not (sticky RB in the net zone), power above 0.15 */
        if (!in->is_human && in->ai_net_request)
            return 0;
        if (in->sticky_rb && in->in_net_zone)
            return 0;
        return in->power > t->fatality_power;
    case SC_COND_GO_TO_NET:
        return in->sticky_rb && in->in_net_zone;
    case SC_COND_IS_PERFECT:
        return in->perfect_eval > 0.5f;
    case SC_COND_REACH_SLOW:
        return min_speed(in) > t->min_speed_reach;
    case SC_COND_REACH_FAST:
        return min_speed(in) > t->min_speed_bad;
    case SC_COND_GOOD_REACH:
        return min_speed(in) > t->min_speed_reach && (!in->is_human || in_window(in, t));
    case SC_COND_BAD_REACH:
        return min_speed(in) > t->min_speed_bad && !in_window(in, t);
    case SC_COND_BAD_TIMING:
        return in->timing_value > t->late_timing;
    case SC_COND_LATE_MANUAL:
        return in->manual_timing > t->late_timing && in->slow_down < 0.5f;
    case SC_COND_IS_FAST_BALL:
        return in->is_fast_ball || in->is_baseline_fast_ball;
    case SC_COND_DROP_SHOT:
        return in->shot_id == SC_SHOT_DROP_SHOT;
    case SC_COND_VOLLEY_FORWARD:
        return in->local_x + (in->team_mode_2 ? 600.0f : 450.0f) < 0.0f &&
               in->shot_id != SC_SHOT_SLICE && in->shot_id != SC_SHOT_DROP_SHOT;
    case SC_COND_GOOD_VOLLEY_RELEASE:
        return in->volley_release > 0.5f;
    case SC_COND_BAD_VOLLEY_RELEASE:
        return !(in->volley_release > 0.5f);
    case SC_COND_VOLLEY_SPECTACULAR:
        return in->volley_spectacular != 0;
    case SC_COND_INSIDE_OUT:
        return in->is_inside_out != 0;
    case SC_COND_SKILL_REQUIRED:
        return in->skill_ok != 0;
    }
    return 0;
}

int sc_mode(int autoswing_call, int timing_state_d10, float slow_down)
{
    if (!autoswing_call)
        return 0;
    return (timing_state_d10 || slow_down > 0.5f) ? 1 : 2;
}

int sc_class(int is_volley, int is_smash, uint32_t shot_id, int require_finesse)
{
    if (is_smash)
        return 5;
    if (is_volley)
        return shot_id == SC_SHOT_TOPSPIN ? 4 : 3;
    if (shot_id == SC_SHOT_SLICE || shot_id == SC_SHOT_DROP_SHOT)
        return 2;
    return require_finesse ? 1 : 0;
}

int sc_query_levels(ScQuery q, void *user, uint32_t category, const uint32_t *levels, int nlevels,
                    int autoswing, int frames)
{
    int best = -1;
    for (int i = 0; i < nlevels && best != 0; ++i) {
        int r = q(user, category, levels[i], autoswing, frames);
        if (r == 0)
            return 0;
        if (r == -1)
            continue;
        if (best == -1 || r < best)
            best = r;
    }
    return best;
}

ScResult sc_walk(const ScRow *rows, int nrows, const ScInputs *in, const ScTuning *t,
                 int autoswing_call, int latched, int autoswung, int window, int limit,
                 ScQuery q, void *user, const uint32_t *levels, int nlevels)
{
    ScResult res = {0, 0, 0, 0, -1};
    for (int i = 0; i < nrows; ++i) {
        const ScRow *r = &rows[i];
        if (r->cond != SC_COND_NONE && !sc_condition(r->cond, in, t))
            continue;
        res.row = i;
        res.category = r->value;          /* also ProStyle/Surface keys reset to None */
        int normal = autoswung || (latched && r->easy_autoswing) || in->slow_down > 0.5f;
        int n;
        if (autoswing_call && !normal) {
            n = sc_query_levels(q, user, res.category, levels, nlevels, 1, window);
            if (n > 0) {
                res.autoswing_due |= n < limit;
            } else if (r->alt && n == -1) {
                res.category = r->alt;
                n = sc_query_levels(q, user, res.category, levels, nlevels, 1, window);
                if (n > 0)
                    res.autoswing_due |= n < limit;
            }
        } else {
            n = sc_query_levels(q, user, res.category, levels, nlevels, 0, 3);
            if (r->alt && n == -1) {
                res.category = r->alt;
                n = sc_query_levels(q, user, res.category, levels, nlevels, 0, 3);
            }
        }
        res.found |= n >= 0;
        res.started = n == 0;
        if (n == 0)
            break;
    }
    return res;
}


/* ---------------------------------------------------------------------------------------------- G8 */

int sc_request_autoswing_call(int is_ai, int released_before_clip)
{
    return (is_ai || released_before_clip) ? 0 : 1;
}

int sc_timing_state_d10(int is_volley, float auto_swing, float auto_volley_swing)
{
    return (is_volley ? auto_volley_swing : auto_swing) > 0.5f;
}

static float lerpf(float a, float b, float w)
{
    if (w < 0.0f)
        w = 0.0f;
    if (w > 1.0f)
        w = 1.0f;
    return a + (b - a) * w;
}

float sc_eval_auto_swing(float frames, float min_segment_speed)
{
    return (frames >= 60.0f && min_segment_speed < 5.0f) ? 1.0f : 0.0f;
}

float sc_eval_auto_volley_swing(float frames, float hand)
{
    /* curve(Hand): 60 up to 0.2, 40 at 0.8, 25 at 1.0 (piecewise linear) */
    float need;
    if (hand <= 0.2f)
        need = 60.0f;
    else if (hand <= 0.8f)
        need = lerpf(60.0f, 40.0f, (hand - 0.2f) / 0.6f);
    else
        need = lerpf(40.0f, 25.0f, (hand - 0.8f) / 0.2f);
    return frames >= need ? 1.0f : 0.0f;
}

float sc_eval_fast_net(float frames, float depth, float hand)
{
    return (frames < 40.0f && depth < lerpf(175.0f, 250.0f, hand)) ? 1.0f : 0.0f;
}

float sc_eval_fast_baseline(float depth, float hand)
{
    return depth < lerpf(150.0f, 400.0f, hand) ? 1.0f : 0.0f;
}

float sc_eval_fast_return(float depth, float ret)
{
    return depth < lerpf(200.0f, 400.0f, ret) ? 1.0f : 0.0f;
}

float sc_eval_perfect_shot(float manual_timing)
{
    return (manual_timing >= -0.1f && manual_timing < 0.1f) ? 1.0f : 0.0f;
}

int sc_fast_ball(int is_return_of_serve, int nearer_net, int frames, float abs_dz, float y)
{
    if (!(y < 240.0f))
        return SC_FAST_NONE;
    if (is_return_of_serve)       /* PT+0x110 = 65 frames, PT+0x124 = 300 cm */
        return (frames < 65 && abs_dz < 300.0f) ? SC_FAST_RETURN : SC_FAST_NONE;
    if (nearer_net)               /* PT+0x114 = 35, PT+0x128 = 200 */
        return (frames < 35 && abs_dz < 200.0f) ? SC_FAST_NET : SC_FAST_NONE;
    return (frames < 50 && abs_dz < 250.0f) ? SC_FAST_BASELINE : SC_FAST_NONE;   /* PT+0x118 / 0x12C */
}

int sc_synth_auto_swing(int fast_kind, int is_volley, int team_mode_2, float eval_return_7c4,
                        float eval_baseline_7c0, float eval_net_7bc)
{
    if (fast_kind == SC_FAST_RETURN && eval_return_7c4 > 0.5f)
        return 1;
    if (fast_kind == SC_FAST_BASELINE && eval_baseline_7c0 > 0.5f)
        return 1;
    return is_volley && fast_kind == SC_FAST_NET && !team_mode_2 && eval_net_7bc > 0.5f;
}

int sc_autoswing_gate(float timing_value, int ball_past, int is_smash, int is_volley, int fast_kind)
{
    return timing_value > -1.0f || ball_past || is_smash || is_volley || fast_kind != SC_FAST_NONE;
}

int sc_auto_commit(int frames_to_contact)
{
    return frames_to_contact <= 12;
}

int sc_ai_fatality_first(int difficulty)
{
    return difficulty >= 3;
}

int sc_ai_release_limit(int fast_ball, int bd2)
{
    if (fast_ball)
        return 20;
    return 18 + (bd2 ? 10 : 0);
}

int sc_ai_release(int min_frames, int limit)
{
    return min_frames >= 0 && min_frames < limit;
}

float sc_charge_power(int hold_frames)
{
    float x = (float)hold_frames / 60.0f;
    if (x > 1.25f)
        x = 1.25f;
    if (x < 0.0f)
        x = 0.0f;
    return x / 1.25f;
}

int sc_power_tier(float power)
{
    if (power < 0.15f)
        return 0;
    return power < 0.7f ? 1 : 2;
}
