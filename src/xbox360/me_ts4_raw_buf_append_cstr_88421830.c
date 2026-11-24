/* Swing_DLL.xex 0x88421830: appends a C string to a char buffer whose count includes the terminator: grows (8841C5E8) to max(2*cap, need) when cap is too small, then copies the string with its terminator over the old terminator.
 * /Oc. `(int)strlen(s)` gives the clrrwi; the new capacity has to be a ?: argument written inside the call. */
typedef struct RawBuf { char *data; int count; int capFlags; } RawBuf;
unsigned int strlen(const char *s);
void *memcpy(void *dst, const void *src, unsigned int n);
void fn_8841C5E8(RawBuf *b, unsigned int newCap, unsigned int elemSize);

RawBuf *fn_88421830(RawBuf *b, const char *s)
{
    int end = b->count - 1;
    int n = (int)strlen(s);
    int need = n + end + 1;
    int cap = b->capFlags & 0x3FFFFFFF;
    if (cap < need)
        fn_8841C5E8(b, need < cap * 2 ? cap * 2 : need, 1);
    b->count = need;
    memcpy(b->data + end, s, n + 1);
    return b;
}
