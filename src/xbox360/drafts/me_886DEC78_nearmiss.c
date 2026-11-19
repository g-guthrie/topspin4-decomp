/* 0x886DEC78 near miss (82 off, /Oc plain; first rough pass): takes the next message slot from the 0x84-byte pool
 * (wraps to slot 0), resets it (same inline reset as 0x886CC058), points it at the clip record (index from the
 * self-relative 0x8C table, 16-byte clip stride), queues it (fn_881898E8), handles it (fn_886DC8B0) and reschedules.
 * Residue: size 0x16C vs 0x15C, relocation count 9 vs 7 (zero/one constant loads), reset store scheduling. */
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef struct Accum4 { float v[4]; int n; } Accum4;
typedef struct Ts4Msg {
    const void *vtbl; char *clip; const void *vtbl2;
    float f0c[9];
    int f30, f34;
    float f38, scale, f40;
    Accum4 a, b;
    int f6c; float f70; int f74, f78, f7c; unsigned char f80; char p81[3];
} Ts4Msg;
typedef struct Ts4MsgPool { Ts4Msg *begin, *end; char p[4]; unsigned next; int sent; } Ts4MsgPool;
typedef struct Ts4RelHdr { int self_off; } Ts4RelHdr;
typedef struct Ts4ClipTable { char p[0x50]; Ts4RelHdr entries; } Ts4ClipTable;
typedef struct Ts4ClipSet { char *clips; char p[8]; Ts4ClipTable *table; } Ts4ClipSet;
typedef struct Ts4Player { char p[0x28]; Ts4ClipSet *clips; char p2[0x58 - 0x2c]; char sched[4]; char queue[4]; char p3[0xd4 - 0x60]; Ts4MsgPool pool; } Ts4Player;
void fn_881898E8(void *vec, Ts4Msg **item);
void fn_886DC8B0(Ts4Player *self, Ts4Msg *m);
void fn_886D6820(void *sched);
static __inline void msg_reset(Ts4Msg *t)
{
    float z;
    t->f34 = 0; t->clip = 0;
    t->scale = g_ts4_script_constants[0];
    z = g_ts4_event_value;
    t->f38 = z; t->f40 = z;
    t->f0c[0] = z; t->f0c[1] = z; t->f0c[2] = z; t->f0c[3] = z;
    t->a.n = 0; t->a.v[0] = z; t->a.v[1] = z; t->a.v[2] = z; t->a.v[3] = z;
    t->f6c = 0; t->f0c[4] = z; t->f74 = 0; t->f0c[5] = z; t->f78 = 0; t->f0c[6] = z; t->f7c = 0;
    t->f0c[7] = z; t->f80 = 0; t->f0c[8] = z; t->f70 = z;
}
void ts4_player_send_clip(Ts4Player *self, char *entry)
{
    Ts4MsgPool *p = &self->pool;
    Ts4Msg *m = p->begin;
    unsigned n = (unsigned)(p->end - p->begin);
    p->sent++;
    if (p->next == n) p->next = 1;
    else { m = m + p->next; p->next++; }
    msg_reset(m);
    {
        Ts4ClipSet *cs = self->clips;
        Ts4RelHdr *h = &cs->table->entries;
        char *base = 0;
        if (h->self_off != -1) base = (char *)h + h->self_off;
        m->clip = cs->clips + ((entry - base) / 0x8c) * 16;
    }
    m->f0c[2] = g_ts4_event_value; m->f0c[3] = g_ts4_event_value;
    fn_881898E8(self->queue, &m);
    fn_886DC8B0(self, m);
    fn_886D6820(self->sched);
}
