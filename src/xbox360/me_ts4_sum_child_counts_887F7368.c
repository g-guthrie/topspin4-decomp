/* 0x887F7368: sum of the slot-10 virtual count over the non-null children in the vector at +0x2c, starting at 1 */
/* Matched on /Oc (agAH). Same template as 887F7248. */
typedef struct Item Item;
typedef struct ItemVt { void *s[10]; int (*count)(Item *); } ItemVt;
struct Item { ItemVt *vt; };
typedef struct Vec { Item **begin; Item **end; } Vec;
typedef struct Owner { char p[0x2c]; Vec v; } Owner;
static __inline unsigned int vsize(Vec *v) { return v->end - v->begin; }
int fn_887F7368(Owner *o)
{
    int total = 1;
    unsigned int i, n = vsize(&o->v);
    for (i = 0; i < n; i++) {
        Item *it = o->v.begin[i];
        if (it)
            total += it->vt->count(it);
    }
    return total;
}
