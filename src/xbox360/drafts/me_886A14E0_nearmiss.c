/* near miss 0x886A14E0 (ME agent B): 17 off (/Oc). Remaining: count kept in r10 then copied to the loop
 * counter (mr r27,r10) with the 1.0f load after the clrlwi; joint address summed as (rel+off)+base (we get
 * (rel+base)+off); identity-matrix stack slot order 0x70/0x80 swapped. */
#include "ts4_vector.h"
typedef unsigned char U8;
typedef struct Mat { __vector4 r[4]; } Mat;
typedef struct Joint { char p[0xc]; U8 visible; char pd[0x30 - 0xd]; float x, y, z; char p3c[0x70 - 0x3c]; } Joint;
typedef struct JointTable { char p[0x10]; int joints_rel; int count; } JointTable;
typedef struct Rig { char p[0x48]; U8 enabled; char p49[0x92 - 0x49]; U8 force_all; } Rig;
typedef struct RigHolder { char p[0x28]; Rig *rig; } RigHolder;
typedef struct Model { char p[0x1c]; RigHolder *holder; char p20[0x28 - 0x20]; JointTable *table; } Model;
extern float g_ts4_script_constants[];
void fn_886A13B0(Model *m, Joint *j);
void fn_88672EF8(Model *m, Joint *j, Mat *out);
void fn_88672B50(Model *m, Joint *j, Mat *out);
void fn_886634E0(Joint *j, Mat *out);
void *ts4_mat_pretranslate_by_body_886633E8(Model *m, Mat *out);
void fn_88672938(void *body, Joint *j, Mat *out);
static __inline Joint *joint_at(int *rel, int off) { return (Joint *)((char *)rel + (*rel + off)); }
void fn_886A14E0(Model *self)
{
    Rig *rig = self->holder->rig;
    int n = self->table->count;
    U8 all = rig->enabled && rig->force_all;
    int off;
    float one;
    if (n <= 0)
        return;
    one = g_ts4_script_constants[0];
    for (off = 0; n; n--, off += sizeof(Joint)) {
        Joint *j = joint_at(&self->table->joints_rel, off);
        fn_886A13B0(self, j);
        if (all || j->visible) {
            Mat m;
            float pos[4];
            __vector4 z = __vspltisw(0);
            __vector4 w = __vupkd3d(z, 1);
            pos[0] = j->x; pos[1] = j->y; pos[2] = j->z; pos[3] = one;
            m.r[3] = *(__vector4 *)pos;
            m.r[2] = __vpermwi(w, 174);
            m.r[1] = __vpermwi(w, 186);
            m.r[0] = __vpermwi(w, 234);
            fn_88672EF8(self, j, &m);
            fn_88672B50(self, j, &m);
            fn_886634E0(j, &m);
            { void *body = ts4_mat_pretranslate_by_body_886633E8(self, &m); fn_88672938(body, j, &m); }
        }
    }
}
