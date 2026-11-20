/* CW31: LTCG context only (not a matched function). Gives ts4_forward_varargs_88606270 its varargs shape.
   Swing_DLL.xex 0x88606270. */
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif

extern void ts4_if_call_seq_fn_8856A658_88606208(char *dst, unsigned size, const char *fmt, ts4_va_list ap);

void ts4_forward_varargs_88606270(char *dst, unsigned size, const char *fmt, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, fmt);
    ts4_if_call_seq_fn_8856A658_88606208(dst, size, fmt, ap);
}
