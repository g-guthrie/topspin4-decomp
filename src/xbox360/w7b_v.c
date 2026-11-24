/* Swing_DLL.xex 0x8866FC68: reset a state object and reload it from a source object (LTCG, vector copies) */
#include "vx1_vector.h"
typedef unsigned int W7bU32;
extern void *fn_88562DC0(void *dst, void *src, W7bU32 n);
extern const float g_ts4_event_value;
typedef struct W7bVec { char *first; char *last; } W7bVec;
static __inline char *w7b_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        W7bU32 n = (W7bU32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
typedef struct W7bDst {
    __vector4 v00, v10, v20, v30;
    float f40, f44, f48;
    int w4c, w50, w54, w58, w5c;
    unsigned char pad[0x5a0 - 0x60];
    W7bVec vec;
} W7bDst;
typedef struct W7bSrc {
    float f00;
    unsigned char p0[0x20 - 4];
    int w20;
    unsigned char p1[0x70 - 0x24];
    __vector4 v70;
    float f80;
    unsigned char p2[0x90 - 0x84];
    float f90, f94, f98;
    unsigned char p3[0x100 - 0x9c];
    __vector4 v100, v110;
} W7bSrc;
void ts4_reset_from_src_8866FC68(W7bDst *o, const W7bSrc *s)
{
    W7bVec *v = &o->vec;
    __vector4 t;
    v->last = w7b_copy(v->last, v->last, v->first);
    o->w4c = 0;
    o->w50 = 0x7fffffff;
    o->w4c = s->w20;
    o->f48 = s->f00;
    t.v[0] = s->f90; t.v[1] = s->f94; t.v[2] = s->f98; t.v[3] = g_ts4_event_value;
    o->v00 = t;
    o->v20 = s->v100;
    o->v30 = s->v110;
    o->v10 = s->v70;
    o->w54 = -1; o->w50 = -1; o->w58 = -1; o->w5c = -1;
}

/* Swing_DLL.xex 0x8866DA00: is |first lane| less than |limit| */
extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif
typedef struct W7bODA00 { unsigned char pad[0x74]; struct W7bP74DA00 *p74; } W7bODA00;
struct W7bP74DA00 { unsigned char pad[0xb00]; float fb00; };
extern __vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, W7bODA00 *o);
unsigned ts4_abs_less_8866DA00(W7bODA00 *o)
{
    __vector4 v;
    float a, b, d;
    a = ts4_if_get_u32_off4c_8865EC70(&v, o)->v[0];
    b = o->p74->fb00;
    a = (float)fabs(a);
    b = (float)fabs(b);
    d = a - b;
    return (*(unsigned short *)&d) >> 15;
}
