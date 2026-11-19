/* 0x885E7BA8: Frees a 12-byte-element table (data, flags, last index) through the TLS allocator, kind 0x17, size (last + 1) * 12, without an ownership check. */
/* Matched on /Oc (agAH). Word count (last + 1) * 3 computed into a local before the data load and the KeTlsGetValue call, then * sizeof(int) in the call; a single (last + 1) * 12 is scheduled after the call. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);

typedef struct Elem12 { unsigned char b[12]; } Elem12;
typedef struct Elem12Table { Elem12 *data; int flags; int last; } Elem12Table;

void fn_885E7BA8(Elem12Table *t)
{
    unsigned int words = (t->last + 1) * 3;
    Elem12 *data = t->data;
    void *alloc = KeTlsGetValue(lbl_88CACF08);
    fn_8841A590(alloc, data, words * sizeof(int), 0x17);
}
