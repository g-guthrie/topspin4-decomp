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
