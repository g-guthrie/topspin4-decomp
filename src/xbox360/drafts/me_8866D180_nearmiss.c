/* agentB 2026-11-18 pass 2: still 5 off (plain and LTCG). Else-branch temp/pointer/volatile copy, block pad, vector-only copy (12),
 * ternary with inline negation helper (17-37): r11 is still taken first in the else copy. */
/* NEAR MISS (5 off: else-branch struct copy uses r10/r9/r8 in the target, r11/r10/r9 here; tried
 * if/else swap, switch, helper return, assign helper, union type, C++, LTCG).
 * 0x8866D180: for the given hash, replace the vector by its xyz negation (lane setters on the
 * uninitialised result), otherwise keep it. */
#include "vx1_vector.h"
typedef struct V3 { __vector4 v; } V3;
void ts4_negate_on_hash_8866D180(V3 *o, int h)
{
    V3 r;
    if (h == (int)0xA2EDA1E7) {
        r.v = vx1_set_x(r.v, -o->v.v[0]);
        r.v = vx1_set_y(r.v, -o->v.v[1]);
        r.v = vx1_set_z(r.v, -o->v.v[2]);
    } else
        r = *o;
    *o = r;
}
