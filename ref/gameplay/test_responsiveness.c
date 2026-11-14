/* Self-test for responsiveness.c on synthetic numbers only (no game data). */
#include "responsiveness.h"

#include <math.h>
#include <stdio.h>

static int fails;
#define CHECK(cond) do { if (!(cond)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #cond); ++fails; } } while (0)
static int near(float a, float b) { return fabsf(a - b) < 1e-4f; }

static void test_stick(void)
{
    const float pi = 3.14159265f;
    float d, p;
    rs_stick_to_required_move(0, 1, 0, &d, &p);      /* up: v = (1, 0, 0) */
    CHECK(near(p, 1) && near(d, pi / 2));
    rs_stick_to_required_move(-1, 0, 0, &d, &p);     /* left: v = (0, 0, 1) */
    CHECK(near(d, 0));
    rs_stick_to_required_move(-1, 0, 1, &d, &p);     /* far side adds pi */
    CHECK(near(fabsf(d), pi));
    rs_stick_to_required_move(0, 1, 1, &d, &p);      /* pi/2 + pi wraps to -pi/2 */
    CHECK(near(d, -pi / 2));
    rs_stick_to_required_move(0.3f, 0.4f, 0, &d, &p);
    CHECK(near(p, 0.5f));
    rs_stick_to_required_move(1, 1, 0, &d, &p);
    CHECK(near(p, 1));
}

static void test_freeze(void)
{
    RsFreeze f;
    float d, p;
    rs_freeze_reset(&f);
    rs_prehit_freeze(&f, 1, 25, 20, 10, 0.5f, 1.0f, &d, &p);   /* outside: pass */
    CHECK(near(d, 0.5f) && near(p, 1.0f) && !f.frozen);
    rs_prehit_freeze(&f, 1, 19, 20, 10, 0.7f, 0.8f, &d, &p);   /* first frozen frame latches */
    CHECK(f.frozen && near(d, 0.7f) && near(p, 0.8f));
    rs_prehit_freeze(&f, 1, 18, 20, 10, -1.0f, 1.0f, &d, &p);  /* new stick ignored */
    CHECK(near(d, 0.7f) && near(p, 0.8f));
    rs_prehit_freeze(&f, 1, 15, 20, 10, 0.0f, 0.0f, &d, &p);   /* release before 10 -> stop */
    CHECK(f.stopped && near(p, 0));
    rs_prehit_freeze(&f, 1, 12, 20, 10, 0.7f, 1.0f, &d, &p);   /* stays stopped */
    CHECK(near(p, 0));
    rs_prehit_freeze(&f, 0, -1, 20, 10, 0.2f, 0.9f, &d, &p);   /* opponent no longer next hitter */
    CHECK(!f.frozen && near(p, 0.9f));

    rs_freeze_reset(&f);
    rs_prehit_freeze(&f, 1, 19, 20, 10, 0.1f, 1.0f, &d, &p);
    rs_prehit_freeze(&f, 1, 9, 20, 10, 0.1f, 0.0f, &d, &p);    /* release in the last 10: no stop */
    CHECK(!f.stopped && near(p, 1.0f));
}

static void test_reaction(void)
{
    CHECK(rs_reaction_done(100, 100, 0.0f, 0));     /* human: delay 0 */
    CHECK(!rs_reaction_done(104, 100, 5.0f, 0));
    CHECK(rs_reaction_done(105, 100, 5.0f, 0));
    CHECK(rs_reaction_done(100, 100, 9.0f, 1));     /* doubles */
}

static void test_rush(void)
{
    const RsRushCfg cfg = {-500, 0.1f, 0.6981317f, 175, -1100, -700, 400, 20};
    RsRushIn in = {1, -1189, 0, 1.0f, 0.1f, 700, 0, 0, 0, 1, 60};
    CHECK(rs_rush_mode(&in, &cfg) == 0);            /* behind the box, no RB */
    in.rb = 1;
    CHECK(rs_rush_mode(&in, &cfg) == 2);
    in.frames_to_hit = 19;
    CHECK(rs_rush_mode(&in, &cfg) == 0);            /* refused: keeps previous mode */
    in.prev_mode = 2;
    CHECK(rs_rush_mode(&in, &cfg) == 2);            /* already rushing: not re-tested */
    in.prev_mode = 0;
    in.frames_to_hit = -3;                          /* past the hit (unsigned huge) */
    CHECK(rs_rush_mode(&in, &cfg) == 2);
    in.rb = 0; in.player_x = -900; in.frames_to_hit = 60;
    CHECK(rs_rush_mode(&in, &cfg) == 2);            /* inside the box */
    in.play_mode = 1;
    CHECK(rs_rush_mode(&in, &cfg) == 0);            /* box ignored in play mode 1 */
    in.play_mode = 0; in.move_power = 0.05f;
    CHECK(rs_rush_mode(&in, &cfg) == 0);
    in.move_power = 1; in.angle_to_net = 0.8f;
    CHECK(rs_rush_mode(&in, &cfg) == 0);
    in.angle_to_net = 0.1f; in.player_x = -400;
    CHECK(rs_rush_mode(&in, &cfg) == 0);            /* at the net */
    in.gate = 0; in.prev_mode = 2;
    CHECK(rs_rush_mode(&in, &cfg) == 2);
}

static void test_blend_and_root(void)
{
    static const float xz[5][2] = {{0, 0}, {4, 0}, {12, 1}, {24, 2}, {0, 0}};
    static float d[40][2];
    float dx, dz;
    int k;
    CHECK(near(rs_blend_weight(0, 15), 0) && near(rs_blend_weight(7.5f, 15), 0.5f));
    CHECK(near(rs_blend_weight(30, 15), 1) && near(rs_blend_weight(3, 0), 1));
    rs_root_delta(xz, 3, 0.0f, 1.0f, &dx, &dz);
    CHECK(near(dx, 24) && near(dz, 2));
    rs_root_delta(xz, 3, 0.5f / 3.0f, 1.0f / 3.0f, &dx, &dz);   /* u 0.5 -> 1 */
    CHECK(near(dx, 2) && near(dz, 0));
    for (k = 0; k < 40; ++k) {
        d[k][0] = 1.0f;
        d[k][1] = 0.0f;
    }
    CHECK(rs_frames_to_distance(d, 40, 0, 5) == 5);
    CHECK(rs_frames_to_distance(d, 40, 10, 5) == 10);   /* 0.1+...+0.9 = 4.5, +1.0 = 5.5 */
    CHECK(rs_frames_to_distance(d, 40, 0, 100) == -1);
}

int main(void)
{
    test_stick();
    test_freeze();
    test_reaction();
    test_rush();
    test_blend_and_root();
    if (fails)
        printf("%d failures\n", fails);
    else
        printf("responsiveness: all tests passed\n");
    return fails != 0;
}
