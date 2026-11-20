/*
 * FP1: AnimNode_BusyFrames (rewrite of RT1's rt1_eq_anim_busy_frames.cpp and CL1's cd3c8_v.cpp).
 *
 * Frames until the topmost playing swing clip releases the player. Only clips whose descriptor kind
 * is 2 (two TransitionEvents) count:
 *   busy = (TE[1].Position - layer->rate) * (desc->time_ratio - 1) + layer->base_time - stack->now
 * returned when positive, else 0.
 *
 * Float codegen (FP1, docs/agents/near-misses/FP1.md): compiled in the compiler's default float
 * model (cl passes -fpfast), which contracts a*b+c into fmadds. The zero is a named `const float`
 * with a known value, not a literal: comparing against it makes the compiler if-convert the select
 * into the +1/-1 table form (fcmpu; mfcr; rlwinm LT/UN; lfsx; fsel) instead of a branch or a bare
 * fsel. LTCG route; the module constant pool layout comes from the fp1_pool_primer.c context.
 */
#include "gp7_types.h"

extern "C" {

static const float fp1_zero = 0.0f;

int ts4_anim_stack_top_active_layer_886C4638(Gp7AnimStack *stack, float unused);

struct Fp1SwingAnimController {               /* owner of the layer stack */
    unsigned char pad00[0x2c];
    Gp7AnimStack *stack;                      /* +0x2c */
};

/* TE[1].Position of a two-event clip, at +0x38 of the event table. */
struct Fp1TwoEventTable {
    unsigned char pad00[0x38];
    float te1_position;                       /* +0x38 */
};

static __inline Gp7ClipDesc *fp1_desc(Gp7AnimLayer *l) { return l->inner->desc; }

/* fsel-style max: compare the difference with the named zero. max(0, x) gives 0 - x, which the
 * default float model folds to fneg. */
static __inline float fp1_max(float a, float b) { return (a - b >= fp1_zero) ? a : b; }

/* Swing_DLL.xex 0x886CD3C8 */
float ts4_anim_busy_frames_886CD3C8(Fp1SwingAnimController *self)
{
    Gp7AnimStack *stack = self->stack;
    float zero = fp1_zero;
    int top = ts4_anim_stack_top_active_layer_886C4638(stack, zero);
    if (top != -1) {
        Gp7AnimLayer *layer = stack->layers[top];
        if ((unsigned)layer->inner->desc->kind == 2) {
            Gp7ClipDesc *desc = fp1_desc(stack->layers[top]);
            int *rel = &desc->events_rel;
            const Fp1TwoEventTable *te = (const Fp1TwoEventTable *)((const char *)rel + *rel);
            float busy = (te->te1_position - layer->rate) * (desc->time_ratio - 1.0f) + layer->base_time - stack->now;
            return fp1_max(zero, busy);
        }
    }
    return zero;
}

}
