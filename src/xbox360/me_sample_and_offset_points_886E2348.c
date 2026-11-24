/* 0x886E2348 (hand match): resize the point buffer, sample into it, then offset every point. */
#include "vx1_vector.h"
typedef struct In14 { char p[0x3fc]; int f3fc; } In14;
typedef struct Lay { char p[0x14]; In14 *f14; char q[0x18]; char f30[0x14]; float f44; float f48; char r[0x3c]; int f88; char s[0x4c0-0x8c]; unsigned char f4c0; char t[0x564-0x4c1]; __vector4 *f564; } Lay;
typedef struct In8 { char p[0x40]; int f40; } In8;
typedef struct Obj { int f0; Lay *f4; In8 *f8; __vector4 *fc; char p[8]; int f18; float f1c; } Obj;
void fn_88261EA8(void *v, int n);
void fn_886DBD00(void *s, float a, float t, __vector4 *p, int n, float b, float *out);
typedef struct Sub30 { char p[0x14]; float f14; float f18; char r[0x3c]; int f58; char s[0x490-0x5c]; unsigned char f490; } Sub30;
static __inline void addall(__vector4 *b, __vector4 *e, __vector4 v){ __vector4 *it; for (it = b; it != e; it++) *it = __vaddfp(*it, v); }
void ts4_sample_and_offset_points_886E2348(Obj *o, float t){ Lay *l = o->f4; Sub30 *q = (Sub30 *)l->f30; int base, n; __vector4 *p, *e; float tmp;
 l->f4c0 = 0; base = l->f14->f3fc; n = o->f8->f40 - base + 1;
 fn_88261EA8(&o->fc, n);
 p = o->fc; e = p + n;
 fn_886DBD00(&q->f58, q->f18, t, p, n, q->f14, &tmp);
 addall(p, e, *l->f564);
 o->f1c = tmp; o->f18 = base; l->f4c0 = 1; }
