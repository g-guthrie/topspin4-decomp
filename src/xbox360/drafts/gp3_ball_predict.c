/*
 * GP3 DRAFT: ball prediction (fn_886AD278) and ball stepper entry (fn_889C2818 + helpers).
 *
 *   fn_886AD278 (0x4D0 B)  predict the ball path by running the real ball stepper on a copy of the ball state
 *   fn_8867B2D8 (0x278 B)  fill the ball event frame table from the prediction
 *   fn_889C2818 (0x094 B)  one stepper tick on a ball state (also used for the real ball once per frame)
 *   fn_889C1160/fn_889C0FE8 (0x174 B each)  to/from the scaled local frame
 *
 * STATUS: behaviour documented from the disassembly (gp3.md sections 2-3). fn_889C2818 is small enough to be
 * matched later; it is written here as a readable draft. VMX-heavy parts are summarised with comments.
 */
#include "../gp3_types.h"

struct Gp3Stepper {
    gp3_u8 pad0[0x1C];
    float  tick_scale_1c;      /* +0x1C used for (pos - prev) * scale and duration conversion */
    gp3_u8 pad20[0x14];
    void  *traj_gen_34;        /* +0x34 trajectory generator A (ts4_bm_ball_arc1_position_888AB558) */
    void  *traj_gen_38;        /* +0x38 trajectory generator B (ts4_bm_ball_arc2_position_888AD1C8) */
    gp3_u32 shot_table_3c;     /* +0x3C base of the shot template table */
    gp3_u8 in_local_frame;     /* +0x40 toggled by fn_889C1160 / fn_889C0FE8 */
    gp3_u8 pad41;
    gp3_u8 flag_42;
};

void fn_889C1160(struct Gp3Stepper *s, struct Gp3BallState *b);   /* world -> local frame:  v = (v - origin) * scale */
void fn_889C0FE8(struct Gp3Stepper *s, struct Gp3BallState *b);   /* local -> world frame */
void fn_889C19F0(struct Gp3Stepper *s, struct Gp3BallState *b);   /* launch from the shot template */
void fn_889C1F70(struct Gp3Stepper *s, struct Gp3BallState *b);   /* per-tick flight / bounce (0x704 B) */

/* Swing_DLL.xex 0x889C2818: advance the ball by one tick. */
void gp3_ball_step_889C2818(struct Gp3Stepper *stepper, struct Gp3BallState *ball)
{
    if (!ball->enabled) {
        return;
    }
    fn_889C1160(stepper, ball);
    {
        int launch_done = 1;                     /* r11 in the original: stays 1 unless a launch was pending */
        if (ball->new_shot) {
            fn_889C19F0(stepper, ball);
            ball->new_shot = 0;
            launch_done = (ball->flag_4e0 == 0);
        }
        if (launch_done) {
            fn_889C1F70(stepper, ball);
        }
    }
    fn_889C0FE8(stepper, ball);
}

/* Swing_DLL.xex 0x886AD278 (summary in C). `pred` = world+0x24 object: samples at +0x5A0 (begin) / +0x5A4 (end),
 * stepper at +0x5DC, summary fields at +0x40/+0x44 (speeds m/s), +0x50..+0x5C (segment tick indices), +0x7C (difficulty). */
void gp3_predict_ball_886AD278(void *pred, void *inst, const struct Gp3BallState *ball, int keep_mode, int full)
{
    struct Gp3BallState sim;                     /* memcpy(&sim, ball, 0x540) */
    int i;

    (void)pred; (void)inst; (void)keep_mode; (void)full; (void)i; (void)sim; (void)ball;
    /*
     *   if (!keep_mode) { if (sim.mode == LET_IN) mode = 0x9EA301C2, clear flags a1..a3;
     *                      if (sim.mode == LET_OUT) mode = 0x5D25ED1D, clear flags a1..a3; }
     *   fn_889C2818(stepper, &sim);                       // first tick (also performs the launch when new_shot)
     *   pred.speed0 = sqrt(|sim.v570|^2) * 0.6f; pred.speed1 = sqrt(|sim.v580|^2) * 0.6f;
     *   for (i = 0; i < 600 && sim.bounce_count < 2 && sim.mode not Net/Out; i++) {
     *       sample[i].pos  = sim.pos;           // +0x00
     *       sample[i].v    = sim.v560;          // +0x10
     *       sample[i].f20  = sim.f100;          // +0x20
     *       sample[i].tick = sim.tick + base;   // +0x24 (base = ball.launch_frame)
     *       sample[i].bounce = segment;         // +0x28: 0 before 1st bounce, 1 between, 2 after
     *       segment bookkeeping at pred+0x1E4+12*seg = {first, last, 0.0f}, pred+0x5B4+12*seg = height extremum
     *       fn_889C2818(stepper, &sim);
     *   }
     *   pred.sample_end = sample + i;  pred.last_tick = sim.tick + base - 1;   // +0x5A4 / +0x5C
     *   pred.snapshots at +0x5E0/+0x5F0/+0x600 = sim vectors at three marked ticks;
     *   if (full) fn_886AB250(pred, &sim);            // per-sample difficulty (+0x7C)
     */
}
