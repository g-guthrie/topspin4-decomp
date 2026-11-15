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
#include "gp7_types.h"

extern "C" {

extern const float lbl_8814B440;              /* 0.0f */
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

/* Swing_DLL.xex 0x886CD3C8 */
float ts4_anim_busy_frames_886CD3C8(Rt1SwingAnimController *self)
{
    Gp7AnimStack *stack = self->stack;
    float zero = lbl_8814B440;
    int top = ts4_anim_stack_top_active_layer_886C4638(stack, zero);
    if (top != -1) {
        Gp7AnimLayer *layer = stack->layers[top];
        if ((unsigned)layer->inner->desc->kind == 2) {
            Gp7ClipDesc *desc = layer->inner->desc;
            int *rel = &desc->events_rel;
            const Rt1TwoEventTable *te = (const Rt1TwoEventTable *)((const char *)rel + *rel);
            float busy = (te->te1_position - layer->rate) * (desc->time_ratio - g_ts4_script_constants[0]) + layer->base_time - stack->now;
            return (-busy < zero) ? busy : zero;
        }
    }
    return zero;
}

}
