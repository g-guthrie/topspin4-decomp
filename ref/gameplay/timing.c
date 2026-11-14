#include "timing.h"

const Ts4Range ts4_timing_baseline[6] = {
    {10, 12, 1.0f, 0.5f}, {12, 15, 0.5f, 0.25f}, {15, 20, 0.25f, 0.0f},
    {20, 25, 0.0f, -0.25f}, {25, 30, -0.25f, -0.5f}, {30, 40, -0.5f, -1.0f},
};
const Ts4Range ts4_timing_volley[6] = {
    {10, 12, 1.0f, 0.6f}, {12, 15, 0.6f, 0.3f}, {15, 20, 0.3f, 0.0f},
    {20, 25, 0.0f, -0.3f}, {25, 30, -0.3f, -0.6f}, {30, 40, -0.6f, -1.0f},
};

float ts4_range_curve(const Ts4Range *r, int n, float x)
{
    const Ts4Range *k = r;
    float t, w;
    if (n <= 0) return 0.0f;
    for (int i = 0; i < n && r[i].in_start <= x; i++) k = &r[i];
    w = k->in_stop - k->in_start;
    t = x - k->in_start;
    if (t < 0.0f) t = 0.0f;          /* fsel at 0x88189A7C */
    if (t - w >= 0.0f) t = w;        /* fsel at 0x88189A9C */
    return t / w * (k->out_stop - k->out_start) + k->out_start;
}

float ts4_timing_value(const Ts4Range *worst, int nw, const Ts4Range *best, int nb,
                       int has_prediction, float frames, float ability)
{
    float a, b;
    if (!has_prediction) return -1.0f;
    a = ts4_range_curve(worst, nw, frames);
    b = ts4_range_curve(best, nb, frames);
    return (b - a) * ability + a;   /* fmadds at 0x8867E224 */
}
