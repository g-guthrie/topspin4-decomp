#include "w6c_types.h"

void ts4_vec_spill_8866D168(__vector4 a, __vector4 b)
{
    float *p = a.v;
    float *q = b.v;
    (void)p;
    (void)q;
}

#ifdef _MSC_VER
typedef struct __declspec(align(16)) W6cV {
    float x, y, z, w;
} W6cV;
#else
typedef struct __attribute__((aligned(16))) W6cV {
    float x, y, z, w;
} W6cV;
#endif
void ts4_vec_copy_886C3E08(W6cV *out, __vector4 v)
{
    __vector4 t = v;
    *out = *(W6cV *)&t;
}

void ts4_scale_vv_88670BD8(W6cVV *s, float k)
{
    __vector4 sc = vx1_replicate(k);
    w6c_vmul(&s->b, sc);
    w6c_vmul(&s->a, sc);
    { float *p = &s->x; *p = *p * k; }
    w6c_fmul(&s->y, k);
}


typedef struct W6cDstVec {
    __vector4 *begin;
    __vector4 *end;
    __vector4 *cap;
} W6cDstVec;

typedef struct W6cBoxes {
    unsigned char pad00[8];
    char *a_begin;      /* +0x08 */
    char *a_end;        /* +0x0c */
    unsigned char pad10[4];
    __vector4 *src;     /* +0x14 */
    __vector4 *src_end; /* +0x18 */
    unsigned char pad1c[4];
    W6cDstVec dst;      /* +0x20 */
} W6cBoxes;

void fn_88262ED8(W6cDstVec *v, int n);

void ts4_boxes_minmax_886C9688(W6cBoxes *s)
{
    __vector4 *p, *d, *e;
    fn_88262ED8(&s->dst, (int)(s->a_end - s->a_begin) / 0x18);
    e = s->src_end;
    p = s->src;
    d = s->dst.begin;
    for (; p != e; p += 2) {
        __vector4 a = p[0], b = p[1];
        d[0] = __vminfp(a, b);
        d[1] = __vmaxfp(a, b);
        d += 2;
    }
}

typedef struct W6cCnt {
    unsigned char pad[0x3fc];
    unsigned count;
} W6cCnt;
typedef struct W6cOwn {
    unsigned char pad[0x14];
    W6cCnt *cnt;
} W6cOwn;
typedef struct W6cLim {
    unsigned char pad[0x40];
    unsigned max;
} W6cLim;
typedef struct W6cTrack {
    unsigned char pad00[4];
    W6cOwn *owner;      /* +4 */
    W6cLim *lim;        /* +8 */
    __vector4 *items;   /* +0xc */
    unsigned char pad10[8];
    unsigned first;     /* +0x18 */
} W6cTrack;

void ts4_track_get_886C4DF0(W6cTrack *s, __vector4 *out)
{
    unsigned n = s->owner->cnt->count;
    unsigned char ok = n >= s->first && n <= s->lim->max;
    if (ok)
        *out = s->items[n - s->first];
}
