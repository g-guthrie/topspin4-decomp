/* 0x88329998: memmove for bytes: copies n bytes forward when dst <= src, otherwise backward from the end. */
/* Matched on /Oc /O2 (agAH). while (n--) loops with separate d/s pointers in each branch give the two mtctr/bdnz loops (an index or for (; n; n--) loop gives subic./bne). */
void fn_88329998(unsigned char *dst, const unsigned char *src, int n)
{
    if (dst <= src) {
        unsigned char *d = dst;
        const unsigned char *s = src;
        while (n--)
            *d++ = *s++;
    } else {
        unsigned char *d = dst + n;
        const unsigned char *s = src + n;
        while (n--)
            *--d = *--s;
    }
}
