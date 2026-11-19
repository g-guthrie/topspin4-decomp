/* 0x882598B0: std::vector<0x10-byte item {vtable lbl_880F228C, int, int, u8, u8}> grow step without an insert (copies [begin, where) into the new block; the copy stores the vtable then the fields; old storage released by the tidy call); allocator member at +8 (fn_88613570). */
/* Matched on /Oc plain only (work/army/ME/v.py chk); grow-append body with the insert and tail removed (model 0x882289F8). */
typedef struct Item { const void *vt; int a; int b; unsigned char c; unsigned char e; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void ts4_if_call_seq_u32_off4_882296A8(Vec *v);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 16, 4, a); }
extern const char lbl_880F228C[];
static __inline void construct(Item *d, const Item *s) { d->vt = (const void *)lbl_880F228C; d->a = s->a; d->b = s->b; d->c = s->c; d->e = s->e; }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
void ts4_vector_grow_append_882598B0(Vec *v, Item *where)
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
    ts4_if_call_seq_u32_off4_882296A8(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
