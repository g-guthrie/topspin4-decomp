/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l1b_varargs_o1_830A3620.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, last) __va_start(&(ap), last)
#else
typedef char *ts4_va_list;
#define TS4_VA_START(ap, last) ((ap) = (char *)0)
#endif

typedef void (*ts4_log_fn)(const char *);

int _vsnprintf(char *buf, unsigned int count, const char *fmt, ts4_va_list args);
unsigned long DbgPrint(const char *fmt, ...);

/* Swing_DLL.xex 0x882A67A8 */
void ts4_log_printf_882A67A8(ts4_log_fn *sink, const char *fmt, ...)
{
    char buf[0x104];
    ts4_va_list ap;
    TS4_VA_START(ap, fmt);
    _vsnprintf(buf, 0x104, fmt, ap);
    if (*sink != 0)
        (*sink)(buf);
    else
        DbgPrint(buf);
}

