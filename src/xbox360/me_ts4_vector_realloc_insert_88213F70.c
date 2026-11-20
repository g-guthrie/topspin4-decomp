/* 0x88213F70: std::vector 56-byte items _Insert_n grow path with an at_end flag (tail copy skipped when set); copy fn_881C60C8,
 * per-item destroy ts4_call_seq_fn_881B19A0_881C6008, allocate via ts4_if_call_seq_u32_lbl_88D45B38_882147E8. Plain /Oc only. */
/* Matched on /Oc (work/army/ME fn_check via the b138 build). The newcap sum uses an inline ternary to reproduce the operand order. */
typedef struct Item { unsigned char w[56]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_882147E8(void *alloc, unsigned n);
void fn_881C60C8(Item *dest, const Item *src);
void ts4_call_seq_fn_881B19A0_881C6008(Item *p);
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first)
        ts4_call_seq_fn_881B19A0_881C6008(first);
}
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) fn_881C60C8(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) fn_881C60C8(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_88213F70(Vec *v, Item *where, const Item *val, unsigned n, unsigned char at_end)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_882147E8(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) fn_881C60C8(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    if (!at_end)
        d = ucopy(where, v->end, d);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
