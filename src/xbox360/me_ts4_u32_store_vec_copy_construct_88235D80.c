/* Swing_DLL.xex 0x88235D80: copy constructor of an allocator-handle vector<unsigned int> {first; last; {alloc; end}}: default allocator temp (88255AA0), zero, init the {alloc, end} store, allocate via fn_88613570(alloc, .., &alloc), memmove.
 * /Oc. The alloc handle and end are one struct initialised by an inline through its pointer (fixes the end-store / n-test order). */
typedef struct U32Store { unsigned int alloc; unsigned int *end; } U32Store;
typedef struct U32AVec { unsigned int *first; unsigned int *last; U32Store store; } U32AVec;
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

static __inline void u32_store_init(U32Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
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
    u32_store_init(&v->store);
    p = 0;
    if (n != 0) p = (unsigned int *)fn_88613570(v->store.alloc, n * sizeof(unsigned int), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = u32_ucopy(src->first, src->last, v->first);
    return v;
}
