/* GA3: gameplay state/controller helpers (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "ga3_types.h"



/* ---- one-shot trigger: hand the caller's argument to fn_886965E0 once, unless the state mode excludes it ---- */
struct Ga3ModeState { unsigned char pad_00[0xD0]; unsigned int mode; };  /* +0xD0 current mode hash */
struct Ga3OnceObj {
    unsigned char pad_00[0x20];
    struct Ga3ModeState *state;   /* +0x20 */
    unsigned char pad_24[0x14];
    void *target;                 /* +0x38 */
    unsigned char pad_3C[0x368];
    unsigned char fired;          /* +0x3A4 */
};
void fn_886965E0(void *target, struct Ga3Id id, unsigned int arg);

/* Fires fn_886965E0(target, 0x1AD280AF, arg) the first time, unless the mode is 0xC222A5E0 or 0x5E11F1A7; marks the object as fired. */
void ga3_fire_once_886966A0(struct Ga3OnceObj *self, unsigned int arg)
{
    if (!self->fired) {
        unsigned int mode = self->state->mode;
        if (mode != 0xC222A5E0u && mode != 0x5E11F1A7u) {
            struct Ga3Id id = {0x1AD280AFu};
            fn_886965E0(self->target, id, arg);
        }
    }
    self->fired = 1;
}

/* ---- selects which sub-controller (+0, +0x44, +0x88) to update ---- */
struct Ga3Pawn30 { unsigned char pad_00[0xA8]; int slot_a8; unsigned char pad_AC[0x27E]; unsigned char flag_32A; };
struct Ga3Link4C { unsigned char pad_00[0x24]; struct Ga3Link24 *link24; int slot_28; };
struct Ga3Link24 { unsigned char pad_00[0xB8]; int value_b8; };
struct Ga3Core48 { unsigned char pad_00[0x30]; struct Ga3Pawn30 *pawn; };
struct Ga3Ctx {
    unsigned char pad_00[0x18];
    int key_18;                  /* +0x18 */
    unsigned char pad_1C[0x2C];
    struct Ga3Core48 *core;      /* +0x48 */
    struct Ga3Link4C *link;      /* +0x4C */
    unsigned char pad_50[0x24];
    struct Ga3Ctx74 *opts;       /* +0x74 */
};
struct Ga3Ctx74 { unsigned char pad_00[0x5D9]; unsigned char flag_5D9; };
struct Ga3Updater { unsigned char pad_00[0xCC]; struct Ga3Ctx *ctx; };
void ts4_loop_call_seq_u32_off2c_8890E988(void *sub);

/* Updates the sub-controller at +0x44 when the pawn flag is set and its slot differs from the link's, else the one at +0x88 when option +0x5D9 is set, else the base one. */
void ga3_update_sub_controller_8867DEF0(struct Ga3Updater *self)
{
    struct Ga3Ctx *ctx = self->ctx;
    struct Ga3Pawn30 *pawn = ctx->core->pawn;
    unsigned char first = pawn->flag_32A && pawn->slot_a8 != ctx->link->slot_28
                          && ctx->link->link24->value_b8 == ctx->key_18;
    if (first) {
        ts4_loop_call_seq_u32_off2c_8890E988((char *)self + 0x44);
    } else if (ctx->opts->flag_5D9) {
        ts4_loop_call_seq_u32_off2c_8890E988((char *)self + 0x88);
    } else {
        ts4_loop_call_seq_u32_off2c_8890E988(self);
    }
}

/* ---- per-frame sample copy ---- */
struct Ga3Settings38 { unsigned char pad_00[0x22C]; unsigned int mode_22C; unsigned char pad_230[8]; unsigned int mode_238; };
struct Ga3Link34 { unsigned char pad_00[0x38]; struct Ga3Settings38 *settings; };
struct Ga3Sampler {
    unsigned char pad_00[0x34];
    struct Ga3Link34 *link;       /* +0x34 */
    unsigned char pad_38[0x114];
    int *sources[4];              /* +0x14C pointers read each pass */
    unsigned char pad_15C[0x148];
    int values[4];                /* +0x2A4 sampled copies */
};
void fn_88696D40(struct Ga3Sampler *self, int index);

/* Refreshes the slot data and copies the value each source pointer refers to; 4 slots when mode 0xDD4BF7D9 or 0xFB595DB2 is set, else 2. */
void ga3_sample_sources_88697030(struct Ga3Sampler *self)
{
    struct Ga3Settings38 *cfg = self->link->settings;
    int count;
    int i;
    if (cfg->mode_22C == 0xDD4BF7D9u || cfg->mode_238 == 0xFB595DB2u)
        count = 4;
    else
        count = 2;
    for (i = 0; i < count; i++) {
        fn_88696D40(self, i);
        self->values[i] = *self->sources[i];
    }
}

/* ---- list adjustments ---- */
struct Ga3Counter { unsigned char pad_00[8]; int amount; unsigned int key; };  /* +8 amount, +0xC key */
struct Ga3CounterList { unsigned char pad_00[8]; struct Ga3Counter **begin; struct Ga3Counter **end; };

GA3_INLINE unsigned int *ga3_ids_end(struct Ga3RelArr *a)
{
    unsigned int *r = 0;
    if (a->offset != -1) r = (unsigned int *)((char *)a + (a->count * 4 + a->offset));
    return r;
}
GA3_INLINE unsigned int *ga3_ids_begin(struct Ga3RelArr *a)
{
    unsigned int *r = 0;
    if (a->offset != -1) r = (unsigned int *)((char *)a + a->offset);
    return r;
}

/* For every id in the relative array, adds delta to the amount of the first counter whose key differs from that id. */
void ga3_add_to_first_other_counter_886917F8(struct Ga3CounterList *self, struct Ga3RelArr *ids, int delta)
{
    unsigned int *end = ga3_ids_end(ids);
    unsigned int *id = ga3_ids_begin(ids);
    for (; id != end; id++) {
        struct Ga3Counter **last = self->end;
        struct Ga3Counter **it = self->begin;
        unsigned int want = *id;
        for (; it != last; it++) {
            if ((*it)->key != want) {
                (*it)->amount += delta;
                break;
            }
        }
    }
}

/* ---- pooled-object release ---- */
struct Ga3FreeStack {         /* fixed-capacity stack that grows downwards */
    void **limit;             /* +0x00 lowest usable slot */
    unsigned char pad_04[0x10];
    void **top;               /* +0x14 next free slot */
};
struct Ga3PoolOwner { unsigned char pad_00[0x64]; unsigned char *pool; };   /* free stack lives at pool+0x60 */
struct Ga3PoolHost { unsigned char pad_00[0x48]; struct Ga3PoolOwner *owner; };
struct Ga3ActiveList { void **begin; void **end; };
void fn_8890DDA8(void *p);
void fn_8890E088(void *p);

/* Releases every object in the active list (newest first): resets its three parts and returns it to the host's free stack. */
void ga3_release_all_pooled_8867DB30(struct Ga3ActiveList *self, struct Ga3PoolHost *host)
{
    while (self->begin != self->end) {
        unsigned char *obj = (unsigned char *)self->end[-1];
        struct Ga3FreeStack *fs;
        fn_8890DDA8(obj);
        fn_8890DDA8(obj + 0x44);
        fn_8890E088(obj + 0x88);
        fs = (struct Ga3FreeStack *)(host->owner->pool + 0x60);
        if (fs->top != fs->limit) {
            fs->top--;
            *fs->top = obj;
        }
        self->end--;
    }
}

