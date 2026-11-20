/* Swing_DLL.xex 0x88162F40: vector<12-byte text string>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88263C98), copy-construct each string from its text (ts4_assign_formatted_text), destroy the old range (ts4_loop_call_seq_u32_off0_88150378), release the old block.
 * /Oc. Reserve template; the element copy passes src->p, so the call takes the char pointer, not the element. */
typedef struct Text { char *p; char *last; char *end; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem **owner, unsigned int n);
void ts4_assign_formatted_text(void *dst, void *src);
void ts4_loop_call_seq_u32_off0_88150378(Elem *first, Elem *last);
void ts4_destroy_owned_object(void *obj);

void fn_88162F40(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
            {
                Elem *src = first;
                Elem *dest = buffer;
                for (; src != last; ++src) {
                    if (dest) ts4_assign_formatted_text(dest, src->p);
                    ++dest;
                }
            }
            ts4_loop_call_seq_u32_off0_88150378(v->first, v->last);
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, n) : 0;
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
