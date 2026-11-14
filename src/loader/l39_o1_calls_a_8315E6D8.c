/* Loader_DLL.xex 0x8315E6D8-0x8318B120, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef char *ts4l_va_list;
#define TS4L_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4l_va_list;
#define TS4L_VA_START(ap, v) va_start(ap, v)
#endif
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long ts4l_word;
extern ts4l_word ts4_tailcall_fn_833E2510_833E25A8();
extern ts4l_word ts4_tailcall_fn_833E5B90_833E5C28();
extern u32 fn_830E1140(u32, u32, u32, u32);
extern u32 fn_830B4448(u32);
extern u32 fn_830B4408(u32);
extern u32 fn_8340D710(u32, u32);
extern u32 fn_8318A010(u32);
extern u32 ts4l_if_call_seq_fn_8318A010_8318AA80(u32);
extern int fn_83148048(void *, int);
extern double fn_833E30E8(double);
extern void *fn_833E3A30(void *, int, int);
extern u32 ts4l_if_call_seq_fn_830E1140_830E1610(u32, u32, u32);

u32 ts4l_alloc_status_8315E6D8(u32 a, u32 b, u32 c, u32 d, u32 *out)
{
    u32 r = fn_830E1140(a, b, c, d);
    *out = r;
    return r == 0 ? 0x8007000e : 0;
}

u32 ts4l_alloc_status_8315EEC0(char *p, u32 b, u32 c, u32 d, u32 *out)
{
    u32 r = fn_830E1140(*(u32 *)(p + 0xc), b, c, d);
    *out = r;
    return r == 0 ? 0x8007000e : 0;
}

u32 ts4l_alloc_status_8315EB98(char *p, u32 *out)
{
    u32 r = fn_830B4448(*(u32 *)(p + 0xc));
    *out = r;
    return r == 0 ? 0x88760866 : 0;
}

u32 ts4l_alloc_status_8315EC30(char *p, u32 unused, u32 *out)
{
    u32 r = fn_830B4408(*(u32 *)(p + 0xc));
    (void)unused;
    *out = r;
    return r == 0 ? 0x88760866 : 0;
}

u32 ts4l_call_status_8318B120(char *p)
{
    u32 r = ts4l_if_call_seq_fn_8318A010_8318AA80((u32)(unsigned long)(p + 0x50));
    return r == 0 ? 0x8007000e : 0;
}
