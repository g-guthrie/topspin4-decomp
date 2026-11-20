/* Swing_DLL.xex 0x881A8AB0: vector<80-byte element>::reserve(n): allocate (ts4_if_call_seq_u32_lbl_88D45B38_88187638), copy-construct the 76-byte head (fn_88166AF8) and the trailing word, release the old block.
 * /Oc. Runtime-count reserve template; the element copy is an inline ctor that calls the member copy and assigns the last field. */
typedef struct Inner76 { unsigned int w[19]; } Inner76;
typedef struct Elem80 { Inner76 inner; unsigned int extra; } Elem;
typedef struct ElemVec { Elem *first; Elem *last; Elem *end; } ElemVec;
Elem *ts4_if_call_seq_u32_lbl_88D45B38_88187638(Elem **owner, unsigned int n);
void ts4_destroy_owned_object(void *obj);
Inner76 *fn_88166AF8(Inner76 *dest, const Inner76 *src);
#define ALLOC_VAR(v, n) ((n) != 0 ? ts4_if_call_seq_u32_lbl_88D45B38_88187638(&(v)->end, (n)) : 0)

void fn_881A8AB0(ElemVec *v, unsigned int n)
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
                    fn_88166AF8(&dest->inner, &src->inner);
                    dest->extra = src->extra;
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
