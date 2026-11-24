/* Swing_DLL.xex 0x8856A3F8: C-locale mbstowcs (widen bytes to u16, EINVAL on null source)
 * strlen intrinsic converted to int for the count-only path */
typedef unsigned int u32;
typedef unsigned short wchar16;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);

/* C-locale mbstowcs: widen bytes until NUL or n wide characters. */
u32 fn_8856A3F8(wchar16 *dst, const char *src, u32 n)
{
    u32 count = 0;
    if (dst && n == 0)
        return 0;
    if (dst && n > 0)
        *dst = 0;
    if (src == 0) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 22;
        fn_8856D2C0();
        return (u32)-1;
    }
    if (dst) {
        while (count < n) {
            *dst = (unsigned char)src[count];
            if (src[count] == 0)
                return count;
            count++;
            dst++;
        }
        return count;
    }
    return (int)strlen(src);
}
