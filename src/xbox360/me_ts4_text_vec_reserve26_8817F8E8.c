/* Swing_DLL.xex 0x8817F8E8: vector<12-byte text string>::reserve(26): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88263C98), copy-construct each string from its text (ts4_assign_formatted_text), free each old text buffer, release the old block.
 * /Oc. Sibling of 88162F40 with the text destructor inlined (ts4_destroy_owned_object on the buffer). */
typedef struct Text { char *p; char *last; char *end; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem **owner, unsigned int n);
void ts4_assign_formatted_text(void *dst, void *src);
void ts4_destroy_owned_object(void *obj);

static __inline void text_destroy_range(Elem *first, Elem *last)
{
    for (; first != last; ++first) ts4_destroy_owned_object(first->p);
}

void fn_8817F8E8(ElemVec *v)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < 26) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, 26);
            {
                Elem *src = first;
                Elem *dest = buffer;
                for (; src != last; ++src) {
                    if (dest) ts4_assign_formatted_text(dest, src->p);
                    ++dest;
                }
            }
            first = buffer;
            text_destroy_range(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&v->end, 26);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + 26;
    }
}
