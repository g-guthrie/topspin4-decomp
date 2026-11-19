/* 0x88555608: Frees the pool-owned 4-byte-element array at +0x34 through the TLS allocator (kind 0x17) unless its capacity word has the external-storage bit set. */
/* Matched on /Oc (agAH). Same inline per-buffer helper as 884DC9B0/884E1FE8; the capacity mask folds into the slwi. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem4 { unsigned char b[4]; } Elem4;
typedef struct Elem4Buf { Elem4 *data; int count; int capFlags; } Elem4Buf;

static void Elem4Buf_Free(Elem4Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem4), 0x17);
    }
}

typedef struct Owner { char pad[0x34]; Elem4Buf items; } Owner;

void fn_88555608(Owner *o)
{
    Elem4Buf_Free(&o->items);
}
