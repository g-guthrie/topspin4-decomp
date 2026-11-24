/* Swing_DLL.xex 0x88423580: Ts4WordHashSet::InitExternal: binds the open-addressed u32 key table (slots +0,
 * capacity flags +4, mask +8; the lookup is 0x88423730) to caller storage: capacity flags 0x80000000 (storage not
 * owned), mask = bytes/8 - 1, then every one of the bytes/8 slots set to -1 (empty).
 * Matched on /Oc as a C++ member. The fill store is `stwx r10, r11(offset), r9(slots)`: in a member the induction
 * offset comes before the slots pointer loaded off `this`; the same body as an extern "C" function with the table
 * as the first parameter gives (slots, offset) (docs/agents/regalloc.md C1). */
struct Ts4WordHashSet {
    unsigned int *slots;
    unsigned int capFlags;
    int mask;

    void InitExternal(unsigned int *storage, unsigned int bytes);
};

void Ts4WordHashSet::InitExternal(unsigned int *storage, unsigned int bytes)
{
    int n = bytes >> 3;
    slots = storage;
    capFlags = 0x80000000;
    mask = n - 1;
    for (int i = 0; i < n; i++)
        slots[i] = 0xFFFFFFFF;
}
