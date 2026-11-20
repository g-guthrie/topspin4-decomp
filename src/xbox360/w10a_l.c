/* W10A: expands 32-byte AABB pairs by a delta with the y lane cleared (Swing_DLL.xex 0x886C42D0). LTCG route; byte-offset form gives (base,index) adds. */
#include "w6b_types.h"
typedef struct A20Box { __vector4 lo, hi; } A20Box;
typedef struct A20O { unsigned char pad[0x20]; A20Box *p20; unsigned char pad2[0x2c - 0x24]; A20Box *p2c; unsigned char pad3[0x3c - 0x30]; A20Box *p3c; } A20O;
void ts4_expand_boxes_886C42D0(A20O *s, int i, int j)
{
    int o = i * 32;
    A20Box *start = (A20Box *)((char *)s->p20 + o);
    A20Box *end = s->p20 + j;
    A20Box *dst = (A20Box *)((char *)s->p3c + o);
    A20Box *src = (A20Box *)((char *)s->p2c + o);
    for (; start != end; start++, src++, dst++) {
        __vector4 d = __vsubfp(src->hi, src->lo);
        __vector4 a0 = start->lo;
        __vector4 a1 = start->hi;
        __vector4 mn = __vminfp(a0, a1);
        __vector4 mx = __vmaxfp(a0, a1);
        __vector4 p, q;
        d = __vrlimi(d, __vspltisw(0), 4, 0);
        p = __vaddfp(a0, d);
        q = __vaddfp(a1, d);
        dst->lo = __vminfp(mn, __vminfp(p, q));
        dst->hi = __vmaxfp(mx, __vmaxfp(p, q));
    }
}
