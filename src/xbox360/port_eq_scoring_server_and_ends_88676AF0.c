/* NEAR MISS fn_88676AF0 StdScoring_UpdateServerAndEnds (ME, 2026-11-18), fn_check /Oc: 1 instruction off (+0x22C),
 * size matches. fn_equiv --flags /Oc --seed 1 --trials 1500: EQUIVALENT (16/16 blocks).
 * Operand-order sites 1 and 2 fixed with the period-8 numbering rule: 4 function-scope pads + named players base
 * local p, and 1 block pad in the set loop. Remaining: the merge add r11,r31,r30 of the two accumulators the
 * compiler creates when unrolling the set loop (ours r30,r31). A 16x10 joint pad sweep, block pads around the loop,
 * late-assigned pads and accumulator forms (named block temp, pointer accumulator) never flip it: the
 * compiler-temp case the rule does not cover (same as 0x88669F30). */
/*
 * ME: StdScoring_UpdateServerAndEnds (0x88676AF0). From the games played (0x88669F30), the
 * tie-break serve counter and the points of the current game it sets the server, the serving
 * court, each side's serve-rotation slot, and the court end of each side (ends change after
 * every odd number of games, counted as ceil(games/2) per set plus the tie-break end changes);
 * flags ends_changed when side 0's end differs from before.
 */
#include "rt1_scoring.h"

#define TS4_COURT_DEUCE 0x23BAED9Eu
#define TS4_COURT_AD    0xD826E563u
#define TS4_END_A       0x317C51B7u
#define TS4_END_B       0xA2EDA1E7u

struct Ts4ServeSide {                  /* stride 8 */
    int rotation;                      /* +0x00 serve-rotation slot */
    ts4_u32 end;                       /* +0x04 court end hash */
};
struct Ts4ServeBlock {                 /* B44 +0x48 */
    int sides_rel;                     /* +0x00 self-relative Ts4ServeSide[2] */
    ts4_u8 pad_04[8];
    int server;                        /* +0x0C */
    ts4_u32 court;                     /* +0x10 deuce/ad court hash */
};
struct Ts4ServeB44View { ts4_u8 pad_00[0x48]; struct Ts4ServeBlock serve; /* +0x48 */ };
struct Ts4ServeFlowView {
    ts4_u8 pad_00[0x93];
    ts4_bool match_over;               /* +0x93 */
    ts4_bool ends_changed;             /* +0x94 */
    ts4_u8 pad_95[0x327 - 0x95];
    ts4_bool doubles;                  /* +0x327 (inferred: two players per side) */
};
struct Ts4ScoringTbView {
    ts4_u8 pad_00[0x18];
    int tb_end_changes;                /* +0x18 */
    int tb_serve_changes;              /* +0x1C */
};

int fn_88669F30(struct Rt1Scoring *self);   /* games played in the match */

static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24));
}
static struct Rt1ScorePlayer *ts4_score_players(struct Rt1ScoreState *s)
{
    return (struct Rt1ScorePlayer *)((char *)s + s->players_rel);
}
static struct Rt1SetEntry *ts4_set_at(struct Rt1ScorePlayer *p, int set)
{
    return (struct Rt1SetEntry *)((char *)p + (p->sets.offset + set * 12));
}
static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{
    return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8));
}
static struct Ts4ServeFlowView *ts4_flow(struct Rt1Scoring *self) { return (struct Ts4ServeFlowView *)self->owner->flow; }

/* Swing_DLL.xex 0x88676AF0 */
void ts4_scoring_update_server_and_ends_88676AF0(struct Rt1Scoring *self)
{ int op1_pad0 = 0; int op1_pad1 = 0; int op1_pad2 = 0; int op1_pad3 = 0;
    struct Ts4ServeBlock *b;
    struct Rt1ScoreState *s;
    struct Rt1RulesInfo *rules;
    struct Ts4ServeSide *me, *other;
    int games, points, n, server, divisor, set, played, old_end;
    if (ts4_flow(self)->match_over)
        return;
    b = &((struct Ts4ServeB44View *)self->owner->b44)->serve;
    games = fn_88669F30(self);
    s = &self->rules->score;
    {
        struct Rt1ScorePlayer *p = ts4_score_players(s);
        points = p[1].points + p[0].points;
    }
    if (points % 2 == 0)
        b->court = TS4_COURT_DEUCE;
    else
        b->court = TS4_COURT_AD;
    n = ((struct Ts4ScoringTbView *)self)->tb_serve_changes + games;
    server = n % 2;
    b->server = server;
    me = ts4_serve_side(b, server);
    other = ts4_serve_side(b, 1 - server);
    divisor = ((ts4_flow(self)->doubles == 0) ^ 1) + 1;
    me->rotation = n / 2 % 2 % divisor;
    other->rotation = (n + points) % divisor;
    played = 0;
    rules = self->rules;
    for (set = 0; set <= rules->score.cur_set; set++) {
        int op2_pad0 = 0;
        int g = ts4_set_at(ts4_score_player(&rules->score, 0), set)->games +
                ts4_set_at(ts4_score_player(&rules->score, 1), set)->games;
        played += g % 2 + g / 2;
    }
    n = ((struct Ts4ScoringTbView *)self)->tb_end_changes + played;
    old_end = ts4_serve_side(b, 0)->end;
    if (n % 2 == 0) {
        ts4_serve_side(b, 0)->end = TS4_END_A;
        ts4_serve_side(b, 1)->end = TS4_END_B;
    } else {
        ts4_serve_side(b, 0)->end = TS4_END_B;
        ts4_serve_side(b, 1)->end = TS4_END_A;
    }
    ts4_flow(self)->ends_changed = ts4_serve_side(b, 0)->end != (ts4_u32)old_end;
}
