/* Swing_DLL.xex 0x88215F60: vector<8-byte element>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88263C38), uninitialized copy (fn_882165A8), destroy old elements (ts4_loop_call_seq_u32_off4_88219840), release the old block.
 * /Oc. Reserve template with an element destroy step that re-reads v->first/v->last; see agAJ notes in matching-tips.md. */
typedef struct Elem8 { unsigned char body[8]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(Elem **owner, unsigned int n);
Elem *fn_882165A8(Elem *first, Elem *last, Elem *dest);
void ts4_loop_call_seq_u32_off4_88219840(Elem *first, Elem *last);
void ts4_destroy_owned_object(void *obj);

void fn_88215F60(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->end, n) : 0;
            fn_882165A8(first, last, buffer);
            first = buffer;
            ts4_loop_call_seq_u32_off4_88219840(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->end, n) : 0;
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
