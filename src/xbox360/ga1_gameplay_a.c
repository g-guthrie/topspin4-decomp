/*
 * GA1: gameplay helpers, window 0x88640150..0x886600E0 (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Layouts are read from the machine code; unknown regions are padding.
 */
typedef unsigned int ts4_u32;
typedef unsigned char ts4_u8;

/* Self-relative array header: byte offset from this header to the first element, then a count. */
struct Ga1RelArray {
    int offset;
    ts4_u32 count;
};

/* ---- 0x8865E588: base-class destructor step that deletes an owned child ---- */
struct Ga1VObject {
    void **vtbl;
};
struct Ga1OwnerOfChild {
    const void *vtbl;
    char pad_04[0x14];
    struct Ga1VObject *child;
};
extern char lbl_880F4464[];

/* Resets the vtable to the base class and, when a child is owned, calls its scalar-deleting
   destructor (vtable slot 0, flag 1). Swing_DLL.xex 0x8865E588 */
void ts4_owner_release_child_8865E588(struct Ga1OwnerOfChild *self)
{
    struct Ga1VObject *child = self->child;
    self->vtbl = lbl_880F4464;
    if (child != 0)
        ((void (*)(struct Ga1VObject *, int))child->vtbl[0])(child, 1);
}

/* ---- 0x8864AFF8: semaphore release wrapper ---- */
struct Ga1HandleBox {
    void *handle;
};
extern int ts4_if_call_seq_NtReleaseSemaphore_8857C040(void *handle, int count, int *previous);

/* Releases one count on the semaphore; returns -1 when NtReleaseSemaphore returned 0, else 0.
   Swing_DLL.xex 0x8864AFF8 */
int ts4_semaphore_release_result_8864AFF8(struct Ga1HandleBox **box)
{
    int previous;
    return ts4_if_call_seq_NtReleaseSemaphore_8857C040((*box)->handle, 1, &previous) == 0 ? -1 : 0;
}

/* ---- 0x8865BFC0: clear a self-relative array of 8-byte entries ---- */
struct Ga1Pair {
    int a;
    int b;
};
struct Ga1Block170 {
    char pad_00[0x170];
    struct Ga1RelArray entries;
};
struct Ga1Holder28 {
    char pad_00[0x28];
    struct Ga1Block170 *block;
};

/* Zeroes every {a, b} entry of the array at block+0x170. Swing_DLL.xex 0x8865BFC0 */
void ts4_clear_pair_array_8865BFC0(struct Ga1Holder28 *self)
{
    struct Ga1RelArray *array = &self->block->entries;
    ts4_u32 count = array->count;
    ts4_u32 i;
    for (i = 0; i < count; i++) {
        struct Ga1Pair *entry = (struct Ga1Pair *)((char *)array + array->offset + i * 8);
        entry->a = 0;
        entry->b = 0;
    }
}

/* ---- 0x88645528: address of element n-1 (0x94 bytes each) of a doubly self-relative array ---- */
struct Ga1Holder1C {
    char pad_00[0x1c];
    int *header;
};

/* Follows two self-relative offsets from the header and returns the address of element n-1.
   Swing_DLL.xex 0x88645528 */
char *ts4_rel_element_prev_88645528(struct Ga1Holder1C *self, int n)
{
    char *header = (char *)self->header;
    char *level1 = header + *(int *)header;
    char *level2 = level1 + *(int *)level1;
    return level2 + n * 0x94 - 0x94;
}

/* ---- 0x8865A228: any listed entity with its flag set ---- */
struct Ga1Flag {
    ts4_u8 value;
};
struct Ga1Entity {
    char pad_00[0x40];
    struct Ga1Flag *flag;
};
struct Ga1EntityList {
    char pad_00[0x10];
    struct Ga1Entity **begin;
    struct Ga1Entity **end;
};

/* True when any non-null entity in the list has flag->value != 0. Swing_DLL.xex 0x8865A228 */
ts4_u32 ts4_any_entity_flag_set_8865A228(struct Ga1EntityList *list)
{
    struct Ga1Entity **end = list->end;
    struct Ga1Entity **it = list->begin;
    ts4_u32 result = 0;
    for (; it != end; it++) {
        if (*it && (*it)->flag->value) {
            result = 1;
            break;
        }
    }
    return result;
}

/* ---- 0x8865EB60 ---- */
struct Ga1Slot32A {
    char pad_00[0xa8];
    int current;
    char pad_ac[0x32a - 0xac];
    ts4_u8 active;
};
struct Ga1Link30 {
    char pad_00[0x30];
    struct Ga1Slot32A *slot;
};
struct Ga1TargetB8 {
    char pad_00[0xb8];
    int id;
};
struct Ga1Link24 {
    char pad_00[0x24];
    struct Ga1TargetB8 *target;
    int current;
};
struct Ga1Query {
    char pad_00[0x18];
    int wanted_id;
    char pad_1c[0x48 - 0x1c];
    struct Ga1Link30 *owner;
    struct Ga1Link24 *link;
};

/* True when the owner's slot is active, differs from the link's current one, and the link's
   target id equals wanted_id. Swing_DLL.xex 0x8865EB60 */
ts4_u32 ts4_query_slot_matches_target_8865EB60(struct Ga1Query *q)
{
    struct Ga1Slot32A *slot = q->owner->slot;
    if (slot->active != 0 && slot->current != q->link->current && q->link->target->id == q->wanted_id)
        return 1;
    return 0;
}

/* ---- 0x8865D6A0 ---- */
struct Ga1Flags470 {
    char pad_00[0x470];
    ts4_u8 flag[4];
};
struct Ga1State74 {
    char pad_00[0x74];
    struct Ga1Flags470 *flags;
};
struct Ga1Holder1C74 {
    char pad_00[0x1c];
    struct Ga1State74 *state;
};

/* True when any of the four flag bytes at +0x470 is set. Swing_DLL.xex 0x8865D6A0 */
ts4_u32 ts4_any_flag470_set_8865D6A0(struct Ga1Holder1C74 *self)
{
    struct Ga1Flags470 *f = self->state->flags;
    return f->flag[0] || f->flag[1] || f->flag[2] || f->flag[3];
}

/* ---- 0x88659658 ---- */
/* Maps a small tier index (1..3) to 15/30/40; other values (and skip != 0) pass through.
   Swing_DLL.xex 0x88659658 */
int ts4_tier_to_value_88659658(int tier, ts4_u8 skip)
{
    if (!skip && tier != 0) {
        switch (tier) {
        case 1: return 15;
        case 2: return 30;
        case 3: return 40;
        }
    }
    return tier;
}

/* ---- 0x88660098 ---- */
struct Ga1Range {
    int lo;
    int hi;
    int pad;
};
struct Ga1Item {
    char pad_00[0x28];
    int kind;
    int pad_2c;
};
struct Ga1ItemPool {
    char pad_00[0x5a0];
    struct Ga1Item *first;
    struct Ga1Item *last;
};

/* Index of item within the pool (items are 0x30 bytes) relative to the range of its kind:
   *out_from_lo = index - lo, *out_to_hi = hi - index. Swing_DLL.xex 0x88660098 */
void ts4_item_range_offsets_88660098(struct Ga1ItemPool *pool, struct Ga1Item *item, int *out_from_lo,
                                     int *out_to_hi)
{
    int index = (int)(item - pool->first);
    struct Ga1Range *range = (struct Ga1Range *)((char *)pool + (item->kind + 0x79) * 12);
    int lo = range->lo;
    int hi = range->hi;
    *out_from_lo = index - lo;
    *out_to_hi = hi - index;
}

/* ---- 0x8865E6A8 ---- */
struct Ga1Mode360 {
    char pad_00[0x360];
    ts4_u32 mode;
};
struct Ga1State74B {
    char pad_00[0x74];
    struct Ga1Mode360 *mode;
};
struct Ga1Out1AC {
    char pad_00[0x1ac];
    float value;
};
struct Ga1Ctx8 {
    char pad_00[8];
    struct Ga1State74B *state;
    char pad_0c[0x28 - 0xc];
    struct Ga1Out1AC *out;
};
struct Ga1Holder1C8 {
    char pad_00[0x1c];
    struct Ga1Ctx8 *ctx;
};

/* Stores 1.0f when the mode id is 0x1A944E2E or 0x1EB396F9, else 0.0f. Swing_DLL.xex 0x8865E6A8 */
void ts4_store_mode_flag_8865E6A8(struct Ga1Holder1C8 *self)
{
    struct Ga1Ctx8 *ctx = self->ctx;
    ts4_u32 mode = ctx->state->mode->mode;
    ts4_u8 flag = (mode == 0x1A944E2Eu || mode == 0x1EB396F9u);
    ctx->out->value = (float)flag;
}

/* ---- 0x8865E330 ---- */
struct Ga1CrcList {
    char pad_00[0x24];
    struct Ga1RelArray ids;
};

static ts4_u32 *ga1_rel_u32_array(struct Ga1RelArray *a)
{
    return (ts4_u32 *)((char *)a + a->offset);
}

/* Scans the self-relative id array from the end for 0x71198650; returns that index minus one,
   or -1 when absent. Swing_DLL.xex 0x8865E330 */
int ts4_find_last_id_prev_8865E330(struct Ga1CrcList *self)
{
    int i = (int)self->ids.count - 1;
    int result = -1;
    for (; i >= 0; i--) {
        if (ga1_rel_u32_array(&self->ids)[i] == 0x71198650u) {
            result = i - 1;
            break;
        }
    }
    return result;
}

/* ---- 0x88655628, 0x886575F0: forward to the object held by the global at +0x220 ---- */
struct Ga1VCallObject {
    void **vtbl;
};
struct Ga1System {
    char pad_00[0x220];
    struct Ga1VCallObject *object;
};
struct Ga1Fallback {
    char pad_00[0x1c];
    int active;
};
extern struct Ga1System *lbl_88D45B1C;
extern struct Ga1Fallback *lbl_88D45B2C;
ts4_u32 fn_8861AD70(ts4_u32 a, struct Ga1VCallObject *object, ts4_u32 b, struct Ga1Fallback *fallback);

/* When *use_primary is set, tail-calls vtable slot 0x44 of the system's object; otherwise calls
   slot 0x44 of the fallback object when one exists, else returns 0. Swing_DLL.xex 0x88655628 */
ts4_u32 ts4_forward_vcall_44_88655628(ts4_u8 *use_primary)
{
    ts4_u32 result = 0;
    if (*use_primary) {
        struct Ga1VCallObject *o = lbl_88D45B1C->object;
        return ((ts4_u32(*)(struct Ga1VCallObject *))o->vtbl[0x44 / 4])(o);
    } else if (lbl_88D45B2C != 0) {
        struct Ga1VCallObject *o = (struct Ga1VCallObject *)lbl_88D45B2C;
        result = ((ts4_u32(*)(struct Ga1VCallObject *))o->vtbl[0x44 / 4])(o);
    }
    return result;
}

/* Same dispatch for slot 0x4C with two forwarded arguments (and -1); the fallback path runs
   fn_8861AD70 when the fallback is active. Swing_DLL.xex 0x886575F0 */
ts4_u32 ts4_forward_vcall_4c_886575F0(ts4_u8 *use_primary, ts4_u32 a, ts4_u32 b)
{
    ts4_u32 result = 0;
    if (*use_primary) {
        struct Ga1VCallObject *o = lbl_88D45B1C->object;
        return ((ts4_u32(*)(struct Ga1VCallObject *, ts4_u32, ts4_u32, int))o->vtbl[0x4c / 4])(o, a, b, -1);
    } else {
        struct Ga1Fallback *g = lbl_88D45B2C;
        if (g != 0 && g->active != 0)
            result = fn_8861AD70(a, lbl_88D45B1C->object, b, g);
    }
    return result;
}

/* ---- 0x8865FF90: first record whose flagged object is set ---- */
struct Ga1Record {
    int unused_00;
    int slot;
    int pad_08[3];
};
struct Ga1RecordTable {
    char pad_00[0x2c];
    struct Ga1RelArray records;
};
struct Ga1RecordOwner {
    char pad_00[0x20];
    struct Ga1RecordTable *table;
};
struct Ga1FlagObject {
    ts4_u8 flag;
};
struct Ga1FlagPool {
    struct Ga1FlagObject **objects;
};

/* Index of the first record (0x14 bytes each) whose slot refers to an object with flag != 0,
   or -1. Swing_DLL.xex 0x8865FF90 */
int ts4_first_record_with_flag_8865FF90(struct Ga1RecordOwner *owner, struct Ga1FlagPool *pool)
{
    struct Ga1RecordTable *t = owner->table;
    int result = -1;
    int i;
    int n = (int)t->records.count;
    for (i = 0; i < n; i++) {
        struct Ga1RelArray *a = &t->records;
        struct Ga1FlagObject **objects = pool->objects;
        struct Ga1Record *r = (struct Ga1Record *)((char *)a + a->offset + i * 0x14);
        if (objects[r->slot]->flag != 0) {
            result = i;
            break;
        }
    }
    return result;
}

/* ---- 0x88657BF0: binary search in a sorted table of {key, back-relative value} ---- */
struct Ga1SortedEntry {
    ts4_u32 key;
    int back_rel;
};
struct Ga1SortedTable {
    int offset;
    int count;
};
struct Ga1SortedOwner {
    char pad_00[0xac];
    struct Ga1SortedTable *table;
};

/* Looks key up with a binary search; on a hit with a non-zero back offset stores the word that
   lies back_rel bytes before the offset field and returns 1. Swing_DLL.xex 0x88657BF0 */
ts4_u32 ts4_sorted_lookup_88657BF0(struct Ga1SortedOwner *owner, ts4_u32 key, ts4_u32 *out)
{
    struct Ga1SortedTable *t = owner->table;
    int lo = 0;
    int hi = t->count - 1;
    while (lo <= hi) {
        int off = t->offset;
        int mid = (hi + lo) / 2;
        struct Ga1SortedEntry *e = (struct Ga1SortedEntry *)((char *)t + (off + mid * 8));
        if (e->key == key) {
            int *p = &e->back_rel;
            if (*p == 0)
                return 0;
            *out = *(ts4_u32 *)((char *)p - *p);
            return 1;
        }
        if (e->key < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return 0;
}

/* ---- 0x886565E0..0x88656AC0: indexed accessors on a data block behind a virtual interface ----
 * The object embeds an interface at +0x1c. Slot 0x30 says whether data is available; slot 0x48
 * (read) / 0x4c (write) returns the data block, which holds self-relative arrays of u8 (+0x18),
 * u16 (+0x24), u32 (+0x30) and float (+0x3c). Access is refused while the lock word at +0x78 is
 * non-zero (getters/setters below require it to be 0). */
struct Ga1Iface {
    void **vtbl;
};
struct Ga1DataBlock {
    char pad_00[0x18];
    struct Ga1RelArray bytes;
    char pad_20[4];
    struct Ga1RelArray halves;
    char pad_2c[4];
    struct Ga1RelArray words;
    char pad_38[4];
    struct Ga1RelArray floats;
};
struct Ga1DataOwner {
    char pad_00[0x1c];
    struct Ga1Iface iface;
    char pad_20[0x78 - 0x20];
    ts4_u32 lock;
};
typedef ts4_u8 (*Ga1ReadyFn)(struct Ga1Iface *);
typedef struct Ga1DataBlock *(*Ga1DataFn)(struct Ga1Iface *, int);
typedef unsigned short ts4_u16;

/* Word at index idx of the u32 array, or 0. Swing_DLL.xex 0x886565E0 */
ts4_u32 ts4_data_get_word_886565E0(struct Ga1DataOwner *self, ts4_u32 idx)
{
    struct Ga1Iface *s = &self->iface;
    ts4_u32 result = 0;
    if (((Ga1ReadyFn)s->vtbl[0x30 / 4])(s) && self->lock == 0) {
        struct Ga1RelArray *r = &((Ga1DataFn)s->vtbl[0x48 / 4])(s, 0)->words;
        if (idx < r->count)
            result = *(ts4_u32 *)((char *)r + r->offset + idx * 4);
    }
    return result;
}

/* Halfword at index idx of the u16 array, or 0. Swing_DLL.xex 0x88656678 */
ts4_u32 ts4_data_get_half_88656678(struct Ga1DataOwner *self, ts4_u32 idx)
{
    struct Ga1Iface *s = &self->iface;
    ts4_u32 result = 0;
    if (((Ga1ReadyFn)s->vtbl[0x30 / 4])(s) && self->lock == 0) {
        struct Ga1RelArray *r = &((Ga1DataFn)s->vtbl[0x48 / 4])(s, 0)->halves;
        if (idx < r->count)
            result = *(ts4_u16 *)((char *)r + r->offset + idx * 2);
    }
    return result;
}

/* Byte at index idx of the u8 array, or 0; the lock word must equal expected_lock.
   Swing_DLL.xex 0x88656710 */
ts4_u32 ts4_data_get_byte_88656710(struct Ga1DataOwner *self, ts4_u32 idx, ts4_u32 expected_lock)
{
    struct Ga1Iface *s = &self->iface;
    ts4_u32 result = 0;
    if (((Ga1ReadyFn)s->vtbl[0x30 / 4])(s) && self->lock == expected_lock) {
        struct Ga1RelArray *r = &((Ga1DataFn)s->vtbl[0x48 / 4])(s, 0)->bytes;
        if (idx < r->count)
            result = *((ts4_u8 *)r + r->offset + idx);
    }
    return result;
}

/* Stores float v at index idx of the float array. Swing_DLL.xex 0x886569A8 */
void ts4_data_set_float_886569A8(struct Ga1DataOwner *self, ts4_u32 idx, float v)
{
    struct Ga1Iface *s = &self->iface;
    if (((Ga1ReadyFn)s->vtbl[0x30 / 4])(s) && self->lock == 0) {
        struct Ga1RelArray *r = &((Ga1DataFn)s->vtbl[0x4c / 4])(s, 0)->floats;
        if (idx < r->count)
            *(float *)((char *)r + r->offset + idx * 4) = v;
    }
}

/* Stores halfword v at index idx of the u16 array. Swing_DLL.xex 0x88656A38 */
void ts4_data_set_half_88656A38(struct Ga1DataOwner *self, ts4_u32 idx, ts4_u16 v)
{
    struct Ga1Iface *s = &self->iface;
    if (((Ga1ReadyFn)s->vtbl[0x30 / 4])(s) && self->lock == 0) {
        struct Ga1RelArray *r = &((Ga1DataFn)s->vtbl[0x4c / 4])(s, 0)->halves;
        if (idx < r->count)
            *(ts4_u16 *)((char *)r + r->offset + idx * 2) = v;
    }
}

/* Stores byte v at index idx of the u8 array. Swing_DLL.xex 0x88656AC0 */
void ts4_data_set_byte_88656AC0(struct Ga1DataOwner *self, ts4_u32 idx, ts4_u8 v)
{
    struct Ga1Iface *s = &self->iface;
    if (((Ga1ReadyFn)s->vtbl[0x30 / 4])(s) && self->lock == 0) {
        struct Ga1RelArray *r = &((Ga1DataFn)s->vtbl[0x4c / 4])(s, 0)->bytes;
        if (idx < r->count)
            *((ts4_u8 *)r + r->offset + idx) = v;
    }
}

/* ---- 0x88646318: append a zeroed 0x1c-byte element ---- */
struct Ga1Element1C {
    ts4_u32 head;
    char body[0x18];
};
struct Ga1ElementVector {
    int pad_00;
    struct Ga1Element1C *end;
    struct Ga1Element1C *capacity_end;
};
extern void fn_882788C0(struct Ga1ElementVector *vec, struct Ga1Element1C *at);
extern void *ts4_memset(void *dst, int value, ts4_u32 size);

/* Grows the vector when full, zero-constructs one element at the end and returns it.
   Swing_DLL.xex 0x88646318 */
struct Ga1Element1C *ts4_element_vector_emplace_zeroed_88646318(struct Ga1ElementVector *vec)
{
    struct Ga1Element1C *end = vec->end;
    struct Ga1Element1C *e;
    if (end == vec->capacity_end)
        fn_882788C0(vec, end);
    e = vec->end;
    if (e != 0) {
        e->head = 0;
        ts4_memset(e->body, 0, 0x18);
    }
    vec->end = vec->end + 1;
    return vec->end - 1;
}

/* ---- 0x88657920: AND of the validity of all items under an interface lock ---- */
struct Ga1LockItem {
    char pad_00[8];
    void *data;
};
struct Ga1LockedSet {
    char pad_00[0x21];
    ts4_u8 enabled;
    char pad_22[2];
    struct Ga1Iface lock;
    char pad_28[0x44 - 0x28];
    struct Ga1LockItem **begin;
    struct Ga1LockItem **end;
};
extern ts4_u8 ts4_flush_queue_88655BC8(void *data);

/* Under the interface lock (slot 1 enter, slot 2 leave), ANDs the result of ts4_flush_queue_88655BC8 over
   every item's data; returns 0 immediately when not enabled. Swing_DLL.xex 0x88657920 */
ts4_u8 ts4_all_items_valid_88657920(struct Ga1LockedSet *set)
{
    struct Ga1Iface *lock;
    ts4_u8 ok;
    struct Ga1LockItem **it;
    struct Ga1LockItem **end;
    if (!set->enabled)
        return 0;
    lock = &set->lock;
    ((void (*)(struct Ga1Iface *))lock->vtbl[1])(lock);
    ok = 1;
    end = set->end;
    for (it = set->begin; it != end; it++)
        ok = ts4_flush_queue_88655BC8((*it)->data) & ok;
    ((void (*)(struct Ga1Iface *))lock->vtbl[2])(lock);
    return ok;
}

/* Adds amount to the u16 at index idx, saturating at 0xFFFF; the lock word must equal
   expected_lock. Swing_DLL.xex 0x88656848 */
void ts4_data_add_half_saturating_88656848(struct Ga1DataOwner *self, ts4_u32 idx, ts4_u16 amount,
                                           ts4_u32 expected_lock)
{
    struct Ga1Iface *s = &self->iface;
    if (((Ga1ReadyFn)s->vtbl[0x30 / 4])(s) && self->lock == expected_lock) {
        struct Ga1RelArray *r = &((Ga1DataFn)s->vtbl[0x4c / 4])(s, 0)->halves;
        if (idx < r->count) {
            ts4_u16 *p = (ts4_u16 *)((char *)r + r->offset + idx * 2);
            int current = *p;
            if (0xFFFF - current >= (int)amount)
                *p = (ts4_u16)(current + amount);
            else
                *p = 0xFFFF;
        }
    }
}

/* ---- 0x88649C88: re-initialise a block and set a flag-dependent scale ---- */
extern float g_ts4_script_constants[];
extern void ts4_if_call_seq_u32_off28_88648740(void *block);
extern void ts4_if_get_u32_off0_88647668(void *block, ts4_u32 a, ts4_u32 b, ts4_u32 c);
extern void fn_88649348(void *dst, void *src);

struct Ga1FlagScale {
    char pad_00[0x18];
    ts4_u8 flag;
    char pad_19[3];
    float scale;
    char pad_20[0x70 - 0x20];
    char block_70[0x30];
    char block_a0[8];
    ts4_u32 field_a8;
};

/* Resets block_70, fills block_a0 from the arguments, merges them, then stores the flag and a
   scale taken from the script constant table (+0x38 when the flag is set, +0 otherwise).
   Swing_DLL.xex 0x88649C88 */
void ts4_init_flag_scale_88649C88(struct Ga1FlagScale *self, ts4_u32 a, ts4_u32 b, ts4_u8 flag)
{
    ts4_if_call_seq_u32_off28_88648740(self->block_70);
    ts4_if_get_u32_off0_88647668(self->block_a0, a, self->field_a8, b);
    fn_88649348(self->block_70, self->block_a0);
    self->flag = flag;
    if (flag)
        self->scale = g_ts4_script_constants[0x38 / 4];
    else
        self->scale = g_ts4_script_constants[0];
}

/* ---- 0x8864C040: build a record in a zeroed 0x80-byte buffer and register it ---- */
extern char lbl_880D1EE0[];
struct Ga1Record80 {
    unsigned long long q[16];
};
struct Ga1Registry {
    int pad_00;
};
struct Ga1Registrar {
    char pad_00[0x94];
    struct Ga1Registry *registry;
    char text_98[0x18];
    char pad_b0[0x1b0 - 0xb0];
    char block_1b0[8];
};
struct Ga1RegistrarSource {
    char pad_00[0x1c];
    ts4_u32 value_1c;
    char pad_20[0x3c - 0x20];
    ts4_u32 value_3c;
    char pad_40[0x61 - 0x40];
    char text_61[8];
};
extern void fn_885635D0(struct Ga1Record80 *out, char *format, char *a, char *b);
extern void fn_8864D668(struct Ga1Registry *registry, struct Ga1Record80 *record);
extern void fn_8864DCA0(struct Ga1Registry *registry, char *block);
extern void ts4_if_call_seq_u32_off0_8864D5D0(struct Ga1Registry *registry, ts4_u32 a, ts4_u32 b);

/* Formats a record from two text fields, registers it and its block, then forwards two values
   from the source; always returns 0. Swing_DLL.xex 0x8864C040 */
ts4_u32 ts4_registrar_submit_8864C040(struct Ga1Registrar *self, struct Ga1RegistrarSource *src)
{
    struct Ga1Record80 record;
    int i;
    for (i = 0; i < 16; i++)
        record.q[i] = 0;
    fn_885635D0(&record, lbl_880D1EE0, self->text_98, (char *)src + 0x61);
    fn_8864D668(self->registry, &record);
    fn_8864DCA0(self->registry, self->block_1b0);
    ts4_if_call_seq_u32_off0_8864D5D0(self->registry, src->value_3c, src->value_1c);
    return 0;
}

/* ---- 0x8865E828: add a reference to a keyed entry ---- */
struct Ga1RefEntry {
    ts4_u32 unused_00;
    int refs;
    ts4_u32 key;
    struct Ga1VCallObject *object;
};
struct Ga1RefTable {
    char pad_00[0xc];
    struct Ga1RefEntry *begin;
    struct Ga1RefEntry *end;
};

/* Finds the entry whose key equals *key; when it has an object, calls vtable slot 0x34 on the
   first reference, then increments the reference count. Swing_DLL.xex 0x8865E828 */
void ts4_ref_table_acquire_8865E828(struct Ga1RefTable *table, ts4_u32 *key)
{
    struct Ga1RefEntry *it;
    ts4_u32 k = *key;
    struct Ga1RefEntry *end = table->end;
    for (it = table->begin; it != end; it++) {
        if (it->key == k) {
            if (it->object != 0) {
                struct Ga1VCallObject *o = it->object;
                if (it->refs == 0)
                    ((void (*)(struct Ga1VCallObject *))o->vtbl[0x34 / 4])(o);
                it->refs = it->refs + 1;
            }
            return;
        }
    }
}

/* ---- 0x8865AE10: classic serve, toss started by a stroke button ----
 * PlayerState.InputState.Serve.Classic (docs/gameplay/controls-and-shot-selection.md): +0x480 Throw,
 * +0x482 ThrowFlat, +0x483 ThrowSlice, +0x484 ThrowTopSpin; +0x4B5 is Serve.Advanced.Throw. */
struct Ga1ServeState {
    char pad_000[0x480];
    ts4_u8 throw_any;
    ts4_u8 pad_481;
    ts4_u8 throw_flat;
    ts4_u8 throw_slice;
    ts4_u8 throw_topspin;
    char pad_485[0x4b5 - 0x485];
    ts4_u8 advanced_throw;
};
struct Ga1ServeWorld {
    char pad_00[0x74];
    struct Ga1ServeState *player;
};
struct Ga1ServeContext {
    char pad_00[8];
    struct Ga1ServeWorld *world;
};
struct Ga1ServeButtons {
    ts4_u8 pad_00;
    ts4_u8 toss_latched;
    ts4_u8 pad_02[3];
    ts4_u8 flat;
    ts4_u8 slice;
    ts4_u8 topspin;
};
struct Ga1ServeStroke {
    char pad_00[8];
    int stroke; /* 1 flat, 2 slice, 3 topspin */
};
struct Ga1ServeToss {
    char pad_00[0x1c];
    struct Ga1ServeContext *context;
    struct Ga1ServeButtons *buttons;
    char pad_24[0x28 - 0x24];
    struct Ga1ServeStroke *stroke;
};

/* Raises the ThrowFlat/Slice/TopSpin level of the chosen stroke plus the generic Throw level,
   clears the advanced-serve throw, and latches the toss when that stroke's button is held.
   Swing_DLL.xex 0x8865AE10 */
void ts4_serve_classic_toss_start_8865AE10(struct Ga1ServeToss *self)
{
    ts4_u8 pressed = 0;
    struct Ga1ServeButtons *buttons = self->buttons;
    switch (self->stroke->stroke) {
    case 1:
        pressed = buttons->flat;
        self->context->world->player->throw_flat = 1;
        break;
    case 2:
        pressed = buttons->slice;
        self->context->world->player->throw_slice = 1;
        break;
    case 3:
        pressed = buttons->topspin;
        self->context->world->player->throw_topspin = 1;
        break;
    }
    self->context->world->player->throw_any = 1;
    self->context->world->player->advanced_throw = 0;
    if (pressed)
        buttons->toss_latched = 1;
}

/* ---- 0x8864DB28: run the handler of an active state and stamp the time ---- */
typedef unsigned long long ts4_u64;
struct Ga1TimedState {
    char pad_00[4];
    int state;
    char pad_08[0x130 - 8];
    ts4_u64 stamp;
};
extern ts4_u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);
extern ts4_u8 ts4_if_call_seq_u32_off28_8864D3B8(struct Ga1TimedState *self);
extern ts4_u8 fn_8864D828(struct Ga1TimedState *self);

/* For states 2 and 3 runs the matching handler; returns -1 when it fails, otherwise stores
   the KeTimeStampBundle value at +0x130 and returns 0 (also 0 for every other state).
   Swing_DLL.xex 0x8864DB28 */
int ts4_timed_state_step_8864DB28(struct Ga1TimedState *self)
{
    int st = self->state;
    ts4_u8 active = (st == 2 || st == 3);
    if (active) {
        ts4_u8 ok = 0;
        switch (st) {
        case 2:
            ok = fn_8864D828(self);
            break;
        case 3:
            ok = ts4_if_call_seq_u32_off28_8864D3B8(self);
            break;
        }
        if (!ok)
            return -1;
        self->stamp = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    }
    return 0;
}

/* ---- 0x88649778: look up a pair of table values, loading the table on demand ---- */
struct Ga1PairTable {
    char pad_00[8];
    ts4_u32 *first;
    char pad_0c[4];
    ts4_u32 *second;
};
struct Ga1TableRecord {
    ts4_u32 unused_00;
    ts4_u32 count;
    ts4_u32 unused_08;
    struct Ga1PairTable *table;
};
struct Ga1RecordIndex {
    char pad_00[0x6c];
    struct Ga1RelArray records;
};
struct Ga1RecordIndexOwner {
    char pad_00[8];
    struct Ga1RecordIndex *index;
};
struct Ga1RecordLookup {
    char pad_00[0xa8];
    struct Ga1RecordIndexOwner *owner;
};
struct Ga1RecordKey {
    short record;
    short entry;
};
extern void *lbl_88D45AF0;
extern void ga6_run_while_type012_886D79D8(void *manager, struct Ga1TableRecord *record);

/* Finds the 16-byte record named by key->record in the index at +0x6c; when it has entries and
   its table is loaded (ga6_run_while_type012_886D79D8 loads it on demand) writes table->first[key->entry] and
   table->second[key->entry] and returns 1, else 0. Swing_DLL.xex 0x88649778 */
ts4_u32 ts4_record_table_lookup_88649778(struct Ga1RecordLookup *self, struct Ga1RecordKey *key,
                                         ts4_u32 *out_first, ts4_u32 *out_second)
{
    ts4_u32 ok = 0;
    struct Ga1RelArray *a = (struct Ga1RelArray *)((char *)self->owner->index + 0x6c);
    struct Ga1TableRecord *r = (struct Ga1TableRecord *)((char *)a + (key->record * 16 + a->offset));
    if (r->count > 0) {
        struct Ga1PairTable *t = r->table;
        if (t == 0) {
            ga6_run_while_type012_886D79D8(lbl_88D45AF0, r);
            t = r->table;
        }
        if (t != 0) {
            int i = key->entry;
            ts4_u32 x = t->first[i];
            ts4_u32 y = t->second[i];
            *out_first = x;
            *out_second = y;
            ok = 1;
        }
    }
    return ok;
}
