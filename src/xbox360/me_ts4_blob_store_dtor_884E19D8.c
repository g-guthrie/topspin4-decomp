/* 0x884E19D8: Destructor body: sets vtable lbl_8808D2E0, releases the owned object at +0x18 (fn_88472858 with flag 1), frees every 20-byte blob in the array at +0xc and then the array itself (kind 0x17, unless externally owned), and resets the base vtable lbl_8803A308. */
/* Matched on /Oc (agAH). Element count read into a local before the free loop (count-down subic. loop). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
extern const void *lbl_8808D2E0;
extern const void *lbl_8803A308;
typedef struct Blob { unsigned char *data; int size; int capFlags; char padc[8]; } Blob;
typedef struct BlobArray { Blob *data; int count; int capFlags; } BlobArray;
typedef struct Owned Owned;
void *fn_88472858(void *self, unsigned int flags);
typedef struct BlobStore { const void *vtable; char pad4[8]; BlobArray blobs; Owned *owned; } BlobStore;

static __forceinline void Blob_Free(Blob *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap, 0x17);
    }
}

static __forceinline void BlobArray_Free(BlobArray *a)
{
    if ((a->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = a->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, a->data, cap * sizeof(Blob), 0x17);
    }
}

void fn_884E19D8(BlobStore *s)
{
    int i;
    int n;
    s->vtable = &lbl_8808D2E0;
    if (s->owned != 0)
        fn_88472858(s->owned, 1);
    n = s->blobs.count;
    for (i = 0; i < n; i++)
        Blob_Free(&s->blobs.data[i]);
    BlobArray_Free(&s->blobs);
    s->vtable = &lbl_8803A308;
}
