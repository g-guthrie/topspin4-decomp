/* 0x8866BEE0 (hand match, LTCG route). */
#include "vx1_vector.h"
typedef unsigned int u32;
typedef struct E20 { char p[0x40]; __vector4 v40; } E20;
typedef struct C5c { char p[0x20]; E20 *f20; } C5c;
typedef struct B48 { char p[0x5c]; C5c *f5c; } B48;
typedef struct D74 { char p[0x8d0]; int f8d0; char q[0xc]; __vector4 v8e0; char r[0xc5c-0x8f0]; float fc5c; } D74;
typedef struct A154 { char p[0x48]; B48 *f48; char q[0x74-0x4c]; D74 *f74; } A154;
typedef struct Self { char p[0x154]; A154 *f154; } Self;
int ts4_is_near_mirrored_x_8866BEE0(Self *s){ Vx1Vec v; Vx1Vec p; float t; int r = 0; D74 *d = s->f154->f74;
 t = d->fc5c; v.v = s->f154->f48->f5c->f20->v40;
 if (d->f8d0 == (int)0xa2eda1e7) { vx1_vec_set_x(&v, -vx1_vec_x(&v)); vx1_vec_set_z(&v, -vx1_vec_z(&v)); }
 p.v = s->f154->f74->v8e0;
 if (t < 200.0f) { if (vx1_vec_x(&p) - vx1_vec_x(&v) < 100.0f) r = 1; }
 return r; }
