/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8866C150 - EQUIVALENT tier, not byte-matched.
 * fn_check: 4 instructions off (only the li order of the two vector offsets differs).
 * fn_equiv/4 evidence: work/q5/evidence/eq_q5f_target_far_idle.equiv.json */
#include "w6a_types.h"

#ifdef _MSC_VER
double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

typedef struct W6aActor8e0 {
    unsigned char pad00[0x8e0];
    __vector4 pos;                      /* +0x8e0 */
} W6aActor8e0;

typedef struct W6aTarget154 {
    unsigned char pad00[0x74];
    W6aActor8e0 *actor;                 /* +0x74 */
} W6aTarget154;

typedef struct W6aSelf270 {
    unsigned char pad00[0x154];
    W6aTarget154 *target;               /* +0x154 */
    unsigned char pad158[0x270 - 0x158];
    __vector4 pos;                      /* +0x270 */
    unsigned char pad280[0x294 - 0x280];
    unsigned char b294;
} W6aSelf270;

extern float g_ts4_script_constants[];
int ts4_target_far_and_idle_8866C150(W6aSelf270 *self)
{
    W6aActor8e0 *a = self->target->actor;
    __vector4 d = __vsubfp(a->pos, self->pos);
    __vector4 s = __vmsum3fp(d, d);
    if (s.v[0] > g_ts4_script_constants[0x3e4 / 4]) {
        if (self->b294 == 0)
            return 1;
    }
    return 0;
}
