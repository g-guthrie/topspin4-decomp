/* 0x88152ED8 near miss (29 off, plain /Oc): std::vector<0x208-byte item>::reserve(3) with the allocator member at +8. */
/* Open: the target loads v->alloc.h once above the begin==0 branch and calls fn_88613570 in both arms; see matching-tips agR. */
typedef struct Item { int w[130]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 520, 4, a); }
static __inline void deallocate(Alloc *a, Item *p)
{
    if (p) {
        if (lbl_88D45B38) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, p, a->h);
        else fn_885651F8(p);
    }
}
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    int off = (char *)dest - (char *)first;
    for (; first != last; ++first)
        if ((Item *)((char *)first + off)) *(Item *)((char *)first + off) = *first;
    return (Item *)((char *)first + off);
}
void ts4_vector_reserve3_88152ED8(Vec *v)
{
    Item *first = v->begin;
    if ((unsigned)(v->cap - first) < 3) {
        Item *last = v->end;
        unsigned size = last - first;
        Item *nb;
        if (first) {
            nb = allocate(&v->alloc, 3);
            ucopy(first, last, nb);
            deallocate(&v->alloc, v->begin);
        } else {
            nb = allocate(&v->alloc, 3);
        }
        v->begin = nb;
        v->end = nb + size;
        v->cap = nb + 3;
    }
}
