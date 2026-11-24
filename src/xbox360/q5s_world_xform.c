/* World subsystem: 0x888C0818 sets an object's placement: the position (x, y, z) and the
 * scale (1, sy, 1) go into the transform block at +0x84 as unaligned float3 loads, and the
 * two scalars into +0x88 / +0x8c. Sister of q5_gameplay_scale_reset.c (0x888C0890).
 * Both float3 temporaries are filled before the first vector store. Plain route: on the
 * LTCG route the checker names the 0x8814B440 constant g_ts4_event_value. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#ifdef _MSC_VER
#pragma intrinsic(__vsldoi)
#endif
extern float g_ts4_event_value;  /* 1.0f */
typedef struct Q5SF3 { float x, y, z; } Q5SF3;
typedef struct Q5SXform {
    __vector4 pos;      /* +0x00 */
    __vector4 scale;    /* +0x10 */
} Q5SXform;
typedef struct Q5SPlaced {
    char pad0[0x84];
    Q5SXform *xf;       /* +0x84 */
    float f88;          /* +0x88 */
    float f8c;          /* +0x8c */
} Q5SPlaced;
static __inline __vector4 q5s_load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}
/* Swing_DLL.xex 0x888C0818 */
void ts4_placed_set_888C0818(Q5SPlaced *o, float sy, float a, float b, float x, float y, float z)
{
    Q5SF3 t, s;
    float one = g_ts4_event_value;
    t.x = x;
    t.y = y;
    t.z = z;
    s.x = one;
    s.y = sy;
    s.z = one;
    o->xf->pos = q5s_load3(&t);
    o->xf->scale = q5s_load3(&s);
    o->f88 = a;
    o->f8c = b;
}
