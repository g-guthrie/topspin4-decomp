/* Swing_DLL.xex 0x88565410-0x885655CC, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: vsprintf and _vsnprintf. */
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
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern int fn_8856DC88(Ts4File *f, const char *fmt, void *loc, void *ap);
extern int fn_8856D948(int ch, Ts4File *f);

int ts4_crt_vsprintf_88565410(char *string, const char *format, void *loc, void *ap)
{
    Ts4File str = {0};
    int retval;
    u32 *e;
    if (format == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    if (string == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    str.flag = 0x42;
    str.ptr = str.base = string;
    str.cnt = 0x7FFFFFFF;
    retval = fn_8856DC88(&str, format, loc, ap);
    if (--str.cnt >= 0)
        *str.ptr++ = 0;
    else
        fn_8856D948(0, &str);
    return retval;
}

int ts4_crt_vsnprintf_885654E8(char *string, u32 count, const char *format, void *loc, void *ap)
{
    Ts4File str = {0};
    int retval;
    u32 *e;
    if (format == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    if (count != 0 && string == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return -1;
    }
    str.cnt = count > 0x7FFFFFFFu ? 0x7FFFFFFF : (int)count;
    str.flag = 0x42;
    str.ptr = str.base = string;
    retval = fn_8856DC88(&str, format, loc, ap);
    if (string != 0) {
        if (--str.cnt >= 0)
            *str.ptr++ = 0;
        else
            fn_8856D948(0, &str);
    }
    return retval;
}
