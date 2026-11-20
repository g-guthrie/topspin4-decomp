#include "vx1_vector.h"
extern __vector4 lbl_88D463A0;
typedef struct W11Q2 { unsigned long long q[2]; } W11Q2;
struct W11B { unsigned char pad[0x41]; unsigned char f41; };

void ts4_scale_two_vectors_889C0EF8(struct W11B *b, __vector4 *p)
{
    __vector4 t, u;
    if (b->f41 != 1) return;
    b->f41 = 0;
    t = __vmulfp(p[0], lbl_88D463A0);
    *(W11Q2 *)&p[0] = *(W11Q2 *)&t;
    u = __vmulfp(p[1], lbl_88D463A0);
    *(W11Q2 *)&p[1] = *(W11Q2 *)&u;
}
