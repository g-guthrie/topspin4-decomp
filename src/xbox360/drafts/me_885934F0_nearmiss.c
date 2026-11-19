/* Swing_DLL.xex 0x885934F0: take the lowest free slot of a bit-mask slot pool (near miss, 1 off under /O1).
 * Remaining diff: the target emits xor r10,r10,r8 (mask ^ bit), ours xor r10,r8,r10; every operand order and form of the clear gives the same. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct SlotPool { u8 *data; u32 slotSize; u32 freeMask; } SlotPool;

/* Take the lowest free slot: isolate the low bit of the free mask, find its index, clear it, return the slot. */
void *fn_885934F0(SlotPool *p)
{
    void *slot = 0;
    u32 mask = p->freeMask;
    if (mask != 0) {
        u32 bit = mask & -mask;
        u32 index = (bit & 0xFFFF0000) != 0;
        index = (index << 1) | ((bit & 0xFF00FF00) != 0);
        index = (index << 1) | ((bit & 0xF0F0F0F0) != 0);
        index = (index << 1) | ((bit & 0xCCCCCCCC) != 0);
        index = (index << 1) | ((bit & 0xAAAAAAAA) != 0);
        p->freeMask = mask ^ bit;
        slot = p->data + index * p->slotSize;
    }
    return slot;
}
