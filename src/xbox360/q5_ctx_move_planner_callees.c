/* Q5 LTCG context for ts4_move_planner_transition_886B8468 (src/xbox360/q5_move_planner.c): real bodies of
 * the vector callees whose register use the planner relies on. The planner keeps vectors in volatile
 * v47/v50/v53/v58 across these calls, which the code generator only does when it has seen that the callees
 * (and fn_8867A7C0 below them, src/xbox360/q5_ctx_path_sample.c) leave those registers alone.
 * Compile with flags(/Ob1) so they stay calls. */
#include "w6b_types.h"

typedef struct Q5cAnim { unsigned char pad0[0x90]; __vector4 velocity; } Q5cAnim;
typedef struct Q5cPlayer { unsigned char pad0[0x78]; Q5cAnim *anim; } Q5cPlayer;

void fn_8867A7C0(Q5cPlayer *self, __vector4 *out, float t);

/* 0x8868ED00: *out = velocity + sum over i in 1..n-1 of (1 - i/n) * (path(i) - path(i-1)), path(0) = 0 */
void fn_8868ED00(Q5cPlayer *self, __vector4 *out, int n)
{
    *out = self->anim->velocity;
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
            fn_8867A7C0(self, &tmp, idx);
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

/* 0x8867A908: *out = velocity, plus the path sample at t when t > 0 */
void ts4_vec_with_offset_8867A908(Q5cPlayer *self, __vector4 *out, float t)
{
    *out = self->anim->velocity;
    if (t > q5c_zero) {
        fn_8867A7C0(self, out, t);
        *out = __vaddfp(*out, self->anim->velocity);
    }
}
