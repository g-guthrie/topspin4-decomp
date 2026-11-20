/* 0x881771A0: std::vector<40-byte item> grow path for a single insert at the end: out-of-line uninit copy 0x88177378 and construct 0x88177300, range destroy 0x88177288; lbl_88D45B38 allocator path. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); model 0x88162118 (out-of-line uninit copy and construct). */
typedef struct Item { int w[10]; } Item;
void ts4_destroy_ent28_range_88177288(Item *first, Item *last);
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
Item *ts4_uninit_copy_ent28_88177378(Item *first, Item *last, Item *dest);
void ts4_copy_ctor_text_88177300(Item *dest, const Item *val);
void ts4_vector_grow_append_881771A0(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 40, 4, &v->cap);
    d = ts4_uninit_copy_ent28_88177378(v->begin, where, nb);
    if (n == 1) {
        ts4_copy_ctor_text_88177300(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            ts4_copy_ctor_text_88177300(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_ent28_88177378(where, v->end, d);
    ts4_destroy_ent28_range_88177288(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
