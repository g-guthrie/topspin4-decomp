/* NEAR MISS fn_8865C648 StdScoring_RefreshDisplay (ME, 2026-11-18), fn_check /Oc: 56 off, 0x158 vs 0x148.
 * Behaviour read from the disassembly (not fn_equiv-checked). Blocker: the 0/15/30/40 map. Target is a beq
 * compare chain (cmp 0,1,2,3; bodies laid out 40,30,15); every switch form gives mtctr/bdzf, if-chains give
 * bne-ordered blocks. ~35 variants (case orders, default, unsigned, return form, LTCG with/without primer). */
#include "../rt1_scoring.h"

#define TS4_DISPLAY_ADVANTAGE (-1)

static struct Rt1ScorePlayer *ts4_score_players(struct Rt1ScoreState *s)
{
    return (struct Rt1ScorePlayer *)((char *)s + s->players_rel);
}
/* Points shown on the scoreboard: 0/15/30/40 in a normal game, the raw count in a tie-break. */
static int ts4_display_points(struct Rt1ScoreState *s, int points)
{
    if (!s->tiebreak) {
        switch (points) {
        case 0: return 0;
        case 1: return 15;
        case 2: return 30;
        case 3: return 40;
        }
    }
    return points;
}

/* StdScoring_RefreshDisplay: scoreboard values and the deuce flags. Swing_DLL.xex 0x8865C648 */
void ts4_scoring_refresh_display_8865C648(struct Rt1Scoring *self)
{
    struct Rt1ScoreState *s = &self->rules->score;
    struct Rt1ScorePlayer *p = ts4_score_players(s);
    s->deuce = 0;
    s->first_deuce = 0;
    if (!s->tiebreak && (p[0].points > 3 || p[1].points > 3)) {
        if (p[0].points == p[1].points) {
            p[0].display = 40;
            p[1].display = 40;
            s->deuce = 1;
        } else if (p[0].points > p[1].points) {
            p[0].display = TS4_DISPLAY_ADVANTAGE;
            p[1].display = 40;
        } else {
            p[0].display = 40;
            p[1].display = TS4_DISPLAY_ADVANTAGE;
        }
        return;
    }
    p[0].display = ts4_display_points(s, p[0].points);
    p[1].display = ts4_display_points(s, p[1].points);
    if (p[0].points == 3 && p[1].points == 3) {
        s->deuce = 1;
        s->first_deuce = 1;
    }
}
