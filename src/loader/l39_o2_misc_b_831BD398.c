/* Loader_DLL.xex 0x831BD398-0x832270E0, executable version 0.0.0.3. */
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

void ts4l_put3_831BD398(int v, u8 *d, int unused, int i)
{
    u8 *q = d + i * 3;
    (void)unused;
    q[2] = (u8)v;
    v >>= 8;
    q[1] = (u8)v;
    v >>= 8;
    q[0] = (u8)v;
}

void ts4l_calc_831CD980(char *p)
{
    u16 n = (u16)((((*(u16 *)(p + 0xe)) + 7) / 8) * *(u16 *)(p + 2));
    *(u16 *)(p + 0xc) = n;
    *(u32 *)(p + 8) = *(u32 *)(p + 4) * n;
}

u32 ts4l_read_u16_831F62C0(u8 **pp)
{
    u8 *q = *pp;
    u32 v = q[0] + (q[1] << 8);
    *pp = q + 2;
    return v;
}

int ts4l_read_f_831F62E0(float **pp)
{
    float *q = *pp;
    *pp = q + 1;
    return (int)(*q * lbl_83025D10);
}

void ts4l_write_f_831F6348(float **pp, int n)
{
    float *q = *pp;
    *pp = q + 1;
    *q = (float)n * lbl_8300CCC0;
}

void ts4l_mul_loop_832014C0(int *a, int n, short s)
{
    int i;
    for (i = 0; i < n; i++)
        a[i] *= s;
}

int ts4l_copy16_8321ED40(char *p, int *out)
{
    int *s = *(int *)(p + 0x70) ? (int *)(p + 0x60) : (int *)(p + 0x50);
    out[0] = s[0];
    out[1] = s[1];
    out[2] = s[2];
    out[3] = s[3];
    return 0;
}

u32 ts4l_try_enter_832270E0(char *p)
{
    return ts4l_import_RtlTryEnterCriticalSection_83517858(p + 0x10) == 0 ? 0x80004005 : 0;
}
