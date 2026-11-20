/* Swing_DLL.xex 0x88163238: vector<96-byte element>::reserve(0x78): allocate (ts4_if_call_seq_u32_lbl_88D45B38_881624B8), uninitialized copy (ts4_call_seq_fn_8815ED78_88166A10), destroy old elements (ts4_loop_call_seq_u32_offc_881661F8), release the old block.
 * /Oc. Reserve template with an element destroy step that re-reads v->first/v->last; see agAJ notes in matching-tips.md. */
typedef struct Elem96 { unsigned char body[96]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_881624B8(Elem **owner, unsigned int n);
Elem *ts4_call_seq_fn_8815ED78_88166A10(Elem *dest, const Elem *src);
void ts4_loop_call_seq_u32_offc_881661F8(Elem *first, Elem *last);
void ts4_destroy_owned_object(void *obj);

void fn_88163238(ElemVec *v)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < 0x78) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ts4_if_call_seq_u32_lbl_88D45B38_881624B8(&v->end, 0x78);
            {
                Elem *src = first;
                Elem *dest = buffer;
                for (; src != last; ++src) {
                    if (dest) ts4_call_seq_fn_8815ED78_88166A10(dest, src);
                    ++dest;
                }
            }
            first = buffer;
            ts4_loop_call_seq_u32_offc_881661F8(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = ts4_if_call_seq_u32_lbl_88D45B38_881624B8(&v->end, 0x78);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + 0x78;
    }
}
