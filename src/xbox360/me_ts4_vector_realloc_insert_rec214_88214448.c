/* 0x88214448: std::vector of 0x214-byte records {0x20c-byte head copied by fn_881B2AC8, a, b} reallocating insert with an at_end flag; lbl_88D45B38 allocator path, out-of-line uninit copy 0x882164C8. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); LTCG inlines the uninit copy (50 off). */
typedef struct Head { unsigned char w[0x20c]; } Head;
typedef struct Item { Head h; int a, b; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
Item *ts4_uninit_copy_rec214_882164C8(Item *first, Item *last, Item *dest);
void fn_881B2AC8(Head *dest, const Head *src);
void ts4_destroy_owned_object(void *p);
static __inline void construct(Item *d, const Item *s) { fn_881B2AC8(&d->h, &s->h); d->a = s->a; d->b = s->b; }
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) construct(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_88214448(Vec *v, Item *where, const Item *val, unsigned n, unsigned char at_end)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 0x214, 4, &v->cap);
    d = ts4_uninit_copy_rec214_882164C8(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_rec214_882164C8(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
