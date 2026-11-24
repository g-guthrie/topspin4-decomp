/* 0x88161E88: std::vector<0x20-byte item> grow path for a single insert at the end (out-of-line ucopy fn_881665D0, unchecked construct ts4_if_call_seq_u32_off0_881662F0, destroy frees word 0 of each item); direct allocator ts4_if_call_seq_u32_lbl_88D45B38_88162950. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[8]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88162950(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void ts4_if_call_seq_u32_off0_881662F0(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_if_call_seq_u32_off0_881662F0(d, s); }
Item *fn_881665D0(Item *first, Item *last, Item *dest);
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first) { Item *p = first; ts4_destroy_owned_object((void *)p->w[0]); }
}
void ts4_vector_grow_append_88161E88(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88162950(&v->cap, newcap) : 0;
    Item *d;
    d = fn_881665D0(v->begin, where, nb);
    if (n == 1) {
        construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            construct(d, val);
    }
    if (!at_end)
        d = fn_881665D0(where, v->end, d);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
