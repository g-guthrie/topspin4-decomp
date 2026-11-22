/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x886D19C8 - EQUIVALENT tier, not byte-matched.
 * fn_check: 5 instructions off (the target keeps three vor128 copies of one loaded vector).
 * fn_equiv/4 evidence: work/q5/evidence/eq_q5f_pose_reset_default.equiv.json */
#include "ts4_vector.h"
typedef unsigned int ts4_word;
extern char lbl_880FC650[];
extern float lbl_8814B440;
struct Ga6Pose { __vector4 v[4]; ts4_word w40; float f44; };
struct Ga6PoseHolder { char pad_00[8]; struct Ga6Pose *pose; char pad_0c[0xC]; int w18; };
void ts4_pose_reset_default_886D19C8(struct Ga6PoseHolder *h)
{
    struct Ga6Pose *p = h->pose;
    __vector4 d = *(__vector4 *)lbl_880FC650;
    __vector4 d1 = __vor(d, d);
    __vector4 d2 = __vor(d1, d1);
    __vector4 d3 = __vor(d2, d2);
    p->f44 = lbl_8814B440;
    p->w40 = 0;
    p->v[0] = d;
    p->v[1] = d1;
    p->v[2] = d2;
    p->v[3] = d3;
    h->w18 = -1;
}
