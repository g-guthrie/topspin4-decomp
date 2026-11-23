/*
 * RT1: SwingCategory_Walk (docs/gameplay/controls-and-shot-selection.md s17, s18.3; model
 * ref/gameplay/swing_category.c sc_walk).
 *
 * Reaction gate (human, or AI frames since the opponent's launch beyond SwingReactionTime and
 * > 1, then ts4_rally_active_8866D930). For each row of the category list whose condition holds: write the
 * category (ProStyle / Surface keys = None) and query a clip: immediately when already autoswung,
 * latched with an EasyAutoSwing row, or SlowDown > 0.5, or in any non-autoswing walk; otherwise
 * deferred with the (window, limit) frame pair. "No clip" (-1) tries AltValue. The walk stops at
 * the first query that started a clip; the result is that flag. Afterwards: a deferred result
 * below the limit sets autoswing_due; any result >= 0 clears walk_misses; otherwise walk_misses
 * grows while TimingBaseFrame < 30 (the doc's ">= 30" is reversed: subfc/eqv/addze at +0x374).
 *
 * Verdict: EQUIVALENT (tools/fn_equiv.py --flags /Oc --seed 1: 100% block coverage;
 * work/specs/RT1/rt1_eq_swing_category_walk.equiv.json). Not byte-matched: the original keeps the
 * list pointer in r4 across ts4_rally_active_8866D930 (LTCG: that callee never writes r4), so register
 * allocation differs from +0x1C on; a byte match needs the LTCG route with ts4_rally_active_8866D930 in context.
 * 2026-11-18: the LTCG form in src/xbox360/drafts/me_886AFDF8_nearmiss.c (context rt2_rally_active.c) is
 * 3 instructions off (one lfs scheduled early); see its header for the source shape.
 */
#include "rt1_types.h"

/* Rally/request gate of the human swing (no C yet; reads only r3). */
ts4_bool ts4_rally_active_8866D930(struct Rt1PlayerCtxW *pc);
/* SwingCategory_Condition: evaluates row->condition. */
ts4_bool fn_88697E98(struct Rt1SwingRequest *self, const struct Rt1CategoryRow *row);
/* SwingClip_QueryLevels: -1 no clip, 0 started, > 0 frames to the racket event (deferred). */
int ts4_min_cost_until_zero_886AC7E0(struct Rt1PlayerCtxW *pc, int deferred, int window);

/* AI reaction delay elapsed: frames since the opponent's launch beyond SwingReactionTime, and > 1. */
static RT1_INLINE ts4_bool rt1_reaction_elapsed(const struct Rt1PlayerCtxW *pc)
{
    int frames = pc->team->match->flow->frame - pc->team->launch->launch_frame;
    if (pc->ai->record->swing_reaction_time < (float)frames && frames > 1)
        return 1;
    return 0;
}

static RT1_INLINE const struct Rt1AutoswingWindow *rt1_window(const struct Rt1TuningW *t, ts4_u8 inside_out, ts4_u8 wide)
{
    if (inside_out)
        return &t->inside_out;
    if (wide)
        return &t->flag_bd2;
    return &t->normal;
}

/* Swing_DLL.xex 0x886AFDF8 */
ts4_bool ts4_swing_category_walk_886AFDF8(struct Rt1SwingRequest *self, const struct Ts4RelArray *list, ts4_bool autoswing)
{
    struct Rt1PlayerCtxW *pc = self->pc;
    ts4_bool started = 0;
    ts4_bool found = 0;
    ts4_bool due = 0;
    ts4_bool ready = pc->is_human;

    if (!ready)
        ready = rt1_reaction_elapsed(pc);
    if (ready && ts4_rally_active_8866D930(pc)) {
        const struct Rt1CategoryRow *row = 0;
        const struct Rt1CategoryRow *end = 0;
        if (list->offset != -1)
            end = (const struct Rt1CategoryRow *)((const char *)list + (list->count * (int)sizeof(struct Rt1CategoryRow) + list->offset));
        if (list->offset != -1)
            row = (const struct Rt1CategoryRow *)((const char *)list + list->offset);

        for (; row != end; row++) {
            struct Rt1PlayerStateW *s;
            ts4_bool immediate;
            int n;

            if (row->condition != RT1_CONDITION_NONE && !fn_88697E98(self, row))
                continue;
            s = self->pc->state;
            s->swing_category = row->value;
            s->pro_style = RT1_CONDITION_NONE;
            s->surface = RT1_CONDITION_NONE;
            immediate = self->autoswing_due || (self->latched && row->easy_autoswing) || s->slow_down > 0.5f;

            if (autoswing && !immediate) {
                struct Rt1PlayerCtxW *p = self->pc;
                ts4_u8 inside_out = p->state->is_inside_out;
                ts4_u8 wide = p->state->flag_bd2;
                int window = rt1_window(p->tuning, inside_out, wide)->window;
                n = ts4_min_cost_until_zero_886AC7E0(p, 1, window);
                if (n > 0) {
                    due = due || n < rt1_window(p->tuning, inside_out, wide)->limit;
                } else if (row->alt != 0 && n == -1) {
                    s->swing_category = row->alt;
                    n = ts4_min_cost_until_zero_886AC7E0(self->pc, 1, window);
                    if (n > 0)
                        due = due || n < rt1_window(p->tuning, inside_out, wide)->limit;
                }
            } else {
                n = ts4_min_cost_until_zero_886AC7E0(self->pc, 0, 3);
                if (row->alt != 0 && n == -1) {
                    s->swing_category = row->alt;
                    n = ts4_min_cost_until_zero_886AC7E0(self->pc, 0, 3);
                }
            }
            started = n == 0;
            found = found || n >= 0;
            if (started) {
                row++;
                break;
            }
        }
    } else {
        self->walk_misses = 0;
    }

    if (due)
        self->autoswing_due = 1;
    if (found) {
        self->walk_misses = 0;
    } else if (self->pc->state->timing_base_frame < 30) {
        self->walk_misses++;
    }
    return started;
}
