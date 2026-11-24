/* 0x8826B718: std::vector<4-byte scalar> reallocating insert with an at_end flag: memmove _Ucopy (fn_88562DC0), fill_n without null checks; lbl_88D45B38 allocator path. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Ucopy must return early on an empty range. */
typedef struct Item { int v; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
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
void ts4_vector_realloc_insert_8826B718(Vec *v, Item *where, const Item *val, unsigned n, unsigned char at_end)
{
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = *mp + size;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 4, 4, &v->cap);
    d = ucopy(v->begin, where, nb);
    d = ufill(d, n, val);
    if (!at_end)
        d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
