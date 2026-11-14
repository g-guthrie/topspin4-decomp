/* Swing_DLL.xex 0x88605AB8-0x88605CEC, executable version 0.0.0.3. */
typedef unsigned char u8;
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif
extern char lbl_880F77DC[];

static int is_sep(char c)
{
    int i;
    unsigned char found = 0;
    for (i = 0; i < 2; i++) {
        if (c == lbl_880F77DC[i]) { found = 1; break; }
    }
    return found;
}

int ts4_find_first_sep_88605AB8(const char *base, int off)
{
    const char *s = base + off;
    int n = (int)strlen(s);
    int i;
    int r = -1;
    for (i = 0; i < n; i++) {
        if (is_sep(s[i])) { r = i + off; break; }
    }
    return r;
}

int ts4_find_first_nonsep_88605B58(const char *base, int off)
{
    const char *s = base + off;
    int n = (int)strlen(s);
    int i;
    int r = -1;
    for (i = 0; i < n; i++) {
        if (!is_sep(s[i])) { r = i + off; break; }
    }
    return r;
}

int ts4_find_last_nonsep_88605C58(const char *s, int stop)
{
    int i = (int)strlen(s) - 1;
    int r = -1;
    while (i != stop) {
        if (!is_sep(s[i])) { r = i; break; }
        i--;
    }
    return r;
}
