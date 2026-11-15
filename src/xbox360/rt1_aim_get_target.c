/*
 * RT1: AimSelector_GetTarget, vtable slot 4 (docs/gameplay/aiming.md s3, symbols.md).
 *
 * Reads the stick into QuadAimingState (DirectionSelected says whether a direction is held),
 * builds the aiming quad at the current QuadEfficiency, and returns the stick point on the quad
 * edge, or the quad centre when no direction is selected.
 */
#include "rt1_types.h"

struct Rt1AimSelectorA;
/* Aim_StickToQuadState: picks the stick source; true when a direction is selected. */
ts4_bool ts4_pick_aim_vector_886706C8(struct Rt1PlayerCtxA *pc, struct Rt1QuadAimingState *out);
/* AimSelector_BuildQuad: zone quads interpolated by QuadEfficiency `m`. */
void fn_88693040(struct Rt1AimSelectorA *self, struct Rt1AimQuad *out, struct Rt1PlayerCtxA *pc, float m);
/* Aim_QuadPoint: stick direction to the quad edge. */
void fn_8867D150(const struct Rt1AimQuad *q, const struct Rt1QuadAimingState *a, struct Rt1Vec4 *out);

/* Swing_DLL.xex 0x886935A0 */
void ts4_aim_selector_get_target_886935A0(struct Rt1AimSelectorA *self, struct Rt1Vec4 *out, struct Rt1PlayerCtxA *pc)
{
    struct Rt1AimingState *aim = &pc->state->aim;
    struct Rt1QuadAimingState *quad_state = &aim->quad;
    struct Rt1AimQuad quad;

    aim->direction_selected = ts4_pick_aim_vector_886706C8(pc, quad_state);
    fn_88693040(self, &quad, pc, pc->state->aim.quad_efficiency);
    if (!aim->direction_selected)
        *out = quad.center;
    else
        fn_8867D150(&quad, quad_state, out);
}
