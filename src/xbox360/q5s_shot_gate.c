/* Shot subsystem (q5s): hold gate of the shot-setup stepper. LTCG route, /Oc. */
extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif

typedef struct Q5sGatePos {
    char pad_00[8];
    float dist;                                  /* +0x08 */
    float angle;                                 /* +0x0C */
} Q5sGatePos;
typedef struct Q5sGateCount {
    char pad_00[0xc];
    int count;                                   /* +0x0C consecutive frames inside the gate */
} Q5sGateCount;
typedef struct Q5sGate {
    char pad_00[0x20];
    Q5sGatePos *pos;                             /* +0x20 */
    char pad_24[4];
    Q5sGateCount *out;                           /* +0x28 */
} Q5sGate;
/* 0x10-byte gate records at stepper ranges + 0x30 / 0x50 / 0x60 (callers 0x88681848, 0x88681958). */
typedef struct Q5sGateRange {
    float min_dist;                              /* +0x00 */
    float angle;                                 /* +0x04 */
    float angle_tol;                             /* +0x08 */
    int frames;                                  /* +0x0C */
} Q5sGateRange;

void ts4_angle_wrap_pi_8817B608(float *angle);

/* Swing_DLL.xex 0x88672750: true once the position has stayed at least min_dist out and within angle_tol of
 * the gate angle (difference wrapped to [-pi, pi]) for `frames` consecutive calls; leaving the distance band
 * resets the counter. */
unsigned char ts4_gate_hold_88672750(Q5sGate *self, Q5sGateRange *r)
{
    Q5sGatePos *p = self->pos;
    unsigned char ok = r->min_dist <= p->dist;
    float d;
    if (ok) {
        d = p->angle - r->angle;
        ts4_angle_wrap_pi_8817B608(&d);
        ok = fabs(d) < r->angle_tol;
        if (ok)
            ok = ++self->out->count >= r->frames;
    } else {
        self->out->count = 0;
    }
    return ok;
}
