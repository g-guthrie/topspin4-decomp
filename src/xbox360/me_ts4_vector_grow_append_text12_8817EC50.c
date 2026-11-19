/* 0x8817EC50: std::vector of 12-byte text items (copy ts4_assign_formatted_text, destroy frees the text) grow path for a single insert at the end; direct allocator 0x88263C98. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { const char *text; int w1, w2; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void ts4_assign_formatted_text(Item *dst, const char *text);
static __inline void construct(Item *d, const Item *s) { ts4_assign_formatted_text(d, s->text); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first) { Item *p = first; ts4_destroy_owned_object((void *)p->text); }
}
void ts4_vector_grow_append_8817EC50(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->cap, newcap) : 0;
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
