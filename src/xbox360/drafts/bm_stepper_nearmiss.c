/* Ball flight stepper entry (Top Spin 4, Xbox 360), BM family. See docs/gameplay/gp4b.md section 4.2. */
#include "../bm_ball.h"

typedef struct ts4_bm_stepper ts4_bm_stepper;

void fn_889C1160(ts4_bm_stepper *s, ts4_bm_ball *b);
void fn_889C19F0(ts4_bm_stepper *s, ts4_bm_ball *b);
void fn_889C1F70(ts4_bm_stepper *s, ts4_bm_ball *b);
void fn_889C0FE8(ts4_bm_stepper *s, ts4_bm_ball *b);

/* Per-frame ball step: to-local, launch when requested, flight step unless frozen, to-world. Swing_DLL.xex 0x889C2818 */
void ts4_bm_ball_step_889C2818(ts4_bm_stepper *s, ts4_bm_ball *b)
{
    int run;
    if (b->enabled) {
        fn_889C1160(s, b);
        run = 1;
        if (b->new_shot) {
            fn_889C19F0(s, b);
            b->new_shot = 0;
            run = (b->frozen == 0);
        }
        if (run)
            fn_889C1F70(s, b);
        fn_889C0FE8(s, b);
    }
}
