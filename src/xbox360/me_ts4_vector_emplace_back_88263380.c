/* 0x88263380: std::vector<0x20-byte item of two __vector4> emplace_back with no construct: grow step inlined when end == cap (member-wise vector copy gives the lvx128/stvx128 pairs), direct allocator ts4_if_call_seq_u32_lbl_88D45B38_88267070; returns the new last item. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); grow is __forceinline (plain __inline is not inlined with vector members); a struct assignment gives ld/std. */
#include "vx1_vector.h"
typedef struct Item { __vector4 a; __vector4 b; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88267070(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);

static __inline void construct(Item *d, const Item *s) { d->a = s->a; d->b = s->b; }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
static __forceinline void grow(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88267070(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
Item *ts4_vector_emplace_back_88263380(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    ++v->end;
    return v->end - 1;
}
