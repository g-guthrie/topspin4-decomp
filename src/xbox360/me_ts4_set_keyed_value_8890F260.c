/* 0x8890F260: set the 12-byte value for a key in the 16-byte {value, key} vector at owner+4. Finds the key with the STL 4-way unrolled find (trip count = n/4, then a 3/2/1 switch on the rest); overwrites the value when found, otherwise appends through fn_8890ED60.
 * Matched on the plain /Oc route only (work/army/ME/v.py chk, matching-b129); the LTCG route does not match. */
typedef struct Val3 { int a, b, c; } Val3;
typedef struct Item { int a, b, c; unsigned key; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
typedef struct Owner { int f0; Vec items; } Owner;
void fn_8890ED60(Owner *o, const unsigned *key, Val3 val);
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
void fn_8890F260(Owner *o, const unsigned *key, Val3 val)
{
    Item *it = find_key(o->items.begin, o->items.end, *key);
    if (it == o->items.end)
        fn_8890ED60(o, key, val);
    else {
        it->a = val.a; it->b = val.b; it->c = val.c;
    }
}
