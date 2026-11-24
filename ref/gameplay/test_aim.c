/* Self tests for aim.c (synthetic), plus an optional check of the real tables:
 *   cc -std=c11 -Wall -Wextra -Werror ref/gameplay/test_aim.c ref/gameplay/aim.c -lm -o /tmp/ta
 *   /tmp/ta [data/gameplay/aim_tables.txt]                                          */
#include "aim.h"

#include <math.h>
#include <stdio.h>

static int fails;
#define CHECK(c) do { if (!(c)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #c); fails++; } } while (0)
static int near(float a, float b) { return fabsf(a - b) < 0.01f; }

static void square(Ts4Quad *q, float x0, float x1, float h)
{
    q->c[0] = (Ts4Pt){x0, -h}; q->c[1] = (Ts4Pt){x0, h};
    q->c[2] = (Ts4Pt){x1, -h}; q->c[3] = (Ts4Pt){x1, h};
}

int main(int argc, char **argv)
{
    static Ts4AimConfig cfg;
    Ts4Pt p;
    float ax, ay;
    cfg.volley_distance = 300.0f;
    cfg.baseline_distance = 1300.0f;
    cfg.center_distance = 0.0f;
    cfg.side_distance = 350.0f;
    for (int z = 0; z < 4; z++) {
        cfg.zone[z].centre = (Ts4Pt){700.0f, 0.0f};
        square(&cfg.zone[z].quad[0], 690.0f, 710.0f, 10.0f);
        square(&cfg.zone[z].quad[1], 600.0f, 900.0f, 200.0f);
        square(&cfg.zone[z].quad[2], 600.0f, 1188.0f, 411.0f);
        square(&cfg.zone[z].quad[3], 550.0f, 1488.0f, 710.0f);
    }
    /* stick state */
    CHECK(!ts4_aim_quad_state(0.0f, 0.0f, 0, &ax, &ay));
    CHECK(ts4_aim_quad_state(0.5f, -0.2f, 1, &ax, &ay) && ax == -0.5f && ay == 0.2f);
    /* no direction: the zone centre */
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 1.0f, 0.0f, 0.0f, 0, 0, 0.0f);
    CHECK(near(p.x, 700.0f) && near(p.z, 0.0f));
    /* efficiency 1 = the court lines; direction only, magnitude ignored */
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 1.0f, 0.0f, 0.3f, 1, 0, 0.0f);
    CHECK(near(p.x, 1188.0f) && near(p.z, 0.0f));
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 1.0f, 1.0f, 0.0f, 1, 0, 0.0f);
    CHECK(near(p.x, 894.0f) && near(p.z, 411.0f));
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 1.0f, 0.7f, 0.7f, 1, 0, 0.0f);
    CHECK(near(p.x, 1188.0f) && near(p.z, 411.0f));
    /* efficiency 0.5 = quad 1, 0.75 = half way to the lines */
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 0.5f, 0.0f, 1.0f, 1, 0, 0.0f);
    CHECK(near(p.x, 900.0f));
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 0.75f, 0.0f, 1.0f, 1, 0, 0.0f);
    CHECK(near(p.x, 1044.0f));
    /* the Out path: m = OutEfficiency + 1 = 1.5 is half way to quad 3 */
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 1.5f, 0.0f, 1.0f, 1, 0, 0.0f);
    CHECK(near(p.x, 1338.0f));
    /* doubles alley: quad 2 widened by 137 cm */
    p = ts4_aim_target(&cfg, -1188.0f, -50.0f, 1.0f, 1.0f, 0.0f, 1, 0, 137.0f);
    CHECK(near(p.z, 548.0f));
    /* mirror keeps the stick's sense in world z */
    CHECK(ts4_aim_mirror(0, 0, 50.0f) && !ts4_aim_mirror(0, 1, -50.0f) && ts4_aim_mirror(1, 1, -50.0f));
    p = ts4_aim_target(&cfg, -1188.0f, 50.0f, 1.0f, 1.0f, 0.0f, 1, 1, 0.0f);
    CHECK(near(p.z, 411.0f));
    if (argc > 1) {
        static Ts4AimConfig real[32];
        int n = ts4_aim_load(argv[1], real, 32);
        CHECK(n == 25);
        if (n >= 5) {
            /* FlatNormal (index 4), baseline, full efficiency, stick right: right sideline */
            CHECK(real[4].id == 0x59f4f54du);
            p = ts4_aim_target(&real[4], -1188.0f, -50.0f, 1.0f, 1.0f, 0.0f, 1, 0, 0.0f);
            CHECK(p.z > 405.0f && p.z < 415.0f);
            printf("FlatNormal right at efficiency 1: (%.1f, %.1f)\n", p.x, p.z);
        }
    }
    if (fails) return 1;
    printf("aim ok\n");
    return 0;
}
