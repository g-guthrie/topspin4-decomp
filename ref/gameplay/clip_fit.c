/*
 * Reference implementation: animation clip contact timing and fit scaffold.
 *
 * Source: Swing_DLL.xex planner 0x886D3AD8 / 0x886D4978 (part C of
 * docs/gameplay/stats-swing-clipfit.md).  The marker lookup, the
 * normalised-time to frame mapping, the acceptance gates and the cost (squared
 * distance, arg-min; GE2) are read from code.
 */
#include "gp_swing.h"

static float absf(float v)
{
    return v < 0.0f ? -v : v;
}

float gp_clip_contact_frame(const GpClip *c, uint32_t contact_id,
                            float start_frame, float playback_scale)
{
    for (int i = 0; i < c->marker_count; ++i) {
        if (c->markers[i].id == contact_id) {
            /* marker times are normalised (0..1) fractions of the clip */
            return start_frame + c->markers[i].time * c->length * playback_scale;
        }
    }
    return -1.0f;
}

float gp_clip_prep_tolerance(float root_distance, float data_tol)
{
    float t = root_distance - 150.0f;            /* lbl_880C8FD0 */
    if (t < 0.0f) t = 0.0f;
    if (t > 450.0f) t = 450.0f;                  /* pool +0x470 */
    t = t * (1.0f / 450.0f) * 40.0f + 60.0f;     /* pool +0x710, +0x404, +0x15C */
    return t > data_tol ? t : data_tol;
}

float gp_clip_fit_cost(const GpFitInput *in, const GpFitParams *p)
{
    float tx = p->tol_x, tz = p->tol_z;
    if (!(in->contact_frame < p->latest && in->contact_frame > p->earliest))
        return -1.0f;
    if (!in->has_racket_event) {
        tx = gp_clip_prep_tolerance(in->root_distance, p->tol_x);
        tz = gp_clip_prep_tolerance(in->root_distance, p->tol_z);
    }
    if (!(absf(in->err_x) < tx && absf(in->err_z) < tz))
        return -1.0f;
    return in->err_x * in->err_x + in->err_y * in->err_y + in->err_z * in->err_z;
}
