/* Swing_DLL.xex 0x88603D78: writes a length-prefixed string: a 16-bit length (strlen, or -1 for null) followed by the characters; returns the bytes written (2 + length).
 * /Oc. `s ? (unsigned short)strlen(s) : -1` stored in a short. */
unsigned int strlen(const char *s);
void *memcpy(void *dst, const void *src, unsigned int n);

int fn_88603D78(short *out, const char *s)
{
    short n = s ? (unsigned short)strlen(s) : -1;
    *out = n;
    if (n > 0) {
        memcpy(out + 1, s, n);
        return n + 2;
    }
    return 2;
}
