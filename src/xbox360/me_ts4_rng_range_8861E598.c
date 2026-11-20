/* Swing_DLL.xex 0x8861E598: xorshift + LCG random float in [lo, hi]. */
typedef unsigned int ts4_u32;
struct Ts4Rng { ts4_u32 pad_00; ts4_u32 xs; ts4_u32 lcg; };
static const float kZero = 0.0f;
static __inline float ts4_rng_max(float a, float b) { return (a - b >= kZero) ? a : b; }
static __inline float ts4_rng_min(float a, float b) { return (a - b >= kZero) ? b : a; }
float ts4_rng_range_8861E598(struct Ts4Rng *r, float lo, float hi)
{
    ts4_u32 x = r->xs;
    ts4_u32 l;
    float u;
    float d = hi - lo;
    x ^= x >> 15;
    l = r->lcg * 0x10DCD;
    r->lcg = l;
    x ^= x << 17;
    r->xs = x;
    u = (float)(l ^ x) * 2.3283064e-10f;
    u = ts4_rng_min(ts4_rng_max(u, kZero), 1.0f);
    return u * d + lo;
}
