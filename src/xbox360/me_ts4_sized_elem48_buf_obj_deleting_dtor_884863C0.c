/* 0x884863C0: Scalar deleting destructor of the 88486090 class: sets vtable lbl_88087300, frees the 48-byte-element array at +0x18 unless externally owned, sets the base vtable, and with flags bit 0 frees the object by its u16 size (kind 0x2c); returns the object. */
/* Matched on /Oc (agAH). Inlined 88486090 body plus the d1_band2 deleting tail. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem48 { unsigned char b[48]; } Elem48;
typedef struct Elem48Buf { Elem48 *data; int count; int capFlags; } Elem48Buf;

static void Elem48Buf_Free(Elem48Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem48), 0x17);
    }
}

extern const void *lbl_88087300;
extern const void *lbl_8803A308;
typedef struct SizedElem48BufObj { const void *vtable; unsigned short size; char pad[16]; Elem48Buf items; } SizedElem48BufObj;

SizedElem48BufObj *fn_884863C0(SizedElem48BufObj *o, unsigned int flags)
{
    o->vtable = &lbl_88087300;
    Elem48Buf_Free(&o->items);
    o->vtable = &lbl_8803A308;
    if ((flags & 1) != 0) {
        void *allocator = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(allocator, o, o->size, 44);
    }
    return o;
}
