/* 0x88182420: std::vector of 20-byte {a, text, e} items reallocating insert: out-of-line uninit copy 0x88185E50 and one-item copy 0x88185DF8, range destroy 0x88181670; direct allocator 0x8817F480. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); LTCG is 48 off. Adapted from 0x88283490. */
typedef struct Str { const char *text; int w1, w2; } Str;
typedef struct Item { int a; Str s; int e; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
Item *ts4_if_call_seq_u32_lbl_88D45B38_8817F480(void *alloc, unsigned n);
Item *ts4_uninit_copy_text_88185E50(Item *first, Item *last, Item *dest);
void ts4_copy_text_obj_88185DF8(Item *dest, const Item *src);
void ts4_assign_formatted_text(Str *dst, const char *text);
void ts4_loop_call_seq_u32_0x4_88181670(Item *first, Item *last);
void ts4_destroy_owned_object(void *p);
static __inline Item *ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) {
            dest->a = val->a;
            ts4_assign_formatted_text(&dest->s, val->s.text);
            dest->e = val->e;
        }
    return dest;
}
void ts4_vector_realloc_insert_88182420(Vec *v, Item *where, const Item *val, unsigned n)
{
    unsigned size = v->end - v->begin;
    unsigned newcap = size + *(size < n ? &n : &size);
    Item *nb = newcap ? ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&v->cap, newcap) : 0;
    Item *d;
    d = ts4_uninit_copy_text_88185E50(v->begin, where, nb);
    if (n == 1) {
        ts4_copy_text_obj_88185DF8(d, val);
        d++;
    } else {
        d = ufill(d, n, val);
    }
    d = ts4_uninit_copy_text_88185E50(where, v->end, d);
    ts4_loop_call_seq_u32_0x4_88181670(v->begin, v->end);
    ts4_destroy_owned_object(v->begin);
    v->begin = nb;
    v->end = d;
    v->cap = nb + newcap;
}
