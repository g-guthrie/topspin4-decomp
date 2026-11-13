/* Self-test for the reference swing/stat logic.  No game data is used. */
#include "gp_swing.h"

#include <stdio.h>
#include <string.h>

static int failures;

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #cond);            \
            ++failures;                                                      \
        }                                                                    \
    } while (0)

static int near(float a, float b)
{
    float d = a - b;
    return d < 1e-5f && d > -1e-5f;
}

static void test_hash(void)
{
    CHECK(gp_crc32("Volley") == GP_ID_VOLLEY);
    CHECK(gp_crc32("Smash") == GP_ID_SMASH);
    CHECK(gp_crc32("Baseline") == GP_ID_BASELINE);
    CHECK(gp_crc32("Left") == GP_ID_LEFT);
    CHECK(gp_crc32("Good") == GP_ID_GOOD);
    CHECK(gp_crc32("Medium") == GP_ID_MEDIUM);
    CHECK(gp_crc32("Bad") == GP_ID_BAD);
    CHECK(gp_crc32("Serve") == 0xa6a1b2aeu);
    CHECK(gp_crc32("Forehand") == 0xe630e16bu);
    CHECK(gp_crc32("Stamina") == 0xf431f5e8u);
}

static void test_stats(void)
{
    GpPlayerStats s = {1, 2, 3, 4, 5, 6, 7, 8};
    CHECK(near(gp_stat_for_stroke(&s, GP_STROKE_RETURN, 1), 2));
    CHECK(near(gp_stat_for_stroke(&s, GP_STROKE_GROUND, 1), 3));
    CHECK(near(gp_stat_for_stroke(&s, GP_STROKE_GROUND, 0), 4));
    CHECK(near(gp_stat_for_stroke(&s, GP_STROKE_VOLLEY, 0), 5));
    CHECK(gp_stronger_side(&s, 0.5f) == -1);
    s.forehand = 4.2f;
    CHECK(gp_stronger_side(&s, 0.5f) == 0);
}

static void test_curve_graph(void)
{
    const GpCurveSeg segs[2] = {{0, 10, 1, 0.5f}, {10, 20, 6, -0.25f}};
    GpCurve curve = {segs, 2};
    CHECK(near(gp_curve_eval(&curve, -5), 1));       /* clamps to first y0 */
    CHECK(near(gp_curve_eval(&curve, 4), 3));
    CHECK(near(gp_curve_eval(&curve, 10), 6));
    CHECK(near(gp_curve_eval(&curve, 14), 5));
    CHECK(near(gp_curve_eval(&curve, 99), 3.5f));    /* clamps at segment end */

    /* regs: 0=in, 1=lo, 2=hi, 3=t, 4=lerped, 5=curve out, 6=sum */
    float regs[8] = {0};
    float in_var = 0.5f, out_curve = 0, out_sum = 0;
    GpNode nodes[4];
    memset(nodes, 0, sizeof nodes);
    nodes[0].kind = GP_NODE_CONST;   nodes[0].out = 1; nodes[0].literal = 10.0f;
    nodes[1].kind = GP_NODE_CONST;   nodes[1].out = 2; nodes[1].literal = 30.0f;
    nodes[2].kind = GP_NODE_LERP;    nodes[2].in[0] = 1; nodes[2].in[1] = 2;
    nodes[2].in[2] = 0; nodes[2].out = 4;
    nodes[3].kind = GP_NODE_CURVE;   nodes[3].in[0] = 4; nodes[3].out = 5;
    nodes[3].curve = &curve;
    GpBinding ins[1] = {{&in_var, 0}};
    GpBinding outs[2] = {{&out_curve, 5}, {&out_sum, 4}};
    GpGraph g = {regs, nodes, 4, ins, 1, outs, 2};
    gp_graph_eval(&g);
    CHECK(near(out_sum, 20.0f));       /* 10 + 0.5*(30-10) */
    CHECK(near(out_curve, 3.5f));      /* x=20 -> end of seg1: 6 - 0.25*10 */
}

static void test_window(void)
{
    GpWindowParams p;
    memset(&p, 0, sizeof p);
    p.volley_lateral_max = 2.0f;
    p.volley_max_bounce = 0;
    p.split_height_volley = 1.0f;
    p.split_height_other = 1.5f;
    p.smash_band_volley[0] = 1.8f; p.smash_band_volley[1] = 3.0f;
    p.smash_band_other[0] = 2.0f;  p.smash_band_other[1] = 3.0f;
    p.reach_radius = 1.0f;
    p.prep_frames_volley = 2;
    p.prep_frames_other = 5;
    p.unit_scale = 10.0f;
    p.speed_cap = 1000.0f;
    p.unreachable = 1e30f;
    p.far_default = 100.0f;
    p.min_time_frames = 1.0f;
    p.id_baseline = GP_ID_BASELINE;
    p.id_volley = GP_ID_VOLLEY;
    p.id_smash = GP_ID_SMASH;
    p.id_none = 0xdda489b8u;

    GpBallSample s[3] = {
        {1.0f, 0.5f, 0.0f, 20, 0},   /* low, volley zone  -> Volley   */
        {5.0f, 0.5f, 0.0f, 30, 1},   /* low, far lateral  -> Baseline */
        {0.0f, 2.5f, 0.0f, 40, 0},   /* high, in band     -> Smash    */
    };
    float dist[3] = {4.0f, 6.0f, 1.0f};
    GpWindow w;
    gp_window_build(&w, s, dist, 3, &p, 10, 0);
    CHECK(w.type_id[0] == GP_ID_VOLLEY);
    CHECK(w.type_id[1] == GP_ID_BASELINE);
    CHECK(w.type_id[2] == GP_ID_SMASH);
    CHECK(near(w.reach_speed[0], (4.0f - 1.0f) / (10.0f - 2.0f) * 10.0f));
    CHECK(near(w.reach_speed[1], (6.0f - 1.0f) / (20.0f - 5.0f) * 10.0f));
    CHECK(near(w.reach_speed[2], 0.0f));
    CHECK(w.first_valid == 0 && w.last_valid == 2);

    GpMoveMode mode = {1, 0, 5.0f, 5.0f};
    GpSel sel;
    gp_sel_extract_rows(&sel, &w, &mode, 1, GP_ID_VOLLEY, GP_ID_SMASH);
    /* speeds 3.75, 3.33 are reachable (< 5); the smash is excluded (smash_only=0) */
    CHECK(sel.valid && sel.row_count == 1);
    CHECK(sel.rows[0].first == 0 && sel.rows[0].last == 1);
    CHECK(near(sel.min_speed_all, 10.0f * 5.0f / 15.0f));
    CHECK(near(sel.min_speed_volley, 3.75f));
    {
        GpMoveMode smash_mode = {0, 1, 5.0f, 5.0f};
        GpSel s2;
        gp_sel_extract_rows(&s2, &w, &smash_mode, 1, GP_ID_VOLLEY, GP_ID_SMASH);
        CHECK(s2.row_count == 1 && s2.rows[0].first == 2 && s2.rows[0].last == 2);
        gp_sel_extract_rows(&s2, &w, &smash_mode, 0, GP_ID_VOLLEY, GP_ID_SMASH);
        CHECK(!s2.valid);
    }

    sel.score[0] = 0.4f; sel.score[1] = 0.9f; sel.score[2] = 0.2f;
    CHECK(gp_select_best(&sel, &w, 0, 0, -1.0f, GP_ID_VOLLEY) == 1);
    CHECK(gp_select_best(&sel, &w, 0, 1, -1.0f, GP_ID_VOLLEY) == 0); /* volley only */
    CHECK(gp_select_best(&sel, &w, 1, 0, -1.0f, GP_ID_VOLLEY) == 1); /* non-volley  */
    CHECK(gp_select_best(&sel, &w, 1, 1, -1.0f, GP_ID_VOLLEY) == 1);  /* both flags  */
    sel.score[0] = sel.score[1] = sel.score[2] = -1.0f;
    CHECK(gp_select_best(&sel, &w, 0, 0, -1.0f, GP_ID_VOLLEY) == -1);
}

static void test_clip(void)
{
    GpMarker m[2] = {{0x11111111u, 0.25f}, {0x22222222u, 0.5f}};
    GpClip c = {m, 2, 40.0f};
    CHECK(near(gp_clip_contact_frame(&c, 0x22222222u, 100.0f, 1.0f), 120.0f));
    CHECK(near(gp_clip_contact_frame(&c, 0x33333333u, 100.0f, 1.0f), -1.0f));
    GpFitParams fp = {110.0f, 130.0f, 1.0f, 2.0f, 0.5f, 0.25f};
    GpFitInput in = {120.0f, 121.0f, 0.5f, 0.2f, 0.4f};
    CHECK(near(gp_clip_fit_cost(&in, &fp), 1.0f + 1.0f + 0.1f + 0.1f));
    in.contact_frame = 140.0f;
    CHECK(gp_clip_fit_cost(&in, &fp) < 0.0f);
}

int main(void)
{
    test_hash();
    test_stats();
    test_curve_graph();
    test_window();
    test_clip();
    if (failures) {
        printf("%d failure(s)\n", failures);
        return 1;
    }
    printf("test_swing: all checks passed\n");
    return 0;
}
