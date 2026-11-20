/* GA3: gameplay state machines (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "ga3_types.h"

/* ---- 4-state step handler ---- */
struct Ga3Pawn { unsigned char pad_00[0x310]; unsigned int value_310; };
struct Ga3PawnCore { unsigned char pad_00[0x30]; struct Ga3Pawn *pawn; };
struct Ga3PawnOwner { unsigned char pad_00[0x48]; struct Ga3PawnCore *core; };
struct Ga3PawnHost { unsigned char pad_00[8]; struct Ga3PawnOwner *owner; };
struct Ga3StepFlags { unsigned char pad_00[1]; unsigned char done; unsigned char pad_02[0x34]; unsigned char reset; };   /* +1 done, +0x36 reset */
struct Ga3StepOut { unsigned char pad_00[8]; int stage; };                                                              /* +8 */
struct Ga3Stepper {
    unsigned char pad_00[0x1C];
    struct Ga3PawnHost *host;       /* +0x1C */
    struct Ga3StepFlags *flags;     /* +0x20 */
    unsigned char *ranges;          /* +0x24 */
    struct Ga3StepOut *out;         /* +0x28 */
    unsigned char pad_2C[4];
    unsigned int pawn_30;           /* +0x30 */
    unsigned int pawn_34;           /* +0x34 */
};
unsigned char fn_88672750(void *self, void *range);
void ts4_set_onehot_flags_from_mode(struct Ga3Stepper *self);

/* Runs one state of the 4-state stepper: 0 sets stage 1, 1 caches the pawn value, 2 picks the stage from two range checks and finishes, 3 raises the reset flag. */
void ga3_stepper_run_state_88681848(struct Ga3Stepper *self, unsigned int state)
{
    switch (state) {
    case 0:
        self->out->stage = 1;
        break;
    case 1:
        self->pawn_34 = self->host->owner->core->pawn->value_310;
        break;
    case 2: {
        int one = 1;
        if (fn_88672750(self, self->ranges + 0x60)) {
            self->out->stage = 3;
        } else if (fn_88672750(self, self->ranges + 0x50)) {
            self->out->stage = 2;
        } else {
            self->out->stage = one;
        }
        ts4_set_onehot_flags_from_mode(self);
        self->flags->done = (unsigned char)one;
        self->pawn_30 = self->host->owner->core->pawn->value_310;
        break;
    }
    case 3:
        self->flags->reset = 1;
        break;
    default:
        break;
    }
}

/* ---- input-mode cycling driven by two button flags ---- */
struct Ga3ButtonRec { unsigned char pad_00[0x48]; unsigned short mask_48; unsigned char pad_4A[0x12]; unsigned short mask_5C; unsigned char pad_5E[0x66]; };   /* stride 0xC4 */
struct Ga3ButtonSet {
    unsigned char pad_00[0x1C];
    int default_index;                 /* +0x1C */
    unsigned char pad_20[0x10];
    int *active_index;                 /* +0x30 */
    int active_count;                  /* +0x34 */
    unsigned char pad_38[4];
    unsigned char *records;            /* +0x3C records, stride 0xC4 */
};
struct Ga3InputRoot { unsigned char pad_00[0x234]; struct Ga3ButtonSet *buttons; };   /* +0x234 */
extern struct Ga3InputRoot *lbl_88D45B1C;
struct Ga3ModeSlot { unsigned char pad_00[0xF4]; unsigned int mode_hash; };
struct Ga3Counter7 { unsigned char pad_00[0xC0]; int count; };
struct Ga3CounterOwner { unsigned char pad_00[0x2C]; struct Ga3Counter7 *counter; unsigned char pad_30[0x71B]; unsigned char flag_74B; };
struct Ga3ModeCycler {
    unsigned char pad_00[0x20];
    struct Ga3ModeSlot *slot;          /* +0x20 */
    unsigned char pad_24[0x14];
    struct Ga3CounterOwner *owner;     /* +0x38 */
};
void fn_88674E00(struct Ga3ModeCycler *self);

/* Reads the held-button masks of the active record; when mask +0x5C has bit 0x40 the mode hash steps 0x4850AF43 -> 0xC920AC38 -> 0x26296DD2 -> 0x4850AF43 and fn_88674E00 runs; when mask +0x48 has bit 0x40 a counter wraps 0..6. */
void ga3_cycle_mode_88684CE8(struct Ga3ModeCycler *self)
{
    struct Ga3ButtonSet *set = lbl_88D45B1C->buttons;
    int idx;
    struct Ga3ButtonRec *rec;
    unsigned char flag_a;
    unsigned char flag_b;
    if (set->active_count > 0 && *set->active_index != -1)
        idx = *set->active_index;
    else
        idx = set->default_index;
    rec = (struct Ga3ButtonRec *)(set->records + idx * 0xC4);
    flag_a = 0;
    flag_b = 0;
    if (rec) {
        if ((rec->mask_5C & 0x40) == 0x40) flag_a = 1;
        if ((rec->mask_48 & 0x40) == 0x40) flag_b = 1;
    }
    if (flag_a == 1) {
        struct Ga3ModeSlot *slot = self->slot;
        unsigned int mode = slot->mode_hash;
        if (mode == 0x4850AF43u)
            slot->mode_hash = 0xC920AC38u;
        else if (mode == 0xC920AC38u)
            slot->mode_hash = 0x26296DD2u;
        else
            slot->mode_hash = 0x4850AF43u;
        fn_88674E00(self);
    }
    if (flag_b == 1) {
        struct Ga3CounterOwner *owner = self->owner;
        owner->flag_74B = 1;
        owner->counter->count = (owner->counter->count + 1 > 6) ? 0 : owner->counter->count + 1;
    }
}

/* ---- stage decision ---- */
struct Ga3Keys { unsigned char pad_00[0x1C]; unsigned char key_a; unsigned char key_b; };            /* +0x1C, +0x1D */
struct Ga3Rally { unsigned char pad_00[0x9AC]; int limit; };                                         /* +0x9AC */
struct Ga3ViewA { unsigned char pad_00[0x6C]; struct Ga3Rally *rally; };                             /* +0x6C */
struct Ga3ViewB { unsigned char pad_00[0x44]; struct Ga3Keys *keys; };                               /* +0x44 */
struct Ga3ViewC { unsigned char pad_00[0x18C]; int amount; };                                        /* +0x18C */
struct Ga3Scene {
    unsigned char pad_00[8];
    unsigned char pad_08[0x3C];
    struct Ga3ViewA *view_a;         /* +0x44 */
    struct Ga3ViewB *view_b;         /* +0x48 */
    unsigned char pad_4C[0x2C];
    struct Ga3ViewC *view_c;         /* +0x78 */
};
struct Ga3EnvRef { unsigned char pad_00[8]; struct Ga3Scene *scene; };
struct Ga3StageOut { int stage; unsigned char pad_04[0x18]; unsigned char armed; };                   /* +0 stage, +0x1C */
struct Ga3Latches { unsigned char done; unsigned char pad_01; unsigned char l2; unsigned char l3; unsigned char l4; unsigned char pad_05[0x30]; unsigned char s35; unsigned char s36; unsigned char pad_37[9]; int word_40; };
struct Ga3Decider {
    unsigned char pad_00[0x1C];
    struct Ga3EnvRef *env;           /* +0x1C */
    struct Ga3Latches *latches;      /* +0x20 */
    unsigned char *ranges;           /* +0x24 */
    struct Ga3StageOut *out;         /* +0x28 */
    int *counter;                    /* +0x2C */
};
struct Ga3Decider *ts4_if_get_u32_off20_88659C48(struct Ga3Decider *self);   /* returns self */
void ts4_reset_color_block_88681AE0(struct Ga3Decider *self);

/* Decides the stage after a point: nothing when the amount is positive; stage 3 when the counter exceeds the rally limit and key A is held without key B; stage 1 when any of the three latches is set; stage 2 when the range check passes and the stage output is armed. */
void ga3_decide_stage_88681B80(struct Ga3Decider *self)
{
    struct Ga3Latches *lat = self->latches;
    struct Ga3Scene *scene;
    unsigned char keys_down;
    unsigned char any;
    int amount;
    unsigned char positive;
    amount = self->env->scene->view_c->amount;
    positive = amount > 0;
    lat->done = 0;
    self->latches->s35 = 0;
    if (positive)
        return;
    scene = self->env->scene;
    keys_down = scene->view_b->keys->key_a && !scene->view_b->keys->key_b;
    if (*self->counter > scene->view_a->rally->limit && keys_down) {
        self->out->stage = 3;
        lat->l2 = 1;
        {
            struct Ga3Decider *same = ts4_if_get_u32_off20_88659C48(self);
            lat->done = 1;
            ts4_reset_color_block_88681AE0(same);
        }
        self->latches->word_40 = 0;
        return;
    }
    any = lat->l4 || lat->l3 || lat->l2;
    if (any) {
        self->out->stage = 1;
        {
            struct Ga3Decider *same = ts4_if_get_u32_off20_88659C48(self);
            lat->done = 1;
            ts4_reset_color_block_88681AE0(same);
        }
        self->latches->word_40 = 0;
        return;
    }
    if (fn_88672750(self, self->ranges + 0x30) && self->out->armed) {
        self->out->stage = 2;
        lat->s36 = 0;
        lat->s35 = 1;
        ts4_reset_color_block_88681AE0(self);
    }
}
