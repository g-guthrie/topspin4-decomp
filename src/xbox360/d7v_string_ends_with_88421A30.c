/* Swing_DLL.xex 0x88421A30-0x88421AB8, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern u32 strlen(const char *s);
#else
#include <string.h>
#endif
typedef struct Ts4V7Str { char *data; u32 len; } Ts4V7Str;

void ts4_string_ends_with_88421A30(char *result, Ts4V7Str *str, const char *suffix)
{
    int start = (int)(str->len - (u32)strlen(suffix)) - 1;
    u32 i;
    if (start < 0) {
        *result = 0;
        return;
    }
    for (i = 0; suffix[i] != 0; ++i) {
        if (str->data[start + i] != suffix[i]) {
            *result = 0;
            return;
        }
    }
    *result = 1;
}
