/* 0x886DCDC0 (hand match): for every 0x30-byte item of the relative-offset table, resolves its two
 * references against the given 12-byte key (passed by value), then looks up its record in the owner's registry. */
typedef struct Tag { int a, b, c; } Tag;
typedef struct Item { char p[0x10]; char key[4]; char ref_a[0xc]; char ref_b[0xc]; void *record; } Item;
typedef struct Rel { int offset; unsigned int count; } Rel;
typedef struct Registry { void *impl; } Registry;
typedef struct Mid { char p[0x94]; Registry *registry; } Mid;
typedef struct Obj { char p[0x2c]; Mid *mid; } Obj;
void fn_8892EE88(void *ref, Tag tag, int flag);
void *fn_88645A68(void *impl, void *key);
static __forceinline Item *ibegin(Rel *t) { Item *r = 0; if (t->offset != -1) r = (Item *)((char *)t + t->offset); return r; }
static __forceinline Item *iend(Rel *t) { Item *r = 0; if (t->offset != -1) r = (Item *)((char *)t + (t->count * 0x30 + t->offset)); return r; }
void ts4_resolve_table_items_886DCDC0(Obj *o, Tag tag, Rel *t)
{
    Item *end = iend(t);
    Item *it;
    for (it = ibegin(t); it != end; it++) {
        fn_8892EE88(it->ref_a, tag, 0);
        fn_8892EE88(it->ref_b, tag, 0);
        it->record = fn_88645A68(o->mid->registry->impl, it->key);
    }
}
