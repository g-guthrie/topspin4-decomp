/* 0x88178798: std::vector<0x28-byte item> grow path for a single insert at the end (copy fn_88179D88, per-item destroy fn_88178268); direct allocator ts4_if_call_seq_u32_lbl_88D45B38_88162AE0. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[10]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void fn_88179D88(Item *d, const Item *s);
void fn_88178268(Item *p);
static __inline void construct(Item *d, const Item *s) { fn_88179D88(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first) { Item *p = first; fn_88178268(p); }
}
void ts4_vector_grow_append_88178798(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(&v->cap, newcap) : 0;
    Item *d;
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
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
