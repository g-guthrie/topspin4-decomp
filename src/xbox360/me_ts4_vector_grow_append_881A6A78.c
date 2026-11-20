/* 0x881A6A78: std::vector of 0x48-byte items (copy fn_881A7188, range destroy ts4_loop_call_seq_u32_off4_881A7108) grow path for a single insert at the end; lbl_88D45B38 allocator path. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[18]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
void ts4_loop_call_seq_u32_off4_881A7108(Item *first, Item *last);
void fn_881A7188(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { fn_881A7188(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_append_881A6A78(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 0x48, 4, &v->cap);
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            if (d) construct(d, val);
    }
    if (!at_end)
        d = ucopy(where, v->end, d);
    ts4_loop_call_seq_u32_off4_881A7108(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
