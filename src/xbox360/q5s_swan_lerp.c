/*
 * Q5S swan: swing animation engine, small float/vector helpers (LTCG route, /Oc).
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_swan_lerp.c <name>=<addr> --flags /Oc --auto-context
 */
#include "vx1_vector.h"

/* Rate block of a clip channel: four reciprocals rebuilt from four durations. */
typedef struct Q5sRateBlock {
    float inv[4];               /* +0x00 1/d0, -1/d1, 1/d2, 1/d3 */
    float f_10;                 /* +0x10 */
    float d0;                   /* +0x14 */
    float d2;                   /* +0x18 */
    float d1;                   /* +0x1c */
    float d3;                   /* +0x20 */
} Q5sRateBlock;

typedef struct Q5sRateOwner {
    unsigned char pad_00[0x18];
    Q5sRateBlock *rates;        /* +0x18 */
} Q5sRateOwner;

/* Swing_DLL.xex 0x886C4540: refresh the reciprocals of the rate block (the second one negated).
 * Each statement goes through o->rates again: the stores then act as alias barriers and the
 * loads stay below them as in the target. */
void ts4_rate_block_refresh_inverses_886C4540(Q5sRateOwner *o)
{
    { Q5sRateBlock *r = o->rates; r->inv[0] = 1.0f / o->rates->d0; }
    o->rates->inv[1] = -1.0f / o->rates->d1;
    o->rates->inv[2] = 1.0f / o->rates->d2;
    o->rates->inv[3] = 1.0f / o->rates->d3;
}

/* Two time ranges; the overlap test reads x/y at +8/+0xc, this function the pair at +0/+4. */
typedef struct Q5sSpan {
    float lo;                   /* +0x00 */
    float hi;                   /* +0x04 */
    float x;                    /* +0x08 */
    float y;                    /* +0x0c */
} Q5sSpan;

extern int ts4_rect_overlap_project_886C9110(Q5sSpan *a, Q5sSpan *b, float *out1, float *out2);

/* seg[0], seg[1] := lerp(seg[0], seg[1], t[0]), lerp(seg[0], seg[1], t[1]) */
static __inline void q5s_lerp_segment(__vector4 *seg, const float *t)
{
    __vector4 p0 = seg[0];
    __vector4 d = __vsubfp(seg[1], p0);
    seg[0] = __vmaddfp(__vspltw(__lvlx(t, 0), 0), d, p0);
    seg[1] = __vmaddfp(__vspltw(__lvlx(t + 1, 0), 0), d, p0);
}

/* Swing_DLL.xex 0x886CE940: project the overlap of spans a and b to parameters t1/t2; if they
 * overlap and b starts no later than a ends, trim both segments to the overlap and return 1. */
int ts4_trim_segments_to_overlap_886CE940(Q5sSpan *a, Q5sSpan *b, __vector4 *seg1, __vector4 *seg2,
                                           float *t1, float *t2)
{
    int hit = 0;
    if ((unsigned char)ts4_rect_overlap_project_886C9110(a, b, t1, t2)) {
        if (!(b->lo > a->hi)) {
            q5s_lerp_segment(seg1, t1);
            q5s_lerp_segment(seg2, t2);
            hit = 1;
        }
    }
    return hit;
}
