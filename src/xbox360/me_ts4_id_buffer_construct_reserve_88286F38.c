/* Swing_DLL.xex 0x88286F38: constructor of {vector<unsigned int>; dirty byte; cursor}: zero the vector, reserve(n) (memmove copy), clear dirty and cursor.
 * /Oc. The end zero store goes through a pointer to the end slot, which keeps first/last reloaded in the inlined reserve (plain stores fold it). */
typedef unsigned int Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
typedef struct IdBuffer { ElemVec ids; unsigned char dirty; unsigned int cursor; } IdBuffer;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88162340(Elem **owner, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *obj);

static __inline void copy_elems(Elem *first, Elem *last, Elem *dest)
{
    if (last != first) fn_88562DC0(dest, first, (char *)last - (char *)first);
}

static __inline void elem_vec_reserve(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = v->last - v->first;
        Elem *p;
        if (first != 0) {
            p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->end, n) : 0;
            copy_elems(first, last, p);
            ts4_destroy_owned_object(v->first);
        } else {
            p = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->end, n) : 0;
        }
        v->first = p;
        v->last = p + size;
        v->end = p + n;
    }
}

IdBuffer *fn_88286F38(IdBuffer *b, unsigned int n)
{
    Elem **end_slot = &b->ids.end;
    b->ids.first = 0;
    b->ids.last = 0;
    *end_slot = 0;
    elem_vec_reserve(&b->ids, n);
    b->dirty = 0;
    b->cursor = 0;
    return b;
}
