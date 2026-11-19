/* 0x881B9270: std::vector<0x204-byte item> emplace_back: grow step inlined when end == cap (POD item copied by memcpy), then the default ctor inlined as a zero store to the word at +0x200; direct allocator. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); ga.py EMPLACE mode with an inline ctor body (EBODY). */
typedef struct Item { int w[129]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_881B93D8(void *alloc, unsigned n);
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
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_881B93D8(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
Item *ts4_vector_emplace_back_881B9270(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end)
        v->end->w[128] = 0;
    ++v->end;
    return v->end - 1;
}
