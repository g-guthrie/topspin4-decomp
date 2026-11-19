/* 0x88259518: std::vector<0x3c-byte item> emplace_back of a default item: grow step inlined when end == cap (copies via the call construct, old storage released by the tidy call), then the default ctor on end; returns the new last item. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the grow step is the PREFIX grow body (model 0x882289F8) as a static inline with where = v->end. */
typedef struct Item { int w[15]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_u32_off4_88229720(Vec *v);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 60, 4, a); }
void fn_8815FD40(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { fn_8815FD40(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
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
    d = ucopy(v->begin, where, nb);
    ts4_if_call_seq_u32_off4_88229720(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void ts4_call_seq_u32_off0_886F1F60(Item *p);
Item *ts4_vector_emplace_back_88259518(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end)
        ts4_call_seq_u32_off0_886F1F60(v->end);
    ++v->end;
    return v->end - 1;
}
