/* 0x8817E890: std::vector of 0x50-byte {0x4c-byte head copied by fn_88166AF8, a} items grow path for a single insert at the end; direct allocator 0x88187638. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); LTCG is 42 off. _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Head { int w[19]; } Head;
typedef struct Item { Head h; int a; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88187638(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void fn_88166AF8(Head *d, const Head *s);
static __inline void construct(Item *d, const Item *s) { fn_88166AF8(&d->h, &s->h); d->a = s->a; }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_append_8817E890(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88187638(&v->cap, newcap) : 0;
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
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
