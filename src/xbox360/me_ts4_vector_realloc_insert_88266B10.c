/* 0x88266B10: std::vector of 32-byte items holding two __vector4 (lvx128/stvx128 copies), direct allocator 0x88267070,
 * the same _Insert_n grow path as 0x88262090. */
typedef struct __declspec(passinreg) __vector4 { float v[4]; } __vector4;
typedef struct Item { __vector4 a, b; } Item;
static __inline void copy2(Item *d, const Item *s) { d->a = s->a; d->b = s->b; }
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88267070(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) copy2(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) copy2(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_88266B10(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88267070(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) copy2(d, val);
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
