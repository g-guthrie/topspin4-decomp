/* 0x8844E450: Scalar deleting destructor: sets vtable lbl_880820AC, frees the pool-owned 12-byte-element array at +0xc (kind 0x17) unless externally owned, sets the base vtable, and with flags bit 0 frees the object by its u16 size (kind 0x1f); returns the object. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper plus the d1_band2 deleting tail. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem12 { unsigned char b[12]; } Elem12;
typedef struct Elem12Buf { Elem12 *data; int count; int capFlags; } Elem12Buf;

static void Elem12Buf_Free(Elem12Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem12), 0x17);
    }
}

extern const void *lbl_880820AC;
extern const void *lbl_8803A308;
typedef struct SizedElem12BufObj { const void *vtable; unsigned short size; char pad[4]; Elem12Buf items; } SizedElem12BufObj;

SizedElem12BufObj *fn_8844E450(SizedElem12BufObj *o, unsigned int flags)
{
    o->vtable = &lbl_880820AC;
    Elem12Buf_Free(&o->items);
    o->vtable = &lbl_8803A308;
    if ((flags & 1) != 0) {
        void *allocator = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(allocator, o, o->size, 31);
    }
    return o;
}
