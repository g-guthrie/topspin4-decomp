/* 0x8817EB80: std::vector<0x10-byte item> grow path for a single insert at the end (text item: out-of-line ucopy ts4_uninit_copy_text_88181740, unchecked construct ts4_if_call_seq_u32_off0_88181618, destroy frees word 0 of each item); direct allocator ts4_if_call_seq_u32_lbl_88D45B38_8827A758. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[4]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_8827A758(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void ts4_if_call_seq_u32_off0_88181618(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_if_call_seq_u32_off0_88181618(d, s); }
Item *ts4_uninit_copy_text_88181740(Item *first, Item *last, Item *dest);
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first) { Item *p = first; ts4_destroy_owned_object((void *)p->w[0]); }
}
void ts4_vector_grow_append_8817EB80(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&v->cap, newcap) : 0;
    Item *d;
    d = ts4_uninit_copy_text_88181740(v->begin, where, nb);
    if (n == 1) {
        construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            construct(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_text_88181740(where, v->end, d);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
