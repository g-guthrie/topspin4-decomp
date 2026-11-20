/* 0x881B6EB0: std::vector 12-byte items, helper copy fn_881B6A80, range destroy ts4_loop_call_seq_u32_off0_881B68A8, direct allocator 0x88263C98, the same _Insert_n grow path as 0x8817A2A0. */
/* Matched on /Oc (work/army/ME fn_check via the b134 build). The newcap sum uses an inline ternary to reproduce the operand order. */
typedef struct Item { unsigned char w[12]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(void *alloc, unsigned n);
void fn_881B6A80(Item *dest, const Item *src);
void ts4_loop_call_seq_u32_off0_881B68A8(Item *first, Item *last);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) fn_881B6A80(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) fn_881B6A80(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_881B6EB0(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) fn_881B6A80(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    ts4_loop_call_seq_u32_off0_881B68A8(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
