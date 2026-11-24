/* Swing_DLL.xex 0x88216198: vector<64-byte element>::reserve(0x60): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88214848), uninitialized copy (fn_882166D0), destroy old elements (fn_887BA228), release the old block.
 * /Oc. Reserve template with an element destroy loop that re-reads v->first/v->last; see agAJ notes in matching-tips.md. */
typedef struct Elem64 { unsigned char body[64]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88214848(Elem **owner, unsigned int n);
Elem *fn_882166D0(Elem *dest, const Elem *src);
void fn_887BA228(void *p);
void ts4_destroy_owned_object(void *obj);

static __inline void destroy_range(Elem *first, Elem *last)
{
    for (; first != last; ++first) fn_887BA228(first);
}

void fn_88216198(ElemVec *v)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < 0x60) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88214848(&v->end, 0x60);
            {
                Elem *src = first;
                Elem *dest = buffer;
                for (; src != last; ++src) {
                    if (dest) fn_882166D0(dest, src);
                    ++dest;
                }
            }
            first = buffer;
            destroy_range(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = ts4_if_call_seq_u32_lbl_88D45B38_88214848(&v->end, 0x60);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + 0x60;
    }
}
