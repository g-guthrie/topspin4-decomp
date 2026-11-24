/* 0x88161B30: std::vector<0x60-byte item> grow path for a single insert at the end (copy ts4_call_seq_fn_8815ED78_88166A10, range destroy ts4_loop_call_seq_u32_offc_881661F8); direct allocator ts4_if_call_seq_u32_lbl_88D45B38_881624B8. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[24]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_881624B8(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void ts4_loop_call_seq_u32_offc_881661F8(Item *first, Item *last);
void ts4_call_seq_fn_8815ED78_88166A10(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_call_seq_fn_8815ED78_88166A10(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_append_88161B30(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_881624B8(&v->cap, newcap) : 0;
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
    ts4_loop_call_seq_u32_offc_881661F8(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
