/* Q5: the movement planner's "swing committed" latch (Swing_DLL.xex 0x8866BD00, 0xD4 bytes).
 * Byte-matched on the LTCG route: work/specs/Q5/q5_planner_commit.json (contexts cl1_clrrwi_reload.c and
 * q5_prediction_ticks_until_x.c: the link knows 0x886600E0 leaves r4 alone, so `pred` stays in r4 across the call).
 *
 * ts4_planner_update_committed_8866BD00(planner): while planner+0x120 is clear, sets it once the ball sample the
 * player is heading for (player->actor+0xBC8 into the ball prediction) is less than player->tuning+0x25C frames
 * away. Otherwise it asks the player's shot prediction (player+0xB4 -> +0x88) for the first sample beyond the
 * player's x (0x886600E0) and latches on that sample's frame instead. Planner states 12 and 16 call it each tick
 * (docs/gameplay/movement-and-ai.md); while the flag is set they stop re-searching the swing profile.
 *
 * Codegen notes (cl 16.00.10224 PPC, /O2 /Oc /GL, LTCG):
 *  - `unsigned char ok = a - b < c` gives the branchless signed compare (subfc/eqv/srwi/addze, clrlwi 31) and the
 *    `mulli 0x30` sample indexing; an `int` flag or an inline helper turns the index into shifts;
 *  - x read into a local before the prediction pointer gives the target's call order. */
#include "vx1_vector.h"
#include "gp2_types.h"

typedef struct Q5Clock { unsigned char pad0[0x310]; int frame; } Q5Clock;
typedef struct Q5BallSys { unsigned char pad0[0x24]; struct Gp2BallPrediction *prediction; } Q5BallSys;
typedef struct Q5World {
    unsigned char pad0[0x30];
    Q5Clock *clock;             /* +0x30 */
    unsigned char pad34[0x5c - 0x34];
    Q5BallSys *balls;           /* +0x5c */
} Q5World;
typedef struct Q5Tuning { unsigned char pad0[0x25c]; int lead_frames; } Q5Tuning;
typedef struct Q5Actor { unsigned char pad0[0xbc8]; int sample_index; } Q5Actor;
typedef struct Q5Shot { unsigned char pad0[0x88]; struct Gp2BallPrediction *prediction; } Q5Shot;
typedef struct Q5Player {
    unsigned char pad0[0x2c];
    Q5Tuning *tuning;           /* +0x2c */
    unsigned char pad30[0x48 - 0x30];
    Q5World *world;             /* +0x48 */
    unsigned char pad4c[0x74 - 0x4c];
    Q5Actor *actor;             /* +0x74 */
    unsigned char pad78[0xb4 - 0x78];
    Q5Shot *shot;               /* +0xb4 */
} Q5Player;
typedef struct Q5Planner {
    unsigned char pad0[0x120];
    unsigned char committed;    /* +0x120 */
    unsigned char pad121[0x154 - 0x121];
    Q5Player *player;           /* +0x154 */
} Q5Planner;

/* the player's world position (written to *out, returned) */
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, Q5Player *p);
/* ticks until the predicted ball passes x, -1 if never (src/xbox360/q5_prediction_ticks_until_x.c) */
int ts4_prediction_ticks_until_x_886600E0(struct Gp2BallPrediction *pred, float x);

void ts4_planner_update_committed_8866BD00(Q5Planner *s)
{
    if (!s->committed) {
        Q5Player *p = s->player;
        int lead = p->tuning->lead_frames;
        int now = p->world->clock->frame;
        unsigned char ok = p->world->balls->prediction->samples_begin[p->actor->sample_index].tick - now < lead;
        if (!ok) {
            __vector4 here;
            float x = ts4_if_get_u32_off4c_8865EC70(&here, p)->v[0];
            struct Gp2BallPrediction *pred = p->shot->prediction;
            int i = ts4_prediction_ticks_until_x_886600E0(pred, x);
            if (i != -1)
                ok = pred->samples_begin[i].tick - now < lead;
        }
        s->committed = ok;
    }
}
