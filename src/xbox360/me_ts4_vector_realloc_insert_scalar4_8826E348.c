/* 0x8826E348: std::vector<4-byte scalar> reallocating insert: memmove _Ucopy (fn_88562DC0), fill_n without null checks; direct allocator 0x88162340. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); adapted from 0x88283878. */
typedef struct Item { int v; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88162340(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void *fn_88562DC0(void *dst, const void *src, unsigned n);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    if (last != first) {
        unsigned off = (char *)last - (char *)first;
        dest = (Item *)((char *)fn_88562DC0(dest, first, off) + off);
    }
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; 0 < n; --n, ++dest)
        *dest = *val;
    return dest;
}
void ts4_vector_realloc_insert_8826E348(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = *mp + size;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    d = ufill(d, n, val);
    d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
