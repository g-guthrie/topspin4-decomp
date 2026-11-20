/* Swing_DLL.xex 0x885790D8-0x88579238, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _fptostr. */
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
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);
extern void fn_88562DC0(void *dest, const void *src, u32 n);

int ts4_crt_fptostr_885790D8(char *buf, u32 size, int digits, StrFlt *pflt)
{
    char *pbuf = buf;
    char *mantissa = pflt->mantissa;
    u32 *e;
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
    buf[0] = 0;
    if (!(size > (u32)((digits > 0 ? digits : 0) + 1))) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 34;
        fn_8856D2C0();
        return 34;
    }
    *pbuf++ = '0';
    while (digits > 0) {
        char c;
        if (*mantissa)
            c = *mantissa++;
        else
            c = '0';
        *pbuf++ = c;
        digits--;
    }
    *pbuf = 0;
    if (digits >= 0 && *mantissa >= '5') {
        pbuf--;
        while (*pbuf == '9')
            *pbuf-- = '0';
        *pbuf += 1;
    }
    if (*buf == '1') {
        pflt->decpt++;
    } else {
        fn_88562DC0(buf, buf + 1, strlen(buf + 1) + 1);
    }
    return 0;
}
