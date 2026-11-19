/* 0x882256B0: std::vector<0x134-byte item> grow path for a single insert at the end (copy ts4_if_call_seq_fn_8822A4A0_88232CE0, out-of-line ucopy ts4_uninit_copy_rec134_88233A88, construct not null-checked); allocator member at +8 (fn_88613570; free via 0x886131F0 or fn_885651F8). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[77]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 308, 4, a); }
static __inline void deallocate(Alloc *a, Item *p)
{
    if (p) {
        if (lbl_88D45B38) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, p, a->h);
        else fn_885651F8(p);
    }
}
void ts4_if_call_seq_fn_8822A4A0_88232CE0(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_if_call_seq_fn_8822A4A0_88232CE0(d, s); }
Item *ts4_uninit_copy_rec134_88233A88(Item *first, Item *last, Item *dest);
void ts4_vector_grow_append_882256B0(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Alloc *a = &v->alloc;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = allocate(a, newcap);
    d = ts4_uninit_copy_rec134_88233A88(v->begin, where, nb);
    if (n == 1) {
        construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            construct(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_rec134_88233A88(where, v->end, d);
    deallocate(a, v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
