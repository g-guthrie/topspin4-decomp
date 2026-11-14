/* Self-test for movement.c / ai_driver.c (synthetic data only). */
#include <stdio.h>
#include <string.h>
#include "movement.h"

static int fails;
#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); fails++; } } while (0)

static float table(const struct mv_mode_cfg *m, float d, float slack, void *u)
{
    (void)m; (void)u;
    return slack > d * 0.01f ? 1.0f : 0.0f;
}

static float score(const struct ai_candidate *c, int human, void *u)
{
    (void)u;
    return 1.0f / (1.0f + c->reach_speed) + (human ? c->input_notation : 0.0f);
}

int main(void)
{
    struct mv_cfg cfg;
    struct mv_planner p;
    struct mv_world w;
    struct mv_out out;
    struct ai_candidate c[4];
    int flags;

    memset(&cfg, 0, sizeof cfg);
    cfg.reaction_frames = 12.0f;
    cfg.validity_threshold = 0.5f;
    cfg.rush_guard = 1.0f;
    cfg.rush.min_distance = 300.0f;
    cfg.jogjog.min_distance = 150.0f;
    cfg.jog.min_distance = 50.0f;
    cfg.max_hops = 8;

    /* reaction delay */
    memset(&p, 0, sizeof p);
    memset(&w, 0, sizeof w);
    w.frames_since_opp_hit = 5;
    w.sel_from_anticipate = MV_ANTICIPATE_A;
    CHECK(mv_next_state(&p, &cfg, &w, &out) == MV_WAIT);
    w.frames_since_opp_hit = 12;
    CHECK(mv_next_state(&p, &cfg, &w, &out) == MV_ANTICIPATE_A);

    /* speed regime selection order */
    CHECK(mv_select_move_state(&cfg, 0, 0, 0, 2.0f, 400.0f, 10.0f, table, 0,
                               &flags) == MV_RUSH && flags == 1);
    CHECK(mv_select_move_state(&cfg, 0, 0, 0, 0.5f, 400.0f, 10.0f, table, 0,
                               &flags) == MV_JOGJOG);
    CHECK(mv_select_move_state(&cfg, 0, 0, 0, 0.5f, 100.0f, 10.0f, table, 0,
                               &flags) == MV_JOG);
    CHECK(mv_select_move_state(&cfg, 0, 0, 0, 0.5f, 10.0f, 10.0f, table, 0,
                               &flags) == MV_APPROACH);
    CHECK(mv_select_move_state(&cfg, 0, 0, 1, 2.0f, 400.0f, 10.0f, table, 0,
                               &flags) == MV_VOLLEY);

    /* fixed-point update with replan resume */
    memset(&p, 0, sizeof p);
    p.state = MV_APPROACH_NEAR;
    memset(&w, 0, sizeof w);
    w.replan = 1;
    w.candidate_stable_window = 0;
    CHECK(mv_update(&p, &cfg, &w, &out) == MV_APPROACH_NEAR); /* 6 -> 9 -> 6 */
    CHECK(p.saved_state == MV_APPROACH_NEAR);

    /* AI argmax truth table and human/AI scoring */
    memset(c, 0, sizeof c);
    c[0].reach_speed = 5; c[1].reach_speed = 2; c[1].is_volley = 1;
    c[2].reach_speed = 1; c[3].reach_speed = 80;
    c[0].input_notation = c[1].input_notation = 0.5f;
    ai_score_all(c, 4, 0, 50.0f, score, 0);
    CHECK(c[3].score == -1.0f);
    CHECK(ai_argmax(c, 4, 0, 0, -0.5f) == 2);
    CHECK(ai_argmax(c, 4, 0, 1, -0.5f) == 1);
    CHECK(ai_argmax(c, 4, 1, 0, -0.5f) == 2);
    {
        struct ai_stick raw = {0.7f, -0.3f}, z = ai_effective_stick(0, raw);
        CHECK(z.x == 0.0f && z.y == 0.0f);
        z = ai_effective_stick(1, raw);
        CHECK(z.x == 0.7f);
    }
    CHECK(mv_ball_window(-600.0f, 45.0f, 0.0f) && !mv_ball_window(-900.0f, 45.0f, 0.0f));
    CHECK(!mv_ball_window(600.0f, 30.0f, 100.0f) && mv_ball_window(600.0f, 30.0f, -450.0f));
    CHECK(mv_shot_window(-1000.0f, 0, 20.0f) && !mv_shot_window(-1000.0f, 0, 80.0f));
    CHECK(mv_shot_window(-1000.0f, 1, 80.0f) && !mv_shot_window(-700.0f, 1, 0.0f));
    CHECK(mv_alt_swing_ok(1, 2.0f, 0.5f, 5, 0) && !mv_alt_swing_ok(1, 1.0f, 0.5f, 5, 0));
    CHECK(!mv_alt_swing_ok(1, 2.0f, 0.1f, 5, 0) && !mv_alt_swing_ok(0, 0.0f, 0.0f, 10, 0));
    CHECK(mv_alt_swing_ok(0, 0.0f, 0.0f, 9, 0) && !mv_alt_swing_ok(0, 0.0f, 0.0f, 9, 1));
    CHECK(strcmp(mv_state_name(MV_RUSH), "Rush") == 0);
    /* GE2: planner geometry and repositioning */
    {
        struct mv_v2 a = {0, 100}, q = {0, 0}, pos = {0, -100}, pred = {0, -10}, pt;
        float t1, t2;
        CHECK(mv_replan_check(a, q, pos, pred, 8) == 1);
        CHECK(mv_replan_check(a, q, pos, pred, 30) == -1);
        pred.z = -50.0f;                       /* 50 cm short of the stand point */
        CHECK(mv_replan_check(a, q, pos, pred, 8) == 0);
        pred.z = -10.0f; pred.x = 45.0f;       /* 45 cm off the line */
        CHECK(mv_replan_check(a, q, pos, pred, 8) == 0);
        {
            struct mv_v2 p1 = {0, 0}, d1 = {1, 0}, p2 = {50, -20}, d2 = {0, 1};
            CHECK(mv_line_intersect(p1, d1, p2, d2, &pt, &t1, &t2));
            CHECK(pt.x == 50.0f && t1 == 50.0f && t2 == 20.0f);
            CHECK(!mv_line_intersect(p1, d1, p2, d1, &pt, &t1, &t2));
        }
        {
            struct mv_v2 tq = {500, 0}, tp = {0, 0}, v0 = {0, 0}, tb = {-500, 1};
            CHECK(mv_run_angle(tq, tp, v0) < 0.01f && mv_run_angle(tb, tp, v0) > 3.1f);
            CHECK(mv_mode_slack(60, 10.0f, 15.0f) == 35.0f);
        }
        {
            float sum = 0.0f, mean = 0.0f; int i;
            for (i = 0; i < 60; i++) mv_mover_step(&sum, &mean, 6.0f, 3.0f);
            CHECK(mean > 5.99f && mean < 6.01f);
        }
        CHECK(mv_volley_or_bounce(0, 1) && !mv_volley_or_bounce(1, 1) && !mv_volley_or_bounce(0, 0));
        CHECK(mv_human_reach_input(2.0f, 1.0f, 2.8f) == 1.0f && mv_human_reach_input(4.0f, 1.0f, 2.8f) == 100.0f);
        {
            struct mv_v2 p = {-1000, 0}, b0 = {1000, 0}, b1l = {-1100, -100}, b1r = {-1100, 100};
            CHECK(mv_inside_out(p, b0, b1l, 0) && !mv_inside_out(p, b0, b1r, 0));
        }
        {
            struct mv_v2 net, base;
            rp_singles_points(600.0f, &net, &base);
            CHECK(net.x == 300.0f && net.z == 100.0f && base.x == 1300.0f && base.z == -50.0f);
            rp_singles_points(-900.0f, &net, &base);
            CHECK(net.z == -100.0f && base.z == 50.0f);
        }
        CHECK(rp_human_mode(-900.0f, 0.0f, 0.5f, 0.2f, 600.0f, 0, 0, 0, 0, 0) == 2);  /* baseline box */
        CHECK(rp_human_mode(-600.0f, 0.0f, 0.5f, 0.2f, 600.0f, 0, 0, 0, 0, 0) == 0);  /* outside: needs RB */
        CHECK(rp_human_mode(-600.0f, 0.0f, 0.5f, 0.2f, 600.0f, 1, 0, 0, 0, 0) == 2);
        CHECK(rp_human_mode(-400.0f, 0.0f, 0.5f, 0.2f, 600.0f, 1, 0, 0, 0, 0) == 0);  /* already at the net */
        CHECK(rp_human_mode(-900.0f, 0.0f, 0.5f, 0.8f, 600.0f, 1, 0, 0, 0, 0) == 0);  /* stick 46 deg off */
        CHECK(rp_human_mode(-900.0f, 0.0f, 0.5f, 0.2f, 600.0f, 1, 0, 1, 10, 0) == 0); /* event in 10 frames */
        CHECK(rp_ai_singles_mode(0.3f, 0.5f, 0.5f, 0) == 2 && rp_ai_singles_mode(0.7f, 0.5f, 0.5f, 0) == 1);
        CHECK(rp_doubles_nearest(1, 2, 3, 4, 0) == 4 && rp_doubles_nearest(4, 3, 2, 1, 0) == 5);
        CHECK(rp_doubles_nearest(1, 1, 3, 4, 7) == 7);
        CHECK(rp_doubles_ai_swap(3, 100.0f, 0.0f) == 5 && rp_doubles_ai_swap(6, -100.0f, 0.0f) == 4);
        CHECK(rp_doubles_ai_swap(0, -1.0f, -1000.0f) == 3 && rp_doubles_ai_swap(0, 1.0f, -500.0f) == 6);
        CHECK(!rp_ai_stop(1.0f, 0.0f, 0.0f, 30.0f) && rp_ai_stop(0.0f, 0.0f, 40.0f, 30.0f));
        {
            int stamp = -1;
            CHECK(rp_ai_post_swing_hold(20, 1, &stamp, 100) == 1 && stamp == -1);
            CHECK(rp_ai_post_swing_hold(20, 0, &stamp, 110) == 1 && stamp == 110);
            CHECK(rp_ai_post_swing_hold(20, 0, &stamp, 130) == 1 && rp_ai_post_swing_hold(20, 0, &stamp, 131) == 0);
        }
    }
    if (!fails)
        printf("movement tests passed\n");
    return fails != 0;
}
