/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x889C2940: evaluates the step (0x889C2678) at a trial position: saves +0x36c, +0x369 and the vector at +0x350,
 * substitutes the event value, a cleared flag and *v, calls the step with the +0x380 output, stores whether
 * +0x3a8 * constants[8] < +0x124 at +0x384 and restores the saved state (+0x370 takes +0x3cc first).
 * Source: drafts/me_889C2940_nearmiss.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_889C2940.json for route and flags. */
#include "vx1_vector.h"
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];
typedef unsigned char u8;
typedef struct{u8 x;} Ts4StepFlag;
typedef struct Ts4StepObj { char p0[0x124]; float f124; char p128[0x350-0x128]; __vector4 v350; char p360[9]; Ts4StepFlag b369; char p36a[2]; float f36c; float f370; char p374[0xc]; char o380[4]; signed char b384; char p385[0x3a8-0x385]; float f3a8; char p3ac[0x20]; float f3cc; } Ts4StepObj;
extern void fn_889C2678(void *self, Ts4StepObj *o, void *out);
void ts4_stepper_eval_at_889C2940(void *self, Ts4StepObj *o, const __vector4 *v){ float t; Ts4StepFlag b; __vector4 sv; __vector4 nv; signed char c;
 o->f370 = o->f3cc; nv = *v; t = o->f36c; b = o->b369; o->b369.x = 0; sv = o->v350; o->f36c = g_ts4_event_value; o->v350 = nv;
 fn_889C2678(self, o, o->o380);
 if ((o->f3a8 * g_ts4_script_constants[8] < o->f124)) c = 1; else c = 0; o->f36c = t; o->b384 = c; o->v350 = sv; o->b369 = b; }
