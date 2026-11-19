/* 0x885E9568: 16-bit-header variant of 8841C678: doubles the capacity (or 1 when empty), copies the u16 count of elemSize elements, frees the old storage unless bit 15 of the u16 capacity word is set, keeps bit 14. */
/* Matched on /Oc (agAH). Same as 8841C678 with unsigned short count/capacity; memcpy size count * elemSize here. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
void *memcpy(void *dst, const void *src, unsigned int n);
typedef struct ShortBuf { void *data; unsigned short count; unsigned short capFlags; } ShortBuf;

void fn_885E9568(ShortBuf *b, unsigned int elemSize)
{
    unsigned int newCap = b->count ? b->count * 2 : 1;
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
