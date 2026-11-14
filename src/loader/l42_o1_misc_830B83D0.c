/* Loader_DLL.xex 0x830B83D0-0x830CC088, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;
typedef unsigned char u8;

extern unsigned short lbl_83086A40[];
extern void fn_8340BCE8(s64 *out);
extern u32 fn_830C9D08(void);

u32 ts4l_perf_counter_shr10_830B83D0(void)
{
    s64 t;
    fn_8340BCE8(&t);
    return (u32)(t >> 10);
}

int ts4l_is_kernel_va_830B9938(u32 a)
{
    if (a >= 0xC0000000u && a <= 0xDFFFFFFFu)
        return 1;
    return 0;
}

void *ts4l_slot_ptr_830C0A30(char *o, int i)
{
    void *r = 0;
    u32 off = ((u32 *)o)[(i + 3) * 2];
    if (off)
        r = o + off;
    return r;
}

int ts4l_contains_830C2290(u32 key, const u32 *a, u32 n)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (a[i] == key)
            return 1;
    }
    return 0;
}



int ts4l_below_100_830C9680(void)
{
    return fn_830C9D08() < 0x100u;
}


int ts4l_is_type4_flag_830AE730(u32 *p)
{
    u32 v = *p;
    if ((v & 0xf) == 4 && (v & 0x40000000u))
        return 1;
    return 0;
}

int ts4l_tbl_nonzero_830AB6D0(u32 x)
{
    u32 i = x & 0x3f;
    if (i < 0x40) {
        if (lbl_83086A40[i] != 0)
            return 1;
    }
    return 0;
}

int ts4l_fill_m1_830D8018(char *o)
{
    int *p = (int *)(o + 0x5c30);
    int i;
    for (i = 0; i < 0x29; i++)
        p[i] = -1;
    return 1;
}

void *ts4l_first_nonzero_830FFF28(void **p)
{
    int i;
    for (i = 0; i < 27; i++) {
        if (p[i] != 0)
            return p[i];
    }
    return 0;
}

int ts4l_div_up_830DDBD0(int a, int b)
{
    return (a + b - 1) / b * b;
}

int ts4l_div_down_830DDBF8(int a, int b)
{
    return a / b * b;
}

int ts4l_mul_div_831610D0(int a, int b, int c)
{
    return a * b / c;
}

int ts4l_div_up_830B6058(int a, int b)
{
    return (a + b - 1) / b * b;
}

int ts4l_div_down_830B6080(int a, int b)
{
    return a / b * b;
}

int ts4l_clamp_index_83126378(int *o, int i)
{
    int r;
    if (i >= 0 && i < o[2]) {
        r = i - 1;
        if (r >= 0)
            return r;
        return o[2] - 1;
    }
    return -1;
}

void ts4l_set_pair_83143728(int **o, int i, const int *x, const int *y)
{
    int *d = o[0] + i;
    int *e;
    if (d)
        *d = *x;
    e = o[1] + i;
    if (e)
        *e = *y;
}

int ts4l_dec_if_positive_83122748(int *o)
{
    int r = 1;
    int n = o[2];
    if (n > 0) {
        r = 0;
        o[2] = n - 1;
    }
    return r;
}

int ts4l_set_if_idle_83121C20(char *o, int v)
{
    int st = *(int *)(o + 0xa0);
    int r = (int)0x80004005u;
    if (st == 0 || st == 1) {
        *(int *)(o + 0x18) = v;
        r = 0;
    }
    return r;
}

int ts4l_is_fmt_830B62F0(u32 k)
{
    if (k == 0x1e || k == 0x1f || k == 0x20 || k == 0x24 || k == 0x25 || k == 0x26 || k == 0x39 || k == 0x3f)
        return 1;
    return 0;
}

void ts4l_unpack_830C17C0(char *dev, int idx, int *out, int n)
{
    char *p = dev + idx * 4 + 0x279d;
    int *o = out;
    do {
        o[0] = *(u32 *)(p + 3) & 0xff;
        o[1] = *(u8 *)(p + 5);
        p += 4;
        o[2] = *(signed char *)p;
        o[3] = 0;
        o += 4;
    } while (--n);
}

void ts4l_unpack_830C1808(char *dev, int idx, int *out, int n)
{
    char *p = dev + idx * 4 + 0x27dd;
    int *o = out;
    do {
        o[0] = *(u32 *)(p + 3) & 0xff;
        o[1] = *(u8 *)(p + 5);
        p += 4;
        o[2] = *(signed char *)p;
        o[3] = 0;
        o += 4;
    } while (--n);
}
