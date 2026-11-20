/* 0x883CC1F0: counts down the start delay at q+0x1C by dt; when it expires, sets the handle level to 0 (flag 0x100000, then stop(1)) or to b*a; while still delayed, keeps the handle level at progress * b * a */
/* Matched on /O1 plain only (work/army/ME/v.py chk); QH() is the null-guarded q->h macro, re-read at each use as in the target; C++ virtual stop (slot 4). */
struct Q { char pad[0x18]; void *h; unsigned short delay; };
struct T {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int stop(int a);
    char p4[0x30 - 4]; float a, b; char p38[0x60 - 0x38]; unsigned int flags; char p64[0xAC - 0x64]; Q *q;
};
extern "C" int ts4_fetch_then_use_float_88317A60(void *h, float v);
extern "C" int ts4_lookup_then_forward_88317AA8(void *h, float *out);
extern "C" float ts4_progress_ratio_883C9520(T *t);
#define QH(t) ((t)->q ? (t)->q->h : 0)
extern "C" int ts4_tick_fade_delay_883CC1F0(T *t, int dt)
{
    int r;
    float cur, v;
    if (!(t->flags & 0x2000) && t->q->delay) {
        t->q->delay -= dt;
        if ((short)t->q->delay <= 0) {
            t->q->delay = 0;
            if (QH(t)) {
                r = ts4_fetch_then_use_float_88317A60(QH(t), (t->flags & 0x100000) ? 0.0f : t->b * t->a);
                if (r) return r;
            }
            if (t->flags & 0x100000) {
                t->stop(1);
                return 0;
            }
        }
    }
    if ((short)t->q->delay > 0 && QH(t)) {
        r = ts4_lookup_then_forward_88317AA8(QH(t), &cur);
        if (r) return r;
        v = ts4_progress_ratio_883C9520(t) * t->b * t->a;
        if (v != cur) {
            r = ts4_fetch_then_use_float_88317A60(QH(t), v);
            if (r) return r;
        }
    }
    return 0;
}
