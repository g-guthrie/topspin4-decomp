/* me_88649C10 near-miss: 26 off (LTCG, ctx src/xbox360/w8d_b.c). Shaper apply: store gain/active, run
   fn_88646658 over the 12-byte point vector, ts4_multiply_by_keys_886491E8, then fn_88644DE0(s, gain, 1).
   BLOCKED: the target keeps `gain` in volatile f1 across the 0x88646658 and 0x886491E8 calls (LTCG knowledge of
   the callees). 0x886491E8 is in w8d_b.c, but 0x88646658 has no source yet; until it does we spill to f31.
   (The dead `fmr f13,f1` likely comes from 0x88646658's inlined/known register use.) 1 variant. */
#include "vx1_vector.h"
struct W8dRel_886491E8 { int off; int count; };
struct W8dC1c_886491E8 { int x; };
struct W8dO_886491E8 { char pad[0x1c]; struct W8dC1c_886491E8 *p1c; };
typedef struct Pt3 { float x, y, z; } Pt3;
typedef struct Pt3Vec { Pt3 *begin; Pt3 *end; } Pt3Vec;
typedef struct Shaper { char p[0x20]; unsigned char active; char p21[3]; float gain; } Shaper;
extern void fn_88646658(Shaper *s, void *src, Pt3 *pts, int count, float gain);
extern void ts4_multiply_by_keys_886491E8(Shaper *s, struct W8dRel_886491E8 *keys);
extern void fn_88644DE0(Shaper *s, float gain, int flag);

void fn_88649C10(Shaper *s, void *src, Pt3Vec *pts, struct W8dRel_886491E8 *keys, float gain)
{
    s->gain = gain;
    s->active = 1;
    fn_88646658(s, src, pts->begin, pts->end - pts->begin, gain);
    ts4_multiply_by_keys_886491E8(s, keys);
    fn_88644DE0(s, gain, 1);
}
