/* Self tests for timing.c and fatigue.c:
 *   cc -std=c11 -Wall -Wextra -Werror ref/gameplay/test_timing_fatigue.c ref/gameplay/timing.c \
 *      ref/gameplay/fatigue.c -lm -o $SCRATCH/ttf && $SCRATCH/ttf                         */
#include "fatigue.h"
#include "timing.h"

#include <math.h>
#include <stdio.h>

static int fails;
#define CHECK(c) do { if (!(c)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #c); fails++; } } while (0)
static int near(float a, float b) { return fabsf(a - b) < 1e-4f; }

int main(void)
{
    const Ts4Range *b = ts4_timing_baseline, *v = ts4_timing_volley;
    Ts4Fatigue f;
    /* timing curve: perfect at 20 frames, clamps outside 10..40 */
    CHECK(near(ts4_timing_value(b, 6, b, 6, 1, 20.0f, 0.5f), 0.0f));
    CHECK(near(ts4_timing_value(b, 6, b, 6, 1, 12.0f, 0.0f), 0.5f));
    CHECK(near(ts4_timing_value(b, 6, b, 6, 1, 5.0f, 0.0f), 1.0f));
    CHECK(near(ts4_timing_value(b, 6, b, 6, 1, 600.0f, 0.0f), -1.0f));
    CHECK(near(ts4_timing_value(b, 6, b, 6, 1, 35.0f, 0.0f), -0.75f));
    CHECK(near(ts4_timing_value(v, 6, v, 6, 1, 13.5f, 0.0f), 0.45f));
    CHECK(near(ts4_timing_value(b, 6, b, 6, 0, 20.0f, 0.0f), -1.0f));
    /* ability blends two different curves */
    CHECK(near(ts4_timing_value(b, 6, v, 6, 1, 12.0f, 0.5f), 0.55f));
    /* the |t| < 0.3 window of a groundstroke spans 14.4 .. 26 frames */
    CHECK(near(ts4_range_curve(b, 6, 14.4f), 0.3f) && near(ts4_range_curve(b, 6, 26.0f), -0.3f));

    /* vigor */
    ts4_fatigue_init(&f);
    CHECK(f.vigor == 1.0f && f.vigor_max == 1.0f);
    ts4_fatigue_add_acceleration(&f, 10.0f);      /* 0.001 < 0.02: ignored */
    CHECK(f.sum_acceleration == 0.0f);
    ts4_fatigue_add_acceleration(&f, 50.0f);      /* 0.005: ignored */
    ts4_fatigue_add_acceleration(&f, 300.0f);     /* 0.03 */
    CHECK(near(f.sum_acceleration, 0.03f));
    f.capacity = 50.0f;
    f.cost = 20.0f;
    ts4_fatigue_update_vigor(&f);
    CHECK(near(f.vigor, 0.8f));
    f.recovery_rate = 0.05f;
    f.recovery_scale = 100.0f;
    f.vigor_max = 0.9f;
    ts4_fatigue_point_end(&f, 0.0f, 1.0f);
    CHECK(near(f.total, 20.0f) && near(f.recovery, 0.9f));
    CHECK(near(f.vigor, 0.85f) && near(f.carried, 15.0f) && f.sum_acceleration == 0.0f);
    /* next point: the carried fatigue lowers vigor from the first frame */
    f.cost = 0.0f;
    ts4_fatigue_update_vigor(&f);
    CHECK(near(f.vigor, 0.85f));
    /* a set break (rest 3) recovers to the VigorMax ceiling */
    ts4_fatigue_point_end(&f, 0.0f, 3.0f);
    CHECK(near(f.vigor, 0.9f));
    /* rest 0 means 1; the bonus cannot drive the total negative */
    ts4_fatigue_point_end(&f, 1000.0f, 0.0f);
    CHECK(f.total == 0.0f && near(f.recovery, 1.0f));
    if (fails) return 1;
    printf("timing/fatigue ok\n");
    return 0;
}
