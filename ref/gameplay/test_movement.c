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
    CHECK(strcmp(mv_state_name(MV_RUSH), "Rush") == 0);
    if (!fails)
        printf("movement tests passed\n");
    return fails != 0;
}
