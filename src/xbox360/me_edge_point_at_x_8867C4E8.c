/* 0x8867C4E8 (hand match): point (x, 0, 0); when the object has edge records, replace it with the
 * intersection of the segment (x,0,0)-(x,0,K) with the object's edge. */
#include "vx1_vector.h"
typedef struct Obj { char p[0x7c]; char *f7c; char *f80; } Obj;
extern const float g_ts4_script_constants[];
int ts4_segment_intersect_xz_88670178(Obj *s, __vector4 *out, __vector4 a, __vector4 b);
static __inline __vector4 make(float x, float y, float z, float w) { __vector4 t; t.v[0] = x; t.v[1] = y; t.v[2] = z; t.v[3] = w; return t; }
static __inline void set(__vector4 *t, float x, float y, float z, float w) { t->v[0] = x; t->v[1] = y; t->v[2] = z; t->v[3] = w; }
static __inline int count(Obj *o) { return (int)(o->f80 - o->f7c) >> 3; }
__vector4 *ts4_edge_point_at_x_8867C4E8(__vector4 *out, Obj *o, float x)
{
    __vector4 r = make(x, 0.0f, 0.0f, 0.0f);
    if (count(o) != 0)
        ts4_segment_intersect_xz_88670178(o, &r, make(x, 0.0f, 0.0f, 0.0f), make(x, 0.0f, g_ts4_script_constants[15], 0.0f));
    *out = r;
    return out;
}
