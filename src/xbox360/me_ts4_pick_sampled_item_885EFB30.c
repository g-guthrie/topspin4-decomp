/* 0x885EFB30: Samples item index of the array into a temporary pointer buffer (count entries, step span/count from start) through fn_885EED10 using keyA or keyB (+4/+8, chosen by +0xc), and returns entry pick of the result or 0; the temporary buffer is freed (kind 0x17). */
/* Matched on /Oc (agAH). Key choice written override == 0 ? keyA : keyB; floats take r4/r5 slots in the callee call. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct PtrBuf { void **data; int count; int capFlags; } PtrBuf;
void fn_8841C5E8(PtrBuf *b, unsigned int newCap, unsigned int elemSize);
typedef struct Item { char pad[0x34]; int childCount; } Item;
typedef struct ItemArray { Item **items; } ItemArray;
typedef struct Picker { int unk0; void *keyA; void *keyB; void *override; } Picker;
void fn_885EED10(Item *item, float start, float step, int count, PtrBuf *out, void *key);

static __forceinline void PtrBuf_Free(PtrBuf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(void *), 0x17);
    }
}

void *fn_885EFB30(Picker *p, int index, int pick, ItemArray *items, int count, float span, float start)
{
    PtrBuf buf;
    void *result = 0;
    float step = span / (float)count;
    buf.data = 0;
    buf.count = 0;
    buf.capFlags = (int)0x80000000;
    if (count > 0)
        fn_8841C5E8(&buf, count, 4);
    if (items->items[index]->childCount > 0) {
        buf.count = 0;
        fn_885EED10(items->items[index], start, step, count, &buf, p->override == 0 ? p->keyA : p->keyB);
        if (pick < buf.count)
            result = buf.data[pick];
    }
    PtrBuf_Free(&buf);
    return result;
}
