#include "vx1_vector.h"
extern const __vector4 lbl_880FC650;
struct W10qC {
    unsigned char pad[0x2c];
    int w2c;
    unsigned char pad30[0x160 - 0x30];
    __vector4 v160, v170, v180, v190;
};
struct W10qB { unsigned char pad[0x4c]; struct W10qC *p4c; };
struct W10qO {
    unsigned char pad[0x1c];
    struct W10qB *p1c;
    __vector4 v20, v30;
    int w40;
};
void ts4_select_basis_vec_8866CB28(__vector4 *out, struct W10qO *o)
{
    struct W10qC *c = o->p1c->p4c;
    __vector4 r = lbl_880FC650;
    if (c->w2c == 2) {
        switch (o->w40) {
        case 5: r = c->v190; break;
        case 3: r = c->v180; break;
        case 6: r = c->v170; break;
        case 4: r = c->v160; break;
        }
    } else {
        switch (o->w40) {
        case 1: r = o->v30; break;
        case 2: r = o->v20; break;
        }
    }
    *out = r;
}
