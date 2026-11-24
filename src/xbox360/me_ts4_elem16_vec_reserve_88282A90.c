/* Swing_DLL.xex 0x88282A90: vector<16-byte element>::reserve(n): allocate through ts4_if_call_seq_u32_lbl_88D45B38_8827A758, element-wise uninitialized copy, release the old block (ts4_destroy_owned_object).
 * /Oc. Runtime-count form of d1_big1_vector_reserve_family.c: allocate is n != 0 ? alloc : 0; copy loop walks src with a separate dest. */
typedef struct Elem16 { unsigned int w[4]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_8827A758(Elem **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);
#define ALLOC_VAR(v, n) ((n) != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_8827A758(&(v)->end, (n)) : 0)

void fn_88282A90(ElemVec *v, unsigned int n)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ALLOC_VAR(v, n);
            Elem *src = first;
            Elem *dest = buffer;
            for (; src != last; ++src) {
                if (dest) *dest = *src;
                ++dest;
            }
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = ALLOC_VAR(v, n);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
