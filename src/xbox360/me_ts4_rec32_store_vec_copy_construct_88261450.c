/* Swing_DLL.xex 0x88261450: copy constructor of an allocator-handle vector<32-byte POD> {first; last; {alloc; end}}.
 * /Oc. Store-vector copy-ctor template (as 88235D80): {alloc; end} store initialised through its pointer, p = 0 then if (n) allocate. */
typedef struct Rec32 { unsigned int w[8]; } Rec32;
typedef struct Rec32Store { unsigned int alloc; Rec32 *end; } Rec32Store;
typedef struct Rec32AVec { Rec32 *first; Rec32 *last; Rec32Store store; } Rec32AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);

static __inline Rec32 *rec32_ucopy(const Rec32 *first, const Rec32 *last, Rec32 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) *dest = *first;
    return dest;
}

static __inline void rec32_store_init(Rec32Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Rec32AVec *fn_88261450(Rec32AVec *v, const Rec32AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec32 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec32_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec32 *)fn_88613570(v->store.alloc, n * sizeof(Rec32), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = rec32_ucopy(src->first, src->last, v->first);
    return v;
}
