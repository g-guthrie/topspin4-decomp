/* Swing_DLL.xex 0x88166428: construct(p, vector<12-byte POD>): if p is non-null, copy-construct the vector from src.
 * /Oc. Copy-ctor template inside a null test, returns nothing; word-wise element copy (struct assignment is 2 off). */
typedef struct Elem { unsigned int w[3]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem **owner, unsigned int n);

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
    p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
    v->first = p;
    v->last = p;
    v->end = p + n;
}

void fn_88166428(ElemVec *v, const ElemVec *src)
{
    if (v) {
        elem_vec_construct_n(v, src->last - src->first);
        v->last = elem_ucopy(src->first, src->last, v->first);
    }
}
