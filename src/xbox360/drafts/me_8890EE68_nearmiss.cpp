/* NEAR MISS (agO, 2026-11-19): fn_8890EE68 keyed Val3 get, 5 real instructions off on plain (/Oc); LTCG differs widely.
 * Assigning members in the ctor body as a, c, b (not an init list) dropped it from 9 to 5. The li r7,0 hoist to entry is still missing. */
struct Val3 { int a, b, c; Val3() {} Val3(int a_, int b_, int c_) { a = a_; c = c_; b = b_; } };

struct Item { Val3 v; unsigned key; };
struct Vec { Item *begin; Item *end; Item *cap; };
struct Owner { int f0; Vec items; };
static __inline Item *find_key(Item *first, Item *last, unsigned key)
{
    int trip = (last - first) >> 2;
    for (; trip > 0; --trip) {
        if (first->key == key) return first;
        ++first;
        if (first->key == key) return first;
        ++first;
        if (first->key == key) return first;
        ++first;
        if (first->key == key) return first;
        ++first;
    }
    switch (last - first) {
    case 3:
        if (first->key == key) return first;
        ++first;
    case 2:
        if (first->key == key) return first;
        ++first;
    case 1:
        if (first->key == key) return first;
        ++first;
    case 0:
    default:
        return last;
    }
}
extern "C" Val3 fn_8890EE68(Owner *o, const unsigned *key)
{
    Item *it = find_key(o->items.begin, o->items.end, *key);
    const Val3 &r = (it == o->items.end) ? Val3(0, 0x000fffff, 0) : it->v;
    return r;
}
