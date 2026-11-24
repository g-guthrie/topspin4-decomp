/* Swing_DLL.xex 0x88329478: Ts4IntSlotList::GetAt: *out = values[i] and 0 when out is non-null and 0 <= i < count
 * (count +4, values +0x14); 0x25 otherwise.
 * Matched on /Oc as a C++ member: `lwzx` takes (i*4, values) only with values loaded off `this`; the extern "C"
 * form with the list as the first parameter gives (values, i*4) (docs/agents/regalloc.md C1). */
struct Ts4IntSlotList {
    int flags;
    int count;
    char pad08[0xc];
    int *values;

    int GetAt(int i, int *out);
};

int Ts4IntSlotList::GetAt(int i, int *out)
{
    if (out && i >= 0 && i < count) {
        *out = values[i];
        return 0;
    }
    return 0x25;
}
