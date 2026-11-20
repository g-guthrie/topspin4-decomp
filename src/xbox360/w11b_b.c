/* W11B batch B: plain route. */
#include "vx1_vector.h"

typedef struct W11bElem { Vx1Vec a; Vx1Vec b; unsigned char p20[0x10]; unsigned w30; unsigned char p34[0xc]; } W11bElem;
typedef struct W11bPool {
    unsigned char p00[0x24]; unsigned w24; unsigned char p28[8];
    W11bElem *src; unsigned char p34[0xc]; W11bElem *dst; unsigned count;
} W11bPool;

/* Swing_DLL.xex 0x886E6FA0: start every element at its source position (position = previous = source). */
void ts4_init_elems_886E6FA0(W11bPool *s)
{
    unsigned i;
    for (i = 0; i < s->count; i++) {
        W11bElem *db = s->dst;
        W11bElem *d = &db[i];
        W11bElem *e = &s->src[i];
        d->a.v = e->a.v;
        d->b.v = e->a.v;
        d->w30 = s->w24;
    }
}
