/* Swing_DLL.xex 0x882642E0: vector<8-byte pair>::reserve(n): allocate through the global heap (ts4_if_call_seq_u32_lbl_88D45B38_88263C38), element-wise uninitialized copy, release the old block.
 * /Oc. Template of d1_big1_vector_reserve_family.c with a runtime count: allocate is n != 0 ? alloc : 0. */
typedef struct Pair { unsigned int a; unsigned int b; } Pair;
typedef struct PairVec { Pair *first; Pair *last; Pair *end; } PairVec;
Pair *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(Pair **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);

static __inline Pair *allocate(PairVec *v, unsigned int n)
{
    return n != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88263C38(&v->end, n) : 0;
}

void fn_882642E0(PairVec *v, unsigned int n)
{
    Pair *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        Pair *last = v->last;
        int size = last - first;
        if (first != 0) {
            Pair *buffer = allocate(v, n);
            Pair *src = first;
            Pair *dest = buffer;
            for (; src != last; ++src) {
                if (dest) *dest = *src;
                ++dest;
            }
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = allocate(v, n);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}
