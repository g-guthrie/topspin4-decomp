/* 0x884CCF20: searches the {items, count} array back to front for the item whose slot-3 name compares equal (fn_884210E8 == 0) */
/* Matched on /Oc (agAH). agZ loop-body base local for the test, chain for the returned element. */
typedef struct O O;
typedef struct OVt { void *f[3]; const char *(*name)(O *o); } OVt;
struct O { OVt *vt; };
typedef struct Arr { O **items; int count; } Arr;
extern int fn_884210E8(const char *a, const char *b);
O *fn_884CCF20(const char *name, Arr *a)
{
    int i;
    for (i = a->count - 1; i >= 0; i--) {
        O **it = a->items;
        if (fn_884210E8(it[i]->vt->name(it[i]), name) == 0)
            return a->items[i];
    }
    return 0;
}
