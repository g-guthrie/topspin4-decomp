/* Loader_DLL.xex 0x83261AA8-0x83261DB4, executable version 0.0.0.3. */
#ifndef _MSC_VER
#define __forceinline inline
#endif
#define TS4L_MAX(a, b) ((a) > (b) ? (a) : (b))

static __forceinline int ts4l_abs(int x)
{
    if (x < 0)
        return -x;
    return x;
}

/* Largest absolute value of the first `count` integers; 1, 2 and 6 are unrolled. */
int ts4l_max_abs_int_83261AA8(int *v, int count)
{
    int a0, a1, a2, a3, a4, a5, m, i;

    if (count == 1)
        return ts4l_abs(v[0]);
    if (count == 2) {
        a0 = ts4l_abs(v[0]);
        a1 = ts4l_abs(v[1]);
        return TS4L_MAX(a0, a1);
    }
    if (count == 6) {
        a0 = ts4l_abs(v[0]);
        a1 = ts4l_abs(v[1]);
        a2 = ts4l_abs(v[2]);
        a3 = ts4l_abs(v[3]);
        a4 = ts4l_abs(v[4]);
        a5 = ts4l_abs(v[5]);
        return TS4L_MAX(a0, TS4L_MAX(a1, TS4L_MAX(a2, TS4L_MAX(a3, TS4L_MAX(a4, a5)))));
    }
    m = 0;
    for (i = 0; i < count; i++) {
        int ax = ts4l_abs(v[i]);
        if (ax > m)
            m = ax;
    }
    return m;
}
