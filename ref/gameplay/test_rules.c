/* Self-test for the Top Spin 4 rules reference implementation. */
#include "rules.h"

#include <stdio.h>
#include <stdlib.h>

static int failures;

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            fprintf(stderr, "%s:%d: FAILED: %s\n", __FILE__, __LINE__, #cond); \
            failures++;                                                      \
        }                                                                    \
    } while (0)

static const rules_config best_of_three = { 6, 3, false, false, false, false };

static unsigned rally(rules_state *rs, int winner)
{
    return rules_end_point(rs, RULES_END_RALLY, winner);
}

static unsigned win_game(rules_state *rs, int w)
{
    unsigned ev = 0;
    for (int i = 0; i < 4; i++)
        ev |= rally(rs, w);
    return ev;
}

static void test_game_scoring(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);

    CHECK(rules_display(&rs, 0) == 0 && rules_display(&rs, 1) == 0);
    rally(&rs, 0);
    CHECK(rules_display(&rs, 0) == 15);
    rally(&rs, 0);
    CHECK(rules_display(&rs, 0) == 30);
    rally(&rs, 1);
    CHECK(rules_display(&rs, 1) == 15);
    rally(&rs, 0);
    CHECK(rules_display(&rs, 0) == 40 && rules_display(&rs, 1) == 15);
    unsigned ev = rally(&rs, 0);
    CHECK(ev & RULES_EV_GAME);
    CHECK(rs.p[0].sets[0].games == 1);
    CHECK(rs.p[0].points == 0 && rs.p[1].points == 0);
}

static void test_deuce_advantage(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);

    for (int i = 0; i < 3; i++) { rally(&rs, 0); rally(&rs, 1); }
    CHECK(rules_display(&rs, 0) == 40 && rules_display(&rs, 1) == 40);
    CHECK(rs.deuce && rs.deuce_first);

    rally(&rs, 0);                       /* advantage player 0 */
    CHECK(rules_display(&rs, 0) == -1 && rules_display(&rs, 1) == 40);
    rally(&rs, 1);                       /* back to deuce */
    CHECK(rules_display(&rs, 0) == 40 && rules_display(&rs, 1) == 40);
    CHECK(rs.deuce && !rs.deuce_first);

    rally(&rs, 1);
    CHECK(rules_display(&rs, 1) == -1);
    unsigned ev = rally(&rs, 1);         /* advantage converted */
    CHECK(ev & RULES_EV_GAME);
    CHECK(rs.p[1].sets[0].games == 1);
}

static void test_set_and_tiebreak(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);

    /* 5-5 then 6-5 does not end the set, 7-5 does */
    for (int i = 0; i < 5; i++) { win_game(&rs, 0); win_game(&rs, 1); }
    win_game(&rs, 0);
    CHECK(rs.cur_set == 0 && !rs.tiebreak);
    unsigned ev = win_game(&rs, 0);
    CHECK(ev & RULES_EV_SET);
    CHECK(rs.cur_set == 1 && rs.p[0].sets_won == 1);

    /* second set: 6-6 starts a seven point tiebreak */
    for (int i = 0; i < 6; i++) { win_game(&rs, 1); win_game(&rs, 0); }
    CHECK(rs.tiebreak && rs.point_target == RULES_TIEBREAK_TARGET);
    for (int i = 0; i < 6; i++) { rally(&rs, 0); rally(&rs, 1); }
    CHECK(rules_display(&rs, 0) == 6 && rules_display(&rs, 1) == 6);
    rally(&rs, 0);                       /* 7-6: not yet, need two clear */
    CHECK(rs.cur_set == 1);
    ev = rally(&rs, 0);                  /* 8-6 */
    CHECK((ev & RULES_EV_SET) && (ev & RULES_EV_MATCH));
    CHECK(rs.match_over && rs.match_winner == 0);
    CHECK(rs.p[0].sets[1].games == 7 && rs.p[1].sets[1].games == 6);
    CHECK(rs.p[0].sets[1].tb_points == 8 && rs.p[1].sets[1].tb_points == 6);
}

static void test_tiebreak_serving_and_ends(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);
    for (int i = 0; i < 6; i++) { win_game(&rs, 0); win_game(&rs, 1); }
    CHECK(rs.tiebreak);
    CHECK(rules_server(&rs) == 0);       /* player 0 serves the first point */

    int expect[12] = { 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 };
    /* server for points 2..13 follows 1,2,2,2,... */
    int point = 0;
    for (int i = 0; i < 12; i++) {
        rally(&rs, (i & 1) ? 1 : 0);
        point++;
        /* after the 1st point the other player serves two in a row */
        CHECK(rules_server(&rs) == expect[i]);
    }
    CHECK(point == 12);

    /* ends change after every six tiebreak points */
    rules_init(&rs, &best_of_three, 0);
    for (int i = 0; i < 6; i++) { win_game(&rs, 0); win_game(&rs, 1); }
    bool changed = false;
    for (int i = 0; i < 5; i++)
        changed |= (rally(&rs, i & 1) & RULES_EV_CHANGE_ENDS) != 0;
    CHECK(!changed);
    CHECK(rally(&rs, 1) & RULES_EV_CHANGE_ENDS);
}

static void test_server_rotation_and_ends(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);
    CHECK(rules_server(&rs) == 0);
    unsigned ev = win_game(&rs, 0);
    CHECK(rules_server(&rs) == 1);
    CHECK(ev & RULES_EV_CHANGE_ENDS);    /* change after the first game */
    ev = win_game(&rs, 1);
    CHECK(rules_server(&rs) == 0);
    CHECK(!(ev & RULES_EV_CHANGE_ENDS)); /* but not after the second */
    ev = win_game(&rs, 0);
    CHECK(ev & RULES_EV_CHANGE_ENDS);    /* third game */

    /* serve side flips with every point and returns to the first court */
    rules_init(&rs, &best_of_three, 0);
    CHECK(rules_serve_side(&rs) == 0);
    rally(&rs, 0);
    CHECK(rules_serve_side(&rs) == 1);
    rally(&rs, 1);
    CHECK(rules_serve_side(&rs) == 0);
}

static void test_serve_faults(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);
    int srv = rules_server(&rs);
    int rcv = srv ^ 1;

    /* first serve fault: replay as second serve, no point */
    unsigned ev = rules_end_point(&rs, RULES_END_SERVE, rcv);
    CHECK((ev & RULES_EV_FAULT) && !(ev & RULES_EV_POINT));
    CHECK(rs.second_serve && rs.p[rcv].points == 0);

    /* let on the second serve keeps it a second serve */
    ev = rules_end_point(&rs, RULES_END_LET, -1);
    CHECK((ev & RULES_EV_LET) && !(ev & RULES_EV_POINT));
    CHECK(rs.second_serve);

    /* second serve fault: double fault, point to the receiver */
    ev = rules_end_point(&rs, RULES_END_SERVE, rcv);
    CHECK((ev & RULES_EV_DOUBLE_FAULT) && (ev & RULES_EV_POINT));
    CHECK(rs.p[rcv].points == 1 && !rs.second_serve);

    /* an ace on a first serve scores and does not touch the serve number */
    ev = rules_end_point(&rs, RULES_END_SERVE, srv);
    CHECK((ev & RULES_EV_POINT) && !(ev & RULES_EV_FAULT));
    CHECK(rs.p[srv].points == 1 && !rs.second_serve);

    /* let on a first serve replays the first serve */
    ev = rules_end_point(&rs, RULES_END_LET, -1);
    CHECK(!rs.second_serve);

    /* single-serve option: the first fault already loses the point */
    rules_config single = best_of_three;
    single.single_serve = true;
    rules_init(&rs, &single, 0);
    ev = rules_end_point(&rs, RULES_END_SERVE, 1);
    CHECK((ev & RULES_EV_DOUBLE_FAULT) && rs.p[1].points == 1);
}

static void test_super_tiebreak_final_set(void)
{
    rules_config cfg = best_of_three;
    cfg.final_set_super_tb = true;
    rules_state rs;
    rules_init(&rs, &cfg, 0);

    for (int s = 0; s < 2; s++) {
        for (int g = 0; g < 6; g++) win_game(&rs, s);      /* 6-0 each set */
    }
    CHECK(rs.cur_set == 2 && rs.p[0].sets_won == 1 && rs.p[1].sets_won == 1);
    CHECK(rs.tiebreak && rs.super_tiebreak);
    CHECK(rs.point_target == RULES_SUPER_TB_TARGET);

    for (int i = 0; i < 9; i++) { rally(&rs, 0); rally(&rs, 1); }
    CHECK(!rs.match_over);               /* 9-9 */
    rally(&rs, 0);                       /* 10-9: needs two clear */
    CHECK(!rs.match_over);
    unsigned ev = rally(&rs, 0);         /* 11-9 */
    CHECK((ev & RULES_EV_MATCH) && rs.match_winner == 0);
}

static void test_tiebreak_cap(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);
    for (int i = 0; i < 6; i++) { win_game(&rs, 0); win_game(&rs, 1); }
    for (int i = 0; i < 98; i++) { rally(&rs, 0); rally(&rs, 1); }
    CHECK(rs.tiebreak && rs.cur_set == 0);
    rally(&rs, 0);                       /* 99-98: the cap ends it */
    CHECK(rs.cur_set == 1 && rs.p[0].sets_won == 1);
}

static void test_best_of_five_and_flags(void)
{
    rules_config cfg = best_of_three;
    cfg.num_sets = 5;
    rules_state rs;
    rules_init(&rs, &cfg, 0);

    for (int s = 0; s < 2; s++)
        for (int g = 0; g < 6; g++) win_game(&rs, 0);
    CHECK(!rs.match_over && rs.p[0].sets_won == 2);
    /* player 0 is a set up with sets_won == 2 == (5-1)/2: next set wins match */
    for (int g = 0; g < 5; g++) win_game(&rs, 0);
    CHECK(rules_set_point(&rs, 0) && rules_match_point(&rs, 0));
    CHECK(!rules_set_point(&rs, 1));
    for (int i = 0; i < 3; i++) rally(&rs, 0);
    CHECK(rules_point_wins_match(&rs, 0));
    CHECK(!rules_point_wins_match(&rs, 1));
    unsigned ev = rally(&rs, 0);
    CHECK((ev & RULES_EV_MATCH) && rs.p[0].sets_won == 3);
}

static void test_withdrawal_and_short_format(void)
{
    rules_state rs;
    rules_init(&rs, &best_of_three, 0);
    unsigned ev = rules_withdraw(&rs, 1);
    CHECK((ev & RULES_EV_MATCH) && rs.match_winner == 0);
    CHECK(rs.p[0].sets_won == 2 && rs.p[1].sets_won == 0);
    CHECK(rally(&rs, 1) == 0);           /* nothing scores after the match */

    rules_config one = best_of_three;
    one.short_format = true;
    rules_init(&rs, &one, 0);
    ev = rally(&rs, 1);                  /* a point is a game; one game is not a set */
    CHECK((ev & RULES_EV_GAME) && !rs.match_over);
    ev = rally(&rs, 1);                  /* two games clear ends the one-set match */
    CHECK((ev & RULES_EV_MATCH) && rs.match_winner == 1);
}

int main(void)
{
    test_game_scoring();
    test_deuce_advantage();
    test_set_and_tiebreak();
    test_tiebreak_serving_and_ends();
    test_server_rotation_and_ends();
    test_serve_faults();
    test_super_tiebreak_final_set();
    test_tiebreak_cap();
    test_best_of_five_and_flags();
    test_withdrawal_and_short_format();

    if (failures) {
        fprintf(stderr, "%d check(s) failed\n", failures);
        return 1;
    }
    puts("rules: all checks passed");
    return 0;
}
