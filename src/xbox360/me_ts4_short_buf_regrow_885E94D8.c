/* 0x885E94D8: 16-bit-header variant of 8841C5E8: reallocates to newCap elements of elemSize, copies the u16 count, frees the old storage unless bit 15 of the u16 capacity word is set (mask 0x3FFF), and keeps only bit 14 of the old capacity word. */
/* Matched on /Oc (agAH). Allocator locals before both calls; unsigned short capacity word gives clrrwi 15 + cmplwi. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
void *memcpy(void *dst, const void *src, unsigned int n);
typedef struct ShortBuf { void *data; unsigned short count; unsigned short capFlags; } ShortBuf;

void fn_885E94D8(ShortBuf *b, unsigned int newCap, unsigned int elemSize)
{
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    void *fresh = fn_8841A510(allocator, newCap * elemSize, 0x17);
    memcpy(fresh, b->data, b->count * elemSize);
    if ((b->capFlags & 0x8000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * elemSize, 0x17);
    }
    b->data = fresh;
    b->capFlags = (unsigned short)((b->capFlags & 0x4000) | newCap);
}
