/* Loader_DLL.xex 0x8314E9C0-0x8321B828, executable version 0.0.0.3. */
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

ts4l_word ts4l_vfwd_8314E9C0(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return ts4_tailcall_fn_833E5B90_833E5C28(p0, 0x20, p1, ap);
}

ts4l_word ts4l_vfwd_8315B3F8(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return ts4_tailcall_fn_833E2510_833E25A8(p0, 0x1000, p1, ap);
}

ts4l_word ts4l_vfwd_8315B448(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return ts4_tailcall_fn_833E2510_833E25A8(p0, 0x800, p1, ap);
}

ts4l_word ts4l_vfwd_8315B4A8(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return ts4_tailcall_fn_833E2510_833E25A8(p0, 0x400, p1, ap);
}

ts4l_word ts4l_vfwd_8321B828(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return ts4_tailcall_fn_833E2510_833E25A8(p0, p1, p2, ap);
}
