/* 0x886D2A08 (hand match): creates one named object through the owner's factory and appends a
 * (value, object) pair to the owner's list for every value in the source block. The object takes its
 * name from the source block, or the empty string when the block has none. */
typedef struct Named { char p[8]; int state; } Named;
typedef struct Pair { int value; Named *object; } Pair;
typedef struct Vec { void *first; Pair *end; Pair *cap; } Vec;
typedef struct Factory Factory;
typedef struct FactoryVt { void *s[11]; Named *(*create)(Factory *self); } FactoryVt;
struct Factory { FactoryVt *vt; };
typedef struct Obj { char p[0x5c]; Vec pairs; char p2[0x148 - 0x68]; Factory *factory; } Obj;
typedef struct Item { int value; int pad; } Item;
typedef struct Rel { volatile int offset; } Rel;
typedef struct Src { Rel items; int count; } Src;
extern char lbl_880C1320[];
static __forceinline Item *item_at(Rel *t, int index) { int off = t->offset; return (Item *)((char *)t + (index * 8 + off)); }
static __forceinline Item *item_at2(Rel *t, int index) { return (Item *)((char *)t + (index * 8 + t->offset)); }
void fn_882642E0(Vec *v, int n);
void fn_88648998(Named *n, const char *name);
void ts4_vector_grow_append_881784B0(Vec *v, Pair *at, Pair *value);
void ts4_append_value_pairs_886D2A08(Obj *o, Src *src)
{
    int n = src->count;
    Vec *v = &o->pairs;
    Named *obj;
    Rel *name;
    const char *s;
    int i;
    Pair p;
    fn_882642E0(v, n);
    obj = o->factory->vt->create(o->factory);
    name = (Rel *)((char *)src + src->items.offset + 4);
    { int off = name->offset; if (off != -1) s = (char *)name + off; else s = lbl_880C1320; }
    obj->state = 0;
    fn_88648998(obj, s);
    if (n <= 0) return; p.object = obj; for (i = 0; i < n; i++) {
        p.value = item_at(&src->items, i)->value;
        if (v->end != v->cap) {
            if (v->end != 0)
                *v->end = p;
            v->end++;
        } else {
            ts4_vector_grow_append_881784B0(v, v->end, &p);
        }
    }
}
