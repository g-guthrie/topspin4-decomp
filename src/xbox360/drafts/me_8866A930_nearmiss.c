/* q5s-nm (2026-11-24): the 7-off form depends on six dead op1_pad locals (disallowed); without them 29 off. Block-scoped macro forms: 89-90 off (hud/owner CSEd, fewer saved regs). Blocker: target reloads owner->hud after every store, which needs an aliasing-visible store type we have not found. */
/* agF 2026-11-19: still 7. A second helper computing (rel + i*16) + *rel for the active stores (o sites only, or all) does not move the add before the load. */
/* agD 2026-11-19: ts4_gp_flag as `{ int r = *rel; return (Flag *)((char *)rel + r) + i; }`: 8 -> 7 off (plain and LTCG). Remaining: the o-site active stores add (rel + i*16) before loading *rel in the target, plus two add operand orders (+0x58, +0xa4); a second helper form for the o sites did not help. */
/* agentA2 (2026-11-18 tips pass): ts4_gp_flag with named base and rel locals -> 9 to 8 off (plain and LTCG). Residue: the three active-flag stores read *rel before the add (target: add r3,i16,rel; lwz; stwx) and one add operand order at +0x58. Tried volatile *rel (size grows), reassociated and array-index forms. */
/* near-miss: 9 off (operand order/sched in flag stores; op1_pad x6 from operand_order_pad); fn_equiv: EQUIVALENT ts4_scoring_update_point_flags_8866A930 vs 0x8866A930 size 0x184: 57 valid trial(s) of 604, coverage 100% (7/7 blocks) */
/*
 * ME: game-point flags (0x8866A930). For the last point winner (or, before any point, the side stored
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
    { int r = *rel; return (struct Ts4GamePointFlag *)((char *)rel + r) + i; }
}

/* Game/set-point flags for whichever side is serving for it (server index at rules+0).
   Swing_DLL.xex 0x8866A930 */
void ts4_scoring_update_point_flags_8866A930(struct Rt1Scoring *self)
{ int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0, op1_pad4 = 0, op1_pad5 = 0;
    int w = *(int *)self->rules;
    int o = w ^ 1;
    struct Rt1ScorePlayer *me = ts4_score_player(&self->rules->score, w);
    struct Rt1ScorePlayer *op = ts4_score_player(&self->rules->score, o);
    int target = ((struct Ts4GameConfigTarget *)self->owner->game_config)->target_points;
    int mp = me->points, opp = op->points;
    ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->previous = ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->active;
    ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->previous = ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->active;
    if (mp >= target - 1 && mp > opp) {
        ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->active = 1;
        ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->active = 0;
    } else if (opp >= target - 1 && opp > mp) {
        ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->active = 0;
        ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->active = 1;
    } else {
        ts4_gp_flag(&ts4_hud(self)->flags_rel, w)->active = 0;
        ts4_gp_flag(&ts4_hud(self)->flags_rel, o)->active = 0;
    }
}
