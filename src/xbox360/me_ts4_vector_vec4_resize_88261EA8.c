/* Swing_DLL.xex 0x88261EA8: vector<__vector4>::resize(n) with a default-constructed (uninitialised) element: erase the tail (lvx128/stvx128 copy) or _Insert_n (fn_88261F30).
 * /Oc. 88280428 resize template on ts4_vector.h's __vector4. */
#include "ts4_vector.h"
typedef struct VecV { __vector4 *first; __vector4 *last; __vector4 *end; } VecV;
void fn_88261F30(VecV *v, __vector4 *where, unsigned int count, const __vector4 *val);

static __inline __vector4 *copyv(__vector4 *f, __vector4 *l, __vector4 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}

void fn_88261EA8(VecV *v, unsigned int n)
{
    __vector4 val;   /* default-constructed, no initialiser */
    if (n < (unsigned int)(v->last - v->first))
        v->last = copyv(v->last, v->last, v->first + n);
    else
        fn_88261F30(v, v->last, n - (v->last - v->first), &val);
}
