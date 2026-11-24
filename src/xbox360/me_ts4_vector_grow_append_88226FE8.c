/* 0x88226FE8: std::vector<0x14-byte item> grow path for a single insert at the end (out-of-line ucopy; the inserted item is copied by a call on its first 16 bytes plus the word at +0x10; old storage released by the tidy call); allocator member at +8 (fn_88613570). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[5]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_882287D8(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 20, 4, a); }
void fn_88235D80(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { fn_88235D80(d, s); d->w[4] = s->w[4]; }
Item *ts4_uninit_copy_rec14_88233E30(Item *first, Item *last, Item *dest);
void ts4_vector_grow_append_88226FE8(Vec *v, Item *where, const Item *val)
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
    d = ts4_uninit_copy_rec14_88233E30(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            if (d) construct(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_rec14_88233E30(where, v->end, d);
    ts4_if_call_seq_u32_off4_882287D8(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
