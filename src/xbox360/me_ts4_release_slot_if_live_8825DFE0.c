/* 0x8825DFE0: Releases the 0x44-byte slot index of the pool (ts4_release_three_88753388) when the index is non-negative, not on the free list at +0x14..+0x18, and the slot is not pinned (+0xd). */
/* Matched on /Oc (agAH). End pointer read into a local first and compared as end != it (loads +0x18 before +0x14). */
typedef struct Slot44 { char pad[0xd]; unsigned char pinned; char pade[0x44 - 0xe]; } Slot44;
void ts4_release_three_88753388(Slot44 *s);
typedef struct SlotPool {
    char pad[0x14];
    unsigned int *freeBegin;
    unsigned int *freeEnd;
    char pad1c[8];
    Slot44 *slots;
} SlotPool;
static __forceinline unsigned char SlotPool_IsLive(SlotPool *p, int index)
{
    unsigned int *it;
    unsigned int *end;
    if (index < 0)
        return 0;
    end = p->freeEnd;
    for (it = p->freeBegin; end != it; it++) {
        if ((unsigned int)index == *it)
            return 0;
    }
    return 1;
}
void fn_8825DFE0(SlotPool *p, int index)
{
    if (SlotPool_IsLive(p, index) == 1) {
        Slot44 *s = &p->slots[index];
        if (s->pinned == 0)
            ts4_release_three_88753388(s);
    }
}
