/* 0x88283490: std::vector of 20-byte {text, a, b} items reallocating insert, no flag; direct allocator 0x8817F480, out-of-line uninit copy fn_88286558 and one-item construct 0x882863D0, inline per-item destroy 0x8827C828. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); LTCG inlines the out-of-line helpers (43 off). */
typedef struct Str { const char *text; int w1, w2; } Str;
typedef struct Item { Str s; int a, b; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_8817F480(void *alloc, unsigned n);
Item *fn_88286558(Item *first, Item *last, Item *dest);
void ts4_if_call_seq_u32_off0_882863D0(Item *dest, const Item *src);
void ts4_assign_formatted_text(Str *dst, const char *text);
void ts4_if_get_u32_offc_8827C828(Item *p);
void ts4_destroy_owned_object(void *p);
static __inline void destroy_range(Item *first, Item *last)
{
    for (; first != last; ++first)
        ts4_if_get_u32_offc_8827C828(first);
}
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) {
            ts4_assign_formatted_text(&dest->s, val->s.text);
            dest->a = val->a;
            dest->b = val->b;
        }
    return dest;
}
void ts4_vector_realloc_insert_88283490(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&v->cap, newcap) : 0;
    Item *d;
    d = fn_88286558(v->begin, where, nb);
    if (n == 1) {
        ts4_if_call_seq_u32_off0_882863D0(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = fn_88286558(where, v->end, d);
    destroy_range(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
