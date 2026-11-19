/* 0x882596F8: std::vector<empty item> (C++ empty struct, size 1) emplace_back: grow step inlined when end == cap (the item copy and construct compile away, so ucopy is d = nb + (where - begin)); allocator member at +8 (fn_88613570 align 1, inline deallocate). */
/* Matched on /Oc plain only (work/army/ME/v.py chk); C++ is needed for the empty struct; grow body as in 0x88259518. */
struct Item {};
extern "C" {
typedef struct Alloc { void *h; } Alloc;
struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; };
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
}
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 1, 1, a); }
static __inline void deallocate(Alloc *a, Item *p)
{
    if (p) {
        if (lbl_88D45B38) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, p, a->h);
        else fn_885651F8(p);
    }
}
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) *dest = *first;
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
    deallocate(a, v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
extern "C" Item *ts4_vector_emplace_back_882596F8(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    ++v->end;
    return v->end - 1;
}
