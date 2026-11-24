/* Swing_DLL.xex 0x885934F0: take the lowest free slot of a bit-mask slot pool. Built /O1.
 * Isolates the low set bit of the free mask, computes its index with the five-mask binary search,
 * clears the bit and returns data + index * slotSize, or 0 when full.
 * Source shape: the mask is re-read as p->freeMask (no local) and cleared with `^=`. A `mask` local with
 * `p->freeMask = mask ^ bit` gives `xor bit, mask`; a local with `^=` gives the xor order but a cr0 compare. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct SlotPool { u8 *data; u32 slotSize; u32 freeMask; } SlotPool;

void *ts4_slot_pool_take_lowest_free_885934F0(SlotPool *p)
{
    void *slot = 0;
    if (p->freeMask != 0) {
        u32 bit = p->freeMask & -p->freeMask;
        u32 index = (bit & 0xFFFF0000) != 0;
        index = (index << 1) | ((bit & 0xFF00FF00) != 0);
        index = (index << 1) | ((bit & 0xF0F0F0F0) != 0);
        index = (index << 1) | ((bit & 0xCCCCCCCC) != 0);
        index = (index << 1) | ((bit & 0xAAAAAAAA) != 0);
        p->freeMask ^= bit;
        slot = p->data + index * p->slotSize;
    }
    return slot;
}
