/* 0x88586858: Walks the slot ring from the slot after head back round to head, calling fn_88586700 on each idle slot with flags 0x40 and 0x8 set. Stops early on a negative result. */
/* Matched on /O1 (agAH). Natural for(;;) loop. */
typedef struct Slot { unsigned int data; unsigned char busy; unsigned char pad5; unsigned char next; unsigned char flags; } Slot;
typedef struct Pool { char p0[0x30]; Slot *slots; char p34[0xc9 - 0x34]; unsigned char head; } Pool;
extern int fn_88586700(Pool *pool, unsigned int idx, Slot *slot);
int fn_88586858(Pool *pool)
{
    Slot *slots = pool->slots;
    Slot *start = &slots[pool->head];
    unsigned int idx = start->next;
    for (;;) {
        Slot *s = &slots[idx];
        if (s->busy == 0 && (s->flags & 0x40) && (s->flags & 0x8)) {
            int r = fn_88586700(pool, idx, s);
            if (r < 0)
                return r;
        }
        if (s == start)
            return 0;
        idx = s->next;
    }
}
