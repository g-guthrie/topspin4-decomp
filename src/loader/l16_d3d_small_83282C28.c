/* Loader_DLL.xex 0x83282C28-0x832A3A5F, executable version 0.0.0.3.
 * Small Direct3D device-state helpers (field setters, size/pitch
 * computation, timers, event signalling). */

#define W(p, o) (*(int *)((char *)(p) + (o)))
#define UW(p, o) (*(unsigned *)((char *)(p) + (o)))
#define LL(p, o) (*(long long *)((char *)(p) + (o)))

extern int lbl_8303AE58[];
extern void fn_8340BCE8(long long *);
extern void ts4_if_call_seq_NtSetEvent_8340AED8(void *);
extern void fn_833E3F58(void *, void *, unsigned);

void ts4l_align_dims_83282C28(void *o, int w, int h, int *out)
{
    int a = (w + 15) & ~15;
    int b = (h + 15) & ~15;
    int x, y;
    if (W(o, 0xf8c) != 0) {
        x = a >> 2;
        y = b;
    } else {
        x = a >> 1;
        y = b >> 1;
    }
    if (W(o, 0x3cb0) == 7) {
        b = (b + 31) & ~31;
        y = b >> 1;
    }
    out[0] = a;
    out[1] = b;
    out[2] = x;
    out[3] = y;
    out[4] = 32;
    out[5] = 16;
}

void ts4l_query_mode_832938D0(void *o, int *out1, int *out2)
{
    int v = 2;
    int mode = W(o, 0x3cb0);
    if (mode == 6) {
        if (W(o, 0xf8c) != 0)
            v = 3;
    } else if (mode == 7) {
        if (W(o, 0x50c8) != 0 || W(o, 0x50cc) != 0)
            v = 3;
    }
    *out1 = v;
    *out2 = 0;
}

void ts4l_pick_mode_832933B8(void *o)
{
    int px = W(o, 0xbc) * W(o, 0xb4);
    if (W(o, 0xe84) <= 300 && px <= 0x12c00) {
        if (px > 0xa500)
            W(o, 0x3cec) = 4;
        else
            W(o, 0x3cec) = 1;
    } else {
        W(o, 0x3ce0) = 0;
    }
}

void ts4l_timer_start_8329F888(void *o)
{
    long long t;
    if (o != 0) {
        if (W(o, 0x4ff8) == 0) {
            fn_8340BCE8(&t);
            LL(o, 0x4fe0) = LL(o, 0x4fe0) - t;
            W(o, 0x4ff8) = 1;
        }
    }
}

void ts4l_timer_stop_8329F8E8(void *o)
{
    long long t;
    if (o != 0) {
        if (W(o, 0x4ff8) != 0) {
            fn_8340BCE8(&t);
            LL(o, 0x4fe0) = LL(o, 0x4fe0) + t;
            W(o, 0x4ff8) = 0;
        }
    }
}

void ts4l_timer_mark_8329F948(void *o)
{
    long long t;
    if (o != 0) {
        if (W(o, 0x4ffc) == 0) {
            fn_8340BCE8(&t);
            W(o, 0x4ffc) = 1;
            LL(o, 0x4fe8) = -t;
            LL(o, 0x4ff0) = t;
        }
    }
}

void ts4l_signal_events_8329FF70(void *o)
{
    void **p = (void **)((char *)o + 0x398);
    int n = 2;
    do {
        if (*p != 0)
            ts4_if_call_seq_NtSetEvent_8340AED8(*p);
        p++;
    } while (--n != 0);
}
