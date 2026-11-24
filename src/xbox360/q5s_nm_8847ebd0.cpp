/* Swing_DLL.xex 0x8847EBD0: Ts4RefListOwner::RemoveAt: releases item i of the pointer list at +0x2C through
 * ts4_counted_ref_release_88475B08, then fills the hole with the last item (unordered erase).
 * Matched on /Oc as a C++ member with the swap-erase as an inline member of the list: the first `lwzx` takes
 * (i*4, items) with items loaded off `this` (docs/agents/regalloc.md C1); the extern "C" form, or a `list` pointer
 * local taken before the release call, gives (items, i*4). */
extern "C" void ts4_counted_ref_release_88475B08(void *p);

struct Ts4PtrList {
    void **items;
    int count;

    void EraseSwap(int i)
    {
        count--;
        items[i] = items[count];
    }
};

struct Ts4RefListOwner {
    char pad00[0x2c];
    Ts4PtrList list;

    void RemoveAt(int i);
};

void Ts4RefListOwner::RemoveAt(int i)
{
    ts4_counted_ref_release_88475B08(list.items[i]);
    list.EraseSwap(i);
}
