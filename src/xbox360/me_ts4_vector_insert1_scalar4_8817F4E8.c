/* 0x8817F4E8: std::vector<4-byte scalar> reallocating insert of one copy of *val with an at_end flag (n fixed at 1): memmove _Ucopy, direct allocator 0x88162340. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); 0x88263908 with n as a local constant 1. */
typedef struct Item { int v; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88162340(void *alloc, unsigned n);
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
void ts4_vector_realloc_insert_8817F4E8(Vec *v, Item *where, const Item *val, unsigned char at_end)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = *mp + size;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    d = ufill(d, n, val);
    if (!at_end)
        d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
