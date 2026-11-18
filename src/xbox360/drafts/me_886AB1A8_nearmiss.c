/* agentA2 2026-11-18: still 2 best; for-loop early return (36), int settled (34), comma init (15), bool C++ (6), int i<600 (3), constant inline (39). */
/* NEAR MISS (2 instructions): the two zero initialisations (loop count r30, settled flag r11) are
 * emitted in the opposite order. Tried every declaration/assignment order of the three locals. */
/* 0x886AB1A8: steps the ball simulation until the ball's vertical speed drops under the settle
 * threshold (script constant 60), counting the steps on the ball. Returns the step count, or INT_MAX
 * when the ball has not settled after 600 iterations. */
double fabs(double);
#pragma intrinsic(fabs)
typedef struct Ball { char p[0x18]; int steps; char p2[0x40 - 0x1c]; float vy; } Ball;
typedef struct Sim Sim;
typedef struct Owner { char p[0x5dc]; Sim *sim; } Owner;
extern float g_ts4_script_constants[];
void fn_889C2818(Sim *s, Ball *b);
int f(Owner *o, Ball *b)
{
    unsigned char settled = 0;
    float thr = g_ts4_script_constants[60];
    unsigned int i = 0;
    while (!settled && i < 600u) {
        b->steps++;
        i++;
        fn_889C2818(o->sim, b);
        settled = fabs(b->vy) < thr;
    }
    if (settled) return b->steps;
    return 0x7fffffff;
}
