/* CW8: LTCG context only (not a matched function). Gives ts4_forward_varargs_8819BEF0 its varargs shape so callers
   reserve the register home area as in the original link. Swing_DLL.xex 0x8819BEF0. */
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif
typedef long ts4_word;

extern ts4_word fn_8819C000(ts4_word p0, ts4_word p1, ts4_va_list ap);

ts4_word ts4_forward_varargs_8819BEF0(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return fn_8819C000(p0, p1, ap);
}
