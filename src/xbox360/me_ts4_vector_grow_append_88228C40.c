/* 0x88228C40: std::vector<0x24-byte item> grow step without an insert (copies [begin, where) into the new block; the item copy is two words plus fn_8825F1A8 on the member at +8; old storage released by ts4_if_call_seq_u32_off4_8825F130(v)); allocator member at +8 (fn_88613570). */
/* Matched on /Oc plain only (work/army/ME/v.py chk); grow-append body with the insert and tail removed (model 0x882289F8). */
typedef struct Item { int w[9]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_8825F130(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 36, 4, a); }
void fn_8825F1A8(int *d, const int *s);
static __inline void construct(Item *d, const Item *s) { d->w[0] = s->w[0]; d->w[1] = s->w[1]; fn_8825F1A8(&d->w[2], &s->w[2]); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_append_88228C40(Vec *v, Item *where)
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
    ts4_if_call_seq_u32_off4_8825F130(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
