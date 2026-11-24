/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x886EBA80: C++ member: returns &items[i] for 16-byte items, array pointer at +0x10. Only the member form
 * matches; C callers use the alias in the spec.
 * Source: drafts/me_886EBA80_nearmiss.cpp (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_886EBA80.json for route and flags. */
struct Ts4Item16_886EBA80 { int a[4]; };
struct Ts4Items16Owner_886EBA80 { char p[0x10]; Ts4Item16_886EBA80 *items; Ts4Item16_886EBA80 *At(int i); };
Ts4Item16_886EBA80 *Ts4Items16Owner_886EBA80::At(int i) { return &items[i]; }
