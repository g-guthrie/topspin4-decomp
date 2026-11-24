/* Swing_DLL.xex 0x88421BF8: finds sep in s with strstr (885646F8) and appends each match offset to an int buffer (growing it with 8841C678); *found is set when there is a match. Only the first match is taken unless all is set.
 * /Oc. Read the capacity and the count into locals before the found store; `(int)strlen(sep)` gives the clrrwi. */
typedef struct IntBuf { int *data; int count; int capFlags; } IntBuf;
unsigned int strlen(const char *s);
char *fn_885646F8(const char *s, const char *sub); /* strstr */
void fn_8841C678(IntBuf *b, unsigned int elemSize);

unsigned char *fn_88421BF8(unsigned char *found, const char *s, const char *sep, IntBuf *offsets, int all)
{
    int seplen = (int)strlen(sep);
    const char *p = fn_885646F8(s, sep);
    *found = 0;
    while (p) {
        int off = p - s;
        int cap = offsets->capFlags & 0x3FFFFFFF;
        int count = offsets->count;
        *found = 1;
        if (count == cap)
            fn_8841C678(offsets, 4);
        offsets->data[offsets->count] = off;
        offsets->count++;
        if (!all)
            break;
        p = fn_885646F8(p + seplen, sep);
    }
    return found;
}
