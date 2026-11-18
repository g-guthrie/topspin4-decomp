/*
 * D1G: shot request helpers of the swing request controller (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * See docs/gameplay/controls-and-shot-selection.md sections 4 and 6.2.
 */
#include "d1g_types.h"

D1G_EXTERN_C void ts4_shot_request_8868F178(struct Ts4PlayerController *pc);
D1G_EXTERN_C void fn_8866B8C0(struct Ts4SwingRequest *self);
D1G_EXTERN_C const float lbl_8814B440; /* 0.0f */

/* Reset a hold counter to {0 frames, 0.0}. */
static void ts4_hold_counter_reset(struct Ts4HoldCounter *c, float zero)
{
    c->value = zero;
    c->frames = 0;
}

/* Re-press while a request is already latched: rebuild the request and the press stamp, un-commit,
   and reset the power and risk hold counters. Swing_DLL.xex 0x88698538 */
D1G_EXTERN_C void ts4_shot_request_repress_88698538(struct Ts4SwingRequest *self)
{
    self->pc->swing_flags[0xD4] = 1;
    self->pressed = 1;
    ts4_shot_request_8868F178(self->pc);
    fn_8866B8C0(self);
    self->committed = 0;
    float zero = lbl_8814B440;
    ts4_hold_counter_reset(&self->receiver->power, zero);
    ts4_hold_counter_reset(&self->receiver->risk, zero);
    self->unk_40 = 0;
}

/* Swing class keys (PlayerState +0x35C, crc32 of the class name). */
#define TS4_CLASS_FLAT_POWER      0xDDDE0AE8u
#define TS4_CLASS_FLAT_FINESSE    0xB0043514u
#define TS4_CLASS_SLICE           0xFC6F57A1u
#define TS4_CLASS_VOLLEY_STANDARD 0xB70A03F3u
#define TS4_CLASS_VOLLEY_POWER    0xBFB9D8C0u
#define TS4_CLASS_SMASH           0x7EB30F90u

D1G_EXTERN_C ts4_bool ts4_swing_category_walk_886AFDF8(struct Ts4SwingRequest *self, struct Ts4CategoryList *list);

/* Pick the swing-category rule list of the current swing class (S+0x35C) inside one mode's six class
   lists and walk it; false for an unknown class. Swing_DLL.xex 0x886B01A8 */
D1G_EXTERN_C ts4_bool ts4_swing_category_by_class_886B01A8(struct Ts4SwingRequest *self,
                                                          struct Ts4CategoryList *lists)
{
    ts4_bool found = 0;
    switch (self->pc->state->swing_class) {
    case TS4_CLASS_FLAT_POWER:
        found = ts4_swing_category_walk_886AFDF8(self, &lists[0]);
        break;
    case TS4_CLASS_FLAT_FINESSE:
        found = ts4_swing_category_walk_886AFDF8(self, &lists[1]);
        break;
    case TS4_CLASS_SLICE:
        found = ts4_swing_category_walk_886AFDF8(self, &lists[2]);
        break;
    case TS4_CLASS_VOLLEY_STANDARD:
        found = ts4_swing_category_walk_886AFDF8(self, &lists[3]);
        break;
    case TS4_CLASS_VOLLEY_POWER:
        found = ts4_swing_category_walk_886AFDF8(self, &lists[4]);
        break;
    case TS4_CLASS_SMASH:
        found = ts4_swing_category_walk_886AFDF8(self, &lists[5]);
        break;
    }
    return found;
}
