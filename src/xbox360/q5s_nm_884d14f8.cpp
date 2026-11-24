// Swing_DLL.xex 0x884D14F8: Ts4FixupTable::Apply(base): relocates a loaded block in place.
// Pointer fixups store base + target at base + offset; value fixups store value at base + offset.
// Callers: 884D67A0 (twice), 884DE8E8. Matched /Oc as a C++ const member: as a C function
// taking the table as its first parameter the first loop's address add takes the operands
// the other way round (`this` is numbered differently from a first parameter, regalloc.md C1).
struct Ts4PtrFixup {
    unsigned int offset; // +0x0
    unsigned int target; // +0x4
};
struct Ts4ValueFixup {
    unsigned int offset; // +0x0
    unsigned int value;  // +0x4
    unsigned int f_08;
};
struct Ts4FixupTable {
    Ts4PtrFixup *ptrs;     // +0x00
    int ptr_count;         // +0x04
    int f_08;
    Ts4ValueFixup *values; // +0x0C
    int value_count;       // +0x10
    void Apply(char *base) const;
};

void Ts4FixupTable::Apply(char *base) const
{
    for (int i = 0; i < ptr_count; i++) {
        const Ts4PtrFixup *f = &ptrs[i];
        *(unsigned int *)(base + f->offset) = f->target + (unsigned int)(unsigned long)base;
    }
    for (int i = 0; i < value_count; i++) {
        const Ts4ValueFixup *f = &values[i];
        *(unsigned int *)(base + f->offset) = f->value;
    }
}
