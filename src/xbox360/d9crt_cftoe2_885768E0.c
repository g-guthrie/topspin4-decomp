/* Swing_DLL.xex 0x885768E0-0x88576B30, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _cftoe2 (exponent formatting). */
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
extern char lbl_88090AF0[];
extern u32 lbl_88D2E838;
extern int fn_885755B0(char *dest, u32 size, const char *src);
#ifdef _MSC_VER
__declspec(noreturn)
extern void fn_8856D398(u32 a, u32 b, u32 c, u32 d, u32 e);
#else
__attribute__((noreturn)) extern void fn_8856D398(u32 a, u32 b, u32 c, u32 d, u32 e);
#endif
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern void fn_88562DC0(void *dest, const void *src, u32 n);

#define VALIDATE(expr, code) \
    do { \
        int ok_ = !!(expr); \
        if (!ok_) { \
            u32 *e_ = ts4_if_call_seq_fn_8856CD88_88567ED8(); \
            *e_ = (code); \
            fn_8856D2C0(); \
            return (code); \
        } \
    } while (0)

int ts4_crt_cftoe2_885768E0(char *buf, u32 size, int ndec, int caps, StrFlt *pflt, char g_fmt)
{
    char *p;
    char *e;
    char *q;
    int exp;
    VALIDATE(buf != 0, 22);
    VALIDATE(size > 0, 22);
    VALIDATE(size > (u32)((ndec > 0 ? ndec : 0) + 9), 34);
    if (g_fmt) {
        p = buf + (pflt->sign == '-');
        if (ndec > 0)
            fn_88562DC0(p + 1, p, strlen(p) + 1);
    }
    p = buf;
    if (pflt->sign == '-')
        *p++ = '-';
    if (ndec > 0) {
        *p = p[1];
        p++;
        *p = **lbl_88C31878->decimal_point;
    }
    p = p + (g_fmt == 0) + ndec;
    if (fn_885755B0(p, size == (u32)-1 ? (u32)-1 : size - (u32)(p - buf), lbl_88090AF0) == 0) {
        e = p + 2;
        if (caps)
            *p = 'E';
        q = p + 1;
        if (*pflt->mantissa != '0') {
            exp = pflt->decpt - 1;
            if (exp < 0) {
                exp = -exp;
                *q = '-';
            }
            q++;
            if (exp >= 100) {
                *q += (char)(exp / 100);
                exp %= 100;
            }
            q++;
            if (exp >= 10) {
                *q += (char)(exp / 10);
                exp %= 10;
            }
            q++;
            *q += (char)exp;
        }
        if (lbl_88D2E838 & 1) {
            if (*e == '0')
                fn_88562DC0(e, e + 1, 3);
        }
        return 0;
    }
    fn_8856D398(0, 0, 0, 0, 0);
}
