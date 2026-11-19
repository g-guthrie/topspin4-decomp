/* Swing_DLL.xex 0x881798E0: vector<36-byte element>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88162A18), uninitialized copy (fn_88179F80), destroy old elements (fn_88178378), release the old block.
 * /Oc. Reserve template with an element destroy step that re-reads v->first/v->last; see agAJ notes in matching-tips.md. */
typedef struct Elem36 { unsigned char body[36]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88162A18(Elem **owner, unsigned int n);
Elem *fn_88179F80(Elem *dest, const Elem *src);
void fn_88178378(void *p);
void ts4_destroy_owned_object(void *obj);

static __inline void destroy_range(Elem *first, Elem *last)
{
    for (; first != last; ++first) fn_88178378(first);
}

void fn_881798E0(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162A18(&v->end, n) : 0;
            {
                Elem *src = first;
                Elem *dest = buffer;
                for (; src != last; ++src) {
                    if (dest) fn_88179F80(dest, src);
                    ++dest;
                }
            }
            first = buffer;
            destroy_range(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162A18(&v->end, n) : 0;
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
