/* agentB 2026-11-18 pass 2: still 5 off. Function pads 0-16 (period 8: 0/8 give 5, others 16-18), loop-block pads 1-9, hist-first,
 * cap-last, block-local Inner/Hist, volatile inner read, named hist begin: 5-17. fk3_000.c as LTCG context fails to link. */
/* 0x886D1578 near miss (5 off, /Oc plain C; sweep 2026-11-18: 10 more incl. volatile casts on inner/cfg/hist/end/begin, used-first order, LTCG, /Ob1: still 5). Ring-buffer flush: for each queued index whose history sample is older
 * than max_age, hands the pending slot to the first free slot (ts4_get_u32_off40_882625F0), clears it, advances head.
 * Residue: r10/r11 swap between q->inner and q->hist in the prologue loads. Tried 5 declaration orders / named locals
 * (5-17 off); round 2: hist_len/qcap inline helpers, block-local Hist* and Cfg*, tail local, 1/2/4 dead-int pads (5-16 off). Keys found: head update inside the found branch; pend_at = r + i*sizeof(Slot) + *r. */
typedef unsigned int u32;
typedef struct Slot { char _0[0x44]; void *busy; char _48[0x38]; } Slot;
typedef struct SlotRange { int offset; int count; } SlotRange;
typedef struct Cfg { char _0[0x490]; int pending_off; u32 capacity; char _498[4]; SlotRange free; } Cfg;
typedef struct Inner { char _0[0x14]; Cfg *cfg; } Inner;
typedef struct Sample { char _0[0x24]; float time; } Sample;
typedef struct Hist { char _0[0x18]; float now; char _1c[0x40]; Sample **begin, **end; } Hist;
typedef struct Queue { char _0[0x10]; float max_age; u32 head, tail; Inner *inner; Hist *hist; } Queue;
float ts4_get_u32_off40_882625F0(Slot *dst, Slot *src);
static __inline Slot *range_begin(SlotRange *r) { Slot *p = 0; if (r->offset != -1) p = (Slot *)((char *)r + r->offset); return p; }
static __inline Slot *range_end(SlotRange *r) { Slot *p = 0; if (r->offset != -1) p = (Slot *)((char *)r + r->offset) + r->count; return p; }
static __inline unsigned char too_old(Queue *q, Sample *s) { return s->time - q->hist->now > q->max_age; }
static __inline Slot *pend_at(int *r, u32 i) { return (Slot *)((char *)r + i * sizeof(Slot) + *r); }
void ts4_queue_flush_expired_886D1578(Queue *q)
{
    u32 cap = q->inner->cfg->capacity;
    u32 head = q->head;
    int nhist = q->hist->end - q->hist->begin;
    u32 used = (q->tail - head) % cap;
    u32 i;
    for (i = head; i != q->tail; i = (i + 1) % cap) {
        Sample *s = q->hist->begin[(i - head) % cap - used + nhist];
        Cfg *cfg;
        Slot *p, *e;
        if (too_old(q, s))
            return;
        cfg = q->inner->cfg;
        p = range_begin(&cfg->free);
        e = range_end(&cfg->free);
        for (; p != e; p++) {
            if (!p->busy) {
                ts4_get_u32_off40_882625F0(p, pend_at(&cfg->pending_off, i));
                pend_at(&q->inner->cfg->pending_off, i)->busy = 0;
                q->head = (q->head + 1) % cap;
                break;
            }
        }
    }
}
