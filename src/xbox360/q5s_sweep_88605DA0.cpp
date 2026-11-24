/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88605DA0: C++ member: returns items[i].b >> 12 for 16-byte items, array pointer at +0x1c. Only the
 * member form matches; C callers use the alias in the spec.
 * Source: drafts/me_88605DA0_nearmiss.cpp (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_88605DA0.json for route and flags. */
struct Ts4Quad_88605DA0 { unsigned a, b, c, d; };
struct Ts4QuadOwner_88605DA0 { char p[0x1c]; Ts4Quad_88605DA0 *items; unsigned Word1Shr12At(int i); };
unsigned Ts4QuadOwner_88605DA0::Word1Shr12At(int i) { return items[i].b >> 12; }
