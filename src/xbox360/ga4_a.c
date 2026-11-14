/*
 * GA4: gameplay controller helpers (Top Spin 4, Xbox 360, Swing_DLL.xex), batch A.
 * Offsets were read from machine code; names follow docs/gameplay where known.
 */
#include "ts4_vector.h"

typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

/* Ring of 10 slots of 0x41C bytes starting at +0x34; newest slot = (head + count - 1) % 10. */
struct Ga4SlotRing {
    ts4_u8 pad_00[8];
    ts4_u32 head;      /* +0x08 */
    ts4_u32 count;     /* +0x0C */
    ts4_u8 pad_10[0x24];
    ts4_u8 slots[10][0x41C]; /* +0x34 */
};

extern void fn_886A0188(void *slot);

/* Pass the most recently added slot of the ring to the slot handler. Swing_DLL.xex 0x886A75D0 */
void ga4_ring_newest_slot_886A75D0(struct Ga4SlotRing *ring)
{
    fn_886A0188(ring->slots[(ring->head + ring->count - 1) % 10]);
}

/* ------------------------------------------------------------------ */
extern ts4_u8 fn_88688D90(void *obj);

struct Ga4FlagBlock { ts4_u8 pad_000[0xA34]; ts4_u8 flag_a34; ts4_u8 pad_a35[0x19C]; ts4_u8 flag_bd1; };
struct Ga4Inner { ts4_u8 pad_00[0x74]; struct Ga4FlagBlock *flags; };
struct Ga4Mid { ts4_u8 pad_00[0x30]; struct Ga4Inner *inner; };
struct Ga4Link { ts4_u8 pad_00[0x68]; struct Ga4Mid *mid; ts4_u8 pad_6c[8]; struct Ga4FlagBlock *flags; };
struct Ga4Host154 { ts4_u8 pad_00[0x154]; struct Ga4Link *link; };

/* Publish the query result into both flag bytes (+0xA34 via link->mid->inner, +0xBD1 via link). Swing_DLL.xex 0x8869A4D0 */
void ga4_publish_query_flag_8869A4D0(struct Ga4Host154 *host)
{
    ts4_u8 v = fn_88688D90(host);
    host->link->mid->inner->flags->flag_a34 = v;
    host->link->flags->flag_bd1 = v;
}

/* ------------------------------------------------------------------ */
extern char lbl_880F4428, lbl_880D19F0, lbl_880F46F0, lbl_880F4BCC, lbl_880D6B70;
extern void fn_8890F1E8(void *element);

/* 0x44-byte element with its own vtable. */
struct Ga4Element {
    void *vtbl;
    ts4_u32 words[16];
};

/* Owner holding four elements at +0x08 (stride 0x44). */
struct Ga4OwnerFour {
    void *vtbl;
    ts4_u32 f04;
    struct Ga4Element elem[4];
};

/* Destroy an owner with four elements: destroy the elements back to front, then reset the vtable.
   Swing_DLL.xex 0x886A0478 */
void ga4_owner_four_dtor_886A0478(struct Ga4OwnerFour *self)
{
    struct Ga4Element *e = self->elem + 4;
    int n;
    self->vtbl = &lbl_880F4428;
    for (n = 3; n >= 0; n--) {
        e--;
        fn_8890F1E8(e);
    }
    self->vtbl = &lbl_880D19F0;
}

/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
extern void fn_886921A0(void *target, int flag, int a, int b);

struct Ga4SideInfo { ts4_u8 pad_00[0x28]; int side; };
struct Ga4TeamInfo { ts4_u8 pad_00[0x7C]; int side; };
struct Ga4EnableBlock { ts4_u8 pad_00[0x6C]; ts4_u8 enabled; };
struct Ga4TeamOwner {
    ts4_u8 pad_00[0x28];
    struct Ga4EnableBlock *enable;  /* +0x28 */
    ts4_u8 pad_2c[4];
    struct Ga4TeamInfo *team;       /* +0x30 */
};
struct Ga4SideHost {
    ts4_u8 pad_00[0x18];
    int mode;                       /* +0x18 */
    ts4_u8 pad_1c[0x2C];
    struct Ga4TeamOwner *owner;     /* +0x48 */
    struct Ga4SideInfo *other;      /* +0x4C */
    ts4_u8 pad_50[0x64];
    void *target;                   /* +0xB4 */
};

/* If the owner's team side equals the other party's side and the enable byte is set, notify the target
   (flag = mode > 1). Swing_DLL.xex 0x8869D870 */
void ga4_notify_same_side_8869D870(struct Ga4SideHost *self)
{
    struct Ga4TeamOwner *owner = self->owner;
    struct Ga4SideInfo *other = self->other;
    if (owner->team->side != other->side)
        return;
    if (!owner->enable->enabled)
        return;
    fn_886921A0(self->target, self->mode > 1, 0, 1);
}

/* ------------------------------------------------------------------ */
extern void *fn_8865FD40(void *self, int index);
extern void fn_886A02B0(void *dst, void *entry);
extern void ts4_if_call_seq_u32_off4_8865E5C0(void *obj, void *rel_base);
extern void ts4_loop_call_seq_fn_886917F8_88691900(void *dst, void *src_a, void *src_b);

struct Ga4EntryRec { ts4_u8 pad_00[0xC]; int rel; /* +0x0C self-relative offset */ };
struct Ga4Inner5C { ts4_u8 pad_00[0x18]; void *sink; };
struct Ga4Inner18 { ts4_u8 pad_00[0x5C]; struct Ga4Inner5C *sub; };
struct Ga4EntryHost {
    ts4_u8 pad_00[0x10];
    int index;                      /* +0x10 */
    ts4_u8 pad_14[4];
    struct Ga4Inner18 *inner;       /* +0x18 */
    ts4_u8 pad_1c[4];
    ts4_u8 slot[1];                 /* +0x20 */
};

/* Load entry `index`: copy it into `dst`, remember the index, hand the entry's relative-offset base to the
   sink and refresh the state at +0x20 from the entry's +0x14/+0x20 members. Swing_DLL.xex 0x886A7610 */
void ga4_entry_select_886A7610(struct Ga4EntryHost *self, void *dst, int index)
{
    struct Ga4EntryRec *rec = (struct Ga4EntryRec *)fn_8865FD40(self, index);
    int *rel;
    fn_886A02B0(dst, rec);
    self->index = index;
    rel = &rec->rel;
    ts4_if_call_seq_u32_off4_8865E5C0(self->inner->sub->sink, (char *)rel - *rel);
    ts4_loop_call_seq_fn_886917F8_88691900(self->slot, (char *)rec + 0x14, (char *)rec + 0x20);
}

/* ------------------------------------------------------------------ */
extern void fn_88692468(void *a, void *b, void *c, ts4_u32 d, int e);

struct Ga4Clock310 { ts4_u8 pad_00[0x310]; ts4_u32 value; };
struct Ga4Clock30 { ts4_u8 pad_00[0x30]; struct Ga4Clock310 *clock; };
struct Ga4Range { ts4_u8 pad_00[0x5A0]; ts4_u32 begin; ts4_u32 end; };
struct Ga4Widget { ts4_u8 pad_00[0x88]; struct Ga4Range *range; };
struct Ga4Quad { ts4_u32 w[4]; };
struct Ga4Member {
    ts4_u8 pad_00[0x48];
    struct Ga4Clock30 *ctx;         /* +0x48 */
    ts4_u8 pad_4c[0x28];
    void *p74;                      /* +0x74 */
    ts4_u8 pad_78[0x3C];
    struct Ga4Widget *widget;       /* +0xB4 */
    void *pb8;                      /* +0xB8 */
    ts4_u8 pad_bc[4];
    void *pc0;                      /* +0xC0 */
    void *pc4;                      /* +0xC4 */
    struct Ga4Quad *result;         /* +0xC8 */
};
struct Ga4MemberSet { ts4_u8 pad_00[4]; struct Ga4Member **members; /* +0x04, four entries */ };

/* Run the per-member update for each of the four member slots that is occupied.
   Swing_DLL.xex 0x8869F068 */
void ga4_update_members_8869F068(struct Ga4MemberSet *set)
{
    ts4_u32 off;
    for (off = 0; off < 16; off += 4) {
        struct Ga4Member *m = *(struct Ga4Member **)((char *)set->members + off);
        if (m)
            fn_88692468(m->pb8, m->pc0, m->p74, m->ctx->clock->value, 1);
    }
}

/* ------------------------------------------------------------------ */
/* 12-byte handle passed by value (docs/agents/codegen-idioms.md, triple-arg idiom). */
struct Ga4Triple { ts4_u32 first, second, third; };
extern int *fn_88923530(ts4_u32 owner, struct Ga4Triple handle, ts4_u32 type_id);
extern void fn_8892EE88(void *record, struct Ga4Triple handle, int flag);
extern void *ts4_if_call_seq_fn_8892EE88_8817F5E0(void *record, struct Ga4Triple handle);

struct Ga4Binder { ts4_u8 pad_00[8]; void *bound; /* +0x08 */ };

/* Look up the record of type 0xA4FFC421 for `handle` (record base = self-relative offset), register `target`
   with it and store the resulting binding at +0x08. Swing_DLL.xex 0x886B25B8 */
void ga4_bind_record_886B25B8(struct Ga4Binder *self, struct Ga4Triple handle, int unused_r6,
                              struct Ga4Triple *target)
{
    int *rec;
    char *base;
    struct Ga4Triple t;
    (void)unused_r6;
    rec = fn_88923530(handle.third, handle, 0xA4FFC421u);
    base = (char *)rec + *rec;
    t = *target;
    fn_8892EE88(base, t, 1);
    self->bound = ts4_if_call_seq_fn_8892EE88_8817F5E0(base, t);
}

/* ------------------------------------------------------------------ */
extern void fn_886AE528(void *self, __vector4 *out);
struct Ga4PosInner { ts4_u8 pad_00[0x84]; __vector4 *pos; /* +0x84 */ };
struct Ga4PosHost { struct Ga4PosInner *inner; };

/* Copy the position vector (inner+0x84) into `out`, then run the swing planner step on it.
   Swing_DLL.xex 0x886AFC78 */
void ga4_load_position_886AFC78(struct Ga4PosHost *self, __vector4 *out)
{
    *out = *self->inner->pos;
    fn_886AE528(self, out);
}

/* ------------------------------------------------------------------ */
extern void fn_8869DC38(void *self, __vector4 pos);

struct Ga4TimedSlot {
    float pos[4];           /* +0x00 vector (stored with stvx128) */
    ts4_u32 expire;         /* +0x10 clock + delay */
    ts4_u8 active;          /* +0x14 */
};
struct Ga4DelayCfg { ts4_u8 pad_00[0x18C]; ts4_u32 delay; };
struct Ga4TimedHost {
    ts4_u8 pad_00[0x48];
    struct Ga4Clock30 *ctx;             /* +0x48 */
    ts4_u8 pad_4c[0x2C];
    struct Ga4DelayCfg *cfg;            /* +0x78 */
    ts4_u8 pad_7c[8];
    struct Ga4TimedSlot *slot;          /* +0x84 */
};

/* Arm the timed slot once: clear the +0x91 byte, mark it active, set its expiry to now + delay and store
   the vector argument into it, then continue with the vector. Swing_DLL.xex 0x886A5BB0 */
void ga4_arm_timed_slot_886A5BB0(struct Ga4TimedHost *self, __vector4 pos)
{
    struct Ga4DelayCfg *cfg;
    ts4_u32 delay;
    if (self->slot->active)
        return;
    cfg = self->cfg;
    *((ts4_u8 *)self + 0x91) = 0;
    delay = cfg->delay;
    self->slot->active = 1;
    self->slot->expire = self->ctx->clock->value + delay;
    *(__vector4 *)self->slot = pos;
    fn_8869DC38(self, pos);
}

/* ------------------------------------------------------------------ */
/* Base part at +0x38: own vtable plus three elements starting at +0x0C. */
struct Ga4BasePart {
    void *vtbl;
    ts4_u8 pad_04[8];
    struct Ga4Element elem[3];
};

/* Object with a four-element array at +0x158, a base part at +0x38 and a secondary vtable at +0x28. */
struct Ga4MultiPart {
    void *vtbl;                 /* +0x00 */
    ts4_u8 pad_04[0x24];
    void *vtbl_28;              /* +0x28 secondary vtable */
    ts4_u8 pad_2c[0xC];
    struct Ga4BasePart base;    /* +0x38 */
    ts4_u8 pad_[0x158 - 0x38 - sizeof(struct Ga4BasePart)];
    struct Ga4Element elem[4];  /* +0x158 */
};

static void ga4_base_part_dtor(struct Ga4BasePart *b)
{
    b->vtbl = &lbl_880F4BCC;
    fn_8890F1E8(&b->elem[2]);
    fn_8890F1E8(&b->elem[1]);
    fn_8890F1E8(&b->elem[0]);
}

/* Destroy the four elements (back to front), then the base part, and reset the secondary vtable.
   Swing_DLL.xex 0x886A3A38 */
void ga4_multipart_dtor_886A3A38(struct Ga4MultiPart *self)
{
    self->vtbl = &lbl_880F46F0;
    fn_8890F1E8(&self->elem[3]);
    fn_8890F1E8(&self->elem[2]);
    fn_8890F1E8(&self->elem[1]);
    fn_8890F1E8(&self->elem[0]);
    ga4_base_part_dtor(&self->base);
    self->vtbl_28 = &lbl_880D6B70;
}

/* ------------------------------------------------------------------ */
extern struct Ga4Quad fn_88660690(void *widget);

/* For each occupied member slot whose widget has a non-empty range, run the update and copy the widget's
   16-byte result into the member's result block. Swing_DLL.xex 0x8869EFC8 */
void ga4_update_members_with_result_8869EFC8(struct Ga4MemberSet *set)
{
    ts4_u32 off;
    for (off = 0; off < 16; off += 4) {
        struct Ga4Member *m = *(struct Ga4Member **)((char *)set->members + off);
        if (m) {
            struct Ga4Range *r = m->widget->range;
            if (r->begin != r->end) {
                struct Ga4Quad *dst;
                fn_88692468(m->widget, m->pc4, m->p74, m->ctx->clock->value, 1);
                dst = m->result;
                *dst = fn_88660690(m->widget);
            }
        }
    }
}
