/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): movement planner query, player far from the planner's stored position.
 * Called by MovePlanner NextState 0x886B8468. LTCG unit, /Oc.
 */
#include "include/ts4/ts4.h"

extern float g_ts4_script_constants[];

/* 0x8866C150: 1 when the squared 3D distance from the planner's position (+0x270) to the player's local
 * position exceeds the script constant at +0x3E4 and the planner flag +0x294 is clear; 0 otherwise.
 * The planner position is read through a volatile view so it loads before the player position, as in the original. */
int ts4_target_far_and_idle_8866C150(Ts4MovePlanner *self)
{
    Ts4PlayerState *state = self->player->state;
    __vector4 player_pos = state->local_position.v;
    __vector4 d = __vsubfp(player_pos, *(volatile __vector4 *)&self->f_270.v);
    __vector4 s = __vmsum3fp(d, d);
    if (s.v[0] > g_ts4_script_constants[0x3e4 / 4]) {
        if (self->f_294 == 0)
            return 1;
    }
    return 0;
}
