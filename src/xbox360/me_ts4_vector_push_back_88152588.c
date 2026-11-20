/* 0x88152588: std::vector<0x94-byte item> push_back: unchecked ts4_copy_block94 on end when end != cap, else the grow-append body inlined with where = end (out-of-line ucopy, ts4_destroy_owned_object free); direct allocator ts4_netdb_allocate_94. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the grow path is the 0x882116A0 model as a static inline insert1 (ga.py PUSH mode). */
typedef struct Item { int w[37]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_netdb_allocate_94(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void ts4_copy_block94(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_copy_block94(d, s); }
Item *fn_88155248(Item *first, Item *last, Item *dest);
static __inline void insert1(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_netdb_allocate_94(&v->cap, newcap) : 0;
    Item *d;
    d = fn_88155248(v->begin, where, nb);
    if (n == 1) {
        construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            construct(d, val);
    }
    if (!at_end)
        d = fn_88155248(where, v->end, d);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void ts4_vector_push_back_88152588(Vec *v, const Item *val)
{
    if (v->end != v->cap) {
        construct(v->end, val);
        ++v->end;
    } else {
        insert1(v, v->end, val);
    }
}
