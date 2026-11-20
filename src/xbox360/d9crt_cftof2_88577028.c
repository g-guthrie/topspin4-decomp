/* Swing_DLL.xex 0x88577028-0x885771DC, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _cftof2 (fixed-point formatting). */
typedef unsigned int u32;
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
typedef struct StrFlt {
    int sign;
    int decpt;
    int flag;
    char *mantissa;
} StrFlt;
typedef struct LocInfo {
    char pad[0xbc];
    char **decimal_point;
} LocInfo;
extern LocInfo *lbl_88C31878;
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern void fn_88562DC0(void *dest, const void *src, u32 n);

int ts4_crt_cftof2_88577028(char *buf, u32 size, int ndec, StrFlt *pflt, char g_fmt)
{
    char *p;
    char *q;
    u32 *e;
    int dec = pflt->decpt - 1;
    if (buf == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return 22;
    }
    if (size == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return 22;
    }
    if (g_fmt && dec == ndec) {
        p = buf + dec + (pflt->sign == '-');
        *p++ = '0';
        *p = 0;
    }
    p = buf;
    if (pflt->sign == '-')
        *p++ = '-';
    if (pflt->decpt <= 0) {
        fn_88562DC0(p + 1, p, strlen(p) + 1);
        *p = '0';
        q = p + 1;
    } else {
        q = p + pflt->decpt;
    }
    if (ndec > 0) {
        fn_88562DC0(q + 1, q, strlen(q) + 1);
        p = q + 1;
        *q = **lbl_88C31878->decimal_point;
        if (pflt->decpt < 0) {
            if (g_fmt) {
                ndec = -pflt->decpt;
            } else {
                int t = -pflt->decpt;
                if (ndec >= t)
                    ndec = t;
            }
            if (ndec != 0)
                fn_88562DC0(p + ndec, p, strlen(p) + 1);
            memset(p, '0', ndec);
        }
    }
    return 0;
}
