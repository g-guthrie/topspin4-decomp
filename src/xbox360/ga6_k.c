/*
 * GA6: gameplay object lists, self-relative pointer setup and small loops.
 */
#include "ts4_vector.h"

typedef unsigned int ts4_word;

extern float g_ts4_script_constants[];
extern void *lbl_88D45B1C;

void ts4_tailcall_fn_88584548_8857AFE8(int arg);
void fn_886D2E78(void *self);
unsigned char ts4_none_kind_012_886C3D50(void *self);
void ts4_registry_dispatch_888860A0(void *buffer);
void fn_886CE170(void *owner, void *item, void *a, void *b, int c);
void fn_886D5028(void *obj, void *arg);
void fn_886CECE0(void *obj);
void ts4_boxes_minmax_886C9688(void *obj);
void ts4_r2_swing_ring_release_entry_886DC9C0(void *self, ts4_word item);

/* Global table of live object pointers; the count lives after the 0xC69 slots. */
struct Ga6ObjectTable {
    void *items[0x31A4 / 4];
    ts4_word count;            /* +0x31A4 */
};
extern struct Ga6ObjectTable lbl_88D42948;

/* Remove obj from the global table by moving the last entry into its slot. */

/* Copy each row of the source matrix array into the dest array twice (rows 0 and 1) and set the word at +0x30. */
struct Ga6Row {
    __vector4 v[3];
    ts4_word w30;              /* +0x30 */
    char pad_34[0xC];
};
struct Ga6RowSet {
    char pad_00[0x24];
    ts4_word tag;              /* +0x24 */
    char pad_28[8];
    char *src;                 /* +0x30 */
    char pad_34[0xC];
    char *dst;                 /* +0x40 */
    ts4_word count;            /* +0x44 */
};

/* Source record with self-relative pointers at +0x30 and +0x3C. */
struct Ga6RelSource {
    char pad_00[0x30];
    int rel_30;                /* +0x30 */
    ts4_word w34;              /* +0x34 */
    char pad_38[4];
    int rel_3c;                /* +0x3C */
    ts4_word w40;              /* +0x40 */
};
struct Ga6RelUser {
    char pad_00[0x20];
    struct Ga6RelSource *source; /* +0x20 */
    char pad_24[0xAC];
    char *ptr_d0;              /* +0xD0 */
    ts4_word w_d4;             /* +0xD4 */
    char *ptr_d8;              /* +0xD8 */
    ts4_word w_dc;             /* +0xDC */
};

/* ---- vector shrink, float interpolation, simple state refresh ---- */
struct Ga6PtrVec { ts4_word *begin; ts4_word *end; };
struct Ga6Ring {
    char pad_00[0x5C];
    struct Ga6PtrVec vec;      /* +0x5C */
};

/* Release trailing entries until only keep + 1 remain... (count - keep - 1 pops). */
void ga6_pop_back_n_886E22E8(struct Ga6Ring *self, int keep)
{
    int n = (int)(self->vec.end - self->vec.begin) - keep - 1;
    struct Ga6PtrVec *v = &self->vec;
    for (; n != 0; n--) {
        ts4_r2_swing_ring_release_entry_886DC9C0(self, self->vec.end[-1]);
        v->end = v->end - 1;
    }
}

struct Ga6Interp {
    ts4_word w00;
    float f04, f08;            /* +0x04, +0x08 */
    float f0c, f10;            /* +0x0C, +0x10 */
};
struct Ga6Inner14 { char pad_00[0x14]; float f14; };
struct Ga6Inner8 { char pad_00[8]; struct Ga6Inner14 *p08; };
struct Ga6Inner4 { char pad_00[4]; struct Ga6Inner8 *p04; };
struct Ga6InterpArg {
    char pad_00[4];
    struct Ga6Inner8 *inner;   /* +0x04 */
    char pad_08[0xC];
    float f14;                 /* +0x14 */
    char pad_18[0xC];
    float f24;                 /* +0x24 */
};
/* Store the two values, then blend each toward the pivot: out = (v - pivot) * (scale - base) + offset. */

struct Ga6Limit14 { char pad_00[0x14]; struct { char pad[0x3FC]; int limit; } *stats; };
struct Ga6Watcher {
    struct Ga6Limit14 *owner;  /* +0x00 */
    char pad_04[4];
    void *target;              /* +0x08 */
    char pad_0c[0x30];
    int last_limit;            /* +0x3C */
};
struct Ga6OwnerLink { char pad_00[0x30]; char link[1]; };
/* When the owner's limit changed, record it and refresh the target. */
void ga6_refresh_on_limit_change_886D7D08(struct Ga6Watcher *self)
{
    struct Ga6Limit14 *owner = self->owner;
    int limit = owner->stats->limit;
    if (limit != self->last_limit) {
        void *target;
        self->last_limit = limit;
        target = self->target;
        fn_886D5028(target, (char *)owner + 0x30);
        fn_886CECE0(target);
        ts4_boxes_minmax_886C9688(target);
    }
}

struct Ga6Buffers {
    char pad_00[4];
    void *buf_a;               /* +0x04 */
    ts4_word len_a;            /* +0x08 */
    void *buf_b;               /* +0x0C */
    ts4_word len_b;            /* +0x10 */
};
/* Free the two owned buffers (when present) and clear pointer/length. */
void ga6_free_buffers_886CF110(struct Ga6Buffers *self)
{
    if ((long)self->buf_a != 0) {
        ts4_registry_dispatch_888860A0(self->buf_a);
        self->buf_a = 0;
        self->len_a = 0;
    }
    if ((long)self->buf_b != 0) {
        ts4_registry_dispatch_888860A0(self->buf_b);
        self->buf_b = 0;
        self->len_b = 0;
    }
}

struct Ga6Counted2 { ts4_word pad_00; ts4_word count; };
struct Ga6Globals { char pad_00[0x27C]; ts4_word w27c; };

/* Take one more reference; the first reference runs fn_886CE170 with the global default. */
void ga6_add_reference_886D2AF0(void *owner, struct Ga6Counted2 *item)
{
    if (item->count == 0) {
        ts4_word a[2];
        ts4_word v = ((struct Ga6Globals *)lbl_88D45B1C)->w27c;
        a[0] = v;
        a[1] = v;
        fn_886CE170(owner, item, &a[1], &a[0], 0);
        return;
    }
    item->count = item->count + 1;
}

/* Run the type check loop: while ts4_none_kind_012_886C3D50 says not done (max 1000 times), idle-hook and step. */
void ga6_wait_loop_886D7970(void *self)
{
    int i;
    for (i = 0; i < 1000; i++) {
        if (ts4_none_kind_012_886C3D50(self))
            break;
        ts4_tailcall_fn_88584548_8857AFE8(1);
        fn_886D2E78(self);
    }
}
