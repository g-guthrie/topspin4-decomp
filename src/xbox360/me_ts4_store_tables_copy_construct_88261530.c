/* Swing_DLL.xex 0x88261530: copy constructor of {store-vectors of 20-, 304-, 24- and 32-byte records; two words}: the 304-byte vector inlined (16-byte aligned, uninit copy 88261278), the others via 88261188/88261360/88261450.
 * /Oc. Store-vector copy-ctor template inlined for the second member. */
typedef struct Rec20 { unsigned int w[5]; } Rec20;
typedef struct Rec20Store { unsigned int alloc; Rec20 *end; } Rec20Store;
typedef struct Rec20AVec { Rec20 *first; Rec20 *last; Rec20Store store; } Rec20AVec;
typedef struct Rec24 { unsigned int w[6]; } Rec24;
typedef struct Rec24Store { unsigned int alloc; Rec24 *end; } Rec24Store;
typedef struct Rec24AVec { Rec24 *first; Rec24 *last; Rec24Store store; } Rec24AVec;
typedef struct Rec32 { unsigned int w[8]; } Rec32;
typedef struct Rec32Store { unsigned int alloc; Rec32 *end; } Rec32Store;
typedef struct Rec32AVec { Rec32 *first; Rec32 *last; Rec32Store store; } Rec32AVec;
typedef struct Rec304 { unsigned int w[76]; } Rec304;
typedef struct Rec304Store { unsigned int alloc; Rec304 *end; } Rec304Store;
typedef struct Rec304AVec { Rec304 *first; Rec304 *last; Rec304Store store; } Rec304AVec;
typedef struct StoreTables { Rec20AVec a; Rec304AVec b; Rec24AVec c; Rec32AVec d; unsigned int x; unsigned int y; } StoreTables;
void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(unsigned int *alloc);
void *fn_88613570(unsigned int alloc, unsigned int size, unsigned int align, void *owner);
Rec20AVec *fn_88261188(Rec20AVec *v, const Rec20AVec *src);
Rec24AVec *fn_88261360(Rec24AVec *v, const Rec24AVec *src);
Rec32AVec *fn_88261450(Rec32AVec *v, const Rec32AVec *src);
Rec304 *fn_88261278(const Rec304 *first, const Rec304 *last, Rec304 *dest);

static __inline void rec304_store_init(Rec304Store *s)
{
    s->alloc = 0;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&s->alloc);
    s->end = 0;
}

static __inline void rec304_avec_copy(Rec304AVec *v, const Rec304AVec *src)
{
    unsigned int def = 0;
    unsigned int n;
    Rec304 *p;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&def);
    n = src->last - src->first;
    v->first = 0;
    v->last = 0;
    rec304_store_init(&v->store);
    p = 0;
    if (n != 0) p = (Rec304 *)fn_88613570(v->store.alloc, n * sizeof(Rec304), 16, &v->store.alloc);
    v->first = p;
    v->last = p;
    v->store.end = p + n;
    v->last = fn_88261278(src->first, src->last, v->first);
}

StoreTables *fn_88261530(StoreTables *t, const StoreTables *src)
{
    fn_88261188(&t->a, &src->a);
    rec304_avec_copy(&t->b, &src->b);
    fn_88261360(&t->c, &src->c);
    fn_88261450(&t->d, &src->d);
    t->x = src->x;
    t->y = src->y;
    return t;
}
