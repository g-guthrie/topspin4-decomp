/* Swing_DLL.xex 0x88235D80: copy constructor of an allocator-handle vector<unsigned int> {first; last; alloc; end}: default allocator temp (88255AA0), zero, init the alloc slot, allocate via fn_88613570(alloc, .., &alloc), memmove.
 * /Oc near miss, 2 off: the end zero store and the n == 0 test are swapped. Writing the alloc slot through a scoped pointer fixed 15 of 17; siblings 88162768 (12 off), 882400F8, 88255C08, 8825EB00, 88260C58, 88261188-88261530 share the shape. */
typedef struct U32AVec { unsigned int *first; unsigned int *last; unsigned int alloc; unsigned int *end; } U32AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline unsigned int *u32_ucopy(const unsigned int *first, const unsigned int *last, unsigned int *dest)
{
    unsigned int bytes;
    if (last == first) return dest;
    bytes = (const char *)last - (const char *)first;
    return (unsigned int *)((char *)fn_88562DC0(dest, first, bytes) + bytes);
}

U32AVec *fn_88235D80(U32AVec *v, const U32AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    unsigned int *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    {
        unsigned int *alloc = &v->alloc;
        *alloc = 0;
        ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(alloc);
    }
    v->end = 0;
    p = 0;
    if (n != 0) p = (unsigned int *)fn_88613570(v->alloc, n * sizeof(unsigned int), 4, &v->alloc);
    v->first = p;
    v->last = p;
    v->end = p + n;
    v->last = u32_ucopy(src->first, src->last, v->first);
    return v;
}
