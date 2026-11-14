/* Family LG1: builder that creates two keyed entries (region 0x886DAD28). Each entry is allocated by
 * fn_88265498, appended to a pointer vector (std::vector layout {first, last, end}; fn_8826B718 is the
 * grow-and-insert path), tagged with a kind hash by fn_886CF6B0, then seven 8-byte slots of the entry
 * are resolved by key hash through fn_886C8750 and stamped with that key. Finally a span described by
 * self-relative data at owner->source+0x14 is attached with fn_886D9B98. Hash meanings are unknown. */

#define LG1_INLINE __forceinline

typedef struct lg1_ptr_vector {
    void **first; /* +0x0 */
    void **last;  /* +0x4 */
    void **end;   /* +0x8 */
} lg1_ptr_vector;

typedef struct lg1_key_slot {
    int value;        /* +0x0 */
    unsigned int key; /* +0x4 */
} lg1_key_slot;

typedef struct lg1_entry {
    lg1_key_slot *slots; /* +0x0 */
} lg1_entry;

typedef struct lg1_key {
    unsigned int hash;
} lg1_key;

/* Self-relative reference to the span description; operator-> resolves it (C++ is needed: the inlined
 * operator calls are not merged, which the original code shows as two separate address additions). */
struct lg1_span_desc;
typedef struct lg1_rel_ref {
    int off;
    __forceinline lg1_span_desc *operator->() { return (lg1_span_desc *)((char *)this + off); }
} lg1_rel_ref;

typedef struct lg1_span_desc {
    char pad0[0x14];
    int begin;  /* +0x14 */
    int count;  /* +0x18 */
    char pad1c[0x18];
    int extra;  /* +0x34 */
} lg1_span_desc;

typedef struct lg1_source {
    char pad0[0x14];
    lg1_rel_ref span; /* +0x14 */
} lg1_source;

typedef struct lg1_builder {
    char pad0[0xC];
    lg1_source *source;  /* +0x0C */
    char pad10[0x78];
    lg1_ptr_vector entries; /* +0x88 */
} lg1_builder;

extern "C" {
lg1_entry *fn_88265498(void);
void fn_8826B718(lg1_ptr_vector *vector, void **where, lg1_entry **value, int count, int flag);
void fn_886CF6B0(lg1_entry *entry, unsigned int kind);
void fn_886C8750(lg1_builder *builder, lg1_key *key, lg1_key_slot *slot);
void fn_886D9B98(lg1_entry *entry, lg1_source *source, int begin, int end);
}

LG1_INLINE void lg1_resolve_slot(lg1_builder *builder, lg1_entry *entry, int index, unsigned int hash)
{
    lg1_key key;
    lg1_key_slot *slot;
    key.hash = hash;
    slot = &entry->slots[index];
    fn_886C8750(builder, &key, slot);
    slot->key = hash;
}

LG1_INLINE void lg1_add_entry(lg1_builder *builder, unsigned int kind)
{
    lg1_entry *entry = fn_88265498();
    lg1_ptr_vector *v = &builder->entries;
    int count;
    {
        lg1_entry *tmp = entry;
        if (v->last != v->end) {
            if (v->last != 0)
                *v->last = tmp;
            v->last++;
        } else {
            fn_8826B718(v, v->last, &tmp, 1, 1);
        }
    }
    fn_886CF6B0(entry, kind);
    lg1_resolve_slot(builder, entry, 0, 0xAD4BA1ABu);
    lg1_resolve_slot(builder, entry, 1, 0x96793E47u);
    lg1_resolve_slot(builder, entry, 2, 0x860F3051u);
    lg1_resolve_slot(builder, entry, 3, 0xE4DC7934u);
    lg1_resolve_slot(builder, entry, 4, 0x73FCA7F2u);
    lg1_resolve_slot(builder, entry, 5, 0xA906C730u);
    lg1_resolve_slot(builder, entry, 6, 0x80EC0B87u);
    {
        lg1_span_desc *d = builder->source->span.operator->();
        count = builder->source->span->extra + d->count;
        if (count != 0)
            fn_886D9B98(entry, builder->source, d->begin, d->begin + count);
    }
}

/* Create the two default entries (kinds 0xEEEC65F2 and 0xCC20BAEA). Swing_DLL.xex 0x886DB058 */
extern "C" void ts4_entry_builder_add_defaults_886DB058(lg1_builder *builder)
{
    lg1_add_entry(builder, 0xEEEC65F2u);
    lg1_add_entry(builder, 0xCC20BAEAu);
}
