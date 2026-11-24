/* 0x8847B028: Copies the word list at +0x2c of the shared object referenced from +0x18 into out. */
/* Matched on /Oc (agAH). Pool-buffer assign helper: if capacity < src count, free old storage unless externally owned and allocate src count elements (kind 0x17, keeping bit 30 of the capacity word); then count = src count and copy elements via locals n, d, s with an indexed loop (d[i] = s[i]); a pointer-increment loop gives lwzu/stwu. */
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct WordBuf { unsigned int *data; int count; int capFlags; } WordBuf;

static void WordBuf_Assign(WordBuf *dst, const WordBuf *src)
{
    unsigned int cap = dst->capFlags & 0x3FFFFFFF;
    int i;
    if ((int)cap < src->count) {
        if ((dst->capFlags & (int)0x80000000) == 0) {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            fn_8841A590(alloc, dst->data, cap * sizeof(unsigned int), 0x17);
        }
        {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            dst->data = (unsigned int *)fn_8841A510(alloc, src->count * sizeof(unsigned int), 0x17);
        }
        dst->capFlags = (dst->capFlags & 0x40000000) | src->count;
    }
    {
        int n = src->count;
        unsigned int *d = dst->data;
        const unsigned int *s;
        dst->count = n;
        s = src->data;
        for (i = 0; i < n; i++)
            d[i] = s[i];
    }
}

typedef struct Shared { char pad[0x2c]; WordBuf words; } Shared;
typedef struct Viewer { char pad[0x18]; Shared *shared; } Viewer;

void fn_8847B028(const Viewer *v, WordBuf *out)
{
    WordBuf_Assign(out, &v->shared->words);
}
