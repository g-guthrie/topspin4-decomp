/* 0x88423D60: Frees an 8-byte-element table (data, flags, last index) through the TLS allocator, kind 0x17, size (last + 1) * 8, unless flags bit 31 is set. */
/* Near miss (agAH): /Oc, 4 instructions off: r30/r31 swapped between data and last+1. Sibling 88423F08 is the 16-byte version. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Elem8 { unsigned char b[8]; } Elem8;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;

static void Elem8_PoolFree(Elem8 *data, unsigned int n)
{
    void *alloc = KeTlsGetValue(lbl_88CACF08);
    fn_8841A590(alloc, data, n * sizeof(Elem8), 0x17);
}

void fn_88423D60(Elem8Table *t)
{
    if ((t->flags & (int)0x80000000) == 0)
        Elem8_PoolFree(t->data, t->last + 1);
}
