/* 0x88152BB0: std::vector<0x98-byte item> grow path for a single insert at the end (POD copy); direct allocator ts4_netdb_allocate_98. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[38]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_netdb_allocate_98(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) *dest = *first;
    return dest;
}
void ts4_vector_grow_append_88152BB0(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_netdb_allocate_98(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) *d = *val;
        d++;
    } else {
        for (; n; --n, ++d)
            if (d) *d = *val;
    }
    if (!at_end)
        d = ucopy(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
