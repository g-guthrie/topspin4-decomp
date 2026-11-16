#include "vx1_vector.h"
/* 0x886964C0: drains the pending-command queue. Each queued entry (state 1) is consumed in order:
 * two named commands toggle the active flag and reset the limit, one resets only the limit, and one
 * forwards the entry's vector to the block-parameter setter. Stops at the first non-pending entry. */
typedef struct Cmd { char p[0x10]; __vector4 v; unsigned int hash; unsigned char state; char p2[0x30 - 0x25]; } Cmd;
typedef struct Queue { volatile int offset; int count; char p[4]; unsigned char pending; } Queue;
typedef struct W6dE W6dE;
typedef struct Owner { char p[0x14]; int active; char p2[0x20 - 0x18]; W6dE *block; char p3[0x34 - 0x24]; Queue *queue; char p4[0x44 - 0x38]; int limit; } Owner;
void ts4_set_block_params_8865ECE0(W6dE *self, __vector4 v);
static __forceinline Cmd *q_begin(Queue *q) { int off = q->offset; Cmd *r = 0; if (off != -1) r = (Cmd *)((char *)q + off); return r; }
static __forceinline Cmd *q_end(Queue *q) { int off = q->offset; Cmd *r = 0; if (off != -1) r = (Cmd *)((char *)q + (q->count * 48 + off)); return r; }
void ts4_drain_pending_commands_886964C0(Owner *o)
{
    Queue *q = o->queue;
    Cmd *e, *end;
    if (!q->pending) return;
    q->pending = 1;
    q = o->queue;
    e = q_begin(q); end = q_end(q);
    for (; e != end; e++) {
        if (e->state != 1) return;
        e->state = 0;
        if (e->hash == 0x6437E5EF) { o->active = 1; o->limit = 0x7FFFFFFF; }
        else if (e->hash == 0xC9250733) { o->active = 0; o->limit = 0x7FFFFFFF; }
        else if (e->hash == 0x4F9FF028) { o->limit = 0x7FFFFFFF; }
        else if (e->hash == 0xA963206A) { ts4_set_block_params_8865ECE0(o->block, e->v); }
    }
}
