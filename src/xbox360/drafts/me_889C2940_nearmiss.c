/* NEAR MISS draft (not built, not counted): 2 off, lfs/lbz load pair swapped before the call (1260 statement orders give the same pair). See docs/agents/matching-tips.md, "Near misses parked". */
#include "vx1_vector.h"
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef unsigned char u8;
typedef struct{u8 x;} T369;
typedef struct Obj { char p0[0x124]; float f124; char p128[0x350-0x128]; __vector4 v350; char p360[9]; T369 b369; char p36a[2]; float f36c; float f370; char p374[0xc]; char o380[4]; signed char b384; char p385[0x3a8-0x385]; float f3a8; char p3ac[0x20]; float f3cc; } Obj;
extern void fn_889C2678(void *self, Obj *o, void *out);
void f(void *self, Obj *o, const __vector4 *v){ float t; T369 b; __vector4 sv; __vector4 nv; signed char c;
 o->f370 = o->f3cc; nv = *v; t = o->f36c; b = o->b369; o->b369.x = 0; sv = o->v350; o->f36c = g_ts4_event_value; o->v350 = nv;
 fn_889C2678(self, o, o->o380);
 if ((o->f3a8 * g_ts4_script_constants[8] < o->f124)) c = 1; else c = 0; o->f36c = t; o->b384 = c; o->v350 = sv; o->b369 = b; }
