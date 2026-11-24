/* Self-test for locomotion.c on synthetic numbers only (no game data). */
#include "locomotion.h"

#include <math.h>
#include <stdio.h>

static int fails;
#define CHECK(cond) do { if (!(cond)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #cond); ++fails; } } while (0)
static int near(float a, float b) { return fabsf(a - b) < 1e-4f; }

static void test_sectors(void)
{
    const float pi = 3.14159265f;
    CHECK(lo_sector8(0, 0, 1, 0.01f, 0) == LO_FRONT);
    CHECK(lo_sector8(0, 1, 0, 0.01f, 0) == LO_LEFT);
    CHECK(lo_sector8(0, -1, 0, 0.01f, 0) == LO_RIGHT);
    CHECK(lo_sector8(0, 0, -1, 0.01f, 0) == LO_BACK);
    CHECK(lo_sector8(0, 0, -1, 0.01f, 1) == LO_BACK_ALT);
    CHECK(lo_sector8(0, 1, 1, 0.01f, 0) == LO_FRONT_LEFT);
    CHECK(lo_sector8(0, -1, -1, 0.01f, 0) == LO_BACK_RIGHT);
    CHECK(lo_sector8(0, 0.05f, 0.05f, 0.01f, 0) == LO_STAND);
    /* Facing +x (yaw pi/2): moving +x is Front, moving +z is Right. */
    CHECK(lo_sector8(pi / 2, 1, 0, 0.01f, 0) == LO_FRONT);
    CHECK(lo_sector8(pi / 2, 0, 1, 0.01f, 0) == LO_RIGHT);
    /* 20 deg left still Front, 25 deg left is FrontLeft. */
    CHECK(lo_sector8(0, sinf(0.349f), cosf(0.349f), 0, 0) == LO_FRONT);
    CHECK(lo_sector8(0, sinf(0.436f), cosf(0.436f), 0, 0) == LO_FRONT_LEFT);
    CHECK(lo_sector16(0, 0, 1) == 0);
    CHECK(lo_sector16(0, sinf(pi / 8), cosf(pi / 8)) == 1);
    CHECK(lo_sector16(0, -1, 0) == 12);
    CHECK(lo_sector_direction(LO_FRONT_RIGHT) == LO_DIR_FRONT_RIGHT);
    CHECK(lo_sector_direction(LO_BACK_ALT) == LO_DIR_BACK);

    LoSectorEntry e9[10], e8[9], out;
    for (int i = 0; i < 10; ++i) { e9[i].group = 50; e9[i].subgroup = (int16_t)i; }
    for (int i = 0; i < 9; ++i) e8[i] = e9[i];
    LoMoveSet jog = {e9, 10}, rush = {e8, 9};
    CHECK(lo_moveset_pick(&jog, LO_BACK_ALT, &out) == 0 && out.subgroup == 9);
    CHECK(lo_moveset_pick(&rush, LO_BACK_ALT, &out) == 0 && out.subgroup == LO_BACK);
    CHECK(lo_moveset_pick(&rush, LO_STAND, &out) == 0 && out.subgroup == 8);
}

static void test_transitions(void)
{
    LoTransitionEvent ev[2] = {
        {0, 0, 0x1FE, 1u << LO_PACE_JOG, 0.0f, 0.1f, 0, 0, 0, 1, 0},     /* In window */
        {0, 0, (1u << LO_DIR_LEFT) | (1u << LO_DIR_FRONT), (1u << LO_PACE_JOG) | (1u << LO_PACE_SIDESTEPS),
         0.6f, 0.2f, 0, 0, 0, 0, 1},                                    /* Out window */
    };
    CHECK(lo_event_accepts(&ev[1], LO_DIR_LEFT, LO_PACE_JOG));
    CHECK(!lo_event_accepts(&ev[1], LO_DIR_RIGHT, LO_PACE_JOG));
    CHECK(!lo_event_accepts(&ev[1], LO_DIR_LEFT, LO_PACE_SERVE));
    CHECK(lo_next_out_event(ev, 2, 0.3f, LO_DIR_FRONT, LO_PACE_JOG) == 1);
    CHECK(lo_next_out_event(ev, 2, 0.9f, LO_DIR_FRONT, LO_PACE_JOG) == -1);
    CHECK(!lo_can_leave(ev, 2, 0.5f, LO_DIR_FRONT, LO_PACE_JOG));
    CHECK(lo_can_leave(ev, 2, 0.7f, LO_DIR_FRONT, LO_PACE_JOG));

    LoMatrixCell r0[] = {{73, 13}, {76, 13}}, r2[] = {{5, 7}};
    LoMatrixRow rows[3] = {{r0, 2}, {0, 0}, {r2, 1}};
    CHECK(lo_matrix_rule(rows, 3, 0, 76) == 13);
    CHECK(lo_matrix_rule(rows, 3, 1, 76) == -1);
    CHECK(lo_matrix_rule(rows, 3, 2, 5) == 7);
    CHECK(lo_matrix_rule(rows, 3, 9, 5) == -1);

    LoTransitionRule r;
    lo_rule_defaults(&r);
    CHECK(near(r.blend_in_frames, 15) && near(lo_rule_speed(&r, 0.3f), 1));
    r.low_vivacity_speed = 0.8f;
    CHECK(near(lo_rule_speed(&r, 0), 0.8f) && near(lo_rule_speed(&r, 0.5f), 0.9f) &&
          near(lo_rule_speed(&r, 2), 1.0f));
    CHECK(near(lo_blend_weight(5, 10), 0.5f) && near(lo_blend_weight(20, 10), 1) &&
          near(lo_blend_weight(3, 0), 1));
}

static void test_clock(void)
{
    /* 61-frame clip started at frame 100 at phase 0. */
    CHECK(near(lo_phase_to_frame(0.5f, 0, 61, 100, 160), 130));
    CHECK(near(lo_phase_to_frame(2.0f, 0, 61, 100, 160), 160));
    CHECK(near(lo_phase_to_frame(-1, 0, 61, 100, 160), 100));
    CHECK(near(lo_frames_until_out(0.75f, 0, 61, 100, 120), 25));
    CHECK(near(lo_frames_until_out(0.75f, 0, 61, 100, 200), 0));

    CHECK(near(lo_cycle_phase(0.9f, 0.5f, 0.8f), 0.6f));
    CHECK(near(lo_cycle_phase(0.7f, 0.5f, 0.8f), 0.7f));
    CHECK(near(lo_roty_offset(50, 60, 160, 0, 0.7854f), 0));
    CHECK(near(lo_roty_offset(110, 60, 160, 0, 0.7854f), 0.3927f));
    CHECK(near(lo_roty_offset(200, 60, 160, 0, 0.7854f), 0.7854f));

    LoClipProps c = {61, 1.2f, 0, 0};
    CHECK(near(lo_play_rate(&c, 1, 0, 1.15f, 1), 1.2f));
    CHECK(near(lo_play_rate(&c, 1, 1, 1.15f, 1), 1.38f));
    c.ignore_speed_coef = 1;
    CHECK(near(lo_play_rate(&c, 1, 1, 1.15f, 0.8f), 0.92f));
}

static void test_root_and_glue(void)
{
    const float pi = 3.14159265f;
    LoVec3 fwd = {0, 0, 10}, left = {10, 0, 0};
    LoVec3 w = lo_root_step(fwd, 0, 0, 1);
    CHECK(near(w.x, 0) && near(w.z, 10));
    w = lo_root_step(fwd, pi / 2, 0, 1);      /* facing +x */
    CHECK(near(w.x, 10) && near(w.z, 0));
    w = lo_root_step(left, 0, 1, 0.5f);       /* mirrored, half rate */
    CHECK(near(w.x, -5) && near(w.z, 0));
    /* Sector of the displacement agrees with the local direction. */
    w = lo_root_step(left, 1.0f, 0, 1);
    CHECK(lo_sector8(1.0f, w.x, w.z, 0, 0) == LO_LEFT);

    CHECK(near(lo_override_update(1.0f, 0.7f, 0.4f), 1.0f));
    CHECK(near(lo_override_update(1.0f, 0.5f, 0.4f), 0.5f));

    LoVec3 player = {0, 0, 0}, near_ball = {100, 0, 100}, far_ball = {300, 0, 0};
    CHECK(lo_retarget(near_ball, player, 62500, 0, 0.5f, 1) == 8);
    CHECK(lo_retarget(near_ball, player, 62500, 0, -0.5f, 1) == 7);
    CHECK(lo_retarget(near_ball, player, 62500, 1, -0.5f, 1) == -1);
    CHECK(lo_retarget(far_ball, player, 62500, 0, -0.5f, 1) == -1);
}

int main(void)
{
    test_sectors();
    test_transitions();
    test_clock();
    test_root_and_glue();
    if (fails) {
        printf("%d failure(s)\n", fails);
        return 1;
    }
    printf("test_locomotion: ok\n");
    return 0;
}
