#include "vx1_vector.h"
extern __vector4 lbl_88D46390;
typedef struct HkaQ2 { unsigned long long q[2]; } HkaQ2;
struct HkaB { unsigned char pad[0x41]; unsigned char f41; };

void ts4_scale_two_vectors_889C0F70(struct HkaB *b, __vector4 *p)
{
    __vector4 t, u;
    if (b->f41 != 0) return;
    b->f41 = 1;
    t = __vmulfp(p[0], lbl_88D46390);
    *(HkaQ2 *)&p[0] = *(HkaQ2 *)&t;
    u = __vmulfp(p[1], lbl_88D46390);
    *(HkaQ2 *)&p[1] = *(HkaQ2 *)&u;
}
