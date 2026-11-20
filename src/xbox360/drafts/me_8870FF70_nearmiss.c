/* 0x8870FF70: On event 0x87B1920F, adds rate to value on the holder gauge while below max, clamps to max, then calls fn_8870FE00(o). */
/* Near miss (agAH): /Oc, 3 off: the target loads rate (0xc) before value (0x10) for the fadds; every operand order tried loads value first. */
typedef struct Gauge { char p0[0xc]; float rate; float value; float max; } Gauge;
typedef struct Holder { char p0[0xc]; Gauge *gauge; } Holder;
typedef struct Owner { char p0[0x34]; Holder *holder; } Owner;
typedef struct Event { int p0; unsigned int type; } Event;
extern void fn_8870FE00(Owner *o);
static Gauge *holder_gauge(Holder *h)
{
    return h->gauge;
}
void fn_8870FF70(Owner *o, const Event *ev)
{
    Holder *h = o->holder;
    if (h == 0 || h->gauge == 0)
        return;
    if (ev->type != 0x87B1920Fu)
        return;
    if (h->gauge->value < h->gauge->max) {
        Gauge *g = holder_gauge(h);
        g->value = g->rate + g->value;
        if (h->gauge->value > h->gauge->max) {
            g = holder_gauge(h);
            g->value = g->max;
        }
        fn_8870FE00(o);
    }
}
