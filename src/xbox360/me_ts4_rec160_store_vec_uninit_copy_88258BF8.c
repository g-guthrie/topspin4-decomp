/* Swing_DLL.xex 0x88258BF8: uninitialized_copy of 160-byte store vectors: each destination is copy-constructed from the source
 * (store init, allocate n*160 aligned 8, element copy 88259D10). */
typedef struct Rec160 { unsigned int w[40]; } Rec160;
typedef struct Rec160Store { unsigned int alloc; Rec160 *end; } Rec160Store;
typedef struct Rec160AVec { Rec160 *first; Rec160 *last; Rec160Store store; } Rec160AVec;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);
Rec160 *fn_88259D10(const Rec160 *first, const Rec160 *last, Rec160 *dest);

static __inline void rec160_store_init(Rec160Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

static __inline void rec160_avec_copy(Rec160AVec *v, const Rec160AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec160 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec160_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec160 *)fn_88613570(v->store.alloc, n * sizeof(Rec160), 8, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = fn_88259D10(src->first, src->last, v->first);
}

Rec160AVec *fn_88258BF8(const Rec160AVec *first, const Rec160AVec *last, Rec160AVec *dest)
{
    for (; first != last; ++first, ++dest) {
        Rec160AVec *d = dest;
        if (d)
            rec160_avec_copy(d, first);
    }
    return dest;
}
