/* Loader_DLL.xex 0x83400718-0x83489310, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern char lbl_83071C74[];
extern char lbl_83071C68[];
extern long long ts4l_import_KeQueryPerformanceFrequency_83517418(void);
extern u32 fn_83415B08(u32, u32);
extern int fn_8346C650(void *);

int ts4l_tag_le_1000000_83400718(char *p)
{
    return (int)(*(u32 *)(p + 4) & 0xff000000u) <= 0x1000000;
}

int ts4l_state_is_one_flag_83400AB8(char *p)
{
    return *(int *)(p + 4) == 1 ? 0x20 : 0;
}

void ts4l_set_state_83400A80(char *p, int v)
{
    *(int *)(p + 4) = v;
    *(char **)p = lbl_83071C74;
    *(int *)(p + 8) = v == 1 ? 4 : 0;
}

char *ts4l_put_byte_83400998(char *p, char *a, char *b)
{
    if (a < b) {
        *a = *(p + 4);
        a++;
    }
    return a;
}

int ts4l_hdr_is_kind_9_8340BA40(unsigned long long x)
{
    u16 h = (u16)(x >> 48);
    return (h & 0xf) == 9 && (h & 0xc0) != 0;
}

long long *ts4l_set_scaled_83415BF0(long long *p, int b)
{
    if (b == -1)
        return 0;
    *p = (u32)b * -10000LL;
    return p;
}

long long *ts4l_set_scaled_83415810(long long *p, int b)
{
    if (b == -1)
        return 0;
    *p = (u32)b * -10000LL;
    return p;
}

int ts4l_neither_zero_nor_one_83489310(char *p)
{
    int v = *(int *)(p + 8);
    return v != 1 && v != 0;
}

int ts4l_flag_bit9_83400778(char *p)
{
    return *(u32 *)p != 0 && (*(u32 *)(p + 4) & 0x00400000) != 0;
}

int ts4l_flag_bit10_834007C0(char *p)
{
    return *(u32 *)p != 0 && (*(u32 *)(p + 4) & 0x00200000) != 0;
}

void ts4l_update_level_834008F0(char *p, char *q)
{
    int v;
    if ((int)(*(u32 *)(p + 4) & 0xff000000u) == 0x3000000)
        return;
    v = *(signed char *)(q + 4);
    if (v <= 1)
        return;
    *(signed char *)(p + 4) = (signed char)v;
}

void ts4l_init_link_834009B8(char *p, char *q)
{
    *(char **)p = lbl_83071C68;
    if (q) {
        int v = *(signed char *)(q + 4);
        if (v == 2 || v == 3)
            q = 0;
    }
    *(char **)(p + 4) = q;
}

char *ts4l_copy_bounded_83400EE0(char *d, char *end, char *s, int n)
{
    int avail = (int)(end - d);
    u32 i;
    if (n > avail)
        n = avail;
    for (i = 0; i < (u32)n; i++)
        d[i] = s[i];
    return d + n;
}

int ts4l_query_frequency_8340BD08(long long *p)
{
    *p = ts4l_import_KeQueryPerformanceFrequency_83517418();
    return 1;
}

int ts4l_is_c0_8340CE58(u32 a, u32 b)
{
    return fn_83415B08(a, (unsigned char)b) == 0xc0 ? 0xc0 : 0;
}

u16 *ts4l_wcschr_833E4AB8(u16 *s, u32 c)
{
    while (*s != 0 && *s != (u16)c)
        s++;
    return *s == (u16)c ? s : 0;
}

/* Index of the first newline in the buffer, or 0 when there is none. */
u32 ts4l_find_newline_83423438(u8 *s, u32 n)
{
    u32 i;
    for (i = 0; i < n; i++)
        if (s[i] == 10)
            return i;
    return 0;
}

/* True when the rectangle (left, top, right, bottom) is empty. */
int ts4l_rect_is_empty_8346C7E0(int *p)
{
    return p[0] >= p[2] || p[1] >= p[3];
}

int ts4l_call_nonzero_mask_8346C708(void *x)
{
    return fn_8346C650(x) != 0 ? -1 : 0;
}

void ts4l_widen_u8x4_8346D150(u8 *in, u16 *out)
{
    int i;
    for (i = 0; i < 4; i++)
        *out++ = *in++;
}
