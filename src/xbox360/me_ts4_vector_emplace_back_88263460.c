/* 0x88263460: std::vector<1-byte item> emplace_back: grow step inlined when end == cap (byte copy loop, mtctr), then a zero byte store on end; direct allocator. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the ucopy loop increments first before dest (++first, ++dest) for the addi order. */
typedef struct Item { unsigned char b; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88150878(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}
static __inline void grow(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88150878(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
Item *ts4_vector_emplace_back_88263460(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end)
        v->end->b = 0;
    ++v->end;
    return v->end - 1;
}
