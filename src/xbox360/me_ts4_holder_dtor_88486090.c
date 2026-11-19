/* 0x88486090: Destructor body: sets the derived vtable lbl_88087300, frees the pool-owned 48-byte-element array at +0x18 (kind 0x17) unless externally owned, then sets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). C vtable stores around the shared inline per-buffer free helper (3*16 size gives clrlslwi+add+slwi). */
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
typedef struct Holder { const void *vtable; char pad[0x14]; Elem48Buf items; } Holder;

void fn_88486090(Holder *h)
{
    h->vtable = &lbl_88087300;
    Elem48Buf_Free(&h->items);
    h->vtable = &lbl_8803A308;
}
