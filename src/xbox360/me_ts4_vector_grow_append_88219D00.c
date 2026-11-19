/* 0x88219D00: std::vector<0x1c-byte item> grow path for a single insert at the end (out-of-line ucopy, unchecked construct call, range destroy call); lbl_88D45B38 allocator path (fn_88613570). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); _Insert_n with n = 1 and at_end = 1 inlined (model 0x882116A0). */
typedef struct Item { int w[7]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_destroy_owned_object(void *p);
void ts4_loop_call_seq_u32_offc_88219E68(Item *first, Item *last);
void ts4_if_call_seq_u32_off0_88219EC0(Item *d, const Item *s);
static __inline void construct(Item *d, const Item *s) { ts4_if_call_seq_u32_off0_88219EC0(d, s); }
Item *ts4_uninit_copy_rec1c_88219F18(Item *first, Item *last, Item *dest);
void ts4_vector_grow_append_88219D00(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned char at_end = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 28, 4, &v->cap);
    d = ts4_uninit_copy_rec1c_88219F18(v->begin, where, nb);
    if (n == 1) {
        construct(d, val);
        d++;
    } else {
        for (; n; --n, ++d)
            construct(d, val);
    }
    if (!at_end)
        d = ts4_uninit_copy_rec1c_88219F18(where, v->end, d);
    ts4_loop_call_seq_u32_offc_88219E68(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
