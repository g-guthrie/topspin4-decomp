/* NEAR MISS fn_8867DF68 TimingState_Update: 169 off (0x31C vs 0x320), LTCG with pp1_pool_primer.c, /Oc (was 193).
 * Remaining: the target also keeps pred (r30) and timing (r28) in saved registers and stores base_frame via
 * state+0xD04; one saved GPR fewer here (savegprlr_27 vs _26), so registers shift throughout. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wuninitialized"
#endif
/*
 * RT1: TimingState_Update (docs/gameplay/timing-and-fatigue.md s1, symbols.md).
 *
 * Every frame: TimingBaseFrame = 600; with no predicted ball, TimingValue = -1. Otherwise
 * take the reference point where the line through the player's current position, square to
 * the facing direction, meets the body line, moved reach_offset (50 cm) back along the facing
 * direction; walk the predicted ball samples for the first whose |x| is beyond the
 * reference |x| (else the last sample); f = that sample's tick - match frame, stored as
 * TimingBaseFrame; TimingValue = lerp(worst(f), best(f), TimingAbility) over the Baseline or
 * Volley curve pair. The value is copied to the HUD block of the player.
 *
 * Verdict: compiling, unverified. The original uses VMX128 (inlined 3-D normalise twice,
 * lvlx/vrlimi vector assembly), so tools/fn_equiv.py reports UNCHECKED (vmx). See
 * work/army/RT1.failed.md for the byte diff and the native trace plan.
 */
#include "rt1_types.h"

extern const float g_ts4_event_value;           /* 0.0f */
extern const float g_ts4_script_constants[]; /* +0x38: -1.0f */

/* Look-ahead position of the player after `frames` frames (ts4_vec_with_offset_8867A908). */
void ts4_vec_with_offset_8867A908(struct Rt1PlayerCtxView *pc, __vector4 *out, float frames);
/* Court_MirrorBySide: mirror x and z for the far side tag. */
void ts4_if_get_8865E730(__vector4 *v, ts4_u32 side_tag);
/* Line2_Intersect: x-z intersection of two lines; false when parallel. */
ts4_bool fn_881896F8(const struct Rt1Line *a, const struct Rt1Line *b, __vector4 *point, float *t1, float *t2);
/* RangeCurve_Eval: clamped ramp over a {InStart, InStop, OutStart, OutStop} list. x is in f1,
 * so the list pointer is the second GPR argument (r4). */
float ts4_range_lookup_881899D8(float x, const struct Rt1RangeList *list);
#ifdef _MSC_VER
double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

/* XMVector3Normalize: v / |v| over x, y, z with one Newton step; |v|^2 when v is zero. */
static RT1_INLINE __vector4 rt1_normalize3(__vector4 v, __vector4 half, __vector4 zero)
{
    __vector4 len_sq = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(len_sq);
    __vector4 is_zero = __vcmpeqfp(len_sq, zero);
    __vector4 step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    r = __vmaddfp(r, step, r);
    return __vsel(__vmulfp(v, r), len_sq, is_zero);
}

/* The predictor sample list (+0x5A0) seen as its own {begin, end} pair: the target keeps a pointer to it
   (addi r31,pred,0x5A0). LTCG + pp1_pool_primer.c: 169 off (was 193). */
struct Rt1SampleList { struct Rt1BallSample *begin, *end; };
static RT1_INLINE int rt1_sl_empty(const struct Rt1SampleList *l) { return l->begin == l->end; }

/* Swing_DLL.xex 0x8867DF68 */
void ts4_timing_state_update_8867DF68(struct Rt1SubController *self)
{
    struct Rt1PlayerCtxView *pc = self->pc;
    const struct Rt1TimingCurves *curves;
    struct Rt1TimingState *timing;
    struct Rt1BallPredictor *pred;
    const struct Rt1SampleList *sl;

    curves = &pc->tuning->volley;
    if (!pc->state->is_volley)
        curves = &pc->tuning->baseline;
    timing = &self->pc->state->timing;
    pred = self->pc->ball->predictor;
    sl = (const struct Rt1SampleList *)&pred->samples;
    timing->base_frame = 600;

    if (rt1_sl_empty(sl)) {
        timing->value = g_ts4_script_constants[0x38 / 4];
    } else {
        struct Rt1PlayerCtxView *p = self->pc;
        __vector4 side;                  /* square to the facing direction, in x-z */
        __vector4 pos;
        __vector4 ref;
        struct Rt1Line probe;
        float t1, t2;
        float tmp;
        __vector4 half, zero, back, nx, ny, nz;
        float ref_x;
        struct Rt1BallSample *last, *s;
        int frames;
        float f, worst;

        side.v[1] = g_ts4_event_value;
        side.v[3] = g_ts4_event_value;
        side.v[2] = p->body->line.dir.v[0];
        side.v[0] = -p->body->line.dir.v[2];
        ts4_vec_with_offset_8867A908(p, &pos, g_ts4_event_value);
        ts4_if_get_8865E730(&pos, p->team->state->side_tag);

        zero = __vspltisw(0);
        half = __vcfsx(__vspltisw(1), 1);
        probe.point = pos;
        probe.dir = rt1_normalize3(side, half, zero);
        fn_881896F8(&probe, &p->body->line, &ref, &t1, &t2);

        p = self->pc;
        tmp = -p->body->line.dir.v[1];
        ny = __lvlx(&tmp, 0);
        tmp = -p->body->line.dir.v[2];
        nz = __lvlx(&tmp, 0);
        tmp = -p->body->line.dir.v[0];
        nx = __lvlx(&tmp, 0);
        back = __vrlimi(back, nx, 8, 0);
        back = __vrlimi(back, ny, 4, 3);
        tmp = curves->reach_offset;
        back = __vrlimi(back, nz, 2, 2);
        ref = __vmaddfp(rt1_normalize3(back, half, zero), __vspltw(__lvlx(&tmp, 0), 0), ref);
        ref_x = (float)fabs(ref.v[0]);

        last = 0;
        if (!rt1_sl_empty(sl))
            last = sl->end - 1;
        frames = last->tick - p->match->flow->frame;
        s = 0;
        if (!rt1_sl_empty(sl))
            s = sl->begin;
        for (; s != last; s++) {
            tmp = ref_x - (float)fabs(s->pos[0]);
            if (*(unsigned short *)&tmp & 0x8000) {
                frames = s->tick - p->match->flow->frame;
                break;
            }
        }
        timing->base_frame = frames;
        f = (float)frames;
        worst = ts4_range_lookup_881899D8(f, &curves->worst);
        timing->value = (ts4_range_lookup_881899D8(f, &curves->best) - worst) * timing->ability + worst;
    }

    pc = self->pc;
    {
        int *rel = &pc->match->hud->players_rel;
        struct Rt1HudPlayer *blk = (struct Rt1HudPlayer *)((char *)rel + (pc->index * (int)sizeof(struct Rt1HudPlayer) + *rel));
        blk->timing_value = timing->value;
    }
}
