/* 0x886DFAE8 near miss (34 off, /Oc plain; sibling of 0x886DCE78): adds the pending release budget, releases ring
 * entries from the front while age <= script constant [111] and budget remains, shifts ring/anim timelines back by
 * the last span, erases the released prefix, unlinks the new front, reschedules. Residue: budget add/store order
 * (game stores budget before loading the ring), anim/clock register pair, front clrrwi copy. */

typedef unsigned int u32;
extern const float g_ts4_script_constants[];
extern void *fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Ts4RingEntry { char p[0x20]; float age; float span; char p2[0x34 - 0x28]; int linked; } Ts4RingEntry;
typedef struct Ts4RingVec { Ts4RingEntry **begin, **end; } Ts4RingVec;
typedef struct Ts4Clock { char p[0x44]; float t; } Ts4Clock;
typedef struct Ts4Timeline { char p[8]; Ts4Clock *clock; char p2[0x20 - 0xc]; float t; } Ts4Timeline;
typedef struct Ts4Anim { char p[0x430]; Ts4Timeline tl; char p2[0x5f4 - 0x454]; unsigned char *paused; } Ts4Anim;
typedef struct Ts4Ring { char p[0x18]; float t; char p1c[4]; Ts4Anim *anim; char p2[0x58 - 0x24]; char sched[4]; Ts4RingVec entries; char p3[0xa0 - 0x64]; char slots[4]; } Ts4Ring;
void ts4_r2_swing_ring_release_entry_886DC9C0(Ts4Ring *self, Ts4RingEntry *e);
void ts4_claim_slot_886CC408(void *slots, int count, float span);
void fn_886D6820(void *sched);
typedef struct Ts4RingUser { char p[0x1c]; Ts4Anim *anim; Ts4Ring *ring; char p24[4]; unsigned budget; unsigned pending; } Ts4RingUser;
void ts4_ring_user_release(Ts4RingUser *self)
{
    Ts4Ring *ring;
    Ts4RingEntry **begin, **end, **it;
    unsigned count = 0;
    float span;
    { unsigned *pb = &self->budget; *pb = self->pending + *pb; }
    ring = self->ring;
    self->pending = 0;
    begin = ring->entries.begin; end = ring->entries.end; it = begin;
    if (it == end) return;
    {
        float limit = g_ts4_script_constants[111];
        do {
            Ts4RingEntry *e = *it;
            float age = e->age;
            span = e->span;
            if (age > limit) break;
            if (self->budget <= 0) break;
            ts4_r2_swing_ring_release_entry_886DC9C0(self->ring, e);
            it++;
            count++;
            self->budget--;
        } while (it != end);
    }
    if (count == 0) return;
    {
        float d = -span;
        Ts4Timeline *tl;
        self->ring->t = self->ring->t + d;
        tl = &self->anim->tl;
        tl->clock->t = d + tl->clock->t;
        tl->t = d + tl->t;
    }
    {
        Ts4RingVec *v = &self->ring->entries;
        Ts4RingEntry **ne;
        if (v->end == it) ne = begin;
        else { u32 n = (u32)((char *)v->end - (char *)it); ne = (Ts4RingEntry **)((char *)fn_88562DC0(begin, it, n) + n); }
        v->end = ne;
    }
    if (self->ring->entries.begin != self->ring->entries.end) (*self->ring->entries.begin)->linked = 0;
    fn_886D6820(self->ring->sched);
}
