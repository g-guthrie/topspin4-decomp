/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8841ED80: C++ member: returns &items[i] for 24-byte items, array pointer at +0x18. Only the member form
 * matches (as a C function the load takes r10 instead of r11); C callers use the alias in the spec.
 * Source: drafts/me_8841ED80_nearmiss.cpp (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_8841ED80.json for route and flags. */
struct Ts4Item24_8841ED80 { int a[6]; };
struct Ts4Items24Owner_8841ED80 { char p[0x18]; Ts4Item24_8841ED80 *items; Ts4Item24_8841ED80 *At(int i); };
Ts4Item24_8841ED80 *Ts4Items24Owner_8841ED80::At(int i) { return &items[i]; }
