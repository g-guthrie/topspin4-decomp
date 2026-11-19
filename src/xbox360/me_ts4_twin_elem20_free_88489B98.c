/* 0x88489B98: Releases a struct: ts4_if_call_seq_u32_off4_88472748 on the member at +0x48, then frees the pool-owned 20-byte-element arrays at +0x10 and +0x0 (kind 0x17, each skipped if externally owned). */
/* Matched on /Oc (agAH). Shared inline per-buffer free helper (see 884DC9B0); deleting variants use the d1_band2_deleting_dtors_a.c tail; 884CCAB0 inlines the 884D50C8 index free. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Elem20 { unsigned char b[20]; } Elem20;
typedef struct Elem20Buf { Elem20 *data; int count; int capFlags; } Elem20Buf;

static void Elem20Buf_Free(Elem20Buf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap * sizeof(Elem20), 0x17);
    }
}

void ts4_if_call_seq_u32_off4_88472748(void *p);
typedef struct TwinElem20 { Elem20Buf first; char pad[4]; Elem20Buf second; char pad2[0x2c]; char list[4]; } TwinElem20;

void fn_88489B98(TwinElem20 *t)
{
    ts4_if_call_seq_u32_off4_88472748(&t->list);
    Elem20Buf_Free(&t->second);
    Elem20Buf_Free(&t->first);
}
