/* Q5: ticks until the predicted ball crosses a court x (Swing_DLL.xex 0x886600E0, 0x110 bytes).
 * Byte-matched on the LTCG route: work/specs/Q5/q5_prediction_ticks_until_x.json (context
 * src/xbox360/cl1_clrrwi_reload.c, whose first/last sample accessors the link inlines here).
 *
 * ts4_prediction_ticks_until_x_886600E0(pred, x): walks the prediction's samples from the first to (not
 * including) the last one and returns the tick, relative to the first sample, of the first sample that lies beyond
 * x in the ball's direction of travel along x (direction = sign of last.x - first.x); -1 when no sample does.
 * The movement planner (0x886B8468) calls it with the player's x to get the ticks until the ball is level with
 * the player.
 *
 * Codegen notes (cl 16.00.10224 PPC, /O2 /Oc /GL, LTCG):
 *  - both float sign tests read the high half-word of the stored difference (`lhz; rlwinm`), not a float compare;
 *  - `result = -1` + `break` gives the preloaded `li r3,-1`, the `beqlr` loop exits and one shared "found" tail;
 *  - x_last and x_first in separate locals give the target's evaluation order (last, then first). */
#include "gp2_types.h"

extern struct Gp2BallSample *ts4_last_record_8865A3E8(struct Gp2BallPrediction *pred);
extern struct Gp2BallSample *ts4_first_record_8865A410(struct Gp2BallPrediction *pred);

/* sign bit of a float, read from its high half-word */
static __inline int q5_negative16(float f) { return *(const unsigned short *)&f >> 15; }
static __inline int q5_sign_bit(float f) { return *(const unsigned short *)&f & 0x8000; }

int ts4_prediction_ticks_until_x_886600E0(struct Gp2BallPrediction *pred, float x)
{
    float x_last = ts4_last_record_8865A3E8(pred)->pos[0];
    float x_first = ts4_first_record_8865A410(pred)->pos[0];
    unsigned char descending = q5_negative16(x_last - x_first);
    struct Gp2BallSample *end = ts4_last_record_8865A3E8(pred);
    struct Gp2BallSample *it;
    int result = -1;
    if (descending) {
        for (it = ts4_first_record_8865A410(pred); it != end; it++) {
            if (q5_sign_bit(it->pos[0] - x)) {
                result = it->tick - ts4_first_record_8865A410(pred)->tick;
                break;
            }
        }
    } else {
        for (it = ts4_first_record_8865A410(pred); it != end; it++) {
            if (q5_sign_bit(x - it->pos[0])) {
                result = it->tick - ts4_first_record_8865A410(pred)->tick;
                break;
            }
        }
    }
    return result;
}
