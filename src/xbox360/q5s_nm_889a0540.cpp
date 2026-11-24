/* Swing_DLL.xex 0x889A0540: Ts4IdTable::Init — one-time init of a 64-entry id
 * table. When no owner is set, allocates 0x100 bytes (kind 2) from
 * lbl_88D45B38, fills every slot with 0x80000000, stores the owner and
 * returns 1; otherwise returns 0. Called from ts4_renumber_889A4888.
 * Byte-exact only as a C++ member: `this` is numbered after the explicit
 * parameter, so the fill stwx comes out index-first (stwx r9,r10,r8); as an
 * extern "C" function taking the table first it is base-first (1 off). */
extern "C" void *lbl_88D45B38;
extern "C" void *ts4_node_dispatch_with_target_88613268(void *alloc, unsigned int size,
                                                        unsigned int align, void *owner, int kind);

struct Ts4IdTable {
    unsigned int *ids;
    int capacity;
    unsigned int owner;
    int Init(unsigned int newOwner);
};

int Ts4IdTable::Init(unsigned int newOwner)
{
    if (owner <= 0) {
        ids = (unsigned int *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x100, 4, 0, 2);
        capacity = 64;
        for (int i = 0; i < capacity; i++)
            ids[i] = 0x80000000;
        owner = newOwner;
        return 1;
    }
    return 0;
}
