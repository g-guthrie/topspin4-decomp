/* 0x88235140: std::vector<16-byte item> reallocating insert on a fixed inline-buffer allocator (4 items at +8, cap at +0x48): allocate returns the buffer, nothing is freed. */
/* Matched on /Oc (work/army/ME/v.py chk); the 0x88283980 grow path with an inline allocate(). */
typedef struct Item { int w[4]; } Item;
typedef struct Alloc { Item buf[4]; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
static __inline Item *allocate(Alloc *a, unsigned n) { return a->buf; }
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
void ts4_vector_realloc_insert_88235140(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = allocate(&v->alloc, newcap);
    Item *d;
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) *d = *val;
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
