/* Swing_DLL.xex 0x88181910: copy constructor of {two words; vector<8-byte pair>}.
 * /Oc. Aggregate copy-ctor template with p = 0 then if (n != 0) p = alloc (the ternary swaps the first/last stores); end zero store through the end-slot pointer. */
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Pair8Vec { Pair8 *first; Pair8 *last; Pair8 *end; } Pair8Vec;
Pair8 *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(Pair8 **owner, unsigned int n);
typedef struct Pair8List { unsigned int a; unsigned int b; Pair8Vec items; } Pair8List;

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
    Pair8 *p = 0;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    if (n != 0) p = ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->end, n);
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = pair8_ucopy(src->first, src->last, v->first);
}

Pair8List *fn_88181910(Pair8List *t, const Pair8List *src)
{
    t->a = src->a;
    t->b = src->b;
    pair8_vec_copy(&t->items, &src->items);
    return t;
}
