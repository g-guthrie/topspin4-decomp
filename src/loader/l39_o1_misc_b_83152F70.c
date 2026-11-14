/* Loader_DLL.xex 0x83152F70-0x831A20C8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;
extern float lbl_830009F8;
extern float lbl_830009E0;
extern float lbl_8300568C;
extern float lbl_8300CCC0;
extern double lbl_83025D10;
extern u32 lbl_835280A8[];
extern u16 lbl_830298F0[];
extern int fn_831739A0(void *);
extern void fn_83120540(void *);
extern int ts4l_import_RtlTryEnterCriticalSection_83517858(void *);

void ts4l_push_83152F70(char *p, void *o)
{
    u32 n;
    if (o == 0)
        return;
    n = *(u32 *)(p + 0x190);
    if (n < 100) {
        *(void **)(p + n * 4) = o;
        *(int *)(p + 0x190) = *(int *)(p + 0x190) + 1;
        return;
    }
    fn_83120540(o);
}

int ts4l_scale_8315FD78(char *p)
{
    return (u32)(*(float *)(p + 0x14) * lbl_8300568C) + 7;
}

u32 ts4l_bitrev_8316B138(u32 x, int n)
{
    u32 r = 0;
    do {
        r |= x & 1;
        x >>= 1;
        r <<= 1;
    } while (--n > 0);
    return r >> 1;
}

int ts4l_hdr_size_8317E168(u16 *p, int f)
{
    u16 t = *p;
    if (t == 0x165)
        return 0x20;
    if (t == 1)
        return f ? 0x12 : 0x10;
    return p[8] + 0x12;
}

u32 ts4l_first_set_7c_8317F690(char *p)
{
    u32 v = *(u32 *)(p + 0x7c);
    if (v == 0) {
        char *w = *(char **)(p + 0x34);
        if (w != 0)
            v = *(u32 *)(w + 8);
        else
            v = *(u32 *)(p + 0x78);
    }
    return v;
}

long long *ts4l_set_scaled_8319D968(int b, long long *out)
{
    if (b == -1)
        return 0;
    *out = (u32)b * -10000LL;
    return out;
}

long long *ts4l_set_scaled_831A20C8(int b, long long *out)
{
    if (b == -1)
        return 0;
    *out = (u32)b * -10000LL;
    return out;
}
