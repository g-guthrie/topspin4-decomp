/* agK 2026-11-19: still 3 aligned (both routes). Pads 0-7 at top: no change. Copy forms (separate count local, do/while, copy_n helper, dest+off return, index loop, pointer !=) all keep 3 or worse; the `mr` count copy looks tied to the same param-copy pattern as 0x88178D10. */
/* NEAR MISS 0x8890ED60 (plain /Oc and LTCG, matching-b129): fn_check reports 52 differing (a 1-instruction shift);
 * aligned, 3 instructions differ: the target keeps a copy of the erase-copy count (`mr r10,r9`), and it places
 * `std r6,0xa8(r1)` after `mr r30,r4`.
 * Behaviour: append a keyed record to the 16-byte item vector at owner+4. resize(size + 1, default item
 * {0, 0xFFFFF, 0, 0}) (Dinkumware: erase when shrinking, else _Insert_n = fn_88178D10), then fill the new back
 * element with the 12-byte value (passed by value in r5/r6) and *key.
 * Tried copy-loop forms: down-counting for, while(off--), do/while, pointer !=, unsigned, index loop. */
typedef struct Val3 { int a, b, c; } Val3;
typedef struct Item { int a, b, c; int key; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
typedef struct Owner { int f0; Vec items; } Owner;
void fn_88178D10(Vec *v, Item *where, unsigned n, const Item *val);
static __inline void item_init(Item *it) { it->a = 0; it->b = 0xFFFFF; it->c = 0; it->key = 0; }
static __inline Item *copy(Item *first, Item *last, Item *dest)
{
    int off;
    for (off = last - first; 0 < off; --off, ++dest, ++first)
        *dest = *first;
    return dest;
}
static __inline void resize(Vec *v, unsigned n, const Item *val)
{
    unsigned size = v->end - v->begin;
    if (n < size) {
        v->end = copy(v->end, v->end, v->begin + n);
    } else
        fn_88178D10(v, v->end, n - size, val);
}
void fn_8890ED60(Owner *o, const int *key, Val3 val)
{
    Item tmp;
    Item *back;
    item_init(&tmp);
    resize(&o->items, (o->items.end - o->items.begin) + 1, &tmp);
    back = o->items.end - 1;
    back->a = val.a; back->b = val.b; back->c = val.c;
    back->key = *key;
}
