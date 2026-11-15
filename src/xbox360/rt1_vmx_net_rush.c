/*
 * RT1: Repositioning_HumanMode, the human net-rush rule (docs/gameplay/repositioning.md s3.1).
 *
 * For a human team: mode 0 at the net (LocalPosition.x > -at_net_depth) or with the move stick
 * released (power < 0.1). Otherwise mode 2 (go to the net) when the stick angle is within
 * max_stick_angle_deg of the direction to the net point, the net point is farther than
 * min_net_distance, and either the player is in the baseline box (outside play mode 1) or RB
 * (@ReqFastRepos) is held. A new mode 2 is refused while the next hitter's planned hit is fewer
 * than hit_lead_frames away. Then fn_8868C218 raises the behaviour flags, and S+0xA2D records
 * whether a repositioning mode is active.
 *
 * Verdict: compiling, unverified. The original uses VMX128 (vector LocalPosition copies, the
 * net-point difference and its vmsum3fp length), so tools/fn_equiv.py reports UNCHECKED (vmx).
 * See work/army/RT1.failed.md.
 */
#include "rt1_types.h"

extern const float lbl_8814B440;              /* 0.0f */
extern const float g_ts4_script_constants[];  /* +0x184 pi/180, +0x2AC 0.1 */
#define RT1_K(off) g_ts4_script_constants[(off) / 4]

/* PlayerCtx_LocalToWorld: LocalPosition to world (r4 = pc is left intact for the caller). */
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, struct Rt1PlayerCtxR *pc);
double fn_88564BF8(double y, double x);       /* atan2 */
void fn_8817B608(float *angle);               /* wrap to [-pi, pi) */
/* Match_NextHitterPlannedFrame. */
ts4_bool fn_8865EF98(struct Rt1MatchR *match, int *frame_out);
/* Repositioning_BehaviorFlags. */
void fn_8868C218(struct Rt1Repositioning *r, int mode);

#ifdef _MSC_VER
double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

/* Swing_DLL.xex 0x8869B928 */
void ts4_repositioning_human_mode_8869B928(struct Rt1Repositioning *r)
{
    struct Rt1PlayerCtxR *pc = r->pc;
    const struct Rt1ReposPointSettings *set = &pc->world->settings->repos;

    if (pc->team->human) {
        struct Rt1PlayerStateR *s = pc->state;
        int prev = r->mode;
        float stick_angle;
        ts4_bool at_net;
        __vector4 local = s->local_position;

        at_net = local.v[0] > -set->at_net_depth;
        stick_angle = s->stick_move_angle;
        if (s->move_power < RT1_K(0x2AC) || at_net) {
            r->mode = 0;
        } else {
            ts4_bool in_box, aligned, far, rb;
            __vector4 world, to_net;
            float angle, diff;
            int frame;

            r->mode = 0;
            local = pc->state->local_position;
            in_box = local.v[0] < set->box_x_max && local.v[2] < set->box_z_max &&
                     local.v[0] > set->box_x_min && local.v[2] > set->box_z_min;
            ts4_if_get_u32_off4c_8865EC70(&world, pc);
            to_net = __vsubfp(r->net_point, world);
            angle = (float)fn_88564BF8(to_net.v[2], to_net.v[0]);
            fn_8817B608(&angle);
            diff = stick_angle - angle;
            fn_8817B608(&diff);
            aligned = fabs(diff) < set->max_stick_angle_deg * RT1_K(0x184);
            {
                __vector4 dist_sq = __vmsum3fp(to_net, to_net);
                far = dist_sq.v[0] > set->min_net_distance * set->min_net_distance;
            }

            pc = r->pc;
            rb = pc->state->req_fast_repos;
            if (aligned && (float)far != lbl_8814B440) {
                if ((in_box && pc->match->mode->kind != 1) || rb)
                    r->mode = 2;
            }
            if (r->mode != prev && r->mode == 2) {
                struct Rt1MatchR *match = pc->match;
                if (fn_8865EF98(match, &frame) &&
                    (ts4_u32)(frame - match->flow->frame) < pc->world->settings->hit_lead_frames)
                    r->mode = prev;
            }
        }
        fn_8868C218(r, r->mode);
    }
    r->pc->state->repositioning_active = r->mode != 0;
}
