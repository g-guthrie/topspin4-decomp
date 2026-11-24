/* Swing_DLL.xex 0x883F9D78: Ts4ItemList::Forward: for item i (< count at +0x2C, array +0x34) forwards (item, arg,
 * flags) to 0x883D38C8 with the manager lbl_88CAC988 when flag 4 is set, else to 0x883DA438 with the item's handle
 * (+0x28); 0x25 when arg is null or i is out of range.
 * Matched on /O1 as a C++ member: `lwzx r4, r9(i*4), r10(items)` needs items loaded off `this`; the extern "C" form
 * gives (items, i*4) (docs/agents/regalloc.md C1). */
struct Ts4ListItem {
    char pad00[0x28];
    void *handle;
};

extern "C" {
extern void *lbl_88CAC988;
int fn_883D38C8(void *mgr, Ts4ListItem *it, void *arg, unsigned int flags, int z);
int fn_883DA438(void *handle, Ts4ListItem *it, void *arg, unsigned int flags);
}

struct Ts4ItemList {
    char pad00[0x2c];
    unsigned int count;
    char pad30[4];
    Ts4ListItem **items;

    int Forward(unsigned int i, unsigned int flags, void *arg);
};

int Ts4ItemList::Forward(unsigned int i, unsigned int flags, void *arg)
{
    if (!arg || i >= count)
        return 0x25;
    Ts4ListItem *it = items[i];
    if (flags & 4)
        return fn_883D38C8(lbl_88CAC988, it, arg, flags, 0);
    return fn_883DA438(it->handle, it, arg, flags);
}
