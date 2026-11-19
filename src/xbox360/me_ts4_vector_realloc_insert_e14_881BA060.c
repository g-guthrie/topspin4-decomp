/* 0x881BA060: std::vector of 20-byte items reallocating insert; the inline construct zeroes word 1 and then copies all five words; out-of-line range copy 0x881BA4D8, lbl_88D45B38 allocator path. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); LTCG is 80 off. Copy the fields one by one after d->b = 0 (MSVC keeps the dead store). */
typedef struct Item { int a, b, c, d, e; } Item;

static __inline void construct(Item *d, const Item *s) { d->b = 0; d->a = s->a; d->b = s->b; d->c = s->c; d->d = s->d; d->e = s->e; }
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
Item *ts4_copy_range_e14_881BA4D8(Item *first, Item *last, Item *dest);
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) construct(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_881BA060(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 20, 4, &v->cap);
    d = ts4_copy_range_e14_881BA4D8(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ts4_copy_range_e14_881BA4D8(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
