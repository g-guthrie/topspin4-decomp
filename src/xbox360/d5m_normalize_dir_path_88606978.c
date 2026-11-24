/* Swing_DLL.xex 0x88606978-0x88606A2C, executable version 0.0.0.3. */
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
extern char *strcpy(char *d, const char *s);
#pragma intrinsic(strlen)
#pragma intrinsic(strcpy)
#else
#include <string.h>
#endif
extern void fn_8856CC88(char *s);

void ts4_normalize_dir_path_88606978(char *dst, const char *src)
{
    unsigned int n;
    char *p;
    strcpy(dst, src);
    fn_8856CC88(dst);
    n = strlen(dst);
    for (p = dst; *p; p++) {
        if (*p == '\\') *p = '/';
    }
    if (dst[n - 1] != '/') {
        dst[n] = '/';
        dst[n + 1] = 0;
    }
}
