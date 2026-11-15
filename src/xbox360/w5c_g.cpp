/*
 * W5C batch g: swing animation controller helpers (types from gp7_types.h).
 * Float code: default float model plus LTCG pool primer, see docs/agents/near-misses/FP1.md and PP1.md.
 */
#include "gp7_types.h"

extern "C" {

struct W5gRecord { unsigned char pad00[4]; float value; };
struct W5gKeyArg { unsigned int key; };
struct W5gSwingController { unsigned char pad00[0x2c]; Gp7AnimStack *stack; };

int fn_886C66C0(Gp7AnimStack *stack);
W5gRecord *ts4_find_record_by_key_88265440(void *table, W5gKeyArg *key);

/* Swing_DLL.xex 0x886CD488 */
int ts4_anim_frames_to_event_886CD488(W5gSwingController *self, int *out)
{
    Gp7AnimStack *stack = self->stack;
    int result;
    int top;
    *out = -1;
    result = 0;
    top = fn_886C66C0(stack);
    if (top != -1) {
        Gp7AnimLayer *layer = stack->layers[top];
        Gp7ClipDesc *desc = layer->inner->desc;
        result = (short)desc->slot + 1 != 0;
        if ((unsigned char)result != 0) {
            W5gKeyArg key;
            key.key = 0x3b9ad22e;
            *out = (int)((ts4_find_record_by_key_88265440((char *)desc + 0x64, &key)->value - layer->rate) * (desc->time_ratio - 1.0f) + layer->base_time - stack->now);
        }
    }
    return result;
}

}
