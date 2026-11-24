/* 0x886E9BC8 near miss (agBE, b197, .cpp /Oc, key ??0TS4RObj886E9BC8@@QAA@XZ): constructor on the shared base
 * fn_88617D88 that registers `this` in a 36-slot table (lbl_88D42948, count at +0x31A4).
 * 3 instructions differ, schedule only: the target loads the registry count between the +0x94 and +0x98 stores;
 * here it lands after +0xB0. Reading the count one store earlier changes register allocation (size +4). */

extern "C" void *fn_88617D88(void *self);
extern "C" char lbl_880F34E4[];
struct TS4RReg886E9BC8 { void *items[0x24]; char pad[0x31a4 - 0x24 * 4]; unsigned int count; };
extern "C" TS4RReg886E9BC8 lbl_88D42948;
struct TS4RBase886E9BC8 { const void *vt; char p4[0x18]; int f1c, f20; TS4RBase886E9BC8() { fn_88617D88(this); f20 = 0; } };
struct TS4RVt886E9BC8 : TS4RBase886E9BC8 { TS4RVt886E9BC8() { vt = lbl_880F34E4; } };
struct TS4RRange886E9BC8 { int lo, hi, cur; TS4RRange886E9BC8() { hi = 0xfffff; lo = 0; cur = 0; } };
struct TS4RPtr886E9BC8 { void *p; TS4RPtr886E9BC8() { p = 0; } };
struct TS4RObj886E9BC8 : TS4RVt886E9BC8 {
  int f24; TS4RRange886E9BC8 r28, r34, r40, r4c;
  int a58[17]; char pad9c[0x14]; int ab0[15];
  TS4RObj886E9BC8();
};
TS4RObj886E9BC8::TS4RObj886E9BC8()
{
  unsigned int n;
  a58[0]=0;
  a58[1]=0;
  a58[2]=0;
  a58[3]=0;
  a58[4]=0;
  a58[5]=0;
  a58[6]=0;
  a58[7]=0;
  a58[8]=0;
  a58[9]=0;
  a58[10]=0;
  a58[11]=0;
  a58[12]=0;
  a58[13]=0;
  a58[14]=0;
  a58[15]=0;
  a58[16]=0;
  ab0[0]=0;
  n = lbl_88D42948.count;
  ab0[1]=0;
  ab0[2]=0;
  ab0[3]=0;
  ab0[4]=0;
  ab0[5]=0;
  ab0[6]=0;
  ab0[7]=0;
  ab0[8]=0;
  ab0[9]=0;
  ab0[10]=0;
  ab0[11]=0;
  ab0[12]=0;
  ab0[13]=0;
  ab0[14]=0;
  f1c = 0;
  f24 = 0;
  if (n < 0x24) { lbl_88D42948.count = n + 1; lbl_88D42948.items[n] = this; }
}
