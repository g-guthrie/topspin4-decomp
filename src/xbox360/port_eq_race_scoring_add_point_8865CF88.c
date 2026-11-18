/* near-miss: 76 off, size 0x180 vs 0x17c; fn_equiv EQUIVALENT (seed 2: 187 valid/748, 13/13 blocks) */
/*
 * ME: race-scoring AddPoint (0x8865CF88); shared types as 0x8865C818. Counts the point; only the serving side scores. The match
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
static int ts4_max(int a, int b) { return a < b ? b : a; }
static struct Ts4ServeScoring *ts4_self(struct Ts4ServeScoring *s) { return s; }

/* Race scoring: a won point (reasons A03CA0ED, Miss) adds one to the winner; reasons 5E11F1A7,
   7DDEC718 and Let take one from the other side; scores never go below zero. Swing_DLL.xex 0x8865CF88 */
void ts4_race_scoring_add_point_8865CF88(struct Ts4ServeScoring *self)
{
    struct Rt1PointInfo *info;
    struct Rt1ScorePlayer *win, *lose;
    int w;
    { int *pc = &self->points_played; (*pc)++; }
    info = self->owner->info;
    w = self->vtbl->point_winner((struct Rt1Scoring *)self, info);
    lose = &ts4_score_players(&self->rules->score)[1 - w];
    win = &ts4_score_players(&self->rules->score)[w];
    switch (info->reason) {
    case 0xA03CA0EDu:
    case 0xC222A5E0u:
        win->points++;
        break;
    case 0x5E11F1A7u:
    case 0x7DDEC718u:
    case 0xC9238771u:
        lose->points--;
        break;
    }
    win->points = ts4_max(0, win->points);
    lose->points = ts4_max(0, lose->points);
    if (win->points - lose->points >= 2 &&
        win->points >= ((struct Ts4GameConfigTarget *)ts4_self(self)->owner->game_config)->target_points) {
        ts4_self(self)->owner->flow->match_over = 1;
        (*(struct Ts4StatsFlags **)((char *)self->owner + 0x4C))->match_event = 1;
    }
}
