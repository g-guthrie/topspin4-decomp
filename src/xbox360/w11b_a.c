/* W11B batch A: small gameplay functions, LTCG route (vector copy, FLT_MAX pool constant, lane stores). */
#include "vx1_vector.h"

/* ---- 0x8867D8D0: two vectors set to a constant, two floats set to zero ---- */
extern const __vector4 lbl_880FC650;
extern const float g_ts4_event_value;
typedef struct W11bVV { Vx1Vec a; Vx1Vec b; float x; float y; } W11bVV;

/* Swing_DLL.xex 0x8867D8D0. The second vector is a vor128 copy of the first. */
void ts4_init_vec_pair_8867D8D0(W11bVV *p)
{
    float z = g_ts4_event_value;
    __vector4 v = lbl_880FC650;
    __vector4 w = __vor(v, v);
    p->x = z;
    p->y = z;
    p->a.v = v;
    p->b.v = w;
}

/* ---- 0x88670D10: set the +0x44 relative-array record of the object at +0x28 ---- */
struct W11bRec { unsigned char p[0x18]; unsigned h18; unsigned char q[0x2c-0x1c]; float f2c; };
struct W11bHdr { int rel; int f4; };
struct W11bOwn { unsigned char p[0x44]; struct W11bHdr h; };
struct W11bSelf { unsigned char p[0x28]; struct W11bOwn *o; };

/* Swing_DLL.xex 0x88670D10 */
void ts4_set_rec_88670D10(struct W11bSelf *s)
{
    struct W11bHdr *h = &s->o->h;
    struct W11bRec *r;
    h->f4 = 1;
    r = (struct W11bRec *)((char *)h + h->rel);
    r->h18 = 0x968230b3u;
    r = (struct W11bRec *)((char *)h + h->rel);
    r->f2c = 3.402823466e+38f;
}

/* ---- 0x8869B0A8: run the 20-sample accumulator, keep the first three lanes ---- */
typedef struct W11bC { unsigned char pad[0x48]; unsigned char b48; unsigned char p49[0x6f-0x49]; unsigned char b6f; } W11bC;
typedef struct W11bB { unsigned char pad[0x28]; W11bC *c; } W11bB;
typedef struct W11bA { unsigned char pad[0x48]; W11bB *b; } W11bA;
typedef struct W11bEv { unsigned char pad[0xc]; W11bA *a; } W11bEv;
extern void fn_8868ED00(W11bA *self, __vector4 *out, int n);

/* Swing_DLL.xex 0x8869B0A8 */
void ts4_reach_sample_lanes_8869B0A8(W11bEv *ev)
{
    __vector4 v;
    float t[4];
    W11bC *c;
    c = ev->a->b->c;
    if (c->b48 != 0 && c->b6f != 0) {
        fn_8868ED00(ev->a, &v, 20);
        __stvewx(__vspltw(v, 0), t, 0);
        __stvewx(__vspltw(v, 1), t, 4);
        __stvewx(__vspltw(v, 2), t, 8);
    }
}
