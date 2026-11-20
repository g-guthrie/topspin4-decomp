#include "vx1_vector.h"

typedef struct Hp02Cfg { unsigned char p0[0x3c]; float thr; } Hp02Cfg;
typedef struct Hp02R {
    unsigned char p0[0xc];
    Hp02Cfg *cfg;
    unsigned char p10[0xa8 - 0x10];
    int a8;
    int ac;
} Hp02R;

int ts4_ratio_ge_8865B570(Hp02R *self)
{
    int a;
    int b;
    float q;

    a = self->a8;
    if (a == 0)
        return 0;
    b = self->ac;
    q = (float)b / (float)a;
    if (q >= self->cfg->thr)
        return 1;
    return 0;
}
