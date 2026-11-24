/*
 * Reference implementation: swing-selection candidate window.
 *
 * Source: Swing_DLL.xex, part B of docs/gameplay/stats-swing-clipfit.md.
 *   gp_window_build        <- 0x8869B178 (classification) + 0x8868B4E8 (speeds)
 *   gp_sel_extract_rows    <- 0x8869A520
 *   gp_select_best         <- 0x8865DBA8
 * Classification thresholds and the speed formula are INFERRED: the vector
 * part of the engine code was not recoverable.  Tunables are parameters.
 */
#include "gp_swing.h"

static float min2(float a, float b)
{
    return (a < b) ? a : b;
}

void gp_window_build(GpWindow *w, const GpBallSample *samples,
                     const float *local_dist, int n, const GpWindowParams *p,
                     int current_frame, float lead_frames)
{
    if (n > GP_MAX_SAMPLES)
        n = GP_MAX_SAMPLES;
    w->count = n;
    w->first_valid = -1;
    w->last_valid = -1;

    for (int i = 0; i < n; ++i) {
        const GpBallSample *s = &samples[i];
        float lateral = s->local_x < 0.0f ? -s->local_x : s->local_x;
        float height = s->local_y;
        int volley_zone = s->bounce_index <= p->volley_max_bounce &&
                          lateral < p->volley_lateral_max;
        float split = volley_zone ? p->split_height_volley : p->split_height_other;
        uint32_t type;

        if (height < split) {
            type = volley_zone ? p->id_volley : p->id_baseline;
        } else {
            const float *band = volley_zone ? p->smash_band_volley : p->smash_band_other;
            type = (height > band[0] && height < band[1]) ? p->id_smash : p->id_none;
        }

        w->pos[i][0] = s->local_x;
        w->pos[i][1] = s->local_y;
        w->pos[i][2] = s->local_z;
        w->pos[i][3] = 0.0f;
        w->type_id[i] = type;

        /* required speed to be at the contact point in time */
        float prep = (type == p->id_volley) ? p->prep_frames_volley : p->prep_frames_other;
        float time = (float)(s->time_frame - current_frame) - prep - lead_frames;
        float speed;

        if (type == p->id_none) {
            speed = p->far_default;
        } else if (local_dist[i] <= p->reach_radius) {
            speed = (time >= p->min_time_frames) ? 0.0f : p->unreachable;
        } else if (time >= p->min_time_frames) {
            speed = (local_dist[i] - p->reach_radius) / time * p->unit_scale;
            if (speed < 0.0f)
                speed = 0.0f;
            speed = min2(speed, p->speed_cap);
        } else {
            speed = p->far_default;
        }
        w->reach_speed[i] = speed;
        if (type != p->id_none) {
            if (w->first_valid < 0)
                w->first_valid = i;
            w->last_valid = i;
        }
    }
}

/* Group consecutive reachable candidates into rows and record the cheapest
 * required speed overall / for non-volley / for volley candidates. */
void gp_sel_extract_rows(GpSel *sel, const GpWindow *w, const GpMoveMode *mode,
                         int hand_ok, uint32_t id_volley, uint32_t id_smash)
{
    sel->row_count = 0;
    sel->valid = 0;
    sel->min_speed_all = 3.402823466e+38f;
    sel->min_speed_other = 3.402823466e+38f;
    sel->min_speed_volley = 3.402823466e+38f;

    int in_run = 0;
    for (int i = 0; i < w->count; ++i) {
        int is_other = w->type_id[i] != id_volley;
        float limit = is_other ? mode->speed_limit_other : mode->speed_limit_volley;
        float reach = w->reach_speed[i];
        int is_smash = w->type_id[i] == id_smash;
        int eligible = hand_ok && (mode->allow_volley || is_other) &&
                       is_smash == (mode->smash_only != 0) && reach - limit < 0.0f;

        if (!eligible) {
            in_run = 0;
            continue;
        }
        sel->valid = 1;
        sel->min_speed_all = min2(sel->min_speed_all, reach);
        if (is_other)
            sel->min_speed_other = min2(sel->min_speed_other, reach);
        else
            sel->min_speed_volley = min2(sel->min_speed_volley, reach);

        if (!in_run) {
            if (sel->row_count >= GP_MAX_ROWS)
                break;
            GpRow *r = &sel->rows[sel->row_count++];
            r->first = i;
            r->last = i;
            r->min_speed = reach;
            in_run = 1;
        } else {
            GpRow *r = &sel->rows[sel->row_count - 1];
            r->last = i;
            r->min_speed = min2(r->min_speed, reach);
        }
    }
}

/* Arg-max of the selection score over the rows.  (want_other, want_volley):
 * (0,0) and (1,1) accept every candidate, (1,0) only non-volley candidates,
 * (0,1) only volley candidates.  Strictly greater than the running best wins,
 * the running best starts at floor_score (the engine uses -1, the value the
 * scorer stores for ineligible candidates). */
int gp_select_best(const GpSel *sel, const GpWindow *w, int want_other,
                   int want_volley, float floor_score, uint32_t id_volley)
{
    int best = -1;
    float best_score = floor_score;

    if (!sel->valid)
        return -1;
    for (int r = 0; r < sel->row_count; ++r) {
        for (int i = sel->rows[r].first; i <= sel->rows[r].last; ++i) {
            int is_volley = w->type_id[i] == id_volley;
            int accept = is_volley ? (want_volley || !want_other)
                                   : (want_other || !want_volley);
            if (accept && sel->score[i] > best_score) {
                best_score = sel->score[i];
                best = i;
            }
        }
    }
    return best;
}
