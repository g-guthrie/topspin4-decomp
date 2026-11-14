/* GA5 part B: more gameplay-side helpers in 0x886B3xxx..0x886CExxx (animation/clip tables, small walkers).
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 * Field names are roles read from machine code; offsets are in the comments. */

extern void fn_886C8750(void *clip, void *key, void *slot);

/* Swing_DLL.xex 0x886C9A68: fill the 8-byte entry `index` of the table at *self through fn_886C8750, then store
 * the key word *key into the entry's second word (+4). */
void ts4_fill_table_entry_886C9A68(char **self, void *clip, int index, int *key)
{
    int *entry = (int *)(*self + index * 8);
    fn_886C8750(clip, key, entry);
    entry[1] = *key;
}

typedef struct Ga5TableRef { int off; } Ga5TableRef;          /* self-relative table: data at (this + off) */
typedef struct Ga5ClipSet { char pad00[0x10]; Ga5TableRef *table; } Ga5ClipSet;
typedef struct Ga5ClipWorld {
    char pad00[0x18];
    Ga5ClipSet *clips;                /* +0x18 */
    char pad1c[0x28c - 0x1c];
    int base_index;                   /* +0x28C */
    char pad290[0x555 - 0x290];
    unsigned char locked;             /* +0x555 */
} Ga5ClipWorld;
typedef struct Ga5ClipRef { char pad00[0x1c]; short index; } Ga5ClipRef;   /* +0x1C clip index */
typedef struct Ga5ClipBinder {
    char pad00[0x10];
    Ga5ClipRef *clip;                 /* +0x10 */
    char pad14[0x48 - 0x14];
    char *entry;                      /* +0x48 0x2C-byte table entry of the clip */
    char pad4c[0x50 - 0x4c];
    Ga5ClipWorld *world;              /* +0x50 */
    char pad54[0x60 - 0x54];
    unsigned char dirty60;            /* +0x60 */
    unsigned char dirty61;            /* +0x61 */
} Ga5ClipBinder;

/* Swing_DLL.xex 0x886C6048: bind a clip to the binder: when the world is not locked flag both dirty bytes,
 * remember the clip and point +0x48 at its 0x2C-byte table entry (base_index + clip index). */
void ts4_bind_clip_entry_886C6048(Ga5ClipBinder *self, Ga5ClipRef *clip)
{
    Ga5ClipWorld *world = self->world;
    Ga5TableRef *table;
    int index;
    if (world->locked == 0) {
        self->dirty61 = 1;
        self->dirty60 = 1;
    }
    index = clip->index + world->base_index;
    self->clip = clip;
    table = world->clips->table;
    self->entry = (index * 0x2c + table->off) + (char *)table;
}

typedef struct Ga5RelHdr { int off; int count; } Ga5RelHdr;     /* offset -1 = absent */
typedef struct Ga5HeaderOwner { char pad00[0x58]; Ga5RelHdr rel; } Ga5HeaderOwner;   /* relative array header at +0x58 */
typedef struct Ga5HeaderCursor {
    char pad00[4];
    char *cursor;                     /* +0x04 points just past the header (+0x5C) */
    Ga5HeaderOwner *owner;            /* +0x08 */
    unsigned char multi;              /* +0x0C set when the relative array holds more than one element */
} Ga5HeaderCursor;

/* Swing_DLL.xex 0x886C7230: start a cursor over the owner; `multi` is set when the +0x58 relative array exists
 * and its element count exceeds 1. */
void ts4_header_cursor_init_886C7230(Ga5HeaderCursor *self, Ga5HeaderOwner *owner)
{
    Ga5RelHdr *rel = &owner->rel;
    unsigned char present;
    self->owner = owner;
    self->cursor = (char *)owner + 0x5c;
    present = (unsigned)(rel->off + 1) != 0;
    self->multi = 0;
    if (present == 1) {
        Ga5RelHdr *array = (Ga5RelHdr *)(rel->off + (char *)rel);
        if ((unsigned)array->count > 1u)
            self->multi = 1;
    }
}

extern float g_ts4_script_constants[];
extern float lbl_8814B440;            /* 0.0f */
extern float fn_886CBEE8(void *self, float time);

typedef struct Ga5TimedClip {
    char pad00[0x14];
    float time_ratio;                 /* +0x14 */
    char pad18[0x80 - 0x18];
    unsigned kind_hash;               /* +0x80 clip kind hash */
} Ga5TimedClip;
typedef struct Ga5TimedClipRef { char pad00[8]; Ga5TimedClip *clip; } Ga5TimedClipRef;
typedef struct Ga5TimedPlayer {
    char pad00[4];
    Ga5TimedClipRef *ref;             /* +0x04 */
    char pad08[0x14 - 8];
    float rate;                       /* +0x14 */
    char pad18[0x48 - 0x18];
    float offset_a;                   /* +0x48 */
    float offset_b;                   /* +0x4C */
} Ga5TimedPlayer;

/* Swing_DLL.xex 0x886CBFF8: advance a time value by the clip's stretch term (ratio - 1) * rate. Clips of kind
 * 0xAD11D5A1 also reset both offsets to 0; kind 0x490B9918 continues in fn_886CBEE8 with the new time. */
float ts4_advance_clip_time_886CBFF8(Ga5TimedPlayer *self, float time)
{
    Ga5TimedClip *clip = self->ref->clip;
    float result = (clip->time_ratio - g_ts4_script_constants[0]) * self->rate + time;
    if (clip->kind_hash == 0xAD11D5A1) {
        float zero = lbl_8814B440;
        self->offset_b = zero;
        self->offset_a = zero;
        return result;
    }
    if (clip->kind_hash == 0x490B9918)
        return fn_886CBEE8(self, result);
    return result;
}

typedef struct Ga5GraphDomain { char pad00[0x8c]; int params; char pad90[0xd4 - 0x90]; int outputs; } Ga5GraphDomain;
typedef struct Ga5PlayerCtx {
    char pad00[0x44];
    Ga5GraphDomain *domain;           /* +0x44 */
    char pad48[0x74 - 0x48];
    char *state;                      /* +0x74 scorer inputs live at state+0x880 */
    char pad78[0x330 - 0x78];
    int inputs;                       /* +0x330 */
} Ga5PlayerCtx;
typedef struct Ga5Scorer {
    char pad00[4];
    char *inputs;                     /* +0x04 */
    char slots[1];                    /* +0x08 four 0x44-byte graph slots */
} Ga5Scorer;

extern void *ts4_graph_set_find_8866F028(Ga5GraphDomain *domain, const unsigned *name_hash);
extern void fn_88911668(void *slot, void *inputs, void *graph, void *params, void *outputs);

/* Swing_DLL.xex 0x886B6348: hit-point scorer, vtable slot 3: look each of the four graph name hashes up in the
 * player's graph domain and bind the graph found into slot i (this+8+i*0x44). */
void ts4_scorer_bind_graphs_886B6348(Ga5Scorer *self, const unsigned *hashes, Ga5PlayerCtx *ctx)
{
    const unsigned *hash = hashes;
    char *slot = self->slots;
    Ga5GraphDomain *domain;
    int remaining = 4;
    self->inputs = ctx->state + 0x880;
    domain = ctx->domain;
    do {
        void *graph = ts4_graph_set_find_8866F028(domain, hash);
        if (graph != 0)
            fn_88911668(slot, &ctx->inputs, graph, &domain->params, &domain->outputs);
        remaining--;
        hash++;
        slot += 0x44;
    } while (remaining != 0);
}

typedef struct Ga5RelRef { int off; int count; } Ga5RelRef;                 /* self-relative array header */
typedef struct Ga5RelItem { int off; int pad[9]; } Ga5RelItem;              /* 0x28-byte item; off -> {?, value} */
typedef struct Ga5CountBlock { char pad00[0x70]; Ga5RelRef rel; } Ga5CountBlock;   /* header at +0x70 */
typedef struct Ga5CountBlockList { Ga5CountBlock **first; Ga5CountBlock **last; } Ga5CountBlockList;

/* Swing_DLL.xex 0x886C85C0: totals over a list of blocks: *total_a = sum of each block's item count (+0x74),
 * *total_b = sum over the items of the value word reached through the item's relative offset (1 when the item
 * has no offset). */
void ts4_sum_block_item_counts_886C85C0(Ga5CountBlockList *self, int *total_a, int *total_b)
{
    Ga5CountBlock **end = self->last;
    Ga5CountBlock **it = self->first;
    int sum_a = 0;
    int sum_b = 0;
    for (; it != end; it++) {
        Ga5RelRef *rel = &(*it)->rel;
        Ga5RelItem *begin = 0;
        Ga5RelItem *stop = 0;
        Ga5RelItem *item;
        sum_a += rel->count;
        if (rel->off != -1)
            stop = (Ga5RelItem *)((char *)rel + rel->off + rel->count * 0x28);
        begin = 0;
        if (rel->off != -1)
            begin = (Ga5RelItem *)((char *)rel + rel->off);
        for (item = begin; item != stop; item++) {
            if (item->off != -1)
                sum_b += *(int *)((char *)item + item->off + 4);
            else
                sum_b += 1;
        }
    }
    *total_b = sum_b;
    *total_a = sum_a;
}

typedef struct Ga5RingSlot { char pad00[0x2d]; unsigned char complete; char pad2e[2]; } Ga5RingSlot;   /* 0x30 bytes */
typedef struct Ga5RingSrcA { char pad00[0x60]; void *target; } Ga5RingSrcA;
typedef struct Ga5RingSrcB { char pad00[0x30]; char *data; } Ga5RingSrcB;
typedef struct Ga5Ring {
    char pad00[0x10];
    int start;                        /* +0x10 index of the oldest slot */
    int count;                        /* +0x14 number of live slots */
    Ga5RingSrcA *source_a;            /* +0x18 */
    Ga5RingSrcB *source_b;            /* +0x1C */
    char pad20[0x5c - 0x20];
    Ga5RingSlot slots[20];            /* +0x5C 20-slot ring */
} Ga5Ring;

extern void fn_886E0780(void *target, void *input, void *slot);
extern void ts4_ring_trim_active_span_8865FEC0(Ga5Ring *ring);

/* Swing_DLL.xex 0x886B6230: fill the next free slot of the 20-entry ring ((start + count) % 20) through
 * fn_886E0780; a completed slot extends the live count; then trim the active span. */
void ts4_ring_push_slot_886B6230(Ga5Ring *self)
{
    int index = (self->start + self->count) % 20;
    Ga5RingSlot *slot = &self->slots[index];
    fn_886E0780(self->source_a->target, self->source_b->data + 0x28, slot);
    if (slot->complete)
        self->count++;
    ts4_ring_trim_active_span_8865FEC0(self);
}
