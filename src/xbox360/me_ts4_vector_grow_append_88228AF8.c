/* 0x88228AF8: std::vector<0xa0-byte item> grow step without an insert (copies [begin, where) into the new block with an unchecked copy call; old storage released by the tidy call); allocator member at +8 (fn_88613570, align 8). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); grow-append body with the insert and tail removed (model 0x882289F8); the copy loop has no null check (ga.py UNCHK). */
typedef struct Item { int w[40]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_88229348(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 160, 8, a); }
void ts4_rec_copy_ctor_8823F698(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_rec_copy_ctor_8823F698(d, s); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        construct(dest, first);
    return dest;
}
void ts4_vector_grow_append_88228AF8(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Alloc *a = &v->alloc;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = allocate(a, newcap);
    d = ucopy(v->begin, where, nb);
    ts4_if_call_seq_u32_off4_88229348(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
