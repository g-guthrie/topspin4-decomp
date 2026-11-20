/* 0x88266EF8: std::vector of 4-byte {u16, u16} items reallocating insert, no flag; lbl_88D45B38 allocator path (fn_88613570, align 2). Same grow path as 0x8817B198. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); val is __restrict so both halves of *val load before the stores. */
typedef struct Item { unsigned short x, y; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
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
void ts4_vector_realloc_insert_88266EF8(Vec *v, Item *where, const Item *__restrict val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 4, 2, &v->cap);
    d = ucopy(v->begin, where, nb);
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
