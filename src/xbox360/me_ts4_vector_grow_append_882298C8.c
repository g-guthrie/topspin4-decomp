/* 0x882298C8: std::vector<0xa0-byte item> grow step without an insert (allocate max(2*size, size+1), copy [begin, where), end = new prefix end; copy fn_88224D50, old storage released by ts4_if_call_seq_u32_off4_88229B60(v)); allocator member at +8 (fn_88613570; free via 0x886131F0 or fn_885651F8). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); PREFIX form of the grow-append template (model 0x882289F8). */
typedef struct Item { int w[40]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 160, 16, a); }
void fn_88224D50(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { fn_88224D50(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_append_882298C8(Vec *v, Item *where)
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
    ts4_if_call_seq_u32_off4_88229B60(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
