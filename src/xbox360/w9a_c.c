/* W9A: vector resize helper pair plus final copy. Plain route, /Oc. */
typedef unsigned int W9U32;
extern void *fn_88562DC0(void *dst, void *src, W9U32 n);
extern void fn_8826B928(void *v, void *pos, int n, W9U32 *val);
extern void fn_88281CA8(void *v, void *pos, int n, W9U32 *val);

typedef struct W9Vec { W9U32 *first; W9U32 *last; W9U32 *cap; } W9Vec;
static __inline W9U32 *w9_copy(W9U32 *first, W9U32 *last, W9U32 *dest)
{
    if (last == first) {
        return dest;
    } else {
        W9U32 n = (W9U32)((char *)last - (char *)first);
        dest = (W9U32 *)fn_88562DC0(dest, first, n);
        return (W9U32 *)((char *)dest + n);
    }
}
typedef struct W9O9710 { W9Vec a; W9Vec b; } W9O9710;

void ts4_resize_and_copy_886C9710(W9O9710 *self, W9Vec *src)
{
    W9U32 n = (W9U32)(src->last - src->first);
    {
        W9U32 zero = 0;
        W9Vec *v = &self->a;
        if (n < v->last - v->first)
            v->last = w9_copy(v->last, v->last, v->first + n);
        else
            fn_8826B928(v, v->last, n - (v->last - v->first), &zero);
    }
    {
        W9U32 zero = 0;
        W9Vec *v = &self->b;
        if (n < v->last - v->first)
            v->last = w9_copy(v->last, v->last, v->first + n);
        else
            fn_88281CA8(v, v->last, n - (v->last - v->first), &zero);
    }
    w9_copy(src->first, src->last, self->a.first);
}
