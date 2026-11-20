/* Swing_DLL.xex 0x88421D50: builds out = a + s: allocates count(a) - 1 + strlen(s) + 1 bytes (kind 0x16 from the TLS allocator), copies a's characters and then s with its terminator; count and capacity are both the new size.
 * /Oc. Allocate through an inline whose size argument is `len + 1` and that reads the TLS allocator first; that puts the +1 after the KeTlsGetValue call. */
typedef struct RawBuf { char *data; int count; int capFlags; } RawBuf;
extern unsigned int lbl_88CACF08;
unsigned int strlen(const char *s);
void *memcpy(void *dst, const void *src, unsigned int n);
void *KeTlsGetValue(unsigned int index);
void *fn_8841A510(void *allocator, unsigned int size, int kind);

static __inline char *raw_alloc(int size)
{
    void *alloc = KeTlsGetValue(lbl_88CACF08);
    return (char *)fn_8841A510(alloc, size, 0x16);
}

RawBuf *fn_88421D50(RawBuf *out, const RawBuf *a, const char *s)
{
    int end = a->count - 1;
    int n = (int)strlen(s);
    int len = n + end;
    char *d = raw_alloc(len + 1);
    memcpy(d, a->data, end);
    memcpy(d + end, s, n + 1);
    out->data = d;
    out->count = len + 1;
    out->capFlags = len + 1;
    return out;
}
