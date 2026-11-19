/* Swing_DLL.xex 0x88171088: copy constructor of {vector<16-byte POD>; tag word}.
 * /Oc. Vector copy is an inline taking &src->items with the end zero store through the end-slot pointer (direct member code is 2 off). */
typedef struct Elem16 { unsigned int a; unsigned int b; unsigned int c; unsigned int d; } Elem16;
typedef struct Elem16Vec { Elem16 *first; Elem16 *last; Elem16 *end; } Elem16Vec;
Elem16 *ts4_if_call_seq_u32_lbl_88D45B38_8827A758(Elem16 **owner, unsigned int n);
typedef struct Elem16List { Elem16Vec items; unsigned int tag; } Elem16List;

static __inline Elem16 *elem16_ucopy(const Elem16 *first, const Elem16 *last, Elem16 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void elem16_vec_copy(Elem16Vec *v, const Elem16Vec *src)
{
    unsigned int n = src->last - src->first;
    Elem16 **end_slot = &v->end;
    Elem16 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = elem16_ucopy(src->first, src->last, v->first);
}

Elem16List *fn_88171088(Elem16List *t, const Elem16List *src)
{
    elem16_vec_copy(&t->items, &src->items);
    t->tag = src->tag;
    return t;
}
