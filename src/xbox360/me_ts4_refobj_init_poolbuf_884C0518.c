/* 0x884C0518: Initialises a refcounted object with vtable lbl_880898DC: refs (+6) = 1, an empty not-owned pool buffer at +0x10 {0, 0, 0x80000000}, +0xc = +8 = 0, then the buffer count is zeroed again; returns the object. */
/* Matched on /Oc (agAH). Buffer init through an inline helper, then the explicit second count store (kept by the compiler). */
extern void *lbl_880898DC;
typedef struct PoolBuf { void *data; unsigned int count; unsigned int capFlags; } PoolBuf;
typedef struct RefList { void *vtable; short unk4; short refs; int x8; int xc; PoolBuf buf; } RefList;
static __forceinline void PoolBuf_Init(PoolBuf *b) { b->data = 0; b->count = 0; b->capFlags = 0x80000000; }
RefList *fn_884C0518(RefList *o)
{
    o->refs = 1;
    o->vtable = &lbl_880898DC;
    PoolBuf_Init(&o->buf);
    o->xc = 0;
    o->x8 = 0;
    o->buf.count = 0;
    return o;
}
