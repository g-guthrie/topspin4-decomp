/* Swing_DLL.xex 0x889A0540: one-time init of a 64-entry id table: when no owner is set, allocates 0x100 bytes (kind 2) from lbl_88D45B38, fills every slot with 0x80000000, stores the owner and returns 1; otherwise returns 0.
 * /Oc near miss, 1 off: the fill stwx operand order (target index-first, stwx r9,r10,r8). Same open family as 88423C28; signed/unsigned index, i[p], *(p+i) and byte-offset forms do not change it. */
typedef struct IdTable { unsigned int *ids; int capacity; unsigned int owner; } IdTable;
extern void *lbl_88D45B38;
void *ts4_node_dispatch_with_target_88613268(void *alloc, unsigned int size, unsigned int align, void *owner, int kind);

int fn_889A0540(IdTable *t, unsigned int owner)
{
    int i;
    if (t->owner <= 0) {
        t->ids = (unsigned int *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x100, 4, 0, 2);
        t->capacity = 64;
        for (i = 0; i < t->capacity; i++)
            t->ids[i] = 0x80000000;
        t->owner = owner;
        return 1;
    }
    return 0;
}
