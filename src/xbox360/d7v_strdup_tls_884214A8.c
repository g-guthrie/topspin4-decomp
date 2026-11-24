/* Swing_DLL.xex 0x884214A8-0x8842152C, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern u32 strlen(const char *s);
#else
#include <string.h>
#endif
extern u32 lbl_88CACF08;
u32 KeTlsGetValue(u32 index);
char *ts4_call_seq_fn_8841A510_8841A7C8(u32 tls, u32 size, u32 tag);

char *ts4_strdup_tls_884214A8(const char *src)
{
    u32 len = (u32)strlen(src);
    u32 tls = KeTlsGetValue(lbl_88CACF08);
    char *dst = ts4_call_seq_fn_8841A510_8841A7C8(tls, len + 1, 0x16);
    const char *p = src;
    char c;
    do {
        c = *p;
        dst[p - src] = c;
        ++p;
    } while (c != 0);
    return dst;
}
