/* nearmiss: 2 off (q5s batch 2); also tried as a C++ const member Range::InRange(const float&): an Angle ctor that wraps, an operator float, an inline Contains(float / const float& / const Angle&), Between(t,lo,hi), a local lo and a const-ref t. All stay at 2 (lfs lo is still after lfs wrapped). Blocker: unknown; possibly fn_8817B608 returns the angle or is a member of a class with a different layout. */
/* agAO near-miss (2 off, /Oc): 0x8890DF58 wraps (x - ref) with fn_8817B608 and tests whether the result is in
 * [lo, hi]. This is the callee of the scaled-range test 8890E300.
 * Remaining diff: the target loads r->lo (f11) before the wrapped value (f0). We load them in the opposite order.
 * Also tried: inline helpers, `r->lo <= t`, a local `lo`, and /Os. */
typedef unsigned char u8;
typedef struct Ga3Angle { float v; } Ga3Angle;
void fn_8817B608(Ga3Angle *angle);
typedef struct { float lo, hi, ref; } Cx33Range;
u8 ts4_wrapped_offset_in_range_8890DF58(Cx33Range *r, const float *x)
{
    Ga3Angle a;
    a.v = *x - r->ref;
    fn_8817B608(&a);
    return a.v >= r->lo && a.v <= r->hi;
}
