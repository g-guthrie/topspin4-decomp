/* 0x8890F008: true when t lies in [lo, hi] and x is inside the scaled range built from v. */
typedef unsigned char u8;
typedef struct { float v[3]; float lo, hi; } Ts4ScaledRange;
u8 ts4_range_contains_scaled_8890E300(const float *v, const float *x);
static u8 in_window(Ts4ScaledRange *r, float t) { return t >= r->lo && t <= r->hi; }
u8 ts4_window_and_range_contains_8890F008(Ts4ScaledRange *r, const float *x, float t)
{
    return in_window(r, t) && ts4_range_contains_scaled_8890E300(r->v, x);
}
