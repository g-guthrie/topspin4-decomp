/* GA5: small gameplay-side helpers in 0x886C3xxx..0x886C8xxx (animation/clip table queries and
 * simple container walks). Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 * Field names are roles read from machine code; offsets are in the comments. */

typedef struct Ga5IdRecord {          /* element of an id-keyed pointer vector */
    char pad00[0x78];
    unsigned id;                      /* +0x78 */
} Ga5IdRecord;

typedef struct Ga5IdRecordList {      /* std::vector-like range of Ga5IdRecord* */
    char pad00[0x5c];
    Ga5IdRecord **first;              /* +0x5c */
    Ga5IdRecord **last;               /* +0x60 */
} Ga5IdRecordList;

typedef struct Ga5ListOwner {
    char pad00[0x20];
    Ga5IdRecordList *records;         /* +0x20 */
} Ga5ListOwner;

typedef struct Ga5ValueMsg {
    char pad00[0x38];
    float value;                      /* +0x38 */
    char pad3c[0x58 - 0x3c];
    unsigned id;                      /* +0x58 */
} Ga5ValueMsg;

typedef struct Ga5PtrVec {            /* header + begin/end of a pointer vector at +4/+8 */
    char pad00[4];
    Ga5IdRecord **first;              /* +4 */
    Ga5IdRecord **last;               /* +8 */
} Ga5PtrVec;

typedef struct Ga5KeyedPairVec {      /* 8-byte {key, value} pairs in a vector at +0x5c/+0x60 */
    char pad00[0x5c];
    unsigned *first;                  /* +0x5c */
    unsigned *last;                   /* +0x60 */
} Ga5KeyedPairVec;

/* Swing_DLL.xex 0x886C34C0: index of the first entry of values[0..count) that is >= *key, or -1. */
int ts4_find_first_not_less_886C34C0(const unsigned *key, const unsigned *values, int count)
{
    const unsigned *end = values + count;
    unsigned limit = *key;
    int result = -1;
    const unsigned *p;
    int i = 0;
    for (p = values; p != end; ++p, ++i) {
        if (*p >= limit) {
            result = i;
            break;
        }
    }
    return result;
}

/* Swing_DLL.xex 0x886C4690: true when both 32-bit masks (+8 and +0xC) of a and b overlap. */
int ts4_masks_overlap_886C4690(const unsigned *a, const unsigned *b)
{
    if ((a[2] & b[2]) != 0) {
        int yes = 1;
        if (a[3] & b[3])
            return yes;
    }
    return 0;
}

/* Swing_DLL.xex 0x886C47F8: first record in the pointer vector whose id (+0x78) equals the argument, or NULL. */
Ga5IdRecord *ts4_find_record_by_id_886C47F8(Ga5PtrVec *vec, unsigned id)
{
    Ga5IdRecord *found = 0;
    Ga5IdRecord **p;
    for (p = vec->first; p != vec->last; p++) {
        if ((*p)->id == id) {
            found = *p;
            break;
        }
    }
    return found;
}

/* Swing_DLL.xex 0x886C4BC8: find the record matching msg->id in the owner's record list and copy msg->value
 * into its float at +0x4C. */
void ts4_set_record_value_by_id_886C4BC8(Ga5ListOwner *self, Ga5ValueMsg *msg)
{
    Ga5IdRecordList *list = self->records;
    Ga5IdRecord **p = list->first;
    Ga5IdRecord **end = list->last;
    for (; p != end; p++) {
        if ((*p)->id == msg->id) {
            char *record = (char *)*p;
            if (record)
                *(float *)(record + 0x4c) = msg->value;
            return;
        }
    }
}

/* Swing_DLL.xex 0x886C51A0: value of the {key, value} pair whose key equals *key (pairs at +0x5C..+0x60), or 0. */
unsigned ts4_find_pair_value_by_key_886C51A0(Ga5KeyedPairVec *self, const unsigned *key)
{
    unsigned *p = self->first;
    unsigned *end = self->last;
    for (; end != p; p += 2) {
        if (p[0] == *key)
            return p[1];
    }
    return 0;
}

/* Swing_DLL.xex 0x886C8728: address of row `row` in a table whose header is at o+0x84: base + offset-to-data
 * (stored at +0x84) + row * stride(+0xC) * 4. */
char *ts4_table_row_886C8728(char *self, int row)
{
    char *owner = *(char **)(self + 0xc);
    char *base = owner + 0x84;
    return base + *(int *)base + 4 * (*(int *)(owner + 0xc) * row);
}

typedef struct Ga5BlendLink {         /* two int fields at +0x24/+0x28 cleared together */
    char pad00[0x24];
    int a;                            /* +0x24 */
    int b;                            /* +0x28 */
} Ga5BlendLink;

typedef struct Ga5BlendPair {         /* at owner->+0x28 + 0x3f0 */
    char pad00[0x30];
    Ga5BlendLink *link0;              /* +0x30 */
    Ga5BlendLink *link1;              /* +0x34 */
} Ga5BlendPair;

typedef struct Ga5BlendOwner {
    char pad00[0x28];
    char *base;                       /* +0x28 */
} Ga5BlendOwner;

/* Swing_DLL.xex 0x886C5020: clear the two int fields (+0x24, +0x28) of both link records of the blend pair. */
void ts4_clear_blend_links_886C5020(Ga5BlendOwner *self)
{
    Ga5BlendPair *pair = (Ga5BlendPair *)(self->base + 0x3f0);
    pair->link0->a = 0;
    pair->link0->b = 0;
    pair->link1->a = 0;
    pair->link1->b = 0;
}

typedef struct Ga5ByteLookup {        /* 8-byte {key, byte*} pairs at +0x2c..+0x30 */
    char pad00[0x2c];
    unsigned *first;                  /* +0x2c */
    unsigned *last;                   /* +0x30 */
} Ga5ByteLookup;

/* Swing_DLL.xex 0x886C4360: first byte flag stored for *key in the pair vector, 0 when absent. */
unsigned char ts4_lookup_byte_by_key_886C4360(Ga5ByteLookup *self, const unsigned *key)
{
    unsigned char result = 0;
    unsigned *p;
    for (p = self->first; p != self->last; p += 2) {
        if (p[0] == *key) {
            result = *(unsigned char *)(unsigned long)p[1];
            break;
        }
    }
    return result;
}

typedef struct Ga5IntTable {
    char pad00[0x14c];
    int *values;                      /* +0x14c */
    int pad150;
    int count;                        /* +0x154 */
} Ga5IntTable;

typedef struct Ga5IntTableOwner {
    char pad00[0x1c];
    Ga5IntTable *table;               /* +0x1c */
} Ga5IntTableOwner;

/* Swing_DLL.xex 0x886C4F70: zero every entry of the owner's int table. */
void ts4_clear_int_table_886C4F70(Ga5IntTableOwner *self)
{
    int i;
    for (i = 0; i < self->table->count; i++)
        self->table->values[i] = 0;
}

/* Swing_DLL.xex 0x886C43B0: 4-entry table of {value, key} u16 pairs; value for the entry whose key matches, else -1. */
int ts4_lookup_u16_pair4_by_key_886C43B0(const unsigned short *pairs, unsigned key)
{
    int result = -1;
    if (pairs[1] == key)
        result = pairs[0];
    else if (pairs[3] == key)
        result = pairs[2];
    else if (pairs[5] == key)
        result = pairs[4];
    else if (pairs[7] == key)
        result = pairs[6];
    return result;
}

typedef struct Ga5AnimStack {         /* animation layer owner: records vector at +0x5c */
    char pad00[0x5c];
    Ga5IdRecord **records;            /* +0x5c */
} Ga5AnimStack;

extern int fn_886C66C0(void *self);   /* index of the layer to query, or -1 */

/* Swing_DLL.xex 0x886CB618: id (+0x78) of the record chosen by fn_886C66C0, or -1 when there is none. */
int ts4_selected_record_id_886CB618(Ga5AnimStack *self)
{
    int result = -1;
    int index;
    index = fn_886C66C0(self);
    if (index != -1) {
        Ga5IdRecord **records = self->records;
        result = (int)records[index]->id;
    }
    return result;
}

extern float lbl_8814B440;            /* 0.0f */
extern float ts4_ramp_weight_886CAEC0(void *self, void *clip);

/* Swing_DLL.xex 0x886CAF78: evaluate clip via ts4_ramp_weight_886CAEC0 when the clip's data word (+0x84) is set, else 0.0f. */
float ts4_eval_clip_if_loaded_886CAF78(void *self, char *clip)
{
    if (*(unsigned *)(clip + 0x84) != 0)
        return ts4_ramp_weight_886CAEC0(self, clip);
    return lbl_8814B440;
}

extern void ts4_tsu_cleanup_end(void *object);

/* Swing_DLL.xex 0x886CA428: drop the owned object at +0x54 (clear its back link at +0x74, destroy it) and
 * clear the owner's bookkeeping words at +0x50/+0x54/+0x58/+0x5C. */
void ts4_release_owned_object_886CA428(char *self)
{
    char *owned = *(char **)(self + 0x54);
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x5c) = 0;
    if ((long)owned != 0) {
        *(int *)(owned + 0x74) = 0;
        ts4_tsu_cleanup_end(owned);
        *(int *)(self + 0x54) = 0;
    }
    *(int *)(self + 0x50) = 0;
}

extern void ts4_loop_call_seq_u32_off18_886A0350(void *slot, void *ctx);
extern void fn_88691980(void *self, void *ctx);
extern void fn_886B6050(void *self);

/* Swing_DLL.xex 0x886B61D0: bind the context (+0x18, and its +0x48 word into +0x1C), run the per-slot
 * binder over the ten 0x41C-byte slots starting at +0x34, then rebind the sub-object at +0x20 and finish. */
void ts4_bind_slots_to_context_886B61D0(char *self, char *ctx)
{
    char *slot = self + 0x34;
    int remaining;
    *(char **)(self + 0x18) = ctx;
    *(int *)(self + 0x1c) = *(int *)(ctx + 0x48);
    for (remaining = 10; remaining != 0; remaining--) {
        ts4_loop_call_seq_u32_off18_886A0350(slot, ctx);
        slot += 0x41c;
    }
    fn_88691980(self + 0x20, ctx);
    fn_886B6050(self);
}

typedef struct Ga5LayerDesc {         /* inner record: id at +8 */
    char pad00[8];
    unsigned id;                      /* +0x08 */
} Ga5LayerDesc;

typedef struct Ga5Layer {             /* element of the layer stack */
    char pad00[4];
    Ga5LayerDesc *desc;               /* +0x04 */
    char pad08[0x24 - 8];
    float time;                       /* +0x24 */
} Ga5Layer;

typedef struct Ga5LayerStack {
    char pad00[0x18];
    float limit;                      /* +0x18 */
    char pad1c[0x5c - 0x1c];
    Ga5Layer **first;                 /* +0x5c */
    Ga5Layer **last;                  /* +0x60 */
} Ga5LayerStack;

/* Swing_DLL.xex 0x886C45E8: walking the stack from the top, count the consecutive layers whose descriptor id
 * equals `id` and whose time (+0x24) is later than the stack's limit (+0x18). */
int ts4_count_top_layers_with_id_after_limit_886C45E8(Ga5LayerStack *self, unsigned id)
{
    int count = 0;
    Ga5Layer **begin = self->first;
    Ga5Layer **p = self->last;
    while (p != begin) {
        Ga5Layer *layer = *(p - 1);
        if (layer->desc->id != id)
            return count;
        if (self->limit >= layer->time)
            return count;
        count++;
        p--;
    }
    return count;
}

typedef struct Ga5SlotEntry {         /* identified by id at +8 */
    char pad00[8];
    unsigned id;                      /* +0x08 */
} Ga5SlotEntry;

typedef struct Ga5SlotLink {          /* back-reference holder: index into the owner's slot array at +0x14 */
    char pad00[0x14];
    int index;                        /* +0x14 */
} Ga5SlotLink;

typedef struct Ga5SlotTable {
    Ga5SlotEntry **first;             /* +0x00 */
    Ga5SlotEntry **last;              /* +0x04 */
    char pad08[4];
    Ga5SlotLink **slots;              /* +0x0C parallel array: one link pointer per entry */
} Ga5SlotTable;

/* Swing_DLL.xex 0x886C3FE0: find the entry with the given id; when found, bind `link` to its slot (flag != 0:
 * store the link and remember the entry index in it) or unbind it (flag == 0: clear the slot and the index). */
void ts4_bind_slot_link_by_id_886C3FE0(Ga5SlotTable *self, unsigned id, Ga5SlotLink *link, unsigned char bind)
{
    Ga5SlotEntry **begin = self->first;
    Ga5SlotEntry **end = self->last;
    Ga5SlotEntry **p;
    for (p = begin; p != end; p++) {
        if (id == (*p)->id)
            break;
    }
    if (p == end)
        return;
    {
        int index = (int)(p - begin);
        if (bind) {
            self->slots[index] = link;
            link->index = index;
        } else {
            self->slots[index] = 0;
            link->index = 0;
        }
    }
}

/* Relative array header used by the animation data blocks: `off` is the byte offset from the header to the
 * first element (-1 = no array) and `count` the element count. Writing the begin and end computations as two
 * separate guarded assignments (end = 0 set between them) reproduces the original branch layout. */
typedef struct Ga5RelArray {
    int off;                          /* +0x00 byte offset to elements, -1 when absent */
    int count;                        /* +0x04 */
} Ga5RelArray;

typedef struct Ga5Rec16 {             /* 16-byte element */
    int w0, w1, w2, w3;
} Ga5Rec16;

extern unsigned char fn_886C5E18(Ga5Rec16 *rec, void *a, void *b);

/* Swing_DLL.xex 0x886C6098: first 16-byte element for which fn_886C5E18(rec, a, b) is true; end pointer if none. */
Ga5Rec16 *ts4_find_rec16_if_886C6098(Ga5RelArray *self, void *a, void *b)
{
    Ga5Rec16 *begin = 0;
    Ga5Rec16 *end;
    Ga5Rec16 *p;
    if (self->off != -1)
        begin = (Ga5Rec16 *)((char *)self + self->off);
    end = 0;
    if (self->off != -1)
        end = (Ga5Rec16 *)((char *)self + self->off + self->count * 16);
    for (p = begin; p != end; p++) {
        if (fn_886C5E18(p, a, b))
            break;
    }
    return p;
}

/* Swing_DLL.xex 0x886C5CB0: index of `*key` in a relative array of u32 values, or -1. */
int ts4_rel_u32_index_of_886C5CB0(Ga5RelArray *self, const unsigned *key)
{
    int result = -1;
    unsigned *begin = 0;
    unsigned *end;
    unsigned *p;
    if (self->off != -1)
        begin = (unsigned *)((char *)self + self->off);
    end = 0;
    if (self->off != -1)
        end = (unsigned *)((char *)self + self->off + self->count * 4);
    for (p = begin; p != end; p++) {
        if (*p == *key) {
            result = (int)(p - begin);
            break;
        }
    }
    return result;
}

typedef struct Ga5Rec8C {             /* 0x8C-byte element (animation record) */
    char pad00[0x1c];
    unsigned key_b;                   /* +0x1C */
    char pad20[0x84 - 0x20];
    unsigned key_a;                   /* +0x84 */
    int value88;                      /* +0x88 */
} Ga5Rec8C;

typedef struct Ga5Rec8CBlock {
    char pad00[0xc];
    char *data;                       /* +0x0C block data; the relative array header is at +0x50 */
} Ga5Rec8CBlock;

typedef struct Ga5Rec8COwner {
    char pad00[0x48];
    Ga5Rec8CBlock *block;             /* +0x48 */
} Ga5Rec8COwner;

/* Swing_DLL.xex 0x886C8438: element of the 0x8C-byte relative array (header block->data+0x50) whose +0x84
 * equals `key_a` and whose +0x1C equals `key_b`; NULL when none. */
Ga5Rec8C *ts4_find_rec8c_by_keys_886C8438(Ga5Rec8COwner *self, unsigned key_a, unsigned key_b)
{
    Ga5RelArray *rel = (Ga5RelArray *)(self->block->data + 0x50);
    Ga5Rec8C *result = 0;
    Ga5Rec8C *begin = 0;
    Ga5Rec8C *end;
    Ga5Rec8C *p;
    if (rel->off != -1)
        begin = (Ga5Rec8C *)((char *)rel + rel->off);
    end = 0;
    if (rel->off != -1)
        end = (Ga5Rec8C *)((char *)rel + rel->off + rel->count * 0x8c);
    for (p = begin; p != end; p++) {
        if (p->key_a == key_a && p->key_b == key_b) {
            result = p;
            break;
        }
    }
    return result;
}

typedef struct Ga5DataRef {
    char pad00[8];
    char *data;                       /* +0x08 block data; the relative array header is at +0x50 */
} Ga5DataRef;

typedef struct Ga5DataRefOwner {
    char pad00[0x1c];
    Ga5DataRef *ref;                  /* +0x1C */
} Ga5DataRefOwner;

/* Swing_DLL.xex 0x886C50D0: clear the +0x88 word of every 0x8C-byte element of the owner's relative array. */
void ts4_clear_rec8c_values_886C50D0(Ga5DataRefOwner *self)
{
    Ga5RelArray *rel = (Ga5RelArray *)(self->ref->data + 0x50);
    Ga5Rec8C *begin = 0;
    Ga5Rec8C *end;
    Ga5Rec8C *p;
    if (rel->off != -1)
        begin = (Ga5Rec8C *)((char *)rel + rel->off);
    end = 0;
    if (rel->off != -1)
        end = (Ga5Rec8C *)((char *)rel + rel->off + rel->count * 0x8c);
    for (p = begin; p != end; p++)
        p->value88 = 0;
}

typedef struct Ga5Rec80 {             /* 0x80-byte element with a 32-bit handle at +0x44 */
    char pad00[0x44];
    unsigned handle;                  /* +0x44 */
    char pad48[0x80 - 0x48];
} Ga5Rec80;

typedef struct Ga5Rec80Data {
    char pad00[0x14];
    char *data;                       /* +0x14 block data; relative array headers at +0x490 and +0x49C */
} Ga5Rec80Data;

typedef struct Ga5Rec80Owner {
    char pad00[0x14];
    int active;                       /* +0x14 */
    int pending;                      /* +0x18 */
    Ga5Rec80Data *ref;                /* +0x1C */
} Ga5Rec80Owner;

/* Swing_DLL.xex 0x886C6E18: release handles. In the array at data+0x49C, clear each element's handle until the
 * first element whose handle is already 0; then clear every handle of the array at data+0x490; reset the
 * owner's active/pending words (+0x14/+0x18). */
void ts4_release_rec80_handles_886C6E18(Ga5Rec80Owner *self)
{
    Ga5RelArray *rel = (Ga5RelArray *)(self->ref->data + 0x49c);
    Ga5Rec80 *begin = 0;
    Ga5Rec80 *end;
    Ga5Rec80 *p;
    if (rel->off != -1)
        begin = (Ga5Rec80 *)((char *)rel + rel->off);
    end = 0;
    if (rel->off != -1)
        end = (Ga5Rec80 *)((char *)rel + rel->off + rel->count * 0x80);
    for (p = begin; p != end; p++) {
        if (p->handle == 0)
            break;
        p->handle = 0;
    }
    rel = (Ga5RelArray *)(self->ref->data + 0x490);
    begin = 0;
    if (rel->off != -1)
        begin = (Ga5Rec80 *)((char *)rel + rel->off);
    end = 0;
    if (rel->off != -1)
        end = (Ga5Rec80 *)((char *)rel + rel->off + rel->count * 0x80);
    for (p = begin; p != end; p++)
        p->handle = 0;
    self->active = 0;
    self->pending = 0;
}
