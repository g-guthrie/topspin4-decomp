/* Q5 gameplay: 0x888C0890 reset of a scale state to the unit value (g_ts4_event_value, 1.0f):
 * marks it dirty, stores (1,1,1) as an unaligned float3 load into +0x70, sets the
 * range pair to (1,1) and clears +0x88. Byte-matches with the default flags.
 * The range pair goes through an inline setter; direct member stores schedule
 * the +0x88 store before +0x84. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#ifdef _MSC_VER
#pragma intrinsic(__vsldoi)
#endif
typedef unsigned int u32;
typedef unsigned char u8;
extern float g_ts4_event_value;
typedef struct Q5F3 { float x, y, z; } Q5F3;
typedef struct Q5F2 { float lo, hi; } Q5F2;
typedef struct Q5ScaleState {
    char pad0[0x70];
    __vector4 scale;    /* +0x70 */
    Q5F2 range;         /* +0x80 */
    u32 w88;            /* +0x88 */
    char pad8c[0x101 - 0x8c];
    u8 dirty;           /* +0x101 */
} Q5ScaleState;
typedef struct Q5ScaleOwner { char pad0[0x80]; Q5ScaleState *st; } Q5ScaleOwner;
static __inline void q5_set2(Q5F2 *p, float a, float b) { p->lo = a; p->hi = b; }
static __inline __vector4 q5_load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}
/* Swing_DLL.xex 0x888C0890 */
void ts4_scale_reset_888C0890(Q5ScaleOwner *o)
{
    Q5F3 t;
    float one = g_ts4_event_value;
    o->st->dirty = 1;
    t.x = one;
    t.y = one;
    t.z = one;
    o->st->scale = q5_load3(&t);
    {
        Q5ScaleState *st = o->st;
        q5_set2(&st->range, one, one);
        st->w88 = 0;
    }
}
