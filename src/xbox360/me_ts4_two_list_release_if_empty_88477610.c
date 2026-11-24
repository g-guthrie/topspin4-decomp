/* 0x88477610: For the word lists at +0x80 and +0x8c: when a list is empty, frees its storage (kind 0x17) unless externally owned, then nulls data and count and marks the capacity word external (bit 31) keeping bit 30. */
/* Matched on /Oc (agAH). Empty test written at the call site through the owner (o->first.count == 0), reset body in an inline helper; flags = (flags & 0x40000000) | 0x80000000 gives the rlwimi. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Elem4Buf { unsigned int *data; int count; int capFlags; } Elem4Buf;

static __forceinline void Elem4Buf_Reset(Elem4Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(unsigned int), 0x17);
    }
    b->data = 0;
    b->count = 0;
    b->capFlags = (b->capFlags & 0x40000000) | 0x80000000;
}

typedef struct TwoListObj { char pad[0x80]; Elem4Buf first; Elem4Buf second; } TwoListObj;

void fn_88477610(TwoListObj *o)
{
    if (o->first.count == 0)
        Elem4Buf_Reset(&o->first);
    if (o->second.count == 0)
        Elem4Buf_Reset(&o->second);
}
