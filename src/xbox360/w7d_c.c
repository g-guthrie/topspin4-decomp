/* W7D: vector/float helpers (LTCG route, /Oc). */
#include "vx1_vector.h"
/* Swing_DLL.xex 0x8866B6E0: |z of the converted position| < limit */
extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif
struct W7dL { char pad[0x6f0]; float f6f0; };
struct W7dC { char pad[0x2c]; struct W7dL *l2c; };
struct W7dS { char pad[0x1c]; struct W7dC *c; };
extern __vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, struct W7dC *c);
unsigned char ts4_z_below_limit_8866B6E0(struct W7dS *s)
{
    __vector4 tmp;
    struct W7dC *c = s->c;
    float d;
    d = ts4_if_get_u32_off4c_8865EC70(&tmp, c)->v[2];
    d = (float)fabs(d);
    if (d < c->l2c->f6f0)
        return 1;
    return 0;
}
