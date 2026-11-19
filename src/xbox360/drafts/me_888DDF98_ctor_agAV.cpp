/* DRAFT (agAV): full byte match under plain /Oc as a real C++ ctor; key ??0TS4SwObj888DDF98@@QAA@XZ. Not saved as a spec (mangled keys break integration). */
/* 0x888DDF98: constructor of a Swing_DLL object built on the shared base fn_88617D88 (agAV).
 * Matched as a real C++ constructor: an intermediate inline base stores the vtable label right after the
 * base call, then inline member constructors run in field order (a 3-word range record {0, 0xFFFFF, 0},
 * three 12-byte members built by fn_8816D1A8 with a cleared word pair between them), then the body clears
 * the remaining fields and sets +0x44 to -1. */
extern "C" void *fn_88617D88(void *self);
extern "C" void fn_8816D1A8(void *p);
extern "C" char lbl_880DB8DC[];
struct TS4SwBase888DDF98 { const void *vt; char p4[0x28]; TS4SwBase888DDF98() { fn_88617D88(this); } };
struct TS4SwVt888DDF98 : TS4SwBase888DDF98 { TS4SwVt888DDF98() { vt = lbl_880DB8DC; } };
struct TS4SwRange888DDF98 { int lo, hi, cur; TS4SwRange888DDF98() { lo = 0; cur = 0; hi = 0xfffff; } };
struct TS4SwMember888DDF98 { int x[3]; TS4SwMember888DDF98() { fn_8816D1A8(this); } };
struct TS4SwPair888DDF98 { int a, b; TS4SwPair888DDF98() { a = 0; b = 0; } };
struct TS4SwObj888DDF98 : TS4SwVt888DDF98 {
  int f2c; TS4SwRange888DDF98 range; int f3c, f40, f44;
  TS4SwMember888DDF98 m48; TS4SwPair888DDF98 p54; TS4SwMember888DDF98 m5c; TS4SwMember888DDF98 m68; int f74;
  TS4SwObj888DDF98();
};
TS4SwObj888DDF98::TS4SwObj888DDF98() { f2c = 0; f3c = 0; f40 = 0; f44 = -1; f74 = 0; }
