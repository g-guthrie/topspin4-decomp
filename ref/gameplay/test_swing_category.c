/* Self-test for swing_category.c on synthetic rows and inputs only (no game data). */
#include "swing_category.h"

#include <stdio.h>
#include <string.h>

static int fails;
#define CHECK(c) do { if (!(c)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #c); ++fails; } } while (0)

/* synthetic category ids */
enum { CAT_A = 1, CAT_B = 2, CAT_C = 3, CAT_ALT = 4 };

typedef struct {
    uint32_t available[4];   /* categories that have a clip */
    int n;
    uint32_t want_level;     /* only this preference level has the clip */
    int frames;              /* autoswing answer when > 0 */
    int calls;
} Fake;

static int fake_query(void *user, uint32_t category, uint32_t level, int autoswing, int frames)
{
    Fake *f = user;
    ++f->calls;
    (void)frames;
    for (int i = 0; i < f->n; ++i)
        if (f->available[i] == category && (f->want_level == 0 || level == f->want_level))
            return (autoswing && f->frames > 0) ? f->frames : 0;
    return -1;
}

static ScInputs base_inputs(void)
{
    ScInputs in;
    memset(&in, 0, sizeof in);
    in.is_human = 1;
    in.min_speed_left = in.min_speed_right = 1.0f;
    return in;
}

static void test_conditions(void)
{
    ScTuning t;
    sc_default_tuning(&t);
    ScInputs in = base_inputs();
    in.power = 0.5f;
    CHECK(sc_condition(SC_COND_FATALITY, &in, &t));
    in.sticky_rb = 1;
    CHECK(sc_condition(SC_COND_FATALITY, &in, &t));        /* RB but outside the net zone */
    in.in_net_zone = 1;
    CHECK(!sc_condition(SC_COND_FATALITY, &in, &t) && sc_condition(SC_COND_GO_TO_NET, &in, &t));
    in.sticky_rb = 0;
    in.power = 0.1f;                                        /* a tap (Finesse) is never a put-away */
    CHECK(!sc_condition(SC_COND_FATALITY, &in, &t));
    in.power = 0.9f;
    in.is_human = 0;
    in.ai_net_request = 1;
    CHECK(!sc_condition(SC_COND_FATALITY, &in, &t));

    in = base_inputs();
    in.min_speed_left = 5.0f;
    in.min_speed_right = 4.0f;                              /* the smaller line counts */
    CHECK(sc_condition(SC_COND_REACH_SLOW, &in, &t) && !sc_condition(SC_COND_REACH_FAST, &in, &t));
    in.manual_timing = 0.0f;
    CHECK(sc_condition(SC_COND_GOOD_REACH, &in, &t));
    in.manual_timing = 0.5f;                                /* late: outside (-0.3, 0.1) */
    CHECK(!sc_condition(SC_COND_GOOD_REACH, &in, &t));
    in.is_human = 0;                                        /* the AI ignores the window */
    CHECK(sc_condition(SC_COND_GOOD_REACH, &in, &t));
    in.min_speed_right = 4.6f;
    CHECK(sc_condition(SC_COND_BAD_REACH, &in, &t));
    in.manual_timing = 0.0f;
    CHECK(!sc_condition(SC_COND_BAD_REACH, &in, &t));

    in = base_inputs();
    in.timing_value = 0.2f;
    CHECK(sc_condition(SC_COND_BAD_TIMING, &in, &t));
    in.local_x = -500.0f;
    in.shot_id = SC_SHOT_TOPSPIN;
    CHECK(sc_condition(SC_COND_VOLLEY_FORWARD, &in, &t));
    in.team_mode_2 = 1;
    CHECK(!sc_condition(SC_COND_VOLLEY_FORWARD, &in, &t));
    in.volley_release = 0.6f;
    CHECK(sc_condition(SC_COND_GOOD_VOLLEY_RELEASE, &in, &t) &&
          !sc_condition(SC_COND_BAD_VOLLEY_RELEASE, &in, &t));
    in.is_baseline_fast_ball = 1;
    CHECK(sc_condition(SC_COND_IS_FAST_BALL, &in, &t));
    CHECK(sc_condition(SC_COND_NONE, &in, &t) && !sc_condition(0x12345678u, &in, &t));
}

static void test_mode_class(void)
{
    CHECK(sc_mode(0, 1, 1.0f) == 0);
    CHECK(sc_mode(1, 1, 0.0f) == 1 && sc_mode(1, 0, 0.6f) == 1 && sc_mode(1, 0, 0.4f) == 2);
    CHECK(sc_class(0, 1, 0, 0) == 5);
    CHECK(sc_class(1, 0, SC_SHOT_TOPSPIN, 0) == 4 && sc_class(1, 0, SC_SHOT_SLICE, 0) == 3);
    CHECK(sc_class(0, 0, SC_SHOT_DROP_SHOT, 0) == 2 && sc_class(0, 0, 0, 1) == 1 && sc_class(0, 0, 0, 0) == 0);
}

static void test_walk(void)
{
    ScTuning t;
    sc_default_tuning(&t);
    ScInputs in = base_inputs();
    const uint32_t levels[] = {8, 7, 6, 5, 4, 3};
    ScRow rows[] = {
        {CAT_A, 0, SC_COND_GO_TO_NET, 0, 0},     /* skipped: condition false */
        {CAT_B, 0, SC_COND_NONE, 0, 0},          /* condition true but no clip */
        {CAT_C, CAT_ALT, SC_COND_NONE, 0, 0},    /* no clip for C, the alternative has one */
        {CAT_A, 0, SC_COND_NONE, 0, 0},          /* never reached */
    };
    Fake f = {{CAT_ALT, CAT_A}, 2, 5, 0, 0};
    ScResult r = sc_walk(rows, 4, &in, &t, 0, 0, 0, 5, 8, fake_query, &f, levels, 6);
    CHECK(r.category == CAT_ALT && r.started && r.found && r.row == 2);

    /* nothing matches: the last row tried stays written and found is 0 */
    Fake none = {{0}, 0, 0, 0, 0};
    r = sc_walk(rows, 4, &in, &t, 0, 0, 0, 5, 8, fake_query, &none, levels, 6);
    CHECK(!r.found && !r.started && r.category == CAT_A && r.row == 3);
    CHECK(none.calls == 4 * 6);   /* B, C, ALT, A: every preference level each */

    /* autoswing: the clip is 6 frames away, within the limit 8 -> due, walk continues */
    Fake far = {{CAT_B}, 1, 0, 6, 0};
    r = sc_walk(rows, 2, &in, &t, 1, 0, 0, 5, 8, fake_query, &far, levels, 6);
    CHECK(r.autoswing_due && r.found && !r.started);
    /* an EasyAutoSwing row on a latched (button) request is queried normally */
    ScRow easy[] = {{CAT_B, 0, SC_COND_NONE, 0, 1}};
    r = sc_walk(easy, 1, &in, &t, 1, 1, 0, 5, 8, fake_query, &far, levels, 6);
    CHECK(r.started && !r.autoswing_due);
}

int main(void)
{
    test_conditions();
    test_mode_class();
    test_walk();
    if (fails)
        return 1;
    printf("swing_category ok\n");
    return 0;
}
