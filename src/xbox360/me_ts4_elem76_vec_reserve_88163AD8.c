/* Swing_DLL.xex 0x88163AD8: vector<76-byte element>::reserve(0x78): allocate through ts4_if_call_seq_u32_lbl_88D45B38_88162A80, uninitialized copy via fn_88166AF8, release the old block.
 * /Oc. d1_big1_vector_reserve_family.c template (src walk with a separate dest pointer). */
typedef struct Elem76 { unsigned int w[19]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88162A80(Elem **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);
Elem *fn_88166AF8(Elem *dest, const Elem *src);
#define ALLOC_CONST(v, n) ts4_if_call_seq_u32_lbl_88D45B38_88162A80(&(v)->end, (n))

void fn_88163AD8(ElemVec *v)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < 0x78) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ALLOC_CONST(v, 0x78);
            Elem *src = first;
            Elem *dest = buffer;
            for (; src != last; ++src) {
                if (dest) fn_88166AF8(dest, src);
                ++dest;
            }
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = ALLOC_CONST(v, 0x78);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + 0x78;
    }
}
