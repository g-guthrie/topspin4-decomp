/* Swing_DLL.xex 0x88264F28: vector<pair of __vector4>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88267070), copy each element member-wise (lvx/stvx), release the old block.
 * /Oc. Member-wise __vector4 assignment keeps lvx128/stvx128 (struct assignment gives ld/std). */
#include "vx1_vector.h"
typedef struct Elem32 { __vector4 a; __vector4 b; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88267070(Elem **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);
#define ALLOC_VAR(v, n) ((n) != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88267070(&(v)->end, (n)) : 0)

void fn_88264F28(ElemVec *v, unsigned int n)
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
                if (dest) {
                    dest->a = src->a;
                    dest->b = src->b;
                }
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
