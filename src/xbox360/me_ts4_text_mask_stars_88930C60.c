/* Swing_DLL.xex 0x88930C60: masks a string in place: zero the whole string with ts4_memset, then copy "********" (8 stars) over its start.
 * /Oc. The mask is built byte by byte on the stack (a string initializer gives a copy instead). Both lengths are `(int)strlen`. */
unsigned int strlen(const char *s);
void *ts4_memset(void *dst, int c, unsigned int n);
void *memcpy(void *dst, const void *src, unsigned int n);

void fn_88930C60(char *text)
{
    char mask[9];
    unsigned int n;
    mask[0] = '*';
    mask[1] = '*';
    mask[2] = '*';
    mask[3] = '*';
    mask[4] = '*';
    mask[5] = '*';
    mask[6] = '*';
    mask[7] = '*';
    mask[8] = 0;
    n = (int)strlen(mask);
    ts4_memset(text, 0, (int)strlen(text));
    memcpy(text, mask, n);
}
