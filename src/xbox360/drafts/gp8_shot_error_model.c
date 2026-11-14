/*
 * GP8 draft: Top Spin 4 (Xbox 360, Swing_DLL.xex) shot-error inputs and the In/Out/Net/Let decision.
 * Module sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44, all addresses are xex VAs.
 * Evidence and open items: work/gameplay-notes/gp8.md ("Shot error inputs").
 *
 * STATUS: DRAFT, not part of the matching build.  Host check:
 *   cc -std=c11 -Wall -Wextra -Werror -fsyntax-only src/xbox360/drafts/gp8_shot_error_model.c
 *
 * What is code and what is data
 *   code : the dice rolls, the decision table (shot_error_decide), the court-tolerance rules, the grade -> factor
 *          lookup, the ShotDifficulty analyser input preparation, the per-shot reset of S+0x750/0x754.
 *   data : the analyser graphs (LetProbability and friends) and their input/output bindings, the PlayerState
 *          array element contents, the five-level grade tables, every constant of the pool g_ts4_script_constants
 *          that is read from .rdata (those are readable from the image and are quoted below).
 * Float fields S+0x718 / 0x564 / 0x71C / 0x720 and the flags S+0x56D / 0x56E / 0x572 have NO literal store anywhere
 * in .text (exhaustive scan), they are filled by the data path (analyser output bindings, XData array element).
 */
#include <stdint.h>
#include <stddef.h>

/* ------------------------------------------------------------------ names (zlib.crc32 of ASCII) */
enum Gp8Hash {
    GP8_IN = 0xCA68AAECu,        /* "In" */
    GP8_OUT = 0x81A72B79u,       /* "Out" */
    GP8_NET = 0xCAA7531Fu,       /* "Net" */
    GP8_LET = 0xC9238771u,       /* "Let" */
    GP8_OUT_FAR = 0x2C59FAEAu,   /* "OutFar" (second out-region class of fn_88662C08) */
    GP8_NO_ERROR = 0x280AE84Du,  /* unclassified / no error (name not found) */
    GP8_GRADE_VERY_BAD = 0x555267AAu,   /* "VeryBad"  */
    GP8_GRADE_BAD = 0xBA667F1Bu,        /* "Bad"      */
    GP8_GRADE_NORMAL = 0x26296DD2u,     /* "Normal"   */
    GP8_GRADE_GOOD = 0xCCB6E1ACu,       /* "Good"     */
    GP8_GRADE_VERY_GOOD = 0x703F56AEu,  /* "VeryGood" */
    GP8_GRADE_MEDIUM = 0xC1DF4081u,     /* "Medium": hit-quality grade only, not in the five-level tables */
    GP8_MATCH_STATE_POINT_END = 0x029EAAF4u
};

/* ------------------------------------------------------------------ PlayerState view (offsets from the code) */
typedef struct Gp8Vec4 { float x, y, z, w; } Gp8Vec4;

typedef struct Gp8PlayerStateView {
    /* only the fields of the error model; the real element is 0x1070 bytes, XData type hash 0x502FE79D,
       an array inside the DebugConfig/tuning root object (+0xE80, self-relative offset), index = player slot. */
    float error_added;        /* +0x564 additive modifier to the error probability (no literal store in code) */
    uint8_t force_error;      /* +0x56D forces "an error happens" */
    uint8_t force_net_error;  /* +0x56E forces "the error is a net error" (and an error) */
    uint8_t force_let;        /* +0x572 forces the Let outcome */
    float error_prob;         /* +0x718 base error probability (also averaged into match stats by fn_886AE528) */
    float let_prob;           /* +0x71C Let chance; output of analyser "LetProbability" (planner+0x1C), evaluated
                                 immediately before it is compared (see decide) */
    float net_share;          /* +0x720 share of errors that are Net errors (rest are Out) */
    float net_aim_cm;         /* +0x750 net-plane aim height for a Net outcome (cm), reset per shot from cfg+0x134 */
    float let_aim_cm;         /* +0x754 net-plane aim height for a Let outcome (cm), reset per shot from cfg+0x138 */
} Gp8PlayerStateView;

/* ------------------------------------------------------------------ RNG (fn_8861E598, rng state at world->rng+0xB4) */
typedef struct Gp8Rng { uint32_t s1, s2; } Gp8Rng;   /* +4 / +8 of the 0xB4 block */

/* fn_8861E598(rng, lo, hi): one xorshift-like + LCG draw, result lo + u * (hi - lo), u in [0,1] (clamped). */
static float gp8_rng_range(Gp8Rng *r, float lo, float hi)
{
    uint32_t t = (r->s1 >> 15) ^ r->s1;
    uint32_t s1n = (t << 17) ^ t;
    uint32_t s2n = r->s2 * 0x10DCDu;
    float u;
    r->s1 = s1n;
    r->s2 = s2n;
    u = (float)(uint32_t)(s2n ^ s1n) * 2.3283064365386963e-10f; /* pool+0xDC = 2^-32 */
    if (u > 1.0f) u = 1.0f;
    return lo + u * (hi - lo);   /* fused multiply-add in the original */
}

/* ------------------------------------------------------------------ fn_88671B10 (final combine only) */
/*
 * fn_88671B10(shot_rec, PC, &b50, &b51).  Geometry (decoded only partly, marked ?): from the shot origin
 * (shot_rec vec, brought into court space by ts4_if_get_8865E730), the court bounds of fn_8866E318 and the player
 * state floats S+0x7DC / 0x7E0 (lengths) and S+0x44C / 0x450 (angles in degrees, scaled by pool+0x184 = pi/180)
 * it builds five end points (sin/cos fans via fn_8817B3F8/B500) and two sets of four distance tests
 * against max(S.7E0, S.7DC) and S.7E0.  The final result is exact:
 */
static void gp8_error_reach_flags(int match_point_end, int all_five_points_inside, int set2_all, int set1_any,
                                  uint8_t *b50, uint8_t *b51)
{
    if (match_point_end) { *b50 = 1; *b51 = 1; return; }          /* state 0x029EAAF4: both open */
    if (all_five_points_inside) { *b51 = 0; *b50 = 1; return; }   /* error can never leave the court */
    if (set2_all) { *b50 = 1; *b51 = 1; return; }
    if (!set1_any) { *b50 = 1; *b51 = 1; return; }
    *b50 = 0;                                                      /* some end points outside: shot is forced Out */
    *b51 = 1;
}

/* ------------------------------------------------------------------ fn_886807C0 */
typedef struct Gp8DecideIn {
    float prob_error_point_end;   /* DebugConfig+0x218, used for AI at point end (PC+0x10 == 0) */
    int ai_point_end_override;    /* (PC+0x10 == 0) && match state == POINT_END */
    int net_let_enabled;          /* DebugConfig+0x784 && !match+0x329 && match+0x328 (meaning of the match bytes unknown) */
    float tx, tz;                 /* aimed target (cm); x > 0 = opponent half */
    float xmax, zlo, zhi;         /* fn_8866E318 bounds in cm, already widened by 2 * ball radius */
    uint8_t b50, b51;             /* from gp8_error_reach_flags */
    float roll3;                  /* drawn AFTER the LetProbability analyser has run (it refreshes S.let_prob) */
} Gp8DecideIn;

/* Returns the outcome hash GP8_IN / GP8_OUT / GP8_NET / GP8_LET. `rolls` supplies roll1/roll2 (before the analyser). */
static uint32_t gp8_shot_error_decide(const Gp8PlayerStateView *s, const Gp8DecideIn *in, float roll1, float roll2)
{
    float p = in->ai_point_end_override ? in->prob_error_point_end : s->error_prob + s->error_added;
    int G, C, A, B, outside, F1, F2;
    float ax;
    if (p < 0.0f) p = 0.0f;           /* fsel clamps */
    if (p > 1.0f) p = 1.0f;
    G = in->net_let_enabled;
    C = G && (in->roll3 < s->let_prob || s->force_let);
    A = (roll1 < p) || s->force_error || s->force_net_error;
    B = (A && roll2 < s->net_share) || s->force_net_error;
    ax = in->tx < 0.0f ? -in->tx : in->tx;
    outside = (ax - in->xmax > 0.0f) || (in->tz < in->zlo) || (in->tz > in->zhi) || in->tx < 0.0f; /* ? exact strictness */
    F1 = !C && A && B && G;
    F2 = !F1 && (!in->b50 || (!C && in->b51 && A) || outside);
    if (C && !F2) return GP8_LET;
    if (F1) return GP8_NET;
    if (F2) return GP8_OUT;
    return GP8_IN;
}

/* ------------------------------------------------------------------ fn_8865AC08 (matched: src/xbox360/gp8_timing_grade.c) */
static float gp8_grade_factor(uint32_t h)
{
    switch (h) {
    case GP8_GRADE_VERY_GOOD: return 1.0f;    /* pool+0x000 */
    case GP8_GRADE_GOOD:      return 0.75f;   /* pool+0x2A0 */
    case GP8_GRADE_NORMAL:    return 0.5f;
    case GP8_GRADE_BAD:       return 0.25f;   /* pool+0x29C */
    default:                  return 0.0f;    /* VeryBad, Medium, anything else */
    }
}

/* ------------------------------------------------------------------ fn_8868E248 (ShotDifficulty analyser inputs) */
/*
 * For every candidate ball sample: dist_m = |S.player_pos(+0xE30 vec) - sample_pos| * 0.01 (pool+0x1BC) and
 * speed = dist_m / (ticks * 1/60) with ticks = sample_tick - clock tick (pool+0xE0 = 1/60; a zero time is
 * replaced by 1.0).  They are written to S+0x7A0 and S+0x7A4, then the analyser at PC+0x154 (hash of
 * "ShotDifficulty", crc32 0xDDA048F3) runs; its output (S+0x7A8, per fn_8868FCC0) is the "Ball Difficulty".
 */
static void gp8_shot_difficulty_inputs(float dist_cm, int ticks, float *s_7a0, float *s_7a4)
{
    float t = (float)ticks * (1.0f / 60.0f);
    float d = dist_cm * 0.01f;
    if (t == 0.0f) t = 1.0f;
    *s_7a0 = d;
    *s_7a4 = d / t;
}
