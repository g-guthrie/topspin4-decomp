/* EQUIVALENT, not byte-matched (fsel +-1 table orientation, clrrwi, fmadds scheduling blockers).
 * Evidence: work/equiv/rt3_886CD3C8.json (3450 valid trials, 100% blocks, seed 7). Flags /Oc /fp:precise. */
/*
 * RT3: swing animation busy time (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * fn_886CD3C8: ticks until the swing event of the topmost playing animation layer.
 * Types: src/xbox360/gp7_types.h.
 */
#include "../gp7_types.h"

extern "C" {

extern float g_ts4_script_constants[];

struct Rt3AnimCtrl {
    unsigned char pad00[0x2c];
    Gp7AnimStack *stack;          /* +0x2c */
};

int ts4_anim_stack_top_active_layer_886C4638(Gp7AnimStack *stack, float unused);

/* Swing_DLL.xex 0x886CD3C8: ticks until the swing event of the topmost playing layer (0 if none / not a swing record). */
float ts4_anim_busy_ticks_886CD3C8(Rt3AnimCtrl *ctrl)
{
    Gp7AnimStack *stack = ctrl->stack;
    
    int top = ts4_anim_stack_top_active_layer_886C4638(stack, 0.0f);
    float busy = 0.0f;
    if (top != -1) {
        Gp7AnimLayer *layer = stack->layers[top];
        Gp7ClipDesc *desc = layer->inner->desc;
        if ((unsigned)desc->kind == 2u) {
            const float *ev = (const float *)((char *)&desc->events_rel + desc->events_rel);
            float t = (ev[0x38 / 4] - layer->rate) * (desc->time_ratio - g_ts4_script_constants[0]) + layer->base_time - stack->now;
            busy = t < 0.0f ? 0.0f : t;
        }
    }
    return busy;
}

}
