/* Swing_DLL.xex 0x88423C28: Ts4Elem8Table::Ts4Elem8Table(int expected): an open-addressed table of 8-byte entries
 * (data +0, capacity flags +4, mask +8) sized for an expected count: capacity is the smallest power of two >= 4 and
 * >= 3 * expected, storage from the TLS allocator (kind 0x17), mask = cap - 1, every word filled with -1, then the
 * capacity flags reduced to bit 31. The default-size init is 0x88423CE0 (C, me_ts4_elem8_table_init_88423CE0.c).
 * Matched on /Oc as a constructor: the fill store is `stwx r10, r11(offset), r9(data)` only with the data pointer
 * loaded off `this` (docs/agents/regalloc.md C1); the extern "C" form gives (data, offset). */
extern "C" {
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
}

struct Ts4Elem8 { int key; int value; };

struct Ts4Elem8Table {
    Ts4Elem8 *data;
    int capFlags;
    int mask;

    Ts4Elem8Table(int expected);
};

Ts4Elem8Table::Ts4Elem8Table(int expected)
{
    int want = expected * 3;
    int cap = 4;
    capFlags = 0;
    while (cap < want)
        cap <<= 1;
    void *alloc = KeTlsGetValue(lbl_88CACF08);
    data = (Ts4Elem8 *)fn_8841A510(alloc, cap * sizeof(Ts4Elem8), 0x17);
    mask = cap - 1;
    int n = (mask + 1) * 2;
    for (int i = 0; i < n; i++)
        ((int *)data)[i] = -1;
    capFlags &= 0x80000000;
}
