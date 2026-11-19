/* 0x887FB120: base append, then forward the item to every non-null child's slot-11 virtual */
/* Matched on /Oc (agAH). Inline vsize() on the embedded vector, as 887F7248. */
typedef struct Item Item;
typedef struct ItemVt { void *s[11]; void (*add)(Item *, void *); } ItemVt;
struct Item { ItemVt *vt; };
typedef struct Vec { Item **begin; Item **end; } Vec;
typedef struct Owner { char p[0x2c]; Vec v; } Owner;
extern void ts4_if_call_seq_u32_off8_887F9C40(Owner *o, void *x);
static __inline unsigned int vsize(Vec *v) { return v->end - v->begin; }
void fn_887FB120(Owner *o, void *x)
{
    unsigned int i, n;
    ts4_if_call_seq_u32_off8_887F9C40(o, x);
    n = vsize(&o->v);
    for (i = 0; i < n; i++) {
        Item *it = o->v.begin[i];
        if (it)
            it->vt->add(it, x);
    }
}
