/* 0x88263B60: std::vector<0x18-byte item> grow step without an insert (allocate max(2*size, size+1), copy [begin, where), end = new prefix end; POD copy); direct allocator ts4_if_call_seq_u32_lbl_88D45B38_881629B0. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); PREFIX form of the grow-append template (model 0x882289F8). */
typedef struct Item { int w[6]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_881629B0(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) *dest = *first;
    return dest;
}
void ts4_vector_grow_append_88263B60(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_881629B0(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
