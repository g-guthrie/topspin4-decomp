/* 0x88423C28: Initialises an 8-byte-element table sized for an expected count: capacity is the smallest power of two >= 4 and >= 3 * expected, storage allocated (kind 0x17), last = cap - 1, every word filled with -1, capacity word reduced to bit 31. */
/* Near miss (agAH): /Oc, 1 instruction off: the fill store is stwx r10, r9, r11 (base, index) where the target has stwx r10, r11, r9. The same fill in 88423CE0 (constant count) matches. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct Elem8 { int a; int b; } Elem8;
typedef struct Elem8Table { Elem8 *data; int flags; int last; } Elem8Table;

Elem8Table *fn_88423C28(Elem8Table *t, int expected)
{
    int want = expected * 3;
    int cap = 4;
    int i, n;
    void *alloc;
    t->flags = 0;
    while (cap < want)
        cap <<= 1;
    alloc = KeTlsGetValue(lbl_88CACF08);
    t->data = (Elem8 *)fn_8841A510(alloc, cap * sizeof(Elem8), 0x17);
    t->last = cap - 1;
    n = (t->last + 1) * 2;
    for (i = 0; i < n; i++)
        ((int *)t->data)[i] = -1;
    t->flags &= 0x80000000;
    return t;
}
