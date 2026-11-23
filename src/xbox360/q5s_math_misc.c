/*
 * Small math helpers (Swing_DLL.xex), LTCG route with the pool primer, /Oc.
 *
 * 0x881C5BD8: derives two counts from a count and two ratios; the second count is zeroed below 17.
 *   Only caller 0x881FBD30 stores the count (+0x1C) and then calls it. Field meaning unknown, so the
 *   struct stays private and minimal (no shared type covers it yet).
 *   Codegen: (float)unsigned -> std/lfd/fcfid with no extsw; (unsigned)float -> fctidz + stfd/lwz.
 *   The +0x2C store comes before +0x30 in the target, so ratio_b is converted first.
 *
 * 0x881CD128: unpacks a packed 32-bit ARGB colour passed by value in r4 (bytes in memory A,R,G,B)
 *   into four floats {r, g, b, a} * (1/255) (pool +0x44). Statement order r, g, b, a gives the
 *   target's lbz order and store order.
 */

typedef struct Q5sRatioCounts {
    char pad00[0x1c];
    unsigned int count;      /* +0x1C written by 0x881FBD30 before the call */
    char pad20[4];
    float ratio_a;           /* +0x24 */
    float ratio_b;           /* +0x28 */
    unsigned int n_b;        /* +0x2C = ratio_b * count */
    unsigned int n_a;        /* +0x30 = ratio_a * count, 0 when below 17 */
} Q5sRatioCounts;

void ts4_ratio_counts_update_881C5BD8(Q5sRatioCounts *o)
{
    float n = (float)o->count;
    o->n_b = (unsigned int)(o->ratio_b * n);
    o->n_a = (unsigned int)(o->ratio_a * n);
    if (o->n_a < 17)
        o->n_a = 0;
}

typedef struct Q5sArgb8 { unsigned char a, r, g, b; } Q5sArgb8;
typedef struct Q5sColorF { float r, g, b, a; } Q5sColorF;

void ts4_color_argb8_to_float_881CD128(Q5sColorF *out, Q5sArgb8 c)
{
    out->r = (float)c.r * 0.003921568859368563f;
    out->g = (float)c.g * 0.003921568859368563f;
    out->b = (float)c.b * 0.003921568859368563f;
    out->a = (float)c.a * 0.003921568859368563f;
}
