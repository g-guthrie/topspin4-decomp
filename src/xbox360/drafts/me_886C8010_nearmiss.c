/* 0x886C8010 near miss (9 off; sweep 2026-11-18: file was missing its closing lines (fixed); 8 more (branch swap 32, vcopy/court local/no pads 9, explicit u64 copies 16-39, volatile y 37); LTCG + pp1_pool_primer; GPR numbering in the two ld/std copies only).
 * Mirrors a court-space vector when the court is mirrored: x and z negated, y kept (re-inserted from the saved
 * original). Vx1Vec gives the stack temporary and ld/std copies; pads 1-8 and an inline copy helper: no change. */
#include "vx1_vector.h"
typedef struct Ts4Court { char p[0x88]; int mirrored; } Ts4Court;
typedef struct Ts4Side { char p[0x14]; Ts4Court *court; } Ts4Side;
static __inline void vcopy(Vx1Vec *d, const Vx1Vec *s) { *d = *s; }
void ts4_side_to_court(Ts4Side *self, Vx1Vec *v)
{
    float y = vx1_vec_y(v);
    Vx1Vec t;
    int pad0 = 0;
    int pad1 = 0;
    int pad2 = 0;
    int pad3 = 0;
    int pad4 = 0;
    int pad5 = 0;
    int pad6 = 0;
    int pad7 = 0;
    if (self->court->mirrored == 0) t = *v;
    else {
        float ny = -vx1_vec_y(v), nz = -vx1_vec_z(v);
        vx1_vec_set_x(&t, -vx1_vec_x(v)); vx1_vec_set_y(&t, ny); vx1_vec_set_z(&t, nz);
    }
    vcopy(v, &t);
    vx1_vec_set_y(v, y);
    (void)pad0;
    (void)pad1;
    (void)pad2;
    (void)pad3;
    (void)pad4;
    (void)pad5;
    (void)pad6;

    (void)pad7;
}
