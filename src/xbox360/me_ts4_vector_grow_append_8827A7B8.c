/* 0x8827A7B8: std::vector<0x20-byte item> grow step without an insert (allocate max(2*size, size+1), copy [begin, where), end = new prefix end; copy fn_8827A130, per-item destroy fn_8827B778); direct allocator ts4_if_call_seq_u32_lbl_88D45B38_88162950. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); PREFIX form of the grow-append template (model 0x882289F8). */
typedef struct Item { int w[8]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88162950(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void fn_8827A130(Item *d, const Item *s);
void fn_8827B778(Item *p);
static __inline void construct(Item *d, const Item *s) { fn_8827A130(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first) { Item *p = first; fn_8827B778(p); }
}
void ts4_vector_grow_append_8827A7B8(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88162950(&v->cap, newcap) : 0;
    Item *d;
    d = ucopy(v->begin, where, nb);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
