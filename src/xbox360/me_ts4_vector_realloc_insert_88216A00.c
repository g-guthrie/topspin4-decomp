/* 0x88216A00: std::vector 84-byte items _Insert_n grow path: allocate max(2*size, size+n) items, copy-construct
 * with ts4_call_seq_u32_offc_88212570, destroy the old range item by item (ts4_if_call_seq_u32_offc_882124A8), free. */
typedef struct Item { unsigned char w[84]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_call_seq_u32_offc_88212570(Item *dest, const Item *src);
void ts4_if_call_seq_u32_offc_882124A8(Item *p);
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first)
        ts4_if_call_seq_u32_offc_882124A8(first);
}
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) ts4_call_seq_u32_offc_88212570(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) ts4_call_seq_u32_offc_88212570(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_88216A00(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 84, 4, &v->cap);
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) ts4_call_seq_u32_offc_88212570(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
