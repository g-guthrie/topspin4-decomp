/* 0x88173950: std::vector of 16-byte {key, text} items: grow-and-append one copy of *val after the prefix [begin, where) (n fixed at 1, tail not copied); lbl_88D45B38 allocator path, old range destroyed by freeing each text. */
/* Matched on /Oc plain only; LTCG is 47 off (work/army/ME/v.py chk); the 0x88188BA0 grow path with n = 1 and the at_end branch folded. */
typedef struct Str { const char *text; int w1, w2; } Str;
typedef struct Item { int key; Str s; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
void *fn_88613570(void *alloc, unsigned size, unsigned align, void *owner);
void ts4_assign_formatted_text(Str *dst, const char *text);
void ts4_destroy_owned_object(void *p);
static __inline void construct(Item *d, const Item *s) { d->key = s->key; ts4_assign_formatted_text(&d->s, s->s.text); }
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) construct(dest, first);
    return dest;
}
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first)
        ts4_destroy_owned_object((void *)first->s.text);
}
void ts4_vector_grow_push_88173950(Vec *v, Item *where, const Item *val)
{
    unsigned n = 1;
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = 0;
    Item *d;
    if (newcap)
        nb = (Item *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, newcap * 16, 4, &v->cap);
    d = ucopy(v->begin, where, nb);
    if (d) construct(d, val);
    d++;
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
