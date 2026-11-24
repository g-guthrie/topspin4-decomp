/* 0x884DF498: Reads up to maxLen bytes through fn_884DF2D0 into a temporary pool byte buffer (reserved to maxLen when positive), copies the result to dst and returns its length; returns -1 if the read fails or the result is longer than maxLen. The temporary storage is freed (kind 0x17) on both paths. */
/* Matched on /Oc (agAH). Clamp written as ((unsigned)n >> 31) - 1 & n (a ternary or n >= 0 test folds away under the n > 0 guard); buffer free __forceinline. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct RawBuf { unsigned char *data; int count; int capFlags; } RawBuf;
void fn_8841C5E8(RawBuf *b, unsigned int newCap, unsigned int elemSize);
int fn_884DF2D0(void *a, void *b, RawBuf *out, int c, int d);
void *ts4_tailcall_memcpy_88421450(void *dst, const void *src, unsigned int n);

static __forceinline void RawBuf_Free(RawBuf *b)
{
    if ((b->capFlags & (int)0x80000000) == 0) {
        unsigned int cap = b->capFlags & 0x3FFFFFFF;
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, b->data, cap, 0x17);
    }
}

int fn_884DF498(void *a, void *b, unsigned char *dst, int maxLen, int c, int d)
{
    RawBuf buf;
    int n;
    buf.data = 0;
    buf.count = 0;
    buf.capFlags = (int)0x80000000;
    if (maxLen > 0)
        fn_8841C5E8(&buf, ((unsigned int)maxLen >> 31) - 1 & maxLen, 1);
    if (fn_884DF2D0(a, b, &buf, c, d) != 0 || buf.count > maxLen) {
        RawBuf_Free(&buf);
        return -1;
    }
    ts4_tailcall_memcpy_88421450(dst, buf.data, buf.count);
    n = buf.count;
    RawBuf_Free(&buf);
    return n;
}
