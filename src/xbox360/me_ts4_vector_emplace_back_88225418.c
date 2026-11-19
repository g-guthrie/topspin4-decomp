/* 0x88225418: std::vector<0xb0-byte item> emplace_back of a default item: grow step inlined when end == cap (copy call with null check, old storage released by the tidy call), then the default ctor on end; returns the new last item. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); same shape as 0x88259518 (ga.py EMPLACE mode). */
typedef struct Item { int w[44]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_88228BC8(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 176, 8, a); }
void fn_8823FAF0(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { fn_8823FAF0(d, s); }
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
    ts4_if_call_seq_u32_off4_88228BC8(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void fn_88713DF8(Item *p);
Item *ts4_vector_emplace_back_88225418(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end)
        fn_88713DF8(v->end);
    ++v->end;
    return v->end - 1;
}
