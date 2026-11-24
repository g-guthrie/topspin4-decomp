/* Swing_DLL.xex 0x8822A3D8: vector<unsigned short>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_8815C920), memmove the old elements, release the old block.
 * /Oc. size is v->last - v->first (re-read) so the memmove length is a separate subf. */
typedef unsigned short Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_8815C920(Elem **owner, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *obj);

static __inline void copy_elems(Elem *first, Elem *last, Elem *dest)
{
    if (last != first) fn_88562DC0(dest, first, (char *)last - (char *)first);
}

void fn_8822A3D8(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = v->last - v->first;
        if (first != 0) {
            Elem *buffer = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_8815C920(&v->end, n) : 0;
            copy_elems(first, last, buffer);
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_8815C920(&v->end, n) : 0;
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
