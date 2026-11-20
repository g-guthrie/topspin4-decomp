/* W9D: 0x886706C8 aim vector pick (plain route, /Oc). Bool via int c, result by ||, conditional negate through a float local. */
typedef unsigned char u8;
extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif
extern const float lbl_880C960C;
typedef struct M1Y { char p[0x24]; struct { char p[0xb0]; int w; } *z; char p1[4]; } M1Y;
typedef struct M1Y2 { char p[0x28]; int w28; } M1Y2;
typedef struct M1A { char p[0x32a]; u8 b32a; } M1A;
typedef struct M1X { char p[0x30]; M1A *a; char p1[0x44-0x34]; struct { char p[0x54]; int w54; } *b; } M1X;
typedef struct M1Aim { char p[0x8e]; u8 b8e; } M1Aim;
typedef struct M1 { char p[0x10]; u8 f10; char p1[0x48-0x11]; M1X *x; M1Y *y; char p2[0x74-0x50]; char *st; } M1;
int ts4_pick_aim_vector_886706C8(M1 *pc, float *out)
{
    char *st = pc->st;
    char *aim = st + 0xd20;
    float *src;
    int result;
    int c;
    float t;
    c = pc->f10 != 0 && pc->x->a->b32a != 0 && pc->x->b->w54 == ((M1Y2 *)pc->y)->w28;
    if ((u8)c) src = (float *)(st + 0x438);
    else if (((M1Aim *)aim)->b8e != 0) src = (float *)(aim + 0x50);
    else src = (float *)(st + 0x430);
    result = fabs(src[0]) > lbl_880C960C || fabs(src[1]) > lbl_880C960C;
    out[0] = src[0];
    out[1] = src[1];
    t = out[0];
    if (pc->y->z->w == (int)0xa2eda1e7) t = -t;
    out[0] = t;
    t = out[1];
    if (pc->y->z->w == (int)0xa2eda1e7) t = -t;
    out[1] = t;
    return result;
}
