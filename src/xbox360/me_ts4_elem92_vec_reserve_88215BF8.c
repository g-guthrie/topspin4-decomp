/* Swing_DLL.xex 0x88215BF8: vector<92-byte element>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_882148A8), uninitialized copy (ts4_e5c_ucopy_88216528), destroy the old elements' +4 member (ts4_if_call_seq_u32_offc_882124A8), release the old block.
 * /Oc. first = buffer is assigned before the destroy loop, which re-reads v->first/v->last. */
typedef struct Elem92 { unsigned int key; unsigned int w[22]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_882148A8(Elem **owner, unsigned int n);
Elem *ts4_e5c_ucopy_88216528(Elem *first, Elem *last, Elem *dest);
void ts4_if_call_seq_u32_offc_882124A8(void *sub);
void ts4_destroy_owned_object(void *obj);

static __inline void destroy_range(Elem *first, Elem *last)
{
    for (; first != last; ++first) ts4_if_call_seq_u32_offc_882124A8(&first->w[0]);
}

void fn_88215BF8(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_882148A8(&v->end, n) : 0;
            ts4_e5c_ucopy_88216528(first, last, buffer);
            first = buffer;
            destroy_range(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_882148A8(&v->end, n) : 0;
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
