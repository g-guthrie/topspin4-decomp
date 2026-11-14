/* Loader_DLL.xex 0x831C67C8-0x83261340, executable version 0.0.0.3. */
/* Running smoothing over a buffer: after the initial fill, each element accumulates
 * a rounded, scaled copy of its predecessor. */
extern int fn_832014C0(int *, int, unsigned);
extern int fn_8326C1B8(int *, int, unsigned);
typedef struct { char pad0[0xae]; unsigned short s; char pad1[0x278 - 0xb0]; int mul; } Ts4lSmoothObj;

int ts4l_smooth_prefix_831C67C8(Ts4lSmoothObj *o, int a1, int *buf, int a3, int n)
{
    short i;

    (void)a1;
    (void)a3;
    fn_832014C0(buf, n, o->s);
    if (n > 1) {
        for (i = 1; i < n; i++)
            buf[i] += (buf[i - 1] * o->mul + 0x20) >> 6;
    }
    return 1;
}

int ts4l_smooth_prefix_832612C8(Ts4lSmoothObj *o, int a1, int *buf, int a3, int n)
{
    short i;

    (void)a1;
    (void)a3;
    fn_8326C1B8(buf, n, o->s);
    if (n > 1) {
        for (i = 1; i < n; i++)
            buf[i] += (buf[i - 1] * o->mul + 0x20) >> 6;
    }
    return 1;
}
