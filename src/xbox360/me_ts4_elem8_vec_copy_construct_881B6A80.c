/* Swing_DLL.xex 0x881B6A80: vector<8-byte POD element> copy constructor: zero, allocate size(src), copy each element.
 * /Oc. Copy-ctor template of 88166C58 (end zero store through the end-slot pointer). */
typedef struct Elem { unsigned int a; unsigned int b; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(Elem **owner, unsigned int n);

static __inline Elem *elem_ucopy(const Elem *first, const Elem *last, Elem *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void elem_vec_construct_n(ElemVec *v, unsigned int n)
{
    Elem **end_slot = &v->end;
    Elem *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

ElemVec *fn_881B6A80(ElemVec *v, const ElemVec *src)
{
    elem_vec_construct_n(v, src->last - src->first);
    v->last = elem_ucopy(src->first, src->last, v->first);
    return v;
}
