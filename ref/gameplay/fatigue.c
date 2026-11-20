#include "fatigue.h"

void ts4_fatigue_init(Ts4Fatigue *f)
{
    Ts4Fatigue z = {0};
    *f = z;
    f->vigor = f->recovery = f->vigor_max = 1.0f;
}

void ts4_fatigue_add_acceleration(Ts4Fatigue *f, float accel)
{
    float a = accel * 0.1f * 0.001f;     /* consts +0x2AC, +0x80 */
    if (a > 0.02f) f->sum_acceleration += a;   /* consts +0x408 */
}

void ts4_fatigue_update_vigor(Ts4Fatigue *f)
{
    float v = 1.0f - (f->carried + f->cost) / (f->capacity * 2.0f);
    f->vigor = v < 0.0f ? 0.0f : v;
}

void ts4_fatigue_point_end(Ts4Fatigue *f, float bonus, float rest)
{
    float v;
    f->total += f->cost;
    f->total -= bonus;
    if (f->total < 0.0f) f->total = 0.0f;
    if (f->recovery_scale != 0.0f) {
        float r = 1.0f - f->total / (2.0f * f->recovery_scale);
        f->recovery = r < 0.0f ? 0.0f : r;
    }
    if (rest == 0.0f) rest = 1.0f;
    v = f->recovery_rate * rest + f->vigor;
    if (v > f->vigor_max) v = f->vigor_max;
    f->vigor = v;
    f->carried = (1.0f - v) * f->capacity * 2.0f;
    f->sum_acceleration = f->sum_powerful = 0.0f;
}
