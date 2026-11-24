/* 0x882285E8: std::vector<0xbc-byte item> grow step: allocate max(2*size, size+1) items (allocator member at +8), copy-construct [begin, where) with fn_8823FDA8, destroy the old range (0x88233618), free the old block, end = new prefix end. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); model 0x882289F8. */
typedef struct Item { int w[47]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 0xbc, 4, a); }
static __inline void deallocate(Alloc *a, Item *p)
{
    if (p) {
        if (lbl_88D45B38) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, p, a->h);
        else fn_885651F8(p);
    }
}
void fn_8823FDA8(Item *d, const Item *s);
void ts4_loop_call_seq_u32_off20_88233618(Item *first, Item *last);
static __inline void construct(Item *d, const Item *s) { fn_8823FDA8(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_prefix_882285E8(Vec *v, Item *where)
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
    ts4_loop_call_seq_u32_off20_88233618(v->begin, v->end);
    deallocate(a, v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
