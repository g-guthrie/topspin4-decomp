/*
 * Q5S rules: scoring object methods (vtables 0x880F48B8 / 0x880F4900 and siblings,
 * docs/gameplay/rules-and-scoring.md). Types: include/ts4/scoring.h.
 */
#include "include/ts4/ts4.h"
#include "include/ts4/scoring.h"

static Ts4ScorePlayer *ts4_score_players(Ts4ScoreState *s)
{
    return (Ts4ScorePlayer *)((char *)s + s->players_rel);
}

static Ts4ScorePlayer *ts4_score_player(Ts4ScoreState *s, int i)
{
    return (Ts4ScorePlayer *)((char *)s + s->players_rel) + i;
}

static Ts4SetEntry *ts4_score_set_entry(Ts4ScorePlayer *p, int set)
{
    return (Ts4SetEntry *)((char *)p + p->sets.offset) + set;
}

static void ts4_score_clear_deuce(Ts4ScoreState *s)
{
    s->deuce = 0;
    s->first_deuce = 0;
}

static void ts4_score_player_show_points(Ts4ScorePlayer *p)
{
    p->display = p->points;
}

/* Mark the current set of both players as decided by a single game (or not). */
static void ts4_score_set_single_game(Ts4ScoreState *s, bool single)
{
    int i;
    for (i = 0; i < 2; i++)
        ts4_score_set_entry(ts4_score_player(s, i), s->cur_set)->single_game = single;
}

/* Scoring refresh_display (vtable slot +0x1C): clear the deuce flags and show both players' raw point
 * counts. Swing_DLL.xex 0x8865C2D8 */
extern "C" void ts4_scoring_refresh_display_raw_8865C2D8(Ts4Scoring *self)
{
    Ts4ScoreState *s = ts4_rules_score(self->rules);
    Ts4ScorePlayer *p = ts4_score_players(s);
    ts4_score_clear_deuce(s);
    ts4_score_player_show_points(&p[0]);
    ts4_score_player_show_points(&p[1]);
}

/* Set start: in the last set of a match with a final super tie-break, switch to a tie-break to 10
 * points (no games); otherwise clear the super tie-break flag. Then flag the set as a one-game set when
 * games_to_win <= 1 and clear +0x1C. Swing_DLL.xex 0x8865C578 */
extern "C" void ts4_scoring_begin_set_8865C578(Ts4Scoring *self)
{
    Ts4ScoreState *s = ts4_rules_score(self->rules);
    if (self->final_set_super_tb && self->num_sets - 1 == s->cur_set) {
        s->tiebreak = 1;
        s->super_tiebreak = 1;
        self->games_to_win = 0;
        self->match->hud->point_target = 10;
    } else {
        s->super_tiebreak = 0;
    }
    ts4_score_set_single_game(s, self->games_to_win <= 1);
    self->f_1c = 0;
}
