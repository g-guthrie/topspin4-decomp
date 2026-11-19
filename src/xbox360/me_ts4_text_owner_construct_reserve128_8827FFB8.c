/* Swing_DLL.xex 0x8827FFB8: constructor: zero the u32 vector at +0x800, clear the 0x800-byte text, store self at +0x80C, reserve 128 slots (heap allocator inlined).
 * /Oc. The vector init stores end through a pointer to the end slot (fixes the +0x804/+0x808 order and keeps first reloaded); allocate and reserve are __forceinline. */
typedef struct UVec { unsigned int *first; unsigned int *last; unsigned int *end; } UVec;
typedef struct Owner { char text[0x800]; UVec items; struct Owner *self; } Owner;
extern void *lbl_88D45B38;
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

static __inline void uvec_init(UVec *v)
{
    unsigned int **end_slot = &v->end;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
}

Owner *fn_8827FFB8(Owner *o)
{
    uvec_init(&o->items);
    o->text[0] = 0;
    o->self = o;
    reserve(&o->items, 128);
    return o;
}
