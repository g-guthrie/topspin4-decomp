/* 0x886EEDF0: Adds the clock delta (vt slot 28) to t->elapsed, passes &elapsed to the scheduler advance (slot 34), and returns whether the scheduler reports t expired (slot 35, u8). */
/* Matched on /Oc (agAH). The &t->elapsed pointer local sets the vt-load scheduling. */
typedef struct Clock Clock;
typedef struct ClockVt { void *s[28]; float (*delta)(Clock *); } ClockVt;
struct Clock { ClockVt *vt; };
typedef struct Timer { char p0[0x54]; float elapsed; char p58[4]; Clock *clock; } Timer;
typedef struct Sched Sched;
typedef struct SchedVt { void *s[34]; void (*advance)(Sched *, float *); unsigned char (*expired)(Sched *, Timer *); } SchedVt;
struct Sched { SchedVt *vt; };
int fn_886EEDF0(Sched *s, Timer *t)
{
    float *e = &t->elapsed;
    *e += t->clock->vt->delta(t->clock);
    s->vt->advance(s, e);
    return s->vt->expired(s, t) != 0;
}
