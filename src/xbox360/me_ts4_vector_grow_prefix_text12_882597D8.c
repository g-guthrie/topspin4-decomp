/* 0x882597D8: std::vector of 12-byte text items grow step without an insert: allocate max(2*size, size+1) from the allocator member at +8, copy [begin, where) with ts4_assign_formatted_text, release old storage with 0x8825E738(v). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); model 0x882289F8. */
typedef struct Item { const char *text; int w1, w2; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_8825E738(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 12, 4, a); }
void ts4_assign_formatted_text(Item *dst, const char *text);
static __inline void construct(Item *d, const Item *s) { ts4_assign_formatted_text(d, s->text); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_prefix_text12_882597D8(Vec *v, Item *where)
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
    ts4_if_call_seq_u32_off4_8825E738(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
