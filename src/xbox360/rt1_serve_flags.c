/*
 * RT1: Rules_PublishPointEndFlags, the serve-number bookkeeping (docs/gameplay/rules-and-scoring.md
 * s3.1, s4.7).
 *
 * Once per point end (RulesInfo.point_end_pending): publish the game / set / match-over events
 * and the change-of-ends requests for the umpire, then update the serve number:
 *   fault on a first serve (multi-serve game)           -> second serve
 *   second serve, net cord (LetIn/LetOut), no fault     -> stays second serve
 *   otherwise                                           -> first serve
 *   a Withdrawal always resets it.
 * The serve-phase flags record a Miss and the net-cord state.
 *
 * Verdict: MATCH (tools/fn_check.py, base flags; work/specs/RT1/rt1_serve_flags.json). Also
 * EQUIVALENT under tools/fn_equiv.py with hash seeding (100% block coverage).
 */
#include "rt1_scoring.h"

/* The point-end publisher: owner at +4 and a pending-ends byte at +8. */
struct Rt1PointEndPublisher {
    ts4_u32 unk_00;
    struct Rt1ScoringOwner *owner;     /* +0x04 */
    ts4_bool ends_pending;             /* +0x08 a change of ends is waiting for the set end */
};

/* Swing_DLL.xex 0x88669878 */
void ts4_rules_publish_point_end_flags_88669878(struct Rt1PointEndPublisher *self)
{
    struct Rt1RulesInfo *r = &((struct Rt1ScoreB44Rules *)self->owner->b44)->rules;
    ts4_u32 reason;

    if (r->point_end_pending) {
        if (self->owner->flow->game_over) {
            r->game_over_event = 1;
            self->owner->flow->game_over = 0;
            if (self->owner->flow->ends_changed && !r->score.tiebreak) {
                r->ends_change = 1;
                if (!self->ends_pending) {
                    self->ends_pending = 1;
                    r->ends_change_2 = 1;
                }
            }
            if (self->owner->flow->set_over) {
                r->set_over_event = 1;
                self->ends_pending = 0;
                if (self->owner->flow->match_over)
                    r->match_over_event = 1;
            }
        }
        if (self->owner->game_config->mode != RT1_GAME_MODE_E981B5D1 && self->owner->flow->match_over) {
            r->game_over_event = 1;
            r->set_over_event = 1;
            r->match_over_event = 1;
        }
    }
    if (!r->point_end_pending)
        return;

    r->second_serve_let = 0;
    r->missed_serve = 0;
    r->net_cord = 0;
    reason = r->reason;
    if (self->owner->flow->serve_phase) {
        ts4_u32 ball = self->owner->ball->ball->mode;
        ts4_bool let_in = ball == RT1_BALL_LET_IN;
        ts4_bool let_out = ball == RT1_BALL_LET_OUT;
        if (!let_in) {
            if (reason == RT1_REASON_MISS)
                r->missed_serve = 1;
            else
                r->second_serve_let = r->second_serve;
        }
        r->net_cord = let_in || let_out;
    }
    {
        struct Rt1ScoringOwner *o = self->owner;
        ts4_bool fault = o->flow->fault;
        if (fault && !r->second_serve && !o->game_config->single_serve)
            r->second_serve = 1;
        else if (r->second_serve && r->net_cord && !fault && !o->game_config->single_serve)
            r->second_serve = 1;
        else
            r->second_serve = 0;
    }
    if (reason == RT1_REASON_WITHDRAWAL)
        r->second_serve = 0;
}
