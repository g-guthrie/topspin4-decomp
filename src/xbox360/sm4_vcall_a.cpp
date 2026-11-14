// SM4: virtual dispatch through global / member objects (C++ so the compiler emits real vtable calls).
// Members holding the object pointer as a plain int avoid the zero-extension of `this`.
struct Ts4V8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int v4(void *a); virtual void v5(); virtual void v6(); virtual void v7(float f); };
struct Ts4VF { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(float f); };
struct Ts4V6 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); };
struct Ts4VO { virtual void v0(void *o); virtual void v1(void *o); char pad[0x14]; void *f18; int f1c; };

extern "C" Ts4V8 *lbl_88CAD568;
/* call slot 4 of the global object with the argument */
extern "C" void ts4_vcall_global_slot4_88422490(void *a) { lbl_88CAD568->v4(a); }

extern "C" const float lbl_88001A68;
/* slot 4 of this with (constant / x) */
extern "C" void ts4_vcall_slot4_div_884790A8(Ts4VF *w, float x) { w->v4(lbl_88001A68 / x); }

struct Ts4H2 { char pad[0x18]; Ts4V8 *m; char pad2[4]; float f20; };
/* slot 7 of the member object with (f20 + x) */
extern "C" void ts4_vcall_member_slot7_add_8844BBC8(Ts4H2 *h, float x) { h->m->v7(h->f20 + x); }

struct Ts4H3 { char pad[0x2c]; int o; };
/* slot 5 of the object at +0x2c when present */
extern "C" void ts4_vcall_member_slot5_88608300(Ts4H3 *h) { int o = h->o; if (o) ((Ts4V6 *)o)->v5(); }

/* remember the owner and two derived pointers, then dispatch slot 1 */
extern "C" void ts4_attach_owner_vcall1_88660CF0(Ts4VO *s, char *o) { s->f18 = o; s->f1c = *(int *)(o + 0x74) + 0x3a8; s->v1(o); }
extern "C" void ts4_attach_owner_vcall1_88660EE8(Ts4VO *s, char *o) { s->f18 = o; s->f1c = *(int *)(o + 0x74) + 0x358; s->v1(o); }

// delete of an owned member: null check, then the virtual scalar deleting destructor with flag 1
struct Ts4VDtor { virtual ~Ts4VDtor(); };
struct Ts4HDel0 { Ts4VDtor *m; };
struct Ts4HDel24 { char pad[0x24]; Ts4VDtor *m; };
extern "C" void ts4_delete_member_0_884D5F78(Ts4HDel0 *h) { delete h->m; }
extern "C" void ts4_delete_member_24_8860E5C0(Ts4HDel24 *h) { delete h->m; }

// write one byte through the object's stream (slot 4 with the address of the by-value parameter)
struct Ts4IO { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(char *p, int n); };
struct Ts4W1 { char pad[8]; Ts4IO *io; };
extern "C" void ts4_write_byte_via_stream_88426F60(Ts4W1 *w, char c) { w->io->v4(&c, 1); }
extern "C" Ts4W1 *ts4_write_byte_via_stream_8841D008(Ts4W1 *w, char c) { w->io->v4(&c, 1); return w; }

// replace the value at +0x38, running the change handler when asked; returns the old value
extern "C" int fn_886F6348(void *);
struct Ts4X1 { char pad[0x38]; int cur; };
extern "C" int ts4_set_current_notify_886F63C0(Ts4X1 *s, int v, unsigned char flag) { int old = s->cur; if (v != old) { if (flag) fn_886F6348(s); } s->cur = v; return old; }

// global singleton queries: arguments are evaluated right to left, so the trailing global is read before the virtual call
struct Ts4GO { virtual void v0(); virtual void v1(); virtual void v2(); virtual int v3(); virtual int v4(void *a); };
extern "C" Ts4GO *lbl_88D26F84;
extern "C" int lbl_88D26FCC;
extern "C" void fn_884CE440(int, int, int, int, int);
extern "C" void ts4_call_with_global_vcall3_884CE740(int a, int b, int c) { fn_884CE440(a, b, c, lbl_88D26F84->v3(), lbl_88D26FCC); }
extern "C" void ts4_if_call_seq_fn_8841E4A0_884CE798(int, int, int, int, int);
extern "C" void ts4_call_with_global_vcall3_884CE888(int a, int b, int c) { ts4_if_call_seq_fn_8841E4A0_884CE798(a, b, c, lbl_88D26F84->v3(), lbl_88D26FCC); }

// ask the global registry for the object matching this, then forward when found
extern "C" void fn_88422860(void *, void *, int, int);
extern "C" void fn_88422BA0(void *, void *, int, int);
extern "C" void ts4_lookup_then_forward_884230E8(void *self, int a, int b) { void *r = (void *)lbl_88CAD568->v4(self); if (r) fn_88422860(self, r, a, b); }
extern "C" void ts4_lookup_then_forward_88423140(void *self, int a, int b) { void *r = (void *)lbl_88CAD568->v4(self); if (r) fn_88422BA0(self, r, a, b); }

// slot 21 of this supplies the third argument of the helper
extern "C" void fn_8860DCF8(void *, int, int, int);
struct Ts4X21 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual int v21(); };
extern "C" void ts4_call_with_vcall21_88613890(Ts4X21 *s, int a, int b) { fn_8860DCF8(s, a, s->v21(), b); }
