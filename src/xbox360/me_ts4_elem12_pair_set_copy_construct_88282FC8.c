/* Swing_DLL.xex 0x88282FC8: copy constructor of {id; kind; vector<12-byte POD>; vector<8-byte pair>; four flag bytes}.
 * /Oc. Two inlined vector copies (end zero store through the end-slot pointer); the 12-byte vector stores last before first. */
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
Elem12 *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem12 **owner, unsigned int n);
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Pair8Vec { Pair8 *first; Pair8 *last; Pair8 *end; } Pair8Vec;
Pair8 *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(Pair8 **owner, unsigned int n);
typedef struct Elem12PairSet { unsigned int id; unsigned int kind; Elem12Vec items; Pair8Vec pairs; unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; } Elem12PairSet;

static __inline Elem12 *elem12_ucopy(const Elem12 *first, const Elem12 *last, Elem12 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void elem12_vec_copy(Elem12Vec *v, const Elem12Vec *src)
{
    unsigned int n = src->last - src->first;
    Elem12 **end_slot = &v->end;
    Elem12 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
    v->last = p;
    v->first = p;
    v->end = p + n;
    v->last = elem12_ucopy(src->first, src->last, v->first);
}
static __inline Pair8 *pair8_ucopy(const Pair8 *first, const Pair8 *last, Pair8 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void pair8_vec_copy(Pair8Vec *v, const Pair8Vec *src)
{
    unsigned int n = src->last - src->first;
    Pair8 **end_slot = &v->end;
    Pair8 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = pair8_ucopy(src->first, src->last, v->first);
}

Elem12PairSet *fn_88282FC8(Elem12PairSet *t, const Elem12PairSet *src)
{
    t->id = src->id;
    t->kind = src->kind;
    elem12_vec_copy(&t->items, &src->items);
    pair8_vec_copy(&t->pairs, &src->pairs);
    t->f0 = src->f0;
    t->f1 = src->f1;
    t->f2 = src->f2;
    t->f3 = src->f3;
    return t;
}
