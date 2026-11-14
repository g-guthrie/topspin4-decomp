/* Wide-character string helpers used by the Swing_DLL.xex Lua build.
   Reconstructed from the disassembly only. */

/* Widen a NUL-terminated narrow string into dst (sign-extending each char). */
void lib3_lua_widen_string_8882ED68(const char *src, unsigned short *dst)
{
    while (*src) {
        *dst++ = (unsigned short)*src++;
    }
    *dst = 0;
}

/* Bounded wide copy that zero-fills the rest of the destination. */
void lib3_lua_wstrncpy_8882EDF0(unsigned short *dst, const unsigned short *src, unsigned int n)
{
    while (n) {
        if ((*dst++ = *src++) == 0) break;
        n--;
    }
    if (n) {
        while (--n) *dst++ = 0;
    }
}

/* Bounded wide compare returning -1, 0 or 1. */
int lib3_lua_wstrncmp_8882F0B0(const unsigned short *a, const unsigned short *b, unsigned int n)
{
    for (; n; n--, a++, b++) {
        if (*a != *b) return *a < *b ? -1 : 1;
    }
    return 0;
}
