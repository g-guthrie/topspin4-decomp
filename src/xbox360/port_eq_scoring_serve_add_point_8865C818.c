/* NEAR MISS fn_8865C818 serve-scoring AddPoint (ME, 2026-11-18), fn_check /Oc: 13 off, size matches.
 * fn_equiv --flags /Oc --seed 1 --trials 1000: EQUIVALENT (30 valid of 415, 6/6 blocks).
 * Fixed so far: the counter increment through a plain block-local pointer (keeps the owner/vtbl loads after
 * the store), the &players[i] form with &self->rules->score at each use (gives the dead mr copy).
 * Remaining: owner-before-vtbl load order at the vcall (5 instrs) and register numbering of the win/lose
 * addresses. ~45 variants. */
/*
 * ME: serve-scoring AddPoint (0x8865C818). Counts the point; only the serving side scores. The match
 * ends when the scorer leads by two and has reached the game configuration's target (+0x1D4); the
 * winner (the server) and the receiving side's rotation slot are recorded.
 */
#include "rt1_scoring.h"

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
/* Swing_DLL.xex 0x8865C818 */
void ts4_serve_scoring_add_point_8865C818(struct Ts4ServeScoring *self)
{
    struct Ts4ServeBlock *b;
    struct Rt1ScoreState *s;
    struct Rt1ScorePlayer *win, *lose;
    int w;
    { int *pc = &self->points_played; (*pc)++; }
    b = &((struct Ts4ServeB44View *)self->owner->b44)->serve;
    w = self->vtbl->point_winner((struct Rt1Scoring *)self, self->owner->info);
    s = &self->rules->score;
    lose = &ts4_score_players(&self->rules->score)[1 - w];
    win = &ts4_score_players(&self->rules->score)[w];
    if (b->server == w)
        win->points++;
    if (win->points - lose->points >= 2 &&
        win->points >= ((struct Ts4GameConfigTarget *)self->owner->game_config)->target_points) {
        self->owner->flow->match_over = 1;
        (*(struct Ts4StatsFlags **)((char *)self->owner + 0x4C))->match_event = 1;
    }
    self->winner = b->server;
    self->loser_rotation = ts4_serve_side(b, 1 - b->server)->rotation;
}
