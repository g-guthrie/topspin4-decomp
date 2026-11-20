/* 0x888DE430: constructor of a Swing_DLL object built on the shared base fn_88617D88 (agAV).
 * Same shape as 0x888DDF98: an intermediate inline base stores the vtable label right after the base call,
 * inline member constructors then clear three 8-byte slots ({word, flag byte at +6}) and build three
 * 12-byte members with fn_8816D1A8; the body clears four flag bytes, sets two to 1 and clears +0x1c. */
extern "C" void *fn_88617D88(void *self);
extern "C" void fn_8816D1A8(void *p);
extern "C" char lbl_880DB794[];
struct TS4SwBase888DE430 { const void *vt; char p4[0x18]; int f1c; TS4SwBase888DE430() { fn_88617D88(this); } };
struct TS4SwVt888DE430 : TS4SwBase888DE430 { TS4SwVt888DE430() { vt = lbl_880DB794; } };
struct TS4SwSlot888DE430 { int value; char p4[2]; unsigned char set; char p7; TS4SwSlot888DE430() { value = 0; set = 0; } };
struct TS4SwMember888DE430 { int x[3]; TS4SwMember888DE430() { fn_8816D1A8(this); } };
struct TS4SwObj888DE430 : TS4SwVt888DE430 {
  TS4SwSlot888DE430 s20, s28, s30;
  unsigned char c38, c39, c3a, c3b, c3c, c3d; char p3e[2];
  TS4SwMember888DE430 m40, m4c, m58;
  TS4SwObj888DE430();
};
TS4SwObj888DE430::TS4SwObj888DE430() { c3b = 0; c38 = 0; c39 = 0; c3a = 0; c3c = 1; c3d = 1; f1c = 0; }
