/* Swing_DLL.xex 0x882294A0: copy constructor of an allocator-handle vector<64-byte element of eight 64-bit words> (16-byte aligned) {first; last; {alloc; end}}.
 * /Oc. Store-vector copy-ctor template (as 88235D80); 8-byte members give the ldu/stdu copy. */
typedef struct Rec64 { unsigned __int64 q[8]; } Rec64;
typedef struct Rec64Store { unsigned int alloc; Rec64 *end; } Rec64Store;
typedef struct Rec64AVec { Rec64 *first; Rec64 *last; Rec64Store store; } Rec64AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);

static __inline Rec64 *rec64_ucopy(const Rec64 *first, const Rec64 *last, Rec64 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void rec64_store_init(Rec64Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Rec64AVec *fn_882294A0(Rec64AVec *v, const Rec64AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec64 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec64_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec64 *)fn_88613570(v->store.alloc, n * sizeof(Rec64), 16, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = rec64_ucopy(src->first, src->last, v->first);
    return v;
}
