/* Swing_DLL.xex 0x88577760-0x88577854, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: wctomb_s (single-byte locale). */
typedef unsigned int u32;
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);

int ts4_crt_wctomb_s_88577760(int *pret, char *dst, u32 size, unsigned short wc)
{
    u32 *e;
    if (dst == 0 && size != 0) {
        if (pret != 0)
            *pret = 0;
        return 0;
    }
    if (pret)
        *pret = -1;
    if (size > 0x7FFFFFFF) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0();
        return 22;
    }
    if (wc > 0xFF) {
        if (dst != 0 && size != 0)
            memset(dst, 0, size);
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 42;
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        return *e;
    }
    if (dst != 0) {
        if (size == 0) {
            e = ts4_if_call_seq_fn_8856CD88_88567ED8();
            *e = 34;
            fn_8856D2C0();
            return 34;
        }
        *dst = (char)wc;
    }
    if (pret)
        *pret = 1;
    return 0;
}
