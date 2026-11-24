/* 0x881712D0: std::vector of 12-byte polymorphic values {vtbl lbl_880D63EC, a, b} reallocating insert, no flag; lbl_88D45B38 allocator path, old range destroyed by ts4_destroy_polymorphic_value_range. Same grow path as 0x88182180. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); copy-construct writes the vtable then copies a and b. */
typedef struct Item { const void *vtbl; int a, b; } Item;
extern const char lbl_880D63EC[];
static __inline void construct(Item *d, const Item *s) { d->vtbl = lbl_880D63EC; d->a = s->a; d->b = s->b; }
void ts4_destroy_polymorphic_value_range(Item *first, Item *last);
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) construct(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_881712D0(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 12, 4, &v->cap);
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    ts4_destroy_polymorphic_value_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
