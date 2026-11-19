/* Swing_DLL.xex 0x881B6E00: vector<vector<8-byte pair>> copy constructor: zero, allocate size(src), copy-construct each inner vector (881B6A80).
 * /Oc. Copy-ctor template of 88166C58 (end zero store through the end-slot pointer). */
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Elem { Pair8 *first; Pair8 *last; Pair8 *end; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
void fn_881B6A80(Elem *dest, const Elem *src);
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem **owner, unsigned int n);

static __inline Elem *elem_ucopy(const Elem *first, const Elem *last, Elem *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) fn_881B6A80(dest, first);
    return dest;
}

static __inline void elem_vec_construct_n(ElemVec *v, unsigned int n)
{
    Elem **end_slot = &v->end;
    Elem *p;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

ElemVec *fn_881B6E00(ElemVec *v, const ElemVec *src)
{
    elem_vec_construct_n(v, src->last - src->first);
    v->last = elem_ucopy(src->first, src->last, v->first);
    return v;
}
