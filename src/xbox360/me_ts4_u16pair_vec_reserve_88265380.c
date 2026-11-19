/* Swing_DLL.xex 0x88265380: vector<pair of u16>::reserve(64): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88263D00), struct-copy each element (two lhz/sth), release the old block.
 * /Oc. Constant-count reserve template (d1_big1_vector_reserve_family.c) with a 2x u16 element. */
typedef struct Elem4 { unsigned short h[2]; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88263D00(Elem **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);
#define ALLOC_CONST(v, n) ts4_if_call_seq_u32_lbl_88D45B38_88263D00(&(v)->end, (n))

void fn_88265380(ElemVec *v)
{
    Elem *first = v->first;
    if ((unsigned int)(v->end - first) < 0x40) {
        Elem *last = v->last;
        int size = last - first;
        if (first != 0) {
            Elem *buffer = ALLOC_CONST(v, 0x40);
            Elem *src = first;
            Elem *dest = buffer;
            for (; src != last; ++src) {
                if (dest) *dest = *src;
                ++dest;
            }
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = ALLOC_CONST(v, 0x40);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + 0x40;
    }
}
