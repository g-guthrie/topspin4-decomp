/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8841F0D8: C++ member: returns &items[i] for 20-byte items, array pointer at +0x10. Only the member form
 * matches (as a C function the load takes r10 instead of r11); C callers use the alias in the spec.
 * Source: drafts/me_8841F0D8_nearmiss.cpp (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_8841F0D8.json for route and flags. */
struct Ts4Item20_8841F0D8 { int a[5]; };
struct Ts4Items20Owner_8841F0D8 { char p[0x10]; Ts4Item20_8841F0D8 *items; Ts4Item20_8841F0D8 *At(int i); };
Ts4Item20_8841F0D8 *Ts4Items20Owner_8841F0D8::At(int i) { return &items[i]; }
