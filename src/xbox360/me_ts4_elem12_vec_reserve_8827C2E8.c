/* Swing_DLL.xex 0x8827C2E8: vector<12-byte element>::reserve(0x20): allocate through ts4_if_call_seq_u32_lbl_88D45B38_88263C98, uninitialized copy, release the old block.
 * /Oc. d1_big1_vector_reserve_family.c template (src walk with a separate dest pointer). */
typedef struct Elem12 { unsigned int w[3]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(Elem **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);
#define ALLOC_CONST(v, n) ts4_if_call_seq_u32_lbl_88D45B38_88263C98(&(v)->end, (n))

void fn_8827C2E8(ElemVec *v)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < 0x20) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ALLOC_CONST(v, 0x20);
            Elem *src = first;
            Elem *dest = buffer;
            for (; src != last; ++src) {
                if (dest) { int k; for (k = 0; k < 3; k++) dest->w[k] = src->w[k]; }
                ++dest;
            }
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = ALLOC_CONST(v, 0x20);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + 0x20;
    }
}
