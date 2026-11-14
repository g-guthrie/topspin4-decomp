/* Loader_DLL.xex 0x83353370-0x833DBCB0, executable version 0.0.0.3. */

#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#define TS4L_TOPBIT 0x8000000000000000ui64
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#define TS4L_TOPBIT 0x8000000000000000ULL
#endif

/* Mask of the 64-bit words covering quad indices a/4 .. (a+n-1)/4. */
extern void fn_830C13E0(void *o, unsigned a, int x, unsigned n, ts4l_u64 mask);

ts4l_u64 ts4l_quad_range_mask_83353370(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D24C8(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D3468(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D3F10(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D4318(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D4850(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D4C40(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D50A0(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833D7170(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

ts4l_u64 ts4l_quad_range_mask_833DB908(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    return m >> i;
}

void ts4l_quad_range_apply_83353448(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D2898(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D3810(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D3FD0(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D43D8(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D4910(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D4D00(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D5470(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833D8A48(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

void ts4l_quad_range_apply_833DBCB0(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4l_u64 m = (ts4l_u64)((ts4l_s64)TS4L_TOPBIT >> (j - i));
    fn_830C13E0(o, a, x, n, m >> i);
}

