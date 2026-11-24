/* Q5: the two path getters of the movement planner (Swing_DLL.xex 0x8868ED00, 0x8867A908), byte-matched on the
 * LTCG route (work/specs/Q5/q5_path_getters.json) with the real ts4_path_sample_8867A7C0
 * (src/xbox360/q5_path_sample.cpp) in the link.
 *
 * Also the LTCG context for ts4_move_planner_transition_886B8468: the planner keeps vectors in volatile
 * v47/v50/v53/v58 across these calls, which the code generator only does when it has seen that the callees (and
 * the sampler below them) leave those registers alone. Compile with flags(/Ob1) so they stay calls.
 *
 * These stay C: compiled as C++ the accumulation in 0x8868ED00 is fused early (`vmaddfp v0,v0,v13,v12` on
 * volatile v0/v12/v13) instead of the target's late `vmaddfp128 v56,v61,v59`. */
#include "w6b_types.h"

typedef struct Q5cPathState { unsigned char pad0[0x90]; __vector4 position; } Q5cPathState;
typedef struct Q5cPlayer { unsigned char pad0[0x78]; Q5cPathState *state; } Q5cPlayer;

/* displacement along the recorded path at the fractional tick t (src/xbox360/q5_path_sample.cpp) */
void ts4_path_sample_8867A7C0(const Q5cPlayer *self, __vector4 *out, float t);

/* 0x8868ED00: *out = position + sum over i in 1..n-1 of (1 - i/n) * (d(i) - d(i-1)), d = path displacement,
 * d(0) = 0: the position n ticks ahead with the path steps weighted down linearly */
void ts4_path_weighted_ahead_8868ED00(const Q5cPlayer *self, __vector4 *out, int n)
{
    *out = self->state->position;
    if (n > 0) {
        float one = 1.0f;
        float inv = one / (float)n;
        float idx = one;
        float w = one;
        __vector4 prev = __vspltisw(0);
        int i;
        for (i = 1; i < n; i++) {
            __vector4 tmp;
            __vector4 cur;
            w = w - inv;
            ts4_path_sample_8867A7C0(self, &tmp, idx);
            cur = tmp;
            {
                __vector4 l = __vmulfp(__vsubfp(cur, prev), vx1_replicate(w));
                prev = cur;
                *out = __vaddfp(*out, l);
            }
            idx = idx + one;
        }
    }
}

static const float q5c_zero = 0.0f;

/* 0x8867A908: *out = position, plus the path displacement at t when t > 0 */
void ts4_vec_with_offset_8867A908(const Q5cPlayer *self, __vector4 *out, float t)
{
    *out = self->state->position;
    if (t > q5c_zero) {
        ts4_path_sample_8867A7C0(self, out, t);
        *out = __vaddfp(*out, self->state->position);
    }
}
