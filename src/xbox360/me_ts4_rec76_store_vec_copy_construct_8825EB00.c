/* Swing_DLL.xex 0x8825EB00: copy constructor of an allocator-handle vector<76-byte element (copy 88166AF8)> {first; last; {alloc; end}}.
 * /Oc. Store-vector copy-ctor template (as 88235D80): {alloc; end} store initialised through its pointer, p = 0 then if (n) allocate. */
typedef struct Rec76 { unsigned int w[19]; } Rec76;
typedef struct Rec76Store { unsigned int alloc; Rec76 *end; } Rec76Store;
typedef struct Rec76AVec { Rec76 *first; Rec76 *last; Rec76Store store; } Rec76AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);
Rec76 *fn_88166AF8(Rec76 *dest, const Rec76 *src);

static __inline Rec76 *rec76_ucopy(const Rec76 *first, const Rec76 *last, Rec76 *dest)
{
    for (; first != last; ++first, ++dest)
        if (dest) fn_88166AF8(dest, first);
    return dest;
}

static __inline void rec76_store_init(Rec76Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

Rec76AVec *fn_8825EB00(Rec76AVec *v, const Rec76AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec76 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec76_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec76 *)fn_88613570(v->store.alloc, n * sizeof(Rec76), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = rec76_ucopy(src->first, src->last, v->first);
    return v;
}
