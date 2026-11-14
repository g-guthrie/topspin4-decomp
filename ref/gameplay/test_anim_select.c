/* Self-test for anim_select.c on synthetic numbers only (no game data). */
#include "anim_select.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

static int fails;
#define CHECK(cond) do { if (!(cond)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #cond); ++fails; } } while (0)
static int near(float a, float b) { return fabsf(a - b) < 1e-3f; }

#define Q_SURFACE 22
#define Q_PROPERTIES 35
#define TRICK_SHOT 16

static AsClip make_swing(int swing_type, int timing)
{
    AsClip c;
    memset(&c, 0, sizeof c);
    c.q[AS_Q_CATEGORY] = 1u << 0;            /* Swing */
    c.q[AS_Q_SWING_TYPE] = 1u << swing_type;
    if (timing >= 0)
        c.q[AS_Q_TIMING] = 1u << timing;
    c.frame_count = 80;
    c.contact_phase = 0.4f;
    return c;
}

static void test_filters(void)
{
    AsClip fh = make_swing(1, 0), bh = make_swing(2, -1);
    fh.q[Q_SURFACE] = 1u << 0;               /* Clay */
    uint32_t keys[2] = {1u << 1, 0};         /* key0: SwingType mask FH; key1: surface value Clay */

    AsNode by_type = {AS_NODE_MATCH_KEY_MASK, AS_Q_SWING_TYPE, 0, 0, 0, 0, 0};
    AsNode clay = {AS_NODE_MATCH_KEY, Q_SURFACE, 0, 1, 0, 0, 0};
    AsNode clay_x = {AS_NODE_MATCH_KEY, Q_SURFACE, 0, 1, 1, 0, 0};
    CHECK(as_eval(&by_type, &fh, keys) && !as_eval(&by_type, &bh, keys));
    CHECK(as_eval(&clay, &fh, keys) && as_eval(&clay, &bh, keys));   /* bh unconstrained */
    CHECK(as_eval(&clay_x, &fh, keys) && !as_eval(&clay_x, &bh, keys));

    const AsNode *kids[] = {&by_type, &clay_x};
    AsNode all = {AS_NODE_ALL, 0, 0, 0, 0, kids, 2};
    AsNode any = {AS_NODE_ANY, 0, 0, 0, 0, kids, 2};
    const AsNode *nk[] = {&all};
    AsNode not_all = {AS_NODE_NOT, 0, 0, 0, 0, nk, 1};
    CHECK(as_eval(&all, &fh, keys) && !as_eval(&all, &bh, keys));
    CHECK(as_eval(&any, &fh, keys) && !as_eval(&any, &bh, keys));
    CHECK(!as_eval(&not_all, &fh, keys) && as_eval(&not_all, &bh, keys));

    AsNode eq = {AS_NODE_EQUALS, AS_Q_SWING_TYPE, 2, 0, 1, 0, 0};
    CHECK(!as_eval(&eq, &fh, keys) && as_eval(&eq, &bh, keys));

    AsSwingKeys k = {0, -1, -1, -1, -1, -1, 1};   /* Timing Good, FH */
    CHECK(as_swing_matches(&fh, &k) && !as_swing_matches(&bh, &k));
    k.swing_type = 2;
    CHECK(as_swing_matches(&bh, &k));             /* timing unset on clip = wildcard */
    k.timing = 2;                                 /* TooLate */
    k.swing_type = 1;
    CHECK(!as_swing_matches(&fh, &k));
    AsClip miss = fh;
    miss.q[AS_Q_CATEGORY] = 1u << 1;
    k.timing = -1;
    CHECK(!as_swing_matches(&miss, &k));

    CHECK(as_mirror_mode(&fh, 0, 1) == 0 && as_mirror_mode(&fh, 1, 1) == 1);
    fh.no_mirror = 1;
    CHECK(as_mirror_mode(&fh, 1, 1) == -1 && as_mirror_mode(&fh, 1, 0) == 0);
    CHECK(near(as_contact_frame(&bh), 32));
}

static void test_fit(void)
{
    AsFitParams p;
    memset(&p, 0, sizeof p);
    p.target = (AsVec3){100, 90, 50};
    p.ref = (AsVec3){0, 0, 0};
    p.scale = p.y_scale = 1;
    p.t_min = 0; p.t_max = 20;
    p.tol_x = p.tol_z = 60;

    AsFitCandidate c[3];
    memset(c, 0, sizeof c);
    c[0].root_at_contact = (AsVec3){90, 90, 50};  c[0].contact_frame = 10;   /* off by 10 */
    c[1].root_at_contact = (AsVec3){100, 80, 48}; c[1].contact_frame = 12;   /* off by (0,10,2) */
    c[2].root_at_contact = (AsVec3){100, 90, 50}; c[2].contact_frame = 25;   /* perfect but late */
    CHECK(near(as_fit_cost(&c[0], &p, 0), 100));
    CHECK(near(as_fit_cost(&c[1], &p, 0), 104));
    CHECK(as_fit_cost(&c[2], &p, 0) < 0);
    float best;
    CHECK(as_fit_best(c, 3, &p, &best) == 0 && near(best, 100));
    p.tol_x = 5;                                       /* c0 fails |e.x| < 5 */
    CHECK(as_fit_best(c, 3, &p, &best) == 1);
    p.tol_x = 60;

    /* Rotation: facing pi/2 turns local +z offset into +x. */
    AsFitCandidate r;
    memset(&r, 0, sizeof r);
    r.root_at_contact = (AsVec3){0, 90, 100};
    r.side_matches = 1;
    r.contact_frame = 5;
    p.target = (AsVec3){100, 90, 0};
    p.facing_yaw = 1.5707963f;
    AsVec3 out;
    float k = as_fit_cost(&r, &p, &out);
    CHECK(k >= 0 && k < 1e-2f && near(out.x, 100) && fabsf(out.z) < 1e-3f);
    /* Linked offset is added after rotation; ref shifts the target. */
    r.has_offset = 1;
    r.offset = (AsVec3){0, 0, 10};
    p.ref = (AsVec3){-10, 0, 0};          /* target - ref = 110 */
    CHECK(near(as_fit_cost(&r, &p, &out), 0) && near(out.x, 100));
}

static void test_specials(void)
{
    AsDiveCfg cfg;
    as_dive_defaults(&cfg);
    AsDiveInputs in = {-200, 1, 1, 1, 70, 30};
    CHECK(as_volley_spectacular(&in, &cfg));
    in.pos_x = -700;
    CHECK(!as_volley_spectacular(&in, &cfg));
    in.pos_x = 0; in.team_mode = 2;
    CHECK(!as_volley_spectacular(&in, &cfg));
    in.team_mode = 0; in.has_spectacular_skill = 0;
    CHECK(!as_volley_spectacular(&in, &cfg));
    in.has_spectacular_skill = 1; in.timing_a = 60;
    CHECK(!as_volley_spectacular(&in, &cfg));
    in.timing_a = 61; in.timing_b = 45;
    CHECK(!as_volley_spectacular(&in, &cfg));

    uint32_t props = (1u << AS_PROP_SPECTACULAR) | (1u << AS_PROP_SWING_REACH) | (1u << TRICK_SHOT);
    uint32_t rw = as_rewards_from_props(props, TRICK_SHOT);
    CHECK(rw == (AS_RW_SPECTACULAR | AS_RW_REACH | AS_RW_TRICK_SHOT));
    CHECK(as_rewards_from_props(1u << AS_PROP_WRONG_FOOT, TRICK_SHOT) == 0);
    CHECK(as_reward_edges(AS_RW_REACH, rw) == (AS_RW_SPECTACULAR | AS_RW_TRICK_SHOT));
    CHECK(as_reward_edges(rw, rw) == 0);
    CHECK(as_rushing_to_ball(500, 0.9f, 400, 0.8f) && !as_rushing_to_ball(300, 0.9f, 400, 0.8f));

    AsReachCfg rc = {50, 200, 100};
    CHECK(as_reach_allowed(&rc, 120, 150));
    CHECK(!as_reach_allowed(&rc, 30, 150) && !as_reach_allowed(&rc, 120, 80));
    (void)Q_PROPERTIES;
}

int main(void)
{
    test_filters();
    test_fit();
    test_specials();
    if (fails) {
        printf("%d failure(s)\n", fails);
        return 1;
    }
    printf("test_anim_select: ok\n");
    return 0;
}
