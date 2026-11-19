/* 0x88235388: std::vector 128-byte items (copy helper ts4_get_u32_off0_882344C8, 16-byte aligned global allocator) with the owner slot at vec+8 and the deallocation tail through ts4_if_call_seq_fn_881F04B8_886131F0 or fn_885651F8 (no element destructor loop). Same _Insert_n grow path as 0x8817A2A0. */
/* Matched on /Oc (work/army/ME fn_check via the b134 build). The newcap sum uses an inline ternary, and the slot and nb assignments are ordered to reproduce the register allocation. */
typedef struct Item { unsigned char w[128]; } Item;
typedef struct Vec { Item *begin; Item *end; void *alloc; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_get_u32_off0_882344C8(Item *dest, const Item *src);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, Item *p, void *a);
void fn_885651F8(Item *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) ts4_get_u32_off0_882344C8(dest, first);
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) ts4_get_u32_off0_882344C8(dest, val);
    return dest;
}
void ts4_vector_realloc_insert_88235388(Vec *v, Item *where, const Item *val, unsigned n)
{
    void **slot;
    Item *nb;
    Item *d;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    slot = &v->alloc;
    nb = 0;
    if (newcap)
        nb = (Item *)fn_88613570(*slot, newcap * 128, 16, slot);
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) ts4_get_u32_off0_882344C8(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    if (v->begin) {
        if (lbl_88D45B38)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, v->begin, *slot);
        else
            fn_885651F8(v->begin);
    }
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
