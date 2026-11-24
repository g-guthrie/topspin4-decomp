/* 0x88161938: std::vector<0x20-byte item> push_back: unchecked construct call on end when end != cap, else the grow-append body inlined with where = end (out-of-line ucopy, unchecked construct, range destroy call, ts4_destroy_owned_object free); direct allocator. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); the grow path is the 0x882116A0 model as a static inline (ga.py UCOPY + NOCHK + DRANGE). */
typedef struct Item { int w[8]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_88162950(void *alloc, unsigned n);
void ts4_destroy_owned_object(void *p);
void ts4_loop_call_seq_u32_offc_88166048(Item *first, Item *last);
void ts4_if_call_seq_u32_off0_881664E8(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_if_call_seq_u32_off0_881664E8(d, s); }
Item *ts4_uninit_copy_text2_88166838(Item *first, Item *last, Item *dest);
static __inline void insert1(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_88162950(&v->cap, newcap) : 0;
    Item *d;
    d = ts4_uninit_copy_text2_88166838(v->begin, where, nb);
    if (n == 1) {
        construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            construct(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_text2_88166838(where, v->end, d);
    ts4_loop_call_seq_u32_offc_88166048(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
void ts4_vector_push_back_88161938(Vec *v, const Item *val)
{
    if (v->end != v->cap) {
        construct(v->end, val);
        ++v->end;
    } else {
        insert1(v, v->end, val);
    }
}
