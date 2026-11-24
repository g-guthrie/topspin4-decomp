/* W9A: clear of a three-vector buffer holder; the zero-distance copies stay as dead inline loops. Plain route, /Oc. */
#include "vx1_vector.h"
extern void fn_886C5370(void *p);
extern void fn_886DAFA0(void *p);
extern void fn_88263300(void *p, unsigned a, unsigned b);

typedef struct W9E32 { __vector4 a, b; } W9E32;
typedef unsigned long long W9E8;
typedef struct W9VB { unsigned char *first, *last; } W9VB;
typedef struct W9V32 { W9E32 *first, *last; } W9V32;
typedef struct W9V8 { W9E8 *first, *last; } W9V8;

static __inline unsigned char *w9_copy_b(unsigned char *first, unsigned char *last, unsigned char *dest)
{
    int n = last - first;
    for (; 0 < n; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}
static __inline W9E32 *w9_copy_32(W9E32 *first, W9E32 *last, W9E32 *dest)
{
    int n = last - first;
    for (; 0 < n; --n) { dest->a = first->a; dest->b = first->b; ++dest; ++first; }
    return dest;
}
static __inline W9E8 *w9_copy_8(W9E8 *first, W9E8 *last, W9E8 *dest)
{
    int n = last - first;
    for (; 0 < n; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}

typedef struct W9O886DB398 {
    unsigned w00, w04, w08, w0c, w10, w14, w18;
    W9V32 v32;       /* 0x1c */
    unsigned w24;
    W9VB vb;         /* 0x28 */
    unsigned w30;
    W9V8 v8;         /* 0x34 */
} W9O886DB398;

void ts4_clear_buffers_886DB398(W9O886DB398 *o)
{
    fn_886C5370(o);
    fn_886DAFA0(o);
    o->w10 = 0;
    { W9VB *v = &o->vb; v->last = w9_copy_b(v->last, v->last, v->first); }
    { W9V32 *v = &o->v32; v->last = w9_copy_32(v->last, v->last, v->first); }
    { W9V8 *v = &o->v8; v->last = w9_copy_8(v->last, v->last, v->first); }
    fn_88263300(o, o->w00, o->w04);
    o->w14 = 0;
    o->w0c = 0;
}
