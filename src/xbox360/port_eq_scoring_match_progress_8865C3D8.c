/* NEAR MISS fn_8865C3D8 match progress fraction (ME, 2026-11-18), fn_check /Oc: 11 instructions off, size matches.
 * Remaining: which of the three players_rel loads (first lwz / clrrwi copy / second lwz) feeds sets_won[0],
 * sets_won[1] and points[1]; ~400 orderings of the load statements (hill-climb) and &players[i] forms all stop at 11.
 * fn_equiv --flags /Oc --seed 1: EQUIVALENT (71 valid of 239, 9/9 blocks); per-player (self,i) accessors also stop at 11. */
#include "rt1_scoring.h"

static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24));
}
static struct Rt1SetEntry *ts4_set_at(struct Rt1ScorePlayer *p, int set)
{
    return (struct Rt1SetEntry *)((char *)p + (p->sets.offset + set * 12));
}
/* RulesInfo +0x50: points needed to win a game. */
static int ts4_game_points(struct Rt1RulesInfo *r) { return *(const int *)((const char *)r + 0x50); }
static int ts4_max(int a, int b) { return a < b ? b : a; }
/* Points player `me` still needs to win the current game against `op`. */
static int ts4_points_needed(int me, int op, int target)
{
    return op >= target - 1 ? op - me + 2 : target - me;
}

/* Match progress fraction: 1 - (fewest points either player still needs to win the match) / (max points).
   Swing_DLL.xex 0x8865C3D8 */
float ts4_scoring_match_progress_8865C3D8(struct Rt1Scoring *self)
{
    int target = ts4_game_points(self->rules);
    int pts1 = ts4_score_player(&self->rules->score, 1)->points;
    int games0 = ts4_set_at(ts4_score_player(&self->rules->score, 0), self->rules->score.cur_set)->games;
    int games = self->owner->config->games_per_set;
    int games1 = ts4_set_at(ts4_score_player(&self->rules->score, 1), self->rules->score.cur_set)->games;
    int pts0 = ts4_score_player(&self->rules->score, 0)->points;
    int sets1 = ts4_score_player(&self->rules->score, 1)->sets_won;
    int sets0 = ts4_score_player(&self->rules->score, 0)->sets_won;
    int sets = self->num_sets;
    int total = sets * games * 4;
    int left0 = sets - sets0, left1 = sets - sets1;
    int g0 = games - games0, g1 = games - games1;
    int need0 = ts4_points_needed(pts0, pts1, target);
    int need1 = ts4_points_needed(pts1, pts0, target);
    int r0 = ts4_max(0, ((left0 - 1) * games + g0) * 4 + need0 - 4);
    int r1 = ts4_max(0, ((left1 - 1) * games + g1) * 4 + need1 - 4);
    if (r0 >= r1)
        r0 = r1;
    return (float)(total - r0) / (float)total;
}
