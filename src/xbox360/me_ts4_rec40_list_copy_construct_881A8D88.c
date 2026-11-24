/* Swing_DLL.xex 0x881A8D88: copy constructor of {three words; vector<40-byte POD>}.
 * /Oc. Aggregate copy-ctor template: member copies, then an inlined vector copy (end zero store through the end-slot pointer). */
typedef struct Rec40 { unsigned int w[10]; } Rec40;
typedef struct Rec40Vec { Rec40 *first; Rec40 *last; Rec40 *end; } Rec40Vec;
Rec40 *ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(Rec40 **owner, unsigned int n);
typedef struct Rec40List { unsigned int a; unsigned int b; unsigned int c; Rec40Vec items; } Rec40List;

static __inline Rec40 *rec40_ucopy(const Rec40 *first, const Rec40 *last, Rec40 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void rec40_vec_copy(Rec40Vec *v, const Rec40Vec *src)
{
    unsigned int n = src->last - src->first;
    Rec40 **end_slot = &v->end;
    Rec40 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = rec40_ucopy(src->first, src->last, v->first);
}

Rec40List *fn_881A8D88(Rec40List *t, const Rec40List *src)
{
    t->a = src->a;
    t->b = src->b;
    t->c = src->c;
    rec40_vec_copy(&t->items, &src->items);
    return t;
}
