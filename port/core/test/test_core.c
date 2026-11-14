/*
 * ts4core self-test. Built and run by `make test` and tests/test_port_core.py (host cc, synthetic data only).
 *
 *   test_core BLOB                         run the suite against a synthetic blob (tools/ts4d.py synthetic)
 *   test_core --eval BLOB HASH BITS...     evaluate graph HASH (hex) on float bit patterns (hex), print output bits
 *   test_core --match BLOB SEED TICKS      AI vs AI, print one summary line (used for the wasm cross-check)
 *   test_core --trace BLOB ROW             probe + trace one template row, print tau, ticks and a position digest
 *
 * -std=c99 -Wall -Wextra -Werror -ffp-contract=off; the libm used for the reference comparisons is the host's.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "ts4core.h"

/* The shim redirects exp/log/fmaf to the software versions; the tests want the host libm as the oracle. */
#undef exp
#undef log
#undef fmaf
#undef sinf
#undef cosf
#undef atan2f
extern double ts4_exp(double);
extern double ts4_log(double);
extern float ts4_fmaf(float, float, float);
extern float ts4_sinf(float);
extern float ts4_cosf(float);
extern float ts4_atan2f(float, float);

static int failures, checks;
#define CHECK(cond)                                                                      \
    do {                                                                                 \
        checks++;                                                                        \
        if (!(cond)) {                                                                   \
            fprintf(stderr, "%s:%d: FAILED: %s\n", __FILE__, __LINE__, #cond);           \
            failures++;                                                                  \
        }                                                                                \
    } while (0)

static uint8_t *read_file(const char *path, uint32_t *size)
{
    FILE *f = fopen(path, "rb");
    uint8_t *buf;
    long n;
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (uint8_t *)malloc((size_t)n + 16);
    if (buf && fread(buf, 1, (size_t)n, f) != (size_t)n) { free(buf); buf = NULL; }
    fclose(f);
    *size = (uint32_t)n;
    return buf;
}

static Ts4Core *new_core(void)
{
    uint32_t sz = ts4_core_size();
    void *mem = malloc(sz + 16);
    Ts4Core *c;
    /* malloc is 16-byte aligned on every host we build for */
    c = ts4_core_init(mem, sz);
    return c;
}

static uint32_t fbits(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static float bitsf(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

static uint32_t rnd_state = 12345u;
static uint32_t rnd(void) { rnd_state = rnd_state * 1664525u + 1013904223u; return rnd_state; }
static float rndf(float lo, float hi) { return lo + (hi - lo) * ((float)(rnd() >> 8) / 16777216.0f); }

/* ------------------------------------------------------------------------------------------------ */
static void test_softmath(void)
{
    int i, bad_fma = 0, diff_exp = 0, diff_log = 0;
    double max_rel_exp = 0.0, max_rel_log = 0.0;
    /* fused multiply-add: exact against the hardware instruction on random and edge inputs */
    for (i = 0; i < 2000000; i++) {
        float a, b, c;
        uint32_t k = rnd() & 7u;
        a = rndf(-100.0f, 100.0f); b = rndf(-100.0f, 100.0f); c = rndf(-1e4f, 1e4f);
        if (k == 0) c = -a * b + rndf(-1e-3f, 1e-3f);          /* heavy cancellation */
        if (k == 1) { a = bitsf(rnd()); b = bitsf(rnd()); c = bitsf(rnd()); if (a != a || b != b || c != c) continue; }
        if (k == 2) { a = rndf(1e-20f, 1e-18f); b = rndf(1e-20f, 1e-18f); c = rndf(-1e-38f, 1e-38f); }   /* subnormals */
        {
            float x = ts4_fmaf(a, b, c), y = fmaf(a, b, c);
            if (fbits(x) != fbits(y) && !(x != x && y != y)) bad_fma++;
        }
    }
    CHECK(bad_fma == 0);
    /* exp / log: within 2e-15 relative of libm, and equal after rounding to float except at rounding ties */
    for (i = 0; i < 200000; i++) {
        double x = (double)rndf(-80.0f, 80.0f), a = exp(x), b = ts4_exp(x), r = fabs((a - b) / a);
        double y = (double)rndf(1e-6f, 1e6f), la = log(y), lb = ts4_log(y);
        double rl = la == 0.0 ? fabs(lb) : fabs((la - lb) / la);
        if (r > max_rel_exp) max_rel_exp = r;
        if (rl > max_rel_log && fabs(la) > 1e-3) max_rel_log = rl;
        if ((float)a != (float)b) diff_exp++;
        if ((float)la != (float)lb) diff_log++;
    }
    CHECK(max_rel_exp < 2e-15);
    CHECK(max_rel_log < 2e-15);
    CHECK(diff_exp <= 4 && diff_log <= 4);       /* float-rounding disagreements, expected ~0 in 200k */
    CHECK(ts4_exp(0.0) == 1.0 && ts4_log(1.0) == 0.0);
    CHECK(ts4_exp(1000.0) > 1e308 && ts4_exp(-1000.0) == 0.0);
    for (i = 0; i < 20000; i++) {
        float x = rndf(-50.0f, 50.0f), y = rndf(-5.0f, 5.0f), z = rndf(-5.0f, 5.0f);
        CHECK(fabsf(ts4_sinf(x) - sinf(x)) < 2e-6f);
        CHECK(fabsf(ts4_cosf(x) - cosf(x)) < 2e-6f);
        CHECK(fabsf(ts4_atan2f(y, z) - atan2f(y, z)) < 2e-6f);
        if (failures > 20) return;
    }
    printf("softmath: fma exact on 2e6 cases, exp/log max rel err %.2e / %.2e, float-rounded diffs %d/%d\n",
           max_rel_exp, max_rel_log, diff_exp, diff_log);
}

/* ------------------------------------------------------------------------------------------------ */
/* the wasm / JavaScript binding reads these structs by offset: sizes are part of the API contract */
static void test_layout(void)
{
    CHECK(sizeof(Ts4Snapshot) == 256 && ts4_snapshot_size() == 256);
    CHECK(sizeof(Ts4Event) == 32);
    CHECK(sizeof(Ts4MatchConfig) == 120);
    CHECK(sizeof(Ts4Input) == 12);
    CHECK(sizeof(Ts4ShotIn) == 60);
    CHECK(sizeof(Ts4ShotOut) == 52);
    CHECK(sizeof(Ts4BallView) == 52 && sizeof(Ts4PlayerView) == 48 && sizeof(Ts4ScoreView) == 88);
    CHECK(offsetof(Ts4Snapshot, ball) == 16 && offsetof(Ts4Snapshot, players) == 68 && offsetof(Ts4Snapshot, score) == 164);
    CHECK(offsetof(Ts4MatchConfig, players) == 40);
    CHECK(ts4_core_size() % 16 == 0);
}

static void test_registry_and_loader(const uint8_t *blob, uint32_t size)
{
    Ts4Core *c = new_core();
    float v = 0.0f;
    uint32_t i, m;
    Ts4Core *tiny;
    uint8_t bad[64];
    CHECK(c != NULL);
    CHECK(ts4_api_version() == TS4_API_VERSION);
    CHECK(ts4_crc32("IsTopSpin") == 0xF271F3C8u);
    CHECK(ts4_crc32("") == 0u);
    CHECK(ts4_tunable_count() > 40);
    for (i = 0; i < ts4_tunable_count(); i++) {
        CHECK(ts4_tunable_name(i) != NULL);
        CHECK(ts4_tunable_key(i) == ts4_crc32(ts4_tunable_name(i)));
    }
    /* before load everything required is missing */
    CHECK(ts4_missing_tunable_count(c) == ts4_tunable_count());
    CHECK(ts4_module_status(c, TS4_MOD_DATA) == TS4_STATUS_MISSING_DATA);
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    CHECK(ts4_missing_tunable_count(c) == 0);
    for (m = 0; m < TS4_MOD_COUNT; m++) CHECK(ts4_module_status(c, m) != TS4_STATUS_MISSING_DATA);
    CHECK(ts4_module_status(c, TS4_MOD_REACH) == TS4_STATUS_READY);
    CHECK(ts4_get_tunable(c, 0, &v) == TS4_OK);
    CHECK(ts4_template_count(c) == 9);
    CHECK(ts4_template_id(c, 0) == 0xA0000001u);
    CHECK(ts4_graph_count(c) == 6);
    /* override wins and survives a reload */
    CHECK(ts4_set_tunable(c, 0, 5.5f) == TS4_OK);
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    CHECK(ts4_get_tunable(c, 0, &v) == TS4_OK && v == 5.5f);

    /* rejects */
    CHECK(ts4_core_init(NULL, 0) == NULL);
    tiny = ts4_core_init(bad, sizeof bad);
    CHECK(tiny == NULL);
    CHECK(ts4_data_load(c, blob, 8) == TS4_ERR_BAD_BLOB);
    memset(bad, 0, sizeof bad);
    CHECK(ts4_data_load(c, bad, sizeof bad) == TS4_ERR_BAD_BLOB);
    {
        uint8_t *copy = (uint8_t *)malloc(size);
        uint32_t off, dirn;
        memcpy(copy, blob, size);
        dirn = (uint32_t)copy[8];
        CHECK(dirn >= 4);
        /* corrupt: section offset beyond the blob */
        off = 16 + 4;
        copy[off + 3] = 0x7F;
        CHECK(ts4_data_load(c, copy, size) == TS4_ERR_BAD_BLOB);
        free(copy);
    }
    CHECK(ts4_match_start(c, NULL) == TS4_ERR_ARG);
    free(c);
}

/* ------------------------------------------------------------------------------------------------ */
static void test_graphs(const uint8_t *blob, uint32_t size)
{
    Ts4Core *c = new_core();
    float in[8], out[8], prof[8];
    int32_t gi;
    int i;
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    /* DefaultAttributes: eight curves y = 0.01 * x */
    gi = ts4_graph_find(c, ts4_crc32("DefaultAttributes"));
    CHECK(gi >= 0);
    CHECK(ts4_graph_input_count(c, (uint32_t)gi) == 8 && ts4_graph_output_count(c, (uint32_t)gi) == 8);
    for (i = 0; i < 8; i++) in[i] = 10.0f * (float)(i + 1);
    CHECK(ts4_graph_eval(c, (uint32_t)gi, in, 8, prof, 8) == TS4_OK);
    for (i = 0; i < 8; i++) CHECK(prof[i] == ts4_fmaf(in[i], 0.01f, 0.0f));
    /* wrong arity / bad index */
    CHECK(ts4_graph_eval(c, (uint32_t)gi, in, 7, prof, 8) == TS4_ERR_ARG);
    CHECK(ts4_graph_eval(c, 99, in, 8, prof, 8) == TS4_ERR_ARG);
    /* LetProbability: one constant curve */
    gi = ts4_graph_find(c, ts4_crc32("LetProbability"));
    in[0] = 0.7f;
    CHECK(ts4_graph_eval(c, (uint32_t)gi, in, 1, out, 1) == TS4_OK);
    CHECK(out[0] == 0.02f);
    /* ShotDifficulty: sum of two curves (0.03 * speed) + (0.02 * dist) */
    gi = ts4_graph_find(c, ts4_crc32("ShotDifficulty"));
    in[0] = 5.0f; in[1] = 10.0f; in[2] = 0.0f;
    CHECK(ts4_graph_eval(c, (uint32_t)gi, in, 3, out, 1) == TS4_OK);
    CHECK(fabsf(out[0] - (0.3f + 0.1f)) < 1e-6f);
    in[0] = 500.0f; in[1] = 500.0f;     /* beyond the key: clamped at the segment end */
    CHECK(ts4_graph_eval(c, (uint32_t)gi, in, 3, out, 1) == TS4_OK);
    CHECK(fabsf(out[0] - (0.03f * 30.0f + 0.02f * 20.0f)) < 1e-5f);
    free(c);
}

/* ------------------------------------------------------------------------------------------------ */
static void fill_shot(Ts4ShotIn *in, uint32_t row)
{
    memset(in, 0, sizeof *in);
    in->struct_size = sizeof *in;
    in->row = row;
    in->from[0] = -1100.0f; in->from[1] = 110.0f; in->from[2] = 40.0f;
    in->to[0] = 900.0f; in->to[1] = 0.0f; in->to[2] = -150.0f;
    in->spin_blend = 0.5f;
    in->mode = 0xCA68AAECu;      /* In */
    in->planned = 1;
}

static void test_ball(const uint8_t *blob, uint32_t size)
{
    Ts4Core *c = new_core();
    Ts4ShotIn in;
    Ts4ShotOut o1, o2;
    float *tr1, *tr2;
    int32_t n1, n2, k;
    uint32_t row;
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    tr1 = (float *)malloc(sizeof(float) * 3 * 400);
    tr2 = (float *)malloc(sizeof(float) * 3 * 400);
    for (row = 0; row < 9; row++) {
        int32_t bad_nan = 0;
        fill_shot(&in, row);
        o1.struct_size = o2.struct_size = sizeof o1;
        CHECK(ts4_shot_probe(c, &in, &o1) == TS4_OK);
        CHECK(ts4_shot_probe(c, &in, &o2) == TS4_OK);
        CHECK(memcmp(&o1, &o2, sizeof o1) == 0);               /* determinism */
        CHECK(o1.tau > 0.05f && o1.tau < 5.2f && o1.bounce_tick == (uint32_t)(o1.tau * 60.0f + 0.5f));
        CHECK(o1.initial_kmh > 10.0f && o1.initial_kmh < 400.0f);
        n1 = ts4_shot_trace(c, &in, tr1, 400);
        n2 = ts4_shot_trace(c, &in, tr2, 400);
        CHECK(n1 == n2 && n1 > (int32_t)o1.bounce_tick);
        CHECK(memcmp(tr1, tr2, sizeof(float) * 3 * (size_t)n1) == 0);
        for (k = 0; k < n1; k++)
            if (tr1[3 * k] != tr1[3 * k] || tr1[3 * k + 1] != tr1[3 * k + 1]) bad_nan++;
        CHECK(bad_nan == 0);
        /* first bounce lands on the planned point (to within the float rounding of the frame conversion) */
        CHECK(fabsf(tr1[3 * o1.bounce_tick] - in.to[0]) < 0.5f && fabsf(tr1[3 * o1.bounce_tick + 2] - in.to[2]) < 0.5f);
        /* arc clears the net plane: find the crossing */
        if (row != 3) {
            int32_t j;
            for (j = 1; j < n1; j++) {
                if (tr1[3 * (j - 1)] < 0.0f && tr1[3 * j] >= 0.0f) { CHECK(tr1[3 * j + 1] > 91.4f); break; }
            }
        }
        /* after the bounce the ball keeps going toward +x and rises again */
        CHECK(tr1[3 * (n1 - 1)] > tr1[3 * o1.bounce_tick]);
        CHECK(o1.launch_vel[0] > 0.0f);
    }
    /* planned = 0: commanded initial speed with an aimed net-crossing height */
    fill_shot(&in, 0);
    in.planned = 0; in.speed_kmh = 100.0f; in.aim_height_m = 0.8f;
    CHECK(ts4_shot_probe(c, &in, &o1) == TS4_OK);
    CHECK(fabsf(o1.initial_kmh - 100.0f) < 5.0f || o1.net_unreachable || o1.raised == 0);
    /* a Net-mode shot hits the net and falls back on the own side */
    fill_shot(&in, 0);
    in.mode = 0xCAA7531Fu;
    in.to[0] = 900.0f;
    in.planned = 0; in.speed_kmh = 90.0f; in.aim_height_m = 0.5f;
    n1 = ts4_shot_trace(c, &in, tr1, 400);
    CHECK(n1 > 10);
    {
        int32_t j; float maxx = -1e9f;
        for (j = 0; j < n1; j++) if (tr1[3 * j] > maxx) maxx = tr1[3 * j];
        CHECK(maxx < 60.0f);        /* never gets far past the net plane (x = 0) */
    }
    /* the drag time constant is data: overriding it changes the launch speed (a4 = ball.a4) */
    fill_shot(&in, 0);
    CHECK(ts4_shot_probe(c, &in, &o1) == TS4_OK);
    {
        uint32_t id;
        for (id = 0; id < ts4_tunable_count() && strcmp(ts4_tunable_name(id), "ball.a4") != 0; id++) {}
        CHECK(ts4_set_tunable(c, id, 3.0f) == TS4_OK);
    }
    CHECK(ts4_shot_probe(c, &in, &o2) == TS4_OK);
    CHECK(o1.initial_kmh != o2.initial_kmh);
    /* argument checks */
    in.row = 99;
    CHECK(ts4_shot_probe(c, &in, &o1) == TS4_ERR_ARG);
    in.row = 0; in.struct_size = 4;
    CHECK(ts4_shot_probe(c, &in, &o1) == TS4_ERR_ARG);
    free(tr1); free(tr2); free(c);
}

/* ------------------------------------------------------------------------------------------------ */
typedef struct Summary {
    uint32_t hits, serves, bounces, nets, points, faults, doubles, lets, games, sets, matches, whiffs, ticks_to_end;
    uint32_t hash;
    int32_t sets_won[2], games0[2];
    int nan;
} Summary;

static void collect(Ts4Core *c, Summary *s)
{
    Ts4Event ev[64];
    uint32_t n, i;
    while ((n = ts4_poll_events(c, ev, 64)) > 0) {
        for (i = 0; i < n; i++) {
            switch (ev[i].type) {
            case TS4_EV_HIT: s->hits++; break;
            case TS4_EV_SERVE: s->serves++; break;
            case TS4_EV_BOUNCE: s->bounces++; break;
            case TS4_EV_NET: s->nets++; break;
            case TS4_EV_POINT_END: s->points++; break;
            case TS4_EV_FAULT: s->faults++; break;
            case TS4_EV_DOUBLE_FAULT: s->doubles++; break;
            case TS4_EV_LET: s->lets++; break;
            case TS4_EV_GAME: s->games++; break;
            case TS4_EV_SET: s->sets++; break;
            case TS4_EV_MATCH: s->matches++; break;
            case TS4_EV_WHIFF: s->whiffs++; break;
            default: break;
            }
        }
    }
}

static void default_cfg(Ts4MatchConfig *cfg, uint32_t seed)
{
    int i, k;
    memset(cfg, 0, sizeof *cfg);
    cfg->struct_size = sizeof *cfg;
    cfg->seed = seed;
    cfg->games_per_set = 6;
    cfg->num_sets = 1;
    cfg->first_server = 0;
    for (i = 0; i < 2; i++) {
        for (k = 0; k < TS4_STAT_COUNT; k++) cfg->players[i].stats[k] = 60.0f + 5.0f * (float)i + (float)k;
        cfg->players[i].human = 0;
    }
}

static int run_match(Ts4Core *c, uint32_t seed, uint32_t ticks, Summary *s)
{
    Ts4MatchConfig cfg;
    uint32_t t;
    int32_t r;
    const Ts4Snapshot *snap;
    memset(s, 0, sizeof *s);
    default_cfg(&cfg, seed);
    r = ts4_match_start(c, &cfg);
    if (r != TS4_OK) return r;
    for (t = 0; t < ticks; t++) {
        ts4_step(c);
        collect(c, s);
        snap = ts4_snapshot(c);
        if (snap->ball.pos[0] != snap->ball.pos[0] || snap->players[0].pos[0] != snap->players[0].pos[0] ||
            snap->players[1].pos[2] != snap->players[1].pos[2])
            s->nan = 1;
        if (snap->phase == TS4_PHASE_MATCH_OVER && !s->ticks_to_end) s->ticks_to_end = t;
    }
    snap = ts4_snapshot(c);
    s->hash = ts4_state_hash(c);
    s->sets_won[0] = snap->score.sets_won[0]; s->sets_won[1] = snap->score.sets_won[1];
    s->games0[0] = snap->score.games[0][0]; s->games0[1] = snap->score.games[1][0];
    return TS4_OK;
}

static void test_rules_glue(const uint8_t *blob, uint32_t size)
{
    Ts4Core *c = new_core();
    Ts4MatchConfig cfg;
    const Ts4Snapshot *s;
    unsigned ev;
    int i;
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    CHECK(ts4_snapshot(c)->struct_size == 0);          /* nothing before the match */
    default_cfg(&cfg, 1);
    CHECK(ts4_match_start(c, &cfg) == TS4_OK);
    s = ts4_snapshot(c);
    CHECK(ts4_set_input(c, 0, NULL) == TS4_ERR_ARG);
    CHECK(s->phase == TS4_PHASE_SERVE);
    CHECK(s->score.server == 0 && s->score.display[0] == 0);
    /* a 0-15-30-40 game for player 1 flips the server and counts games */
    for (i = 0; i < 4; i++) ev = ts4_debug_end_point(c, 0, 1);
    CHECK(ev & 2u);
    s = ts4_snapshot(c);
    ts4_step(c);
    s = ts4_snapshot(c);
    CHECK(s->score.games[1][0] == 1);
    CHECK(s->score.server == 1);
    /* a service fault sets the second serve, the second fault is a double fault that awards the point */
    ev = ts4_debug_end_point(c, 1, 0);       /* server is 1, winner 0 = fault */
    CHECK((ev & 0x20u) && !(ev & 0x40u));
    ev = ts4_debug_end_point(c, 1, 0);
    CHECK((ev & 0x20u) && (ev & 0x40u) && (ev & 1u));
    /* let: nothing awarded */
    ev = ts4_debug_end_point(c, 2, -1);
    CHECK((ev & 0x80u) && !(ev & 1u));
    free(c);
}

static void test_match(const uint8_t *blob, uint32_t size)
{
    Ts4Core *c = new_core(), *d = new_core();
    Summary a, b, e;
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    CHECK(ts4_data_load(d, blob, size) == TS4_OK);
    CHECK(run_match(c, 7, 6000, &a) == TS4_OK);
    CHECK(run_match(d, 7, 6000, &b) == TS4_OK);
    CHECK(a.hash == b.hash && a.hits == b.hits && a.points == b.points);     /* deterministic */
    CHECK(!a.nan);
    CHECK(a.serves >= 4);
    CHECK(a.hits > a.serves);                 /* rallies happen */
    CHECK(a.points >= 3);
    CHECK(a.bounces > a.hits / 2);
    CHECK(run_match(d, 8, 6000, &e) == TS4_OK);
    CHECK(e.hash != a.hash);
    printf("match seed 7 / 6000 ticks: serves %u hits %u bounces %u nets %u points %u faults %u double %u lets %u whiffs %u games %u hash %08x\n",
           a.serves, a.hits, a.bounces, a.nets, a.points, a.faults, a.doubles, a.lets, a.whiffs, a.games, a.hash);
    /* a whole one-set match terminates */
    CHECK(run_match(c, 3, 60000, &a) == TS4_OK);
    printf("match seed 3 / 60000 ticks: points %u games %u sets %u matches %u over at tick %u score %d-%d (games %d-%d)\n",
           a.points, a.games, a.sets, a.matches, a.ticks_to_end, a.sets_won[0], a.sets_won[1], a.games0[0], a.games0[1]);
    CHECK(a.matches == 1 && a.sets == 1 && a.ticks_to_end > 0);
    CHECK(a.sets_won[0] + a.sets_won[1] == 1);
    /* the ball stays inside a sane volume: re-run and check the snapshot every tick */
    {
        Ts4MatchConfig cfg;
        uint32_t t;
        float maxx = 0.0f, maxy = 0.0f;
        default_cfg(&cfg, 11);
        CHECK(ts4_match_start(c, &cfg) == TS4_OK);
        for (t = 0; t < 5000; t++) {
            const Ts4Snapshot *s;
            ts4_step(c);
            s = ts4_snapshot(c);
            if (s->ball.live) {
                if (fabsf(s->ball.pos[0]) > maxx) maxx = fabsf(s->ball.pos[0]);
                if (s->ball.pos[1] > maxy) maxy = s->ball.pos[1];
                CHECK(s->ball.pos[1] > -10.0f);
            }
        }
        CHECK(maxx < 3000.0f && maxy < 2000.0f);
    }
    free(c); free(d);
}

static void test_human(const uint8_t *blob, uint32_t size)
{
    Ts4Core *c = new_core();
    Ts4MatchConfig cfg;
    Ts4Input in;
    Summary s;
    uint32_t t;
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    default_cfg(&cfg, 5);
    cfg.players[0].human = 1;
    cfg.first_server = 0;
    CHECK(ts4_match_start(c, &cfg) == TS4_OK);
    memset(&s, 0, sizeof s);
    memset(&in, 0, sizeof in);
    CHECK(ts4_set_input(c, 0, &in) == TS4_OK);
    for (t = 0; t < 30; t++) ts4_step(c);
    CHECK(ts4_snapshot(c)->phase == TS4_PHASE_SERVE);       /* a human server waits for the button */
    in.buttons = TS4_BTN_FLAT;
    for (t = 0; t < 30; t++) { ts4_set_input(c, 0, &in); ts4_step(c); }   /* charge */
    in.buttons = 0;
    ts4_set_input(c, 0, &in);
    ts4_step(c);
    collect(c, &s);
    CHECK(s.serves == 1 && s.hits == 1);
    CHECK(ts4_snapshot(c)->phase == TS4_PHASE_RALLY && ts4_snapshot(c)->ball.live == 1);
    CHECK(ts4_snapshot(c)->ball.vel[0] > 1000.0f);          /* fast serve toward +x */
    /* the stick moves the player: forward = toward the net for player 0 on the x < 0 half */
    {
        float x0 = ts4_snapshot(c)->players[0].pos[0];
        in.stick_x = 1.0f; in.buttons = TS4_BTN_SPRINT;
        for (t = 0; t < 30; t++) { ts4_set_input(c, 0, &in); ts4_step(c); }
        CHECK(ts4_snapshot(c)->players[0].pos[0] > x0 + 100.0f);
        CHECK(ts4_snapshot(c)->players[0].pos[0] < 0.0f);          /* never across the net */
        CHECK(ts4_snapshot(c)->players[0].vel[0] > 0.0f);
    }
    free(c);
}

/* A scripted human receiver: stands on its baseline, lines up with where the ball will arrive (from the snapshot
 * velocity), holds a shot button and releases it so that contact (swing.contact_delay ticks later) happens as the ball
 * passes. Exercises the human swing path (release -> contact search on the prediction -> launch) end to end. */
static void test_human_return(const uint8_t *blob, uint32_t size)
{
    Ts4Core *c = new_core();
    Ts4MatchConfig cfg;
    Ts4Input in;
    uint32_t t, hits0 = 0, hits1 = 0, whiffs0 = 0, hold = 0;
    CHECK(ts4_data_load(c, blob, size) == TS4_OK);
    default_cfg(&cfg, 21);
    cfg.players[0].human = 1;
    cfg.first_server = 1;                         /* the AI serves, the human returns */
    CHECK(ts4_match_start(c, &cfg) == TS4_OK);
    for (t = 0; t < 12000; t++) {
        const Ts4Snapshot *sn = ts4_snapshot(c);
        Ts4Event ev[32];
        uint32_t n, k;
        memset(&in, 0, sizeof in);
        if (sn->ball.live && sn->ball.last_hitter == 1 && sn->ball.pos[0] < -300.0f && sn->ball.vel[0] < -100.0f) {
            float vx = sn->ball.vel[0] / 60.0f;                       /* cm per tick */
            float ticks = (sn->players[0].pos[0] - sn->ball.pos[0]) / vx;   /* until the ball is at the player's x */
            float zt = sn->ball.pos[2] + sn->ball.vel[2] / 60.0f * ticks;
            float dz = zt - sn->players[0].pos[2];
            in.stick_x = 0.0f;
            in.stick_z = dz > 5.0f ? 1.0f : (dz < -5.0f ? -1.0f : 0.0f);   /* player 0: +z is the right hand side */
            if (sn->ball.bounce_count >= 1 && ticks > 0.0f && ticks <= 24.0f) {
                if (hold < 8 || ticks > 19.0f) { in.buttons |= TS4_BTN_TOPSPIN; hold++; }     /* release at ~18 ticks */
            }
        } else hold = 0;
        ts4_set_input(c, 0, &in);
        ts4_step(c);
        while ((n = ts4_poll_events(c, ev, 32)) > 0)
            for (k = 0; k < n; k++) {
                if (ev[k].type == TS4_EV_HIT) { if (ev[k].a == 0) hits0++; else hits1++; }
                if (ev[k].type == TS4_EV_WHIFF && ev[k].a == 0) whiffs0++;
            }
    }
    printf("human receiver bot: human hits %u whiffs %u, AI hits %u\n", hits0, whiffs0, hits1);
    CHECK(hits0 >= 1);
    CHECK(hits1 > hits0);
    free(c);
}

static void test_degraded_and_missing(const char *path_nograph, const char *path_notpl)
{
    uint32_t size;
    uint8_t *blob;
    Ts4Core *c = new_core();
    Summary s;
    if (path_nograph) {
        blob = read_file(path_nograph, &size);
        CHECK(blob != NULL);
        CHECK(ts4_data_load(c, blob, size) == TS4_OK);
        CHECK(ts4_module_status(c, TS4_MOD_GRAPHS) == TS4_STATUS_DEGRADED);
        CHECK(ts4_module_status(c, TS4_MOD_REACH) == TS4_STATUS_DEGRADED);
        CHECK(ts4_graph_count(c) == 0);
        CHECK(run_match(c, 2, 4000, &s) == TS4_OK);          /* runs with fallbacks */
        CHECK(s.hits > 2 && !s.nan);
        free(blob);
    }
    if (path_notpl) {
        free(c);
        c = new_core();
        blob = read_file(path_notpl, &size);
        CHECK(blob != NULL);
        CHECK(ts4_data_load(c, blob, size) == TS4_OK);
        CHECK(ts4_module_status(c, TS4_MOD_TEMPLATES) == TS4_STATUS_MISSING_DATA);
        CHECK(ts4_module_status(c, TS4_MOD_BALL) == TS4_STATUS_MISSING_DATA);
        CHECK(run_match(c, 2, 10, &s) == TS4_ERR_MISSING_DATA);   /* refuses, never invents data */
        {
            Ts4ShotIn in;
            Ts4ShotOut o;
            fill_shot(&in, 0);
            o.struct_size = sizeof o;
            CHECK(ts4_shot_probe(c, &in, &o) == TS4_ERR_MISSING_DATA);
        }
        free(blob);
    }
    free(c);
}

/* ------------------------------------------------------------------------------------------------ */
static int cmd_eval(int argc, char **argv)
{
    uint32_t size, i;
    uint8_t *blob;
    Ts4Core *c = new_core();
    int32_t gi;
    float in[64], out[64];
    uint32_t nin, nout;
    if (argc < 4) return 2;
    blob = read_file(argv[2], &size);
    if (!blob || ts4_data_load(c, blob, size) != TS4_OK) { fprintf(stderr, "load failed\n"); return 2; }
    gi = ts4_graph_find(c, (uint32_t)strtoul(argv[3], NULL, 16));
    if (gi < 0) { fprintf(stderr, "graph not found\n"); return 2; }
    nin = ts4_graph_input_count(c, (uint32_t)gi);
    nout = ts4_graph_output_count(c, (uint32_t)gi);
    if ((uint32_t)argc - 4 != nin || nin > 64 || nout > 64) { fprintf(stderr, "need %u inputs\n", nin); return 2; }
    for (i = 0; i < nin; i++) in[i] = bitsf((uint32_t)strtoul(argv[4 + i], NULL, 16));
    if (ts4_graph_eval(c, (uint32_t)gi, in, nin, out, nout) != TS4_OK) return 2;
    for (i = 0; i < nout; i++) printf("%08x%s", fbits(out[i]), i + 1 < nout ? " " : "\n");
    return 0;
}

/* --eval-stdin BLOB: lines "HASH bits bits ..." -> one line of output bits each (batch form of --eval) */
static int cmd_eval_stdin(int argc, char **argv)
{
    uint32_t size, i;
    uint8_t *blob;
    Ts4Core *c = new_core();
    char line[4096];
    if (argc < 3) return 2;
    blob = read_file(argv[2], &size);
    if (!blob || ts4_data_load(c, blob, size) != TS4_OK) { fprintf(stderr, "load failed\n"); return 2; }
    while (fgets(line, sizeof line, stdin)) {
        char *tok = strtok(line, " \n");
        float in[64], out[64];
        uint32_t nin = 0, nout;
        int32_t gi;
        if (!tok) continue;
        gi = ts4_graph_find(c, (uint32_t)strtoul(tok, NULL, 16));
        if (gi < 0) { printf("ERR\n"); continue; }
        while ((tok = strtok(NULL, " \n")) && nin < 64) in[nin++] = bitsf((uint32_t)strtoul(tok, NULL, 16));
        nout = ts4_graph_output_count(c, (uint32_t)gi);
        if (ts4_graph_eval(c, (uint32_t)gi, in, nin, out, nout) != TS4_OK) { printf("ERR\n"); continue; }
        for (i = 0; i < nout; i++) printf("%08x%s", fbits(out[i]), i + 1 < nout ? " " : "\n");
    }
    return 0;
}

static int cmd_match(int argc, char **argv)
{
    uint32_t size;
    uint8_t *blob;
    Ts4Core *c = new_core();
    Summary s;
    if (argc < 5) return 2;
    blob = read_file(argv[2], &size);
    if (!blob || ts4_data_load(c, blob, size) != TS4_OK) { fprintf(stderr, "load failed\n"); return 2; }
    if (run_match(c, (uint32_t)strtoul(argv[3], NULL, 0), (uint32_t)strtoul(argv[4], NULL, 0), &s) != TS4_OK) return 2;
    printf("hash %08x serves %u hits %u bounces %u points %u games %u\n", s.hash, s.serves, s.hits, s.bounces, s.points, s.games);
    return 0;
}

static int cmd_trace(int argc, char **argv)
{
    uint32_t size, row;
    uint8_t *blob;
    Ts4Core *c = new_core();
    Ts4ShotIn in;
    Ts4ShotOut o;
    float tr[3 * 400];
    int32_t n, k;
    uint32_t h = 2166136261u;
    if (argc < 4) return 2;
    blob = read_file(argv[2], &size);
    if (!blob || ts4_data_load(c, blob, size) != TS4_OK) return 2;
    row = (uint32_t)strtoul(argv[3], NULL, 0);
    fill_shot(&in, row);
    o.struct_size = sizeof o;
    if (ts4_shot_probe(c, &in, &o) != TS4_OK) return 2;
    n = ts4_shot_trace(c, &in, tr, 400);
    for (k = 0; k < 3 * n; k++) { uint32_t u = fbits(tr[k]); h = (h ^ (u & 0xFF)) * 16777619u; h = (h ^ (u >> 8 & 0xFF)) * 16777619u; h = (h ^ (u >> 16 & 0xFF)) * 16777619u; h = (h ^ (u >> 24)) * 16777619u; }
    printf("tau %08x ticks %d kmh %08x digest %08x\n", fbits(o.tau), n, fbits(o.initial_kmh), h);
    return 0;
}

int main(int argc, char **argv)
{
    uint32_t size;
    uint8_t *blob;
    if (argc >= 2 && strcmp(argv[1], "--eval") == 0) return cmd_eval(argc, argv);
    if (argc >= 2 && strcmp(argv[1], "--eval-stdin") == 0) return cmd_eval_stdin(argc, argv);
    if (argc >= 2 && strcmp(argv[1], "--match") == 0) return cmd_match(argc, argv);
    if (argc >= 2 && strcmp(argv[1], "--trace") == 0) return cmd_trace(argc, argv);
    if (argc < 2) { fprintf(stderr, "usage: %s BLOB [NOGRAPHS_BLOB NOTPL_BLOB]\n", argv[0]); return 2; }
    blob = read_file(argv[1], &size);
    if (!blob) { fprintf(stderr, "cannot read %s\n", argv[1]); return 2; }
    test_layout();
    test_softmath();
    test_registry_and_loader(blob, size);
    test_graphs(blob, size);
    test_ball(blob, size);
    test_rules_glue(blob, size);
    test_match(blob, size);
    test_human(blob, size);
    test_human_return(blob, size);
    test_degraded_and_missing(argc > 2 ? argv[2] : NULL, argc > 3 ? argv[3] : NULL);
    printf("%d checks, %d failures\n", checks, failures);
    free(blob);
    return failures ? 1 : 0;
}
