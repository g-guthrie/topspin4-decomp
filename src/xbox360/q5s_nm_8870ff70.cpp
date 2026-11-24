/* Swing_DLL.xex 0x8870FF70 (/Oc): Ts4GaugeOwner::OnEvent. On event 0x87B1920F, while the holder's gauge is below
 * its maximum, adds the gauge rate to its value, clamps to the maximum, then refreshes the owner (fn_8870FE00).
 * Matched only with the holder handing out the gauge by reference (`Get().value += Get().rate`): that loads rate
 * (+0xc) before value (+0x10) for the fadds; every pointer form loads value first. */
struct Ts4GaugeEvent {
    int p0;
    unsigned int type;
};

struct Ts4Gauge {
    char p0[0xc];
    float rate;     /* 0x0c */
    float value;    /* 0x10 */
    float max;      /* 0x14 */
};

struct Ts4GaugeHolder {
    char p0[0xc];
    Ts4Gauge *gauge; /* 0x0c */
    Ts4Gauge &Get() { return *gauge; }
};

struct Ts4GaugeOwner {
    char p0[0x34];
    Ts4GaugeHolder *holder; /* 0x34 */
    void OnEvent(const Ts4GaugeEvent *ev);
};

extern "C" void fn_8870FE00(Ts4GaugeOwner *o);

void Ts4GaugeOwner::OnEvent(const Ts4GaugeEvent *ev)
{
    Ts4GaugeHolder *h = holder;
    if (h == 0 || h->gauge == 0)
        return;
    if (ev->type != 0x87B1920Fu)
        return;
    if (h->gauge->value < h->gauge->max) {
        h->Get().value += h->Get().rate;
        if (h->gauge->value > h->gauge->max)
            h->Get().value = h->Get().max;
        fn_8870FE00(this);
    }
}
