/* Swing_DLL.xex 0x881FB710: vector<4-byte element>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88162340), uninitialized copy (ts4_copy_strs_881FB7F8), destroy old elements (ts4_call_seq_u32_off0_881A2570), release the old block.
 * /Oc. Reserve template with an element destroy loop that re-reads v->first/v->last; see agAJ notes in matching-tips.md. */
typedef struct Elem4 { unsigned char body[4]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88162340(Elem **owner, unsigned int n);
Elem *ts4_copy_strs_881FB7F8(Elem *first, Elem *last, Elem *dest);
void ts4_call_seq_u32_off0_881A2570(void *p);
void ts4_destroy_owned_object(void *obj);

static __inline void destroy_range(Elem *first, Elem *last)
{
    for (; first != last; ++first) ts4_call_seq_u32_off0_881A2570(first);
}

void fn_881FB710(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->end, n) : 0;
            ts4_copy_strs_881FB7F8(first, last, buffer);
            first = buffer;
            destroy_range(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->end, n) : 0;
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
