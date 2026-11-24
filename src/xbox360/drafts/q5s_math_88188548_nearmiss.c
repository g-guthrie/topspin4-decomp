/* nearmiss: 64 off (LTCG, primer context); blocker: the abs is the open mfcr/lfsx/fsel table-select shape
 * (matching-tips "abs as an mfcr/lfsx table select", 0x889C1C80): the target compares d = a[i] - b[i] directly
 * against the extern zero (g_ts4_event_value) and picks d or fneg(d) from the {+1,-1} table at constants+0x68.
 * (d >= kZero) ? d : -d, (a - b >= kZero) ? a - b : -(a - b) and (d - kZero >= kZero) ? d : n with a static or
 * extern zero all stay branches. Odds improve once that abs shape is found for 0x889C1C80; this one then
 * follows (same 4-lane early-out chain). */
/* 0x88188548: true when |a[i] - b[i]| < eps for all four lanes (early out at the first lane that fails). */
extern const float g_ts4_event_value;
#define kZero g_ts4_event_value
static __inline float q_absd(float a, float b) { float d = a - b; return (d >= kZero) ? d : -d; }
unsigned char ts4_vec4_near_equal_88188548(const float *a, const float *b, float eps)
{
    return q_absd(a[0], b[0]) < eps && q_absd(a[1], b[1]) < eps && q_absd(a[2], b[2]) < eps &&
           q_absd(a[3], b[3]) < eps;
}
