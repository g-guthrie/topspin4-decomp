/* nearmiss: 2 off (LTCG /Oc, pool primer); the lfs *x and lfs r->lo loads are swapped (target loads *x first). C++ const member form gives the same 2 off. */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float c, float x, float y) { return c >= 0.0f ? x : y; }
#endif
static const float kz = 0.0f;
static __inline float sel(float c, float x, float y) { return __fself(c - kz, x, y); }
static __inline float mx(float a, float b) { return sel(a - b, a, b); }
static __inline float mn(float a, float b) { return sel(a - b, b, a); }
typedef struct { float lo; float hi; } Range;
void ts4_input_clamp_to_range_8890E1C8(Range *r, float *x)
{
    float v = *x; float lo = r->lo; float m = sel(v - lo, v, lo); *x = sel(m - r->hi, r->hi, m);
}
