/* PORT (EQUIVALENT) fn_88676DB0 StdScoring_AddPoint (ME, 2026-11-18). Behaviour: fn_equiv EQUIVALENT,
 * command: TS4_MATCHING_DIR=work/matching-b46 python3 tools/fn_equiv.py <this file>
 *   ts4_scoring_add_point_88676DB0=0x88676DB0 --flags /Oc --trials 3000 --seed 1 --json work/equiv/rt1_88676DB0.json
 * result: 57 valid trials of 1214 run (time limit), coverage 100% (15/15 blocks), size 0x1FC.
 * Bytes: fn_check /Oc 35 off, size matches (not byte-matched; see near-miss notes below).
 */
/* UPDATE (agentB, 2026-11-18): 35 off. Behaviour fix from the target: the stats update 0x88674ED0 runs on every
 * point (the blt past the game check and the beq past AddGame both land on it), not only when the game is won.
 * C++ rewrite (Rt1Scoring as a class with real virtuals, slot 8 point_winner) did not help: with C++ `bool` the
 * three flags are no longer all evaluated first (`||` 80-89 off, `|` 81, helper/else-if/goto forms 80-88). */
/* NEAR MISS fn_88676DB0 StdScoring_AddPoint (ME, 2026-11-18), fn_check /Oc: 39 off with `lead | cap | short_format`
 * (size matches); the `||` form is 81 off (0x1F8 vs 0x1FC). Open: the target evaluates all three flags first,
 * cap = tiebreak ? (pts == 99) via li/beq, the format test as subis/addi/cntlzw, then branches on each flag;
 * player 1 set-entry store addresses players+0x18 (addi) before its loads. ~60 variants. Not fn_equiv-checked. */
/*
 * ME: StdScoring_AddPoint (0x88676DB0). Gives the point to the point winner, mirrors both players'
 * point counts into the current set entry, awards the game (AddGame 0x88676960, then the stats
 * update 0x88674ED0) on a two-point lead past the game target, at 99 points in a tie-break, or
 * in the short format; in a tie-break it counts the change-of-ends (every 6 points) and
 * server-switch (odd total) events.
 */
#include "rt1_scoring.h"

/* Tie-break event counters of the scoring object (+0x18, +0x1C). */
struct Ts4ScoringTbView {
    ts4_u8 pad_00[0x18];
    int tb_end_changes;            /* +0x18 */
    int tb_serve_changes;          /* +0x1C */
};

void ts4_scoring_add_game_88676960(struct Rt1Scoring *self);
void ts4_scoring_reset_88674ED0(void *stats);

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
static void *ts4_owner_stats(struct Rt1ScoringOwner *o) { return *(void **)((char *)o + 0x4C); }

/* Swing_DLL.xex 0x88676DB0 */
void ts4_scoring_add_point_88676DB0(struct Rt1Scoring *self)
{
    int w = self->vtbl->point_winner(self, self->owner->info);
    struct Rt1ScoreState *s = &self->rules->score;
    struct Rt1ScorePlayer *win = ts4_score_player(s, w);
    struct Rt1ScorePlayer *lose = ts4_score_player(s, 1 - w);
    win->points++;
    ts4_set_at(&ts4_score_players(s)[0], s->cur_set)->points = ts4_score_players(s)[0].points;
    ts4_set_at(&ts4_score_players(s)[1], s->cur_set)->points = ts4_score_players(s)[1].points;
    if (win->points >= self->owner->b44->point_target) {
        ts4_bool lead = win->points - lose->points >= 2;
        ts4_bool cap = s->tiebreak ? win->points == 99 : 0;
        ts4_bool short_format = self->owner->config->format == RT1_FORMAT_SHORT;
        if (lead | cap | short_format)
            ts4_scoring_add_game_88676960(self);
    }
    ts4_scoring_reset_88674ED0(ts4_owner_stats(self->owner));
    if (s->tiebreak) {
        struct Rt1ScorePlayer *p = ts4_score_players(&self->rules->score);
        int total = p[1].points + p[0].points;
        if (total != 0) {
            if (total % 6 == 0)
                ((struct Ts4ScoringTbView *)self)->tb_end_changes++;
            if (total % 2 == 1)
                ((struct Ts4ScoringTbView *)self)->tb_serve_changes++;
        }
    }
}
