/* 0x882280B0: std::vector<4-byte item> emplace_back: grow step inlined when end == cap (out-of-line ucopy, old storage released by the tidy call), then the ctor inlined as a zero store to word 0 and a call on the item; returns the new last item. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); ga.py EMPLACE + EBODY + UCOPY + TIDY (model 0x88259518). */
typedef struct Item { int w[1]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_loop_call_seq_u32_off4_88229AF0(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 4, 4, a); }
void fn_8825DA28(Item *p);
static __inline void construct(Item *d, const Item *s) { *d = *s; }
Item *fn_882342F0(Item *first, Item *last, Item *dest);
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
    d = fn_882342F0(v->begin, where, nb);
    ts4_loop_call_seq_u32_off4_88229AF0(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
Item *ts4_vector_emplace_back_882280B0(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end)
        { Item *e = v->end; e->w[0] = 0; fn_8825DA28(e); };
    ++v->end;
    return v->end - 1;
}
