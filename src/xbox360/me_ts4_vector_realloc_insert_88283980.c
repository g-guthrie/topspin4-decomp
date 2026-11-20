/* 0x88283980: std::vector vector insert of 8-byte items on the 0x88263C38 direct allocator, no flag. Same _Insert_n grow path as 0x8817A2A0. */
/* Matched on /Oc (work/army/ME/v.py chk); the newcap sum uses an inline ternary to reproduce the operand order. */
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
void ts4_vector_realloc_insert_88283980(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) *d = *val;
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
