/*
 * GP7 (WP7): swing animation controller helpers used by the reach evaluation (GP2).
 *   ts4_anim_stack_top_active_layer_886C4638  topmost active layer of the per-player animation layer stack
 *   fn_886CD3C8  ticks until the current swing animation releases the player ("anim busy ticks")
 * Types: src/xbox360/gp7_types.h (offsets from machine code, see work/gameplay-notes/gp7.md).
 */
#include "gp7_types.h"

extern "C" {

extern float g_ts4_script_constants[];

/* Swing_DLL.xex 0x886C4638: index of the topmost layer whose slot != 0xffff, or -1. */
int ts4_anim_stack_top_active_layer_886C4638(Gp7AnimStack *stack, float unused)
{
    int found = -1;
    for (int i = stack->layers.size() - 1; i >= 0; --i) {
        if (stack->layers[i]->inner->desc->slot != 0xffff) {
            found = i;
            break;
        }
    }
    return found;
}

}
