/* Swing_DLL.xex 0x881642B0-0x88164338, executable version 0.0.0.3. */
#ifdef _MSC_VER
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
#pragma intrinsic(strcpy, strcat)
#else
#include <string.h>
#endif
void ts4_concat3_881642B0(char *dst, const char *a, const char *b, const char *c)
{
    strcpy(dst, a);
    strcat(dst, b);
    strcat(dst, c);
}
