/* Wide strtol helper used by the wide copy of trio (lib4_trio_wide.c); a separate
 * translation unit in the original. See lib4_trio.h for the trio license. */
#include "lib4_trio.h"

typedef unsigned short trio_wchar_t;

/* 0x8819F8B0: wide strtol(.., .., 10) helper; narrows the string into a stack buffer.
 */
long lib4_trio_wide_wcstol_8819F8B0(const trio_wchar_t *string, trio_wchar_t **endp)
{
    char buffer[100]; /* any size 0x49..0x68 gives the same 0xe0 frame */
    char *end;
    const trio_wchar_t *p;
    unsigned int length;
    unsigned int i;
    long result;

    p = string;
    while (*p)
        p++;
    length = (unsigned int)(p - string);
    for (i = 0; i < length; i++)
        buffer[i] = (char)string[i];
    result = ts4_tailcall_fn_88564828_88564B00(buffer, &end, 10);
    *endp = (trio_wchar_t *)string + (end - buffer);
    return result;
}
