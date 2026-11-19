/* 0x881617C8: std::vector of 12-byte text items (copy = ts4_assign_formatted_text(dst, src->text)) reallocating insert with an at_end flag; direct allocator 0x88263C98, range destroy 0x88150378. Same grow path as 0x881A9540. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the LTCG route is 39 off (register allocation). */
typedef struct Item { const char *text; int w1, w2; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(void *alloc, unsigned n);
void ts4_assign_formatted_text(Item *dst, const char *text);
void ts4_loop_call_seq_u32_off0_88150378(Item *first, Item *last);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) ts4_assign_formatted_text(dest, first->text);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) ts4_assign_formatted_text(dest, val->text);
    return dest;
}
void ts4_vector_realloc_insert_881617C8(Vec *v, Item *where, const Item *val, unsigned n, unsigned char at_end)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) ts4_assign_formatted_text(d, val->text);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    if (!at_end)
        d = ucopy(where, v->end, d);
    ts4_loop_call_seq_u32_off0_88150378(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
