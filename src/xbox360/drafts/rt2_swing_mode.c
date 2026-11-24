/*
 * RT2: swing-category mode selection (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * See docs/gameplay/controls-and-shot-selection.md sections 17 and 18.2.
 *
 * EQUIVALENT, not byte-matched (22 instructions differ: the original reloads pc->match and copies autoswing to r5).
 * Evidence: work/equiv/rt2_886B0250.json (296 valid trials, 100% blocks, --flags /Oc /fp:precise).
 * The callee 0x886B01A8 takes a third argument, autoswing (r5), which the d1g_shotreq.cpp copy does not declare.
 */
#include "../d1g_types.h"

#define RT2_PAD(name, n) ts4_u8 name[n]

/* Match state hash: end of the point. */
#define RT2_MATCH_STATE_END_OF_POINT 0x85E3E155u
/* Incoming shot record that skips the walk when the match mode is 2 (meaning not yet known). */
#define RT2_SHOT_RECORD_SKIP 0x280AE84Du

struct Rt2ShotRecordOwner {
    RT2_PAD(pad_00, 0x84);
    ts4_u32 record;                       /* +0x84 */
};
struct Rt2ShotRecordRef {
    RT2_PAD(pad_00, 0x88);
    struct Rt2ShotRecordOwner *owner;     /* +0x88 */
};
struct Rt2PlayerSlotInner {
    RT2_PAD(pad_00, 0x48);
    int player_index;                     /* +0x48 */
};
struct Rt2PlayerSlot {
    RT2_PAD(pad_00, 0x24);
    struct Rt2PlayerSlotInner *inner;     /* +0x24 */
};
struct Rt2MatchPlayers {
    RT2_PAD(pad_00, 4);
    struct Rt2ShotRecordRef **players;    /* +0x04 */
};
struct Rt2MatchClock {
    RT2_PAD(pad_00, 0x318);
    ts4_u32 state;                        /* +0x318 */
};
struct Rt2MatchModeRef {
    RT2_PAD(pad_00, 0x78);
    int *kind;                            /* +0x78: *kind == 2 is the special mode */
};
struct Rt2Match {
    RT2_PAD(pad_00, 4);
    struct Rt2ShotRecordRef **players;    /* +0x04 */
    RT2_PAD(pad_08, 0x28);
    struct Rt2MatchClock *clock;          /* +0x30 */
    RT2_PAD(pad_34, 0x44);
    int *mode;                            /* +0x78 */
};
struct Rt2State {
    RT2_PAD(pad_000, 0x7CC);
    float slow_down;                      /* +0x7CC SlowDown */
    RT2_PAD(pad_7d0, 0x540);
    ts4_u8 autoswing_good;                /* +0xD10 */
    RT2_PAD(pad_d11, 0x2AB);
    ts4_u8 end_of_point;                  /* +0xFBC BehaviorTransitionState.EOP */
};
struct Rt2Tuning {
    RT2_PAD(pad_000, 0x4D8);
    struct Ts4CategoryList normal[6];
    struct Ts4CategoryList autoswing_good[6];
    struct Ts4CategoryList autoswing_bad[6];
};
struct Rt2Controller {
    RT2_PAD(pad_00, 0x2C);
    struct Rt2Tuning *tuning;             /* +0x2C */
    RT2_PAD(pad_30, 0x18);
    struct Rt2Match *match;               /* +0x48 */
    struct Rt2PlayerSlot *slot;           /* +0x4C */
    RT2_PAD(pad_50, 0x24);
    struct Rt2State *state;               /* +0x74 */
};
struct Rt2SwingRequest {
    RT2_PAD(pad_00, 0x1C);
    struct Rt2Controller *pc;             /* +0x1C */
};

D1G_EXTERN_C extern const float lbl_8814B910; /* 0.5f */
D1G_EXTERN_C ts4_bool ts4_swing_category_by_class_886B01A8(struct Rt2SwingRequest *self,
                                                          struct Ts4CategoryList *lists, ts4_bool autoswing);

/* Pick the swing-category mode and walk its class list: Normal for a normal request, otherwise
   AutoSwingGood when the autoswing evaluation (S+0xD10) or SlowDown > 0.5, else AutoSwingBad.
   No walk at the end of the point, or in match mode 2 while the incoming shot record is 0x280AE84D.
   Swing_DLL.xex 0x886B0250 */
D1G_EXTERN_C ts4_bool ts4_swing_category_select_886B0250(struct Rt2SwingRequest *self, ts4_bool autoswing)
{
    struct Rt2Controller *pc = self->pc;
    ts4_bool found = 0;
    if (!(*pc->match->mode == 2 &&
          pc->match->players[pc->slot->inner->player_index]->owner->record == RT2_SHOT_RECORD_SKIP) &&
        pc->match->clock->state != RT2_MATCH_STATE_END_OF_POINT && !pc->state->end_of_point) {
        if (autoswing) {
            float d = lbl_8814B910 - pc->state->slow_down;
            ts4_u8 neg = *(unsigned short *)&d >> 15;
        if (pc->state->autoswing_good || neg)
                found = ts4_swing_category_by_class_886B01A8(self, pc->tuning->autoswing_good, autoswing);
            else
                found = ts4_swing_category_by_class_886B01A8(self, pc->tuning->autoswing_bad, autoswing);
        } else {
            found = ts4_swing_category_by_class_886B01A8(self, pc->tuning->normal, autoswing);
        }
    }
    return found;
}
