/* 0x8827A3C8: std::vector<8-byte item> reallocating insert of n copies of *val at where, with a flag (skip_tail) that skips copying [where, end) after the fill. Same as 0x88280708 with 8-byte items and the 0x88263C38 allocator. */
/* Matched on /Oc (work/army/ME/v.py chk). The newcap sum uses an inline ternary to reproduce the operand order. */
typedef struct Item { int w[2]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) *dest = *first;
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) *dest = *val;
    return dest;
}
void ts4_vector_realloc_insert_8827A3C8(Vec *v, Item *where, const Item *val, unsigned n, unsigned char skip_tail)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->cap, newcap) : 0;
    Item *d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) *d = *val;
        d++;
    } else {
        d = ufill(d, n, val);
    }
    if (!skip_tail)
        d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
