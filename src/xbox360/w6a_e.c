#include "w6a_types.h"

typedef struct W6aHolder40 {
    unsigned char pad00[0x40];
    Vx1Vec v;
} W6aHolder40;

W6aHolder40 *fn_88661078(void *self);

void ts4_negate_xz_88670868(void *self)
{
    W6aHolder40 *h = fn_88661078(self);
    vx1_vec_set_z(&h->v, -vx1_vec_z(&h->v));
    vx1_vec_set_x(&h->v, -vx1_vec_x(&h->v));
}
