/* Swing_DLL.xex 0x882400F8: copy constructor of {store-vector<8-byte pair> (memmove); store-vector<u32> (88235D80); store-vector<16-byte> (88255C08); flags}.
 * /Oc. First vector inlined with the store-vector copy template (as 88235D80), the other two are calls. */
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Pair8Store { unsigned int alloc; Pair8 *end; } Pair8Store;
typedef struct Pair8AVec { Pair8 *first; Pair8 *last; Pair8Store store; } Pair8AVec;
typedef struct U32Store { unsigned int alloc; unsigned int *end; } U32Store;
typedef struct U32AVec { unsigned int *first; unsigned int *last; U32Store store; } U32AVec;
typedef struct Rec16 { unsigned int w[4]; } Rec16;
typedef struct Rec16Store { unsigned int alloc; Rec16 *end; } Rec16Store;
typedef struct Rec16AVec { Rec16 *first; Rec16 *last; Rec16Store store; } Rec16AVec;
typedef struct StoreLists { Pair8AVec pairs; U32AVec ids; Rec16AVec recs; unsigned int flags; } StoreLists;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
U32AVec *fn_88235D80(U32AVec *v, const U32AVec *src);
Rec16AVec *fn_88255C08(Rec16AVec *v, const Rec16AVec *src);

static __inline Pair8 *pair8_ucopy(const Pair8 *first, const Pair8 *last, Pair8 *dest)
{
    unsigned int bytes;
    if (last == first) return dest;
    bytes = (const char *)last - (const char *)first;
    return (Pair8 *)((char *)fn_88562DC0(dest, first, bytes) + bytes);
}

static __inline void pair8_store_init(Pair8Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

static __inline void pair8_avec_copy(Pair8AVec *v, const Pair8AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Pair8 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    pair8_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Pair8 *)fn_88613570(v->store.alloc, n * sizeof(Pair8), 4, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = pair8_ucopy(src->first, src->last, v->first);
}

StoreLists *fn_882400F8(StoreLists *t, const StoreLists *src)
{
    pair8_avec_copy(&t->pairs, &src->pairs);
    fn_88235D80(&t->ids, &src->ids);
    fn_88255C08(&t->recs, &src->recs);
    t->flags = src->flags;
    return t;
}
