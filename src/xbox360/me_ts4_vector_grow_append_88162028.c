/* 0x88162028: std::vector<0x84-byte item> grow path for a single insert at the end: out-of-line uninit copy fn_88166650 and construct 0x88166360, per-item destroy 0x8815FB60; lbl_88D45B38 allocator path. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); model 0x88162118 (out-of-line uninit copy and construct). */
typedef struct Item { int w[33]; } Item;
void ts4_if_call_seq_u32_off78_8815FB60(Item *p);
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
Item *fn_88166650(Item *first, Item *last, Item *dest);
void ts4_if_call_seq_u32_off0_88166360(Item *dest, const Item *val);
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first)
        ts4_if_call_seq_u32_off78_8815FB60(first);
}
void ts4_vector_grow_append_88162028(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 0x84, 4, &v->cap);
    d = fn_88166650(v->begin, where, nb);
    if (n == 1) {
        ts4_if_call_seq_u32_off0_88166360(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            ts4_if_call_seq_u32_off0_88166360(d, val);
    }
    if (!at_end)
        d = fn_88166650(where, v->end, d);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
