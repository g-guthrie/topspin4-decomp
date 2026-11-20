/* CW1: LTCG context only (not a matched function). Gives ts4_format_text its varargs shape so callers
   reserve the register home area as in the original link. Swing_DLL.xex 0x88606318. */
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif

extern int ts4_tailcall_fn_885654E8_885655D0(char *dst, unsigned size, const char *fmt, ts4_va_list ap);

int ts4_format_text(char *dst, unsigned size, const char *fmt, ...)
{
    ts4_va_list ap;
    int n;
    TS4_VA_START(ap, fmt);
    n = ts4_tailcall_fn_885654E8_885655D0(dst, size, fmt, ap);
    if (n < 0 || (unsigned)n >= size) {
        if (size != 0)
            dst[size - 1] = 0;
        return -1;
    }
    return n;
}
