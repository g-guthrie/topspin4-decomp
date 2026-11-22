/* Q5 equivalent route: shaper apply over a begin/end point vector (Swing_DLL.xex 0x88649C10),
 * sister of ts4_shaper_apply_rel_88649298 in eq_q5_gameplay_small_c.c.
 * Stores gain/active, shapes the 12-byte points (0x88646658), multiplies by the key
 * curve (0x886491E8), then finalises with 0x88644DE0(s, gain, 1).
 * Not byte-matched: under LTCG the target keeps `gain` in volatile f1 across the first two
 * calls; plain C spills it to f31. Proven by tools/fn_equiv.py (see the spec's evidence). */
#include "vx1_vector.h"

struct W8dRel_886491E8 { int off; int count; };
typedef struct Q5Pt3 { float x, y, z; } Q5Pt3;
typedef struct Q5Pt3Vec { Q5Pt3 *begin; Q5Pt3 *end; } Q5Pt3Vec;
typedef struct Q5Shaper { char p[0x20]; unsigned char active; char p21[3]; float gain; } Q5Shaper;
extern void fn_88646658(Q5Shaper *s, void *src, Q5Pt3 *pts, int count, float gain);
extern void ts4_multiply_by_keys_886491E8(Q5Shaper *s, struct W8dRel_886491E8 *keys);
extern void fn_88644DE0(Q5Shaper *s, float gain, int flag);

/* Swing_DLL.xex 0x88649C10 */
void ts4_shaper_apply_88649C10(Q5Shaper *s, void *src, Q5Pt3Vec *pts,
                               struct W8dRel_886491E8 *keys, float gain)
{
    s->gain = gain;
    s->active = 1;
    fn_88646658(s, src, pts->begin, (int)(pts->end - pts->begin), gain);
    ts4_multiply_by_keys_886491E8(s, keys);
    fn_88644DE0(s, gain, 1);
}
