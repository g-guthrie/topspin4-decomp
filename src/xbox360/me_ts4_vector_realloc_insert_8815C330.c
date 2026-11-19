/* 0x8815C330: std::vector 40-byte items, helper copy fn_8815BCA8 and per-element destroy range fn_8815DCE0 (global allocator), the same _Insert_n grow path as 0x8817A2A0. */
/* Matched on /Oc (work/army/ME fn_check via the b134 build). The newcap sum uses an inline ternary to reproduce the operand order. */
typedef struct Item { unsigned char w[40]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void fn_8815BCA8(Item *dest, const Item *src);
void fn_8815DCE0(Item *first, Item *last);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) fn_8815BCA8(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) fn_8815BCA8(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_8815C330(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 40, 4, &v->cap);
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) fn_8815BCA8(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    fn_8815DCE0(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
