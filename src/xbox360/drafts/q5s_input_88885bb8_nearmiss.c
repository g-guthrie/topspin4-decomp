/* nearmiss: 23 off (LTCG /Oc, pool primer); target copies this to r11 (mr r11,r3) and builds the value-store address in r3; ours gives the dead addi r10,r3,0x1c r11. Blocker: register-allocation only, no source lever found (C++ members, at() helper, split helpers tried). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct RingEnt { u8 done; char pad1[3]; u32 value; } RingEnt;
typedef struct Ring { u32 cap; RingEnt *buf; u32 pad24; u32 head; } Ring;
typedef struct RingOwner { char pad0[0x1c]; Ring ring; u32 count; } RingOwner;

static __inline void ring_push(Ring *r, u32 v)
{
    r->buf[r->head].done = 0;
    r->buf[r->head].value = v;
    r->head = (r->head + 1) % r->cap;
}

void ts4_input_ring_push_88885BB8(RingOwner *o, u32 v)
{
    ring_push(&o->ring, v);
    o->count++;
}
