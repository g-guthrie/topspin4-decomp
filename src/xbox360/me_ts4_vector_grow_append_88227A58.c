/* 0x88227A58: std::vector<0x130-byte item> grow step without an insert (copies [begin, where) into the new block; POD item, range destroy fn_88261CA8, out-of-line ucopy fn_88261278); allocator member at +8 (fn_88613570; free via 0x886131F0 or fn_885651F8). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); grow-append body with the insert and tail removed, where is the only argument (model 0x882289F8). */
typedef struct Item { int w[76]; } Item;
typedef struct Alloc { void *h; } Alloc;
typedef struct Vec { Item *begin; Item *end; Alloc alloc; Item *cap; } Vec;
void fn_88261CA8(Item *first, Item *last);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *p, void *h);
void fn_885651F8(void *p);
static __inline Item *allocate(Alloc *a, unsigned n) { return (Item *)fn_88613570(a->h, n * 304, 16, a); }
static __inline void deallocate(Alloc *a, Item *p)
{
    if (p) {
        if (lbl_88D45B38) ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, p, a->h);
        else fn_885651F8(p);
    }
}
Item *fn_88261278(Item *first, Item *last, Item *dest);
void ts4_vector_grow_append_88227A58(Vec *v, Item *where)
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
    d = fn_88261278(v->begin, where, nb);
    fn_88261CA8(v->begin, v->end);
    deallocate(a, v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
