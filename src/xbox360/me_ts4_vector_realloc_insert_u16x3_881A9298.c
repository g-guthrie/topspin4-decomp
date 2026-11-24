/* 0x881A9298: std::vector of 6-byte {u16[3]} items reallocating insert: memmove _Ucopy, fill_n without null checks; direct allocator 881A9828. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); scalar memmove _Ucopy (fn_88562DC0) returning early on an empty range (model 0x8826B718). */
typedef struct Item { unsigned short w[3]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_881A9828(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void *fn_88562DC0(void *dst, const void *src, unsigned n);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    unsigned off;
    if (last == first)
        return dest;
    off = (char *)last - (char *)first;
    return (Item *)((char *)fn_88562DC0(dest, first, off) + off);
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; 0 < n; --n, ++dest)
        *dest = *val;
    return dest;
}
void ts4_vector_realloc_insert_881A9298(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = *mp + size;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_881A9828(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    d = ufill(d, n, val);
    d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
