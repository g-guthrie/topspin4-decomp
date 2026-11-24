/* Near miss, 9 instructions: the target materialises s+0x30 in a register and
 * swaps the v62/v63 roles (zero splat in v63, constant in v62). All statement
 * orders were tried, flat and through an inline sub-object reset helper.
 * Check: python3 tools/fn_check.py <this> ts4_reset_88670CC8=0x88670CC8 --flags /Oc */
#include "ts4_vector.h"
extern const __vector4 lbl_880FC650;
extern const float g_ts4_event_value;
typedef struct { char p[0x30]; __vector4 v30; float f40, f44, f48; char q[0x8d - 0x4c]; unsigned char b8d; } TS4State88670CC8;
typedef struct { char p[0x74]; char *base; } TS4Owner88670CC8;
typedef struct { __vector4 v; char p[0x30 - 0x10]; float f30; } TS4Out88670CC8;
void ts4_reset_88670CC8(void *self, TS4Out88670CC8 *out, TS4Owner88670CC8 *o)
{
    TS4State88670CC8 *s = (TS4State88670CC8 *)(o->base + 0xd20);
    float z = g_ts4_event_value;
    s->b8d = 0;
    out->f30 = z;
    s->v30 = lbl_880FC650;
    out->v = __vspltisw(0);
    s->f40 = z; s->f44 = z; s->f48 = z;
}
