/* Swing_DLL.xex 0x88577488-0x88577518, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _strdup. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern void *ts4_crt_nh_malloc_88565258(u32 size);
extern int fn_885755B0(char *dest, u32 size, const char *src);
extern void fn_8856D398(u32 a, u32 b, u32 c, u32 d, u32 e);

char *ts4_crt_strdup_88577488(const char *s)
{
    char *mem;
    u32 n;
    if (s) {
        n = strlen(s) + 1;
        mem = (char *)ts4_crt_nh_malloc_88565258(n);
        if (mem) {
            if (fn_885755B0(mem, n, s) == 0)
                return mem;
            fn_8856D398(0, 0, 0, 0, 0);
        }
    }
    return 0;
}
