/* NEAR MISS 0x88605DA0 (agU round 2): this C++ member body MATCHES on /Oc plain and LTCG, but the mangled member name breaks C callers that reference fn_88605DA0. As a C function or an extern "C" C++ function (direct, wrapping an inline member, a reference parameter, an index helper, __restrict, pads 0-4, LTCG, /O1, /Ob1) every form is 2-4 off: lwz goes to r10 instead of r11. Register choice follows the hidden this symbol. */
/* 0x88605DA0: returns items[i].b >> 12 for 16-byte items at +0x1c */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
struct It_88605DA0 { unsigned a, b, c, d; };
struct O_88605DA0 { char p[0x1c]; It_88605DA0 *items; unsigned w(int i); };
unsigned O_88605DA0::w(int i) { return items[i].b >> 12; }
