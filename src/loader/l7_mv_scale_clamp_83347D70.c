/* Loader_DLL.xex 0x83347D70-0x833482F0, executable version 0.0.0.3. */
typedef struct Ctx {
    char pad0[0x1a4];
    int limit_x;
    int limit_y;
    char pad1[0x50d0 - 0x1ac];
    int mode;
    char pad2[0x5520 - 0x50d4];
    int thr_x;
    int thr_y;
    int off_x;
    int off_y;
    int gain_lo;
    int gain_hi;
} Ctx;

typedef struct Ctx2 {
    char pad0[0x1a4];
    int limit_x;
    int limit_y;
    char pad1[0x50d0 - 0x1ac];
    int mode;
    char pad2[0x553c - 0x50d4];
    int thr_x;
    int thr_y;
    int off_x;
    int off_y;
    int gain_lo;
    int gain_hi;
} Ctx2;
#ifndef _MSC_VER
#define __forceinline inline
#endif

static __forceinline int ts4l_mv_curve(int v, volatile int *pthr, volatile int *pgl, volatile int *pgh, volatile int *poff, int maxabs)
{
    int a = v < 0 ? -v : v;
    if (a > maxabs)
        return v;
    if (a < *pthr)
        return (*pgl * v) >> 8;
    if (v < 0)
        return ((*pgh * v) >> 8) - *poff;
    return ((*pgh * v) >> 8) + *poff;
}

static __forceinline int ts4l_mv_curve2(int v, volatile int *pthr, volatile int *pgl, volatile int *pgh, volatile int *poff, int maxabs, int bias)
{
    int a = v < 0 ? -v : v;
    if (a > maxabs)
        return v * 2 + bias;
    if (a < *pthr)
        return ((*pgl * v) >> 8) * 2 + bias;
    if (v < 0)
        return (((*pgh * v) >> 8) - *poff) * 2 + bias;
    return (((*pgh * v) >> 8) + *poff) * 2 + bias;
}

void ts4l_mv_scale_clamp_83347D70(Ctx *c, int mx, int my, int *ox, int *oy, int flag)
{
    int x;
    int y;
    int t;
    int lim;
    x = ts4l_mv_curve(mx, &c->thr_x, &c->gain_lo, &c->gain_hi, &c->off_x, 0xff);
    if (flag != 0) {
        t = (c->mode == 0 ? my - 1 : my + 1) >> 1;
        y = ts4l_mv_curve2(t, &c->thr_y, &c->gain_lo, &c->gain_hi, &c->off_y, 0x3f, 0);
        lim = c->limit_y;
        if (y > lim - 2)
            y = lim - 2;
        lim = -lim;
    } else {
        t = my >> 1;
        if (c->mode == 0) {
            y = ts4l_mv_curve2(t, &c->thr_y, &c->gain_lo, &c->gain_hi, &c->off_y, 0x3f, 1);
        } else {
            y = ts4l_mv_curve2(t, &c->thr_y, &c->gain_lo, &c->gain_hi, &c->off_y, 0x3f, -1);
        }
        lim = c->limit_y;
        if (y > lim - 1)
            y = lim - 1;
        lim = 1 - lim;
    }
    if (y < lim)
        y = lim;
    lim = c->limit_x;
    if (x > lim - 1)
        x = lim - 1;
    if (x < -lim)
        x = -lim;
    *ox = x;
    *oy = y;
}

void ts4l_mv_scale_clamp_83348070(Ctx2 *c, int mx, int my, int *ox, int *oy, int flag)
{
    int x;
    int y;
    int t;
    int lim;
    x = ts4l_mv_curve(mx, &c->thr_x, &c->gain_lo, &c->gain_hi, &c->off_x, 0xff);
    if (flag != 0) {
        t = (c->mode == 0 ? my - 1 : my + 1) >> 1;
        y = ts4l_mv_curve2(t, &c->thr_y, &c->gain_lo, &c->gain_hi, &c->off_y, 0x3f, 0);
        lim = c->limit_y;
        if (y > lim - 2)
            y = lim - 2;
        lim = -lim;
    } else {
        t = my >> 1;
        if (c->mode == 0) {
            y = ts4l_mv_curve2(t, &c->thr_y, &c->gain_lo, &c->gain_hi, &c->off_y, 0x3f, 1);
        } else {
            y = ts4l_mv_curve2(t, &c->thr_y, &c->gain_lo, &c->gain_hi, &c->off_y, 0x3f, -1);
        }
        lim = c->limit_y;
        if (y > lim - 1)
            y = lim - 1;
        lim = 1 - lim;
    }
    if (y < lim)
        y = lim;
    lim = c->limit_x;
    if (x > lim - 1)
        x = lim - 1;
    if (x < -lim)
        x = -lim;
    *ox = x;
    *oy = y;
}
