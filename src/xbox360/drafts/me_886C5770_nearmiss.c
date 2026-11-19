/* 0x886C5770 near miss (33 off, LTCG + pp1_pool_primer): remaps a range: to = to.lo + (x - from.lo)/(from.hi-from.lo)
 * * (to.hi - to.lo), denominator replaced by 1 when |d| == 0. Residue: game's abs select compares d itself against
 * zero (fcmpu d,0; fneg; table fsel); every abs spelling here either compares d-(-d) (max helper) or branches.
 * Zero in the game is g_ts4_event_value (0x8814B440); kZero lands in the pool instead. */
static const float kZero = 0.0f;
extern float __fres(float);
#pragma intrinsic(__fres)
typedef struct Range2 { float lo, hi; } Range2;
static __inline float sel_max(float a, float b) { return (a - b >= kZero) ? a : b; }
void ts4_range_remap(const Range2 *from, const Range2 *x, Range2 *to)
{
    float lo = from->lo;
    float d = from->hi - lo;
    float xl = x->lo - lo, xh = x->hi - lo;
    float tl = to->lo;
    float ad = sel_max(d, -d);
    float den = (-ad >= kZero) ? 1.0f : d;
    float inv = __fres(den); float k;
    inv = ((1.0f - inv*den) + 1.0f) * inv;
    k = inv * (to->hi - tl);
    to->hi = xh * k + tl;
    to->lo = xl * k + tl;
}
