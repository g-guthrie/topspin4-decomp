/* Swing_DLL.xex 0x8856A218-0x8856A39C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: string scanf helper and the sscanf entry points. */
#ifdef _MSC_VER
typedef char *Ts4VaList;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#define TS4_VA_END(ap) ((void)0)
#else
#include <stdarg.h>
typedef va_list Ts4VaList;
#define TS4_VA_START(ap, v) va_start(ap, v)
#define TS4_VA_END(ap) va_end(ap)
#endif
typedef unsigned int u32;
typedef struct Ts4File {
    char *ptr;
    int cnt;
    char *base;
    int flag;
    int file;
    int charbuf;
    int bufsiz;
    int tmpfname;
} Ts4File;
typedef int (*Ts4InputFn)(Ts4File *f, const char *fmt, void *loc, Ts4VaList ap);
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern int fn_88570D60(Ts4File *f, const char *fmt, void *loc, Ts4VaList ap);
extern int fn_88572018(Ts4File *f, const char *fmt, void *loc, Ts4VaList ap);

#ifdef _MSC_VER
__declspec(noinline)
#endif
int ts4_crt_vsscanf_helper_8856A218(Ts4InputFn infn, const char *string, const char *format, void *loc, Ts4VaList ap)
{
    Ts4File str = {0};
    u32 len = strlen(string);
    u32 *e;
    if (string == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    if (format == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    str.flag = 0x49;
    str.ptr = str.base = (char *)string;
    str.cnt = len > 0x7FFFFFFFu ? 0x7FFFFFFF : (int)len;
    return infn(&str, format, loc, ap);
}

