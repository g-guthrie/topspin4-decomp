/* 0x8826E018: std::vector vector insert of 8-byte {vtable, value} items: each copy stores the lbl_880D6B70 vtable word, then the range destroy ts4_loop_get_u32_off0_8826DF58 runs before the buffer is freed. Same _Insert_n grow path as 0x8817A2A0. */
/* Matched on /Oc (work/army/ME/v.py chk); the newcap sum uses an inline ternary to reproduce the operand order. */
typedef struct Item { void *vtbl; unsigned v; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern char lbl_880D6B70;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_loop_get_u32_off0_8826DF58(Item *first, Item *last);
void ts4_destroy_owned_object(void *p);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) { dest->vtbl = &lbl_880D6B70; dest->v = first->v; }
    return dest;
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) { dest->vtbl = &lbl_880D6B70; dest->v = val->v; }
    return dest;
}
void ts4_vector_realloc_insert_8826E018(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 8, 4, &v->cap);
    d = ucopy(v->begin, where, nb);
    if (n == 1) {
        if (d) { d->vtbl = &lbl_880D6B70; d->v = val->v; }
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ucopy(where, v->end, d);
    ts4_loop_get_u32_off0_8826DF58(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
