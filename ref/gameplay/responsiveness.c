/* See responsiveness.h. */
#include "responsiveness.h"

#include <math.h>

#define RS_PI 3.14159265358979f

void rs_stick_to_required_move(float stick_x, float stick_y, int far_side,
                               float *direction, float *power)
{
    float vx = stick_y, vz = -stick_x;
    float len = sqrtf(vx * vx + vz * vz);
    float dir = atan2f(vx, vz);
    *power = len < 1.0f ? len : 1.0f;
    if (far_side) {
        dir += RS_PI;
        if (dir > RS_PI)
            dir -= 2.0f * RS_PI;
    }
    *direction = dir;
}

void rs_freeze_reset(RsFreeze *f)
{
    f->frozen = 0;
    f->stopped = 0;
    f->dir = 0.0f;
    f->power = 0.0f;
}

void rs_prehit_freeze(RsFreeze *f, int applies, int frames_to_hit,
                      int freeze_frames, int stop_frames,
                      float in_dir, float in_power, float *out_dir, float *out_power)
{
    if (!applies || frames_to_hit >= freeze_frames) {
        rs_freeze_reset(f);
        *out_dir = in_dir;
        *out_power = in_power;
        return;
    }
    if (!f->frozen) {
        f->frozen = 1;
        f->dir = in_dir;
        f->power = in_power;
    }
    if (!f->stopped && frames_to_hit > stop_frames && in_power < 0.1f && f->power > 0.1f)
        f->stopped = 1;
    *out_dir = f->dir;
    *out_power = f->stopped ? 0.0f : f->power;
}

int rs_reaction_done(int clock, int stamp, float delay, int doubles)
{
    return doubles || (float)(clock - stamp) >= delay;
}

int rs_rush_mode(const RsRushIn *in, const RsRushCfg *cfg)
{
    int mode = 0;
    if (!in->gate)
        return in->prev_mode;
    if (in->move_power < cfg->min_power || in->player_x > cfg->net_x)
        return 0;
    if (in->dist_to_net > cfg->min_dist && in->angle_to_net < cfg->max_angle) {
        int in_box = in->player_x > cfg->box_x0 && in->player_x < cfg->box_x1
                     && fabsf(in->player_z) < cfg->box_z;
        if ((in_box && in->play_mode != 1) || in->rb)
            mode = 2;
    }
    if (mode != in->prev_mode && mode == 2 && in->opp_plan_valid
        && (unsigned)in->frames_to_hit < (unsigned)cfg->refuse_frames)
        mode = in->prev_mode;
    return mode;
}

float rs_blend_weight(float elapsed, float duration)
{
    float w;
    if (duration <= 0.0f)
        return 1.0f;
    w = elapsed / duration;
    return w < 0.0f ? 0.0f : (w > 1.0f ? 1.0f : w);
}

static void root_pos(const float (*xz)[2], float n, float t, float *x, float *z)
{
    float u = t * n;
    int i = (int)u;
    float f = u - (float)i;
    *x = xz[i][0] * (1.0f - f) + xz[i + 1][0] * f;
    *z = xz[i][1] * (1.0f - f) + xz[i + 1][1] * f;
}

void rs_root_delta(const float (*xz)[2], float count_minus_one, float t1, float t2,
                   float *dx, float *dz)
{
    float x1, z1, x2, z2;
    root_pos(xz, count_minus_one, t1, &x1, &z1);
    root_pos(xz, count_minus_one, t2, &x2, &z2);
    *dx = x2 - x1;
    *dz = z2 - z1;
}

int rs_frames_to_distance(const float (*d)[2], int n, float blend_frames, float target_cm)
{
    float x = 0.0f, z = 0.0f;
    int k;
    for (k = 0; k < n; ++k) {
        float w = blend_frames > 0.0f ? (float)(k + 1) / blend_frames : 1.0f;
        if (w > 1.0f)
            w = 1.0f;
        x += w * d[k][0];
        z += w * d[k][1];
        if (sqrtf(x * x + z * z) >= target_cm)
            return k + 1;
    }
    return -1;
}
