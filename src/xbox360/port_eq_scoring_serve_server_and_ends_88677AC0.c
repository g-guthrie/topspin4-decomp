/* near-miss: 8 off (scheduling only); fn_equiv EQUIVALENT (233 valid/327, 8/8 blocks) */
/*
 * ME: serve-scoring UpdateServerAndEnds (0x88677AC0). From the points played (+0x0C, counted as a
 * tie-break): ends change every 6 points, court alternates every point, the server changes every
 * 2 points after the first, and each side's rotation slot follows the 4-point cycle.
 */
#include "/home/user/topspin4-decomp/src/xbox360/rt1_scoring.h"

#define TS4_COURT_DEUCE 0x23BAED9Eu
#define TS4_COURT_AD    0xD826E563u
#define TS4_END_A       0x317C51B7u
#define TS4_END_B       0xA2EDA1E7u

struct Ts4ServeSide {
    int rotation;                      /* +0x00 */
    ts4_u32 end;                       /* +0x04 */
};
struct Ts4ServeBlock {                 /* B44 +0x48 */
    int sides_rel;                     /* +0x00 */
    ts4_u8 pad_04[8];
    int server;                        /* +0x0C */
    ts4_u32 court;                     /* +0x10 */
};
struct Ts4ServeB44View { ts4_u8 pad_00[0x48]; struct Ts4ServeBlock serve; };
struct Ts4ServeFlowView {
    ts4_u8 pad_00[0x93];
    ts4_bool match_over;               /* +0x93 */
    ts4_bool ends_changed;             /* +0x94 */
    ts4_u8 pad_95[0x327 - 0x95];
    ts4_bool doubles;                  /* +0x327 (inferred) */
};
struct Ts4ServeScoring {
    void *vtbl;
    struct Rt1ScoringOwner *owner;     /* +0x04 */
    struct Rt1RulesInfo *rules;        /* +0x08 */
    ts4_u32 points_played;             /* +0x0C */
};

static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{
    return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8));
}
static struct Ts4ServeFlowView *ts4_flow(struct Ts4ServeScoring *self) { return (struct Ts4ServeFlowView *)self->owner->flow; }

/* Swing_DLL.xex 0x88677AC0 */
void ts4_serve_scoring_update_server_and_ends_88677AC0(struct Ts4ServeScoring *self)
{
    struct Ts4ServeBlock *b;
    ts4_u32 old_end;
    int divisor;
    int server;
    if (ts4_flow(self)->match_over)
        return;
    b = &((struct Ts4ServeB44View *)self->owner->b44)->serve;
    old_end = ts4_serve_side(b, 0)->end;
    if (self->points_played % 12 < 6) {
        ts4_serve_side(b, 0)->end = TS4_END_A;
        ts4_serve_side(b, 1)->end = TS4_END_B;
    } else {
        ts4_serve_side(b, 0)->end = TS4_END_B;
        ts4_serve_side(b, 1)->end = TS4_END_A;
    }
    ts4_flow(self)->ends_changed = ts4_serve_side(b, 0)->end != old_end;
    if (self->points_played % 2 == 0)
        b->court = TS4_COURT_DEUCE;
    else
        b->court = TS4_COURT_AD;
    server = (self->points_played - 1) % 4 <= 1;
    b->server = server;
    divisor = ((ts4_flow(self)->doubles == 0) ^ 1) + 1;
    ts4_serve_side(b, server)->rotation = (int)((self->points_played + 1) % 8 >= 4) % divisor;
    ts4_serve_side(b, 1 - server)->rotation = (int)(self->points_played % 4 >= 2) % divisor;
}
