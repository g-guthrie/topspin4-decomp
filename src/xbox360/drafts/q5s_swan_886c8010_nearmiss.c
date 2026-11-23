/* nearmiss: 9 off; concrete blocker: GPR numbering of the two 16-byte ld/std copies only (target: then-branch
 * copy uses r10/r9/r8 and skips r11, tail copy numbers the ld before the &y temp; here r11/r10/r9 and &y first).
 * Every instruction otherwise matches. Tried without effect (all 9): C and extern "C" C++, local order, split init
 * of y, a copy helper on one or both copies, a pointer to t, an inline mirror() returning or filling t, a block
 * around the tail. The older draft (drafts/me_886C8010_nearmiss.c) needed 8 dead pads for the same 9.
 * Swing_DLL.xex 0x886C8010: mirrors a court-space vector when the court is mirrored (x and z negated, y kept). */
#include "vx1_vector.h"
typedef struct Ts4Court { char p[0x88]; int mirrored; } Ts4Court;
typedef struct Ts4Side { char p[0x14]; Ts4Court *court; } Ts4Side;
void ts4_side_mirror_vec_886C8010(Ts4Side *self, Vx1Vec *v)
{
    float y = vx1_vec_y(v);
    Vx1Vec t;
    if (self->court->mirrored == 0) t = *v;
    else {
        float ny = -vx1_vec_y(v), nz = -vx1_vec_z(v);
        vx1_vec_set_x(&t, -vx1_vec_x(v)); vx1_vec_set_y(&t, ny); vx1_vec_set_z(&t, nz);
    }
    *v = t;
    vx1_vec_set_y(v, y);
}
