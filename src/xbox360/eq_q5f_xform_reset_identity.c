/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x886E7738 - EQUIVALENT tier, not byte-matched.
 * fn_check: 2 instructions off (order of the two constant vector loads).
 * fn_equiv/4 evidence: work/q5/evidence/eq_q5f_xform_reset_identity.equiv.json */
#include "af1_vector.h"
typedef unsigned int u32;
typedef struct Q5Xf { __vector4 rot; __vector4 pos; char p20[0x38]; u32 a, b, c, d, e; u32 dirty; } Q5Xf;
extern const __vector4 lbl_880FC770;
extern const __vector4 lbl_880FC760;
/* byte-gap: 3 off; order of the two constant vector loads */
void ts4_xform_reset_identity_886E7738(Q5Xf *self)
{
    __vector4 pos = lbl_880FC760, rot = lbl_880FC770;
    self->pos = pos;
    self->rot = rot;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    self->e = 0;
    self->dirty = 1;
}
