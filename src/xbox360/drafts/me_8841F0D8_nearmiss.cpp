/* NEAR MISS 0x8841F0D8 (agU round 2): this C++ member body MATCHES on /Oc plain and LTCG, but the mangled member name breaks C callers that reference fn_8841F0D8. As a C function or an extern "C" C++ function (direct, wrapping an inline member, a reference parameter, an index helper, __restrict, pads 0-4, LTCG, /O1, /Ob1) every form is 2-4 off: lwz goes to r10 instead of r11. Register choice follows the hidden this symbol. */
/* 0x8841F0D8: returns &items[i] for 20-byte items at +0x10 (C++ member; the C form swaps r10/r11) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
struct It_8841F0D8 { int a[5]; };
struct O_8841F0D8 { char p[0x10]; It_8841F0D8 *items; It_8841F0D8 *at(int i); };
It_8841F0D8 *O_8841F0D8::at(int i) { return &items[i]; }
