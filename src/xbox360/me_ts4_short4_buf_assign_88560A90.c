/* 0x88560A90: Assignment operator of a pool buffer of 8-byte (four u16) elements: regrows to the source count when capacity is short (old storage freed unless externally owned, kind 0x17), copies count and elements; returns dst. */
/* Matched on /Oc (agAH). Same assign helper as 8847B028, forced inline (a lone static call is not inlined here); the struct element copy unrolls to four lhz/sth. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Short4 { unsigned short s[4]; } Short4;
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct Short4Buf { Short4 *data; int count; int capFlags; } Short4Buf;

static __forceinline void Short4Buf_Assign(Short4Buf *dst, const Short4Buf *src)
{
    unsigned int cap = dst->capFlags & 0x3FFFFFFF;
    int i;
    if ((int)cap < src->count) {
        if ((dst->capFlags & (int)0x80000000) == 0) {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            fn_8841A590(alloc, dst->data, cap * sizeof(Short4), 0x17);
        }
        {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            dst->data = (Short4 *)fn_8841A510(alloc, src->count * sizeof(Short4), 0x17);
        }
        dst->capFlags = (dst->capFlags & 0x40000000) | src->count;
    }
    {
        int n = src->count;
        Short4 *d = dst->data;
        const Short4 *s;
        dst->count = n;
        s = src->data;
        for (i = 0; i < n; i++)
            d[i] = s[i];
    }
}

Short4Buf *fn_88560A90(Short4Buf *dst, const Short4Buf *src)
{
    Short4Buf_Assign(dst, src);
    return dst;
}
