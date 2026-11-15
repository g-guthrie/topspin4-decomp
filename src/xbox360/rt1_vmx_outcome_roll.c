/*
 * RT1: the outcome roll (docs/gameplay/gp4b.md s10, gp8.md; models
 * src/xbox360/drafts/gp8_shot_error_model.c and ref/gameplay/ball.c).
 *
 * Decides In / Out / Net / Let for one planned shot before launch and moves the landing target
 * to match:
 *   P = clamp01(FaultProbability + error_bonus) (AI serve: the AI record's serve fault probability,
 *   and its serve efficiencies are copied to AimingState); roll1, roll2; run the LetProbability
 *   analyser; roll3.
 *   gate   = DebugConfig.net_let_outcomes && !flow.flag_329 && flow.flag_328
 *   let    = gate && (roll3 < LetProbability || force_let)
 *   error  = roll1 < P || force_error || force_net
 *   net    = (error && roll2 < OutcomeNet) || force_net
 *   (open, may_out) = fn_88671B10 flags, both start at 1
 *   off    = the target is outside the bounds or on the hitter's half
 *   Net    = !let && error && net && gate
 *   Out    = !Net && (!open || (!let && may_out && error) || off)
 *   In     = !let && !Net && !Out, else Let
 * In: clamp the target to [75, x_max] x [z_min, z_max]. Out: unless forced, push an inside target
 * just outside the nearest line (re-aiming with OutEfficiency + 1 first), or, for a target already
 * outside, move it toward the nearest of three boundary points by U[sqrt(d2), 200] and push it out;
 * if that point is more than 200 cm away, demote to In (clamp to [-x_max, x_max]); then classify the
 * landing point with fn_88662C08. Net / Let keep the target. Finally targets within 75 cm of the net
 * are moved to +-75, and the target and outcome are stored in the plan, the caller's target and
 * Debug.ChosenOutcome.
 *
 * The flag GP8 called "point end" is the serve state: fn_8866E318 returns the service box for it.
 *
 * Verdict: compiling, unverified. The original uses VMX128 (vector target copies, lvlx/vrlimi
 * component inserts, an inlined 3-D normalise) and fsel/mfcr float selects, so tools/fn_equiv.py
 * reports UNCHECKED (vmx). See work/army/RT1.failed.md for the native trace plan.
 */
#include "rt1_types.h"

extern const float lbl_8814B440;              /* 0.0f */
extern const float g_ts4_script_constants[];  /* +0 1.0, +0x38 -1.0, +0x2AC 0.1, +0x364 200, +0x604 75, +0x610 -75, +0x614 40000 */
#define RT1_K(off) g_ts4_script_constants[(off) / 4]

void fn_8866E318(struct Rt1MatchO *match, ts4_bool serve, struct Rt1CourtBounds *out);
float fn_8861E598(struct Rt1RandomGen *rng, float lo, float hi);
void ts4_loop_call_seq_u32_off2c_8890E988(void *analysers);
void fn_88671B10(struct Rt1ShotPlan *plan, struct Rt1PlayerCtxO *pc, ts4_u8 *open, ts4_u8 *may_out);
/* Moves a point inside the bounds to 3 cm outside the nearest line. */
struct Rt1Vec4 *fn_88672130(struct Rt1Vec4 *ret, const __vector4 *point, struct Rt1CourtBounds bounds);
ts4_bool fn_88662738(struct Rt1ShotContext *sc, struct Rt1ShotPlan *plan, const __vector4 *point);
/* Classifies a landing point (Out, 0x2C59FAEA or 0x280AE84D). */
ts4_u32 *fn_88662C08(ts4_u32 *ret, const __vector4 *point, const struct Rt1CourtBounds *bounds, struct Rt1PlayerCtxO *pc);
void ts4_if_get_8865E730(__vector4 *v, ts4_u32 side_tag);
#ifdef _MSC_VER
double fabs(double x);
double sqrt(double x);
#pragma intrinsic(fabs, sqrt)
#else
#include <math.h>
#endif

/* x clamped to [lo, hi] with the game's two float selects. */
static RT1_INLINE float rt1_clamp(float x, float lo, float hi)
{
    x = (x - lo < 0.0f) ? lo : x;
    return (x - hi < 0.0f) ? x : hi;
}

/* Replace the x (mask 8) or z (mask 2) component of v with a float. */
static RT1_INLINE __vector4 rt1_set_x(__vector4 v, float x)
{
    float t = x;
    return __vrlimi(v, __lvlx(&t, 0), 8, 0);
}
static RT1_INLINE __vector4 rt1_set_z(__vector4 v, float z)
{
    float t = z;
    return __vrlimi(v, __lvlx(&t, 0), 2, 2);
}

static RT1_INLINE __vector4 rt1_normalize3(__vector4 v)
{
    __vector4 zero = __vspltisw(0);
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 len_sq = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(len_sq);
    __vector4 is_zero = __vcmpeqfp(len_sq, zero);
    __vector4 step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    r = __vmaddfp(r, step, r);
    return __vsel(__vmulfp(v, r), len_sq, is_zero);
}

/* Swing_DLL.xex 0x886807C0 */
ts4_u32 *ts4_outcome_roll_886807C0(ts4_u32 *out, void *let_analysers, struct Rt1ShotPlan *plan,
                                   __vector4 *target, struct Rt1PlayerCtxO *pc, ts4_bool forced)
{
    struct Rt1PlayerStateO *s = pc->state;
    ts4_u32 side_tag = pc->team->state->side_tag;
    ts4_bool serve = pc->match->flow->state == RT1_MATCH_STATE_SERVE;
    struct Rt1CourtBounds bounds;
    const float zero = lbl_8814B440;
    const float one = RT1_K(0);
    float p, roll1, roll2, roll3, let_p;
    ts4_bool gate, let, error, net, off, to_net, to_out, to_in;
    ts4_u8 open, may_out;
    float min_depth;
    __vector4 aim, tgt;
    ts4_u32 outcome;

    fn_8866E318(pc->match, serve, &bounds);
    p = rt1_clamp(pc->state->fault_probability + pc->state->error_bonus, zero, one);
    roll1 = fn_8861E598(&pc->world->rng, zero, one);
    roll2 = fn_8861E598(&pc->world->rng, zero, one);
    if (!pc->is_human && serve) {
        const struct Rt1AIRecordO *rec = pc->ai->record;
        struct Rt1PlayerStateO *ps = pc->state;
        p = rec->serve_fault_probability;
        ps->efficiency = rec->serve_efficiency;
        ps->out_efficiency = rec->serve_out_efficiency;
    }
    ts4_loop_call_seq_u32_off2c_8890E988(let_analysers);
    let_p = pc->state->let_probability;
    roll3 = fn_8861E598(&pc->world->rng, zero, one);

    gate = pc->match->debug->net_let_outcomes && !pc->match->flow->flag_329 && pc->match->flow->flag_328;
    let = gate && (roll3 < let_p || pc->state->force_let);
    open = 1;
    may_out = 1;
    fn_88671B10(plan, pc, &open, &may_out);
    error = roll1 < p || pc->state->force_error || pc->state->force_net;
    net = (error && roll2 < s->outcome_net) || pc->state->force_net;
    {
        float x = ((float *)target)[0];
        float z = ((float *)target)[2];
        float dx = (x < zero) ? -x - bounds.x_max : x - bounds.x_max;
        float dz = (z < zero) ? bounds.z_min - z : z - bounds.z_max;
        off = dx > zero || dz > zero || x < zero;
    }
    to_net = !let && error && net && gate;
    to_out = !to_net && (!open || (!let && may_out && error) || off);
    to_in = !let && !to_net && !to_out;

    tgt = *target;
    aim = tgt;
    min_depth = RT1_K(0x604);
    *out = 0;

    if (to_in) {
        *out = outcome = RT1_OUTCOME_IN;
        tgt = rt1_set_x(tgt, rt1_clamp(tgt.v[0], min_depth, bounds.x_max));
        tgt = rt1_set_z(tgt, rt1_clamp(tgt.v[2], bounds.z_min, bounds.z_max));
    } else if (!to_out) {
        outcome = let ? RT1_OUTCOME_LET : RT1_OUTCOME_NET;
        *out = outcome;
    } else {
        struct Rt1Vec4 tmp;
        outcome = RT1_OUTCOME_OUT;
        if (!forced) {
            __vector4 world;
            if (!off) {
                /* Aimed inside: re-aim with the out efficiency, then push past the nearest line. */
                struct Rt1PlayerStateO *ps = pc->state;
                float lim = RT1_K(0x2AC);
                ps->quad_efficiency = ps->out_efficiency + one;
                if (fabs(pc->state->stick_x) < lim && fabs(pc->state->stick_y) < lim) {
                    pc->state->stick_x = zero;
                    pc->state->stick_y = one;
                }
                pc->row->aim->vtbl->get_target(pc->row->aim, target, pc);
                tgt = *target;
                tgt = *(__vector4 *)fn_88672130(&tmp, &tgt, bounds);
            }
            world = tgt;
            ts4_if_get_8865E730(&world, side_tag);
            if (!serve && !fn_88662738(pc->shot_ctx, plan, &world)) {
                /* Aimed outside: nearest of the side line points and the base line point. */
                __vector4 c1, c2, c3, best;
                float d1, d2, d3, d;
                c1 = aim; c1.v[1] = zero; c1.v[2] = bounds.z_max; c1.v[3] = zero;
                c2 = aim; c2.v[1] = zero; c2.v[2] = bounds.z_min; c2.v[3] = zero;
                c3 = aim; c3.v[0] = bounds.x_max; c3.v[1] = zero; c3.v[3] = zero;
                d2 = (c2.v[0] - aim.v[0]) * (c2.v[0] - aim.v[0]) + (c2.v[2] - aim.v[2]) * (c2.v[2] - aim.v[2]);
                d1 = (c1.v[0] - aim.v[0]) * (c1.v[0] - aim.v[0]) + (c1.v[2] - aim.v[2]) * (c1.v[2] - aim.v[2]);
                d3 = (c3.v[0] - aim.v[0]) * (c3.v[0] - aim.v[0]) + (c3.v[2] - aim.v[2]) * (c3.v[2] - aim.v[2]);
                d = RT1_K(0x38);
                best = aim;
                if (d2 < d1 && d2 < d3) { d = d2; best = c2; }
                if (d1 < d2 && d1 < d3) { d = d1; best = c1; }
                if (d3 < d1 && d3 < d2) { d = d3; best = c3; }
                if (d > RT1_K(0x614)) {
                    /* More than 200 cm from the court: the shot is played In after all. */
                    float lim = -bounds.x_max;
                    tgt = aim;
                    *out = outcome = RT1_OUTCOME_IN;
                    tgt = rt1_set_x(tgt, rt1_clamp(tgt.v[0], lim, bounds.x_max));
                    tgt = rt1_set_z(tgt, rt1_clamp(tgt.v[2], bounds.z_min, bounds.z_max));
                    goto done;
                } else {
                    float dist = fn_8861E598(&pc->world->rng, (float)sqrt(d), RT1_K(0x364));
                    float t = dist;
                    __vector4 moved = __vmaddfp(rt1_normalize3(__vsubfp(best, aim)), __vspltw(__lvlx(&t, 0), 0), aim);
                    *(__vector4 *)&tmp = moved;
                    tgt = moved;
                    tgt = *(__vector4 *)fn_88672130(&tmp, &tgt, bounds);
                }
            }
        }
        {
            ts4_u32 cls;
            *out = *fn_88662C08(&cls, &tgt, &bounds, pc);
        }
    }

done:
    if (tgt.v[0] > zero && tgt.v[0] < min_depth)
        tgt = rt1_set_x(tgt, RT1_K(0x604));
    if (tgt.v[0] < zero && tgt.v[0] > RT1_K(0x610))
        tgt = rt1_set_x(tgt, RT1_K(0x610));
    plan->target = tgt;
    *target = tgt;
    plan->outcome = outcome;
    s->chosen_outcome = outcome;
    return out;
}
