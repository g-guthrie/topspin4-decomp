/* 0x8841C5E8: Reallocates a pool buffer to newCap elements of elemSize bytes: allocates through the TLS allocator (kind 0x17), copies count elements, frees the old storage unless externally owned, then stores the new pointer and newCap, keeping only bit 30 of the old capacity word. */
/* Matched on /Oc (agAH). Both allocator fetches as separate locals before the alloc/free calls; the free uses the signed & (int)0x80000000 test. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
void *memcpy(void *dst, const void *src, unsigned int n);
typedef struct RawBuf { void *data; int count; int capFlags; } RawBuf;

void fn_8841C5E8(RawBuf *b, unsigned int newCap, unsigned int elemSize)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    void *fresh = fn_8841A510(allocator, newCap * elemSize, 0x17);
    memcpy(fresh, b->data, b->count * elemSize);
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * elemSize, 0x17);
    }
    b->data = fresh;
    b->capFlags = (b->capFlags & 0x40000000) | newCap;
}
