/* 0x88670178 (hand match). */
#include "vx1_vector.h"
typedef struct Obj { char p[0x5a0]; __vector4 *f5a0; __vector4 *f5a4; } Obj;
typedef struct Self { char p[0x88]; Obj *f88; } Self;
double fabs(double);
#pragma intrinsic(fabs)
extern const float lbl_880C960C;
#define DX (b.v[0] - a.v[0])
#define DZ (b.v[2] - a.v[2])
#define EX (e1.v[0] - e0.v[0])
#define EZ (e1.v[2] - e0.v[2])
int ts4_segment_intersect_xz_88670178(Self *s, __vector4 *out, __vector4 a, __vector4 b){ Obj *o = s->f88; __vector4 e1 = o->f5a4[-3]; __vector4 e0 = *o->f5a0; __vector4 r; float det; float t;
 det = DX * EZ - DZ * EX;
 if ((float)fabs(det) < lbl_880C960C) { *out = a; return 0; }
 t = ((a.v[2] - e0.v[2]) * EX - (a.v[0] - e0.v[0]) * EZ) / det;
 e1.v[3] = 0.0f; e1.v[1] = 0.0f; e1.v[0] = DX * t + a.v[0]; e1.v[2] = DZ * t + a.v[2];
 *out = e1; if (t < 0.0f) return 0; return 1; }
