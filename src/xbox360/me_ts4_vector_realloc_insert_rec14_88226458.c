/* 0x88226458: std::vector of 20-byte {16-byte head copied by fn_88162768, a} items reallocating insert with an allocator member at +8 and an at_end flag; out-of-line uninit copy 0x88233C68, old storage released by 0x8825C148(v). */
/* Matched on /Oc plain only (work/army/ME/v.py chk); LTCG inlines the uninit copy (40 off). Adapted from 0x88234C48. */
typedef struct Head { unsigned char w[16]; } Head;
typedef struct Item { Head h; int a; } Item;
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 20, 4, a); }
Item *ts4_uninit_copy_rec14_88233C68(Item *first, Item *last, Item *dest);
void fn_88162768(Head *dest, const Head *src);
void ts4_loop_call_seq_u32_off4_8825C148(Vec *v);
static __inline void construct(Item *d, const Item *s) { fn_88162768(&d->h, &s->h); d->a = s->a; }
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) construct(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_88226458(Vec *v, Item *where, const Item *val, unsigned n, unsigned char at_end)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Alloc *a = &v->alloc;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = allocate(a, newcap);
    d = ts4_uninit_copy_rec14_88233C68(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_rec14_88233C68(where, v->end, d);
    ts4_loop_call_seq_u32_off4_8825C148(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
