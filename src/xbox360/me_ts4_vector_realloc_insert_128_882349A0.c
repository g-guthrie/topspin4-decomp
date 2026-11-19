/* 0x882349A0: std::vector<128-byte POD, 16-byte aligned> reallocating insert with an allocator member at +8: memmove _Ucopy (fn_88562DC0), out-of-line fill fn_8823F758, free via 0x886131F0 or fn_885651F8. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Ucopy must return early on an empty range. */
typedef struct Item { int w[32]; } Item;
extern void *lbl_88D45B38;
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
void *fn_88562DC0(void *dst, const void *src, unsigned n);
Item *fn_8823F758(Item *dest, unsigned n, const Item *val);
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 128, 16, a); }
static __inline void deallocate(Alloc *a, Item *p)
{
    if (p) {
        if (lbl_88D45B38) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, p, a->h);
        else fn_885651F8(p);
    }
}
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    unsigned off;
    if (last == first)
        return dest;
    off = (char *)last - (char *)first;
    return (Item *)((char *)fn_88562DC0(dest, first, off) + off);
}
void ts4_vector_realloc_insert_882349A0(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = *mp + size;
    Alloc *a = &v->alloc;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = allocate(a, newcap);
    d = ucopy(v->begin, where, nb);
    d = fn_8823F758(d, n, val);
    d = ucopy(where, v->end, d);
    deallocate(a, v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
