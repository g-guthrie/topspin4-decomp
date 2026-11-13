/*
 * Reference implementation: animation clip contact timing and fit scaffold.
 *
 * Source: Swing_DLL.xex planner 0x886D3AD8 / 0x886D4978 (part C of
 * docs/gameplay/stats-swing-clipfit.md).  Only the marker lookup, the
 * normalised-time to frame mapping and the acceptance window are verified.
 * The cost aggregate below is a scaffold, NOT the engine's formula.
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

float gp_clip_fit_cost(const GpFitInput *in, const GpFitParams *p)
{
    if (in->contact_frame < p->window_lo || in->contact_frame > p->window_hi)
        return -1.0f;
    return p->w_timing * absf(in->contact_frame - in->target_frame) +
           p->w_position * absf(in->pos_error) +
           p->w_height * absf(in->height_error) +
           p->w_facing * absf(in->facing_error);
}
