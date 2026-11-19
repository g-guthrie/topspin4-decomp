/* 0x88162118: std::vector of 12-byte {owned buf, w1, w2} items grow path for a single insert at the end: out-of-line uninit copy fn_88166728 and construct fn_88166428, destroy frees non-null bufs; lbl_88D45B38 allocator path. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { void *buf; int w1, w2; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
Item *fn_88166728(Item *first, Item *last, Item *dest);
void fn_88166428(Item *dest, const Item *val);
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first)
        if (first->buf) ts4_destroy_owned_object(first->buf);
}
void ts4_vector_grow_append_88162118(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 12, 4, &v->cap);
    d = fn_88166728(v->begin, where, nb);
    if (n == 1) {
        fn_88166428(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            fn_88166428(d, val);
    }
    if (!at_end)
        d = fn_88166728(where, v->end, d);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
