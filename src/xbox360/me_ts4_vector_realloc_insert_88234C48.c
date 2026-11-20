/* 0x88234C48: std::vector 140-byte items _Insert_n grow path with an allocator member at +8: allocate max(2*size,
 * size+n) items from it, copy-construct (fn_88260E90) prefix, n copies and (unless at_end) the tail, then release the old block. */
typedef struct Item { unsigned char w[140]; } Item;
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 140, 4, a); }
void fn_88260E90(Item *dest, const Item *src);
void ts4_if_call_seq_u32_off4_88260BE0(Vec *v);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) fn_88260E90(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) fn_88260E90(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_88234C48(Vec *v, Item *where, const Item *val, unsigned n, unsigned char at_end)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Alloc *a = &v->alloc;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = allocate(a, newcap);
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) fn_88260E90(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    if (!at_end)
        d = ucopy(where, v->end, d);
    ts4_if_call_seq_u32_off4_88260BE0(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
