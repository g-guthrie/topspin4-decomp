/* Swing_DLL.xex 0x88162E48: vector<48-byte element>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_881884E0), uninitialized copy (ts4_call_seq_u32_off0_8815ED78), destroy old elements (ts4_loop_call_seq_u32_off18_88165F68), release the old block.
 * /Oc. Reserve template with an element destroy step that re-reads v->first/v->last; see agAJ notes in matching-tips.md. */
typedef struct Elem48 { unsigned char body[48]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_881884E0(Elem **owner, unsigned int n);
Elem *ts4_call_seq_u32_off0_8815ED78(Elem *dest, const Elem *src);
void ts4_loop_call_seq_u32_off18_88165F68(Elem *first, Elem *last);
void ts4_destroy_owned_object(void *obj);

void fn_88162E48(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_881884E0(&v->end, n) : 0;
            {
                Elem *src = first;
                Elem *dest = buffer;
                for (; src != last; ++src) {
                    if (dest) ts4_call_seq_u32_off0_8815ED78(dest, src);
                    ++dest;
                }
            }
            first = buffer;
            ts4_loop_call_seq_u32_off18_88165F68(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_881884E0(&v->end, n) : 0;
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
