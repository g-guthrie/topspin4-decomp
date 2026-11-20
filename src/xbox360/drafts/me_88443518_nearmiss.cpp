/* NEAR MISS 0x88443518 (agU round 2): this C++ member body MATCHES on /Oc plain and LTCG, but the mangled member name breaks C callers that reference fn_88443518. As a C function or an extern "C" C++ function (direct, wrapping an inline member, a reference parameter, an index helper, __restrict, pads 0-4, LTCG, /O1, /Ob1) every form is 2-4 off: lwz goes to r10 instead of r11. Register choice follows the hidden this symbol. */
/* 0x88443518: returns items[i].b (+4) for 16-byte items at +0x8 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
struct It_88443518 { unsigned a, b, c, d; };
struct O_88443518 { char p[0x8]; It_88443518 *items; unsigned w(int i); };
unsigned O_88443518::w(int i) { return items[i].b; }
