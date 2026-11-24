/* 0x8826E5B8: std::vector of 20-byte polymorphic values {vtbl ts4_vtbl_Ts4TrackerShell880D6B70, 4 words} reallocating insert, no flag; lbl_88D45B38 allocator path, out-of-line uninitialized copy 0x88270720 and range destroy 0x8826DFB8. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); adapted from 0x881712D0. */
typedef struct Item { const void *vtbl; int a, b, c, e; } Item;
extern const char ts4_vtbl_Ts4TrackerShell880D6B70[];
static __inline void construct(Item *d, const Item *s) { d->vtbl = ts4_vtbl_Ts4TrackerShell880D6B70; d->a = s->a; d->b = s->b; d->c = s->c; d->e = s->e; }
void ts4_loop_get_u32_off0_8826DFB8(Item *first, Item *last);
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
Item *ts4_uninit_copy_e14_88270720(Item *first, Item *last, Item *dest);
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) construct(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_8826E5B8(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 20, 4, &v->cap);
    d = ts4_uninit_copy_e14_88270720(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ts4_uninit_copy_e14_88270720(where, v->end, d);
    ts4_loop_get_u32_off0_8826DFB8(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
