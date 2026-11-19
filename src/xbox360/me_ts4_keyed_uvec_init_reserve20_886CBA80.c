/* Swing_DLL.xex 0x886CBA80: stores the key at +0x18, reserves 20 u32 slots in the vector at +4 (heap allocator via ts4_if_call_seq_fn_88883CD0_8860D250/fn_88613570, memmove, ts4_destroy_owned_object) and resets the value at +0x10 to lbl_8814B440.
 * /Oc. allocate and reserve must be __forceinline (the allocator is expanded twice). */
typedef struct UVec { unsigned int *first; unsigned int *last; unsigned int *end; } UVec;
typedef struct Owner { unsigned int f0; UVec items; float value; unsigned int f14; unsigned int key; } Owner;
extern void *lbl_88D45B38;
extern const float lbl_8814B440;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_destroy_owned_object(void *obj);

static __forceinline unsigned int *allocate(UVec *v, unsigned int n)
{
    return (unsigned int *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, n * sizeof(unsigned int), 4, &v->end);
}

static __inline void copy_elems(unsigned int *first, unsigned int *last, unsigned int *dest)
{
    if (last != first) fn_88562DC0(dest, first, (char *)last - (char *)first);
}

static __forceinline void reserve(UVec *v, unsigned int n)
{
    unsigned int *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        unsigned int *last = v->last;
        int size = v->last - v->first;
        if (first != 0) {
            unsigned int *buffer = allocate(v, n);
            copy_elems(first, last, buffer);
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

void fn_886CBA80(Owner *o, unsigned int key)
{
    o->key = key;
    reserve(&o->items, 20);
    o->value = lbl_8814B440;
}
