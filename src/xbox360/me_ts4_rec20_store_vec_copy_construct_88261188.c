/* Swing_DLL.xex 0x88261188: copy constructor of an allocator-handle vector<20-byte POD> {first; last; {alloc; end}}.
 * /Oc. Store-vector copy-ctor template (as 88235D80): {alloc; end} store initialised through its pointer, p = 0 then if (n) allocate. */
typedef struct Rec20 { unsigned int w[5]; } Rec20;
typedef struct Rec20Store { unsigned int alloc; Rec20 *end; } Rec20Store;
typedef struct Rec20AVec { Rec20 *first; Rec20 *last; Rec20Store store; } Rec20AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);

static __inline Rec20 *rec20_ucopy(const Rec20 *first, const Rec20 *last, Rec20 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void rec20_store_init(Rec20Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Rec20AVec *fn_88261188(Rec20AVec *v, const Rec20AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec20 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec20_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec20 *)fn_88613570(v->store.alloc, n * sizeof(Rec20), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = rec20_ucopy(src->first, src->last, v->first);
    return v;
}
