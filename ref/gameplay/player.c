/* Readable reference for the player character.  See player.h and
 * docs/gameplay/player-and-movement.md (addresses, confidence tags). */
#include "player.h"

#include <math.h>
#include <string.h>

static float clampf(float v, float lo, float hi) { return v < lo ? lo : (v > hi ? hi : v); }

/* ------------------------------------------------------------ curves */

/* fn_881899D8: last key with x0 <= x (first if none); linear inside, flat outside. */
float pl_curve16(const PlCurve16 *c, float x)
{
    if (!c || c->count <= 0)
        return 0.0f;
    const PlKey16 *k = &c->keys[0];
    for (int i = 0; i < c->count; ++i)
        if (c->keys[i].x0 <= x)
            k = &c->keys[i];
    float w = k->x1 - k->x0;
    if (w <= 0.0f)
        return k->y0;
    float t = clampf(x - k->x0, 0.0f, w) / w;
    return k->y0 + t * (k->y1 - k->y0);
}

/* fn_8826D278: bracket the row value between two row keys, evaluate both rows'
 * curves at the column value and interpolate; nearest row outside the range. */
float pl_table2d(const PlTable2D *t, float row_value, float col_value)
{
    if (!t || t->count <= 0)
        return 0.0f;
    if (row_value <= t->rows[0].key || t->count == 1)
        return pl_curve16(&t->rows[0].curve, col_value);
    int i = 0;
    while (i + 1 < t->count && row_value >= t->rows[i + 1].key)
        ++i;
    if (i + 1 >= t->count)
        return pl_curve16(&t->rows[t->count - 1].curve, col_value);
    const PlRow *lo = &t->rows[i], *hi = &t->rows[i + 1];
    float a = pl_curve16(&lo->curve, col_value), b = pl_curve16(&hi->curve, col_value);
    float f = (row_value - lo->key) / (hi->key - lo->key);
    return a + f * (b - a);
}

/* fn_8817A688 (analyser curves). */
float pl_curve20(const PlKey20 *k, int n, float x, PlCurveMode mode)
{
    if (n <= 0)
        return 0.0f;
    const PlKey20 *s = &k[0];
    for (int i = 0; i < n; ++i)
        if (k[i].x0 <= x)
            s = &k[i];
    float w = s->x1 - s->x0;
    float d = clampf(x - s->x0, 0.0f, w > 0.0f ? w : 0.0f);
    float slope = s->slope;
    if (mode == PL_CURVE_RAMP_Y1 && w > 0.0f)
        slope = (s->y1 - s->y0) / w;
    return s->y0 + slope * d;
}

/* ------------------------------------------------------------ stats */

float pl_stroke_skill(const float st[PL_STAT_COUNT], PlStroke stroke, int forehand)
{
    switch (stroke) {
    case PL_STROKE_RETURN: return st[PL_RETURN];
    case PL_STROKE_SERVE: return st[PL_SERVE];
    case PL_STROKE_VOLLEY: return st[PL_VOLLEY];
    case PL_STROKE_FH_ONLY: return st[PL_FOREHAND];          /* states 0xA/0xB */
    case PL_STROKE_GROUND:
    default: return forehand ? st[PL_FOREHAND] : st[PL_BACKHAND];
    }
}

void pl_profile_from_ratings(const float r[PL_STAT_COUNT], const PlStatCurve c[PL_STAT_COUNT],
                             PlCurveMode mode, float out[PL_STAT_COUNT])
{
    for (int i = 0; i < PL_STAT_COUNT; ++i)
        out[i] = pl_curve20(c[i].keys, c[i].count, r[i], mode);
}

int pl_side_preference(float fh, float bh, int fh_uses, int bh_uses, float threshold)
{
    int total = fh_uses + bh_uses;
    if (fh == bh)
        return 0;
    float share = total > 0 ? (float)(fh > bh ? fh_uses : bh_uses) / (float)total : 0.0f;
    if (share >= threshold)
        return 0;                 /* already used enough: no preference (I) */
    return fh > bh ? 1 : -1;
}

/* ------------------------------------------------------------ reach */

PlSampleType pl_classify_sample(const PlTypeCfg *c, float x, float y, int bounces, int index, int lookahead)
{
    float ax = fabsf(x);
    if (ax <= 150.0f)                      /* code constant 150: too close to the net plane */
        return PL_UNREACHABLE;
    int in_zone = bounces <= 2 && index < lookahead && ax < c->volley_zone_abs_x;
    int low = y < (in_zone ? c->low_in : c->low_out);
    if (low)
        return in_zone ? PL_VOLLEY_T : PL_BASELINE;
    float lo = in_zone ? c->smash_lo_in : c->smash_lo_out, hi = in_zone ? c->smash_hi_in : c->smash_hi_out;
    return (y > lo && y < hi) ? PL_SMASH : PL_UNREACHABLE;
}

float pl_reach_speed(const PlReachCfg *c, PlSampleType type, int alt, int side_faces_ball,
                     float dx, float dz, float run_cm, float ticks, float turn_ticks, float busy)
{
    const float unit = 0.6f;               /* pool +0x114: cm/tick -> m/s */
    if (type == PL_UNREACHABLE || (type == PL_VOLLEY_T && dx + 150.0f < 0.0f))
        return 100.0f;                     /* pool +0x20 */
    float radius, vx = dx, vz = dz, prep;
    if (type == PL_VOLLEY_T) {
        radius = 10.0f;                    /* code constant */
        if (side_faces_ball) {
            vx = fmaxf(fabsf(dx) - c->volley_box_x, 0.0f);
            vz = fmaxf(fabsf(dz) - c->volley_box_z, 0.0f);
        }
        prep = c->prep_volley;
    } else {
        radius = alt ? c->reach_radius_alt : c->reach_radius;
        prep = alt ? c->prep_alt : c->prep;
    }
    if (sqrtf(vx * vx + vz * vz) < radius) {
        float slack = ticks - prep - busy;
        return slack < 1.0f ? 3.4028235e38f : 0.0f;
    }
    float avail = ticks - prep - turn_ticks - busy;
    if (avail < 1.0f)
        return 100.0f;
    float v = (run_cm - radius) / avail * unit;
    return v < 0.0f ? 0.0f : v;
}

/* ------------------------------------------------------------ movement */

float pl_mode_validity(const PlTable2D *t, float distance, float ticks, float prep, float lead)
{
    float slack = ticks - prep - lead;
    return pl_table2d(t, distance, slack);
}

int pl_mode_valid(const PlModeCfg *m, float distance, float ticks, float prep, float lead)
{
    if (m->min_distance * m->min_distance >= distance * distance)
        return 0;                          /* "Minimum distance %.2f < %.2f" */
    return pl_mode_validity(&m->validity, distance, ticks, prep, lead) >= 0.5f;
}

int pl_select_regime(const PlModeCfg *rush, const PlModeCfg *jogjog, const PlModeCfg *jog,
                     float rush_value, float rush_guard,
                     float distance, float ticks, float prep, float lead)
{
    if (rush_value > rush_guard && pl_mode_valid(rush, distance, ticks, prep, lead))
        return PL_MODE_RUSH;
    if (pl_mode_valid(jogjog, distance, ticks, prep, lead))
        return PL_MODE_JOGJOG;
    if (pl_mode_valid(jog, distance, ticks, prep, lead))
        return PL_MODE_JOG;
    return PL_MODE_DEFAULT;
}

float pl_jog_ramp_tick(PlJogRamp *r, int ticks_since_commit, int period,
                       const PlTable2D *step_table, float distance, float slack)
{
    if (r->initialised && period > 0 && ticks_since_commit % period != 0) {
        r->value -= r->step;
        return r->value;                   /* published to S+0xDE8, S+0xDEC = 1 */
    }
    r->initialised = 1;
    r->step = pl_table2d(step_table, distance, slack);
    return r->value;
}

/* ------------------------------------------------------------ swing target */

float pl_racket_lateral(float a, float b, int left_handed, int side)
{
    if (left_handed)
        return side ? -b : -a;
    return side ? a : b;
}

void pl_contact_window(float sample_tick, int now, int alt, const float lo_hi_alt[2], const float lo_hi[2],
                       float *lo, float *hi)
{
    float ticks = sample_tick - (float)now;
    const float *w = alt ? lo_hi_alt : lo_hi;
    *lo = ticks - w[0];
    *hi = ticks - w[1];
}

/* ------------------------------------------------------------ clip timing */

float pl_time_warp(const PlLayer *l, float ratio, float t)
{
    return clampf((t - l->t0) * (ratio - 1.0f) + l->base, l->base, l->end);
}

float pl_anim_busy(const PlLayer *l, float ratio, float seg1_start, float now)
{
    float v = (seg1_start - l->t0) * (ratio - 1.0f) + l->base - now;
    return v > 0.0f ? v : 0.0f;
}

float pl_rate_to_target(float event_time, float clip_now, int target, int now, float prev_rate, float decay)
{
    if (now <= target)
        return (event_time - clip_now) / (float)(target - now + 1);
    return prev_rate * decay;
}

float pl_contact_frame(float phase, float clip_frames) { return phase * clip_frames; }

/* ------------------------------------------------------------ grades, AI, crowd */

void pl_grades(float out, PlGrade *two, PlGrade *three)
{
    *two = out < 0.5f ? PL_GRADE_BAD : PL_GRADE_GOOD;
    *three = out < 0.33f ? PL_GRADE_BAD : (out < 0.66f ? PL_GRADE_MEDIUM : PL_GRADE_GOOD);
}

const PlAiRecord *pl_ai_lookup(const PlAiGroup *g, int n, uint32_t style, uint32_t level)
{
    if (n <= 0)
        return 0;
    const PlAiGroup *grp = &g[0];
    for (int i = 0; i < n; ++i)
        if (g[i].style == style) {
            grp = &g[i];
            break;
        }
    if (grp->count <= 0)
        return 0;
    for (int j = 0; j < grp->count; ++j)
        if (grp->recs[j].level == level)
            return &grp->recs[j];
    return &grp->recs[0];
}

float pl_excitement_step(float level, float events, float gain, float cap)
{
    return clampf(level + events + clampf(gain, -cap, cap), 0.0f, 1.0f);
}

uint32_t pl_crc32(const char *s)
{
    uint32_t c = 0xFFFFFFFFu;
    for (; *s; ++s) {
        c ^= (uint8_t)*s;
        for (int k = 0; k < 8; ++k)
            c = (c >> 1) ^ (0xEDB88320u & (0u - (c & 1u)));
    }
    return ~c;
}
