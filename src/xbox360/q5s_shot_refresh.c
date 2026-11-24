/* Shot subsystem (q5s): per-frame refresh of a player's shot helper. LTCG route, /Oc. */
#include "include/ts4/ts4.h"
#include "vx1_vector.h"

typedef struct Q5sShotRefresh {
    char pad_00[4];
    Ts4Player *player;                           /* +0x04 */
} Q5sShotRefresh;

extern unsigned char ts4_cursor_out_of_range_886603C0(void *cursor);
extern const __vector4 lbl_88001AF0;             /* up (0, 1, 0, 0) */

/* Swing_DLL.xex 0x886A1128: while both debug bytes +0x48/+0x69 are set and the player's cursor is in range,
 * writes the up vector and then the player's position (8865EC70) into a dead float3 temp (the position query
 * is kept only for its side effects); always ends with the same-side notification (8869D870).
 * Codegen: the constant splats come straight from the global (`__vspltw(lbl, k)` three times); a local copy of
 * the constant adds a vor128. */
void ts4_shot_refresh_886A1128(Q5sShotRefresh *self)
{
    Ts4Player *p = self->player;
    Ts4DebugConfig *dbg = p->match->debug;
    if (dbg->f_048 && dbg->f_069 && !ts4_cursor_out_of_range_886603C0(p->cursor)) {
        float t[4];
        __vector4 v;
        __stvewx(__vspltw(lbl_88001AF0, 0), t, 0);
        __stvewx(__vspltw(lbl_88001AF0, 1), t, 4);
        __stvewx(__vspltw(lbl_88001AF0, 2), t, 8);
        v = *ts4_if_get_u32_off4c_8865EC70((__vector4 *)t, p);
        __stvewx(__vspltw(v, 0), t, 0);
        __stvewx(__vspltw(v, 1), t, 4);
        __stvewx(__vspltw(v, 2), t, 8);
    }
    ga4_notify_same_side_8869D870(p);
}
