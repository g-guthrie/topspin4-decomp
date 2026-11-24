/* Swing_DLL.xex 0x8890EBB8: reserves 32 pairs in the vector at +4 (heap allocator via ts4_if_call_seq_fn_88883CD0_8860D250/fn_88613570, element copy, ts4_destroy_owned_object), then calls fn_8890EA30 on the owner.
 * /Oc. Forceinline allocate/reserve; the copy loop is written in place (src walk with a separate dest). */
typedef struct Pair { unsigned int a; unsigned int b; } Pair;
typedef struct UVec { Pair *first; Pair *last; Pair *end; } UVec;
typedef struct Owner { unsigned int f0; UVec items; } Owner;
void fn_8890EA30(Owner *o);
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
void ts4_destroy_owned_object(void *obj);

static __forceinline Pair *allocate(UVec *v, unsigned int n)
{
    return (Pair *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, n * sizeof(Pair), 4, &v->end);
}

static __forceinline void reserve(UVec *v, unsigned int n)
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

void fn_8890EBB8(Owner *o)
{
    reserve(&o->items, 32);
    fn_8890EA30(o);
}
