/* 0x887F4698: Destructor body: sets vtable lbl_880E45FC, frees the pool-owned 48-byte-element array at +0x84 (kind 0x17) unless externally owned, then destroys the owned object at +0x78. */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (signed capacity word, & (int)0x80000000 test, masked capacity local before KeTlsGetValue, cap * sizeof(elem)) with C vtable stores; see 884DC9B0. */
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

extern const void *lbl_880E45FC;
void ts4_destroy_owned_object(void *p);
typedef struct OwnerBufObj { const void *vtable; char pad[0x74]; void *owned; char pad2[0x8]; Elem48Buf items; } OwnerBufObj;

void fn_887F4698(OwnerBufObj *n)
{
    n->vtable = &lbl_880E45FC;
    Elem48Buf_Free(&n->items);
    if (n->owned)
        ts4_destroy_owned_object(n->owned);
}
