/* Loader_DLL.xex 0x830A3620-0x830CB4C8, executable version 0.0.0.3.
 * Variadic formatting wrappers. */

#ifdef _MSC_VER
typedef char *ts4l_va_list;
#define TS4L_VA_START(ap, last) __va_start(&(ap), last)
#else
typedef char *ts4l_va_list;
#define TS4L_VA_START(ap, last) ((ap) = (char *)0)
#endif

typedef void (*ts4l_log_fn)(const char *);

int fn_833E25A8(int stream, int mode, const char *fmt, ts4l_va_list args);
int _vsnprintf(char *buf, unsigned int count, const char *fmt, ts4l_va_list args);
unsigned long DbgPrint(const char *fmt, ...);

int ts4l_va_format_830A3620(int stream, const char *fmt, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, fmt);
    return fn_833E25A8(stream, 8, fmt, ap);
}

void ts4l_log_printf_830CB448(ts4l_log_fn *sink, const char *fmt, ...)
{
    char buf[0x104];
    ts4l_va_list ap;
    TS4L_VA_START(ap, fmt);
    _vsnprintf(buf, 0x104, fmt, ap);
    if (*sink != 0)
        (*sink)(buf);
    else
        DbgPrint(buf);
}
