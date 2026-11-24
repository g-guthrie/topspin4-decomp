/* Swing_DLL.xex 0x884C9AC8: binary packfile reader (vtable 0x8808C29C, RTTI hkBinaryPackfileReader,
 * Havok 5.5 serialize range): address `offset` bytes into loaded section `index`, or 0 when that
 * section has no data. The section pointers are a growable array {data, size, capacity} at +0x24.
 * Matches only as a member function reading the array through operator[]: the same body as an
 * extern "C" function with an explicit `self` allocates the index before the base (r10/r11 swapped). */

template <class T> struct Ts4PackArray {
    T *data;
    int size;
    int capacity;
    const T &operator[](int i) const { return data[i]; }
};

struct Ts4PackfileReader {
    char pad_00[0x24];
    Ts4PackArray<void *> section_data;
    void *section_data_at(int index, int offset) const;
};

/* Swing_DLL.xex 0x884C9AC8 (vtable slot only, no direct callers) */
void *Ts4PackfileReader::section_data_at(int index, int offset) const
{
    if (section_data[index])
        return static_cast<char *>(section_data[index]) + offset;
    return 0;
}
