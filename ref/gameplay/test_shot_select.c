/*
 * Tests for shot_select.c with synthetic data only (no game values).
 *
 *   cc -std=c11 -Wall -Wextra -Werror -o /tmp/test_shot_select \
 *      ref/gameplay/test_shot_select.c ref/gameplay/shot_select.c -lm && /tmp/test_shot_select
 *   /tmp/test_shot_select data/gameplay/shot_tree.tree   # also walks a real values file
 */
#include "shot_select.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

static int fails;
#define CHECK(c)                                                         \
    do {                                                                 \
        if (!(c)) {                                                      \
            printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #c);          \
            fails++;                                                     \
        }                                                                \
    } while (0)

/* A synthetic tree with the same shape rules as the shipped one (made-up ids
 * built from crc32 of descriptive names, made-up tier numbers). */
static void synth(char *buf, size_t n)
{
    uint32_t smash = ts4_crc32("TestSmash"), top_p = ts4_crc32("TestTopP"), top = ts4_crc32("TestTop"),
             drop = 0xc47dfdc1u, slice = ts4_crc32("TestSlice"), flat = ts4_crc32("TestFlat"),
             volley = ts4_crc32("TestVolley");
    snprintf(buf, n,
             "# synthetic\n"
             "node 0 %08x l%08x:5 n1\n"       /* IsSmash */
             "node 1 82747a4b n2 l%08x:6\n"   /* IsBaseLine */
             "node 2 f271f3c8 n3 n4\n"        /* IsTopSpin */
             "node 3 bc06cec7 l%08x:1 l%08x:0\n" /* IsPowerful */
             "node 4 fb043007 n5 l%08x:3\n"   /* IsSlice */
             "node 5 df97c57b l%08x:4 l%08x:2\n" /* IsRisk */
             "power_curve 0.0 2.0 0.0 1.0\n"
             "tier Finesse 0.0 0.25\n"
             "tier Medium 0.25 0.5\n"
             "tier Powerful 0.5 1.0\n",
             ts4_crc32("IsSmash"), smash, volley, top_p, top, flat, drop, slice);
}

int main(int argc, char **argv)
{
    CHECK(ts4_crc32("IsTopSpin") == 0xf271f3c8u);
    CHECK(ts4_crc32("DropShot") == TS4_ID_DROPSHOT);
    CHECK(ts4_crc32("IsBaseLine") == 0x82747a4bu);

    char text[2048];
    synth(text, sizeof text);
    Ts4ShotTree t;
    CHECK(ts4_shot_tree_parse(text, &t) == 0);
    CHECK(t.n_nodes == 6 && t.n_tiers == 3 && t.has_power_curve);

    /* bad files are rejected */
    Ts4ShotTree bad;
    CHECK(ts4_shot_tree_parse("node 0 1 n0 n0\n", &bad) != 0);
    CHECK(ts4_shot_tree_parse("node 1 1 l1:1 l2:2\n", &bad) != 0);
    CHECK(ts4_shot_tree_parse("bogus\n", &bad) != 0);

    /* input layer */
    CHECK(ts4_button_level(TS4_PAD_RT, 0x80, 0) == 0);
    CHECK(ts4_button_level(TS4_PAD_RT, 0x81, 0) == 1);
    CHECK(ts4_button_level(TS4_PAD_A, 1, 0) == 1);
    CHECK(ts4_button_level(TS4_PAD_A, 1, 1) == 0);

    uint32_t latched = 0;
    int released;
    uint8_t held[4] = {0, 1, 1, 0}; /* B and X: TopSpin wins */
    CHECK(ts4_latch_update(&latched, held, &released) == TS4_ID_TOPSPIN && !released);
    uint8_t held2[4] = {1, 0, 1, 0}; /* A pressed later does not steal the latch */
    CHECK(ts4_latch_update(&latched, held2, &released) == TS4_ID_TOPSPIN && released);

    /* power and tiers: frames / D through the curve, then the tier intervals */
    CHECK(fabsf(ts4_power(&t, 30, 60) - 0.25f) < 1e-6f);
    CHECK(ts4_power(&t, 600, 60) == 1.0f);
    CHECK(ts4_power(&t, -5, 60) == 0.0f);
    int tf[3];
    ts4_tier_flags(&t, 0.1f, tf);
    CHECK(tf[0] == 1 && tf[1] == 0 && tf[2] == 0);
    ts4_tier_flags(&t, 0.25f, tf); /* key boundary belongs to the upper key */
    CHECK(tf[0] == 0 && tf[1] == 1 && tf[2] == 0);
    ts4_tier_flags(&t, 1.0f, tf);
    CHECK(tf[0] == 0 && tf[1] == 0 && tf[2] == 1);

    /* request + tree */
    Ts4ShotContext base = {1}, volley = {0};
    Ts4RequestInput in;
    memset(&in, 0, sizeof in);
    in.stroke_id = TS4_ID_TOPSPIN;
    in.tier_powerful = 1;
    uint32_t sid;
    Ts4Request rq = ts4_build_request(&in, &sid);
    CHECK(sid == TS4_ID_TOPSPIN && rq.is_topspin && rq.is_powerful && !rq.is_slice);
    Ts4ShotChoice c;
    CHECK(ts4_shot_select(&t, &rq, &base, &c) == 0 && c.row == 1 && c.shot_id == 0);
    CHECK(c.path_len == 4 && c.path[3] == 3);

    in.tier_powerful = 0;
    rq = ts4_build_request(&in, &sid);
    CHECK(ts4_shot_select(&t, &rq, &base, &c) == 0 && c.row == 0);

    in.stroke_id = TS4_ID_SLICE;
    in.risk = 1;
    rq = ts4_build_request(&in, &sid);
    CHECK(ts4_shot_select(&t, &rq, &base, &c) == 0 && c.row == 4 && c.shot_id == TS4_ID_DROPSHOT);
    in.risk = 0;
    rq = ts4_build_request(&in, &sid);
    CHECK(ts4_shot_select(&t, &rq, &base, &c) == 0 && c.row == 2);

    in.stroke_id = TS4_ID_LOB; /* no IsLob node in this synthetic tree: falls through */
    rq = ts4_build_request(&in, &sid);
    CHECK(ts4_shot_select(&t, &rq, &base, &c) == 0 && c.row == 3);
    CHECK(ts4_shot_select(&t, &rq, &volley, &c) == 0 && c.row == 6);

    in.overhead = 1; /* overhead situation forces Smash whatever the button */
    rq = ts4_build_request(&in, &sid);
    CHECK(sid == TS4_ID_SMASH && rq.is_smash && !rq.is_lob);
    CHECK(ts4_shot_select(&t, &rq, &base, &c) == 0 && c.row == 5);

    /* aim */
    Ts4Aim a = ts4_aim_from_stick(0.0f, 1.0f, 0);
    CHECK(fabsf(a.depth - 1.0f) < 1e-6f && fabsf(a.angle - 1.5707964f) < 1e-5f);
    a = ts4_aim_from_stick(0.6f, 0.8f, 1);
    CHECK(fabsf(a.depth - 1.0f) < 1e-5f);
    a = ts4_aim_from_stick(0.3f, 0.0f, 0);
    CHECK(fabsf(a.depth - 0.3f) < 1e-6f && fabsf(fabsf(a.angle) - 3.14159265f) < 1e-5f);
    float p[2] = {0, 0}, tgt[2] = {100, 100}, near[2] = {90, 90}, far[2] = {0, 0};
    a = ts4_aim_auto(p, tgt, near);
    CHECK(a.depth == 0.0f);
    a = ts4_aim_auto(p, tgt, far);
    CHECK(a.depth == 1.0f && fabsf(a.angle + 0.7853982f) < 1e-5f);

    /* optional: walk a real values file for every Request combination */
    if (argc > 1) {
        Ts4ShotTree real;
        CHECK(ts4_shot_tree_load(argv[1], &real) == 0);
        int hits[64] = {0};
        for (unsigned m = 0; m < (1u << 13); ++m) {
            Ts4Request r;
            memset(&r, 0, sizeof r);
            uint8_t *b = (uint8_t *)&r;
            for (int k = 0; k < 12; ++k)
                b[k] = (uint8_t)((m >> k) & 1);
            Ts4ShotContext x = {(uint8_t)((m >> 12) & 1)};
            CHECK(ts4_shot_select(&real, &r, &x, &c) == 0);
            if (c.row >= 0 && c.row < 64)
                hits[c.row]++;
        }
        printf("rows reached:");
        for (int k = 0; k < 64; ++k)
            if (hits[k])
                printf(" %d", k);
        printf("\n");
    }

    printf(fails ? "%d failure(s)\n" : "all tests passed\n", fails);
    return fails != 0;
}
