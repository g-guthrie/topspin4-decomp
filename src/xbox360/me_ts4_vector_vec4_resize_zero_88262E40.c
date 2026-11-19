/* Swing_DLL.xex 0x88262E40: vector<16-byte vector>::resize(n) with a zeroed default element: erase the tail or _Insert_n (fn_882643C8) at end.
 * /Oc. Same as 88261EA8 but the default is value-initialised (memset to zero: two std through a pointer). */
void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
#include "ts4_vector.h"
typedef struct VecV { __vector4 *first; __vector4 *last; __vector4 *end; } VecV;
void fn_882643C8(VecV *v, __vector4 *where, unsigned int count, const __vector4 *val);

static __inline __vector4 *copyv(__vector4 *f, __vector4 *l, __vector4 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}

void fn_88262E40(VecV *v, unsigned int n)
{
    __vector4 val;
    memset(&val, 0, sizeof(val));
    if (n < (unsigned int)(v->last - v->first))
        v->last = copyv(v->last, v->last, v->first + n);
    else
        fn_882643C8(v, v->last, n - (v->last - v->first), &val);
}
