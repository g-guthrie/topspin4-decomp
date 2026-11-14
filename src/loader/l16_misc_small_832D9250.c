/* Loader_DLL.xex 0x832D9250-0x8332B0D7, executable version 0.0.0.3.
 * Small helpers: format-code tests, row copies, median, byte reversal,
 * bound checks, RC4 key setup. */

#define W(p, o) (*(int *)((char *)(p) + (o)))

extern void fn_833E3AD0(void *, const void *, unsigned);

int ts4l_is_packed_fourcc_832DB9F8(int a, int fmt)
{
    (void)a;
    if (fmt == 0x56555949 || fmt == 0x30323449 || fmt == 0x32315659 || fmt == 0x31313450)
        return 1;
    return 0;
}

int ts4l_fourcc_class_832DC8E0(void *o)
{
    unsigned *p = *(unsigned **)o;
    unsigned fmt;
    if (p == 0)
        return 0;
    fmt = p[4];
    if (fmt == 0x56555949u || fmt == 0x30323449u || fmt == 0x31313450u || fmt == 0x32315659u)
        return 1;
    return 2;
}

void ts4l_copy_16_rows_832E04B0(unsigned char *dst, unsigned char *src, int sstride, int dstride)
{
    int i;
    for (i = 16; i != 0; i--) {
        fn_833E3AD0(dst, src, 16);
        src += sstride;
        dst += dstride;
    }
}

short ts4l_median3_833019E8(short a, short b, short c)
{
    if (a > b) {
        if (b > c)
            return b;
        if (a <= c)
            return a;
        return c;
    }
    if (a > c)
        return a;
    if (b > c)
        return c;
    return b;
}

void ts4l_reverse_copy_8332AA88(unsigned char *dst, unsigned char *src, unsigned n)
{
    unsigned char *d;
    unsigned i;
    if (dst == 0 || src == 0 || n == 0)
        return;
    d = dst + n - 1;
    for (i = 0; i < n; i++)
        *d-- = *src++;
}
