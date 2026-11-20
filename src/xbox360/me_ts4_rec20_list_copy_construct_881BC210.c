/* Swing_DLL.xex 0x881BC210: copy constructor of {four words; vector<20-byte POD>}.
 * /Oc. Aggregate copy-ctor template (inlined vector copy with the end zero store through the end-slot pointer). */
typedef struct Rec20 { unsigned int w[5]; } Rec20;
typedef struct Rec20Vec { Rec20 *first; Rec20 *last; Rec20 *end; } Rec20Vec;
Rec20 *ts4_if_call_seq_u32_lbl_88D45B38_8817F480(Rec20 **owner, unsigned int n);
typedef struct Rec20List { unsigned int w[4]; Rec20Vec items; } Rec20List;

static __inline Rec20 *rec20_ucopy(const Rec20 *first, const Rec20 *last, Rec20 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void rec20_vec_copy(Rec20Vec *v, const Rec20Vec *src)
{
    unsigned int n = src->last - src->first;
    Rec20 **end_slot = &v->end;
    Rec20 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_8817F480(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = rec20_ucopy(src->first, src->last, v->first);
}

Rec20List *fn_881BC210(Rec20List *t, const Rec20List *src)
{
    t->w[0] = src->w[0];
    t->w[1] = src->w[1];
    t->w[2] = src->w[2];
    t->w[3] = src->w[3];
    rec20_vec_copy(&t->items, &src->items);
    return t;
}
