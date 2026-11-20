/* agP 2026-11-19: residue is constant (lfs vs lis/ori) scheduling, not a store; pointer-local trick not applicable. Not retried (needs drafts/rt2 context). */
/*
 * NEAR MISS ts4_swing_category_walk_886AFDF8 SwingCategory_Walk: 3 instructions off (same size 0x3AC), LTCG route:
 *   tools/fn_check_ltcg.py <this> ts4_swing_category_walk_886AFDF8=0x886AFDF8
 *     --context src/xbox360/drafts/rt2_rally_active.c --context src/xbox360/pp1_pool_primer.c --flags /Oc
 *   (TS4_MATCHING_DIR=work/matching-b105). Was 207 off on the plain route (rt1_eq_swing_category_walk.c).
 * Remaining: the `lfs f31` of the hoisted 0.5f is scheduled before `lis/ori r24,0xDFA2AFF1` (target: after).
 *   A 0.5f literal gets the order right but loads from __pool@ with an extra addi; extern-const in the
 *   loop is not hoisted (232 off).
 * Keys: rt2_rally_active.c (fn_8866D930) in the LTCG context keeps r4 live across the call; iterate a row
 *   pointer in `do { if (row == end) break; ...; row++; } while (!found);`; the reaction gate as
 *   `now = a || (b && c) || slow_down > half;`; take `sel = &self->pc->state->sel` and derive `st` from it.
 * fn_equiv (plain, /Oc, seed 1, work/matching-b46): EQUIVALENT, 249 valid of 400, 67/67 blocks.
 */
/*
 * RT2: swing-category row walk (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * ts4_swing_category_walk_886AFDF8 walks one class list of the swing-category rules (PT+0x4D8 + 0x48*mode + 0xC*class),
 * writes the first row whose condition holds to SwingCategory (S+0x360) and asks the animation
 * system for a clip (ts4_min_cost_until_zero_886AC7E0). See docs/gameplay/controls-and-shot-selection.md section 18.3.
 *
 * EQUIVALENT, not byte-matched (plain and LTCG routes: 0x3B8 vs 0x3AC bytes, the loop is rotated differently and
 * the registers differ). Evidence: work/equiv/rt2_886AFDF8.json (719 valid trials, 100% blocks, --flags /Oc /fp:precise).
 * Callees fn_88697E98 (condition switch) and ts4_min_cost_until_zero_886AC7E0 (clip query) keep placeholder names.
 */
#include "../d1g_types.h"

#define RT2_PAD(name, n) ts4_u8 name[n]

/* crc32 of the condition name "None": the row has no condition. */
#define RT2_COND_NONE 0xDFA2AFF1u

/* One swing-category rule row (0x14 bytes). */
struct Rt2CategoryRow {
    ts4_u32 value;           /* +0x00 SwingCategory written to S+0x360 */
    ts4_u32 alt_value;       /* +0x04 AltValue (5d78dedc), tried when the clip query reports no clip */
    ts4_u32 condition;       /* +0x08 Condition (2ce1ada4) crc32 */
    ts4_u32 skill_id;        /* +0x0C SkillId */
    ts4_u8 easy_autoswing;   /* +0x10 EasyAutoSwing (5b9470b9) */
    ts4_u8 unk_11;           /* +0x11 (e0dcd0b9) */
    ts4_u8 pad_12[2];
};

/* AnimationSelection.SwingSelection head (S+0x358). */
struct Rt2SwingSelection {
    ts4_u32 unk_00[2];
    ts4_u32 category;        /* +0x08 (S+0x360) SwingCategory */
    ts4_u32 unk_0c;
    ts4_u32 pro_style;       /* +0x10 (S+0x368) */
    ts4_u32 surface;         /* +0x14 (S+0x36C) */
};

struct Rt2WalkTuning {
    RT2_PAD(pad_000, 0x6D0);
    int window_default;      /* +0x6D0 clip window (frames) */
    int limit_default;       /* +0x6D4 due limit */
    int window_inside_out;   /* +0x6D8 */
    int limit_inside_out;    /* +0x6DC */
    int window_bd2;          /* +0x6E0 */
    int limit_bd2;           /* +0x6E4 */
};

struct Rt2WalkState {
    RT2_PAD(pad_000, 0x358);
    struct Rt2SwingSelection sel;     /* +0x358 */
    RT2_PAD(pad_370, 0x26B);
    ts4_u8 inside_out;                /* +0x5DB Context.IsInsideOut */
    RT2_PAD(pad_5dc, 0x1F0);
    float slow_down;                  /* +0x7CC */
    RT2_PAD(pad_7d0, 0x402);
    ts4_u8 flag_bd2;                  /* +0xBD2 */
    RT2_PAD(pad_bd3, 0x131);
    int timing_base_frame;            /* +0xD04 TimingBaseFrame */
};

struct Rt2RallyClock {
    RT2_PAD(pad_00, 0x68);
    int launch_frame;                 /* +0x68 frame of the opponent's launch */
};
struct Rt2FrameClock {
    RT2_PAD(pad_00, 0x310);
    int frame;                        /* +0x310 match frame */
};
struct Rt2ClockOwner {
    RT2_PAD(pad_00, 0x30);
    struct Rt2FrameClock *clock;      /* +0x30 */
};
struct Rt2AiSlot {
    RT2_PAD(pad_00, 0x20);
    struct Rt2ClockOwner *match;      /* +0x20 */
    struct Rt2RallyClock *rally;      /* +0x24 */
};
struct Rt2AiRecordInner {
    RT2_PAD(pad_00, 0x1C0);
    float reaction_time;              /* +0x1C0 SwingReactionTime */
};
struct Rt2AiRecord {
    RT2_PAD(pad_00, 0x28);
    struct Rt2AiRecordInner *inner;   /* +0x28 */
};

struct Rt2WalkController {
    RT2_PAD(pad_00, 0x10);
    ts4_u8 is_human;                  /* +0x10 */
    RT2_PAD(pad_11, 0x1B);
    struct Rt2WalkTuning *tuning;     /* +0x2C */
    RT2_PAD(pad_30, 0x1C);
    struct Rt2AiSlot *slot;           /* +0x4C */
    struct Rt2AiRecord *ai;           /* +0x50 */
    RT2_PAD(pad_54, 0x20);
    struct Rt2WalkState *state;       /* +0x74 */
};

struct Rt2WalkRequest {
    RT2_PAD(pad_00, 0x1C);
    struct Rt2WalkController *pc;     /* +0x1C */
    RT2_PAD(pad_20, 0x20);
    int unk_40;                       /* +0x40 */
    RT2_PAD(pad_44, 0x549);
    ts4_u8 latched;                   /* +0x58D request latched */
    RT2_PAD(pad_58e, 0xE);
    ts4_u8 autoswing_due;             /* +0x59C autoswing-due flag */
};

/* The row fields from +0x04 on: the walk steps a pointer to the AltValue field. */
struct Rt2RowTail {
    ts4_u32 alt_value;       /* +0x04 */
    ts4_u32 condition;       /* +0x08 */
    ts4_u32 skill_id;        /* +0x0C */
    ts4_u8 easy_autoswing;   /* +0x10 */
    ts4_u8 unk_11;           /* +0x11 */
    ts4_u8 pad_12[2];
};

static void rt2_set_category(struct Rt2SwingSelection *sel, ts4_u32 value)
{
    sel->category = value;
}

D1G_EXTERN_C extern const float lbl_8814B910; /* 0.5f */
D1G_EXTERN_C ts4_bool ts4_rally_active_8866D930(struct Rt2WalkController *pc);
D1G_EXTERN_C ts4_bool fn_88697E98(struct Rt2WalkRequest *self, struct Rt2CategoryRow *row);
D1G_EXTERN_C int ts4_min_cost_until_zero_886AC7E0(struct Rt2WalkController *pc, int deferred, int frames);

/* Walk one class list: for each row whose condition holds, write it to SwingCategory and query a
   clip (now, or deferred until the racket event); stop at the first row whose query started a clip.
   Returns whether a clip started. Swing_DLL.xex 0x886AFDF8 */
D1G_EXTERN_C ts4_bool ts4_swing_category_walk_886AFDF8(struct Rt2WalkRequest *self,
                                                      struct Ts4CategoryList *list, ts4_bool autoswing)
{
    struct Rt2WalkController *pc = self->pc;
    ts4_bool found = 0;
    ts4_bool queried = 0;
    ts4_bool due = 0;
    ts4_bool gate = pc->is_human;

    if (!gate) {
        int frames = pc->slot->match->clock->frame - pc->slot->rally->launch_frame;
        gate = pc->ai->inner->reaction_time < (float)frames && frames > 1;
    }
    if (!gate || !ts4_rally_active_8866D930(pc)) {
        self->unk_40 = 0;
    } else {
        char *end;
        char *begin;
        struct Rt2CategoryRow *row;
        end = 0;
        if (list->rel != -1)
            end = (char *)list + list->rel + list->count * 20;
        begin = 0;
        if (list->rel != -1)
            begin = (char *)list + list->rel;
        row = (struct Rt2CategoryRow *)begin;
        {
            float half = lbl_8814B910;
            do {
                int r;
                ts4_bool ok;
                if ((char *)row == end)
                    break;
                ok = 1;
                if (row->condition != RT2_COND_NONE)
                    ok = fn_88697E98(self, row);
                if (ok) {
                    struct Rt2SwingSelection *sel = &self->pc->state->sel;
                    struct Rt2WalkState *st = (struct Rt2WalkState *)((char *)sel - 0x358);
                    ts4_bool now;
                    rt2_set_category(sel, row->value);
                    st->sel.pro_style = RT2_COND_NONE;
                    st->sel.surface = RT2_COND_NONE;
                    now = self->autoswing_due || (self->latched && row->easy_autoswing) || self->pc->state->slow_down > half;
                    if (!autoswing || now) {
                        r = ts4_min_cost_until_zero_886AC7E0(self->pc, 0, 3);
                        if (row->alt_value != 0 && r == -1) {
                            rt2_set_category(sel, row->alt_value);
                            r = ts4_min_cost_until_zero_886AC7E0(self->pc, 0, 3);
                        }
                    } else {
                        struct Rt2WalkTuning *pt = self->pc->tuning;
                        ts4_u8 inside = self->pc->state->inside_out;
                        ts4_u8 bd2 = self->pc->state->flag_bd2;
                        int window = inside ? pt->window_inside_out : (bd2 ? pt->window_bd2 : pt->window_default);
                        int limit;
                        r = ts4_min_cost_until_zero_886AC7E0(self->pc, 1, window);
                        if (r > 0) {
                            limit = inside ? pt->limit_inside_out : (bd2 ? pt->limit_bd2 : pt->limit_default);
                            due = due || r < limit;
                        } else if (row->alt_value != 0 && r == -1) {
                            rt2_set_category(sel, row->alt_value);
                            r = ts4_min_cost_until_zero_886AC7E0(self->pc, 1, window);
                            if (r > 0) {
                                limit = inside ? pt->limit_inside_out : (bd2 ? pt->limit_bd2 : pt->limit_default);
                                due = due || r < limit;
                            }
                        }
                    }
                    found = r == 0;
                    queried = queried || r >= 0;
                }
                row++;
            } while (!found);
        }
    }
    if (due)
        self->autoswing_due = 1;
    if (queried) {
        self->unk_40 = 0;
        return found;
    }
    {
        ts4_bool late = self->pc->state->timing_base_frame < 30;
        if (late)
            self->unk_40++;
    }
    return found;
}
