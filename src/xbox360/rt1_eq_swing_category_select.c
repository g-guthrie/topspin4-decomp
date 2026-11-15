/*
 * RT1: SwingCategory_Select (docs/gameplay/controls-and-shot-selection.md s17, s18.3; model
 * ref/gameplay/swing_category.c).
 *
 * No swing at the end of a point: in play mode 2 when this player's match record is unclassified
 * (0x280AE84D), when the match state is 0x85E3E155, or with S+0xFBC set. Otherwise pick the rule
 * lists of the mode (Normal for a normal request; AutoSwingGood when TimingState.0eaa0333 or
 * SlowDown > 0.5, else AutoSwingBad) and walk the current class's list.
 *
 * Verdict: EQUIVALENT (tools/fn_equiv.py --seed 1: 100% block coverage;
 * work/specs/RT1/rt1_eq_swing_category_select.equiv.json). Not byte-matched: 57 instructions differ
 * from +0x3C; the original re-reads pc->match after the play-mode test and keeps the zero result
 * in r9 from the entry, so every register in the record chain shifts. LTCG gives the same result.
 */
#include "d1g_types.h"

#define RT1_RECORD_UNCLASSIFIED 0x280AE84Du
#define RT1_MATCH_STATE_85E3E155 0x85E3E155u

/* Views of the d1g incomplete types used here. */
struct Rt1SelPlayerRecord { ts4_u8 pad_00[0x84]; ts4_u32 outcome; /* +0x84 */ };
struct Rt1SelMatchPlayer { ts4_u8 pad_00[0x88]; struct Rt1SelPlayerRecord *record; /* +0x88 */ };
struct Rt1SelTeamState { ts4_u8 pad_00[0x48]; int player; /* +0x48 index into match->players */ };
struct Rt1SelTeam { ts4_u8 pad_00[0x24]; struct Rt1SelTeamState *state; /* +0x24 */ };

extern const float lbl_8814B910;              /* 0.5f */

/* SwingCategory_ClassList: walks the class list of `lists`; autoswing is forwarded in r5. */
ts4_bool ts4_swing_category_by_class_886B01A8(struct Ts4SwingRequest *self, struct Ts4CategoryList *lists,
                                              ts4_bool autoswing);

/* Swing_DLL.xex 0x886B0250 */
ts4_bool ts4_swing_category_select_886B0250(struct Ts4SwingRequest *self, ts4_bool autoswing)
{
    struct Ts4PlayerController *pc = self->pc;
    ts4_bool result = 0;

    if (!(pc->match->mode->kind == 2 &&
          ((struct Rt1SelMatchPlayer **)pc->match->players)[((const struct Rt1SelTeam *)pc->slot)->state->player]
                  ->record->outcome == RT1_RECORD_UNCLASSIFIED) &&
        pc->match->clock->state != RT1_MATCH_STATE_85E3E155 && !pc->state->flag_fbc) {
        struct Ts4PlayerState *s = pc->state;
        if (autoswing) {
            float margin = lbl_8814B910 - s->slow_down;
            if (s->autoswing_good || (*(unsigned short *)&margin >> 15))
                result = ts4_swing_category_by_class_886B01A8(self, pc->tuning->autoswing_good, autoswing);
            else
                result = ts4_swing_category_by_class_886B01A8(self, pc->tuning->autoswing_bad, autoswing);
        } else {
            result = ts4_swing_category_by_class_886B01A8(self, pc->tuning->normal, autoswing);
        }
    }
    return result;
}
