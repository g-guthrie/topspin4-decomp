/* Swing_DLL.xex 0x88166728: uninitialized_copy of a range of vector<12-byte POD>: copy-construct each vector (heap allocator fn_88613570 inlined).
 * /Oc. p starts at 0 and the allocation is an if (n != 0) assignment (the ternary schedules mr r3 later); end zero store through the end-slot pointer. */
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);

static __inline Elem12 *elem12_allocate(Elem12 **owner, unsigned int n)
{
    return (Elem12 *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, n * sizeof(Elem12), 4, owner);
}

static __inline Elem12 *elem12_ucopy(const Elem12 *first, const Elem12 *last, Elem12 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void elem12_vec_copy(Elem12Vec *v, const Elem12Vec *src)
{
    unsigned int n = src->last - src->first;
    Elem12 **end_slot = &v->end;
    Elem12 *p = 0;
    v->first = 0;
    v->last = 0;
    *end_slot = 0;
    if (n != 0) p = elem12_allocate(&v->end, n);
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = elem12_ucopy(src->first, src->last, v->first);
}

Elem12Vec *fn_88166728(const Elem12Vec *first, const Elem12Vec *last, Elem12Vec *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) elem12_vec_copy(dest, first);
    return dest;
}
