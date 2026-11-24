/* 0x8834E3A8: Copies the text between the first pair of double quotes in src into dst (NUL-terminated), writes its length to *outLen and returns 0. The first scan reads at most 0x200 bytes (it spins if no quote is found); the copy stops at index 0x1ff. The first argument is unused. */
/* Matched on /Oc (agAH). First scan as do { if (i < 0x200) c = src[i++]; } while ((char)c != quote), with c unsigned char so the copy loop compares unsigned (cmplwi). */
int fn_8834E3A8(void *unused, const char *src, char *dst, int *outLen)
{
    unsigned char c = 0;
    int i = 0;
    int n = 0;
    do {
        if (i < 0x200)
            c = src[i++];
    } while ((char)c != '"');
    do {
        c = src[i++];
        if (c == '"')
            break;
        dst[n++] = c;
    } while (i < 0x1ff);
    dst[n] = 0;
    *outLen = n;
    return 0;
}
