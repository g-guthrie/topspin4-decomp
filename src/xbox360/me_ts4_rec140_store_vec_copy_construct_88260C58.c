/* Swing_DLL.xex 0x88260C58: copy constructor of an allocator-handle vector<140-byte element (copy 88260E90)> {first; last; {alloc; end}}.
 * /Oc. Store-vector copy-ctor template (as 88235D80): {alloc; end} store initialised through its pointer, p = 0 then if (n) allocate. */
typedef struct Rec140 { unsigned int w[35]; } Rec140;
typedef struct Rec140Store { unsigned int alloc; Rec140 *end; } Rec140Store;
typedef struct Rec140AVec { Rec140 *first; Rec140 *last; Rec140Store store; } Rec140AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);
Rec140 *fn_88260E90(Rec140 *dest, const Rec140 *src);

static __inline Rec140 *rec140_ucopy(const Rec140 *first, const Rec140 *last, Rec140 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) fn_88260E90(dest, first);
    return dest;
}

static __inline void rec140_store_init(Rec140Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Rec140AVec *fn_88260C58(Rec140AVec *v, const Rec140AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec140 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec140_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec140 *)fn_88613570(v->store.alloc, n * sizeof(Rec140), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = rec140_ucopy(src->first, src->last, v->first);
    return v;
}
