/* DRAFT (agAV, 2 off, plain /Oc, spec key ??0D@@QAA@XZ): 0x888C80A0 constructor on base fn_88617D88 that
 * registers itself in lbl_88D4595C. Only the `lis r7` for lbl_88D4595C is scheduled one slot early
 * (target puts it after the vtable store). Member-struct / /Ox / init-list variants all stay 2 off. */
extern "C" void *fn_88617D88(void *self);
extern "C" char lbl_880DB92C[];
struct B { const void *vt; char p4[0x18]; int w1c; B() { fn_88617D88(this); } };
struct B2 : B { B2() { w1c = 0; vt = lbl_880DB92C; } };
struct R { int lo, hi, cur; R() { lo = 0; cur = 0; hi = 0xfffff; } };
struct D : B2 { R r20; R r2c; int a38, a3c, a40, a44, a48; unsigned char b4c; int a50, a54, a58, a5c, a60, a64; D(); };
extern "C" D *lbl_88D4595C;
D::D() { a38 = 0; a3c = 0; a40 = 0; a44 = 0; a48 = 0; b4c = 0; a50 = 0; a54 = 0; a58 = 0; a64 = 0; lbl_88D4595C = this; }
