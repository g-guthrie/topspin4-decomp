/* 0x88223E10: std::vector<0x20-byte item> push_back: unchecked construct call on end when end != cap, else the grow-append body inlined with where = end (out-of-line ucopy, old storage released by the tidy call); allocator member at +8 (fn_88613570). */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the grow path is the 0x882116A0 model as a static inline insert1 (ga.py PUSH mode). */
typedef struct Item { int w[8]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_loop_call_seq_u32_off4_88228578(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 32, 4, a); }
void ts4_if_call_seq_u32_off0_882334C0(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_if_call_seq_u32_off0_882334C0(d, s); }
Item *ts4_uninit_copy_rec20_88233D20(Item *first, Item *last, Item *dest);
static __inline void insert1(Vec *v, Item *where, const Item *val)
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
    d = ts4_uninit_copy_rec20_88233D20(v->begin, where, nb);
    if (n == 1) {
        construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            construct(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_rec20_88233D20(where, v->end, d);
    ts4_loop_call_seq_u32_off4_88228578(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void ts4_vector_push_back_88223E10(Vec *v, const Item *val)
{
    if (v->end != v->cap) {
        construct(v->end, val);
        ++v->end;
    } else {
        insert1(v, v->end, val);
    }
}
