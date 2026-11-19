/* 0x883E3C98: stores target at +0x144 and, when it is non-null, binds each of the four 0x4c-byte slots at +0x14 via fn(target, slot), returning the first error. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct Slot { char b[0x4c]; } Slot;
typedef struct T { char pad[0x14]; Slot slots[4]; void *target; } T;
int ts4_lookup_then_forward_88317C68(void *target, Slot *s);
int ts4_bind_slots_883E3C98(T *t, void *target)
{
    int i;
    t->target = target;
    if (target) {
        for (i = 0; i < 4; i++) {
            int r = ts4_lookup_then_forward_88317C68(t->target, &t->slots[i]);
            if (r)
                return r;
        }
    }
    return 0;
}
