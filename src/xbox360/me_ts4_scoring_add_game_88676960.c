/*
 * ME: StdScoring_AddGame (0x88676960). Awards the current game to the point winner, updates the
 * per-side game statistics (a "game held" counter when the other side's +0x0C stat is zero; meaning
 * of that field inferred, not verified), ends the set on a tie-break game or a two-game lead at
 * games_to_win, then sets the game-over flags.
 */
#include "rt1_scoring.h"

/* Match statistics reached through ScoringOwner +0x4C (only the fields used here). */
struct Ts4StatSide {                     /* stride 0x18, self-relative table at stats +0xB4 */
    ts4_u8 pad_00[0x0C];
    int break_count;                     /* +0x0C (inferred: zero = the winner held serve) */
    ts4_u8 pad_10[8];
};
struct Ts4StatTable { ts4_u8 pad_00[0xB4]; int sides_rel; /* +0xB4 */ };
struct Ts4PlayerStats {                  /* stride 0x134 */
    ts4_u8 pad_00[0xD4];
    int games_held;                      /* +0xD4 */
    ts4_u8 pad_d8[0x134 - 0xD8];
};
struct Ts4MatchStats {
    ts4_u8 pad_00[0x5C];
    int players_rel;                     /* +0x5C self-relative Ts4PlayerStats[2] */
    ts4_u8 pad_60[0x71 - 0x60];
    ts4_bool game_held;                  /* +0x71 */
};
struct Ts4StatsOwner {
    ts4_u8 pad_00[0x1C];
    ts4_bool game_event;                 /* +0x1C */
    ts4_u8 pad_1d[3];
    struct Ts4StatTable *table;          /* +0x20 */
    ts4_u8 pad_24[4];
    struct Ts4MatchStats *match;         /* +0x28 */
};
struct Ts4OwnerStatsView { ts4_u8 pad_00[0x4C]; struct Ts4StatsOwner *stats; /* +0x4C */ };

void fn_8866A060(struct Rt1Scoring *self);     /* set won */
void fn_88676898(struct Rt1Scoring *self);     /* next game setup */

static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24));
}
static struct Rt1SetEntry *ts4_set_at(struct Rt1ScorePlayer *p, int set)
{
    return (struct Rt1SetEntry *)((char *)p + (p->sets.offset + set * 12));
}
static struct Ts4StatsOwner *ts4_stats(struct Rt1Scoring *self)
{
    return ((struct Ts4OwnerStatsView *)self->owner)->stats;
}
static struct Ts4StatSide *ts4_stat_side(int *rel, int i)
{
    return (struct Ts4StatSide *)((char *)rel + (*rel + i * 24));
}
static struct Ts4PlayerStats *ts4_player_stats(int *rel, int i)
{
    return (struct Ts4PlayerStats *)((char *)rel + (i * 0x134 + *rel));
}

/* StdScoring_AddGame: award the current game to the point winner. Swing_DLL.xex 0x88676960 */
void ts4_scoring_add_game_88676960(struct Rt1Scoring *self)
{
    int w = self->vtbl->point_winner(self, self->owner->info);
    struct Rt1ScoreState *s = &self->rules->score;
    struct Rt1ScorePlayer *win = ts4_score_player(s, w);
    struct Rt1ScorePlayer *lose = ts4_score_player(s, 1 - w);
    struct Rt1SetEntry *we = ts4_set_at(win, s->cur_set);
    struct Rt1SetEntry *le = ts4_set_at(lose, s->cur_set);
    ts4_bool set_won;
    we->games++;
    ts4_stats(self)->match->game_held = 0;
    if (w >= 0 && ts4_stat_side(&ts4_stats(self)->table->sides_rel, 1 - w)->break_count == 0) {
        ts4_player_stats(&ts4_stats(self)->match->players_rel, w)->games_held++;
        ts4_stats(self)->match->game_held = 1;
    }
    win->points = 0;
    lose->points = 0;
    set_won = 0;
    if (s->tiebreak || (we->games >= self->games_to_win &&
        we->games - le->games >= 2))
        set_won = 1;
    if (set_won)
        fn_8866A060(self);
    if (!self->match_over)
        fn_88676898(self);
    self->owner->flow->game_over = 1;
    ts4_stats(self)->game_event = 1;
}
