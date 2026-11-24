/* Loader_DLL.xex 0x8332B940-0x8332BADC / 0x833C2DB0-0x833C2F4C, executable version 0.0.0.3. */
#define TS4L_RANGE_STEP(v) \
    if (mn > (v)) mn = (v); \
    else if ((v) > mx) mx = (v)

int ts4l_range_below8_8332B940(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int thr)
{
    int mn, mx;
    if (a0 >= a7) {
        mn = a7;
        mx = a0;
    } else {
        mn = a0;
        mx = a7;
    }
    TS4L_RANGE_STEP(a2);
    TS4L_RANGE_STEP(a4);
    if (mx - mn >= thr) return 0;
    TS4L_RANGE_STEP(a1);
    TS4L_RANGE_STEP(a3);
    TS4L_RANGE_STEP(a5);
    TS4L_RANGE_STEP(a6);
    return (mx - mn) < thr;
}

int ts4l_range_below8_833C2DB0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int thr)
{
    int mn, mx;
    if (a0 >= a7) {
        mn = a7;
        mx = a0;
    } else {
        mn = a0;
        mx = a7;
    }
    TS4L_RANGE_STEP(a2);
    TS4L_RANGE_STEP(a4);
    if (mx - mn >= thr) return 0;
    TS4L_RANGE_STEP(a1);
    TS4L_RANGE_STEP(a3);
    TS4L_RANGE_STEP(a5);
    TS4L_RANGE_STEP(a6);
    return (mx - mn) < thr;
}

int ts4l_range_below_8332BA38(int a0, int a1, int a2, int a3, int a4, int a5, int thr)
{
    int mn, mx;
    if (a0 >= a5) {
        mn = a5;
        mx = a0;
    } else {
        mn = a0;
        mx = a5;
    }
    TS4L_RANGE_STEP(a2);
    TS4L_RANGE_STEP(a4);
    TS4L_RANGE_STEP(a1);
    TS4L_RANGE_STEP(a3);
    return (mx - mn) < thr;
}

int ts4l_range_below_833C2EA8(int a0, int a1, int a2, int a3, int a4, int a5, int thr)
{
    int mn, mx;
    if (a0 >= a5) {
        mn = a5;
        mx = a0;
    } else {
        mn = a0;
        mx = a5;
    }
    TS4L_RANGE_STEP(a2);
    TS4L_RANGE_STEP(a4);
    TS4L_RANGE_STEP(a1);
    TS4L_RANGE_STEP(a3);
    return (mx - mn) < thr;
}
