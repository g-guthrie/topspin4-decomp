/* NEAR MISS fn_886CD3C8 AnimNode_BusyFrames (ME, 2026-11-18): 22 instructions off, size matches (0xC0).
 * Route: LTCG /Oc (default float model), context flags(/Ob1):src/xbox360/gp7_anim_busy.cpp, WITHOUT pp1_pool_primer.c
 * (with the primer: also 22). Explicit __fself on the {1,-1} table g_ts4_script_constants[26 + (-busy < zero)]
 * reproduces fneg + fcmpu against the call's zero in f1 and the fsel; clrrwi and fmadds as before.
 * Remaining: the index is computed with `li 1; blt; li 0; slwi` instead of mfcr/rlwinm/or (8 index forms tried,
 * all identical), and the constant-address schedule (lis/addi of g_ts4_script_constants) differs. */
/*
 * RT1: AnimNode_BusyFrames (docs/gameplay/movement-and-animation.md s7.5, symbols.md s4).
 *
 * Frames until the topmost playing swing clip releases the player. Only clips with exactly two
 * TransitionEvents (descriptor kind 2) count:
 *   busy = (TE[1].Position - layer->rate) * (desc->time_ratio - 1) + layer->base_time - stack->now
 * returned when positive, else 0 (put-away clips, with three events, read as "not busy").
 * Field names are those of gp7_types.h (GP7's reading of the same offsets).
 *
 * The original passes 0.0f to ts4_anim_stack_top_active_layer_886C4638 in f1 and reuses f1 (and r4,
 * the stack) after the call: an LTCG register convention.
 *
 * Verdict: EQUIVALENT (tools/fn_equiv.py --flags /Oc --seed 1 --trials 1500: 100% block coverage;
 * work/specs/RT1/rt1_eq_anim_busy_frames.equiv.json). Not byte-matched: on the LTCG route
 * (context flags(/Ob1):gp7_anim_busy.cpp, /Oc /fp:precise) the r4/f1 reuse across the call
 * reproduces, but 37 instructions still differ: the original re-reads desc through
 * `clrrwi r9,r9,0`, contracts (a-b)*(c-1)+d into fmadds, and lowers the final select to
 * mfcr/fsel without the xori our compiler emits (three known open idioms, matching-tips.md).
 */
#include "../gp7_types.h"

#ifdef _MSC_VER
extern "C" float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float a, float b, float c) { return a >= 0 ? b : c; }
#endif
extern "C" {

extern const float g_ts4_event_value;              /* 0.0f */
extern const float g_ts4_script_constants[];  /* +0: 1.0f */

int ts4_anim_stack_top_active_layer_886C4638(Gp7AnimStack *stack, float unused);

struct Rt1SwingAnimController {               /* owner of the layer stack */
    unsigned char pad00[0x2c];
    Gp7AnimStack *stack;                      /* +0x2c */
};

/* TE[1].Position of a two-event clip, at +0x38 of the event table. */
struct Rt1TwoEventTable {
    unsigned char pad00[0x38];
    float te1_position;                       /* +0x38 */
};

static __inline Gp7ClipDesc *rt1_desc(Gp7ClipRef *r) { return r->desc; }
static __inline float rt1_max(float a, float b) { return (a - b >= 0.0f) ? a : b; }
static __inline float rt1_max2(float a, float b) { return (b - a >= 0.0f) ? b : a; }
static __inline Gp7ClipDesc *rt1_ldesc(Gp7AnimLayer *l) { return l->inner->desc; }
static __inline float rt1_te1(Gp7ClipDesc *d) { int *rel = &d->events_rel; return ((const Rt1TwoEventTable *)((const char *)rel + *rel))->te1_position; }
static __inline float rt1_maxz(float a, float b, float z) { return (a - b >= z) ? a : b; }
/* Swing_DLL.xex 0x886CD3C8 */
float ts4_anim_busy_frames_886CD3C8(Rt1SwingAnimController *self)
{
    Gp7AnimStack *stack = self->stack;
    float zero = g_ts4_event_value;
    int top = ts4_anim_stack_top_active_layer_886C4638(stack, zero);
    if (top != -1) {
        Gp7AnimLayer *layer = stack->layers[top];
        if ((unsigned)layer->inner->desc->kind == 2) {
            float busy = (rt1_te1(rt1_ldesc(layer)) - layer->rate) * (rt1_ldesc(layer)->time_ratio - g_ts4_script_constants[0]) + layer->base_time - stack->now;
            return __fself(g_ts4_script_constants[26 + (-busy < zero)], zero, busy);
        }
    }
    return zero;
}

}
