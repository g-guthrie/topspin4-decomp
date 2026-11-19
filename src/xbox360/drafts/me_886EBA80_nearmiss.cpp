/* NEAR MISS 0x886EBA80 (agU round 2): this C++ member body MATCHES on /Oc plain and LTCG, but the mangled member name breaks C callers that reference fn_886EBA80. As a C function or an extern "C" C++ function (direct, wrapping an inline member, a reference parameter, an index helper, __restrict, pads 0-4, LTCG, /O1, /Ob1) every form is 2-4 off: lwz goes to r10 instead of r11. Register choice follows the hidden this symbol. */
/* 0x886EBA80: returns &items[i] for 16-byte items at +0x10 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
struct It_886EBA80 { int a[4]; };
struct O_886EBA80 { char p[0x10]; It_886EBA80 *items; It_886EBA80 *at(int i); };
It_886EBA80 *O_886EBA80::at(int i) { return &items[i]; }
