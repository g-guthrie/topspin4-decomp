/* near-miss: 58 off; fn_equiv EQUIVALENT (240 valid/764 trials, 6/6 blocks) */
/*
 * ME: game-point flags (0x8866A670). For the last point winner (or, before any point, the side stored
 * at RulesInfo +0x00) it saves each side's game-point flag as "previous" and sets the flag for the
 * side that is one point from the game target (+0x1D4 of the game configuration) and ahead.
 */
#include "/home/user/topspin4-decomp/src/xbox360/rt1_scoring.h"

struct Ts4GamePointFlag {              /* stride 0x10 */
    int active;                        /* +0x00 */
    int previous;                      /* +0x04 */
    ts4_u8 pad_08[8];
};
struct Ts4HudState { ts4_u8 pad_00[0x3C]; int flags_rel; /* +0x3C self-relative Ts4GamePointFlag[2] */ };
struct Ts4GameConfigTarget { ts4_u8 pad_000[0x1D4]; int target_points; /* +0x1D4 */ };

static struct Rt1ScorePlayer *ts4_score_player(struct Rt1ScoreState *s, int i)
{
    return (struct Rt1ScorePlayer *)((char *)s + (s->players_rel + i * 24));
}
static struct Ts4HudState *ts4_hud(struct Rt1Scoring *self)
{
    return *(struct Ts4HudState **)((char *)self->owner + 0x50);
}
static struct Ts4GamePointFlag *ts4_gp_flag(int *rel, int i)
{
    return (struct Ts4GamePointFlag *)((char *)rel + (*rel + i * 16));
}

/* Swing_DLL.xex 0x8866A670 */
void ts4_scoring_update_game_point_8866A670(struct Rt1Scoring *self)
{
    int target = ((struct Ts4GameConfigTarget *)self->owner->game_config)->target_points;
    int w = self->rules->last_winner;
    int o;
    struct Rt1ScorePlayer *me, *op;
    if (w == -1)
        w = *(int *)self->rules;
    o = w ^ 1;
    me = ts4_score_player(&self->rules->score, w);
    op = ts4_score_player(&self->rules->score, o);
    ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->previous = ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->active;
    ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->previous = ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->active;
    if (me->points >= target - 1 && me->points > op->points) {
        ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->active = 1;
        ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->active = 0;
    } else {
        ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->active = 0;
        ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->active = 0;
    }
}
