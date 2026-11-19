/* 0x882270C0: std::vector<0x14-byte item> emplace_back of a default item: grow step inlined when end == cap (out-of-line ucopy, old storage released by the tidy call), then the default ctor call on end; returns the new last item. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); ga.py EMPLACE + UCOPY + TIDY (model 0x88259518). */
typedef struct Item { int w[5]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_882287D8(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 20, 4, a); }
Item *ts4_uninit_copy_rec14_88233E30(Item *first, Item *last, Item *dest);
static __inline void grow(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Alloc *a = &v->alloc;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = allocate(a, newcap);
    d = ts4_uninit_copy_rec14_88233E30(v->begin, where, nb);
    ts4_if_call_seq_u32_off4_882287D8(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void ts4_call_seq_fn_88255AA0_887215E0(Item *p);
Item *ts4_vector_emplace_back_882270C0(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end)
        ts4_call_seq_fn_88255AA0_887215E0(v->end);
    ++v->end;
    return v->end - 1;
}
