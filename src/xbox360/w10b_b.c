#include "vx1_vector.h"
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, unsigned size, unsigned align, unsigned flags, unsigned pool);
struct W10dH { int rel; int cnt; };
struct W10dX { unsigned char pad[0xc]; struct W10dH h; };
struct W10dK { unsigned char pad[0x10]; struct W10dX *p10; };
struct W10dA { unsigned char pad[0x18]; struct W10dK *p18; };
struct W10dN { unsigned char b0; unsigned char pad1[0x1f]; __vector4 v20; unsigned char pad30[0x70 - 0x30]; int w70; struct W10dX *w74; struct W10dA *w78; };
struct W10dO {
    unsigned char pad[0x50];
    struct W10dA *p50;
    struct W10dN *p54;
    struct W10dX *p58;
    void *p5c;
    unsigned char pad60;
    unsigned char b61;
};
static __inline char *w10d_beg(struct W10dH *h) { return (char *)h + h->rel; }
void ts4_init_owner_886CA480(struct W10dO *o, struct W10dA *a)
{
    struct W10dN *n, *r;
    struct W10dK *k;
    struct W10dX *x;
    o->p50 = a;
    o->b61 = 0;
    k = a->p18;
    n = (struct W10dN *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x80, 0x10, 0, 2);
    if (n) {
        n->w70 = 0;
        n->b0 = 0;
        n->v20 = __vspltisw(0);
        n->w74 = k->p10;
        n->w78 = 0;
        r = n;
    } else {
        r = 0;
    }
    o->p54 = r;
    r->w78 = a;
    x = a->p18->p10;
    o->p58 = x;
    if (x->h.cnt != 0)
        o->p5c = w10d_beg(&x->h);
}
