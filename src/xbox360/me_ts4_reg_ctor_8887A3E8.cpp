/* 0x8887A3E8: constructor of an object with a primary base and two registered interfaces (agAT).
 * Matched as a real C++ constructor: the inline base constructors store the interface base vtables at +8/+0xc,
 * then the derived vtables overwrite all three; the dead base stores are kept as in the target.
 * Both interfaces are registered with ctx (fn_88474708, fn_88474A60) before ctx is stored at +0x14. */
extern "C" void fn_88474708(void *ctx, void *iface);
extern "C" void fn_88474A60(void *ctx, void *iface);
extern "C" char lbl_88088DD4[], lbl_88087B80[], lbl_880DF840[], lbl_880DF84C[], lbl_880DF860[];
struct TS4RegBase8887A3E8 { const void *vt; short f4; short f6; TS4RegBase8887A3E8() { f6 = 1; } };
struct TS4RegIfaceA8887A3E8 { const void *vt; TS4RegIfaceA8887A3E8() { vt = lbl_88088DD4; } };
struct TS4RegIfaceB8887A3E8 { const void *vt; TS4RegIfaceB8887A3E8() { vt = lbl_88087B80; } };
struct TS4Reg8887A3E8 : TS4RegBase8887A3E8, TS4RegIfaceA8887A3E8, TS4RegIfaceB8887A3E8 {
  void *f10; void *ctx; int f18;
  TS4Reg8887A3E8(void *ctx);
};
TS4Reg8887A3E8::TS4Reg8887A3E8(void *c) {
  TS4RegBase8887A3E8::vt = lbl_880DF840;
  TS4RegIfaceA8887A3E8::vt = lbl_880DF84C;
  TS4RegIfaceB8887A3E8::vt = lbl_880DF860;
  f18 = 0;
  fn_88474708(c, static_cast<TS4RegIfaceA8887A3E8 *>(this));
  fn_88474A60(c, static_cast<TS4RegIfaceB8887A3E8 *>(this));
  ctx = c; f10 = 0;
}
