/*
 * FP1: layer time warp (ts4_layer_time_warp_886D1408, described in drafts/gp7_engine_update.c). The clip time ratio
 * stretches the time elapsed since t_ref; the result is clamped to [base, limit].
 *
 * Float codegen (docs/agents/near-misses/FP1.md): default float model (fmadds), and a file-scope
 * `const float` zero. With a named zero constant in the translation unit the compiler compares
 * against it instead of a literal and if-converts both clamps into the +1/-1 table select
 * (fcmpu; mfcr; rlwinm LT/UN; lfsx; fsel). LTCG route; context fp1_pool_primer.c lays out the
 * module constant pool so the table sits at pool+0x68.
 */
static const float fp1_zero = 0.0f;

typedef struct Fp1ClipDesc {
    unsigned char pad00[0x14];
    float time_ratio;           /* +0x14 */
} Fp1ClipDesc;

typedef struct Fp1ClipRef {
    unsigned char pad00[0x08];
    Fp1ClipDesc *desc;          /* +0x08 */
} Fp1ClipRef;

typedef struct Fp1AnimLayer {
    unsigned char pad00[0x04];
    Fp1ClipRef *inner;          /* +0x04 */
    unsigned char pad08[0x14 - 0x08];
    float t_ref;                /* +0x14 */
    unsigned char pad18[0x24 - 0x18];
    float base;                 /* +0x24 */
    float limit;                /* +0x28 */
} Fp1AnimLayer;

/* fsel-style max/min: compare the difference with the named zero. */
static __inline float fp1_max(float a, float b) { return (a - b >= fp1_zero) ? a : b; }
static __inline float fp1_min(float a, float b) { return (a - b >= fp1_zero) ? b : a; }

/* Swing_DLL.xex 0x886D1408 */
float ts4_layer_time_warp_886D1408(Fp1AnimLayer *l, float t)
{
    float x = (t - l->t_ref) * (l->inner->desc->time_ratio - 1.0f) + l->base;
    return fp1_min(fp1_max(x, l->base), l->limit);
}
