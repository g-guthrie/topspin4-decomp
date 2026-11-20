/* 0x8817A2A0: std::vector<16-byte item> reallocating insert of n copies of *val at where (the _Insert_n grow path). New capacity = size + max(size, n) (max by reference, as std::max); storage comes from the allocator at vec+8. Copies [begin, where), the n copies (single-copy fast path for n == 1), then [where, end) with the STL uninitialized-copy/fill helpers, frees the old block and sets begin/end/capacity.
 * Matched on plain /Oc and LTCG routes (work/army/ME/v.py chk, matching-b129). */
typedef struct Item { int w[4]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_8827A758(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
static __inline const unsigned *umax(const unsigned *a, const unsigned *b) { return *a < *b ? b : a; }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) *dest = *first;
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) *dest = *val;
    return dest;
}
void fn_8817A2A0(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *umax(&size, &n);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&v->cap, newcap) : 0;
    Item *d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) *d = *val;
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
