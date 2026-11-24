/* Small glue accessors: a list-front handle copy, a slot activation check and
 * a map lookup. Matched byte-exact on the LTCG route (/Oc); context is
 * fk_024.c (callee ts4_call_seq_fn_881A84E8_88871928) plus the pool primer. */

typedef unsigned int ts4_u32;
typedef unsigned char ts4_u8;

/* ---- 0x88923380: copy the handle of the first list element ---- */

struct TS4GlueHandle {
    ts4_u32 obj; /* +0x0 */
    ts4_u32 id;  /* +0x4 0xFFFFF when empty */
    ts4_u32 x;   /* +0x8 */
    TS4GlueHandle() { obj = 0; x = 0; id = 0xFFFFF; }
};
struct TS4GlueHandleElem {
    ts4_u32 key;          /* +0x0 */
    TS4GlueHandle handle; /* +0x4 */
};
struct TS4GlueHandleList {
    TS4GlueHandleElem *first;
    TS4GlueHandleElem *last;
};
/* Passing the list pointer to helpers at each use gives the target's clrrwi copy. */
static inline bool ts4_glue_list_empty(const TS4GlueHandleList *l) { return l->first == l->last; }
static inline TS4GlueHandleElem *ts4_glue_list_front(const TS4GlueHandleList *l) { return l->first; }
struct TS4GlueHandleSource {
    ts4_u32 f0;
    TS4GlueHandleList *list; /* +0x4 */
    ts4_u32 f8;
    ts4_u32 enabled;         /* +0xC */
};

extern "C" TS4GlueHandle ts4_glue_front_handle_88923380(const TS4GlueHandleSource *s)
{
    TS4GlueHandle h;
    if (s->enabled != 0 && s->list != 0 && !ts4_glue_list_empty(s->list))
        h = ts4_glue_list_front(s->list)->handle;
    return h;
}

/* ---- 0x888719E0: run the slot callback when slot idx is active ---- */

struct TS4GlueSlot84 {
    ts4_u8 pad0[0x54];
    ts4_u8 active; /* +0x54 */
    ts4_u8 pad55[0x84 - 0x55];
};
struct TS4GlueSlotVec {
    TS4GlueSlot84 *first;
    TS4GlueSlot84 *last;
    ts4_u32 size() const { return last - first; }
    TS4GlueSlot84 &operator[](ts4_u32 i) { return first[i]; }
};
struct TS4GlueSlotOwner {
    ts4_u8 pad0[0x84];
    TS4GlueSlotVec slots; /* +0x84 */
};

/* ts4_word in fk_024.c: a pointer-sized word on the target. */
typedef unsigned long ts4_glue_uptr;
extern "C" ts4_glue_uptr ts4_call_seq_fn_881A84E8_88871928(ts4_glue_uptr a0, ts4_glue_uptr a1);

extern "C" int ts4_glue_slot_activate_888719E0(TS4GlueSlotOwner *o, ts4_u32 idx)
{
    if (idx < o->slots.size() && o->slots[idx].active) {
        ts4_call_seq_fn_881A84E8_88871928((ts4_glue_uptr)o, (ts4_glue_uptr)&o->slots[idx]);
        return 1;
    }
    return 0;
}

/* ---- 0x88941B30: map<u32, void *> lookup at +0x44, 0 when absent ---- */

struct TS4GlueMapKey { ts4_u32 v; };
struct TS4GlueMapNode {
    ts4_u32 color;
    TS4GlueMapNode *parent;
    TS4GlueMapNode *left;
    TS4GlueMapNode *right;
    TS4GlueMapKey key; /* +0x10 */
    void *value;       /* +0x14 */
};
/* The key copy decouples the load order from the compare order. */
static inline bool ts4_glue_key_less(const ts4_u32 &k, const TS4GlueMapNode *y)
{
    TS4GlueMapKey yk = y->key;
    return k < yk.v;
}
struct TS4GlueMap {
    TS4GlueMapNode *header;
    TS4GlueMapNode *find(const ts4_u32 &k) const
    {
        TS4GlueMapNode *y = header;
        TS4GlueMapNode *x = header->parent;
        while (x != 0) {
            if (!(x->key.v < k)) {
                y = x;
                x = x->left;
            } else {
                x = x->right;
            }
        }
        if (y == header || ts4_glue_key_less(k, y))
            y = header;
        return y;
    }
    TS4GlueMapNode *end() const { return header; }
};
struct TS4GlueMapOwner {
    ts4_u8 pad0[0x44];
    TS4GlueMap map; /* +0x44 */
};

extern "C" void *ts4_glue_map_lookup_88941B30(TS4GlueMapOwner *o, const ts4_u32 *key)
{
    TS4GlueMapNode *it = o->map.find(*key);
    if (o->map.end() != it)
        return it->value;
    return 0;
}
