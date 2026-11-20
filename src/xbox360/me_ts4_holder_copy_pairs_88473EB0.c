/* 0x88473EB0: Assigns the 16-byte (two u64) element list at +0x74 of dst from src. */
/* Matched on /Oc (agAH). Pool-buffer assign helper: if capacity < src count, free old storage unless externally owned and allocate src count elements (kind 0x17, keeping bit 30 of the capacity word); then count = src count and copy elements via locals n, d, s with an indexed loop (d[i] = s[i]); a pointer-increment loop gives lwzu/stwu. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
typedef struct Pair64 { unsigned __int64 lo; unsigned __int64 hi; } Pair64;
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct Pair64Buf { Pair64 *data; int count; int capFlags; } Pair64Buf;

static void Pair64Buf_Assign(Pair64Buf *dst, const Pair64Buf *src)
{
    unsigned int cap = dst->capFlags & 0x3FFFFFFF;
    int i;
    if ((int)cap < src->count) {
        if ((dst->capFlags & (int)0x80000000) == 0) {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            fn_8841A590(alloc, dst->data, cap * sizeof(Pair64), 0x17);
        }
        {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            dst->data = (Pair64 *)fn_8841A510(alloc, src->count * sizeof(Pair64), 0x17);
        }
        dst->capFlags = (dst->capFlags & 0x40000000) | src->count;
    }
    {
        int n = src->count;
        Pair64 *d = dst->data;
        const Pair64 *s;
        dst->count = n;
        s = src->data;
        for (i = 0; i < n; i++)
            d[i] = s[i];
    }
}

typedef struct Holder { char pad[0x74]; Pair64Buf pairs; } Holder;

void fn_88473EB0(Holder *dst, const Holder *src)
{
    Pair64Buf_Assign(&dst->pairs, &src->pairs);
}
