/* agK 2026-11-19: top pads 0-7: all 2 (pad-insensitive). */
/* agentA2 2026-11-18: still 2: named pos/player pointer locals, block-local mode, pointer from getter result (3), getter nested in arg (17). */
/* NEAR MISS (2 instructions off: `mr r4,r3` / `mr r31,r3` swapped, see matching-tips "no rule
 * found"). 0x8868E320: fetch the player's world position and hand it, with the current match
 * mode from the shared state, to the position update at 0x8868E248. Tried by-value struct
 * return, C++ RVO, named result and mode locals. */
#include "vx1_vector.h"
typedef struct State { char p[0x310]; int mode; } State;
typedef struct Shared { char p[0x30]; State *state; } Shared;
typedef struct Player { char p[0x48]; Shared *shared; } Player;
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, Player *pc);
void fn_8868E248(Player *p, const __vector4 *pos, int mode);
void ts4_update_from_world_pos_8868E320(Player *p)
{
    __vector4 pos;
    ts4_if_get_u32_off4c_8865EC70(&pos, p);
    fn_8868E248(p, &pos, p->shared->state->mode);
}
