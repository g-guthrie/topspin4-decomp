/* GA3: small gameplay helpers (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "ga3_types.h"

/* Ring of 10 slots (stride 0x41C, base +0x34); first/count at +8/+0xC. */
struct Ga3Ring {
    int unk_00[2];
    int first;   /* +0x08 */
    int count;   /* +0x0C */
    unsigned char pad[0x24];
    unsigned char slots[10][0x41C];
};
void fn_88691548(struct Ga3Ring *self, void *slot);

/* Processes the most recently added slot of the ring: (first + count - 1) mod 10. */
void ga3_ring_process_last_88691758(struct Ga3Ring *self)
{
    unsigned int idx = (unsigned int)(self->count + self->first - 1) % 10u;
    fn_88691548(self, self->slots[idx]);
}

void ts4_object_finalize(void *p);
void ts4_delete_all_8865A348(void *p);
void fn_8867C350(void *p);

/* Tears down the 10-slot pool: finalizes the member at +0x294C, the one at +0x20, then each slot. */
void ga3_pool_destroy_88691798(unsigned char *self)
{
    int i;
    unsigned char *slot;
    ts4_object_finalize(self + 0x294C);
    ts4_delete_all_8865A348(self + 0x20);
    slot = self + 0x34;
    for (i = 10; i != 0; i--) {
        fn_8867C350(slot);
        slot += 0x41C;
    }
}

/* Entry list (self-relative array of {id, value}) attached at +0x640 of the block at object+0x74. */
extern float lbl_8814B910;   /* 0.5f */
struct Ga3IdValue { unsigned id; float value; };
struct Ga3Block640 { unsigned char pad[0x640]; struct Ga3RelArr list; };
struct Ga3Obj74 { unsigned char pad[0x74]; struct Ga3Block640 *block; };

GA3_INLINE struct Ga3IdValue *ga3_list_end(struct Ga3RelArr *a)
{
    struct Ga3IdValue *r = 0;
    if (a->offset != -1) r = (struct Ga3IdValue *)((char *)a + (a->count * 8 + a->offset));
    return r;
}
GA3_INLINE struct Ga3IdValue *ga3_list_begin(struct Ga3RelArr *a)
{
    struct Ga3IdValue *r = 0;
    if (a->offset != -1) r = (struct Ga3IdValue *)((char *)a + a->offset);
    return r;
}
GA3_INLINE struct Ga3RelArr *ga3_list_of(struct Ga3Obj74 *o) { return &o->block->list; }

/* True when the list holds an entry for *key whose value is above 0.5 (0.5 - value has its sign bit set). */
int ga3_has_entry_above_half_8868F0D8(struct Ga3Obj74 *self, unsigned *key)
{
    int found = 0;
    struct Ga3IdValue *end = ga3_list_end(ga3_list_of(self));
    struct Ga3IdValue *e = ga3_list_begin(ga3_list_of(self));
    for (; e != end; e++) {
        if (e->id == *key) {
            float d = lbl_8814B910 - e->value;
            if (*(unsigned short *)&d & 0x8000) { found = 1; break; }
        }
    }
    return found;
}

/* ---- calls that pass a name hash ---- */
void ts4_call_seq_u32_off0_88683D78(void *self, struct Ga3Id id, unsigned int a, unsigned int b,
                                    int c, int d, float f1);

/* Forwards (a, b, f1) to ts4_call_seq_u32_off0_88683D78 under the fixed name hash 0x6023F2AF. */
void ga3_call_with_hash_6023F2AF_88683DF0(void *self, unsigned int a, unsigned int b, float f1)
{
    struct Ga3Id id = {0x6023F2AFu};
    ts4_call_seq_u32_off0_88683D78(self, id, a, b, -1, 0, f1);
}

struct Ga3VtObj { void **vtbl; };
struct Ga3Sub8 { unsigned char pad_00[8]; struct Ga3VtObj *obj; };
struct Ga3Stats8C { unsigned char pad_00[0x8C]; unsigned int value; };
struct Ga3Obj6C {
    unsigned char pad_00[0x30];
    struct Ga3Stats8C *stats;   /* +0x30 */
    unsigned char pad_34[0x18];
    void *controller;           /* +0x4C */
    unsigned char pad_50[0x1C];
    struct Ga3Sub8 *source;     /* +0x6C */
};
void fn_88685060(void *controller, struct Ga3Id id, unsigned int arg);

/* Sends arg to the controller under hash 0x7110D0BB, then stores the source object's vtbl[8](arg) result in stats+0x8C. */
void ga3_apply_arg_8868F9C8(struct Ga3Obj6C *self, unsigned int arg)
{
    struct Ga3Id id = {0x7110D0BBu};
    struct Ga3VtObj *src;
    fn_88685060(self->controller, id, arg);
    src = self->source->obj;
    self->stats->value = ((unsigned int (*)(struct Ga3VtObj *, unsigned int))src->vtbl[8])(src, arg);
}
