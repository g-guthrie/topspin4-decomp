/* Swing_DLL.xex 0x88423600: Ts4QwordHashSet::InitExternal: the 64-bit-key sibling of 0x88423580 (lookup
 * 0x88423A78): slots = caller storage, capacity flags 0x80000000 (not owned), mask = bytes/16 - 1, then every one
 * of the bytes/16 64-bit slots set to -1 (empty).
 * Matched on /Oc as a C++ member: `stdx r10, r11(offset), r9(slots)` needs the base loaded off `this`
 * (docs/agents/regalloc.md C1); as an extern "C" function the operands come out (slots, offset). */
struct Ts4QwordHashSet {
    long long *slots;
    unsigned int capFlags;
    int mask;

    void InitExternal(long long *storage, unsigned int bytes);
};

void Ts4QwordHashSet::InitExternal(long long *storage, unsigned int bytes)
{
    int n = bytes >> 4;
    slots = storage;
    capFlags = 0x80000000;
    mask = n - 1;
    for (int i = 0; i < n; i++)
        slots[i] = -1;
}
