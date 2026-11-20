/* Swing_DLL.xex 0x88261360: copy constructor of an allocator-handle vector<24-byte POD> {first; last; {alloc; end}}.
 * /Oc. Store-vector copy-ctor template (as 88235D80): {alloc; end} store initialised through its pointer, p = 0 then if (n) allocate. */
typedef struct Rec24 { unsigned int w[6]; } Rec24;
typedef struct Rec24Store { unsigned int alloc; Rec24 *end; } Rec24Store;
typedef struct Rec24AVec { Rec24 *first; Rec24 *last; Rec24Store store; } Rec24AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);

static __inline Rec24 *rec24_ucopy(const Rec24 *first, const Rec24 *last, Rec24 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void rec24_store_init(Rec24Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Rec24AVec *fn_88261360(Rec24AVec *v, const Rec24AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec24 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec24_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec24 *)fn_88613570(v->store.alloc, n * sizeof(Rec24), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = rec24_ucopy(src->first, src->last, v->first);
    return v;
}
