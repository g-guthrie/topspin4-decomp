/* Self-test for player.c on synthetic numbers only (no game data). */
#include "player.h"

#include <math.h>
#include <stdio.h>

static int fails;
#define CHECK(cond) do { if (!(cond)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #cond); ++fails; } } while (0)
static int near(float a, float b) { return fabsf(a - b) < 1e-4f; }

static void test_curves(void)
{
    PlKey16 k[] = {{0, 10, 0, 1}, {10, 20, 1, 3}};
    PlCurve16 c = {k, 2};
    CHECK(near(pl_curve16(&c, -5), 0));
    CHECK(near(pl_curve16(&c, 5), 0.5f));
    CHECK(near(pl_curve16(&c, 15), 2));
    CHECK(near(pl_curve16(&c, 99), 3));

    PlKey16 a[] = {{0, 10, 0, 10}}, b[] = {{0, 10, 0, 20}};
    PlRow rows[] = {{{a, 1}, 100}, {{b, 1}, 200}};
    PlTable2D t = {rows, 2};
    CHECK(near(pl_table2d(&t, 50, 5), 5));     /* below first key: row 0 */
    CHECK(near(pl_table2d(&t, 150, 5), 7.5f)); /* halfway between 5 and 10 */
    CHECK(near(pl_table2d(&t, 300, 5), 10));   /* above last key: last row */

    PlKey20 s[] = {{30, 50, 0.0f, 0.0f, 0.2f}, {50, 80, 0.2f, 0.0f, 0.8f}};
    CHECK(near(pl_curve20(s, 2, 40, PL_CURVE_STEP), 0.0f));  /* step reading (option) */
    CHECK(near(pl_curve20(s, 2, 40, PL_CURVE_RAMP), 0.1f));    /* ramp reading (default) */
    CHECK(near(pl_curve20(s, 2, 10, PL_CURVE_RAMP_Y1), 0.0f));    /* below first key */
    CHECK(near(pl_curve20(s, 2, 200, PL_CURVE_RAMP_Y1), 0.8f));   /* flat after last x1 */
}

static void test_stats(void)
{
    float st[PL_STAT_COUNT] = {1, 2, 3, 4, 5, 6, 7, 8};
    CHECK(pl_stroke_skill(st, PL_STROKE_GROUND, 1) == 3);
    CHECK(pl_stroke_skill(st, PL_STROKE_GROUND, 0) == 4);
    CHECK(pl_stroke_skill(st, PL_STROKE_RETURN, 0) == 2);
    CHECK(pl_stroke_skill(st, PL_STROKE_VOLLEY, 0) == 5);
    PlKey20 k[] = {{0, 100, 0, 0.01f, 1}};
    PlStatCurve cur[PL_STAT_COUNT];
    for (int i = 0; i < PL_STAT_COUNT; ++i) { cur[i].keys = k; cur[i].count = 1; }
    float r[PL_STAT_COUNT] = {50, 60, 70, 80, 90, 100, 30, 40}, p[PL_STAT_COUNT];
    pl_profile_from_ratings(r, cur, PL_CURVE_RAMP, p);
    CHECK(near(p[0], 0.5f) && near(p[6], 0.3f));
    CHECK(pl_side_preference(80, 70, 1, 9, 0.5f) == 1);
    CHECK(pl_side_preference(80, 70, 9, 1, 0.5f) == 0);
    CHECK(pl_side_preference(70, 80, 5, 1, 0.5f) == -1);
    CHECK(pl_side_preference(70, 70, 5, 1, 0.5f) == 0);
}

static void test_reach(void)
{
    PlTypeCfg tc = {200, 220, 230, 280, 260, 280, 750};
    CHECK(pl_classify_sample(&tc, 100, 50, 0, 0, 10) == PL_UNREACHABLE);  /* |x| <= 150 */
    CHECK(pl_classify_sample(&tc, 500, 100, 0, 0, 10) == PL_VOLLEY_T);
    CHECK(pl_classify_sample(&tc, 1000, 100, 1, 0, 10) == PL_BASELINE);
    CHECK(pl_classify_sample(&tc, 500, 250, 0, 0, 10) == PL_SMASH);
    CHECK(pl_classify_sample(&tc, 500, 300, 0, 0, 10) == PL_UNREACHABLE);
    CHECK(pl_classify_sample(&tc, 500, 100, 0, 20, 10) == PL_BASELINE);   /* beyond lookahead */

    PlReachCfg rc = {10, 30, 100, 250, 10, 0, 15};
    /* 300 cm run, 60 ticks, 10 prep, 5 turn, 5 busy -> (300-10)/40*0.6 */
    CHECK(near(pl_reach_speed(&rc, PL_BASELINE, 0, 0, 300, 0, 300, 60, 5, 5), 290.0f / 40.0f * 0.6f));
    CHECK(pl_reach_speed(&rc, PL_BASELINE, 0, 0, 300, 0, 300, 15, 5, 5) == 100.0f);  /* no time */
    CHECK(pl_reach_speed(&rc, PL_BASELINE, 0, 0, 5, 0, 5, 60, 5, 5) == 0.0f);        /* in reach */
    CHECK(pl_reach_speed(&rc, PL_BASELINE, 0, 0, 5, 0, 5, 10, 5, 5) > 1e30f);        /* in reach, late */
    CHECK(pl_reach_speed(&rc, PL_VOLLEY_T, 0, 1, 50, 200, 0, 60, 0, 0) == 0.0f);    /* inside volley box */
    CHECK(pl_reach_speed(&rc, PL_VOLLEY_T, 0, 1, -200, 0, 0, 60, 0, 0) == 100.0f);  /* behind */
}

static void test_movement(void)
{
    /* validity 1 while slack <= 30 then ramps to 0 at 50, independent of distance */
    PlKey16 k[] = {{0, 30, 1, 1}, {30, 50, 1, 0}};
    PlRow r[] = {{{k, 2}, 400}, {{k, 2}, 1000}};
    PlModeCfg rush = {{r, 2}, 6, 400}, jj = {{r, 2}, 6, 2000}, jog = {{r, 2}, 6, 175};
    CHECK(pl_mode_valid(&rush, 600, 50, 10, 15));     /* slack 25 */
    CHECK(!pl_mode_valid(&rush, 600, 100, 10, 15));   /* slack 75 */
    CHECK(!pl_mode_valid(&rush, 300, 50, 10, 15));    /* under min distance */
    CHECK(pl_select_regime(&rush, &jj, &jog, 0, -1, 600, 50, 10, 15) == PL_MODE_RUSH);
    CHECK(pl_select_regime(&rush, &jj, &jog, -2, -1, 600, 50, 10, 15) == PL_MODE_JOG);  /* guard blocks rush */
    CHECK(pl_select_regime(&rush, &jj, &jog, 0, -1, 600, 200, 10, 15) == PL_MODE_DEFAULT);

    PlKey16 sk[] = {{0, 100, 0.1f, 0.1f}};
    PlRow sr[] = {{{sk, 1}, 0}};
    PlTable2D st = {sr, 1};
    PlJogRamp ramp = {1.0f, 0, 0};
    CHECK(near(pl_jog_ramp_tick(&ramp, 0, 10, &st, 500, 20), 1.0f));   /* init */
    CHECK(near(pl_jog_ramp_tick(&ramp, 1, 10, &st, 500, 20), 0.9f));
    CHECK(near(pl_jog_ramp_tick(&ramp, 2, 10, &st, 500, 20), 0.8f));
    CHECK(near(pl_jog_ramp_tick(&ramp, 10, 10, &st, 500, 20), 0.8f));  /* re-init tick */
}

static void test_swing_and_clip(void)
{
    CHECK(pl_racket_lateral(94, -79, 0, 1) == 94);
    CHECK(pl_racket_lateral(94, -79, 0, 0) == -79);
    CHECK(pl_racket_lateral(94, -79, 1, 1) == 79);
    CHECK(pl_racket_lateral(94, -79, 1, 0) == -94);
    float lo, hi, w0[2] = {0, 30}, w1[2] = {0, 20};
    pl_contact_window(140, 100, 0, w0, w1, &lo, &hi);
    CHECK(near(lo, 40) && near(hi, 20));

    PlLayer l = {10, 0, 100};
    CHECK(near(pl_time_warp(&l, 1.0f, 50), 0));      /* ratio 1: no shift */
    CHECK(near(pl_time_warp(&l, 1.5f, 50), 20));
    CHECK(near(pl_time_warp(&l, 0.5f, 50), 0));      /* clamped at base */
    CHECK(near(pl_anim_busy(&l, 2.0f, 40, 10), 20));
    CHECK(near(pl_anim_busy(&l, 1.0f, 40, 10), 0));
    CHECK(near(pl_rate_to_target(45, 15, 110, 100, 1, 0.9f), 30.0f / 11.0f));
    CHECK(near(pl_rate_to_target(45, 15, 90, 100, 2, 0.5f), 1.0f));
    CHECK(near(pl_contact_frame(0.25f, 120), 30));
}

static void test_misc(void)
{
    PlGrade a, b;
    pl_grades(0.2f, &a, &b); CHECK(a == PL_GRADE_BAD && b == PL_GRADE_BAD);
    pl_grades(0.5f, &a, &b); CHECK(a == PL_GRADE_GOOD && b == PL_GRADE_MEDIUM);
    pl_grades(0.7f, &a, &b); CHECK(a == PL_GRADE_GOOD && b == PL_GRADE_GOOD);
    CHECK(pl_crc32("Good") == 0xCCB6E1ACu && pl_crc32("Volley") == 0x71198650u);

    PlAiRecord r0[] = {{1, 4, {0}}, {2, 6, {0}}}, r1[] = {{1, 5, {0}}, {2, 7, {0}}};
    PlAiGroup g[] = {{100, r0, 2}, {200, r1, 2}};
    CHECK(pl_ai_lookup(g, 2, 200, 2)->skill_speed_limit == 7);
    CHECK(pl_ai_lookup(g, 2, 200, 9)->skill_speed_limit == 5);   /* level fallback: first */
    CHECK(pl_ai_lookup(g, 2, 999, 2)->skill_speed_limit == 6);   /* style fallback: group 0 */

    CHECK(near(pl_excitement_step(0.5f, 0.1f, 0.3f, 0.2f), 0.8f));
    CHECK(near(pl_excitement_step(0.9f, 0.3f, 0, 1), 1.0f));
}

int main(void)
{
    test_curves();
    test_stats();
    test_reach();
    test_movement();
    test_swing_and_clip();
    test_misc();
    if (fails) { printf("%d failures\n", fails); return 1; }
    printf("test_player: all passed\n");
    return 0;
}
