/* Swing_DLL.xex 0x8827F008-0x88479E70, executable version 0.0.0.3. */
/* Virtual-slot call thunks (numbered virtual slots, extern "C" entry points). */
struct ts4_iface_8827F008 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void m(); };
struct ts4_in_8827F008 { char p0[4]; struct { char p[0x44]; int cnt; } *x; };
struct ts4_owner_8827F008 { char p0[0x14]; ts4_iface_8827F008 *p14; ts4_in_8827F008 *p18; };
extern "C" void ts4_bump_then_call_slot7_8827F008(ts4_owner_8827F008 *o) { o->p18->x->cnt++; o->p14->m(); }

struct ts4_iface_88419EE0 { virtual void s0(); virtual void s1(); virtual void m(int a, int b, char *c, int d, int e); };
extern "C" const float lbl_88001978;
struct ts4_iface_88479E70 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void m(void *p, float t, int a); };
struct ts4_tm_88479E70 { char p[4]; float f; };
struct ts4_rr_88479E70 { char p[0x6c]; ts4_tm_88479E70 *t; };
struct ts4_owner_88479E70 { char p0[8]; ts4_rr_88479E70 *r; int pad; ts4_iface_88479E70 *i; char p1[0xa0 - 0x14]; char blob[1]; };
extern "C" void ts4_call_slot7_scaled_88479E70(ts4_owner_88479E70 *o, int a) { o->i->m(o->blob, o->r->t->f * lbl_88001978, a); }

extern "C" const float lbl_88001A20;
extern "C" const float lbl_88001A68;
struct ts4_iface_88475410 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void m(float v); };
extern "C" void ts4_call_slot4_reciprocal_88475410(ts4_iface_88475410 *o, float v) { if (v == lbl_88001A20) v = lbl_88001A20; else v = lbl_88001A68 / v; o->m(v); }

struct ts4_iface_88426FA0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void m(const char *p, int n); };
struct ts4_owner_88426FA0 { char p[8]; ts4_iface_88426FA0 *i; };
extern "C" void ts4_call_slot4_one_byte_88426FA0(ts4_owner_88426FA0 *o, char c) { o->i->m(&c, 1); }
