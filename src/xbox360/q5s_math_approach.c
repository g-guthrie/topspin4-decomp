/*
 * 0x881A38F0: starts a float approach: stores from (twice: start and current) and to, sets the active flag,
 * and points the step's sign toward the target (|step| when to > from, -|step| when to < from, unchanged
 * when equal).
 *
 * Codegen: |x| is the `fcmpu; mfcr; rlwinm; rlwinm; or; lfsx {+1,-1}; fsel x,-x` table select from
 * `__fself(x - kZero, x, -x)` with a NAMED file-static zero (the target loads it from 0x8814B440). The `fneg`
 * of -x is computed before the compare, as in the target.
 */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float c, float x, float y) { return c >= 0.0f ? x : y; }
#endif

static const float q5s_approach_zero = 0.0f;

/* |x| as a speculated select */
static __inline float q5s_approach_abs(float x) { return __fself(x - q5s_approach_zero, x, -x); }

typedef struct Q5sApproach {
    char pad00[4];
    float start;            /* +0x04 */
    float target;           /* +0x08 */
    float current;          /* +0x0C */
    float step;             /* +0x10 sign follows the direction */
    unsigned char active;   /* +0x14 */
} Q5sApproach;

void ts4_approach_start_881A38F0(Q5sApproach *a, float from, float to)
{
    a->start = from;
    a->current = from;
    a->target = to;
    if (to > from) {
        a->active = 1;
        a->step = q5s_approach_abs(a->step);
    } else if (to < from) {
        a->active = 1;
        a->step = -q5s_approach_abs(a->step);
    } else {
        a->active = 1;
    }
}
