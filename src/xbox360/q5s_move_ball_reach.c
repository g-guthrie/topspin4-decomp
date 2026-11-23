/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): movement planner, "can the player reach the predicted ball in time".
 * LTCG unit, /Oc. Callers: MovePlanner NextState 0x886B8468 (through 0x88678708).
 */
#include "include/ts4/ts4.h"

extern float g_ts4_event_value;          /* 0.0f (BINKCONS 0x8814B440), written into the y lane */
extern float g_ts4_script_constants[];   /* +0x2B8: maximum ball height for a reachable sample */

/* Probe passed by the planner: frame budget and two radii. */
typedef struct Q5sReachProbe {
    float max_frames;                    /* +0x0 frames from now the sample must be within */
    float radius;                        /* +0x4 horizontal radius used against the prediction */
    float radius_now;                    /* +0x8 radius used against the current target (0x88678708) */
} Q5sReachProbe;

/* 0x886601F0: walks the ball prediction's samples and returns the tick, relative to the first sample, of the first
 * sample whose horizontal (x/z, y lane zeroed) distance to *pos is below radius and whose height is below the script
 * constant at +0x2B8; -1 when no sample qualifies. Each sample is copied to the stack (vector + four doublewords). */
int ts4_prediction_ticks_until_near_886601F0(Ts4BallPrediction *pred, const __vector4 *pos, float radius)
{
    float r2 = radius * radius;
    Ts4BallSample *it;
    int result = -1;
    for (it = pred->samples_begin; it != pred->samples_end; it++) {
        Ts4BallSample s = *it;
        __vector4 d, m;
        d = __vsubfp(*pos, s.pos.v);
        d = __vrlimi(d, __lvlx(&g_ts4_event_value, 0), 4, 3);
        m = __vmsum3fp(d, d);
        if (m.v[0] < r2 && s.pos.f[1] < g_ts4_script_constants[0x2B8 / 4]) {
            result = s.tick - pred->samples_begin->tick;
            break;
        }
    }
    return result;
}

/* 0x8866BC48: 1 when the match's ball prediction has a sample near the player's position (radius p->radius, see
 * 0x886601F0) whose tick is less than p->max_frames frames after the current match frame; 0 otherwise (also when
 * the prediction is empty). */
unsigned char ts4_planner_ball_reachable_in_time_8866BC48(Ts4MovePlanner *self, const Q5sReachProbe *p)
{
    Ts4Player *pl = self->player;
    Ts4Match *m = pl->match;
    Ts4BallPrediction *pred = m->balls->prediction;
    Ts4BallSample *begin = pred->samples_begin;
    unsigned char r = 0;
    if (begin != pred->samples_end) {
        __vector4 here;
        int i = ts4_prediction_ticks_until_near_886601F0(pred, ts4_if_get_u32_off4c_8865EC70(&here, pl), p->radius);
        if (i != -1)
            r = (float)(begin[i].tick - m->flow->frame) < p->max_frames;
    }
    return r;
}
