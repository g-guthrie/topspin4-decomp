/* 0x8815C620: std::vector<unsigned char> reallocating insert of n copies of *val: memmove _Ucopy (fn_88562DC0), memset fill; direct allocator 0x88150878. */
/* Matched on /Oc (work/army/ME/v.py chk); model 0x8817F4E8. */
typedef unsigned char Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88150878(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void *fn_88562DC0(void *dst, const void *src, unsigned n);
void *memset(void *dst, int c, unsigned n);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    unsigned off;
    if (last == first)
        return dest;
    off = (char *)last - (char *)first;
    return (Item *)((char *)fn_88562DC0(dest, first, off) + off);
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    memset(dest, *val, n);
    return dest + n;
}
void ts4_vector_realloc_insert_8815C620(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = *mp + size;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88150878(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    d = ufill(d, n, val);
    d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
