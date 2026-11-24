/*
 * GA2: gameplay controller / state helpers, Swing_DLL.xex 0x886601F0..0x8867B608.
 * Struct layouts list only the fields the matched functions touch (see ga2_types.h).
 */
#include "ga2_types.h"

/* ---- 0x886688A8 ---- */
struct Ga2StatsEntity { PAD(0x48); int count_48; };
struct Ga2StateFlags { PAD(0xd0); ga2_u32 id_d0; PAD(2); ga2_u8 f_d6; ga2_u8 f_d7; };
struct Ga2StateFlags99 { PAD(0x99); ga2_u8 f_99; PAD(0x36); ga2_u32 id_d0; PAD(2); ga2_u8 f_d6; ga2_u8 f_d7; };
struct Ga2CountOwner { PAD(0x20); struct Ga2StateFlags99 *state; PAD(4); struct Ga2StatsEntity *stats; };

/* ---- selector update ---- */
struct Ga2Selector {
    PAD(0x410);
    void *entry_410;
    PAD(0x18);
    int pending_42c;
    PAD(0x114);
    void *entry_544;
};
struct Ga2EntryHolder { PAD(0x28); void *entry_28; };
struct Ga2SelHolder { PAD(0x28); struct Ga2Selector *selector; };
struct Ga2PlayerState9fc { PAD(0x9fc); ga2_u32 state_id; };
struct Ga2EntryOwner { PAD(0x5c); struct Ga2EntryHolder *current; };
struct Ga2SelCtx {
    PAD(0x48);
    struct Ga2EntryOwner *a;
    PAD(0x14);
    struct Ga2SelHolder *b;
    PAD(0x10);
    struct Ga2PlayerState9fc *player;
};
struct Ga2SelSelf { PAD(4); struct Ga2SelCtx *ctx; };


/* ---- per-player record array (stride 0x140, self-relative, at +0x104 of the match object) ---- */
struct Ga2Rec140 { PAD(0xd0); ga2_u8 flag_d0; PAD(0x6f); };
struct Ga2RecList { int recs_rel; };
struct Ga2RecTable { PAD(0x104); struct Ga2RecList recs; };
struct Ga2RecOwner { PAD(0x44); struct Ga2RecTable *table; };
struct Ga2RecTop { PAD(0x14); int cur_index; PAD(0x30); struct Ga2RecOwner *owner; };
struct Ga2RecSelf { PAD(0x1c); struct Ga2RecTop *top; };

/* 0x886612A8: clear flag byte 0xD0 of the current player's record. */
void ts4_ga2_clear_current_record_flag_886612A8(struct Ga2RecSelf *self)
{
    struct Ga2RecTop *top = self->top;
    struct Ga2RecList *list = &top->owner->table->recs;
    int idx = top->cur_index;
    struct Ga2Rec140 *rec = (struct Ga2Rec140 *)((char *)list + (idx * 0x140 + list->recs_rel));
    rec->flag_d0 = 0;
}

/* ---- is-idle ---- */
struct Ga2IdleState { PAD(0xf3); ga2_u8 busy_f3; };
struct Ga2IdleSelf { PAD(0x38); struct Ga2IdleState *state; ga2_u8 active_3c; PAD(0x3f); int timer_7c; };

/* 0x88664680: active, not busy, and the timer has run out. */
ga2_u8 ts4_ga2_is_idle_88664680(struct Ga2IdleSelf *self)
{
    return self->active_3c != 0 && self->state->busy_f3 == 0 && self->timer_7c <= 0;
}

/* ---- counter wrap ---- */
struct Ga2CounterSub { PAD(0xc0); int counter_c0; };
struct Ga2CounterSelf { PAD(0x2c); struct Ga2CounterSub *sub; PAD(0x74b - 0x30); ga2_u8 armed_74b; };

/* ---- frame flag clear ---- */
struct Ga2FrameFlags {
    PAD(0x96); ga2_u8 f_96; ga2_u8 f_97;
    PAD(0xcc - 0x98); ga2_u8 f_cc; ga2_u8 f_cd; ga2_u8 f_ce;
    PAD(0xe5 - 0xcf); ga2_u8 f_e5;
    PAD(0x160 - 0xe6); ga2_u8 f_160; ga2_u8 f_161; ga2_u8 f_162; PAD(1); ga2_u8 f_164;
    PAD(0x19a - 0x165); ga2_u8 f_19a;
};
struct Ga2FrameOwner { PAD(0x44); struct Ga2FrameFlags *flags; };
struct Ga2FrameSelf { PAD(4); struct Ga2FrameOwner *owner; };

