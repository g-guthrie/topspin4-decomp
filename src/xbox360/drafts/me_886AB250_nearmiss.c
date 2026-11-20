/* NEAR MISS (4 instructions): f30/f31 swapped between the direction and the zero constant (the game
 * keeps dir in f30, zero in f31). Tried declaration/assignment orders and compare forms. */
/* 0x886AB250: steps the ball simulation forward until the ball's vertical velocity turns against the
 * given direction and has dropped to the rest threshold (script constant 120), counting the steps on
 * the ball; gives up after 600 iterations. */
double fabs(double);
#pragma intrinsic(fabs)
typedef struct Ball { char p[0x18]; int steps; char p2[0x40 - 0x1c]; float vy; char p3[0x100 - 0x44]; float dir; } Ball;
typedef struct Sim Sim;
typedef struct Owner { char p[0x5dc]; Sim *sim; } Owner;
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
void fn_889C2818(Sim *s, Ball *b);
void f(Owner *o, Ball *b)
{
    float dir = b->dir;
    unsigned int i;
    float zero, thr;
    fn_889C2818(o->sim, b);
    zero = lbl_8814B440;
    thr = g_ts4_script_constants[120];
    for (i = 1; (b->vy * dir > zero || fabs(b->vy) < thr) && i < 600; i++) {
        b->steps++;
        fn_889C2818(o->sim, b);
    }
}
