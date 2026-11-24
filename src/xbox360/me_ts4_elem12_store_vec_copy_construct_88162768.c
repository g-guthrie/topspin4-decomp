/* Swing_DLL.xex 0x88162768: copy constructor of an allocator-handle vector<12-byte POD> {first; last; {alloc; end}} (same shape as 88235D80).
 * /Oc. The alloc handle and end are one struct initialised by an inline through its pointer. */
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Store { unsigned int alloc; Elem12 *end; } Elem12Store;
typedef struct Elem12AVec { Elem12 *first; Elem12 *last; Elem12Store store; } Elem12AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);

static __inline Elem12 *elem12_ucopy(const Elem12 *first, const Elem12 *last, Elem12 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void elem12_store_init(Elem12Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Elem12AVec *fn_88162768(Elem12AVec *v, const Elem12AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Elem12 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    elem12_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Elem12 *)fn_88613570(v->store.alloc, n * sizeof(Elem12), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = elem12_ucopy(src->first, src->last, v->first);
    return v;
}
