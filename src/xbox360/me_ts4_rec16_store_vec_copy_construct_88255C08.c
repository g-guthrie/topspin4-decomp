/* Swing_DLL.xex 0x88255C08: copy constructor of an allocator-handle vector<16-byte POD> {first; last; {alloc; end}}.
 * /Oc. Store-vector copy-ctor template (as 88235D80): {alloc; end} store initialised through its pointer, p = 0 then if (n) allocate. */
typedef struct Rec16 { unsigned int w[4]; } Rec16;
typedef struct Rec16Store { unsigned int alloc; Rec16 *end; } Rec16Store;
typedef struct Rec16AVec { Rec16 *first; Rec16 *last; Rec16Store store; } Rec16AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);

static __inline Rec16 *rec16_ucopy(const Rec16 *first, const Rec16 *last, Rec16 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void rec16_store_init(Rec16Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Rec16AVec *fn_88255C08(Rec16AVec *v, const Rec16AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec16 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec16_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec16 *)fn_88613570(v->store.alloc, n * sizeof(Rec16), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = rec16_ucopy(src->first, src->last, v->first);
    return v;
}
