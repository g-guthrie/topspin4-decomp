/*
 * D2G: point-start receiving/serving side resolution (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Called from the gameplay frame (src/xbox360/drafts/gp3_frame_step.c) when the active group is in mode 2.
 * Offsets were read from machine code; names are roles inferred from usage.
 */
#include "d1g_types.h"

#ifdef _MSC_VER
#define TS4_RX_FORCEINLINE static __forceinline
#else
#define TS4_RX_FORCEINLINE static inline
#endif

/* Float sign bit: d < 0 (or -0) when the top bit of the high halfword is set. */
#define TS4_SIGN_BIT(d) (*(unsigned short *)&(d) >> 15)

struct Ts4RxFlagBlock {
    ts4_u8 pad_00[0x1C];
    ts4_bool b1c;               /* +0x1C */
    ts4_bool b1d;               /* +0x1D */
};
struct Ts4RxFlow {
    ts4_u8 pad_000[0x32A];
    ts4_bool serve_phase;       /* +0x32A */
};
struct Ts4RxContext {
    ts4_u8 pad_00[0x30];
    struct Ts4RxFlow *flow;     /* +0x30 */
    ts4_u8 pad_34[0x10];
    struct Ts4RxFlagBlock *flags; /* +0x44 */
};

struct Ts4RxPlayerState {
    ts4_u8 pad_000[0xE6C];
    ts4_bool b_e6c;             /* +0xE6C */
    ts4_u8 pad_e6d[0x138];
    ts4_bool b_fa5;             /* +0xFA5 */
    ts4_u8 pad_fa6[0x14];
    ts4_bool b_fba;             /* +0xFBA */
};
struct Ts4RxAnim {
    ts4_u8 pad_00[0x8C];
    ts4_bool b8c;               /* +0x8C */
};
struct Ts4RxSideInfo {
    ts4_u8 pad_00[0x48];
    int index;                  /* +0x48 */
};
struct Ts4RxPlayer;
struct Ts4RxTeam {
    ts4_u8 pad_00[0x10];
    struct Ts4RxPlayer **members; /* +0x10 */
    ts4_u8 pad_14[0x10];
    struct Ts4RxSideInfo *side; /* +0x24 */
    ts4_u8 pad_28[4];
    int mode;                   /* +0x2C (2 = doubles) */
};
struct Ts4RxStateObj {
    ts4_u8 pad_00[0x84];
    ts4_u32 state;              /* +0x84 */
};
struct Ts4RxSlot {
    ts4_u8 pad_00[0x88];
    struct Ts4RxStateObj *obj;  /* +0x88 */
};
struct Ts4RxRules {
    int mode;                   /* +0x00 */
};
struct Ts4RxMatch {
    ts4_u8 pad_00[4];
    struct Ts4RxSlot **slots;   /* +0x04 */
    ts4_u8 pad_08[0x70];
    struct Ts4RxRules *rules;   /* +0x78 */
};
struct Ts4RxPlayer {
    ts4_u8 pad_00[0x10];
    ts4_bool active;            /* +0x10 */
    ts4_u8 pad_11[7];
    int partner_slot;           /* +0x18 */
    ts4_u8 pad_1c[0x2C];
    struct Ts4RxMatch *match;   /* +0x48 */
    struct Ts4RxTeam *team;     /* +0x4C */
    ts4_u8 pad_50[0x24];
    struct Ts4RxPlayerState *state; /* +0x74 */
    ts4_u8 pad_78[8];
    struct Ts4RxAnim *anim;     /* +0x80 */
    ts4_u8 pad_84[0x30];
    ts4_u32 key_b4;             /* +0xB4 */
    ts4_u8 pad_b8[0x304];
    int target_3bc;             /* +0x3BC */
};

struct Ts4RxEntry {
    float value;
    ts4_u32 unk;
};
struct Ts4RxTable {
    ts4_u8 pad_00[0x7C];
    struct Ts4RxEntry *entries; /* +0x7C */
};
struct Ts4RxLookup {
    int index;
    struct Ts4RxTable *table;
    ts4_u32 unk_08[2];
};

struct Ts4RxSetup {
    ts4_u8 pad_00[0x70];
    ts4_u8 side0[0x18];         /* +0x70 */
    float a88;                  /* +0x88 */
    ts4_bool b8c;               /* +0x8C */
    ts4_bool b8d;               /* +0x8D */
    ts4_u8 pad_8e[2];
    ts4_u8 side1[0x18];         /* +0x90 */
    float a8;                   /* +0xA8 */
    ts4_bool bac;               /* +0xAC */
    ts4_bool bad;               /* +0xAD */
    ts4_u8 pad_ae[0xA];
    int player_index;           /* +0xB8 */
};

struct Ts4RxOwner {
    ts4_u8 pad_00[0x10];
    struct Ts4RxPlayer **players; /* +0x10 */
    ts4_u8 pad_14[0xC];
    struct Ts4RxContext *ctx;   /* +0x20 */
    struct Ts4RxSetup *setup;   /* +0x24 */
    ts4_u8 pad_28[0x50];
    ts4_u8 list_78[0x44];       /* +0x78 */
    ts4_u8 list_bc[0x44];       /* +0xBC */
    ts4_u8 list_100[4];         /* +0x100 */
};

extern float lbl_8814B910;      /* 0.5f */

void fn_88660690(struct Ts4RxLookup *out, ts4_u32 key);
ts4_u8 fn_88660520(struct Ts4RxLookup *lookup);
void fn_8866D4D8(struct Ts4RxOwner *self, void *side, struct Ts4RxPlayer *player);
void fn_886A4978(struct Ts4RxPlayer *player, int flag);
void ts4_loop_call_seq_u32_off2c_8890E988(void *list);

static struct Ts4RxPlayer *ts4_rx_partner(struct Ts4RxPlayer *p)
{
    struct Ts4RxTeam *team = p->team;
    if (team->mode == 2)
        return team->members[p->partner_slot == 0];
    return p;
}

static ts4_bool ts4_rx_flag(struct Ts4RxOwner *self)
{
    struct Ts4RxFlagBlock *f = self->ctx->flags;
    return f->b1c && !f->b1d;
}

static int ts4_rx_in_state(struct Ts4RxMatch *m, struct Ts4RxPlayer *p, ts4_u32 state)
{
    return m->rules->mode == 2 && m->slots[p->team->side->index]->obj->state == state;
}

TS4_RX_FORCEINLINE void ts4_rx_mark_server(struct Ts4RxOwner *self)
{
    struct Ts4RxPlayer *p;
    self->players[self->setup->player_index]->state->b_fa5 = 1;
    p = ts4_rx_partner(self->players[self->setup->player_index]);
    p->state->b_fba = 1;
}

/* Point set-up between the active player and the partner/opponent: refresh the anim flags, look up both players'
   rows, then (outside the serve phase and the two blocking slot states) bind both sides, pick the starting roles
   from the setup flags or the row values, and run fn_886A4978 on each. In the serve phase mark the server.
   Swing_DLL.xex 0x886A4AE0 */
void ts4_rx_resolve_886A4AE0(struct Ts4RxOwner *self)
{
    struct Ts4RxPlayer *first;
    struct Ts4RxPlayer *a;
    struct Ts4RxPlayer *b;
    struct Ts4RxLookup la;
    struct Ts4RxLookup lb;
    int ok;
    struct Ts4RxMatch *m;

    first = self->players[0];
    a = first->active ? first : self->players[1];
    b = ts4_rx_partner(a);
    a->anim->b8c = !ts4_rx_flag(self);
    b->anim->b8c = !ts4_rx_flag(self);
    a->target_3bc = -1;
    b->target_3bc = -1;
    fn_88660690(&la, a->key_b4);
    fn_88660690(&lb, b->key_b4);
    ok = fn_88660520(&la) && fn_88660520(&lb);
    m = a->match;
    if (!ts4_rx_in_state(m, a, 0x280AE84D) && !ts4_rx_in_state(m, a, 0x2C59FAEA) && (ts4_bool)ok) {
        if (self->ctx->flow->serve_phase) {
            ts4_rx_mark_server(self);
            return;
        }
        {
            struct Ts4RxSetup *st;
            int both;
            int neither;
            ts4_bool mixed;
            float da;
            float db;
            unsigned neg_b;
            unsigned neg_a;
            fn_8866D4D8(self, self->setup->side0, a);
            fn_8866D4D8(self, self->setup->side1, b);
            st = self->setup;
            if (st->b8c && st->bad) {
                fn_886A4978(a, 0);
                fn_886A4978(b, 1);
                a->state->b_e6c = 1;
                return;
            }
            if (st->bac && st->b8d) {
                fn_886A4978(a, 1);
                fn_886A4978(b, 0);
                b->state->b_e6c = 1;
                return;
            }
            both = a->active && b->active;
            neither = !a->active && !b->active;
            mixed = !(ts4_bool)both && !(ts4_bool)neither;
            if ((ts4_bool)both)
                ts4_loop_call_seq_u32_off2c_8890E988(self->list_78);
            else if ((ts4_bool)neither)
                ts4_loop_call_seq_u32_off2c_8890E988(self->list_100);
            else if (mixed)
                ts4_loop_call_seq_u32_off2c_8890E988(self->list_bc);
            st = self->setup;
            da = lbl_8814B910 - st->a8;
            db = lbl_8814B910 - st->a88;
            neg_a = TS4_SIGN_BIT(da);
            neg_b = TS4_SIGN_BIT(db);
            if (!neg_b && !(ts4_bool)neg_a) {
                if (la.table->entries[la.index].value > lb.table->entries[lb.index].value)
                    a->state->b_fa5 = 1;
                else
                    b->state->b_fa5 = 1;
                return;
            }
            fn_886A4978(a, neg_b);
            fn_886A4978(b, neg_a);
            return;
        }
    }
    if (self->ctx->flow->serve_phase) {
        ts4_rx_mark_server(self);
    } else {
        a->state->b_fa5 = 1;
        b->state->b_fa5 = 1;
    }
}
