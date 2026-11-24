/* near-miss: 58 off, size 0x180 vs 0x178; fn_equiv EQUIVALENT (360 valid/1006, 22/22 blocks) */
/*
 * ME: race-scoring WouldWin check (0x8866ADC0); shared types as 0x8865C818. Counts the point; only the serving side scores. The match
 * ends when the scorer leads by two and has reached the game configuration's target (+0x1D4); the
 * winner (the server) and the receiving side's rotation slot are recorded.
 */
#include "/home/user/topspin4-decomp/src/xbox360/rt1_scoring.h"

struct Ts4ServeSide {                  /* stride 8 */
    int rotation;                      /* +0x00 serve-rotation slot */
    ts4_u32 end;                       /* +0x04 court end hash */
};
struct Ts4ServeBlock {                 /* B44 +0x48 */
    int sides_rel;                     /* +0x00 self-relative Ts4ServeSide[2] */
    ts4_u8 pad_04[8];
    int server;                        /* +0x0C */
};
struct Ts4ServeB44View { ts4_u8 pad_00[0x48]; struct Ts4ServeBlock serve; /* +0x48 */ };
struct Ts4GameConfigTarget { ts4_u8 pad_000[0x1D4]; int target_points; /* +0x1D4 */ };
struct Ts4StatsFlags { ts4_u8 pad_00[0x1E]; ts4_bool match_event; /* +0x1E */ };
/* Serve-scoring object view: Rt1Scoring with its own counters. */
struct Ts4ServeScoring {
    struct Rt1ScoringVtbl *vtbl;       /* +0x00 */
    struct Rt1ScoringOwner *owner;     /* +0x04 */
    struct Rt1RulesInfo *rules;        /* +0x08 */
    int points_played;                 /* +0x0C */
    ts4_u8 pad_10[4];
    int winner;                        /* +0x14 */
    int loser_rotation;                /* +0x18 */
};

static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24));
}
static struct Rt1ScorePlayer *ts4_score_players(struct Rt1ScoreState *s)
{
    return (struct Rt1ScorePlayer *)((char *)s + s->players_rel);
}
static struct Rt1ScorePlayer *ts4_score_player2(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + s->players_rel) + i;
}
static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{
    return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8));
}

static void ts4_count(int *p) { (*p)++; }
static void ts4_count2(struct Ts4ServeScoring *s) { s->points_played++; }
#define TS4_FLAG(p, off) (*((unsigned char *)(p) + (off)))
#define TS4_I32(p, off) (*(int *)((char *)(p) + (off)))
static int ts4_max(int a, int b) { return a < b ? b : a; }

/* Would awarding this point (winner w, reason) end the race-scoring match?
   Swing_DLL.xex 0x8866ADC0 */
int ts4_race_scoring_would_win_8866ADC0(struct Ts4ServeScoring *self, int w, ts4_u32 reason)
{
    struct Rt1ScoringOwner *o = self->owner;
    int ret = 0;
    unsigned char ok = 1;
    int wp, lp;
    if (TS4_FLAG(o->flow, 0x32A)) {
        unsigned char judged = w != -1 && w != TS4_I32(o->flow, 0xA8) && !TS4_FLAG(o->flow, 0x328);
        if (judged) {
            if (!TS4_FLAG(o->b44, 0x9A))
                ok = 0;
        } else {
            if (o->info->reason == 0xC9238771u)
                ok = 0;
        }
    }
    if (!(unsigned char)ok)
        return ret;
    wp = ts4_score_players(&self->rules->score)[w].points;
    lp = ts4_score_players(&self->rules->score)[1 - w].points;
    switch (reason) {
    case 0xA03CA0EDu:
    case 0xC222A5E0u:
        wp++;
        break;
    case 0x5E11F1A7u:
    case 0x7DDEC718u:
    case 0xC9238771u:
        lp--;
        break;
    }
    wp = ts4_max(0, wp);
    lp = ts4_max(0, lp);
    if (wp - lp >= 2 && wp >= ((struct Ts4GameConfigTarget *)o->game_config)->target_points)
        ret = 1;
    return ret;
}
