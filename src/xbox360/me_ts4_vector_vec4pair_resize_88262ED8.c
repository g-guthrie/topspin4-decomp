/* Swing_DLL.xex 0x88262ED8: vector<pair of __vector4>::resize(n) with a default-constructed element: erase the tail or _Insert_n (fn_88264068) at end.
 * /Oc. The 32-byte element is not passinreg, so its copy is written member-wise (two lvx128/stvx128) to avoid a word loop. */
#include "ts4_vector.h"
typedef struct Pair4 { __vector4 a, b; } Pair4;
typedef struct VecV { Pair4 *first; Pair4 *last; Pair4 *end; } VecV;
void fn_88264068(VecV *v, Pair4 *where, unsigned int count, const Pair4 *val);

static __inline Pair4 *copyv(Pair4 *f, Pair4 *l, Pair4 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) {
        d->a = f->a;
        d->b = f->b;
    }
    return d;
}

void fn_88262ED8(VecV *v, unsigned int n)
{
    Pair4 val;   /* default-constructed, no initialiser */
    if (n < (unsigned int)(v->last - v->first))
        v->last = copyv(v->last, v->last, v->first + n);
    else
        fn_88264068(v, v->last, n - (v->last - v->first), &val);
}
