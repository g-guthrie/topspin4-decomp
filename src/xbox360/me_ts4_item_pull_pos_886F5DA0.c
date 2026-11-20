/* Swing_DLL.xex 0x886F5DA0: copy a source's position (w = g_ts4_event_value) and a 2-float pair into a render item. */
#include "vx1_vector.h"
extern const float g_ts4_event_value;
typedef struct Ts4PosSrc { char pad[0x1c]; float u, v; float x, y, z; } Ts4PosSrc;
typedef struct Ts4PosItem { char pad[8]; Ts4PosSrc *src; char pad2[0x74]; float u, v; char pad3[8]; __vector4 pos; } Ts4PosItem;
static __inline __vector4 make(float x, float y, float z, float w) { __vector4 t; t.v[0] = x; t.v[1] = y; t.v[2] = z; t.v[3] = w; return t; }
void ts4_item_pull_pos_886F5DA0(Ts4PosItem *o)
{
    Ts4PosSrc *s = o->src;
    __vector4 t; t.v[0] = s->x; t.v[1] = s->y; t.v[2] = s->z; t.v[3] = g_ts4_event_value; o->pos = t;
    o->u = s->u;
    o->v = s->v;
}
