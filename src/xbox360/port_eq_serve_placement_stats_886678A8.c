/* port_eq: EQUIVALENT to 0x886678A8 (serve placement statistics). NOT byte-matched (12 off; draft src/xbox360/drafts/me_886678A8_nearmiss.c).
 * Command: TS4_MATCHING_DIR=work/matching-b129 python3 tools/fn_equiv.py src/xbox360/port_eq_serve_placement_stats_886678A8.c fn_886678A8=0x886678A8 --flags /Oc --seed 1 --trials 3000
 * Verdict: EQUIVALENT, 2245 valid of 3000, coverage 96% (25/26 blocks). Evidence: work/equiv/agH_886678A8.json */
/*
 * 0x886678A8: serve placement statistics. Skipped when the B44 block's disabled flag (+0x1D0) is set.
 * From the current court (deuce/ad, +0x58) and the server's end (side end hash), maps the serve's x
 * position (+0x1B8) to a 0..1 lateral fraction: deuce (411.5 - x)/411.5 or (x + 411.5)/411.5, ad -x/411.5
 * or x/411.5 (constants g_ts4_script_constants[231], [232]); default 0.5. Below stats->lo (+0x104) counts
 * a short/T serve, above stats->hi (+0x108) a wide serve, otherwise middle, into the server's record
 * (self-relative array at stats+0x5C, stride 0x134, counters +0xBC..+0xD0; bucket names inferred).
 * Dead locals op1_pad* and q0_0 only steer MSVC's operand numbering (docs/agents/matching-tips.md, agG).
 */
#include "/home/user/topspin4-decomp/src/xbox360/rt1_scoring.h"

#define TS4_COURT_DEUCE 0x23BAED9Eu
#define TS4_COURT_AD    0xD826E563u
#define TS4_END_A       0x317C51B7u
#define TS4_END_B       0xA2EDA1E7u

extern const float g_ts4_script_constants[];  /* [231] 411.5f half-court width, [232] 1/411.5f */

struct Ts4ServeSide { int rotation; ts4_u32 end; };
struct Ts4ServeBlock { int sides_rel; ts4_u8 pad_04[8]; int server; ts4_u32 court; };
struct Ts4PlaceB44 {
    ts4_u8 pad_00[0x48];
    struct Ts4ServeBlock serve;        /* +0x48 */
    ts4_u8 pad_5c[0x1B8 - 0x5C];
    float serve_x;                     /* +0x1B8 */
    ts4_u8 pad_1bc[0x1D0 - 0x1BC];
    ts4_bool disabled;                 /* +0x1D0 */
};
struct Ts4PlaceStat {                  /* stride 0x134 */
    ts4_u8 pad_00[0xBC];
    int ad_short;                      /* +0xBC */
    int ad_mid;                        /* +0xC0 */
    int ad_wide;                       /* +0xC4 */
    int deuce_short;                   /* +0xC8 */
    int deuce_mid;                     /* +0xCC */
    int deuce_wide;                    /* +0xD0 */
    ts4_u8 pad_d4[0x134 - 0xD4];
};
struct Ts4PlaceStats {
    ts4_u8 pad_00[0x5C];
    struct Ts4RelArray stats;          /* +0x5C Ts4PlaceStat[] */
    ts4_u8 pad_64[0x104 - 0x64];
    float lo;                          /* +0x104 */
    float hi;                          /* +0x108 */
};
struct Ts4PlaceSelf {
    ts4_u8 pad_00[0x20];
    struct Ts4PlaceB44 *b44;           /* +0x20 */
    ts4_u8 pad_24[4];
    struct Ts4PlaceStats *stats;       /* +0x28 */
};

static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{
    return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8));
}
static struct Ts4PlaceStat *ts4_stat(struct Ts4RelArray *a, int i)
{
    return (struct Ts4PlaceStat *)((char *)a + a->offset) + i;
}

static struct Ts4PlaceB44 *ts4_b44(struct Ts4PlaceSelf *s) { return s->b44; }
static struct Ts4PlaceStats *ts4_stats(struct Ts4PlaceSelf *s) { return s->stats; }
void fn_886678A8(struct Ts4PlaceSelf *self)
{ int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0, op1_pad4 = 0;
    struct Ts4PlaceB44 *x = self->b44;
    ts4_u32 court, end;
    int server;
    float v;
    if (x->disabled)
        return;
    court = x->serve.court;
    server = ts4_b44(self)->serve.server;
    v = 0.5f;
    end = ts4_serve_side(&ts4_b44(self)->serve, server)->end;
    if (court == TS4_COURT_DEUCE) {
        if (end == TS4_END_A)
            v = (g_ts4_script_constants[231] - ts4_b44(self)->serve_x) * g_ts4_script_constants[232];
        else if (end == TS4_END_B)
            v = (ts4_b44(self)->serve_x + g_ts4_script_constants[231]) * g_ts4_script_constants[232];
    } else if (court == TS4_COURT_AD) {
        float t;
        if (end == TS4_END_A)
            t = -ts4_b44(self)->serve_x;
        else if (end == TS4_END_B)
            t = ts4_b44(self)->serve_x;
        else
            goto judged;
        v = t * g_ts4_script_constants[232];
    }
judged:
    if (v < self->stats->lo) {
        if (court == TS4_COURT_DEUCE)
            { int q0_0 = 0; ts4_stat(&ts4_stats(self)->stats, server)->deuce_short = ts4_stat(&self->stats->stats, server)->deuce_short + 1; }
        else if (court == TS4_COURT_AD)
            ts4_stat(&ts4_stats(self)->stats, server)->ad_short = ts4_stat(&ts4_stats(self)->stats, server)->ad_short + 1;
    } else if (v > self->stats->hi) {
        if (court == TS4_COURT_DEUCE)
            ts4_stat(&self->stats->stats, server)->deuce_wide = ts4_stat(&ts4_stats(self)->stats, server)->deuce_wide + 1;
        else if (court == TS4_COURT_AD)
            ts4_stat(&self->stats->stats, server)->ad_wide = ts4_stat(&ts4_stats(self)->stats, server)->ad_wide + 1;
    } else {
        if (court == TS4_COURT_DEUCE)
            ts4_stat(&self->stats->stats, server)->deuce_mid = ts4_stat(&ts4_stats(self)->stats, server)->deuce_mid + 1;
        else if (court == TS4_COURT_AD)
            ts4_stat(&self->stats->stats, server)->ad_mid = ts4_stat(&ts4_stats(self)->stats, server)->ad_mid + 1;
    }
}
