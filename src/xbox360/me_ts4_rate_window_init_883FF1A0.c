/* 0x883FF1A0: binds a stream to its service, doubles the reported length, stores the sample rate and derives two rounded windows (rate*0.4, rate*0.1) and unity gain. All four float constants must be literals (0.4f, 0.1f, 0.5f, 1.0f); any extern breaks scheduling */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef unsigned long long u64;
typedef struct Sys { char pad[0xc]; void *svc; } Sys;
typedef struct T {
    int p0;
    Sys *sys;
    char pad0[0x20 - 8];
    unsigned int lo;
    unsigned int hi;
    int len;
    unsigned int rate;
    unsigned char b30, b31;
    char pad1[0x38 - 0x32];
    u64 q38, q40;
    float gain;
    void *cb;
} T;
int ts4_if_call_seq_fn_88309DB8_88308BC0(void *svc, int *out, int a);
int ts4_if_call_seq_fn_88309DB8_88308B60(void *svc, unsigned int *rate, int a, int b, int c, int d, int e);

int fn_883FF1A0(T *t, Sys *sys, void *cb)
{
    int r; unsigned int rate;
    t->sys = sys;
    r = ts4_if_call_seq_fn_88309DB8_88308BC0(sys->svc, &t->len, 0);
    if (r)
        return r;
    t->len *= 2;
    r = ts4_if_call_seq_fn_88309DB8_88308B60(t->sys->svc, &rate, 0, 0, 0, 0, 0);
    if (r)
        return r;
    t->cb = cb;
    t->rate = rate;
    t->b30 = 0;
    t->b31 = 0;
    t->gain = 1.0f;
    t->q38 = 0;
    t->q40 = 0;
    t->hi = (unsigned int)((float)rate * 0.4f + 0.5f);
    t->lo = (unsigned int)((float)rate * 0.1f + 0.5f);
    return 0;
}
