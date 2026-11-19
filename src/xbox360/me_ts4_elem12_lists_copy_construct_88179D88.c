/* Swing_DLL.xex 0x88179D88: copy constructor of {vector<12-byte>; vector<8-byte pair> x2; flags}: three inlined vector copy constructors, then the flags word.
 * /Oc. The vector copies must be __forceinline (the pair copy is expanded twice); end zero store through the end-slot pointer. */
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Pair8Vec { Pair8 *first; Pair8 *last; Pair8 *end; } Pair8Vec;
typedef struct Elem12Lists { Elem12Vec items; Pair8Vec ranges; Pair8Vec links; unsigned int flags; } Elem12Lists;
Elem12 *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem12 **owner, unsigned int n);
Pair8 *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(Pair8 **owner, unsigned int n);

static __inline Elem12 *elem12_ucopy(const Elem12 *first, const Elem12 *last, Elem12 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __forceinline void elem12_vec_copy(Elem12Vec *v, const Elem12Vec *src)
{
    unsigned int n = src->last - src->first;
    Elem12 **end_slot = &v->end;
    Elem12 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = elem12_ucopy(src->first, src->last, v->first);
}

static __inline Pair8 *pair8_ucopy(const Pair8 *first, const Pair8 *last, Pair8 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __forceinline void pair8_vec_copy(Pair8Vec *v, const Pair8Vec *src)
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

Elem12Lists *fn_88179D88(Elem12Lists *t, const Elem12Lists *src)
{
    elem12_vec_copy(&t->items, &src->items);
    pair8_vec_copy(&t->ranges, &src->ranges);
    pair8_vec_copy(&t->links, &src->links);
    t->flags = src->flags;
    return t;
}
