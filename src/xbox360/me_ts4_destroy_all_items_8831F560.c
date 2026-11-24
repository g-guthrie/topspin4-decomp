/* 0x8831F560: calls slot 5 (destroy, 1) on every non-null element of a {items, count} pointer array when items is set */
/* Matched on /Oc (agAH). agZ loop-body base local (O **it = a->items) gives index-first lwzx and the clrrwi copy. */
typedef struct O O;
typedef struct OVt { void *f[5]; void (*destroy)(O *o, int del); } OVt;
struct O { OVt *vt; };
typedef struct Arr { O **items; int count; } Arr;
void fn_8831F560(Arr *a)
{
    int i;
    if (!a->items)
        return;
    for (i = 0; i < a->count; i++) {
        O **it = a->items;
        if (it[i])
            it[i]->vt->destroy(it[i], 1);
    }
}
