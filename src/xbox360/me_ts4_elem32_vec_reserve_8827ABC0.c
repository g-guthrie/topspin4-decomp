/* Swing_DLL.xex 0x8827ABC0: vector<32-byte element>::reserve(0x5): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88162950), uninitialized copy (fn_8827A130), destroy old elements (fn_8827B778), release the old block.
 * /Oc. Reserve template with an element destroy loop that re-reads v->first/v->last; see agAJ notes in matching-tips.md. */
typedef struct Elem32 { unsigned char body[32]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88162950(Elem **owner, unsigned int n);
Elem *fn_8827A130(Elem *dest, const Elem *src);
void fn_8827B778(void *p);
void ts4_destroy_owned_object(void *obj);

static __inline void destroy_range(Elem *first, Elem *last)
{
    for (; first != last; ++first) fn_8827B778(first);
}

void fn_8827ABC0(ElemVec *v)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < 0x5) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ts4_if_call_seq_u32_lbl_88D45B38_88162950(&v->end, 0x5);
            {
                Elem *src = first;
                Elem *dest = buffer;
                for (; src != last; ++src) {
                    if (dest) fn_8827A130(dest, src);
                    ++dest;
                }
            }
            first = buffer;
            destroy_range(v->first, v->last);
            ts4_destroy_owned_object(v->first);
        } else {
            first = ts4_if_call_seq_u32_lbl_88D45B38_88162950(&v->end, 0x5);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + 0x5;
    }
}
