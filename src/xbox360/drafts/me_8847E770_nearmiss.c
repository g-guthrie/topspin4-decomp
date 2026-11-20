/* 0x8847E770: Copies the 16-byte vector array at +0x20 of an object into out (pool buffer assign: regrow when capacity < count, kind 0x17, then element copy). */
/* Near miss (agAH): /Oc, 2 instructions off: the element copy uses lvx128/stvx128 v63 where the target uses v0 (open v0-v13 register issue). The same assign helper matches 8847B028/884A74E8/88473EB0. */
#include "ts4_vector.h"
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void *fn_8841A510(void *allocator, unsigned int size, int kind);
typedef struct VecBuf { __vector4 *data; int count; int capFlags; } VecBuf;

static void VecBuf_Assign(VecBuf *dst, const VecBuf *src)
{
    unsigned int cap = dst->capFlags & 0x3FFFFFFF;
    int i;
    if ((int)cap < src->count) {
        if ((dst->capFlags & (int)0x80000000) == 0) {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            fn_8841A590(alloc, dst->data, cap * sizeof(__vector4), 0x17);
        }
        {
            void *alloc = KeTlsGetValue(lbl_88CACF08);
            dst->data = (__vector4 *)fn_8841A510(alloc, src->count * sizeof(__vector4), 0x17);
        }
        dst->capFlags = (dst->capFlags & 0x40000000) | src->count;
    }
    {
        int n = src->count;
        __vector4 *d = dst->data;
        const __vector4 *s;
        dst->count = n;
        s = src->data;
        for (i = 0; i < n; i++)
            d[i] = s[i];
    }
}

typedef struct VecOwner { char pad[0x20]; VecBuf vecs; } VecOwner;

void fn_8847E770(const VecOwner *o, VecBuf *out)
{
    VecBuf_Assign(out, &o->vecs);
}
