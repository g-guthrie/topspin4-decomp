#include "vx1_vector.h"
struct W8bMats { unsigned char *base; };
struct W8bSelfM { unsigned char pad00[0x24]; void *src; };
extern struct W8bMats *ts4_call_seq_fn_884025C0_88402FB0(void *src);
extern struct W8bMats *ts4_call_seq_fn_884027D8_88402FD8(void *src);

void ts4_get_matrix_row_88645348(struct W8bSelfM *self, unsigned idx, float *out, unsigned char flag)
{
    struct W8bMats *m;
    __vector4 *rp;
    float t[4];
    if (flag)
        m = ts4_call_seq_fn_884025C0_88402FB0(self->src);
    else
        m = ts4_call_seq_fn_884027D8_88402FD8(self->src);
    rp = (__vector4 *)(m->base + idx * 0x30 + 0x10);
    __stvewx(__vspltw(*rp, 3), &t[1], 0);
    __stvewx(__vspltw(*rp, 2), &t[0], 0);
    __stvewx(__vspltw(*rp, 1), &t[3], 0);
    __stvewx(__vspltw(*rp, 0), &t[2], 0);
    out[0] = t[2];
    out[1] = t[3];
    out[2] = t[0];
    out[3] = t[1];
}
