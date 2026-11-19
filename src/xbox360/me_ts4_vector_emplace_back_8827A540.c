/* 0x8827A540: std::vector<0x1c-byte item> emplace_back: grow step inlined when end == cap (out-of-line ucopy fn_8827B928, range destroy fn_8827B810, ts4_destroy_owned_object free), then the ctor inlined: seven zero words and fn_881705B0(&w[1], 50), fn_881705B0(&w[4], 20); direct allocator. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the stores go through an int *w local (ga.py EMPLACE + EBODY). */
typedef struct Item { int w[7]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88278A68(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void fn_8827B810(Item *first, Item *last);
Item *fn_8827B928(Item *first, Item *last, Item *dest);
static __inline void grow(Vec *v, Item *where)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    const unsigned *mp = size < n ? &n : &size;
    unsigned newcap = size + *mp;
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88278A68(&v->cap, newcap) : 0;
    Item *d;
    d = fn_8827B928(v->begin, where, nb);
    fn_8827B810(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void fn_881705B0(int *p, int n);
Item *ts4_vector_emplace_back_8827A540(Vec *v)
{
    if (v->end == v->cap)
        grow(v, v->end);
    if (v->end) {
        int *w = v->end->w;
        w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0; w[4] = 0; w[5] = 0; w[6] = 0;
        fn_881705B0(&w[1], 50);
        fn_881705B0(&w[4], 20);
    }
    ++v->end;
    return v->end - 1;
}
