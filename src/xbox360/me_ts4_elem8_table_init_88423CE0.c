/* 0x88423CE0: Initialises an 8-byte-element table: allocates 16 entries (0x80 bytes, kind 0x17) from the TLS allocator, sets last index 15, fills every word with -1, then clears all capacity-word bits except bit 31; returns the table. */
/* Matched on /Oc (agAH). Allocator fetched into a local before the alloc call (else li r4/li r5 swap). */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct Elem8 { int a; int b; } Elem8;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;

Elem8Table *fn_88423CE0(Elem8Table *t)
{
    int i;
    void *alloc = KeTlsGetValue(lbl_88CACF08);
    t->data = (Elem8 *)fn_8841A510(alloc, 16 * sizeof(Elem8), 0x17);
    t->flags = 0;
    t->last = 15;
    for (i = 0; i < 32; i++)
        ((int *)t->data)[i] = -1;
    t->flags &= 0x80000000;
    return t;
}
