/* 0x88228EF8: std::vector<0x10-byte item {vtable lbl_880F228C, int, int, u8, u8}> grow path for a single insert at the end (out-of-line ucopy; the inserted item stores the vtable then the fields; old storage released by the tidy call); allocator member at +8 (fn_88613570). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
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
Item *ts4_uninit_copy_rec10_88234290(Item *first, Item *last, Item *dest);
void ts4_vector_grow_append_88228EF8(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Alloc *a = &v->alloc;
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = allocate(a, newcap);
    d = ts4_uninit_copy_rec10_88234290(v->begin, where, nb);
    if (n == 1) {
        if (d) construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            if (d) construct(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_rec10_88234290(where, v->end, d);
    ts4_if_call_seq_u32_off4_882296A8(v);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
