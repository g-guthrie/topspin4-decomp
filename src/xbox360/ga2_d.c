/*
 * GA2: gameplay timing / selector helpers, Swing_DLL.xex 0x886601F0..0x8867B608.
 */
#include "ga2_types.h"

extern float g_ts4_script_constants[];
#define GA2_INVALID_FRAME 0x7FFFFFFF

/* ---- swing-timing window test (0x88662458 / 0x88662510) ---- */
struct Ga2TimingTuning { PAD(0x740); int window_740; };
struct Ga2TimingPlayerState { PAD(0x98); int press_frame_98; };
struct Ga2TimingClock { PAD(0x310); int clock_310; };
struct Ga2TimingMatch { PAD(0x30); struct Ga2TimingClock *clock; };
struct Ga2TimingCtx {
    PAD(0x2c);
    struct Ga2TimingTuning *tuning;
    PAD(0x48 - 0x30);
    struct Ga2TimingMatch *match;
    PAD(0x74 - 0x4c);
    struct Ga2TimingPlayerState *player;
};
struct Ga2TimingSelf { PAD(4); struct Ga2TimingCtx *ctx; };


/* ---- 0x8866EB80: set five limits to "none" (INT_MAX) ---- */
struct Ga2LimitBlock { PAD(0xb0); int lim_b0; PAD(4); int lim_b8; PAD(4); int lim_c0; PAD(0x1c); int lim_e0; PAD(4); int lim_e8; };
struct Ga2LimitOwner { PAD(0x20); struct Ga2LimitBlock *limits; };
struct Ga2LimitSelf { PAD(0x5c); struct Ga2LimitOwner *owner; };

/* ---- 0x88662980: find the entry whose id (+0x10) equals *key ---- */
struct Ga2IdEntry { PAD(0x10); ga2_u32 id_10; };
struct Ga2IdList { PAD(0x10); struct Ga2IdEntry **begin; struct Ga2IdEntry **end; };


/* ---- 0x88668C38 / 0x886685E0 / 0x88668568: per-player statistic counters ---- */
struct Ga2StatsFlags { PAD(0xe4); ga2_u8 flag_e4; };
struct Ga2StatsTotals { PAD(0x38); int total_38; };
struct Ga2StatsBinding { PAD(0xa9); ga2_u8 flag_a9; };
struct Ga2StatsSelf { PAD(0x20); struct Ga2StatsFlags *state; PAD(4); struct Ga2StatsTotals *totals; PAD(8); struct Ga2StatsBinding *binding; };

void fn_886567A8(void *obj, int id);
extern void *lbl_88D45B0C;

/* 0x88668C38: count the event and, when the binding is flagged, post event 0x2F. */
void ts4_ga2_count_and_post_88668C38(struct Ga2StatsSelf *self)
{
    if (!self->state->flag_e4) return;
    self->totals->total_38++;
    if (!self->binding->flag_a9) return;
    fn_886567A8(lbl_88D45B0C, 0x2f);
}

/* ---- 0x8866DF18: default hash, or the value of the selected entry in mode 2 ---- */
struct Ga2PickValue { PAD(0x84); ga2_u32 value_84; };
struct Ga2PickEntry { PAD(0x88); struct Ga2PickValue *value; };
struct Ga2PickMode { int mode; };
struct Ga2PickHolder { PAD(4); struct Ga2PickEntry **entries; PAD(0x70); struct Ga2PickMode *mode_78; };
struct Ga2PickIndexOwner { PAD(0x48); int index_48; };
struct Ga2PickIndexHolder { PAD(0x24); struct Ga2PickIndexOwner *owner_24; };
struct Ga2PickCtx { PAD(0x48); struct Ga2PickHolder *holder; struct Ga2PickIndexHolder *index_holder; };

/* 0x88662980 */
struct Ga2IdEntry *ts4_ga2_find_entry_by_id_88662980(struct Ga2IdList *self, ga2_u32 *key)
{
    struct Ga2IdEntry **end = self->end;
    struct Ga2IdEntry *result = 0;
    struct Ga2IdEntry **it = self->begin;
    for (; it != end; it++) {
        if (*key == (*it)->id_10) { result = *it; break; }
    }
    return result;
}

/* ---- 0x88668850: count one more event in two per-player counters when flagged ---- */
struct Ga2CountState { PAD(0xc6); ga2_u8 flag_c6; };
struct Ga2CountBlock { PAD(0x84); int count_84; PAD(0x130); int count_1b8; };
struct Ga2RelHdr { int rel; };
struct Ga2CountOwner { PAD(0x5c); struct Ga2RelHdr hdr; };
struct Ga2CountSelf { PAD(0x20); struct Ga2CountState *state; PAD(4); struct Ga2CountOwner *owner; };

void ts4_ga2_count_player_events_88668850(struct Ga2CountSelf *self)
{
    struct Ga2RelHdr *h;
    if (!self->state->flag_c6) return;
    h = &self->owner->hdr;
    ((struct Ga2CountBlock *)((char *)h + h->rel))->count_84++;
    h = &self->owner->hdr;
    ((struct Ga2CountBlock *)((char *)h + h->rel))->count_1b8++;
}

/* ---- 0x88670D50: reset the 8-byte slots of one 16-byte group to the default id ---- */
struct Ga2SlotGroup { int slots_rel; int slot_count; PAD(8); };    /* 16 bytes, slots are 8 bytes */
struct Ga2SlotTable { int groups_rel; };
struct Ga2SlotOwner { PAD(0x98); struct Ga2SlotTable table; };
struct Ga2SlotSelf { PAD(0x28); struct Ga2SlotOwner *owner; };

void ts4_ga2_reset_group_slots_88670D50(struct Ga2SlotSelf *self, int group)
{
    struct Ga2SlotTable *tbl = &self->owner->table;
    struct Ga2SlotGroup *g = (struct Ga2SlotGroup *)((char *)tbl + (group * 16 + tbl->groups_rel));
    int n = g->slot_count;
    int i;
    for (i = 0; i < n; i++)
        *(ga2_u32 *)((char *)g + g->slots_rel + i * 8 + 4) = 0x968230B3u;
}

