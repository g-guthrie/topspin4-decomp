/* Swing_DLL.xex 0x881A6D80: vector<64-byte element of eight 64-bit words>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_881A6B90), struct-copy each element (ldu/stdu loop), release the old block.
 * /Oc. 8-byte member type gives the ld/std copy; runtime-count reserve template. */
typedef struct Elem64 { unsigned __int64 q[8]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_881A6B90(Elem **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);
#define ALLOC_VAR(v, n) ((n) != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_881A6B90(&(v)->end, (n)) : 0)

void fn_881A6D80(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ALLOC_VAR(v, n);
            Elem *src = first;
            Elem *dest = buffer;
            for (; src != last; ++src) {
                if (dest) *dest = *src;
                ++dest;
            }
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = ALLOC_VAR(v, n);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
