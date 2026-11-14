/* Loader_DLL.xex 0x8329B7B0-0x832C0A63, executable version 0.0.0.3.
 * Small helpers: slice bounds, row wrappers, byte-add clamps, field
 * initialisers. */

#define W(p, o) (*(int *)((char *)(p) + (o)))
#define HW(p, o) (*(unsigned short *)((char *)(p) + (o)))

extern int fn_834D27B8(void *, void *, int, int, unsigned, unsigned);
extern int fn_834D3358(void *, void *, int, int, unsigned, unsigned);

int ts4l_scaled_index_8329B7B0(int a, int b, int c)
{
    int t, r, s;
    if (a == 0 && b == 0)
        return a;
    if (c == 1)
        return a;
    t = (a < 0 ? -a : a) - 1;
    r = t * c + b + 1;
    s = (a > 0) ? 1 : -1;
    return s * r;
}

void ts4l_slice_bounds_832A1198(void *o, int idx, unsigned *start, unsigned *end)
{
    unsigned stride = (unsigned)W(o, 0x180);
    unsigned e = (unsigned)(idx + 1) * stride;
    unsigned lim = HW(o, 0x34) >> 1;
    unsigned s = stride * (unsigned)idx;
    if (e > lim || idx == W(o, 0x17c) - 1)
        e = lim;
    *start = s;
    *end = e;
}

int ts4l_slice_call_832A1808(void *o, int a, int idx)
{
    char *sub = (char *)o + 0x3e70;
    unsigned stride, e, lim, s;
    if (sub != 0) {
        stride = (unsigned)W(sub, 0x180);
        e = (unsigned)(idx + 1) * stride;
        lim = HW(sub, 0x34) >> 1;
        s = stride * (unsigned)idx;
        if (e > lim || idx == W(sub, 0x17c) - 1)
            e = lim;
        return fn_834D27B8(o, sub, a, idx, s, e);
    }
    return -9;
}

int ts4l_slice_call_832A21D0(void *o, int a, int idx)
{
    char *sub = (char *)o + 0x3e70;
    unsigned stride, e, lim, s;
    if (sub != 0) {
        stride = (unsigned)W(sub, 0x180);
        e = (unsigned)(idx + 1) * stride;
        lim = HW(sub, 0x34) >> 1;
        s = stride * (unsigned)idx;
        if (e > lim || idx == W(sub, 0x17c) - 1)
            e = lim;
        return fn_834D3358(o, sub, a, idx, s, e);
    }
    return -9;
}

int ts4l_slice_call_832A2228(void *o, int a, int idx)
{
    char *sub = (char *)o + 0x4710;
    unsigned stride, e, lim, s;
    if (sub != 0) {
        stride = (unsigned)W(sub, 0x180);
        e = (unsigned)(idx + 1) * stride;
        lim = HW(sub, 0x34) >> 1;
        s = stride * (unsigned)idx;
        if (e > lim || idx == W(sub, 0x17c) - 1)
            e = lim;
        return fn_834D3358(o, sub, a, idx, s, e);
    }
    return -9;
}

void ts4l_add_bias_clamp_832BEE60(unsigned char *a, unsigned char *b, unsigned char *dst, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        int v = a[i] + b[i] - 128;
        if (v < 0)
            v = 0;
        else if (v > 255)
            v = 255;
        dst[i] = (unsigned char)v;
    }
}

void ts4l_add_clamp_hi_832C09C8(unsigned char *dst, unsigned char *a, unsigned char *b, int n, int bias)
{
    int i;
    for (i = 0; i < n; i++) {
        int v = a[i] + b[i] + bias;
        if (v > 255)
            v = 255;
        dst[i] = (unsigned char)v;
    }
}

void ts4l_add_bias_clamp_832C0A10(unsigned char *dst, unsigned char *a, unsigned char *b, int n, int bias)
{
    int i;
    for (i = 0; i < n; i++) {
        int v = a[i] + b[i] + bias - 128;
        if (v < 0)
            v = 0;
        else if (v > 255)
            v = 255;
        dst[i] = (unsigned char)v;
    }
}

int ts4l_set_abs_params_832B5F40(void *o, int a, int b, int c, int d)
{
    if (o == 0)
        return -3;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (c < 0)
        c = -c;
    if (d < 0)
        d = -d;
    W(o, 0x14) = a;
    W(o, 0x3c1c) = b;
    W(o, 0x3c20) = c;
    W(o, 0x3c24) = d;
    W(o, 0x3c28) = 1;
    return 0;
}

int ts4l_init_ids_832A0AB8(void *o, unsigned n)
{
    if (o == 0)
        return -0x1b;
    if (n != 0x18)
        return -0x1c;
    W(o, 0xc) = -1;
    HW(o, 4) = 0;
    W(o, 0) = 0;
    W(o, 8) = 0;
    ((signed char *)o)[0x10] = -1;
    ((signed char *)o)[0x11] = -1;
    ((signed char *)o)[0x12] = -1;
    ((signed char *)o)[0x13] = -1;
    W(o, 0x14) = -2;
    return 0;
}
