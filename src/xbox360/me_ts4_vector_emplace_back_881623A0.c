/* 0x881623A0: std::vector<0x28-byte item> emplace_back: grow step inlined when end == cap (out-of-line ucopy cw3_uninit_copy_40_881668A8, range destroy fn_88166108, ts4_destroy_owned_object free), then the default ctor inlined (word 0 from lbl_88D45B1C+0x27c, -1/0 defaults); direct allocator. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); ga.py EMPLACE + EBODY (model 0x88259518). */
typedef struct Item { int a; int b; int c; int d; int e; unsigned char f; int g; int h; int i; int j; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void fn_88166108(Item *first, Item *last);
Item *cw3_uninit_copy_40_881668A8(Item *first, Item *last, Item *dest);
static __inline void grow(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(&v->cap, newcap) : 0;
    Item *d;
    d = cw3_uninit_copy_40_881668A8(v->begin, where, nb);
    fn_88166108(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
typedef struct Reg { char pad[0x27c]; int def; } Reg;
extern Reg *lbl_88D45B1C;
Item *ts4_vector_emplace_back_881623A0(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end) {
        Item *e = v->end;
        e->a = lbl_88D45B1C->def;
        e->b = -1;
        e->c = -1;
        e->d = 0;
        e->e = 0;
        e->f = 0;
        e->g = -1;
        e->h = 0;
        e->i = 0;
        e->j = 0;
    }
    ++v->end;
    return v->end - 1;
}
