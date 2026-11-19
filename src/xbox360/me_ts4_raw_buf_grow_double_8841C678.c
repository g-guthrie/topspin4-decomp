/* 0x8841C678: Doubles a pool buffer (capacity count*2, or 1 when empty) of elemSize-byte elements: allocates (kind 0x17), copies count elements, frees the old storage unless externally owned, then stores the new pointer and capacity, keeping bit 30 of the old capacity word. */
/* Matched on /Oc (agAH). Same shape as 8841C5E8; memcpy size written elemSize * count to get mullw r5, r30, r11. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
void *memcpy(void *dst, const void *src, unsigned int n);
typedef struct RawBuf { void *data; int count; int capFlags; } RawBuf;

void fn_8841C678(RawBuf *b, unsigned int elemSize)
{
    unsigned int newCap = b->count ? b->count * 2 : 1;
    void *allocator = KeTlsGetValue(lbl_88CACF08);
    void *fresh = fn_8841A510(allocator, newCap * elemSize, 0x17);
    memcpy(fresh, b->data, elemSize * b->count);
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * elemSize, 0x17);
    }
    b->data = fresh;
    b->capFlags = (b->capFlags & 0x40000000) | newCap;
}
