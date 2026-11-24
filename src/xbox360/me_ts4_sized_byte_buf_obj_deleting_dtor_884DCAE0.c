/* 0x884DCAE0: Scalar deleting destructor: frees the pool-owned byte array (kind 0x17) unless externally owned, sets the base vtable lbl_8803A308, and with flags bit 0 returns the object to the TLS allocator using its u16 size at +4 (kind 1); returns the object. */
/* Matched on /Oc (agAH). Inlined destructor body (shared per-buffer free helper) followed by the same deleting tail as d1_band2_deleting_dtors_a.c. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem1 { unsigned char b[1]; } Elem1;
typedef struct Elem1Buf { Elem1 *data; int count; int capFlags; } Elem1Buf;

static void Elem1Buf_Free(Elem1Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem1), 0x17);
    }
}

extern const void *lbl_8803A308;
typedef struct SizedByteBufObj {
    const void *vtable;
    unsigned short size;
    char pad[4];
    Elem1Buf bytes;
} SizedByteBufObj;

SizedByteBufObj *fn_884DCAE0(SizedByteBufObj *o, unsigned int flags)
{
    Elem1Buf_Free(&o->bytes);
    o->vtable = &lbl_8803A308;
    if ((flags & 1) != 0) {
        void *allocator = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(allocator, o, o->size, 1);
    }
    return o;
}
