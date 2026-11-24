/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8868E320: fetch the player's world position and hand it, with the current match mode from the shared
 * state, to the position update at 0x8868E248.
 * Source: drafts/me_8868E320_nearmiss.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_8868E320.json for route and flags. */
#include "vx1_vector.h"
typedef struct Ts4MatchState { char p[0x310]; int mode; } Ts4MatchState;
typedef struct Ts4PlayerShared { char p[0x30]; Ts4MatchState *state; } Ts4PlayerShared;
typedef struct Ts4PosPlayer { char p[0x48]; Ts4PlayerShared *shared; } Ts4PosPlayer;
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, Ts4PosPlayer *pc);
void fn_8868E248(Ts4PosPlayer *p, const __vector4 *pos, int mode);
void ts4_update_from_world_pos_8868E320(Ts4PosPlayer *p)
{
    __vector4 pos;
    ts4_if_get_u32_off4c_8865EC70(&pos, p);
    fn_8868E248(p, &pos, p->shared->state->mode);
}
