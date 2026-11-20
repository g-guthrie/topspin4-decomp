/* 0x88263730: std::vector<4-byte item of two u16> emplace_back: grow step inlined when end == cap (POD lhz/sth copy), then the default ctor inlined as two zero halfword stores; direct allocator. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the zero stores go through an unsigned short *w local, as in 0x88263548. */
typedef struct Item { unsigned short w[2]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88263D00(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) *dest = *first;
    return dest;
}
static __inline void grow(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88263D00(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
Item *ts4_vector_emplace_back_88263730(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end)
        { unsigned short *w = v->end->w; w[0] = 0; w[1] = 0; };
    ++v->end;
    return v->end - 1;
}
