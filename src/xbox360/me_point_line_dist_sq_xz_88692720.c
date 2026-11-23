/* 0x88692720 (hand match): squared distance from a point flattened to XZ to a line (origin, direction). */
#include "vx1_vector.h"
typedef struct Seg { Vx1Vec a; Vx1Vec d; } Seg;
typedef struct Line { __vector4 p0; Seg g; } Line;
extern float g_ts4_event_value;
static __inline float dot3(__vector4 a, __vector4 b){ Vx1Vec t; t.v = __vmsum3fp(a, b); return t.v.v[0]; }
static __inline __vector4 repp(const float *p){ return __vspltw(__lvlx(p, 0), 0); }
float ts4_point_line_dist_sq_xz_88692720(Line *s, __vector4 pv){ Seg *g = &s->g; Vx1Vec q, d; float k; __vector4 l;
 q.v.v[0] = pv.v[0]; q.v.v[2] = pv.v[2]; q.v.v[1] = g_ts4_event_value; q.v.v[3] = g_ts4_event_value;
 d = g->d;
 k = dot3(__vsubfp(q.v, g->a.v), g->d.v);
 { Vx1Vec *o = &d; l = __vmulfp(o->v, repp(&k)); o->v = g->a.v; o->v = __vaddfp(o->v, l); o->v = __vsubfp(o->v, q.v); return dot3(o->v, o->v); } }
