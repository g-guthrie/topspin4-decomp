/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88443518: C++ member: returns items[i].b (+4) for 16-byte items, array pointer at +0x8. Only the member
 * form matches; C callers use the alias in the spec.
 * Source: drafts/me_88443518_nearmiss.cpp (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_88443518.json for route and flags. */
struct Ts4Quad_88443518 { unsigned a, b, c, d; };
struct Ts4QuadOwner_88443518 { char p[0x8]; Ts4Quad_88443518 *items; unsigned Word1At(int i); };
unsigned Ts4QuadOwner_88443518::Word1At(int i) { return items[i].b; }
