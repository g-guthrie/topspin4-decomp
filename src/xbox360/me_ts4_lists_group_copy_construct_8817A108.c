/* Swing_DLL.xex 0x8817A108: copy constructor of {vector<Elem12Lists>; vector<36-byte record>; six words; two bytes}: element copies call 88179D88 and 88179F80.
 * /Oc. Copy-ctor template twice (end zero store through the end-slot pointer), then member-wise tail copy. */
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Pair8Vec { Pair8 *first; Pair8 *last; Pair8 *end; } Pair8Vec;
typedef struct Elem12Lists { Elem12Vec items; Pair8Vec ranges; Pair8Vec links; unsigned int flags; } Elem12Lists;
typedef struct Elem12ListsVec { Elem12Lists *first; Elem12Lists *last; Elem12Lists *end; } Elem12ListsVec;
typedef struct Rec36 { unsigned int w[9]; } Rec36;
typedef struct Rec36Vec { Rec36 *first; Rec36 *last; Rec36 *end; } Rec36Vec;
typedef struct ListsGroup { Elem12ListsVec lists; Rec36Vec recs; unsigned int w[6]; unsigned char b0; unsigned char b1; } ListsGroup;
Elem12Lists *ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(Elem12Lists **owner, unsigned int n);
Rec36 *ts4_if_call_seq_u32_lbl_88D45B38_88162A18(Rec36 **owner, unsigned int n);
Elem12Lists *fn_88179D88(Elem12Lists *t, const Elem12Lists *src);
Rec36 *fn_88179F80(Rec36 *t, const Rec36 *src);

static __inline Elem12Lists *lists_ucopy(const Elem12Lists *first, const Elem12Lists *last, Elem12Lists *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) fn_88179D88(dest, first);
    return dest;
}

static __inline void lists_vec_copy(Elem12ListsVec *v, const Elem12ListsVec *src)
{
    unsigned int n = src->last - src->first;
    Elem12Lists **end_slot = &v->end;
    Elem12Lists *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = lists_ucopy(src->first, src->last, v->first);
}

static __inline Rec36 *rec36_ucopy(const Rec36 *first, const Rec36 *last, Rec36 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) fn_88179F80(dest, first);
    return dest;
}

static __inline void rec36_vec_copy(Rec36Vec *v, const Rec36Vec *src)
{
    unsigned int n = src->last - src->first;
    Rec36 **end_slot = &v->end;
    Rec36 *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162A18(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = rec36_ucopy(src->first, src->last, v->first);
}

ListsGroup *fn_8817A108(ListsGroup *t, const ListsGroup *src)
{
    lists_vec_copy(&t->lists, &src->lists);
    rec36_vec_copy(&t->recs, &src->recs);
    t->w[0] = src->w[0];
    t->w[1] = src->w[1];
    t->w[2] = src->w[2];
    t->w[3] = src->w[3];
    t->w[4] = src->w[4];
    t->w[5] = src->w[5];
    t->b0 = src->b0;
    t->b1 = src->b1;
    return t;
}
