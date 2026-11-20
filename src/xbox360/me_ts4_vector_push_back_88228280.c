/* 0x88228280: std::vector<0xb0-byte item> push_back: construct in place when end != cap, else the grow-append body inlined with where = end (out-of-line ucopy, null-checked construct call, old storage released by the tidy call); allocator member at +8 (fn_88613570, align 16). */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the grow path is the 0x882116A0 model as a static inline. */
typedef struct Item { int w[44]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_8825BFE0(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 176, 16, a); }
void ts4_call_seq_lbl_880F3430_8825C358(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_call_seq_lbl_880F3430_8825C358(d, s); }
Item *fn_8825C058(Item *first, Item *last, Item *dest);
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
    d = fn_8825C058(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            if (d) construct(d, val);
    }
    if (!at_end)
        d = fn_8825C058(where, v->end, d);
    ts4_if_call_seq_u32_off4_8825BFE0(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void ts4_vector_push_back_88228280(Vec *v, const Item *val)
{
    if (v->end != v->cap) {
        if (v->end) construct(v->end, val);
        ++v->end;
    } else {
        insert1(v, v->end, val);
    }
}
